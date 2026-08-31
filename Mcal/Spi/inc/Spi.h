/**
 * @file    Spi.h
 * @version
 *
 * @brief   AUTOSAR Spi module interface
 * @details API implementation for SPI driver
 *
 * @addtogroup SPI_DRIVER Spi Driver
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Spi
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

#ifndef SPI_H
#define SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Spi_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Spi_PBCfg_C_REF_2

 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Spi_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID                      (180)
#define SPI_AR_RELEASE_MAJOR_VERSION       (4)
#define SPI_AR_RELEASE_MINOR_VERSION       (4)
#define SPI_AR_RELEASE_REVISION_VERSION    (0)
#define SPI_SW_MAJOR_VERSION               (2)
#define SPI_SW_MINOR_VERSION               (3)
#define SPI_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SPI configuration header file are of the same vendor */
#if (SPI_VENDOR_ID != SPI_VENDOR_ID_CFG)
#error "Spi.h and Spi_Cfg.h have different vendor ids"
#endif

/* Check if source file and SPI configuration header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif

/* Check if source file and SPI configuration header file are of the same software version */
#if ((SPI_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION_CFG) || \
     (SPI_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief
 * @note            trace: SWS_Spi_00382
 */
typedef enum
{
    SPI_POLLING_MODE                         = 0U, /**< Spi async transmit with polling mode */
    SPI_INTERRUPT_MODE                       = 1U, /**< Spi async transmit with interrupt mode */
} Spi_AsyncModeType;

/**
 * @brief           The type Spi_JobResultType defines a range of specific Jobs status for SPI Handler/Driver.
 * @note            trace: SWS_Spi_00374,SWS_Spi_00062
 */
typedef enum
{
    SPI_JOB_OK                               = 0U, /**<The last transmission of the Job has been finished successfully*/
    SPI_JOB_PENDING                          = 1U, /**<SPI Handler/Driver is performing a SPI Job.*/
    SPI_JOB_FAILED                           = 2U, /**<The last transmission of the Job has failed.*/
    SPI_JOB_QUEUED                           = 3U, /**<An asynchronous transmit Job has been accepted,
                                                       while actual transmission for this Job has not started yet.*/
} Spi_JobResultType;

/**
 * @brief           The type Spi_SeqResultType defines the range of specific Sequences status for SPI Handler/Driver
 * @note            trace: SWS_Spi_00375,SWS_Spi_00019
 */
typedef enum
{
    SPI_SEQ_OK                               = 0U, /**<The last transmission of the Sequence has been finished successfully*/
    SPI_SEQ_PENDING                          = 1U, /**<The SPI Handler/Driver is performing a SPI Sequence*/
    SPI_SEQ_FAILED                           = 2U, /**<The last transmission of the Sequence has failed.*/
    SPI_SEQ_CANCELLED                        = 3U, /**<The last transmission of the Sequence has been canceled by user*/
} Spi_SeqResultType;

/*! @brief SPI Peripheral Chip Select (PCS) configuration (which PCS to configure).
 * Implements : Spi_WhichPcsType_Class
 */
typedef enum
{
    SPI_PCS0                                 = 0U, /*!< PCS[0] */
    SPI_PCS1                                 = 1U, /*!< PCS[1] */
    SPI_PCS2                                 = 2U, /*!< PCS[2] */
    SPI_PCS3                                 = 3U, /*!< PCS[3] */
#if defined (CPU_YTM32B1HA0)
    SPI_PCS4                                 = 4U, /*!< PCS[4] */
    SPI_PCS5                                 = 5U, /*!< PCS[5] */
    SPI_PCS6                                 = 6U, /*!< PCS[6] */
    SPI_PCS7                                 = 7U, /*!< PCS[7] */
#endif
} Spi_WhichPcsType;

/*! @brief SPI Signal (PCS and Host Request) Polarity configuration.
 * Implements : spi_PcsPolarityType_Class
 */
typedef enum
{
    SPI_ACTIVE_HIGH                          = 1U, /*!< Signal is inactive High (idles low). */
    SPI_ACTIVE_LOW                           = 0U, /*!< Signal is inactive Low (idles high). */
} Spi_PcsPolarityType;

/*! @brief SPI clock phase configuration.
 * Implements : Spi_ClockPhaseType_Class
 */
typedef enum
{
    SPI_DATA_SHIFT_TRAILING                  = 0U,  /*!< Data shift on clock trailing edge, Data changed on clock trailing edge. */
    SPI_DATA_SHIFT_LEADING                   = 1U, /*!< Data shift on clock leading edge, Data changed on clock leading edge. */
} Spi_ClockPhaseType;

/*! @brief SPI Clock Signal (SCK) Polarity configuration.
 * Implements : Spi_ClockPolarityType_Class
 */
typedef enum
{
    SPI_SCK_IDLE_HIGH                        = 1U, /*!< Clock idles high. */
    SPI_SCK_IDLE_LOW                         = 0U, /*!< Clock idles low. */
} Spi_ClockPolarityType;

typedef enum
{
    SPI_RX_DATA_FLAG                         = 0x0U,        /*!< RX data flag */
    SPI_TX_DATA_FLAG                         = 0x1U,        /*!< TX data flag */
    SPI_WORD_COMPLETE                        = 0x2U,        /*!< Word Complete flag */
    SPI_FRAME_COMPLETE                       = 0x3U,        /*!< Frame Complete flag */
    SPI_TRANSFER_COMPLETE                    = 0x4U,        /*!< Transfer Complete flag */
    SPI_TRANSMIT_ERROR                       = 0x5U,        /*!< Transmit Error flag (FIFO underrun) */
    SPI_RECEIVE_ERROR                        = 0x6U,        /*!< Receive Error flag (FIFO overrun) */
    SPI_DATA_MATCH                           = 0x7U,        /*!< Data Match flag */
    SPI_MODULE_BUSY                          = 0x12U,       /*!< Module Busy flag */
    SPI_ALL_STATUS                           = 0x000000FCU, /*!< Used for clearing all w1c status flags */
} Spi_StatusFlagType;

typedef enum
{
    SPI_RX_DATA_INTERRUPT                    = 0x0U,        /*!< RX interrupt */
    SPI_TX_DATA_INTERRUPT                    = 0x1U,        /*!< TX interrupt */
    SPI_WORD_COMPLETE_INTERRUPT              = 0x2U,        /*!< Word Complete interrupt */
    SPI_FRAME_COMPLETE_INTERRUPT             = 0x3U,        /*!< Frame Complete interrupt */
    SPI_TRANSFER_COMPLETE_INTERRUPT          = 0x4U,        /*!< Transfer Complete interrupt */
    SPI_TRANSMIT_ERROR_INTERRUPT             = 0x5U,        /*!< Transmit Error interrupt (FIFO underrun) */
    SPI_RECEIVE_ERROR_INTERRUPT              = 0x6U,        /*!< Receive Error interrupt (FIFO overrun) */
    SPI_DATA_MATCH_INTERRUPT                 = 0x7U,        /*!< Data Match interrupt */
    SPI_ALL_INTERRUPT                        = 0xFFU,       /*!< Used for clearing all w1c interrupt flags */
}Spi_IntStatusType;

/*! @brief Type of SPI transfer (based on interrupts or DMA).
 * Implements : spi_transfer_type_Class
 */
typedef enum
{
    SPI_USING_POLLING                        = 0U, /**< @brief The driver will use DMA to perform SPI transfer */
    SPI_USING_INTERRUPTS                     = 1U, /**< @brief The driver will use interrupts to perform SPI transfer */
} Spi_TransferType;

/*! @brief Type of error reported by SPI
 */
typedef enum
{
    SPI_TRANSFER_OK                          = 0U,  /*!< Transfer OK */
    SPI_TRANSMIT_FAIL                        = 1U,  /*!< Error during transmission */
    SPI_RECEIVE_FAIL                         = 2U,  /*!< Error during reception */
    SPI_TRANSFER_TIMEOUT                     = 3U,  /*!< Transfer timed out */
} Spi_TransferStatusType;

typedef enum
{
    SPI_IB                                   = 0U, /**<The Channel is configured using Internal Buffer */
    SPI_EB                                   = 1U, /**<The Channel is configured using External Buffer */
    SPI_IB_EB                                = 2U, /**<The Channel is configured Both Buffer types are supported */
} Spi_BufferType;

typedef enum
{
    SPI_DRIVER_INITIALIZED                   = 0U,  /**<The Spi module is in initialization State */
    SPI_DRIVER_DEINITIALIZE                  = 1U,  /**<The Spi module is in uninitialized State */
} Spi_InitStatusType;

/**
 * @brief           defines a range of specific status for  SPI Handler/Driver.
*                   It informs about the SPI Handler/Driver status or specified SPI
*                   Hardware micro controller peripheral.
 * @note            trace: SWS_Spi_00373
 */
typedef enum
{
    SPI_UNINIT                               = 0x0U,  /**<The SPI Handler/Driver is not initialized or not usable */
    SPI_IDLE                                 = 0X1U,  /**<The SPI Handler/Driver is not currently transmitting any Job */
    SPI_BUSY                                 = 0X2U,  /**<The SPI Handler/Driver is performing a SPI Job */
} Spi_StatusType;

typedef enum
{
    SPI_0                                    = 0x0U,  /**<The SPI 0 instance number */
    SPI_1                                    = 0X1U,  /**<The SPI 1 instance number */
    SPI_2                                    = 0X2U,  /**<The SPI 2 instance number */
    SPI_3                                    = 0X3U,  /**<The SPI 3 instance number */
    SPI_4                                    = 0X4U,  /**<The SPI 4 instance number */
    SPI_5                                    = 0X5U,  /**<The SPI 5 instance number */
    SPI_6                                    = 0X6U,  /**<The SPI 6 instance number */
    SPI_7                                    = 0X7U,  /**<The SPI 7 instance number */
} Spi_InstanceNumType;

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief           Type of application data buffer elements.
 * @note            trace: SWS_Spi_00376
 */
typedef uint8 Spi_DataBufferType;

/**
 * @brief           Type for defining the number of data elements of the type Spi_DataBufferType to
 *                  send and / or receive by Channel.
 * @note            trace: SWS_Spi_00377
 */
typedef uint16 Spi_NumberOfDataType;

/**
 * @brief           Specifies the identification (ID) for a SPI Hardware micro controller peripheral (unit).
 * @note            trace: SWS_Spi_00381
 */
typedef uint8 Spi_HWUnitType;

/**
 * @brief           The type specifies the identification (ID) for a Channel.
 * @note            trace: SWS_Spi_00378
 */
typedef uint8 Spi_ChannelType;

/**
 * @brief           The type specifies the identification (ID) for a Job.
 * @note            trace: SWS_Spi_00379
 */
typedef uint16 Spi_JobType;

/*
 *@brief     To provide Job and Sequence Notification the following type will be used.
*/
typedef void(*Spi_NotifFunctionPtrType)(void);

/**
 * @brief           The type specifies the identification (ID) for a Sequence.
 * @note            trace: SWS_Spi_00380
 */
typedef uint8 Spi_SequenceType;

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#define SPI_JOB_PRIORITY_LEVELS_COUNT        (4U)   /** @brief The number of allowed job priority levels (0..3). */
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/**
*@brief    The definition for each Sequence.
*@trace    SWS_Spi_00064
*/
typedef struct
{
    Spi_NotifFunctionPtrType SeqEndNotification; /**< @brief Sequence finish end notification function*/
    Spi_JobType NumJobs;                /**< @brief Number of jobs in the sequence. */
    const Spi_JobType *JobIndexListPtr;   /**< @brief Pointer to a list of linked jobs */
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
    boolean Interruptible; /**< @brief Interruptible or not interruptible after each Job*/
#endif
} Spi_SequenceConfigType;

/**
* @brief   Internal structure used to manage the sequence State.
*/
typedef struct
{
    Spi_SeqResultType Result;             /**< @brief Seq Result. */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    const Spi_SequenceConfigType *SequencePtr; /**< @brief Pointer to the configuration. */
    const Spi_JobType *CurrentJobIndexPtr; /**< @brief Position in JobIndexList to the job in transmission of an async sequence. */
    Spi_JobType RemainingJobs;/**< @brief Number of jobs in a pending async sequence, not yet transmitted. */
#endif

} Spi_SequenceStateType;

/**
* @brief   Internal structure used to manage the job State.
*
*/
typedef struct
{
    Spi_JobResultType Result;             /**< @brief Job Result. */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    Spi_SequenceStateType *AsyncCrtSequenceStatePtr; /**< @brief Pointer to the State information of the async sequence. */
    Spi_JobType AsyncNextJob;/**< @brief Pointer to the next async job planned for transmission. */
#endif
} Spi_JobStateType;

/**
*@brief     The definition for each Job.
*@note      trace: SWS_Spi_00009
*/
typedef struct
{
    Spi_HWUnitType HWUnit;                         /**< @brief Assigned SPI HW Unit*/
    uint8 ExternalDeviceId;                         /**< @brief External Device Index*/
    sint8 Priority;                                /**< @brief JOb priority (4 levels are available from 0, the lower to 3, the higher)*/
    const Spi_ChannelType *ChannelLinkPtr;         /**< @brief Fixed link of Channels (at least one)*/
    Spi_ChannelType NumChannels;                   /**< @brief Number of Channels in the Job*/
    Spi_NotifFunctionPtrType JobEndNotification;   /**< @brief Job finish end notification function*/
    Spi_NotifFunctionPtrType JobStartNotification; /**< @brief Job  start notification function*/
    Spi_JobStateType *JobStatePtr;                 /**< @brief Pointer to the State information of the job*/
} Spi_JobConfigType;

typedef struct 
{
    uint8 Instance;                     /**<SPI hardware module instance */
    boolean IsSync;                     /**< @brief Indicates if the HW unit is configured as Sync or Async*/
}Spi_HWUnitConfigType;

/**
* @brief   This structure holds the HWUnit configuration parameters.
*/
typedef struct
{
    uint8 HWUnitId;                     /**< @brief HWUnit ID */
#if (SPI_SLAVE_SUPPORT == STD_ON)
    boolean SlaveMode;                  /**< @brief Slave mode or master mode*/
#endif
    Spi_WhichPcsType WhichPcs;          /**< @brief Assigned Chip Select pin*/
    uint8 DualEn;                       /**< @brief Chip select functionality on/off*/
    boolean SamplePoint;                /**< @brief Sample delay logic before data input or not under master mode*/
    uint8 PinConfig;                    /**< @brief Control the data input source and data output target */
    Spi_PcsPolarityType PcsPolarity;    /**< @brief Chip select pin polarity high or low*/
    uint32 BaudRate;                    /**< @brief Baud rate*/
    uint8 TimeClkToCs;                  /**< @brief Timing of clock to chip select*/
    uint8 TimeCsToClk;                  /**< @brief Timing between chip select to clock*/
    uint8 TimeCsToCs;                   /**< @brief Timing between chip select to chip select during transfer*/
    Spi_ClockPolarityType ClkPolarity;  /**< @brief Shift clock active low or active high, as opposed to idle*/
    Spi_ClockPhaseType ClkPhase;        /**< @brief clock phase*/
    uint32 SrcClk;                      /**< @brief Module source clock*/
    boolean IsSync;                     /**< @brief Indicates if the HW unit is configured as Sync or Async*/
    boolean IsPcsContinuous;            /**< @brief Keeps PCS asserted until transfer complete*/

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)

    boolean UseDma;                     /**< @brief Boolean flag indicating if DMA will be used or not for this SPI unit. */
    uint8 TxDmaChannel;                 /**< @brief Master TX DMA channel - enabled by the SPI TX source. */
    uint8 RxDmaChannel;                 /**< @brief RX DMA channel - enabled by the SPI RX source. */
#endif
#endif
} Spi_ExternalDeviceConfigType;

