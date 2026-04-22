#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include <stdio.h>

#include "AHT21.h"
#include "BussinessConfig.h"
#include "Config.h"
#include "LCD_Seg.h"
#include "STC8G_H_Delay.h"
#include "STC8G_H_Timer.h"
#include "StandaloneTask.h"
#include "TouchKey.h"

typedef void (*StateFunc_t)(void);

typedef struct
{
    StateFunc_t last;
    StateFunc_t current;
} FSM_t;

void FSM_RUN();

#endif  // __STATEMACHINE_H__