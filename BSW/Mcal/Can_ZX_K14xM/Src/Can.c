/***************************************************************************************************/
/**
 * @file      : Can.c
 * @brief     : Can AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
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

#include "Can.h"
#include "Can_Drv.h"

#if (STD_ON == CAN_WAKEUP_SUPPORT)
    #include "EcuM.h"
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

#if (STD_ON == CAN_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

#include "SchM_Can.h"
#include "CanIf_Can.h"
#include "Can_Externals.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CAN_C_VENDOR_ID                   0x00B3U
#define CAN_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_C_SW_MAJOR_VERSION            1U
#define CAN_C_SW_MINOR_VERSION            2U
#define CAN_C_SW_PATCH_VERSION            2U

/* Check if current file and Can.h are of the same vendor */
#if (CAN_C_VENDOR_ID != CAN_VENDOR_ID)
    #error "Vendor ID of Can.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION) ||                           \
     (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION) ||                           \
     (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can.c and Can.h are different"
#endif
/* Check if current file and Can header file are of the same Software version */
#if ((CAN_C_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION) ||                                           \
     (CAN_C_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION) ||                                           \
     (CAN_C_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
    #error "Software Version of Can.c and Can.h are different"
#endif

/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor ID of Can.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_C_SW_MAJOR_VERSION != CAN_DRV_H_SW_MAJOR_VERSION) ||                                     \
     (CAN_C_SW_MINOR_VERSION != CAN_DRV_H_SW_MINOR_VERSION) ||                                     \
     (CAN_C_SW_PATCH_VERSION != CAN_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Can.c and Can_Drv.h are different"
#endif

/* Check if current file and Can_Externals.h are of the same vendor */
#if (CAN_C_VENDOR_ID != CAN_EXTERNALS_H_VENDOR_ID)
    #error "Vendor ID of Can.c and Can_Externals.h are different"
#endif
/* Check if current file and Can_Externals.h are of the same Autosar version */
#if ((CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_EXTERNALS_H_AR_RELEASE_MINOR_VERSION) ||               \
     (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_EXTERNALS_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can.c and Can_Externals.h are different"
#endif
/* Check if current file and Can_Externals.h are of the same Software version */
#if ((CAN_C_SW_MAJOR_VERSION != CAN_EXTERNALS_H_SW_MAJOR_VERSION) ||                               \
     (CAN_C_SW_MINOR_VERSION != CAN_EXTERNALS_H_SW_MINOR_VERSION) ||                               \
     (CAN_C_SW_PATCH_VERSION != CAN_EXTERNALS_H_SW_PATCH_VERSION))
    #error "Software Version of Can.c and Can_Externals.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Det.h are of the same version */
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        #if ((CAN_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                   \
             (CAN_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Can.c and Det.h are different"
        #endif
    #endif

    /* Check if current file and CanIf_Can.h are of the same version */
    #if ((CAN_C_AR_RELEASE_MAJOR_VERSION != CANIF_CAN_AR_RELEASE_MAJOR_VERSION) ||                 \
         (CAN_C_AR_RELEASE_MINOR_VERSION != CANIF_CAN_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Can.c and CanIf_Can.h are different"
    #endif

    /* Check if current file and SchM_Can.h are of the same version */
    #if ((SCHM_CAN_H_AR_RELEASE_MAJOR_VERSION != CAN_C_AR_RELEASE_MAJOR_VERSION) ||                \
         (SCHM_CAN_H_AR_RELEASE_MINOR_VERSION != CAN_C_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Can.c and SchM_Can.h are different"
    #endif

    #if (STD_ON == CAN_WAKEUP_SUPPORT)
    /* Check if current file and EcuM.h are of the same version */
        #if ((ECUM_AR_RELEASE_MAJOR_VERSION != CAN_C_AR_RELEASE_MAJOR_VERSION) ||                  \
             (ECUM_AR_RELEASE_MINOR_VERSION != CAN_C_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version of EcuM.h and Can.c are different"
        #endif
    #endif

#endif

#define Can_GetCoreID() ((uint32)0U)

#define CAN_FORMATA_EXT_SHIFT                       (1U)
#define CAN_FORMATA_STD_SHIFT                       (19U)
#define CAN_FORMATB_EXT_SHIFT1                      (16U)
#define CAN_FORMATB_STD_SHIFT1                      (19U)
#define CAN_FORMATB_STD_SHIFT2                      (3U)
#define CAN_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT (15U)
#define CAN_FORMATC_STD_EXT_SHIFT1                  (24U)
#define CAN_FORMATC_STD_EXT_SHIFT2                  (16U)
#define CAN_FORMATC_STD_EXT_SHIFT3                  (8U)
#define CAN_FORMATC_STD_CMP_SHIFT                   (3U)
#define CAN_FORMATC_EXT_CMP_SHIFT                   (21U)

#define CAN_CS_IDE_MASK  ((uint32)0x00200000U)
#define CAN_CS_EDL_MASK  ((uint32)0x80000000U)
#define CAN_CS_CODE_MASK ((uint32)0x0F000000U)
#define CAN_ALL_ERR_INT  ((uint32)0x003B0006U)

#define CAN_RX_OVERRUN                ((uint32)0x06000000U)
#define CAN_RX_FIFO_OVERFLOW_MB_INDEX ((uint32)7U)

#define CAN_STFERR_MASK  ((uint32)1U << 10U)
#define CAN_FRAMERR_MASK ((uint32)1U << 11U)
#define CAN_CRCERR_MASK  ((uint32)1U << 12U)
#define CAN_ACKERR_MASK  ((uint32)1U << 13U)
#define CAN_BIT0ERR_MASK ((uint32)1U << 14U)
#define CAN_BIT1ERR_MASK ((uint32)1U << 15U)

#define CAN_STFERR_FAST_MASK    ((uint32)1U << 26U)
#define CAN_FRAMERR_FAST_MASK   ((uint32)1U << 27U)
#define CAN_CRCERR_FAST_MASK    ((uint32)1U << 28U)
#define CAN_BIT0ERR_FAST_MASK   ((uint32)1U << 30U)
#define CAN_BIT1ERR_FAST_MASK   ((uint32)1U << 31U)
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define CAN_START_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"
/**
 * @brief  Records number of called times of disable controller interrupts.
 */
static uint32 Can_DisableInterruptLevel[CAN_CONTROLLER_CONFIG_COUNT];

#define CAN_STOP_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_16
#include "Can_MemMap.h"

/**
 *  @brief  Controllers baudrate configuration.
 */
static uint16 Can_BaudrateIdConfig[CAN_CONTROLLER_CONFIG_COUNT];

#define CAN_STOP_SEC_VAR_CLEARED_16
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
/**
 *  @brief  Store controllers mode.
 */
static Can_ControllerStateType Can_ControllerState[CAN_CONTROLLER_CONFIG_COUNT];

/**
 *  @brief  CAN driver status(uninit or ready).
 */
static Can_DriverStateType Can_DriverStatus[CAN_MAX_PARTITIONS];

#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"
/**
 *  @brief Pointer to the current driver configuration
 */
static const Can_ConfigType *Can_ConfigPtr[CAN_MAX_PARTITIONS];

#define CAN_STOP_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"

/**
 *  @brief Store controllers configuration.
 */
static const Can_ControllerConfigType *Can_ControllerConfigPtr[CAN_CONTROLLER_CONFIG_COUNT];

/**
 *  @brief Store hardware objects configuration.
 */
static const Can_HwObjConfigType *Can_HwObjectConfigPtr[CAN_HWOBJECT_CONFIG_COUNT];

#define CAN_STOP_SEC_VAR_CLEARED_PTR
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#if CAN_CONTROLLER_CONFIG_COUNT == 1U
static Can_Drv_StateType Can_Status0;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 1U */

#if CAN_CONTROLLER_CONFIG_COUNT == 2U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 2U */

#if CAN_CONTROLLER_CONFIG_COUNT == 3U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
static Can_Drv_StateType Can_Status2;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 3U */

#if CAN_CONTROLLER_CONFIG_COUNT == 4U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
static Can_Drv_StateType Can_Status2;
static Can_Drv_StateType Can_Status3;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 4U */

#if CAN_CONTROLLER_CONFIG_COUNT == 5U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
static Can_Drv_StateType Can_Status2;
static Can_Drv_StateType Can_Status3;
static Can_Drv_StateType Can_Status4;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 5U */

#if CAN_CONTROLLER_CONFIG_COUNT == 6U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
static Can_Drv_StateType Can_Status2;
static Can_Drv_StateType Can_Status3;
static Can_Drv_StateType Can_Status4;
static Can_Drv_StateType Can_Status5;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 6U */

#if CAN_CONTROLLER_CONFIG_COUNT == 7U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
static Can_Drv_StateType Can_Status2;
static Can_Drv_StateType Can_Status3;
static Can_Drv_StateType Can_Status4;
static Can_Drv_StateType Can_Status5;
static Can_Drv_StateType Can_Status6;
#endif /* CAN_CONTROLLER_CONFIG_COUNT == 7U */
#if CAN_CONTROLLER_CONFIG_COUNT == 8U
static Can_Drv_StateType Can_Status0;
static Can_Drv_StateType Can_Status1;
static Can_Drv_StateType Can_Status2;
static Can_Drv_StateType Can_Status3;
static Can_Drv_StateType Can_Status4;
static Can_Drv_StateType Can_Status5;
static Can_Drv_StateType Can_Status6;
static Can_Drv_StateType Can_Status7;
#endif

#if ((CAN_TX_POLLING_SUPPORT == STD_ON) || (CAN_MB_INTERRUPT_SUPPORT == STD_ON))
static PduIdType Can_TxPduId[CAN_CONTROLLER_CONFIG_COUNT][CAN_HWMB_COUNT];
#endif

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
static Can_HwHandleType Can_HwToMapMbIndex[CAN_CONTROLLER_CONFIG_COUNT][CAN_HWMB_COUNT];
#endif

#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONST_PTR
#include "Can_MemMap.h"

#if CAN_CONTROLLER_CONFIG_COUNT == 1U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Status0};
#endif

#if CAN_CONTROLLER_CONFIG_COUNT == 2U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {&Can_Status0,
                                                                          &Can_Status1};
#endif

#if CAN_CONTROLLER_CONFIG_COUNT == 3U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {
    &Can_Status0, &Can_Status1, &Can_Status2};
#endif

#if CAN_CONTROLLER_CONFIG_COUNT == 4U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {
    &Can_Status0, &Can_Status1, &Can_Status2, &Can_Status3};
#endif

#if CAN_CONTROLLER_CONFIG_COUNT == 5U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {
    &Can_Status0, &Can_Status1, &Can_Status2, &Can_Status3, &Can_Status4};
#endif

#if CAN_CONTROLLER_CONFIG_COUNT == 6U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {
    &Can_Status0, &Can_Status1, &Can_Status2, &Can_Status3, &Can_Status4, &Can_Status5};
#endif

#if CAN_CONTROLLER_CONFIG_COUNT == 7U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {
    &Can_Status0, &Can_Status1, &Can_Status2, &Can_Status3,
    &Can_Status4, &Can_Status5, &Can_Status6};
#endif
#if CAN_CONTROLLER_CONFIG_COUNT == 8U
static Can_Drv_StateType *const Can_State[CAN_CONTROLLER_CONFIG_COUNT] = {
    &Can_Status0, &Can_Status1, &Can_Status2, &Can_Status3,
    &Can_Status4, &Can_Status5, &Can_Status6, &Can_Status7};
#endif

#define CAN_STOP_SEC_CONST_PTR
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_BOOLEAN
#include "Can_MemMap.h"

/**
 *  @brief Store controllers interrupts enabled status.
 */
static boolean Can_InterruptEnableStatus[CAN_CONTROLLER_CONFIG_COUNT];

#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 *  @brief Store controllers wakeup status.
 */
static boolean Can_SelfWakeupStatus[CAN_CONTROLLER_CONFIG_COUNT];
#endif
#if (CAN_ERROR_INJECTION_SUPPORT == STD_ON)
static boolean Can_EccInjectionStatus[CAN_CONTROLLER_CONFIG_COUNT];
#endif
#define CAN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Can_MemMap.h"



/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckInitialized(uint8 ServiceId);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckInit(const Can_ConfigType *Config);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckDeinit(void);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckController(uint8 ServiceId, uint8 Controller);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckGetControllerErrorState(const Can_ErrorStateType *ErrorStatePtr);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckGetControllerErrorCounter(uint8 ServiceId, const uint8 *ErrorCounterPtr);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckGetControllerMode(const Can_ControllerStateType *ControllerModePtr);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
static boolean Can_CheckWrite(Can_HwHandleType Hth, const Can_PduType *PduInfo);
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_ABORT_HW_OBJECT_SEND_API == STD_ON)
static boolean Can_CheckAbortHwObjectSend(Can_HwHandleType Hth);
#endif

#if ((CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON))
static boolean Can_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfo);
#endif

#if ((CAN_SET_BAUDRATE_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON))
static boolean Can_CheckSetBaudrate(uint8 Controller, uint16 BaudRateConfigId);
#endif

static boolean Can_CheckControllerBusy(uint32 CoreId);

static uint16 Can_SetControllerRxMask(const uint8 ControllerId, const uint8 HwChannel,
                                     Can_Drv_RxAcceptanceType *FormatPtr, uint16 Index,
                                     const Can_HwObjConfigType *HwConfigPtr);

static void Can_SetControllerFifoFilter(const uint8 ControllerId, const uint8 HwChannel,
                                        uint8 HwObjId);

static Std_ReturnType Can_SetControllerRxConfig(const uint8 ControllerId, const uint8 HwChannel);

static Std_ReturnType Can_InitController(const uint8 ControllerId, const uint8 HwChannel,
                                         const Can_ControllerConfigType *ConfigPtr);

static void Can_InitAllControllers(uint32 CoreId);

static boolean Can_CheckPduInfo(const Can_ControllerConfigType *ConfigPtr,
                                const Can_HwObjConfigType      *HwConfigPtr,
                                const Can_PduType              *PduInfoPtr);

static Std_ReturnType Can_SetControllerToStopMode(const uint8 ControllerId, const uint8 HwChannel);

static Std_ReturnType Can_EnterStopMode(uint8 ControllerId);

#if (CAN_WAKEUP_SUPPORT == STD_ON)
static Std_ReturnType Can_SetControllerToSleepMode(const uint8 ControllerId, const uint8 HwChannel);
#endif

static Std_ReturnType Can_EnterSleepMode(uint8 ControllerId);

static Std_ReturnType Can_SetControllerToStartMode(const uint8 ControllerId, const uint8 HwChannel);

static Std_ReturnType Can_EnterStartMode(const uint8 ControllerId, const uint8 HwChannel);

static Std_ReturnType Can_ControllerModeTransition(uint8                   Controller,
                                                   Can_ControllerStateType Transition);

#if (CAN_MAINFUNCTION_MULTIPLE_WRITE == STD_ON)
static void Can_MainFunctionMultipleWrite(uint8 Index);
#endif

#if (CAN_MAINFUNCTION_MULTIPLE_READ == STD_ON)
static void Can_MainFunctionMultipleRead(uint8 Index);
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
static Std_ReturnType Can_ConfigBaudrate(const uint8 ControllerId, const uint8 HwChannel,
                                         uint16 BaudId);
#endif