/**
* @brief   The structure contains the pointers to the Tx/Rx memory locations for the given buffer (IB or EB).
*
*/
typedef struct
{
    Spi_DataBufferType *BufferTXPtr; /**< @brief Transmit buffer pointer. */
    Spi_DataBufferType *BufferRXPtr; /**< @brief Receive buffer pointer. */
} Spi_BufferDescriptorType;

/**
* @brief    The definition for each Channel.
* @trace     SWS_Spi_00063
*/
typedef struct
{
    Spi_BufferType BufferType;                    /**< @brief Type Of Channel: EB/IB */
    uint8 DataWidth;                               /**< @brief Data frame size */
    Spi_NumberOfDataType Length;                   /**< @brief Data length */
    uint8 MsbOrLsbFirst;                           /**< @brief Bite order MSB or LSB */
    uint32 DefaultValue;                           /**< @brief Default transmit value*/
    Spi_BufferDescriptorType *BufferDescriptorPtr; /**< @brief Buffer Descriptor. */
} Spi_ChannelConfigType;

/**
* @brief   Internal structure used to manage the channel State.
*
*/
typedef struct
{
    uint8 Flags;                 /**< @brief Default Transmit Enabled. */
    Spi_NumberOfDataType Length; /**< @brief Actual Transfer size for EB. */
} Spi_ChannelStateType;

