#include "SysCtl.h"

bit backlightResetFlag = FALSE;
u8 backlightCounter = BACKLIGHT_CD;

static AirCtlData_t xdata dat;
static AHT21_DAT_t xdata aht21Dat = {0.0F, 0.0F};

void SYS_Init()
{
    LCD_Clear();
    Data_Load(&dat);
    SYS_UpdateTempHum();
}

/**
 * @return bit manual mode: 1, auto mode: 0
 */
bit SYS_GetFanMode() { return Data_GetFanMode(&dat); }

void SYS_SetFanMode(bit manual) { Data_SetFanMode(&dat, manual); }

void SYS_UpdateTempHum()
{
    AHT21_Read(&aht21Dat);
    LCD_SetTemperature(aht21Dat.temperature, TRUE);
    LCD_SetHumidity(aht21Dat.humidity, TRUE);
}

void SYS_DisplaySetting(SETTING_CATE cat, u8 index)
{
    LCD_SetManualSign(FALSE);
    LCD_SetAutoSign(FALSE);
    LCD_SetFanSpeed(0);
    LCD_SetSettingSign(TRUE);
    LCD_HideHumidity();
    LCD_SetTemperature(index + 1, FALSE);
    if (cat == SETTING_FAN_TH)
        LCD_SetPM25(dat.autoSpeedPM25Threshold[index], FALSE);
    else if (cat == SETTING_INHALE_PWM)
        LCD_SetPM25(dat.autoSpeedInhalePWM[index], FALSE);
    else if (cat == SETTING_EXHALE_PWM)
        LCD_SetPM25(dat.autoSpeedExhaustPWM[index], FALSE);
    else if (cat == SETTING_FILTER_TH)
        LCD_SetPM25(dat.filterSetTime, FALSE);
}

void SYS_IncreaseSettingValue(SETTING_CATE cat, u8 index)
{
    if (cat == SETTING_FAN_TH)
        dat.autoSpeedPM25Threshold[index]++;
    else if (cat == SETTING_INHALE_PWM)
        dat.autoSpeedInhalePWM[index]++;
    else if (cat == SETTING_EXHALE_PWM)
        dat.autoSpeedExhaustPWM[index]++;
    else if (cat == SETTING_FILTER_TH)
        dat.filterSetTime++;
}
void SYS_DecreaseSettingValue(SETTING_CATE cat, u8 index)
{
    if (cat == SETTING_FAN_TH)
        dat.autoSpeedPM25Threshold[index]--;
    else if (cat == SETTING_INHALE_PWM)
        dat.autoSpeedInhalePWM[index]--;
    else if (cat == SETTING_EXHALE_PWM)
        dat.autoSpeedExhaustPWM[index]--;
    else if (cat == SETTING_FILTER_TH)
        dat.filterSetTime--;
}

void SYS_UpdateFanSpeed()
{
    u8 speed = Data_GetFanSpeed(&dat);
    LCD_SetFanSpeed(speed);
}

void SYS_ResetBackLightCD() { backlightCounter = BACKLIGHT_CD; }

void SYS_DecreaseBackLightCD()
{
    if (backlightCounter > 0)
        backlightCounter--;
}

void SYS_HandleBackLight()
{
    if (backlightResetFlag)
    {
        backlightCounter = BACKLIGHT_CD;
    }
    if (backlightCounter == 0)
    {
        LCD_SetBacklight(FALSE);
        backlightResetFlag = FALSE;
    }
    else
    {
        LCD_SetBacklight(TRUE);
    }
}

void SYS_IncreaseFanSpeed()
{
    u8 speed = Data_GetFanSpeed(&dat);
    speed = speed >= 5 ? 1 : speed + 1;
    Data_SetFanSpeed(&dat, speed);
    LCD_SetFanSpeed(speed);
    // TODO: handle data sending to slave
}

void SYS_DecreaseFanSpeed()
{
    u8 speed = Data_GetFanSpeed(&dat);
    speed = speed <= 1 ? 5 : speed - 1;
    Data_SetFanSpeed(&dat, speed);
    LCD_SetFanSpeed(speed);
    // TODO: handle data sending to slave
}

void SYS_StartFilterTimer() { Timer3_Run(ENABLE); }
void SYS_StopFilterTimer() { Timer3_Run(DISABLE); }
