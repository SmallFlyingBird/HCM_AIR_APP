#ifndef OS_USER_H
#define OS_USER_H
#include "Os.h"

typedef enum
{
	OsIndex_5ms,
	OsIndex_10ms,
	OsIndex_20ms,
	OsIndex_50ms,
	OsIndex_100ms,
	OsIndex_Total
} OsTask_index_Tyde;

typedef enum
{
	Os_Task_Idle,
	Os_Task_Pending
} OsTask_State_Type;

typedef struct
{
	OsTask_State_Type TaskState;
	TickType Increment;
	TickType Cycle;
	TickType TaskExpiryPoint;
}OsTask_Info_Type;

/* Decalre Variables */
extern OsTask_Info_Type TaskInfo[OsIndex_Total];
extern uint32 Os_Timer;
// extern uint8 Boot_UninitRam[256];
// extern uint8 App_UninitRam[256];
/* Decalre Functions */
extern void undefined_handler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void); 
extern void MemManageFault_Handler(void) ;
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void DebugMonitor_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);
extern void SVC_Handler(void); 
extern void Reset_Handler(void);
extern void StartOS(void);
extern void OSTask_Initial_User(void);
extern	void OSTask_5ms_User(void);
extern	void OSTask_10ms_User(void);
extern	void OSTask_20ms_User(void);
extern	void OSTask_50ms_User(void);
extern	void OSTask_100ms_User(void);
extern	void OSTask_Idle_User(void);
extern void SetRelAlarm(uint8 TaskId, TickType increment, TickType cycle);

#endif
