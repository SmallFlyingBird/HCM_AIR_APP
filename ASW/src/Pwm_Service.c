
#include "Pwm_Service.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "ParaMgr.h"
/* 0x8000=100%=close the high beam ；200:f=400HZ */
void Pwm_HLCtrl_Disable(void)  
{ 
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,200,0x08000);
}
/* enable the HB
*  0% =open the high beam ；200:f=400HZ 0% */
void Pwm_HLCtrl_Enable(void)   
{ 
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,200,0);
}

void Pwm_Config_DC_Ctrl(uint16 duty) 
{ 
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_DC_Ctr,200,duty);
}

// 输出TRK=16.325%,BOOST=49V
void PWM_Config_BOOST_TRK(void)      
{ 
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 0x8000*TRK_DATA/100);
} 

void PWM_Config_Trigger_Ctrl(uint16 duty)      
{
    uint16 setting=0;
/* setting = 2000000/parameter  eg:500=4khz;1000=2khz;20000=100hz */
    setting=2000000/ParaMgr_pHWOUT1Frequency_B;
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_PTB9_Trigger_Ctrl,setting,duty);
}

void PWM_Config_Trigger_Ctr2(uint16 duty)      
{
    uint16 setting=0;
    /* setting = 2000000/parameter  eg:500=4khz;1000=2khz;20000=100hz */
    setting=2000000/ParaMgr_pHWOUT1Frequency_B;
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_PTA2_Trigger_Ctrl2,setting,duty);
}

void Pwm_Init_All(void)
{
    Pwm_HLCtrl_Disable();//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Pwm_Config_DC_Ctrl(0); //拉低电机控制引脚
    PWM_Config_BOOST_TRK();
    PWM_Config_Trigger_Ctrl(0x8000);            /* high out close the start light */
    PWM_Config_Trigger_Ctr2(0x8000);
}



