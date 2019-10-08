
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
    // Turn on channel 0
    DCH0CONbits.CHEN = 0;
    // Set channel 0 priority to 3 (highest)
    DCH0CONbits.CHPRI = 3;
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
    U3STAbits.UTXISEL = 0b01;
    
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
    
    // Set interrupt priorities
    setInterruptPriority(UART3_Fault, 1);
    
    // Set interrupt subpriorities
    setInterruptSubpriority(UART3_Fault, 1);
    
    // Clear all UART 3 Interrupts
    clearInterruptFlag(UART3_Fault);
    clearInterruptFlag(UART3_Transfer_Done);
    
    // Enable UART 3
    U3MODEbits.ON = 1;
    
    // Enable receive and error interrupts
    enableInterrupt(UART3_Fault);
    
}

// This is the UAB UART fault interrupt service routine
void __ISR(_UART3_FAULT_VECTOR, ipl1SRS) usbUartFaultISR(void) {
    
    // TO-DO: Fault tasks
    error_handler.USB_error_flag = 1;
    
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

// Print help message, used in a command above
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