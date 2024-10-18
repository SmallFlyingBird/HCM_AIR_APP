/**************************************************************************************************/
/**
 * @file      : Gpt_PBcfg.c  
 * @brief     : Gpt AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Configuration
 *  @brief Gpt AUTOSAR level configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif


#include "Gpt.h"
#include "Gpt_Drvw.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_PBCFG_C_VENDOR_ID                   0x00B3U
#define GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define GPT_PBCFG_C_SW_MAJOR_VERSION            1U
#define GPT_PBCFG_C_SW_MINOR_VERSION            2U
#define GPT_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Gpt header file are of the same vendor */
#if (GPT_PBCFG_C_VENDOR_ID != GPT_VENDOR_ID)
    #error "Vendor ID of Gpt_PBcfg.c and Gpt.h are different"
#endif
/* Check if current file and Gpt header file are of the same vendor */
#if ((GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Gpt_PBcfg.c and Gpt.h are different"
#endif
/* Check if current file and Gpt header file are of the same vendor */
#if ((GPT_PBCFG_C_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION) || \
     (GPT_PBCFG_C_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION) || \
     (GPT_PBCFG_C_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION) \
    )
    #error "Software Version of Gpt_PBcfg.c and Gpt.h are different"
#endif

/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if (GPT_PBCFG_C_VENDOR_ID != GPT_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Gpt_PBcfg.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if ((GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_DRVW_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Gpt_PBcfg.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if ((GPT_PBCFG_C_SW_MAJOR_VERSION != GPT_DRVW_H_SW_MAJOR_VERSION) || \
     (GPT_PBCFG_C_SW_MINOR_VERSION != GPT_DRVW_H_SW_MINOR_VERSION) || \
     (GPT_PBCFG_C_SW_PATCH_VERSION != GPT_DRVW_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Gpt_PBcfg.c and Gpt_Drvw.h are different"
#endif


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_CONF_CHANNELS_PB    5U

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

extern void TaskNotification10ms(void); /*!< Start Gpt Notification 'GptChannelConfiguration_0' */
extern void TaskNotification20ms(void); /*!< Start Gpt Notification 'GptChannelConfiguration_1' */
extern void TaskNotification50ms(void); /*!< Start Gpt Notification 'GptChannelConfiguration_2' */
extern void TaskNotification1ms(void); /*!< Start Gpt Notification 'GptChannelConfiguration_3' */
extern void TaskNotificationTdgAdcCheck(void); /*!< Start Gpt Notification 'GptChannelConfiguration_4' */

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONFIG_DATA_8
#include "Gpt_MemMap.h"



static const uint8 GptLogicChannelIdToIndexMap[GPT_NUM_CONFIG] =
{
    0,    /*!< Logical Channel GptChannelConfiguration_0 */
    1,    /*!< Logical Channel GptChannelConfiguration_1 */
    2,    /*!< Logical Channel GptChannelConfiguration_2 */
    3,    /*!< Logical Channel GptChannelConfiguration_3 */
    4     /*!< Logical Channel GptChannelConfiguration_4 */
};


#define GPT_STOP_SEC_CONFIG_DATA_8
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

static const Gpt_Drvw_HwPredefChannelConfigType *const Gpt_InitPredefTimerChannel[GPT_HW_PREDEFTIMER_NUM]=
{
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/
static const Gpt_ChannelConfigType Gpt_InitChannel[GPT_CONF_CHANNELS_PB] =
{
    {   /*!<GptChannelConfiguration_0 configuration */
        (boolean)FALSE, /*!< Wakeup capability of MCU for a channel */
        &TaskNotification10ms, /*!< Pointer to callback function */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)0U, /*!< Wakeup information */
#endif
        (float64)(3000000U), /*!< The tick frequency of the timer channel in Hz.*/
        (Gpt_ValueType)(65535U), /*!< Maximum value in ticks */
        (GPT_CH_MODE_CONTINUOUS), /*!< Modes of the GPT driver */
        &Gpt_Drvw_ChannelConfig[0U]
    }
    ,
    {   /*!<GptChannelConfiguration_1 configuration */
        (boolean)FALSE, /*!< Wakeup capability of MCU for a channel */
        &TaskNotification20ms, /*!< Pointer to callback function */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)0U, /*!< Wakeup information */
#endif
        (float64)(3000000U), /*!< The tick frequency of the timer channel in Hz.*/
        (Gpt_ValueType)(65535U), /*!< Maximum value in ticks */
        (GPT_CH_MODE_CONTINUOUS), /*!< Modes of the GPT driver */
        &Gpt_Drvw_ChannelConfig[1U]
    }
    ,
    {   /*!<GptChannelConfiguration_2 configuration */
        (boolean)FALSE, /*!< Wakeup capability of MCU for a channel */
        &TaskNotification50ms, /*!< Pointer to callback function */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)0U, /*!< Wakeup information */
#endif
        (float64)(3000000U), /*!< The tick frequency of the timer channel in Hz.*/
        (Gpt_ValueType)(65535U), /*!< Maximum value in ticks */
        (GPT_CH_MODE_CONTINUOUS), /*!< Modes of the GPT driver */
        &Gpt_Drvw_ChannelConfig[2U]
    }
    ,
    {   /*!<GptChannelConfiguration_3 configuration */
        (boolean)FALSE, /*!< Wakeup capability of MCU for a channel */
        &TaskNotification1ms, /*!< Pointer to callback function */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)0U, /*!< Wakeup information */
#endif
        (float64)(3000000U), /*!< The tick frequency of the timer channel in Hz.*/
        (Gpt_ValueType)(65535U), /*!< Maximum value in ticks */
        (GPT_CH_MODE_CONTINUOUS), /*!< Modes of the GPT driver */
        &Gpt_Drvw_ChannelConfig[3U]
    }
    ,
    {   /*!<GptChannelConfiguration_4 configuration */
        (boolean)FALSE, /*!< Wakeup capability of MCU for a channel */
        &TaskNotificationTdgAdcCheck, /*!< Pointer to callback function */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)0U, /*!< Wakeup information */
#endif
        (float64)(1000000U), /*!< The tick frequency of the timer channel in Hz.*/
        (Gpt_ValueType)(4294967295U), /*!< Maximum value in ticks */
        (GPT_CH_MODE_CONTINUOUS), /*!< Modes of the GPT driver */
        &Gpt_Drvw_ChannelConfig[4U]
    }

};
    

/**
 * @brief        Gpt configuration type does not existing GptEcucPartitionRef 
 * @details      This is the type of the data structure including the configuration
 *               set required for initializing the GPT driver.
 *
 */
const Gpt_ConfigType Gpt_Config=
{
    (Gpt_ChannelType)5U,/*!< Total number of channels defined in configuration*/
    &Gpt_InitChannel,/*!< A pointer to the GPT channel configuration defined in configuration*/
    2U, /*!< Total number of instances defined in configuration*/
    &Gpt_Drvw_InstanceConfig,/*!< A pointer to the GPT instance configuration defined in configuration*/
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_InitPredefTimerChannel, /*!< A pointer to the predeftimer configuration defined in configuration*/
#endif
    &GptLogicChannelIdToIndexMap/*!< Hardware-to-logical channel mapping table*/
};


#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @} end of group Gpt_Configuration */

/** @} end of group Gpt_Module */

#ifdef __cplusplus
}
#endif /* GPT_PBCFG_C */

