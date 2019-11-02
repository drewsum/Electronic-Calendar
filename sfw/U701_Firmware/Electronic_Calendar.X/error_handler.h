/* ************************************************************************** */
/** Error Handler

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    error_handler.h

  @Summary
 Provides functions and variables/structures for recording and reporting errors
 during runtime

 */
/* ************************************************************************** */

#ifndef _ERROR_HANDLER_H    /* Guard against multiple inclusion */
#define _ERROR_HANDLER_H

#include <xc.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#define ERROR_HANDLER_NUM_FLAGS  18

// Error handler structure
// Follow the convention in XC32 user's guide section 8.6.2
// Each flag indicates if the described error has occurred
// This is used for controlling status LEDs and USB debugging
// Access a flag like any C structure
union error_handler_u {
    
    struct {

        unsigned configuration_error                    : 8;    // error in device configuration at boot
        unsigned USB_general_error                      : 8;    // Error with USB debugging interface
        unsigned USB_framing_error                      : 8;    // usb uart framing error
        unsigned USB_parity_error                       : 8;    // usb uart parity error
        unsigned USB_overrun_error                      : 8;    // RX overrun error
        unsigned USB_tx_dma_overrun                     : 8;
        unsigned USB_tx_dma_address_error               : 8;    
        unsigned USB_tx_dma_error                       : 8;    // Error with usb uart tx dma
        unsigned USB_rx_dma_overrun                     : 8;
        unsigned USB_rx_dma_address_error               : 8;
        unsigned USB_rx_dma_error                       : 8;    // Error with usb uart rx dma
        unsigned DMT_error                              : 8;    // Deadman timer error
        unsigned system_bus_protection_violation        : 8;    // System bus protection event occurred
        unsigned prefetch_module_SEC                    : 8;    // Prefetch module recorded an SEC event
        unsigned ADC_configuration_error                : 8;    // ADC could not be configured properly
        unsigned ADC_bandgap_vref_voltage_fault         : 8;
        unsigned ADC_reference_fault                    : 8;
        unsigned clock_failure                          : 8;

    }  __attribute__((persistent)) flags;

    uint8_t flag_array[ERROR_HANDLER_NUM_FLAGS] __attribute__((persistent)) ;
    
} error_handler;
    
// this array holds the names of error handler flags
const char * const error_handler_flag_names[] = {
 
    "Configuration",
    "USB General",
    "USB Framing",
    "USB Parity",
    "USB Overrun",
    "USB TX DMA Overrun",
    "USB TX DMA Address",
    "USB TX DMA",
    "USB RX DMA Overrun",
    "USB RX DMA Address",
    "USB RX DMA",
    "Deadman Timer",
    "System Bus Protection Violation",
    "Prefetch Module SEC",
    "ADC Configuration",
    "ADC Bandgap VREF Voltage",
    "ADC Reference",
    "Clock Failure"

};

// This function initializes the error handler structure to detect fault conditions
void errorHandlerInitialize(void);

// System Bus Protection Violation interrupt service routine
void __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, ipl1SRS) systemBusProtectionISR(void);

// This function is called when a general exception occurs
void __attribute__((nomips16)) _general_exception_handler(void);

// This function is called when a TRB exception occurs
void __attribute__((nomips16)) _simple_tlb_refill_exception_handler(void);

// This function is called when a cache error occurs
void __attribute__((nomips16)) _cache_err_exception_handler(void);

// This function is called when a bootstrap exception occurs
void __attribute__((nomips16)) _bootstrap_exception_handler(void);

// This function prints the status of the error handler flags
void printErrorHandlerStatus(void);

// This function clears the error handler flags
void clearErrorHandler(void);

// This function updates the error LEDs based on the error handler state
void updateErrorLEDs(void);

// This function prints short strings during a CPU exception
void exceptionPrint(char *input_string);

// this function checks for clock failures and records them into the error handler
void clockFailCheck(void);

#endif /* _ERROR_HANDLER_H */

/* *****************************************************************************
 End of File
 */
