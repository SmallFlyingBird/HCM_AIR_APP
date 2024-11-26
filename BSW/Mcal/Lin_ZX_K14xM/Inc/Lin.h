/**************************************************************************************************/
/**
 * @file      : Lin.h
 * @brief     : Lin AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef LIN_H
#define LIN_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Lin
 *  @brief Lin AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "LinIf.h"
#include "Lin_GeneralTypes.h"
#include "Lin_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define LIN_MODULE_ID                   82U
#define LIN_VENDOR_ID                   0x00B3U
#define LIN_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_AR_RELEASE_MINOR_VERSION    6U
#define LIN_AR_RELEASE_REVISION_VERSION 0U
#define LIN_SW_MAJOR_VERSION            1U
#define LIN_SW_MINOR_VERSION            2U
#define LIN_SW_PATCH_VERSION            2U

/* Check if current file and Lin_Types header file are of the same vendor */
#if (LIN_VENDOR_ID != LIN_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Lin.h and Lin_Types.h are different"
#endif
/* Check if current file and Lin_Types header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION != LIN_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (LIN_AR_RELEASE_MINOR_VERSION != LIN_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (LIN_AR_RELEASE_REVISION_VERSION != LIN_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin.h and Lin_Types.h are different"
#endif
/* Check if current file and Lin_Types header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION != LIN_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (LIN_SW_MINOR_VERSION != LIN_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (LIN_SW_PATCH_VERSION != LIN_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Lin.h and Lin_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE

    #if((LIN_AR_RELEASE_MAJOR_VERSION != LIN_GENERAL_H_AR_RELEASE_MAJOR_VERSION) || \
        (LIN_AR_RELEASE_MINOR_VERSION != LIN_GENERAL_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Lin_GeneralTypes.h and Lin.h are different"
    #endif

    #if((LIN_AR_RELEASE_MAJOR_VERSION != LINIF_H_AR_RELEASE_MAJOR_VERSION) || \
        (LIN_AR_RELEASE_MINOR_VERSION != LINIF_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of LinIf.h and Lin.h are different"
    #endif

#endif

/**
 * @brief  LIN instance id
 */
#define LIN_INSTANCE_ID ((uint8)0x00)

/** @name  Lin driver status
 * @{
 */
#define LIN_UNINIT                                                                                 \
    0x00U /*!< The state LIN_UNINIT means that the Lin module has not been initialized yet and     \
             cannot be used. */
#define LIN_INIT                                                                                   \
    0x01U /*!< The LIN_INIT state indicates that the LIN driver has been initialized, making each  \
             available channel ready for service. */
/** @} */

/** @name LIN driver states
 * @{
 */
#define LIN_CH_OPERATIONAL                                                                         \
    (uint8)0x01U /*!< The individual channel has been initialized (using at least one statically   \
                    configured data set) and is able to participate in the LIN cluster. */
#define LIN_CH_SLEEP_PENDING                                                                       \
    (uint8)0x02U /*!< Only master node applicable, get a go to sleep command,  channel enters      \
                    pending sleep mode */
#define LIN_CH_SLEEP_STATE                                                                         \
    (uint8)0x03U /*!< The detection of a wake-up pulse is enabled. The LIN hardware is into a low  \
                    power mode if such a mode is provided by the hardware. */
/** @} */

/** @name Development errors
 * @{
 */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#define LIN_E_UNINIT (uint8)0x00U /*!< API service used without module initialization */
#define LIN_E_INVALID_CHANNEL                                                                      \
    (uint8)0x02U /*!< API service used with an invalid or inactive channel parameter */
#define LIN_E_INVALID_POINTER                                                                      \
    (uint8)0x03U /*!< API service called with invalid configuration pointer */
#define LIN_E_STATE_TRANSITION (uint8)0x04U /*!< Invalid state transition for the current state */
#define LIN_E_PARAM_POINTER    (uint8)0x05U /*!< API service called with a NULL pointer */
#define LIN_E_TIMEOUT (uint8)0x06U /*!< Timeout caused by hardware error */
#define LIN_E_BUS_BUSY_IN_SLEEP_MODE (uint8)0x07U /*!< busy busy */
#endif                                 /* (LIN_DEV_ERROR_DETECT == STD_ON) */

