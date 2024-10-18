/**************************************************************************************************/
/**
 * @file      : Stim_Drv.h
 * @brief     : Stim module header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef STIM_DRV_H
#define STIM_DRV_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Stim_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Stim_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define STIM_DRV_H_VENDOR_ID                   0x00B3U
#define STIM_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define STIM_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define STIM_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define STIM_DRV_H_SW_MAJOR_VERSION            1U
#define STIM_DRV_H_SW_MINOR_VERSION            2U
#define STIM_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Stim_Drv_Types header file are of the same vendor */
#if (STIM_DRV_H_VENDOR_ID != STIM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Stim_Drv.h and Stim_Drv_Types.h are different"
#endif
/* Check if current file and Stim_Drv_Types header file are of the same Autosar version */
#if ((STIM_DRV_H_AR_RELEASE_MAJOR_VERSION != STIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (STIM_DRV_H_AR_RELEASE_MINOR_VERSION != STIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (STIM_DRV_H_AR_RELEASE_REVISION_VERSION != STIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Stim_Drv.h and Stim_Drv_Types.h are different"
#endif
/* Check if current file and Stim_Drv_Types header file are of the same Software version */
#if ((STIM_DRV_H_SW_MAJOR_VERSION != STIM_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (STIM_DRV_H_SW_MINOR_VERSION != STIM_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (STIM_DRV_H_SW_PATCH_VERSION != STIM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Stim_Drv.h and Stim_Drv_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

#if (STIM_DRV_ENABLE == STD_ON)
/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
STIM_DRV_CONFIG_EXT

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/**
 * @brief       Get current compare value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      uint32
 * @retval      Stim compare value.
 */
uint32 Stim_Drv_GetCompareValue(uint8 Instance, uint8 Channel);

/**
 * @brief       Get current counter value of stim.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      CurrentCntValue
 */
uint32 Stim_Drv_GetCurrentCounterValue(uint8 Instance, uint8 Channel);

/**
 * @brief       This function checks if the status flag is set when the counter matches the
 *              compare value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      boolean
 * @retval      TRUE: Stim flag is set.
 * @retval      FALSE: Stim flag is not set.
 */
boolean Stim_Drv_GetStatus(uint8 Instance, uint8 Channel);

/**
 * @brief       This function initialize the STIM
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   ConfigChannelPtr: Pointer to the specified STIM channel configuration
 *
 * @return      None
 */
void Stim_Drv_InitChannel(uint8 Instance, const Stim_Drv_ChannelConfigType *ConfigChannelPtr);

/**
 * @brief       This function de-initialize the STIM
 *
 * @param[in]   Instance: STIM peripheral instance number
 *
 * @return      None
 */
void Stim_Drv_DeInit(uint8 Instance);

/**
 * @brief       Start the stim counter.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   Value: Channel timeout value.
 *
 * @return      None
 */
void Stim_Drv_StartTimer(uint8 Instance, uint8 Channel, uint32 Value);

/**
 * @brief       Stop the stim counter.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_StopTimer(uint8 Instance, uint8 Channel);

/**
 * @brief       Enable interrupt for stim channel.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_EnableInterrupt(uint8 Instance, uint8 Channel);

/**
 * @brief       Disable interrupt for stim channel.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_DisableInterrupt(uint8 Instance, uint8 Channel);

#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief       Change the Stim prescaler value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   ClockMode: Stim prescaler type.
 *                        - STIM_DRV_CLOCKMODE_NORMAL
 *                        - STIM_DRV_CLOCKMODE_ALTERNATE
 *
 * @return      None
 */
void Stim_Drv_SetDualClockMode(uint8 Instance, uint8 Channel, Stim_Drv_DualClockModeType ClockMode);
#endif

#if (STIM_DRV_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Start the predefTimer.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   CompareValue: Stim compare value.
 * @param[in]   Prescaler: Select stim prescaler value.
 * @param[in]   ClockSource: Select stim clock source.
 *
 * @return      None
 */
void Stim_Drv_StartPredefTimer(uint8 Instance, uint8 Channel, uint32 CompareValue, uint8 Prescaler,
                               uint8 ClockSource);
#endif

/**
 * @brief       Stop the predefTimer.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_StopPredefTimer(uint8 Instance, uint8 Channel);

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* STIM_DRV_ENABLE == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} end of group Stim_Drv */

/** @} end of group Stim_Module */

#endif /* STIM_DRV_H */
