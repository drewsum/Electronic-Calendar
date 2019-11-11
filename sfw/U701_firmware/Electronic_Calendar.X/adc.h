/* ************************************************************************** */
/** Analog to Digital Converter

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    adc.h

  @Summary
 Gives APIs for controlling ADC and measuring application channels

 */
/* ************************************************************************** */

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

#ifndef _ADC_H    /* Guard against multiple inclusion */
#define _ADC_H

#include <xc.h>

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

#include "telemetry.h"

// ADC constants macros
#define ADC_VOLTS_PER_LSB           0.000805861

// This is an ADC result scaling factor calculated using the internal reference voltage
double adc_cal_gain = 1.0;

// This function initializes the ADC modules
void ADCInitialize(void);

// This function initializes Timer3 as the ADC trigger timer
void ADCTriggerTimerInitialize(void);

// these ISRs are triggered when data for their respective ADC channel is ready
void __ISR(_ADC_DATA10_VECTOR, IPL1SRS) ADCData10ISR(void);
void __ISR(_ADC_DATA29_VECTOR, IPL1SRS) ADCData29ISR(void);
void __ISR(_ADC_DATA43_VECTOR, IPL1SRS) ADCData43ISR(void);
void __ISR(_ADC_DATA44_VECTOR, IPL1SRS) ADCData44ISR(void);
void __ISR(_ADC_DATA1_VECTOR, IPL1SRS) ADCData46ISR(void);
void __ISR(_ADC_DATA2_VECTOR, IPL1SRS) ADCData47ISR(void);
void __ISR(_ADC_DATA3_VECTOR, IPL1SRS) ADCData48ISR(void);
void __ISR(_ADC_DATA4_VECTOR, IPL1SRS) ADCData49ISR(void);

// This is the ADC end of scan interrupt service routine
void __ISR(_ADC_EOS_VECTOR, IPL3SRS) ADCEndOfScanISR(void);

// this is the ADC fault interrupt service routine
void __ISR(_ADC_FAULT_VECTOR, IPL3SRS) ADCFaultISR(void);

// This function prints the status of the ADC
void printADCStatus(void);

#endif /* _ADC_H */

/* *****************************************************************************
 End of File
 */
