/***************************************************************************************************/
/**
 * @file      : Can_Drv_Types.h
 * @brief     : Can low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_DRV_TYPES_H
#define CAN_DRV_TYPES_H

/** @addtogroup  Can_Module
 *  @{
 */

/** @addtogroup Can_Drv
 *  @brief Can low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Can_Drv_Cfg.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CAN_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define CAN_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define CAN_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define CAN_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Can_Drv_Cfg.h are of the same vendor */
#if (CAN_DRV_TYPES_H_VENDOR_ID != CAN_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Can_Drv_Types.h and Can_Drv_Cfg.h are different"
#endif
/* Check if current file and Can_Drv_Cfg.h are of the same Software version */
#if ((CAN_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != CAN_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (CAN_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != CAN_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (CAN_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != CAN_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Can_Drv_Types.h and Can_Drv_Cfg.h are different"
#endif
/* Check if current file and Can_Drv_Cfg.h are of the same Software version */
#if ((CAN_DRV_TYPES_H_SW_MAJOR_VERSION != CAN_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (CAN_DRV_TYPES_H_SW_MINOR_VERSION != CAN_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (CAN_DRV_TYPES_H_SW_PATCH_VERSION != CAN_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Drv_Types.h and Can_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h are of the same Autosar version */
    #if ((CAN_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (CAN_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Can_Drv_Types.h and McalLib.h are different"
    #endif

    /* Check if current file and Std_Types.h are of the same Software version */
    #if ((CAN_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (CAN_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Can_Drv_Types.h and Std_Types.h are different"
    #endif
#endif

#define CAN_DRV_RXFIFO_START_INDEX (0U)

/**
 * @brief Default value for the MCR register
 */
#define CAN_DRV_MCR_DEFAULT_VALUE ((uint32)0xD890000FU)

/**
 * @brief Default value for the CTRL1 register
 */
#define CAN_DRV_CTRL1_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 * @brief Default value for the TIMER register
 */
#define CAN_DRV_TIMER_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 * @brief Default value for the ECR register
 */
#define CAN_DRV_ECR_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 * @brief Default value for the ESR1 register
 */
#define CAN_DRV_ESR1_DEFAULT_VALUE ((uint32)0x0003B006U)

/**
 * @brief Default value for the CTRL2 register
 */
#define CAN_DRV_CTRL2_DEFAULT_VALUE ((uint32)0x00100000U)

/**
 * @brief Default value for the CBT register
 */
#define CAN_DRV_CBT_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 * @brief Default value for the FDCTRL register
 */
#define CAN_DRV_FDCTRL_DEFAULT_VALUE ((uint32)0x80004100U)

/**
 * @brief Default value for the FDCBT register
 */
#define CAN_DRV_FDCBT_DEFAULT_VALUE ((uint32)0x00000000U)

/**
 *  @brief Frames available in Rx FIFO Flag shift
 */
#define CAN_DRV_RXFIFO_FRAME_AVAILABLE (5U)

/**
 *  @brief  Rx FIFO warning Flag shift
 */
#define CAN_DRV_RXFIFO_WARNING (6U)

/**
 *  @brief Rx FIFO overflow Flag shift
 */
#define CAN_DRV_RXFIFO_OVERFLOW (7U)

/*Edge Filter Disable set*/
#define CAN_DRV_EDFLTDIS 0x00000001U

/* enables the CAN FD protocol according to ISO specification (ISO 11898-1)*/
#define CAN_DRV_ISOCANFDEN 0x00000002U

/*Protocol Exception set*/
#define CAN_DRV_PREXCEN 0x00000004U

/*CAN Bit Sampling.*/
#define CAN_DRV_SMP 0x00000020U

/*Lowest Buffer Transmitted First.*/
#define CAN_DRV_LBUF 0x00000040U

#define CAN_DRV_ESR1_FLTCONF_BUS_OFF (0x00000002U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Can controller Status
 */
typedef enum
{
    CAN_DRV_SUCCESS = 0U, /*!< set success. */
    CAN_DRV_ERROR,        /*!< set error */
    CAN_DRV_ENTER_BUSY,   /*!< Can busy */
    CAN_DRV_NO_TRANSMIT   /*!< Can Idle */
} Can_Drv_ControllerStatus;

