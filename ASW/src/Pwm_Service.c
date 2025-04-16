
#include "Pwm_Service.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
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

// TRK设置为18.5% 0x8000*18.5%=6062   18.0输出TRK=16.5%,BOOST=49V
void PWM_Config_BOOST_TRK(void)      
{ 
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 0x8000*18/100);
} 

void Pwm_Init_All(void)
{
    Pwm_HLCtrl_Disable();//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Pwm_Config_DC_Ctrl(0); //拉低电机控制引脚
    PWM_Config_BOOST_TRK();
}



