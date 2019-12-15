
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
    setInterruptPriority(ADC_End_Of_Scan_Ready, 3);
    setInterruptSubpriority(ADC_End_Of_Scan_Ready, 1);
    clearInterruptFlag(ADC_End_Of_Scan_Ready);
    
    // setup ADC fault interrupt
    disableInterrupt(ADC_Fault);
    setInterruptPriority(ADC_Fault, 3);
    setInterruptSubpriority(ADC_Fault, 2);
    clearInterruptFlag(ADC_Fault);
    
    // Block ADC triggers for startup
    ADCCON3bits.TRGSUSP = 1;
    
    /* initialize ADC calibration setting */
    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    ADC7CFG = DEVADC7;
    
    // disable analog input charge pump
    ADCCON1bits.AICPMPEN = 0;
    CFGCONbits.IOANCPEN = 0;
    
    /* Configure ADCCON1 */
    ADCCON1 = 0;
    ADCCON1bits.TRBEN = 0;     // Disable Turbo Mode
    if (ADCCON1bits.TRBERR) error_handler.flags.ADC_configuration_error = 1;     // Verify turbo mode disabled
    ADCCON1bits.SIDL = 1;   // Stop ADC in idle mode

    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 0b1111; // Set for longest wakeup time to be safe
    
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0; // Select input clock source
    ADCCON3bits.CONCLKDIV = 1; // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0; // Select AVDD and AVSS as reference source
    
    /* Configure ADCCON2 */
    ADCCON2 = 0;
    /* Select ADC7 sample time and conversion clock */
    ADCCON2bits.ADCDIV = 40;
    ADCCON2bits.SAMC = 8;
    ADCCON1bits.SELRES = 3;     // 12 bit result
    
    /* Select ADC input mode */
    ADCIMCON1bits.DIFF10 = 0; // Single ended mode
    ADCIMCON1bits.SIGN10 = 0; //unsigned data format
    ADCIMCON2bits.DIFF29 = 0; // Single ended mode
    ADCIMCON2bits.SIGN29 = 0; //unsigned data format
    ADCIMCON1bits.DIFF1 = 0; // Single ended mode
    ADCIMCON1bits.SIGN1 = 0; //unsigned data format
    ADCIMCON1bits.DIFF2 = 0; // Single ended mode
    ADCIMCON1bits.SIGN2 = 0; //unsigned data format
    ADCIMCON1bits.DIFF3 = 0; // Single ended mode
    ADCIMCON1bits.SIGN3 = 0; //unsigned data format
    ADCIMCON1bits.DIFF4 = 0; // Single ended mode
    ADCIMCON1bits.SIGN4 = 0; //unsigned data format
    ADCIMCON3bits.DIFF43 = 0; // Single ended mode
    ADCIMCON3bits.SIGN43 = 0; // unsigned data format
    ADCIMCON3bits.DIFF44 = 0; // Single ended mode
    ADCIMCON3bits.SIGN44 = 0; // unsigned data format
    
    // Configure high speed ADC input channels
    ADCTRGMODEbits.SH1ALT = 0b01; // ADC1 converts channel AN46
    ADCTRGMODEbits.SH2ALT = 0b01; // ADC2 converts channel AN47
    ADCTRGMODEbits.SH3ALT = 0b01; // ADC3 converts channel AN48
    ADCTRGMODEbits.SH4ALT = 0b01; // ADC1 converts channel AN49
    
    /* Configure ADCGIRQENx */
    ADCGIRQEN1 = 0;
    ADCGIRQEN2 = 0;
    ADCGIRQEN1bits.AGIEN1 = 1;      // enable data ready 1 IRQ
    ADCGIRQEN1bits.AGIEN2 = 1;      // enable data ready 2 IRQ
    ADCGIRQEN1bits.AGIEN3 = 1;      // enable data ready 3 IRQ
    ADCGIRQEN1bits.AGIEN4 = 1;      // enable data ready 4 IRQ
    ADCGIRQEN1bits.AGIEN10 = 1;     // enable data ready 10 IRQ
    ADCGIRQEN1bits.AGIEN29 = 1;     // enable data ready 29 IRQ
    ADCGIRQEN2bits.AGIEN43 = 1;     // enable data ready 43 IRQ
    ADCGIRQEN2bits.AGIEN44 = 1;     // enable data ready 44 IRQ
    ADCCON2bits.EOSIEN = 1;         // Enable interrupt on end of scan
    
    // set IRQ priorities
    setInterruptPriority(ADC_Data_1, 1);
    setInterruptPriority(ADC_Data_2, 1);
    setInterruptPriority(ADC_Data_3, 1);
    setInterruptPriority(ADC_Data_4, 1);
    setInterruptPriority(ADC_Data_10, 1);
    setInterruptPriority(ADC_Data_29, 1);
    setInterruptPriority(ADC_Data_43, 1);
    setInterruptPriority(ADC_Data_44, 1);
    
    // set IRQ subpriorities
    setInterruptSubpriority(ADC_Data_1, 0);
    setInterruptSubpriority(ADC_Data_2, 1);
    setInterruptSubpriority(ADC_Data_3, 2);
    setInterruptSubpriority(ADC_Data_4, 3);
    setInterruptSubpriority(ADC_Data_10, 0);
    setInterruptSubpriority(ADC_Data_29, 1);
    setInterruptSubpriority(ADC_Data_43, 2);
    setInterruptSubpriority(ADC_Data_44, 3);
    
    /* Configure ADCCSSx */
    ADCCSS1 = 0;
    ADCCSS2 = 0;
    ADCCSS1bits.CSS1 = 1;           // Enable channel 46 for common scan
    ADCCSS1bits.CSS2 = 1;           // Enable channel 47 for common scan
    ADCCSS1bits.CSS3 = 1;           // Enable channel 48 for common scan
    ADCCSS1bits.CSS4 = 1;           // Enable channel 49 for common scan
    ADCCSS1bits.CSS10 = 1;          // Enable channel 10 for common scan
    ADCCSS1bits.CSS29 = 1;          // Enable channel 29 for common scan
    ADCCSS2bits.CSS43 = 1;          // Enable Channel 43 for common scan
    ADCCSS2bits.CSS44 = 1;          // Enable Channel 44 for common scan
    
    // Configure ADC1 timing
    ADC1TIMEbits.ADCEIS = 0b000;    // data ready IRQ is fired 1 adc clock before end of conversion
    ADC1TIMEbits.SELRES = 0b11;     // 12 bit result
    ADC1TIMEbits.ADCDIV = 10;        // input clock divider is / 2 
    ADC1TIMEbits.SAMC = 5;          // conversion takes 5 clk cycles
    
    // Configure ADC2 timing
    ADC2TIMEbits.ADCEIS = 0b000;    // data ready IRQ is fired 1 adc clock before end of conversion
    ADC2TIMEbits.SELRES = 0b11;     // 12 bit result
    ADC2TIMEbits.ADCDIV = 10;        // input clock divider is / 5
    ADC2TIMEbits.SAMC = 5;          // conversion takes 5 clk cycles
    
    // Configure ADC3 timing
    ADC3TIMEbits.ADCEIS = 0b000;    // data ready IRQ is fired 1 adc clock before end of conversion
    ADC3TIMEbits.SELRES = 0b11;     // 12 bit result
    ADC3TIMEbits.ADCDIV = 10;        // input clock divider is / 5
    ADC3TIMEbits.SAMC = 5;          // conversion takes 5 clk cycles
    
    // Configure ADC4 timing
    ADC4TIMEbits.ADCEIS = 0b000;    // data ready IRQ is fired 1 adc clock before end of conversion
    ADC4TIMEbits.SELRES = 0b11;     // 12 bit result
    ADC4TIMEbits.ADCDIV = 10;        // input clock divider is / 5
    ADC4TIMEbits.SAMC = 5;          // conversion takes 5 clk cycles
    
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
    ADCCON1bits.STRGSRC = 0b00101;      // Trigger source is Timer1
    ADCTRGSNSbits.LVL1 = 0;             // trigger on edge
    ADCTRGSNSbits.LVL2 = 0;             // trigger on edge
    ADCTRGSNSbits.LVL3 = 0;             // trigger on edge
    ADCTRGSNSbits.LVL4 = 0;             // trigger on edge
    ADCTRG1bits.TRGSRC1 = 0b00011;      // ADC1 triggers on scan trigger
    ADCTRG1bits.TRGSRC2 = 0b00011;      // ADC2 triggers on scan trigger
    ADCTRG1bits.TRGSRC3 = 0b00011;      // ADC3 triggers on scan trigger
    ADCTRG2bits.TRGSRC4 = 0b00011;      // ADC4 triggers on scan trigger
    
    /* Early interrupt */
    ADCEIEN1 = 0; // No early interrupts used
    ADCEIEN2 = 0;
    
    /* Turn the ADC on */
    ADCCON1bits.ON = 1;
    
    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY); // Wait until the reference voltage is ready
    
    if (ADCCON2bits.REFFLT) error_handler.flags.ADC_configuration_error = 1;     // Record error if reference fails
    
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN1 = 1; // Enable the clock to analog bias
    ADCANCONbits.ANEN2 = 1; // Enable the clock to analog bias
    ADCANCONbits.ANEN3 = 1; // Enable the clock to analog bias
    ADCANCONbits.ANEN4 = 1; // Enable the clock to analog bias
    ADCANCONbits.ANEN7 = 1; // Enable the clock to analog bias
    
    while (ADCANCONbits.WKRDY1);    // wait for ADC1 AN to be ready
    while (ADCANCONbits.WKRDY2);    // wait for ADC2 AN to be ready
    while (ADCANCONbits.WKRDY3);    // wait for ADC3 AN to be ready
    while (ADCANCONbits.WKRDY4);    // wait for ADC4 AN to be ready
    while (ADCANCONbits.WKRDY7);    // wait for ADC7 AN to be ready
    
    
    /* Enable the ADC module */
    ADCCON3bits.DIGEN1 = 1; // Enable ADC7 digital circuits
    ADCCON3bits.DIGEN2 = 1; // Enable ADC7 digital circuits
    ADCCON3bits.DIGEN3 = 1; // Enable ADC7 digital circuits
    ADCCON3bits.DIGEN4 = 1; // Enable ADC7 digital circuits
    ADCCON3bits.DIGEN7 = 1; // Enable ADC7 digital circuits
    
    // Unblock triggers
    ADCCON3bits.TRGSUSP = 0;
    
    // enable data ready interrupts
    enableInterrupt(ADC_Data_1);
    enableInterrupt(ADC_Data_2);
    enableInterrupt(ADC_Data_3);
    enableInterrupt(ADC_Data_4);
    enableInterrupt(ADC_Data_10);
    enableInterrupt(ADC_Data_29);
    enableInterrupt(ADC_Data_43);
    enableInterrupt(ADC_Data_44);
    
    // Enable ADC end of scan interrupt
    enableInterrupt(ADC_End_Of_Scan_Ready);
    
    // enable ADC fault interrupt
    ADCCON2bits.REFFLTIEN = 1;
    enableInterrupt(ADC_Fault);
    
}

