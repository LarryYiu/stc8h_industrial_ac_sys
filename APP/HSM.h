#ifndef __HSM_H__
#define __HSM_H__
#include <stdio.h>

#include "BussinessConfig.h"
#include "Config.h"
#include "STC8G_H_Timer.h"
#include "SysCtl.h"
#include "TouchKey.h"

typedef enum
{
    EVT_DEFAULT = 0,
    EVT_BTN_POWER,
    EVT_BTN_POWER_LONG,
    EVT_BTN_MODE,
    EVT_BTN_MODE_LONG,
    EVT_BTN_UP,
    EVT_BTN_UP_LONG,
    EVT_BTN_DOWN,
    EVT_BTN_DOWN_LONG,
    EVT_BTN_SET,
    EVT_BTN_SET_LONG,
} Event_t;

void HSM_Dispatch(Event_t evt);

#endif  // __HSM_H__