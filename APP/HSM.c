#include "HSM.h"

typedef struct State State_t;
typedef struct HSM HSM_t;

typedef bit (*StateHandler_t)(Event_t evt);

struct State
{
    StateHandler_t Handler;
    State_t* Parent;
};

struct HSM
{
    State_t* Current;
};

bit State_Top(Event_t evt);
bit State_Off(Event_t evt);

bit State_OnAuto(Event_t evt);
bit State_OnManual(Event_t evt);

State_t code TOP = {State_Top, NULL};
State_t code OFF = {State_Off, &TOP};

State_t code MANUAL = {State_OnManual, &TOP};
State_t code AUTO = {State_OnAuto, &TOP};

HSM_t hsm = {&OFF};
void HSM_Dispatch(Event_t evt)
{
    State_t* s = hsm.Current;

    while (s != 0)
    {
        if (s->Handler(evt))
        {
            break;  // handled
        }
        s = s->Parent;  // go to parent
    }
}

bit State_Top(Event_t evt)
{
    if (time0IntNum % 1000 == 0)
    {
        SYS_UpdateTempHum();
        SYS_DecreaseBackLightCD();
    }
    SYS_HandleBackLight();

    if (evt == EVT_DEFAULT)
    {
        return 1;  // handled
    }
    return 0;
}

bit State_Off(Event_t evt)
{
    if (evt > EVT_DEFAULT)
    {
        SYS_ResetBackLightCD();
    }
    switch (evt)
    {
        case EVT_DEFAULT:
            return 0;
        case EVT_BTN_POWER:
        {
            hsm.Current = SYS_GetFanMode() ? &MANUAL : &AUTO;
            SYS_StartFilterTimer();
            return 1;
        }
    }
    return 0;
}

bit State_OnAuto(Event_t evt)
{
    // TODO: implement auto mode logic
    LCD_SetManualSign(FALSE);
    LCD_SetAutoSign(TRUE);
    SYS_UpdateFanSpeed();
    if (evt > EVT_DEFAULT)
    {
        SYS_ResetBackLightCD();
    }
    switch (evt)
    {
        case EVT_DEFAULT:
            return 0;
        case EVT_BTN_POWER:
            hsm.Current = &OFF;
            SYS_StopFilterTimer();
            SYS_FanDisplayOff();
            return 1;
        case EVT_BTN_MODE:
            hsm.Current = &MANUAL;
            return 1;
    }
    return 0;
}

bit State_OnManual(Event_t evt)
{
    if (evt > EVT_DEFAULT)
    {
        SYS_ResetBackLightCD();
    }
    LCD_SetManualSign(TRUE);
    LCD_SetAutoSign(FALSE);
    SYS_UpdateFanSpeed();
    switch (evt)
    {
        case EVT_DEFAULT:
            return 0;
        case EVT_BTN_POWER:
            hsm.Current = &OFF;
            SYS_StopFilterTimer();
            SYS_FanDisplayOff();
            return 1;
        case EVT_BTN_MODE:
            hsm.Current = &AUTO;
            return 1;
        case EVT_BTN_UP:
            SYS_IncreaseFanSpeed();
            return 1;
        case EVT_BTN_DOWN:
            SYS_DecreaseFanSpeed();
            return 1;
    }
    return 0;
}