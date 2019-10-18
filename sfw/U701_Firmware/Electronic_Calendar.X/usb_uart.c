
#include <xc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

// These macros are needed for switching between physical and virtual memory locations
#include <sys/kmem.h>

#include "32mz_interrupt_control.h"
#include "pin_macros.h"
#include "device_control.h"
#include "power_saving.h"
#include "watchdog_timer.h"
#include "usb_uart.h"
#include "terminal_control.h"
#include "error_handler.h"
#include "cause_of_reset.h"
#include "prefetch.h"
#include "error_handler.h"

// Printable Variables from other header files
extern uint32_t device_on_time_counter;
extern reset_cause_t reset_cause;

// This function is used to setup DMA0 for UART transmit
void usbUartTrasmitDmaInitialize(void) {
 
    // Set up DMA0 for USB UART Transmit
    // From reference manual example 31-2
    // Disable DMA0 interrupt
    disableInterrupt(DMA_Channel_0);
    clearInterruptFlag(DMA_Channel_0);
    
    // Enable DMA controller
    DMACONbits.ON = 0;
    // Disable DMA CRC
    DCRCCONbits.CRCEN = 0;
    // Turn off channel 0
    DCH0CONbits.CHEN = 0;
    // Set channel 0 priority to 2
    DCH0CONbits.CHPRI = 2;
    // Disable DMA chaining
    DCH0CONbits.CHCHN = 0;
    
    // Start interrupt request is UART 3 TX done
    DCH0ECONbits.CHSIRQ = UART3_Transfer_Done;
    // configure DMA0 to start on an IRQ matching CHSIRQ
    DCH0ECONbits.SIRQEN = 1;
    // configure DMA0 to abort on pattern match where data matched DCH0DAT
    DCH0ECONbits.PATEN = 1;
    // pattern is 1 byte long
    DCH0CONbits.CHPATLEN = 0;
    // Pattern value is a null ('\0'), end of string
    DCH0DAT = '\0';
    
    // Set DMA0 source location
    DCH0SSA = KVA_TO_PA((void *) &usb_uart_tx_buffer);
    // DCH0SSA = KVA_TO_PA((void *) "Hello World\r\n");
    // Set DMA0 destination location
    DCH0DSA = KVA_TO_PA((void*)&U3TXREG);
    // Set source size to size of transmit buffer
    DCH0SSIZ = USB_UART_TX_BUFFER_SIZE;
    // Set destination size to 1, since U3TXREG is one byte long
    DCH0DSIZ = 1;
    // 1 byte transferred per event (cell size = 1)
    DCH0CSIZ = 1;
    
    // clear existing events, disable all interrupts
    DCH0INTCLR = 0x00000000;
    // enable Block Complete and error interrupts
    DCH0INTbits.CHBCIF = 0;
    DCH0INTbits.CHBCIE = 1;
    DCH0INTbits.CHERIF = 0;
    DCH0INTbits.CHERIE = 1;
    
    // Set up DMA0 interrupts
    setInterruptPriority(DMA_Channel_0, 5);
    setInterruptSubpriority(DMA_Channel_0, 3);
    clearInterruptFlag(DMA_Channel_0);
    enableInterrupt(DMA_Channel_0);
    
    // Turn on DMA
    DMACONbits.ON = 1;
    
}

