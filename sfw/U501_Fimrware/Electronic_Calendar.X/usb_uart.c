
#include <xc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

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

volatile uint32_t usb_uart_TxHead = 0;
volatile uint32_t usb_uart_TxTail = 0;
volatile uint8_t usb_uart_TxBuffer[USB_UART_TX_BUFFER_SIZE];
volatile uint32_t usb_uart_TxBufferRemaining;

volatile uint32_t usb_uart_RxHead = 0;
volatile uint32_t usb_uart_RxTail = 0;
volatile uint8_t usb_uart_RxBuffer[USB_UART_RX_BUFFER_SIZE];
volatile uint32_t usb_uart_RxCount;

volatile uint8_t usb_uart_RxStringReady = 0;

// Printable Variables from other header files
extern uint32_t device_on_time_counter;
extern reset_cause_t reset_cause;

// This function initializes UART 6 for USB debugging
void usbUartInitialize(void) {
 
    __XC_UART = 3;
    
    usb_in_use_flag = 1;
    
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
    
    // RX idle state is logic low
    U3MODEbits.RXINV = 1;
    
    // High speed baud rate setting
    U3MODEbits.BRGH = 0;
    
    // 8 bit data length and no parity
    U3MODEbits.PDSEL = 0b00;
    
    // 1 stop bit
    U3MODEbits.STSEL = 0;
    
    // Disable addressing
    U3STAbits.ADM_EN = 0;
    
    // Interrupt on every transmitted character
    U3STAbits.UTXISEL = 0b00;
    
    // Idle transmit state is low
    U3STAbits.UTXINV = 1;
    
    // Enable receiver
    U3STAbits.URXEN = 1;
    
    // Disable break
    U3STAbits.UTXBRK = 0;
    
    // Enable transmitter
    U3STAbits.UTXEN = 1;
    
    // Interrupt on every character received
    U3STAbits.URXISEL = 0b00;
    
    // Disable address detection
    U3STAbits.ADDEN = 0;
    
    // Set baud rate to 115200 bps
    // From section 21.3 of PIC32MZ reference manual
    // Input CLK is PBCLK2 (84 MHz)
    // With PBCLK2 = 84 MHz, BRGH = 1, baud rate error is 0.16%
    U3BRG = 35;
    
    // initializing the driver state
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;
    usb_uart_TxBufferRemaining = sizeof(usb_uart_TxBuffer);
    usb_uart_RxHead = 0;
    usb_uart_RxTail = 0;
    usb_uart_RxCount = 0;
        
    
    // Set interrupt priorities
    setInterruptPriority(UART3_Receive_Done, 2);
    setInterruptPriority(UART3_Transfer_Done, 6);
    setInterruptPriority(UART3_Fault, 1);
    
    // Set interrupt subpriorities
    setInterruptSubpriority(UART3_Receive_Done, 2);
    setInterruptSubpriority(UART3_Transfer_Done, 2);
    setInterruptSubpriority(UART3_Fault, 1);
    
    // Clear all UART 3 Interrupts
    clearInterruptFlag(UART3_Receive_Done);
    clearInterruptFlag(UART3_Transfer_Done);
    clearInterruptFlag(UART3_Fault);
    
    // Enable UART 3
    U3MODEbits.ON = 1;
    
    // Trick UART into thinking user has pressed enter twice
//    U3MODEbits.LPBACK = 1;
//    U3TXREG = '\n';
//    U3TXREG = '\r';
//    U3TXREG = '\n';
//    U3TXREG = '\r';
//    U3MODEbits.LPBACK = 0;
    
    // Enable receive and error interrupts
    // Transfer interrupt is set in write function
    enableInterrupt(UART3_Receive_Done);
    enableInterrupt(UART3_Fault);
    
}

// This is the USB UART receive interrupt service routine
void __ISR(_UART3_RX_VECTOR, ipl2SRS) usbUartReceiveISR(void) {
    
    usb_in_use_flag = 1;
    
    // Do receive tasks
    usbUartReceiveHandler();
    
    // Clear receive interrupt flag
    clearInterruptFlag(UART3_Receive_Done);
    
}

