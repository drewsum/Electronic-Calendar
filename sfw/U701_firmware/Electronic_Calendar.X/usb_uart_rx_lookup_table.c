
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
#include "misc_IO_functions.h"
#include "telemetry.h"

usb_uart_command_function_t helpCommandFunction(char * input_str) {

    terminalTextAttributesReset();
    terminalTextAttributes(YELLOW_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Supported Commands:\n\r");
    
    terminalTextAttributes(YELLOW_COLOR, BLACK_COLOR, NORMAL_FONT);
    
    // iterate over usb_uart_commands hash table and print the name of all commands and their help messages
    usb_uart_command_t  *current_command, *temp;
    HASH_ITER(hh, usb_uart_commands, current_command, temp) {
            
        printf("    %s: %s\r\n", current_command->command_name, current_command->command_help_message);
        
    }
    
    terminalTextAttributes(YELLOW_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("\r\nHelp messages and neutral responses appear in yellow\n\r");
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Measurement responses appear in cyan\n\r");
    terminalTextAttributes(MAGENTA_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Urgent/interrupt messages appear in cyan\n\r");
    terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Errors and negative responses appear in red\n\r");
    terminalTextAttributesReset();
    printf("User input appears in white\n\r");
         
    
}

usb_uart_command_function_t resetCommand(char * input_str) {
 
    deviceReset();
    
}

usb_uart_command_function_t clearCommand(char * input_str) {

    terminalClearScreen();
    terminalSetCursorHome();
    
}

usb_uart_command_function_t idnCommand(char * input_str) {
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Electronic Calendar by Drew Maatman, 2019\r\n");
    terminalTextAttributesReset();    
}

usb_uart_command_function_t causeOfResetCommand(char * input_str) {
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
    
    printf("Cause of most recent device reset: %s\r\n", getResetCauseString(reset_cause));
    terminalTextAttributesReset();
}

usb_uart_command_function_t mcuIdCommand(char * input_str) {
    
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    
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

usb_uart_command_function_t mcuStatusCommand(char * input_str) {

    printWatchdogStatus();
        
    printDeadmanStatus();
        
    printPrefetchStatus();

}

usb_uart_command_function_t interruptStatusCommand(char * input_str) {
 
    printInterruptStatus();
    
}

usb_uart_command_function_t clockStatusCommand(char * input_str) {

    printClockStatus(SYSCLK_INT);
    
}

usb_uart_command_function_t deviceOnTimeComand(char * input_str) {
 
    terminalTextAttributesReset();
        terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("On time since last device reset: %s\n\r", 
                getStringSecondsAsTime(device_on_time_counter));
        terminalTextAttributesReset();
    
}

usb_uart_command_function_t errorStatusCommand(char * input_str) {
 
    // Print error handler status
    printErrorHandlerStatus();

    // Print help message
    terminalTextAttributes(YELLOW_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("\n\rCall 'Clear Errors' command to clear any errors that have been set\n\r");
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t clearErrorsCommand(char * input_str) {
 
    // Zero out all error handler flags
    clearErrorHandler();

    // Update error LEDs based on error handler status
    update_error_leds_flag = 1;

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Error Handler flags cleared\n\r");
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t causeOfResetCOmmand(char * input_str) {
 
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

        terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);

    }

    else {

        terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);

    }

    printf("Cause of the most recent device reset: %s\n\r",
            getResetCauseString(reset_cause));
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t pmdStatusCommand(char * input_str) {
 
    printPMDStatus();
    
}

usb_uart_command_function_t timeAndDateCommand(char * input_str) {
 
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Current system time and date:\r\n   ");
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printTimeAndDate();
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t setDateCommand(char * input_str) {
 
    // Snipe out received string
    uint32_t read_month, read_day, read_year;
    sscanf(input_str, "Set Date: %u/%u/%u", &read_month, &read_day, &read_year);

    // Write received data into RTCC
    if (read_year >= 2000) {

        rtccWriteDate((uint8_t) read_month, (uint8_t) read_day, (uint16_t) read_year);

        // print out what we just did
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("Set RTCC date as %02u/%02u/%04u\r\n", rtcc_shadow.month, rtcc_shadow.day, rtcc_shadow.year);
        terminalTextAttributesReset();

    }

    // return error if year < 2000
    else {

        terminalTextAttributesReset();
        terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("Enter a valid date after 01/01/2000. User entered %02u/%02u/%04u\r\n", read_month, read_day, read_year);
        terminalTextAttributesReset();

    }
    
}

usb_uart_command_function_t setTimeCommand(char * input_str) {
 
    // Snipe out received string
    uint32_t read_hour, read_minute, read_second;
    sscanf(input_str, "Set Time: %u:%u:%u", &read_hour, &read_minute, &read_second);

    rtccWriteTime((uint8_t) read_hour, (uint8_t) read_minute, (uint16_t) read_second);

    // print out what we just did
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Set RTCC time as %02u:%02u:%02u\r\n", rtcc_shadow.hours, rtcc_shadow.minutes, rtcc_shadow.seconds);
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t setWeekdayCommand(char * input_str) {
 
     char read_weekday[16];
    uint8_t read_weekday_enum;
    sscanf(input_str, "Set Weekday: %s", &read_weekday);

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
        terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
        rtccWriteWeekday(read_weekday_enum);
        printf("Set RTCC weekday as %s\r\n", getDayOfWeek(rtcc_shadow.weekday));
        terminalTextAttributesReset();

    }

    else {

        terminalTextAttributesReset();
        terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("Please enter a valid day of the weekday. Input is case sensitive\r\n");
        terminalTextAttributesReset();

    }
    
}

usb_uart_command_function_t adcStatusCommand(char * input_str) {
 
    printADCStatus();
    
}

usb_uart_command_function_t telemetryCommand(char * input_str) {
 
    if (error_handler.flags.ADC_configuration_error) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, BOLD_FONT);
            printf("Most recent system telemetry:\n\r");
            terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, NORMAL_FONT);
            printf("    +12V Input Voltage: %+0.3f V\n\r", telemetry.current.params.pos12_voltage);
            printf("    +12V Input Current: %+0.3f A\n\r", telemetry.current.params.pos12_current);
            printf("    +12V Input MOSFET Temperature: %+0.3f C\n\r", telemetry.current.params.input_temperature);
            printf("    +3.3V Power Supply Voltage: %+0.3f V\n\r", telemetry.current.params.pos3p3_voltage);
            printf("    +3.3V Power Supply Current: %+0.3f A\n\r", telemetry.current.params.pos3p3_current);
            printf("    +3.3V Power Supply Temperature: %+0.3f C\n\r", telemetry.current.params.pos3p3_temperature);
            printf("    +5V USB Power Supply Voltage: %+0.3f V\n\r", telemetry.current.params.pos5_usb_voltage);
            printf("    Backup Battery Voltage: %+0.3f V\n\r", telemetry.current.params.vbat_voltage);
            printf("    Backup Ideal Diode Temperature: %+0.3f C\n\r", telemetry.current.params.backup_temperature);
            printf("    Internal VREF Voltage: %+0.3f V\n\r", telemetry.current.params.mcu_vref_voltage);
            printf("    Internal Die Temperature Temperature: %+0.3f C\n\r", telemetry.current.params.mcu_die_temp);
            printf("    Ambient Temperature: %+0.3f C\n\r", telemetry.current.params.ambient_temperature);
            terminalTextAttributesReset();

        }
    
}

usb_uart_command_function_t minTelemetryCommand(char * input_str) {
 
    if (error_handler.flags.ADC_configuration_error) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, BOLD_FONT);
            printf("Minimum system telemetry recorded:\n\r");
            terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, NORMAL_FONT);
            printf("    +12V Input Voltage: %+0.3f V\n\r", telemetry.min.params.pos12_voltage);
            printf("    +12V Input Current: %+0.3f A\n\r", telemetry.min.params.pos12_current);
            printf("    +12V Input MOSFET Temperature: %+0.3f C\n\r", telemetry.min.params.input_temperature);
            printf("    +3.3V Power Supply Voltage: %+0.3f V\n\r", telemetry.min.params.pos3p3_voltage);
            printf("    +3.3V Power Supply Current: %+0.3f A\n\r", telemetry.min.params.pos3p3_current);
            printf("    +3.3V Power Supply Temperature: %+0.3f C\n\r", telemetry.min.params.pos3p3_temperature);
            printf("    +5V USB Power Supply Voltage: %+0.3f V\n\r", telemetry.min.params.pos5_usb_voltage);
            printf("    Backup Battery Voltage: %+0.3f V\n\r", telemetry.min.params.vbat_voltage);
            printf("    Backup Ideal Diode Temperature: %+0.3f C\n\r", telemetry.min.params.backup_temperature);
            printf("    Internal VREF Voltage: %+0.3f V\n\r", telemetry.min.params.mcu_vref_voltage);
            printf("    Internal Die Temperature Temperature: %+0.3f C\n\r", telemetry.min.params.mcu_die_temp);
            printf("    Ambient Temperature: %+0.3f C\n\r", telemetry.min.params.ambient_temperature);
            terminalTextAttributesReset();

        }
    
}

