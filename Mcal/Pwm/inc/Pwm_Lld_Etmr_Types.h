/**
 * @file    Pwm_Lld_Etmr_Types.h
 * @version V2.3.0
 *
 * @brief   YUNTU Pwm_Lld_Etmr module interface
 * @details API implementation for Pwm_Lld_Etmr driver
 *
 * @addtogroup PWM_LLD_ETMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifndef PWM_LLD_ETMR_TYPES_H
#define PWM_LLD_ETMR_TYPES_H

#include "Platform_Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Etmr_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_TYPES_VENDOR_ID                      (180)
#define PWM_LLD_ETMR_TYPES_MODULE_ID            (121)
#define PWM_LLD_ETMR_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_LLD_ETMR_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_LLD_ETMR_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_LLD_ETMR_TYPES_SW_MAJOR_VERSION               (2)
#define PWM_LLD_ETMR_TYPES_SW_MINOR_VERSION               (3)
#define PWM_LLD_ETMR_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief eTMR clock sources.
 */
typedef enum
{
    PWM_LLD_ETMR_CLKSRC_BUS         = 0x00U,    /**< Bus clock */
    PWM_LLD_ETMR_CLKSRC_EXTERNAL    = 0x01U     /**< External clock */
} Pwm_Lld_Etmr_ClkSrcType;

/**
 * @brief eTMR external clock sources.
 */
typedef enum
{
    PWM_LLD_ETMR_EXCLKSRC_TCLK_IN0  = 0x00U,    /**< Select TCLK_IN0 input as external clock */
    PWM_LLD_ETMR_EXCLKSRC_TCLK_IN1  = 0x01U,    /**< Select TCLK_IN1 input as external clock */
    PWM_LLD_ETMR_EXCLKSRC_TCLK_IN2  = 0x02U,    /**< Select TCLK_IN2 input as external clock */
    PWM_LLD_ETMR_EXCLKSRC_IPC       = 0x03U,    /**< Select ETMR_FUNC_CLK from IPC as external clock */
} Pwm_Lld_Etmr_ExClkSrcType;

/**
 * @brief eTMR dither mode.
 */
typedef enum
{
    PWM_LLD_ETMR_DITHMD_DISABLED    = 0x00U,    /**< Dither mode disabled */
    PWM_LLD_ETMR_DITHMD_PERIOD      = 0x01U,    /**< Dither mode enabled for period */
    PWM_LLD_ETMR_DITHMD_EDGE        = 0x02U,    /**< Dither mode enabled for edge */
    PWM_LLD_ETMR_DITHMD_PERIOD_EDGE = 0x03U     /**< Dither mode enabled for period and edge */
} Pwm_Lld_Etmr_DitherModeType;

/**
 * @brief eTMR PWM channel mode.
 */
typedef enum
{
    PWM_LLD_ETMR_MODE_INDEPENDENT   = 0x00U,    /**< Independent mode */
    PWM_LLD_ETMR_MODE_COMPLEMENTARY = 0x01U     /**< Complementary mode */
} Pwm_Lld_Etmr_ChModeType;

/**
 * @brief eTMR PWM aligned mode.
 */
typedef enum
{
    PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE   = 0x00U,    /**< Left edge aligned */
    PWM_LLD_ETMR_ALIGN_MODE_CENTER      = 0x01U,    /**< Center aligned */
    PWM_LLD_ETMR_ALIGN_MODE_RIGHT_EDGE  = 0x02U     /**< Right edge aligned */
} Pwm_Lld_Etmr_AlignModeType;

/**
 * @brief eTMR PWM output state.
 */
typedef enum
{
    PWM_LLD_ETMR_OUTPUT_STATE_LOW  = 0x00U, /**< The PWM channel is in low state */
    PWM_LLD_ETMR_OUTPUT_STATE_HIGH = 0x01U  /**< The PWM channel is in high state */
} Pwm_Lld_Etmr_OutputStateType;

/**
 * @brief eTMR PWM polarity.
 */
typedef enum
{
    PWM_LLD_ETMR_POLARITY_NOT_INVERT = 0x00U,   /**< Not invert the channel output. */
    PWM_LLD_ETMR_POLARITY_INVERT     = 0x01U    /**< Invert the channel output. */
} Pwm_Lld_Etmr_PolarityType;