/** @} */

/** @name Service IDs of the AUTOSAR LIN API.
 * @{
 */
#define LIN_SID_INIT              (uint8)0x00U /*!< Lin_Init() ID. */
#define LIN_SID_GET_VERSION_INFO    (uint8)0x01U /*!< Lin_GetVersionInfo() ID. */
#define LIN_SID_SEND_FRAME         (uint8)0x04U /*!< Lin_SendFrame() ID. */
#define LIN_SID_GO_TO_SLEEP         (uint8)0x06U /*!< Lin_GoToSleep() ID. */
#define LIN_SID_WAKE_UP            (uint8)0x07U /*!< Lin_WakeUp() ID.*/
#define LIN_SID_GET_STATUS         (uint8)0x08U /*!< Lin_GetStatus() ID. */
#define LIN_SID_GO_TO_SLEEP_INTERNAL (uint8)0x09U /*!< Lin_GoToSleepInternal() ID. */
#define LIN_SID_CHECK_WAKE_UP       (uint8)0x0AU /*!< Lin_CheckWakeup() ID. */
#define LIN_SID_WAKE_UP_INTERNAL     (uint8)0x0BU /*!< Lin_WakeupInternal() ID. */
#define LIN_SID_MAINFUNCTION_HANDLING     (uint8)0x0CU /*!< Lin_MainFunction_Handling() ID. */

#if (STD_ON == LIN_SOFTWARE_SIMULATION_TIMEOUT )
#define LIN_SID_SIMULATION_TIMEOUT     (uint8)0x0DU /*!< Lin_SetSimulationStatusToIdle() ID. */
#endif

/** @} */

/** @} end of Public_MacroDefinition */


/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (LIN_PRECOMPILE_SUPPORT == STD_ON)
    #define LIN_START_SEC_CONFIG_DATA_PTR
    #include "Lin_MemMap.h"
extern const Lin_ConfigType *const Lin_PreDefinedConfigPtr[LIN_MAX_PARTITIONS];
    #define LIN_STOP_SEC_CONFIG_DATA_PTR
    #include "Lin_MemMap.h"
#else
    #define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Lin_MemMap.h"

LIN_CONFIG_EXT

    #define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Lin_MemMap.h"
#endif /* (LIN_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */


/** @defgroup Public_TypeDefinition
 *  @{
 */
/** @} end of group Public_TypeDefinition */


/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/**
 *
 * @brief     Initializes the LIN module.
 *             - Service ID: 0x00
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Config: Pointer to LIN driver configuration set.
 *
 * @return    None
 *
 */
void Lin_Init(const Lin_ConfigType *Config);

/**
 *
 * @brief    This function checks if a wakeup has occurred on the addressed LIN channel.
 *             - Service ID: 0x0a
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: No error has occurred during execution of the API.
 * @retval    E_NOT_OK: An error has occurred during execution of the API.
 *
 */
Std_ReturnType Lin_CheckWakeup(uint8 Channel);

#if (LIN_VERSION_INFO_API == STD_ON)
/**
 *
 * @brief      This service returns the version information of this module.
 *             pre-established configurations
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[inout] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 *
 */
void Lin_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* LIN_VERSION_INFO_API == STD_ON */

#if (LIN_MASTER_SUPPORT == STD_ON)
/**
 *
 * @brief     Sends a LIN header and a LIN response, if necessary. The direction of the frame
 *            response (master response, slave response, slave-to-slave communication) is provided 
 *            by the PduInfoPtr. Only used for LIN master nodes.
 *             - Service ID: 0x04
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed
 * @param[in] PduInfoPtr: Pointer to PDU containing the PID, checksum model, response type, Dl and
 *            SDU data pointer
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Send command has been accepted.
 * @retval    E_NOT_OK: Send command has not been accepted, development or production error
 *            occurred.
 *
 */
Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr);