// these ISRs are triggered when data for their respective ADC channel is ready
void __ISR(_ADC_DATA10_VECTOR, IPL1SRS) ADCData10ISR(void) {
 
    // check to see if data is actually ready
    if (ADCDSTAT1bits.ARDY10) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.vbat_voltage = (double) (ADCDATA10 * ADC_VOLTS_PER_LSB * adc_cal_gain * VBAT_CHANNEL_GAIN);
        VBAT_ADC_ENABLE_PIN = 0;
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_10);
    
}

void __ISR(_ADC_DATA29_VECTOR, IPL1SRS) ADCData29ISR(void) {

    // check to see if data is actually ready
    if (ADCDSTAT1bits.ARDY29) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.pos3p3_current = (double) (ADCDATA29 * ADC_VOLTS_PER_LSB * adc_cal_gain * POS3P3_ISNS_CHANNEL_GAIN);
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_29);
    
}


void __ISR(_ADC_DATA43_VECTOR, IPL1SRS) ADCData43ISR(void) {

    // check to see if data is actually ready
    if (ADCDSTAT2bits.ARDY43) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.mcu_vref_voltage = (double) ADCDATA43 * ADC_VOLTS_PER_LSB;
        // compensate for errors in the ADC, we know VREF is supposed to be 1.2V
        adc_cal_gain = (1.2 / telemetry.current.params.mcu_vref_voltage);
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_43);
    
}

