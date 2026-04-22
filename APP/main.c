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
            TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress, onLongPress);
        }
        HSM_Run(evt);
        evt = EVT_DEFAULT;
    }
}