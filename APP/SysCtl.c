#include "SysCtl.h"

bit backlightResetFlag = FALSE;
u8 backlightCounter = BACKLIGHT_CD;

AHT21_DAT_t xdata dat = {0.0f, 0.0f};
void SYS_UpdateTempHum()
{
    AHT21_Read(&dat);
    LCD_SetHumidity(TRUE, dat.humidity, TRUE);
    LCD_SetTemperature(TRUE, dat.temperature, TRUE);
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
}

void SYS_IncreaseFanSpeed()
{
    u8 speed = sysData.wind >> 1;
    speed = speed >= 5 ? 1 : speed + 1;
    LCD_SetFanLevel(speed);
    sysData.wind = (sysData.wind & 0x01) | (speed << 1);
    // TODO: handle data sending to slave
}

void SYS_DecreaseFanSpeed()
{
    u8 speed = sysData.wind >> 1;
    speed = speed <= 1 ? 5 : speed - 1;
    LCD_SetFanLevel(speed);
    sysData.wind = (sysData.wind & 0x01) | (speed << 1);
    // TODO: handle data sending to slave
}