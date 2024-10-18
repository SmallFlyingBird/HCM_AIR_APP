/**************************************************************************************************/
/**
 * @file      : Cmu.h
 * @brief     : AUTOSAR Cmu driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CMU_H
#define CMU_H

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu
 *  @brief Cmu high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Cmu_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CMU_MODULE_ID                   CMU_CFG_H_MODULE_ID
#define CMU_VENDOR_ID                   0x00B3U
#define CMU_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_AR_RELEASE_MINOR_VERSION    6U
#define CMU_AR_RELEASE_REVISION_VERSION 0U
#define CMU_SW_MAJOR_VERSION            1U
#define CMU_SW_MINOR_VERSION            1U
#define CMU_SW_PATCH_VERSION            0U

/**
 * @brief Specifies the InstanceId of this module instance.
 */
#define CMU_INSTANCE_ID ((uint8)0x0U)

/**
 * @brief Service Ids for Cmu APIs
 */
#define CMU_SID_INIT                    ((uint8)0x01U) /* Initialize CMU module */
#define CMU_SID_SET_CLOCK_MONITOR_STATE ((uint8)0x02U) /* Set clock monitor state */
#define CMU_SID_GET_CLOCK_MONITOR_STATE ((uint8)0x03U) /* Get clock monitor state */
#define CMU_SID_GET_VERSION_INFO        ((uint8)0x04U) /* Get module verion information */
#define CMU_SID_GET_CLOCK_MONITOR_MODE  ((uint8)0x05U) /* Get given cmu current mode */
#define CMU_SID_SET_CLOCK_MONITOR_MODE  ((uint8)0x06U) /* Get given cmu mode */
#define CMU_SID_START_MEASURE           ((uint8)0x07U) /* Start measure of given cmu */
#define CMU_SID_GET_MEASURE_STATUS      ((uint8)0x08U) /* Get given cmu measure status */
#define CMU_SID_GET_MEASURE_RESULT      ((uint8)0x09U) /* Get given cmu measure result */


/* Check if current file and Cmu_Types.h file are of the same vendor */
#if (CMU_VENDOR_ID != CMU_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Cmu.h and Cmu_Types.h are different"
#endif

/* Check if current file and Cmu_Types.h file are of the same Autosar version */
#if ((CMU_AR_RELEASE_MAJOR_VERSION != CMU_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (CMU_AR_RELEASE_MINOR_VERSION != CMU_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (CMU_AR_RELEASE_REVISION_VERSION != CMU_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu.h and Cmu_Types.h are different"
#endif

/* Check if current file and Cmu_Types.h file are of the same software version */
#if ((CMU_SW_MAJOR_VERSION != CMU_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (CMU_SW_MINOR_VERSION != CMU_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (CMU_SW_PATCH_VERSION != CMU_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu.h and Cmu_Types.h are different"
#endif

/**
 * @brief Development errors
 */
#define CMU_E_UNINIT               ((uint8)0x01U)
#define CMU_E_NULL_POINTER         ((uint8)0x02U)
#define CMU_E_PARAM_INVALID        ((uint8)0x03U)
#define CMU_E_ALLREADY_INITIALIZED ((uint8)0x04U)
#define CMU_E_INVALID_MODE         ((uint8)0x05U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (CMU_PRECOMPILE_SUPPORT == STD_ON)
    #define CMU_START_SEC_CONFIG_DATA_PTR
    #include "Cmu_MemMap.h"

extern const Cmu_ConfigType *const Cmu_PreDefinedConfigPtr;

    #define CMU_STOP_SEC_CONFIG_DATA_PTR
    #include "Cmu_MemMap.h"
#else
    #define CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Cmu_MemMap.h"

CMU_CONFIG_EXT

    #define CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Cmu_MemMap.h"
#endif /* (CMU_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/* Start of Cmu section CODE */
#define CMU_START_SEC_CODE
#include "Cmu_MemMap.h"

/**
 * @brief     Initializes the Cmu driver.
 *
 * @param[in] ConfigPtr: Pointer to Cmu driver configuration set.
 *
 * @return    None
 *
 */
void Cmu_Init(const Cmu_ConfigType *ConfigPtr);

/**
 * @brief      Sets the given clock monitor state(Enabled/Disabled).
 *
 * @param[in]  CmuId: The given CMU id.
 * @param[in]  Enable: Enable or disable.
 *
 * @return    Std_ReturnType
 * @retval    - E_OK:       The command is executed successfully.
 * @retval    - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_SetClockMonitorState(Cmu_IdType CmuId, boolean Enable);

#if (CMU_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersionInfo: Pointer to where to store the version information of this module.
 *
 * @return    None.
 *
 */
void Cmu_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif /* (CMU_VERSION_INFO_API == STD_ON) */

/**
 * @brief        Gets the given clock monitor current mode.
 *
 * @param[in]    CmuId: The given CMU id.
 * @param[out]   CmuModePtr: Pointer to store clock monitor mode.
 *
 * @return       Std_ReturnType
 * @retval       - E_OK:       The command is executed successfully.
 * @retval       - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetClockMonitorMode(const Cmu_IdType CmuId, Cmu_ModeType *CmuModePtr);

/**
 * @brief      Sets the given clock monitor mode.
 *
 * @param[in]  CmuId: The given CMU ID.
 * @param[in]  CmuMode: The given CMU mode.
 *
 * @return     Std_ReturnType
 * @retval     - E_OK:       The command is executed successfully.
 * @retval     - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_SetClockMonitorMode(const Cmu_IdType CmuId, const Cmu_ModeType CmuMode);

/**
 * @brief      Starts the measure of the given clock monitor.
 *
 * @param[in]  CmuId: The given CMU id.
 *
 * @return     Std_ReturnType
 * @retval     - E_OK:       The command is executed successfully.
 * @retval     - E_NOT_OK:   The command is executed failed.
 *
 */
Std_ReturnType Cmu_StartMeasure(Cmu_IdType CmuId);

/**
 * @brief       Gets the measure status.
 *
 * @param[in]   CmuId: The given CMU id.
 * @param[out]  MeasureStatusPtr: Pointer to store meaure status.
 *
 * @return      Std_ReturnType
 * @retval      - E_OK:     The command is executed successfully.
 * @retval      - E_NOT_OK: The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetMeasureStatus(Cmu_IdType CmuId, boolean *MeasureStatusPtr);

/**
 * @brief      Gets measure result when CMU is working in measure mode.
 * @note       User needs to make sure the measure is completed before calling this function,
 * otherwise the return value is incorrect.
 *
 * @param[in]   CmuId: The given CMU id.
 * @param[out]  MeaureResultPtr: Pointer to store the measure result.
 *
 * @return    Std_ReturnType
 * @retval    - E_OK:     The command is executed successfully.
 * @retval    - E_NOT_OK: The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetMeasureResult(Cmu_IdType CmuId, uint32 *MeaureResultPtr);

/**
 * @brief        Gets the given clock monitor state.
 *
 * @param[in]    CmuId: The given CMU id.
 * @param[out] CmuStatePtr: Pointer to store the state.
 *
 * @return       Std_ReturnType
 * @retval       - E_OK:     The command is executed successfully.
 * @retval       - E_NOT_OK: The command is executed failed.
 *
 */
Std_ReturnType Cmu_GetClockMonitorState(Cmu_IdType CmuId, Cmu_StateType *CmuStatePtr);

/* Stop of Cmu section CODE*/
#define CMU_STOP_SEC_CODE
#include "Cmu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Cmu */

/** @} end of group Cmu_Module */

#endif /* CMU_H */
