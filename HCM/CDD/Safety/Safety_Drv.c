#include "SafetyDrv.h"
#include "Mcu.h"

#define FLS_ECC_INJECT 0
#define SRAM_ECC_INJECT 0
#define SERU_ECC_INJECT 0
#define MPU_ADDR_INJECT 0

void SafetyTask20ms(void)
{
#if SAFETEY_MECHANISMS_ON
    return;

    static uint8_t time = 0;
    // 100ms
    if (time == 5) 
    { 
        Safety_CmuMeasure();
        Safety_MstpRamTst();
        Safety_MpuBandgapCheck();
        SafeTy_MstpReadDelayRegisterCheck();
        Safety_StlOlTst();
        time = 0;
    }
    time++;
#endif
}

void SafetyStartupTest(void)
{
#if SAFETEY_MECHANISMS_ON
    Safety_MstpInit();
    Safety_MstpRegCheck();

    Safety_CmuInit();
    Safety_CmuMonitor();

    Safety_MehInit();

    Safety_Mpuinit();

    Safety_LatenSBEDetection();

#if FLS_ECC_INJECT
    Safety_FlsEccInject(); // flash MBE 手动注入
#endif

#if SRAM_ECC_INJECT
    Safety_MehSramInject(); // SRAM手动注入
#endif

#if SERU_ECC_INJECT
    Safety_MehSeruInject(); // 软件通道注入
#endif

#if MPU_ADDR_INJECT
    // mup 读写测试, 配置 默认 可读/不可写/可执行
    Safety_MpuReadTst();
    Safety_MpuWriteTstAllow();
    Safety_MpuWriteTstNotAllow();
#endif
#endif
}

typedef enum {
    SAFETY_REC_DTC,
    SAFETY_REC_REG_FILE,
    SAFETY_REC_NULL,
}SafetyTestRec;

typedef enum {
    SAFETY_ACT_RESET,
    SAFETY_ACT_REINIT,
    SAFETY_ACT_NULL,
}SafetyTestAct;

typedef struct
{
    SafetyTestPro test;
    SafetyTestRes res;
    SafetyTestRec rec;
    SafetyTestAct act;
}SafetyTestResSummary;

static SafetyTestResSummary g_resSumary[] = {
    {SAFETY_STL_OOR,                SAFETY_INVALID,     SAFETY_REC_NULL,    SAFETY_ACT_RESET},
    {SAFETY_STL_OL_TIME,            SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_RESET},
    {SAFETY_TDG,                    SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_RESET},
    {SAFETY_PMU_BANDGAP,            SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_NULL},
    {SAFETY_MSTP_REG_CHECK,         SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_RESET},
    {SAFETY_MSTP_READ_DELAY_REG,    SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_REINIT},
    {SAFETY_MSTP_RAM_RW,            SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_RESET},
    {SAFETY_MEH_LATEN_SBE,          SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_NULL},
    {SAFETY_FLS_VERIFY_WRITE,       SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_NULL},   // TODO  待实现
    // {SAFETY_MEH_SERU,               SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_NULL},
    {SAFETY_HTMSS,                  SAFETY_INVALID,     SAFETY_REC_NULL,    SAFETY_ACT_RESET},
    {SAFETY_CMU,                    SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_RESET},
    {SAFETY_ADC_SELF_TEST,          SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_RESET},  // TODO  待实现
    {SAFETY_ADC_TIMEOUT,            SAFETY_INVALID,     SAFETY_REC_DTC,     SAFETY_ACT_REINIT},
    {SAFETY_NULL,                   SAFETY_INVALID,     SAFETY_REC_NULL,    SAFETY_ACT_NULL},
};

static void Safety_UpdataRes(SafetyTestPro test,  SafetyTestRes res) 
{
    for(uint8_t i = 0; i < SAFETY_NULL; i++) {
        if(g_resSumary[i].test == test) {
            g_resSumary[i].res = res;
            return;
        }
    }
}

static void Safety_RecordErr(SafetyTestPro test, SafetyTestRes res)
{
    if(res != SAFETY_ERROR) {
        return;
    }

    if((res == SAFETY_ERROR) && g_resSumary[test].rec == SAFETY_REC_DTC) {
        // 记录dtc    
    }
}

static void Safety_ErrAct(SafetyTestPro test, SafetyTestRes res)
{
    if(res != SAFETY_ERROR) {
        return;
    }

    if((res == SAFETY_ERROR) && g_resSumary[test].act == SAFETY_ACT_RESET) {
        Mcu_PerformReset();
    }
}

void Safety_SetTestRes(SafetyTestPro test,  SafetyTestRes res)
{
#if SAFETEY_MECHANISMS_ON
    Safety_UpdataRes(test, res);

    Safety_RecordErr(test, res);

    Safety_ErrAct(test,  res);
#endif
}