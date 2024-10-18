/**************************************************************************************************/
/**
 * @file      : Adc.h
 * @brief     : Adc AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_H
#define ADC_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc
 *  @brief Adc AUTOSAR level
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Adc_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define ADC_VENDOR_ID                   0x00B3U
#define ADC_MODULE_ID                   123U
#define ADC_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_AR_RELEASE_MINOR_VERSION    6U
#define ADC_AR_RELEASE_REVISION_VERSION 0U
#define ADC_SW_MAJOR_VERSION            1U
#define ADC_SW_MINOR_VERSION            2U
#define ADC_SW_PATCH_VERSION            1U

/* Check if current file and Adc_Types.h are the same vendor */
#if (ADC_VENDOR_ID != ADC_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Adc.h and Adc_Types.h are different"
#endif

/* Check if current file and Adc_Types.h are the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc.h and Adc_Types.h are different"
#endif

/* Check if current file and Adc_Types.h are the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (ADC_SW_MINOR_VERSION != ADC_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (ADC_SW_PATCH_VERSION != ADC_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Adc.h and Adc_Types.h are different"
#endif

/**
 * @brief   API service used without Adc module initialization.
 */
#define ADC_E_UNINIT ((uint8)0x0AU)

/**
 * @brief   Adc module is busy with a running operation.
 */
#define ADC_E_BUSY ((uint8)0x0BU)

/**
 * @brief   Adc module is in idle state.
 */
#define ADC_E_IDLE ((uint8)0x0CU)

/**
 * @brief   The ADC module is already initialized.
 */
#define ADC_E_ALREADY_INITIALIZED ((uint8)0x0DU)

/**
 * @brief   The ADC module is not properly configured.
 */
#define ADC_E_PARAM_CONFIG ((uint8)0x0EU)

/**
 * @brief   API service is called using an invalid pointer (e.g. the pointer should not be NULL).
 */
#define ADC_E_PARAM_POINTER ((uint8)0x14U)

/**
 * @brief   API service used with an invalid ADC group.
 */
#define ADC_E_PARAM_GROUP ((uint8)0x15U)

/**
 * @brief   API service used with an invalid ADC Conversion Mode.
 */
#define ADC_E_WRONG_CONV_MODE ((uint8)0x16U)

/**
 * @brief   API service used with an invalid ADC Trigger Source.
 */
#define ADC_E_WRONG_TRIGG_SRC ((uint8)0x17U)

/**
 * @brief   Check the notification capability of a group.
 */
#define ADC_E_NOTIF_CAPABILITY ((uint8)0x18U)

/**
 * @brief   API service used without initializing the buffer.
 */
#define ADC_E_BUFFER_UNINIT ((uint8)0x19U)

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
    /**
     * @brief   One or more ADC group/channel not in IDLE state.
     */
    #define ADC_E_NOT_DISENGAGED ((uint8)0x1AU)

    /**
     * @brief   Unsupported power state request.
     */
    #define ADC_E_POWER_STATE_NOT_SUPPORTED ((uint8)0x1BU)

    /**
     * @brief   Requested power state can not be reached directly.
     */
    #define ADC_E_TRANSITION_NOT_POSSIBLE ((uint8)0x1CU)

    /**
     * @brief   ADC not prepared for target power state.
     */
    #define ADC_E_PERIPHERAL_NOT_PREPARED ((uint8)0x1DU)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/**
* @brief    The Adc_StartGroupConversion and Adc_EnableHardwareTrigger services can not queue
            another conversion (queue is full)
*/
#define ADC_E_QUEUE_FULL ((uint8)0x20U)

/**
 * @brief   API service called using a wrong ADC unit.
 */
#define ADC_E_PARAM_UNIT ((uint8)0x26U)

/**
 * @brief   An error occurred if the timeout counter variable has expired when checking status
 * flags.
 */
#define ADC_E_TIMEOUT ((uint8)0x2BU)