/**
* @brief Typedef for DEM error management implemented by MCAL drivers
*/
typedef struct
{
    uint8 State;   /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint16 Id ;     /**< ID of DEM error (0 if STD_OFF)*/
} Spi_DemErrorType;

/**
 * @brief  This is the top level structure containing all the initialization data for the SPI Handle driver.
 * @trace  SWS_Spi_00372
 *
 * @implements Spi_ConfigType_struct
 */
typedef struct
{

    Spi_ChannelConfigType *ChannelConfigPtr;                      /**< @brief Pointer to Array of SPI Channel Configurations */
    const Spi_JobConfigType *JobConfigPtr;                        /**< @brief Pointer to Array of SPI Job Configurations */
    const Spi_SequenceConfigType *SequenceConfigPtr;              /**< @brief Pointer to Array of SPI Sequence Configurations */
    const Spi_ExternalDeviceConfigType *ExternalDeviceConfigPtr;  /**< @brief Pointer to SPIx Module (HW Peripheral) Configuration */
    Spi_JobType MaxJob;                                           /**< @brief Max of Jobs Configured */
    Spi_ChannelType MaxChannel;                                   /**< @brief Max of Channels Configured */
    Spi_SequenceType MaxSequence;                                 /**< @brief Max of Sequences Configured */
    Spi_HWUnitType MaxHWUnitUsed;                                 /**< @brief Max of HW unit Configured */
    const Spi_HWUnitConfigType *HWUnitConfigPtr;                        /**< @brief Pointer to the HW unit configuration */
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    const Spi_DemErrorType SpiErrorHardwareCfg;                   /**< @brief SPI Driver DEM Error: SPI_E_HARDWARE_ERROR. */
#endif
} Spi_ConfigType;

