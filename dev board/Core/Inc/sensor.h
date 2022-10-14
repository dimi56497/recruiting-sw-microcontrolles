#ifndef __SENSOR_H
#define __SENSOR_H

#include "stm32g4xx_hal.h"
#include "stdio.h"

extern uint8_t sensorLight;

void initSensor(ADC_HandleTypeDef *adc);
void readLight();

#endif //sensor