/**
 *  @brief CAN ID Type definition
 */
typedef enum
{
    CAN_DRV_ID_0 = 0U, /*!< CAN0 */
    CAN_DRV_ID_1 = 1U, /*!< CAN1 */
    CAN_DRV_ID_2 = 2U, /*!< CAN2 */
    CAN_DRV_ID_3 = 3U, /*!< CAN3 */
    CAN_DRV_ID_4 = 4U, /*!< CAN4 */
    CAN_DRV_ID_5 = 5U, /*!< CAN5 */
    CAN_DRV_ID_6 = 6U, /*!< CAN6 */
    CAN_DRV_ID_7 = 7U  /*!< CAN7 */
} Can_Drv_IdType;

/**
 *  @brief CAN FD MB Region Type definition
 */
typedef enum
{
    CAN_DRV_CAN_FD_MB_REGION_0 = 0U, /*!< FD MB Region 0*/
    CAN_DRV_CAN_FD_MB_REGION_1,      /*!< FD MB Region 1*/
    CAN_DRV_CAN_FD_MB_REGION_2,      /*!< FD MB Region 2*/
    CAN_DRV_CAN_FD_MB_REGION_3       /*!< FD MB Region 3*/
} Can_Drv_FdMbRegionType;

/**
 * @brief Used to set Acceptance Mode
 */
typedef enum
{
    CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_A = 0U, /*!< One full ID (standard and extended)*/
    CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_B, /*!< Two full standard IDs or two partial 14-bit extended
                                           IDs*/
    CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_C, /*!< Four partial 8-bit Standard,extended IDs */
    CAN_DRV_RX_FIFO_ACCEPTANCE_FORMAT_D  /*!< All frames rejected.*/
} Can_Drv_RxAcceptanceType;

/**
 *  @brief CAN Rx FIFO ID filters number Type definition
 */
typedef enum
{
    CAN_DRV_RX_FIFO_FILTERS_8 = 0x0U,   /*!<   8 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_16 = 0x1U,  /*!<  16 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_24 = 0x2U,  /*!<  24 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_32 = 0x3U,  /*!<  32 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_40 = 0x4U,  /*!<  40 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_48 = 0x5U,  /*!<  48 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_56 = 0x6U,  /*!<  56 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_64 = 0x7U,  /*!<  64 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_72 = 0x8U,  /*!<  72 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_80 = 0x9U,  /*!<  80 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_88 = 0xAU,  /*!<  88 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_96 = 0xBU,  /*!<  96 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_104 = 0xCU, /*!< 104 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_112 = 0xDU, /*!< 112 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_120 = 0xEU, /*!< 120 Rx FIFO Filters */
    CAN_DRV_RX_FIFO_FILTERS_128 = 0xFU  /*!< 128 Rx FIFO Filters */
} Can_Drv_RxFifoFilterNumType;

/**
 *  @brief RxFIFO transfer Type definition
 */
typedef enum
{
    CAN_DRV_RXFIFO_INTERRUPTS = 0U, /*!< Use interrupts for RxFIFO. */
    CAN_DRV_RXFIFO_DMA,             /*!< Use DMA for RxFIFO. */
    CAN_DRV_RXFIFO_POLLING          /*!< Use Polling Mode */
} Can_Drv_RxFifoTransferType;

/**
 *  @brief CAN FD Payload size definition
 */
typedef enum
{
    CAN_DRV_OBJECT_PL_8 = 0U, /*!< CAN FD message buffer Payload length in bytes*/
    CAN_DRV_OBJECT_PL_16,     /*!< CAN FD message buffer Payload length in bytes*/
    CAN_DRV_OBJECT_PL_32,     /*!< CAN FD message buffer Payload length in bytes*/
    CAN_DRV_OBJECT_PL_64      /*!< CAN FD message buffer Payload length in bytes*/
} Can_Drv_FdPayloadLengthType;

/**
 *  @brief CAN FD Payload Block definition
 */
