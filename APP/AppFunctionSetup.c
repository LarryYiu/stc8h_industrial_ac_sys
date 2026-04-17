#include "AppFunctionSetup.h"

void App_Init()
{
    EAXSFR();
    UART_Config_Common();
    Timer_Config_t0_1ms();
    TouchKey_Config();
    // other peripheral configurations can be added here
}