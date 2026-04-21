#include "LCD_Seg.h"

// u8 code __LCD_REG_ADDR_LOOKUP[] = {0x90, 0x91, 0x92, 0x93, 0x94, 0x98, 0x99,
//                                    0x9A, 0x9B, 0x9C, 0xA0, 0xA1, 0xA2, 0xA3,
//                                    0xA4, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC};

#define LCD_ADDR_H 0xFB00

#define __2D_ADDR__ 0x92
#define __S10_ADDR__ 0x90
#define __3D_ADDR__ 0x90
#define __S7_ADDR__ 0x90
#define __1E_ADDR__ 0x90
#define __1D_ADDR__ 0x92
#define __R14_ADDR__ 0x92
#define __R4_ADDR__ 0x91
#define __R11_ADDR__ 0x91
#define __R13_ADDR__ 0x93
#define __5A_ADDR__ 0x94
#define __R12_ADDR__ 0x94
#define __4A_ADDR__ 0x94
#define __6D_ADDR__ 0x94
#define __6C_ADDR__ 0x93
#define __7D_ADDR__ 0x93
#define __R17_ADDR__ 0x93
#define __8D_ADDR__ 0x93
#define __R16_ADDR__ 0x93
#define __S1_ADDR__ 0x93
#define __S12_ADDR__ 0x93
#define __S6_ADDR__ 0x92
#define __2E_ADDR__ 0x9A
#define __2C_ADDR__ 0x98
#define __3E_ADDR__ 0x98
#define __3C_ADDR__ 0x98
#define __1G_ADDR__ 0x98
#define __1C_ADDR__ 0x9A
#define __R3_ADDR__ 0x9A
#define __R5_ADDR__ 0x99
#define __R10_ADDR__ 0x99
#define __5B_ADDR__ 0x9B
#define __5F_ADDR__ 0x9C
#define __4B_ADDR__ 0x9C
#define __4F_ADDR__ 0x9C
#define __6E_ADDR__ 0x9C
#define __6G_ADDR__ 0x9B
#define __7E_ADDR__ 0x9B
#define __7C_ADDR__ 0x9B
#define __8E_ADDR__ 0x9B
#define __8C_ADDR__ 0x9B
#define __S2_ADDR__ 0x9B
#define __S11_ADDR__ 0x9A
#define __2F_ADDR__ 0xA2
#define __2G_ADDR__ 0xA0
#define __3F_ADDR__ 0xA0
#define __3G_ADDR__ 0xA0
#define __1F_ADDR__ 0xA0
#define __1B_ADDR__ 0xA2
#define __R2_ADDR__ 0xA2
#define __R6_ADDR__ 0xA1
#define __R9_ADDR__ 0xA1
#define __5G_ADDR__ 0xA3
#define __5E_ADDR__ 0xA4
#define __4G_ADDR__ 0xA4
#define __4E_ADDR__ 0xA4
#define __6F_ADDR__ 0xA4
#define __6B_ADDR__ 0xA3
#define __7F_ADDR__ 0xA3
#define __7G_ADDR__ 0xA3
#define __8F_ADDR__ 0xA3
#define __8G_ADDR__ 0xA3
#define __S3_ADDR__ 0xA3
#define __S5_ADDR__ 0xA3
#define __S8_ADDR__ 0xA2
#define __2A_ADDR__ 0xAA
#define __2B_ADDR__ 0xA8
#define __3A_ADDR__ 0xA8
#define __3B_ADDR__ 0xA8
#define __OBC_ADDR__ 0xA8
#define __1A_ADDR__ 0xAA
#define __R1_ADDR__ 0xAA
#define __R7_ADDR__ 0xA9
#define __R8_ADDR__ 0xA9
#define __5C_ADDR__ 0xAB
#define __5D_ADDR__ 0xAC
#define __4C_ADDR__ 0xAC
#define __4D_ADDR__ 0xAC
#define __6A_ADDR__ 0xAC
#define __R15_ADDR__ 0xAB
#define __7A_ADDR__ 0xAB
#define __7B_ADDR__ 0xAB
#define __8A_ADDR__ 0xAB
#define __8B_ADDR__ 0xAB
#define __S4_ADDR__ 0xAB
#define __R18_ADDR__ 0xAB
#define __S9_ADDR__ 0xAA

