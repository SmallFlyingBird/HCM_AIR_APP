#ifndef SAFETYDRV_H
#define SAFETYDRV_H

#include "HcmPlatform.h"

#define SAFETEY_MECHANISMS_ON 0

void SafetyTask20ms(void);
void SafetyStartupTest(void);

// htmss
void Safety_Htmsstest(void);

// tdg
void Safety_TdgOutputCheckStart(uint8_t adcGroupId);
void Safety_TdgOutputCheckEnd(uint8_t adcGroupId); 

// inner 

// 测试项
typedef enum {
    SAFETY_STL_OOR,                     // 上电内核测试
    SAFETY_STL_OL_TIME,                 // 周期内核测试 
    SAFETY_TDG,
    SAFETY_PMU_BANDGAP,
    SAFETY_MSTP_REG_CHECK,              // 配置寄存器检查
    SAFETY_MSTP_READ_DELAY_REG,
    SAFETY_MSTP_RAM_RW,
    SAFETY_MEH_LATEN_SBE,
    SAFETY_FLS_VERIFY_WRITE,
    // SAFETY_MEH_SERU,                    // 故障中心
    SAFETY_HTMSS,                       // 上电自测
    SAFETY_CMU,
    SAFETY_ADC_SELF_TEST,
    SAFETY_ADC_TIMEOUT,
    SAFETY_NULL,
}SafetyTestPro;

typedef enum {
    SAFETY_NORMAL,
    SAFETY_ERROR,
    SAFETY_INVALID
}SafetyTestRes;

void Safety_SetTestRes(SafetyTestPro test,  SafetyTestRes res);

// 时钟监控
void Safety_CmuInit(void);
void Safety_CmuMonitor(void);
void Safety_CmuMeasure(void);

// 寄存器与memory测试
void Safety_MstpInit(void);
void Safety_MstpRegCheck(void);
void Safety_MstpRamTst(void);
void SafeTy_MstpReadDelayRegisterCheck(void);

// meh处理器错误处理
void Safety_MehInit(void);
void Safety_MehSramInject(void);
void Safety_MehSeruInject(void);

// mpu
void Safety_Mpuinit(void);
boolean Safety_MpuStart(void);
void Safety_MpuReadTst(void);
void Safety_MpuWriteTstAllow(void);
void Safety_MpuWriteTstNotAllow(void);
void Safety_MpuSetAllow(void);
void Safety_MpuSettNotAllow(void);

// pmu
void Safety_MpuBandgapCheck(void);

// Fls ECC
void Safety_FlsEccInject(void);
void Safety_LatenSBEDetection(void);

// Core test
void Safety_CoreSwSelfTest(void);
void Safety_StlOlTst(void);

#endif