// This is the USB UART transfer interrupt service routine
void __ISR(_UART3_TX_VECTOR, ipl6SRS) usbUartTransferISR(void) {
    
    // Do transfer tasks
    usbUartTransmitHandler();
    
    // Clear interrupt flag
    clearInterruptFlag(UART3_Transfer_Done);
    
}

// This is the UAB UART fault interrupt service routine
void __ISR(_UART3_FAULT_VECTOR, ipl1SRS) usbUartFaultISR(void) {
    
    // TO-DO: Fault tasks
    error_handler.USB_error_flag = 1;   
    
    // Clear fault interrupt flag
    clearInterruptFlag(UART3_Fault);
    
}

// This function pulls a byte from the RX ring buffer
uint8_t usbUartReadByte(void) {
 
    uint8_t readValue  = 0;
    
    // This state should never be entered
    while(0 == usb_uart_RxCount)
    {
        error_handler.USB_error_flag = 1;
        return 0;
    }

    readValue = usb_uart_RxBuffer[usb_uart_RxTail++];
    if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxTail)
    {
        usb_uart_RxTail = 0;
    }
    
    
    disableInterrupt(UART3_Receive_Done);
    usb_uart_RxCount--;
    enableInterrupt(UART3_Receive_Done);
    return readValue;
    
}


// This function adds a byte to the TX ring buffer
void usbUartPutchar(uint8_t txData) {
 
    // wait for ring buffer to open up
    while(0 == usb_uart_TxBufferRemaining);

    if(0 == getInterruptEnable(UART3_Transfer_Done))
    {
        U3TXREG = txData;
   
    }
    else
    {
        
        disableInterrupt(UART3_Transfer_Done);
        usb_uart_TxBuffer[usb_uart_TxHead++] = txData;
        
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxHead)
        {
            usb_uart_TxHead = 0;
        }
        
        usb_uart_TxBufferRemaining--;

    }

     enableInterrupt(UART3_Transfer_Done);
   
    
}

// This serves as the TX interrupt handler and is called by the TX ISR
void usbUartTransmitHandler(void) {
 
    if(sizeof(usb_uart_TxBuffer) > usb_uart_TxBufferRemaining)
    {
        U3TXREG = usb_uart_TxBuffer[usb_uart_TxTail++];
        if(sizeof(usb_uart_TxBuffer) <= usb_uart_TxTail)
        {
            usb_uart_TxTail = 0;
        }
        usb_uart_TxBufferRemaining++;
    }
    
    else
    {
        disableInterrupt(UART3_Transfer_Done);
        
    }
    
    
}


// This serves as the RX handler and is called by the RX ISR
void usbUartReceiveHandler(void) {
            
    if(1 == U3STAbits.OERR)
    {
        U3MODEbits.ON = 0;
        error_handler.USB_error_flag = 1;
        U3STAbits.OERR = 0;
        U3MODEbits.ON = 1;
    }
    
    while(U3STAbits.URXDA) {
    
        usb_uart_RxBuffer[usb_uart_RxHead++] = U3RXREG;
        
        if(sizeof(usb_uart_RxBuffer) <= usb_uart_RxHead)
        {
            usb_uart_RxHead = 0;
        }
        usb_uart_RxCount++;
        
    }    
    
    // This chunk tells main() or whatever is pulling from the ring buffer that
    // data is ready to be read, since the terminal sent a newline or 
    // carriage return
    if((usb_uart_RxBuffer[usb_uart_RxHead - 1] == (int) '\n') || 
       (usb_uart_RxBuffer[usb_uart_RxHead - 1] == (int) '\r')) {

        usb_uart_RxStringReady = 1;
                
    }
    
    else {
        
        usb_uart_RxStringReady = 0;
        
    }
   
    // If we've received a backspace
    if((usb_uart_RxBuffer[usb_uart_RxHead - 1] == (int) '\b')) {
     
        usb_uart_RxBuffer[usb_uart_RxHead - 1] = '\0';
        usb_uart_RxHead--;
 
        // Erase the "backspaced" character on terminal
        printf("\033[K");
        
        if(usb_uart_RxHead != usb_uart_RxTail) {
        
            usb_uart_RxBuffer[usb_uart_RxHead - 1] = '\0';
            usb_uart_RxHead--;

        }
        
    }
    
}

