#include "old sensor.h"

float sensorTemp;
I2C_HandleTypeDef sensorBus;
HAL_StatusTypeDef sensorStatus;


void initSensor(I2C_HandleTypeDef *i2cBus)
{
    sensorBus = *i2cBus;
    sensorTemp = 0;
    uint8_t initData[] = {0x01, 0x02};
    sensorStatus = HAL_I2C_Master_Transmit(&sensorBus, SENSOR_ADDR, initData, 2, 100);

    if(sensorStatus != HAL_OK)
        uartPrint("Sensor comunication error!\n\r");
}

void readTemp()
{
    uint8_t buffer[2];
    char string[20];
    int16_t rawTemp = 0;
    HAL_I2C_Master_Transmit(&sensorBus, SENSOR_ADDR, 0x00, 1, 100);
    sensorStatus = HAL_I2C_Master_Receive(&sensorBus, SENSOR_ADDR, buffer, 2, 100);

    if(sensorStatus == HAL_OK)
    {
        rawTemp = buffer[0] << 4 | buffer[1] >> 7;

        if(rawTemp > 0xFF)
        {
            rawTemp = ~rawTemp + 1;
            rawTemp &= 0x1FF;
            rawTemp *= -1;
        }

        sensorTemp = rawTemp * 0.5;
        sprintf(string, "Temperature: %.1f\n\r", sensorTemp);
        uartPrint(string);
    }
    else
    {
        uartPrint("Sensor comunication error!\n\r");
    }
}
