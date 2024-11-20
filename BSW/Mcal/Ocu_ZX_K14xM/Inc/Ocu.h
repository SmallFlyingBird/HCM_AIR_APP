/**************************************************************************************************/
/**
 * @file      : Ocu.h
 * @brief     : Ocu AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Ocu
 *  @brief Ocu driver
 *  @{
 */

#ifndef OCU_H
#define OCU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Ocu_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define OCU_VENDOR_ID                   0x00B3U
#define OCU_MODULE_ID                   125U
#define OCU_AR_RELEASE_MAJOR_VERSION    4U
#define OCU_AR_RELEASE_MINOR_VERSION    6U
#define OCU_AR_RELEASE_REVISION_VERSION 0U
#define OCU_SW_MAJOR_VERSION            1U
#define OCU_SW_MINOR_VERSION            2U
#define OCU_SW_PATCH_VERSION            2U

/* Check if current file and Ocu_Types.h are the same vendor */
#if (OCU_VENDOR_ID != OCU_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Ocu.h and Ocu_Types.h are different"
#endif
/* Check if current file and Ocu_Types.h are the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION != OCU_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                \
     (OCU_AR_RELEASE_MINOR_VERSION != OCU_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                \
     (OCU_AR_RELEASE_REVISION_VERSION != OCU_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu.h and Ocu_Types.h are different"
#endif
/* Check if current file and Ocu_Types.h are the same Software version */
#if ((OCU_SW_MAJOR_VERSION != OCU_TYPES_H_SW_MAJOR_VERSION) ||                                \
     (OCU_SW_MINOR_VERSION != OCU_TYPES_H_SW_MINOR_VERSION) ||                                \
     (OCU_SW_PATCH_VERSION != OCU_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu.h and Ocu_Types.h are different"
#endif

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (OCU_PRECOMPILE_SUPPORT == STD_OFF)
#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
OCU_CONFIG_EXT

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"
#endif /* (OCU_PRECOMPILE_SUPPORT == STD_OFF) */

/** @} end of group Global_VariableDeclaration */

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief      Service for OCU initialization.
 *             This function initializes the Ocu driver using the
 *             pre-established configurations
 *             - Service ID: 0x00
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @param[in]  ConfigPtr: Pointer to configuration set
 *
 * @return     None
 */
void Ocu_Init(const Ocu_ConfigType * ConfigPtr);

/**
 * @brief      Service to start an OCU channel.
 *             This function start an OCU channel by 
 *             allowing all compare match configured actions to be performed.
 *             - Service ID: 0x02
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_StartChannel(Ocu_ChannelType ChannelNumber);

/**
 * @brief      Service to stop an OCU channel.
 *             This function stop an OCU channel by 
 *             halting compare match configured actions for this channel.
 *             - Service ID: 0x03
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_StopChannel(Ocu_ChannelType ChannelNumber);

#if (OCU_SET_PIN_STATE_API == STD_ON)
/**
 * @brief      Service to set immediately the level of the pin associated to an OCU channel.
 *             This function set the pin associated with
 *              the channel to the level indicated by 'PinState'.
 *             - Service ID: 0x04
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  PinState: Ocu channel pin state after init or deinit
 *
 * @return     None
 */
void Ocu_SetPinState(Ocu_ChannelType ChannelNumber, Ocu_PinStateType PinState);
#endif

#if (OCU_DEINIT_API == STD_ON)
/**
 * @brief      Service for OCU de-initialization..
 *             This function de-initializes the OCU driver using the pre-established configurations
 *             The driver needs to be initialized before calling Ocu_DeInit()
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @return     None
 */
void Ocu_DeInit(void);
#endif

#if (OCU_SET_PIN_ACTION_API == STD_ON)
/**
 * @brief      Service to indicate the driver what shall be done automatically by 
 *             hardware (if supported) upon compare match.
 *             This function set the action to be performed by hardware automatically, at the next 
 *             compare match in the corresponding OCU channel.
 *             - Service ID: 0x05
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  PinAction: Ocu channel action after compare match
 *
 * @return     None
 */
void Ocu_SetPinAction(Ocu_ChannelType ChannelNumber, Ocu_PinActionType PinAction);
#endif

#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold using an absolute input data.
 *             This function set the channel threshold (the compare value) to the value 
 *             given by AbsoluteValue.
 *             - Service ID: 0x07
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  ReferenceValue: Value given by the upper layer and used as a base to determine 
 *                             whether to call the notification before the function exits or not.
 *                             This value should less then OcuMaxCounterValue in EB.
 * @param[in]  AbsoluteValue: Value to compare with the content of the counter. This value is in 
 *                            ticks.This value should less then OcuMaxCounterValue in EB.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval,
 *                             as a result of setting the new threshold value.
 * 
 * @retval     OCU_CM_IN_REF_INTERVAL:   The compare match will occur inside the current 
 *                                       reference interval.
 * @retval     OCU_CM_OUT_REF_INTERVAL:  The compare match will not occur inside the current 
 *                                       reference interval.
 */
Ocu_ReturnType Ocu_SetAbsoluteThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType ReferenceValue, Ocu_ValueType AbsoluteValue);
#endif

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold relative to the current value of 
 *             the counter.
 *             This function set the channel threshold (the compare value) to the value 
 *             given by RelativeValue.
 *             - Service ID: 0x08
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 * @param[in]  RelativeValue: Value to use for computing the new threshold.
 * This value should less then OcuMaxCounterValue in EB.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval,
 *                             as a result of setting the new threshold value.
 * 
 * @retval     OCU_CM_IN_REF_INTERVAL:   The compare match will occur inside the current 
 *                                       reference interval.
 * @retval     OCU_CM_OUT_REF_INTERVAL:  The compare match will not occur inside the current 
 *                                       reference interval.
 */
Ocu_ReturnType Ocu_SetRelativeThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType RelativeValue);
#endif

#if (OCU_GET_COUNTER_API == STD_ON)
/**
 * @brief      Service to read the current value of the counter.
 *             This function read and return the value of the counter of the channel indicated by 
 *             ChannelNumber.
 *             - Service ID: 0x06
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     Ocu_ValueType
 * @retval  RetVal: Content of the counter in ticks
 */
Ocu_ValueType Ocu_GetCounter(Ocu_ChannelType ChannelNumber);
#endif

#if (OCU_VERSION_INFO_API == STD_ON)
/**
 * @brief      This service returns the version information of this module.
 *             This function return the version information of this module. 
 *             The version information includes:
 *             - Module Id
 *             - Vendor Id
 *             - Vendor specific version numbers.
 *             - Service ID: 0x09
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  None
 * @param[out] versioninfo: Pointer to where to store the version information of this module
 *
 * @return     None
 */
void Ocu_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief      This service is used to disable notifications from an OCU channel.
 *             This function disable the OCU compare match notification.
 *             - Service ID: 0x0a
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_DisableNotification(Ocu_ChannelType ChannelNumber);
#endif

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief      This service is used to enable notifications from an OCU channel.
 *             This function enable the OCU compare match notification of the indexed channel.
 *             - Service ID: 0x0b
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant for different channel numbers
 *
 * @param[in]  ChannelNumber: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_EnableNotification(Ocu_ChannelType ChannelNumber);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Ocu */

/** @} end of group Ocu_Module */

#endif /* OCU_H */
