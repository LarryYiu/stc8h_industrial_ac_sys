#ifndef __DATAHANDLER_H__
#define __DATAHANDLER_H__

#include "Config.h"

typedef struct AirCtlData AirCtlData_t;
struct AirCtlData
{
    u8 wind;  // bit0: manual 1/auto 0
};

extern AirCtlData_t xdata sysData;
void Data_Save();
void Data_Load();
bit Data_IsFirstTime();

#endif  // __DATAHANDLER_H__