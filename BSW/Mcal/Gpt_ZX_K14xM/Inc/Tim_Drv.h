/**************************************************************************************************/
/**
 * @file      : Tim_Drv.h
 * @brief     : Tim module header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef TIM_DRV_H
#define TIM_DRV_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Tim_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tim_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_DRV_H_VENDOR_ID                   0x00B3U
#define TIM_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_DRV_H_SW_MAJOR_VERSION            1U
#define TIM_DRV_H_SW_MINOR_VERSION            2U
#define TIM_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Tim_Drv_Types header file are of the same vendor */
#if (TIM_DRV_H_VENDOR_ID != TIM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Tim_Drv.h and Tim_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Drv_Types header file are of the same Autosar version */
#if ((TIM_DRV_H_AR_RELEASE_MAJOR_VERSION != TIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (TIM_DRV_H_AR_RELEASE_MINOR_VERSION != TIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (TIM_DRV_H_AR_RELEASE_REVISION_VERSION != TIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Drv.h and Tim_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Drv_Types header file are of the same Software version */
#if ((TIM_DRV_H_SW_MAJOR_VERSION != TIM_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (TIM_DRV_H_SW_MINOR_VERSION != TIM_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (TIM_DRV_H_SW_PATCH_VERSION != TIM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Drv.h and Tim_Drv_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

#if (TIM_DRV_ENABLE == STD_ON)
/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
TIM_DRV_CONFIG_EXT

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/**
 * @brief  Timer target value.
 */
extern uint32 Tim_Drv_TargetValue[TIM_DRV_INSTANCE_COUNT][TIM_DRV_CHANNEL_COUNT];

#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/**
 * @brief       This function gets timer current value
 *
 * @param[in]   Instance: Timer hardware instance number
 *
 * @return      CurrentCntValue
 */
uint16 Tim_Drv_GetCounterValue(uint8 Instance);

/**
 * @brief      This function gets timer compare value
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 *
 * @return     uint16
 * @retval     Timer compare value
 */
uint16 Tim_Drv_GetCompareValue(uint8 Instance, uint8 Channel);

/**
 * @brief      This function gets timer channel interrupt flag
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 *
 * @return     uint32
 * @retval     Timer interrupt flag
 */
uint32 Tim_Drv_GetInterruptFlag(uint8 Instance, uint8 Channel);

/**
 * @brief      This function initializes the Timer instance.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  ConfigInstancePtr: Pointer to the specified TIMER instance configuration
 * 
 * @return     None 
 */
void Tim_Drv_InitInstance(uint8 Instance, const Tim_Drv_InstanceConfigType *ConfigInstancePtr);

/**
 * @brief      This function initializes the Timer channel.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  ConfigChannelPtr: Pointer to the specified TIMER channel configuration
 * 
 * @return     None 
 */
void Tim_Drv_InitChannel(uint8 Instance, const Tim_Drv_ChannelConfigType *ConfigChannelPtr);

/**
 * @brief      This function de-initialize the TIMER.
 *
 * @param[in]  Instance: Timer hardware instance numberr
 * 
 * @return     None
 */
void Tim_Drv_Deinit(uint8 Instance);

/**
 * @brief      Start the timer counter.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * @param[in]  CompareValue: Channel timeout value.
 * 
 * @return     None
 */
void Tim_Drv_StartTimer(uint8 Instance, uint8 Channel, uint16 CompareValue,
                        Tim_Drv_ClockSourceType ClockSource);

/**
 * @brief      Stop the timer counter.
 *
 * @param[in]  Instance: Timer hardware instance number
 * 
 * @return     None
 */
void Tim_Drv_StopTimer(uint8 Instance, uint8 Channel);

/**
 * @brief      Enable interrupt for timer channel.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * 
 * @return     None
 */
void Tim_Drv_EnableChannelInterrupt(uint8 Instance, uint8 Channel);

/**
 * @brief      Disable interrupt for timer channel.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * 
 * @return     None
 */
void Tim_Drv_DisableChannelInterrupt(uint8 Instance, uint8 Channel);

#if (STD_ON == TIM_DRV_SET_DUAL_CLOCK_MODE)
/**
 * @brief       Change the Timer prescaler value.
 *
 * @param[in]   Instance: Timer peripheral instance number
 * @param[in]   ClockMode: Timer prescaler type.
 *                        - TIM_DRV_CLOCKMODE_NORMAL
 *                        - TIM_DRV_CLOCKMODE_ALTERNATE
 * 
 * @return      None
 */
void Tim_Drv_SetDualClockMode(uint8 Instance, Tim_Drv_DualClockModeType ClockMode);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* TIM_DRV_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Drv */

/** @} end of group Tim_Module */

#endif /* TIM_DRV_H */
