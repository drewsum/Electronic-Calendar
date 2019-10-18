
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "usb_uart_rx_lookup_table.h"
#include "usb_uart.h"
#include "uthash.h"

#include "terminal_control.h"
#include "device_control.h"
#include "heartbeat_timer.h"
#include "cause_of_reset.h"
#include "rtcc.h"
#include "adc.h"
#include "error_handler.h"


void helpCommandFunction(char * input_str) {
 
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("Supported Commands:\n\r");
    
    // iterate over usb_uart_commands hash table and print the name of all commands and their help messages
    usb_uart_command_t *current_command, *temp;
    HASH_ITER(hh, usb_uart_commands, current_command, temp) {
        
        printf("    %s: %s\r\n", current_command->command_name, current_command->command_help_message);
        
    }
    
    printf("Help messages and neutral responses appear in yellow\n\r");
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminalTextAttributes(CYAN, BLACK, NORMAL);
    printf("Measurement responses appear in cyan\n\r");
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("Errors and negative responses appear in red\n\r");
    terminalTextAttributesReset();
    printf("User input appears in white\n\r");
         
    
}

void resetCommandFunction(char * input_str) {
 
    deviceReset();
    
}

// This function must be called to set up the usb_uart_commands hash table
// Entries into this hash table are "usb_uart serial commands"
void usbUartHashTableInitialize(void) {
    
    usbUartHashTableAdd("Help", "Prints help message for all supported serial commands", helpCommandFunction);
    usbUartHashTableAdd("Reset", "Executes an MCU software reset", resetCommandFunction);
    
    
}


//
//// ************************************************************************************************************
//// This usb_uart command clears the serial terminal
//void clearCommandFunction(void) {
//    terminalClearScreen();
//    terminalSetCursorHome();
//} usb_uart_command_s clear_command = {      "Clear",
//                                            "Clears the serial terminal",
//                                            clearCommandFunction};
//
//// ************************************************************************************************************
//// This usb_uart command returns the device identification string
//void idnCommandFunction(void) {
//    terminalTextAttributesReset();
//    terminalTextAttributes(GREEN, BLACK, NORMAL);
//    printf("Electronic Calendar\r\n");
//    terminalTextAttributesReset();    
//} usb_uart_command_s idn_command = {        "*IDN?",
//                                            "Prints identification string",
//                                            idnCommandFunction};
//
//// ************************************************************************************************************
//// This usb_uart command prints MCU silicon revision, device id, and serial number
//void mcuIdCommandFunction(void) {
//    
//    terminalTextAttributesReset();
//    terminalTextAttributes(GREEN, BLACK, NORMAL);
//    
//    // Print serial number
//    printf("    PIC32MZ Serial Number retrieved from Flash: %s\n\r",
//                getStringSerialNumber());
//        
//    // Print device ID
//    printf("    Device ID retrieved from Flash: %s (0x%X)\n\r", 
//        getDeviceIDString(getDeviceID()), 
//        getDeviceID());
//
//        // Print revision ID
//    printf("    Revision ID retrieved from Flash: %s (0x%X)\n\r", 
//        getRevisionIDString(getRevisionID()), 
//        getRevisionID());
//
//    terminalTextAttributesReset();
//    
//} usb_uart_command_s mcu_id_command = {     "MCU IDs?",
//                                            "Prints microcontroller serial number, device ID, and silicon revision ID",
//                                            mcuIdCommandFunction};
//
//// ************************************************************************************************************
//// This usb_uart command prints MCU status (WDT, DMT and Prefetch information)
//void mcuStatusCommandFunction(void) {
//
//    printWatchdogStatus();
//        
//    printDeadmanStatus();
//        
//    printPrefetchStatus();
//
//} usb_uart_command_s mcu_status_command = {     "MCU Status?",
//                                            "Prints the status of the watchdog timer, deadman timer and predictive prefetch module",
//                                            mcuStatusCommandFunction};