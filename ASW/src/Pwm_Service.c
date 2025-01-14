
#include "Pwm_Service.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"

void Pwm_CH1Tap_Disable(void)  { Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0x08000);}//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
void Pwm_CH1Tap_Enable(void)   { Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0);}//远光使能

void Pwm_Config_DC_Ctrl(uint16 duty) { Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, duty);      }
void PWM_Config_BOOST_TRK(void)      { Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 6062);} // TRK设置为18.5% 0x8000*18.5%=6062


void Pwm_Init_All(void)
{
    Pwm_CH1Tap_Disable();//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Pwm_Config_DC_Ctrl(0); //拉低电机控制引脚
    PWM_Config_BOOST_TRK();
}