/**
* @brief   This structure holds the HWUnit scheduling queue.
* @details For async transmissions, this structure holds the HWUnit scheduling queue .
*          For sync transmissions, only HWUnit Status is managed.
*
*/
typedef struct
{
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    Spi_JobType ScheduledJobsListHead[SPI_JOB_PRIORITY_LEVELS_COUNT];  /**< Array of the IDs of jobs to be scheduled, for each priority level. */
    Spi_JobType ScheduledJobsListTail[SPI_JOB_PRIORITY_LEVELS_COUNT];  /**< Array of the IDs of last jobs in queues, for each priority level. */
    sint8 MaxScheduledPriority;                                        /**< The highest value for priority of jobs. */
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
    Spi_StatusType Status;                                             /**< SPI State. */
} Spi_HWUnitQueueType;

/*!
 * @brief Runtime State structure for the SPI master driver.
 *
 * This structure holds data that is used by the SPI peripheral driver to
 * communicate between the transfer function and the interrupt handler. The
 * interrupt handler also uses this information to keep track of its progress.
 * The user must pass  the memory for this run-time State structure. The
 * SPI master driver populates the members.
 * Implements : spi_state_t_Class
 */
typedef struct
{
    uint16 BytesPerFrame;                                /**< Number of bytes per frame: 1- to 512-bytes */
    uint16 BitsPerFrame;                                 /**< @brief Number of bits per frame: 8- to 4096-bits; needed for TCR programming */
    boolean IsTransferInProgress;                        /**< @brief True if there is an active transfer */
    const Spi_DataBufferType *TxBuffPtr;                 /**< @brief The buffer from which transmitted bytes are taken */
    Spi_DataBufferType *RxBuffPtr;                       /**< @brief The buffer into which received bytes are placed */
    Spi_NumberOfDataType TxCount;                        /**< @brief Number of bytes remaining to send  */
    Spi_NumberOfDataType RxCount;                        /**< @brief Number of bytes remaining to receive */
    uint16 TxFrameCnt;                                   /**< @brief Number of bytes from current frame which were already sent */
    uint16 RxFrameCnt;                                   /**< @brief Number of bytes from current frame which were already received */
    uint8 FifoSize;                                      /**< @brief RX/TX fifo size */
    uint8 RxDMAChannel;                                  /**< @brief Channel number for DMA rx channel */
    uint8 TxDMAChannel;                                  /**< @brief Channel number for DMA tx channel */
    Spi_TransferStatusType TransferStatus;               /**< @brief The status of the current */
    boolean TransferUsingInterruptEn;                    /**< @brief The transfer type interrupt enable*/
    boolean DmaUsed;                                     /**< @brief Dma used or not*/
    Spi_TransferType TransferUsing;                      /**< @brief Type of SPI transfer: sync or async */
    Spi_AsyncModeType AsyncMode;                         /**< @brief async mod*/
    uint32 DefaultValue;                                 /**< @brief default value*/
    boolean LsbFirst;                                    /**< @brief True if first bit is LSB and false if first bit is MSB */
    Spi_WhichPcsType WhichPcs;                           /**< @brief Assigned Chip Select pin*/
    uint8 DualEn;                                        /**< @brief Chip select functionality on/off*/
    boolean SamplePoint;                                 /**< @brief Sample delay logic before data input or not under master mode*/
    uint8 PinConfig;                                     /**< @brief Control the data input source and data output target */
    Spi_PcsPolarityType PcsPolarity;                     /**< @brief Chip select pin polarity high or low*/
    uint32 BaudRate;                                     /**< @brief Baud rate*/
    uint8 TimeClkToCs;                                   /**< @brief Timing between clock and chip select*/
    uint8 TimeCsToClk;                                   /**< @brief Timing between chip select to clock  */
    uint8 TimeCsToCs;                                    /**< @brief Timing between chip select to chip select during transfer  */
    Spi_ClockPolarityType ClkPolarity;                   /**< @brief Shift clock active low or active high , as opposed to idle*/
    Spi_ClockPhaseType ClkPhase;                         /**< @brief clock phase */
    uint32 SrcClk;                                       /**< @brief Module source clock */
    boolean IsSync;                                      /**< @brief Indicates if the HW unit is configured as Sync or Async */
    boolean IsPcsContinuous;                             /**< @brief Keeps PCS asserted until transfer complete */
    uint32 PreScale;                                     /**< @brief Clock percale of following SPI clock */
    uint32 DivScale;                                     /**< @brief SPI Clock Divider */
    const Spi_JobConfigType *CurrentJobPtr;              /**< @brief Reference to the current job. */
    const Spi_ChannelType *CurrentChannelIndexPointerTX; /**< @brief Position in ChannelIndexList to the channel in transmission. */
    const Spi_ChannelType *CurrentChannelIndexPointerRX; /**< @brief Position in ChannelIndexList to the channel in reception. */
    Spi_ChannelType RemainingChannelsTX;                 /**< @brief Number of channels in a pending async job, not yet transmitted. */
    Spi_ChannelType RemainingChannelsRX;                 /**< @brief Number of channels in a pending async job, not yet received. */
#if (SPI_SLAVE_SUPPORT == STD_ON)
    boolean SlaveMode;                                   /**< @brief Slave mode or master mode*/
#endif
} Spi_StateType;

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief  Values used to denote NULL indexes.
*/
#define SPI_JOB_NULL            (0XFFFFU)
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */


