
#include <stdio.h>

#include "misc_IO_functions.h"

#include "pin_macros.h"

#include "terminal_control.h"

// this function checks the state of the power good signals
void powerGoodCheck(void) {
 
    pgood_status.BCKP_PGOOD = nDIODE_FAULT_PIN;
    pgood_status.POS12_PGOOD = POS12_PGOOD_PIN;
    pgood_status.POS3P3_PGOOD = POS3P3_PGOOD_PIN;
    pgood_status.POS5_USB_PGOOD = POS5_USB_PGOOD_PIN;
    pgood_status.VBAT_ISOLATE = !(nVBAT_ISOLATE_PIN);
    
}

// this function prints current PGOOD status
void printPGOODStatus(void) {
 
    terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, BOLD_FONT);
    printf("Current Power Good Status:\r\n");
   
    if (pgood_status.POS12_PGOOD) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    +12V Input Voltage is %s\n\r", pgood_status.POS12_PGOOD ? "within regulation" : "out of regulation");
    
    if (pgood_status.POS3P3_PGOOD) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    +3.3V Power Supply Voltage is %s\n\r", pgood_status.POS3P3_PGOOD ? "within regulation" : "out of regulation");
    
    if (pgood_status.POS5_USB_PGOOD) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    USB Bus Voltage is %s\n\r", pgood_status.POS5_USB_PGOOD ? "within regulation" : "out of regulation (or USB cable is unplugged)");
    
    if (pgood_status.BCKP_PGOOD) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Backup Ideal Diode is %s\n\r", pgood_status.BCKP_PGOOD ? "functional" : "faulty");
    
    if (pgood_status.VBAT_ISOLATE) terminalTextAttributes(GREEN_COLOR, BLACK_COLOR, NORMAL_FONT);
    else terminalTextAttributes(RED_COLOR, BLACK_COLOR, NORMAL_FONT);
    printf("    Backup Battery is %s Ideal Diode\n\r", pgood_status.VBAT_ISOLATE ? "connected to" : "isolated from");
    
    terminalTextAttributesReset();
}