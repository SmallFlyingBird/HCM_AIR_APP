#include "SafetyDrv.h"
#include "Cmu.h"
#include "Scc_Drv.h"
/*
        Monitored clock      Reference clock
CMU0    Bus clock(80MHZ)        FIRC64M clock (64MHZ)
CMU1    FIRC64M clock           OSC40M clock (24M)
CMU2    LPO32K clock(32KHZ)     OSC40M clock
 */

typedef struct Safety_Cmu
{
    uint8_t cmuBusClockHighFlag;
    uint8_t cmuBusClockLowFlag;
    uint8_t cmuFIRC64HighFlag;
    uint8_t cmuFIRC64LowFlag;
    uint8_t cmuLPO32kHighFlag;
    uint8_t cmuLPO32kLowFlag;
    uint32_t tkk;
} SafetyCmuInfo;

SafetyCmuInfo g_cmuInfo = {0};

void CmuBusHighNotification(void)
{
    Safety_SetTestRes(SAFETY_CMU, SAFETY_ERROR);
    g_cmuInfo.cmuBusClockHighFlag++;
}

void CmuBusLowNotification(void)
{
    Safety_SetTestRes(SAFETY_CMU, SAFETY_ERROR);
    g_cmuInfo.cmuBusClockHighFlag++;
}

void CmuFIRC64HighNotification(void)
{
    Safety_SetTestRes(SAFETY_CMU, SAFETY_ERROR);
    g_cmuInfo.cmuFIRC64HighFlag++;
}

void CmuFIRC64LowNotification(void)
{
    Safety_SetTestRes(SAFETY_CMU, SAFETY_ERROR);
    g_cmuInfo.cmuFIRC64LowFlag++;
}

void CmuLPO32KHighNotification(void)
{
    Safety_SetTestRes(SAFETY_CMU, SAFETY_ERROR);
    g_cmuInfo.cmuLPO32kHighFlag++;
}

void CmuLPO32KLowNotification(void)
{
    Safety_SetTestRes(SAFETY_CMU, SAFETY_ERROR);
    g_cmuInfo.cmuFIRC64LowFlag++;
}

void Safety_CmuInit(void)
{
    Cmu_Init(&Cmu_Config);
}

// CMU1 监控模式
void Safety_CmuMonitor(void)
{
    Cmu_SetClockMonitorState(CmuConf_CmuSettingConfig_CmuSettingConfig_BusClock, 1);
    Cmu_SetClockMonitorState(CmuConf_CmuSettingConfig_CmuSettingConfig_FIRC64, 1);
    Cmu_SetClockMonitorState(CmuConf_CmuSettingConfig_CmuSettingConfig_LPO32K, 1);
    Safety_SetTestRes(SAFETY_CMU, SAFETY_NORMAL);
}

void Sfety_CmuTst(void)
{
    Scc_Drv_DisableFirc64MClockMonitor();
}

/** CMU1 测量模式
 * @brief   This use case will use CMU1 to measure FIRC64M clock and
 *          get measure result.
 *          CMU1用于监控时钟 FIRC64M clock,时钟源为 OSC40M clock
 *          当设置 被检测时钟的时钟源的计数器Mod值为：10000
 *          监测阈值计算: 1/64 * count = 1/40 * 10000，count=16000
 */
typedef struct
{
    uint32_t expectedValue;
    uint32 measureHiThreshold;
    uint32 measureLowThreshold;
} CmuMeasure;

static const CmuMeasure g_cmuMeasure[3] = {
    {
        .expectedValue = 37500, // 监测阈值计算: 1/80 * count = 1/64 * 30000(win)，count=37500
        .measureHiThreshold = 39750,
        .measureLowThreshold = 34500,
    },
    {
        .expectedValue = 80000, // 监测阈值计算: 1/64 * count = 1/24 * 30000(win)，count=80000
        .measureHiThreshold = 84800,
        .measureLowThreshold = 73600,
    },
    {
        .expectedValue = 40, // 监测阈值计算: 1/0.032 * count = 1/24 * 30000(win)，count=40
        .measureHiThreshold = 48,
        .measureLowThreshold = 32,
    }
};

static boolean Cmu_Measure(Cmu_IdType cmuId)
{
    boolean RetVal = FALSE;
    Std_ReturnType CurrentStatus = E_NOT_OK;
    static uint32_t MeasureResult = 0U;
    boolean MeasureCompleteState = 0U;
    uint32_t MeasureHiThreshold = g_cmuMeasure[cmuId].measureHiThreshold;
    uint32_t MeasureLowThreshold = g_cmuMeasure[cmuId].measureLowThreshold;
    /* Disable Cmu1*/
    Cmu_SetClockMonitorState(cmuId, 0U);

    /* Set Cmu to measure mode*/
    CurrentStatus = Cmu_SetClockMonitorMode(cmuId, CMU_MEASURE_MODE);

    if (E_OK == CurrentStatus)
    {
        /* Start Measure */
        CurrentStatus = Cmu_StartMeasure(cmuId);

        /* Wait measure complete */
        while (1U != MeasureCompleteState)
        {
            CurrentStatus = Cmu_GetMeasureStatus(cmuId, &MeasureCompleteState);
        }

        /* Get measure result 获取测量的结果*/
        CurrentStatus = Cmu_GetMeasureResult(cmuId, &MeasureResult);

        if (E_OK == CurrentStatus)
        {
            if (MeasureResult < MeasureHiThreshold && MeasureResult > MeasureLowThreshold)
            {
                RetVal = TRUE;
            }
        }
    }
    return RetVal;
}

void Safety_CmuMeasure(void)
{


    //Cmu_Measure(CmuConf_CmuSettingConfig_CmuSettingConfig_LPO32K);
}