#if (CAN_TX_POLLING_SUPPORT == STD_ON)
static void Can_ExecutePollingWrite(const uint8 ControllerId, const uint8 HwChannel, uint8 HwObjId,
                                    const Can_HwObjConfigType *HwConfigPtr);
#endif

static void Can_ParseRxData(const uint8 ControllerId, uint8 HwObjId, Can_HwType *CanHwObjPtr,
                            PduInfoType *CanIfPduInfoPtr, Can_Drv_MsgBufType *MsgBufPtr);

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
static void Can_ProcessRxNormalReceive(const uint8 ControllerId, const uint8 HwChannel,
                                       uint8 HwObjId);

static void Can_ProcessRxFifoReceive(const uint8 ControllerId, const uint8 HwChannel,
                                     uint8 HwObjId);
#endif

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
static void Can_ExecutePollingRead(const uint8 ControllerId, const uint8 HwChannel, uint8 HwObjId,
                                   const Can_HwObjConfigType *HwConfigPtr);
#endif

static void Can_ExecutePollingMode(const uint8 ControllerId, const uint8 HwChannel,
                                   Can_ControllerStateType *ControllerStatePtr);

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
static void Can_ProcessTxMsgBuffer(const uint8 ControllerId, const Can_HwObjConfigType *HwConfigPtr,
                                   uint8 MbIdx);

static void Can_ProcessRxMsgBuffer(const uint8 ControllerId, const uint8 HwChannel,
                                   const Can_HwObjConfigType *HwConfigPtr, uint8 MbIdx);
#endif

#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
static void Can_ProcessRxDma(const uint8 ControllerId, const uint8 HwChannel,
                             const Can_HwObjConfigType *HwConfigPtr, Can_Drv_IntType IntType);
#endif
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
#if (CAN_SEC_EVENT_REPORT_SUPPORT == STD_ON)
static void Can_ReportSecurityEvents(uint8 CanInterfaceId, uint32 Data);
#endif
#endif
static Can_Drv_ControllerStatus Can_SendMessage(const uint8 ControllerId, const uint8 HwChannel,
                                                uint8                    HwObjId,
                                                Can_Drv_MessageInfoType *MessageInfoPtr,
                                                uint8 Index, const Can_PduType *PduInfoPtr);

static Std_ReturnType Can_SendPdu(const uint8 ControllerId, const uint8 HwChannel,
                                  Can_HwHandleType HwObjId, const Can_HwObjConfigType *HwConfigPtr,
                                  const Can_PduType *PduPtr);

static void Can_ProcessEnableControllerInterrupts(const uint8 ControllerId, const uint8 HwChannel);

static void Can_ProcessDisableControllerInterrupts(const uint8 ControllerId, const uint8 HwChannel);

static Can_ErrorStateType Can_GetControllerState(const uint8 ControllerId, const uint8 HwChannel);

#if (STD_ON == CAN_ABORT_HW_OBJECT_SEND_API)
static void Can_CancelTransfer(const uint8 HwChannel, const Can_HwObjConfigType *HwConfigPtr);
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief     Checks whether CAN driver has already been initialized.
 *
 * @param[in] ServiceId: Service id.
 *
 * @return    boolean
 * @retval    TRUE: CAN driver has already been initialized.
 * @retval    FALSE: CAN driver has not already been initialized.
 *
 */
static boolean Can_CheckInitialized(uint8 ServiceId)
{
    boolean CheckStatus = FALSE;
    uint32  CanCoreId = Can_GetCoreID();

    if (CAN_UNINIT == Can_DriverStatus[CanCoreId])
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, ServiceId,
                              (uint8)CAN_E_UNINIT);
    }
    else
    {
        CheckStatus = TRUE;
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief     Checks whether CAN driver has not been initialized and input parameter is valid.
 *
 * @param[in] Config: Pointer to driver configuration
 *
 * @return    boolean
 * @retval    TRUE: CAN driver has not been initialized and input parameter is valid.
 * @retval    TRUE: CAN driver has been initialized or input parameter is invalid.
 *
 */
static boolean Can_CheckInit(const Can_ConfigType *Config)
{
    uint32  CanCoreId = Can_GetCoreID();
    boolean CheckStatus = FALSE;

    if (CAN_UNINIT != Can_DriverStatus[CanCoreId])
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_INIT,
                              (uint8)CAN_E_TRANSITION);
    }
    else
    {
    #if (CAN_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != Config)
    #else
        if (NULL_PTR == Config)
    #endif
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_INIT,
                                  (uint8)CAN_E_INIT_FAILED);
        }
        else
        {
            CheckStatus = TRUE;
        }
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief     Checks whether all controllers are not in start mode.
 *
 * @param[in] None
 *
 * @return    boolean
 * @retval    TRUE: All controllers are not in start mode.
 * @retval    FALSE: Not all controllers are not in start mode.
 *
 */
static boolean Can_CheckDeinit(void)
{
    boolean CheckStatus = TRUE;
    uint32  CanCoreId = Can_GetCoreID();
    uint8   CtrlId = 0U;

    if (CAN_READY != Can_DriverStatus[CanCoreId])
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_DEINIT,
                              (uint8)CAN_E_TRANSITION);
        CheckStatus = FALSE;
    }
    else
    {
        for (CtrlId = 0U; CtrlId < Can_ConfigPtr[CanCoreId]->CanControllerCounter; CtrlId++)
        {
            if (NULL_PTR != (Can_ConfigPtr[CanCoreId])->CanControllerConfigPtr[CtrlId])
            {
                if (CAN_CS_STARTED == Can_ControllerState[CtrlId])
                {
                    (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                          (uint8)CAN_SID_DEINIT, (uint8)CAN_E_TRANSITION);
                    CheckStatus = FALSE;
                    break;
                }
            }
        }
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief     Checks whether the given controller id is valid.
 *
 * @param[in] ServiceId: Service id.
 * @param[in] Controller: Controller id.
 *
 * @return    boolean
 * @retval    TRUE: The given controller id is valid.
 * @retval    FALSE: The given controller id is invalid.
 *
 */
static boolean Can_CheckController(uint8 ServiceId, uint8 Controller)
{
    boolean CheckStatus = TRUE;
    uint32  CanCoreId = Can_GetCoreID();

    if (Controller >= Can_ConfigPtr[CanCoreId]->CanControllerCounter)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, ServiceId,
                              (uint8)CAN_E_PARAM_CONTROLLER);
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks whether input pointer is a NULL pointer.
 *
 * @param[in]  ErrorStatePtr: Pointer to a memory location, where the error State of the CAN
 *             controller will be stored.
 *
 * @return     boolean
 * @retval     TRUE: Input pointer is not a NULL pointer.
 * @retval     FALSE: Input pointer is a NULL pointer.
 *
 */
static boolean Can_CheckGetControllerErrorState(const Can_ErrorStateType *ErrorStatePtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == ErrorStatePtr)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              (uint8)CAN_SID_GET_CONTROLLER_ERROR_STATE,
                              (uint8)CAN_E_PARAM_POINTER);
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks whether input pointer is a NULL pointer.
 *
 * @param[in]  ServiceId: Service id.
 * @param[in]  ErrorCounterPtr: Pointer to store Tx/Rx error counter.
 *
 * @return     boolean
 * @retval     TRUE: Input pointer is not a NULL pointer.
 * @retval     FALSE: Input pointer is a NULL pointer.
 *
 */
static boolean Can_CheckGetControllerErrorCounter(uint8 ServiceId, const uint8 *ErrorCounterPtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == ErrorCounterPtr)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, ServiceId,
                              (uint8)CAN_E_PARAM_POINTER);
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks whether input parameter is a NULL pointer.
 *
 * @param[out] ControllerModePtr: Pointer to a memory location, where the current Mode of the
 *			   CAN controller will be stored
 *
 * @return     boolean
 * @retval     TRUE: Input parameter is a not NULL pointer.
 * @retval     FALSE: Input parameter is a NULL pointer.
 *
 */
static boolean Can_CheckGetControllerMode(const Can_ControllerStateType *ControllerModePtr)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == ControllerModePtr)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              (uint8)CAN_SID_GET_CONTROLLER_MODE, (uint8)CAN_E_PARAM_POINTER);
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      Checks whether HTH and PduInfo are valid.
 *
 * @param[in]  Hth:  Hardware transmit handle shall be used for transmit
 * @param[in]  PduInfo: Pointer to SDU user memory, Data Length and Identifier.
 *
 * @return     boolean
 * @retval     TRUE: HTH and PduInfo are valid.
 * @retval     TRUE: HTH or PduInfo is invalid.
 *
 */
static boolean Can_CheckWrite(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    boolean CheckStatus = TRUE;
    uint32  CanCoreId = Can_GetCoreID();

    if ((Hth >= Can_ConfigPtr[CanCoreId]->CanHardwareCounter) ||
        (Hth < Can_ConfigPtr[CanCoreId]->CanFirstHTHIndex))
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE,
                              (uint8)CAN_E_PARAM_HANDLE);
        CheckStatus = FALSE;
    }
    else if (NULL_PTR == PduInfo)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE,
                              (uint8)CAN_E_PARAM_POINTER);
        CheckStatus = FALSE;
    }
    else
    {
        /* Nothing to do */
    }

    return CheckStatus;
}
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_ABORT_HW_OBJECT_SEND_API == STD_ON)
/**
 * @brief      Checks whether HTH and PduInfo are valid.
 *
 * @param[in]  Hth:  Hardware transmit handle shall be used for transmit
 *
 * @return     boolean
 * @retval     TRUE: HTH and PduInfo are valid.
 * @retval     TRUE: HTH or PduInfo is invalid.
 *
 */
static boolean Can_CheckAbortHwObjectSend(Can_HwHandleType Hth)
{
    boolean CheckStatus = TRUE;
    uint32  CanCoreId = Can_GetCoreID();

    if ((Hth >= Can_ConfigPtr[CanCoreId]->CanHardwareCounter) ||
        (Hth < Can_ConfigPtr[CanCoreId]->CanFirstHTHIndex))
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ABORT_MB,
                              (uint8)CAN_E_PARAM_HANDLE);
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif

#if ((CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief      Checks whther input parameter is a NULL pointer.
 *
 * @param[in]  VersionInfo: Pointer to where to store the version information of this module
 *
 * @return     boolean
 * @retval     TRUE: Input parameter is not a NULL pointer.
 * @retval     FALSE: Input parameter is a NULL pointer.
 *
 */
static boolean Can_CheckGetVersionInfo(const Std_VersionInfoType *VersionInfo)
{
    boolean CheckStatus = TRUE;

    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              (uint8)CAN_SID_GET_VERSION_INFO, (uint8)CAN_E_PARAM_POINTER);
        CheckStatus = FALSE;
    }

    return CheckStatus;
}
#endif

#if ((CAN_SET_BAUDRATE_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief     Checks whether controller id and baudrate id are valid.
 *
 * @param[in] Controller : CAN controller, whose baud Rate shall be set
 * @param[in] BaudRateConfigID : references a baud Rate configuration by ID
 *
 * @return    boolean
 * @retval    TRUE: Controller id and baudrate id are valid.
 * @retval    FALSE: Controller id or baudrate id is invalid.
 *
 */
static boolean Can_CheckSetBaudrate(uint8 Controller, uint16 BaudRateConfigId)
{
    boolean                         CheckStatus = FALSE;
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

    CanCtrlPtr = (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                        ->CanControllerConfigPtr[Controller]);

    if (BaudRateConfigId >= CanCtrlPtr->CanBaudrateCount)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              (uint8)CAN_SID_SET_BAUDRATE, (uint8)CAN_E_PARAM_BAUDRATE);
    }
    else if (CAN_CS_STOPPED != Can_ControllerState[Controller])
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              (uint8)CAN_SID_SET_BAUDRATE, (uint8)CAN_E_TRANSITION);
    }
    else
    {
        CheckStatus = TRUE;
    }

    return CheckStatus;
}
#endif

/**
 * @brief     Checks whether any controller is in busy state.
 *
 * @param[in] CoreId: Core id.
 *
 * @return    boolean
 * @retval    TRUE: Some controller is in busy state.
 * @retval    FALSE: No controller is in busy state.
 *
 */
/*SWS_Can_00408 */
static boolean Can_CheckControllerBusy(uint32 CoreId)
{
    boolean CtrlBusy = (boolean)FALSE;
    uint8   Index = 0U;

    for (Index = 0U; Index < Can_ConfigPtr[CoreId]->CanControllerCounter; ++Index)
    {
        if (NULL_PTR != (Can_ConfigPtr[CoreId])->CanControllerConfigPtr[Index])
        {
            if (CAN_CS_UNINIT != Can_ControllerState[Index])
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                      (uint8)CAN_SID_INIT, (uint8)CAN_E_TRANSITION);
#endif
                CtrlBusy = (boolean)TRUE;
                break;
            }
        }
    }

    return CtrlBusy;
}

/**
 * @brief      Sets Rx FIFO message id filter mask.
 *
 * @param[in]  ControllerId: Controller id.
 * @param[in]  HwChannel: Hardware channel.
 * @param[out] FormatPtr: Filter format
 * @param[in]  Index: data index
 * @param[in]  HwConfigPtr: Can object configure
 *
 * @return     uint8: Filter number.
 *
 */
