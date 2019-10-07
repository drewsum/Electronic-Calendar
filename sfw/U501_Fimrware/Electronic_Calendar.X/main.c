/*
 * File:   main.c
 * Author: Drew Maatman
 *
 * Created on July 19, 2019, 9:00 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdbool.h>

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
//    reset_cause = getResetCause();
    
    // Initialize GPIO pins to startup settings
    gpioInitialize();
    
    // Setup USB UART debugging
    usbUartInitialize();
    
    // Setup DMA0 for USB UART Transmit
    usbUartTrasmitDmaInitialize();
    
    printf("Hello, World!\r\n");
    
    
    // Clear the terminal
    // terminalClearScreen();
    // terminalSetCursorHome();
    
    // terminalTextAttributesReset();
    // terminalTextAttributes(GREEN, BLACK, NORMAL);
    // printf("Clocks Initialized\n\r");
    // printf("Interrupt Controller Initialized, Global Interrupts Enabled\n\r");
    // printf("GPIO Pins Initialized\n\r");
    // printf("USB UART Initialized\n\r");
    
    // Setup error handling
    errorHandlerInitialize();
    // printf("Error Handler Initialized\n\r");
    
    
//    // Setup heartbeat timer
    heartbeatTimerInitialize();
    // printf("Heartbeat Timer Initialized\n\r");
//    
//    // Disable unused peripherals for power savings
//    PMDInitialize();
//    // printf("Unused Peripheral Modules Disabled\n\r");
            
    // Setup the watchdog timer
    watchdogTimerInitialize();
    // printf("Watchdog Timer Initialized\n\r");
    
    // Startup the deadman timer
    deadmanTimerInitialize();
    // printf("Deadman Timer Initialized\n\r");
    
    // Enable status LED supply rail
    STATUS_LED_ENABLE_PIN = HIGH;
    // printf("Status LEDs enabled\r\n");
    
    // Disable RESET LED
    RESET_LED_PIN = LOW;
    // printf("Reset LED disabled\r\n");
    
    // terminalTextAttributesReset();
    // terminalTextAttributes(YELLOW, BLACK, NORMAL);
    // printf("\n\rType 'Help' for list of supported commands, press enter twice after reset\n\r\n\r");
    // terminalTextAttributesReset();
    
    // Main loop
    while (true) {
     
        Nop();
        
    }
}