typedef struct
{
    Can_Drv_FdPayloadLengthType Block0; /*!< CAN Block0*/
    Can_Drv_FdPayloadLengthType Block1; /*!< CAN Block1*/
    Can_Drv_FdPayloadLengthType Block2; /*!< CAN Block2*/
    Can_Drv_FdPayloadLengthType Block3; /*!< CAN Block3*/
} Can_Drv_FdPayloadBlockType;

/**
 *  @brief CAN operation Mode Type definition
 */
typedef enum
{
    CAN_DRV_MODE_NORMAL = 0U, /*!< Normal Mode or user Mode */
    CAN_DRV_MODE_LISTEN_ONLY, /*!< Listen-only Mode */
    CAN_DRV_MODE_LOOPBACK,    /*!< Loop-back Mode */
    CAN_DRV_MODE_FREEZE,      /*!< Freeze Mode */
    CAN_DRV_MODE_DISABLE      /*!< Module Disable Mode */
} Can_Drv_ModeType;

/**
 *  @brief CAN Message ID Type definition
 */
typedef enum
{
    CAN_DRV_MSG_ID_STD = 0U, /*!< Standard ID*/
    CAN_DRV_MSG_ID_EXT       /*!< Extended ID*/
} Can_Drv_MsgIdType;

/**
 *  @brief CAN Rx Mask Type definition
 */
typedef enum
{
    CAN_DRV_RX_MASK_GLOBAL = 0U, /*!< Rx global Mask*/
    CAN_DRV_RX_MASK_INDIVIDUAL   /*!< Rx individual Mask*/
} Can_Drv_RxMaskType;

/**
 *  @brief CAN MB Code Type definition
 */
typedef enum
{
    CAN_DRV_MB_RX_INACTIVE = 0x0,  /*!< MB is not active.*/
    CAN_DRV_MB_RX_FULL = 0x2,      /*!< MB is full.*/
    CAN_DRV_MB_RX_EMPTY = 0x4,     /*!< MB is active and empty.*/
    CAN_DRV_MB_RX_OVERRUN = 0x6,   /*!< MB is overwritten into a full buffer.*/
    CAN_DRV_MB_RX_RANSWER = 0xA,   /*!< A frame was configured to recognize a Remote Request Frame
                                     and transmit a Response Frame in return.*/
    CAN_DRV_MB_TX_INACTIVE = 0x08, /*!< MB is not active.*/
    CAN_DRV_MB_TX_ABORT = 0x09,    /*!< MB is aborted.*/
    CAN_DRV_MB_TX_DATA_REMOTE = 0x0C, /*!< MB is a TX Data Frame(MB RTR = 0). or a
                                       remote request frame (MB RTR = 1)*/
    CAN_DRV_MB_TX_TANSWER = 0x0E,     /*!< MB is a Tx Response frame from an incoming
                                       Remote Request frame. */
    CAN_DRV_NOT_USED = 0x0F           /*!< Not used*/
} Can_Drv_MbCodeType;

/**
 *  @brief CAN interrupt Type definition
 */
