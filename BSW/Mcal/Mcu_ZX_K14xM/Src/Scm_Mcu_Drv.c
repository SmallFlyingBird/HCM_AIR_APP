/**************************************************************************************************/
/**
 * @file      : Scm_Mcu_Drv.c
 * @brief     : SCM low level driver source file for Autosar Mcu
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Scm_Mcu_Drv
 *  @brief SCM low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scm_Mcu_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define SCM_MCU_DRV_C_VENDOR_ID                   0x00B3U
#define SCM_MCU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCM_MCU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define SCM_MCU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define SCM_MCU_DRV_C_SW_MAJOR_VERSION            1U
#define SCM_MCU_DRV_C_SW_MINOR_VERSION            2U
#define SCM_MCU_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Scm_Mcu_Drv.h file are of the same vendor */
#if (SCM_MCU_DRV_C_VENDOR_ID != SCM_MCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Scm_Mcu_Drv.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Autosar version */
#if ((SCM_MCU_DRV_C_AR_RELEASE_MAJOR_VERSION != SCM_MCU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (SCM_MCU_DRV_C_AR_RELEASE_MINOR_VERSION != SCM_MCU_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (SCM_MCU_DRV_C_AR_RELEASE_REVISION_VERSION != SCM_MCU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Scm_Mcu_Drv.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Software version */
#if ((SCM_MCU_DRV_C_SW_MAJOR_VERSION != SCM_MCU_DRV_H_SW_MAJOR_VERSION) ||                         \
     (SCM_MCU_DRV_C_SW_MINOR_VERSION != SCM_MCU_DRV_H_SW_MINOR_VERSION) ||                         \
     (SCM_MCU_DRV_C_SW_PATCH_VERSION != SCM_MCU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Scm_Mcu_Drv.c and Scm_Mcu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((SCM_MCU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||     \
         (SCM_MCU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Scm_Mcu_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

static const uint32 Scm_Mcu_Drv_IntMaskTable[] = {
    0x00010000U, /*!< MCU_DRV_CACHE_BE_INT */
    0x01000000U, /*!< SCM_MCU_DRV_FPU_INEXACT_INT */
    0x02000000U, /*!< SCM_MCU_DRV_FPU_OVERFLOW_INT */
    0x04000000U, /*!< SCM_MCU_DRV_FPU_UNDERFLOW_INT */
    0x08000000U, /*!< SCM_MCU_DRV_FPU_INVALIDOP_INT */
    0x10000000U, /*!< SCM_MCU_DRV_FPU_DIVZERO_INT */
    0x20000000U  /*!< SCM_MCU_DRV_FPU_DENORMALIN_INT */
};

#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_PTR
#include "Mcu_MemMap.h"

/**
 *  @brief Pointer to SCM Unit Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Scm_BfType *const Scm_Mcu_Drv_ScmRegBfPtr = (Reg_Scm_BfType *)SCM_BASE_ADDR;
static Reg_Scm_WType *const  Scm_Mcu_Drv_ScmRegWPtr = (Reg_Scm_WType *)SCM_BASE_ADDR;

/**
 *  @brief Pointer to System Clock Control Unit Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
static Reg_Scc_BfType *const Scm_Mcu_Drv_SccRegBfPtr = (Reg_Scc_BfType *)SCC_BASE_ADDR;

#define MCU_STOP_SEC_CONST_PTR
#include "Mcu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/**
 * @brief      Configs interrupts of misc control in SCM.
 *
 * @param[in]  InterruptType: Interrupt type.
 * @param[in]  Enable:  Enable/disable this interrupt.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_SetInterrupt(Scm_Mcu_Drv_IntType InterruptType, boolean Enable)
{
    if (FALSE == Enable)
    {
        Scm_Mcu_Drv_ScmRegWPtr->SCM_MISCCTL1 &= (~Scm_Mcu_Drv_IntMaskTable[InterruptType]);
    }
    else
    {
        Scm_Mcu_Drv_ScmRegWPtr->SCM_MISCCTL1 |= Scm_Mcu_Drv_IntMaskTable[InterruptType];
    }
}

/**
 * @brief      Configs enable or disable SRAM read buffer.
 *
 * @param[in]  SramType: SRAM type, SRAML or SRAMU.
 * @param[in]  Enable: Enable/Disable given SRAM read buffer.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_SetSramReadBuffer(Scm_Mcu_Drv_SramType SramType, boolean Enable)
{
    if (SCM_MCU_DRV_SRAML == SramType)
    {
        Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL1.SRAML_READ_BUFF_EN = (uint32)Enable;
    }
    else if (SCM_MCU_DRV_SRAMU == SramType)
    {
        Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL1.SRAMU_READ_BUFF_EN = (uint32)Enable;
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * @brief      Configs enable or disable cache.
 *
 * @param[in]  Enable: Enable/Disable cache.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_SetCacheMode(boolean Enable)
{
    Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL1.CACHE_DIS = ~(uint32)Enable;
}

/**
 * @brief      Configs enable or disable cache parity fault.
 *
 * @param[in]  Enable: Enable/Disable cache parity fault.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_SetParityFaultMode(boolean Enable)
{
    Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL1.CCACHE_PARITY_FAULT_EN = (uint32)Enable;
}

/**
 * @brief      Configs enable or disable cache parity miss.
 *
 * @param[in]  Enable: Enable/Disable cache parity miss.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_SetParityMissMode(boolean Enable)
{
    Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL1.CCACHE_PARITY_MISS_EN = (uint32)Enable;
}

/**
 * @brief      Configs external input clock to given timer.
 *
 * @param[in]  ScmTimerType: Given timer.
 * @param[in]  ClockSource: Selected external input clock.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_ConfigTimerInput(Scm_Mcu_Drv_TimerType              ScmTimerType,
                                         Scm_Mcu_Drv_TimerExtClockInputType ClockSource)
{
    switch (ScmTimerType)
    {
        case SCM_MCU_DRV_TIM0:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.TIM0_TCLK_SEL = (uint32)ClockSource;
            break;
        case SCM_MCU_DRV_TIM1:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.TIM1_TCLK_SEL = (uint32)ClockSource;
            break;
        case SCM_MCU_DRV_TIM2:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.TIM2_TCLK_SEL = (uint32)ClockSource;
            break;
        case SCM_MCU_DRV_TIM3:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.TIM3_TCLK_SEL = (uint32)ClockSource;
            break;
        case SCM_MCU_DRV_MCPWM0:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.MCPWM0_TCLK_SEL = (uint32)ClockSource;
            break;
        case SCM_MCU_DRV_MCPWM1:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.MCPWM1_TCLK_SEL = (uint32)ClockSource;
            break;
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Configs mux to given ADC channel.
 *
 * @param[in]  ChannelType: Given ADC channel.
 * @param[in]  MuxSelectSource: Selected mux.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_ConfigAdcChannelMux(Scm_Mcu_Drv_AdcChannelSelectType ChannelType,
                                            Scm_Mcu_Drv_AdcMuxSelectType     MuxSelectSource)
{
    switch (ChannelType)
    {
        case SCM_MCU_DRV_ADC1CH15:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.ADC1_CH15_SEL = (uint32)MuxSelectSource;
            break;
        case SCM_MCU_DRV_ADC1CH14:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.ADC1_CH14_SEL = (uint32)MuxSelectSource;
            break;
        case SCM_MCU_DRV_ADC0CH9:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.ADC0_CH9_SEL = (uint32)MuxSelectSource;
            break;
        case SCM_MCU_DRV_ADC0CH8:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_MISCCTL2.ADC0_CH8_SEL = (uint32)MuxSelectSource;
            break;
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      Configs which SCC clock source is selected to be ported out to the CLKOUT pin.
 *
 * @param[in]  OutputSrc:  Selected clock source.
 * @param[in]  OutputDivider: Clock out divider.
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_ConfigClockOut(Scm_Mcu_Drv_ClockOutSrcType OutputSrc,
                                       Scm_Mcu_Drv_ClockOutDivType OutputDivider)
{
    /* Disable clock out before switching */
    Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTEN = 0U;

    switch (OutputSrc)
    {
        case SCM_MCU_DRV_CLOCK_OUT_DISABLED:
        case SCM_MCU_DRV_CLOCK_OUT_FIRC64M:
        case SCM_MCU_DRV_CLOCK_OUT_FOSC:
        case SCM_MCU_DRV_CLOCK_OUT_PLL:
        case SCM_MCU_DRV_CLOCK_OUT_SLOW:
        case SCM_MCU_DRV_CLOCK_OUT_BUS:
        case SCM_MCU_DRV_CLOCK_OUT_CORE:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTSEL = 0U;
            Scm_Mcu_Drv_SccRegBfPtr->SCC_CLKOUTCFG.CLKOUTSEL = (uint32)OutputSrc;
            break;

        case SCM_MCU_DRV_CLOCK_OUT_SOSC:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTSEL = 1U;
            break;

        case SCM_MCU_DRV_CLOCK_OUT_LPO32K:
            Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTSEL = 2U;
            break;

        default:
            /* Do nothing */
            break;
    }

    Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTDIV = (uint32)OutputDivider;

    /* Enable clock out after switching */
    Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTEN = 1U;
}

/**
 * @brief      Disables clock output.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
static void Scm_Mcu_Drv_DisableClockOut(void)
{
    Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTEN = 0U;
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief      Initializes the SCM configure.
 *
 * @param[in]  ConfigPtr: Pointer to the SCM configuration.
 *
 * @return     None
 *
 */
void Scm_Mcu_Drv_Init(const Scm_Mcu_Drv_ConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        /* Configure SCM Misc Control 1 register */
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_CCACHE_BE_INT, ConfigPtr->CacheBEInterruptEnable);
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_FPU_INEXACT_INT, ConfigPtr->FpuInExactInterruptEnable);
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_FPU_OVERFLOW_INT,
                                 ConfigPtr->FpuOverflowInterruptEnable);
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_FPU_UNDERFLOW_INT,
                                 ConfigPtr->FpuUnderflowInterruptEnable);
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_FPU_INVALIDOP_INT,
                                 ConfigPtr->FpuInvalidOPInterruptEnable);
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_FPU_DIVZERO_INT, ConfigPtr->FpuDivzeroInterruptEnable);
        Scm_Mcu_Drv_SetInterrupt(SCM_MCU_DRV_FPU_DENORMALIN_INT,
                                 ConfigPtr->FpuDenormalInterruptEnable);

        Scm_Mcu_Drv_SetSramReadBuffer(SCM_MCU_DRV_SRAML, ConfigPtr->SramLReadBufferEnable);
        Scm_Mcu_Drv_SetSramReadBuffer(SCM_MCU_DRV_SRAMU, ConfigPtr->SramUReadBufferEnable);

        Scm_Mcu_Drv_SetCacheMode(ConfigPtr->CacheEnable);
        Scm_Mcu_Drv_SetParityFaultMode(ConfigPtr->CacheParityFaultEnable);
        Scm_Mcu_Drv_SetParityMissMode(ConfigPtr->CacheParityMissEnable);

        /* SCM Misc Control 2 register */
        Scm_Mcu_Drv_ConfigTimerInput(SCM_MCU_DRV_TIM0, ConfigPtr->Tim0Select);
        Scm_Mcu_Drv_ConfigTimerInput(SCM_MCU_DRV_TIM1, ConfigPtr->Tim1Select);
        Scm_Mcu_Drv_ConfigTimerInput(SCM_MCU_DRV_TIM2, ConfigPtr->Tim2Select);
        Scm_Mcu_Drv_ConfigTimerInput(SCM_MCU_DRV_TIM3, ConfigPtr->Tim3Select);
        Scm_Mcu_Drv_ConfigTimerInput(SCM_MCU_DRV_MCPWM0, ConfigPtr->Mcpwm0Select);
        Scm_Mcu_Drv_ConfigTimerInput(SCM_MCU_DRV_MCPWM1, ConfigPtr->Mcpwm1Select);

        Scm_Mcu_Drv_ConfigAdcChannelMux(SCM_MCU_DRV_ADC1CH15, ConfigPtr->Adc1Ch15Select);
        Scm_Mcu_Drv_ConfigAdcChannelMux(SCM_MCU_DRV_ADC1CH14, ConfigPtr->Adc1Ch14Select);
        Scm_Mcu_Drv_ConfigAdcChannelMux(SCM_MCU_DRV_ADC0CH9, ConfigPtr->Adc0Ch9Select);
        Scm_Mcu_Drv_ConfigAdcChannelMux(SCM_MCU_DRV_ADC0CH8, ConfigPtr->Adc0Ch8Select);
    }
}

