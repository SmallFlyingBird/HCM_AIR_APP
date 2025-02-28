/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DerateRatioManager_Interface.h"
#include "BuckDerate_Interface.h"
#include "NtcDerate_Interface.h"
#include "OUVDerate_Interface.h"
#include "GeneralFunction.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
/* 目标降额 */
static uint8 DerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};
/* 降额原因 */
static E_Derate_t DerateFor[MAX_CHANNLE_NUM] = {DERA_UN};
/* 当前降额 */
static uint8 DerateCurr[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};

/* Derate to 0 delay timer */
static uint16_t BucksDerate0Hys[MAX_CHANNLE_NUM] = {0,0,0,0,0,0}; /* ms */
static uint16_t NtcsDerate0Hys[MAX_CHANNLE_NUM] = {0,0,0,0,0,0}; /* ms */

#define DER_STEP    (5) /*  */
#define DER_STEPB    (10) /*  */
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint8 Interface_GetChannelDerateRatio(E_ChannelID id)
{
    // static uint8 oncnt=0;
    // if(oncnt<=2)
    // {
    //     oncnt++;
    //     return 0;
    // }
    if ((id) >= MAX_CHANNLE_NUM)
        { return 100; }

    return DerateCurr[id];
}

E_Derate_t Interface_GetChannelDerateFor(E_ChannelID id)
{
    if ((id) >= MAX_CHANNLE_NUM)
    { return DERA_UN; }

    return DerateFor[id];
}

/*
 * 建议每隔100ms执行一次这个函数
 * 此函数会根据NTC和Buck计算出来的降流比例，计算出最终的降流比例
 */
uint8 Derate_Reason_data=0;//////////////////////////////////////
uint8 Derate_Reason_pwm=0;////////////////////////////////////////////
void DerateRatioManagerFuncmain(uint8 timebase)
{
    E_ChannelID ch;
    uint8 ratio_ouv=100;
    uint8 chratio;
    uint8 derate[MAX_CHANNLE_NUM];
    E_Derate_t derfor[MAX_CHANNLE_NUM];
    
    struct {
    uint8 enaECU  :1;
    uint8 enaLED  :1;
    uint8 enaAMB  :1;
    uint8 enaOUV  :1;
    } EnaDer = {1,1,0,1};   /* 默认全部使能 */

    for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
    { 
        derate[ch] = 100; 
        derfor[ch] = DERA_UN; 
    }
//电源降额
    if (EnaDer.enaOUV)
    { 
        ratio_ouv = Interface_GetDerateRatioOfOUV();
    }
    else
    { 
        ratio_ouv = 100; 
    }

    for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
    {
//NTC降额
        // if (EnaDer.enaLED)
        // { 
        //     chratio = Interface_GetChannelDerateRatioOfNtc(ch); 
        // }
        // else
        // {
        //     chratio = 100; 
        // }

        // /* NTC降额到0, 至少保持5S */
        // if ((chratio == 0) && (NtcsDerate0Hys[ch] == 0)) 
        // { 
        //     NtcsDerate0Hys[ch] = 5000; 
        // }
        // if (NtcsDerate0Hys[ch] > 0) 
        // {
        //     chratio = 0; 
        // }
        // NtcsDerate0Hys[ch] = C_SubToMin_U16(NtcsDerate0Hys[ch], timebase);//降到0的时间减timebase

        // if (chratio < derate[ch])
        // {
        //     derate[ch] = chratio;
        //     derfor[ch] = DERA_LED;
        // }
//BUCK降额
        if (EnaDer.enaECU)
        { 
            chratio = Interface_GetChannelDerateRatioOfBuckTemp(ch); 
        }
        else
        {
            chratio = 100; 
        }
        
        /* LBkink最低降到55% */
        if ((ch == ChannelID1) && (chratio < 55))
        { 
            chratio = 55; 
        }
        /* BUCK降额到0, 至少保持5S */
        if ((chratio == 0) && (BucksDerate0Hys[ch] == 0)) 
        { 
            BucksDerate0Hys[ch] = 5000; 
        }
        if (BucksDerate0Hys[ch] > 0) 
        { 
            chratio = 0; 
        }
        BucksDerate0Hys[ch] = C_SubToMin_U16(BucksDerate0Hys[ch], timebase);

        if (chratio < derate[ch])
        {
            derate[ch] = chratio;
            derfor[ch] = DERA_ECU;
        }

        /* OUV Derate */
        if (ratio_ouv < derate[ch])
        {
            derate[ch] = ratio_ouv; 
            derfor[ch] = DERA_OUV;
        }
    }

    for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
    {
        sint8_t ss;
        DerateRatio[ch] = derate[ch];
        DerateFor[ch]   = derfor[ch];

        if (DerateCurr[ch] > DerateRatio[ch])//当前降额>目标降额
        {
            ss = DerateCurr[ch] - DerateRatio[ch];
            if (ss > DER_STEPB) 
            { 
                DerateCurr[ch] -= DER_STEPB; 
            }
            else if (ss > DER_STEP) 
            { 
                DerateCurr[ch] -= DER_STEP; 
            }
            Derate_Reason_data=DerateFor[ch];
            Derate_Reason_pwm=DerateCurr[ch];
            // else               
            // {
            //     DerateCurr[ch] = DerateRatio[ch]; 
            // }
        }
        if (DerateCurr[ch] < DerateRatio[ch])
        {
            ss = DerateRatio[ch] - DerateCurr[ch];
            if (ss > DER_STEPB) 
            { 
                DerateCurr[ch] += DER_STEPB; 
            }
            else if (ss > DER_STEP) 
            { 
                DerateCurr[ch] += DER_STEP; 
            }
            Derate_Reason_data=DerateFor[ch];
            Derate_Reason_pwm=DerateCurr[ch];
            // else               
            // { 
            //     DerateCurr[ch] = DerateRatio[ch]; 
            // }
        }
    }
}



uint8 Derate_Reason (void)
{
    return Derate_Reason_data;
}

uint8 Derate_PWM (void)
{
    return Derate_Reason_pwm;
}