static uint16 Can_SetControllerRxMask(const uint8 ControllerId, const uint8 HwChannel,
                                     Can_Drv_RxAcceptanceType *FormatPtr, uint16 Index,
                                     const Can_HwObjConfigType *HwConfigPtr)
{
    uint16                           HwFilterCount = 0U;
    uint32                          HwFilterMask = (uint32)0x00000000U;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    Can_RxAcceptanceType            TempRxFifoType = ConfigPtr->CanRxFifoConfigPtr->CanRxFifoType;

    switch (TempRxFifoType)
    {
        case CAN_RX_FIFO_FORMAT_A:
            /*Filter Table number*/
            HwFilterCount = HwConfigPtr->CanHwFilterCount;
            HwFilterMask = (uint32)0xC0000000U;

            *FormatPtr = CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_A;
            if (CAN_MSG_ID_STANDARD != HwConfigPtr->CanIdMessageType)
            {
                HwFilterMask |= HwConfigPtr->CanHwFilterPtr[Index].CanHwFilterMask
                                << CAN_FORMATA_EXT_SHIFT;
            }
            else
            {
                HwFilterMask |= HwConfigPtr->CanHwFilterPtr[Index].CanHwFilterMask
                                << CAN_FORMATA_STD_SHIFT;
            }
            break;
        case CAN_RX_FIFO_FORMAT_B:
            HwFilterCount = ((uint16)HwConfigPtr->CanHwFilterCount * 2U);
            HwFilterMask = (uint32)0xC000C000U;

            *FormatPtr = CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_B;
            if (CAN_MSG_ID_STANDARD != HwConfigPtr->CanIdMessageType)
            {
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[Index * 2U].CanHwFilterMask >>
                                 CAN_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT)
                                << CAN_FORMATB_EXT_SHIFT1;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 2U) + 1U].CanHwFilterMask >>
                                 CAN_RX_FIFO_ID_FILTER_FORMATB_EXT_CMP_SHIFT);
            }
            else
            {
                HwFilterMask |= HwConfigPtr->CanHwFilterPtr[Index * 2U].CanHwFilterMask
                                << CAN_FORMATB_STD_SHIFT1;
                HwFilterMask |= HwConfigPtr->CanHwFilterPtr[(Index * 2U) + 1U].CanHwFilterMask
                                << CAN_FORMATB_STD_SHIFT2;
            }
            break;
        case CAN_RX_FIFO_FORMAT_C:
            HwFilterCount = ((uint16)HwConfigPtr->CanHwFilterCount * 4U);
            *FormatPtr = CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_C;
            if (CAN_MSG_ID_STANDARD != HwConfigPtr->CanIdMessageType)
            {
                HwFilterMask = (HwConfigPtr->CanHwFilterPtr[Index * 4U].CanHwFilterMask >>
                                CAN_FORMATC_EXT_CMP_SHIFT)
                               << CAN_FORMATC_STD_EXT_SHIFT1;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 4U) + 1U].CanHwFilterMask >>
                                 CAN_FORMATC_EXT_CMP_SHIFT)
                                << CAN_FORMATC_STD_EXT_SHIFT2;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 4U) + 2U].CanHwFilterMask >>
                                 CAN_FORMATC_EXT_CMP_SHIFT)
                                << CAN_FORMATC_STD_EXT_SHIFT3;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 4U) + 3U].CanHwFilterMask >>
                                 CAN_FORMATC_EXT_CMP_SHIFT);
            }
            else
            {
                HwFilterMask = (HwConfigPtr->CanHwFilterPtr[Index * 4U].CanHwFilterMask >>
                                CAN_FORMATC_STD_CMP_SHIFT)
                               << CAN_FORMATC_STD_EXT_SHIFT1;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 4U) + 1U].CanHwFilterMask >>
                                 CAN_FORMATC_STD_CMP_SHIFT)
                                << CAN_FORMATC_STD_EXT_SHIFT2;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 4U) + 2U].CanHwFilterMask >>
                                 CAN_FORMATC_STD_CMP_SHIFT)
                                << CAN_FORMATC_STD_EXT_SHIFT3;
                HwFilterMask |= (HwConfigPtr->CanHwFilterPtr[(Index * 4U) + 3U].CanHwFilterMask >>
                                 CAN_FORMATC_STD_CMP_SHIFT);
            }
            break;
        default:
            *FormatPtr = CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_D;
            break;
    }

    /*set RxFIFO individual Mask*/
    (void)Can_Drv_SetRxFifoIndividualMask(HwChannel, Index, HwFilterMask);

    return HwFilterCount;
}

/**
 * @brief     Sets Rx FIFO message id filter.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwObjId: Can object configure index
 *
 * @return    None
 *
 */
static void Can_SetControllerFifoFilter(const uint8 ControllerId, const uint8 HwChannel,
                                        uint8 HwObjId)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    uint16                           FilterIdx = 0U;
    uint16                           HwFilterCount = 0U;
    const Can_HwObjConfigType      *HwConfigPtr = ConfigPtr->CanHwObjectPPtr[HwObjId];
    /*set Fifo filter Data*/
    uint8                    FifoFilterRffn = 0U;
    Can_Drv_RxAcceptanceType ElementFormat = CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_A;
    Can_Drv_IdFilterType     RxFifoFilters[512] = {0};

    if (((HwConfigPtr->CanHwFilterCount / 4U) + 6U) <= 32U)
    {
        FifoFilterRffn = (HwConfigPtr->CanHwFilterCount / 4U) + 6U;
    }
    else
    {
        FifoFilterRffn = 32U;
    }

    for (FilterIdx = 0U;
         ((FilterIdx < FifoFilterRffn) && (FilterIdx < HwConfigPtr->CanHwFilterCount)); FilterIdx++)
    {
        HwFilterCount = Can_SetControllerRxMask(ControllerId, HwChannel, &ElementFormat, FilterIdx,
                                                HwConfigPtr);
    }

    (void)Can_Drv_SetRxFifoGlobalMask(HwChannel,
                                      ConfigPtr->CanRxFifoConfigPtr->CanRxFifoGlobalFilterMask);

    for (FilterIdx = 0U; FilterIdx < HwFilterCount; FilterIdx++)
    {
        RxFifoFilters[FilterIdx].Id = HwConfigPtr->CanHwFilterPtr[FilterIdx].CanHwFilterCode;
        if (HwConfigPtr->CanIdMessageType != CAN_MSG_ID_STANDARD)
        {
            RxFifoFilters[FilterIdx].IsExtendedFrame = (boolean)TRUE;
        }
        else
        {
            RxFifoFilters[FilterIdx].IsExtendedFrame = (boolean)FALSE;
        }
        RxFifoFilters[FilterIdx].IsRemoteFrame = (boolean)FALSE;
    }

    (void)Can_Drv_ConfigRxFifo(HwChannel, ElementFormat, &RxFifoFilters[0]);
}

/**
 * @brief     Initializes Can controller Rx configure
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    Std_ReturnType: Standard return Type.
 * @retval    E_OK: Init operation  successfully
 * @retval    E_NOT_OK:  Init operation failed
 *
 */
static Std_ReturnType Can_SetControllerRxConfig(const uint8 ControllerId, const uint8 HwChannel)
{
    Std_ReturnType                  Ret;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    uint8                           HwObjIndex = 0U;
    const Can_HwObjConfigType      *CanHwObjPtr;
    Can_Drv_MsgIdType               CanMsgIdType;

    /* Enable individual Rx masking and queue */
    (void)Can_Drv_SetRxMaskType(HwChannel, CAN_DRV_RX_MASK_INDIVIDUAL);

    for (HwObjIndex = 0U; HwObjIndex < ConfigPtr->CanHwObjectRefCount; HwObjIndex++)
    {
        CanHwObjPtr = (const Can_HwObjConfigType *)ConfigPtr->CanHwObjectPPtr[HwObjIndex];

        if (CAN_OBJ_RECEIVE == CanHwObjPtr->CanObjectType)
        {
            if (CAN_MSG_ID_STANDARD == CanHwObjPtr->CanIdMessageType)
            {
                CanMsgIdType = CAN_DRV_MSG_ID_STD;
            }
            else
            {
                CanMsgIdType = CAN_DRV_MSG_ID_EXT;
            }
            (void)Can_Drv_ConfigRxMb(HwChannel, CanHwObjPtr->CanHwBufferIndex, CanMsgIdType,
                                     CanHwObjPtr->CanHwFilterPtr->CanHwFilterCode);
            /* configure Mask  */
            (void)Can_Drv_SetRxIndividualMask(HwChannel, CanMsgIdType,
                                              CanHwObjPtr->CanHwBufferIndex,
                                              CanHwObjPtr->CanHwFilterPtr->CanHwFilterMask);
        }
        else if (CAN_OBJ_FIFO == CanHwObjPtr->CanObjectType)
        {
            Can_SetControllerFifoFilter(ControllerId, HwChannel, HwObjIndex);
        }
        else
        {
            /* Nothing to do */
        }
    }
    Ret = (CAN_DRV_SUCCESS == Can_Drv_SetStopMode(HwChannel)) ? ((Std_ReturnType)E_OK)
                                                              : ((Std_ReturnType)E_NOT_OK);
    return Ret;
}

/**
 * @brief     Initializes specify controller.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] ConfigPtr: Controller configuration.
 *
 * @return    Std_ReturnType: Standard return Type.
 * @retval    E_OK: Init operation executed successfully.
 * @retval    E_NOT_OK: Init operation executed failed.
 *
 */
static Std_ReturnType Can_InitController(const uint8 ControllerId, const uint8 HwChannel,
                                         const Can_ControllerConfigType *ConfigPtr)
{
    Std_ReturnType ReturnVal = (Std_ReturnType)E_NOT_OK;
    Can_ControllerConfigPtr[ControllerId] = ConfigPtr;

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
    uint8                      HwObjectRefIndex = 0U;
    uint8                      ObjIndex = 0U;
    uint8                      HwBufferCount = 0U;
    const Can_HwObjConfigType *CanHwObjectPtr = NULL_PTR;
    Can_HwObjectType           TempCanObjectType;
#endif

    ReturnVal = (Std_ReturnType)Can_Drv_Init(HwChannel, Can_State[ControllerId],
                                             ConfigPtr->CanHwChannelConfigPtr->CanHwConfigPtr);

    if ((Std_ReturnType)CAN_DRV_SUCCESS == ReturnVal)
    {
        (void)Can_Drv_DisableMbInterrupts(HwChannel);

        Can_InterruptEnableStatus[ControllerId] = (boolean)TRUE;

#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
        Can_SelfWakeupStatus[ControllerId] = (boolean)FALSE;
#endif

#if (CAN_FD_MODE_ENABLE == STD_ON)
        /* Enable TDC and set TDC offset */
        if (TRUE == ConfigPtr->CanBaudratePtr[ConfigPtr->CanDefaultBaudrateIndex].CanFdEnable)
        {
            (void)Can_Drv_SetFdTdc(
                HwChannel,
                ConfigPtr->CanBaudratePtr[ConfigPtr->CanDefaultBaudrateIndex].CanTransmitCompEnable,
                ConfigPtr->CanBaudratePtr[ConfigPtr->CanDefaultBaudrateIndex]
                    .CanControllerSspOffset);
        }

#endif
        (void)Can_Drv_SetTxArbitrationDelay(
            HwChannel, ConfigPtr->CanBaudratePtr[ConfigPtr->CanDefaultBaudrateIndex]
                           .CanControlTxArbitrationStartDelay);
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
        for (HwBufferCount = 0U; HwBufferCount < CAN_HWMB_COUNT; HwBufferCount++)
        {
            Can_HwToMapMbIndex[ControllerId][HwBufferCount] = (Can_HwHandleType)0xFF;
        }

        for (HwObjectRefIndex = 0U; HwObjectRefIndex < ConfigPtr->CanHwObjectRefCount;
             HwObjectRefIndex++)
        {
            CanHwObjectPtr = ConfigPtr->CanHwObjectPPtr[HwObjectRefIndex];
            Can_HwObjectConfigPtr[CanHwObjectPtr->CanHwObjectId] = CanHwObjectPtr;
            TempCanObjectType = CanHwObjectPtr->CanObjectType;
            switch (TempCanObjectType)
            {
                case CAN_OBJ_RECEIVE:
                {
                    Can_HwToMapMbIndex[ControllerId][CanHwObjectPtr->CanHwBufferIndex] =
                        CanHwObjectPtr->CanHwObjectId;
                    break;
                }
                case CAN_OBJ_TRANSMIT:
                {
                    /* Support multiple Transmit */
                    for (ObjIndex = 0U; ObjIndex < CanHwObjectPtr->CanHwObjectCount; ObjIndex++)
                    {
                        Can_HwToMapMbIndex[ControllerId][CanHwObjectPtr->CanHwBufferIndex +
                                                         ObjIndex] = CanHwObjectPtr->CanHwObjectId;
                    }
                    break;
                }
                case CAN_OBJ_FIFO:
                {
                    Can_HwToMapMbIndex[ControllerId][CanHwObjectPtr->CanHwBufferIndex] =
                        CanHwObjectPtr->CanHwObjectId;
                    Can_HwToMapMbIndex[ControllerId][6U] = CanHwObjectPtr->CanHwObjectId;
                    Can_HwToMapMbIndex[ControllerId][7U] = CanHwObjectPtr->CanHwObjectId;
                    break;
                }
                default:
                {
                    /* Nothing to do */
                    break;
                }
            }
        }

#endif

        (void)Can_SetControllerRxConfig(ControllerId, HwChannel);
    }

    return (Std_ReturnType)ReturnVal;
}

/**
 * @brief     Initializes all controllers.
 *
 * @param[in] CoreId: Core id.
 *
 * @return    None
 *
 */
/* SWS_Can_00245, SWS_Can_00246 */
static void Can_InitAllControllers(uint32 CoreId)
{
    uint8                           Index = 0U;
    Std_ReturnType                  ReturnVal = (Std_ReturnType)E_NOT_OK;
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

    for (Index = 0U; Index < Can_ConfigPtr[CoreId]->CanControllerCounter; ++Index)
    {
        if (NULL_PTR != (Can_ConfigPtr[CoreId])->CanControllerConfigPtr[Index])
        {
            CanCtrlPtr = (Can_ConfigPtr[CoreId])->CanControllerConfigPtr[Index];
            if (TRUE == CanCtrlPtr->CanActiveStatus)
            {
                /* Set current baud Rate Index */
                Can_BaudrateIdConfig[Index] = CanCtrlPtr->CanDefaultBaudrateIndex;

                /* Reset current interrupt level */
                Can_DisableInterruptLevel[Index] = 0U;
                #if (CAN_ERROR_INJECTION_SUPPORT == STD_ON)
                    Can_EccInjectionStatus[Index] = FALSE;
                #endif
                ReturnVal = Can_InitController(Index, CanCtrlPtr->CanControllerOffset, CanCtrlPtr);
                if ((Std_ReturnType)E_OK == ReturnVal)
                {
                    Can_ControllerState[Index] = CAN_CS_STOPPED;
                }
                else
                {
                    break;
                }
            }
        }
    }

    if ((Std_ReturnType)E_NOT_OK == ReturnVal)
    {
        /* Reset Can controller status in case of any can controller init failed */
        for (Index = 0U; Index < Can_ConfigPtr[CoreId]->CanControllerCounter; ++Index)
        {
            if (NULL_PTR != (Can_ConfigPtr[CoreId])->CanControllerConfigPtr[Index])
            {
                Can_ControllerState[Index] = CAN_CS_UNINIT;
            }
        }
    }
    else
    {
        Can_DriverStatus[CoreId] = CAN_READY;
        (void)Can_DriverStatus[CoreId]; /* avoid compile warning if DET is disabled */
    }
}

/**
 * @brief      Checks whether data length and sdu are valid.
 *
 * @param[in]  ConfigPtr: Controller configuration.
 * @param[in]  HwConfigPtr: Hardware object configuration.
 * @param[in]  PduInfoPtr: Pointer to store the PDU info.
 *
 * @return     boolean
 * @retval     TRUE: Data length and sdu are valid.
 * @retval     FALSE: Data length or sdu is invalid.
 *
 */
/* SWS_Can_00218, SWS_Can_00486,SWS_Can_00505, SWS_Can_00503 */
static boolean Can_CheckPduInfo(const Can_ControllerConfigType *ConfigPtr,
                                const Can_HwObjConfigType      *HwConfigPtr,
                                const Can_PduType              *PduInfoPtr)
{

    boolean IsInvalidDlc = (boolean)FALSE;
    boolean ReturnVal = (boolean)FALSE;
    uint16  BaudrateId = 0U;

    BaudrateId = Can_BaudrateIdConfig[ConfigPtr->CanControllerId];

    if (TRUE == ConfigPtr->CanBaudratePtr[BaudrateId].CanFdEnable)
    {
        if ((PduInfoPtr->length > HwConfigPtr->CanPayloadLength) ||
            ((PduInfoPtr->length > 8U) &&
             (CAN_IDTYPE_FD_FRAME != (PduInfoPtr->id & CAN_IDTYPE_FD_FRAME))))
        {
            IsInvalidDlc = (boolean)TRUE;
        }
    }
    else
    {
        if (PduInfoPtr->length > 8U)
        {
            IsInvalidDlc = (boolean)TRUE;
        }
    }

    if (TRUE == IsInvalidDlc)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE,
                              (uint8)CAN_E_PARAM_DATA_LENGTH);
