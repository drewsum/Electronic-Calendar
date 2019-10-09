/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _USB_UART_RX_LOOKUP_TABLE_H    /* Guard against multiple inclusion */
#define _USB_UART_RX_LOOKUP_TABLE_H

#include <xc.h>
#include <stdio.h>

// This function is what interprets strings sent over USB Virtual COM Port
void usb_uart_rx_lookup_table(char * input_string);

// Print help message, prints out list of all commands
void usbUartPrintHelpMessage(void);

// This function returns a string of a large number of seconds in a human readable format
char * getStringSecondsAsTime(uint32_t input_seconds);

// This function compares the "needle" string parameter to see if it is the 
// beginning of the "haystack" string variable
// Returns 0 for success, 1 for failure
uint8_t strstart(const char * haystack, const char * needle);


#endif /* _USB_UART_RX_LOOKUP_TABLE_H */

/* *****************************************************************************
 End of File
 */