// This function redirects stdout to USB_UART output, allowing printf functionality
void _mon_putc(char c) {
    
    usbUartPutchar(c);
    
}


// This function pulls data out of the RX ring buffer
void usbUartRingBufferPull(void) {

    int charNumber = usb_uart_RxCount;
            
    // Clear line buffer
    uint32_t index;
    for (index = 0; index < sizeof(usb_uart_line); index++) {

        usb_uart_line[index] = '\0';

    }

    // Fill line from ring buffer
    for(index = 0; index < charNumber; index++){

        usb_uart_line[index] = usbUartReadByte();

    }

    // Reset ring buffer
    usb_uart_RxTail = usb_uart_RxHead;

    // Try to kill off ending returns/newlines
    while((usb_uart_line[strlen(usb_uart_line) - 1] == (int) '\n') ||
          (usb_uart_line[strlen(usb_uart_line) - 1] == (int) '\r')) {
     
        // NULL
        usb_uart_line[strlen(usb_uart_line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    usb_uart_RxStringReady = 0;

    // Check to see if line matches a command
    usbUartRingBufferLUT(usb_uart_line);

    
}


// This function parses the data pulled from the RX ring buffer
// This is the function that actually makes stuff happen based on commands
// Enter the command you'd like to set up within the if statements as
// an argument to the "strstr" functions
/*
 
    if (strcmp(line_in, "<INSERT COMMAND HERE>") == 0) {

        <ACTIONS OF COMMAND>;
    }
 
 * 
 *  * */
void usbUartRingBufferLUT(char * line_in) {
 
    // THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
    // ACT ON IT
    
    if (strcmp(line_in, "Reset") == 0) {

         deviceReset();
        
    }
    
    else if (strcmp(line_in, "Clear") == 0) {
     
        terminalClearScreen();
        terminalSetCursorHome();
        
    }
    
    else if (strcmp(line_in, "*IDN?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("E44 Electronic Display Logic Board\n\r");
        terminalTextAttributesReset();
        
    }
    
    else if (strcmp(line_in, "Device On Time?") == 0) {
     
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("On time since last device reset: %s\n\r", 
                getStringSecondsAsTime(device_on_time_counter));
        terminalTextAttributesReset();
        
    }
    
//    else if (strcmp(line_in, "PMD Status?") == 0) {
//     
//        usb_uart_TxHead = 0;
//        usb_uart_TxTail = 0;
//        
//        printPMDStatus();
//        
//    }
    
     else if (strcmp(line_in, "MCU IDs?") == 0) {
     
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
    
    else if (strcmp(line_in, "MCU Status?") == 0) {
     
        printWatchdogStatus();
        
        printDeadmanStatus();
        
        printPrefetchStatus();
        
        
    }
    
    else if (strcmp(line_in, "Interrupt Status?") == 0) {
     
        usb_uart_TxHead = 0;
        usb_uart_TxTail = 0;
            
        // Print function from interrupt control module
        printInterruptStatus();
        
    }
    
//    else if (strcmp(line_in, "Cause of Reset?") == 0) {
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
    
    else if (strcmp(line_in, "Clock Status?") == 0) {
     
        printClockStatus(SYSCLK_INT);
        
    }
        
    
    else if (strcmp(line_in, "Error Status?") == 0) {
     
        // Print error handler status
        printErrorHandlerStatus();
        
        // Print help message
        terminalTextAttributes(YELLOW, BLACK, NORMAL);
        printf("\n\rCall 'Clear Errors' command to clear any errors that have been set\n\r");
        terminalTextAttributesReset();
        
        
    }
    
    else if (strcmp(line_in, "Clear Errors") == 0) {
     
        // Zero out all error handler flags
        clearErrorHandler();
        
        // Update error LEDs based on error handler status
        // updateErrorLEDs();
        
        terminalTextAttributesReset();
        terminalTextAttributes(GREEN, BLACK, NORMAL);
        printf("Error Handler flags cleared\n\r");
        terminalTextAttributesReset();
        
    }
        
    
    else if (strcmp(line_in, "Help") == 0) {
    
        usbUartPrintHelpMessage();
        
    }
    
}

// Print help message, used in a command above
void usbUartPrintHelpMessage(void) {
 
    usb_uart_TxHead = 0;
    usb_uart_TxTail = 0;   

    
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