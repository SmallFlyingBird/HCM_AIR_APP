/*
 * PowerSupply_Interface.c
 *
 *  Created on: 2024��2��19��
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
static uint32_t g_KL15_VoltageValue[VOLTAGE_BUFFER_ARRAY_NUM] = {0};
static uint32_t g_KL56_VoltageValue[VOLTAGE_BUFFER_ARRAY_NUM] = {0};
static uint32_t g_KL15_VoltageValueMean = 0xFFFFFFFF;
static uint32_t g_KL56_VoltageValueMean = 0xFFFFFFFF;

static uint8_t KL15_ReadIndex = 0;
static uint8_t KL56_ReadIndex = 0;

static uint8_t KL15_ShortOrOpenErrorFlag = 0;
static uint8_t KL56_ShortOrOpenErrorFlag = 0;

static U_SupplyVoltageState gu_SupplyVoltageState;
static double Voltage_K = 5.7;
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
static Std_ReturnType KL15_PowerSupplyMainFunction(uint8_t tmiebase)
{
    Std_ReturnType rtval = E_OK;
    uint32_t DigitalValue;
    E_AdcAccuracy AdcAccuracy;

    if (Interface_GetAdcDigitalValue(E_AdcFunction_KL15, &DigitalValue) != E_OK)
        return E_NOT_OK;
#if 1
    if (g_KL15_VoltageValueMean == 0xFFFFFFFF)
    {
        g_KL15_VoltageValue[KL15_ReadIndex] = DigitalValue;
        if (KL15_ReadIndex >= (VOLTAGE_BUFFER_ARRAY_NUM - 1))
        {
            /*计算平均值*/
            g_KL15_VoltageValueMean = CalArrayAverageValue_Uint32(g_KL15_VoltageValue, VOLTAGE_BUFFER_ARRAY_NUM);
        }
    }
    else
    {
        g_KL15_VoltageValue[KL15_ReadIndex] = DigitalValue;
        g_KL15_VoltageValueMean = CalArrayAverageValue_Uint32(g_KL15_VoltageValue, VOLTAGE_BUFFER_ARRAY_NUM);
    }

    if (g_KL15_VoltageValueMean != 0xFFFFFFFF)
    {
        Interface_GetAdcAccuracy(E_AdcFunction_KL15, &AdcAccuracy);
        if (AdcAccuracy == E_AdcAccuracy_Bit12)
        {
            if (g_KL15_VoltageValueMean < KL15_SHORT2GND_OPEN_THRESHOLD_12ADBIT)
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL15_SHORT2GND_OPEN, 1);
                KL15_ShortOrOpenErrorFlag = 1;
            }
            else if (g_KL15_VoltageValueMean < KL15_SHORT2GND_OPEN_RECOVER_THRESHOLD_12ADBIT)
            {
                /*Do nothing*/
            }
            else
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL15_SHORT2GND_OPEN, 0);
                KL15_ShortOrOpenErrorFlag = 0;
            }
        }
    }

    KL15_ReadIndex++;
    if (KL15_ReadIndex >= VOLTAGE_BUFFER_ARRAY_NUM)
        KL15_ReadIndex = 0;

#else
    if (KL15_ReadIndex >= VOLTAGE_BUFFER_ARRAY_NUM)
    {
        g_KL15_VoltageValueMean = CalArrayAverageValue_Uint32(g_KL15_VoltageValue, VOLTAGE_BUFFER_ARRAY_NUM);
        Interface_GetAdcAccuracy(E_AdcFunction_KL15, &AdcAccuracy);
        if (AdcAccuracy == E_AdcAccuracy_Bit12)
        {
            if (g_KL15_VoltageValueMean < KL15_SHORT2GND_OPEN_THRESHOLD_12ADBIT)
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL15_SHORT2GND_OPEN, 1);
                KL15_ShortOrOpenErrorFlag = 1;
            }
            else if (g_KL15_VoltageValueMean < KL15_SHORT2GND_OPEN_RECOVER_THRESHOLD_12ADBIT)
            {
                /*Do nothing*/
            }
            else
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL15_SHORT2GND_OPEN, 0);
                KL15_ShortOrOpenErrorFlag = 0;
            }
        }
        KL15_ReadIndex = 0;
    }

    g_KL15_VoltageValue[KL15_ReadIndex] = DigitalValue;
    KL15_ReadIndex++;
#endif
    return rtval;
}

static Std_ReturnType KL56_PowerSupplyMainFunction(uint8_t tmiebase)
{
    Std_ReturnType rtval = E_OK;
    uint32_t DigitalValue;
    E_AdcAccuracy AdcAccuracy;

    if (Interface_GetAdcDigitalValue(E_AdcFunction_KL56, &DigitalValue) != E_OK)
        return E_NOT_OK;
#if 1
    if (g_KL56_VoltageValueMean == 0xFFFFFFFF)
    {
        g_KL56_VoltageValue[KL56_ReadIndex] = DigitalValue;
        if (KL56_ReadIndex >= (VOLTAGE_BUFFER_ARRAY_NUM - 1))
        {
            /*计算平均值*/
            g_KL56_VoltageValueMean = CalArrayAverageValue_Uint32(g_KL56_VoltageValue, VOLTAGE_BUFFER_ARRAY_NUM);
        }
    }
    else
    {
        g_KL56_VoltageValue[KL56_ReadIndex] = DigitalValue;
        g_KL56_VoltageValueMean = CalArrayAverageValue_Uint32(g_KL56_VoltageValue, VOLTAGE_BUFFER_ARRAY_NUM);
    }

    if (g_KL56_VoltageValueMean != 0xFFFFFFFF)
    {
        Interface_GetAdcAccuracy(E_AdcFunction_KL56, &AdcAccuracy);
        if (AdcAccuracy == E_AdcAccuracy_Bit12)
        {
            if (g_KL56_VoltageValueMean < KL56_SHORT2GND_OPEN_THRESHOLD_12ADBIT)
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN, 1);
                KL56_ShortOrOpenErrorFlag = 1;
            }
            else if (g_KL56_VoltageValueMean < KL56_SHORT2GND_OPEN_RECOVER_THRESHOLD_12ADBIT)
            {
                /*Do nothing*/
            }
            else
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN, 0);
                KL56_ShortOrOpenErrorFlag = 0;
            }
        }
    }

    KL56_ReadIndex++;
    if (KL56_ReadIndex >= VOLTAGE_BUFFER_ARRAY_NUM)
        KL56_ReadIndex = 0;
