#include "StateMachine.h"

AHT21_DAT_t xdata dat = {0.0f, 0.0f};
bit SYS_POWER = 0;
bit resetBackLightCD = FALSE;
void onShortPress_ON(u8 index);
void onShortPress_OFF(u8 index);

void FSM_OFF(void)
{
    BacklightHandler(resetBackLightCD);
    resetBackLightCD = FALSE;
    if (time0IntNum % 1000 == 0)
    {
        printf("Measuring...\r\n");
        AHT21ReadAndDisplay(&dat);
    }
    if (SYS_POWER)
    {
        printf("System Power Off\r\n");
    }
    SYS_POWER = 0;

    if (TK_Ready)
    {
        TK_Ready = FALSE;
        TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress_OFF, onShortPress_OFF);
    }
}

void FSM_ON(void)
{
    BacklightHandler(resetBackLightCD);
    resetBackLightCD = FALSE;
    if (time0IntNum % 1000 == 0)
    {
        // printf("Measuring...\r\n");
        AHT21ReadAndDisplay(&dat);
    }
    if (!SYS_POWER)
    {
        printf("System Power On\r\n");
    }
    SYS_POWER = 1;

    if (TK_Ready)
    {
        TK_Ready = FALSE;
        TouchKey_Event(TK_IDX_POWER, TRUE, onShortPress_ON, onShortPress_ON);
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

void onShortPress_ON(u8 index)
{
    if (index == TK_IDX_POWER)
    {
        mainFSM.last = mainFSM.current;
        mainFSM.current = FSM_OFF;
    }
    resetBackLightCD = TRUE;
}

void onShortPress_OFF(u8 index)
{
    if (index == TK_IDX_POWER)
    {
        mainFSM.last = mainFSM.current;
        mainFSM.current = FSM_ON;
    }
    resetBackLightCD = TRUE;
}