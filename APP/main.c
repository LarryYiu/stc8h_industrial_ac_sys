#include <stc8h.h>
#include <stdio.h>

#include "AppFunctionSetup.h"
#include "Config.h"
#include "STC8G_H_Delay.h"

void main()
{
    App_Init();
    EA = 1;
    // TouchKey_Calibrate();
    printf("Hello World! \r\n");

    while (1)
    {
        if (TK_Ready)
        {
            TK_Ready = FALSE;
            printf("val: %u\r\n", TouchKey_GetRawData(14));
        }
    }
}