// This function is used to setup DMA1 for UART Receive
void usbUartReceiveDmaInitialize(void) {
 
    // Set up DMA1 for USB UART Transmit
    // From reference manual example 31-2
    // Disable DMA1 interrupt
    disableInterrupt(DMA_Channel_1);
    clearInterruptFlag(DMA_Channel_1);
    
    // Disable DMA controller
    DMACONbits.ON = 0;
    // Disable DMA CRC
    DCRCCONbits.CRCEN = 0;
    // Turn off channel 1
    DCH1CONbits.CHEN = 0;
    // Set channel 1 priority to 3
    DCH1CONbits.CHPRI = 3;
    // Disable DMA chaining
    DCH1CONbits.CHCHN = 0;
    
    // Start interrupt request is UART 3 RX done
    DCH1ECONbits.CHSIRQ = UART3_Receive_Done;
    // configure DMA1 to start on an IRQ matching CHSIRQ
    DCH1ECONbits.SIRQEN = 1;
    // configure DMA1 to abort on pattern match where data matched DCH1DAT
    DCH1ECONbits.PATEN = 1;
    // pattern is 1 byte long
    DCH1CONbits.CHPATLEN = 0;
    // Pattern value is a carriage return ('\r'), end of string
    DCH1DAT = '\r';
    
    // Set DMA1 source location
    DCH1SSA = KVA_TO_PA((void *) &U3RXREG);
    // Set DMA1 destination location
    DCH1DSA = KVA_TO_PA((void*) &usb_uart_rx_buffer[0]);
    // Set source size to size of U3RXREG
    DCH1SSIZ = 1;
    // Set destination size to size of receive buffer
    DCH1DSIZ = USB_UART_RX_BUFFER_SIZE;
    // 1 byte transferred per event (cell size = 1)
    DCH1CSIZ = 1;
    
    // clear existing events, disable all interrupts
    DCH1INTCLR = 0x00000000;
    // enable Block Complete and error interrupts
    DCH1INTbits.CHBCIF = 0;
    DCH1INTbits.CHBCIE = 1;
    DCH1INTbits.CHERIF = 0;
    DCH1INTbits.CHERIE = 1;
    
    // Set up DMA1 interrupts
    setInterruptPriority(DMA_Channel_1, 6);
    setInterruptSubpriority(DMA_Channel_1, 3);
    clearInterruptFlag(DMA_Channel_1);
    enableInterrupt(DMA_Channel_1);
    
    // Enable channel for receiving data
    DCH1CONbits.CHEN = 1;
    // Set up to auto-enable on pattern match
    DCH1CONbits.CHAEN = 1;
    
    // Turn on DMA
    DMACONbits.ON = 1;
    
}

// This function initializes UART 6 for USB debugging
void usbUartInitialize(void) {
 
    // Disable UART 3 interrupts
    disableInterrupt(UART3_Receive_Done);
    disableInterrupt(UART3_Transfer_Done);
    disableInterrupt(UART3_Fault);
    
    // Turn off UART 3 for configuration
    U3MODEbits.ON = 0;
    
    // Enable UART 3 operation in IDLE mode
    U3MODEbits.SIDL = 0;
    
    // Disable IrDA encoding
    U3MODEbits.IREN = 0;
    
    // Disable CTS, RTS signals
    // (No flow control used)
    U3MODEbits.UEN = 0b00;
    
    // Enable wake from sleep
    U3MODEbits.WAKE = 1;
    
    // Disable loopback
    U3MODEbits.LPBACK = 0;
    
    // Disable auto-baud
    U3MODEbits.ABAUD = 0;
    
    // RX idle state is logic high
    U3MODEbits.RXINV = 0;
    
    // High speed baud rate setting
    U3MODEbits.BRGH = 0;
    
    // 8 bit data length and no parity
    U3MODEbits.PDSEL = 0b00;
    
    // 1 stop bit
    U3MODEbits.STSEL = 0;
    
    // Disable addressing
    U3STAbits.ADM_EN = 0;
    
    // Interrupt on every transmitted character
    U3STAbits.UTXISEL = 0b01;
    
    // Idle transmit state is low
    U3STAbits.UTXINV = 1;
    
    // Disable break
    U3STAbits.UTXBRK = 0;
    
    // Interrupt on every character received
    U3STAbits.URXISEL = 0b00;
    
    // Disable address detection
    U3STAbits.ADDEN = 0;
    
    // Set baud rate to 115200 bps
    // From section 21.3 of PIC32MZ reference manual
    // Input CLK is PBCLK2 (84 MHz)
    // With PBCLK2 = 84 MHz, BRGH = 1, baud rate error is 0.16%
    U3BRG = 35;
    
    // Set interrupt priorities
    setInterruptPriority(UART3_Fault, 1);
    
    // Set interrupt subpriorities
    setInterruptSubpriority(UART3_Fault, 1);
    
    // Clear all UART 3 Interrupts
    clearInterruptFlag(UART3_Fault);
    clearInterruptFlag(UART3_Transfer_Done);
    
    // clear receive errors
    U3STAbits.FERR = 0;
    U3STAbits.PERR = 0;
    U3STAbits.OERR = 0;
    
    // Enable UART 3
    U3MODEbits.ON = 1;
    
    // Enable transmitter
    U3STAbits.UTXEN = 1;
    
    // Enable receiver
    U3STAbits.URXEN = 1;
    
    // Enable receive and error interrupts
    enableInterrupt(UART3_Fault);
    
    // Setup DMA0 for USB UART Transmit
    usbUartTrasmitDmaInitialize();

    // Setup DMA1 for USB UART Receive
    usbUartReceiveDmaInitialize();
    
}

