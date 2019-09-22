
#include <xc.h>

#include "gpio_setup.h"

// initializes GPIO ports on microcontroller
void gpioInitialize (void){
    
    // Unlock peripheral pin select
    PPSUnlock();
    
    portAGPIOInitialize();
    portBGPIOInitialize();
    portCGPIOInitialize();
    portDGPIOInitialize();
    portEGPIOInitialize();
    portFGPIOInitialize();
    portGGPIOInitialize();
    
    // Lock PPS
    PPSLock();
    
}

// initializes port A GPIO pins
void portAGPIOInitialize (void) {

    // Setup RA0
    TRISAbits.TRISA0    = TRIS_OUTPUT;
    LATAbits.LATA0      = LAT_LOW;
    ODCAbits.ODCA0      = ODC_DISABLE;
    ANSELAbits.ANSA0    = ANALOG_DISABLE;
    
    // Setup RA1
    TRISAbits.TRISA1    = TRIS_INPUT;
    LATAbits.LATA1      = LAT_LOW;
    ODCAbits.ODCA1      = ODC_DISABLE;
    ANSELAbits.ANSA1    = ANALOG_ENABLE;
    
    // Setup RA2
    TRISAbits.TRISA2    = TRIS_OUTPUT;
    LATAbits.LATA2      = LAT_HIGH;
    ODCAbits.ODCA2      = ODC_ENABLE;
    
    // Setup RA3
    TRISAbits.TRISA3    = TRIS_OUTPUT;
    LATAbits.LATA3      = LAT_HIGH;
    ODCAbits.ODCA3      = ODC_ENABLE;

    // Setup RA4
    TRISAbits.TRISA4    = TRIS_OUTPUT;
    LATAbits.LATA4      = LAT_HIGH;
    ODCAbits.ODCA4      = ODC_ENABLE;

    // Setup RA5
    TRISAbits.TRISA5    = TRIS_OUTPUT;
    LATAbits.LATA5      = LAT_HIGH;
    ODCAbits.ODCA5      = ODC_ENABLE;
    ANSELAbits.ANSA5    = ANALOG_DISABLE;
    
    // Setup RA6
    TRISAbits.TRISA6    = TRIS_OUTPUT;
    LATAbits.LATA6      = LAT_HIGH;
    ODCAbits.ODCA6      = ODC_ENABLE;
    
    // Setup RA7
    TRISAbits.TRISA7    = TRIS_OUTPUT;
    LATAbits.LATA7      = LAT_HIGH;
    ODCAbits.ODCA7      = ODC_ENABLE;
    
    // Setup RA9
    TRISAbits.TRISA9    = TRIS_OUTPUT;
    LATAbits.LATA9      = LAT_LOW;
    ODCAbits.ODCA9      = ODC_DISABLE;
    ANSELAbits.ANSA9    = ANALOG_DISABLE;
    
    // Setup RA10
    TRISAbits.TRISA10   = TRIS_OUTPUT;
    LATAbits.LATA10     = LAT_LOW;
    ODCAbits.ODCA10     = ODC_DISABLE;
    ANSELAbits.ANSA10   = ANALOG_DISABLE;
    
    // Setup RA14
    TRISAbits.TRISA14   = TRIS_INPUT;
    LATAbits.LATA14     = LAT_LOW;
    ODCAbits.ODCA14     = ODC_DISABLE;
    
    // Setup RA15
    TRISAbits.TRISA15   = TRIS_INPUT;
    LATAbits.LATA15     = LAT_LOW;
    ODCAbits.ODCA15     = ODC_DISABLE;
    
}