usb_uart_command_function_t maxTelemetryCommand(char * input_str) {
 
    if (error_handler.flags.ADC_configuration_error) {
         
            terminalTextAttributesReset();
            terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
            printf("ADC Configuration Error\n\r");
            terminalTextAttributesReset();
            
        }
        
        else {

            terminalTextAttributesReset();
            terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, BOLD_FONT);
            printf("Maximum system telemetry recorded:\n\r");
            terminalTextAttributes(CYAN_COLOR, BLACK_COLOR, NORMAL_FONT);
            printf("    +12V Input Voltage: %+0.3f V\n\r", telemetry.max.params.pos12_voltage);
            printf("    +12V Input Current: %+0.3f A\n\r", telemetry.max.params.pos12_current);
            printf("    +12V Input MOSFET Temperature: %+0.3f C\n\r", telemetry.max.params.input_temperature);
            printf("    +3.3V Power Supply Voltage: %+0.3f V\n\r", telemetry.max.params.pos3p3_voltage);
            printf("    +3.3V Power Supply Current: %+0.3f A\n\r", telemetry.max.params.pos3p3_current);
            printf("    +3.3V Power Supply Temperature: %+0.3f C\n\r", telemetry.max.params.pos3p3_temperature);
            printf("    +5V USB Power Supply Voltage: %+0.3f V\n\r", telemetry.max.params.pos5_usb_voltage);
            printf("    Backup Battery Voltage: %+0.3f V\n\r", telemetry.max.params.vbat_voltage);
            printf("    Backup Ideal Diode Temperature: %+0.3f C\n\r", telemetry.max.params.backup_temperature);
            printf("    Internal VREF Voltage: %+0.3f V\n\r", telemetry.max.params.mcu_vref_voltage);
            printf("    Internal Die Temperature Temperature: %+0.3f C\n\r", telemetry.max.params.mcu_die_temp);
            printf("    Ambient Temperature: %+0.3f C\n\r", telemetry.max.params.ambient_temperature);
            terminalTextAttributesReset();

        }
    
}