/**
 * @brief eTMR Register loading opportunity.
 */
typedef enum
{
    PWM_LLD_ETMR_REG_LOAD_REGISTER  = 0x00U,    /**< Load REG with other registers */
    PWM_LLD_ETMR_REG_LOAD_MATCH_MOD = 0x01U,    /**< Load REG with MOD match */
#if (defined(YTM32B1MC0) || defined(CPU_YTM32B1MC0)) /* NO MID match trigger support on MC03 */
    PWM_LLD_ETMR_REG_LOAD_TRIGGER   = 0x02U,    /**< Load REG with trigger event */
    PWM_LLD_ETMR_REG_LOAD_RESERVED  = 0x03U     /**< reserved */
#else
    PWM_LLD_ETMR_REG_LOAD_MATCH_MID = 0x02U,    /**< Load REG with MID match */
    PWM_LLD_ETMR_REG_LOAD_TRIGGER   = 0x03U     /**< Load REG with trigger event */
#endif
} Pwm_Lld_Etmr_RegLoadType;

/**
 * @brief eTMR trigger sources.
 */
typedef enum
{
    PWM_LLD_ETMR_TRGSRC_NONE    = 0x00U,    /**< No trigger source */
    PWM_LLD_ETMR_TRGSRC_SW      = 0x01U,    /**< Software trigger */
    PWM_LLD_ETMR_TRGSRC_HW      = 0x02U,    /**< Hardware trigger */
    PWM_LLD_ETMR_TRGSRC_BOTH    = 0x03U     /**< Both software and hardware trigger */
} Pwm_Lld_Etmr_TrgSrcType;

/**
 * @brief eTMR counter loading opportunity.
 */
typedef enum
{
    PWM_LLD_ETMR_COUNTER_LOAD_REGISTER  = 0x00U,    /**< Load counter with other registers */
    PWM_LLD_ETMR_COUNTER_LOAD_MATCH_MID = 0x01U,    /**< Load counter with MID match */
    PWM_LLD_ETMR_COUNTER_LOAD_TRIGGER   = 0x02U     /**< Load counter with trigger event */
} Pwm_Lld_Etmr_CounterLoadType;

/**
 * @brief eTMR channel mode.
 */
typedef enum
{
    PWM_LLD_ETMR_CHANNEL_MODE_DISABLE   = 0x00U,    /**< Disable the channel */
    PWM_LLD_ETMR_CHANNEL_MODE_PWM       = 0x01U,    /**< PWM mode */
    PWM_LLD_ETMR_CHANNEL_MODE_OCU       = 0x02U,    /**< OCU mode */
    PWM_LLD_ETMR_CHANNEL_MODE_ICU       = 0x03U     /**< ICU mode */
} Pwm_Lld_Etmr_ChannelModeType;

/**
 * @brief eTMR PWM source.
 */
typedef enum
{
    PWM_LLD_ETMR_PWMSRC_NORMAL  = 0x00U,    /**< Normal mode, PWM is generated by VAL0 and VAL1. */
    PWM_LLD_ETMR_PWMSRC_INVERT  = 0x01U,    /**< Invert mode, invert the PWM in normal mode. */
    PWM_LLD_ETMR_PWMSRC_SW      = 0x02U     /**< Software mode, PWM is generated by CHSWV register. */
} Pwm_Lld_Etmr_PwmSrcType;

/**
 * @brief eTMR PWM output trigger source.
 */
typedef enum
{
    PWM_LLD_ETMR_OUTTRGSRC_MATCH    = 0x00U,    /**< Select trigger that generated by matching event. */
    PWM_LLD_ETMR_OUTTRGSRC_PWM      = 0x01U,    /**< Select PWM output as the trigger. */
} Pwm_Lld_Etmr_OutTrgSrcType;

/**
 * @brief eTMR PWM output pulse source.
 */