#define SPI_INSTANCE_ID           ((uint8)0U)  /** @brief SPI MODULE INSTANCE ID */
#define SPI_MODULE_ID             ((uint8)83U)  /** @brief SPI MODULE ID */

#if (SPI_DEV_ERROR_DETECT == STD_ON)

/**
 * @defgroup        Spi_DEV_ERROR
 * @brief           SPI development errors
 * @{
 */
#define SPI_E_PARAM_POINTER       ((uint8)0x10)  /** @brief SPI API service is called using an invalid pointer  */
#define SPI_E_UNINIT              ((uint8)0x1A)  /** @brief SPI service used without module initialization*/
#define SPI_E_ALREADY_INITIALIZED ((uint8)0x4A)  /** @brief API SPI_Init service called while the SPI driver has already been initialized*/
#define SPI_E_PARAM_CHANNEL       ((uint8)0x0A)  /** @brief API service called with wrong parameter channel*/
#define SPI_E_PARAM_JOB           ((uint8)0x0B)  /** @brief API service called with wrong parameter job*/
#define SPI_E_PARAM_SEQ           ((uint8)0x0C)  /** @brief API service called with wrong parameter sequence*/
#define SPI_E_PARAM_LENGTH        ((uint8)0x0D)  /** @brief API service called with wrong parameter length*/
#define SPI_E_PARAM_UNIT          ((uint8)0x0E)  /** @brief API service called with wrong parameter unit*/
#define SPI_E_SEQ_EMPTY           ((uint8)0x4A)  /** @brief Sequence is empty, 0 job */
#define SPI_E_JOB_EMPTY           ((uint8)0x4B)  /** @brief JOB is empty, 0 channel */
#define SPI_E_CHANNEL_EMPTY       ((uint8)0x4C)  /** @brief Channel is empty*/
/** @} */
#endif

