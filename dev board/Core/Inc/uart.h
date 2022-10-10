#ifndef __UART_H
#define __UART_H

#include "stm32g4xx_hal.h"
#include "string.h"

void initUart(UART_HandleTypeDef *huart);
void uartPrint(char *string);

#endif //uart