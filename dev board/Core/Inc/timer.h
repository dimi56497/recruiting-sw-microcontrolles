#ifndef __TIMER_H
#define __TIMER_H

#include "stm32g4xx_hal.h"
#include <stdbool.h>

typedef struct timer
{
    /* data */
    uint16_t elapsedTime;
    uint16_t timerValue;
} timer;


void initTimer(timer *timer, uint16_t timerValue);
bool timeElapsed(timer *timer);
void updateTime(timer *timer);

#endif //timer