#endif
    }
    else
    {
        if ((NULL_PTR == PduInfoPtr->sdu) && (FALSE == HwConfigPtr->CanTriggerTransmitStatus))
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE,
                                  (uint8)CAN_E_PARAM_POINTER);
#endif
        }
        else
        {
            ReturnVal = (boolean)TRUE;
        }
    }

    return ReturnVal;
}

/**
 * @brief     Sets Controller to stop mode.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Controller transfers to stop mode success.
 * @retval    E_NOT_OK: Controller transfers to stop mode failed.
 *
 */
static Std_ReturnType Can_SetControllerToStopMode(const uint8 ControllerId, const uint8 HwChannel)
{
    Std_ReturnType                  ReturnVal;
    uint8                           HwObjIdx = 0U;
    const Can_HwObjConfigType      *CanHwObjPtr;
    uint8                           IdIndex = 0U;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];

    if (TRUE == Can_InterruptEnableStatus[ControllerId])
    {
        (void)Can_Drv_DisableInterrupts(HwChannel);
#if (STD_ON == CAN_ERROR_INTERRUPT_SUPPORT)
        if (TRUE == ConfigPtr->CanErrEnable)
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR, (boolean)FALSE);
    #if (STD_ON == CAN_FEATURE_HAS_FD)
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR_FAST, (boolean)FALSE);
    #endif
        }
#endif
#if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
        if (0U != (ConfigPtr->CanEccEnable & (uint32)CAN_HOST_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_HOST_MEM_ERR, (boolean)FALSE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_MEM_ERR, (boolean)FALSE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_COR_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_COR_MEM_ERR, (boolean)FALSE);
        }
#endif
#if (STD_ON == CAN_BUSOFF_INTERRUPT_SUPPORT)
        if (FALSE == ((ConfigPtr->CanProcessConfig) & CAN_BUSOFF_POLLING_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_BUS_OFF, (boolean)FALSE);
        }
#endif
    }
    for (HwObjIdx = 0U; HwObjIdx < ConfigPtr->CanHwObjectRefCount; HwObjIdx++)
    {
        CanHwObjPtr = (const Can_HwObjConfigType *)ConfigPtr->CanHwObjectPPtr[HwObjIdx];

        /* Abort current transmission */
        if (CAN_OBJ_TRANSMIT == CanHwObjPtr->CanObjectType)
        {
            for (IdIndex = 0U; IdIndex < CanHwObjPtr->CanHwObjectCount; IdIndex++)
            {
                (void)Can_Drv_AbortTransfer(HwChannel, CanHwObjPtr->CanHwBufferIndex + IdIndex);
            }
        }
        else
        {
            (void)Can_Drv_AbortTransfer(HwChannel, CanHwObjPtr->CanHwBufferIndex);
        }
    }
    ReturnVal = (Std_ReturnType)Can_Drv_SetStopMode(HwChannel);

    return ReturnVal;
}

/**
 * @brief     Sets controller to stop mode.
 *
 * @param[in] ControllerId : Controller id.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Controller transfers to stop mode success.
 * @retval    E_OK: Controller transfers to stop mode failed.
 *
 */
static Std_ReturnType Can_EnterStopMode(uint8 ControllerId)
{
    uint32                          CanCoreId = 0U;
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;

    CanCoreId = Can_GetCoreID();
    CanCtrlPtr = (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                        ->CanControllerConfigPtr[ControllerId]);
    switch (Can_ControllerState[ControllerId])
    {
        case CAN_CS_STARTED:
        {
            if ((Std_ReturnType)E_OK ==
                Can_SetControllerToStopMode(CanCtrlPtr->CanControllerId,
                                            CanCtrlPtr->CanControllerOffset))
            {
                Can_ControllerState[ControllerId] = CAN_CS_STOPPED;
                CanIf_ControllerModeIndication(CanCtrlPtr->CanInterfaceId, CAN_CS_STOPPED);
                ReturnStatus = E_OK;
            }
            break;
        }
        case CAN_CS_STOPPED:
        case CAN_CS_SLEEP:
        {
#if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Disable wakeup interrupt in case of state transition from SLEEP to STOP */
            if ((CAN_CS_SLEEP == Can_ControllerState[ControllerId]) &&
                (TRUE == CanCtrlPtr->CanWakeUpCanActiveStatus))
            {
                (void)Can_Drv_DisableSelfWakeup(CanCtrlPtr->CanControllerOffset);
            }
#endif
            Can_ControllerState[ControllerId] = CAN_CS_STOPPED;
            CanIf_ControllerModeIndication(CanCtrlPtr->CanInterfaceId, CAN_CS_STOPPED);
            ReturnStatus = E_OK;
            break;
        }
        default:
        {
            /* Nothing to do */
            break;
        }
    }

    return ReturnStatus;
}

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/**
 * @brief   Sets controller to sleep mode.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Controller transfers to sleep mode success.
 * @retval    E_NOT_OK: Controller transfers to sleep mode failed.
 *
 */
static Std_ReturnType Can_SetControllerToSleepMode(const uint8 ControllerId, const uint8 HwChannel)
{
    Std_ReturnType                  RetValue = E_OK;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];

    if (CAN_WAKE_POLLING_MASK != (ConfigPtr->CanProcessConfig & CAN_WAKE_POLLING_MASK))
    {
        RetValue = (Std_ReturnType)Can_Drv_EnableSelfWakeup(HwChannel);
    }

    return RetValue;
}
#endif

/*
 * @brief     Sets controller to sleep mode.
 *
 * @param[in] ControllerId: Controller id.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Controller transfers to sleep mode success.
 * @retval    E_NOT_OK: Controller transfers to sleep mode failed.
 *
 */
static Std_ReturnType Can_EnterSleepMode(uint8 ControllerId)
{
    uint32                          CanCoreId = 0U;
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;

    CanCoreId = Can_GetCoreID();
    CanCtrlPtr = (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                        ->CanControllerConfigPtr[ControllerId]);
    if (CAN_CS_STOPPED == Can_ControllerState[ControllerId])
    {
#if (CAN_WAKEUP_SUPPORT == STD_ON)
        if (TRUE == CanCtrlPtr->CanWakeUpCanActiveStatus)
        {
            (void)Can_SetControllerToSleepMode(CanCtrlPtr->CanControllerId,
                                               CanCtrlPtr->CanControllerOffset);
        }

#endif
        Can_ControllerState[ControllerId] = CAN_CS_SLEEP;
        CanIf_ControllerModeIndication(CanCtrlPtr->CanInterfaceId, CAN_CS_SLEEP);
        ReturnStatus = E_OK;
    }
    else if (CAN_CS_SLEEP == Can_ControllerState[ControllerId])
    {
        ReturnStatus = E_OK;
    }
    else
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
#endif
    }

    return ReturnStatus;
}

/**
 * @brief     Clears controller error state, enables controller and tries to recover from bus-off
 * state is possible.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Controller transfers to start mode success.
 * @retval    E_NOT_OK: Controller transfers to start mode failed.
 *
 */
static Std_ReturnType Can_SetControllerToStartMode(const uint8 ControllerId, const uint8 HwChannel)
{
    Can_Drv_ControllerStatus ReturnVal = (Can_Drv_ControllerStatus)E_NOT_OK;
#if ((CAN_ERROR_INTERRUPT_SUPPORT == STD_ON) || (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON) ||        \
     (CAN_ECC_INTERRUPT_SUPPORT == STD_ON))
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
#endif
    ReturnVal = Can_Drv_SetStartMode(HwChannel);

    /* Clear all error flags */
    Can_Drv_ClearErrorStatus(HwChannel, CAN_ALL_ERR_INT);
    if (TRUE == Can_InterruptEnableStatus[ControllerId])
    {
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        if (TRUE == ConfigPtr->CanErrEnable)
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR, (boolean)TRUE);
    #if (STD_ON == CAN_FEATURE_HAS_FD)
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR_FAST, (boolean)TRUE);
    #endif
        }
#endif
#if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
        if (0U != (ConfigPtr->CanEccEnable & CAN_HOST_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_HOST_MEM_ERR, (boolean)TRUE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_MEM_ERR, (boolean)TRUE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_COR_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_COR_MEM_ERR, (boolean)TRUE);
        }
#endif
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
        if (FALSE == ((ConfigPtr->CanProcessConfig) & CAN_BUSOFF_POLLING_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_BUS_OFF, TRUE);
        }
#endif
        (void)Can_Drv_EnableInterrupts(HwChannel);
    }

    if (CAN_DRV_SUCCESS == ReturnVal)
    {
        /* Try to recover from bus-off if possible */
        ReturnVal = Can_Drv_ManualBusOffRecovery(HwChannel);
    }

    return (Std_ReturnType)ReturnVal;
}

/**
 * @brief     Sets Controller to start mode.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    Std_ReturnType: Standard return Type.
 * @retval    E_OK: Controller transfers to start mode success.
 * @retval    E_NOT_OK: Controller transfers to start mode failed.
 *
 */
static Std_ReturnType Can_EnterStartMode(const uint8 ControllerId, const uint8 HwChannel)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    uint8                           HwObjIdx = 0U;
    const Can_HwObjConfigType      *CanHwObjPtr = NULL_PTR;
    Can_Drv_ControllerStatus        ReturnVal = CAN_DRV_ERROR;
    Can_Drv_MsgIdType               CanMsgIdType;

    for (HwObjIdx = 0U; HwObjIdx < ConfigPtr->CanHwObjectRefCount; HwObjIdx++)
    {
        CanHwObjPtr = (const Can_HwObjConfigType *)ConfigPtr->CanHwObjectPPtr[HwObjIdx];

        if (CAN_MSG_ID_STANDARD == CanHwObjPtr->CanIdMessageType)
        {
            CanMsgIdType = CAN_DRV_MSG_ID_STD;
        }
        else
        {
            CanMsgIdType = CAN_DRV_MSG_ID_EXT;
        }

        if (CAN_OBJ_RECEIVE == CanHwObjPtr->CanObjectType)
        {
            (void)Can_Drv_ConfigRxMb(HwChannel, CanHwObjPtr->CanHwBufferIndex, CanMsgIdType,
                                     CanHwObjPtr->CanHwFilterPtr->CanHwFilterCode);
        }
#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
        if (FALSE == CanHwObjPtr->CanHwUsesPolling)
        {
            switch (CanHwObjPtr->CanObjectType)
            {
                case CAN_OBJ_RECEIVE:
                {
                    (void)Can_Drv_Receive(HwChannel, CanHwObjPtr->CanHwBufferIndex, NULL_PTR,
                                          CanHwObjPtr->CanHwUsesPolling);
                    break;
                }
                case CAN_OBJ_FIFO:
                {
    #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
                    if (CAN_DRV_RXFIFO_DMA ==
                        ConfigPtr->CanHwChannelConfigPtr->CanHwConfigPtr->TransferType)
                    {
                        (void)Can_Drv_RxFIFO(HwChannel, ConfigPtr->DmaDstAddr);
                    }
                    else
    #endif
                    {
                        (void)Can_Drv_RxFIFO(HwChannel, NULL_PTR);
                    }
                    break;
                }
                default:
                {
                    /* Nothing to do */
                    break;
                }
            }
        }
#endif
    }

    if ((Std_ReturnType)E_OK == Can_SetControllerToStartMode(ControllerId, HwChannel))
    {
        ReturnVal = CAN_DRV_SUCCESS;
    }

    return (Std_ReturnType)ReturnVal;
}

/**
 * @brief     Transmits controller mode.
 *
 * @param[in] Controller: CAN controller for which the Status shall be changed
 * @param[in] Transition: Transition Value to request new CAN controller State
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Mode transition executed success.
 * @retval    E_NOT_OK: Mode transition executed failed.
 *
 */
/* SWS_Can_00409, SWS_Can_00384, SWS_Can_00263, SWS_Can_00267,SWS_Can_00290,  SWS_Can_00290,
 *SWS_Can_00405 SWS_Can_00411, SWS_Can_00199 */
static Std_ReturnType Can_ControllerModeTransition(uint8                   Controller,
                                                   Can_ControllerStateType Transition)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;

    CanCtrlPtr = (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                        ->CanControllerConfigPtr[Controller]);
    switch (Transition)
    {
        case CAN_CS_STARTED:
        {
            if (CAN_CS_STOPPED != Can_ControllerState[Controller])
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                      (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_TRANSITION);
#endif
            }
            else
            {
                if ((Std_ReturnType)E_OK == Can_EnterStartMode(CanCtrlPtr->CanControllerId,
                                                               CanCtrlPtr->CanControllerOffset))
                {
                    Can_ControllerState[Controller] = CAN_CS_STARTED;
                    CanIf_ControllerModeIndication(CanCtrlPtr->CanInterfaceId, CAN_CS_STARTED);
                    ReturnStatus = E_OK;
                }
            }
            break;
        }
        case CAN_CS_STOPPED:
        {
            ReturnStatus = Can_EnterStopMode(Controller);
            break;
        }
        case CAN_CS_SLEEP:
        {
            ReturnStatus = Can_EnterSleepMode(Controller);
            break;
        }
        default:
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                  (uint8)CAN_SID_SET_CONTROLLER_MODE,
                                  (uint8)CAN_E_PARAM_CONTROLLER);
#else
            /* Nothing to do */
#endif
            break;
        }
    }

    return ReturnStatus;
}

#if (CAN_MAINFUNCTION_MULTIPLE_WRITE == STD_ON)
/**
 * @brief     Performs the polling of TX confirmation when CAN_TX_PROCESSING is set to POLLING.
 *
 * @param[in] Index: Period transmit confirmation id.
 *
 * @return    None
 *
 */
static void Can_MainFunctionMultipleWrite(uint8 Index)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;
    Can_HwHandleType                HwObjIndex = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        HwObjIndex = (Can_ConfigPtr[CanCoreId])->CanFirstHTHIndex;
        while (HwObjIndex < Can_ConfigPtr[CanCoreId]->CanHardwareCounter)
        {
            CanControllerId = Can_ConfigPtr[CanCoreId]->CanHwObjIndexPtr[HwObjIndex];
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                /* Can_MainFunction_Write shall perform the polling */
                if ((TRUE == CanObjConfigPtr->CanActiveStatus) &&
                    (Index == (Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex])
                                  .CanMainFunctionRwPeriodIndex))
                {
                    Can_ExecutePollingWrite(
                        CanControllerId, CanObjConfigPtr->CanControllerOffset, HwObjIndex,
                        &(Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex]));
                }
            }
            HwObjIndex++;
        }
    }
}
#endif

#if (CAN_MAINFUNCTION_MULTIPLE_READ == STD_ON)
/**
 * @brief     Performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
 *
 * @param[in] Index: Period transmit confirmation id.
 *
 * @return    None
 *
 */
static void Can_MainFunctionMultipleRead(uint8 Index)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;
    Can_HwHandleType                HwObjIndex = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        while (HwObjIndex < Can_ConfigPtr[CanCoreId]->CanFirstHTHIndex)
        {
            CanControllerId = Can_ConfigPtr[CanCoreId]->CanHwObjIndexPtr[HwObjIndex];
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                /* Can_MainFunction_Write shall perform the polling */
                if ((TRUE == CanObjConfigPtr->CanActiveStatus) &&
                    (Index == (Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex])
                                  .CanMainFunctionRwPeriodIndex))
                {
                    Can_ExecutePollingRead(
                        CanControllerId, CanObjConfigPtr->CanControllerOffset, HwObjIndex,
                        &(Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex]));
                }
            }
            HwObjIndex++;
        }
    }
}
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/**
 * @brief     Configures baudrate.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel id.
 * @param[in] BaudId: Baudrate id.
 *
 * @return    Std_ReturnType:
 * @retval    E_OK: Baudrate configured successfully.
 * @retval    E_NOT_OK: Baudrate configured unsuccessfully.
 *
 */
