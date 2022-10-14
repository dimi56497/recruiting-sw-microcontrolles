#include "uart.h"

UART_HandleTypeDef uart;

void initUart(UART_HandleTypeDef *huart)
{
    uart = *huart;
}

void uartPrint(char *string)
{
    HAL_UART_Transmit(&uart, string, strlen(string), 10);
}