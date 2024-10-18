/**************************************************************************************************/
/**
 * @file      : Tmu_Drv_Types.h
 * @brief     : Tmu driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TMU_DRV_TYPES_H
#define TMU_DRV_TYPES_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Tmu_Drv
 *  @brief Tmu driver type definition file
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Tmu_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define TMU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TMU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TMU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TMU_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Tmu_Drv.h are the same vendor */
#if (TMU_DRV_TYPES_H_VENDOR_ID != TMU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Tmu_Drv.c and Tmu_Drv.h have different vendor ids"
#endif
/* Check if current file and Tmu_Drv.h are the same Autosar version */
#if ((TMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != TMU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (TMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != TMU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (TMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != TMU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tmu_Drv.c and Tmu_Drv.h are different"
#endif
/* Check if current file and Tmu_Drv.h are the same Software version */
#if ((TMU_DRV_TYPES_H_SW_MAJOR_VERSION != TMU_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (TMU_DRV_TYPES_H_SW_MINOR_VERSION != TMU_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (TMU_DRV_TYPES_H_SW_PATCH_VERSION != TMU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Tmu_Drv.c and Tmu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((TMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (TMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Tmu_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((TMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (TMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tmu_Drv.c and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief TMU Input Select type definition
 */
typedef enum
{
    TMU_DRV_INPUT_CHANNEL_VSS = 0U,                          /*!< VSS  */
    TMU_DRV_INPUT_CHANNEL_VDD = 1U,                          /*!< VDD  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN0 = 2U,                   /*!< TMU  IN0  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN1 = 3U,                   /*!< TMU  IN1  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN2 = 4U,                   /*!< TMU  IN2  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN3 = 5U,                   /*!< TMU  IN3  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN4 = 6U,                   /*!< TMU  IN4  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN5 = 7U,                   /*!< TMU  IN5  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN6 = 8U,                   /*!< TMU  IN6  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN7 = 9U,                   /*!< TMU  IN7  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN8 = 10U,                  /*!< TMU  IN8  */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN9 = 11U,                  /*!< TMU  IN9 */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN10 = 12U,                 /*!< TMU  IN10 */
    TMU_DRV_INPUT_CHANNEL_IO_TMU_IN11 = 13U,                 /*!< TMU  IN11 */
    TMU_DRV_INPUT_CHANNEL_RTC_SECOND = 14U,                  /*!< RTC_1HZ_MUX_OUT */
    TMU_DRV_INPUT_CHANNEL_RTC_ALARM = 15U,                   /*!< RTC  Alarm  */
    TMU_DRV_INPUT_CHANNEL_STIM_TRIG_OUT0 = 16U,              /*!< stim_trig_out[0] */
    TMU_DRV_INPUT_CHANNEL_STIM_TRIG_OUT1 = 17U,              /*!< stim_trig_out[1] */
    TMU_DRV_INPUT_CHANNEL_STIM_TRIG_OUT2 = 18U,              /*!< stim_trig_out[2] */
    TMU_DRV_INPUT_CHANNEL_STIM_TRIG_OUT3 = 19U,              /*!< stim_trig_out[3] */
    TMU_DRV_INPUT_CHANNEL_TIM0_MATCH_TRIGGER = 20U,          /*!< Timer0 Match Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM0_INITIALIZATION_TRIGGER = 21U, /*!< Timer0 Initialization Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM1_MATCH_TRIGGER = 22U,          /*!< Timer1 Match Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM1_INITIALIZATION_TRIGGER = 23U, /*!< Timer1 Initialization Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM2_MATCH_TRIGGER = 24U,          /*!< Timer2 Match Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM2_INITIALIZATION_TRIGGER = 25U, /*!< Timer2 Initialization Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM3_MATCH_TRIGGER = 26U,          /*!< Timer3 Match Trigger  */
    TMU_DRV_INPUT_CHANNEL_TIM3_INITIALIZATION_TRIGGER = 27U, /*!< Timer3 Initialization Trigger  */
    TMU_DRV_INPUT_CHANNEL_ADC0_COCO = 28U,                   /*!< ADC0 Conversion Complete  */
    TMU_DRV_INPUT_CHANNEL_ADC1_COCO = 29U,                   /*!< ADC1 Conversion Complete  */
    TMU_DRV_INPUT_CHANNEL_CMP0_COUT = 30U,                   /*!< CMP Cout  */
    TMU_DRV_INPUT_CHANNEL_TDG0_CHANNEL0_TRIGGER_OUT = 31U,   /*!< TDG0 channel 0 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG0_CHANNEL1_TRIGGER_OUT = 32U,   /*!< TDG0 channel 1 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG0_CHANNEL2_TRIGGER_OUT = 33U,   /*!< TDG0 channel 2 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG0_CHANNEL3_TRIGGER_OUT = 34U,   /*!< TDG0 channel 3 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG0_CHANNEL4_TRIGGER_OUT = 35U,   /*!< TDG0 channel 4 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG0_CHANNEL5_TRIGGER_OUT = 36U,   /*!< TDG0 channel 5 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG1_CHANNEL0_TRIGGER_OUT = 37U,   /*!< TDG1 channel 0 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG1_CHANNEL1_TRIGGER_OUT = 38U,   /*!< TDG1 channel 1 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG1_CHANNEL2_TRIGGER_OUT = 39U,   /*!< TDG1 channel 2 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG1_CHANNEL3_TRIGGER_OUT = 40U,   /*!< TDG1 channel 3 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG1_CHANNEL4_TRIGGER_OUT = 41U,   /*!< TDG1 channel 4 trigger out */
    TMU_DRV_INPUT_CHANNEL_TDG1_CHANNEL5_TRIGGER_OUT = 42U,   /*!< TDG1 channel 5 trigger out */
    TMU_DRV_INPUT_CHANNEL_SPI0_RX_TRIG = 43U,                /*!< SPI0 Rx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI0_TX_TRIG = 44U,                /*!< SPI0 Tx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI1_RX_TRIG = 45U,                /*!< SPI1 Rx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI1_TX_TRIG = 46U,                /*!< SPI1 Tx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI2_RX_TRIG = 47U,                /*!< SPI2 Rx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI2_TX_TRIG = 48U,                /*!< SPI2 Tx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI3_RX_TRIG = 49U,                /*!< SPI3 Rx Data  */
    TMU_DRV_INPUT_CHANNEL_SPI3_TX_TRIG = 50U,                /*!< SPI3 Tx Data  */
    TMU_DRV_INPUT_CHANNEL_I2C0_RX_TRIG = 51U,                /*!< I2C0 Rx Data  */
    TMU_DRV_INPUT_CHANNEL_I2C0_TX_TRIG = 52U,                /*!< I2C0 Tx Data  */
    TMU_DRV_INPUT_CHANNEL_I2C1_RX_TRIG = 53U,                /*!< I2C1 Rx Data  */
    TMU_DRV_INPUT_CHANNEL_I2C1_TX_TRIG = 54U,                /*!< I2C1 Tx Data  */
    TMU_DRV_INPUT_CHANNEL_SCM_SW_TRIG0 = 55U,                /*!< SCM Trigger  */
    TMU_DRV_INPUT_CHANNEL_SCM_SW_TRIG1 = 56U,                /*!< SCM Trigger  */
    TMU_DRV_INPUT_CHANNEL_SCM_SW_TRIG2 = 57U,                /*!< SCM Trigger  */
    TMU_DRV_INPUT_CHANNEL_SCM_SW_TRIG3 = 58U,                /*!< SCM Trigger  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG0 = 59U,            /*!< MCPWM0 EXT_TRIG[0]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG1 = 60U,            /*!< MCPWM0 EXT_TRIG[1]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG2 = 61U,            /*!< MCPWM0 EXT_TRIG[2]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG3 = 62U,            /*!< MCPWM0 EXT_TRIG[3]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG4 = 63U,            /*!< MCPWM0 EXT_TRIG[4]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG5 = 64U,            /*!< MCPWM0 EXT_TRIG[5]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG6 = 65U,            /*!< MCPWM0 EXT_TRIG[6]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_EXT_TRIG7 = 66U,            /*!< MCPWM0 EXT_TRIG[7]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_INIT_TRIG0 = 67U,           /*!< MCPWM0 INIT_TRIG[0]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_INIT_TRIG1 = 68U,           /*!< MCPWM0 INIT_TRIG[1]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_INIT_TRIG2 = 69U,           /*!< MCPWM0 INIT_TRIG[2]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM0_INIT_TRIG3 = 70U,           /*!< MCPWM0 INIT_TRIG[3]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG0 = 71U,            /*!< MCPWM1 EXT_TRIG[0]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG1 = 72U,            /*!< MCPWM1 EXT_TRIG[1]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG2 = 73U,            /*!< MCPWM1 EXT_TRIG[2]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG3 = 74U,            /*!< MCPWM1 EXT_TRIG[3]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG4 = 75U,            /*!< MCPWM1 EXT_TRIG[4]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG5 = 76U,            /*!< MCPWM1 EXT_TRIG[5]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG6 = 77U,            /*!< MCPWM1 EXT_TRIG[6]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_EXT_TRIG7 = 78U,            /*!< MCPWM1 EXT_TRIG[7]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_INIT_TRIG0 = 79U,           /*!< MCPWM1 INIT_TRIG[0]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_INIT_TRIG1 = 80U,           /*!< MCPWM1 INIT_TRIG[1]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_INIT_TRIG2 = 81U,           /*!< MCPWM1 INIT_TRIG[2]  */
    TMU_DRV_INPUT_CHANNEL_MCPWM1_INIT_TRIG3 = 82U            /*!< MCPWM1 INIT_TRIG[3]  */
} Tmu_Drv_InputChannelType;

