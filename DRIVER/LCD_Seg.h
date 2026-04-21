#ifndef __LCD_SEG_H__
#define __LCD_SEG_H__

#include <stc8h.h>
#include <stdio.h>

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

void LCD_SetDT(u8 tubeIndex, u8 num);

void LCD_ALL();
void LCD_Clear();

void LCD_SetHour(bit enable, u8 hour);
void LCD_Set_T_Sign(bit on);
void LCD_SetLockSign(bit on);
void LCD_SetNetSign(bit on);
void LCD_SetLeafSign(bit on);
void LCD_SetHouseLeafSign(bit on);
void LCD_Set_A_Sign(bit on);
void LCD_Set_M_Sign(bit on);
void LCD_SetHouseWindSign(bit on);
void LCD_SetSunSign(bit on);
void LCD_SetSnowSign(bit on);
void LCD_SetSignalSign(bit on);
void LCD_SetHumidity(bit enable, float humidity, bit showSign);
void LCD_SetTemperature(bit enable, float temperature, bit showSign);
void LCD_Set_PM25_Sign(bit on);
void LCD_Set485Sign(bit on);
void LCD_SetSettingTemp(bit enable, float temperature, bit showSign);
void LCD_SetSettingSign(bit on);
void LCD_SetFanLevel(int8 level);
void LCD_SETBacklight(bit on);

#endif  // __LCD_SEG_H__