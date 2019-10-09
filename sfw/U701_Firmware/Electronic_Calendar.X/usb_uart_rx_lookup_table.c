
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "usb_uart_rx_lookup_table.h"

#include "terminal_control.h"
#include "device_control.h"
#include "heartbeat_timer.h"

// This function is what interprets strings sent over USB Virtual COM Port
void usb_uart_rx_lookup_table(char * input_string) {
 
    if (strcmp(input_string, "POWER TEAM\r\n") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(BLACK, RED, NORMAL);
        printf("Todd Keene is back, with the ultimate strength team\r\n");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(input_string, "Help\r\n") == 0) {
     
        usbUartPrintHelpMessage();
        
    }
    
    else if (strcmp(input_string, "Reset\r\n") == 0) {

         deviceReset();
        
    }
    
    else if (strcmp(input_string, "Clear\r\n") == 0) {
     
        terminalClearScreen();
        terminalSetCursorHome();
        
    }
    
    else if (strcmp(input_string, "*IDN?\r\n") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Electronic Calendar\r\n");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(input_string, "MCU IDs?\r\n") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        
        // Print serial number
        printf("    PIC32MZ Serial Number retrieved from Flash: %s\n\r",
                getStringSerialNumber());
        
        // Print device ID
        printf("    Device ID retrieved from Flash: %s (0x%X)\n\r", 
            getDeviceIDString(getDeviceID()), 
            getDeviceID());

        // Print revision ID
        printf("    Revision ID retrieved from Flash: %s (0x%X)\n\r", 
            getRevisionIDString(getRevisionID()), 
            getRevisionID());

        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(input_string, "MCU Status?\r\n") == 0) {
     
        printWatchdogStatus();
        
        printDeadmanStatus();
        
        printPrefetchStatus();
        
        
    }
    
    else if (strcmp(input_string, "Interrupt Status?\r\n") == 0) {
     
        // Print function from interrupt control module
        printInterruptStatus();
        
    }
    
    else if (strcmp(input_string, "Clock Status?\r\n") == 0) {
     
        printClockStatus(SYSCLK_INT);
        
    }
    
    else if (strcmp(input_string, "Device On Time?\r\n") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("On time since last device reset: %s\n\r", 
                getStringSecondsAsTime(device_on_time_counter));
        terminalTextAttributesReset();
        
    }
    
}

// Print help message, prints out list of all commands
void usbUartPrintHelpMessage(void) {
    
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("Supported Commands:\n\r");
    printf("    Reset: Software Reset\n\r");
    printf("    Clear: Clears the terminal\n\r");
    // printf("    Cause of Reset?: Prints the cause of the most recent device reset\n\r");
    printf("    *IDN?: Prints identification string\n\r");
    printf("    MCU IDs?: Print microcontroller serial number, device ID, and silicon revision ID\r\n");
    printf("    MCU Status?: Prints the status of the watchdog timer, deadman timer and predictive prefetch module\n\r");
    printf("    Device On Time?: Returns the device on time since last reset\n\r");
    //printf("    PMD Status?: Prints the state of Peripheral Module Disable settings\n\r");
    printf("    Interrupt Status? Prints information on interrupt settings\n\r");
    printf("    Clock Status?: Prints system clock settings\n\r");
    //printf("    Error Status?: Prints the state of system error flags\n\r");
    //printf("    Clear Errors: Clears all error handler flags\n\r");
    printf("    Help: This Command\n\r");
    
    printf("Help messages and neutral responses appear in yellow\n\r");
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminalTextAttributes(CYAN, BLACK, NORMAL);
    printf("Measurement responses and WiFi responses appear in cyan\n\r");
    terminalTextAttributes(RED, BLACK, NORMAL);
    printf("Errors and negative responses appear in red\n\r");
    terminalTextAttributesReset();
    printf("User input appears in white\n\r");
         
}


// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds) {
 
    uint32_t years, days, hours, minutes, seconds, remainder;
    static char return_string[80];
    
    // clear return string
    int i;
    for (i = 0; i < strlen(return_string); i++) {
     
        return_string[i] = '\0';
        
    }
    
    char buff[20];
    
    years = input_seconds / (60 * 60 * 24 * 365);
    input_seconds -= years * (60 * 60 * 24 * 365);
    days = input_seconds / (60 * 60 * 24);
    input_seconds -= days * (60 * 60 * 24);
    hours = input_seconds / (60 * 60);
    input_seconds -= hours * (60 * 60);
    minutes = input_seconds / 60;
    input_seconds -= minutes * 60;
    seconds = input_seconds;
    
    if (years > 0) {
        
        if (years == 1) {
         
            sprintf(buff, "%d year, ", years);
            
        }
        
        else {
         
            sprintf(buff, "%d years, ", years);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (days > 0) {
     
        if (days == 1) {
         
            sprintf(buff, "%d day, ", days);
            
        }
        
        else {
         
            sprintf(buff, "%d days, ", days);
            
        }
        
        strcat(return_string, buff);
    }
    
    if (hours > 0) {
     
        if (hours == 1) {
         
            sprintf(buff, "%d hour, ", hours);
            
        }
        
        else {
         
            sprintf(buff, "%d hours, ", hours);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (minutes > 0) {
     
        if (minutes == 1) {
         
            sprintf(buff, "%d minute, ", minutes);
            
        }
        
        else {
         
            sprintf(buff, "%d minutes, ", minutes);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    if (seconds > 0) {
     
        if (seconds == 1) {
         
            sprintf(buff, "%d second", seconds);
            
        }
        
        else {
         
            sprintf(buff, "%d seconds", seconds);
            
        }
        
        strcat(return_string, buff);
        
    }
    
    return return_string;
    
}

// This function compares the "needle" string parameter to see if it is the 
// beginning of the "haystack" string variable
// Returns 0 for success, 1 for failure
uint8_t strstart(const char * haystack, const char * needle) {
 
    // First check to see if needle is longer than haystack, if it is 
    // we already know this is not a match
    if (strlen(needle) >= strlen(haystack)) return 1;
    
    // Next loop through each element in needle to see if it matches the 
    // same character in haystack at the same position
    // If the characters do not match, return 1
    // After the loop, return 0 for exit success
    uint8_t char_index;
    for(char_index = 0; char_index < strlen(needle); char_index++) {
        
        // Return a 1 if there is not a match
        if (needle[char_index] != haystack[char_index]) return 1;
        
    }
    
    // return a 0 for exit success
    return 0;
    
}