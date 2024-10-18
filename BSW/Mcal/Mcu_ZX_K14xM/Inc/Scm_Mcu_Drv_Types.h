/**************************************************************************************************/
/**
 * @file      : Scm_Mcu_Drv_Types.h
 * @brief     : SCM low level driver type definition header file for Autosar Mcu
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCM_MCU_DRV_TYPES_H
#define SCM_MCU_DRV_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu_Drv
 *  @brief SCM low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scm_Mcu_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SCM_MCU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define SCM_MCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCM_MCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SCM_MCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SCM_MCU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define SCM_MCU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define SCM_MCU_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Scm_Mcu_Drv_Cfg.h file are of the same vendor */
#if (SCM_MCU_DRV_TYPES_H_VENDOR_ID != SCM_MCU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Scm_Mcu_Drv_Types.h and Scm_Mcu_Drv_Cfg.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Cfg.h file are of the same Autosar version */
#if ((SCM_MCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION !=                                              \
      SCM_MCU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||                                               \
     (SCM_MCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION !=                                              \
      SCM_MCU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||                                               \
     (SCM_MCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                           \
      SCM_MCU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Scm_Mcu_Drv_Types.h and Scm_Mcu_Drv_Cfg.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Cfg.h file are of the same Software version */
#if ((SCM_MCU_DRV_TYPES_H_SW_MAJOR_VERSION != SCM_MCU_DRV_CFG_H_SW_MAJOR_VERSION) ||               \
     (SCM_MCU_DRV_TYPES_H_SW_MINOR_VERSION != SCM_MCU_DRV_CFG_H_SW_MINOR_VERSION) ||               \
     (SCM_MCU_DRV_TYPES_H_SW_PATCH_VERSION != SCM_MCU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Scm_Mcu_Drv_Types.h and Scm_Mcu_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((SCM_MCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||         \
         (SCM_MCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Scm_Mcu_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((SCM_MCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||     \
         (SCM_MCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Scm_Mcu_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of output clock divider.
 *
 */
typedef enum
{
    SCM_MCU_DRV_CLOCK_OUT_DIV_1 = 0U, /*!< clock divided by 1 */
    SCM_MCU_DRV_CLOCK_OUT_DIV_2 = 1U, /*!< clock divided by 2 */
    SCM_MCU_DRV_CLOCK_OUT_DIV_4 = 2U, /*!< clock divided by 4 */
    SCM_MCU_DRV_CLOCK_OUT_DIV_8 = 3U  /*!< clock divided by 8 */
} Scm_Mcu_Drv_ClockOutDivType;

/**
 *  @brief Type of output clock source option.
 *
 */
typedef enum
{
    SCM_MCU_DRV_CLOCK_OUT_DISABLED = 0U, /*!< Disabled */
    SCM_MCU_DRV_CLOCK_OUT_FIRC64M = 1U, /*!< FIRC64M Clock */
    SCM_MCU_DRV_CLOCK_OUT_FOSC = 2U,    /*!< Fast OSC Clock */
    SCM_MCU_DRV_CLOCK_OUT_PLL = 3U,     /*!< PLL Clock */
    SCM_MCU_DRV_CLOCK_OUT_SLOW = 8U,    /*!< SLOW Clock */
    SCM_MCU_DRV_CLOCK_OUT_BUS = 9U,     /*!< BUS Clock */
    SCM_MCU_DRV_CLOCK_OUT_CORE = 10U,   /*!< CORE Clock */
    SCM_MCU_DRV_CLOCK_OUT_SOSC = 11U,   /*!< Slow OSC Clock */
    SCM_MCU_DRV_CLOCK_OUT_LPO32K = 12U  /*!< LPO32K Clock */
} Scm_Mcu_Drv_ClockOutSrcType;

/**
 *  @brief Type of SRAM.
 *
 */
typedef enum
{
    SCM_MCU_DRV_SRAML = 0U, /*!< SWTRIG0 */
    SCM_MCU_DRV_SRAMU = 1U  /*!< SWTRIG0 */
} Scm_Mcu_Drv_SramType;

/**
 *  @brief Type of Timer.
 *
 */
typedef enum
{
    SCM_MCU_DRV_TIM0 = 3U,   /*!< TIM0 */
    SCM_MCU_DRV_TIM1 = 4U,   /*!< TIM1 */
    SCM_MCU_DRV_TIM2 = 5U,   /*!< TIM2 */
    SCM_MCU_DRV_TIM3 = 6U,   /*!< TIM3 */
    SCM_MCU_DRV_MCPWM0 = 7U, /*!< MCPWM0 */
    SCM_MCU_DRV_MCPWM1 = 8U  /*!< MCPWM1 */
} Scm_Mcu_Drv_TimerType;

/**
 *  @brief Type of external input clock of timer.
 *
 */
typedef enum
{
    SCM_MCU_DRV_TCLK0 = 0U, /*!< Timer external input clock 0 */
    SCM_MCU_DRV_TCLK1 = 1U, /*!< Timer external input clock 1 */
    SCM_MCU_DRV_TCLK2 = 2U  /*!< Timer external input clock 2 */
} Scm_Mcu_Drv_TimerExtClockInputType;

/**
 *  @brief Type of ADC channel.
 *
 */
typedef enum
{
    SCM_MCU_DRV_ADC1CH15 = 0U, /*!< ADC1 Channel15 Select */
    SCM_MCU_DRV_ADC1CH14 = 1U, /*!< ADC1 Channel14 Select */
    SCM_MCU_DRV_ADC0CH9 = 2U,  /*!< ADC0 Channel9 Select */
    SCM_MCU_DRV_ADC0CH8 = 3U   /*!< ADC0 Channel8 Select */
} Scm_Mcu_Drv_AdcChannelSelectType;

/**
 *  @brief Type of ADC mux.
 *
 */
typedef enum
{
    SCM_MCU_DRV_ADCMUX0 = 0U, /*!< ADC mux function0 */
    SCM_MCU_DRV_ADCMUX1 = 1U  /*!< ADC mux function1 */
} Scm_Mcu_Drv_AdcMuxSelectType;

/**
 *  @brief Type of SCM interrupt.
 *
 */
typedef enum
{
    SCM_MCU_DRV_CCACHE_BE_INT = 0U,     /*!< Cache bit error error interrupt */
    SCM_MCU_DRV_FPU_INEXACT_INT = 1U,   /*!< FPU inexact interrupt */
    SCM_MCU_DRV_FPU_OVERFLOW_INT = 2U,  /*!< FPU overflow interrupt */
    SCM_MCU_DRV_FPU_UNDERFLOW_INT = 3U, /*!< FPU underflow interrupt */
    SCM_MCU_DRV_FPU_INVALIDOP_INT = 4U, /*!< FPU invalid op interrupt */
    SCM_MCU_DRV_FPU_DIVZERO_INT = 5U,   /*!< FPU divzero interrupt */
    SCM_MCU_DRV_FPU_DENORMALIN_INT = 6U /*!< FPU denormal interrupt */
} Scm_Mcu_Drv_IntType;

/**
 *  @brief Type of system clock configuration.
 *
 */
typedef struct
{
    Scm_Mcu_Drv_ClockOutSrcType ScmClockOutputSrc;     /*!< Clock output source */
    Scm_Mcu_Drv_ClockOutDivType ScmClockOutputDivider; /*!< Clock output divider */
    boolean                     Enable;                /*!< Clock output enable / disable */
} Scm_Mcu_Drv_ClockOutputConfigType;

/**
 *  @brief Type of SCM clock configuration.
 *
 */
typedef struct
{
    Scm_Mcu_Drv_ClockOutputConfigType ScmClockOutputConfig; /*!< Clock output config */
} Scm_Mcu_Drv_ClockConfigType;

/**
 *  @brief Type of SRMC power mode configuration.
 *
 */
typedef struct
{
    /* SCM Misc Control 1 register define */
    boolean CacheBEInterruptEnable;      /*!< Cache bit error interrupt enable */
    boolean FpuInExactInterruptEnable;   /*!< FPU inexact interrupt enable */
    boolean FpuOverflowInterruptEnable;  /*!< FPU overflow interrupt enable */
    boolean FpuUnderflowInterruptEnable; /*!< FPU underflow interrupt enable */
    boolean FpuInvalidOPInterruptEnable; /*!< FPU invalid op interrupt enable */
    boolean FpuDivzeroInterruptEnable;   /*!< FPU divzero interrupt enable */
    boolean FpuDenormalInterruptEnable;  /*!< FPU denormal interrupt enable */
    boolean SramLReadBufferEnable;       /*!< SRAML read buffer enable */
    boolean SramUReadBufferEnable;       /*!< SRAMU read buffer enable */
    boolean CacheEnable;                 /*!< Cache enable */
    boolean CacheParityFaultEnable;      /*!< Cache parity fault enable */
    boolean CacheParityMissEnable;       /*!< Cache parity miss enable */

    /* SCM Misc Control 2 register define */
    Scm_Mcu_Drv_TimerExtClockInputType Mcpwm0Select; /*!< MCPWM0 external input clock select */
    Scm_Mcu_Drv_TimerExtClockInputType Mcpwm1Select; /*!< MCPWM1 external input clock select */
    Scm_Mcu_Drv_TimerExtClockInputType Tim0Select;   /*!< TIM0 external input clock select */
    Scm_Mcu_Drv_TimerExtClockInputType Tim1Select;   /*!< TIM1 external input clock select */
    Scm_Mcu_Drv_TimerExtClockInputType Tim2Select;   /*!< TIM2 external input clock select */
    Scm_Mcu_Drv_TimerExtClockInputType Tim3Select;   /*!< TIM3 external input clock select */

    Scm_Mcu_Drv_AdcMuxSelectType Adc0Ch8Select;  /*!< ADC0 channel 8 mux select */
    Scm_Mcu_Drv_AdcMuxSelectType Adc0Ch9Select;  /*!< ADC0 channel 9 mux select */
    Scm_Mcu_Drv_AdcMuxSelectType Adc1Ch14Select; /*!< ADC1 channel 14 mux select */
    Scm_Mcu_Drv_AdcMuxSelectType Adc1Ch15Select; /*!< ADC1 channel 15 mux select */
} Scm_Mcu_Drv_ConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Scm_Mcu_Drv */

/** @} end of group Mcu_Module */

#endif /* SCM_MCU_DRV_TYPES_H */
