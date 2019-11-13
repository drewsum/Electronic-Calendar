/* ************************************************************************** */
/** Power Saving

  @Company
 Marquette Senior Design E44 2018-2019

  @File Name
    power_saving.h

  @Summary
 Gives APIs for disabling unused peripherals and entering/exiting sleep mode, etc

 */
/* ************************************************************************** */

#ifndef _POWER_SAVING_H    /* Guard against multiple inclusion */
#define _POWER_SAVING_H

#include <xc.h>

#include "device_control.h"

// These are macros needed for defining ISRs, included in XC32
#include <sys/attribs.h>

// This function disables unused peripherals on startup for power savings
// THIS FUNCTION CAN ONLY BE CALLED ONCE DUE TO PMD LOCKOUT AFTER ONE WRITE SESSION
void PMDInitialize(void);

// This function prints the status of PMD settings
void printPMDStatus(void);

// this function initializes INT2 for use with the cap touch power toggle pushbutton
void capTouchPowerInitialize(void);

// This function initializes the heartbeat timer
void powerToggleDebounceTimerIntialize(void);

// this is the cap touch power toggle button interrupt service routine
void __ISR(_EXTERNAL_2_VECTOR, IPL7SRS) capTouchPowerToggleISR(void);

// power toggle debounce timer ISR
void __ISR(_TIMER_8_VECTOR, IPL3SRS) powerToggleDebounceISR(void);

#endif /* _POWER_SAVING_H */

/* *****************************************************************************
 End of File
 */
