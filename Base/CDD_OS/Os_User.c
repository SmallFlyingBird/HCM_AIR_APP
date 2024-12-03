#include "Dio.h"
#include "Wdg.h"
#include "Os_User.h"
#include "Ex_SleepWakeup.h"

#define DEBUG_OFF 0
#define DEBUG_ON 1
#define LIN_AWAKE_TIME (DEBUG_OFF)//

uint16 Task_Counter[OsIndex_Total];
extern uint16 AWakeTimer;
/* Initial Task */
void OSTask_Initial_User(void)
{
    /*keep lin awake*/
    // Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    // Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
	Ex_SleepWakeupInit();
	Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_LOW);

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
}
/* 10ms Task */
void OSTask_10ms_User(void)
{
	Task_Counter[OsIndex_10ms]++;
}
/* 20ms Task */
void OSTask_20ms_User(void)
{
	Task_Counter[OsIndex_20ms]++;
}
/* 50ms Task */
void OSTask_50ms_User(void)
{
	Task_Counter[OsIndex_50ms]++;
}
/* 100ms Task */
void OSTask_100ms_User(void)
{
	Task_Counter[OsIndex_100ms]++;
	Wdg_Service();
#if (LIN_AWAKE_TIME == DEBUG_ON)
	Ex_SleepWakeupMain();
#endif
}
/* idle Task */
void OSTask_Idle_User(void)
{

}

