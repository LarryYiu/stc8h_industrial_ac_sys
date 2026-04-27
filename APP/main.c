#include <stc8h.h>
#include <stdio.h>

#include "AppFunctionSetup.h"
#include "Config.h"
#include "HSM.h"
#include "KeyEventHandler.h"
#include "SysCtl.h"
// #include "LCD_Seg.h"

void main()
{
    App_Init();
    EA = 1;
    SYS_Init();
    printf("Config Done \r\n");
    // LCD_ALL();
    while (1)
    {
        if (TK_Ready)
        {
            TK_Ready = FALSE;
            // TouchKey_Event_ListenerAIO(TRUE, onShortPress, onLongPress);

            TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress, onLongPress);
            TouchKey_Event(TK_IDX_MANUAL, TRUE, onShortPress, onLongPress);
            TouchKey_Event(TK_IDX_DOWN, TRUE, onShortPress, onLongPress);
            TouchKey_Event(TK_IDX_UP, TRUE, onShortPress, onLongPress);
            TouchKey_Event(TK_IDX_SETTING, TRUE, onShortPress, onLongPress);
        }
        HSM_Dispatch(evt);
        evt = EVT_DEFAULT;

        // if (COM4.RX_TimeOut > 0)
        // {
        //     if (--COM4.RX_TimeOut == 0)
        //     {
        //         if (COM4.RX_Cnt > 0)
        //         {
        //             u8 i;
        //             for (i = 0; i < COM4.RX_Cnt; i++)
        //             {
        //                 TX4_write2buff(RX4_Buffer[i]);
        //             }
        //             COM4.RX_Cnt = 0;
        //         }
        //     }
        // }
    }
}