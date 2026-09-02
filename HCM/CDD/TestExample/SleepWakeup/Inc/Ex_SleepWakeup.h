#ifndef EXSLEEPWAKEUP_HEADER_H
#define EXSLEEPWAKEUP_HEADER_H

// typedef enum
// {
//     HCM_SLEEP,
//     HCM_WAKEUP
// }SleepWakeupStatus;

void Ex_SleepWakeupInit(void);
void PowerManagerMainFunction(void);
void WDT_Service(void);
#endif