#define SPI_E_SEQ_PENDING         ((uint8)0x2A)  /** @brief Services called in a wrong sequence*/
#define SPI_E_SEQ_IN_PROCESS      ((uint8)0x3A)  /** @brief Synchronous transmission service*/

/**
 * @defgroup        Spi_SID
 * @brief           Service ID number for all SPI driver services
 */
/** @{ */
#define SPI_SID_ASYNC_TRANSMIT          (0x03U)  /** @brief API Service ID for Spi_AsyncTransmit */
#define SPI_SID_CANCEL                  (0x0CU)  /** @brief API Service ID for Spi_Cancel */
#define SPI_SID_DE_INIT                 (0x01U)  /** @brief API Service ID for Spi_DeInit */
#define SPI_SID_GET_HW_UNIT_STATUS      (0x0BU)  /** @brief API Service ID for Spi_GetHWUnitStatus */
#define SPI_SID_GET_JOB_RESULT          (0x07U)  /** @brief API Service ID for Spi_GetJobResult */
#define SPI_SID_GET_SEQUENCE_RESULT     (0x08U)  /** @brief API Service ID for Spi_GetSequenceResult */
#define SPI_SID_GET_STATUS              (0x06U)  /** @brief API Service ID for Spi_GetStatus */
#if (SPI_VERSION_INFO_API == STD_ON)
#define SPI_SID_GET_VERSION_INFO        (0x09U)  /** @brief API Service ID for Spi_GetVersionInfo */
#endif
#define SPI_SID_INIT                    (0x00U)  /** @brief API Service ID for Spi_Init */
#define SPI_SID_MAIN_FUNCTION_HANDLING  (0x10U)  /** @brief API Service ID for Spi_MainFunction_Handling */
#define SPI_SID_READ_IB                 (0x04U)  /** @brief API Service ID for Spi_ReadIB */
#define SPI_SID_SET_ASYNC_MODE          (0x0DU)  /** @brief API Service ID for Spi_SetAsyncMode */
#define SPI_SID_SETUP_EB                (0x05U)  /** @brief API Service ID for Spi_SetupEB */
#define SPI_SID_SYNC_TRANSMIT           (0x0AU)  /** @brief API Service ID for Spi_SyncTransmit */
#define SPI_SID_WRITE_IB                (0x02U)  /** @brief API Service ID for Spi_WriteIB */
/** @} */

#define SPI_CHANNEL_FLAG_TX_DEFAULT_U8      ((uint8) 0x01U)
#define SPI_CHANNEL_FLAG_RX_DISCARD_U8      ((uint8) 0x02U)

#define SPI_PHYUNIT_ASYNC                   (0U)

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                         EXTERNAL CONSTANTS
==================================================================================================*/

