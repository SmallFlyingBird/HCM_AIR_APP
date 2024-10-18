/**************************************************************************************************/
/**
 * @file      : Cmu_Drv.h
 * @brief     : AUTOSAR Cmu driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CMU_DRV_H
#define CMU_DRV_H

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu_Drv
 *  @brief Cmu low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Cmu_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CMU_DRV_H_VENDOR_ID                   0x00B3U
#define CMU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define CMU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define CMU_DRV_H_SW_MAJOR_VERSION            1U
#define CMU_DRV_H_SW_MINOR_VERSION            1U
#define CMU_DRV_H_SW_PATCH_VERSION            0U

/* Check if current file and Cmu_Drv_Types.h file are of the same vendor */
#if (CMU_DRV_H_VENDOR_ID != CMU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Cmu_Drv.h and Cmu_Drv_Types.h are different"
#endif

/* Check if current file and Cmu_Drv_Types.h file are of the same Autosar version */
#if ((CMU_DRV_H_AR_RELEASE_MAJOR_VERSION != CMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (CMU_DRV_H_AR_RELEASE_MINOR_VERSION != CMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (CMU_DRV_H_AR_RELEASE_REVISION_VERSION != CMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu_Drv.h and Cmu_Drv_Types.h are different"
#endif

/* Check if current file and Cmu_Drv_Types.h file are of the same Software version */
#if ((CMU_DRV_H_SW_MAJOR_VERSION != CMU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (CMU_DRV_H_SW_MINOR_VERSION != CMU_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (CMU_DRV_H_SW_PATCH_VERSION != CMU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu_Drv.h and Cmu_Drv_Types.h are different"
#endif

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

#define CMU_START_SEC_CODE
#include "Cmu_MemMap.h"

/**
 * @brief       Initializes the given clock monitor.
 *
 * @param[in]   CmuConfigPtr: Pointer to the clock monitor configuration.
 *
 * @return      None
 *
 */
void Cmu_Drv_Init(const Cmu_Drv_ConfigType *CmuConfigPtr);

/**
 * @brief       Gets current mode of the given clock monitor.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return      Cmu_Drv_ModeType
 * @retval      - CMU_DRV_MONITOR_MODE: Monitor mode.
 * @retval      - CMU_DRV_MEASURE_MODE: Measure mode.
 *
 */
Cmu_Drv_ModeType Cmu_Drv_GetMode(const Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief       Sets specify clock monitor to the given mode.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 * @param[in]   CmuMode: The given mode.
 *
 * @return      None
 *
 */
void Cmu_Drv_SetMode(const Cmu_Drv_IdType CmuMonitorId, const Cmu_Drv_ModeType CmuMode);

/**
 * @brief       Starts the measure mode.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return      None
 *
 */
void Cmu_Drv_StartMeasure(Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief       Gets the measure complete status.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return     boolean.
 * @retval     - TRUE:measure state is completed.
 * @retval     - FALSE:measure state is not completed.
 */
boolean Cmu_Drv_GetMeasureCompleteStatus(Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief      Gets measure result when CMU is working in measure mode.
 * @note       User  needs to make sure the measure is completed before calling this
 *             function, otherwise, the return value is incorrect.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return    uint32: Measurement result.
 *
 *
 */
uint32 Cmu_Drv_GetMeasureResult(Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief      Enables the given CMU.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return     None
 *
 */
void Cmu_Drv_Enable(Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief      Disables the given CMU.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return     None
 *
 */
void Cmu_Drv_Disable(Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief      CMU interrupt Handler
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return     None
 *
 */
void Cmu_Drv_IrqHandler(Cmu_Drv_IdType CmuMonitorId);

/**
 * @brief      Gets the given CMU current state.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return     Cmu_Drv_StateType.
 * @retval     - CMU_DRV_STATE_CFG_UPDATABLE:CMU configuration can be updated.
 * @retval     - CMU_DRV_STATE_CFG_LOCKED:CMU configuration is locked.
 * @retval     - CMU_DRV_STATE_MONITOR_RUNNING:CMU is running.
 */

Cmu_Drv_StateType Cmu_Drv_GetState(Cmu_Drv_IdType CmuMonitorId);

#define CMU_STOP_SEC_CODE
#include "Cmu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Cmu_Drv */

/** @} end of group Cmu_Module */

#endif /* CMU_DRV_H */
