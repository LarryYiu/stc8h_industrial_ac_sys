#ifndef __LCD_SEG_H__
#define __LCD_SEG_H__

#include <stc8h.h>

#include "BussinessConfig.h"
#include "Config.h"
#include "GPIO.h"
#include "STC8G_H_GPIO.h"
#include "STC8G_H_NVIC.h"
#include "STC8G_H_Switch.h"

#ifndef LCD_DEBUG
#define LCD_DEBUG TRUE
#endif  // LCD_DEBUG

void LCD_Config();
void LCD_ALL();
void LCD_Clear();

void LCD_SetManualSign(bit on);
void LCD_SetAutoSign(bit on);
void LCD_DisplayHour(char hour);
void LCD_SetTestSign(bit on);
void LCD_SetLockSign(bit on);
void LCD_SetNetSign(bit on);
void LCD_SetLeafSign(bit on);
void LCD_SetHouseLeafSign(bit on);
void LCD_SetAutoSign(bit on);
void LCD_SetManualSign(bit on);
void LCD_SetHouseWindSign(bit on);
void LCD_SetSunSign(bit on);
void LCD_SetSnowSign(bit on);
void LCD_SetSignalSign(bit on);
void LCD_SetSettingSign(bit on);
void LCD_Set485Label(bit on);
void LCD_SetTempSettingLabel(bit on);
void LCD_HideHumidity();
void LCD_SetHumidity(float humidity, bit showLabel);
void LCD_HideTemperature();
void LCD_SetTemperature(float temperature, bit showLabel);
void LCD_HidePM25();
void LCD_SetPM25(u8 pm25, bit showLabel);
void LCD_SetFanSpeed(int8 level);
void LCD_SetBacklight(bit on);

#endif  // __LCD_SEG_H__