#else
    if (KL56_ReadIndex >= VOLTAGE_BUFFER_ARRAY_NUM)
    {
        g_KL56_VoltageValueMean = CalArrayAverageValue_Uint32(g_KL56_VoltageValue, VOLTAGE_BUFFER_ARRAY_NUM);
        Interface_GetAdcAccuracy(E_AdcFunction_KL56, &AdcAccuracy);
        if (AdcAccuracy == E_AdcAccuracy_Bit12)
        {
            if (g_KL56_VoltageValueMean < KL56_SHORT2GND_OPEN_THRESHOLD_12ADBIT)
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN, 1);
                KL56_ShortOrOpenErrorFlag = 1;
            }
            else if (g_KL56_VoltageValueMean < KL56_SHORT2GND_OPEN_RECOVER_THRESHOLD_12ADBIT)
            {
                /*Do nothing*/
            }
            else
            {
                Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN, 0);
                KL56_ShortOrOpenErrorFlag = 0;
            }
        }
        KL56_ReadIndex = 0;
    }

    g_KL56_VoltageValue[KL56_ReadIndex] = DigitalValue;
    KL56_ReadIndex++;
#endif
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_GetKL15Voltage(double *voltage)
{
    Std_ReturnType rtval = E_OK;
    E_AdcAccuracy AdcAccuracy;
    uint32_t adc_width;

    if (g_KL15_VoltageValueMean == 0xFFFFFFFF)
        return E_NOT_OK;

    if (Interface_GetAdcAccuracy(E_AdcFunction_KL15, &AdcAccuracy) != E_OK)
        return E_NOT_OK;

    adc_width = GetAdcWidth(AdcAccuracy);

    *voltage = (((double)g_KL15_VoltageValueMean) * 5.0 * Voltage_K / adc_width);

    return rtval;
}
Std_ReturnType Interface_GetKL56Voltage(double *voltage)
{
    Std_ReturnType rtval = E_OK;
    E_AdcAccuracy AdcAccuracy;
    uint32_t adc_width;

    if (g_KL56_VoltageValueMean == 0xFFFFFFFF)
        return E_NOT_OK;

    if (Interface_GetAdcAccuracy(E_AdcFunction_KL56, &AdcAccuracy) != E_OK)
        return E_NOT_OK;

    adc_width = GetAdcWidth(AdcAccuracy);

    *voltage = (((double)g_KL56_VoltageValueMean) * 5.0 * Voltage_K / adc_width);

    return rtval;
}

Std_ReturnType Interface_GetMaxVolBetweenKL15AndKL56(double *voltage)
{
    double MaxVol = 0;
    double tmp = 0;
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_GetKL56Voltage(&tmp);
    if (rtval == E_OK)
        MaxVol = tmp;

    rtval |= Interface_GetKL15Voltage(&tmp);
    if (rtval == E_OK)
        MaxVol = MaxVol > tmp ? MaxVol : tmp;

    if (rtval == E_OK)
        *voltage = MaxVol;

    return rtval;
}

void PowerSupplyMainFunction(uint8_t tmiebase)
{
    static uint16_t timetick = 0;
    double MaxVoltage = 0;
    uint32_t SignalValue;
    KL15_PowerSupplyMainFunction(tmiebase);
    KL56_PowerSupplyMainFunction(tmiebase);

    if (Interface_GetMaxVolBetweenKL15AndKL56(&MaxVoltage) == E_OK)
    {
        if (MaxVoltage > OVER_VOLTAGE_FAIL_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH, 1);
        else if (MaxVoltage < OVER_VOLTAGE_PASS_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH, 0);
#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
        /*SignalValue = 真实电压x10 */
        if (MaxVoltage < UNDER_VOLTAGE_FAIL_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 1);
        else if (MaxVoltage > UNDER_VOLTAGE_PASS_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 0);
#else
        Interface_GetSignal_VehBattUSysU(&SignalValue);
        /*SignalValue = 真实电压x10 */
        if (((MaxVoltage * 10) > (SignalValue - 30)) &&
            (MaxVoltage < UNDER_VOLTAGE_FAIL_THRESHOLD))
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 1);
        else if (MaxVoltage > UNDER_VOLTAGE_PASS_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 0);
#endif
        if ((MaxVoltage * 10) < (SignalValue - 30))
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_BUSSIGNAL_MISMATCH, 1);
        else
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_BUSSIGNAL_MISMATCH, 0);
    }

    timetick += tmiebase;
    if (timetick >= 40)
    {
        timetick = 0;
    }
}
