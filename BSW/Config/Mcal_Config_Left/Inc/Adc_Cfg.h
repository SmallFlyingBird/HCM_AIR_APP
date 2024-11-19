/**************************************************************************************************/
/**
 * @file      : Adc_Cfg.h  
 * @brief     : Adc AUTOSAR level - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Configuration
 *  @brief Adc AUTOSAR level configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif
#include "Adc_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_CFG_H_VENDOR_ID                   0x00B3U
#define ADC_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_CFG_H_SW_MAJOR_VERSION            1U
#define ADC_CFG_H_SW_MINOR_VERSION            2U
#define ADC_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Adc_PBcfg.h are the same vendor */
#if (ADC_CFG_H_VENDOR_ID != ADC_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Adc_Cfg.h and Adc_PBcfg.h are different"
#endif
/* Check if current file and Adc_PBcfg.h are the same Autosar version */
#if ((ADC_CFG_H_AR_RELEASE_MAJOR_VERSION != ADC_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_CFG_H_AR_RELEASE_MINOR_VERSION != ADC_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_CFG_H_AR_RELEASE_REVISION_VERSION != ADC_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Adc_Cfg.h and Adc_PBcfg.h are different"
#endif
/* Check if current file and Adc_PBcfg.h are the same software version */
#if ((ADC_CFG_H_SW_MAJOR_VERSION != ADC_PBCFG_H_SW_MAJOR_VERSION) || \
     (ADC_CFG_H_SW_MINOR_VERSION != ADC_PBCFG_H_SW_MINOR_VERSION) || \
     (ADC_CFG_H_SW_PATCH_VERSION != ADC_PBCFG_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Adc_Cfg.h and Adc_PBcfg.h are different"
#endif


/** 
 * @brief Defines ADC notification functions declaration.
 */
#define ADC_FUNC_DECL_EXT \
    ADC_FUNC_DECL_PB

/**
 * @brief Maximum number of configured partitions.
 */
#define ADC_MAX_PARTITIONS    (1U)

/**
 * @brief Adc Get Core Id.
 */
#define Adc_GetCoreID()    ((uint32)McalLib_GetCoreID())

/**
 * @brief Defines timeout value
 */
#define ADC_TIMEOUT_COUNTER    (1000U)

/**
 * @brief Defines the number of configured hardware unit 
 */
#define ADC_MAX_HWUNITS    (2U)

/**
 * @brief Switches hardware trigger API functionality ON or OFF.
 */
#define ADC_HW_TRIGGER_API    (STD_ON)

/**
 * @brief Switches limit checking functionality ON or OFF.
 */
#define ADC_ENABLE_LIMIT_CHECK    (STD_OFF)

/**
 * @brief Switches Group notification mechanism ON or OFF.
 */
#define ADC_GROUP_NOTIF_CAPABILITY    (STD_ON)

/**
 * @brief Type for configuring the prioritization mechanism.
 *
 */
/* SWS_Adc_00522 */
#define ADC_PRIORITY_HW       (0U) /*!< priority mechanism is not available. */
#define ADC_PRIORITY_HW_SW    (1U) /*!< Hardware priority mechanism is available only. */
#define ADC_PRIORITY_NONE     (2U) /*!< Hardware and software priority mechanism is available. */

/**
 * @brief Priority implementation.
 */
#define ADC_PRIORITY_IMPLEMENTATION    (ADC_PRIORITY_NONE)

/**
 * @brief Defines Left and Right Result Alignment.
 */
/* SWS_Adc_00525 */
#define ADC_ALIGN_LEFT     (0U)
#define ADC_ALIGN_RIGHT    (1U)

/**
 * @brief Defines Result Alignment.
 */
#define ADC_RESULT_ALIGNMENT    (ADC_ALIGN_RIGHT)

/**
 * @brief Switches DMA functionality ON or OFF.
 */
#define ADC_DMA_USED    (ADC_DRV_DMA_USED)

/**
 * @brief Switches the calibration API functionality ON or OFF.
 */
#define ADC_CALIBRATION    (STD_OFF)

/**
 * @brief Defines max number of groups configured across all configset.
 */
#define ADC_MAX_GROUPS    (3U)

/**
 * @brief Invalid Hardware group ID to identify that hardware group is not ongoing.
 */
#define ADC_INVALID_HW_GROUP_ID    (0xFFFFU)

/**
 * @brief Maximum number of channels across all hardware units.
 */
#define ADC_MAX_CHANNELS_PER_HWUNIT    (ADC_DRV_MAX_CHANNELS_PER_HWUNIT)

/**
 * @brief   Configuration Precompile variant.
 */
#define ADC_PRECOMPILE_SUPPORT    (STD_ON)

/**
 * @brief Switches Development error detection ON or OFF.
 */
#define ADC_DEV_ERROR_DETECT    (STD_ON)

/**
 * @brief Switches the Version Information API functionality ON or OFF.
 */
#define ADC_VERSION_INFO_API    (STD_ON)

/**
 * @brief Switches the ADC de-initialization functionality ON or OFF.
 */
#define ADC_DEINIT_API    (STD_ON)

/**
 * @brief Switches the start/stop group API functionality ON or OFF.
 */
#define ADC_ENABLE_START_STOP_GROUP_API    (STD_ON)

/**
 * @brief Switches the read group API functionality ON or OFF.
 */
#define ADC_READ_GROUP_API    (STD_ON)

/**
 * @brief Switches power state mode supporte ON or OFF.
 *
 */
#define ADC_POWER_STATE_SUPPORTED     (STD_OFF)

/**
 * @brief Switches the asynchronous power mode ON or OFF.
 *
 */
#define ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED    (STD_OFF)

/**
 * @brief Switches queue support functionality ON or OFF.
 */
#define ADC_ENABLE_QUEUING    (STD_ON)

/**
 * @brief Defines max queue depth configured across the configset.
 */
#define ADC_QUEUE_MAX_QUEUE_DEPTH     (2U)

/**
 * @brief   Symbolic names of ADC Hardware units.
 */
#define AdcConf_AdcHwUnit_AdcHwUnit_0    (0U)
#define AdcConf_AdcHwUnit_AdcHwUnit_1    (1U)

/**
* @brief   Symbolic names of channels on all HW units with encoded value.
* @details Bit fields [12-15]:  physical ID of HW Unit 
*          Bit fields [0-11]:   Logical ID of channel in HW unit 
*/
#define AdcConf_AdcChannel_DC_Ctr_AD          (0x0U)
#define AdcConf_AdcChannel_HSD1_SNS          (0x1U)
#define AdcConf_AdcChannel_MCU_AD6          (0x2U)
#define AdcConf_AdcChannel_MCU_AD1          (0x3U)
#define AdcConf_AdcChannel_MCU_AD5          (0x4U)
#define AdcConf_AdcChannel_MCU_AD3          (0x5U)
#define AdcConf_AdcChannel_MCU_AD4          (0x6U)
#define AdcConf_AdcChannel_MCU_AD2          (0x7U)
#define AdcConf_AdcChannel_KL56_Vol_Get          (0x1000U)

/**
 * @brief Symbolic groups names configured.
 */
#define AdcConf_AdcGroup_Adc0_Group_0          (0U)
#define AdcConf_AdcGroup_Adc0_Group_1          (1U)
#define AdcConf_AdcGroup_Adc1_Group_0          (2U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

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

/** @} end of group Adc_Configuration */

/** @} end of group Adc_Module */

#endif /* ADC_CFG_H */
