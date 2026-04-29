#include "FSM.h"

AHT21_DAT_t xdata dat = {0.0f, 0.0f};
bit resetBackLightCD = FALSE;
void onShortPress(u8 index);
void onLongPress(u8 index);

void FSM_OFF(void)
{
    // update temp hum
    if (TK_Ready)
    {
        TK_Ready = FALSE;
        TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_SETTING, TRUE, onShortPress, onLongPress);
    }
}

void FSM_ON(void)
{
    if (TK_Ready)
    {
        TK_Ready = FALSE;
        TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_MANUAL, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_DOWN, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_UP, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_SETTING, TRUE, onShortPress, onLongPress);
    }
}

void FSM_SET(void)
{
    if (TK_Ready)
    {
        TK_Ready = FALSE;
        TouchKey_Event(TK_IDX_MANUAL, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_DOWN, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_UP, TRUE, onShortPress, onLongPress);
        TouchKey_Event(TK_IDX_SETTING, TRUE, onShortPress, onLongPress);
    }
}

/* FSM ENTRY */

FSM_t mainFSM = {FSM_ON, FSM_OFF};

void FSM_RUN()
{
    if (mainFSM.current != NULL)
    {
        mainFSM.current();
    }
}

/* EVENT HANDLERS HERE*/

void onShortPress(u8 index)
{
    if (index == TK_IDX_POWER)
    {
        mainFSM.last = mainFSM.current;
        mainFSM.current = FSM_OFF;
    }
    resetBackLightCD = TRUE;
}

void onLongPress(u8 index)
{
    if (index == TK_IDX_POWER)
    {
        mainFSM.last = mainFSM.current;
        mainFSM.current = FSM_ON;
    }
    resetBackLightCD = TRUE;
}