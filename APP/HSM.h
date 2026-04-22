#ifndef __HSM_H__
#define __HSM_H__
#include <stdio.h>

#include "AHT21.h"
#include "BussinessConfig.h"
#include "Config.h"
#include "LCD_Seg.h"
#include "STC8G_H_Timer.h"
#include "TouchKey.h"

typedef enum
{
    EVT_DEFAULT = 0,
    EVT_BTN,
} Event_t;

void HSM_Dispatch(Event_t evt);
void HSM_Run(Event_t evt);

#endif  // __HSM_H__