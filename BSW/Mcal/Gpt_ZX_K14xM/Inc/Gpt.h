/**************************************************************************************************/
/**
 * @file      : Gpt.h
 * @brief     : AUTOSAR Gpt driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef GPT_H
#define GPT_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Gpt
 *  @brief Gpt AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_MODULE_ID                   100U
#define GPT_VENDOR_ID                   0x00B3U
#define GPT_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_AR_RELEASE_MINOR_VERSION    6U
#define GPT_AR_RELEASE_REVISION_VERSION 0U
#define GPT_SW_MAJOR_VERSION            1U
#define GPT_SW_MINOR_VERSION            2U
#define GPT_SW_PATCH_VERSION            2U

/* Check if current file and Gpt_Types header file are of the same vendor */
#if (GPT_VENDOR_ID != GPT_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Gpt.h and Gpt_Types.h are different"
#endif
/* Check if current file and Gpt_Types header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt.h and Gpt_Types.h are different"
#endif
/* Check if current file and Gpt_Types header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (GPT_SW_MINOR_VERSION != GPT_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (GPT_SW_PATCH_VERSION != GPT_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt.h and Gpt_Types.h are different"
#endif

/* Error Values */

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief API service called without module initialization.
 *
 */
#define GPT_E_UNINIT ((uint8)0x0AU)
/**
 * @brief API service for initialization called when already initialized.
 *
 */
#define GPT_E_ALREADY_INITIALIZED ((uint8)0x0DU)
#endif

/**
 * @brief API Gpt_Init was called with wrong configuration pointer.
 *
 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #define GPT_E_INIT_FAILED ((uint8)0x0EU)
#endif

/**
 * @brief API service called for invalid channel.
 *
 */
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)

/**
 * @brief API service called with invalid value.
 *
 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #define GPT_E_PARAM_VALUE ((uint8)0x15U)
#endif

/**
 * @brief API service called with invalid pointer.
 *
 */
#if (((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)) ||        \
     ((GPT_VERSION_INFO_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)))
    #define GPT_E_PARAM_POINTER ((uint8)0x16U)
#endif

/**
 * @brief API service called with invalid PredefTimer.
 *
 */
#if ((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_E_PARAM_PREDEF_TIMER ((uint8)0x17U)
#endif

/**
 * @brief API service called with invalid mode.
 *
 */
#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) &&               \
     (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    #define GPT_E_PARAM_MODE ((uint8)0x1FU)
#endif

/**
 * @brief API service called wfor invalid channel on the current core.
 *
 */
#define GPT_E_PARAM_CONFIG ((uint8)0x18U)

/**
 * @brief API service called with wrong parameter.
 *
 */
#if ((GPT_SET_DUAL_CLOCK_MODE == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_E_PARAM_CLOCK_MODE ((uint8)0x20U)
#endif

/**
 * @brief The Gpt_StartTimer function is called when the channel is in sleep mode and wake up is
 *        not enabled.
 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #if (((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)))
        #define GPT_E_INVALID_CALL ((uint8)0xA0U)
    #endif
#endif

/**
 * @brief API service called when timer channel is still busy (running).
 *
 */

#define GPT_E_BUSY ((uint8)0x0BU)
/**
 * @brief API service called when driver is in wrong mode.
 *
 */
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    #define GPT_E_MODE ((uint8)0x0CU)
#endif

/**
 * @brief API service called when a timeout is occurred.
 *
 */
#define GPT_E_TIMEOUT ((uint8)0x2BU)

/* Service IDs */
/**
 * @brief API service ID for get Gpt version information.
 *
 */
#if ((GPT_VERSION_INFO_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_SID_GET_VERSION_INFO ((uint8)0x00U)
#endif
/**
 * @brief API service ID for Gpt init function.
 *
 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #define GPT_SID_INIT ((uint8)0x01U)
#endif
/**
 * @brief API service ID for Gpt deinit function.
 * @details Parameters used when raising an error or exception.
 *
 */
#if (GPT_DEINIT_API == STD_ON)
    #define GPT_SID_DEINIT ((uint8)0x02U)
#endif
/**
 * @brief API service ID for get elapsed time function.
 *
 */
#if ((GPT_TIME_ELAPSED_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_SID_GET_TIME_ELAPSED ((uint8)0x03U)
#endif
/**
 * @brief API service ID for get remaining time function.
 *
 */
#if ((GPT_TIME_REMAINING_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_SID_GET_TIME_EMAINING ((uint8)0x04U)
#endif
/**
 * @brief API service ID for Gpt start timer function.
 *
 */
#define GPT_SID_START_TIMER ((uint8)0x05U)

/**
 * @brief API service ID for Gpt stop timer function.
 *
 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #define GPT_SID_STOP_TIMER ((uint8)0x06U)
#endif
/**
 * @brief API service ID for Gpt enable notification function.
 *
 */
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON))
    #define GPT_SID_ENABLE_NOTIFICATION ((uint8)0x07U)
#endif
/**
 * @brief API service ID for Gpt disable notification function.
 *
 */
#define GPT_SID_DISABLE_NOTIFICATION ((uint8)0x08U)

/**
 * @brief API service ID for Gpt set mode function.
 *
 */
#if (((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_DEV_ERROR_DETECT == STD_ON)) ||             \
     ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) &&              \
      (GPT_REPORT_WAKEUP_SOURCE == STD_ON)))
    #define GPT_SID_SET_MODE ((uint8)0x09U)
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief API service ID for Gpt disable wakeup function.
 *
 */
#define GPT_SID_DISABLE_WAKEUP ((uint8)0x0AU)
/**
 * @brief API service ID for Gpt enable wakeup function.
 *
 */
