/***************************************************************************************************/
/**
 * @file      : Can_Types.h
 * @brief     : Can AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_TYPES_H
#define CAN_TYPES_H

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can
 *  @brief Can driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can_Drv_Types.h"
#include "Can_Cfg.h"
#include "Can_GeneralTypes.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CAN_TYPES_H_VENDOR_ID                   0x00B3U
#define CAN_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_TYPES_H_SW_MAJOR_VERSION            1U
#define CAN_TYPES_H_SW_MINOR_VERSION            2U
#define CAN_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Can_Drv_Types.h are the same vendor */
#if (CAN_TYPES_H_VENDOR_ID != CAN_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Can_Types.h and Can_Drv_Types.h are different"
#endif
/* Check if current file and Can_Drv_Types.h are the same Autosar version */
#if ((CAN_TYPES_H_AR_RELEASE_MAJOR_VERSION != CAN_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (CAN_TYPES_H_AR_RELEASE_MINOR_VERSION != CAN_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (CAN_TYPES_H_AR_RELEASE_REVISION_VERSION != CAN_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_Types.h and Can_Drv_Types.h are different"
#endif
/* Check if current file and Can_Drv_Types.h are the same Software version */
#if ((CAN_TYPES_H_SW_MAJOR_VERSION != CAN_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (CAN_TYPES_H_SW_MINOR_VERSION != CAN_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (CAN_TYPES_H_SW_PATCH_VERSION != CAN_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Types.h and Can_Drv_Types.h are different"
#endif

/* Check if current file and Can_Cfg.h are the same vendor */
#if (CAN_TYPES_H_VENDOR_ID != CAN_CFG_H_VENDOR_ID)
    #error "Can_Types.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_Cfg.h are the same Autosar version */
