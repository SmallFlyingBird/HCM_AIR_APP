#ifndef EXSLEEPWAKEUP_HEADER_H
#define EXSLEEPWAKEUP_HEADER_H
#include "Platform.h"
#include "Dio.h"

typedef enum
{
    HCM_SLEEP,
    HCM_WAKEUP
}SleepWakeupStatus;

void Ex_SleepWakeupInit(void);
void ResetAWakeTime(void);
void WDT_Service(void);
#endif