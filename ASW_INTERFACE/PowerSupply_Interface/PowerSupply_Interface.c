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
#include "Ex_Lin.h"
#include "AdcDrv.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint32_t g_KL56_VoltageValue[VOLTAGE_BUFFER_ARRAY_NUM] = {0};
static uint32_t g_KL56_VoltageValueMean = 0xFFFFFFFF;
static uint8_t KL56_ReadIndex = 0;

static U_SupplyVoltageState gu_SupplyVoltageState;
static double Voltage_K = 5.7;

//测试 临时放置
uint8_t gMap_SupplyVolError[5] = {14, 15, 16, 17, 18};

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
    if (g_KL56_VoltageValueMean == 0xFFFFFFFF)
        return E_NOT_OK;

    *voltage = (((double)g_KL56_VoltageValueMean) * 5.0 * Voltage_K / ADCWIDTH);

    return rtval;
}
// extern uint8 lin_powererr;
// extern uint16 kl56vol111;
void PowerSupplyMainFunction(uint8_t tmiebase)
{
    double tmp = 0;
    KL56_PowerSupplyMainFunction(tmiebase);

    if ( Interface_GetKL56Voltage(&tmp) == E_OK) //KL56值
    {
        // kl56vol111=(uint16)(tmp*10);
        // if (tmp > OVER_VOLTAGE_FAIL_THRESHOLD) // >17V
        //     gMap_SupplyVolError[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH]=1;
        // else if (tmp < OVER_VOLTAGE_PASS_THRESHOLD)  // <16V
        //     gMap_SupplyVolError[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH]=0;
        // // Interface_GetSignal_VehBattUSysU(&SignalValue);
        // /*SignalValue = 真实电压x10 */
        // if (tmp < UNDER_VOLTAGE_FAIL_THRESHOLD)  // <8V
        //    gMap_SupplyVolError[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW]=1;
        // else if (tmp > UNDER_VOLTAGE_PASS_THRESHOLD) // >9V
        //     gMap_SupplyVolError[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW]=0;
    }
    // if(gMap_SupplyVolError[E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN]==1)
    //     lin_powererr=Low_Voltage;
    // if(gMap_SupplyVolError[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH]==1)
    //     lin_powererr=Over_Voltage;
    // else if(gMap_SupplyVolError[E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW]==1)  
    //     lin_powererr=Low_Voltage;
    // else lin_powererr=STATUS_OFF;
}

extern uint8 ldoerr;
void LDOSupplyMainFuntion(void)
{
    ldoerr=Adc_LDOStatusRead();
}