#define __2D_BIT__ 5
#define __S10_BIT__ 3
#define __3D_BIT__ 2
#define __S7_BIT__ 1
#define __1E_BIT__ 0
#define __1D_BIT__ 2
#define __R14_BIT__ 1
#define __R4_BIT__ 5
#define __R11_BIT__ 4
#define __R13_BIT__ 7
#define __5A_BIT__ 3
#define __R12_BIT__ 2
#define __4A_BIT__ 1
#define __6D_BIT__ 0
#define __6C_BIT__ 6
#define __7D_BIT__ 5
#define __R17_BIT__ 4
#define __8D_BIT__ 3
#define __R16_BIT__ 2
#define __S1_BIT__ 1
#define __S12_BIT__ 0
#define __S6_BIT__ 7
#define __2E_BIT__ 5
#define __2C_BIT__ 3
#define __3E_BIT__ 2
#define __3C_BIT__ 1
#define __1G_BIT__ 0
#define __1C_BIT__ 2
#define __R3_BIT__ 1
#define __R5_BIT__ 5
#define __R10_BIT__ 4
#define __5B_BIT__ 7
#define __5F_BIT__ 3
#define __4B_BIT__ 2
#define __4F_BIT__ 1
#define __6E_BIT__ 0
#define __6G_BIT__ 6
#define __7E_BIT__ 5
#define __7C_BIT__ 4
#define __8E_BIT__ 3
#define __8C_BIT__ 2
#define __S2_BIT__ 1
#define __S11_BIT__ 7
#define __2F_BIT__ 5
#define __2G_BIT__ 3
#define __3F_BIT__ 2
#define __3G_BIT__ 1
#define __1F_BIT__ 0
#define __1B_BIT__ 2
#define __R2_BIT__ 1
#define __R6_BIT__ 5
#define __R9_BIT__ 4
#define __5G_BIT__ 7
#define __5E_BIT__ 3
#define __4G_BIT__ 2
#define __4E_BIT__ 1
#define __6F_BIT__ 0
#define __6B_BIT__ 6
#define __7F_BIT__ 5
#define __7G_BIT__ 4
#define __8F_BIT__ 3
#define __8G_BIT__ 2
#define __S3_BIT__ 1
#define __S5_BIT__ 0
#define __S8_BIT__ 7
#define __2A_BIT__ 5
#define __2B_BIT__ 3
#define __3A_BIT__ 2
#define __3B_BIT__ 1
#define __OBC_BIT__ 0
#define __1A_BIT__ 2
#define __R1_BIT__ 1
#define __R7_BIT__ 5
#define __R8_BIT__ 4
#define __5C_BIT__ 7
#define __5D_BIT__ 3
#define __4C_BIT__ 2
#define __4D_BIT__ 1
#define __6A_BIT__ 0
#define __R15_BIT__ 6
#define __7A_BIT__ 5
#define __7B_BIT__ 4
#define __8A_BIT__ 3
#define __8B_BIT__ 2
#define __S4_BIT__ 1
#define __R18_BIT__ 0
#define __S9_BIT__ 7

// clang-format off
//      21  3   2   1   0   18  17  13  12  31  35  34  33  32  30  29  28  27  26  25  24  23
// COM0	2D	S10	3D	S7	1E	1D	R14	R4	R11	R13	5A	R12	4A	6D	6C	7D	R17	8D	R16	S1	S12	S6
// COM1	2E	2C	3E	3C	1G	1C	R3	R5	R10	5B	5F	4B	4F	6E	6G	7E	7C	8E	8C	S2	-	S11
// COM2	2F	2G	3F	3G	1F	1B	R2	R6	R9	5G	5E	4G	4E	6F	6B	7F	7G	8F	8G	S3	S5	S8
// COM3	2A	2B	3A	3B	OBC	1A	R1	R7	R8	5C	5D	4C	4D	6A	R15	7A	7B	8A	8B	S4	R18	S9
// clang-format on

