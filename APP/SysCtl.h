#ifndef __SYSCTL_H__
#define __SYSCTL_H__

#include "AHT21.h"
#include "BussinessConfig.h"
#include "Config.h"
#include "DataHandler.h"
#include "LCD_Seg.h"
#include "STC8G_H_Timer.h"

void SYS_UpdateTempHum();

void SYS_ResetBackLightCD();
void SYS_DecreaseBackLightCD();
void SYS_HandleBackLight();

void SYS_IncreaseFanSpeed();
void SYS_DecreaseFanSpeed();
#endif  // __SYSCTL_H__