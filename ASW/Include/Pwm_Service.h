
#ifndef PWM_SERVICE_H
#define PWM_SERVICE_H
#include "HcmPlatform.h"
void Pwm_HLCtrl_Disable(void);
void Pwm_HLCtrl_Enable(void);
void Pwm_Init_All(void);
void PWM_Config_Trigger_Ctrl(uint16 duty) ;     
void PWM_Config_Trigger_Ctr2(uint16 duty) ; 
#endif