#define GPT_SID_ENABLE_WAKEUP ((uint8)0x0BU)
/**
 * @brief API service ID for Gpt check wakeup function.
 *
 */
#define GPT_SID_CHECK_WAKEUP ((uint8)0x0CU)
#endif

#endif /*((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))*/
/**
 * @brief API service ID for Gpt get predeftimer value function.
 *
 */
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    #define GPT_SID_GET_PREDEFTIMER_VALUE ((uint8)0x0DU)
#endif

/**
 * @brief API service ID for Gpt set clock mode function.
 *
 */
#if ((GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_SET_DUAL_CLOCK_MODE == STD_ON))
    #define GPT_SID_SET_CLOCK_MODE ((uint8)0x10U)
#endif

/**
 * @brief Instance ID.
 */
#define GPT_INSTANCE_ID ((uint8)0U)

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
GPT_CONFIG_EXT

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
#else
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/* Extern declarations of GPT Pre compile configuration from Gpt_PBCfg.c */
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
extern const Gpt_ConfigType *const Gpt_PreDefinedConfigPtr[GPT_MAX_PARTITIONS];
#endif

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
#endif

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (GPT_VERSION_INFO_API == STD_ON)
/**
 * @brief    This function get Gpt version information.
 *           - Service ID: 0x00U
 *           - Sync or Async: Synchronous
 *           - Reentrancy: Reentrant
 *
 * @param[out] VersionInfoPtr: Pointer to where to store the version information of this module.
 *
 * @return     None
 */
/* SWS_Gpt_00279 */
void Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
#endif

/**
 * @brief      This function initializes the Gpt driver.
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @param[in]  ConfigPtr: Pointer to a selected configuration structure.
 *
 * @return     None
 */
/* SWS_Gpt_00280 */
void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

#if (GPT_DEINIT_API == STD_ON)
/**
 * @brief      This function de-initializes the Gpt driver.
 *             - Service ID: 0x02
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @return     None
 */
/* SWS_Gpt_00281 */
void Gpt_DeInit(void);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief     This function returns the time already elapsed.
 *            - Service ID: 0x03
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the Gpt channel.
 *
 * @return    Gpt_ValueType
 * @retval    Elapsed timer value (in number of ticks).
 */
/* SWS_Gpt_00282 */
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief     This function returns the time remaining until the target time is reached.
 *            - Service ID: 0x04
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the Gpt channel.
 *
 * @return    Gpt_ValueType
 * @retval    Remaining timer value (in number of ticks).
 */
/* SWS_Gpt_00283 */
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
#endif

/**
 * @brief     This function for starting a timer channel.
 *            - Service ID: 0x05
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 * @param[in] Value: Target time in number of ticks. This value is dependent on the specific GPT 
 *                   channel, the TIM (HW IP) channel should be less than or equal to 0xFFFF.
 *
 * @return    None.
 */
/* SWS_Gpt_00284 */
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/**
 * @brief     This function for stopping a timer channel.
 *            - Service ID: 0x06
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
/* SWS_Gpt_00285 */
void Gpt_StopTimer(Gpt_ChannelType Channel);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief     This function for enabling the interrupt notification for a channel
 *            (relevant in normal mode).
 *            - Service ID: 0x07
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
/* SWS_Gpt_00286 */
void Gpt_EnableNotification(Gpt_ChannelType Channel);

/**
 * @brief     This function for disabling the interrupt notification for a channel
 *            (relevant in normal mode).
 *            - Service ID: 0x08
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
/* SWS_Gpt_00287 */
void Gpt_DisableNotification(Gpt_ChannelType Channel);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     This function for setting the operation mode of the Gpt.
 *            - Service ID: 0x09
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Mode    operation mode :
 *                    - GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                    - GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *
 * @return    None.
 */
/* SWS_Gpt_00288 */
void Gpt_SetMode(Gpt_ModeType Mode);

/**
 * @brief     This function for disabling the wakeup interrupt of a channel
 *            (relevant in sleep mode).
 *            - Service ID: 0x0A
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
/* SWS_Gpt_00289 */
void Gpt_DisableWakeup(Gpt_ChannelType Channel);

/**
 * @brief     This function for enabling the wakeup interrupt  of a channel
 *            (relevant in sleep mode)
 *            - Service ID: 0x0B
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Channel: Numeric identifier of the GPT channel.
 *
 * @return    None.
 */
/* SWS_Gpt_00290 */
void Gpt_EnableWakeup(Gpt_ChannelType Channel);

/**
 * @brief     The function for checking if a wakeup capable GPT channel is the source for a wakeup
 *            event.
 *            - Service ID: 0x0C
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] WakeupSource: Information on wakeup source to be checked. The associated Gpt channel
 *                          can be determined from configuration data.
 *
 * @return    None.
 */
/* SWS_Gpt_00328 */
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief     The function delivers the current value of the desired GPT Predef Timer.
 *            - Service ID: 0x0D
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in]  PredefTimer: GPT Predef Timer.
 * @param[out] TimeValuePtr: Pointer to time value destination data in RAM.
 *
 * @return     Std_ReturnType.
 * @retval     E_OK:      No error has been detected
 * @retval     E_NOT_OK:  Aborted due to errors
 */
/* SWS_Gpt_00394 */
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr);
#endif

#if (GPT_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief     This function changes the channel prescaler.
 *            - Service ID: 0x10
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] ClockMode   Dual clock mode.
 *
 * @return    None
 */
void Gpt_SetDualClockMode(Gpt_ClockModeType ClockMode);
#endif

/**
 * @brief   Stop of Gpt section CODE
 */
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt */

/** @} end of group Gpt_Module */

#endif /* GPT_H */
