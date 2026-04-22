#include "I2C.h"

bit I2C_Config(u8 i2cPins, bit isMaster, bit isEnabled, bit isAutoSendEnabled,
               u8 i2cSpeed, int8 priority)
{
    bit res = FALSE;
    I2C_InitTypeDef i2c;
    bit noPrio = priority < 0;
    i2c.I2C_Mode = isMaster;
    i2c.I2C_Enable = isEnabled;
    i2c.I2C_MS_WDTA = isAutoSendEnabled;
    i2c.I2C_Speed = i2cSpeed;
    I2C_Init(&i2c);
    if (noPrio)
    {
        res = NVIC_I2C_Init(isMaster, DISABLE, Priority_0);
    }
    else
    {
        res = NVIC_I2C_Init(isMaster, ENABLE, priority > 3 ? 3 : priority);
    }

    I2C_SW(i2cPins);
    if (i2cPins == I2C_P14_P15)
    {
        GPIO_Config(GPIO_P1, GPIO_Pin_4 | GPIO_Pin_5, GPIO_PullUp);
    }
    else if (i2cPins == I2C_P24_P25)
    {
        GPIO_Config(GPIO_P2, GPIO_Pin_4 | GPIO_Pin_5, GPIO_PullUp);
    }
    else if (i2cPins == I2C_P33_P32)
    {
        GPIO_Config(GPIO_P3, GPIO_Pin_3 | GPIO_Pin_2, GPIO_PullUp);
    }
    else
    {
        res &= FALSE;
    }
    return res;
}

void I2C_Config_Common()
{
    I2C_Config(I2C_P33_P32, I2C_Mode_Master, ENABLE, DISABLE, 16, -1);
}

void __I2C_Wait()
{
    while (!(I2CMSST & 0x40));
    I2CMSST &= ~0x40;
}

void I2C_Start()
{
    I2CMSCR = 0x01;
    __I2C_Wait();
}

void I2C_Stop()
{
    I2CMSCR = 0x06;
    __I2C_Wait();
}

void I2C_SendBus(u8 dat)
{
    I2CTXD = dat;
    I2CMSCR = 0x02;
    __I2C_Wait();
}

u8 I2C_RecvBus()
{
    I2CMSCR = 0x04;
    __I2C_Wait();
    return I2CRXD;
}

void I2C_RecvACK()
{
    I2CMSCR = 0x03;
    __I2C_Wait();
}

void I2C_SendACK()
{
    I2CMSST = 0x00;
    I2CMSCR = 0x05;
    __I2C_Wait();
}

void I2C_SendNACK()
{
    I2CMSST = 0x01;
    I2CMSCR = 0x05;
    __I2C_Wait();
}

I2C_IsrTypeDef I2CIsr;
bit DisplayFlag;
void I2C_ISR_Handler() interrupt I2C_VECTOR
{
    if (I2CSLST & 0x40)
    {
        I2CSLST &= ~0x40;
    }
    else if (I2CSLST & 0x20)
    {
        I2CSLST &= ~0x20;
        if (I2CIsr.isda)
        {
            I2CIsr.isda = 0;
        }
        else if (I2CIsr.isma)
        {
            I2CIsr.isma = 0;
            I2CIsr.addr = I2CRXD;
            I2CTXD = I2C_Buffer[I2CIsr.addr];
        }
        else
        {
            I2C_Buffer[I2CIsr.addr++] = I2CRXD;
        }
    }
    else if (I2CSLST & 0x10)
    {
        I2CSLST &= ~0x10;
        if (I2CSLST & 0x02)
        {
            I2CTXD = 0xff;
        }
        else
        {
            I2CTXD = I2C_Buffer[++I2CIsr.addr];
        }
    }
    else if (I2CSLST & 0x08)
    {
        I2CSLST &= ~0x08;
        I2CIsr.isda = 1;
        I2CIsr.isma = 1;
        DisplayFlag = 1;
    }
}