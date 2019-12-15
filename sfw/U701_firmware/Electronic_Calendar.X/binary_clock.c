
#include "binary_clock.h"

// This function updates the binary clock LEDs based on hours, minutes and seconds passed to it
void updateBinaryClockLEDs(uint8_t input_hours, uint8_t input_minutes, uint8_t input_seconds) {
    
    // Set hour
    uint8_t input_hours10 = (input_hours / 10) % 10;
    uint8_t input_hours01 = input_hours % 10;
    
    // Set minutes
    uint8_t input_minutes10 = (input_minutes / 10) % 10;
    uint8_t input_minutes01 = input_minutes % 10;
    
    // Set second
    uint8_t input_seconds10 = (input_seconds / 10) % 10;
    uint8_t input_seconds01 = input_seconds % 10;
    
    
    
    // update hour pins
    nHOURS6_LED_PIN = !(input_hours01 & (1 << 0));
    nHOURS4_LED_PIN = !(input_hours01 & (1 << 1));
    nHOURS2_LED_PIN = !(input_hours01 & (1 << 2));
    nHOURS0_LED_PIN = !(input_hours01 & (1 << 3));
    
    nHOURS5_LED_PIN = !(input_hours10 & (1 << 0));
    nHOURS3_LED_PIN = !(input_hours10 & (1 << 1));
    nHOURS1_LED_PIN = !(input_hours10 & (1 << 2));
    
    // update minute pins
    nMINUTES6_LED_PIN = !(input_minutes01 & (1 << 0));
    nMINUTES4_LED_PIN = !(input_minutes01 & (1 << 1));
    nMINUTES2_LED_PIN = !(input_minutes01 & (1 << 2));
    nMINUTES0_LED_PIN = !(input_minutes01 & (1 << 3));
    
    nMINUTES5_LED_PIN = !(input_minutes10 & (1 << 0));
    nMINUTES3_LED_PIN = !(input_minutes10 & (1 << 1));
    nMINUTES1_LED_PIN = !(input_minutes10 & (1 << 2));
        
    // update second pins
    nSECONDS6_LED_PIN = !(input_seconds01 & (1 << 0));
    nSECONDS4_LED_PIN = !(input_seconds01 & (1 << 1));
    nSECONDS2_LED_PIN = !(input_seconds01 & (1 << 2));
    nSECONDS0_LED_PIN = !(input_seconds01 & (1 << 3));
    
    nSECONDS5_LED_PIN = !(input_seconds10 & (1 << 0));
    nSECONDS3_LED_PIN = !(input_seconds10 & (1 << 1));
    nSECONDS1_LED_PIN = !(input_seconds10 & (1 << 2));
    
}