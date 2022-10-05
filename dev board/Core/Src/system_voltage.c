#include "system_voltage.h"

systemVoltage sysVoltage;
ADC_HandleTypeDef sysVltInput;

/**
* This funciton prepares sysVoltage with thresolds
* and takes the adc where the voltage will come from
* @param adc: adc pointer
*/
void initSysVlt(ADC_HandleTypeDef *adc)
{
    sysVltInput = *adc;
    sysVoltage.upperThld = 2.7;
    sysVoltage.lowerThld = 1.8;
}

/**
* This function reads the voltage from the adc input 
* and puts the value into sysVoltage
*/
void readSysVlt()
{
    HAL_ADC_Start(&sysVltInput);
    HAL_ADC_PollForConversion(&sysVltInput, 0);
    sysVoltage.voltage = HAL_ADC_GetValue(&sysVltInput) / 4096.0 * 3.3;
}