void __LCD_SET_SEG(u8 addr, u8 bitPos, bit setVal)
{
    if (setVal)
    {
        (*(unsigned char volatile xdata*)((u16)LCD_ADDR_H | addr)) |=
            (1 << bitPos);
    }
    else
    {
        (*(unsigned char volatile xdata*)((u16)LCD_ADDR_H | addr)) &=
            ~(1 << bitPos);
    }
}

void LCD_Config()
{
    /**
     * LCDCFG CKSEL[7] VRLPSEL[3, not used] VLCDSEL[2:0]
     * CKSEL: 0 cpu clock, 1 external 32kHz
     * VLCDSEL: 111 for 1.0 * VCC
     */
    LCDCFG = 0x07;

    /**
     * LCDCFG2[3:0] pin mux for COM0-COM3
     * LCDCFG2[3]: SEG3PS, 0 for P1.2, 1 for P7.4
     * LCDCFG2[2]: SEG2PS, 0 for P1.3, 1 for P7.5
     * LCDCFG2[1]: SEG1PS, 0 for P1.4, 1 for P7.6
     * LCDCFG2[0]: SEG0PS, 0 for P1.5, 1 for P7.7
     */
    LCDCFG2 = 0x0f;

    /**
     * LCD REFRESH RATE = f(CLK)/(DBLEN[2:0] + COMLEN[19:0] + 1) * NUM_OF_COM
     * DBLEN = 2
     * COMLEN = 0x00c34d = 5005
     * NUM_OF_COM = 22
     */
    DBLEN = 0x02;
    COMLENH = 0x00;
    COMLENM = 0xc3;
    COMLENL = 0x4d;

    /*FLICKER RATE 60Hz*/
    BLINKRATE = 60;

    /* Enable LCD COMs and SEGs */
    COMON = 0x0f;
    SEGON1 = 0x0f;
    SEGON2 = 0x30;
    SEGON3 = 0xa6;
    SEGON4 = 0xff;
    SEGON5 = 0x0f;

    /**
     * LCDCR ACTMODE[1:0]
     * 00: Normal mode
     * 01: Always on mode
     * 10: Always off mode
     * 11: Blinking mode
     *
     * LCDCR[0] is the ENABLE bit
     */
    LCDCR = 0x01;  // Enable LCD

    GPIO_Config(GPIO_P6, GPIO_Pin_0, GPIO_OUT_PP);
}

u8 code __LCD_DT_NUM_LOOKUP[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,
                                 0x7d, 0x07, 0x7f, 0x6f, 0x00};

