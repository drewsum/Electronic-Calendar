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

#endif /* _USB_UART_H */

/* *****************************************************************************
 End of File
 */