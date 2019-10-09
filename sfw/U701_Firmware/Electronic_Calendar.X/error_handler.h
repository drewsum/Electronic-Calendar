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

// Error handler structure - can hold up to 32 flags (I think, we'll see if we run over)
// Follow the convention in XC32 user's guide section 8.6.2
// Each flag indicates if the described error has occurred
// This is used for controlling status LEDs and USB debugging
// Access a flag like any C structure
struct {
    
    unsigned configuration_error_flag                   : 1;    // error in device setup
    
    unsigned USB_error_flag                             : 1;    // Error with USB debugging interface
    unsigned USB_tx_dma_error_flag                      : 1;    // Error with usb uart tx dma
    unsigned USB_rx_dma_error_flag                      : 1;    // Error with usb uart rx dma
    unsigned DMT_error_flag                             : 1;    // Deadman timer error
    unsigned system_bus_protection_violation_flag       : 1;    // System bus protection event occurred
    unsigned prefetch_module_SEC_flag                   : 1;    // Prefetch module recorded an SEC event
    unsigned other_error_flag                           : 1;    // undiagnosable error
    //unsigned ADC_configuration_error_flag               : 1;    // ADC could not be configured properly
    
} error_handler;

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

#endif /* _ERROR_HANDLER_H */

/* *****************************************************************************
 End of File
 */
