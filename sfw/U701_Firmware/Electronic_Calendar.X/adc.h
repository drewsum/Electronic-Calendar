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

// ADC constants macros
#define ADC_VOLTS_PER_LSB           0.000805861

// These constants compensate for input voltage dividers/value scaling
#define POS3P3_CHANNEL_GAIN         2.0
#define POS12_CHANNEL_GAIN          9.3333333333333333333333
#define POS5_USB_CHANNEL_GAIN       2.0
#define POS12_ISNS_CHANNEL_GAIN     1.002004008
#define POS3P3_ISNS_CHANNEL_GAIN    2.50501002004
#define ADC_TEMP_SENS_OFFSET        -100.0

// This structure holds ADC measurement results
struct adc_results_t {
    
    double POS3P3_adc;
    double POS12_adc;
    double vref_adc;
    double die_temp_adc;
    double POS5_USB_adc;
    double POS3P3_isns_adc;
    double POS12_isns_adc;
    
} adc_results;

// This is an ADC result scaling factor calculated using the internal reference voltage
double adc_cal_gain;

// This function initializes the ADC modules
void ADCInitialize(void);

// This function initializes Timer3 as the ADC trigger timer
void ADCTriggerTimerInitialize(void);

// This is the ADC end of scan interrupt service routine
void __ISR(_ADC_EOS_VECTOR, IPL1SRS) ADCEndOfScanISR(void);

// This function prints the status of the ADC
void printADCStatus(void);

#endif /* _ADC_H */

/* *****************************************************************************
 End of File
 */
