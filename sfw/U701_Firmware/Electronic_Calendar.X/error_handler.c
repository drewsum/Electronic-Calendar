
#include <xc.h>
#include <stdio.h>
#include <string.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#include "error_handler.h"
#include "32mz_interrupt_control.h"
#include "pin_macros.h"
#include "terminal_control.h"

// This function initializes the error handler structure to detect fault conditions
void errorHandlerInitialize(void) {
 
    // Setup system bus protection violation interrupt
    disableInterrupt(System_Bus_Protection_Violation);
    setInterruptPriority(System_Bus_Protection_Violation, 1);
    setInterruptSubpriority(System_Bus_Protection_Violation, 1);
    clearInterruptFlag(System_Bus_Protection_Violation);
    enableInterrupt(System_Bus_Protection_Violation);
    
}

// System Bus Protection Violation interrupt service routine
void __ISR(_SYSTEM_BUS_PROTECTION_VECTOR, ipl1SRS) systemBusProtectionISR(void) {
 
    // Record a system bus protection violation occurred
    error_handler.system_bus_protection_violation_flag = 1;
    clearInterruptFlag(System_Bus_Protection_Violation);
    
}

// This function is called when a general exception occurs
void __attribute__((nomips16)) _general_exception_handler(void) {
    
    // Signal to user something really bad happened
//    EBI_ERROR_LED_PIN = 1;
//    SPI_ERROR_LED_PIN = 1;
//    WIFI_ERROR_LED_PIN = 1;
//    USB_ERROR_LED_PIN = 1;
//    OTHER_ERROR_LED_PIN = 1;
//    nACTIVE_LED_PIN = 1;
//    
    // Disable global interrupts
    setGlobalInterruptsState(0);
    
    // Clear watchdog and deadman to give user time to see error state
//    kickTheDog();
//    holdThumbTighter();
//    
    exceptionPrint(" \033[0;31;40mCPU General Exception! EXCCODE: ");
    
    uint8_t exception_code = (_CP0_GET_CAUSE() >> 2) & 0b11111;
    char exception_code_number = exception_code + 48;
    U3TXREG = exception_code_number;
    exceptionPrint("\n\r");
    
    
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function is called when a TLB exception occurs
void __attribute__((nomips16)) _simple_tlb_refill_exception_handler(void) {

    // Signal to user something really bad happened
//    EBI_ERROR_LED_PIN = 1;
//    SPI_ERROR_LED_PIN = 1;
//    WIFI_ERROR_LED_PIN = 1;
//    USB_ERROR_LED_PIN = 1;
//    OTHER_ERROR_LED_PIN = 1;
//    nACTIVE_LED_PIN = 1;
//    
//    // Clear watchdog to give user time to see error state
//    kickTheDog();
//    holdThumbTighter();
//    
    exceptionPrint("\033[0;31;40mCPU TLB Refill Exception!\n\r");
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function is called when a cache error occurs
void __attribute__((nomips16)) _cache_err_exception_handler(void) {

    // Signal to user something really bad happened
//    EBI_ERROR_LED_PIN = 1;
//    SPI_ERROR_LED_PIN = 1;
//    WIFI_ERROR_LED_PIN = 1;
//    USB_ERROR_LED_PIN = 1;
//    OTHER_ERROR_LED_PIN = 1;
//    nACTIVE_LED_PIN = 1;
//    
//    // Clear watchdog to give user time to see error state
//    kickTheDog();
//    holdThumbTighter();
//    
    exceptionPrint("\033[0;31;40mCPU Cache Exception!\n\r");
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function is called when a bootstrap exception occurs
void __attribute__((nomips16)) _bootstrap_exception_handler(void) {

    // Signal to user something really bad happened
//    EBI_ERROR_LED_PIN = 1;
//    SPI_ERROR_LED_PIN = 1;
//    WIFI_ERROR_LED_PIN = 1;
//    USB_ERROR_LED_PIN = 1;
//    OTHER_ERROR_LED_PIN = 1;
//    nACTIVE_LED_PIN = 1;
//    
//    // Clear watchdog to give user time to see error state
//    kickTheDog();
//    holdThumbTighter();
//    
    exceptionPrint("\033[0;31;40mCPU Bootstrap Exception!\n\r");
    
    // Give up
    // Wait for watchdog to save us
    while(1);
    
    // Half-baked exception recovery
    // _CP0_SET_EPC(_CP0_GET_EPC()+4); // increment Error Program Counter (EPC) to next word (skip over offending instruction)
    
}

// This function prints the status of the error handler flags
void printErrorHandlerStatus(void) {
 
    terminalTextAttributesReset();    
    
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    
    // Print heading
    printf("Error Handler Status:\n\r");
    
    // Print status of each error handler element
    // Configuration Error
    if (error_handler.configuration_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   Configuration error %s\n\r", error_handler.configuration_error_flag ? "has occurred" : "has not occurred");
    
    // USB Error
    if (error_handler.USB_error_flag) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("   USB UART error %s\n\r", error_handler.USB_error_flag ? "has occurred" : "has not occurred");
    
    
    terminalTextAttributesReset();    
    
}

// This function clears the error handler flags
void clearErrorHandler(void) {
 
    error_handler.DMT_error_flag = 0;
    error_handler.USB_error_flag = 0;
    error_handler.USB_tx_dma_error_flag = 0;
    error_handler.configuration_error_flag = 0;

    error_handler.system_bus_protection_violation_flag = 0;
    error_handler.prefetch_module_SEC_flag = 0;
    // error_handler.ADC_configuration_error_flag = 0;
    
}

// This function updates the error LEDs based on the error handler state
void updateErrorLEDs(void) {
 
    // Configuration Error
//    if (    error_handler.configuration_error_flag ||
//            error_handler.DMT_error_flag ||
//            error_handler.system_bus_protection_violation_flag ||
//            error_handler.prefetch_module_SEC_flag ||
//            error_handler.other_error_flag) {
//        
//        OTHER_ERROR_LED_PIN = 1;
//        
//    }
//    
//    else OTHER_ERROR_LED_PIN = 0;

    // USB Error
    if (    error_handler.USB_error_flag || 
            error_handler.USB_tx_dma_error_flag ||
            error_handler.USB_rx_dma_error_flag) {
        
        USB_ERROR_LED_PIN = 1;
    
    }
    else USB_ERROR_LED_PIN = 0;    
    
}

// This function prints short strings during a CPU exception
void exceptionPrint(char *input_string) {
 
    // loop through all input characters
    int i;
    for (i = 0; i < strlen(input_string); i++) {
     
        // if we're done with the string, return
        if (input_string[i] == '\0') return;
        
        // send single character
        U3TXREG = input_string[i];
        
        // wait for buffer to open
        while(U3STAbits.UTXBF);
        
        
    }
    
}