void __ISR(_ADC_DATA44_VECTOR, IPL1SRS) ADCData44ISR(void) {
    
    // check to see if data is actually ready
    if (ADCDSTAT2bits.ARDY44) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.mcu_die_temp = (double) ((ADCDATA44 * ADC_VOLTS_PER_LSB * adc_cal_gain) - 0.7) / 0.005 + ADC_TEMP_SENS_OFFSET;
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_44);
    
}

void __ISR(_ADC_DATA1_VECTOR, IPL1SRS) ADCData46ISR(void) {
    
    // check to see if data is actually ready
    if (ADCDSTAT1bits.ARDY1) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.pos5_usb_voltage = (double) (ADCDATA1 * ADC_VOLTS_PER_LSB * adc_cal_gain * POS5_USB_CHANNEL_GAIN);
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_1);
    
}

void __ISR(_ADC_DATA2_VECTOR, IPL1SRS) ADCData47ISR(void) {
    
    // check to see if data is actually ready
    if (ADCDSTAT1bits.ARDY2) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.pos12_voltage = (double) (ADCDATA2 * ADC_VOLTS_PER_LSB * adc_cal_gain * POS12_CHANNEL_GAIN);
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_2);
    
}

void __ISR(_ADC_DATA3_VECTOR, IPL1SRS) ADCData48ISR(void) {
    
    // check to see if data is actually ready
    if (ADCDSTAT1bits.ARDY3) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.pos3p3_voltage = (double) (ADCDATA3 * ADC_VOLTS_PER_LSB * adc_cal_gain * POS3P3_CHANNEL_GAIN);
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_3);

    // enable VBAT ADC voltage divider
    VBAT_ADC_ENABLE_PIN = 1;

}

