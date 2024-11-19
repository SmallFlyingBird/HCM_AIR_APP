/**************************************************************************************************/
/**
 * @file      : Spi_Types.h
 * @brief     : Spi AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_TYPES_H
#define SPI_TYPES_H

/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi
 *  @brief Spi driver wrapper
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Drvw_Types.h"
#include "Spi_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_TYPES_H_VENDOR_ID                   0x00B3U
#define SPI_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_TYPES_H_SW_MAJOR_VERSION            1U
#define SPI_TYPES_H_SW_MINOR_VERSION            2U
#define SPI_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Drvw_Types.h are the same vendor */
#if (SPI_TYPES_H_VENDOR_ID != SPI_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Spi_Types.h and Spi_Drvw_Types.h are different"
#endif
/* Check if current file and Spi_Drvw_Types.h are the same Autosar version */
#if ((SPI_TYPES_H_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (SPI_TYPES_H_AR_RELEASE_MINOR_VERSION != SPI_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (SPI_TYPES_H_AR_RELEASE_REVISION_VERSION != SPI_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Types.h and Spi_Drvw_Types.h are different"
#endif
/* Check if current file and Spi_Drvw_Types.h are the same Software version */
#if ((SPI_TYPES_H_SW_MAJOR_VERSION != SPI_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (SPI_TYPES_H_SW_MINOR_VERSION != SPI_DRVW_TYPES_H_SW_MINOR_VERSION) ||                        \
     (SPI_TYPES_H_SW_PATCH_VERSION != SPI_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Types.h and Spi_Drvw_Types.h are different"
#endif

/* Check if current file and Spi_Cfg.h are the same vendor */
#if (SPI_TYPES_H_VENDOR_ID != SPI_CFG_H_VENDOR_ID)
    #error "Vendor ID of Spi_Types.h Spi_Cfg.h and are different"
#endif
/* Check if current file and Spi_Cfg.h are the same Autosar version */
#if ((SPI_TYPES_H_AR_RELEASE_MAJOR_VERSION != SPI_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SPI_TYPES_H_AR_RELEASE_MINOR_VERSION != SPI_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SPI_TYPES_H_AR_RELEASE_REVISION_VERSION != SPI_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Types.h and Spi_Cfg.h are different"
#endif
/* Check if current file and Spi_Cfg header file are the same Software version */
#if ((SPI_TYPES_H_SW_MAJOR_VERSION != SPI_CFG_H_SW_MAJOR_VERSION) ||                               \
     (SPI_TYPES_H_SW_MINOR_VERSION != SPI_CFG_H_SW_MINOR_VERSION) ||                               \
     (SPI_TYPES_H_SW_PATCH_VERSION != SPI_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Types.h and Spi_Cfg.h are different"
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
/**
 * @brief   This type defines a range of specific status for SPI Handler Driver.
 *
 */
typedef enum
{
    SPI_UNINIT = 0, /*!< The SPI Handler/Driver is not initialized or not usable. */
    SPI_IDLE,       /*!< The SPI Handler/Driver is not currently transmitting any jobs. */
    SPI_BUSY        /*!< The SPI Handler/Driver is performing a SPI Job(transmit). */
} Spi_StatusType;

/**
 * @brief   This type defines a range of specific Jobs status for SPI Handler Driver.
 */
/* SWS_Spi_00374 */
typedef enum
{
    SPI_JOB_OK = 0,  /*!< The last transmission of the Job has been finished successfully. */
    SPI_JOB_PENDING, /*!< The SPI handler/Driver is performing a SPI Job. */
    SPI_JOB_FAILED,  /*!< The last transmission of the Job has failed. */
    SPI_JOB_QUEUED   /*!< An asynchronous transmit Job has been accepted, while actual
                                  transmission for this Job has not started yet. */
} Spi_JobResultType;

/**
 * @brief   This type defines a range of specific Sequences status for SPI Handler Driver.
 */
typedef enum
{
    SPI_SEQ_OK = 0,   /*!< The last transmission of the Sequence has been finished successfully. */
    SPI_SEQ_PENDING,  /*!< The SPI handler/Driver is performing a SPI Sequence, The meaning of this
                         status is equal to SPI_BUSY */
    SPI_SEQ_FAILED,   /*!< The last transmission of the Sequence has failed. */
    SPI_SEQ_CANCELLED /*!< The last transmission of the Sequence has been cancelled by the user. */
} Spi_SeqResultType;

/**
 * @brief Specifies the asynchronous mechanism mode for SPI buses handled asynchronously in Level2
 *
 */
/* SWS_Spi_00382 */
typedef enum
{
    SPI_POLLING_MODE = 0, /*!< The asynchronous mechanism is ensured by polling, so interrupts
                             related to SPI buses handled asynchronously are disabled. */
    SPI_INTERRUPT_MODE    /*!< The asynchronous mechanism is ensured by interrupt, so interrupts
                             related to SPI buses handled asynchronously are enabled. */
} Spi_AsyncModeType;

/**
 * @brief Type of application data buffer elements.
 */
/* SWS_Spi_00376 */
typedef Spi_Drvw_DataBufferType Spi_DataBufferType;

/**
 * @brief Type for defining the number of data elements of the type Spi_DataBufferType
 *          to send and/or receive by Channel.
 */
/* SWS_Spi_00377 */
typedef Spi_Drvw_NumberOfDataType Spi_NumberOfDataType;

/**
 * @brief   Specifies the identification (ID) for a Channel.
 */
typedef uint8 Spi_ChannelType;

/**
 * @brief   Specifies the identification (ID) for a Job.
 */
typedef uint16 Spi_JobType;

/**
 * @brief   Specifies the identification (ID) for a sequence of jobs.
 */
typedef uint8 Spi_SequenceType;

/**
 * @brief   Specifies the identification (ID) for a SPI Hardware microcontroller peripheral (unit).
 */
/* SWS_Spi_00381 */
typedef Spi_Drvw_HWUnitType Spi_HWUnitType;

/**
 * @brief     Contains the ID of an external device.
 * @details  This contains the identification (ID) of the external device for which
 *            there's a collection of particular settings
 */
typedef uint8 Spi_ExternalDeviceType;

typedef void(Spi_NotifyType)(void);

/**
 * @brief   This structure contains all the needed data to configure one SPI Sequence.
 */
typedef struct
{
    Spi_JobType        JobNum;        /*!< Number of jobs in the sequence */
    uint32             SpiCoreUse;    /*!< CoreID used */
    const Spi_JobType *JobIndexList;  /*!< Job index list */
    Spi_NotifyType(*EndNotification); /*!< Job notification handler */
    uint8 Interruptible;              /*!< interruptible or not */
} Spi_SequenceConfigType;

/**
 * @brief   This structure contains Sequence configuration.
 */
typedef struct
{
    const Spi_SequenceConfigType *SeqConfig; /*!< Pointer to Sequence configuration */
} Spi_SequenceConfigListType;

/**
 * @brief   Internal structure used to manage the sequence state.
 */
typedef struct
{
    Spi_SeqResultType Result; /*!< Sequence Result */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    const Spi_SequenceConfigType *Sequence;    /*!< Pointer to the configuration */
    const Spi_JobType *CurrentJobIndexPointer; /*!< Number of jobs in a pending async sequence, not
                                                  yet transmitted */
    Spi_JobType
        RemainingJobs; /*!< Number of jobs in a pending async sequence, not yet transmitted */
#endif
} Spi_SequenceStateType;

/**
 * @brief   Internal structure used to manage the job state.
 */
typedef struct
{
    Spi_JobResultType Result; /*!< Job Result */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    Spi_SequenceStateType
               *AsyncSequenceState; /*!< Pointer to the state information of the async sequence */
    Spi_JobType AsyncNextJob;       /*!< Pointer to the next async job planned for transmission */
#endif
} Spi_JobStateType;

/**
 * @brief   This is the structure containing all the parameters needed to completely define a Job.
 */
typedef struct
{
    Spi_ChannelType        ChannelNum;       /*!< Number of channels in the job */
    const Spi_ChannelType *ChannelIndexList; /*!< Channel index list */
    Spi_NotifyType(*EndNotification);        /*!< Job end notification */
    Spi_NotifyType(*StartNotification);      /*!< Job start notification */
    sint8                  Priority;         /*!< Priority */
    uint32                 SpiCoreUse;       /*!< CoreID used */
    Spi_JobStateType      *JobState;         /*!< Job State */
    Spi_HWUnitType         HWUnit;           /*!< HWUnit */
    Spi_ExternalDeviceType ExternalDevice;   /*!< ExternalDevice */
    const Spi_Drvw_ExternalDeviceListType
        *ExternalDeviceConfig; /*!< Pointer to External Device Configuration */
} Spi_JobConfigType;

/**
 * @brief   This is the structure containing Job configuration.
 */
typedef struct
{
    const Spi_JobConfigType *JobConfig; /*!< Pointer to Job configuration */
} Spi_JobConfigListType;

/**
 * @brief   This structure holds the HWUnit scheduling queue.
 * @details For async transmissions, this structure holds the HWUnit scheduling queue .
 *          For sync transmissions, only HWUnit Status is managed.
 */
typedef struct
{
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    Spi_JobType ScheduledJobsListHead[SPI_JOB_PRIORITY_LEVELS_COUNT];
    Spi_JobType ScheduledJobsListTail[SPI_JOB_PRIORITY_LEVELS_COUNT];
    sint8       MaxScheduledPriority; /*!< Maximum scheduled priority. */
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
    Spi_StatusType  Status;  /*!< SPI state. */
    Spi_ChannelType Channel; /*!< Current channel index in Job */
    Spi_JobType     Job;     /*!< Current job index */
} Spi_HWUnitQueue;

/**
 * @brief   The structure contains the channel configuration.
 */
typedef struct
{
    /** @brief Pointer to Channel configuration. */
    const Spi_Drvw_ChannelConfigType *ChannelConfig;
} Spi_ChannelConfigListType;

/**
 * @brief   This is the top level structure containing all the
 *          needed parameters for the SPI Handler Driver.
 */
typedef struct
{
    uint16           MaxExternalDevice; /*!< Number of configured external devices */
    Spi_ChannelType  SpiMaxChannel;     /*!< Number of channels configured */
    Spi_JobType      SpiMaxJob;         /*!< Number of configured jobs */
    Spi_SequenceType SpiMaxSequence;    /*!< Number of configured sequences */
    uint32           SpiCoreUse;        /*!< CoreID used */
    const Spi_ChannelConfigListType
                                *ChannelConfigList; /*!< Pointer to Array of configured channels */
    const Spi_JobConfigListType *JobConfigList;     /*!< Pointer to Array of configured channels */
    const Spi_SequenceConfigListType
        *SequenceConfigList; /*!< Pointer to Array of configured sequences  */
    const Spi_Drvw_ExternalDeviceListType
        *ExternalDeviceConfigList; /*!< Pointer to Array of configured External devices */
    const Spi_Drvw_HWUnitConfigListType
        *HWUnitConfigList; /*!< Pointer to Array of SPI device instances */
} Spi_ConfigType;

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi */

/** @} end of group Spi_Module */

#endif /*SPI_TYPES_H*/
