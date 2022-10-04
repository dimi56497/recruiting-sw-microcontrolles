#include "timer.h"

void initTimer(timer *timer, uint16_t timerValue)
{
    timer->elapsedTime = 0;
    timer->timerValue = timerValue;
}

bool elapsedTime(timer *timer)
{
    return timer->elapsedTime == timer->timerValue;
}

void updateTime(timer *timer)
{
    timer->elapsedTime++;
}