/**
* @brief Spi Channel State.
*/
extern Spi_ChannelStateType Spi_ChannelState[SPI_MAX_CHANNEL];
/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/**
* @brief   This function report production error SPI_E_HARDWARE_ERROR to DEM.
*
* @param[in]     EventStatus       Specifies the Event status
* @return        void
*
*/
void Spi_180_DemReportStatus(uint8 EventStatus);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief            Service to transmit data on the SPI bus.
 * @details          This function triggers the asynchronous transmission for the given sequence.
 * @param[in]        Sequence Sequence ID.
 *
 * @return           Std_ReturnType
 * @retval E_OK      Transmission command has been accepted
 * @retval E_NOT_OK  Transmission command has not been accepted
 *
 * @pre  The driver needs to be initialized before calling Spi_AsyncTransmit()
 *       otherwise, the function Spi_AsyncTransmit() shall raise the development error
 *       if SPI_DEV_ERROR_DETECT is STD_ON.
 * @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
 */
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if SPI_CANCEL_API == STD_ON
/**
 * @brief            Service cancels the specified on-going sequence transmission.
 * @details          This function is used to request the cancellation of the given sequence.
 * @param[in]        Sequence Sequence ID.
 *
 * @return           void
 *
 * @pre   The driver needs to be initialized before calling Spi_Cancel()
 *        otherwise, the function Spi_Cancel() shall raise the development error
 *        if SPI_DEV_ERROR_DETECT is STD_ON.
 * @pre   Pre-compile parameter SPI_CANCEL_API shall be STD_ON
 * @post  The SPI Handler Driver is not responsible on external devices damages or
 *        undefined State due to cancelling a sequence transmission.
 */
void Spi_Cancel(Spi_SequenceType Sequence);
#endif /* SPI_CANCEL_API == STD_ON */

/**
 * @brief            Service for SPI de-initialization.
 * @details          This function de-initializes the SPI driver using the pre-established configurations
 *
 * @return           Std_ReturnType
 * @retval E_OK      de-initialisation command has been accepted
 * @retval E_NOT_OK  de-initialisation command has not been accepted
 *
 */
Std_ReturnType Spi_DeInit(void);

#if SPI_HW_STATUS_API == STD_ON
/**
 * @brief            This service returns the status of the specified SPI Hardware micro controller peripheral.
 * @details          This function is used to request the status of a specific SPI peripheral unit.
 * @param[in]        HWUnit SPI Hardware micro controller peripheral (unit) ID.
 *
 * @return             Spi_StatusType
 * @retval SPI_UNINIT  The peripheral is un-initialized
 * @retval SPI_IDLE    The peripheral is in idle State
 * @retval SPI_BUSY    The peripheral is busy
 *
 */
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
#endif /* SPI_HW_STATUS_API == STD_ON */

/**
 * @brief            This service returns the last transmission result of the specified Job.
 * @details
 * @param[in]        Job Job ID. An invalid job ID will return an undefined result.
 *
 * @return           Spi_JobResultType
 * @retval SPI_JOB_OK        The job ended successfully
 * @retval SPI_JOB_PENDING   The job is pending
 * @retval SPI_JOB_FAILED    The job has failed
 * @retval SPI_JOB_QUEUED    The job has been accepted, while actual transmission is under schedule
 *
 */
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);

/**
 * @brief            This function is used to request the last transmission result of the specified Sequence.
 * @details
 * @param[in]        Sequence Sequence ID. An invalid sequence ID will return an undefined result.
 *
 * @return           Spi_SeqResultType
 * @retval SPI_SEQ_OK        The sequence ended successfully
 * @retval SPI_SEQ_PENDING   The sequence is pending
 * @retval SPI_SEQ_FAILED    The sequence has failed
 * @retval SPI_SEQ_CANCELLED The sequence has cancelled
 *
 */
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);

/**
 * @brief            This function returns the SPI Handler/Driver software module status.
 * @details
 *
 * @return             Spi_StatusType
 * @retval SPI_UNINIT  The driver is un-initialized
 * @retval SPI_IDLE    The driver has no pending transfers
 * @retval SPI_BUSY    The driver is busy
 *
 */
Spi_StatusType Spi_GetStatus(void);

/**
 * @brief            This function is used to initializes the SPI driver
 * @details          This function initializes the SPI driver using the pre-established configurations
 * @param[in]        ConfigPtr Specifies the pointer to the configuration set
 *
 * @return           void
 */
void Spi_Init(const Spi_ConfigType *ConfigPtr);

/**
 * @brief            This function shall asynchronously poll SPI interrupts and call ISR if appropriate.
 * @details          This function shall asynchronously poll SPI interrupts and call ISR if appropriate.
 *
 * @return           void
 *
 */
