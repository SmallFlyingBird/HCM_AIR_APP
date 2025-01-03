#include "SafetyDrv.h"
#include "Gpt.h"
#include "Adc_Cfg.h"

#define SAFETY_TDG_CONVER_TIME_COPE         (0.5f)
#define SAFETY_TDG_CONVER_TIME_EX_COUNT     (8U) // 当前转换定时器最快100us，单次转换预计7~800us

typedef struct
{
    uint32_t acTime;
    uint32_t exTime;
    uint32_t acCount;
    uint32_t exCount;
} SafetyTdgCheck;

static SafetyTdgCheck g_tdgCheck[ADC_MAX_GROUPS] = {
    {0, SAFETY_TDG_CONVER_TIME_EX_COUNT, 0, 1},
    {0, SAFETY_TDG_CONVER_TIME_EX_COUNT, 0, 1},
    {0, SAFETY_TDG_CONVER_TIME_EX_COUNT, 0, 1},
};

static uint32_t StimCount = 0;
void TaskNotificationTdgAdcCheck(void)
{
    StimCount++;
}

void Safety_TdgOutputCheckStart(uint8_t adcGroupId)
{
    if (adcGroupId >= ADC_MAX_GROUPS)
    {
        return;
    }

    StimCount = 0;  // 从触发开始计时
    g_tdgCheck[adcGroupId].acCount++;
}

void Safety_TdgOutputCheckEnd(uint8_t adcGroupId)
{
    if (adcGroupId >= ADC_MAX_GROUPS)
    {
        return;
    }

    g_tdgCheck[adcGroupId].acTime = StimCount;

    if (g_tdgCheck[adcGroupId].acCount != g_tdgCheck[adcGroupId].exCount)
    {
        // tdg 触发次数不符合预期
        Safety_SetTestRes(SAFETY_TDG, SAFETY_ERROR);
        return;
    }

    if ((g_tdgCheck[adcGroupId].acTime > g_tdgCheck[adcGroupId].exTime * (1.0 + SAFETY_TDG_CONVER_TIME_COPE)) ||
        (g_tdgCheck[adcGroupId].acTime < g_tdgCheck[adcGroupId].exTime * (1.0 - SAFETY_TDG_CONVER_TIME_COPE)))
    {
        // tdg 转换时间不符合预期
        Safety_SetTestRes(SAFETY_TDG, SAFETY_ERROR);
        return;
    }

    g_tdgCheck[adcGroupId].acCount = 0;
    g_tdgCheck[adcGroupId].acTime = 0;

    Safety_SetTestRes(SAFETY_TDG, SAFETY_NORMAL);
}
