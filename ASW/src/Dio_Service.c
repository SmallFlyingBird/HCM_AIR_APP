

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio.h"
#include "Dio_Service.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"

void initializePort(void)
{
    Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW); //打开TL
    Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW); //打开DRL
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);//关电机
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0x08000);//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0); //拉低电机控制引脚
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 0x3399);//0x4899U);//0x1999 约等于20%   //0x3399空载50V
}


