/**************************************************************************************************/
/**
 * @file      : Gpt_Drvw.h
 * @brief     : AUTOSAR Gpt drvw driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPT_DRVW_H
#define GPT_DRVW_H

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drvw
 *  @brief Gpt driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_DRVW_H_VENDOR_ID                   0x00B3U
#define GPT_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define GPT_DRVW_H_SW_MAJOR_VERSION            1U
#define GPT_DRVW_H_SW_MINOR_VERSION            2U
#define GPT_DRVW_H_SW_PATCH_VERSION            1U

/* Check if current file and Gpt_Drvw_Types header file are of the same vendor */
#if (GPT_DRVW_H_VENDOR_ID != GPT_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw.h and Gpt_Drvw_Types.h are different"
#endif
/* Check if current file and Gpt_Drvw_Types header file are of the same Autosar version */
#if ((GPT_DRVW_H_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (GPT_DRVW_H_AR_RELEASE_MINOR_VERSION != GPT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (GPT_DRVW_H_AR_RELEASE_REVISION_VERSION != GPT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw.h and Gpt_Drvw_Types.h are different"
#endif
/* Check if current file and Gpt_Drvw_Types header file are of the same Software version */
#if ((GPT_DRVW_H_SW_MAJOR_VERSION != GPT_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (GPT_DRVW_H_SW_MINOR_VERSION != GPT_DRVW_TYPES_H_SW_MINOR_VERSION) ||                         \
     (GPT_DRVW_H_SW_PATCH_VERSION != GPT_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw.h and Gpt_Drvw_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/**
 * @brief   Export Post-Build configurations.
 */
GPT_DRVW_CONFIG_EXT

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief        This function initializes the Gpt driver instance.
 * 
 * @param[in]    HwInstanceConfigPtr  A pointer to the instance configuration structure.
 *
 * @return       void
 */
void Gpt_Drvw_InitInstances(const Gpt_Drvw_HwInstanceConfigType *HwInstanceConfigPtr);

/**
 * @brief      This function initializes the Gpt driver.
 *
 * @param[in]  HwChannelConfigPtr  A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_Init(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr);

#if (GPT_DRVW_DEINIT_API == STD_ON)
/**
 * @brief      This function de-initializes the Gpt driver.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_DeInit(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr);
#endif

/**
 * @brief      This function starts the timer.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  Value   A notification is generated when the value is reached(if enabled).
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 */
Std_ReturnType Gpt_Drvw_StartTimer(const Gpt_Drvw_HwChannelConfigType  *HwChannelConfigPtr,
                                   uint32                               Value);
/**
 * @brief      This function stops the timer.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_StopTimer(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr);

/**
 * @brief      This function enable hardware timer interrupts.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_EnableInterrupt(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr);

#if ((GPT_DRVW_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||                                       \
     (GPT_DRVW_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
 * @brief      This function disable hardware timer interrupts.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_DisableInterrupt(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr);
#endif

/**
 * @brief      This function returns the time already elapsed.
 *
 * @param[in]  HwChannelConfigPtr  A pointer to the channel configuration structure.
 * @param[out] ReturnHwChannelInfoPtr  The rollover status of the hardware timer channel.
 *
 * @return     uint32
 * @retval     The elapsed time
 */
uint32 Gpt_Drvw_GetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                               Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr);

#if (GPT_DRVW_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief      This function start predeftimer.
 *
 * @param[in]  HwPredefChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  PrdefTimerType  The type of predef timer.
 *
 * @return     None
 */
void Gpt_Drvw_StartPredefTimer(const Gpt_Drvw_HwPredefChannelConfigType *HwPredefChannelConfigPtr,
                               Gpt_Drvw_PredefTimerType                  PrdefTimerType);

/**
 * @brief      This function gets value of predeftimer.
 *
 * @param[in]  HwPredefChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  TimeValuePtr    A pointer that saves the current value of the channel.
 *
 * @return     None
 */
void Gpt_Drvw_GetPredefTimerValue
(
    const Gpt_Drvw_HwPredefChannelConfigType *HwPredefChannelConfigPtr,
    Gpt_Drvw_PredefTimerType PredefTimer, uint32 *TimeValuePtr
);
/**
 * @brief      This function stops predeftimer.
 *
 * @param[in]  HwPredefChannelConfigPtr  A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_StopPredefTimer(const Gpt_Drvw_HwPredefChannelConfigType *HwPredefChannelConfigPtr);
#endif

#if (GPT_DRVW_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief      This function sets instance dual clock mode.
 *
 * @param[in]  InstanceConfigPtr A pointer to the channel configuration structure.
 * @param[in]  ClockMode  Prescaler type.
 *
 * @return     None
 */
void Gpt_Drvw_SetInstanceDualClockMode(const Gpt_Drvw_HwInstanceConfigType *InstanceConfigPtr,
                                       Gpt_Drvw_DualClockModeType           ClockMode);

/**
 * @brief      This function sets channel dual clock mode.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  ClockMode  Prescaler type.
 *
 * @return     None
 */
void Gpt_Drvw_SetChannelDualClockMode(const Gpt_Drvw_HwChannelConfigType  *HwChannelConfigPtr,
                               Gpt_Drvw_DualClockModeType           ClockMode);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt_Drvw */

/** @} end of group Gpt_Module */

#endif /*GPT_DRVW_H*/