/**
 * @brief    Initializes the SCM clock.
 *
 * @param[in]  ScmClockConfigPtr: Pointer to the SCM clock configuration.
 *
 * @return     None
 *
 */
void Scm_Mcu_Drv_InitClockOut(const Scm_Mcu_Drv_ClockConfigType *ScmClockConfigPtr)
{
    if (NULL_PTR != ScmClockConfigPtr)
    {
        if (TRUE == ScmClockConfigPtr->ScmClockOutputConfig.Enable)
        {
            Scm_Mcu_Drv_ConfigClockOut(
                ScmClockConfigPtr->ScmClockOutputConfig.ScmClockOutputSrc,
                ScmClockConfigPtr->ScmClockOutputConfig.ScmClockOutputDivider);
        }
        else
        {
            Scm_Mcu_Drv_DisableClockOut();
        }
    }
}

/**
 * @brief    Updates clock out configuration if core clock selected as clock out source and core
 * clock source changed.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Scm_Mcu_Drv_UpdateClockOut(void)
{
    uint32 OutputDivider = Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTDIV;

    if ((0U == Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTSEL) &&
        ((uint32)SCM_MCU_DRV_CLOCK_OUT_CORE == Scm_Mcu_Drv_SccRegBfPtr->SCC_CLKOUTCFG.CLKOUTSEL))
    {
        /* Disable clock out before switching */
        Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTEN = 0U;

        Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTSEL = 0U;
        Scm_Mcu_Drv_SccRegBfPtr->SCC_CLKOUTCFG.CLKOUTSEL = (uint32)SCM_MCU_DRV_CLOCK_OUT_CORE;

        Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTDIV = (uint32)OutputDivider;

        /* Enable clock out after switching */
        Scm_Mcu_Drv_ScmRegBfPtr->SCM_CHIPCTL.CLKOUTEN = 1U;
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Scm_Mcu_Drv */

/** @} end of group Mcu_Module */
