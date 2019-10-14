
#include <xc.h>

#include <stdio.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>


#include "adc.h"
#include "32mz_interrupt_control.h"
#include "error_handler.h"
#include "pin_macros.h"
#include "terminal_control.h"

/* Used ADC channels include:
 * 
 * AN10 - VBAT_ADC
 * AN29 - POS3P3_ISNS_ADC
 * AN46 - POS5_USB_ADC
 * AN47 - POS12_ADC
 * AN48 - POS3P3_ADC
 * AN49 - POS12_ISNS_ADC
 * 
 * */


// This function initializes the ADC modules
void ADCInitialize(void) {
    
    // Setup ADC end of scan interrupt
    disableInterrupt(ADC_End_Of_Scan_Ready);
    setInterruptPriority(ADC_End_Of_Scan_Ready, 1);
    setInterruptSubpriority(ADC_End_Of_Scan_Ready, 1);
    clearInterruptFlag(ADC_End_Of_Scan_Ready);
    
    // Block ADC triggers for startup
    ADCCON3bits.TRGSUSP = 1;
    
    /* initialize ADC calibration setting */
    ADC7CFG = DEVADC7;
    
    /* Configure ADCCON1 */
    ADCCON1 = 0;
    ADCCON1bits.TRBEN = 0;     // Disable Turbo Mode
    if (ADCCON1bits.TRBERR) error_handler.ADC_configuration_error_flag = 1;     // Verify turbo mode disabled
    ADCCON1bits.SIDL = 1;   // Stop ADC in idle mode

    /* Configure ADCCON2 */
    ADCCON2 = 0;
    ADCCON2bits.SAMC = 0b0000001000;       // Set ADC7 sample time
    ADCCON2bits.ADCDIV = 0b0000001;         // Set clock divider

    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 0b1111; // Set for longest wakeup time to be safe
    
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0; // Select input clock source
    ADCCON3bits.CONCLKDIV = 1; // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0; // Select AVDD and AVSS as reference source
    
    /* Select ADC sample time and conversion clock */
    ADCCON2bits.ADCDIV = 1;
    ADCCON2bits.SAMC = 5;
    ADCCON1bits.SELRES = 3;
    
    /* Select ADC input mode */
//    ADCIMCON3bits.SIGN38 = 0; // unsigned data format
//    ADCIMCON3bits.DIFF38 = 0; // Single ended mode
//    ADCIMCON3bits.SIGN39 = 0; // unsigned data format
//    ADCIMCON3bits.DIFF39 = 0; // Single ended mode
//    ADCIMCON3bits.SIGN40 = 0; // unsigned data format
//    ADCIMCON3bits.DIFF40 = 0; // Single ended mode
//    ADCIMCON3bits.SIGN41 = 0; // unsigned data format
//    ADCIMCON3bits.DIFF41 = 0; // Single ended mode
//    ADCIMCON3bits.SIGN42 = 0; // unsigned data format
//    ADCIMCON3bits.DIFF42 = 0; // Single ended mode
    
    /* Configure ADCGIRQENx */
    ADCGIRQEN1 = 0;
    ADCGIRQEN2 = 0;
    // ADCCON2bits.BGVRIEN = 1;        // Enable analog circuits ready interrupt
    // ADCANCONbits.WKIEN7 = 1;        // Enable ADC7 warm up interrupt
//    ADCGIRQEN2bits.AGIEN38 = 1;     // Enable Data 38 ready interrupt
//    ADCGIRQEN2bits.AGIEN39 = 1;     // Enable Data 39 ready interrupt
//    ADCGIRQEN2bits.AGIEN40 = 1;     // Enable Data 40 ready interrupt
//    ADCGIRQEN2bits.AGIEN41 = 1;     // Enable Data 41 ready interrupt
//    ADCGIRQEN2bits.AGIEN42 = 1;     // Enable Data 42 ready interrupt
    // ADCGIRQEN2bits.AGIEN43 = 1;     // Enable Data 43 ready interrupt
    // ADCGIRQEN2bits.AGIEN44 = 1;     // Enable Data 44 ready interrupt
    ADCCON2bits.EOSIEN = 1;         // Enable interrupt on end of scan
    
    /* Configure ADCCSSx */
    ADCCSS1 = 0;
    ADCCSS2 = 0;
//    ADCCSS2bits.CSS38 = 1;          // Enable Channel 38 for common scan
//    ADCCSS2bits.CSS39 = 1;          // Enable Channel 39 for common scan
//    ADCCSS2bits.CSS40 = 1;          // Enable Channel 40 for common scan
//    ADCCSS2bits.CSS41 = 1;          // Enable Channel 41 for common scan
//    ADCCSS2bits.CSS42 = 1;          // Enable Channel 42 for common scan
    ADCCSS2bits.CSS43 = 1;          // Enable Channel 43 for common scan
    ADCCSS2bits.CSS44 = 1;          // Enable Channel 44 for common scan
    
    /* Configure ADCCMPCONx */
    ADCCMPCON1 = 0; // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0; // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0; // Other registers are ?don't care?.
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    
   /* Configure ADCFLTRx */
    ADCFLTR1 = 0; // No oversampling filters are used.
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;
    
    /* Set up the trigger sources */
    ADCCON1bits.STRGLVL = 0;            // Edge trigger mode
    ADCCON1bits.STRGSRC = 0b00110;      // Trigger source is Timer3
    
    /* Early interrupt */
    ADCEIEN1 = 0; // No early interrupts used
    ADCEIEN2 = 0;
    
    /* Turn the ADC on */
    ADCCON1bits.ON = 1;
    
    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY); // Wait until the reference voltage is ready
    
    if (ADCCON2bits.REFFLT) error_handler.ADC_configuration_error_flag = 1;     // Record error if reference fails
    
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN7 = 1; // Enable the clock to analog bias
    
    /* Enable the ADC module */
    ADCCON3bits.DIGEN7 = 1; // Enable ADC7 digital circuits
    
    // Unblock triggers
    ADCCON3bits.TRGSUSP = 0;
    
    ADCANCONbits.WKIEN7 = 0;    // Disable ADC7 warm up interrupt
    
    // Setup ADC Trigger Timer
    ADCTriggerTimerInitialize();
    
    // Enable ADC end of scan interrupt
    enableInterrupt(ADC_End_Of_Scan_Ready);
    
}

