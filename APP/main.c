#include <stc8h.h>
#include <stdio.h>

#include "AppFunctionSetup.h"
#include "Config.h"
#include "HSM.h"
#include "KeyEventHandler.h"
#include "LCD_Seg.h"
#include "SysCtl.h"

void main()
{
    App_Init();
    EA = 1;
    SYS_Init();
    printf("Config Done \r\n");
    // LCD_ALL();
    while (1)
    {
        // FSM_RUN();
        TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_MANUAL, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_DOWN, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_UP, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_SETTING, TRUE, onShortPress, onLongPress);
        HSM_Dispatch(evt);
        evt = EVT_DEFAULT;
    }
}