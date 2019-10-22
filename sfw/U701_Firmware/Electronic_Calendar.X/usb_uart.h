/* ************************************************************************** */
/** USB UART

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    usb_uart.h

  @Summary
 Allows USB debugging over UART6 to a USB virtual COM port

 */
/* ************************************************************************** */

#ifndef _USB_UART_H    /* Guard against multiple inclusion */
#define _USB_UART_H

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#include "usb_uart_rx_lookup_table.h"

#include "uthash.h"

// Sizes of TX and RX ring buffers
#define USB_UART_TX_BUFFER_SIZE 16384
#define USB_UART_RX_BUFFER_SIZE 2048

// Hardcoded COM Port Descriptor Strings
#define USB_UART_BAUD_RATE_STR          "115.2 kbs"
#define USB_UART_DATA_LENGTH_STR        "8 bits"
#define USB_UART_PARITY_STR             "None"
#define USB_UART_STOP_BITS_STR          "1"
#define USB_UART_FLOW_CONTROL_STR       "None"

// This is the outgoing TX USB UART buffer
char __attribute__((coherent)) usb_uart_tx_buffer[USB_UART_TX_BUFFER_SIZE];

// This is the incoming RX USB UART buffer
char __attribute__((coherent)) usb_uart_rx_buffer[USB_UART_RX_BUFFER_SIZE];

// This variable keeps track of how many bytes are used up in usb_uart_tx_buffer[]
uint32_t usb_uart_tx_buffer_head = 0;

// this is a typedef for a function call based on usb uart command
typedef void (*usb_uart_command_function_t)(char *);

// this structure is the model for each usb uart command, and makes them hashable with UTHASH
// the command_name stirng is what you type to call the command over a serial port
// the command_help_message is the string that's printed to show what the command does when the help command is called
// the function func is the function called when this command is received
typedef struct usb_uart_command_s {
  
    char command_name[32];
    char command_help_message[128];
    usb_uart_command_function_t func;
    UT_hash_handle hh;
    
} usb_uart_command_t ;

// This structure is what holds the hash table. This is the initialization
// of the usb_uart commands hash table.
// DON'T TOUCH THIS!!!
usb_uart_command_t *usb_uart_commands = NULL;

// this keeps track of the number of strings received
uint32_t num_strings_received = 0;

// this is a flag to request that received strings be parsed
uint8_t usb_uart_rx_parse_request = 0;


// This function is used to setup DMA0 for UART transmit
void usbUartTrasmitDmaInitialize(void);

// This function is used to setup DMA1 for UART Receive
void usbUartReceiveDmaInitialize(void);

// This function initializes UART 3 for USB debugging
void usbUartInitialize(void);

// These are the USB UART Interrupt Service Routines
void __ISR(_UART3_FAULT_VECTOR, ipl1SRS) usbUartFaultISR(void);

// These are the USB UART DMA Interrupt Service Routines
void __ISR(_DMA0_VECTOR, IPL5SRS) usbUartTxDmaISR(void);
void __ISR(_DMA1_VECTOR, IPL6SRS) usbUartRxDmaISR(void);

// this function adds a usb_uart command to the usb_uart_commands hash table
void usbUartHashTableAdd(char * input_cmd_name, char * input_cmd_help_message, usb_uart_command_function_t input_cmd_func);

// This function is what interprets strings sent over USB Virtual COM Port
void usbUartRxLUTInterface(char * cmd_string);

// Print help message, prints out list of all commands
void usbUartPrintHelpMessage(void);

// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds);

// This function compares the "needle" string parameter to see if it is the 
// beginning of the "haystack" string variable
// Returns 0 for success, 1 for failure
uint8_t strcomp(const char * haystack, const char * needle);

#endif /* _USB_UART_H */

/* *****************************************************************************
 End of File
 */