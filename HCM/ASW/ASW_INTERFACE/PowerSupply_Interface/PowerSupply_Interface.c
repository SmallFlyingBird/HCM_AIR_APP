
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
#include "DID_Interface.h"
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
*funxtion :get the realtime KL52 ADC, ValueMean=(sum5-min-max)/3,judge if open error or not
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

/* get kl56 voltage */
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

    KL56_PowerSupplyMainFunction(tmiebase);

    if ( Interface_GetKL56Voltage(&tmp) == E_OK) /* KL56 value */
    {
        /**************************************HIGT ERROR**************************************/
        if (tmp > OVER_VOLTAGE_FAIL_THRESHOLD)
        {
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH, 1);
            Interface_SetD900Data( KL56_Too_High, STATE_ERROR);
        }
        else if (tmp < OVER_VOLTAGE_PASS_THRESHOLD)
        {
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH, 0);
            Interface_SetD900Data( KL56_Too_High, STATE_OK);
        }
        /**************************************LOW error**************************************/
        /*SignalValue = 真实电压x10 */
        if (tmp < UNDER_VOLTAGE_FAIL_THRESHOLD)
        {
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 1);
            Interface_SetD900Data( KL56_Too_Low, STATE_ERROR);
        }
        else if (tmp > UNDER_VOLTAGE_PASS_THRESHOLD)
        {
            Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW, 0);
            Interface_SetD900Data( KL56_Too_Low, STATE_OK);
        }
    }
}

// extern uint8 ldoerr;
void LDOSupplyMainFuntion(void)
{
    // ldoerr=Adc_LDOStatusRead();
}
