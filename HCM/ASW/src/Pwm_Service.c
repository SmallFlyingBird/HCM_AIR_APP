
#include "Pwm_Service.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "ParaMgr.h"
/* enable the HB*/
void ByPass_PwmSetting(uint8 pwm)   
{ 
    /* f = 2000000/parameter  eg:500=4khz;1000=2khz;10000=200hz */
    uint16 dutydata=0;
    dutydata=0x8000-pwm*0x8000/100;
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_HL_Ctrl,10000,dutydata);
}

void Pwm_Config_DC_Ctrl(uint16 duty) 
{ 
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_DC_Ctr,200,duty);
}

// 输出TRK=16.325%,BOOST=49V
void PWM_Config_BOOST_TRK(void)      
{ 
    Pwm_SetDutyCycle(PwmConf_PwmChannel_TRK_CC_BOOST, 0x8000*TRK_DATA/100);
} 

void PWM_Config_Trigger_Ctrl(uint16 duty)      
{
    uint16 setting=0;
/* setting = 2000000/parameter  eg:500=4khz;1000=2khz;20000=100hz */
/* 星空灯的PWM频率由参数表配置决定，等于 ParaMgr_pHWOUT1Frequency_B */
    if(ParaMgr_pHWOUT1Frequency_B!=0)
    {
        setting=2000000/ParaMgr_pHWOUT1Frequency_B;
        Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_Trigger_Ctrl,setting,duty);
    }
}

void PWM_Config_Trigger_Ctr2(uint16 duty)      
{
    uint16 setting=0;
    /* setting = 2000000/parameter  eg:500=4khz;1000=2khz;20000=100hz */
    /* 星空灯的PWM频率由参数表配置决定，等于 ParaMgr_pHWOUT1Frequency_B */
    if(ParaMgr_pHWOUT1Frequency_B!=0)
    {
        setting=2000000/ParaMgr_pHWOUT1Frequency_B;
        Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_Trigger_Ctrl2,setting,duty);
    }
}

void Pwm_Init_All(void)
{
    ByPass_PwmSetting(0);
    Pwm_Config_DC_Ctrl(0); //拉低电机控制引脚
    PWM_Config_BOOST_TRK();
    PWM_Config_Trigger_Ctrl(0x8000);            /* high out close the start light */
    PWM_Config_Trigger_Ctr2(0x8000);
}



