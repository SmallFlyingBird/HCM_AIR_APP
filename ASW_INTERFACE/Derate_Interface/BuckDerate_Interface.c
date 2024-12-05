
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
static uint8_t BuckDerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100,
                                                   100, 100, 100, 100, 100, 100};
static sint16 g_MaxTempBetweenAllBuck = 10;

#if (CACULATE_BUCK_TEMP_AVERAGE_ENABLE || BUCK_DERATE_Temp_HYS)
static S_BuckTmpInfo gs_BuckTmpInfo[MAX_SUPPORT_BUCK_NUM];
#endif

#if BUCK_DERATE_Temp_HYS
#endif

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
static void CaculateBuckDerateRatio(sint16 tmp, E_BuckNo BuckNo)
{
    uint8 DerateRatio = 100;
    sint16 perHigh, perLow, tempHigh, templow;
    uint16_t channelmask;
    E_ChannelID chid;
    E_ChannelID i;
    uint16_t LightFuncMask = 0;
    Light_Functions LF;
    uint16_t chmask = 0;

    if (tmp <= BuckDerateTemp1)
        DerateRatio = BuckDerateRatio1;
    else if (tmp <= BuckDerateTemp2)
    {
        perHigh = BuckDerateRatio1;
        perLow = BuckDerateRatio2;
        tempHigh = BuckDerateTemp2;
        templow = BuckDerateTemp1;
        DerateRatio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else if (tmp <= BuckDerateTemp3)
    {
        perHigh = BuckDerateRatio2;
        perLow = BuckDerateRatio3;
        tempHigh = BuckDerateTemp3;
        templow = BuckDerateTemp2;
        DerateRatio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else if (tmp <= BuckDerateTemp4)
    {
        perHigh = BuckDerateRatio3;
        perLow = BuckDerateRatio4;
        tempHigh = BuckDerateTemp4;
        templow = BuckDerateTemp3;
        DerateRatio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else if (tmp <= BuckDerateTemp5)
    {
        perHigh = BuckDerateRatio4;
        perLow = BuckDerateRatio5;
        tempHigh = BuckDerateTemp5;
        templow = BuckDerateTemp4;
        DerateRatio = (uint8_t)(((perHigh - perLow)) * ((tempHigh - tmp)) / ((tempHigh - templow)) + perLow);
    }
    else
    {
        DerateRatio = 0;
    }

    if (Interface_GetBuckChannelMask(BuckNo, &channelmask) == E_OK)
    {
        for (chid = ChannelID1; chid <= ChannelID4; chid++)
        {
            if ((channelmask & (1 << chid)) != 0)
            {
                BuckDerateRatio[chid] = DerateRatio;
            }
            else
            {
                continue;
            }

            /*计算这个所对应的功能，并且设置这个功能所对应的其余通道的降流比率*/

            /*找到这个通道对应灯具功能的掩码*/
            LightFuncMask = GetLightFunctionsMaskByChNo(chid);
            for (LF = E_LowBeamFlat; LF <= E_AssistantLight; LF++)
            {
                if ((LightFuncMask & (1 << LF)) == 0)
                    continue;
                /*找到这个功能对应的所有通道掩码*/
                chmask = GetChannelMaskByLightFunction(LF);

                for (i = ChannelID1; i <= ChannelID4; i++)
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
    if (id > ChannelID4)
        return 100;

    return BuckDerateRatio[id];
}

extern sint16 tempbuf[2];
void BuckDerateMainFunction(uint8_t timebase)
{
    E_BuckNo BuckNo = E_BuckNo1;
    int16_t tmp;
    int16_t MaxTmpOfAllBuck = 10;
#if (CACULATE_BUCK_TEMP_AVERAGE_ENABLE || BUCK_DERATE_Temp_HYS)
    uint8_t BuckTmpInfoIndex;
    uint8_t BuckTmpDataIndex;
    uint8_t TempHy;
#endif
    for (BuckNo = E_BuckNo1; BuckNo <= E_BuckNo2; BuckNo++)
    {
        if (Interface_GetBuckTempterature(BuckNo, &tmp) == E_NOT_OK)
        {
            continue;
        }

#if (CACULATE_BUCK_TEMP_AVERAGE_ENABLE)
        BuckTmpInfoIndex = BuckNo - E_BuckNo1;
        BuckTmpDataIndex = gs_BuckTmpInfo[BuckTmpInfoIndex].BuckDataIndex;
        gs_BuckTmpInfo[BuckTmpInfoIndex].BuckTempData[BuckTmpDataIndex] = tmp;
        gs_BuckTmpInfo[BuckTmpInfoIndex].BuckDataIndex++;
        if (gs_BuckTmpInfo[BuckTmpInfoIndex].BuckDataIndex >= BUCKTEMP_DATABUFFER_SIZE)
        {
            gs_BuckTmpInfo[BuckTmpInfoIndex].BuckDataIndex = 0;
            gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp = CalArrayAverageValue_Sint16(gs_BuckTmpInfo[BuckTmpInfoIndex].BuckTempData, BUCKTEMP_DATABUFFER_SIZE);
            gs_BuckTmpInfo[BuckTmpInfoIndex].DataFirstCalcuComplete = 1;
            tempbuf[BuckTmpInfoIndex]=gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp;
        }
#endif
#if BUCK_DERATE_Temp_HYS
        BuckTmpInfoIndex = BuckNo - E_BuckNo1;
        if (gs_BuckTmpInfo[BuckTmpInfoIndex].DataFirstCalcuComplete == 0)
        {
#if CACULATE_BUCK_TEMP_AVERAGE_ENABLE
            continue;
#else
            gs_BuckTmpInfo[BuckTmpInfoIndex].DataFirstCalcuComplete = 1;
            gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp = tmp;
#endif
        }
        else
        {
            if (tmp > gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp)
                TempHy = (uint8_t)(tmp - gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp);
            else
                TempHy = (uint8_t)(gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp - tmp);

            if (TempHy > BUCK_DERATE_Temp_HYS)
            {
                gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp = tmp;
            }
            else
            {
                continue;
            }
        }
#endif

#if (CACULATE_BUCK_TEMP_AVERAGE_ENABLE || BUCK_DERATE_Temp_HYS)
        if (gs_BuckTmpInfo[BuckTmpInfoIndex].DataFirstCalcuComplete == 1)
        {
            if (gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp > MaxTmpOfAllBuck)
                MaxTmpOfAllBuck = gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp;

            CaculateBuckDerateRatio(gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp, BuckNo);
        }
#else
        if (tmp > MaxTmpOfAllBuck)
            MaxTmpOfAllBuck = tmp;
        CaculateBuckDerateRatio(tmp, BuckNo);
#endif
    }

    g_MaxTempBetweenAllBuck = MaxTmpOfAllBuck;

    if (g_MaxTempBetweenAllBuck > BUCK_OVER_TEMP_THREHOLD)
        Interface_SetDtcBuckOverTempError(1);
    else
        Interface_SetDtcBuckOverTempError(0);
}