// initializes port B GPIO pins
void portBGPIOInitialize (void) {
    
    // Setup RB0
    TRISBbits.TRISB0    = TRIS_OUTPUT;
    LATBbits.LATB0      = LAT_LOW;
    ODCBbits.ODCB0      = ODC_DISABLE;
    ANSELBbits.ANSB0    = ANALOG_DISABLE;
    
    // Setup RB1
    TRISBbits.TRISB1    = TRIS_OUTPUT;
    LATBbits.LATB1      = LAT_LOW;
    ODCBbits.ODCB1      = ODC_DISABLE;
    ANSELBbits.ANSB1    = ANALOG_DISABLE;
    
    // Setup RB2
    TRISBbits.TRISB2    = TRIS_OUTPUT;
    LATBbits.LATB2      = LAT_HIGH;
    ODCBbits.ODCB2      = ODC_ENABLE;
    ANSELBbits.ANSB2    = ANALOG_DISABLE;
    
    // Setup RB3
    TRISBbits.TRISB3    = TRIS_OUTPUT;
    LATBbits.LATB3      = LAT_HIGH;
    ODCBbits.ODCB3      = ODC_ENABLE;
    ANSELBbits.ANSB3    = ANALOG_DISABLE;
    
    // Setup RB4
    TRISBbits.TRISB4    = TRIS_OUTPUT;
    LATBbits.LATB4      = LAT_HIGH;
    ODCBbits.ODCB4      = ODC_ENABLE;
    ANSELBbits.ANSB4    = ANALOG_DISABLE;
    
    // Setup RB5
    TRISBbits.TRISB5    = TRIS_OUTPUT;
    LATBbits.LATB5      = LAT_LOW;
    ODCBbits.ODCB5      = ODC_DISABLE;
    ANSELBbits.ANSB5    = ANALOG_DISABLE;
    
    // Setup RB6
    TRISBbits.TRISB6    = TRIS_INPUT;
    LATBbits.LATB6      = LAT_LOW;
    ODCBbits.ODCB6      = ODC_DISABLE;
    ANSELBbits.ANSB6    = ANALOG_ENABLE;
    
    // Setup RB7
    TRISBbits.TRISB7    = TRIS_INPUT;
    LATBbits.LATB7      = LAT_LOW;
    ODCBbits.ODCB7      = ODC_DISABLE;
    ANSELBbits.ANSB7    = ANALOG_ENABLE;
    
    // Setup RB8
    TRISBbits.TRISB8    = TRIS_INPUT;
    LATBbits.LATB8      = LAT_LOW;
    ODCBbits.ODCB8      = ODC_DISABLE;
    ANSELBbits.ANSB8    = ANALOG_ENABLE;
    
    // Setup RB9
    TRISBbits.TRISB9    = TRIS_INPUT;
    LATBbits.LATB9      = LAT_LOW;
    ODCBbits.ODCB9      = ODC_DISABLE;
    ANSELBbits.ANSB9    = ANALOG_ENABLE;
    
    // Setup RB10
    TRISBbits.TRISB10   = TRIS_OUTPUT;
    LATBbits.LATB10     = LAT_LOW;
    ODCBbits.ODCB10     = ODC_DISABLE;
    ANSELBbits.ANSB10   = ANALOG_DISABLE;
    
    // Setup RB11
    TRISBbits.TRISB11   = TRIS_OUTPUT;
    LATBbits.LATB11     = LAT_LOW;
    ODCBbits.ODCB11     = ODC_DISABLE;
    ANSELBbits.ANSB11   = ANALOG_DISABLE;
    
    // Setup RB12
    TRISBbits.TRISB12   = TRIS_OUTPUT;
    LATBbits.LATB12     = LAT_HIGH;
    ODCBbits.ODCB12     = ODC_ENABLE;
    ANSELBbits.ANSB12   = ANALOG_DISABLE;
    
    // Setup RB13
    TRISBbits.TRISB13   = TRIS_OUTPUT;
    LATBbits.LATB13     = LAT_HIGH;
    ODCBbits.ODCB13     = ODC_ENABLE;
    ANSELBbits.ANSB13   = ANALOG_DISABLE;
    
    // Setup RB14
    TRISBbits.TRISB14   = TRIS_OUTPUT;
    LATBbits.LATB14     = LAT_HIGH;
    ODCBbits.ODCB14     = ODC_ENABLE;
    ANSELBbits.ANSB14   = ANALOG_DISABLE;
    
    // Setup RB15
    TRISBbits.TRISB15   = TRIS_INPUT;
    LATBbits.LATB15     = LAT_LOW;
    ODCBbits.ODCB15     = ODC_DISABLE;
    ANSELBbits.ANSB15   = ANALOG_ENABLE;

}

