#include "Ex_SleepWakeup.h"

static SleepWakeupStatus WakeupStatus = HCM_SLEEP;
extern uint8 Gpt_1s;
void Ex_SleepWakupInit(void)
{
    WakeupStatus = HCM_WAKEUP;
    Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
}

void Ex_SleepWakeupMain(void)
{   
    if(50 == Gpt_1s)
    {
        WakeupStatus = HCM_SLEEP;
        Gpt_1s = 0;
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