/***************************************************************************************************/
/**
 * @file      : Can.h
 * @brief     : Can AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_H
#define CAN_H

/** @addtogroup  Can_Module
 *  @{
 */

/** @addtogroup Can
 *  @brief Can AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CAN_MODULE_ID                   92U
#define CAN_VENDOR_ID                   0x00B3U
#define CAN_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_AR_RELEASE_MINOR_VERSION    6U
#define CAN_AR_RELEASE_REVISION_VERSION 0U
#define CAN_SW_MAJOR_VERSION            1U
#define CAN_SW_MINOR_VERSION            2U
#define CAN_SW_PATCH_VERSION            2U

/* Check if current file and Can_Types.h are of the same vendor */
#if (CAN_VENDOR_ID != CAN_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Can.h and Can_Types.h are different"
#endif
/* Check if current file and Can_Types.h are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (CAN_AR_RELEASE_MINOR_VERSION != CAN_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (CAN_AR_RELEASE_REVISION_VERSION != CAN_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can.h and Can_Types.h are different"
#endif
/* Check if current file and Can_Types.h are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION != CAN_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (CAN_SW_MINOR_VERSION != CAN_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (CAN_SW_PATCH_VERSION != CAN_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Can.h and Can_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
    #define CAN_START_SEC_CONFIG_DATA_PTR
    #include "Can_MemMap.h"
extern const Can_ConfigType *const Can_PreDefinedConfigPtr[CAN_MAX_PARTITIONS];
    #define CAN_STOP_SEC_CONFIG_DATA_PTR
    #include "Can_MemMap.h"
#else
    #define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Can_MemMap.h"

CAN_CONFIG_EXT

    #define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Can_MemMap.h"
#endif /* (CAN_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
 * @brief   Start of Can section CODE
 */
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

CAN_ERROR_NOTIFICATION_CFG_EXT

/**
 * @brief     This function initializes the module.
 *
 * @param[in] Config: Pointer to driver configuration
 *
 * @return    None
 *
 */
void Can_Init(const Can_ConfigType *Config);

/**
 * @brief     This function de-initializes the module.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Can_DeInit(void);

#if (CAN_SET_BAUDRATE_API == STD_ON)
/**
 * @brief     This service shall set the baud Rate configuration of the CAN controller. Depending
 *            on necessary baud Rate modifications the controller might have to reset.
 *
 * @param[in] Controller : CAN controller, whose baud Rate shall be set
 * @param[in] BaudRateConfigID : references a baud Rate configuration by ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Service request accepted, setting of (new) baud rate started.
 * @retval    E_NOT_OK: Service request not accepted.
 *
 */
Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID);
#endif

#if (CAN_VERSION_INFO_API == STD_ON)
/**
 * @brief      This function returns the version information of this module.
 *
 * @param[out] versioninfo: Pointer to where to store the version information of this module
 *
 * @return     None
 *
 */
void Can_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/**
 * @brief     This function performs software triggered State transitions of the CAN controller
 *            State machine.
 *
 * @param[in] Controller: CAN controller for which the Status shall be changed
 * @param[in] Transition: Transition Value to request new CAN controller State
 *
 * @return    Std_ReturnType
 * @retval    E_OK: request accepted.
 * @retval    E_NOT_OK: request not accepted, a development error occurred.
 *
 */
Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);

/**
 * @brief     This function disables all interrupts for this CAN controller.
 *
 * @param[in] Controller: CAN controller for which interrupts shall be disabled.
 *
 * @return    None
 *
 */
void Can_DisableControllerInterrupts(uint8 Controller);

/**
 * @brief      This function enables all allowed interrupts.
 *
 * @param[in]  Controller: CAN controller for which interrupts shall be re-enabled.
 *
 * @return     None
 *
 */
void Can_EnableControllerInterrupts(uint8 Controller);

#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief      This function checks if a wakeup has occurred for the given controller
 *
 * @param[in]  Controller: Controller to be checked for a wakeup
 *
 * @return     Std_ReturnType
 * @retval     E_OK: API call has been accepted.
 * @retval     E_NOT_OK: API call has not been accepted.
 *
 */
Std_ReturnType Can_CheckWakeup(uint8 Controller);
#endif

/**
 * @brief      This service obtains the error State of the CAN controller.
 *
 * @param[in]  Controller: Controller ID
 * @param[out] ErrorStatePtr: Pointer to a memory location, where the error State of the CAN
 *             controller will be stored.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Error state request has been accepted.
 * @retval     E_NOT_OK: Error state request has not been accepted.
 *
 */
Std_ReturnType Can_GetControllerErrorState(uint8 Controller, Can_ErrorStateType *ErrorStatePtr);

/**
 * @brief      Returns the Rx error counter for a CAN controller
 *
 * @param[in]  Controller: CAN controller
 * @param[out] RxErrorCounterPtr: Pointer to a memory location, where the current
 *				 Rx error counter of the CAN controller will be stored.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Rx error counter available.
 * @retval     E_NOT_OK: Wrong ControllerId, or Rx error counter not available.
 *
 */
