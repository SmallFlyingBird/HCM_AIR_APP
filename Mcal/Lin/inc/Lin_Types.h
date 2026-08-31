/**
 * @file    Lin.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin module interface
 * @details API implementation for LIN driver
 *
 * @addtogroup LIN_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lin
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_TYPES_H
#define LIN_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Lin_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Lin_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Lin_GeneralTypes.h"
#include "Lin_Cfg.h"
#if (LIN_DEM_DISABLE == STD_OFF)
#include "Dem.h"
#endif
#if (LIN_IP_UART == STD_ON)
#include "Gpt.h"
#endif

/*==================================================================================================
 *                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_TYPES_VENDOR_ID                      (180)
#define LIN_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define LIN_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define LIN_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define LIN_TYPES_SW_MAJOR_VERSION               (2)
#define LIN_TYPES_SW_MINOR_VERSION               (3)
#define LIN_TYPES_SW_PATCH_VERSION               (0)
/* update, notion: the version 4.2.2 Change to 4.4.0 for build ,without check */

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and LIN configuration header file are of the same vendor */
#if (LIN_TYPES_VENDOR_ID != LIN_GENERALTYPES_VENDOR_ID)
#error "Lin_Types.h and Lin_GeneralTypes.h have different vendor ids"
#endif

/* Check if source file and LIN configuration header file are of the same Autosar version */
#if ((LIN_TYPES_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_TYPES_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_TYPES_AR_RELEASE_REVISION_VERSION != LIN_GENERALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lin_Types.h and Lin_GeneralTypes.h are different"
#endif