/**
 *  @brief TMU output channel type definition
 */
typedef enum
{
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT0 = 0U,           /*!< IO OUTPUT0  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT1 = 1U,           /*!< IO OUTPUT1  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT2 = 2U,           /*!< IO OUTPUT2  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT3 = 3U,           /*!< IO OUTPUT3  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT4 = 4U,           /*!< IO OUTPUT4  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT5 = 5U,           /*!< IO OUTPUT5  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT6 = 6U,           /*!< IO OUTPUT6  */
    TMU_DRV_OUTPUT_CHANNEL_IO_TMU_OUT7 = 7U,           /*!< IO OUTPUT7  */
    TMU_DRV_OUTPUT_CHANNEL_ADC0_HW_TRIG_OPT0 = 8U,     /*!< ADC0 hw trigger OPT0  */
    TMU_DRV_OUTPUT_CHANNEL_ADC0_HW_TRIG_OPT1 = 9U,     /*!< ADC0 hw trigger OPT1  */
    TMU_DRV_OUTPUT_CHANNEL_ADC0_HW_TRIG_OPT2 = 10U,    /*!< ADC0 hw trigger OPT2  */
    TMU_DRV_OUTPUT_CHANNEL_ADC0_HW_TRIG_OPT3 = 11U,    /*!< ADC0 hw trigger OPT3  */
    TMU_DRV_OUTPUT_CHANNEL_ADC1_HW_TRIG_OPT0 = 12U,    /*!< ADC1 hw trigger OPT0  */
    TMU_DRV_OUTPUT_CHANNEL_ADC1_HW_TRIG_OPT1 = 13U,    /*!< ADC1 hw trigger OPT1  */
    TMU_DRV_OUTPUT_CHANNEL_ADC1_HW_TRIG_OPT2 = 14U,    /*!< ADC1 hw trigger OPT2  */
    TMU_DRV_OUTPUT_CHANNEL_ADC1_HW_TRIG_OPT3 = 15U,    /*!< ADC1 hw trigger OPT3  */
    TMU_DRV_OUTPUT_CHANNEL_CMP0_SAMPLE = 16U,          /*!< CMP Sample  */
    TMU_DRV_OUTPUT_CHANNEL_CMP0_EXTERNAL_ENABLE = 17U, /*!< CMP external en  */
    TMU_DRV_OUTPUT_CHANNEL_TDG0_TRIG_IN = 18U,         /*!< TDG0 trig in */
    TMU_DRV_OUTPUT_CHANNEL_TDG1_TRIG_IN = 19U,         /*!< TDG1 trig in */
    TMU_DRV_OUTPUT_CHANNEL_TIM0_FAULT0 = 20U,          /*!< Timer0 fault input channel 0  */
    TMU_DRV_OUTPUT_CHANNEL_TIM0_FAULT1 = 21U,          /*!< Timer0 fault input channel 1  */
    TMU_DRV_OUTPUT_CHANNEL_TIM1_FAULT0 = 22U,          /*!< Timer1 fault input channel 0  */
    TMU_DRV_OUTPUT_CHANNEL_TIM1_FAULT1 = 23U,          /*!< Timer1 fault input channel 1  */
    TMU_DRV_OUTPUT_CHANNEL_TIM2_FAULT0 = 24U,          /*!< Timer2 fault input channel 0  */
    TMU_DRV_OUTPUT_CHANNEL_TIM2_FAULT1 = 25U,          /*!< Timer2 fault input channel 1  */
    TMU_DRV_OUTPUT_CHANNEL_TIM3_FAULT0 = 26U,          /*!< Timer3 fault input channel 0  */
    TMU_DRV_OUTPUT_CHANNEL_TIM3_FAULT1 = 27U,          /*!< Timer3 fault input channel 1  */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM0_FAULT0 = 28U,        /*!< MCPWM0 fault input channel 0 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM0_FAULT1 = 29U,        /*!< MCPWM0 fault input channel 1 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM0_FAULT2 = 30U,        /*!< MCPWM0 fault input channel 2 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM0_FAULT3 = 31U,        /*!< MCPWM0 fault input channel 3 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM1_FAULT0 = 32U,        /*!< MCPWM1 fault input channel 0 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM1_FAULT1 = 33U,        /*!< MCPWM1 fault input channel 1 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM1_FAULT2 = 34U,        /*!< MCPWM1 fault input channel 2 */
    TMU_DRV_OUTPUT_CHANNEL_MCPWM1_FAULT3 = 35U,        /*!< MCPWM1 fault input channel 3 */
    TMU_DRV_OUTPUT_CHANNEL_STIM_TRIG_IN0 = 36U,        /*!< stim_trig_in[0] */
    TMU_DRV_OUTPUT_CHANNEL_STIM_TRIG_IN1 = 37U,        /*!< stim_trig_in[1] */
    TMU_DRV_OUTPUT_CHANNEL_STIM_TRIG_IN2 = 38U,        /*!< stim_trig_in[2] */
    TMU_DRV_OUTPUT_CHANNEL_STIM_TRIG_IN3 = 39U         /*!< stim_trig_in[3] */
} Tmu_Drv_OutputChannelType;

/**
 * @brief  Defines structure for tmu channel configuration.
 */
typedef struct
{
    Tmu_Drv_InputChannelType  InputChannel;  /*!< Tmu Input Channel */
    Tmu_Drv_OutputChannelType OutputChannel; /*!< Tmu Output Channel */
    boolean                   OutputEnabled; /*!< Tmu output enable */
} Tmu_Drv_ChannelConfigType;

/**
 * @brief  Defines structure for list of all tmu channels configuration.
 */
typedef struct
{
    uint32                           ConfigChannelCount; /*!< Number of configured tmu channels */
    const Tmu_Drv_ChannelConfigType *ChannelConfigList;  /*!< List of tmu channels configuration */
} Tmu_Drv_ConfigType;

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

/** @} end of group Tmu_Drv */

/** @} end of group Platform_Module */

#endif /* TMU_DRV_TYPES_H */
