
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

#if (CACULATE_BUCK_TEMP_AVERAGE_ENABLE || BUCK_DERATE_Temp_HYS)
static S_BuckTmpInfo gs_BuckTmpInfo[MAX_SUPPORT_BUCK_NUM];
#endif

extern sint16 bucktempbuf[2];

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
            bucktempbuf[BuckTmpInfoIndex]=gs_BuckTmpInfo[BuckTmpInfoIndex].BuckCurTemp;
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

    // if (g_MaxTempBetweenAllBuck > BUCK_OVER_TEMP_THREHOLD)
    //     Interface_SetDtcBuckOverTempError(1);
    // else
    //     Interface_SetDtcBuckOverTempError(0);
}
