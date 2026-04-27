#ifndef __DATAHANDLER_H__
#define __DATAHANDLER_H__

#include "Config.h"

#define DAT_AUTO_THRESHOLD_DEFAULT1 10
#define DAT_AUTO_THRESHOLD_DEFAULT2 30
#define DAT_AUTO_THRESHOLD_DEFAULT3 50
#define DAT_AUTO_THRESHOLD_DEFAULT4 100

#define DAT_PWM_DEFAULT1 5
#define DAT_PWM_DEFAULT2 10
#define DAT_PWM_DEFAULT3 18
#define DAT_PWM_DEFAULT4 28
#define DAT_PWM_DEFAULT5 38

struct AirCtlData
{
    u8 fanDat;  // bit0: manual 1/auto 0
    u8 autoSpeedPM25Threshold[4];
    u8 autoSpeedInhalePWM[5];
    u8 autoSpeedExhaustPWM[5];
    u16 filterSetTime;   // in hours
    u16 filterTimeLeft;  // in hours
};
typedef struct AirCtlData AirCtlData_t;

bit Data_GetFanMode(AirCtlData_t* dat);
u8 Data_GetFanSpeed(AirCtlData_t* dat);
void Data_SetFanMode(AirCtlData_t* dat, bit manual);
void Data_SetFanSpeed(AirCtlData_t* dat, u8 speed);

void Data_Save(AirCtlData_t* dat);
void Data_Load(AirCtlData_t* dat);
void Data_CheckFirstTime(AirCtlData_t* dat);

#endif  // __DATAHANDLER_H__