void __ISR(_ADC_DATA4_VECTOR, IPL1SRS) ADCData49ISR(void) {
    
    // check to see if data is actually ready
    if (ADCDSTAT1bits.ARDY4) {
     
        // copy ADC conversion result into telemetry
        telemetry.current.params.pos12_current = (double) (ADCDATA4 * ADC_VOLTS_PER_LSB * adc_cal_gain * POS12_ISNS_CHANNEL_GAIN);
        
    }
    
    // clear IRQ
    clearInterruptFlag(ADC_Data_4);
    
}


// This is the ADC end of scan interrupt service routine
void __ISR(_ADC_EOS_VECTOR, IPL3SRS) ADCEndOfScanISR(void) {
    

    // Make sure end of scan is complete
    if (ADCCON2bits.EOSRDY) {
        
        // track min and max values on next loop through main();
        telemetry_update_flag_adc = 1;
        
    }

    // Clear IRQ
    clearInterruptFlag(ADC_End_Of_Scan_Ready);
    
}

// this is the ADC fault interrupt service routine
void __ISR(_ADC_FAULT_VECTOR, IPL3SRS) ADCFaultISR(void) {
 
    // record error
    if (ADCCON2bits.REFFLT) error_handler.flags.ADC_reference_fault = 1;
    
    clearInterruptFlag(ADC_Fault);
    
}

