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

#ifndef _CALENDAR_LEDS_H    /* Guard against multiple inclusion */
#define _CALENDAR_LEDS_H

#include <xc.h>
#include "pin_macros.h"
#include "rtcc.h"

// this function updates the month LEDs to reflect the month passed to it
void updateMonthLEDs(month_t input_month);

// this function updates the weekday LEDs to reflect the weekday passed
void updateWeekdayLEDs(weekday_t input_weekday);

// this function updates the year LEDs to indicate the year passed
void updateYearLEDs(uint16_t input_years);


#endif /* _CALENDAR_LEDS_H */

/* *****************************************************************************
 End of File
 */
