#include "Ex_SleepWakeup.h"

static uint16 Alivetime = 0;
static SleepWakeupStatus WakeupStatus = HCM_SLEEP;
void Ex_SleepWakupInit(void)
{
    Alivetime = 65535;
    WakeupStatus = HCM_WAKEUP;
    Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
}

void Ex_SleepWakeupMain(void)
{
    if(!(Alivetime--))
    {
        WakeupStatus = HCM_SLEEP;
        //Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_HIGH);
        Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_LOW);
    }
    else if(Alivetime && (HCM_WAKEUP == WakeupStatus))
    {
        Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
    }
    else
    {}
}