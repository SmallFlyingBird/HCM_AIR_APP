#include "CpuLoad.h"
#include "Stim_Drv.h"
/* Time information for each  */
S_CpuLoad_TimeInfo CpuLoad_TimeInfo[CpuLoad_Index_Total]={0};
float32 CpuLoad_Percent;
/* Initial Function */
void CpuLoad_Init(void)
{
	uint8 index;

	for(index=0;index<CpuLoad_Index_Total;index++)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Max = 0;
		CpuLoad_TimeInfo[index].ElapsedTime_Min = 0xFFFFFFFF;
		CpuLoad_TimeInfo[index].ElapsedTime_Aver = 0;
		CpuLoad_TimeInfo[index].ElapsedTime_Sum = 0;
	}
	Stim_Drv_StartTimer(0,0,0xFFFFFFFF);
}

/* Record Entry Point */
void CpuLoad_EntryTime(uint8 index)
{
	CpuLoad_TimeInfo[index].EntryTime = Stim_Drv_GetCurrentCounterValue(0,0)/10; //unit: us
}

/* Record Exit Point */
void CpuLoad_ExitTime(uint8 index)
{
	uint32 value;
	value = Stim_Drv_GetCurrentCounterValue(0,0)/10;

	if(value > CpuLoad_TimeInfo[index].EntryTime)
	{
		CpuLoad_TimeInfo[index].ExitTime = value;
		CpuLoad_TimeInfo[index].ElapsedTime = CpuLoad_TimeInfo[index].ExitTime - CpuLoad_TimeInfo[index].EntryTime;
	}
	else
	{
		CpuLoad_TimeInfo[index].ExitTime = (0xFFFFFFFF/10 + 1)+value;
		CpuLoad_TimeInfo[index].ElapsedTime = CpuLoad_TimeInfo[index].ExitTime - CpuLoad_TimeInfo[index].EntryTime;
	}	

	if(CpuLoad_TimeInfo[index].ElapsedTime_Max < CpuLoad_TimeInfo[index].ElapsedTime)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Max = CpuLoad_TimeInfo[index].ElapsedTime;
	}

	if(CpuLoad_TimeInfo[index].ElapsedTime_Min > CpuLoad_TimeInfo[index].ElapsedTime)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Min = CpuLoad_TimeInfo[index].ElapsedTime;
	}

	if(CpuLoad_TimeInfo[index].ElapsedTime_Aver == 0)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Aver = CpuLoad_TimeInfo[index].ElapsedTime;
	}
	else
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Aver = (CpuLoad_TimeInfo[index].ElapsedTime + CpuLoad_TimeInfo[index].ElapsedTime_Aver)/2;
	}

	CpuLoad_TimeInfo[index].ElapsedTime_Sum += CpuLoad_TimeInfo[index].ElapsedTime;
}

/* Calculate CPU load Information  */
void CpuLoad_Calculation(void)
{
	uint8 index;
	uint32 Sum = 0;
	
	for(index=0;index<CpuLoad_Index_Total;index++)
	{
		Sum += CpuLoad_TimeInfo[index].ElapsedTime_Sum;
	}
	for(index=0;index<CpuLoad_Index_Total;index++)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Sum = 0;
	}
	CpuLoad_Percent = ((float32)Sum / (float32)200000.0f)*100.0f;
}
