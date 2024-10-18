/*
 * Boost_Interface.c
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AswInterfaceManager.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

static S_BoostDrv_Dev *g_S_BoostDrv_Dev_Header = NULL;
#if BOOST_TEMP_USE_NTC
static uint32_t BoostTempAdcBuffer[ADC_BUFFER_SIZE];
static uint32_t BoostTempAdcMean = 0xFFFFFFFF;
/*boost温度采集 热敏电阻阻值表 单位Ω*/
const uint32_t BoostNtcRegTable[BOOST_NTC_SIZE] = {
    5089000,
    3549000,
    2503000,
    1785000,
    1286000,
    935300,
    686900,
    509000,
    380500,
    286800,
    217900,
    166900,
    128700,
    100000,
    78230,
    61600,
    48820,
    38930,
    31230,
    25200,
    20440,
    16670,
    13670,
    11260,
    9325,
    7757,
    6482,
    5440,
    4584,
    3879,
    3295,
    2810,
    2405,
    2066,
};
/*boost温度表 单位℃*/
const sint16_t BoostTempTable[BOOST_NTC_SIZE] = {
    -40,
    -35,
    -30,
    -25,
    -20,
    -15,
    -10,
    -5,
    0,
    5,
    10,
    15,
    20,
    25,
    30,
    35,
    40,
    45,
    50,
    55,
    60,
    65,
    70,
    75,
    80,
    85,
    90,
    95,
    100,
    105,
    110,
    115,
    120,
    125,
};
#endif
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_BoostDrv_Dev *GetBoostDevDrvByBoostNo(E_BoostkNo BoostkNo)
{
    S_BoostDrv_Dev *tmp = g_S_BoostDrv_Dev_Header;

    while (tmp)
    {
        if (tmp->dev_id == BoostkNo)
            return tmp;

        tmp = tmp->ptNext;
    }

    return NULL;
}
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/*boost主函数，主要用于计算boostADC的值*/
void BoostInterfaceMainFunction(uint8_t timebase)
{
    S_BoostDrv_Dev *tmp = g_S_BoostDrv_Dev_Header;
    S_BoostDataPackets BoostDataPackets;
    S_BoostMainFuncDataSrc BoostMainFuncDataSrc;
    S_BoostDiagStateDataSrc BoostDiagStateDataSrc;
    sint16_t BoostTemp;
#if BOOST_TEMP_USE_NTC
    static uint8_t adcbufferondex = 0;
    if (Interface_GetAdcDigitalValue(E_AdcFunction_NTC7, &BoostTempAdcBuffer[adcbufferondex]) == E_OK)
    {
        adcbufferondex++;
        if (adcbufferondex >= ADC_BUFFER_SIZE)
        {
            BoostTempAdcMean = CalArrayAverageValue_Uint32(BoostTempAdcBuffer, ADC_BUFFER_SIZE);
            adcbufferondex = 0;
        }
    }

    if (Interface_GetBoostTemperature(&BoostTemp) == E_OK)
    {
        if (BoostTemp > BOOST_OVER_TEMPERATURE_THRESOLD)
            Interface_SetDtcBoostOverTempError(1);
        else if (BoostTemp < (BOOST_OVER_TEMPERATURE_THRESOLD - BOOST_TEMPERATURE_HYSTERESIS))
            Interface_SetDtcBoostOverTempError(0);
    }
#endif

    while (tmp)
    {
        BoostMainFuncDataSrc.BoostkNo = tmp->dev_id;
        BoostDataPackets.BoostDataTypes = E_BoostDataType_BoostMainFunction;
        BoostDataPackets.datasrc = (void *)(&BoostMainFuncDataSrc);
        tmp->MainFunction((void *)(&BoostDataPackets));

        BoostDiagStateDataSrc.BoostkNo = tmp->dev_id;
        BoostDataPackets.BoostDataTypes = E_BoostDataType_BoostDiagState;
        BoostDataPackets.datasrc = (void *)(&BoostDiagStateDataSrc);
        if ((tmp->Read((void *)(&BoostDataPackets))) == E_OK)
        {
            if (BoostDiagStateDataSrc.BoostDiagState.Bits.LostCom == 1)
            {
                /*设置BoostSpi通信故障*/
                Interface_SetSpiError(E_SpiErrorDevice_Boost, tmp->dev_id);
            }
            else
            {
                /*清除BoostSpi通信故障*/
                Interface_ClearSpiError(E_SpiErrorDevice_Boost, tmp->dev_id);
                if (BoostDiagStateDataSrc.BoostDiagState.Bits.LostCfg == 1)
                {
                    Interface_AddReInitDrvDevice(E_DrvReInitID_Boost);
                }
            }
        }
        tmp = tmp->ptNext;
    }
}

