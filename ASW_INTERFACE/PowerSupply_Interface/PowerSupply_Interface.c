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
#include "PowerSupply_Interface.h"
#include "AdcDev_Interface.h"
#include "DTC_Interface.h"
#include "ComSignal_Interface.h"
#include "GeneralFunction.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint32_t g_KL56_VoltageValue[VOLTAGE_BUFFER_ARRAY_NUM] = {0};
static uint32_t g_KL56_VoltageValueMean = 0xFFFFFFFF;
static uint8_t KL56_ReadIndex = 0;
static uint8_t KL56_ShortOrOpenErrorFlag = 0;

static U_SupplyVoltageState gu_SupplyVoltageState;
static double Voltage_K = 5.7;

//测试 临时放置
extern uint8 lin_powererr[4];

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
/*
* 函数名称：KL56_PowerSupplyMainFunction
* 函数功能：获取实时KL56ADC采样值，求3位去掉最低位去掉最高位均值，判断是否有开路故障（实时状态）
*/
static Std_ReturnType KL56_PowerSupplyMainFunction(uint8_t tmiebase)
{
    Std_ReturnType rtval = E_OK;
    uint32_t DigitalValue;
    E_AdcAccuracy AdcAccuracy;

    if (Interface_GetAdcDigitalValue(E_AdcFunction_KL56, &DigitalValue) != E_OK)
        return E_NOT_OK;
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
                lin_powererr[E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN]=1;
                KL56_ShortOrOpenErrorFlag = 1;
            }
            else if (g_KL56_VoltageValueMean < KL56_SHORT2GND_OPEN_RECOVER_THRESHOLD_12ADBIT)
            {
                /*Do nothing*/
            }
            else
            {
                lin_powererr[E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN]=0;
                KL56_ShortOrOpenErrorFlag = 0;
            }
        }
    }

    KL56_ReadIndex++;
    if (KL56_ReadIndex >= VOLTAGE_BUFFER_ARRAY_NUM)
        KL56_ReadIndex = 0;
    return rtval;
}

/*
* 函数名称：Interface_GetKL56Voltage(double *voltage)
* 输出: voltage 实际的电压值
* 函数功能：通过采样的ADC值计算出实际的电压值
*/
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


void PowerSupplyMainFunction(uint8_t tmiebase)
{
    double tmp = 0;
    KL56_PowerSupplyMainFunction(tmiebase);

    if ( Interface_GetKL56Voltage(&tmp) == E_OK) //KL56值
    {
        if (tmp > OVER_VOLTAGE_FAIL_THRESHOLD) // >17V
            lin_powererr[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH]=1;
        else if (tmp < OVER_VOLTAGE_PASS_THRESHOLD)  // <16V
            lin_powererr[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH]=0;
        // Interface_GetSignal_VehBattUSysU(&SignalValue);
        /*SignalValue = 真实电压x10 */
        if (tmp < UNDER_VOLTAGE_FAIL_THRESHOLD)  // <8V
           lin_powererr[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW]=1;
        else if (tmp > UNDER_VOLTAGE_PASS_THRESHOLD) // >9V
            lin_powererr[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW]=0;
    }
}