// This is the UAB UART fault interrupt service routine
void __ISR(_UART3_FAULT_VECTOR, ipl1SRS) usbUartFaultISR(void) {
    
    // TO-DO: Fault tasks
    error_handler.USB_error_flag = 1;
    
    U3STAbits.PERR = 0;
    U3STAbits.FERR = 0;
    U3STAbits.OERR = 0;
    
    // Clear fault interrupt flag
    clearInterruptFlag(UART3_Fault);
    
}

// These are the USB UART DMA Interrupt Service Routines
void __ISR(_DMA0_VECTOR, IPL5SRS) usbUartTxDmaISR(void) {
 
    // Determine source of DMA 0 interrupt
    // Channel block transfer complete interrupt flag (or pattern match)
    if (DCH0INTbits.CHBCIF) {
        
        // clear tx buffer
        uint32_t index;
        for (index = 0; index <= usb_uart_tx_buffer_head; index++) {
         
            usb_uart_tx_buffer[index] = '\0';
            
        }
        
        usb_uart_tx_buffer_head = 0;
        
    }
    
    // channel error
    else if (DCH0INTbits.CHERIF) {
        
        error_handler.USB_tx_dma_error_flag = 1;
        
    }
    
    // Clear DMA controller interrupt flags
    DCH0INTCLR=0x000000ff;
    
    // Clear interrupt flag
    clearInterruptFlag(DMA_Channel_0);
    
}

// These are the USB UART DMA Interrupt Service Routines
void __ISR(_DMA1_VECTOR, IPL6SRS) usbUartRxDmaISR(void) {
    
    // Determine source of DMA 1 interrupt
    // Channel block transfer complete interrupt flag (or pattern match)
    if (DCH1INTbits.CHBCIF) {
        
        usb_uart_rx_parse_request = 1;
        
    }
    
    // channel error
    else if (DCH1INTbits.CHERIF) {
        
        error_handler.USB_rx_dma_error_flag = 1;
        
    }
    
    // Clear DMA controller interrupt flags
    DCH1INTCLR=0x000000ff;
    
    // Clear interrupt flag
    clearInterruptFlag(DMA_Channel_1);
    
}

// This function redirects stdout to USB_UART output, allowing printf functionality
void _mon_putc (char c) {
    
    usb_uart_tx_buffer[usb_uart_tx_buffer_head] = c;
    usb_uart_tx_buffer_head++;
    
    // Force a DMA0 transfer to begin
//    if (DCH0CONbits.CHBUSY == 0) {
//    // if (usb_uart_tx_buffer_head >= 1) {
//    
//        DCH0CONbits.CHEN = 1;
//        // DCH0ECONbits.CFORCE = 1;
//        
//    }
    
    if (U3STAbits.UTXBF == 0 || usb_uart_tx_buffer_head == 1) {
        
        DCH0CONbits.CHEN = 1;
        DCH0ECONbits.CFORCE = 1;
    }
}

// this function adds a usb_uart command to the usb_uart_commands hash table
void usbUartHashTableAdd(char * input_cmd_name, char * input_cmd_help_message, usb_uart_command_function_t input_cmd_func) {

    // Add help command to hash string
    usb_uart_command_t *cmd = malloc(sizeof(usb_uart_command_t));
    strcpy(cmd->command_name, input_cmd_name);
    strcpy(cmd->command_help_message, input_cmd_help_message);
    cmd->func = input_cmd_func;
    HASH_ADD_STR(usb_uart_commands, command_name, cmd);
    
}


