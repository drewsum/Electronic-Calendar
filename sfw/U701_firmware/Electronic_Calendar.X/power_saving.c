
#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "power_saving.h"
#include "terminal_control.h"

#include "device_control.h"
#include "temp_i2c.h"
#include "pin_macros.h"
#include "rtcc.h"
#include "calendar_leds.h"
#include "binary_clock.h"

// This function disables unused peripherals on startup for power savings
// THIS FUNCTION CAN ONLY BE CALLED ONCE DUE TO PMD LOCKOUT AFTER ONE WRITE SESSION
void PMDInitialize(void) {

    // Unlock PMD
    PMDUnlock();
    
    /* If a PMD bit is set (1), that peripheral is disabled */
    
    // Enable ADC
    PMD1bits.ADCMD = 0;
 
    // Disable comparator voltage reference
    PMD1bits.CVRMD = 1;
    
    // Disable both comparators
    PMD2bits.CMP1MD = 1;
    PMD2bits.CMP2MD = 1;
    
    // Disable all input capture modules
    PMD3bits.IC1MD = 1;
    PMD3bits.IC2MD = 1;
    PMD3bits.IC3MD = 1;
    PMD3bits.IC4MD = 1;
    PMD3bits.IC5MD = 1;
    PMD3bits.IC6MD = 1;
    PMD3bits.IC7MD = 1;
    PMD3bits.IC8MD = 1;
    PMD3bits.IC9MD = 1;
    
    // Disable all output compare modules
    PMD3bits.OC1MD = 1;
    PMD3bits.OC2MD = 1;
    PMD3bits.OC3MD = 1;
    PMD3bits.OC4MD = 1;
    PMD3bits.OC5MD = 1;
    PMD3bits.OC6MD = 1;
    PMD3bits.OC7MD = 1;
    PMD3bits.OC8MD = 1;
    PMD3bits.OC9MD = 1;
    
    // Enable all hardware timers
    // TO-DO: This may change
    PMD4bits.T1MD = 0;
    PMD4bits.T2MD = 0;
    PMD4bits.T3MD = 0;
    PMD4bits.T4MD = 0;
    PMD4bits.T5MD = 0;
    PMD4bits.T6MD = 0;
    PMD4bits.T7MD = 0;
    PMD4bits.T8MD = 0;
    PMD4bits.T9MD = 0;
    
    // Enable UART3, disable others
    PMD5bits.U1MD = 1;
    PMD5bits.U2MD = 1;
    PMD5bits.U3MD = 0;
    PMD5bits.U4MD = 1;
    PMD5bits.U5MD = 1;
    PMD5bits.U6MD = 1;
    
    // Disable all SPI Modules
    PMD5bits.SPI1MD = 1;
    PMD5bits.SPI2MD = 1;
    PMD5bits.SPI3MD = 1;                
    PMD5bits.SPI4MD = 1;
    PMD5bits.SPI5MD = 1;
    PMD5bits.SPI6MD = 1;
    
    // Disable all I2C Modules, except I2C 1
    PMD5bits.I2C1MD = 0;
    PMD5bits.I2C2MD = 1;
    PMD5bits.I2C3MD = 1;
    PMD5bits.I2C4MD = 1;
    PMD5bits.I2C5MD = 1;
    
    // Disable USB Module (UART 3 is used for USB debug)
    PMD5bits.USBMD = 1;
    
    // Enable real time clock/calendar
    PMD6bits.RTCCMD = 0;
    
    // Enable all reference clocks, per device errata
    PMD6bits.REFO1MD = 0;
    PMD6bits.REFO2MD = 0;
    PMD6bits.REFO3MD = 0;
    PMD6bits.REFO4MD = 0;
    
    // Disable peripheral master port
    PMD6bits.PMPMD = 1;
    
    // Disable external bus interface (EBI)
    PMD6bits.EBIMD = 1;
    
    // Disable serial quad interface
    PMD6bits.SQI1MD = 1;
    
    // Disable ethernet module
    PMD6bits.ETHMD = 1;
    
    // Enable DMA
    PMD7bits.DMAMD = 0;
    
    // Disable random number generator
    PMD7bits.RNGMD = 1;
    
    // Lock PMD
    PMDLock();
    
}


