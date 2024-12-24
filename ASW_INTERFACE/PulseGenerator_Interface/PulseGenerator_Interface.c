/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "PulseGenerator_Interface.h"
#include "Pwm.h"

/*
* 设置PWM周期 频率
*/
Std_ReturnType SetPulseGeneratorDutyAndCycle(E_PulseGeneratorFunction PulseGeneratorFunction, S_PwmValueDataSrc *PwmValueDataSrc)
{
    Std_ReturnType rtval = E_OK;
    uint16 Cyclcounter = 0;
    uint16 duty = 0;

    Cyclcounter = (PwmValueDataSrc->cycle);
    duty = (uint16)(((uint32)PwmValueDataSrc->duty) * 32767 / 100);
    switch (PulseGeneratorFunction)
    {
        case E_PulseGeneratorFunction_DCMotor:
            Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_DC_Ctr, Cyclcounter, duty);
        break;
    }
    return rtval;
}
/*
* 设置PWM周期 频率 上层接口
*/
Std_ReturnType Interface_EnablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty)
{
    Std_ReturnType rtval = E_OK;
    S_PwmValueDataSrc PwmValueDataSrc;

    if (duty > 100) duty = 100;

    PwmValueDataSrc.cycle = cycle;
    PwmValueDataSrc.duty = duty;
    PwmValueDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    buf[0]=PwmValueDataSrc.cycle;
    buf[1]=PwmValueDataSrc.duty;
    rtval |= SetPulseGeneratorDutyAndCycle(PwmValueDataSrc.PulseGeneratorFunction, &PwmValueDataSrc);

    return rtval;
}