static Std_ReturnType Can_ConfigBaudrate(const uint8 ControllerId, const uint8 HwChannel,
                                         uint16 BaudId)
{
    Std_ReturnType                  Ret = (Std_ReturnType)E_NOT_OK;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    Can_Drv_BitTimingType           CanBit;

    #if (CAN_FD_MODE_ENABLE == STD_ON)
    Can_Drv_BitTimingType CanFdBit;
    #endif

    CanBit.PropSeg = ConfigPtr->CanBaudratePtr[BaudId].CanBitRate.CanPropSeg;
    CanBit.PhaseSeg1 = ConfigPtr->CanBaudratePtr[BaudId].CanBitRate.CanPhaseSeg1;
    CanBit.PhaseSeg2 = ConfigPtr->CanBaudratePtr[BaudId].CanBitRate.CanPhaseSeg2;
    CanBit.PreDivider = ConfigPtr->CanBaudratePtr[BaudId].CanBitRate.CanPreDivider;
    CanBit.RJumpWidth = ConfigPtr->CanBaudratePtr[BaudId].CanBitRate.CanRJumpWidth;

    #if (CAN_FD_MODE_ENABLE == STD_ON)
    if (TRUE == ConfigPtr->CanBaudratePtr[BaudId].CanFdEnable)
    {
        (void)Can_Drv_SetFdArbBitTiming(HwChannel, &CanBit);

        /*set Fd Data bit */
        CanFdBit.PropSeg = ConfigPtr->CanBaudratePtr[BaudId].CanFdDataBitRate.CanPropSeg;
        CanFdBit.PhaseSeg1 = ConfigPtr->CanBaudratePtr[BaudId].CanFdDataBitRate.CanPhaseSeg1;
        CanFdBit.PhaseSeg2 = ConfigPtr->CanBaudratePtr[BaudId].CanFdDataBitRate.CanPhaseSeg2;
        CanFdBit.PreDivider = ConfigPtr->CanBaudratePtr[BaudId].CanFdDataBitRate.CanPreDivider;
        CanFdBit.RJumpWidth = ConfigPtr->CanBaudratePtr[BaudId].CanFdDataBitRate.CanRJumpWidth;

        (void)Can_Drv_SetFdDataBitTiming(HwChannel, &CanFdBit);

        (void)Can_Drv_SetFdTdc(HwChannel, ConfigPtr->CanBaudratePtr[BaudId].CanTransmitCompEnable,
                               ConfigPtr->CanBaudratePtr[BaudId].CanControllerSspOffset);
    }
    else
    {
    #endif
        (void)Can_Drv_SetStdBitTiming(HwChannel, &CanBit);
    #if (CAN_FD_MODE_ENABLE == STD_ON)
    }
    #endif
    (void)Can_Drv_SetTxArbitrationDelay(
        HwChannel, ConfigPtr->CanBaudratePtr[BaudId].CanControlTxArbitrationStartDelay);

    if (CAN_DRV_SUCCESS == Can_Drv_SetStopMode(HwChannel))
    {
        Ret = (Std_ReturnType)E_OK;
    }

    return Ret;
}
#endif

#if (CAN_TX_POLLING_SUPPORT == STD_ON)
/**
 * @brief     Performs the polling of TX confirmation when CAN_TX_PROCESSING is set to POLLING.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel id.
 * @param[in] HwObjId: Hardware object id.
 * @param[in] HwConfigPtr: Hardware object configuration.
 *
 * @return    None
 *
 */
static void Can_ExecutePollingWrite(const uint8 ControllerId, const uint8 HwChannel, uint8 HwObjId,
                                    const Can_HwObjConfigType *HwConfigPtr)
{
    Can_HwObjectConfigPtr[HwObjId] = HwConfigPtr;
    uint8                    ObjIndx = 0U;
    Can_Drv_ControllerStatus TempRet;

    for (ObjIndx = 0U; ObjIndx < HwConfigPtr->CanHwObjectCount; ObjIndx++)
    {
        if (CAN_DRV_STATE_TX ==
            ((Can_State[ControllerId])->Mb[HwConfigPtr->CanHwBufferIndex + ObjIndx].State))
        {
            Can_Drv_WriteMainFunction(HwChannel, HwConfigPtr->CanHwBufferIndex + ObjIndx);
            TempRet = Can_Drv_GetTransferStatus(HwChannel, HwConfigPtr->CanHwBufferIndex + ObjIndx);
            if (CAN_DRV_SUCCESS == TempRet)
            {
                CanIf_TxConfirmation(
                    Can_TxPduId[ControllerId][HwConfigPtr->CanHwBufferIndex + ObjIndx]);
            }
        }
    }
}
#endif

/**
 * @brief      Parses Rx data.
 *
 * @param[in]  ControllerId: Controller id.
 * @param[in]  HwObjId: Hardware object id.
 * @param[out] CanHwObjPtr: Pointer to store the hardware object.
 * @param[in]  CanIfPduInfoPtr: Pointer to store the PDU info.
 * @param[in]  MsgBufPtr: Pointer to store the Rx data.
 *
 * @return    None
 *
 */
/* SWS_Can_00423, SWS_Can_00501, SWS_Can_00279 */
static void Can_ParseRxData(const uint8 ControllerId, uint8 HwObjId, Can_HwType *CanHwObjPtr,
                            PduInfoType *CanIfPduInfoPtr, Can_Drv_MsgBufType *MsgBufPtr)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    const Can_HwObjConfigType      *HwConfigPtr = Can_HwObjectConfigPtr[HwObjId];
    CanHwObjPtr->CanId = MsgBufPtr->MsgId;

    if (((MsgBufPtr->Cs) & CAN_CS_IDE_MASK) != 0U)
    {
        CanHwObjPtr->CanId |= CAN_IDTYPE_EXTENDED;
    }

    if (CAN_OBJ_RECEIVE == HwConfigPtr->CanObjectType)
    {
        /* MB is being overwritten into a full buffer */
        if (CAN_RX_OVERRUN == (MsgBufPtr->Cs & CAN_CS_CODE_MASK))
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportRuntimeError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                         (uint8)CAN_SID_RECEIVE_HANDLER, (uint8)CAN_E_DATALOST);
#endif
        }
    }
    if (CAN_OBJ_FIFO != HwConfigPtr->CanObjectType)
    {
        if ((MsgBufPtr->Cs & CAN_CS_EDL_MASK) != 0U)
        {
            CanHwObjPtr->CanId |= CAN_IDTYPE_FD_FRAME;
        }
    }
#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
    if (TRUE == CAN_LPDU_CALLOUT_FUNC_CALLED((uint8)HwConfigPtr->CanHwObjectId, CanHwObjPtr->CanId,
                                             MsgBufPtr->DataLen, &MsgBufPtr->Data[0]))
    {
#endif
        CanHwObjPtr->Hoh = HwConfigPtr->CanHwObjectId;
        CanHwObjPtr->ControllerId = ConfigPtr->CanControllerId;
        CanIfPduInfoPtr->SduLength = MsgBufPtr->DataLen;
        CanIfPduInfoPtr->SduDataPtr = &MsgBufPtr->Data[0];
        CanIf_RxIndication(CanHwObjPtr, CanIfPduInfoPtr);
#if (CAN_LPDU_CALLOUT_SUPPORT == STD_ON)
    }
#endif
}

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
/**
 * @brief     Performs polling of RX normal mode indications when CAN_RX_PROCESSING is set to
 * POLLING.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwObjId: Hardware object id.
 *
 * @return    None
 *
 */
static void Can_ProcessRxNormalReceive(const uint8 ControllerId, const uint8 HwChannel,
                                       uint8 HwObjId)
{
    Can_Drv_MsgBufType         CanMsgBuf;
    Can_HwType                 HwInfo;
    PduInfoType                PduInfo;
    const Can_HwObjConfigType *HwConfigPtr = Can_HwObjectConfigPtr[HwObjId];
    (void)Can_Drv_Receive(HwChannel, HwConfigPtr->CanHwBufferIndex, &CanMsgBuf,
                          HwConfigPtr->CanHwUsesPolling);
    Can_Drv_ReadMainFunction(HwChannel, HwConfigPtr->CanHwBufferIndex);

    if (CAN_DRV_SUCCESS == Can_Drv_GetTransferStatus(HwChannel, HwConfigPtr->CanHwBufferIndex))
    {
        Can_ParseRxData(ControllerId, HwObjId, &HwInfo, &PduInfo, &CanMsgBuf);
    }
}

/**
 * @brief     Performs the polling of RX normal mode indications when CAN_RX_PROCESSING is set to
 * POLLING.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwObjId: Hardware object id.
 *
 * @return    None
 *
 */
static void Can_ProcessRxFifoReceive(const uint8 ControllerId, const uint8 HwChannel, uint8 HwObjId)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    const Can_HwObjConfigType      *HwConfigPtr = Can_HwObjectConfigPtr[HwObjId];
    Can_Drv_MsgBufType              CanMsgBuf;
    Can_HwType                      HwInfo;
    PduInfoType                     PduInfo;
    uint8                           ObjIdx = 0U;
    boolean                         ReturnVal = (boolean)FALSE;
    boolean                         TempRet = (boolean)FALSE;
    Can_Drv_ControllerStatus        TempStatus;

    ReturnVal = Can_Drv_GetMbInterruptFlag(HwChannel, CAN_DRV_RXFIFO_FRAME_AVAILABLE);

    for (ObjIdx = 0U; ((ObjIdx < ConfigPtr->CanHwObjectRefCount) && (TRUE == ReturnVal)); ObjIdx++)
    {
        TempRet = Can_Drv_GetMbInterruptFlag(HwChannel, CAN_DRV_RXFIFO_WARNING);
        /* Check  Fifo Warning */
        if (TRUE == TempRet)
        {
            if (NULL_PTR != (ConfigPtr->CanRxFifoConfigPtr)->CanWarnNotify)
            {
                (void)((ConfigPtr->CanRxFifoConfigPtr)->CanWarnNotify());
            }
            Can_Drv_ClearMbIntStatus(HwChannel, CAN_DRV_RXFIFO_WARNING);
        }
        TempRet = Can_Drv_GetMbInterruptFlag(HwChannel, CAN_DRV_RXFIFO_OVERFLOW);
        /* Check  Over Flow */
        if (TRUE == TempRet)
        {
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportRuntimeError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                         (uint8)CAN_SID_RECEIVE_HANDLER, (uint8)CAN_E_DATALOST);
    #endif
            if (NULL_PTR != (ConfigPtr->CanRxFifoConfigPtr)->CanOverFlowNotify)
            {
                (void)((ConfigPtr->CanRxFifoConfigPtr)->CanOverFlowNotify());
            }
            Can_Drv_ClearMbIntStatus(HwChannel, CAN_DRV_RXFIFO_OVERFLOW);
        }

        (void)Can_Drv_RxFIFO(HwChannel, &CanMsgBuf);
        Can_Drv_ReadMainFunction(HwChannel, HwConfigPtr->CanHwBufferIndex);

        TempStatus = Can_Drv_GetTransferStatus(HwChannel, HwConfigPtr->CanHwBufferIndex);
        if (CAN_DRV_SUCCESS == TempStatus)
        {
            Can_ParseRxData(ControllerId, HwObjId, &HwInfo, &PduInfo, &CanMsgBuf);
            if (NULL_PTR != (ConfigPtr->CanRxFifoConfigPtr)->CanAvailNotify)
            {
                (void)((ConfigPtr->CanRxFifoConfigPtr)->CanAvailNotify());
            }
        }
        ReturnVal = Can_Drv_GetMbInterruptFlag(HwChannel, CAN_DRV_RXFIFO_FRAME_AVAILABLE);
    }
    (void)ReturnVal;
}
#endif

#if (CAN_RX_POLLING_SUPPORT == STD_ON)
/**
 * @brief     Performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwObjId: Hardware object id.
 * @param[in] HwConfigPtr: Hardware object configuration.
 *
 * @return    None
 *
 */
static void Can_ExecutePollingRead(const uint8 ControllerId, const uint8 HwChannel, uint8 HwObjId,
                                   const Can_HwObjConfigType *HwConfigPtr)
{
    Can_HwObjectConfigPtr[HwObjId] = HwConfigPtr;

    if (FALSE == Can_Drv_CheckStoppedMode(HwChannel))
    {
        if (CAN_OBJ_RECEIVE == HwConfigPtr->CanObjectType)
        {
            Can_ProcessRxNormalReceive(ControllerId, HwChannel, HwObjId);
        }
        else if (CAN_OBJ_FIFO == HwConfigPtr->CanObjectType)
        {
            Can_ProcessRxFifoReceive(ControllerId, HwChannel, HwObjId);
        }
        else
        {
            /* Nothing to do */
        }
    }
}
#endif

/**
 * @brief        Performs the Polling Controller Mode Transitions
 *
 * @param[in]    ControllerId: Controller id.
 * @param[in]    HwChannel: Hardware channel.
 * @param[inout] ControllerStatePtr: Pointer to store the controller state.
 *
 * @return       None
 *
 */
static void Can_ExecutePollingMode(const uint8 ControllerId, const uint8 HwChannel,
                                   Can_ControllerStateType *ControllerStatePtr)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];

    if (CAN_CS_STARTED == *ControllerStatePtr)
    {
        if (FALSE == Can_Drv_CheckStartedMode(HwChannel))
        {
            *ControllerStatePtr = CAN_CS_STOPPED;
            CanIf_ControllerModeIndication(ConfigPtr->CanInterfaceId, CAN_CS_STOPPED);
        }
    }
    else if (CAN_CS_STOPPED == *ControllerStatePtr)
    {
        if (TRUE == Can_Drv_CheckStartedMode(HwChannel))
        {
            *ControllerStatePtr = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(ConfigPtr->CanInterfaceId, CAN_CS_STARTED);
        }
    }
    else
    {
        /* Nothing to do */
    }
}

#if (CAN_MB_INTERRUPT_SUPPORT == STD_ON)
/**
 * @brief     Processes Tx interrupt
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwConfigPtr: Hardware object configuration.
 * @param[in] MbIdx: Message buffer id.
 *
 * @return    None
 *
 */
static void Can_ProcessTxMsgBuffer(const uint8 ControllerId, const Can_HwObjConfigType *HwConfigPtr,
                                   uint8 MbIdx)
{
    Can_HwHandleType HwObjIndex = 0U;
    HwObjIndex = Can_HwToMapMbIndex[ControllerId][MbIdx];

    if ((CAN_HWOBJ_UNMAPPED != HwObjIndex) && (FALSE == HwConfigPtr[HwObjIndex].CanHwUsesPolling))
    {
        if (CAN_OBJ_TRANSMIT == HwConfigPtr[HwObjIndex].CanObjectType)
        {
            CanIf_TxConfirmation(Can_TxPduId[ControllerId][MbIdx]);
        }
    }
}

