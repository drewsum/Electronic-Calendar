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
    
    // Initialize UART USB debugging
//    usbUartInitialize();
//    
//    // Clear the terminal
//    terminalClearScreen();
//    terminalSetCursorHome();
//    terminalTextAttributesReset();

    
    // Print debug message s
//    printf("Logic Board Initializing...\n\r");
//    
//    if (    reset_cause == Undefined ||
//            reset_cause == Primary_Config_Registers_Error ||
//            reset_cause == Primary_Secondary_Config_Registers_Error ||
//            reset_cause == Config_Mismatch ||
//            reset_cause == DMT_Reset ||
//            reset_cause == WDT_Reset ||
//            reset_cause == Software_Reset ||
//            reset_cause == External_Reset ||
//            reset_cause == BOR_Reset) {
//    
//        terminalTextAttributes(RED, BLACK, NORMAL);
//        
//    }
//    
//    else {
//     
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        
//    }
    
    // printf("Cause of most recent device reset: %s\n\r", getResetCauseString(reset_cause));
    
//    terminalTextAttributesReset();
//    terminalTextAttributes(GREEN, BLACK, NORMAL);
//    printf("Clocks Initialized\n\r");
//    printf("Interrupt Controller Initialized, Global Interrupts Enabled\n\r");
//    printf("GPIO Pins Initialized\n\r");
//    printf("USB UART Initialized\n\r");
    
    // Setup error handling
    errorHandlerInitialize();
    // printf("Error Handler Initialized\n\r");
    
    // Setup prefetch module
    // prefetchInitialize();
    // printf("Prefetch Module Initialized\n\r");
    
//    // Setup heartbeat timer
    heartbeatTimerInitialize();
//    printf("Heartbeat Timer Initialized\n\r");
//    
//    // Disable unused peripherals for power savings
//    PMDInitialize();
//    printf("Unused Peripheral Modules Disabled\n\r");
            
    // Setup the watchdog timer
    watchdogTimerInitialize();
    // printf("Watchdog Timer Initialized\n\r");
    
    // Startup the deadman timer
    deadmanTimerInitialize();
    // printf("Deadman Timer Initialized\n\r");
    
    // Enable status LED supply rail
    STATUS_LED_ENABLE_PIN = HIGH;
    
    // Disable RESET LED
    RESET_LED_PIN = LOW;
    
    // Main loop
    while (true) {
     
        Nop();
        
    }
}
