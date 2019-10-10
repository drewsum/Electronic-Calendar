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
#include "32mz_interrupt_control.h"
#include "device_control.h"
#include "gpio_setup.h"
#include "prefetch.h"
#include "watchdog_timer.h"
#include "heartbeat_timer.h"
#include "usb_uart.h"
#include "terminal_control.h"
#include "power_saving.h"
#include "rtcc.h"

void main(void) {
    
    // Disable global interrupts so clocks can be initialized properly
    disableGlobalInterrupts();
    
    // Initialize system clocks
    clockInitialize();
    
    // Configure interrupt controller
    interruptControllerInitialize();
    
    // Enable Global Interrupts
    enableGlobalInterrupts();
    
    // Save the cause of the most recent device reset
    // This also checks for configuration errors
    reset_cause = getResetCause();
    
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
    terminalTextAttributes(GREEN, BLACK, REVERSE);
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
    
        terminalTextAttributes(RED, BLACK, NORMAL);
        
    }
    
    else {
     
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
    }
    
    printf("\r\nCause of most recent device reset: %s\r\n\r\n", getResetCauseString(reset_cause));
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("Beginning Peripheral Initialization:\r\n");
    printf("    Oscillators, Phase-Locked Loop, and System Clocks Initialized\n\r");
    printf("    Interrupt Controller Initialized, Global Interrupts Enabled\n\r");
    printf("    GPIO Pins Initialized\n\r");
    printf("    Status LEDs Enabled\r\n");
    printf("    USB UART Initialized, DMA buffer method used\n\r");
    
    // Setup error handling
    errorHandlerInitialize();
    printf("    Error Handler Initialized\n\r");
    
    
//    // Setup heartbeat timer
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
    
    // Startup the deadman timer
    deadmanTimerInitialize();
    printf("    Deadman Timer Initialized\n\r");
    
    // Setup the real time clock-calendar
    rtccInitialize();
    printf("    Real Time Clock-Calendar Initialized\r\n");
    
    // Disable RESET LED
    RESET_LED_PIN = LOW;
    printf("    Reset LED Disabled\r\n");
    
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("\n\rType 'Help' for list of supported commands\n\r\n\r");
    terminalTextAttributesReset();
    
    // Main loop
    while (true) {
     
        Nop();
        
    }
}
