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

#ifndef _BINARY_CLOCK_H    /* Guard against multiple inclusion */
#define _BINARY_CLOCK_H

#include <xc.h>
#include "pin_macros.h"

// This function updates the binary clock LEDs based on hours, minutes and seconds passed to it
void updateBinaryClockLEDs(uint8_t input_hours, uint8_t input_minutes, uint8_t input_seconds);

#endif /* _BINARY_CLOCK_H */

/* *****************************************************************************
 End of File
 */