// initializes port C GPIO pins
void portCGPIOInitialize (void) {
    
    // Setup RC1
    TRISCbits.TRISC1    = TRIS_OUTPUT;
    LATCbits.LATC1      = LAT_HIGH;
    ODCCbits.ODCC1      = ODC_ENABLE;
    ANSELCbits.ANSC1    = ANALOG_DISABLE;
    
    // Setup RC2
    TRISCbits.TRISC2    = TRIS_OUTPUT;
    LATCbits.LATC2      = LAT_HIGH;
    ODCCbits.ODCC2      = ODC_ENABLE;
    ANSELCbits.ANSC2    = ANALOG_DISABLE;
    
    // Setup RC3
    TRISCbits.TRISC3    = TRIS_OUTPUT;
    LATCbits.LATC3      = LAT_HIGH;
    ODCCbits.ODCC3      = ODC_ENABLE;
    ANSELCbits.ANSC3    = ANALOG_DISABLE;
    
    // Setup RC4
    TRISCbits.TRISC4    = TRIS_OUTPUT;
    LATCbits.LATC4      = LAT_HIGH;
    ODCCbits.ODCC4      = ODC_ENABLE;
    ANSELCbits.ANSC4    = ANALOG_DISABLE;
    
    // Setup RC12
    TRISCbits.TRISC12   = TRIS_OUTPUT;
    LATCbits.LATC12     = LAT_LOW;
    ODCCbits.ODCC12     = ODC_DISABLE;
    
    // Setup RC13
    TRISCbits.TRISC13   = TRIS_INPUT;
    LATCbits.LATC13     = LAT_LOW;
    ODCCbits.ODCC13     = ODC_DISABLE;
    
    // Setup RC14
    TRISCbits.TRISC14   = TRIS_INPUT;
    LATCbits.LATC14     = LAT_LOW;
    ODCCbits.ODCC14     = ODC_DISABLE;
    
    // Setup RC15
    TRISCbits.TRISC15   = TRIS_OUTPUT;
    LATCbits.LATC15     = LAT_HIGH;
    ODCCbits.ODCC15     = ODC_ENABLE;
    
}

// initializes port D GPIO pins
void portDGPIOInitialize (void) {
    
    // Setup RD0
    TRISDbits.TRISD0    = TRIS_OUTPUT;
    LATDbits.LATD0      = LAT_HIGH;
    ODCDbits.ODCD0      = ODC_ENABLE;
    
    // Setup RD1
    TRISDbits.TRISD1    = TRIS_OUTPUT;
    LATDbits.LATD1      = LAT_HIGH;
    ODCDbits.ODCD1      = ODC_ENABLE;
    
    // Setup RD2
    TRISDbits.TRISD2    = TRIS_OUTPUT;
    LATDbits.LATD2      = LAT_HIGH;
    ODCDbits.ODCD2      = ODC_ENABLE;
    
    // Setup RD3
    TRISDbits.TRISD3    = TRIS_OUTPUT;
    LATDbits.LATD3      = LAT_HIGH;
    ODCDbits.ODCD3      = ODC_ENABLE;
    
    // Setup RD4
    TRISDbits.TRISD4    = TRIS_OUTPUT;
    LATDbits.LATD4      = LAT_HIGH;
    ODCDbits.ODCD4      = ODC_ENABLE;
    
    // Setup RD5
    TRISDbits.TRISD5    = TRIS_OUTPUT;
    LATDbits.LATD5      = LAT_HIGH;
    ODCDbits.ODCD5      = ODC_ENABLE;
    
    // Setup RD9
    TRISDbits.TRISD9    = TRIS_OUTPUT;
    LATDbits.LATD9      = LAT_HIGH;
    ODCDbits.ODCD9      = ODC_ENABLE;
    
    // Setup RD10
    TRISDbits.TRISD10   = TRIS_OUTPUT;
    LATDbits.LATD10     = LAT_HIGH;
    ODCDbits.ODCD10     = ODC_ENABLE;
    
    // Setup RD11
    TRISDbits.TRISD11   = TRIS_OUTPUT;
    LATDbits.LATD11     = LAT_HIGH;
    ODCDbits.ODCD11     = ODC_ENABLE;
    
    // Setup RD12
    TRISDbits.TRISD12   = TRIS_OUTPUT;
    LATDbits.LATD12     = LAT_HIGH;
    ODCDbits.ODCD12     = ODC_ENABLE;
    
    // Setup RD13
    TRISDbits.TRISD13   = TRIS_OUTPUT;
    LATDbits.LATD13     = LAT_HIGH;
    ODCDbits.ODCD13     = ODC_ENABLE;
    
    // Setup RD14
    TRISDbits.TRISD14   = TRIS_OUTPUT;
    LATDbits.LATD14     = LAT_LOW;
    ODCDbits.ODCD14     = ODC_DISABLE;
    ANSELDbits.ANSD14   = ANALOG_DISABLE;
    RPD14Rbits.RPD14R   = 0b0001;               // Set RPD14 as UART3 TX
    
    // Setup RD15
    TRISDbits.TRISD15   = TRIS_INPUT;
    LATDbits.LATD15     = LAT_LOW;
    ODCDbits.ODCD15     = ODC_DISABLE;
    ANSELDbits.ANSD15   = ANALOG_DISABLE;
    U3RXRbits.U3RXR     = 0b1011;               // Set RPD15 as UART3 RX
    
}