// This function prints the status of PMD settings
void printPMDStatus(void) {

    terminalTextAttributesReset();    
    
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Peripheral Module Disable Status:\n\r");
    
    // ADC
    if (PMD1bits.ADCMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   ADC Enabled:                              %s\n\r", PMD1bits.ADCMD ? "F" : "T");
    
    // CVREF
    if (PMD1bits.CVRMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Comparator Voltage Reference Enabled:     %s\n\r", PMD1bits.CVRMD ? "F" : "T");
    
    // Comparators
    if (PMD2bits.CMP1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Comparator 1 Enabled:                     %s\n\r", PMD2bits.CMP1MD ? "F" : "T");
    if (PMD2bits.CMP2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Comparator 2 Enabled:                     %s\n\r", PMD2bits.CMP2MD ? "F" : "T");
    
    // Input Capture Modules:
    if (PMD3bits.IC1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Input Capture 1 Enabled:                  %s\n\r", PMD3bits.IC1MD ? "F" : "T");
    if (PMD3bits.IC2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Input Capture 2 Enabled:                  %s\n\r", PMD3bits.IC2MD ? "F" : "T");
    if (PMD3bits.IC3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Input Capture 3 Enabled:                  %s\n\r", PMD3bits.IC3MD ? "F" : "T");
    if (PMD3bits.IC4MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Input Capture 4 Enabled:                  %s\n\r", PMD3bits.IC4MD ? "F" : "T");
    if (PMD3bits.IC5MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Input Capture 5 Enabled:                  %s\n\r", PMD3bits.IC5MD ? "F" : "T");
    if (PMD3bits.IC6MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Input Capture 6 Enabled:                  %s\n\r", PMD3bits.IC6MD ? "F" : "T");
    if (PMD3bits.IC7MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Input Capture 7 Enabled:                  %s\n\r", PMD3bits.IC7MD ? "F" : "T");
    if (PMD3bits.IC8MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Input Capture 8 Enabled:                  %s\n\r", PMD3bits.IC8MD ? "F" : "T");
    if (PMD3bits.IC9MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Input Capture 9 Enabled:                  %s\n\r", PMD3bits.IC9MD ? "F" : "T");
    
    // Output Compare Modules
    if (PMD3bits.OC1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Output Compare 1 Enabled:                 %s\n\r", PMD3bits.OC1MD ? "F" : "T");
    if (PMD3bits.OC2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Output Compare 2 Enabled:                 %s\n\r", PMD3bits.OC2MD ? "F" : "T");
    if (PMD3bits.OC3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Output Compare 3 Enabled:                 %s\n\r", PMD3bits.OC3MD ? "F" : "T");
    if (PMD3bits.OC4MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Output Compare 4 Enabled:                 %s\n\r", PMD3bits.OC4MD ? "F" : "T");
    if (PMD3bits.OC5MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Output Compare 5 Enabled:                 %s\n\r", PMD3bits.OC5MD ? "F" : "T");
    if (PMD3bits.OC6MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Output Compare 6 Enabled:                 %s\n\r", PMD3bits.OC6MD ? "F" : "T");
    if (PMD3bits.OC7MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Output Compare 7 Enabled:                 %s\n\r", PMD3bits.OC7MD ? "F" : "T");
    if (PMD3bits.OC8MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Output Compare 8 Enabled:                 %s\n\r", PMD3bits.OC8MD ? "F" : "T");
    if (PMD3bits.OC9MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Output Compare 9 Enabled:                 %s\n\r", PMD3bits.OC9MD ? "F" : "T");
    
    // Timers
    if (PMD4bits.T1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Timer 1 Enabled:                          %s\n\r", PMD4bits.T1MD ? "F" : "T");
    if (PMD4bits.T2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Timer 2 Enabled:                          %s\n\r", PMD4bits.T2MD ? "F" : "T");
    if (PMD4bits.T3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Timer 3 Enabled:                          %s\n\r", PMD4bits.T3MD ? "F" : "T");
    if (PMD4bits.T4MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Timer 4 Enabled:                          %s\n\r", PMD4bits.T4MD ? "F" : "T");
    if (PMD4bits.T5MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Timer 5 Enabled:                          %s\n\r", PMD4bits.T5MD ? "F" : "T");
    if (PMD4bits.T6MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Timer 6 Enabled:                          %s\n\r", PMD4bits.T6MD ? "F" : "T");
    if (PMD4bits.T7MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Timer 7 Enabled:                          %s\n\r", PMD4bits.T7MD ? "F" : "T");
    if (PMD4bits.T8MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Timer 8 Enabled:                          %s\n\r", PMD4bits.T8MD ? "F" : "T");
    if (PMD4bits.T9MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Timer 9 Enabled:                          %s\n\r", PMD4bits.T9MD ? "F" : "T");
    
    // UART Modules
    if (PMD5bits.U1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   UART 1 Enabled:                           %s\n\r", PMD5bits.U1MD ? "F" : "T");
    if (PMD5bits.U2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   UART 2 Enabled:                           %s\n\r", PMD5bits.U2MD ? "F" : "T");
    if (PMD5bits.U3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   UART 3 Enabled:                           %s\n\r", PMD5bits.U3MD ? "F" : "T");
    if (PMD5bits.U4MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   UART 4 Enabled:                           %s\n\r", PMD5bits.U4MD ? "F" : "T");
    if (PMD5bits.U5MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   UART 5 Enabled:                           %s\n\r", PMD5bits.U5MD ? "F" : "T");
    if (PMD5bits.U6MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   UART 6 Enabled:                           %s\n\r", PMD5bits.U6MD ? "F" : "T");
    
    // SPI Modules
    if (PMD5bits.SPI1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   SPI 1 Enabled:                            %s\n\r", PMD5bits.SPI1MD ? "F" : "T");
    if (PMD5bits.SPI2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   SPI 2 Enabled:                            %s\n\r", PMD5bits.SPI2MD ? "F" : "T");
    if (PMD5bits.SPI3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   SPI 3 Enabled:                            %s\n\r", PMD5bits.SPI3MD ? "F" : "T");
    if (PMD5bits.SPI4MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   SPI 4 Enabled:                            %s\n\r", PMD5bits.SPI4MD ? "F" : "T");
    if (PMD5bits.SPI5MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   SPI 5 Enabled:                            %s\n\r", PMD5bits.SPI5MD ? "F" : "T");
    if (PMD5bits.SPI6MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   SPI 6 Enabled:                            %s\n\r", PMD5bits.SPI6MD ? "F" : "T");
    
    // I2C Modules
    if (PMD5bits.I2C1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   I2C 1 Enabled:                            %s\n\r", PMD5bits.I2C1MD ? "F" : "T");
    if (PMD5bits.I2C2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   I2C 2 Enabled:                            %s\n\r", PMD5bits.I2C2MD ? "F" : "T");
    if (PMD5bits.I2C3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   I2C 3 Enabled:                            %s\n\r", PMD5bits.I2C3MD ? "F" : "T");
    if (PMD5bits.I2C2MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   I2C 4 Enabled:                            %s\n\r", PMD5bits.I2C4MD ? "F" : "T");
    if (PMD5bits.I2C5MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   I2C 5 Enabled:                            %s\n\r", PMD5bits.I2C5MD ? "F" : "T");
    
    // USB Module
    if (PMD5bits.USBMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   USB Enabled:                              %s\n\r", PMD5bits.USBMD ? "F" : "T");
    
    // RTCC
    if (PMD6bits.RTCCMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Real Time Clock Enabled:                  %s\n\r", PMD6bits.RTCCMD ? "F" : "T");
    
    // REFCLKS
    if (PMD6bits.REFO1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Reference Clock 1 Enabled:                %s\n\r", PMD6bits.REFO1MD ? "F" : "T");
    if (PMD6bits.REFO1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Reference Clock 2 Enabled:                %s\n\r", PMD6bits.REFO2MD ? "F" : "T");
    if (PMD6bits.REFO3MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Reference Clock 3 Enabled:                %s\n\r", PMD6bits.REFO3MD ? "F" : "T");
    if (PMD6bits.REFO4MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Reference Clock 4 Enabled:                %s\n\r", PMD6bits.REFO4MD ? "F" : "T");
    
    // PMP
    if (PMD6bits.PMPMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Parallel Master Port Enabled:             %s\n\r", PMD6bits.PMPMD ? "F" : "T");
    
    // EBI
    if (PMD6bits.EBIMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   External Bus Interface Enabled:           %s\n\r", PMD6bits.EBIMD ? "F" : "T");
    
    // SQI
    if (PMD6bits.SQI1MD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Serial Quad Interface Enabled:            %s\n\r", PMD6bits.SQI1MD ? "F" : "T");
    
    // Ethernet
    if (PMD6bits.ETHMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Ethernet Enabled:                         %s\n\r", PMD6bits.ETHMD ? "F" : "T");
    
    // DMA
    if (PMD7bits.DMAMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   Direct Memory Access Enabled:             %s\n\r", PMD7bits.DMAMD ? "F" : "T");
    
    // Random Number Generator
    if (PMD7bits.RNGMD) terminalTextAttributes(RED_COLOR, BLACK_COLOR, REVERSE_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, REVERSE_FONT);
    printf("   Random Number Generator Enabled:          %s\n\r", PMD7bits.RNGMD ? "F" : "T");
    
    // PMD Locked?
    if (CFGCONbits.PMDLOCK) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("   PMD Locked:                               %s\n\r", CFGCONbits.PMDLOCK ? "T" : "F");
    
    terminalTextAttributesReset();
    
}

// this function initializes INT2 for use with the cap touch power toggle pushbutton
void capTouchPowerInitialize(void) {
 
    // INT2 polarity is rising edge
    INTCONbits.INT2EP = 1;
    
    disableInterrupt(External_Interrupt_2);
    setInterruptPriority(External_Interrupt_2, 7);
    setInterruptSubpriority(External_Interrupt_2, 1);
    clearInterruptFlag(External_Interrupt_2);
    enableInterrupt(External_Interrupt_2);
    
}

// this is the cap touch power toggle button interrupt service routine
void __ISR(_EXTERNAL_2_VECTOR, IPL7SRS) capTouchPowerToggleISR(void) {
    
    if (sleep_state == 0) pushbutton_shutdown_request = 1;
    else pushbutton_wakeup_request = 1;
    
    // clear IRQ
    clearInterruptFlag(External_Interrupt_2);
    disableInterrupt(External_Interrupt_2);
    
}

// this function shuts down the MCU when the power toggle button is pressed
void capToughPowerToggleShutdown(void) {
 
    // Clear WDT and shut it off
    kickTheDog();
    WDTCONbits.ON = 0;
    
    terminalTextAttributes(MAGENTA_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Feeling sleepy, entering Idle mode\r\n");
    terminalTextAttributesReset();
    
    // send previous print message and wait until USB UART is cleared
    while(U3STAbits.TRMT == 0);
    
    // shut down I2C
    while (TEMP_I2C_STATUS == TEMP_I2C_MESSAGE_PENDING);
    
    // disable interrupts that could wake from sleep
    disableInterrupt(Real_Time_Clock);
    disableInterrupt(I2C1_Master_Event);
    disableInterrupt(I2C1_Bus_Collision_Event);
    disableInterrupt(Timer1);
    disableInterrupt(ADC_End_Of_Scan_Ready);
    disableInterrupt(ADC_Data_10);
    disableInterrupt(ADC_Data_29);
    disableInterrupt(ADC_Data_43);
    disableInterrupt(ADC_Data_44);
    disableInterrupt(ADC_Data_1);
    disableInterrupt(ADC_Data_2);
    disableInterrupt(ADC_Data_3);
    disableInterrupt(ADC_Data_4);
    disableInterrupt(DMA_Channel_0);
    disableInterrupt(DMA_Channel_1);
    disableInterrupt(UART3_Fault);
    
    // Disable calendar and status LEDs
    STATUS_LED_ENABLE_PIN = 0;
    DATE_DECODE_ENABLE_PIN = 0;
    nDATE_DECODE_1_PIN = 1;
    nDATE_DECODE_2_PIN = 1;
    nDATE_DECODE_3_PIN = 1;
    nDATE_DECODE_4_PIN = 1;
    nSECONDS0_LED_PIN = 1;
    nSECONDS1_LED_PIN = 1;
    nSECONDS2_LED_PIN = 1;
    nSECONDS3_LED_PIN = 1;
    nSECONDS4_LED_PIN = 1;
    nSECONDS5_LED_PIN = 1;
    nSECONDS6_LED_PIN = 1;
    nMINUTES0_LED_PIN = 1;
    nMINUTES1_LED_PIN = 1;
    nMINUTES2_LED_PIN = 1;
    nMINUTES3_LED_PIN = 1;
    nMINUTES4_LED_PIN = 1;
    nMINUTES5_LED_PIN = 1;
    nMINUTES6_LED_PIN = 1;
    nHOURS0_LED_PIN = 1;
    nHOURS1_LED_PIN = 1;
    nHOURS2_LED_PIN = 1;
    nHOURS3_LED_PIN = 1;
    nHOURS4_LED_PIN = 1;
    nHOURS5_LED_PIN = 1;
    nHOURS6_LED_PIN = 1;
    DATE_B0_PIN = 0;
    DATE_B1_PIN = 0;
    DATE_B2_PIN = 0;
    YEAR_B0_PIN = 0;
    YEAR_B1_PIN = 0;
    YEAR_B2_PIN = 0;
    nJAN_LED_PIN = 1;
    nFEB_LED_PIN = 1;
    nMAR_LED_PIN = 1;
    nAPR_LED_PIN = 1;
    nMAY_LED_PIN = 1;
    nJUN_LED_PIN = 1;
    nJUL_LED_PIN = 1;
    nAUG_LED_PIN = 1;
    nSEP_LED_PIN = 1;
    nOCT_LED_PIN = 1;
    nNOV_LED_PIN = 1;
    nDEC_LED_PIN = 1;
    nSUN_LED_PIN = 1;
    nMON_LED_PIN = 1;
    nTUE_LED_PIN = 1;
    nWED_LED_PIN = 1;
    nTHUR_LED_PIN = 1;
    nFRI_LED_PIN = 1;
    nSAT_LED_PIN = 1;
    
    softwareDelay(10000000);
    
    clearInterruptFlag(External_Interrupt_2);
    enableInterrupt(External_Interrupt_2);
    
    sleep_state = 1;
    pushbutton_shutdown_request = 0;
    
    // disable unused PBCLKs
    PB2DIVbits.ON = 0;
    PB3DIVbits.ON = 0;
    PB5DIVbits.ON = 0;
    PB8DIVbits.ON = 0;
    
    // switch SYSCLK to LPRC, only do the switch if we're not already clocked off of LPRC
    if (OSCCONbits.COSC != 0b101) {
        
        // unlock the device
        deviceUnlock();

        // unlock clock and PLL settings
        OSCCONbits.CLKLOCK = 0;
        
        // new oscillator select is LPRC
        OSCCONbits.NOSC = 0b101;
        
        // start a clock change and wait until complete
        OSCCONbits.OSWEN = 1;
        while (OSCCONbits.OSWEN);
        
        // lock clock and PLL settings
        OSCCONbits.CLKLOCK = 1;
        
        // lock device
        deviceLock();
        
    }
    
    // Enter idle mode
    //deviceUnlock();
    //OSCCONCLR = 0x10; // Set the power-saving mode to an idle mode
    //deviceLock();
    asm volatile ( "wait" ); // Put device into Idle mode
    
}

// this function wakes up the MCU when the power toggle button is pressed
void capToughPowerToggleWakeup(void) {
 
    // Clear WDT and turn it on
    kickTheDog();
    WDTCONbits.ON = 1;
    
    // Clear heartbeat timer
    TMR1 = 0;
    
    // switch SYSCLK to SPLL, only do the switch if we're not already clocked off of SPLL
    if (OSCCONbits.COSC != 0b001) {
        
        // unlock the device
        deviceUnlock();

        // unlock clock and PLL settings
        OSCCONbits.CLKLOCK = 0;
        
        // new oscillator select is SPLL
        OSCCONbits.NOSC = 0b001;
        
        // start a clock change and wait until complete
        OSCCONbits.OSWEN = 1;
        while (OSCCONbits.OSWEN);
        
        // lock clock and PLL settings
        OSCCONbits.CLKLOCK = 1;
        
        // lock device
        deviceLock();
        
    }
    
    // enable unused PBCLKs
    PB2DIVbits.ON = 1;
    PB3DIVbits.ON = 1;
    PB5DIVbits.ON = 1;
    PB8DIVbits.ON = 1;
    
    // enable interrupts that could wake from sleep
    enableInterrupt(Real_Time_Clock);
    enableInterrupt(I2C1_Master_Event);
    enableInterrupt(I2C1_Bus_Collision_Event);
    enableInterrupt(Timer1);
    enableInterrupt(ADC_End_Of_Scan_Ready);
    enableInterrupt(ADC_Data_10);
    enableInterrupt(ADC_Data_29);
    enableInterrupt(ADC_Data_43);
    enableInterrupt(ADC_Data_44);
    enableInterrupt(ADC_Data_1);
    enableInterrupt(ADC_Data_2);
    enableInterrupt(ADC_Data_3);
    enableInterrupt(ADC_Data_4);
    enableInterrupt(DMA_Channel_0);
    enableInterrupt(DMA_Channel_1);
    enableInterrupt(UART3_Fault);
    
    // print to user that we're waking up
    terminalTextAttributes(MAGENTA_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Wakey Wakey, eggs and bakey: exiting Idle mode\r\n");
    terminalTextAttributesReset();
    
    // Wait for sync to go low, signifying we can do an RTCC read
    while (RTCCONbits.RTCSYNC == 1);
    
    // Copy values from RTCC into ram shadow register
    rtcc_shadow.weekday     = RTCDATEbits.WDAY01;
    rtcc_shadow.day         = (RTCDATEbits.DAY10 * 10) + RTCDATEbits.DAY01;
    rtcc_shadow.month       = (RTCDATEbits.MONTH10 * 10) + RTCDATEbits.MONTH01;
    rtcc_shadow.year        = (RTCDATEbits.YEAR10 * 10) + RTCDATEbits.YEAR01 + 2000;
    rtcc_shadow.hours       = (RTCTIMEbits.HR10 * 10) + RTCTIMEbits.HR01;
    rtcc_shadow.minutes     = (RTCTIMEbits.MIN10 * 10) + RTCTIMEbits.MIN01;
    rtcc_shadow.seconds     = (RTCTIMEbits.SEC10 * 10) + RTCTIMEbits.SEC01;
    
    // update values displayed on binary clock LEDs
    updateBinaryClockLEDs(rtcc_shadow.hours, rtcc_shadow.minutes, rtcc_shadow.seconds);
    // update value displayed on month LEDs
    updateMonthLEDs(rtcc_shadow.month);
    // update value displayed on weekday LEDs
    updateWeekdayLEDs(rtcc_shadow.weekday);
    // update value displayed on year LEDs
    updateYearLEDs(rtcc_shadow.year);
    // update value displayed on day LEDs
    updateDateLEDs(rtcc_shadow.day);
    
    // enable calendar and status LEDs
    STATUS_LED_ENABLE_PIN = 1;
    DATE_DECODE_ENABLE_PIN = 1;
    
    softwareDelay(10000000);
    
    clearInterruptFlag(External_Interrupt_2);
    enableInterrupt(External_Interrupt_2);
    
    sleep_state = 0;
    pushbutton_wakeup_request = 0;
    
}