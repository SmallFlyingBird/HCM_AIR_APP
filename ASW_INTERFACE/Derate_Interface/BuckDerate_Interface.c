
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "GeneralFunction.h"
#include "BuckDerate_Interface.h"
#include "Buck_Interface.h"
#include "DTC_Interface.h"
#include "Parameter_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint8_t BuckDerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};
static sint16 g_MaxTempBetweenAllBuck = 10;
static S_BuckTmpInfo gs_BuckTmpInfo[MAX_SUPPORT_BUCK_NUM];
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
//通过BUCK温度计算降额比例
static void CaculateBuckDerateRatio(sint16 tmp, E_BuckNo BuckNo)
{
    uint8 Ratio = 100;
    sint16 perHigh, perLow, tempHigh, templow;
    uint16_t channelmask;
    E_ChannelID chid;
    E_ChannelID i;
    uint16_t LightFuncMask = 0;
    Light_Functions LF;
    uint16_t chmask = 0;

    if (tmp <= BuckDerateTemp1)
        Ratio = BuckDerateRatio1;
    else if (tmp <= BuckDerateTemp2)
    {
        perHigh = BuckDerateRatio1;
        perLow = BuckDerateRatio2;
        tempHigh = BuckDerateTemp2;
        templow = BuckDerateTemp1;
        Ratio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else if (tmp <= BuckDerateTemp3)
    {
        perHigh = BuckDerateRatio2;
        perLow = BuckDerateRatio3;
        tempHigh = BuckDerateTemp3;
        templow = BuckDerateTemp2;
        Ratio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else if (tmp <= BuckDerateTemp4)
    {
        perHigh = BuckDerateRatio3;
        perLow = BuckDerateRatio4;
        tempHigh = BuckDerateTemp4;
        templow = BuckDerateTemp3;
        Ratio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else if (tmp <= BuckDerateTemp5)
    {
        perHigh = BuckDerateRatio4;
        perLow = BuckDerateRatio5;
        tempHigh = BuckDerateTemp5;
        templow = BuckDerateTemp4;
        Ratio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else
    {
        Ratio = 0;
    }

    if (Interface_GetBuckChannelMask(BuckNo, &channelmask) == E_OK)
    {
        for (chid = ChannelID1; chid < CHANNEL_NUM; chid++)
        {
            if ((channelmask & (1 << chid)) != 0)
            {
                BuckDerateRatio[chid] = Ratio;
            }
            else
            {
                continue;
            }

//计算这个所对应的功能，并且设置这个功能所对应的其余通道的降流比率

//找到这个通道对应灯具功能的掩码
            LightFuncMask = GetLightFunctionsMaskByChNo(chid);
            for (LF = E_LowBeamKink; LF <= E_FrontCrossLamp; LF++)
            {
                if ((LightFuncMask & (1 << LF)) == 0)
                    continue;
//找到这个功能对应的所有通道掩码
                chmask = GetChannelMaskByLightFunction(LF);

                for (i = ChannelID1; i < CHANNEL_NUM; i++)
                {
                    if ((chmask & (1 << i)) == 0)
                        continue;
                    if (BuckDerateRatio[i] > BuckDerateRatio[chid])
                        BuckDerateRatio[i] = BuckDerateRatio[chid];
                }
            }
        }
    }
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatioOfBuckTemp(E_ChannelID id)
{
    if (id >= CHANNEL_NUM)
        return 100;

    return BuckDerateRatio[id];
}

void BuckDerateMainFunction(uint8_t timebase)
{
    E_BuckNo BuckNo = E_BuckNo1;
    int16_t tmp;
    int16_t MaxTmpOfAllBuck = 10;
    uint8_t BuckTmpDataIndex;
    uint8_t TempHy;
    for (BuckNo = E_BuckNo1; BuckNo <= E_BuckNo2; BuckNo++)
    {
        if (Interface_GetBuckTempterature(BuckNo, &tmp) == E_NOT_OK)
        {
            continue;
        }
        BuckTmpDataIndex = gs_BuckTmpInfo[BuckNo].BuckDataIndex;
        gs_BuckTmpInfo[BuckNo].BuckTempData[BuckTmpDataIndex] = tmp;
        gs_BuckTmpInfo[BuckNo].BuckDataIndex++;
//求均值
        if (gs_BuckTmpInfo[BuckNo].BuckDataIndex >= BUCKTEMP_DATABUFFER_SIZE)
        {
            gs_BuckTmpInfo[BuckNo].BuckDataIndex = 0;
            gs_BuckTmpInfo[BuckNo].BuckCurTemp = CalArrayAverageValue_Sint16(gs_BuckTmpInfo[BuckNo].BuckTempData, BUCKTEMP_DATABUFFER_SIZE);
            gs_BuckTmpInfo[BuckNo].DataFirstCalcuComplete = 1;
        }
//均值获取成功
        if (gs_BuckTmpInfo[BuckNo].DataFirstCalcuComplete == 1)
        {
            if (gs_BuckTmpInfo[BuckNo].BuckCurTemp > MaxTmpOfAllBuck)
                MaxTmpOfAllBuck = gs_BuckTmpInfo[BuckNo].BuckCurTemp;
            CaculateBuckDerateRatio(gs_BuckTmpInfo[BuckNo].BuckCurTemp, BuckNo);
        }
    }

    g_MaxTempBetweenAllBuck = MaxTmpOfAllBuck;

    // if (g_MaxTempBetweenAllBuck > BUCK_OVER_TEMP_THREHOLD)
    //     Interface_SetDtcBuckOverTempError(1);
    // else
    //     Interface_SetDtcBuckOverTempError(0);
}