usb_uart_command_function_t setUnixTimeCommand(char * input_str) {
 
    // Snipe out received string
    uint32_t read_unix_time, read_offset;
    sscanf(input_str, "Set Unix Time: %lu, %d", &read_unix_time, &read_offset);

    // remove timezone from unix time (this converts from UTC to local time)
    read_offset *= 3600;                // convert from hours to seconds
    read_unix_time += read_offset;      // add or remove these seconds to read unix time
    
    // write unix time into RTCC
    rtccWriteUnixTime(read_unix_time);

    // print out what we just did
    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("Set RTCC time as %02u:%02u:%02u\r\n", rtcc_shadow.hours, rtcc_shadow.minutes, rtcc_shadow.seconds);
    printf("Set RTCC date as %02u/%02u/%04u\r\n", rtcc_shadow.month, rtcc_shadow.day, rtcc_shadow.year);
    printf("Set RTCC weekday as %s\r\n", getDayOfWeek(rtcc_shadow.weekday));
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t pgoodStatusCommand(char * input_str) {
 
    printPGOODStatus();
    
}

usb_uart_command_function_t vbatIsolateCommand(char * input_str) {
 
    // Snipe out received string
    uint32_t read_isolation;
    sscanf(input_str, "Set Battery Isolation: %u", &read_isolation);
    
    if (read_isolation > 1) {
     
        terminalTextAttributes(RED_COLOR, BLACK_COLOR, BOLD_FONT);
        printf("Please enter a valid VBAT isolation state: 1 for true (isolated) / 0 for false (connected)\r\n");
        
    }
    
    else {
     
        nVBAT_ISOLATE_PIN = (read_isolation & 0b1);
        pgood_status.VBAT_ISOLATE = !(nVBAT_ISOLATE_PIN);
        if (pgood_status.VBAT_ISOLATE) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
        else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("    Backup Battery is %s Ideal Diode\n\r", pgood_status.VBAT_ISOLATE ? "connected to" : "isolated from");
        
    }
    
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t getRTCCCalCommand(char * input_str) {
 
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("RTCC Calibration Value currently set to 0x%03X\r\n", getRTCCCalibration());
    terminalTextAttributesReset();
    
}

usb_uart_command_function_t setRTCCCalCommand(char * input_str) {
 
    // Snipe out received string
    uint32_t read_cal;
    sscanf(input_str, "Set RTCC Calibration: 0x%03X", &read_cal);
    
    if (read_cal > 0x3FF) {
     
        terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("Please enter a valid 10 bit hexadecimal calibration value, up to 0x3FF\r\n");
        printf("See PIC32 reference manual for determining calibration value\r\n");
        terminalTextAttributesReset();
        
    }
    
    else {

        terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
        printf("Calibrating RTCC, please wait...\r\n");

        setRTCCCalibration(read_cal);

        printf("RTCC Calibration Value set to 0x%03X\r\n", getRTCCCalibration());
        terminalTextAttributesReset();

    }
        
}



usb_uart_command_function_t easterEggCommand(char * input_str) {
 
    terminalClearScreen();
    terminalSetCursorHome();
    
    terminalTextAttributes(MAGENTA_COLOR, BLACK_COLOR, NORMAL_FONT);
    
    printf(

"                     _   _____ _             _           _       _          _     _           _                  \r\n"
"     /\\             | | |_   _( )           | |         | |     | |        | |   (_)         | |                 \r\n"
"    /  \\   _ __   __| |   | | |/ _ __ ___   | | ___  ___| |_    | |__   ___| |__  _ _ __   __| |                 \r\n"
"   / /\\ \\ | '_ \\ / _` |   | |   | '_ ` _ \\  | |/ _ \\/ __| __|   | '_ \\ / _ \\ '_ \\| | '_ \\ / _` |                 \r\n"
"  / ____ \\| | | | (_| |  _| |_  | | | | | | | | (_) \\__ \\ |_ _  | |_) |  __/ | | | | | | | (_| |                 \r\n"
" /_/    \\_\\_| |_|\\__,_| |_____| |_| |_| |_| |_|\\___/|___/\\__( ) |_.__/ \\___|_| |_|_|_| |_|\\__,_|                 \r\n"
"  _______ _                                  _       _____ _|/ _                                __ _           _ \r\n"
" |__   __| |                                | |     |_   _( ) | |                              / _(_)         | |\r\n"
"    | |  | |__   ___  __      _____  _ __ __| |___    | | |/| | |  _ __   _____   _____ _ __  | |_ _ _ __   __| |\r\n"
"    | |  | '_ \\ / _ \\ \\ \\ /\\ / / _ \\| '__/ _` / __|   | |   | | | | '_ \\ / _ \\ \\ / / _ \\ '__| |  _| | '_ \\ / _` |\r\n"
"    | |  | | | |  __/  \\ V  V / (_) | | | (_| \\__ \\  _| |_  | | | | | | |  __/\\ V /  __/ |    | | | | | | | (_| |\r\n"
"    |_|  |_| |_|\\___|_  \\_/\\_/ \\___/|_|  \\__,_|___/ |_____| |_|_| |_| |_|\\___| \\_/ \\___|_| _  |_| |_|_| |_|\\__,_|\r\n"
"     /\\             | | |_   _( )           | |     / _| |   | |        | |   (_)         | |                    \r\n"
"    /  \\   _ __   __| |   | | |/ _ __ ___   | | ___| |_| |_  | |__   ___| |__  _ _ __   __| |                    \r\n"
"   / /\\ \\ | '_ \\ / _` |   | |   | '_ ` _ \\  | |/ _ \\  _| __| | '_ \\ / _ \\ '_ \\| | '_ \\ / _` |                    \r\n"
"  / ____ \\| | | | (_| |  _| |_  | | | | | | | |  __/ | | |_  | |_) |  __/ | | | | | | | (_| |                    \r\n"
" /_/    \\_\\_| |_|\\__,_| |_____| |_| |_| |_| |_|\\___|_|  \\__| |_.__/ \\___|_| |_|_|_| |_|\\__,_|                    \r\n"
"     /\\                                                        | | |               | |                           \r\n"
"    /  \\   ___   ___  ___  __ _ ___  ___  _ __  ___   _ __ ___ | | |   ___  _ __   | |__  _   _                  \r\n"
"   / /\\ \\ / __| / __|/ _ \\/ _` / __|/ _ \\| '_ \\/ __| | '__/ _ \\| | |  / _ \\| '_ \\  | '_ \\| | | |                 \r\n"
"  / ____ \\\\__ \\ \\__ \\  __/ (_| \\__ \\ (_) | | | \\__ \\ | | | (_) | | | | (_) | | | | | |_) | |_| |                 \r\n"
" /_/    \\_\\___/ |___/\\___|\\__,_|___/\\___/|_| |_|___/ |_|  \\___/|_|_|  \\___/|_| |_| |_.__/ \\__, |                 \r\n"
"                                                                                           __/ |                 \r\n"
"                                                                                          |___/                  \r\n"
"                                                                                                                   \r\n"
"                                                                                           -- Chris Cornell\r\n"
"\r\n"
"        **.                                                                                                                                           \r\n"
"        ,     (                                                  *./  ..,,   .*                                                                       \r\n"
"              ((                                               .   , ..,  ../  .                                                                      \r\n"
"        .  .///##(                                           /      .*  ..* /.   /                                                                    \r\n"
"              *//(%#,                                     ./. .. , .  ((%%%#,* ,                                                                      \r\n"
"                ..*/##(.                                   . .. ,/  ,*##%%&&%#   ,.                                                                   \r\n"
"                . .*/((#(#(,                             ,.   ..    .,(#%%%%%##  ..                                                                   \r\n"
"                   */((#####((#*                        . (/       * //((#%%&%#   ..                                                                  \r\n"
"                     ,/##########(.                    . ,    .  , (%(/*%%/&.,/  *                                                                    \r\n"
"                      ,/*(#########...                  .,     * ,,/#%%%(##(..                                                                      \r\n"
"                        .,*((((#%#%   ..,                      , .,/(##%%/%%##  ,                                                                     \r\n"
"                           ,*/##%#     .......,               #  ,*(*(#(##**#(    .                                                                   \r\n"
"                              ,*/          ..........       .(*    *(((#,.  #.  .                                                                     \r\n"
"                                              .. .  ....   *        ./##,.,(.                                                                         \r\n"
"                                                   .     .    #* *       ,                                                                            \r\n"
"                                                      ....      ,(,   ..%,.                                                                           \r\n"
"                                                     . .  ..     (#%*%#%%.,* ......                                                                   \r\n"
"                                                       .       .  .,%%%%.. (/  .....                                                                  \r\n"
"                                                              .    .       .*/    ....                                                                \r\n"
"                                                      .      . .  .       .*,*    .....                                                               \r\n"
"                                                            .  .          ..***.   .....                                                              \r\n"
"                                                           .     .   .   . .,**     .. ..                                                             \r\n"
"                                                      .. .    .     .   .   **/, .   ....,.                                                           \r\n"
"                                                       ..    .           . .//**.  ..,. . ..                                                          \r\n"
"                                                        ...            ..  .**** .     ..  ..                                                         \r\n"
"                                                         ..        .     .   *** .    .     ...                                                       \r\n"
"                                                          .    ..          . ***/             ..,                                                     \r\n"
"                                                          ..     ..   .   .  /***            .    ##/                                                 \r\n"
"                                                             .            .. ,**,               (#(((((//*%##(&%%                                     \r\n"
"                                                                       .  .   **,.             **////,,  .,#.&&%%%                                    \r\n"
"                                               .              .            .  ***,              *,**.    . %%#%%##                                    \r\n"
"                                           . . ..        .     ..       ....  (#(/                        (#%%%%*%                                    \r\n"
"                                           ,                    ..      ...   ****                        /*,*%##                                     \r\n"
"                                          ,.                      ..  .  ..   .**/*                                                                   \r\n"
"                                           .      &////////(.      ... . .     ,///                                                                   \r\n"
"                                              #####%%%%%%%###@      ..       */*/                                                                   \r\n"
"                                          . %(######%#%&&&&&&&%###,    .  .#%%&@%                                                                 \r\n"
"                                        . #((((((####%  &&&&&&&&&&%##@,#%##%###(/(#,                                             ,*  #              \r\n"
"                                         @(((((((####%%%%%@     .&&&&&%%%%#(/****((%                                             .  .  (              \r\n"
"                                        #((///((((####%%%%%%%%&&&&(,&&&%%###((#((%///                                          ,(*(*     *            \r\n"
"                                        ////////(((######%%%%%%%%%%&&&&&%%%%%####%///                  ,%//*,(/#(/(/*(#*(((    (   *   ,            \r\n"
"                                       (//***///(((((########%#&%%,,,*%%%#(#.@@@%@%/((,,/((((//*,//(*(*/,*#(/*##%*,*/(/*/(///        *                \r\n"
"                                       &//*****//*@&@&##(####&/# ,@*%###(# *@/ *((*//%#/*(%%,//*./#/*/(*(&*(#.                 /(  * .              \r\n"
"                                     , #/*%@@(/ ,((#,,*/(#((((.( #/* (#&%# %@/ /#*,.(,,*&**#*                                                       \r\n"
"                                     ,*&@%(*@,%@/ @((( .//((((( ,# @@/ /#( ##* ,(/                                                                  \r\n"
"                                      *%& ,**%,&* */(( &/((((((.@@ , ,*/(#/,,.. .%&                                                                   \r\n"
"                                        ///**,   .,#/,,*//////////./#/(//(,/,**,%(/%                                                                  \r\n"
"                                        ( ./*****  ,*//////////*//(//*(/*/*(((%%&&&&%(/                                                               \r\n"
"                                         /   ,(*** *****/*//#(/***#*/((//%***,,,***////,                                                              \r\n"
"                                          //****, */***,(,*** .& * (,//%    /////**///                                                                \r\n"            
            );
    
    terminalTextAttributesReset();
}

// This function must be called to set up the usb_uart_commands hash table
// Entries into this hash table are "usb_uart serial commands"
void usbUartHashTableInitialize(void) {
    
    usbUartAddCommand("Help", 
            "Prints help message for all supported serial commands", 
            helpCommandFunction);
    usbUartAddCommand("Reset", 
            "Executes an MCU software reset", 
            resetCommand);
    usbUartAddCommand("Cause of Reset?",
            "Prints the cause of the most recent device reset",
            causeOfResetCommand);
    usbUartAddCommand("Clear Screen", 
            "Clears the serial port terminal", 
            clearCommand);
    usbUartAddCommand("*IDN?", 
            "Prints identification string", 
            idnCommand);
    usbUartAddCommand("MCU IDs?", 
            "Prints microcontroller serial number, device ID, and silicon revision ID", 
            mcuIdCommand);
    usbUartAddCommand("MCU Status?", 
            "Prints the status of the watchdog timer, deadman timer and predictive prefetch module", 
            mcuStatusCommand);
    usbUartAddCommand("Interrupt Status?",
            "Prints MCU interrupt settings", 
            interruptStatusCommand);
    usbUartAddCommand("Clock Status?", 
            "Prints MCU clock and oscillator settings", 
            clockStatusCommand);
    usbUartAddCommand("Device On Time?", 
            "Prints the MCU on time since the last device reset", 
            deviceOnTimeComand);
    usbUartAddCommand("Error Status?",
            "Prints the status of various error handler flags",
            errorStatusCommand);
    usbUartAddCommand("Clear Errors",
            "Clears all error handler flags",
            clearErrorsCommand);
    usbUartAddCommand("PMD Status?",
            "Prints status of peripheral module disable settings",
            pmdStatusCommand);
    usbUartAddCommand("PGOOD Status?",
            "Prints current state of power good signals for all voltage rails",
            pgoodStatusCommand);
    usbUartAddCommand("Set Battery Isolation: ",
            "\b\b<isolation_state>: Connects or disconnects the MCU backup battery. 1 for isolated, 0 for connected.",
            vbatIsolateCommand);
    usbUartAddCommand("ADC Status?",
            "Prints status information for the Analog to Digital Converter",
            adcStatusCommand);
    usbUartAddCommand("Telemetry?",
            "Prints board level parameter measurements",
            telemetryCommand);
    usbUartAddCommand("Max Telemetry?",
            "Prints maximum recorded board level parameter measurements",
            maxTelemetryCommand);
    usbUartAddCommand("Min Telemetry?",
            "Prints minimum recorded board level parameter measurements",
            minTelemetryCommand);
    usbUartAddCommand("Time and Date?",
            "Prints the current system time and date",
            timeAndDateCommand);
    usbUartAddCommand("Set Date: ",
            "\b\b<mm>/<dd>/<yyyy>: Sets the system date",
            setDateCommand);
    usbUartAddCommand("Set Time: ",
            "\b\b<hh>:<mm>:<ss>: Sets the system time. (Must be 24 hr time)",
            setTimeCommand);
    usbUartAddCommand("Set Weekday: ",
            "\b\b<weekday>: Sets the system weekday",
            setWeekdayCommand);
    usbUartAddCommand("Set Unix Time: ",
            "\b\b<decimal unix time>, <hour offset from UTC to local time>: sets the RTCC to the supplied UNIX time with hour offset from UTC",
            setUnixTimeCommand);
    usbUartAddCommand("RTCC Calibration?",
            "Prints the current setting of the 10 bit RTCC calibration value",
            getRTCCCalCommand);
    usbUartAddCommand("Set RTCC Calibration: ",
            "\b\b<10 bit hex calibration value>: Sets the RTCC calibration value",
            setRTCCCalCommand);
    usbUartAddCommand("Easter Egg",
            "Prints a surprise\r\n",
            easterEggCommand);
    
}