typedef enum
{
    PWM_LLD_ETMR_OUTPULSESRC_CH0    = 0x00U,    /**< Select PWM channel 0 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH1    = 0x01U,    /**< Select PWM channel 1 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH2    = 0x02U,    /**< Select PWM channel 2 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH3    = 0x03U,    /**< Select PWM channel 3 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH4    = 0x04U,    /**< Select PWM channel 4 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH5    = 0x05U,    /**< Select PWM channel 5 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH6    = 0x06U,    /**< Select PWM channel 6 as the pulse-out source. */
    PWM_LLD_ETMR_OUTPULSESRC_CH7    = 0x07U     /**< Select PWM channel 7 as the pulse-out source. */
} Pwm_Lld_Etmr_OutPulseSrcType;

/*==================================================================================================
 *                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief eTMR PWM callback type.
 */
typedef void (*Pwm_Lld_Etmr_CallbackType)(void);

/**
 * @brief eTMR PWM Mode instance configuration
 */
typedef struct
{
    boolean DebugModeEnable;                    /**< Debug mode enable */
    boolean OvfIrqEn;                           /**< Overflow interrupt enable */
    boolean ModTrgEn;                           /**< MOD trigger enable */
#if (defined(PWM_LLD_ETMR_HAS_MID_MATCH_TRIGGER) && (PWM_LLD_ETMR_HAS_MID_MATCH_TRIGGER == STD_ON))
    boolean MidTrgEn;                           /**< MID trigger enable */
#endif
#if (defined(PWM_LLD_ETMR_HAS_INIT_MATCH_TRIGGER) && (PWM_LLD_ETMR_HAS_INIT_MATCH_TRIGGER == STD_ON))
    boolean InitTrgEn;                          /**< INIT trigger enable */
#endif
    uint8 ClockPrescaler;                       /**< Clock prescaler */
#if (defined(PWM_LLD_ETMR_HAS_OUTPUT_TRIGGER_WIDTH) && (PWM_LLD_ETMR_HAS_OUTPUT_TRIGGER_WIDTH == STD_ON))
    uint8 OutTrgWidth;                          /**< Output trigger width */
#endif
    uint8 OutTrgFreq;                           /**< Output trigger frequency */
    uint8 PulseSrc;                             /**< Pulse source */
    uint32 Period;                              /**< Period */
#if (defined(PWM_LLD_ETMR_HAS_DEADTIME_PRESCALER) && (PWM_LLD_ETMR_HAS_DEADTIME_PRESCALER == STD_ON))
    uint8 DeadtimePrescaler;                    /**< Deadtime prescaler */
#endif
    Pwm_Lld_Etmr_ClkSrcType ClockSource;        /**< Clock source */
    Pwm_Lld_Etmr_ExClkSrcType ExClockSource;    /**< External clock source */
    Pwm_Lld_Etmr_OutTrgSrcType OutTrgSrc;       /**< Output trigger source */
    Pwm_Lld_Etmr_CallbackType OvfCallback;      /**< Overflow interrupt callback */
} Pwm_Lld_Etmr_InstCfgType;

/**
 * @brief eTMR PWM Mode channel configuration
 */
typedef struct
{
    boolean Val0TrgEn;                      /**< VAL0 trigger enable */
    boolean Val1TrgEn;                      /**< VAL1 trigger enable */
    uint8 ChannelId;                        /**< Channel ID */
    uint16 DutyCycle;                       /**< Duty cycle */
    uint16 DeadTime;                        /**< Dead time */
    Pwm_Lld_Etmr_AlignModeType AlignMode;   /**< PWM aligned mode */
    Pwm_Lld_Etmr_PolarityType Polarity;     /**< PWM channel polarity */
    Pwm_Lld_Etmr_OutputStateType IdleState; /**< PWM channel idle state */
    Pwm_Lld_Etmr_ChModeType ChMode;         /**< PWM channel mode */
} Pwm_Lld_Etmr_ChCfgType;

/**
 * @brief eTMR PWM Mode configuration
 */
typedef struct
{
    uint8 ChannelCount;                             /**< Number of PWM channels */
    const Pwm_Lld_Etmr_InstCfgType *InstCfg;        /**< Pointer to instance configuration */
    const Pwm_Lld_Etmr_ChCfgType *const *ChCfgArr;  /**< Pointer to channel configuration array */
} Pwm_Lld_Etmr_CfgType;

#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_ETMR_TYPES_H */

/** @} */

