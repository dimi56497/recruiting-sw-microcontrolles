#ifndef __OLD_SENSOR_H
#define __OLD_SENSOR_H

#include "stm32g4xx_hal.h"
#include "uart.h"
#include "stdio.h"

#define SENSOR_ADDR 0x90

extern float sensorTemp;

void initSensor(I2C_HandleTypeDef *i2cBus);
void readTemp();

#endif //sensor