/**
 *
 * @brief      Gets the status of the LIN driver.Only used for LIN master nodes.
 *             - Service ID: 0x08
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Channel: LIN channel to be addressed.
 * @param[out] Lin_SduPtr: Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *             receive buffer where the current SDU is stored.
 *
 * @return    Lin_StatusType
 * @retval    LIN_NOT_OK - Development or production error occurred.
 * @retval    LIN_TX_OK - Successful transmission.
 * @retval    LIN_TX_BUSY - Ongoing transmission (Header or Response).
 * @retval    LIN_TX_HEADER_ERROR: Erroneous header transmission such as:
 *            - Mismatch between sent and read back data
 *   		  - Identifier parity error or Physical bus error
 * @retval	  LIN_TX_ERROR: Erroneous response transmission such as:
 *			  - Mismatch between sent and read back data
 *			  - Physical bus error
 * @retval	  LIN_RX_OK: Reception of correct response.
 * @retval	  LIN_RX_BUSY: Ongoing reception: at least one response byte has been received,
 *            but the checksum byte has not been received.
 * @retval	  LIN_RX_ERROR: Erroneous response reception such as:
 *			  - Framing error
 *			  - Overrun error
 *			  - Checksum error or Short response
 * @retval	  LIN_RX_NO_RESPONSE: No response byte has been received so far.
 * @retval	  LIN_OPERATIONAL: Normal operation; the related LIN channel is woken up
 *            from the LIN_CH_SLEEP and no data has been sent.
 * @retval	  LIN_CH_SLEEP: Sleep state operation; in this state wake-up detection from slave
 *            nodes is enabled.
 *
 */
Lin_StatusType Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr);

/**
 *
 * @brief     The service instructs the driver to transmit a go-to-sleep-command on the addressed
 *            LIN channel. Only used for LIN master nodes.
 *             - Service ID: 0x06
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Sleep command has been accepted.
 * @retval    E_NOT_OK: Sleep command has not been accepted, development or production error
 *            occurred.
 *
 */
Std_ReturnType Lin_GoToSleep(uint8 Channel);
#endif /* LIN_MASTER_SUPPORT == STD_ON */

/**
 *
 * @brief     Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and optionally
 *            sets the LIN hardware unit to reduced power operation mode (if supported by HW).
 *             - Service ID: 0x09
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Command has been accepted.
 * @retval    E_NOT_OK: Command has not been accepted, development or production error occurred.
 *
 */
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel);

/**
 *
 * @brief      Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 *             - Service ID: 0x07
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Channel: LIN channel to be addressed.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Wake-up request has been accepted.
 * @retval     E_NOT_OK: Wake-up request has not been accepted, development or production error
 *             occurred.
 *
 */
Std_ReturnType Lin_Wakeup(uint8 Channel);

/**
 *
 * @brief      Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *             - Service ID: 0x0b
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Non Reentrant
 *
 * @param[in]  Channel: LIN channel to be addressed.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Wake-up request has been accepted.
 * @retval     E_NOT_OK: Wake-up request has not been accepted, development or production error
 *             occurred.
 *
 */
Std_ReturnType Lin_WakeupInternal(uint8 Channel);


/**
 *
 * @brief      Lin Driver status is uninit 
 *
 * @param[in]  None.
 *
 * @retval     E_OK: Deinit ok.
 * @retval     E_NOT_OK: Deinit error.
 *
 */
Std_ReturnType Lin_DeInit(void);


#if (STD_ON == LIN_SOFTWARE_POLLING )
/**
 *
 * @brief     Lin software poll replace interrupts to handle events.
              In this mode,all interrupts need to be closed.
              
 * @param[in] None
 *
 * @return    None
 *
 */
void Lin_MainFunction_Handling(void);

#endif


#if (STD_ON == LIN_SOFTWARE_SIMULATION_TIMEOUT )
/**
 *
 * @brief     Set Lin software simulation status to idle .
              
 * @param[in] Channel: LIN channel to be addressed.
 *
 * @return    None
 *
 */
void Lin_SetSimulationStatusToIdle(uint8 Channel);
#endif


/**
 * @brief   Stop of Fls section CODE
 */
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Lin */

/** @} end of group Lin_Module */

#endif /* LIN_H */