#if ((CAN_TYPES_H_AR_RELEASE_MAJOR_VERSION != CAN_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (CAN_TYPES_H_AR_RELEASE_MINOR_VERSION != CAN_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (CAN_TYPES_H_AR_RELEASE_REVISION_VERSION != CAN_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_Types.h and Can_Cfg.h are different"
#endif
/* Check if current file and Can_Cfg.h are the same Software version */
#if ((CAN_TYPES_H_SW_MAJOR_VERSION != CAN_CFG_H_SW_MAJOR_VERSION) ||                               \
     (CAN_TYPES_H_SW_MINOR_VERSION != CAN_CFG_H_SW_MINOR_VERSION) ||                               \
     (CAN_TYPES_H_SW_PATCH_VERSION != CAN_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Types.h and Can_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Can_GeneralTypes.h are of the same Software version */
    #if ((CAN_TYPES_H_AR_RELEASE_MAJOR_VERSION != CAN_GENERAL_AR_RELEASE_MAJOR_VERSION) ||         \
         (CAN_TYPES_H_AR_RELEASE_MINOR_VERSION != CAN_GENERAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Can_Types.h and Can_GeneralTypes.h are different"
    #endif
#endif

/** @name Development errors
 * @{
 */
#define CAN_E_PARAM_POINTER     0x01U /* API service called with wrong parameter */
#define CAN_E_PARAM_HANDLE      0x02U /* API service called with wrong parameter */
#define CAN_E_PARAM_DATA_LENGTH 0x03U /* API service called with wrong parameter */
#define CAN_E_PARAM_CONTROLLER  0x04U /* API service called with wrong parameter */
#define CAN_E_UNINIT            0x05U /* API service called without module initialization */
#define CAN_E_TRANSITION        0x06U /* Invalid transition for the current Mode */
#define CAN_E_PARAM_BAUDRATE    0x07U /* Parameter Baudrate has an invalid Value */
#define CAN_E_INIT_FAILED       0x09U /* Invalid configuration set selection */

/** @} */

/** @name Runtime errors
 * @{
 */
#define CAN_E_DATALOST 0x01U /* Received CAN message is lost */

#define CAN_IDTYPE_EXTENDED ((uint32)0x80000000U)  /* Indicates extended CAN frame */

#define CAN_IDTYPE_FD_FRAME ((uint32)0x40000000U)  /* Indicates CAN FD frame */

/** @} */

/** @name Service ID
 * @{
 */
#define CAN_SID_INIT                          0x00U
#define CAN_SID_MAIN_FUNCTION_WRITE           0x01U
#define CAN_SID_SET_CONTROLLER_MODE           0x03U
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS 0x04U
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS  0x05U
#define CAN_SID_WRITE                         0x06U
#define CAN_SID_GET_VERSION_INFO              0x07U
#define CAN_SID_MAIN_FUNCTION_READ            0x08U
#define CAN_SID_MAIN_FUNCTION_BUS_OFF         0x09U
#define CAN_SID_MAIN_FUNCTION_WAKEUP          0x0AU
#define CAN_SID_CHECK_WAKEUP                  0x0BU
#define CAN_SID_MAIN_FUNCTION_MODE            0x0CU
#define CAN_SID_SET_BAUDRATE                  0x0FU
#define CAN_SID_DEINIT                        0x10U
#define CAN_SID_GET_CONTROLLER_ERROR_STATE    0x11U
#define CAN_SID_GET_CONTROLLER_MODE           0x12U
#if (CAN_ABORT_HW_OBJECT_SEND_API == STD_ON)
    #define CAN_SID_ABORT_MB 0x14U
#endif
#if (CAN_ERROR_INJECTION_SUPPORT == STD_ON)
    #define CAN_SID_INJECT_ERROR 0x15U
    #define CAN_SID_CLEAR_INJECT_ERROR 0x16U
#endif
#define CAN_SID_CALLOUT_FUNCTION                0x20U
#define CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER 0x30U
#define CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER 0x31U
/** @} */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Can module State Type.
 */
typedef enum
{
    CAN_UNINIT = 0U, /*!< Can module not initialized */
    CAN_READY        /*!< Can module ready */
} Can_DriverStateType;

/**
 *  @brief Specifies the Type of a hardware object.
 */
typedef enum
{
    CAN_BASIC = 0U, /*!< Basic-CAN*/
    CAN_FULL        /*!< Full-CAN*/
} Can_HandleType;

/**
 *  @brief CAN Message ID Type definition
 */
typedef enum
{
    CAN_MSG_ID_STANDARD = 0U, /*!< Standard ID*/
    CAN_MSG_ID_EXTENDED,      /*!< Extended ID*/
    CAN_MSG_ID_MIXED          /*!< Extended ID and Standard ID*/
} Can_MessageIdType;

/**
 *  @brief Can Object Type (MB Type)
 */
typedef enum
{
    CAN_OBJ_RECEIVE = 0U, /*!< MailBox use to receive*/
    CAN_OBJ_TRANSMIT,     /*!< MailBox use to transmit*/
    CAN_OBJ_FIFO          /*!< MailBox use to Rx FIFO*/
} Can_HwObjectType;

/**
 * @brief Used to set Acceptance Mode
 */
typedef enum
{
    CAN_RX_FIFO_FORMAT_A = 0U, /*!< One full ID (standard and extended)*/
    CAN_RX_FIFO_FORMAT_B,      /*!< Two full standard IDs or two partial 14-bit extended IDs*/
    CAN_RX_FIFO_FORMAT_C,      /*!< Four partial 8-bit Standard,extended IDs */
} Can_RxAcceptanceType;

/**
 *  @brief CAN Hardware Filter Type
 */
typedef struct
{
    uint32 CanHwFilterCode; /*!< Specifies (together with the filter Mask) the identifiers range
                                that passes the hardware filter.*/
    uint32 CanHwFilterMask; /*!< Describes a Mask for hardware-based filtering of CAN identifiers.*/
} Can_HardwareFilterType;

/**
 *  @brief CAN Hardware Object Type
 */
typedef struct
{
    const uint8 CanFdPaddingValue; /*!< Specifies the Value which is used to pad unspecified Data
                                       in CAN FD frames > 8 bytes for transmission.*/
    const Can_HandleType    CanHandleType;    /*!< Specifies the Type of a hardware object.*/
    const Can_MessageIdType CanIdMessageType; /*!< IdValue is of Type  */
    const Can_HwHandleType  CanHwObjectId;    /*!< Holds the handle ID of HRH or HTH.*/
    const boolean           CanHwUsesPolling; /*!< Enables polling of this hardware object.*/
    const boolean CanTriggerTransmitStatus;    /*!< This parameter defines if or if not Can supports
                                                  the trigger-transmit API for this handle.*/
    const uint8 CanMainFunctionRwPeriodIndex; /*!< Reference to CanMainFunctionPeriod.*/
    const uint8 CanHwObjectCount; /*!< Number of hardware objects used to implement one HOH.*/
    const uint8 CanPayloadLength; /*!< Specifies the maximum L-PDU Payload length in bytes the
                                      hardware object can store.*/
    const uint8                   CanHwFilterCount; /*!< Number of hardware object filter */
    const Can_HardwareFilterType *CanHwFilterPtr;   /*!< pointer to hardware object filter */
    const Can_HwObjectType CanObjectType; /*!< Specifies if the HardwareObject is used as Transmit
                                              or as Receive object*/
    const uint8 CanHwBufferIndex;         /*!< buffer index to current message buffer */
} Can_HwObjConfigType;

/**
 *  @brief CAN  notify function Type
 */
typedef void (*Can_NotifyFuncType)(void);

/**
 *  @brief CAN RxFifo Configure Type
 */
typedef struct
{
    const Can_RxAcceptanceType CanRxFifoType;             /*!< Can FIFO acceptance Mode */
    const uint32               CanRxFifoGlobalFilterMask; /*!< Can RX FIFO Global Filter Mask */
    const Can_NotifyFuncType
        CanOverFlowNotify; /*!< Callback function to notify overflow of Legacy FIFO. */
    const Can_NotifyFuncType
        CanWarnNotify;     /*!< Callback function to notify warning of Legacy FIFO. */
    const Can_NotifyFuncType
        CanAvailNotify;    /*!< Call-back function to notify available of Legacy FIFO. */
} Can_RxFifoConfigType;

/**
 *  @brief CAN bit timing configuration structures
 */
typedef struct
{
    const uint8  CanPropSeg;    /*!< Propagation segment*/
    const uint8  CanPhaseSeg1;  /*!< Phase segment 1*/
    const uint8  CanPhaseSeg2;  /*!< Phase segment 2*/
    const uint16 CanPreDivider; /*!< Clock pre-scaler division factor*/
    const uint8  CanRJumpWidth; /*!< Resync jump width*/
} Can_BitTimingType;

/**
 *  @brief  This structure used for the baudrate .
 */
typedef struct
{
    const uint8 CanControlTxArbitrationStartDelay; /*!< How many CAN bits the Tx arbitration
                                                       process start point can be delayed from the
                                                       first bit of CRC field on CAN bus */
    const Can_BitTimingType CanBitRate;       /*!< The bitrate used for standard frames or for the
                                                  arbitration phase of FD frames.*/

    const boolean           CanFdEnable;      /*!< Can Fd frame support bit */
    const Can_BitTimingType CanFdDataBitRate; /*!< Can Fd Data Bit Rate */

    const boolean CanBitRateSwitch;      /*!< Enable bit Rate switch inside a CAN FD Format frame*/
    const boolean CanTransmitCompEnable; /*!< Enable transmit compensation delay support bit */
    const uint8 CanControllerSspOffset;  /*!< Specifies the Transmitter Delay Compensation Offset in
                                             minimum time quanta */
} Can_ControllerBaudrateConfigType;

/**
 *  @brief CAN Hardware Channel Configure Type
 */
typedef struct
{
    const Can_Drv_ConfigType *CanHwConfigPtr;
} Can_HwChannelConfigType;

/**
 *  @brief CAN Controller Configure Type
 */
typedef struct
{
#if (CAN_WAKEUP_SUPPORT == STD_ON)
    const uint32  CanWakeUpSourceId;                 /*!<ID Source Wakeup of EcuM*/
    const boolean CanWakeUpCanActiveStatus;          /*!< Source Wakeup Enable Status*/
#endif
    const uint8                 CanControllerId;     /*!< Current Can Controller Id */
    const uint8                 CanInterfaceId;      /*!< Current Can interface index */
    const uint8                 CanControllerOffset; /*!< Current Can Controller Offset*/
    const boolean               CanActiveStatus; /*!< Can Controller active Status configure bit*/
    const Can_RxFifoConfigType *CanRxFifoConfigPtr; /*!< pointer to CAN RxFifo Configure*/
    const uint32  CanProcessConfig; /*!< Can bus off,Tx,Rx,Wakeup process Mode:interrupt,polling*/
    const boolean CanErrEnable;     /*!< Can error interrupt Enable*/
    const Can_NotifyFuncType CanErrNotify; /*!< Can error interrupt notify callback function*/
    const Can_NotifyFuncType
                 CanFdErrNotify; /*!< Can fd Data bit error interrupt notify callback function*/
    const uint16 CanDefaultBaudrateIndex;                   /*!< Can baudrate default index*/
    const uint16 CanBaudrateCount;                          /*!< Number of Can baudrate */
    const Can_ControllerBaudrateConfigType *CanBaudratePtr; /*!< pointer to Can baudrate configure*/
    const uint8 CanHwObjectRefCount; /*!< Number of Can hardware referred to current controller*/
    const Can_HwObjConfigType *const
        *CanHwObjectPPtr; /*!< pointer to Can hardware that referred to current controller*/
    const Can_HwChannelConfigType *CanHwChannelConfigPtr; /*!< Pointer to Controller Config*/
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    const Can_NotifyFuncType CanDmaErrorNotify;           /*!<Dma Error Notification */
    Can_Drv_MsgBufType      *DmaDstAddr;                 /*!<Pointer to DMA destination address */
#endif
#if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
    const uint32 CanEccEnable;           /*!< Can ecc interrupt Enable*/
    const Can_NotifyFuncType CanHostAccessNotify;           /*!< Non-correctable errors
                                                             detected in memory reads issued by
                                                             the CPU */
    const Can_NotifyFuncType CanAccessMemoryNotify;           /*!< Non-correctable errors
                                                             detected in memory reads issued by
                                                             CAN */
    const Can_NotifyFuncType CanCorrectableMemoryNotify;    /*!< Correctable errors
                                                             detected in memory */   
#endif
    const boolean CanErrInjectEnable;     /*!< Can error inject enable */                                                                             
} Can_ControllerConfigType;

/**
 *  @brief  This structure is All driver Configure.
 */
typedef struct
{
    const uint32           CanCoreId;            /*!< Can Configure core Id */
    const Can_HwHandleType CanFirstHTHIndex;     /*!< Can Tx First Index */
    const uint32           CanControllerCounter; /*!< Can controller number  */
    const uint8 *CanControllerIndexPtr; /*!< The index corresponds to the actual sequence Value */
    const uint32 CanHardwareCounter;    /*!< Hardware object Counter */
    const uint8 *CanHwObjIndexPtr;      /*!< Controller ID corresponds to Hardware Object ID */
    const Can_HwObjConfigType *CanHwObjConfigPtr; /*!< Pointer to Can Hardware Object Config */
    const Can_ControllerConfigType *const
        *CanControllerConfigPtr;                  /*!< Pointer to Can Controller Config pointer */
} Can_ConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Can */

/** @} end of group Can_Module */

#endif /* CAN_H */
