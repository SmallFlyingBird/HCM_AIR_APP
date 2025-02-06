
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "PowerSupply_Interface.h"
#include "AdcDev_Interface.h"
#include "DTC_Interface.h"
#include "GeneralFunction.h"
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

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
/*
* 函数名称：KL56_PowerSupplyMainFunction
* 函数功能：获取实时KL56ADC采样值，求3位去掉最低位去掉最高位均值，判断是否有开路故障（实时状态）
*/
double bufKL56[500]={0};
uint16 bufKL56cnt=0;
uint16 buf10ms1[500]={0};
uint16 buf10ms2[500]={0};
extern uint16 bufouv[10];
static Std_ReturnType KL56_PowerSupplyMainFunction(uint8_t tmiebase)
{
    Std_ReturnType rtval = E_OK;
    uint32_t DigitalValue;

    if (Interface_GetAdcDigitalValue(E_AdcFunction_KL56, &DigitalValue) != E_OK)
        return E_NOT_OK;

    bufKL56[bufKL56cnt]=g_KL56_VoltageValueMean;
    buf10ms1[bufKL56cnt]=bufouv[3];
    bufKL56cnt++;
    if(bufKL56cnt>499) bufKL56cnt=0;
    

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
void PowerSupplyMainFunction(uint8_t tmiebase)
{
    double tmp = 0;
    double MaxVoltage = 0;
    uint32_t SignalValue;
    static uint32_t CommTimeTick = 0;
    Std_ReturnType rtval;
    KL56_PowerSupplyMainFunction(tmiebase);

    if ( Interface_GetKL56Voltage(&tmp) == E_OK) //KL56值
    {
        /**************************************电压比较故障**************************************/
        if ((MaxVoltage * 10) < (SignalValue - 30))
        {
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_BUSSIGNAL_MISMATCH, 1);
        }
        else
        {
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_BUSSIGNAL_MISMATCH, 0);
        }

        /**************************************电压过高故障**************************************/
        if (MaxVoltage > OVER_VOLTAGE_FAIL_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH, 1);
        else if (MaxVoltage < OVER_VOLTAGE_PASS_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH, 0);

        /**************************************电压过低故障**************************************/
        /*SignalValue = 真实电压x10 */
        if (((MaxVoltage * 10) > (SignalValue - 30)) &&
            (MaxVoltage < UNDER_VOLTAGE_FAIL_THRESHOLD))
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 1);
        else if (MaxVoltage > UNDER_VOLTAGE_PASS_THRESHOLD)
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 0);
    }
}

// extern uint8 ldoerr;
void LDOSupplyMainFuntion(void)
{
    // ldoerr=Adc_LDOStatusRead();
}
