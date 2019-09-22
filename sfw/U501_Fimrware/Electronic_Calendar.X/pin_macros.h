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

#ifndef _PIN_MACROS_H    /* Guard against multiple inclusion */
#define _PIN_MACROS_H

#include <xc.h>

// These pin macros allow for easier manipulation of GPIO with matching
// signal names from the hardware schematic

// Port A
#define Date_B0_Pin                 LATAbits.LATA0
#define nThur_LED_Pin               LATAbits.LATA2
#define nFri_LED_Pin                LATAbits.LATA3
#define nSat_LED_Pin                LATAbits.LATA4
#define nMinutes3_LED               LATAbits.LATA5
#define nSeconds2_LED_Pin           LATAbits.LATA6
#define nSeconds4_LED_Pin           LATAbits.LATA7
#define RESET_LED_Pin               LATAbits.LATA9
#define Date_Deconde_Enable_Pin     LATAbits.LATA10

// Port B
#define nHours5_LED_Pin             LATBbits.LATB2
#define nHours3_LED_Pin             LATBbits.LATB3
#define nHours1_LED_Pin             LATBbits.LATB4
#define Year_B0_Pin                 LATBbits.LATB5
#define Analog_Error_LED_Pin        LATBbits.LATB10
#define Status_LED_Enable_Pin       LATBbits.LATB11
#define nDate_Decode_1_Pin          LATBbits.LATB12
#define nDate_Decode_2_Pin          LATBbits.LATB13
#define nDate_Decode_3_Pin          LATBbits.LATB14

// Port C
#define nHours0_LED_Pin             LATCbits.LATC1
#define nHours2_LED_Pin             LATCbits.LATC2
#define nHours4_LED_Pin             LATCbits.LATC3
#define nHours6_LED_Pin             LATCbits.LATC4
#define Heartbeat_LED_Pin           LATCbits.LATC12
#define POS3P3_PGOOD_Pin            PORTCbits.RC13
#define POS5_USB_PGOOD_Pin          PORTCbits.RC14
#define nSun_LED_Pin                LATCbits.LATC15

// Port D
#define nJan_LED_Pin                LATDbits.LATD0
#define nFeb_LED_Pin                LATDbits.LATD1
#define nMar_LED_Pin                LATDbits.LATD2
#define nApr_LED_Pin                LATDbits.LATD3
#define nOct_LED_Pin                LATDbits.LATD4
#define nNov_LED_Pin                LATDbits.LATD5
#define nJul_LED_Pin                LATDbits.LATD9
#define nAug_LED_Pin                LATDbits.LATD10
#define nSep_LED_Pin                LATDbits.LATD11
#define nMay_LED_Pin                LATDbits.LATD12
#define nJun_LED_Pin                LATDbits.LATD13

// Port E
#define nSeconds6_LED_Pin           LATEbits.LATE0
#define nSeconds1_LED_Pin           LATEbits.LATE1
#define nMinutes2_LED_Pin           LATEbits.LATE2
#define nMinutes4_LED_Pin           LATEbits.LATE3
#define nMinutes6_LED_Pin           LATEbits.LATE4
#define nMinutes5_LED_Pin           LATEbits.LATE5
#define nDate_Decode_4_Pin          LATEbits.LATE6
#define Date_B2_Pin                 LATEbits.LATE7
#define Year_B1_Pin                 LATEbits.LATE8
#define Year_B2_Pin                 LATEbits.LATE6

// Port F
#define nDec_LED_Pin                LATFbits.LATF0
#define nSeconds0_LED_Pin           LATFbits.LATF1
#define nTue_LED_Pin                LATFbits.LATF2
#define nMon_LED_Pin                LATFbits.LATF3
#define Exception_LED_Pin           LATFbits.LATF4
#define nVBAT_Isolate_Pin           LATFbits.LATF5
#define nWed_LED_Pin                LATFbits.LATF8
#define VBAT_ADC_Enable_Pin         LATFbits.LATF12
#define nDiode_Fault_Pin            PORTFbits.RF13

// Port G
#define USB_Error_LED_Pin           LATGbits.LATG0
#define Other_Error_LED_Pin         LATGbits.LATG1
#define Cap_Touch_Power_Pin         PORTGbits.RG6
#define POS12_PGOOD_Pin             PORTGbits.RG7
#define Date_B1_Pin                 LATGbits.LATG9
#define nSeconds5_LED_Pin           LATGbits.LATG12
#define nMinutes0_LED_Pin           LATGbits.LATG13
#define nSeconds3_LED_Pin           LATGbits.LATG14
#define nMinutes1_LED_Pin           LATGbits.LATG15

#endif /* _PIN_MACROS_H */

/* *****************************************************************************
 End of File
 */
