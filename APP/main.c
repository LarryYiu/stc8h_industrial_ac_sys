#include <stc8h.h>
#include <stdio.h>

#include "AppFunctionSetup.h"
#include "Config.h"
#include "HSM.h"
#include "KeyEventHandler.h"

void main()
{
    App_Init();
    EA = 1;
    printf("Config Done \r\n");
    while (1)
    {
        if (TK_Ready)
        {
            TK_Ready = FALSE;
            TouchKey_Event_ListenerAIO(TRUE, onShortPress, onLongPress);
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