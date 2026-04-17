#include <stc8h.h>
#include <stdio.h>

#include "AppFunctionSetup.h"
#include "Config.h"
#include "STC8G_H_Delay.h"

void onShortPress(u8 index)
{
    printf("key %bu, duration: %bu, cnt: %bu\r\n", index,
           touchKeys[index].pressDuration, touchKeys[index].pressCount);
}

void onLongPress(u8 index)
{
    printf("key %bu, duration: %bu, cnt: %bu\r\n", index,
           touchKeys[index].pressDuration, touchKeys[index].pressCount);
}

void main()
{
    // u32 xdata printCnter = 0;
    App_Init();
    EA = 1;
    printf("Config Done \r\n");

    while (1)
    {
        // if (time0IntNum - printCnter >= 1000)  // print every 1s
        // {
        //     printCnter = time0IntNum;
        //     if (TK_Ready)
        //     {
        //         TK_Ready = FALSE;
        //         printf("val  6: %u, init: %u\r\n", TouchKey_GetRawData(6),
        //                TouchKey_GetInitVal(6));
        //         printf("val  7: %u, init: %u\r\n", TouchKey_GetRawData(7),
        //                TouchKey_GetInitVal(7));
        //         printf("val 12: %u, init: %u\r\n", TouchKey_GetRawData(12),
        //                TouchKey_GetInitVal(12));
        //         printf("val 13: %u, init: %u\r\n", TouchKey_GetRawData(13),
        //                TouchKey_GetInitVal(13));
        //         printf("val 14: %u, init: %u\r\n", TouchKey_GetRawData(14),
        //                TouchKey_GetInitVal(14));
        //         printf("\n\n");
        //     }
        // }

        if (TK_Ready)
        {
            TK_Ready = FALSE;
            TouchKey_Event(14, onShortPress, onLongPress);
        }
    }
}