/**
 * @brief API service ID for Adc_Init function
 */
#define ADC_SID_INIT ((uint8)0x00U)

/**
 * @brief API service ID for Adc_DeInit function
 */
#define ADC_SID_DEINIT ((uint8)0x01U)

/**
 * @brief API service ID for Adc_StartGroupConversion function
 */
#define ADC_SID_START_GROUP_CONVERSION ((uint8)0x02U)

/**
 * @brief API service ID for Adc_StopGroupConversion function
 */
#define ADC_SID_STOP_GROUP_CONVERSION ((uint8)0x03U)

/**
 * @brief API service ID for Adc_ReadGroup function
 */
#define ADC_SID_READ_GROUP ((uint8)0x04U)

/**
 * @brief API service ID for Adc_EnableHardwareTrigger function
 */
#define ADC_SID_ENABLE_HARDWARE_TRIGGER ((uint8)0x05U)

/**
 * @brief API service ID for Adc_DisableHardwareTrigger function
 */
#define ADC_SID_DISABLE_HARDWARE_TRIGGER ((uint8)0x06U)

/**
 * @brief API service ID for Adc_EnableGroupNotification function
 */
#define ADC_SID_ENABLE_GROUP_NOTIFICATION ((uint8)0x07U)

/**
 * @brief API service ID for Adc_DisableGroupNotification function
 */
#define ADC_SID_DISABLE_GROUP_NOTIFICATION ((uint8)0x08U)

/**
 * @brief API service ID for Adc_GetGroupStatus function
 */
#define ADC_SID_GET_GROUP_STATUS ((uint8)0x09U)

/**
 * @brief API service ID for Adc_GetVersionInfo function
 */
#define ADC_SID_GET_VERSION_INFO ((uint8)0x0AU)

/**
 * @brief API service ID for Adc_GetStreamLastPointer function
 */
#define ADC_SID_GET_STREAM_LAST_POINTER ((uint8)0x0BU)

/**
 * @brief API service ID for Adc_SetupResultBuffer function
 */
#define ADC_SID_SETUP_RESULT_BUFFER ((uint8)0x0CU)

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
    /**
     * @brief API service ID for Adc_SetPowerState function
     */
    #define ADC_SID_SET_POWER_STATE ((uint8)0x10U)

    /**
     * @brief API service ID for Adc_GetCurrentPowerState function
     */
    #define ADC_SID_GET_CURRENT_POWER_STATE ((uint8)0x11U)

    /**
     * @brief API service ID for Adc_GetTargetPowerState function
     */
    #define ADC_SID_GET_TARGET_POWER_STATE ((uint8)0x12U)

    /**
     * @brief API service ID for Adc_PreparePowerState function
     */
    #define ADC_SID_PREPARE_POWER_STATE ((uint8)0x13U)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
    /**
     * @brief API service ID for Adc_Calibrate function
     */
    #define ADC_SID_CALIBRATE ((uint8)0x60U)
#endif

    /**
     * @brief API service ID for Adc_SelfTest function
     */
    #define ADC_SID_SELF_TEST ((uint8)0x61U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
extern Adc_GroupStatusType Adc_GroupStatus[ADC_MAX_GROUPS];
extern Adc_UnitStatusType  Adc_UnitStatus[ADC_MAX_HWUNITS];

#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    #define ADC_START_SEC_CONFIG_DATA_PTR
    #include "Adc_MemMap.h"
extern const Adc_ConfigType *const Adc_PreDefinedConfigPtr[ADC_MAX_PARTITIONS];
    #define ADC_STOP_SEC_CONFIG_DATA_PTR
    #include "Adc_MemMap.h"
#else
    #define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Adc_MemMap.h"

ADC_CONFIG_EXT

    #define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Adc_MemMap.h"
#endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief   Declaration of ADC notification functions.
 */
ADC_FUNC_DECL_EXT

