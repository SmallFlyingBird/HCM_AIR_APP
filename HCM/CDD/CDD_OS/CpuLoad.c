#include "CpuLoad.h"
#include "Gpt.h"

/* Time information for each  */
S_CpuLoad_TimeInfo CpuLoad_TimeInfo[CpuLoad_Index_Total]={0};
S_CpuLoad_Info CpuLoad_Percent;
/* Initial Function */
void CpuLoad_Init(void)
{
#if (CpuloadMonitor_Enable == STD_ON)
	uint8 index;
	for(index=0;index<CpuLoad_Index_Total;index++)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Max = 0;
		CpuLoad_TimeInfo[index].ElapsedTime_Min = 0xFFFFFFFF;
		CpuLoad_TimeInfo[index].ElapsedTime_Aver = 0;
		CpuLoad_TimeInfo[index].ElapsedTime_Sum = 0;
	}

	CpuLoad_Percent.MaxValue = 0.0f;
	CpuLoad_Percent.MinValue = 1000.0f;
	CpuLoad_Percent.AverValue = 0.0f;
	
	//Stim_Drv_StartTimer(0,0,0xFFFFFFFF);
	Gpt_StartTimer(0, 40000);
    //Gpt_EnableNotification(0);
#endif
}

/* Record Entry Point */
void CpuLoad_EntryTime(uint8 index)
{
#if (CpuloadMonitor_Enable == STD_ON)
	CpuLoad_TimeInfo[index].EntryTime = Gpt_GetTimeElapsed(0);//Stim_Drv_GetCurrentCounterValue(0,0)/10; //unit: us
	
#endif
}

/* Record Exit Point */
void CpuLoad_ExitTime(uint8 index)
{
#if (CpuloadMonitor_Enable == STD_ON)
	uint32 value;
	value = Gpt_GetTimeElapsed(0);//Stim_Drv_GetCurrentCounterValue(0,0)/10;

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
#endif
}

/* Calculate CPU load Information  */
void CpuLoad_Calculation(void)
{
#if (CpuloadMonitor_Enable == STD_ON)
	uint8 index;
	uint32 Sum = 0;
	
	for(index=CpuLoad_Index_5ms;index<=CpuLoad_Index_100ms;index++)
	{
		Sum += CpuLoad_TimeInfo[index].ElapsedTime_Sum;
	}
	for(index=0;index<CpuLoad_Index_Total;index++)
	{
		CpuLoad_TimeInfo[index].ElapsedTime_Sum = 0;
	}
	CpuLoad_Percent.RealValue = ((float32)Sum / (float32)200000.0f)*100.0f;

	if(CpuLoad_Percent.MaxValue < CpuLoad_Percent.RealValue)
	{
		CpuLoad_Percent.MaxValue = CpuLoad_Percent.RealValue;
	}
	if(CpuLoad_Percent.MinValue > CpuLoad_Percent.RealValue)
	{
		CpuLoad_Percent.MinValue = CpuLoad_Percent.RealValue;
	}
	
	if(CpuLoad_Percent.AverValue == 0)
	{
		CpuLoad_Percent.AverValue = CpuLoad_Percent.RealValue;
	}
	else
	{
		CpuLoad_Percent.AverValue = (CpuLoad_Percent.AverValue + CpuLoad_Percent.RealValue)/2.0f;
	}
#endif
}