Std_ReturnType Can_GetControllerRxErrorCounter(uint8 Controller, uint8 *RxErrorCounterPtr);

/**
 * @brief      Returns the Tx error counter for a CAN controller.
 *
 * @param[in]  Controller: CAN controller
 * @param[out] TxErrorCounterPtr: Pointer to a memory location, where the current
 *             Tx error counter of the CAN controller will be stored.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Tx error counter available.
 * @retval     E_NOT_OK: Wrong ControllerId, or Tx error counter not available.
 *
 */
Std_ReturnType Can_GetControllerTxErrorCounter(uint8 Controller, uint8 *TxErrorCounterPtr);

/**
 * @brief      This service reports about the current Status of the requested CAN controller
 *
 * @param[in]  Controller: Controller ID
 * @param[out] ControllerModePtr: Pointer to a memory location, where the current Mode of the
 *			   CAN controller will be stored
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Controller mode request has been accepted.
 * @retval     E_NOT_OK: Controller mode request has not been accepted.
 *
 */
Std_ReturnType Can_GetControllerMode(uint8 Controller, Can_ControllerStateType *ControllerModePtr);

/**
 * @brief      This function is called by CanIf to pass a CAN message to CanDrv for transmission
 *
 * @param[in]  Hth:  Hardware transmit handle shall be used for transmit
 * @param[in]  PduInfo: Pointer to SDU user memory, Data Length and Identifier.
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Write command has been accepted.
 * @retval     E_NOT_OK: development error occurred.
 * @retval     CAN_BUSY: No TX hardware buffer available or pre-emptive call of Can_Write that can't
 * be implemented re-entrant.
 *
 */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);

#if (CAN_ABORT_HW_OBJECT_SEND_API == STD_ON)
/**
 * @brief      This function aborts transmission of the given HTH.
 *
 * @param[in]  Hth: Hardware transmit handle.
 *
 * @return     None
 *
 */
void Can_AbortHwObjectSend(Can_HwHandleType Hth);
#endif

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
/**
 * @brief    This function processes message buffer interrupts.
 *
 * @param[in] Id: instance Id
 * @param[in] MbIdx: mailbox Id
 * @param[in] Type: mailbox Type
 *
 * @return    None
 *
 */
void Can_ProcessMbCommonInterrupt(uint8 Id, uint8 MbIdx, Can_HwObjectType Type);
#endif

#if ((CAN_MB_INTERRUPT_SUPPORT == STD_ON) && (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON))
/**
 * @brief    This function processes RX FIFO DMA interrupts.
 *
 * @param[in] Id: instance Id
 * @param[in] IntType: Interrupt type
 *
 * @return    None
 *
 */
void Can_ProcessRxFiFoDmaInterrupt(uint8 Id, Can_Drv_IntType IntType);
#endif

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/**
 * @brief     This function processes self wakeup interrupt.
 *
 * @param[in] Id: Controller id.
 *
 * @return    None
 *
 */
void Can_ProcessSelfWakeup(uint8 Id);
#endif

/**
 * @brief     This function processes bus-off interrupt.
 *
 * @param[in] Id: Controller Id
 *
 * @return    None
 *
 */
void Can_ProcessBusOffInterrupt(uint8 Id);

#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
/**
 * @brief     This function processes error interrupts.
 *
 * @param[in] CtrlOffset: controller Id
 * @param[in] IsErrFast: Can Fd Error Flag
 * @param[in] Data:  error State Data
 *
 * @return    None
 *
 */
void Can_ProcessErrorInterrupt(uint8 CtrlOffset, boolean IsErrFast, uint32 Data);
#endif

#if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
/**
 * @brief     This function processes error interrupts.
 *
 * @param[in] CtrlOffset: Controller Id
 * @param[in] IntType: Can interrupt.
 * @param[in] Data:  Error status.
 *
 * @return    None
 *
 */
void Can_ProcessEccInterrupt(uint8 CtrlOffset, uint32 IntType, uint32 Data);
#endif

#if (CAN_ERROR_INJECTION_SUPPORT == STD_ON)
/**
 * @brief     This function injects error.
 *
 * @param[in] ControllerId: Controller Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Error injection is ok
 * @retval     E_NOT_OK: some error occur
 * 
 * @note      It is suggested that disable CAN ecc interrupt(including NVIC in 
 *            platform and CanEccEnable function) when call this function.
 *
 */
Std_ReturnType Can_InjectError(uint8 ControllerId);

/**
 * @brief     This function clears inject error. 
 *
 * @param[in] ControllerId: Controller Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK: Clear error injection is ok
 * @retval     E_NOT_OK: some error occur
 * 
 * @note      It is suggested that disable CAN ecc interrupt(including NVIC in 
 *            platform and CanEccEnable function) when call this function.
 *
 */
Std_ReturnType Can_ClearInjectError(uint8 ControllerId);
#endif

/**
 * @brief   Stop of Can section CODE
 */
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Can */

/** @} end of group Can_Module */

#endif /* CAN_H */
