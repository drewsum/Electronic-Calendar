
#include "calendar_leds.h"

// this function updates the month LEDs to reflect the month passed to it
void updateMonthLEDs(month_t input_month) {
 
    // decide what LEDs to turn on based on input_month
    switch (input_month) {
     
        case January:
            nJAN_LED_PIN = LOW;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case February:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = LOW;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case March:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = LOW;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case April:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = LOW;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case May:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = LOW;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case June:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = LOW;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case July:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = LOW;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case August:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = LOW;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case September:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = LOW;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case October:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = LOW;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
        case November:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = LOW;
            nDEC_LED_PIN = HIGH;
            break;
            
        case December:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = LOW;
            break;
            
        default:
            nJAN_LED_PIN = HIGH;
            nFEB_LED_PIN = HIGH;
            nMAR_LED_PIN = HIGH;
            nAPR_LED_PIN = HIGH;
            nMAY_LED_PIN = HIGH;
            nJUN_LED_PIN = HIGH;
            nJUL_LED_PIN = HIGH;
            nAUG_LED_PIN = HIGH;
            nSEP_LED_PIN = HIGH;
            nOCT_LED_PIN = HIGH;
            nNOV_LED_PIN = HIGH;
            nDEC_LED_PIN = HIGH;
            break;
            
    }
    
}

// this function updates the weekday LEDs to reflect the weekday passed
void updateWeekdayLEDs(weekday_t input_weekday) {
 
    // determine IO settings based on input_weekday
    switch (input_weekday) {
    
        case Sunday:
            nSUN_LED_PIN = LOW;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = HIGH;
            break;
            
        case Monday:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = LOW;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = HIGH;
            break;
            
        case Tuesday:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = LOW;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = HIGH;
            break;
            
        case Wednesday:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = LOW;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = HIGH;
            break;
            
        case Thursday:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = LOW;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = HIGH;
            break;
            
        case Friday:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = LOW;
            nSAT_LED_PIN = HIGH;
            break;
        
        case Saturday:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = LOW;
            break;
            
        default:
            nSUN_LED_PIN = HIGH;
            nMON_LED_PIN = HIGH;
            nTUE_LED_PIN = HIGH;
            nWED_LED_PIN = HIGH;
            nTHUR_LED_PIN = HIGH;
            nFRI_LED_PIN = HIGH;
            nSAT_LED_PIN = HIGH;
            break;
            
    }
    
}

// this function updates the year LEDs to indicate the year passed
void updateYearLEDs(uint16_t input_year) {
 
    switch (input_year) {
     
        case 2019:
            YEAR_B0_PIN = LOW;
            YEAR_B1_PIN = LOW;
            YEAR_B2_PIN = LOW;
            break;
            
        case 2020:
            YEAR_B0_PIN = HIGH;
            YEAR_B1_PIN = LOW;
            YEAR_B2_PIN = LOW;
            break;
        
        case 2021:
            YEAR_B0_PIN = LOW;
            YEAR_B1_PIN = HIGH;
            YEAR_B2_PIN = LOW;
            break;
            
        case 2022:
            YEAR_B0_PIN = HIGH;
            YEAR_B1_PIN = HIGH;
            YEAR_B2_PIN = LOW;
            break;
            
        case 2023:
            YEAR_B0_PIN = LOW;
            YEAR_B1_PIN = LOW;
            YEAR_B2_PIN = HIGH;
            break;
            
        case 2024:
            YEAR_B0_PIN = HIGH;
            YEAR_B1_PIN = LOW;
            YEAR_B2_PIN = HIGH;
            break;
            
        case 2025:
            YEAR_B0_PIN = LOW;
            YEAR_B1_PIN = HIGH;
            YEAR_B2_PIN = HIGH;
            break;
            
        case 2026:
            YEAR_B0_PIN = HIGH;
            YEAR_B1_PIN = HIGH;
            YEAR_B2_PIN = HIGH;
            break;
    
        default:
            YEAR_B0_PIN = LOW;
            YEAR_B1_PIN = LOW;
            YEAR_B2_PIN = LOW;
            break;
            
    }
    
}

// this function updates the day LEDs to indicate date passed
void updateDateLEDs(uint8_t input_day) {

    // determine settings based on input_day
    switch (input_day) {
     
        case 1:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 2:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;    
            
        case 3:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 4:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 5:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 6:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 7:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 8:
            nDATE_DECODE_1_PIN  = LOW;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 9:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 10:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 11:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 12:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 13:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 14:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 15:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 16:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = LOW;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 17:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 18:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 19:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 20:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 21:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 22:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 23:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 24:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = LOW;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 25:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 26:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
        case 27:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 28:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = LOW;
            break;
            
        case 29:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 30:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = HIGH;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = HIGH;
            break;
            
        case 31:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = LOW;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = HIGH;
            DATE_B2_PIN         = HIGH;
            break;
            
        default:
            nDATE_DECODE_1_PIN  = HIGH;
            nDATE_DECODE_2_PIN  = HIGH;
            nDATE_DECODE_3_PIN  = HIGH;
            nDATE_DECODE_4_PIN  = HIGH;
            DATE_B0_PIN         = LOW;
            DATE_B1_PIN         = LOW;
            DATE_B2_PIN         = LOW;
            break;
            
    }
    
}