Std_ReturnType Interface_SetBoostOutputVoltage(E_BoostkNo BoostkNo, double voltage)
{
    S_BoostDrv_Dev *tmp;
    S_BoostDataPackets BoostDataPackets;
    S_BoostOutputVoltageDataSrc BoostOutputVoltageDataSrc;
    Std_ReturnType rtval = E_OK;

    tmp = GetBoostDevDrvByBoostNo(BoostkNo);

    if (tmp == NULL)
        return E_NOT_OK;

    BoostOutputVoltageDataSrc.BoostkNo = BoostkNo;
    BoostOutputVoltageDataSrc.Voltage = voltage;

    BoostDataPackets.BoostDataTypes = E_BoostDataType_BoostOutputVoltage;
    BoostDataPackets.datasrc = (void *)(&BoostOutputVoltageDataSrc);

    rtval |= tmp->Write((void *)(&BoostDataPackets));

    return rtval;
}

/*获取Boost温度
 *返回E_NOT_OK：温度还没计算好
 *Ntc阻值计算公式   VADC=5*R/（R+10K）=》   BoostTempAdcMean/ADCWidth = R/(R+10K)
 *=>   R=(10K * BoostTempAdcMean)/(ADCWidth-BoostTempAdcMean)
 *通过NTC计算出来的温度只能-40 to 125°
 */
#if BOOST_TEMP_USE_NTC
Std_ReturnType Interface_GetBoostTemperature(sint16_t *Temp)
#else
Std_ReturnType Interface_GetBoostTemperature(E_BoostkNo BoostkNo, sint16_t *Temp)
#endif
{
#if BOOST_TEMP_USE_NTC
    Std_ReturnType rtval = E_OK;
    E_AdcAccuracy AdcAccuracy;
    uint32_t AdcWidth;
    uint32_t NtcRegval;
    uint8_t i;

    if (BoostTempAdcMean == 0xFFFFFFFF)
        return E_NOT_OK;

    Interface_GetAdcAccuracy(E_AdcFunction_NTC7, &AdcAccuracy);
    AdcWidth = GetAdcWidth(AdcAccuracy);

    NtcRegval = (10000 * BoostTempAdcMean) / (AdcWidth - BoostTempAdcMean);

    for (i = 0; i < (BOOST_NTC_SIZE - 1); i++)
    {
        if (NtcRegval <= BoostNtcRegTable[i] && NtcRegval >= BoostNtcRegTable[i + 1])
            break;
    }

    *Temp = BoostTempTable[(i + 1)];
#else

    S_BoostDrv_Dev *tmp;
    S_BoostDataPackets BoostDataPackets;
    S_BoostTemperatureDataSrc BoostTemperatureDataSrc;
    Std_ReturnType rtval = E_OK;

    tmp = GetBoostDevDrvByBoostNo(BoostkNo);

    if (tmp == NULL)
        return E_NOT_OK;

    BoostTemperatureDataSrc.BoostkNo = BoostkNo;
    BoostDataPackets.BoostDataTypes = E_BoostDataType_BoostTemperature;
    BoostDataPackets.datasrc = (void *)(&BoostTemperatureDataSrc);

    rtval |= tmp->Read((void *)(&BoostDataPackets));
#endif
    return rtval;
}
Std_ReturnType Interface_BoostInit(uint8_t InitVoltage)
{
    Std_ReturnType rtval = E_OK;
    S_BoostDrv_Dev *tmp = g_S_BoostDrv_Dev_Header;
    S_BoostDataPackets BoostDataPackets;
    S_BoostInitDataSrc BoostInitDataSrc;

    if (tmp == NULL)
        return E_NOT_OK;

    while (tmp)
    {
        BoostInitDataSrc.BoostkNo = tmp->dev_id;
        BoostInitDataSrc.InitVoltage = InitVoltage;
        BoostDataPackets.BoostDataTypes = E_BoostDataType_BoostInit;
        BoostDataPackets.datasrc = (void *)(&BoostInitDataSrc);

        rtval |= tmp->DeviceInit((void *)(&BoostDataPackets));
        if (rtval != E_OK)
            return E_NOT_OK;

        tmp = tmp->ptNext;
    }

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType BoostDrvDev_Register(S_BoostDrv_Dev *Drv_Dev)
{
    S_BoostDrv_Dev *tmp = g_S_BoostDrv_Dev_Header;

    if (g_S_BoostDrv_Dev_Header == NULL)
    {
        g_S_BoostDrv_Dev_Header = Drv_Dev;
        g_S_BoostDrv_Dev_Header->ptNext = NULL;
    }
    else
    {
        while (tmp->ptNext != NULL)
            tmp = tmp->ptNext;
        tmp->ptNext = Drv_Dev;
        Drv_Dev->ptNext = NULL;
    }
    return E_OK;
}
