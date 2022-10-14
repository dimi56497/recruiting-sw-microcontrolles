#include "sensor.h"

uint8_t sensorLight;
ADC_HandleTypeDef sensorAdc;


void initSensor(ADC_HandleTypeDef *adc)
{
    sensorAdc = *adc;
    sensorLight = 0;
}

void readLight()
{
    float voltage = 0;
    HAL_ADC_Start(&sensorAdc);
    HAL_ADC_PollForConversion(&sensorAdc, 0);
    voltage = HAL_ADC_GetValue(&sensorAdc) / 4096.0 * 3.3;
    sensorLight = voltage / 3.3 * 100;
}