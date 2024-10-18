/**************************************************************************************************/
/**
 * @file      : Tim_Ocu_Drv.h
 * @brief     : Ocu low level driver header file
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

/** @addtogroup Tim_Ocu_Drv
 *  @brief Ocu driver
 *  @{
 */

#ifndef TIM_OCU_DRV_H
#define TIM_OCU_DRV_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Ocu_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_OCU_DRV_H_VENDOR_ID                   0x00B3U
#define TIM_OCU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_OCU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_OCU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_OCU_DRV_H_SW_MAJOR_VERSION            1U
#define TIM_OCU_DRV_H_SW_MINOR_VERSION            2U
#define TIM_OCU_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Ocu_Drv_Types.h are the same vendor */
#if (TIM_OCU_DRV_H_VENDOR_ID != TIM_OCU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Tim_Ocu_Drv.h and Tim_Ocu_Drv_Types.h are different"
#endif

/* Check if  header file and Tim_Ocu_Drv_Types.h  file are of the same Autosar version */
#if ((TIM_OCU_DRV_H_AR_RELEASE_MAJOR_VERSION != TIM_OCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_OCU_DRV_H_AR_RELEASE_MINOR_VERSION != TIM_OCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_OCU_DRV_H_AR_RELEASE_REVISION_VERSION != TIM_OCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Ocu_Drv.h and Tim_Ocu_Drv_Types.h  are different"
#endif

/* Check if header file and Tim_Ocu_Drv_Types.h  file are of the same Software version */
#if ((TIM_OCU_DRV_H_SW_MAJOR_VERSION != TIM_OCU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (TIM_OCU_DRV_H_SW_MINOR_VERSION != TIM_OCU_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (TIM_OCU_DRV_H_SW_PATCH_VERSION != TIM_OCU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Ocu_Drv.h and Tim_Ocu_Drv_Types.h  are different"
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
TIM_OCU_DRV_CONFIG_EXT

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief     The function services get TIM channel number.
 *
 * @param[in] HwChannelId: Channel TIM hw id
 *
 * @return    uint8
 */
LOCAL_INLINE uint8 Tim_Ocu_Drv_GetChannelNum(uint16 HwChannelId)
{
    return (uint8)((HwChannelId & TIM_OCU_DRV_CH_MASK_U8) >> TIM_OCU_DRV_CH_SHIFT);
}

/**
 * @brief     The function services get TIM instance number.
 *
 * @param[in] HwChannelId: Channel TIM hw id
 *
 * @return    uint8
 */
LOCAL_INLINE uint8 Tim_Ocu_Drv_GetInstanceNum(uint16 HwChannelId)
{
    return (uint8)((HwChannelId & TIM_OCU_DRV_MOD_MASK_U8) >> (3U));
}

/**
 * @brief     The function initializes the OCU Driver.
 *
 * @param[in] ModuleConfigPtr: Pointer to the OCU configuration
 *
 * @return    None
 */
void Tim_Ocu_Drv_Init(const Tim_Ocu_Drv_ModuleConfigType * const ModuleConfigPtr);

/**
 * @brief      Service to start an TIM channel.
 *             This function  start an TIM channel by 
 *             allowing all compare match configured actions to be performed.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_StartChannel(uint8 InstNum, uint8 ChNum);

/**
 * @brief      Service to stop an TIM channel.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_StopChannel(uint8 InstNum, uint8 ChNum);

/**
 * @brief      Service to indicate the driver what shall be done automatically by 
 *             hardware (if supported) upon compare match.
 *             This function set the action to be performed by hardware automatically, at the next 
 *             compare match in the corresponding OCU channel.
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  PinAction: Ocu channel action after compare match
 *
 * @return     None
 */
void Tim_Ocu_Drv_SetPinAction(uint8 InstNum, uint8 ChNum, Tim_Ocu_Drv_PinActionType PinAction);

/**
 * @brief      Service to get current counter value of TIM.
 *
 * @param[in]  InstNum: Module id of the TIM
 *
 * @return     Tim_Ocu_Drv_ValueType: current counter value
 */
Tim_Ocu_Drv_ValueType Tim_Ocu_Drv_GetCounter(uint8 InstNum);

/**
 * @brief      Service to set immediately the level of the pin associated to an OCU channel
 * 
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  PinState: Ocu channel pin state after init or deinit
 *
 * @return     None
 */
void Tim_Ocu_Drv_SetPinState(uint8 InstNum, uint8 ChNum, Tim_Ocu_Drv_PinStateType PinState);

/**
 * @brief      Service to set the value of the channel threshold using an absolute input data.
 * 
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  ReferenceValue: Value to use for computing the new threshold by reference.
 * @param[in]  AbsoluteValue: Value to use for computing the new threshold.
 *
 * @return     Tim_Ocu_Drv_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:  compare match was in the given interval
 * @retval     TIM_OCU_DRV_OUT_INTERVAL: compare match was out of the given interval
 */
Tim_Ocu_Drv_ReturnType Tim_Ocu_Drv_SetAbsoluteThreshold(uint8 InstNum, uint8 ChNum, \
                        Tim_Ocu_Drv_ValueType ReferenceValue, Tim_Ocu_Drv_ValueType AbsoluteValue);

/**
 * @brief      Service to set the value of the channel threshold relative to the current value of 
 *             the counter.
 * 
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 * @param[in]  RelativeValue: Value to use for computing the new threshold.
 *
 * @return     Tim_Ocu_Drv_ReturnType: Tells the caller whether the compare match will occur (or has 
 *                             already occurred) during the current reference interval, as a result of 
 *                             setting the new threshold value.
 * @retval     TIM_OCU_DRV_IN_INTERVAL:  compare match was in the given interval
 * @retval     TIM_OCU_DRV_OUT_INTERVAL: compare match was out of the given interval
 */
Tim_Ocu_Drv_ReturnType Tim_Ocu_Drv_SetRelativeThreshold(uint8 InstNum, uint8 ChNum, \
                        Tim_Ocu_Drv_ValueType RelativeValue);

/**
 * @brief      This service is used to enable notifications from an OCU channel.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_EnableNotification(uint8 InstNum, uint8 ChNum);

/**
 * @brief      This service is used to disable notifications from an OCU channel.
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     None
 */
void Tim_Ocu_Drv_DisableNotification(uint8 InstNum, uint8 ChNum);

/**
 * @brief      Service to get max counter value of TIM.
 * 
 *
 * @param[in]  InstNum: Module id of the TIM
 * @param[in]  ChNum: Channel id of the TIM
 *
 * @return     uint16: Ocu channel max counter value
 */
uint16 Tim_Ocu_Drv_GetMaxCounterValue(uint8 InstNum, uint8 ChNum);

/**
 * @brief     The function de-initializes the OCU Driver.
 *
 * @param[in] None
 *
 * @return    None
 */
void Tim_Ocu_Drv_DeInit(void);

/**
 * @brief      TIM channel interrupt handle
 *
 * @param[in]  InstNum:  Select the TIM ID
 *
 * @return none
 *
 */
void Tim_Ocu_Drv_ChIntHandler(Tim_Ocu_Drv_IdType InstNum);

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Ocu_Drv */

/** @} end of group Ocu_Module */

#endif /* TIM_OCU_DRV_H */
