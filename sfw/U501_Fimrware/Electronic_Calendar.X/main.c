/*
 * File:   main.c
 * Author: Drew Maatman
 *
 * Created on July 19, 2019, 9:00 PM
 */


#include <xc.h>
#include <stdio.h>

#include "configuration.h"
#include "32mz_interrupt_control.h"
#include "cause_of_reset.h"
#include "pin_macros.h"
#include "32mz_interrupt_control.h"
#include "device_control.h"
// #include "gpio_setup.h"


void main(void) {
    
    // Set up system clocks
    clockInitialize();
    
    // Set up GPIO ports
    gpioInitialize();
    
    return;
}