typedef enum
{
    CAN_DRV_INT_BUS_OFF = 0U,            /*!< CAN interrupt: bus off */
    CAN_DRV_INT_ERR = 1U,                /*!< CAN interrupt: error */
    CAN_DRV_INT_TXW = 2U,                /*!< CAN interrupt: TX warning */
    CAN_DRV_INT_RXW = 3U,                /*!< CAN interrupt: RX warning */
    CAN_DRV_INT_BUS_OFF_DONE = 4U,       /*!< CAN interrupt: bus off done*/
    CAN_DRV_INT_ERR_FAST = 5U,           /*!< CAN interrupt: error detected in Data
                                          Phase of CAN FD frames with BRS bit
                                          set*/
    CAN_DRV_INT_SELF_WAKEUP = 6U,        /*!< CAN interrupt: self wake up */
    CAN_DRV_INT_RXFIFO_FRAME = 7U,       /*!< CAN interrupt: RX FIFO frame available */
    CAN_DRV_INT_RXFIFO_WARNING = 8U,     /*!< CAN interrupt: RX FIFO warning */
    CAN_DRV_INT_RXFIFO_OVERFLOW = 9U,    /*!< CAN interrupt: RX FIFO overflow */
    CAN_DRV_INT_HOST_MEM_ERR = 10U,      /*!< CAN interrupt: non-correctable errors
                                          detected in memory reads issued by
                                          the CPU */
    CAN_DRV_INT_MEM_ERR = 11U,               /*!< CAN interrupt: non-correctable errors
                                                  detected in memory reads issued by
                                                  CAN */
    CAN_DRV_INT_COR_MEM_ERR = 12U,       /*!< CAN interrupt: correctable errors
                                          detected in memory reads  */
    CAN_DRV_INT_PN_WAKEUP_MATCH = 13U,   /*!< CAN interrupt: wakeup by match */
    CAN_DRV_INT_PN_WAKEUP_TIMEOUT = 14U, /*!< CAN interrupt: wakeup by timeout */
    CAN_DRV_INT_MB_RECEIVE = 15U,        /*!< CAN interrupt: MB reception*/
    CAN_DRV_MB_TRANSMIT = 16U,           /*!< CAN interrupt: MB transmission*/
#if CAN_DRV_FEATURE_HAS_DMA_ENABLE
    CAN_DRV_DMA_COMPLETE = 17U, /*!< complete transfer occurred on DMA */
    CAN_DRV_DMA_ERROR = 18U,    /*!<  DMA transfer fail, because of a DMA Channel error */
#endif                          /* CAN_DRV_FEATURE_HAS_DMA_ENABLE */
    CAN_DRV_INT_ALL = 19U       /*!< CAN all interrupts */
} Can_Drv_IntType;

/**
 *  @brief CAN State Type definition
 */
typedef enum
{
    CAN_DRV_STATE_NOT_SYNC = 0U, /*!< it is not synchronized to CAN bus*/
    CAN_DRV_STATE_IDLE = 1U,          /*!< CAN bus is in idle State */
    CAN_DRV_STATE_TX = 2U,            /*!< CAN is transmitting */
    CAN_DRV_STATE_RX = 3U,            /*!< CAN is receiving */
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    CAN_DRV_STATE_DMA_ERROR = 4U, /*!< The MB is used as DMA Source and fail to transfer */
#endif
    CAN_DRV_STATE_INVALID = 5U /*!< this is not a valid State */
} Can_Drv_ControllerStateType;

/**
 *  @brief CAN bit timing configuration structures
 */
typedef struct
{
    uint32 PropSeg;    /*!< Propagation segment*/
    uint32 PhaseSeg1;  /*!< Phase segment 1*/
    uint32 PhaseSeg2;  /*!< Phase segment 2*/
    uint32 PreDivider; /*!< Clock pre-scaler division factor*/
    uint32 RJumpWidth; /*!< Resync jump width*/
} Can_Drv_BitTimingType;

/**
 *  @brief CAN RX FIFO ID filter table Element structure
 */
typedef struct
{
    boolean IsRemoteFrame;   /*!< Remote frame*/
    boolean IsExtendedFrame; /*!< Extended frame*/
    uint32  Id;              /*!< Rx FIFO ID filter Element*/
} Can_Drv_IdFilterType;

/**
 *  @brief CAN massage info structure
 */
typedef struct
{
    Can_Drv_MsgIdType IdType;     /*!< Type of message ID (standard or extended)*/
    uint8             DataLen;    /*!< Length of Data in Bytes*/
    boolean           RemoteFlag; /*!< Specifies if the frame is standard or remote */
    boolean           FdEn;       /*!< Enable or Disable FD*/
    uint8             FdPadding;  /*!< Set a Value for padding. It will be used
                                         when the Data length Code (DLC) specifies
                                         a bigger Data size than data_length to
                                         fill the MB */
    boolean BrsEn;                /*!< Enable bit Rate switch inside a CAN FD Format frame*/
} Can_Drv_MessageInfoType;

/**
 * @brief CAN message buffer structure
 */