void Spi_MainFunction_Handling(void);

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
/**
 * @brief            This function reads synchronously one or more data from an IB SPI Handler/Driver Channel specified by parameter.
 * @details
 * @param[in]        Channel           Channel ID.
 * @param[in, out]   DataBufferPointer Pointer to destination data buffer in RAM
 *
 * @return Std_ReturnType
 * @retval E_OK      read command has been accepted
 * @retval E_NOT_OK  read command has not been accepted
 *
 */
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPointer);
#endif /* ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) ) */

#if SPI_LEVEL_DELIVERED == LEVEL2
/**
 * @brief            This function is to set the asynchronous mechanism mode for SPI busses handled asynchronously.
 * @details
 * @param[in]        Mode New mode required (SPI_POLLING_MODE or SPI_INTERRUPT_MODE).
 *
 * @return           Std_ReturnType
 * @retval E_OK      The command ended successfully
 * @retval E_NOT_OK  The command has failed
 *
 */
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);
#endif /* SPI_LEVEL_DELIVERED == LEVEL2 */

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
/**
 * @brief            Service to setup the buffers and the length of data for the EB SPI Handler/Driver Channel specified.
 * @details
 * @param[in]        Channel          Channel ID.
 * @param[in]        SrcDataBufferPtr Pointer to source data buffer.
 * @param[out]       DesDataBufferPtr Pointer to destination data buffer in RAM.
 * @param[in]        Length           Length (number of data elements) of the data to be transmitted from SrcDataBufferPtr and/or
                                      received from DesDataBufferPtr
                                          Min.: 1
                                          Max.: Max of data specified at configuration for this channel
 * @return           Std_ReturnType
 * @retval E_OK      Setup command has been accepted
 * @retval E_NOT_OK  Setup command has not been accepted
 *
 */
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, Spi_DataBufferType *SrcDataBufferPtr, \
                           Spi_DataBufferType *DesDataBufferPtr, Spi_NumberOfDataType Length);
#endif /* ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) ) */

#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)
/**
 * @brief            This function is used for synchronous transmission of a given sequence.
 * @details
 * @param[in]        Sequence Sequence ID.
 *
 * @return           Std_ReturnType
 * @retval E_OK      Transmission command has been completed successfully
 * @retval E_NOT_OK  Transmission command has not been accepted
 *
 */
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);
#endif /* (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2) */

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) ||  (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
/**
 * @brief            This function writes the data to an IB SPI Handler/Driver Channel specified by parameter.
 * @details
 * @param[in]        Channel       Channel ID.
 * @param[in]        DataBufferPtr Pointer to source data buffer. If this pointer is null, it is assumed that the data to be transmitted is not
 *                                      relevant and the default transmit value of this channel will be used instead.
 *
 * @return           Std_ReturnType
 * @retval E_OK      Command has been accepted
 * @retval E_NOT_OK  Command has not been accepted
 *
 */
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr);
#endif /* ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) ||  (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) ) */

#if (((SPI_VERSION_INFO_API == STD_ON) && (SPI_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 *
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           void
 */
#define Spi_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: SPI_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report SPI_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)SPI_MODULE_ID,                                        \
                SPI_INSTANCE_ID,                                              \
                SPI_SID_GET_VERSION_INFO,                                       \
                SPI_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = SPI_VENDOR_ID; \
            /* Spi module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = SPI_MODULE_ID; \
            /* Spi module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)SPI_SW_MAJOR_VERSION;                                  \
            /* Spi module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)SPI_SW_MINOR_VERSION;                                  \
            /* Spi module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)SPI_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }
#elif (((SPI_VERSION_INFO_API == STD_ON) && (SPI_DEV_ERROR_DETECT == STD_OFF)))
#define Spi_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = SPI_VENDOR_ID; \
        /* Spi module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = SPI_MODULE_ID; \
        /* Spi module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)SPI_SW_MAJOR_VERSION;                                  \
        /* Spi module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)SPI_SW_MINOR_VERSION;                                  \
        /* Spi module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)SPI_SW_PATCH_VERSION;                                  \
    }
#endif   /* SPI_VERSION_INFO_API == STD_ON && SPI_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/

extern const Spi_ConfigType *Spi_ConfigPtr;
extern Spi_JobStateType Spi_JobState[SPI_MAX_JOB];
extern Spi_HWUnitQueueType Spi_HwUnitQueues[SPI_MAX_HW_UNIT_USED];

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))

extern void Spi_ScheduleNextJob(Spi_HWUnitQueueType *HWUnitQueuePtr);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
extern void  Spi_ScheduleJob(Spi_HWUnitQueueType *HWUnitQueuePtr, Spi_JobType Job, const Spi_JobConfigType *JobConfigPtr);
#endif /* (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) */

extern void Spi_Lld_AsyncTransmitJob(const Spi_JobConfigType *JobConfigPtr);

#ifdef __cplusplus
}
#endif

#endif /* SPI_H */

/** @} */

