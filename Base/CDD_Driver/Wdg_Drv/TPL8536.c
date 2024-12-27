#include "TPL8536.h"
#include "Dio.h"
boolean Wdg_feed_flag = FALSE;
uint16 ExWdg_Timer_20ms = 0;
uint16 ExWdgTimeout = 0;
void ExWdg_SetTriggerCondition(uint16 Timeout)
{
    // if (Timeout)
    // {
    //     ExWdgTimeout = Timeout;
    //     ExWdg_Timer_20ms = 0;
    // }
    // else
    // {
    //     Interface_SetSystemError(E_SystemErrorType_WatchDogTimeout,1);
    // }
}

Std_ReturnType ExWdg_SetMode(WdgIf_ModeType Mode)
{

    return E_OK;
}