// This function prints the status of the ADC
void printADCStatus(void) {

    terminalTextAttributesReset();
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Analog to Digital Converter Status:\n\r");
    
    // Print if ADC is on
    if (ADCCON1bits.ON) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC %s\n\r", ADCCON1bits.ON ? "Enabled" : "Disabled");
    
    // Print ADC resolution
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
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
    if (ADCCON1bits.FRACT) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Fraction Format: %s\n\r", ADCCON1bits.FRACT ? "Fractional" : "Integer");
    
    // Print trigger source
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
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
    if (ADCCON1bits.STRGLVL) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Scan Trigger Sensitivity: %s\n\r", ADCCON1bits.STRGLVL ? "Level" : "Edge");
    
    // print trigger suspension status
    if (ADCCON3bits.TRGSUSP) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Scan Trigger Suspension: %s\n\r", ADCCON3bits.TRGSUSP ? "suspended" : "not suspended");
    
    // Print status of bandgap reference
    if (ADCCON2bits.BGVRRDY) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Bandgap Reference Status: %s\n\r", ADCCON2bits.BGVRRDY ? "Ready" : "Not Ready");
    
    // Print bandgap fault status
    if (ADCCON2bits.REFFLT) terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Bandgap Reference is %s\n\r", ADCCON2bits.REFFLT ? "faulty" : "working properly");
    
    // Print SAMC7
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC7 Sample Time (TSAM7) = %d * TAD7\n\r", ADCCON2bits.SAMC + 2);
    
    // print ADC7 clock divider
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC7 Clock (TAD7) = %d * TQ\n\r", ADCCON2bits.ADCDIV * 2);
    
    // print ADC clock source
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
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
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC Control Clock (TQ) = %d * TCLK\n\r", ADCCON3bits.CONCLKDIV * 2);
    
    // print digital enables
    if (ADCCON3bits.DIGEN0) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC0 is %s\n\r", ADCCON3bits.DIGEN0 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN1) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC1 is %s\n\r", ADCCON3bits.DIGEN1 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN2) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC2 is %s\n\r", ADCCON3bits.DIGEN2 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN3) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC3 is %s\n\r", ADCCON3bits.DIGEN3 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN4) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC4 is %s\n\r", ADCCON3bits.DIGEN4 ? "digital enabled" : "digital disabled");
    if (ADCCON3bits.DIGEN7) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC7 is %s\n\r", ADCCON3bits.DIGEN7 ? "digital enabled" : "digital disabled");
    
    // print voltage reference selection
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
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
    if (ADCANCONbits.ANEN0) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC0 is %s\n\r", ADCANCONbits.ANEN0 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN1) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC1 is %s\n\r", ADCANCONbits.ANEN1 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN2) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC2 is %s\n\r", ADCANCONbits.ANEN2 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN3) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC3 is %s\n\r", ADCANCONbits.ANEN3 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN4) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC4 is %s\n\r", ADCANCONbits.ANEN4 ? "analog enabled" : "analog disabled");
    if (ADCANCONbits.ANEN7) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC7 is %s\n\r", ADCANCONbits.ANEN7 ? "analog enabled" : "analog disabled");
    
    // print wakeup status bits
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC warmup count exponent = %d\n\r", ADCANCONbits.WKUPCLKCNT);
    
    // print wakeup status bits
    if (ADCANCONbits.WKRDY0) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC0 is %s\n\r", ADCANCONbits.WKRDY0 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY1) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC1 is %s\n\r", ADCANCONbits.WKRDY1 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY2) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC2 is %s\n\r", ADCANCONbits.WKRDY2 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY3) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC3 is %s\n\r", ADCANCONbits.WKRDY3 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY4) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC4 is %s\n\r", ADCANCONbits.WKRDY4 ? "warmed up" : "cold");
    if (ADCANCONbits.WKRDY7) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC7 is %s\n\r", ADCANCONbits.WKRDY7 ? "warmed up" : "cold");
    
    // print configuration data
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    ADC0 config data: 0x%08X\n\r", ADC0CFG);
    printf("    ADC1 config data: 0x%08X\n\r", ADC1CFG);
    printf("    ADC2 config data: 0x%08X\n\r", ADC2CFG);
    printf("    ADC3 config data: 0x%08X\n\r", ADC3CFG);
    printf("    ADC4 config data: 0x%08X\n\r", ADC4CFG);
    printf("    ADC7 config data: 0x%08X\n\r", ADC7CFG);
    
    terminalTextAttributesReset();
    
}