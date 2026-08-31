/**
 * @file    Gpt_Lld_Rtc.h
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_RTC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Rtc
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

#ifndef GPT_LLD_RTC_H
#define GPT_LLD_RTC_H

#ifdef __cplusplus
extern "C"
{
#endif
/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_Lld_Rtc_Types.h"
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM.h"
#endif
#include "Gpt_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_RTC_VENDOR_ID                      (180)
#define GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_RTC_SW_MAJOR_VERSION               (2)
#define GPT_LLD_RTC_SW_MINOR_VERSION               (3)
#define GPT_LLD_RTC_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if GPT_LLD_RTC_TYPES_H file and GPT_LLD_RTC header file are of the same vendor */
#if (GPT_LLD_RTC_TYPES_VENDOR_ID != GPT_LLD_RTC_VENDOR_ID)
#error "Gpt_Lld_Rtc_Types.h and Gpt_Lld_Rtc.h have different vendor ids"
#endif

/* Check if GPT_LLD_RTC_TYPES_H file and GPT_LLD_RTC header file are of the same Autosar version */
#if ((GPT_LLD_RTC_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_RTC_TYPES_AR_RELEASE_MINOR_VERSION != GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_RTC_TYPES_AR_RELEASE_REVISION_VERSION != GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Rtc_Types.h and Gpt_Lld_Rtc.h are different"
#endif

/* Check if GPT_LLD_RTC_TYPES_H file and GPT_LLD_RTC header file are of the same Software version */
#if ((GPT_LLD_RTC_TYPES_SW_MAJOR_VERSION != GPT_LLD_RTC_SW_MAJOR_VERSION) || \
     (GPT_LLD_RTC_TYPES_SW_MINOR_VERSION != GPT_LLD_RTC_SW_MINOR_VERSION) || \
     (GPT_LLD_RTC_TYPES_SW_PATCH_VERSION != GPT_LLD_RTC_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Rtc_Types.h and Gpt_Lld_Rtc.h are different"
#endif

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief       This function initializes the RTC module.
 * @param[in]   ConfigPtr Pointer to the RTC instance configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_RtcInitInstance(const Rtc_InstanceConfigType * ConfigPtr);

/**
 * @brief       This function initializes the RTC module.
 * @param[in]   ConfigPtr Pointer to the RTC configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_Init(const Rtc_ConfigType *ConfigPtr);

/**
 * @brief       De-Initializes the RTC instance.
 * @param[in]   Instance The RTC instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_DeInit(uint8 Instance);

/**
 * @brief       This function starts the RTC module.
 * @param[in]   Value Period value.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_StartTimer(Rtc_ValueType Value);

/**
 * @brief       This function stops the RTC module.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_StopTimer(void);

/**
 * @brief       This function is the RTC interrupt handler.
 * @return      void
 */
 GPT_FUNC void Gpt_Lld_Rtc_IrqProcess(void);

/**
 * @brief       This function returns the elapsed time.
 * @return      Rtc_ValueType Elapsed time.
 */
 GPT_FUNC Rtc_ValueType Gpt_Lld_Rtc_GetTimeElapsed(void);

/**
 * @brief       This function returns the remaining time.
 * @return      Rtc_ValueType Remaining time.
 */
 GPT_FUNC Rtc_ValueType Gpt_Lld_Rtc_GetTimeRemaining(void);

/**
 * @brief       This function returns the RTC state.
 * @return      Rtc_StatesType
 */
GPT_FUNC Rtc_StatesType Gpt_Lld_Rtc_GetTimerState(void);

/**
 * @brief       This function enables the RTC notification.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_EnableNotification(void);

/**
 * @brief       This function disables the RTC notification.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_DisableNotification(void);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function enables the RTC wakeup.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_EnableWakeup(void);

/**
 * @brief       This function disables the RTC wakeup.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_DisableWakeup(void);

/**
 * @brief       This function sets the operation mode of the RTC.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_SetMode(Gpt_ModeType Mode);

/**
 * @brief       This function checks whether RTC is the source for a wakeup event.
 * @param[in]   EcuM_WakeupSourceType WakeupSource
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/**
 * @brief       This function gets the RTC hardware instance configuration.
 * @param[in]   Instance The RTC instance id
 * @param[in]   Cfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_GetCfg(uint8 Instance, Rtc_ConfigType * const Cfg);

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_LLD_RTC_H*/

/** @} */