// initializes port E GPIO pins
void portEGPIOInitialize (void) {
    
    // Setup RE0
    TRISEbits.TRISE0    = TRIS_OUTPUT;
    LATEbits.LATE0      = LAT_HIGH;
    ODCEbits.ODCE0      = ODC_ENABLE;
    
    // Setup RE1
    TRISEbits.TRISE1    = TRIS_OUTPUT;
    LATEbits.LATE1      = LAT_HIGH;
    ODCEbits.ODCE1      = ODC_ENABLE;
    
    // Setup RE2
    TRISEbits.TRISE2    = TRIS_OUTPUT;
    LATEbits.LATE2      = LAT_HIGH;
    ODCEbits.ODCE2      = ODC_ENABLE;
    
    // Setup RE3
    TRISEbits.TRISE3    = TRIS_OUTPUT;
    LATEbits.LATE3      = LAT_HIGH;
    ODCEbits.ODCE3      = ODC_ENABLE;
    
    // Setup RE4
    TRISEbits.TRISE4    = TRIS_OUTPUT;
    LATEbits.LATE4      = LAT_HIGH;
    ODCEbits.ODCE4      = ODC_ENABLE;
    ANSELEbits.ANSE4    = ANALOG_DISABLE;
    
    // Setup RE5
    TRISEbits.TRISE5    = TRIS_OUTPUT;
    LATEbits.LATE5      = LAT_HIGH;
    ODCEbits.ODCE5      = ODC_ENABLE;
    ANSELEbits.ANSE5    = ANALOG_DISABLE;
    
    // Setup RE6
    TRISEbits.TRISE6    = TRIS_OUTPUT;
    LATEbits.LATE6      = LAT_HIGH;
    ODCEbits.ODCE6      = ODC_ENABLE;
    ANSELEbits.ANSE6    = ANALOG_DISABLE;
    
    // Setup RE7
    TRISEbits.TRISE7    = TRIS_OUTPUT;
    LATEbits.LATE7      = LAT_LOW;
    ODCEbits.ODCE7      = ODC_DISABLE;
    ANSELEbits.ANSE7    = ANALOG_DISABLE;
    
    // Setup RE8
    TRISEbits.TRISE8    = TRIS_OUTPUT;
    LATEbits.LATE8      = LAT_LOW;
    ODCEbits.ODCE8      = ODC_DISABLE;
    ANSELEbits.ANSE8    = ANALOG_DISABLE;
    
    // Setup RE9
    TRISEbits.TRISE9    = TRIS_OUTPUT;
    LATEbits.LATE9      = LAT_LOW;
    ODCEbits.ODCE9      = ODC_DISABLE;
    ANSELEbits.ANSE9    = ANALOG_DISABLE;
    
}

