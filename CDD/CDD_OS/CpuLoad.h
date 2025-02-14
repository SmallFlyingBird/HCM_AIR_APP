#ifndef CPULOAD_H
#define CPULOAD_H

#include "Std_Types.h"

#define CpuloadMonitor_Enable STD_ON

typedef enum
{
	CpuLoad_Index_5ms,
	CpuLoad_Index_10ms,
	CpuLoad_Index_20ms,
	CpuLoad_Index_50ms,
	CpuLoad_Index_100ms,
	CpuLoad_Index_Uart_Drv_3_Irq,
	CpuLoad_Index_Tim_Drv_0_ChIrq,
	CpuLoad_Index_Tim_Drv_0_OverflowIrq,
	CpuLoad_Index_Tim_Drv_1_ChIrq,
	CpuLoad_Index_Tim_Drv_1_OverflowIrq,
	CpuLoad_Index_Adc_Drv_0_Irq,
	CpuLoad_Index_Adc_Drv_1_Irq,
	CpuLoad_Index_Total
} CpuLoad_Index_Tyde;

typedef struct{
	uint32 EntryTime;
	uint32 ExitTime;
	uint32 ElapsedTime;
	uint32 ElapsedTime_Max;
	uint32 ElapsedTime_Aver;
	uint32 ElapsedTime_Min;
	uint32 ElapsedTime_Sum;
} S_CpuLoad_TimeInfo;

typedef struct{
	float32 RealValue;
	float32 MaxValue;
	float32 MinValue;
	float32 AverValue;
} S_CpuLoad_Info;

extern void CpuLoad_Init(void);
extern void CpuLoad_EntryTime(uint8 index);
extern void CpuLoad_ExitTime(uint8 index);
extern void CpuLoad_Calculation(void);

#endif 