u8 code __LCD_DT_ADDR_LOOKUP[8][7][2] = {
    {
        {__1A_ADDR__, __1A_BIT__},
        {__1B_ADDR__, __1B_BIT__},
        {__1C_ADDR__, __1C_BIT__},
        {__1D_ADDR__, __1D_BIT__},
        {__1E_ADDR__, __1E_BIT__},
        {__1F_ADDR__, __1F_BIT__},
        {__1G_ADDR__, __1G_BIT__},
    },
    {{__2A_ADDR__, __2A_BIT__},
     {__2B_ADDR__, __2B_BIT__},
     {__2C_ADDR__, __2C_BIT__},
     {__2D_ADDR__, __2D_BIT__},
     {__2E_ADDR__, __2E_BIT__},
     {__2F_ADDR__, __2F_BIT__},
     {__2G_ADDR__, __2G_BIT__}},
    {{__3A_ADDR__, __3A_BIT__},
     {__3B_ADDR__, __3B_BIT__},
     {__3C_ADDR__, __3C_BIT__},
     {__3D_ADDR__, __3D_BIT__},
     {__3E_ADDR__, __3E_BIT__},
     {__3F_ADDR__, __3F_BIT__},
     {__3G_ADDR__, __3G_BIT__}},
    {{__4A_ADDR__, __4A_BIT__},
     {__4B_ADDR__, __4B_BIT__},
     {__4C_ADDR__, __4C_BIT__},
     {__4D_ADDR__, __4D_BIT__},
     {__4E_ADDR__, __4E_BIT__},
     {__4F_ADDR__, __4F_BIT__},
     {__4G_ADDR__, __4G_BIT__}},
    {{__5A_ADDR__, __5A_BIT__},
     {__5B_ADDR__, __5B_BIT__},
     {__5C_ADDR__, __5C_BIT__},
     {__5D_ADDR__, __5D_BIT__},
     {__5E_ADDR__, __5E_BIT__},
     {__5F_ADDR__, __5F_BIT__},
     {__5G_ADDR__, __5G_BIT__}},
    {{__6A_ADDR__, __6A_BIT__},
     {__6B_ADDR__, __6B_BIT__},
     {__6C_ADDR__, __6C_BIT__},
     {__6D_ADDR__, __6D_BIT__},
     {__6E_ADDR__, __6E_BIT__},
     {__6F_ADDR__, __6F_BIT__},
     {__6G_ADDR__, __6G_BIT__}},
    {{__7A_ADDR__, __7A_BIT__},
     {__7B_ADDR__, __7B_BIT__},
     {__7C_ADDR__, __7C_BIT__},
     {__7D_ADDR__, __7D_BIT__},
     {__7E_ADDR__, __7E_BIT__},
     {__7F_ADDR__, __7F_BIT__},
     {__7G_ADDR__, __7G_BIT__}},
    {{__8A_ADDR__, __8A_BIT__},
     {__8B_ADDR__, __8B_BIT__},
     {__8C_ADDR__, __8C_BIT__},
     {__8D_ADDR__, __8D_BIT__},
     {__8E_ADDR__, __8E_BIT__},
     {__8F_ADDR__, __8F_BIT__},
     {__8G_ADDR__, __8G_BIT__}},
};

void LCD_SetDT(u8 tubeIndex, u8 num)
{
    if (tubeIndex < 1 || tubeIndex > 8)
        return;
    else
    {
        u8 segments = __LCD_DT_NUM_LOOKUP[num > 10 ? 8 : num];
        u8 i;
        for (i = 0; i < 7; i++)
        {
            __LCD_SET_SEG(__LCD_DT_ADDR_LOOKUP[tubeIndex - 1][i][0],
                          __LCD_DT_ADDR_LOOKUP[tubeIndex - 1][i][1],
                          (segments >> i) & 0x01);
        }
    }
}

void LCD_SetHour(bit enable, u8 hour)
{
    if (!enable)
    {
        __LCD_SET_SEG(__R1_ADDR__, __R1_BIT__, LOW);
        __LCD_SET_SEG(__OBC_ADDR__, __OBC_BIT__, LOW);
        LCD_SetDT(1, 10);
        return;
    }
    else
    {
        __LCD_SET_SEG(__R1_ADDR__, __R1_BIT__, HIGH);
        __LCD_SET_SEG(__OBC_ADDR__, __OBC_BIT__,
                      ((hour / 10) > 0) ? HIGH : LOW);
        LCD_SetDT(1, hour % 10);
    }
}

void LCD_Set_T_Sign(bit on) { __LCD_SET_SEG(__R2_ADDR__, __R2_BIT__, on); }

void LCD_SetLockSign(bit on) { __LCD_SET_SEG(__R3_ADDR__, __R3_BIT__, on); }

void LCD_SetNetSign(bit on) { __LCD_SET_SEG(__R4_ADDR__, __R4_BIT__, on); }

