/**
 * @file    Gpt_Mld.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr, Ptmr, Tmr, Rtc
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

#ifndef GPT_MLD_H
#define GPT_MLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_MLD_VENDOR_ID                      (180)
#define GPT_MLD_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_MLD_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_MLD_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_MLD_SW_MAJOR_VERSION               (2)
#define GPT_MLD_SW_MINOR_VERSION               (3)
#define GPT_MLD_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
* @brief        Initializes the GPT Instances.
* @param[in]    configPtr    Pointer to the Gpt configuration structure.
* @return       void
*/
GPT_FUNC void Gpt_Mld_InitInstances(const Gpt_ConfigType * ConfigPtr);

/**
 * @brief       Initializes the GPT MLD driver.
 * @param[in]   GptChannelConfigPtr    Pointer to the channel configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_Init(const Gpt_ChannelConfigType *GptChannelConfigPtr);

/**
 * @brief       De-Initializes the GPT MLD driver.
 * @param[in]   configPtr    Pointer to the Gpt configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_DeInit(const Gpt_ConfigType *ConfigPtr);

/**
 * @brief       Starts a GPT MLD timer channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @param[in]   Value Target time in number of ticks.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_StartTimer(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr, Gpt_ValueType Value);

/**
 * @brief       Stops a GPT MLD timer channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_StopTimer(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);

/**
 * @brief       Returns the status of the GPT channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      Gpt_ChannelStatusType
 * @retval      GPT_STATUS_RUNNING Channel is running
 * @retval      GPT_STATUS_STOPPED Channel is stopped
 * @retval      GPT_STATUS_EXPIRED Channel is expired
 */
GPT_FUNC Gpt_ChannelStatusType Gpt_Mld_GetChannelState(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);

/**
 * @brief       Checks if the channel is valid.
 * @param[in]   configPtr Pointer to the Gpt configuration structure.
 * @param[in]   Channel Numeric identifier of the GPT channel.
 * @return      Std_ReturnType
 * @retval      E_OK Channel is valid
 * @retval      E_NOT_OK Channel is not valid
 */
GPT_FUNC Std_ReturnType Gpt_Mld_CheckChannel(const Gpt_ConfigType *ConfigPtr, uint16 Channel);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief       Enables the interrupt notification for a channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_EnableNotification(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);

/**
 * @brief       Disables the interrupt notification for a channel.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_DisableNotification(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Enables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_EnableWakeup(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);

/**
 * @brief       Disables the wakeup interrupt of a channel (relevant in sleep mode).
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_DisableWakeup(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);

/**
 * @brief       Sets the operation mode of the GPT.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_SetMode(Gpt_ModeType Mode);
/**
 * @brief       Checks if a wakeup capable GPT channel is the source for a wakeup event and calls
 *              the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel
 *              wakeup event.
 * @param[in]   WakeupSource Information on wakeup source to be checked. The associated GPT channel
 *  can be determined from configuration data.
 * @return      void
 */
GPT_FUNC void Gpt_Mld_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief       Returns the time already elapsed.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      Gpt_ValueType
 */
GPT_FUNC Gpt_ValueType Gpt_Mld_GetTimeElapsed(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief       Returns the time remaining until the target time is reached.
 * @param[in]   GptHwChannelConfigPtr Pointer to the Gpt channel hardware configuration structure.
 * @return      Gpt_ValueType
 */
GPT_FUNC Gpt_ValueType Gpt_Mld_GetTimeRemaining(const Gpt_HwChannelConfigType *GptHwChannelConfigPtr);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"   /*NOSONAR, The #include need to be here to be able to use the Gpt_MemMap.h */

#ifdef __cplusplus
}
#endif

#endif /*GPT_MLD_H*/

/** @} */

