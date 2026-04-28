#include "IAP_Data.h"

void Data_SetFanMode(AirCtlData_t* dat, bit manual)
{
    if (manual)
        dat->fanDat |= 0x01;
    else
        dat->fanDat &= ~0x01;
}
void Data_SetFanSpeed(AirCtlData_t* dat, u8 speed)
{
    dat->fanDat = (dat->fanDat & 0x01) | (speed << 1);
}

/**
 * @return bit manual mode: 1, auto mode: 0
 */
bit Data_GetFanMode(AirCtlData_t* dat) { return (dat->fanDat & 0x01) == 1; }
u8 Data_GetFanSpeed(AirCtlData_t* dat) { return dat->fanDat >> 1; }

void Data_CheckFirstTime(AirCtlData_t* dat)
{
    // read data bit
    // check condition

    // if first time, set default data and save
    dat->fanDat = 0x03;  // default: auto mode, speed level 1
    dat->autoSpeedPM25Threshold[0] = DAT_AUTO_THRESHOLD_DEFAULT1;
    dat->autoSpeedPM25Threshold[1] = DAT_AUTO_THRESHOLD_DEFAULT2;
    dat->autoSpeedPM25Threshold[2] = DAT_AUTO_THRESHOLD_DEFAULT3;
    dat->autoSpeedPM25Threshold[3] = DAT_AUTO_THRESHOLD_DEFAULT4;
    dat->autoSpeedInhalePWM[0] = DAT_PWM_DEFAULT1;
    dat->autoSpeedInhalePWM[1] = DAT_PWM_DEFAULT2;
    dat->autoSpeedInhalePWM[2] = DAT_PWM_DEFAULT3;
    dat->autoSpeedInhalePWM[3] = DAT_PWM_DEFAULT4;
    dat->autoSpeedInhalePWM[4] = DAT_PWM_DEFAULT5;
    dat->autoSpeedExhaustPWM[0] = DAT_PWM_DEFAULT1;
    dat->autoSpeedExhaustPWM[1] = DAT_PWM_DEFAULT2;
    dat->autoSpeedExhaustPWM[2] = DAT_PWM_DEFAULT3;
    dat->autoSpeedExhaustPWM[3] = DAT_PWM_DEFAULT4;
    dat->autoSpeedExhaustPWM[4] = DAT_PWM_DEFAULT5;
    dat->filterSetTime = 500;
    dat->filterTimeLeft = 500;
    // Data_Save();
    // set first time flag to false
}

void Data_Load(AirCtlData_t* dat) { Data_CheckFirstTime(dat); }

void Data_Save(AirCtlData_t* dat)
{
    // to be implemented: write data to flash
}