/**
 * @brief     Initializes the ADC hardware units and driver..
 * @details   This function initializes the ADC hardware units and driver.
 *            - Service ID: 0x00
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] ConfigPtr   Pointer to configuration set in Variant PB (Variant PC requires a
 * NULL_PTR).
 * @return    None
 */
void Adc_Init(const Adc_ConfigType *ConfigPtr);

/**
 * @brief     Initializes the group specific ADC result buffer pointer
 * @details   Initializes ADC driver with the group specific result buffer
 *            start address where the conversion results will be stored.
 *            The application has to ensure that the application buffer,
 *            where pDataBufferPtr points to, can hold all the conversion
 *            results of the specified group. The initialization with
 *            Adc_SetupResultBuffer is required after reset, before a group
 *            conversion can be started.
 *            - Service ID: 0x0C
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 * @param[in] DataBufferPtr: Pointer to result data buffer
 *
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK:           Result buffer pointer initialized correctly.
 *            E_NOT_OK:       Operation failed or development error occurred.
 */
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType *const DataBufferPtr);

#if (ADC_DEINIT_API == STD_ON)
/**
 * @brief     Returns all ADC HW Units to a state comparable to their power on reset state.
 *            - Service ID: 0x01
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @return    None
 */
void Adc_DeInit(void);
#endif /* ADC_DEINIT_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief     Starts the conversion of all channels of the requested ADC Channel group.
 *            - Service ID: 0x02
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
void Adc_StartGroupConversion(Adc_GroupType Group);

/**
 * @brief     Stops the conversion of requested ADC Channel group.
 *            - Service ID: 0x03
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
void Adc_StopGroupConversion(Adc_GroupType Group);
#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief     Reads the group conversion results.
 * @details   Reads the group conversion results of the last completed
 *            conversion round of the requested group and stores the
 *            channel values starting at the DataBufferPtr address.
 *            The group channel values are stored in ascending channel
 *            number order (in contrast to the storage layout of the
 *            result buffer if streaming access is configured).
 *            - Service ID: 0x04
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 * @param[in] DataBufferPtr:  ADC results of all channels of the selected group
 *                             are stored in the data buffer addressed with the pointer.
 * @return    Std_ReturnType: Standard return type.
 * @retval    E_OK: results are available and written to the data buffer.
 *            E_NOT_OK: no results are available or development error occurred.
 */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr);
#endif /* ADC_READ_GROUP_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief     Enables the hardware trigger for the requested ADC Channel group.
 *            - Service ID: 0x05
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
void Adc_EnableHardwareTrigger(Adc_GroupType Group);

/**
 * @brief     Disables the hardware trigger for the requested ADC Channel group.
 *            - Service ID: 0x06
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
void Adc_DisableHardwareTrigger(Adc_GroupType Group);
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
/**
 * @brief     Enables the notification mechanism for the requested ADC Channel group.
 *            - Service ID: 0x07
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
void Adc_EnableGroupNotification(Adc_GroupType Group);

/**
 * @brief     Disables the notification mechanism for the requested ADC Channel group.
 *            - Service ID: 0x08
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    None
 */
void Adc_DisableGroupNotification(Adc_GroupType Group);
#endif /* ADC_GROUP_NOTIF_CAPABILITY == STD_ON */

/**
 * @brief     Returns the conversion status of the requested ADC Channel group.
 *            - Service ID: 0x09
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 *
 * @return    Adc_StatusType: Conversion status for the requested group.
 */
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);

/**
 * @brief      Returns the number of valid samples per channel.
 * @details    Returns the number of valid samples per channel, stored in the result buffer.
 *             Reads a pointer, pointing to a position in the group result buffer.
 *             With the pointer position, the results of all group channels of
 *             the last completed conversion round can be accessed. With the pointer and
 *             the return value, all valid group conversion results can be accessed
 *             (the user has to take the layout of the result buffer into account).
 *             - Service ID: 0x0B
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in] Group: Numeric ID of requested ADC channel group.
 * @param[out] PtrToSamplePtr: Pointer to result buffer pointer.
 *
 * @return     Adc_StreamNumSampleType Number of valid samples per channel.
 * @retval     =0: in case of errors.
 * @retval     >0: Number of valid samples per channel.
 */
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType        Group,
                                                 Adc_ValueGroupType **PtrToSamplePtr);