// initializes port F GPIO pins
void portFGPIOInitialize (void) {
    
    // Setup RF0
    TRISFbits.TRISF0    = TRIS_OUTPUT;
    LATFbits.LATF0      = LAT_HIGH;
    ODCFbits.ODCF0      = ODC_ENABLE;
    
    // Setup RF1
    TRISFbits.TRISF1    = TRIS_OUTPUT;
    LATFbits.LATF1      = LAT_HIGH;
    ODCFbits.ODCF1      = ODC_ENABLE;
    
    // Setup RF2
    TRISFbits.TRISF2    = TRIS_OUTPUT;
    LATFbits.LATF2      = LAT_HIGH;
    ODCFbits.ODCF2      = ODC_ENABLE;
    
    // Setup RF3
    TRISFbits.TRISF3    = TRIS_OUTPUT;
    LATFbits.LATF3      = LAT_HIGH;
    ODCFbits.ODCF3      = ODC_ENABLE;
    
    // Setup RF4
    TRISFbits.TRISF4    = TRIS_OUTPUT;
    LATFbits.LATF4      = LAT_LOW;
    ODCFbits.ODCF4      = ODC_DISABLE;
    
    // Setup RF5
    TRISFbits.TRISF5    = TRIS_OUTPUT;
    LATFbits.LATF5      = LAT_HIGH;
    ODCFbits.ODCF5      = ODC_ENABLE;
    
    // Setup RF8
    TRISFbits.TRISF8    = TRIS_OUTPUT;
    LATFbits.LATF8      = LAT_HIGH;
    ODCFbits.ODCF8      = ODC_ENABLE;
    
    // Setup RF12
    TRISFbits.TRISF12   = TRIS_OUTPUT;
    LATFbits.LATF12     = LAT_LOW;
    ODCFbits.ODCF12     = ODC_DISABLE;
    ANSELFbits.ANSF12   = ANALOG_DISABLE;
    
    // Setup RF13
    TRISFbits.TRISF13   = TRIS_INPUT;
    LATFbits.LATF13     = LAT_LOW;
    ODCFbits.ODCF13     = ODC_DISABLE;
    ANSELFbits.ANSF13   = ANALOG_DISABLE;
    
}

// initializes port G GPIO pins
void portGGPIOInitialize (void) {
    
    // Setup RG0
    TRISGbits.TRISG0    = TRIS_OUTPUT;
    LATGbits.LATG0      = LAT_LOW;
    ODCGbits.ODCG0      = ODC_DISABLE;
    
    // Setup RG1
    TRISGbits.TRISG1    = TRIS_OUTPUT;
    LATGbits.LATG1      = LAT_LOW;
    ODCGbits.ODCG1      = ODC_DISABLE;
    
    // Setup RG6
    TRISGbits.TRISG6    = TRIS_INPUT;
    LATGbits.LATG6      = LAT_LOW;
    ODCGbits.ODCG6      = ODC_DISABLE;
    ANSELGbits.ANSG6    = ANALOG_DISABLE;
    
    // Setup RG7
    TRISGbits.TRISG7    = TRIS_INPUT;
    LATGbits.LATG7      = LAT_LOW;
    ODCGbits.ODCG7      = ODC_DISABLE;
    ANSELGbits.ANSG7    = ANALOG_DISABLE;
    INT4Rbits.INT4R     = 0b0001;               // Assign INT4 to RPG7
    
    // Setup RG8
    TRISGbits.TRISG8    = TRIS_INPUT;
    LATGbits.LATG8      = LAT_LOW;
    ODCGbits.ODCG8      = ODC_DISABLE;
    ANSELGbits.ANSG8    = ANALOG_DISABLE;
    INT3Rbits.INT3R     = 0b0001;               // Assign INT3 to RPG3
    
    // Setup RG9
    TRISGbits.TRISG9    = TRIS_OUTPUT;
    LATGbits.LATG9      = LAT_LOW;
    ODCGbits.ODCG9      = ODC_DISABLE;
    ANSELGbits.ANSG9    = ANALOG_DISABLE;
    
    // Setup RG12
    TRISGbits.TRISG12   = TRIS_OUTPUT;
    LATGbits.LATG12     = LAT_HIGH;
    ODCGbits.ODCG12     = ODC_ENABLE;
    
    // Setup RG13
    TRISGbits.TRISG13   = TRIS_OUTPUT;
    LATGbits.LATG13     = LAT_HIGH;
    ODCGbits.ODCG13     = ODC_ENABLE;
    
    // Setup RG14
    TRISGbits.TRISG14   = TRIS_OUTPUT;
    LATGbits.LATG14     = LAT_HIGH;
    ODCGbits.ODCG14     = ODC_ENABLE;
    
    // Setup RG15
    TRISGbits.TRISG15   = TRIS_OUTPUT;
    LATGbits.LATG15     = LAT_HIGH;
    ODCGbits.ODCG15     = ODC_ENABLE;
    ANSELGbits.ANSG15   = ANALOG_DISABLE;

}
