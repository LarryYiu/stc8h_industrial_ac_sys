#include "AHT21.h"

void AHT21_Config()
{
    EA = 1;
    I2C_Start();
    I2C_SendBus(0x70);
    I2C_RecvACK();
    I2C_SendBus(0xBE);
    I2C_RecvACK();
    I2C_SendBus(0x08);
    I2C_RecvACK();
    I2C_SendBus(0x00);
    I2C_RecvACK();
    I2C_Stop();
    delay_ms(10);
    EA = 0;
}

void __AHT21_Measure()
{
    I2C_Start();
    I2C_SendBus(0x70);
    I2C_RecvACK();
    I2C_SendBus(0xAC);
    I2C_RecvACK();
    I2C_SendBus(0x33);
    I2C_RecvACK();
    I2C_SendBus(0x00);
    I2C_RecvACK();
    I2C_Stop();
    delay_ms(80);
}

#if (AHT21_USE_CRC)
void __AHT21_Validate(u8* rawDat) {}
#endif  // AHT21_USE_CRC

void AHT21_Read(AHT21_DAT_t* dat)
{
    u8 buffer[AHT21_DAT_LEN];
    u8 i;
    __AHT21_Measure();
    I2C_Start();
    I2C_SendBus(0x71);
    I2C_RecvACK();
    for (i = 0; i < AHT21_DAT_LEN; i++)
    {
        buffer[i] = I2C_RecvBus();
        if (i < AHT21_DAT_LEN - 1)
        {
            I2C_SendACK();
        }
        else
        {
            I2C_SendNACK();
        }
    }
    I2C_Stop();

#if AHT21_USE_CRC
    if (!__AHT21_Validate(&buffer))
        return;
#endif

    dat->humidity = (((u32)buffer[1] << 12) | ((u32)buffer[2] << 4) |
                     ((u32)buffer[3] >> 4)) *
                    100.0f / 1048576.0f;
    dat->temperature = (((u32)(buffer[3] & 0x0f) << 16) |
                        ((u32)buffer[4] << 8) | ((u32)buffer[5])) *
                           200.0f / 1048576.0f -
                       50.0f;
}