/* Check if source file and LIN configuration header file are of the same software version */
#if ((LIN_TYPES_SW_MAJOR_VERSION != LIN_GENERALTYPES_SW_MAJOR_VERSION) || \
     (LIN_TYPES_SW_MINOR_VERSION != LIN_GENERALTYPES_SW_MINOR_VERSION) || \
     (LIN_TYPES_SW_PATCH_VERSION != LIN_GENERALTYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lin_Types.h and Lin_GeneralTypes.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief LIN MODULE INSTANCE ID */
#define LIN_INSTANCE_ID             ((uint8)0U)
#define LIN_INSTANCE_ALL_ID         ((uint8)255U)

/** @brief LIN MODULE ID */
#define LIN_MODULE_ID               ((uint8)82U)

#if (LIN_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        Lin_DEV_ERROR
 * @brief           LIN development errors
 * @{
 */

/** @brief API service used without module initialization. */
#define LIN_E_UNINIT                ((uint8)0x00U)

/** @brief API service used with an invalid or inactive channel parameter. */
#define LIN_E_INVALID_CHANNEL       ((uint8)0x02U)

/** @brief API service called with invalid configuration pointer. */
#define LIN_E_INVALID_POINTER       ((uint8)0x03U)

/** @brief Invalid state transition for the current state. */
#define LIN_E_STATE_TRANSITION      ((uint8)0x04U)

/** @brief API service called with a NULL pointer or not valid parameter. */
#define LIN_E_PARAM_POINTER         ((uint8)0x05U)

/** @brief API service called with a NULL pointer or not valid parameter. */
#define LIN_E_INVALID_LINNODETYPE   ((uint8)0x06U)

/* Additional Lin Det_ErrorId*/
#define LIN_E_TIMEOUT               ((uint8)0x08U)

#define LIN_E_TIMER_UNINIT          ((uint8)0x09U)

#define LIN_E_LINTST_TESTING        ((uint8)0x2FU)

/** @} */
#endif

/**
 * @defgroup        Lin_SID
 * @brief           Service ID number for all LIN driver services
 * @{
 */
/** @brief API Service ID for Lin_CheckWakeup */
#define LIN_SID_CHECK_WAKEUP                                 (0x0aU)
/** @brief API Service ID for Lin_GetStatus */
#define LIN_SID_GET_STATUS                                   (0x08U)
/** @brief API Service ID for Lin_GetVersionInfo */
#define LIN_SID_GET_VERSION_INFO                             (0x01U)
/** @brief API Service ID for Lin_GoToSleep */
#define LIN_SID_GO_TO_SLEEP                                  (0x06U)
/** @brief API Service ID for Lin_GoToSleepInternal */
#define LIN_SID_GO_TO_SLEEP_INTERNAL                         (0x09U)
/** @brief API Service ID for Lin_Init */
#define LIN_SID_INIT                                         (0x00U)
/** @brief API Service ID for Lin_SendFrame */
#define LIN_SID_SEND_FRAME                                   (0x04U)
/** @brief API Service ID for Lin_Wakeup */
#define LIN_SID_WAKEUP                                       (0x07U)
/** @brief API Service ID for Lin_WakeupInternal */
#define LIN_SID_WAKEUP_INTERNAL                              (0x0bU)
/** @brief API Service ID for Lin_Init */
#define LIN_SID_DEINIT                                       (0x0fU)
/** @} */

#ifndef LIN_MASTER_API_SUPPORT
#define LIN_MASTER_API_SUPPORT                               (STD_ON)
#endif
#ifndef LIN_DEINIT_API_SUPPORT
#define LIN_DEINIT_API_SUPPORT                               (STD_OFF)
#endif

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief LIN State enum
 */
typedef enum
{
    LIN_DRV_UNINIT              = 0x01U,  /**< @brief The LIN_INIT state indicates that the LIN driver has
                                                been initialized, making each available channel ready
                                                for service.. */
    LIN_DRV_INIT                = 0x02U,  /**< @brief LIN driver has been initialized, making each available
                                                channel ready for service. */
    LIN_DRV_CH_SLEEP_PENDING    = 0x03U,  /**< @brief LIN start to trans to sleep mode */
    LIN_DRV_CH_SLEEP            = 0x04U,  /**< @brief LIN channel under sleep mode */
    LIN_DRV_CH_OPERATIONAL      = 0x05U,  /**< @brief LIN channel is initialized and ready for procress frame. */
    LIN_DRV_CH_NOT_READY        = 0x06U,  /**< @brief LIN channel is not ready to process a frame. */
    LIN_DRV_CH_READY            = 0x07U,  /**< @brief LIN channel is ready to process a frame. */
    LIN_DRV_CH_TX_COMPLETE      = 0x08U,  /**< @brief LIN channel sent a frame without any error. */
    LIN_DRV_CH_RX_COMPLETE      = 0x09U,  /**< @brief LIN channel received a frame without any error. */
    LIN_DRV_CH_HEADER_SENT      = 0x0AU,  /**< @brief LIN channel sent header and no response received yet. */
    LIN_DRV_CH_STS_HEADER_SENT  = 0x0BU,  /**< @brief LIN channel is send a slave to slave frame head. */
} Lin_DrvStateType;

typedef enum
{
    LIN_DRV_NO_ERROR            = 0x00U,  /**< @brief No error */
    LIN_DRV_BIT_ERROR           = 0x01U,  /**< @brief Bit error during header or data transimission. */
    LIN_DRV_CHECKSUM_ERROR      = 0x02U,  /**< @brief Channel checksum not correct. */
    LIN_DRV_SYNCH_FIELD_ERROR   = 0x03U,  /**< @brief Sync field value error. */
    LIN_DRV_BREAK_FIELD_ERROR   = 0x04U,  /**< @brief Break delimiter too short (< 1 bit). */
    LIN_DRV_ID_PARITY_ERROR     = 0x05U,  /**< @brief ID field parity check failed. */
    LIN_DRV_HEADER_FRAMING_ERROR = 0x06U, /**< @brief Invalid stop bit detected in field. */
    LIN_DRV_FRAMING_ERROR       = 0x07U,  /**< @brief Invalid stop bit detected in data or header field. */
    LIN_DRV_OVERRUN_ERROR       = 0x08U,  /**< @brief New data received when receive buffer is already full. */
    LIN_DRV_NOISE_ERROR         = 0x09U,  /**< @brief Noise detected when receiving data or header. */
    LIN_DRV_TIMEOUT_ERROR       = 0x0AU,  /**< @brief Header or response timeout detected. */
    LIN_DRV_UNDERRUN_ERROR      = 0x0BU,  /**< @brief TX need new data while tx buffer is empty. */
} Lin_DrvErrorType;

typedef enum
{
    LIN_DRV_TX_MASTER_RES_CMD   = 0x01U,  /**< @brief Master transmit a frame, response by master. */
    LIN_DRV_TX_SLAVE_RES_CMD    = 0x02U,  /**< @brief Master receive a frame, response by slave. */
    LIN_DRV_TX_SLEEP_CMD        = 0x03U,  /**< @brief Transmitted frame is a sleep command frame. */
    LIN_DRV_TX_NO_CMD           = 0x04U,  /**< @brief No master command pending. */
    LIN_DRV_SLAVE_TO_SLAVE_CMD  = 0x05U   /**< @brief Transmitted frame is from slave to slave. */
} Lin_DrvCommandType;

typedef enum
{
    MASTER_10_BIT_BREAK_LENGTH   = 0x00U,
    MASTER_11_BIT_BREAK_LENGTH   = 0x01U,
    MASTER_12_BIT_BREAK_LENGTH   = 0x02U,
    MASTER_13_BIT_BREAK_LENGTH   = 0x03U,
    MASTER_14_BIT_BREAK_LENGTH   = 0x04U,
    MASTER_15_BIT_BREAK_LENGTH   = 0x05U
} Lin_MasterBreakLengthType;

typedef enum
{
    SLAVE_11_BIT_BREAK_LENGTH    = 0x00U,
    SLAVE_10_BIT_BREAK_LENTH     = 0x01U
} Lin_SlaveSyncBreakLengthType;

typedef enum
{
    LIN_SLAVE_MODE              = 0x00U,
    LIN_MASTER_MODE             = 0x01U
} Lin_LinNodeModeType;

typedef enum
{
    LINFLEXD_IP_0               = 0x00U,
    LINFLEXD_IP_1               = 0x01U,
    LINFLEXD_IP_2               = 0x02U,
    LINFLEXD_IP_3               = 0x03U,
    LINFLEXD_IP_4               = 0x04U,
    LINFLEXD_IP_5               = 0x05U,
    LINFLEXD_IP_6               = 0x06U,
    LINFLEXD_IP_7               = 0x07U,
    LINFLEXD_IP_8               = 0x08U,
    LINFLEXD_IP_9               = 0x09U,
    LINFLEXD_IP_10              = 0x0AU,
    LINFLEXD_IP_11              = 0x0BU,
    LINFLEXD_IP_12              = 0x0CU,
    LINFLEXD_IP_13              = 0x0DU,
    LINFLEXD_IP_14              = 0x0EU,
    LINFLEXD_IP_15              = 0x0FU,
    UART_IP_0                   = 0x40U,
    UART_IP_1                   = 0x41U,
    UART_IP_2                   = 0x42U,
    UART_IP_3                   = 0x43U,
    UART_IP_4                   = 0x44U,
    UART_IP_5                   = 0x45U,
    UART_IP_6                   = 0x46U,
    UART_IP_7                   = 0x47U,
    UART_IP_8                   = 0x48U,
    UART_IP_9                   = 0x49U,
    UART_IP_10                  = 0x4AU,
    UART_IP_11                  = 0x4BU,
    UART_IP_12                  = 0x4CU,
    UART_IP_13                  = 0x4DU,
    UART_IP_14                  = 0x4EU,
    UART_IP_15                  = 0x4FU,
} Lin_ChHardwareIdType;



/**
 * @brief LIN Hardware State
 *
 */
typedef enum
{
    LIN_DRV_HW_SLEEP_MODE       = 0U,   /**<@brief LINFlexD is in sleep mode to reduce 
                                                 power consumption. */
    LIN_DRV_HW_INIT_MODE        = 1U,   /**<@brief LINFlexD is in initialization mode. */
    LIN_DRV_HW_IDLE_MODE        = 2U,   /**<@brief LINFlexD is in idle mode. */
    LIN_DRV_HW_BREAK            = 3U,   /**<@brief LINFlexD is sending or receiving break field. */
    LIN_DRV_HW_BREAK_DELIMITER  = 4U,   /**<@brief LINFlexD slave received a valid break or master */
    LIN_DRV_HW_SYNC_FIELD       = 5U,   /**<@brief LINFlexD slave received break delimiter and
                                                 receiving sync field or master is sending sync byte. */
    LIN_DRV_HW_ID_FIELD         = 6U,   /**<@brief LINFlexD slave is receiving identifier field or
                                                 master is sending identifier field. */
    LIN_DRV_HW_HEADER_FIELD     = 7U,   /**<@brief LINFlexD slave received a valid header or master
                                                 finished header transmission. */
    LIN_DRV_HW_DATA_FIELD       = 8U,   /**<@brief LINFlexD is receiving or tranmitting data field. */
    LIN_DRV_HW_CHECKSUM_FIELD   = 9U,   /**<@brief LINFlexD receiving or tranmitting checksum field. */
#if (LIN_IP_UART == STD_ON)
    LIN_DRV_HW_WAKEUP_FIELD     = 10U   /**<@brief LINFlexD is tranmitting wakeup field, only for UART IP. */
#endif
} Lin_Drv_HwStatusType;

typedef enum
{
    LIN_DRV_UART_NO_CMD         = 0x00U,   /**< @brief No command pending. */
    LIN_DRV_UART_WAKEUP_REQ_CMD = 0x01U,   /**< @brief Master transmit a frame, response by master. */
    LIN_DRV_UART_SLEEP_CMD      = 0x02U,   /**< @brief Master receive a frame, response by slave. */
    LIN_DRV_UART_BREAK_CMD      = 0x03U,   /**< @brief Transmitted frame is a sleep command frame. */
    LIN_DRV_UART_SYNC_CMD       = 0x04U,   /**< @brief No master command pending. */
    LIN_DRV_UART_ID_CMD         = 0x05U,   /**< @brief Transmitted frame is from slave to slave. */
    LIN_DRV_UART_TX_CMD         = 0x06U,   /**< @brief No master command pending. */
    LIN_DRV_UART_RX_CMD         = 0x07U,   /**< @brief Transmitted frame is from slave to slave. */
    LIN_DRV_UART_CS_CMD         = 0x08U    /**< @brief Transmitted frame is from slave to slave. */
} Lin_DrvUartTimerCommandType;

typedef enum
{
    LIN_DRV_UART_DIR_RECEIVE     = 0x00U,   /**< @brief enhanced checksum. */
    LIN_DRV_UART_DIR_TRANSMIT    = 0x01U,   /**< @brief classic checksum. */
} Lin_DrvUartDirType;

typedef enum
{
    LIN_DRV_TO_BREAK             = 0x01U,   /**< @brief Breake Timeout tick type*/
    LIN_DRV_TO_HEADER            = 0x02U,   /**< @brief Header Timeout tick type*/
    LIN_DRV_TO_M_RECEIVE         = 0x03U,   /**< @brief Master receive Timeout tick type*/
    LIN_DRV_TO_S_RECEIVE         = 0x04U,   /**< @brief Slave receive Timeout tick type*/
} Lin_DrvTimeoutType;
/*==================================================================================================
 *                                      GLOBAL TYPEDEFS
==================================================================================================*/
#if (LIN_DEM_DISABLE == STD_OFF)
typedef struct{
    Dem_EventIdType EventId;                 /*!< Lin Dem event ID */
    Dem_EventStatusType  EventStatus;        /*!< Lin Dem event Status. */
} Lin_DemConfigType;
#endif

/**
 * @brief           LIN channel configuration type structure.
 * @details         This is the type of the external data structure containing
 *                  the overall initialization data for one LIN Channel.
 *                  A pointer to such a structure is provided to the LIN channel
 *                  initialization routine for configuration of the LIN hardware
 *                  channel.
 */
typedef  struct
{
    uint8 LinChannelId;                             /*!< Lin channel ID */
    Lin_ChHardwareIdType LinHwChannel;              /*!< Lin hardware channel ID */
    Lin_LinNodeModeType LinNodeMode;                /*!< MASTER or SLAVE mode */
    uint8 LinChWakeSupport;                         /*!< Weather channel support wake-up */
    /*!< [LIN098] This parameter contains a reference to the Wakeup Source for this controller as defined in the ECU State Manager. */
    EcuM_WakeupSourceType LinChEcuMWakeupSource;
    Lin_MasterBreakLengthType LinChBreakLength;         /*!< Break length in master mode */
    Lin_SlaveSyncBreakLengthType LinDetectBreakLength;  /*!< Break length in slave mode */
    uint32 LinClockRef;                             /*!< Lin clock reference */
    uint8 ResponseTimeoutValue;                     /*!< Response timeout value */
    uint8 HeaderTimeoutValue;                       /*!< Header timeout value */
    uint16 LinBaudrateRegValue;                     /*!< Lin baudrate configuration */
    boolean LinFilterEnable;                        /*!< Specific weather to enable Lin filters */
    uint8 LinFilterNum;                             /*!< Lin filter count */
    const uint8 *LinFilterIdPtr;                    /*!< Pointer to Lin filter configuration */
} Lin_ChConfigType;

typedef struct{
    uint8 LinChCount;                               /*!< Lin channel count */
    const Lin_ChConfigType *LinChConfigPtrs;        /*!< Pointer to precompile channel configuration. */
    const uint8 *LinInstMapPtr;                     /*!< Pointer to Lin channel instance map. */
#if (LIN_DEM_DISABLE == STD_OFF)
    const Lin_DemConfigType *LinDemConfigPtr;       /*!< Pointer to DemConfig. */
#endif
#if (LIN_FRAME_TIMEOUT_DISABLE == STD_OFF)  /* timeout update*/
#if (LIN_IP_UART == STD_ON)
    Gpt_ChannelType LinTimerSourceId;
    uint32 LinTimerClockRef;
#endif
#endif
} Lin_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* LIN_H */

/** @} */