typedef struct
{
    uint32 Cs;        /*!< Code and Status*/
    uint32 MsgId;     /*!< Message ID*/
    uint8  Data[64];  /*!< Data bytes of the CAN message*/
    uint8  DataLen;   /*!< Length of Data in bytes */
    uint32 TimeStamp; /*!< Free-Running Counter Time Stamp */
} Can_Drv_MsgBufType;

/**
 * @brief CAN message information
 */
typedef struct
{
    Can_Drv_MsgBufType         *MbMessagePtr; /*!< pointer to CAN message buffer*/
    boolean                     IsPolling;    /*!< polling Mode */
    boolean                     RemoteFlag;   /*!< Specifies if the frame is standard or remote */
    uint32                      TimeStamp;    /*!< TimeStamp of the Message*/
    Can_Drv_ControllerStateType State;        /*!< can message Status*/
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    volatile boolean IsDmaBusy; /*!<The State of the current DMA (idle/busy) */
#endif
} Can_Drv_MbHandleType;

/**
 *  @brief CAN driver State structures
 */
typedef struct Can_Drv_State
{
    Can_Drv_MbHandleType       Mb[CAN_DRV_MAX_MB_NUM]; /*!< Message buffer number */
    Can_Drv_RxFifoTransferType TransferType; /*!< Specifies if the Rx FIFO uses interrupts or DMA.
                                                It is only valid when RXFIFO is enabled */
    boolean RxFifoEn;                        /*!< select if use RX FIFO */
    boolean InterEn;                         /*!< Save Status of enabling/disabling interrupts */
    uint32  MaxMbNumber;                     /*!< The maximum number of Message Buffers */
    void (*IrqCallback)(uint8 Id, Can_Drv_IntType InterType, uint32 MbIdx,
                        const struct Can_Drv_State *State); /*!< irq callback function */
    void (*ErrCallback)(uint8 Id, Can_Drv_IntType InterType,
                        uint32 Data); /*!< error irq callback function */
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 RxFifoDMAChannel;
#endif
} Can_Drv_StateType;

/**
 * @brief CAN configuration
 */
typedef struct
{
    uint32                      MbMaxNum;          /*!< The maximum number of Message Buffers */
    boolean                     RxFifoEn;          /*!< select if use RX FIFO */
    Can_Drv_RxFifoFilterNumType RxFifoIdFilterNum; /*!< The number of RX FIFO ID filters needed. It
                                                      is only valid when RXFIFO is enabled */
    Can_Drv_RxFifoTransferType TransferType; /*!< Specifies if the Rx FIFO uses interrupts or DMA.
                                                It is only valid when RXFIFO is enabled */
    Can_Drv_ModeType      Mode;              /*!< CAN operation modes */
    boolean               BitRateSwitch;     /*!< Enable of BitRate Switch support for FD frames */
    Can_Drv_BitTimingType BitTiming;         /*!< The bitrate used for standard frames or for the
                                                arbitration phase of FD frames. */
    boolean                    FdEn;         /*!< Enable/Disable the Flexible Data Rate feature. */
    Can_Drv_FdPayloadBlockType Payload; /*!< The Payload size of the mailboxes specified in bytes.
                                      It is only valid when Flexible Data Rate feature is enabled*/
    Can_Drv_BitTimingType
        BitTimingFdData; /*!< The bitrate used for the Data phase of FD frames.
                        It is only valid when Flexible Data Rate feature is enabled */
    uint32 CtrlConfig;   /*!< The use of enhanced bit time segments Format from ExCBT register,
                            instead of CTRL1 or CBT register */
#if (CAN_DRV_FEATURE_HAS_DMA_ENABLE == STD_ON)
    uint8 RxFifoDMAChannel; /*!< Specifies the DMA Channel number to be used for DMA transfers. */
#endif
    void (*IrqCallback)(uint8 Id, Can_Drv_IntType InterType, uint32 MbIdx,
                        const struct Can_Drv_State *State); /*!< irq callback function */
    void (*ErrCallback)(uint8 Id, Can_Drv_IntType InterType,
                        uint32 Data); /*!< error irq callback function */
} Can_Drv_ConfigType;

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

/** @} end of group Can_Drv */

/** @} end of group Can_Module */

#endif /* CAN_DRV_TYPES_H */
