/**************************************************************************************************/
/**
 * @file      : McalLib_OsCounter.h
 * @brief     : McalLib OS counter header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MCALLIB_OSCOUNTER_H
#define MCALLIB_OSCOUNTER_H

/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup McalLib_OsCounter
 *  @brief McalLib OS counter. The OS can be selected from AUTOSAR OS, bareMetal and FreeRTOS.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCALLIB_OSCOUNTER_H_VENDOR_ID                   0x00B3U
#define MCALLIB_OSCOUNTER_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_OSCOUNTER_H_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_OSCOUNTER_H_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_OSCOUNTER_H_SW_MAJOR_VERSION            1U
#define MCALLIB_OSCOUNTER_H_SW_MINOR_VERSION            2U
#define MCALLIB_OSCOUNTER_H_SW_PATCH_VERSION            1U

/* Check if current file and McalLib_Cfg.h are the same vendor */
#if (MCALLIB_OSCOUNTER_H_VENDOR_ID != MCALLIB_CFG_H_VENDOR_ID)
    #error "Vendor ID of McalLib_OsCounter.h and McalLib_Cfg.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same Autosar version */
#if ((MCALLIB_OSCOUNTER_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_CFG_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (MCALLIB_OSCOUNTER_H_AR_RELEASE_MINOR_VERSION != MCALLIB_CFG_H_AR_RELEASE_MINOR_VERSION) ||   \
     (MCALLIB_OSCOUNTER_H_AR_RELEASE_REVISION_VERSION !=                                           \
      MCALLIB_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib_OsCounter.h and McalLib_Cfg.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same Software version */
#if ((MCALLIB_OSCOUNTER_H_SW_MAJOR_VERSION != MCALLIB_CFG_H_SW_MAJOR_VERSION) ||                   \
     (MCALLIB_OSCOUNTER_H_SW_MINOR_VERSION != MCALLIB_CFG_H_SW_MINOR_VERSION) ||                   \
     (MCALLIB_OSCOUNTER_H_SW_PATCH_VERSION != MCALLIB_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib_OsCounter.h and McalLib_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((MCALLIB_OSCOUNTER_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||         \
         (MCALLIB_OSCOUNTER_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib_OsCounter.h and Std_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define MCAL_SYSTICK_RELOAD_VALUE (0xFFFFFFU)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MCALLIB_START_SEC_CODE
#include "McalLib_MemMap.h"
#if (MCALLIB_OS_COUNTER_ENABLE == STD_ON)
/**
 * @brief     Initialize McalLib OS counter , this function shall be called during startup
 *
 * @return    None
 *
 */
void McalLib_OsCounter_Init(void);

/**
 * @brief     Get the current value of the OS counter
 *
 * @param[out] Value: point to variable where the counter value will be stored by this API
 *
 * @return    Std_ReturnType
 * @retval    E_OK: succeed in getting counter value.
 * @retval    E_NOT_OK: fail to get counter value.
 *
 */
Std_ReturnType McalLib_OsCounter_GetCounterValue(uint32 *Value);

/**
 * @brief     Get the number of ticks between the current tick value and a previously read tick
 *            value.
 *
 * @param[inout] CounterValue: in - the previously read tick value of the counter
 *                             out - the current tick value of the counter
 * @param[out] ElapsedValue: The elapsed value
 *
 * @return    Std_ReturnType
 * @retval    E_OK: succeed in getting elapsed value.
 * @retval    E_NOT_OK: fail to get elapsed value.
 *
 */
Std_ReturnType McalLib_OsCounter_GetElapsedValue(uint32 *const CounterValue, uint32 *ElapsedValue);

/**
 * @brief     Convert microseconds to ticks
 *
 * @param[in] MicroSecond: microseconds value
 *
 * @return    the tick value
 *
 */
uint32 McalLib_OsCounter_MicroSecToTicks(uint32 MicroSecond);

/**
 * @brief     Set the counter frequency
 *
 * @param[in] Freq: the counter frequency
 *
 * @return    None
 *
 */
void McalLib_OsCounter_SetCounterFreq(uint32 Freq);

#endif /* (MCALLIB_OS_COUNTER_ENABLE == STD_ON) */

#define MCALLIB_STOP_SEC_CODE
#include "McalLib_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group McalLib_OsCounter */

/** @} end of group McalLib_Module */

#endif /* MCALLIB_OSCOUNTER_H */
