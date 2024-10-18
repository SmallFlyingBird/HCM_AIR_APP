/**************************************************************************************************/
/**
 * @file      : Ocu_Drvw.h
 * @brief     : Ocu driver wrapper header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Ocu_Drvw
 *  @brief Ocu driver
 *  @{
 */

#ifndef OCU_DRVW_H
#define OCU_DRVW_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Ocu_Drvw_Types.h "

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define OCU_DRVW_H_VENDOR_ID                   0x00B3U
#define OCU_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define OCU_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define OCU_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define OCU_DRVW_H_SW_MAJOR_VERSION            1U
#define OCU_DRVW_H_SW_MINOR_VERSION            2U
#define OCU_DRVW_H_SW_PATCH_VERSION            1U

/* Check if current file and Ocu_Drvw_Types.h are the same vendor */
#if (OCU_DRVW_H_VENDOR_ID != OCU_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Drvw.h and Ocu_Drvw_Types.h are different"
#endif
/* Check if current file and Ocu_Drvw_Types.h are the same Autosar version */
#if ((OCU_DRVW_H_AR_RELEASE_MAJOR_VERSION != OCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (OCU_DRVW_H_AR_RELEASE_MINOR_VERSION != OCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (OCU_DRVW_H_AR_RELEASE_REVISION_VERSION != OCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Drvw.h and Ocu_Drvw_Types.h are different"
#endif
/* Check if current file and Ocu_Drvw_Types.h are the same Software version */
#if ((OCU_DRVW_H_SW_MAJOR_VERSION != OCU_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (OCU_DRVW_H_SW_MINOR_VERSION != OCU_DRVW_TYPES_H_SW_MINOR_VERSION) ||                         \
     (OCU_DRVW_H_SW_PATCH_VERSION != OCU_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Drvw.h and Ocu_Drvw_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
OCU_DRVW_CONFIG_EXT

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief     OCU Driver wrapper initialization.
 * 
 * @param[in] Ocu_Drvw_Config: Pointer to wrapper configuration set
 *
 * @return    None
 */
void Ocu_Drvw_Init(const Ocu_Drvw_ConfigType * const Ocu_Drvw_Config);

#if (STD_ON == OCU_DRVW_NOTIFICATION_SUPPORTED)
/**
 * @brief      This service is used to disable notifications from an OCU channel in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_DisableNotification(uint16 NumChannel);

/**
 * @brief      This service is used to enable notifications from an OCU channel in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_EnableNotification(uint16 NumChannel);

#endif

/**
 * @brief      Service to start an OCU channel in wrapper level.
 *             This function  start an OCU channel by 
 *             allowing all compare match configured actions to be performed.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_StartChannel(uint16 NumChannel);

/**
 * @brief      Service to stop an OCU channel in wrapper level.
 *             This function stop an OCU channel by 
 *             halting compare match configured actions for this channel.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     None
 */
void Ocu_Drvw_StopChannel(uint16 NumChannel);

#if (OCU_DRVW_GET_COUNTER_API == STD_ON)
/**
 * @brief      Service to read the current value of the counter in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     uint16
 * @retval  RetCntVal: Content of the counter in ticks
 */
uint16 Ocu_Drvw_GetCounter(uint16 NumChannel);
#endif /* OCU_DRVW_GET_COUNTER_API */

#if (STD_ON == OCU_DRVW_SET_PIN_STATE_API)
/**
 * @brief      Service to set immediately the level of the pin associated to an OCU channel in 
 *             wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  PinState: Ocu channel pin state after init or deinit
 *
 * @return     None
 */
void Ocu_Drvw_SetPinState(uint16 NumChannel, OCU_DRVW_PIN_STATE_TYPE PinState);
#endif

#if (OCU_DRVW_SET_PIN_ACTION_API == STD_ON)
/**
 * @brief      Service to indicate the driver what shall be done automatically by 
 *             hardware (if supported) upon compare match in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  PinAction: Ocu channel action after compare match
 *
 * @return     None
 */
void Ocu_Drvw_SetPinAction(uint16 NumChannel, OCU_DRVW_PIN_ACTION_TYPE PinAction);
#endif

#if (OCU_DRVW_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/**
 * @brief      Service to set the value of the channel threshold using an absolute input data in 
 *             wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  ReferenceValue: Value given by the upper layer and used as a base to determine 
 *                             whether to call the notification before the function exits or not.
 * @param[in]  AbsoluteValue: Value to compare with the content of the counter. This value is in 
 *                            ticks.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:   The compare match will occur in this interval.
 * @retval     TIM_OCU_DRV_OUT_INTERVAL:  The compare match will occur out this interval.
 */
OCU_DRVW_RETURN_TYPE Ocu_Drvw_SetAbsoluteThreshold(uint16 NumChannel, uint16 ReferenceValue, uint16 AbsoluteValue);
#endif /* OCU_DRVW_SET_ABSOLUTE_THRESHOLD_API*/

#if ((OCU_DRVW_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_DRVW_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
 * @brief      Service to read the max value of the counter in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 *
 * @return     uint16
 * @retval  RetMaxCntVal: max value of the counter in ticks
 */
uint16 Ocu_Drvw_GetMaxCounterValue(uint16 NumChannel);
#endif

#if (OCU_DRVW_SET_RELATIVE_THRESHOLD_API == STD_ON) 
/**
 * @brief      Service to set the value of the channel threshold relative to the current value of 
 *             the counter in wrapper level.
 *
 * @param[in]  NumChannel: Numeric identifier of the OCU channel
 * @param[in]  RelativeValue: Value to use for computing the new threshold.
 *
 * @return     Ocu_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:   The compare match will occur in this interval.
 * @retval     TIM_OCU_DRV_OUT_INTERVAL:  The compare match will occur out this interval.
 */
OCU_DRVW_RETURN_TYPE Ocu_Drvw_SetRelativeThreshold(uint16 NumChannel, uint16 RelativeValue);
#endif /*OCU_DRVW_SET_RELATIVE_THRESHOLD_API */

#if (OCU_DRVW_DEINIT_API == STD_ON)
/**
 * @brief     OCU Driver wrapper deinitialization.
 * 
 * @param[in] Ocu_Drvw_Config: Pointer to wrapper configuration set
 *
 * @return    None
 */
void Ocu_Drvw_DeInit(const Ocu_Drvw_ConfigType * const Ocu_Drvw_Config);
#endif /* OCU_DRVW_DEINIT_API */

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Ocu_Drvw */

/** @} end of group Ocu_Module */

#endif /* OCU_DRVW_H */