/**
 * @brief     Processes Rx interrupt.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwConfigPtr: Hardware object configuration.
 * @param[in] MbIdx: Message buffer id.
 *
 * @return    None
 *
 */
static void Can_ProcessRxMsgBuffer(const uint8 ControllerId, const uint8 HwChannel,
                                   const Can_HwObjConfigType *HwConfigPtr, uint8 MbIdx)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    Can_Drv_MsgBufType             *CanMsgBuf = NULL_PTR;
    Can_HwType                      HwInfo;
    PduInfoType                     PduInfo;
    Can_HwHandleType                HwObjIndex = 0U;
    const Can_HwObjConfigType      *HwObjPtr = NULL_PTR;

    Can_HwObjectType TempHwObj;
    HwObjIndex = Can_HwToMapMbIndex[ControllerId][MbIdx];

    if ((CAN_HWOBJ_UNMAPPED != HwObjIndex) && (FALSE == HwConfigPtr[HwObjIndex].CanHwUsesPolling))
    {
        HwObjPtr = &HwConfigPtr[HwObjIndex];
        TempHwObj = HwObjPtr->CanObjectType;
        if (CAN_OBJ_RECEIVE == TempHwObj)
        {
            CanMsgBuf = (Can_State[ControllerId])->Mb[HwObjPtr->CanHwBufferIndex].MbMessagePtr;
            Can_ParseRxData(ControllerId, HwObjPtr->CanHwObjectId, &HwInfo, &PduInfo, CanMsgBuf);
            /* ready to receive in next time */
            (void)Can_Drv_Receive(HwChannel, HwObjPtr->CanHwBufferIndex, NULL_PTR,
                                  HwObjPtr->CanHwUsesPolling);
        }
        else if (CAN_OBJ_FIFO == TempHwObj)
        {
            if ((uint8)CAN_DRV_RXFIFO_OVERFLOW == MbIdx)
            {
                if (NULL_PTR != (ConfigPtr->CanRxFifoConfigPtr)->CanOverFlowNotify)
                {
                    (void)((ConfigPtr->CanRxFifoConfigPtr)->CanOverFlowNotify());
                }
            }
            else if ((uint8)CAN_DRV_RXFIFO_WARNING == MbIdx)
            {
                if (NULL_PTR != (ConfigPtr->CanRxFifoConfigPtr)->CanWarnNotify)
                {
                    (void)((ConfigPtr->CanRxFifoConfigPtr)->CanWarnNotify());
                }
            }
            else
            {
                CanMsgBuf = (Can_State[ControllerId])->Mb[HwObjPtr->CanHwBufferIndex].MbMessagePtr;
                Can_ParseRxData(ControllerId, HwObjPtr->CanHwObjectId, &HwInfo, &PduInfo,
                                CanMsgBuf);
                if (NULL_PTR != (ConfigPtr->CanRxFifoConfigPtr)->CanAvailNotify)
                {
                    (void)((ConfigPtr->CanRxFifoConfigPtr)->CanAvailNotify());
                }
                (void)Can_Drv_RxFIFO(HwChannel, NULL_PTR);
            }
        }
        else
        {
            /* Nothing to do */
        }
    }
}
#endif

#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
/**
 * @brief     process Rx via Dma mode(rx FIFO interrupt).
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwConfigPtr: Hardware objection configuration.
 * @param[in] IntType: Interrupt type.
 *
 * @return    None
 *
 */
static void Can_ProcessRxDma(const uint8 ControllerId, const uint8 HwChannel,
                             const Can_HwObjConfigType *HwConfigPtr, Can_Drv_IntType IntType)
{
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
    Can_HwType                      HwInfo;
    PduInfoType                     PduInfo;
    Can_HwHandleType                HwObjIndex = 0U;
    const Can_HwObjConfigType      *HwObjPtr;

    HwObjIndex = Can_HwToMapMbIndex[ControllerId][CAN_DRV_RXFIFO_START_INDEX];

    if ((CAN_HWOBJ_UNMAPPED != HwObjIndex) && (FALSE == HwConfigPtr[HwObjIndex].CanHwUsesPolling))
    {
        HwObjPtr = &HwConfigPtr[HwObjIndex];
        if (CAN_DRV_DMA_COMPLETE == IntType)
        {
            Can_ParseRxData(ControllerId, HwObjPtr->CanHwObjectId, &HwInfo, &PduInfo,
                            &ConfigPtr->DmaDstAddr[0]);

            /* ready to receive in next time */
            (void)Can_Drv_RxFIFO(HwChannel, ConfigPtr->DmaDstAddr);
        }
        else if (CAN_DRV_DMA_ERROR == IntType)
        {
            if (NULL_PTR != ConfigPtr->CanDmaErrorNotify)
            {
                ConfigPtr->CanDmaErrorNotify();
            }

            (void)Can_Drv_RxFIFO(HwChannel, ConfigPtr->DmaDstAddr);
        }
        else
        {
            /* Nothing to do */
        }
    }
}
#endif

#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
#if (CAN_SEC_EVENT_REPORT_SUPPORT == STD_ON)
/**
 * @brief     Notifies error to Can interface module.
 *
 * @param[in] CanInterfaceId: Can interface id
 * @param[in] Data: Error status.
 *
 * @return    None
 *
 */
static void Can_ReportSecurityEvents(uint8 CanInterfaceId, uint32 Data)
{
    if (((CAN_STFERR_MASK & Data) != 0U) || ((CAN_STFERR_FAST_MASK & Data) != 0U))
    {
        CanIf_ErrorNotification(CanInterfaceId, CAN_ERROR_CHECK_STUFFING_FAILED);
    }

    if (((CAN_FRAMERR_MASK & Data) != 0U) || ((CAN_FRAMERR_FAST_MASK & Data) != 0U))
    {
        CanIf_ErrorNotification(CanInterfaceId, CAN_ERROR_CHECK_FORM_FAILED);
    }

    if (((CAN_CRCERR_MASK & Data) != 0U) || ((CAN_CRCERR_FAST_MASK & Data) != 0U))
    {
        CanIf_ErrorNotification(CanInterfaceId, CAN_ERROR_CHECK_CRC_FAILED);
    }

    if ((CAN_ACKERR_MASK & Data) != 0U)
    {
        CanIf_ErrorNotification(CanInterfaceId, CAN_ERROR_CHECK_ACK_FAILED);
    }

    if (((CAN_BIT0ERR_MASK & Data) != 0U) || ((CAN_BIT0ERR_FAST_MASK & Data) != 0U))
    {
        CanIf_ErrorNotification(CanInterfaceId, CAN_ERROR_BIT_MONITORING0);
    }

    if (((CAN_BIT1ERR_MASK & Data) != 0U) || ((CAN_BIT1ERR_FAST_MASK & Data) != 0U))
    {
        CanIf_ErrorNotification(CanInterfaceId, CAN_ERROR_BIT_MONITORING1);
    }
}
#endif
#endif

/**
 * @brief        Sends out message.
 *
 * @param[in]    ControllerId: Controller id.
 * @param[in]    HwChannel: Hardware channel.
 * @param[in]    HwObjId: Hardware object id.
 * @param[inout] MessageInfoPtr: Pointer to store the message info.
 * @param[in]    Index: Message buffer id.
 * @param[in]    PduInfoPtr: Pointer to store the PDU info.
 *
 * @return       Can_Drv_ControllerStatus
 * @retval       CAN_DRV_SUCCESS: Message sent out successfully.
 * @retval       CAN_DRV_ERROR : Message sent out unsuccessfully.
 * @retval       CAN_DRV_ENTER_BUSY: The message buffer is in invalid state.
 *
 */
/* SRS_Can_01009 */
static Can_Drv_ControllerStatus Can_SendMessage(const uint8 ControllerId, const uint8 HwChannel,
                                                uint8                    HwObjId,
                                                Can_Drv_MessageInfoType *MessageInfoPtr,
                                                uint8 Index, const Can_PduType *PduInfoPtr)
{
    Can_Drv_ControllerStatus   ReturnVal = CAN_DRV_ERROR;
    const Can_HwObjConfigType *HwConfigPtr = Can_HwObjectConfigPtr[HwObjId];
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
    PduInfoType    CanIfPduInfo;
    uint8          Data[64U];
    Std_ReturnType TempRet;
#endif

#if ((CAN_TX_POLLING_SUPPORT == STD_ON) || (CAN_MB_INTERRUPT_SUPPORT == STD_ON))
    Can_TxPduId[ControllerId][Index] = PduInfoPtr->swPduHandle;
#endif
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
    if ((TRUE == HwConfigPtr->CanTriggerTransmitStatus) && (NULL_PTR == PduInfoPtr->sdu))
    {
        CanIfPduInfo.SduDataPtr = Data;
        CanIfPduInfo.SduLength = (PduLengthType)HwConfigPtr->CanPayloadLength;
        TempRet = CanIf_TriggerTransmit(PduInfoPtr->swPduHandle, &CanIfPduInfo);
        if ((Std_ReturnType)E_OK == TempRet)
        {
            MessageInfoPtr->DataLen = (uint8)CanIfPduInfo.SduLength;
            ReturnVal = Can_Drv_SendData(HwChannel, Index, MessageInfoPtr,
                                         HwConfigPtr->CanHwUsesPolling, PduInfoPtr->id, Data);
        }
        else
        {
            ReturnVal = CAN_DRV_ERROR;
        }
    }
    else
    {
#endif
        ReturnVal =
            Can_Drv_SendData(HwChannel, Index, MessageInfoPtr, HwConfigPtr->CanHwUsesPolling,
                             PduInfoPtr->id, PduInfoPtr->sdu);
#if (CAN_TRIGGER_TRANSMIT_USED == STD_ON)
    }
#endif
    return ReturnVal;
}

/**
 * @brief     Sends out PDU from CanIf.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwObjId: Hardware object id.
 * @param[in] HwConfigPtr: Hardware object configuration.
 * @param[in] PduPtr: Pointer to store the PDU info.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: PDU sent out successfully.
 * @retval    E_NOT_OK: PDU sent out unsuccessfully.
 *
 */
static Std_ReturnType Can_SendPdu(const uint8 ControllerId, const uint8 HwChannel,
                                  Can_HwHandleType HwObjId, const Can_HwObjConfigType *HwConfigPtr,
                                  const Can_PduType *PduPtr)
{
    Can_Drv_MessageInfoType  MessageInfo;
    Can_Drv_ControllerStatus ReturnVal = CAN_DRV_ERROR;
    uint8                    ObjIndx = 0U;
#if (STD_ON == CAN_FEATURE_HAS_FD)
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
#endif
    Can_HwObjectConfigPtr[HwObjId] = HwConfigPtr;

    if (CAN_OBJ_TRANSMIT == HwConfigPtr->CanObjectType)
    {
        MessageInfo.IdType =
            ((PduPtr->id & CAN_IDTYPE_EXTENDED) != 0U) ? CAN_DRV_MSG_ID_EXT : CAN_DRV_MSG_ID_STD;
        MessageInfo.DataLen = PduPtr->length;

#if (STD_ON == CAN_FEATURE_HAS_FD)
        MessageInfo.FdPadding = HwConfigPtr->CanFdPaddingValue;
        MessageInfo.FdEn = ((PduPtr->id & CAN_IDTYPE_FD_FRAME) != 0U) ? TRUE : FALSE;
    #if (CAN_SET_BAUDRATE_API == STD_ON)
        MessageInfo.BrsEn =
            ConfigPtr->CanBaudratePtr[Can_BaudrateIdConfig[ControllerId]].CanBitRateSwitch;
    #else
        MessageInfo.BrsEn = ConfigPtr->CanBaudratePtr[0U].CanBitRateSwitch;
    #endif
#endif
        MessageInfo.RemoteFlag = (boolean)FALSE;

        do
        {
            ReturnVal =
                Can_Drv_GetTransferStatus(HwChannel, HwConfigPtr->CanHwBufferIndex + ObjIndx);
            if (CAN_DRV_SUCCESS == ReturnVal)
            {
                ReturnVal = Can_SendMessage(ControllerId, HwChannel, (uint8)HwObjId, &MessageInfo,
                                            HwConfigPtr->CanHwBufferIndex + ObjIndx, PduPtr);
            }
            ObjIndx++;
        }
        while ((ObjIndx < HwConfigPtr->CanHwObjectCount) && (CAN_BUSY == (uint8)ReturnVal));
    }

    if ((CAN_DRV_SUCCESS != ReturnVal) && (CAN_BUSY != (uint8)ReturnVal))
    {
        ReturnVal = CAN_DRV_ERROR;
    }

    return (Std_ReturnType)ReturnVal;
}

/**
 * @brief     Enables controller interrupts.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    None
 *
 */
static void Can_ProcessEnableControllerInterrupts(const uint8 ControllerId, const uint8 HwChannel)
{
#if ((CAN_ERROR_INTERRUPT_SUPPORT == STD_ON) || (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON) ||        \
     (CAN_ECC_INTERRUPT_SUPPORT == STD_ON))
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
#endif
    if (FALSE == Can_InterruptEnableStatus[ControllerId])
    {
        (void)Can_Drv_EnableInterrupts(HwChannel);
#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
        if (TRUE == ConfigPtr->CanErrEnable)
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR, (boolean)TRUE);
    #if (STD_ON == CAN_FEATURE_HAS_FD)
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR_FAST, (boolean)TRUE);
    #endif
        }
#endif
#if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
        if (0U != (ConfigPtr->CanEccEnable & CAN_HOST_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_HOST_MEM_ERR, (boolean)TRUE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_MEM_ERR, (boolean)TRUE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_COR_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_COR_MEM_ERR, (boolean)TRUE);
        }
#endif
#if (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON)
        if (FALSE == ((ConfigPtr->CanProcessConfig) & CAN_BUSOFF_POLLING_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_BUS_OFF, (boolean)TRUE);
        }
#endif
        Can_InterruptEnableStatus[ControllerId] = (boolean)TRUE;
    }
}

/**
 * @brief     Disables controller interrupts.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    None
 *
 */
static void Can_ProcessDisableControllerInterrupts(const uint8 ControllerId, const uint8 HwChannel)
{
#if ((CAN_ERROR_INTERRUPT_SUPPORT == STD_ON) || (CAN_BUSOFF_INTERRUPT_SUPPORT == STD_ON) ||        \
     (CAN_ECC_INTERRUPT_SUPPORT == STD_ON))
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
#endif
    if (TRUE == Can_InterruptEnableStatus[ControllerId])
    {
        (void)Can_Drv_DisableInterrupts(HwChannel);
#if (STD_ON == CAN_ERROR_INTERRUPT_SUPPORT)
        if (TRUE == ConfigPtr->CanErrEnable)
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR, (boolean)FALSE);
    #if (STD_ON == CAN_FEATURE_HAS_FD)
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_ERR_FAST, (boolean)FALSE);
    #endif
        }
#endif
#if (STD_ON == CAN_ECC_INTERRUPT_SUPPORT)
        if (0U != (ConfigPtr->CanEccEnable & CAN_HOST_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_HOST_MEM_ERR, (boolean)FALSE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_MEM_ERR, (boolean)FALSE);
        }
        if (0U != (ConfigPtr->CanEccEnable & CAN_COR_MEM_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_COR_MEM_ERR, (boolean)FALSE);
        }
