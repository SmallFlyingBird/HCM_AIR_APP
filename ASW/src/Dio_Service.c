

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
uint8 LR_flag=0xff; //左右识别 临时放置 未做处理


void Boost_Enable(void)
{
    Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_LOW);
}


void Boost_Disable(void)
{
    Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_HIGH);
}


void initializePort(void)
{
    Boost_Disable();
    Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW); //打开TL
    Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW); //打开DRL
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);//关电机
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0x08000);//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0); //拉低电机控制引脚
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 6062);// TRK设置为18.5%
    LR_flag=Dio_ReadChannel(DioConf_DioChannel_L_R_Identify_To_MCU); //左接地 读出1;右悬空 读出0
}



