#ifndef __SYSTEM_VOLTAGE_H
#define __SYSTEM_VOLTAGE_H

#include "stm32g4xx_hal.h"

typedef struct systemVoltage
{
    float voltage;
    float upperThld; //upper thresold
    float lowerThld; //lower thresold
} systemVoltage;

extern systemVoltage sysVoltage;

void initSysVlt(ADC_HandleTypeDef *adc);

void readSysVlt(void);

#endif //system