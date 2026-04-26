#include "KeyEventHandler.h"

Event_t evt = EVT_DEFAULT;

void onShortPress(u8 index)
{
    if (index == TK_IDX_POWER)
    {
        printf("onRelease\r\n");
        evt = EVT_BTN_POWER;
    }
}

void onLongPress(u8 index)
{
    if (index == TK_IDX_POWER)
    {
    }
}
