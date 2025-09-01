#include "Dio.h"
#include "Wdg.h"
#include "Os_User.h"
#include "ASW_Manager.h"
#include "Ex_SleepWakeup.h"
#include "Dcm.h"
#include "Fls.h"
#include "Fee.h"
#include "NvM.h"
#include "Rte_Nvm.h"
#include "SchM_LinIf.h"
#include "CpuLoad.h"
#include "Rte_E2EXf.h"
#include "Com.h"

uint32 Task_Counter[OsIndex_Total];

/* Function declaration */
extern uint8 UDS_ResetReq(void);
/* Variable Declaration */
#pragma ghs section bss=".uninit_boot_ram"
/*the address range is [0x2000fe00,0x2000feff] */
uint8 Boot_UninitRam[256];
#pragma ghs section

#pragma ghs section bss=".uninit_app_ram"
/*the address range is [0x2000ff00,0x2000ffff] */
uint8 App_UninitRam[256];
#pragma ghs section

/* Initial Task */
void OSTask_Initial_User(void)
{
    /*keep lin awake*/
	Ex_SleepWakeupInit();
	E2EXf_Init(&E2EXf_Config);
	ASW_Manager_Init();
	CpuLoad_Init();

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
	LinIf_MainFunction();
	Dcm_MainFunction();
}
/* 10ms Task */
void OSTask_10ms_User(void)
{
	Task_Counter[OsIndex_10ms]++;
	ASW_Manager_MainFunction_10ms();
	Com_Signal_TimeCounter_10ms();
}
/* 20ms Task */
void OSTask_20ms_User(void)
{
	Task_Counter[OsIndex_20ms]++;
	NvM_MainFunction();
	Fee_MainFunction();	
	Fls_MainFunction();
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
	WDT_Service();
}
/* idle Task */
void OSTask_Idle_User(void)
{
}