#endif
#if (STD_ON == CAN_BUSOFF_INTERRUPT_SUPPORT)
        if (FALSE == ((ConfigPtr->CanProcessConfig) & CAN_BUSOFF_POLLING_MASK))
        {
            (void)Can_Drv_ConfigErrorInterrupt(HwChannel, CAN_DRV_INT_BUS_OFF, FALSE);
        }
#endif
        Can_InterruptEnableStatus[ControllerId] = (boolean)FALSE;
    }
}

/**
 * @brief     Reads controller current state.
 *
 * @param[in] ControllerId: Controller id.
 * @param[in] HwChannel: Hardware channel.
 *
 * @return    Can_ErrorStateType
 * @retval    CAN_ERRORSTATE_ACTIVE: Error active.
 * @retval    CAN_ERRORSTATE_PASSIVE: Error passive.
 * @retval    CAN_ERRORSTATE_BUSOFF: Bus off.
 *
 */
static Can_ErrorStateType Can_GetControllerState(const uint8 ControllerId, const uint8 HwChannel)
{
    Can_ErrorStateType ReturnVal = CAN_ERRORSTATE_ACTIVE;
#if (STD_ON == CAN_SEC_EVENT_REPORT_SUPPORT)
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];
#endif
    uint32 Temp;

#if (STD_ON == CAN_SEC_EVENT_REPORT_SUPPORT)
    uint32 RxCount = 0u;
    uint32 TxCount = 0u;
    RxCount = Can_Drv_GetControllerRxErrorCounter(HwChannel);
    TxCount = Can_Drv_GetControllerTxErrorCounter(HwChannel);
#endif
    Temp = Can_Drv_GetControllerErrorState(HwChannel);

    if (0x00U == Temp)
    {
        ReturnVal = CAN_ERRORSTATE_ACTIVE;
    }
    else if (0x01U == Temp)
    {
        ReturnVal = CAN_ERRORSTATE_PASSIVE;
#if (STD_ON == CAN_SEC_EVENT_REPORT_SUPPORT)
        CanIf_ControllerErrorStatePassive(ConfigPtr->CanInterfaceId, (uint16)RxCount,
                                          (uint16)TxCount);
#endif
    }
    else
    {
        ReturnVal = CAN_ERRORSTATE_BUSOFF;
    }

    return ReturnVal;
}

#if (STD_ON == CAN_ABORT_HW_OBJECT_SEND_API)
/**
 * @brief    Cancels transfer of pending messages.
 *
 * @param[in] HwChannel: Hardware channel.
 * @param[in] HwConfigPtr: Hardware object configuration.
 *
 * @return    None
 *
 */
static void Can_CancelTransfer(const uint8 HwChannel, const Can_HwObjConfigType *HwConfigPtr)
{
    uint8 IdIndex = 0;
    for (IdIndex = 0U; IdIndex < HwConfigPtr->CanHwObjectCount; IdIndex++)
    {
        (void)Can_Drv_AbortTransfer(HwChannel, HwConfigPtr->CanHwBufferIndex + IdIndex);
    }
}
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

/**
 * @brief     This function initializes the module.
 *
 * @param[in] Config: Pointer to driver configuration
 *
 * @return    None
 *
 */
/* SWS_Can_00174,  CAN177, SWS_Can_00408*/
void Can_Init(const Can_ConfigType *Config)
{
    uint32 CanCoreId = Can_GetCoreID();

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInit(Config))
    {
#endif
#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
        Can_ConfigPtr[CanCoreId] = Can_PreDefinedConfigPtr[CanCoreId];
#else
    Can_ConfigPtr[CanCoreId] = Config;
#endif

        if (FALSE == Can_CheckControllerBusy(CanCoreId))
        {
            Can_InitAllControllers(CanCoreId);
        }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
 * @brief     This function de-initializes the module.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
/* SWS_Can_91011, SWS_Can_91012, SWS_Can_91009, SWS_Can_91010 */
void Can_DeInit(void)
{
    uint8                           CtrlId = 0U;
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckDeinit())
    {
#endif
        Can_DriverStatus[CanCoreId] = CAN_UNINIT;
        (void)Can_DriverStatus[CanCoreId]; /* avoid compile warning if DET is disabled */
        for (CtrlId = 0U; CtrlId < Can_ConfigPtr[CanCoreId]->CanControllerCounter; CtrlId++)
        {
            if (NULL_PTR != (Can_ConfigPtr[CanCoreId])->CanControllerConfigPtr[CtrlId])
            {
                CanCtrlPtr = (Can_ConfigPtr[CanCoreId])->CanControllerConfigPtr[CtrlId];
                if (TRUE == CanCtrlPtr->CanActiveStatus)
                {
                    Can_ControllerState[CtrlId] = CAN_CS_UNINIT;
                    (void)Can_Drv_Deinit(CanCtrlPtr->CanControllerOffset);
                }
            }
        }

        Can_ConfigPtr[CanCoreId] = NULL_PTR;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    }

#endif
}

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
/* SWS_Can_00492, SWS_Can_00494, SWS_Can_00493, SWS_Can_00256 */
Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID)
{
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;
    uint32                          CanCoreId = Can_GetCoreID();

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_SET_BAUDRATE))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_SET_BAUDRATE, Controller))
        {
            if (TRUE == Can_CheckSetBaudrate(Controller, BaudRateConfigID))
            {
    #endif
                Can_BaudrateIdConfig[Controller] = BaudRateConfigID;
                CanCtrlPtr =
                    (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                           ->CanControllerConfigPtr[Controller]);
                ReturnStatus = Can_ConfigBaudrate(
                    CanCtrlPtr->CanControllerId, CanCtrlPtr->CanControllerOffset, BaudRateConfigID);
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif
    return ReturnStatus;
}
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
/* SWS_Can_00177 */
void Can_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckGetVersionInfo(versioninfo))
    {
    #endif
        versioninfo->vendorID = (uint16)CAN_VENDOR_ID;
        versioninfo->moduleID = (uint16)CAN_MODULE_ID;
        versioninfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION;
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}
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
/* SWS_Can_00198, SWS_Can_00199 */
Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_SET_CONTROLLER_MODE))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_SET_CONTROLLER_MODE, Controller))
        {
#endif
            ReturnStatus = Can_ControllerModeTransition(Controller, Transition);
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
    return ReturnStatus;
}

/**
 * @brief     This function disables all interrupts for this CAN controller.
 *
 * @param[in] Controller: CAN controller for which interrupts shall be disabled.
 *
 * @return    None
 *
 */
/*SWS_Can_00205, SWS_Can_00206,SWS_Can_00202, SWS_Can_00049 */
void Can_DisableControllerInterrupts(uint8 Controller)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_DISABLE_CONTROLLER_INTERRUPTS))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, Controller))
        {
#endif
            CanCtrlPtr =
                (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                       ->CanControllerConfigPtr[Controller]);

            SchM_Enter_Can_DisableIntGlobal();
            Can_DisableInterruptLevel[Controller] += 1U;
            SchM_Exit_Can_DisableIntGlobal();

            Can_ProcessDisableControllerInterrupts(CanCtrlPtr->CanControllerId,
                                                   CanCtrlPtr->CanControllerOffset);
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

/**
 * @brief      This function enables all allowed interrupts.
 *
 * @param[in]  Controller: CAN controller for which interrupts shall be re-enabled.
 *
 * @return     None
 *
 */
/* SWS_Can_00209,  SWS_Can_00210, SWS_Can_00202, SWS_Can_00208 */
void Can_EnableControllerInterrupts(uint8 Controller)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_ENABLE_CONTROLLER_INTERRUPTS))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, Controller))
        {
#endif
            CanCtrlPtr =
                (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                       ->CanControllerConfigPtr[Controller]);

            SchM_Enter_Can_DisableIntGlobal();
            if (Can_DisableInterruptLevel[Controller] > 0U)
            {
                Can_DisableInterruptLevel[Controller] -= 1U;
            }
            SchM_Exit_Can_DisableIntGlobal();

            if (0U == Can_DisableInterruptLevel[Controller])
            {
                Can_ProcessEnableControllerInterrupts(CanCtrlPtr->CanControllerId,
                                                      CanCtrlPtr->CanControllerOffset);
            }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

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
/* SWS_Can_00362, SWS_Can_00363, SWS_Can_00361 */
Std_ReturnType Can_CheckWakeup(uint8 Controller)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;
    #endif

    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    CanCtrlPtr = (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                        ->CanControllerConfigPtr[Controller]);
    #endif

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_CHECK_WAKEUP))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_CHECK_WAKEUP, Controller))
        {
    #endif
            if (TRUE == Can_SelfWakeupStatus[Controller])
            {
                Can_SelfWakeupStatus[Controller] = (boolean)FALSE;
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
                if (TRUE == CanCtrlPtr->CanWakeUpCanActiveStatus)
                {
                    EcuM_SetWakeupEvent(CanCtrlPtr->CanWakeUpSourceId);
                }

    #endif
                /* Controller is in WakeUp State. */
                ReturnStatus = (Std_ReturnType)E_OK;
            }
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif

    return ReturnStatus;
}
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
/*SWS_Can_91005, SWS_Can_91006,  SWS_Can_91007 */
Std_ReturnType Can_GetControllerErrorState(uint8 Controller, Can_ErrorStateType *ErrorStatePtr)
{
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_GET_CONTROLLER_ERROR_STATE))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_GET_CONTROLLER_ERROR_STATE, Controller))
        {
            if (TRUE == Can_CheckGetControllerErrorState(ErrorStatePtr))
            {
#endif
                CanCtrlPtr =
                    (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                           ->CanControllerConfigPtr[Controller]);
                *ErrorStatePtr = Can_GetControllerState(CanCtrlPtr->CanControllerId,
                                                        CanCtrlPtr->CanControllerOffset);
                ReturnStatus = E_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif

    return ReturnStatus;
}

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
/* SWS_Can_00512, SWS_Can_00513, SWS_Can_00514 */
Std_ReturnType Can_GetControllerRxErrorCounter(uint8 Controller, uint8 *RxErrorCounterPtr)
{
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, Controller))
        {
            if (TRUE == Can_CheckGetControllerErrorCounter(
                            (uint8)CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, RxErrorCounterPtr))
            {
#endif
                CanCtrlPtr =
                    (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                           ->CanControllerConfigPtr[Controller]);
                *RxErrorCounterPtr =
                    (uint8)Can_Drv_GetControllerRxErrorCounter(CanCtrlPtr->CanControllerOffset);
                ReturnStatus = (Std_ReturnType)E_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif

    return ReturnStatus;
}

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
/* SWS_Can_00517, SWS_Can_00518, SWS_Can_00519  */
Std_ReturnType Can_GetControllerTxErrorCounter(uint8 Controller, uint8 *TxErrorCounterPtr)
{
    /* Variable of return Status. */
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanCtrlPtr = NULL_PTR;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, Controller))
        {
            if (TRUE == Can_CheckGetControllerErrorCounter(
                            (uint8)CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, TxErrorCounterPtr))
            {
#endif
                CanCtrlPtr =
                    (const Can_ControllerConfigType *)(Can_ConfigPtr[CanCoreId]
                                                           ->CanControllerConfigPtr[Controller]);
                *TxErrorCounterPtr =
                    (uint8)Can_Drv_GetControllerTxErrorCounter(CanCtrlPtr->CanControllerOffset);

                ReturnStatus = (Std_ReturnType)E_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif

    return ReturnStatus;
}

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
/*SWS_Can_91016, SWS_Can_91018, SWS_Can_91017 */
Std_ReturnType Can_GetControllerMode(uint8 Controller, Can_ControllerStateType *ControllerModePtr)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_GET_CONTROLLER_MODE))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_GET_CONTROLLER_MODE, Controller))
        {
            if (TRUE == Can_CheckGetControllerMode(ControllerModePtr))
            {
#endif
                *ControllerModePtr = Can_ControllerState[Controller];
                ReturnStatus = (Std_ReturnType)E_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif

    return ReturnStatus;
}

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
/* SWS_Can_00216, SWS_Can_00217, SWS_Can_00219*/
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    Std_ReturnType                  ReturnStatus = (Std_ReturnType)E_NOT_OK;
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_HwObjConfigType      *CanHwObjPtr = NULL_PTR;
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_WRITE))
    {
        if (TRUE == Can_CheckWrite(Hth, PduInfo))
        {
#endif
            CanControllerId = Can_ConfigPtr[CanCoreId]->CanHwObjIndexPtr[Hth];
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                CanHwObjPtr = &((Can_ConfigPtr[CanCoreId])->CanHwObjConfigPtr[Hth]);

                if ((TRUE == Can_CheckPduInfo(CanObjConfigPtr, CanHwObjPtr, PduInfo)) &&
                    (CAN_CS_STARTED == Can_ControllerState[CanControllerId]))
                {
                    ReturnStatus = Can_SendPdu(CanObjConfigPtr->CanControllerId,
                                               CanObjConfigPtr->CanControllerOffset, Hth,
                                               CanHwObjPtr, PduInfo);
                }
            }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif

    return ReturnStatus;
}

#if (CAN_ABORT_HW_OBJECT_SEND_API == STD_ON)
/**
 * @brief      This function aborts transmission of the given HTH.
 *
 * @param[in]  Hth: Hardware transmit handle.
 *
 * @return     None
 *
 */
void Can_AbortHwObjectSend(Can_HwHandleType Hth)
{

    uint32                          CanCoreId = Can_GetCoreID();
    const Can_HwObjConfigType      *CanHwObjPtr = NULL_PTR;
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_ABORT_MB))
    {
        if (TRUE == Can_CheckAbortHwObjectSend(Hth))
        {
    #endif
            CanControllerId = Can_ConfigPtr[CanCoreId]->CanHwObjIndexPtr[Hth];
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                CanHwObjPtr = &((Can_ConfigPtr[CanCoreId])->CanHwObjConfigPtr[Hth]);

                Can_CancelTransfer(CanObjConfigPtr->CanControllerOffset, CanHwObjPtr);
            }
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
}
#endif

