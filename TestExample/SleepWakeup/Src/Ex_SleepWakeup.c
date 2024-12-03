#include "Ex_SleepWakeup.h"

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
        Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_LOW);
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