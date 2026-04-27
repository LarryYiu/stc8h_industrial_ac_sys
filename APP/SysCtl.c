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

void SYS_FanDisplayOff() { LCD_SetFanSpeed(0); }
