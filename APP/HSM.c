#include "HSM.h"

AHT21_DAT_t xdata dat = {0.0f, 0.0f};
u8 backlightCounter = BACKLIGHT_CD;
bit backlightResetFlag = FALSE;

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
bit State_On(Event_t evt);
bit State_Off(Event_t evt);

State_t code TOP = {State_Top, NULL};
State_t code ON = {State_On, &TOP};
State_t code OFF = {State_Off, &TOP};

HSM_t hsm = {&ON};
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
        AHT21_Read(&dat);
        LCD_SetHumidity(TRUE, dat.humidity, TRUE);
        LCD_SetTemperature(TRUE, dat.temperature, TRUE);
        if (backlightCounter > 0)
        {
            backlightCounter--;
        }
    }
    if (backlightResetFlag)
    {
        backlightCounter = BACKLIGHT_CD;
        backlightResetFlag = FALSE;
    }
    if (backlightCounter == 0)
    {
        LCD_SetBacklight(FALSE);
    }
    else
    {
        LCD_SetBacklight(TRUE);
    }

    if (evt == EVT_DEFAULT)
    {
        return 1;  // handled
    }
    return 0;
}

bit State_On(Event_t evt)
{
    // LCD_SetBacklight(TRUE);
    switch (evt)
    {
        case EVT_DEFAULT:
            return 0;
        case EVT_BTN:
            hsm.Current = &OFF;
            printf("to OFF\r\n");
            return 1;
    }
    return 0;
}

bit State_Off(Event_t evt)
{
    // LCD_SetBacklight(FALSE);
    switch (evt)
    {
        case EVT_DEFAULT:
            return 0;
        case EVT_BTN:
            printf("to ON\r\n");
            hsm.Current = &ON;
            return 1;
    }
    return 0;
}

/* ENTRY */

void HSM_Run(Event_t evt) { HSM_Dispatch(evt); }