// This function initializes Timer3 as the ADC trigger timer
void ADCTriggerTimerInitialize(void) {
 
    // Stop timer 3
    T3CONbits.ON = 0;
    
    // Stop timer 3 in idle
    T3CONbits.SIDL = 1;
    
    // Disable gated time accumulation
    T3CONbits.TGATE = 0;
    
    // Set timer 3 prescalar to 4
    T3CONbits.TCKPS = 0b010;
    
    // Set timer clock input as PBCLK3
    T3CONbits.TCS = 0;
    
    // Clear timer 3
    TMR3 = 0x0000;
    
    // Set timer 3 period match to 16000
    // This should get us a Timer3 period of 1600uS, or a Timer3 frequency of 625Hz
    PR3 = 16000;
    
    // Start timer 3
    T3CONbits.ON = 1;
    
}

// This is the ADC end of scan interrupt service routine
void __ISR(_ADC_EOS_VECTOR, IPL1SRS) ADCEndOfScanISR(void) {
    

    // Make sure end of scan is complete
    if (ADCCON2bits.EOSRDY) {

        // Convert each ADC channel to voltage from LSBs
        adc_results.vref_adc    = (double) ADCDATA43 * ADC_VOLTS_PER_LSB;
        adc_cal_gain = adc_results.vref_adc / 1.2;
        adc_results.die_temp_adc = (double) ((ADCDATA44 * ADC_VOLTS_PER_LSB * adc_cal_gain) - 0.7) / 0.005;

    }

    // Clear IRQ
    clearInterruptFlag(ADC_End_Of_Scan_Ready);
    
}

