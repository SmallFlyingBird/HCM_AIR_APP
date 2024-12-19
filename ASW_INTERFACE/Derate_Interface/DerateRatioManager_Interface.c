/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DerateRatioManager_Interface.h"
#include "BuckDerate_Interface.h"
#include "NtcDerate_Interface.h"
#include "OUVDerate_Interface.h"
#include "LossDerate_Interface.h"
#include "GeneralFunction.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
/* 目标降额 */
static uint8_t DerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};
/* 降额原因 */
static E_Derate_t DerateFor[MAX_CHANNLE_NUM] = {DERA_UN};
/* 当前降额 */
static uint8_t DerateCurr[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};

/* Derate to 0 delay timer */
static uint16_t BucksDerate0Hys[MAX_CHANNLE_NUM] = {0,0,0,0,0,0}; /* ms */
static uint16_t NtcsDerate0Hys[MAX_CHANNLE_NUM] = {0,0,0,0,0,0}; /* ms */

#define DER_STEP    (5) /*  */
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatio(E_ChannelID id)
{
    if (((int)id) >= MAX_CHANNLE_NUM)
    { return 100; }

    return DerateCurr[(int)id];
}

E_Derate_t Interface_GetChannelDerateFor(E_ChannelID id)
{
    if (((int)id) >= MAX_CHANNLE_NUM)
    { return DERA_UN; }

    return DerateFor[(int)id];
}

/*
 * 建议每隔100ms执行一次这个函数
 * 此函数会根据NTC和Buck计算出来的降流比例，计算出最终的降流比例
 */
void DerateRatioManagerFuncmain(uint8_t timebase)
{
    E_ChannelID chid;
    uint8_t chratio1, chratio2;
    uint8_t chratio;
    uint8_t    derate[MAX_CHANNLE_NUM];
    E_Derate_t derfor[MAX_CHANNLE_NUM];
    

    struct {
    uint8_t enaECU  :1;
    uint8_t enaLED  :1;
    // uint8_t enaAMB  :1; //不用环境温度降流
    uint8_t enaOUV  :1;
    uint8_t enaLOS  :1;
    uint8_t enaRes  :3;
    } enaDer = {1,1,1,1,0};   /* 默认全部使能 */

    /*  */
    for (chid = ChannelID1; chid <= ChannelID4; chid++)
    { derate[(int)chid] = 100; derfor[(int)chid] = DERA_UN; }

     chratio1 = 100; 

    if (enaDer.enaOUV)
    { chratio2 = Interface_GetDerateRatioOfOUV(); }
    else
    { chratio2 = 100; }

    for (chid = ChannelID1; chid <= ChannelID4; chid++)
    {
         /* NTC Derate */
        if (enaDer.enaLED)
        { chratio = Interface_GetChannelDerateRatioOfNtc(chid); }
        else
        { chratio = 100; }

        /* NTC降额到0, 至少保持5S */
        if ((chratio == 0) && (NtcsDerate0Hys[chid] == 0)) { NtcsDerate0Hys[chid] = 5000; }
        if (NtcsDerate0Hys[chid] > 0) { chratio = 0; }
        NtcsDerate0Hys[chid] = C_SubToMin_U16(NtcsDerate0Hys[chid], timebase);

        if (chratio < derate[chid])
        {
            derate[chid] = chratio;
            derfor[chid] = DERA_LED;
        }

        if (enaDer.enaECU)
        { chratio = Interface_GetChannelDerateRatioOfBuckTemp(chid); }
        else
        { chratio = 100; }

        /* LBkink最低降到55% */
        if ((chid == ChannelID1) && (chratio < 55))
        { chratio = 55; }
        /* BUCK降额到0, 至少保持5S */
        if ((chratio == 0) && (BucksDerate0Hys[chid] == 0)) { BucksDerate0Hys[chid] = 5000; }
        if (BucksDerate0Hys[chid] > 0) { chratio = 0; }
        BucksDerate0Hys[chid] = C_SubToMin_U16(BucksDerate0Hys[chid], timebase);

        if (chratio < derate[chid])
        {
            derate[chid] = chratio;
            derfor[chid] = DERA_ECU;
        }

        if (enaDer.enaLOS)
        { chratio = Interface_GetChannelDerateRatioOfLoss(chid); }
        else
        { chratio = 100; }
            
        if (chratio < derate[chid])
        {
            derate[chid] = chratio;
            derfor[chid] = DERA_LOS;
        }


        /* OUV Derate */
        if (chratio2 < derate[chid])
        {
            if (chratio2 > 0)   /* OUV降额到0，移到LM模块中，直接禁止通道输出，不反馈故障 */
            { derate[chid] = chratio2; }

            derfor[chid] = DERA_OUV;
        }

    }

    for (chid = ChannelID1; chid <= ChannelID4; chid++)
    {
        sint8_t ss;

        DerateRatio[(int)chid] = derate[(int)chid];
        DerateFor[(int)chid]   = derfor[(int)chid];

        /**/
        if (DerateCurr[(int)chid] > DerateRatio[(int)chid])
        {
            ss = DerateCurr[(int)chid] - DerateRatio[(int)chid];
            if (ss > DER_STEP) { DerateCurr[(int)chid] -= DER_STEP; }
            else               { DerateCurr[(int)chid] = DerateRatio[(int)chid]; }
        }
        if (DerateCurr[(int)chid] < DerateRatio[(int)chid])
        {
            ss = DerateRatio[(int)chid] - DerateCurr[(int)chid];
            if (ss > DER_STEP) { DerateCurr[(int)chid] += DER_STEP; }
            else               { DerateCurr[(int)chid] = DerateRatio[(int)chid]; }
        }
    }
}
