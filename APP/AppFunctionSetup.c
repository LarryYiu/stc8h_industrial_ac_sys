#include "AppFunctionSetup.h"

void App_Init()
{
    EAXSFR();
    UART_Config_Common();
    TouchKey_Config();
    Timer_Config_t0_1ms();
    // other peripheral configurations can be added here
}