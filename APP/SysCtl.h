#ifndef __SYSCTL_H__
#define __SYSCTL_H__
#include <stdio.h>

#include "AHT21.h"
#include "BussinessConfig.h"
#include "Config.h"
#include "IAP_Data.h"
#include "LCD_Seg.h"
#include "STC8G_H_Timer.h"

typedef enum
{
    SETTING_FAN_TH = 0,
    SETTING_INHALE_PWM,
    SETTING_EXHALE_PWM,
    SETTING_FILTER_TH,
} SETTING_CATE;

void SYS_Init();

/**
 * @brief Get current fan mode
 * @return bit 1 for manual mode, 0 for auto mode
 */
bit SYS_GetFanMode();
void SYS_SetFanMode(bit manual);

void SYS_UpdateTempHum();
void SYS_UpdateFanSpeed();

void SYS_DisplaySetting(SETTING_CATE cat, u8 index);

void SYS_IncreaseSettingValue(SETTING_CATE cat, u8 index);
void SYS_DecreaseSettingValue(SETTING_CATE cat, u8 index);

void SYS_ResetBackLightCD();
void SYS_DecreaseBackLightCD();
void SYS_HandleBackLight();

void SYS_IncreaseFanSpeed();
void SYS_DecreaseFanSpeed();

void SYS_StartFilterTimer();
void SYS_StopFilterTimer();
#endif  // __SYSCTL_H__