
#include <xc.h>
#include <string.h>
#include <stdio.h>

#include "usb_uart_rx_lookup_table.h"

#include "terminal_control.h"
#include "device_control.h"
#include "heartbeat_timer.h"
#include "cause_of_reset.h"
#include "rtcc.h"

// This function is what interprets strings sent over USB Virtual COM Port
void usb_uart_rx_lookup_table(char * input_string) {
 
    // Remove trailing newlines and carriage returns
    strtok(input_string, "\n");
    strtok(input_string, "\r");
    
    // Determine if received string has a match
    if (strcomp(input_string, "Help") == 0) {
     
        usbUartPrintHelpMessage();
        
    }
    
    
    else if (strcomp(input_string, "Reset") == 0) {

         deviceReset();
        
    }
    
    else if (strcomp(input_string, "Clear") == 0) {
     
        terminalClearScreen();
        terminalSetCursorHome();
        
    }
    
    else if (strcomp(input_string, "*IDN?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Electronic Calendar\r\n");
        terminalTextAttributesReset();
        
    }
    
    else if (strcomp(input_string, "MCU IDs?") == 0) {
     
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
    
    else if (strcomp(input_string, "MCU Status?") == 0) {
     
        printWatchdogStatus();
        
        printDeadmanStatus();
        
        printPrefetchStatus();
        
        
    }
    
    else if (strcomp(input_string, "Interrupt Status?") == 0) {
     
        // Print function from interrupt control module
        printInterruptStatus();
        
    }
    
    else if (strcomp(input_string, "Clock Status?") == 0) {
     
        printClockStatus(SYSCLK_INT);
        
    }
    
    else if (strcomp(input_string, "Device On Time?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("On time since last device reset: %s\n\r", 
                getStringSecondsAsTime(device_on_time_counter));
        terminalTextAttributesReset();
        
    }
    
    else if (strcomp(input_string, "Error Status?") == 0) {
     
        // Print error handler status
        printErrorHandlerStatus();
        
        // Print help message
        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("\n\rCall 'Clear Errors' command to clear any errors that have been set\n\r");
        terminalTextAttributesReset();
        
        
    }
    
    else if (strcomp(input_string, "Clear Errors") == 0) {
     
        // Zero out all error handler flags
        clearErrorHandler();
        
        // Update error LEDs based on error handler status
        updateErrorLEDs();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Error Handler flags cleared\n\r");
        terminalTextAttributesReset();
        
    }
    
     else if (strcomp(input_string, "Cause of Reset?") == 0) {
     
        terminalTextAttributesReset();
        
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
        
        printf("Cause of the most recent device reset: %s\n\r",
                getResetCauseString(reset_cause));
        terminalTextAttributesReset();
        
    }
    
    else if (strcomp(input_string, "PMD Status?") == 0) {
     
        printPMDStatus();
        
    }
    
    else if (strcomp(input_string, "Time and Date?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Current system time and date:\r\n   ");
        printTimeAndDate();
        terminalTextAttributesReset();
        
    }
    
    else if (strstart(input_string, "Set Date: ") == 0) {
     
        // Snipe out received string
        uint32_t read_month, read_day, read_year;
        sscanf(input_string, "Set Date: %u/%u/%u", &read_month, &read_day, &read_year);
        
        // Write received data into RTCC
        if (read_year >= 2000) {
            
            rtccWriteDate((uint8_t) read_month, (uint8_t) read_day, (uint16_t) read_year);

            // print out what we just did
            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            printf("Set RTCC date as %02u/%02u/%04u\r\n", rtcc_shadow.month, rtcc_shadow.day, rtcc_shadow.year);
            terminalTextAttributesReset();
        
        }
        
        // return error if year < 2000
        else {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Enter a valid date after 01/01/2000. User entered %02u/%02u/%04u\r\n", read_month, read_day, read_year);
            terminalTextAttributesReset();
            
        }
        
    }
    
    else if (strstart(input_string, "Set Time: ") == 0) {
     
        // Snipe out received string
        uint32_t read_hour, read_minute, read_second;
        sscanf(input_string, "Set Time: %u:%u:%u", &read_hour, &read_minute, &read_second);
                    
        rtccWriteTime((uint8_t) read_hour, (uint8_t) read_minute, (uint16_t) read_second);

        // print out what we just did
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Set RTCC time as %02u:%02u:%02u\r\n", rtcc_shadow.hours, rtcc_shadow.minutes, rtcc_shadow.seconds);
        terminalTextAttributesReset();

    }
    
    else if (strstart(input_string, "Set Weekday: ") == 0) {
     
        char read_weekday[16];
        uint8_t read_weekday_enum;
        sscanf(input_string, "Set Weekday: %s", &read_weekday);
        
        if (strcmp(read_weekday, "Sunday") == 0) read_weekday_enum = 0;
        else if (strcmp(read_weekday, "Monday") == 0) read_weekday_enum = 1;
        else if (strcmp(read_weekday, "Tuesday") == 0) read_weekday_enum = 2;
        else if (strcmp(read_weekday, "Wednesday") == 0) read_weekday_enum = 3;
        else if (strcmp(read_weekday, "Thursday") == 0) read_weekday_enum = 4;
        else if (strcmp(read_weekday, "Friday") == 0) read_weekday_enum = 5;
        else if (strcmp(read_weekday, "Saturday") == 0) read_weekday_enum = 6;
        else read_weekday_enum = 255;

        if (read_weekday_enum != 255) {

            // print out what we just did
            terminalTextAttributesReset();
            terminalTextAttributes(GREEN, BLACK, NORMAL);
            rtccWriteWeekday(read_weekday_enum);
            printf("Set RTCC weekday as %s\r\n", getDayOfWeek(rtcc_shadow.weekday));
            terminalTextAttributesReset();

        }
        
        else {
        
            terminalTextAttributesReset();
            terminalTextAttributes(RED, BLACK, NORMAL);
            printf("Please enter a valid day of the weekday. Input is case sensitive\r\n");
            terminalTextAttributesReset();
            
        }
            
    }

    
    // increment the number of strings we've received
    num_strings_received++;
    
}

// Print help message, prints out list of all commands
void usbUartPrintHelpMessage(void) {
    
    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW, BLACK, NORMAL);
    printf("Supported Commands:\n\r");
    printf("    Reset: Software Reset\n\r");
    printf("    Clear: Clears the terminal\n\r");
    printf("    Cause of Reset?: Prints the cause of the most recent device reset\n\r");
    printf("    *IDN?: Prints identification string\n\r");
    printf("    MCU IDs?: Print microcontroller serial number, device ID, and silicon revision ID\r\n");
    printf("    MCU Status?: Prints the status of the watchdog timer, deadman timer and predictive prefetch module\n\r");
    printf("    Device On Time?: Returns the device on time since last reset\n\r");
    printf("    PMD Status?: Prints the state of Peripheral Module Disable settings\n\r");
    printf("    Interrupt Status? Prints information on interrupt settings\n\r");
    printf("    Clock Status?: Prints system clock settings\n\r");
    printf("    Error Status?: Prints the state of system error flags\n\r");
    printf("    Clear Errors: Clears all error handler flags\n\r");
    printf("    Time and Date?: Prints the current system time and date\r\n");
    printf("    Set Date: <month>/<date>/<year>: Sets the system date as date entered\r\n");
    printf("    Set Time: <hour>:<minute>:<second>: Sets the system time as time entered. Must be 24 hour time\r\n");
    printf("    Set Weekday: Sets the system weekday as day entered. Case sensitive, capitalize\r\n");
    printf("    Help: This Command\n\r");
    
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

// This function is a custom string compare
// Compares all characters in two strings after the first character (0th index)
// if the input string is the first received over USB UART
// Runs a normal string compare if it's not the first string
// returns 0 if strings match
// returns 1 if they don't
uint8_t strcomp(const char * haystack, const char * needle) {
    if (num_strings_received == 0) {

        // First check to see if needle is longer than haystack, if it is 
        // we already know this is not a match
        if (strlen(needle) > strlen(haystack)) return 1;
        if (strlen(needle) < strlen(haystack)) return 1;

        // Next loop through each element in needle to see if it matches the 
        // same character in haystack at the same position
        // If the characters do not match, return 1
        // After the loop, return 0 for exit success
        // skip the first character, start looping at index 1
        uint8_t char_index;
        for(char_index = 1; char_index < strlen(needle); char_index++) {

            // Return a 1 if there is not a match
            if (needle[char_index] != haystack[char_index]) return 1;

        }

        // return a 0 for exit success
        return 0;

    }
    
    // return a string compare after we've received more than one string
    else return strcmp(needle, haystack);
        
}