/**
 * @file    Gpt_Lld_Ptmr.h
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_PTMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Ptmr
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

#ifndef GPT_LLD_PTMR_H
#define GPT_LLD_PTMR_H

#ifdef __cplusplus
extern "C"
{
#endif
/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Lld_Ptmr_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_PTMR_VENDOR_ID                      (180)
#define GPT_LLD_PTMR_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_PTMR_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_PTMR_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_PTMR_SW_MAJOR_VERSION               (2)
#define GPT_LLD_PTMR_SW_MINOR_VERSION               (3)
#define GPT_LLD_PTMR_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if GPT_LLD_PTMR_TYPES_H file and GPT_LLD_PTMR header file are of the same vendor */
#if (GPT_LLD_PTMR_TYPES_VENDOR_ID != GPT_LLD_PTMR_VENDOR_ID)
#error "Gpt_Lld_Ptmr_Types.h and Gpt_Lld_Ptmr.h have different vendor ids"
#endif

/* Check if GPT_LLD_PTMR_TYPES_H file and GPT_LLD_PTMR header file are of the same Autosar version */
#if ((GPT_LLD_PTMR_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_LLD_PTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_PTMR_TYPES_AR_RELEASE_MINOR_VERSION != GPT_LLD_PTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_PTMR_TYPES_AR_RELEASE_REVISION_VERSION != GPT_LLD_PTMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Ptmr_Types.h and Gpt_Lld_Ptmr.h are different"
#endif

/* Check if GPT_LLD_PTMR_TYPES_H file and GPT_LLD_PTMR header file are of the same Software version */
#if ((GPT_LLD_PTMR_TYPES_SW_MAJOR_VERSION != GPT_LLD_PTMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_PTMR_TYPES_SW_MINOR_VERSION != GPT_LLD_PTMR_SW_MINOR_VERSION) || \
     (GPT_LLD_PTMR_TYPES_SW_PATCH_VERSION != GPT_LLD_PTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Ptmr_Types.h and Gpt_Lld_Ptmr.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief        Initialize pTMR
 * @param[in]    ConfigPtr pointer to configuration
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_Init(const Ptmr_ConfigType *ConfigPtr);

/**
 * @brief        Initialize pTMR instance
 * @param[in]    ConfigPtr pointer to configuration
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_InitInstance(const Ptmr_InstanceConfigType *ConfigPtr);

/**
 * @brief        Initialize pTMR channel
 * @param[in]    ConfigPtr pointer to configuration
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_InitChannel(const Ptmr_ChannelConfigType *ConfigPtr);

/**
 * @brief       De-Initializes the pTMR instance.
 * @param[in]   Instance The pTMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_DeInitInstance(uint8 Instance);

/**
 * @brief       De-Initializes the pTMR channel.
 * @param[in]   Instance The pTMR instance id
 * @param[in]   Channel The pTMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_DeInitChannel(uint8 Instance, uint8 Channel);

/**
 * @brief        Start pTMR channel
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @param[in]    Value period value
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_StartChannel(uint8 Instance, uint8 Channel, Ptmr_ValueType Value);

/**
 * @brief        Stop pTMR channel
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_StopChannel(uint8 Instance, uint8 Channel);

/**
 * @brief        pTMR channel interrupt process
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_ChannelIrqProcess(uint8 Instance, uint8 Channel);

/**
 * @brief        Get pTMR channel time elapsed
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       Ptmr_ValueType time elapsed
 */
GPT_FUNC Ptmr_ValueType Gpt_Lld_Ptmr_GetChTimeElapsed(uint8 Instance, uint8 Channel);

/**
 * @brief        Get pTMR channel time remaining
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       Ptmr_ValueType time remaining
 */
GPT_FUNC Ptmr_ValueType Gpt_Lld_Ptmr_GetChTimeRemaining(uint8 Instance, uint8 Channel);

/**
 * @brief        Get pTMR channel state
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       Ptmr_ChannelStatesType channel state
 */
GPT_FUNC Ptmr_ChannelStatesType Gpt_Lld_Ptmr_GetTimerState(uint8 Instance, uint8 Channel);

/**
 * @brief        Enable pTMR channel notification
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_EnableNotification(uint8 Instance, uint8 Channel);

/**
 * @brief        Disable pTMR channel notification
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_DisNotification(uint8 Instance, uint8 Channel);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function sets the operation mode of the pTMR.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_SetMode(Gpt_ModeType Mode);
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/**
 * @brief       This function gets the pTMR hardware instance configuration.
 * @param[in]   Instance The pTMR instance id
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_GetInstanceCfg(uint8 Instance, Ptmr_InstanceConfigType * const InstCfg);

/**
 * @brief       This function gets the pTMR channel configuration.
 * @param[in]   Instance The pTMR instance id
 * @param[in]   Channel The pTMR channel id
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_GetChannelCfg(uint8 Instance, uint8 Channel, Ptmr_ChannelConfigType * const ChCfg);

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* GPT_LLD_PTMR_H */

/** @} */

