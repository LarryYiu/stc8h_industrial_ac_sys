#include "AppFunctionSetup.h"

void App_Init()
{
    EAXSFR();
    UART_Config_Common();
    Timer_Config_t0_1ms();
    I2C_Config_Common();
    TouchKey_Config();
    LCD_Config();
    AHT21_Config();
    // other peripheral configurations can be added here
}