void LCD_SetLeafSign(bit on) { __LCD_SET_SEG(__R5_ADDR__, __R5_BIT__, on); }

void LCD_SetHouseLeafSign(bit on)
{
    __LCD_SET_SEG(__R6_ADDR__, __R6_BIT__, on);
}

void LCD_Set_A_Sign(bit on) { __LCD_SET_SEG(__R7_ADDR__, __R7_BIT__, on); }

void LCD_Set_M_Sign(bit on) { __LCD_SET_SEG(__R8_ADDR__, __R8_BIT__, on); }

void LCD_SetHouseWindSign(bit on)
{
    __LCD_SET_SEG(__R9_ADDR__, __R9_BIT__, on);
}

void LCD_SetSunSign(bit on) { __LCD_SET_SEG(__R10_ADDR__, __R10_BIT__, on); }
void LCD_SetSnowSign(bit on) { __LCD_SET_SEG(__R11_ADDR__, __R11_BIT__, on); }
void LCD_SetSignalSign(bit on) { __LCD_SET_SEG(__R12_ADDR__, __R12_BIT__, on); }
void LCD_SetHumidity(bit enable, float humidity, bit showSign)
{
    __LCD_SET_SEG(__R13_ADDR__, __R13_BIT__, showSign);
    if (!enable)
    {
        __LCD_SET_SEG(__R13_ADDR__, __R13_BIT__, LOW);
        LCD_SetDT(4, 10);
        LCD_SetDT(5, 10);
        return;
    }
    else
    {
        u8 humInt = (u8)humidity;
        LCD_SetDT(4, humInt / 10);
        LCD_SetDT(5, humInt % 10);
    }
}
void LCD_SetTemperature(bit enable, float temperature, bit showSign)
{
    __LCD_SET_SEG(__R14_ADDR__, __R14_BIT__, showSign);
    if (!enable)
    {
        __LCD_SET_SEG(__R14_ADDR__, __R14_BIT__, LOW);
        LCD_SetDT(2, 10);
        LCD_SetDT(3, 10);
        return;
    }
    else
    {
        u8 tempInt = (u8)temperature;
        LCD_SetDT(2, tempInt / 10);
        LCD_SetDT(3, tempInt % 10);
    }
}
void LCD_Set_PM25_Sign(bit on) { __LCD_SET_SEG(__R16_ADDR__, __R16_BIT__, on); }
void LCD_Set485Sign(bit on) { __LCD_SET_SEG(__R17_ADDR__, __R17_BIT__, on); }

void LCD_SetSettingTemp(bit enable, float temperature, bit showSign)
{
    __LCD_SET_SEG(__R15_ADDR__, __R15_BIT__, showSign);
    if (!enable)
    {
        __LCD_SET_SEG(__R15_ADDR__, __R15_BIT__, LOW);
        LCD_SetDT(6, 10);
        LCD_SetDT(7, 10);
        LCD_SetDT(8, 10);
        return;
    }
    else
    {
        u16 tempInt = (u16)temperature;
        LCD_SetDT(6, tempInt / 100);
        LCD_SetDT(7, (tempInt / 10) % 10);
        LCD_SetDT(8, tempInt % 10);
    }
}

