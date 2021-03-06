/*
 * File:   main.c
 * Author: Drew Maatman
 *
 * Created on July 19, 2019, 9:00 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "configuration.h"
#include "32mz_interrupt_control.h"
#include "cause_of_reset.h"
#include "pin_macros.h"
#include "device_control.h"
#include "gpio_setup.h"
#include "prefetch.h"
#include "watchdog_timer.h"
#include "heartbeat_timer.h"
#include "usb_uart.h"
#include "usb_uart_rx_lookup_table.h"
#include "terminal_control.h"
#include "power_saving.h"
#include "rtcc.h"
#include "binary_clock.h"
#include "calendar_leds.h"
#include "adc.h"
#include "telemetry.h"
#include "temp_i2c.h"
#include "mcp9804_temp_sensor.h"
#include "misc_IO_functions.h"

void main(void) {
    
    // Disable global interrupts so clocks can be initialized properly
    disableGlobalInterrupts();
    
    // Save the cause of the most recent device reset
    // This also checks for configuration errors
    reset_cause = getResetCause();
    
    // Initialize system clocks
    clockInitialize();
    
    // Configure interrupt controller
    interruptControllerInitialize();
    
    // Enable Global Interrupts
    enableGlobalInterrupts();
    
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Enable status LED supply rail
    STATUS_LED_ENABLE_PIN = HIGH;
    
    // Setup USB UART debugging
    usbUartInitialize();
    
    // Clear the terminal
    terminalClearScreen();
    terminalSetCursorHome();
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Electronic Calendar\r\n");
    printf("Created by Drew Maatman, 2019\r\n");
    terminalTextAttributesReset();
    
    // Print cause of reset
    if (    reset_cause == Undefined ||
            reset_cause == Primary_Config_Registers_Error ||
            reset_cause == Primary_Secondary_Config_Registers_Error ||
            reset_cause == Config_Mismatch ||
            reset_cause == DMT_Reset ||
            reset_cause == WDT_Reset ||
            reset_cause == Software_Reset ||
            reset_cause == External_Reset ||
            reset_cause == BOR_Reset) {
    
        terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
        
    }
    
    else {
     
        terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
        
    }
    
    // only clear persistent error flags if we've seen a POR... keep old values after other resets
    if (reset_cause == POR_Reset) clearErrorHandler();
    
    printf("\r\nCause of most recent device reset: %s\r\n\r\n", getResetCauseString(reset_cause));
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Beginning Peripheral Initialization:\r\n");
    printf("    Oscillators, Phase-Locked Loop, and System Clocks Initialized\n\r");
    printf("    Interrupt Controller Initialized, Global Interrupts Enabled\n\r");
    printf("    GPIO Pins Initialized\n\r");
    printf("    Status LEDs Enabled\r\n");
    printf("    USB UART Initialized, DMA buffer method used\n\r");
    
    // Setup error handling
    errorHandlerInitialize();
    printf("    Error Handler Initialized\n\r");
    
    
    // Setup heartbeat timer
    heartbeatTimerInitialize();
    printf("    Heartbeat Timer Initialized\n\r");
    
    // Setup prefetch module
    prefetchInitialize();
    printf("    CPU Instruction Prefetch Module Enabled\r\n");
    
    // Disable unused peripherals for power savings
    PMDInitialize();
    printf("    Unused Peripheral Modules Disabled\n\r");
    
    // Setup the watchdog timer
    watchdogTimerInitialize();
    printf("    Watchdog Timer Initialized\n\r");
    
    // Setup the real time clock-calendar
    rtccInitialize();
    if (reset_cause == POR_Reset) rtccClear();
    printf("    Real Time Clock-Calendar Initialized\r\n");
    
    // setup the ADC modules
    ADCInitialize();
    telemetryInitialize();
    printf("    Analog to Digital Converters, Telemetry Initialized\r\n");
    
    // setup temperature sensor I2C bus
    TEMP_I2C_Initialize();
    printf("    Temperature Sensor I2C Bus Initialized\r\n");
    MCP9804TempSensorInitialize();
    printf("    I2C Digital Temperature Sensors Initialized\r\n");
    
    // setup power toggle cap touch button
    capTouchPowerInitialize();
    printf("    Power Toggle Capacitive Pushbutton Initialized\r\n");
    
    // Disable RESET LED
    RESET_LED_PIN = LOW;
    printf("    Reset LED Disabled\r\n");
    
    // Enable date decoding
    DATE_DECODE_ENABLE_PIN = HIGH;
    printf("    Date Decoding Enabled\r\n");
    
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("\n\rType 'Help' for list of supported commands\n\r\n\r");
    terminalTextAttributesReset();
    
    clockFailCheck();
    
    // Main loop
    while (true) {
        
        // check to see if a clock fail has occurred and latch it
        clockFailCheck();
        
        // check to see if a PGOOD fault has occurred and latch it
        powerGoodCheck();
        
        // convert raw temp results into floating point telemetry
        MCP9804BatchConvert();
        
        // set LEDs if changes are pending
        if (led_update_request_flag) {
         
            // update values displayed on binary clock LEDs
            updateBinaryClockLEDs(rtcc_shadow.hours, rtcc_shadow.minutes, rtcc_shadow.seconds);

            // update value displayed on month LEDs
            updateMonthLEDs(rtcc_shadow.month);

            // update value displayed on weekday LEDs
            updateWeekdayLEDs(rtcc_shadow.weekday);

            // update value displayed on year LEDs
            updateYearLEDs(rtcc_shadow.year);
            
            // update value displayed on day LEDs
            updateDateLEDs(rtcc_shadow.day);
            
            led_update_request_flag = 0;
            
        }
        
        // check to see if we have a new usb uart string to parse
        // if (usb_uart_rx_parse_request && strlen(usb_uart_rx_buffer) > 2) {
        if (usb_uart_rx_parse_request) {
            // Determine length of received string
            uint32_t length = strlen(usb_uart_rx_buffer);
            
            // parse received string
            usbUartRxLUTInterface(usb_uart_rx_buffer);
            usb_uart_rx_parse_request = 0;
            
            // clear rx buffer
            uint32_t index;
            for (index = 0; index < length; index++) {
                usb_uart_rx_buffer[index] = '\0';
            }
            
        }
        
        // if we need to grab new temp sensor data, do it
        if (MCP9804_start_flag) MCP9804AcquisitionHandler();
        
        // update minimum and maximum measured telemetry
        if (telemetry_update_flag_adc && telemetry_update_flag_i2c) telemetryUpdateExtremes();
        
        // update error LEDs if needed
        if (update_error_leds_flag) updateErrorLEDs();
        
        // if we need to shut down due to a pushbutton toggle
        if (pushbutton_shutdown_request) capToughPowerToggleShutdown();
        
        // if we need to wakeup do to a pushbutton toggle, wakey wakey eggs and bakey
        if (pushbutton_wakeup_request) capToughPowerToggleWakeup();
        
    }
    
}