// This function prints the status of the ADC
void printADCStatus(void) {

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN, BLACK, UNDERSCORE);
    printf("Analog to Digital Converter Status:\n\r");
    
    // Print if ADC is on
    if (ADCCON1bits.ON) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC %s\n\r", ADCCON1bits.ON ? "Enabled" : "Disabled");
    
    // Print ADC resolution
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC7 Resolution: ");
    switch (ADCCON1bits.SELRES) {
     
        case 0b00:
            printf("6 bits\n\r");
            break;
            
        case 0b01:
            printf("8 bits\n\r");
            break;
            
        case 0b10:
            printf("10 bits\n\r");
            break;
                    
        case 0b11:
            printf("12 bits\n\r");
            break;
        
    }
    
    // Print if fractional of integer mode
    if (ADCCON1bits.FRACT) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Fraction Format: %s\n\r", ADCCON1bits.FRACT ? "Fractional" : "Integer");
    
    // Print trigger source
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC Scan Trigger Source: ");
    switch (ADCCON1bits.STRGSRC) {
     
        case 0b00000:
            printf("No Trigger\n\r");
            break;
            
        case 0b00001:
            printf("Global software edge trigger (GSWTRG)\n\r");
            break;
            
        case 0b00010:
            printf("Global level software trigger (GLSWTRG)\n\r");
            break;
            
        case 0b00100:
            printf("INT0 External interrupt\n\r");
            break;
            
        case 0b00101:
            printf("TMR1 match\n\r");
            break;
            
        case 0b00110:
            printf("TMR3 match\n\r");
            break;
            
        case 0b00111:
            printf("TMR5 match\n\r");
            break;
            
        case 0b01000:
            printf("OCMP1\n\r");
            break;
            
        case 0b01001:
            printf("OCMP3\n\r");
            break;
            
        case 0b01010:
            printf("OCMP5\n\r");
            break;
            
        case 0b01011:
            printf("Comparator 1 (COUT)\n\r");
            break;
            
        case 0b01100:
            printf("Comparator 2 (COUT)\n\r");
            break;
            
        default:
            printf("Undefined\n\r");
            break;
            
    }
    
    // print trigger level/edge
    if (ADCCON1bits.STRGLVL) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Scan Trigger Sensitivity: %s\n\r", ADCCON1bits.STRGLVL ? "Level" : "Edge");
    
    // print trigger suspension status
    if (ADCCON3bits.TRGSUSP) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Scan Trigger Suspension: %s\n\r", ADCCON3bits.TRGSUSP ? "suspended" : "not suspended");
    
    // Print status of bandgap reference
    if (ADCCON2bits.BGVRRDY) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    Bandgap Reference Status: %s\n\r", ADCCON2bits.BGVRRDY ? "Ready" : "Not Ready");
    
    // Print bandgap fault status
    if (ADCCON2bits.REFFLT) terminalTextAttributes(RED, BLACK, NORMAL);
    else terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Bandgap Reference is %s\n\r", ADCCON2bits.REFFLT ? "faulty" : "working properly");
    
    // Print SAMC7
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC7 Sample Time (TSAM7) = %d * TAD7\n\r", ADCCON2bits.SAMC + 2);
    
    // print ADC7 clock divider
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC7 Clock (TAD7) = %d * TQ\n\r", ADCCON2bits.ADCDIV * 2);
    
    // print ADC clock source
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC Clock Source (TCLK): ");
    switch (ADCCON3bits.ADCSEL) {
     
        case 0b00:
            printf("PBCLK3\n\r");
            break;
            
        case 0b01:
            printf("System Clock (TCY)\n\r");
            break;
            
        case 0b10:
            printf("REFCLK3\n\r");
            break;
            
        case 0b11:
            printf("FRC\n\r");
            break;
        
    }
    
    // Print control clock divider
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC Control Clock (TQ) = %d * TCLK\n\r", ADCCON3bits.CONCLKDIV * 2);
    
    // print digital enables
    if (ADCCON3bits.DIGEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC0 is %s\n\r", ADCCON3bits.DIGEN0 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC1 is %s\n\r", ADCCON3bits.DIGEN1 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC2 is %s\n\r", ADCCON3bits.DIGEN2 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC3 is %s\n\r", ADCCON3bits.DIGEN3 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN4) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC4 is %s\n\r", ADCCON3bits.DIGEN4 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN7) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC7 is %s\n\r", ADCCON3bits.DIGEN7 ? "digital enabled" : "digital disabled");
    
    // print voltage reference selection
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    Voltage reference selection: ");
    switch (ADCCON3bits.VREFSEL) {
     
        case 0b00:
            printf("AVDD and AVSS\n\r");
            break;
            
        case 0b01:
            printf("VREFH and AVSS\n\r");
            break;
            
        case 0b10:
            printf("AVDD and VREFL\n\r");
            break;
            
        case 0b11:
            printf("VREFH and VREFL\n\r");
            break;
        
    }
    
    // Print analog enable status    
    if (ADCANCONbits.ANEN0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC0 is %s\n\r", ADCANCONbits.ANEN0 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC1 is %s\n\r", ADCANCONbits.ANEN1 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC2 is %s\n\r", ADCANCONbits.ANEN2 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC3 is %s\n\r", ADCANCONbits.ANEN3 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN4) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC4 is %s\n\r", ADCANCONbits.ANEN4 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN7) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC7 is %s\n\r", ADCANCONbits.ANEN7 ? "analog enabled" : "analog disabled");
    
    // print wakeup status bits
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC warmup count exponent = %d\n\r", ADCANCONbits.WKUPCLKCNT);
    
    // print wakeup status bits
    if (ADCANCONbits.WKRDY0) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC0 is %s\n\r", ADCANCONbits.WKRDY0 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY1) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC1 is %s\n\r", ADCANCONbits.WKRDY1 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY2) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC2 is %s\n\r", ADCANCONbits.WKRDY2 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY3) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC3 is %s\n\r", ADCANCONbits.WKRDY3 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY4) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC4 is %s\n\r", ADCANCONbits.WKRDY4 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY7) terminalTextAttributes(GREEN, BLACK, NORMAL);
    else terminalTextAttributes(RED, BLACK, NORMAL);
    printf("    ADC7 is %s\n\r", ADCANCONbits.WKRDY7 ? "warmed up" : "cold");
    
    // print configuration data
    terminalTextAttributes(GREEN, BLACK, NORMAL);
    printf("    ADC0 config data: 0x%08X\n\r", ADC0CFG);
    printf("    ADC1 config data: 0x%08X\n\r", ADC1CFG);
    printf("    ADC2 config data: 0x%08X\n\r", ADC2CFG);
    printf("    ADC3 config data: 0x%08X\n\r", ADC3CFG);
    printf("    ADC4 config data: 0x%08X\n\r", ADC4CFG);
    printf("    ADC7 config data: 0x%08X\n\r", ADC7CFG);
    
    terminalTextAttributesReset();
    
}