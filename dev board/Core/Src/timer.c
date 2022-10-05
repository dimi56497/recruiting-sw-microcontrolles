#include "timer.h"

/**
* @brief Timer Initialization
* This function initializes the timer
* @param timer: timer pointer
* @param timerValue: time value in milliseconds
*/
void initTimer(timer *timer, uint16_t timerValue)
{
    timer->elapsedTime = 0;
    timer->timerValue = timerValue;
}

/**
* This function checks if the timer has
* @param timer: timer pointer
* @retval true if the time interval has elapsed
* @retval false if the time interval hasn't elapsed
*/
bool timeElapsed(timer *timer)
{
    return timer->elapsedTime == timer->timerValue;
}

/**
* This function updates the timer elapsed time
* @param timer: timer pointer
*/
void updateTime(timer *timer)
{
    if(timer->elapsedTime < timer->timerValue)
        timer->elapsedTime++;
}