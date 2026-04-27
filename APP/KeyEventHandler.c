#include "KeyEventHandler.h"

Event_t evt = EVT_DEFAULT;

void onShortPress(u8 index)
{
    switch (index)
    {
        case TK_IDX_POWER:
            evt = EVT_BTN_POWER;
            break;
        case TK_IDX_MANUAL:
            evt = EVT_BTN_MODE;
            break;
        case TK_IDX_UP:
            evt = EVT_BTN_UP;
            break;
        case TK_IDX_DOWN:
            evt = EVT_BTN_DOWN;
            break;
        case TK_IDX_SETTING:
            evt = EVT_BTN_SET;
            break;
        default:
            break;
    }
}

void onLongPress(u8 index)
{
    switch (index)
    {
        case TK_IDX_POWER:
            evt = EVT_BTN_POWER_LONG;
            break;
        case TK_IDX_MANUAL:
            evt = EVT_BTN_MODE_LONG;
            break;
        case TK_IDX_UP:
            evt = EVT_BTN_UP_LONG;
            break;
        case TK_IDX_DOWN:
            evt = EVT_BTN_DOWN_LONG;
            break;
        case TK_IDX_SETTING:
            evt = EVT_BTN_SET_LONG;
            break;
        default:
            break;
    }
}
