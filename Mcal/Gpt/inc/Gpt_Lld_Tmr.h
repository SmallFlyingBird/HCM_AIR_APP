/**
 * @file    Gpt_Lld_Tmr.h
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_TMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Tmr
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

#ifndef GPT_LLD_TMR_H
#define GPT_LLD_TMR_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_TMR_VENDOR_ID                      (180)
#define GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_TMR_SW_MAJOR_VERSION               (2)
#define GPT_LLD_TMR_SW_MINOR_VERSION               (3)
#define GPT_LLD_TMR_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Lld_Tmr_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_Types.h"

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if GPT_LLD_TMR_TYPES_H file and GPT_LLD_TMR header file are of the same vendor */
#if (GPT_LLD_TMR_TYPES_VENDOR_ID != GPT_LLD_TMR_VENDOR_ID)
#error "Gpt_Lld_Tmr_Types.h and Gpt_Lld_Tmr.h have different vendor ids"
#endif

/* Check if GPT_LLD_TMR_TYPES_H file and GPT_MLD header file are of the same Autosar version */
#if ((GPT_LLD_TMR_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_TMR_TYPES_AR_RELEASE_MINOR_VERSION != GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_TMR_TYPES_AR_RELEASE_REVISION_VERSION != GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Tmr_Types.h and Gpt_Lld_Tmr.h are different"
#endif

/* Check if GPT_LLD_TMR_TYPES_H file and GPT_MLD header file are of the same Software version */
#if ((GPT_LLD_TMR_TYPES_SW_MAJOR_VERSION != GPT_LLD_TMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_TMR_TYPES_SW_MINOR_VERSION != GPT_LLD_TMR_SW_MINOR_VERSION) || \
     (GPT_LLD_TMR_TYPES_SW_PATCH_VERSION != GPT_LLD_TMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Tmr_Types.h and Gpt_Lld_Tmr.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief       Initializes the TMR driver.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_Init(const Tmr_ConfigType *ConfigPtr);

/**
 * @brief       Initializes the TMR instance.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_InitInstance(const Tmr_InstanceConfigType *ConfigPtr);

/**
 * @brief       Initializes the TMR channel.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_InitChannel(const Tmr_ChannelConfigType *ConfigPtr);

/**
 * @brief       De-Initializes the TMR instance.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_DeInitInstance(uint8 Instance);

/**
 * @brief       De-Initializes the TMR channel.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_DeInitChannel(uint8 Instance, uint8 Channel);

/**
 * @brief       Starts the TMR.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_Start(uint8 Instance);

/**
 * @brief       Stops the TMR.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_Stop(uint8 Instance);

/**
 * @brief       Starts the TMR channel.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @param[in]   Value The TMR channel value, the minimum value is TMR_CH_CMP_VALUE_MIN
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_StartChannel(uint8 Instance, uint8 Channel, Tmr_ValueType Value);

/**
 * @brief       Stops the TMR channel.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_StopChannel(uint8 Instance, uint8 Channel);

/**
 * @brief       Gets the TMR channel time elapsed.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      Tmr_ValueType
 */
GPT_FUNC Tmr_ValueType Gpt_Lld_Tmr_GetChTimeElapsed(uint8 Instance, uint8 Channel);

/**
 * @brief       Gets the TMR channel time remaining.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      Tmr_ValueType
 */

GPT_FUNC Tmr_ValueType Gpt_Lld_Tmr_GetChTimeRemaining(uint8 Instance, uint8 Channel);


#if defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1ME0)
/**
 * @brief       TMR channel interrupt process.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_ChannelIrqProcess(uint8 Instance, uint8 Channel);
#endif

#if defined(CPU_YTM32B1HA0)
/**
 * @brief       TMR channel interrupt process.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_ChannelIrqProcess(uint8 Instance);
#endif

/**
 * @brief       Gets the TMR channel state.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      Tmr_ChannelStatesType
 */
GPT_FUNC Tmr_ChannelStatesType Gpt_Lld_Tmr_GetTimerState(uint8 Instance, uint8 Channel);

/**
 * @brief       Enables the TMR channel notification.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_EnableNotification(uint8 Instance, uint8 Channel);

/**
 * @brief       Disables the TMR channel notification.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_DisableNotification(uint8 Instance, uint8 Channel);

/**
 * @brief       This function gets the TMR hardware instance configuration.
 * @param[in]   Instance The TMR instance id
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_GetInstanceCfg(uint8 Instance, Tmr_InstanceConfigType * const InstCfg);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function sets the operation mode of the TMR.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_SetMode(Gpt_ModeType Mode);
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/**
 * @brief       This function gets the TMR channel configuration.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_GetChannelCfg(uint8 Instance, uint8 Channel, Tmr_ChannelConfigType * const ChCfg);

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* GPT_LLD_TMR_H */

/** @} */