#if (ADC_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *            - Service ID: 0x0A
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] versionInfo: Pointer to where to store the version information of this module.
 *
 * @return    None
 */
void Adc_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* ADC_VERSION_INFO_API == STD_ON */

#if (ADC_CALIBRATION == STD_ON)
/**
 * @brief     This function calibrates the ADC HW unit and updates calibration related registers.
 *            - Service ID: 0x60
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Unit: Hardware Unit.
 *
 * @return     Std_ReturnType: Calibration result.
 * @retval     E_OK: Successfully.
 * @retval     E_NOT_OK: Failed.
 */
Std_ReturnType Adc_Calibrate(Adc_HwUnitType Unit);
#endif /* (ADC_CALIBRATION == STD_ON) */

/**
 * @brief     This function performs self test of ADC.
 *            - Service ID: 0x61
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Unit: Hardware Unit.
 *
 * @return     Std_ReturnType: Self test result.
 * @retval     E_OK:           Successfully.
 * @retval     E_NOT_OK:       Failed.
 */
Std_ReturnType Adc_SelfTest(Adc_HwUnitType Unit);

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
 * @brief      Enters the already prepared power state.
 *
 * @details    This API configures the Adc module so that it enters the already prepared power
 *             state, chosen between a predefined set of configured ones.
 *             - Service ID: 0x10
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Result: Pointer to a variable to store the result of this function.
 *
 * @return     Std_ReturnType: Standard return type.
 * @retval     E_OK:           Power Mode changed.
 * @retval     E_NOT_OK:       Request rejected.
 */
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result);

/**
 * @brief      Get the current power state of the ADC HW unit.
 *
 * @details    This API returns the current power state of the ADC HW unit.
 *             - Service ID: 0x11
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[out] CurrentPowerState: The current power mode of the ADC HW Unit is returned in this
 *             parameter
 * @param[out] Result: Pointer to a variable to store the result of this function
 *
 * @return     Std_ReturnType  Standard return type.
 * @retval     E_OK:           Mode could be read.
 * @retval     E_NOT_OK:       Service is rejected.
 */
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType              *CurrentPowerState,
                                        Adc_PowerStateRequestResultType *Result);

/**
 * @brief      Get the target power state of the ADC HW unit.
 *
 * @details    This API returns the target power state of the ADC HW unit.
 *             - Service ID: 0x12
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[out] TargetPowerState: The Target power mode of the ADC HW Unit is returned in this
 *             parameter.
 * @param[out] Result: Pointer to a variable to store the result of this function.
 *
 * @return     Std_ReturnType  Standard return type.
 * @retval     E_OK:           Mode could be read.
 * @retval     E_NOT_OK:       Service is rejected.
 */
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType              *TargetPowerState,
                                       Adc_PowerStateRequestResultType *Result);

/**
 * @brief      Starts the needed process to allow the ADC HW module to enter the requested power
 *             state.
 *
 * @details    This API starts the needed process to allow the ADC HW module to enter the requested
 *             power state.
 *             - Service ID: 0x13
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  PowerState      The target power state intended to be attained.
 * @param[out] Result          Pointer to a variable to store the result of this function.
 *
 * @return     Std_ReturnType  Standard return type.
 * @retval     E_OK:           Mode could be read.
 * @retval     E_NOT_OK:       Service is rejected.
 */
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType               PowerState,
                                     Adc_PowerStateRequestResultType *Result);
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc */

/** @} end of group Adc_Module */

#endif /* ADC_H */
