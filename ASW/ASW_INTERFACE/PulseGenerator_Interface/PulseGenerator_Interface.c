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
Std_ReturnType Interface_EnablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty)
{
    Std_ReturnType rtval = E_OK;
    uint16 duty0 = 0;
    if (duty > 100) duty = 100;

    duty0 = duty * 32767 / 100;
    switch (PulseGeneratorFunction)
    {
        case E_PulseGeneratorFunction_DCMotor:
            Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_DC_Ctr, cycle, duty0);
        break;
    }
    return rtval;
}