void LCD_SetSettingSign(bit on)
{
    __LCD_SET_SEG(__R18_ADDR__, __R18_BIT__, on);
}
void LCD_SetFanLevel(int8 level)
{
    if (level > 5 || level < 0)
    {
        __LCD_SET_SEG(__S12_ADDR__, __S12_BIT__, LOW);
        __LCD_SET_SEG(__S1_ADDR__, __S1_BIT__, LOW);
        __LCD_SET_SEG(__S2_ADDR__, __S2_BIT__, LOW);
        __LCD_SET_SEG(__S3_ADDR__, __S3_BIT__, LOW);
        __LCD_SET_SEG(__S4_ADDR__, __S4_BIT__, LOW);
        __LCD_SET_SEG(__S5_ADDR__, __S5_BIT__, LOW);
        __LCD_SET_SEG(__S6_ADDR__, __S6_BIT__, LOW);
        __LCD_SET_SEG(__S8_ADDR__, __S8_BIT__, LOW);
        __LCD_SET_SEG(__S9_ADDR__, __S9_BIT__, LOW);
        __LCD_SET_SEG(__S10_ADDR__, __S10_BIT__, LOW);
        __LCD_SET_SEG(__S11_ADDR__, __S11_BIT__, LOW);
        return;
    }
    else
    {
        __LCD_SET_SEG(__S12_ADDR__, __S12_BIT__, HIGH);
        __LCD_SET_SEG(__S1_ADDR__, __S1_BIT__, level >= 1 ? HIGH : LOW);
        __LCD_SET_SEG(__S2_ADDR__, __S2_BIT__, level >= 2 ? HIGH : LOW);
        __LCD_SET_SEG(__S3_ADDR__, __S3_BIT__, level >= 3 ? HIGH : LOW);
        __LCD_SET_SEG(__S4_ADDR__, __S4_BIT__, level >= 4 ? HIGH : LOW);
        __LCD_SET_SEG(__S5_ADDR__, __S5_BIT__, level >= 5 ? HIGH : LOW);
        __LCD_SET_SEG(__S6_ADDR__, __S6_BIT__, HIGH);
        __LCD_SET_SEG(__S8_ADDR__, __S8_BIT__, HIGH);
        __LCD_SET_SEG(__S9_ADDR__, __S9_BIT__, HIGH);
        __LCD_SET_SEG(__S10_ADDR__, __S10_BIT__, HIGH);
        __LCD_SET_SEG(__S11_ADDR__, __S11_BIT__, HIGH);
    }
}

void LCD_SETBacklight(bit on) { P60 = on; }

void LCD_ALL()
{
    LCD_SetHour(TRUE, 18);
    LCD_Set_T_Sign(TRUE);
    LCD_SetLockSign(TRUE);
    LCD_SetNetSign(TRUE);
    LCD_SetLeafSign(TRUE);
    LCD_SetHouseLeafSign(TRUE);
    LCD_Set_A_Sign(TRUE);
    LCD_Set_M_Sign(TRUE);
    LCD_SetHouseWindSign(TRUE);
    LCD_SetSunSign(TRUE);
    LCD_SetSnowSign(TRUE);
    LCD_SetSignalSign(TRUE);
    LCD_SetHumidity(TRUE, 88, TRUE);
    LCD_SetTemperature(TRUE, 88, TRUE);
    LCD_Set_PM25_Sign(TRUE);
    LCD_Set485Sign(TRUE);
    LCD_SetSettingTemp(TRUE, 888, TRUE);
    LCD_SetSettingSign(TRUE);
    LCD_SetFanLevel(5);
    LCD_SETBacklight(HIGH);
}

void LCD_Clear()
{
    LCD_SetHour(FALSE, 0);
    LCD_Set_T_Sign(FALSE);
    LCD_SetLockSign(FALSE);
    LCD_SetNetSign(FALSE);
    LCD_SetLeafSign(FALSE);
    LCD_SetHouseLeafSign(FALSE);
    LCD_Set_A_Sign(FALSE);
    LCD_Set_M_Sign(FALSE);
    LCD_SetHouseWindSign(FALSE);
    LCD_SetSunSign(FALSE);
    LCD_SetSnowSign(FALSE);
    LCD_SetSignalSign(FALSE);
    LCD_SetHumidity(FALSE, 0, FALSE);
    LCD_SetTemperature(FALSE, 0, FALSE);
    LCD_Set_PM25_Sign(FALSE);
    LCD_Set485Sign(FALSE);
    LCD_SetSettingTemp(FALSE, 0, FALSE);
    LCD_SetSettingSign(FALSE);
    LCD_SetFanLevel(-1);
    LCD_SETBacklight(FALSE);
}