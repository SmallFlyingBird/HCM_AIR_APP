#include "CpuLoad.h"
#include "Gpt.h"

S_CpuLoad_TimeInfo CpuLoad_TimeInfo[CpuLoad_Index_Total] = {0};
S_CpuLoad_Info CpuLoad_Percent;

#if (CpuloadMonitor_Enable == STD_ON)
#define CPULOAD_GPT_CHANNEL GptConf_GptChannelConfiguration_GptChannelConfiguration_0
/* board/Gpt_PBcfg.c: PTMR0 channel 0, continuous, 40 MHz. */
#define CPULOAD_TICKS_PER_US 40U
#define CPULOAD_WINDOW_TICKS (200000U * CPULOAD_TICKS_PER_US)
#define CPULOAD_TIMER_MAX 0xFFFFFFFFU

static uint32 CpuLoad_EntryTicks[CpuLoad_Index_Total];
static boolean CpuLoad_EntryValid[CpuLoad_Index_Total];
static uint32 CpuLoad_BusyTicks;
static uint32 CpuLoad_WindowStart;
static boolean CpuLoad_Initialized = FALSE;
#endif

void CpuLoad_Init(void)
{
#if (CpuloadMonitor_Enable == STD_ON)
    uint8 index;
    if (CpuLoad_Initialized)
    {
        return;
    }
    for (index = 0U; index < CpuLoad_Index_Total; index++)
    {
        CpuLoad_TimeInfo[index].EntryTime = 0U;
        CpuLoad_TimeInfo[index].ExitTime = 0U;
        CpuLoad_TimeInfo[index].ElapsedTime = 0U;
        CpuLoad_TimeInfo[index].ElapsedTime_Max = 0U;
        CpuLoad_TimeInfo[index].ElapsedTime_Min = CPULOAD_TIMER_MAX;
        CpuLoad_TimeInfo[index].ElapsedTime_Aver = 0U;
        CpuLoad_TimeInfo[index].ElapsedTime_Sum = 0U;
        CpuLoad_EntryValid[index] = FALSE;
    }
    CpuLoad_Percent.RealValue = 0.0f;
    CpuLoad_Percent.MaxValue = 0.0f;
    CpuLoad_Percent.MinValue = 100.0f;
    CpuLoad_Percent.AverValue = 0.0f;
    CpuLoad_BusyTicks = 0U;

    /* A 1 ms period loses wraps inside a task. Use the full 32-bit range:
     * 107.3741824 s at 40 MHz, without a periodic timer interrupt. */
    Gpt_StartTimer(CPULOAD_GPT_CHANNEL, CPULOAD_TIMER_MAX);
    CpuLoad_WindowStart = Gpt_GetTimeElapsed(CPULOAD_GPT_CHANNEL);
    CpuLoad_Initialized = TRUE;
#endif
}

void CpuLoad_EntryTime(uint8 index)
{
#if (CpuloadMonitor_Enable == STD_ON)
    uint32 ticks;
    if ((!CpuLoad_Initialized) || (index >= CpuLoad_Index_Total))
    {
        return;
    }
    ticks = Gpt_GetTimeElapsed(CPULOAD_GPT_CHANNEL);
    CpuLoad_EntryTicks[index] = ticks;
    CpuLoad_TimeInfo[index].EntryTime = ticks / CPULOAD_TICKS_PER_US;
    CpuLoad_EntryValid[index] = TRUE;
#endif
}

void CpuLoad_ExitTime(uint8 index)
{
#if (CpuloadMonitor_Enable == STD_ON)
    uint32 ticks;
    uint32 elapsedTicks;
    uint32 elapsedUs;
    if ((!CpuLoad_Initialized) || (index >= CpuLoad_Index_Total))
    {
        return;
    }
    if (!CpuLoad_EntryValid[index])
    {
        return;
    }
    ticks = Gpt_GetTimeElapsed(CPULOAD_GPT_CHANNEL);
    /* Unsigned subtraction handles equal readings and one 32-bit wrap.
     * A measured task must complete within one timer period. */
    elapsedTicks = ticks - CpuLoad_EntryTicks[index];
    elapsedUs = elapsedTicks / CPULOAD_TICKS_PER_US;
    CpuLoad_EntryValid[index] = FALSE;
    CpuLoad_TimeInfo[index].ExitTime = ticks / CPULOAD_TICKS_PER_US;
    CpuLoad_TimeInfo[index].ElapsedTime = elapsedUs;

    if (CpuLoad_TimeInfo[index].ElapsedTime_Max < elapsedUs)
    {
        CpuLoad_TimeInfo[index].ElapsedTime_Max = elapsedUs;
    }
    if (CpuLoad_TimeInfo[index].ElapsedTime_Min > elapsedUs)
    {
        CpuLoad_TimeInfo[index].ElapsedTime_Min = elapsedUs;
    }
    if (CpuLoad_TimeInfo[index].ElapsedTime_Aver == 0U)
    {
        CpuLoad_TimeInfo[index].ElapsedTime_Aver = elapsedUs;
    }
    else
    {
        CpuLoad_TimeInfo[index].ElapsedTime_Aver =
            (elapsedUs + CpuLoad_TimeInfo[index].ElapsedTime_Aver) / 2U;
    }
    CpuLoad_TimeInfo[index].ElapsedTime_Sum += elapsedUs;
    if (index <= CpuLoad_Index_100ms)
    {
        /* Preserve sub-microsecond precision when computing load. */
        CpuLoad_BusyTicks += elapsedTicks;
    }
#endif
}

void CpuLoad_Calculation(void)
{
#if (CpuloadMonitor_Enable == STD_ON)
    uint8 index;
    uint32 now;
    uint32 windowTicks;
    if (!CpuLoad_Initialized)
    {
        return;
    }
    now = Gpt_GetTimeElapsed(CPULOAD_GPT_CHANNEL);
    windowTicks = now - CpuLoad_WindowStart;
    if (windowTicks < CPULOAD_WINDOW_TICKS)
    {
        return;
    }

    /* Called between tasks: no SysTick read/reset can interrupt an update.
     * Use the actual window length if a task delays the 200 ms boundary. */
    CpuLoad_Percent.RealValue =
        ((float32)CpuLoad_BusyTicks / (float32)windowTicks) * 100.0f;
    CpuLoad_WindowStart = now;
    CpuLoad_BusyTicks = 0U;
    for (index = 0U; index < CpuLoad_Index_Total; index++)
    {
        CpuLoad_TimeInfo[index].ElapsedTime_Sum = 0U;
    }
    if (CpuLoad_Percent.MaxValue < CpuLoad_Percent.RealValue)
    {
        CpuLoad_Percent.MaxValue = CpuLoad_Percent.RealValue;
    }
    if (CpuLoad_Percent.MinValue > CpuLoad_Percent.RealValue)
    {
        CpuLoad_Percent.MinValue = CpuLoad_Percent.RealValue;
    }
    if (CpuLoad_Percent.AverValue == 0.0f)
    {
        CpuLoad_Percent.AverValue = CpuLoad_Percent.RealValue;
    }
    else
    {
        CpuLoad_Percent.AverValue =
            (CpuLoad_Percent.AverValue + CpuLoad_Percent.RealValue) / 2.0f;
    }
#endif
}