#if (CAN_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)
/**
 * @brief     This function performs the polling of TX confirmation when CAN_TX_PROCESSING is set to
 * POLLING.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
/*SWS_Can_00031, SWS_Can_00178, */
void Can_MainFunction_Write(void)
{
    #if (CAN_TX_POLLING_SUPPORT == STD_ON)
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;
    Can_HwHandleType                HwObjIndex = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        HwObjIndex = (Can_ConfigPtr[CanCoreId])->CanFirstHTHIndex;
        while (HwObjIndex < Can_ConfigPtr[CanCoreId]->CanHardwareCounter)
        {
            CanControllerId = Can_ConfigPtr[CanCoreId]->CanHwObjIndexPtr[HwObjIndex];
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                /* Can_MainFunction_Write shall perform the polling */
                if ((TRUE == CanObjConfigPtr->CanActiveStatus) &&
                    (TRUE ==
                     (Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex].CanHwUsesPolling)))
                {
                    Can_ExecutePollingWrite(
                        CanControllerId, CanObjConfigPtr->CanControllerOffset, HwObjIndex,
                        &(Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex]));
                }
            }
            HwObjIndex++;
        }
    }

    #endif
}
#else
    /*This parameter describes the period for cyclic call to Can_MainFunction_Read or
     Can_MainFunction_Write depending on the referring item. Unit is seconds. Different poll-cycles
     will be configurable if more than one CanMainFunctionPeriod is configured. In this case
     multiple Can_MainFunction_Read() or Can_MainFunction_Write() will be provided by the CAN Driver
     module.*/
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_0
void Can_MainFunction_Write_0(void)
{
    Can_MainFunctionMultipleWrite(0U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_1
void Can_MainFunction_Write_1(void)
{
    Can_MainFunctionMultipleWrite(1U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_2
void Can_MainFunction_Write_2(void)
{
    Can_MainFunctionMultipleWrite(2U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_3
void Can_MainFunction_Write_3(void)
{
    Can_MainFunctionMultipleWrite(3U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_4
void Can_MainFunction_Write_4(void)
{
    Can_MainFunctionMultipleWrite(4U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_5
void Can_MainFunction_Write_5(void)
{
    Can_MainFunctionMultipleWrite(5U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_6
void Can_MainFunction_Write_6(void)
{
    Can_MainFunctionMultipleWrite(6U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_7
void Can_MainFunction_Write_7(void)
{
    Can_MainFunctionMultipleWrite(7U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_8
void Can_MainFunction_Write_8(void)
{
    Can_MainFunctionMultipleWrite(8U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_9
void Can_MainFunction_Write_9(void)
{
    Can_MainFunctionMultipleWrite(9U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_WRITE_PERIOD_10
void Can_MainFunction_Write_10(void)
{
    Can_MainFunctionMultipleWrite(10U);
}
    #endif

#endif

#if (CAN_MAINFUNCTION_MULTIPLE_READ == STD_OFF)
/**
 * @brief     This function performs the polling of RX indications when CAN_RX_PROCESSING is set to
 * POLLING.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
/*(SWS_Can_00108,SRS_BSW_00432,SRS_SPAL_00157, SWS_Can_00442, ECUC_Can_00438)*/
void Can_MainFunction_Read(void)
{
    #if (CAN_RX_POLLING_SUPPORT == STD_ON)
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;
    Can_HwHandleType                HwObjIndex = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        while (HwObjIndex < Can_ConfigPtr[CanCoreId]->CanFirstHTHIndex)
        {
            CanControllerId = Can_ConfigPtr[CanCoreId]->CanHwObjIndexPtr[HwObjIndex];
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                /* Can_MainFunction_Read shall perform the polling */
                if ((TRUE == CanObjConfigPtr->CanActiveStatus) &&
                    (TRUE ==
                     (Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex].CanHwUsesPolling)))
                {
                    Can_ExecutePollingRead(
                        CanControllerId, CanObjConfigPtr->CanControllerOffset, HwObjIndex,
                        &(Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr[HwObjIndex]));
                }
            }
            HwObjIndex++;
        }
    }
    #endif
}
#else
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_0
void Can_MainFunction_Read_0(void)
{
    Can_MainFunctionMultipleRead(0U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_1
void Can_MainFunction_Read_1(void)
{
    Can_MainFunctionMultipleRead(1U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_2
void Can_MainFunction_Read_2(void)
{
    Can_MainFunctionMultipleRead(2U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_3
void Can_MainFunction_Read_3(void)
{
    Can_MainFunctionMultipleRead(3U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_4
void Can_MainFunction_Read_4(void)
{
    Can_MainFunctionMultipleRead(4U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_5
void Can_MainFunction_Read_5(void)
{
    Can_MainFunctionMultipleRead(5U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_6
void Can_MainFunction_Read_6(void)
{
    Can_MainFunctionMultipleRead(6U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_7
void Can_MainFunction_Read_7(void)
{
    Can_MainFunctionMultipleRead(7U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_8
void Can_MainFunction_Read_8(void)
{
    Can_MainFunctionMultipleRead(8U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_9
void Can_MainFunction_Read_9(void)
{
    Can_MainFunctionMultipleRead(9U);
}
    #endif
    #ifdef CAN_MAINFUNCTION_READ_PERIOD_10
void Can_MainFunction_Read_10(void)
{
    Can_MainFunctionMultipleRead(10U);
}
    #endif

#endif

/**
 * @brief     This function performs the polling of bus-off events that are configured statically as
 * 'to be polled'.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
/*SWS_Can_00109,  SWS_Can_00183 */
void Can_MainFunction_BusOff(void)
{
#if (CAN_BUSOFF_POLLING_SUPPORT == STD_ON)
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != Can_ConfigPtr[CanCoreId])
    {
        for (CanControllerId = 0U; CanControllerId < Can_ConfigPtr[CanCoreId]->CanControllerCounter;
             CanControllerId++)
        {
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                /* Can_MainFunction_BusOff shall perform the polling */
                if ((TRUE == CanObjConfigPtr->CanActiveStatus) &&
                    (CAN_BUSOFF_POLLING_MASK ==
                     ((CanObjConfigPtr->CanProcessConfig) & CAN_BUSOFF_POLLING_MASK)))
                {
                    (void)Can_Drv_BusOffMainFunction(CanObjConfigPtr->CanControllerOffset);
                }
            }
        }
    }

#endif
}

#if (CAN_WAKEUP_POLLING_SUPPORT == STD_ON)
/**
 * @brief     This function performs the polling of wake-up events that are configured statically as
 * 'to be polled'
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
/* SWS_Can_00112, SWS_Can_00185 */
void Can_MainFunction_Wakeup(void)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        for (CanControllerId = 0U; CanControllerId < Can_ConfigPtr[CanCoreId]->CanControllerCounter;
             CanControllerId++)
        {
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                /* Can_MainFunction_Wakeup shall perform the polling */
                if ((TRUE == CanObjConfigPtr->CanActiveStatus) &&
                    (CAN_WAKE_POLLING_MASK ==
                     ((CanObjConfigPtr->CanProcessConfig) & CAN_WAKE_POLLING_MASK)))
                {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
                    (void)Can_Drv_WakeupMainFunction(Can_ConfigPtr[CanCoreId]->CanHwObjConfigPtr);
    #endif
                }
            }
        }
    }
}
#endif

/**
 * @brief      This function performs the polling of CAN controller Mode transitions.
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Can_MainFunction_Mode(void)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        for (CanControllerId = 0U; CanControllerId < Can_ConfigPtr[CanCoreId]->CanControllerCounter;
             CanControllerId++)
        {
            CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];
            if (NULL_PTR != CanObjConfigPtr)
            {
                if ((TRUE == CanObjConfigPtr->CanActiveStatus))
                {
                    Can_ExecutePollingMode(CanObjConfigPtr->CanControllerId,
                                           CanObjConfigPtr->CanControllerOffset,
                                           &Can_ControllerState[CanControllerId]);
                }
            }
        }
    }
}

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
void Can_ProcessMbCommonInterrupt(uint8 Id, uint8 MbIdx, Can_HwObjectType Type)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        CanControllerId = Can_ConfigPtr[CanCoreId]->CanControllerIndexPtr[Id];
        CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];

        if (NULL_PTR != CanObjConfigPtr)
        {
            switch (Type)
            {
                case CAN_OBJ_TRANSMIT:
                {
                    Can_ProcessTxMsgBuffer(CanObjConfigPtr->CanControllerId,
                                           (Can_ConfigPtr[CanCoreId])->CanHwObjConfigPtr, MbIdx);
                    break;
                }
                case CAN_OBJ_RECEIVE:
                {
                    Can_ProcessRxMsgBuffer(CanObjConfigPtr->CanControllerId,
                                           CanObjConfigPtr->CanControllerOffset,
                                           (Can_ConfigPtr[CanCoreId])->CanHwObjConfigPtr, MbIdx);
                    break;
                }
                case CAN_OBJ_FIFO:
                {
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
                    if ((uint8)CAN_RX_FIFO_OVERFLOW_MB_INDEX == MbIdx)
                    {

                        (void)Det_ReportRuntimeError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                                     (uint8)CAN_SID_RECEIVE_HANDLER,
                                                     (uint8)CAN_E_DATALOST);
                    }
    #endif

                    Can_ProcessRxMsgBuffer(CanObjConfigPtr->CanControllerId,
                                           CanObjConfigPtr->CanControllerOffset,
                                           (Can_ConfigPtr[CanCoreId])->CanHwObjConfigPtr, MbIdx);
                    break;
                }
                default:
                {
                    /* Nothing to do */
                    break;
                }
            }
        }
    }
}
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
void Can_ProcessRxFiFoDmaInterrupt(uint8 Id, Can_Drv_IntType IntType)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        CanControllerId = Can_ConfigPtr[CanCoreId]->CanControllerIndexPtr[Id];
        CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];

        if (NULL_PTR != CanObjConfigPtr)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            if(CAN_DRV_DMA_ERROR == IntType)
            {
                (void)Det_ReportRuntimeError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                                             (uint8)CAN_SID_RECEIVE_HANDLER,
                                             (uint8)CAN_E_DATALOST);
            }

#endif
            Can_ProcessRxDma(CanObjConfigPtr->CanControllerId, CanObjConfigPtr->CanControllerOffset,
                             (Can_ConfigPtr[CanCoreId])->CanHwObjConfigPtr, IntType);
        }
    }
}
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
void Can_ProcessSelfWakeup(uint8 Id)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        CanControllerId = Can_ConfigPtr[CanCoreId]->CanControllerIndexPtr[Id];
        CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];

        if (NULL_PTR != CanObjConfigPtr)
        {
            /* Process self wakeup event. */
            if (E_OK == Can_SetControllerToStopMode(CanObjConfigPtr->CanControllerId,
                                                    CanObjConfigPtr->CanControllerOffset))
            {
                Can_ControllerState[CanControllerId] = CAN_CS_STOPPED;
            }

            (void)Can_Drv_DisableSelfWakeup(CanObjConfigPtr->CanControllerOffset);
            EcuM_CheckWakeup(CanObjConfigPtr->CanWakeUpSourceId);
    #if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
            Can_SelfWakeupStatus[CanObjConfigPtr->CanControllerId] = (boolean)TRUE;
    #endif
        }
    }
}
#endif

/**
 * @brief     This function processes bus-off interrupt.
 *
 * @param[in] Id: Controller Id
 *
 * @return    None
 *
 */
void Can_ProcessBusOffInterrupt(uint8 Id)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        CanControllerId = Can_ConfigPtr[CanCoreId]->CanControllerIndexPtr[Id];
        CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];

        if (NULL_PTR != CanObjConfigPtr)
        {
            /* Process BusOff event. */
            if (E_OK == Can_SetControllerToStopMode(CanObjConfigPtr->CanControllerId,
                                                    CanObjConfigPtr->CanControllerOffset))
            {
                Can_ControllerState[CanControllerId] = CAN_CS_STOPPED;
                CanIf_ControllerBusOff(CanObjConfigPtr->CanInterfaceId);
            }
        }
    }
}

#if (CAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
/**
 * @brief     This function processes error interrupts.
 *
 * @param[in] CtrlOffset: Controller Id
 * @param[in] IsErrFast: Can Fd error flag.
 * @param[in] Data:  Error status.
 *
 * @return    None
 *
 */
void Can_ProcessErrorInterrupt(uint8 CtrlOffset, boolean IsErrFast, uint32 Data)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;

    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        CanControllerId = Can_ConfigPtr[CanCoreId]->CanControllerIndexPtr[CtrlOffset];
        CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];

        if (NULL_PTR != CanObjConfigPtr)
        {
    #if (CAN_SEC_EVENT_REPORT_SUPPORT == STD_ON)
            Can_ReportSecurityEvents(CanObjConfigPtr->CanInterfaceId, Data);
    #endif
            if (TRUE == IsErrFast)
            {
                if (NULL_PTR != CanObjConfigPtr->CanFdErrNotify)
                {
                    CanObjConfigPtr->CanFdErrNotify();
                }
            }
            else
            {
                if (NULL_PTR != CanObjConfigPtr->CanErrNotify)
                {
                    CanObjConfigPtr->CanErrNotify();
                }
            }
        }
    }
}
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
void Can_ProcessEccInterrupt(uint8 CtrlOffset, uint32 IntType, uint32 Data)
{
    uint32                          CanCoreId = Can_GetCoreID();
    const Can_ControllerConfigType *CanObjConfigPtr = NULL_PTR;
    uint8                           CanControllerId = 0U;
    (void)Data;
    if (NULL_PTR != (Can_ConfigPtr[CanCoreId]))
    {
        CanControllerId = Can_ConfigPtr[CanCoreId]->CanControllerIndexPtr[CtrlOffset];
        CanObjConfigPtr = Can_ConfigPtr[CanCoreId]->CanControllerConfigPtr[CanControllerId];

        if (NULL_PTR != CanObjConfigPtr)
        {
            if ((uint32)CAN_DRV_INT_HOST_MEM_ERR == IntType)
            {
                if (NULL_PTR != CanObjConfigPtr->CanHostAccessNotify)
                {
                    CanObjConfigPtr->CanHostAccessNotify();
                }
            }
            else if ((uint32)CAN_DRV_INT_MEM_ERR == IntType)
            {
                if (NULL_PTR != CanObjConfigPtr->CanAccessMemoryNotify)
                {
                    CanObjConfigPtr->CanAccessMemoryNotify();
                }
            }
            else if ((uint32)CAN_DRV_INT_COR_MEM_ERR == IntType)
            {
                if (NULL_PTR != CanObjConfigPtr->CanCorrectableMemoryNotify)
                {
                    CanObjConfigPtr->CanCorrectableMemoryNotify();
                }
            }
            else
            {
                /* nothing to do */
            }
        }
    }
}
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
Std_ReturnType Can_InjectError(uint8 ControllerId)
{
    Std_ReturnType                  ReturnVal = E_NOT_OK;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_INJECT_ERROR))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_INJECT_ERROR, ControllerId))
        {
    #endif
            
            if (TRUE == ConfigPtr->CanErrInjectEnable)
            {
                /* inject correctable error */
                ReturnVal = (Std_ReturnType)Can_Drv_InjectCorrectableAddress(
                    ConfigPtr->CanControllerOffset);

                if (E_OK == ReturnVal)
                {
                    Can_EccInjectionStatus[ControllerId] = TRUE;
                    /* inject non-correctable error */
                    ReturnVal = (Std_ReturnType)Can_Drv_InjectAddress(
                    ConfigPtr->CanControllerOffset);

                    if(FALSE != Can_EccInjectionStatus[ControllerId])
                    {
                        ReturnVal = E_NOT_OK;
                    }

                }
            }            

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
    return ReturnVal;
}

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
Std_ReturnType Can_ClearInjectError(uint8 ControllerId)
{
    Std_ReturnType                  ReturnVal = E_NOT_OK;
    const Can_ControllerConfigType *ConfigPtr = Can_ControllerConfigPtr[ControllerId];

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (TRUE == Can_CheckInitialized((uint8)CAN_SID_CLEAR_INJECT_ERROR))
    {
        if (TRUE == Can_CheckController((uint8)CAN_SID_CLEAR_INJECT_ERROR, 
                                         ControllerId))
        {
#endif
            
            if (TRUE == ConfigPtr->CanErrInjectEnable)
            {
                if(TRUE == Can_EccInjectionStatus[ControllerId])
                {
                    /* clear injection error */
                    ReturnVal = (Std_ReturnType)Can_Drv_ClearInjection(
                        ConfigPtr->CanControllerOffset);
                }                
            }
            if(E_OK == ReturnVal)
            {
                Can_EccInjectionStatus[ControllerId] = FALSE;
            }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
    return ReturnVal;
}
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Can */

/** @} end of group Can_Module */
