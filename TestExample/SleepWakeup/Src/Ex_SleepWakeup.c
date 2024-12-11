#include "Ex_SleepWakeup.h"
#include "Pwm_Cfg.h"
#include "Pwm.h"
static SleepWakeupStatus WakeupStatus = HCM_SLEEP;
extern uint8 Gpt_5s;
static uint16 AWakeTimer = 0;
void Ex_SleepWakeupInit(void)
{
    WakeupStatus = HCM_WAKEUP;
    Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
}

void Ex_SleepWakeupMain(void)
{
    AWakeTimer++;/*100ms*/
    if(50 == AWakeTimer)
    {
        WakeupStatus = HCM_SLEEP;

        ResetAWakeTime();
        /* Turn off buck */
        Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN,STD_LOW);

        /* Sleep */
        Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_LOW);
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);//关电机
        Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0); //拉低电机控制引脚
    }
    else if(HCM_SLEEP == WakeupStatus)
    {
        // WakeupStatus = HCM_WAKEUP;
        // Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
        // Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
    }
    else
    {}
}

void ResetAWakeTime(void)
{
    AWakeTimer = 0;
}