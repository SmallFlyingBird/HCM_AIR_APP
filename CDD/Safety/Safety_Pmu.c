#include "SafetyDrv.h"
#include "AdcDrv.h"
#include "Adc.h"
#include "Adc_Cfg.h"
#include "Adc_Types.h"
#include "GeneralFunction.h"

#define BANDGAP_ARRAY_NUM   (3U)
#define BANDGAP_NUM         (2U)
#define BANDGAP_VAILD_VAL   (0xFFFF)
#define BANDGAP_HIGH_VAL    (900U)      // 1.1v -> 12位AD采样精度
#define BANDGAP_LOW_VAL     (737U)      // 0.9v -> 12位AD采样精度

typedef enum
{
    BandGap0 = 11, // ch20 在AdcConvertBuffer[MAX_ADC_DRV_NUM]中的位置;
    BandGap1 = 16
} Bandgap;

typedef struct
{
    Bandgap bandgap;
    uint16_t bandgapVal[BANDGAP_ARRAY_NUM];
    uint8_t bandgapReadIndex;
    uint16_t bandgapAraVal;
} BandgapCheck;

static BandgapCheck g_bandgapCheck[BANDGAP_NUM] = {
    {
        .bandgap = BandGap0,
        .bandgapVal = {0},
        .bandgapVal = 0,
        .bandgapAraVal = BANDGAP_VAILD_VAL,
    },
    {
        .bandgap = BandGap1,
        .bandgapVal = {0},
        .bandgapVal = 0,
        .bandgapAraVal = BANDGAP_VAILD_VAL,
    }
};

static Std_ReturnType Safety_BandgapMain(uint8_t bandgap)
{
    Std_ReturnType rtval = E_OK;

    uint8_t i = 0;
    for (i = 0; i < BANDGAP_NUM; i++)
    {
        if (g_bandgapCheck[i].bandgap == bandgap)
        {
            break;
        }
    }

    uint16_t bandgapAdVal = 0;
    if (CddDriver_GetAdcRes(g_bandgapCheck[i].bandgap, &bandgapAdVal))
    {
        return E_NOT_OK;
    }

    if (g_bandgapCheck[i].bandgapAraVal == BANDGAP_VAILD_VAL)
    {
        g_bandgapCheck[i].bandgapVal[g_bandgapCheck[i].bandgapReadIndex] = bandgapAdVal;
        if (g_bandgapCheck[i].bandgapReadIndex >= (BANDGAP_ARRAY_NUM - 1))
        {
            /*计算平均值*/
            g_bandgapCheck[i].bandgapAraVal = CalArrayAverageValue_Uint32(g_bandgapCheck[i].bandgapVal, BANDGAP_ARRAY_NUM);
        }
    }
    else
    {
        g_bandgapCheck[i].bandgapVal[g_bandgapCheck[i].bandgapReadIndex] = bandgapAdVal;
        g_bandgapCheck[i].bandgapAraVal = CalArrayAverageValue_Uint32(g_bandgapCheck[i].bandgapVal, BANDGAP_ARRAY_NUM);
    }

    if (g_bandgapCheck[i].bandgapAraVal != BANDGAP_VAILD_VAL)
    {
        if ((g_bandgapCheck[i].bandgapAraVal > BANDGAP_HIGH_VAL) || (g_bandgapCheck[i].bandgapAraVal < BANDGAP_LOW_VAL))
        {
            // bandgap 错误处理
            rtval = E_OK;
        }
    }

    g_bandgapCheck[i].bandgapReadIndex++;
    if (g_bandgapCheck[i].bandgapReadIndex >= BANDGAP_ARRAY_NUM)
        g_bandgapCheck[i].bandgapReadIndex = 0;

    return rtval;
}

void Safety_MpuBandgapCheck(void)
{
    Std_ReturnType bandgap0 = Safety_BandgapMain(BandGap0);
    Std_ReturnType bandgap1 = Safety_BandgapMain(BandGap1);
    // 不做动作，记录错误
    if((bandgap0 | bandgap1) != E_OK){
        Safety_SetTestRes(SAFETY_PMU_BANDGAP, SAFETY_ERROR);
    }

    Safety_SetTestRes(SAFETY_PMU_BANDGAP, SAFETY_NORMAL);
}