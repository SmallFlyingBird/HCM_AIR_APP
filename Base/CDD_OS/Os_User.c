#include "Dio.h"
#include "Wdg.h"
#include "Os_User.h"
#include "ASW_Manager.h"
#include "Ex_SleepWakeup.h"
#include "Ex_Lin.h"

#define DEBUG_OFF 0
#define DEBUG_ON 1
#define LIN_AWAKE_TIME (DEBUG_OFF)//

uint16 Task_Counter[OsIndex_Total];

/* Function declaration */
extern uint8 UDS_ResetReq(void);

/* Initial Task */
void OSTask_Initial_User(void)
{
    /*keep lin awake*/
	Ex_SleepWakeupInit();
	
	//ASW_Manager_Init(); //初始化代码

	SetRelAlarm(OsIndex_5ms,1,5);
	SetRelAlarm(OsIndex_10ms,3,10);
	SetRelAlarm(OsIndex_20ms,5,20);
	SetRelAlarm(OsIndex_50ms,7,50);
	SetRelAlarm(OsIndex_100ms,9,100);
}
/* 5ms Task */
void OSTask_5ms_User(void)
{
	Task_Counter[OsIndex_5ms]++;
	ASW_Manager_MainFunction_5ms();
	ExLin_Diagnostic_MainFunction_5ms();
}
/* 10ms Task */
void OSTask_10ms_User(void)
{
	Task_Counter[OsIndex_10ms]++;
	UDS_ResetReq();
	ASW_Manager_MainFunction_10ms();
}
/* 20ms Task */
void OSTask_20ms_User(void)
{
	Task_Counter[OsIndex_20ms]++;
	ASW_Manager_MainFunction_20ms();
}
/* 50ms Task */
void OSTask_50ms_User(void)
{
	Task_Counter[OsIndex_50ms]++;
	ASW_Manager_MainFunction_50ms();
}
/* 100ms Task */
void OSTask_100ms_User(void)
{
	Task_Counter[OsIndex_100ms]++;
	ASW_Manager_MainFunction_100ms();
	Wdg_Service();
#if (LIN_AWAKE_TIME == DEBUG_ON)
	Ex_SleepWakeupMain();
#endif
}
/* idle Task */
void OSTask_Idle_User(void)
{
}