// This function is what interprets strings sent over USB Virtual COM Port
void usbUartRxLUTInterface(char * cmd_string) {
    // Remove trailing newlines and carriage returns
    strtok(cmd_string, "\n");
    strtok(cmd_string, "\r");
    
    // iterate over usb_uart_commands hash table to find a matching command to cmd_string
    usb_uart_command_t *current_command, *temp;
    HASH_ITER(hh, usb_uart_commands, current_command, temp) {
        
        // if the current entry that we've found in the hash table matches cmd_string,
        // call the function pointed to by the current entry in the hash table
        if (strcomp(cmd_string, current_command->command_name) == 0) {
         
            current_command->func(cmd_string);
            break;
            
        }
    }
    
//    if (strcomp(cmd_string, (char *) &help_command) == 0) {
//        // help_command.func();
//        void (*func)(void) = &help_command;
//        func = (void*)(((void*)func) + 16 + 128);
//        //func = &help_command + sizeof(usb_uart_command_t.command_name) + sizeof(usb_uart_command_t.command_name);
//        (*func)();
//        
//    }
    
//    if (strcomp(cmd_string, "Interrupt Status?") == 0) {
//     
//        // Print function from interrupt control module
//        printInterruptStatus();
//        
//    }
//    
//    else if (strcomp(cmd_string, "Clock Status?") == 0) {
//     
//        printClockStatus(SYSCLK_INT);
//        
//    }
//    
//    else if (strcomp(cmd_string, "Device On Time?") == 0) {
//     
//        terminalTextAttributesReset();
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("On time since last device reset: %s\n\r", 
//                getStringSecondsAsTime(device_on_time_counter));
//        terminalTextAttributesReset();
//        
//    }
//    
//    else if (strcomp(cmd_string, "Error Status?") == 0) {
//     
//        // Print error handler status
//        printErrorHandlerStatus();
//        
//        // Print help message
//        terminalTextAttributes(YELLOW, BLACK, NORMAL);
//        printf("\n\rCall 'Clear Errors' command to clear any errors that have been set\n\r");
//        terminalTextAttributesReset();
//        
//        
//    }
//    
//    else if (strcomp(cmd_string, "Clear Errors") == 0) {
//     
//        // Zero out all error handler flags
//        clearErrorHandler();
//        
//        // Update error LEDs based on error handler status
//        updateErrorLEDs();
//        
//        terminalTextAttributesReset();
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("Error Handler flags cleared\n\r");
//        terminalTextAttributesReset();
//        
//    }
//    
//     else if (strcomp(cmd_string, "Cause of Reset?") == 0) {
//     
//        terminalTextAttributesReset();
//        
//        if (    reset_cause == Undefined ||
//                reset_cause == Primary_Config_Registers_Error ||
//                reset_cause == Primary_Secondary_Config_Registers_Error ||
//                reset_cause == Config_Mismatch ||
//                reset_cause == DMT_Reset ||
//                reset_cause == WDT_Reset ||
//                reset_cause == Software_Reset ||
//                reset_cause == External_Reset ||
//                reset_cause == BOR_Reset) {
//
//            terminalTextAttributes(RED, BLACK, NORMAL);
//
//        }
//
//        else {
//
//            terminalTextAttributes(GREEN, BLACK, NORMAL);
//
//        }
//        
//        printf("Cause of the most recent device reset: %s\n\r",
//                getResetCauseString(reset_cause));
//        terminalTextAttributesReset();
//        
//    }
//    
//    else if (strcomp(cmd_string, "PMD Status?") == 0) {
//     
//        printPMDStatus();
//        
//    }
//    
//    else if (strcomp(cmd_string, "Time and Date?") == 0) {
//     
//        terminalTextAttributesReset();
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("Current system time and date:\r\n   ");
//        printTimeAndDate();
//        terminalTextAttributesReset();
//        
//    }
//    
//    else if (strcomp(cmd_string, "Set Date: ") == 0) {
//     
//        // Snipe out received string
//        uint32_t read_month, read_day, read_year;
//        sscanf(cmd_string, "Set Date: %u/%u/%u", &read_month, &read_day, &read_year);
//        
//        // Write received data into RTCC
//        if (read_year >= 2000) {
//            
//            rtccWriteDate((uint8_t) read_month, (uint8_t) read_day, (uint16_t) read_year);
//
//            // print out what we just did
//            terminalTextAttributesReset();
//            terminalTextAttributes(GREEN, BLACK, NORMAL);
//            printf("Set RTCC date as %02u/%02u/%04u\r\n", rtcc_shadow.month, rtcc_shadow.day, rtcc_shadow.year);
//            terminalTextAttributesReset();
//        
//        }
//        
//        // return error if year < 2000
//        else {
//         
//            terminalTextAttributesReset();
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("Enter a valid date after 01/01/2000. User entered %02u/%02u/%04u\r\n", read_month, read_day, read_year);
//            terminalTextAttributesReset();
//            
//        }
//        
//    }
//    
//    else if (strcomp(cmd_string, "Set Time: ") == 0) {
//     
//        // Snipe out received string
//        uint32_t read_hour, read_minute, read_second;
//        sscanf(cmd_string, "Set Time: %u:%u:%u", &read_hour, &read_minute, &read_second);
//                    
//        rtccWriteTime((uint8_t) read_hour, (uint8_t) read_minute, (uint16_t) read_second);
//
//        // print out what we just did
//        terminalTextAttributesReset();
//        terminalTextAttributes(GREEN, BLACK, NORMAL);
//        printf("Set RTCC time as %02u:%02u:%02u\r\n", rtcc_shadow.hours, rtcc_shadow.minutes, rtcc_shadow.seconds);
//        terminalTextAttributesReset();
//
//    }
//    
//    else if (strcomp(cmd_string, "Set Weekday: ") == 0) {
//     
//        char read_weekday[16];
//        uint8_t read_weekday_enum;
//        sscanf(cmd_string, "Set Weekday: %s", &read_weekday);
//        
//        if (strcmp(read_weekday, "Sunday") == 0) read_weekday_enum = 0;
//        else if (strcmp(read_weekday, "Monday") == 0) read_weekday_enum = 1;
//        else if (strcmp(read_weekday, "Tuesday") == 0) read_weekday_enum = 2;
//        else if (strcmp(read_weekday, "Wednesday") == 0) read_weekday_enum = 3;
//        else if (strcmp(read_weekday, "Thursday") == 0) read_weekday_enum = 4;
//        else if (strcmp(read_weekday, "Friday") == 0) read_weekday_enum = 5;
//        else if (strcmp(read_weekday, "Saturday") == 0) read_weekday_enum = 6;
//        else read_weekday_enum = 255;
//
//        if (read_weekday_enum != 255) {
//
//            // print out what we just did
//            terminalTextAttributesReset();
//            terminalTextAttributes(GREEN, BLACK, NORMAL);
//            rtccWriteWeekday(read_weekday_enum);
//            printf("Set RTCC weekday as %s\r\n", getDayOfWeek(rtcc_shadow.weekday));
//            terminalTextAttributesReset();
//
//        }
//        
//        else {
//        
//            terminalTextAttributesReset();
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("Please enter a valid day of the weekday. Input is case sensitive\r\n");
//            terminalTextAttributesReset();
//            
//        }
//            
//    }
//    
//    else if (strcomp(cmd_string, "ADC Status?") == 0) {
//     
//        printADCStatus();
//        
//    }
//    
//    else if (strcomp(cmd_string, "Telemetry?") == 0) {
//     
//        if (error_handler.ADC_configuration_error_flag) {
//         
//            terminalTextAttributesReset();
//            terminalTextAttributes(RED, BLACK, NORMAL);
//            printf("ADC Configuration Error\n\r");
//            terminalTextAttributesReset();
//            
//        }
//        
//        else {
//
//            terminalTextAttributesReset();
//            terminalTextAttributes(CYAN, BLACK, NORMAL);
//            printf("Most recent ADC conversion results:\n\r");
//            printf("    +12V Input Voltage Measurement: %+0.3f V\n\r", adc_results.POS12_adc);
//            printf("    +3.3V Power Supply Measurement: %+0.3f V\n\r", adc_results.POS3P3_adc);
//            printf("    Internal VREF ADC Conversion Result: %+0.3f V\n\r", adc_results.vref_adc);
//            printf("    Internal Die Temperature ADC Conversion Result: %+0.3f C\n\r", adc_results.die_temp_adc);
//            terminalTextAttributesReset();
//
//        }
//            
//    }
//
//    
    // increment the number of strings we've received
    num_strings_received++;
    
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
uint8_t strcomp(const char * haystack, const char * needle) {
 
    if (num_strings_received == 0) {
        
        // move to next pair of characters
        needle++;
        haystack++;
        while(*needle)
        {
            // if characters differ or end of second string is reached
            if (*needle != *haystack)
                return 1;

            // move to next pair of characters
            needle++;
            haystack++;
        }

        // return the ASCII difference after converting char* to unsigned char*
        // return *(const unsigned char*)needle - *(const unsigned char*)haystack;
        return 0;
        
    }
    
    else {
      
        while(*needle)
        {
            // if characters differ or end of second string is reached
            if (*needle != *haystack)
                return 1;

            // move to next pair of characters
            needle++;
            haystack++;
        }

        // return the ASCII difference after converting char* to unsigned char*
        // return *(const unsigned char*)needle - *(const unsigned char*)haystack;
        return 0;
        
    }
        
}
