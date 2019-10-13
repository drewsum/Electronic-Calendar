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

#define HIGH    1
#define LOW     0

// These pin macros allow for easier manipulation of GPIO with matching
// signal names from the hardware schematic

// Port A
#define DATE_B0_PIN                 LATAbits.LATA0
#define nTHUR_LED_PIN               LATAbits.LATA2
#define nFRI_LED_PIN                LATAbits.LATA3
#define nSAT_LED_PIN                LATAbits.LATA4
#define nMINUTES3_LED_PIN           LATAbits.LATA5
#define nSECONDS2_LED_PIN           LATAbits.LATA6
#define nSECONDS4_LED_PIN           LATAbits.LATA7
#define RESET_LED_PIN               LATAbits.LATA9
#define DATE_DECODE_ENABLE_PIN      LATAbits.LATA10

// Port B
#define nHOURS5_LED_PIN             LATBbits.LATB2
#define nHOURS3_LED_PIN             LATBbits.LATB3
#define nHOURS1_LED_PIN             LATBbits.LATB4
#define YEAR_B0_PIN                 LATBbits.LATB5
#define ANALOG_ERROR_LED_PIN        LATBbits.LATB10
#define STATUS_LED_ENABLE_PIN       LATBbits.LATB11
#define nDATE_DECODE_1_PIN          LATBbits.LATB12
#define nDATE_DECODE_2_PIN          LATBbits.LATB13
#define nDATE_DECODE_3_PIN          LATBbits.LATB14

// Port C
#define nHOURS0_LED_PIN             LATCbits.LATC1
#define nHOURS2_LED_PIN             LATCbits.LATC2
#define nHOURS4_LED_PIN             LATCbits.LATC3
#define nHOURS6_LED_PIN             LATCbits.LATC4
#define HEARTBEAT_LED_PIN           LATCbits.LATC12
#define POS3P3_PGOOD_PIN            PORTCbits.RC13
#define POS5_USB_PGOOD_PIN          PORTCbits.RC14
#define nSUN_LED_PIN                LATCbits.LATC15

// Port D
#define nJAN_LED_PIN                LATDbits.LATD0
#define nFEB_LED_PIN                LATDbits.LATD1
#define nMAR_LED_PIN                LATDbits.LATD2
#define nAPR_LED_PIN                LATDbits.LATD3
#define nOCT_LED_PIN                LATDbits.LATD4
#define nNOV_LED_PIN                LATDbits.LATD5
#define nJUL_LED_PIN                LATDbits.LATD9
#define nAUG_LED_PIN                LATDbits.LATD10
#define nSEP_LED_PIN                LATDbits.LATD11
#define nMAY_LED_PIN                LATDbits.LATD12
#define nJUN_LED_PIN                LATDbits.LATD13

// Port E
#define nSECONDS6_LED_PIN           LATEbits.LATE0
#define nSECONDS1_LED_PIN           LATEbits.LATE1
#define nMINUTES2_LED_PIN           LATEbits.LATE2
#define nMINUTES4_LED_PIN           LATEbits.LATE3
#define nMINUTES6_LED_PIN           LATEbits.LATE4
#define nMINUTES5_LED_PIN           LATEbits.LATE5
#define nDATE_DECODE_4_PIN          LATEbits.LATE6
#define DATE_B2_PIN                 LATEbits.LATE7
#define YEAR_B1_PIN                 LATEbits.LATE8
#define YEAR_B2_PIN                 LATEbits.LATE6

// Port F
#define nDEC_LED_PIN                LATFbits.LATF0
#define nSECONDS0_LED_PIN           LATFbits.LATF1
#define nTUE_LED_PIN                LATFbits.LATF2
#define nMON_LED_PIN                LATFbits.LATF3
#define EXCEPTION_LED_PIN           LATFbits.LATF4
#define nVBAT_ISOLATE_PIN           LATFbits.LATF5
#define nWED_LED_PIN                LATFbits.LATF8
#define VBAT_ADC_ENABLE_PIN         LATFbits.LATF12
#define nDIODE_FAULT_PIN            PORTFbits.RF13

// Port G
#define USB_ERROR_LED_PIN           LATGbits.LATG0
#define OTHER_ERROR_LED_PIN         LATGbits.LATG1
#define CAP_TOUCH_POWER_PIN         PORTGbits.RG6
#define POS12_PGOOD_PIN             PORTGbits.RG7
#define DATE_B1_PIN                 LATGbits.LATG9
#define nSECONDS5_LED_PIN           LATGbits.LATG12
#define nMINUTES0_LED_PIN           LATGbits.LATG13
#define nSECONDS3_LED_PIN           LATGbits.LATG14
#define nMINUTES1_LED_PIN           LATGbits.LATG15

#endif /* _PIN_MACROS_H */

/* *****************************************************************************
 End of File
 */
