#ifndef __AHT21__
#define __AHT21__

#include <stc8h.h>

#include "Config.h"
#include "I2C.h"
#include "STC8G_H_Delay.h"

#ifndef AHT21_USE_CRC
#define AHT21_USE_CRC FALSE
#endif  // AHT21_USE_CRC

#define AHT21_DAT_LEN (AHT21_USE_CRC ? 7 : 6)

typedef struct
{
    float temperature;
    float humidity;
} AHT21_DAT_t;

void AHT21_Config();

void AHT21_Read(AHT21_DAT_t* dat);

#endif  // __AHT21__