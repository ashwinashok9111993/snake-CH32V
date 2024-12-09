#ifndef MAIN_H
#define MAIN_H

#include "debug.h"
#include "string.h"
#include "stdbool.h"

#define NUM_CHANNELS 2
// Two channels: PB0 and PB1

typedef struct
{
    uint16_t x; // Joystick X-axis value
    uint16_t y; // Joystick Y-axis value
} JoystickData_t;

extern JoystickData_t JoystickData;
extern uint16_t DMA_Buffer[NUM_CHANNELS];
extern bool JoystickPressed;


#endif