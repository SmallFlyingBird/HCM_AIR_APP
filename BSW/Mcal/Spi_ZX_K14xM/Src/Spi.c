/**************************************************************************************************/
/**
 * @file      : Spi.c
 * @brief     : Spi AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Spi_Module
 *  @{
 */

/** @addtogroup Spi
 *  @brief Spi AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Spi.h"
#include "Spi_Drvw.h"
#include "Det.h"
#include "SchM_Spi.h"
#if (SPI_E_HARDWARE_ERROR_ENABLE == STD_ON)
    #include "Dem.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_C_VENDOR_ID                   0x00B3U
#define SPI_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_C_SW_MAJOR_VERSION            1U
#define SPI_C_SW_MINOR_VERSION            2U
#define SPI_C_SW_PATCH_VERSION            2U

/* Check if current file and Spi.h are the same vendor */
#if (SPI_C_VENDOR_ID != SPI_VENDOR_ID)
    #error "Vendor ID of Spi.c and Spi.h are different"
#endif
/* Check if current file and Spi.h are the same Autosar version */
#if ((SPI_C_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION) ||                           \
     (SPI_C_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION) ||                           \
     (SPI_C_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi.c and Spi.h are different"
#endif
/* Check if current file and Spi header file are the same Software version */
#if ((SPI_C_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION) ||                                           \
     (SPI_C_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION) ||                                           \
     (SPI_C_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION))
    #error "Software Version of Spi.c and Spi.h are different"
#endif

/* Check if current file and Spi_Drvw.h are the same vendor */
#if (SPI_C_VENDOR_ID != SPI_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Spi.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Autosar version */
#if ((SPI_C_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (SPI_C_AR_RELEASE_MINOR_VERSION != SPI_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (SPI_C_AR_RELEASE_REVISION_VERSION != SPI_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Software version */
#if ((SPI_C_SW_MAJOR_VERSION != SPI_DRVW_H_SW_MAJOR_VERSION) ||                                    \
     (SPI_C_SW_MINOR_VERSION != SPI_DRVW_H_SW_MINOR_VERSION) ||                                    \
     (SPI_C_SW_PATCH_VERSION != SPI_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Spi.c and Spi_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and SchM_Spi.h are the same Autosar version */
    #if ((SPI_C_AR_RELEASE_MAJOR_VERSION != SCHM_SPI_H_AR_RELEASE_MAJOR_VERSION) ||                \
         (SPI_C_AR_RELEASE_MINOR_VERSION != SCHM_SPI_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Spi.c and SchM_Spi.h are different"
    #endif

    /* Check if current file and Det.h are the same Autosar version */
    #if ((SPI_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                       \
         (SPI_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Spi.c and Det.h are different"
    #endif

    #if (SPI_E_HARDWARE_ERROR_ENABLE == STD_ON)
        /* Check if current file and Dem.h are the same Autosar version */
        #if ((SPI_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) ||                   \
             (SPI_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Spi.c and Dem.h are different"
        #endif
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/**
 * @brief Defines MACRO for Sequence, Job, Channel and HW Unit access.
 */
#define SPI_CONF(CoreID)     (Spi_ConfigPtr[(CoreID)])
#define SPI_SEQ(CoreID, Seq) (Spi_ConfigPtr[(CoreID)]->SequenceConfigList[(Seq)].SeqConfig)
#define SPI_JOB(CoreID, Job) (Spi_ConfigPtr[(CoreID)]->JobConfigList[(Job)].JobConfig)
#define SPI_CHL(CoreID, Channel)                                                                   \
    (Spi_ConfigPtr[(CoreID)]->ChannelConfigList[(Channel)].ChannelConfig)
#define SPI_HWUNIT(CoreID, Unit)                                                                   \
    (Spi_ConfigPtr[(CoreID)]->HWUnitConfigList[(Unit)].DrvwHWUnitConfig)

/**
 * @brief Defines MACRO for Det report error.
 */
#define SPI_DET_REPORT_ERROR(ServiceId, ErrorId)                                                   \
    (void)Det_ReportError((uint16)SPI_MODULE_ID, (uint8)0, (ServiceId), (ErrorId))

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    /**
     * @brief  Invalid Job.
     */
    #define SPI_JOB_NULL ((Spi_JobType)(0xFFFF))

    /**
     * @brief  Invalid priority.
     */
    #define SPI_PRIORITY_NULL (-1)
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/**
 * @brief Array of Spi job State.
 */
Spi_JobStateType Spi_JobStateArray[SPI_MAX_CFG_JOBS];

/**
 * @brief Array of Spi channel State.
 */
Spi_Drvw_ChannelStateType Spi_ChannelStateArray[SPI_MAX_CFG_CHANNELS];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"
/**
 * @brief Pointer to local SPI configuration.
 */
static const Spi_ConfigType *Spi_ConfigPtr[SPI_MAX_PARTITIONS];

#define SPI_STOP_SEC_VAR_CLEARED_PTR
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/**
 * @brief Array of Spi Sequence State.
 */
static Spi_SequenceStateType Spi_SequenceStateArray[SPI_MAX_CFG_SEQUENCES];

/**
 * @brief Array of HW units queues
 */
static Spi_HWUnitQueue Spi_HWUnitQueueArray[SPI_MAX_CFG_HWUNITS];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_32
#include "Spi_MemMap.h"

/**
 * @brief   Array of used HW units per sequence.
 */
#if ((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0))
static uint32 Spi_SeqUsedHWUnits[SPI_MAX_CFG_SEQUENCES];
#endif

/**
 * @brief Spi HWUnits busy status for Sync Transmit.
 */
static volatile uint32 Spi_SyncHWUnitsBusyStatus[SPI_MAX_CFG_HWUNITS];

#define SPI_STOP_SEC_VAR_CLEARED_32
#include "Spi_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
extern void Spi_ChannelEndCallback(Spi_Drvw_HWUnitType HwUnit, boolean JobResultOK);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if (SPI_LEVEL_DELIVERED == LEVEL2)
LOCAL_INLINE Std_ReturnType Spi_GetHWUnitsBusyStatus(uint32 CoreId);
#endif
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE void Spi_ScheduleNewJob(Spi_HWUnitQueue *HWUnitQueue, Spi_JobType Job,
                                     const Spi_JobConfigType *JobCfgPtr);
LOCAL_INLINE void Spi_UnlockRemainingJobsOfSeq(Spi_JobType                   RemainingJobs,
                                               const Spi_SequenceConfigType *Sequence);
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Spi_CheckInit(uint32 CoreId, const Spi_ConfigType *ConfigPtr);
static Std_ReturnType Spi_CheckSequence(uint32 CoreId, const Spi_SequenceType Sequence,
                                        const uint8 ServiceId);
static Std_ReturnType Spi_CheckChannel(uint32 CoreId, const Spi_ChannelType Channel,
                                       const uint8 ServiceId);
    #if ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))
static Std_ReturnType Spi_CheckSyncTransmit(uint32 CoreId, Spi_SequenceType Sequence);
    #endif
    #if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
static Std_ReturnType Spi_CheckAsyncTransmit(uint32 CoreId, Spi_SequenceType Sequence);
    #endif

    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
static Std_ReturnType Spi_CheckSetupEB(uint32 CoreId, Spi_ChannelType Channel,
                                       Spi_NumberOfDataType Length);
static Std_ReturnType Spi_CheckChannelLength(uint32 CoreId, const Spi_ChannelType Channel,
                                             Spi_NumberOfDataType Length, const uint8 ServiceId);
    #endif
    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
static Std_ReturnType Spi_CheckWriteIB(uint32 CoreId, Spi_ChannelType Channel);
    #endif
    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
static Std_ReturnType Spi_CheckReadIB(uint32 CoreId, Spi_ChannelType Channel,
                                      const Spi_DataBufferType *DataBufferPtr);
    #endif
static Spi_JobResultType Spi_CheckGetJobResult(uint32 CoreId, Spi_JobType Job);
static Spi_SeqResultType Spi_CheckGetSequenceResult(uint32 CoreId, Spi_SequenceType Sequence);
    #if (((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) ||                 \
         (SPI_HW_STATUS_API == STD_ON))
static Std_ReturnType Spi_CheckHWUnit(uint32 CoreId, const Spi_HWUnitType HWUnit,
                                      const uint8 ServiceId);
    #endif
    #if (SPI_CANCEL_API == STD_ON)
static Std_ReturnType Spi_CheckCancel(uint32 CoreId, Spi_SequenceType Sequence);
    #endif

#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

static void Spi_InitChannelsState(uint32 CoreId);
static void Spi_InitJobsState(uint32 CoreId);
static void Spi_InitSequencesState(uint32 CoreId);

#if ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))

static Std_ReturnType Spi_SyncTransmitSequence(const Spi_SequenceConfigType *SeqCfgPtr,
                                               uint32                        CoreId);
static Std_ReturnType Spi_SyncTransmitJob(const Spi_JobConfigType *JobCfgPtr, uint32 CoreId);
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2) )*/

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
static void           Spi_InitAsyncJobsList(uint32 HWUnit);
static void           Spi_TransferAsyncJob(const Spi_JobConfigType *JobCfgPtr);
static Std_ReturnType Spi_LockAsyncSequence(Spi_SequenceType              SequenceId,
                                            const Spi_SequenceConfigType *Sequence);
static void           Spi_StartNextJob(Spi_HWUnitQueue *HWUnitQueue, uint32 CoreId);
static void           Spi_JobTransferFinished(const Spi_JobConfigType *JobCfgPtr,
                                              Spi_JobResultType        JobResult);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if (SPI_LEVEL_DELIVERED == LEVEL2)
/**
 * @brief      This function check busy status of all HW Units.
 *
 * @param[in]  CoreId: Core ID
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      at least on HW Unit is busy.
 * @retval     E_NOT_OK:  no HW Unit is busy.
 */

LOCAL_INLINE Std_ReturnType Spi_GetHWUnitsBusyStatus(uint32 CoreId)
{
    Spi_StatusType Status = SPI_IDLE;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    Spi_HWUnitType HWUnit;

    for (HWUnit = 0U; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
    {
        if ((NULL_PTR != SPI_HWUNIT(CoreId, HWUnit)) &&
            (CoreId == SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse))
        {
            if ((SPI_BUSY == Spi_HWUnitQueueArray[HWUnit].Status) &&
                (SPI_DRVW_PHYUNIT_ASYNC == SPI_HWUNIT(CoreId, HWUnit)->IsSync))
            {
                Status = SPI_BUSY;
                break;
            }
        }
    }
    if (SPI_BUSY == Status)
    {
        Ret = E_NOT_OK;
    }
    return Ret;
}
#endif /* SPI_LEVEL_DELIVERED == LEVEL2 */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief      This function unlock the jobs at the end of an async sequence transmission.
 *
 * @param[in]  RemainingJobs: The remaining jobs in sequence
 * @param[in]  Sequence: The sequence configuration
 *
 * @return     None
 */
LOCAL_INLINE void Spi_UnlockRemainingJobsOfSeq(Spi_JobType                   RemainingJobs,
                                               const Spi_SequenceConfigType *Sequence)
{
    Spi_JobType TotalJobs = Sequence->JobNum;
    Spi_JobType Index;

    for (Index = TotalJobs - RemainingJobs; Index < TotalJobs; Index++)
    {
        Spi_JobStateArray[Sequence->JobIndexList[Index]].AsyncSequenceState = NULL_PTR;
    }
}

/**
 * @brief     This function will schedule a job for a given HW unit.
 *
 * @param[in] HWUnitQueue: HW Unit Queue of the job
 * @param[in] Job: Job ID
 * @param[in] JobCfgPtr: Pointer to scheduled job Configuration
 *
 * @return    None
 *
 */
LOCAL_INLINE void Spi_ScheduleNewJob(Spi_HWUnitQueue *HWUnitQueue, Spi_JobType Job,
                                     const Spi_JobConfigType *JobCfgPtr)
{
    sint8        Priority;
    Spi_JobType *JobListTail;

    SchM_Enter_Spi_UpdateAsyncHWUnitQueue();
    if (SPI_IDLE != HWUnitQueue->Status)
    {
        Priority = JobCfgPtr->Priority;
        JobListTail = &HWUnitQueue->ScheduledJobsListTail[Priority];

        if (SPI_JOB_NULL == *JobListTail)
        {
            HWUnitQueue->ScheduledJobsListHead[Priority] = Job;
        }
        else
        {
            Spi_JobStateArray[*JobListTail].AsyncNextJob = Job;
        }

        *JobListTail = Job;

        Spi_JobStateArray[Job].AsyncNextJob = SPI_JOB_NULL;

        if (HWUnitQueue->MaxScheduledPriority < Priority)
        {
            HWUnitQueue->MaxScheduledPriority = Priority;
        }
        SchM_Exit_Spi_UpdateAsyncHWUnitQueue();
    }
    else
    {
        HWUnitQueue->Status = SPI_BUSY;
        Spi_JobStateArray[Job].Result = SPI_JOB_PENDING;
        HWUnitQueue->Channel = 0;
        HWUnitQueue->Job = Job;
        SchM_Exit_Spi_UpdateAsyncHWUnitQueue();

        Spi_TransferAsyncJob(JobCfgPtr);
    }
}
#endif /* (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) */

#if (SPI_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function check the initialization of driver.
 *
 * @param[in]  CoreId: Core ID
 * @param[in]  ConfigPtr: The pointer to the SPI configuration.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      The parameter is valid.
 * @retval     E_NOT_OK:  The parameter is invalid.
 */
static Std_ReturnType Spi_CheckInit(uint32 CoreId, const Spi_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    Spi_ChannelType  Channel;
    Spi_JobType      Job;
    Spi_SequenceType Sequence;
    #endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */

    if (NULL_PTR != SPI_CONF(CoreId))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED);
    }
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
    else if (NULL_PTR == ConfigPtr)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(SPI_SID_INIT, SPI_E_INIT_FAILED);
    }
    #else
    else if (NULL_PTR != ConfigPtr)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(SPI_SID_INIT, SPI_E_INIT_FAILED);
    }
    #endif /*(SPI_PRECOMPILE_SUPPORT == STD_OFF)*/
    else
    {
    #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
        Channel = (uint32)(ConfigPtr->SpiMaxChannel);
        Job = (uint32)(ConfigPtr->SpiMaxJob);
        Sequence = (uint32)(ConfigPtr->SpiMaxSequence);

        if ((SPI_MAX_CFG_CHANNELS <= Channel) || (SPI_MAX_CFG_JOBS <= Job) ||
            (SPI_MAX_CFG_SEQUENCES <= Sequence))
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
            SPI_DET_REPORT_ERROR(SPI_SID_INIT, SPI_E_CONFIG_OUT_OF_RANGE);
        #endif
        }
        else if (CoreId != ConfigPtr->SpiCoreUse)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            SPI_DET_REPORT_ERROR(SPI_SID_INIT, SPI_E_PARAM_CONFIG);
        }
    #else
        if (NULL_PTR == Spi_PreDefinedConfigPtr[CoreId])
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            SPI_DET_REPORT_ERROR(SPI_SID_INIT, SPI_E_POINTER_INVALID);
        }
    #endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */
        else
        {
            /* Nothing to do */
        }
    }
    return Ret;
}

/**
 * @brief      This function checks sequence validity.
 *
 * @param[in]  CoreId: Core ID
 * @param[in]  Sequence: Sequence Id
 * @param[in]  ServiceId: Service Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      No error was reported.
 * @retval     E_NOT_OK:  Error was reported
 */
static Std_ReturnType Spi_CheckSequence(uint32 CoreId, const Spi_SequenceType Sequence,
                                        const uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_UNINIT);
    }
    else if (Sequence > (SPI_CONF(CoreId)->SpiMaxSequence))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_SEQ);
    }
    else if (NULL_PTR == SPI_SEQ(CoreId, Sequence))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CONFIG);
    }
    else if (CoreId != SPI_SEQ(CoreId, Sequence)->SpiCoreUse)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CONFIG);
    }
    else if (0U == SPI_SEQ(CoreId, Sequence)->JobNum)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_SEQ_EMPTY);
    }
    else
    {
        /* Nothing to do */
    }
    return Ret;
}

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      This function checks the validity of channel length.
 *
 * @param[in]  CoreId: ID of Core
 * @param[in]  Channel: Channel ID
 * @param[in]  ServiceId: Service Id
 * @param[in]  Length: Length of the data to be transmitted
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      No error was reported.
 * @retval     E_NOT_OK:  Error was reported
 */
static Std_ReturnType Spi_CheckChannelLength(uint32 CoreId, const Spi_ChannelType Channel,
                                             Spi_NumberOfDataType Length, const uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if ((Length > SPI_CHL(CoreId, Channel)->Length) || (0U == Length))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_LENGTH);
    }
    else
    {   /*Z20K14xM_SAD_Spi_00003*/
        if ((SPI_CHL(CoreId, Channel)->FrameSize > 8U) &&
            (SPI_CHL(CoreId, Channel)->FrameSize < 17U))
        {
            /* check if Length mod 2 equals 0*/
            if (0U != ((uint32)Length & 1U))
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_LENGTH);
            }
        }
        else if ((SPI_CHL(CoreId, Channel)->FrameSize > 16U) &&
                 (SPI_CHL(CoreId, Channel)->FrameSize < 33U))
        {
            /* check if Length mod 4 equals 0*/
            if (0U != ((uint32)Length & 3U))
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_LENGTH);
            }
        }
        else
        {
            /* Nothing to do */
        }
    }
    return Ret;
}
#endif
/**
 * @brief      This function checks channel validity.
 *
 * @param[in]  CoreId: ID of Core
 * @param[in]  Channel: Channel ID
 * @param[in]  ServiceId: Service Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      No error was reported.
 * @retval     E_NOT_OK:  Error was reported
 */
static Std_ReturnType Spi_CheckChannel(uint32 CoreId, const Spi_ChannelType Channel,
                                       const uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_UNINIT);
    }
    else if (Channel > SPI_CONF(CoreId)->SpiMaxChannel)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == SPI_CHL(CoreId, Channel))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CONFIG);
    }
    else if (CoreId != SPI_CHL(CoreId, Channel)->SpiCoreUse)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CONFIG);
    }
    else
    {
        /* Nothing to do */
    }

    return Ret;
}

    /**
     * @brief      This function check the initialization of driver and sequence ID is compatible
     *             in Synchronous mode.
     *
     * @param[in]  CoreId: ID of Core
     * @param[in]  Sequence: Sequence ID
     *
     * @return     Std_ReturnType
     * @retval     E_OK:      No error was reported.
     * @retval     E_NOT_OK:  Error was reported
     */
    #if ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))
static Std_ReturnType Spi_CheckSyncTransmit(uint32 CoreId, Spi_SequenceType Sequence)
{
    Spi_JobType     NumJobsInSequence;
    Spi_JobType     Job;
    Spi_JobType     JobIndex;
    uint32          IsSync;
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
    Spi_ChannelType ChannelID;
    Spi_ChannelType ChannelIndex;
    Spi_ChannelType ChannelNum;
#endif
    Std_ReturnType  Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckSequence(CoreId, Sequence, SPI_SID_SYNC_TRANSMIT);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        NumJobsInSequence = SPI_SEQ(CoreId, Sequence)->JobNum;
        for (JobIndex = 0U; JobIndex < NumJobsInSequence; JobIndex++)
        {
            Job = SPI_SEQ(CoreId, Sequence)->JobIndexList[JobIndex];
            IsSync = SPI_HWUNIT(CoreId, SPI_JOB(CoreId, Job)->HWUnit)->IsSync;
            if ((uint32)(SPI_DRVW_PHYUNIT_ASYNC) == (IsSync))
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                SPI_DET_REPORT_ERROR(SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_UNIT);
            }
        #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
            if ((Std_ReturnType)E_OK == Ret)
            {
                ChannelNum = SPI_JOB(CoreId, Job)->ChannelNum;
                for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < ChannelNum; ChannelIndex++)
                {
                    ChannelID = SPI_JOB(CoreId, Job)->ChannelIndexList[ChannelIndex];
                    if (EB == SPI_CHL(CoreId, ChannelID)->BufferType)
                    {
                        if (0U == Spi_ChannelStateArray[ChannelID].Length)
                        {
                            SPI_DET_REPORT_ERROR(SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_EB_UNIT);
                            Ret = (Std_ReturnType)E_NOT_OK;
                            break;
                        }
                    }
                }
            }
        #endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED ==      \
                USAGE2) ) */
            if ((Std_ReturnType)E_OK != Ret)
            {
                break;
            }
        }
    }
    return Ret;
}
    #endif /* ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

    #if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief      This function check the initialization of driver and sequence ID is compatible.
 *
 * @param[in]  CoreId: ID of core
 * @param[in]  Sequence: Sequence ID
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      No error was reported.
 * @retval     E_NOT_OK:  Error was reported
 */
static Std_ReturnType Spi_CheckAsyncTransmit(uint32 CoreId, Spi_SequenceType Sequence)
{
    const Spi_SequenceConfigType *SeqCfgPtr;
    const Spi_JobConfigType      *JobCfgPtr;
    Spi_JobType                   NumJobsInSequence;
    Spi_JobType                   JobIndex;
    Spi_JobType                   JobId;
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
    Spi_ChannelType               ChannelID;
    Spi_ChannelType               NumChannelsInJob;
    Spi_ChannelType               ChannelIndex;
#endif
    Std_ReturnType                Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckSequence(CoreId, Sequence, SPI_SID_ASYNC_TRANSMIT);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        SeqCfgPtr = SPI_SEQ(CoreId, Sequence);
        NumJobsInSequence = SeqCfgPtr->JobNum;

        JobIndex = 0U;
        while (JobIndex < NumJobsInSequence)
        {
            JobId = SeqCfgPtr->JobIndexList[JobIndex];
            JobCfgPtr = SPI_JOB(CoreId, JobId);

            /* check for empty jobs */
            if (0U == JobCfgPtr->ChannelNum)
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                SPI_DET_REPORT_ERROR(SPI_SID_ASYNC_TRANSMIT, SPI_E_JOB_EMPTY);
            }

            if (SPI_DRVW_PHYUNIT_ASYNC != SPI_HWUNIT(CoreId, JobCfgPtr->HWUnit)->IsSync)
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                SPI_DET_REPORT_ERROR(SPI_SID_ASYNC_TRANSMIT, SPI_E_PARAM_UNIT);
            }

        #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
            if ((Std_ReturnType)E_OK == Ret)
            {
                NumChannelsInJob = JobCfgPtr->ChannelNum;
                for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob;
                     ChannelIndex++)
                {
                    ChannelID = JobCfgPtr->ChannelIndexList[ChannelIndex];
                    if (EB == SPI_CHL(CoreId, ChannelID)->BufferType)
                    {
                        if (0U == Spi_ChannelStateArray[ChannelID].Length)
                        {
                            Ret = (Std_ReturnType)E_NOT_OK;
                            SPI_DET_REPORT_ERROR(SPI_SID_ASYNC_TRANSMIT, SPI_E_PARAM_EB_UNIT);
                            break;
                        }
                    }
                }
            }
        #endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED ==      \
                  USAGE2) ) */
            if ((Std_ReturnType)E_OK != Ret)
            {
                break;
            }
            JobIndex++;
        }
    }
    return Ret;
}
    #endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      This function checks input of SetupEB service.
 *
 * @param[in]  CoreId: Core Id
 * @param[in]  Channel: Channel Id
 * @param[in]  Length: Length of the data to be transmitted
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Valid
 * @retval     E_NOT_OK:  Invalid
 */
static Std_ReturnType Spi_CheckSetupEB(uint32 CoreId, Spi_ChannelType Channel,
                                       Spi_NumberOfDataType Length)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckChannel(CoreId, Channel, SPI_SID_SETUP_EB);

    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (IB == SPI_CHL(CoreId, Channel)->BufferType)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            SPI_DET_REPORT_ERROR(SPI_SID_SETUP_EB, SPI_E_PARAM_CHANNEL);
        }
        else
        {
            Ret = Spi_CheckChannelLength(CoreId, Channel, Length, SPI_SID_SETUP_EB);
        }
    }
    return Ret;
}
    #endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2)) \
            */

    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      This function checks input of ReadIB service.
 *
 * @param[in]  CoreId: Core Id
 * @param[in]  Channel: Channel Id
 * @param[in]  DataBufferPtr: DataBuffer privided by upper level
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Valid
 * @retval     E_NOT_OK:  Invalid
 */
static Std_ReturnType Spi_CheckReadIB(uint32 CoreId, Spi_ChannelType Channel,
                                      const Spi_DataBufferType *DataBufferPtr)
{
    const Spi_Drvw_ChannelConfigType *ChannelCfgPtr;
    Std_ReturnType                    Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckChannel(CoreId, Channel, SPI_SID_READ_IB);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        ChannelCfgPtr = SPI_CHL(CoreId, Channel);
        if (EB == ChannelCfgPtr->BufferType)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            SPI_DET_REPORT_ERROR(SPI_SID_READ_IB, SPI_E_PARAM_CHANNEL);
        }
        else if (NULL_PTR == DataBufferPtr)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            SPI_DET_REPORT_ERROR(SPI_SID_READ_IB, SPI_E_PARAM_CHANNEL);
        }
        else
        {
            /* Nothing to do */
        }
    }
    return Ret;
}
    #endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2)) \
            */

    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      This function checks input of WriteIB service.
 *
 * @param[in]  CoreId: Core Id
 * @param[in]  Channel: Channel Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Valid
 * @retval     E_NOT_OK:  Invalid
 */
static Std_ReturnType Spi_CheckWriteIB(uint32 CoreId, Spi_ChannelType Channel)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckChannel(CoreId, Channel, SPI_SID_WRITE_IB);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
        if (EB == SPI_CHL(CoreId, Channel)->BufferType)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            SPI_DET_REPORT_ERROR(SPI_SID_WRITE_IB, SPI_E_PARAM_CHANNEL);
        }
    }
    return Ret;
}
    #endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2)) \
            */

/**
 * @brief      This function checks input of GetJobResult service.
 *
 * @param[in]  CoreId: Core Id
 * @param[in]  Job: Job Id
 *
 * @return     Spi_JobResultType
 * @retval     SPI_JOB_OK:      Valid
 * @retval     SPI_JOB_FAILED:  Invalid
 */
static Spi_JobResultType Spi_CheckGetJobResult(uint32 CoreId, Spi_JobType Job)
{
    Spi_JobResultType JobResult = SPI_JOB_FAILED;

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_JOB_RESULT, SPI_E_UNINIT);
    }
    else if (Job > SPI_CONF(CoreId)->SpiMaxJob)
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_JOB);
    }
    else if (NULL_PTR == SPI_JOB(CoreId, Job))
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_CONFIG);
    }
    else if (CoreId != SPI_JOB(CoreId, Job)->SpiCoreUse)
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_CONFIG);
    }
    else
    {
        JobResult = SPI_JOB_OK;
    }
    return JobResult;
}

/**
 * @brief      This function checks input of GetSequenceResult service.
 *
 * @param[in]  CoreId: Core Id
 * @param[in]  Sequence: Sequence Id
 *
 * @return     Spi_SeqResultType
 * @retval     SPI_SEQ_OK:      Valid
 * @retval     SPI_SEQ_FAILED:  Invalid
 */
static Spi_SeqResultType Spi_CheckGetSequenceResult(uint32 CoreId, Spi_SequenceType Sequence)
{
    Spi_SeqResultType SequenceResult = SPI_SEQ_FAILED;

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_SEQUENCE_RESULT, SPI_E_UNINIT);
    }
    else if (Sequence > SPI_CONF(CoreId)->SpiMaxSequence)
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_SEQUENCE_RESULT, SPI_E_PARAM_SEQ);
    }
    else if (NULL_PTR == SPI_SEQ(CoreId, Sequence))
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_SEQUENCE_RESULT, SPI_E_PARAM_CONFIG);
    }
    else if (CoreId != SPI_SEQ(CoreId, Sequence)->SpiCoreUse)
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_SEQUENCE_RESULT, SPI_E_PARAM_CONFIG);
    }
    else
    {
        SequenceResult = SPI_SEQ_OK;
    }
    return SequenceResult;
}
    #if (((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) ||                 \
         (SPI_HW_STATUS_API == STD_ON))
/**
 * @brief      This function check validity of HWUnit.
 *
 * @param[in]  CoreId:  Core Id
 * @param[in]  HWUnit: The hardware Peripheral
 * @param[in]  ServiceId: Service Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Valid
 * @retval     E_NOT_OK:  Invalid
 */
static Std_ReturnType Spi_CheckHWUnit(uint32 CoreId, const Spi_HWUnitType HWUnit,
                                      const uint8 ServiceId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_UNINIT);
    }
    else if (SPI_MAX_CFG_HWUNITS <= HWUnit)
    {
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_HWUNIT);
    }
    else if (NULL_PTR == SPI_HWUNIT(CoreId, HWUnit))
    {
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CONFIG);
    }
    else if (CoreId != SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse)
    {
        SPI_DET_REPORT_ERROR(ServiceId, SPI_E_PARAM_CONFIG);
    }
    else
    {
        Ret = (Std_ReturnType)E_OK;
    }

    return Ret;
}
    #endif /* ( ((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON)) ||          \
                  (SPI_HW_STATUS_API == STD_ON) ) */

    #if (SPI_CANCEL_API == STD_ON)
/**
 * @brief      This function checks input of Cancel service.
 *
 * @param[in]  CoreId: Core Id
 * @param[in]  Sequence: Sequence Id
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Valid
 * @retval     E_NOT_OK:  Invalid
 */
static Std_ReturnType Spi_CheckCancel(uint32 CoreId, Spi_SequenceType Sequence)
{
    Std_ReturnType                Ret = (Std_ReturnType)E_NOT_OK;
    const Spi_SequenceConfigType *SeqCfgPtr;

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        SPI_DET_REPORT_ERROR(SPI_SID_CANCEL, SPI_E_UNINIT);
    }
    else if (Sequence > SPI_CONF(CoreId)->SpiMaxSequence)
    {
        SPI_DET_REPORT_ERROR(SPI_SID_CANCEL, SPI_E_PARAM_SEQ);
    }
    else
    {
        SeqCfgPtr = SPI_SEQ(CoreId, Sequence);
        if (NULL_PTR == SeqCfgPtr)
        {
            SPI_DET_REPORT_ERROR(SPI_SID_CANCEL, SPI_E_PARAM_CONFIG);
        }
        else if (CoreId != SeqCfgPtr->SpiCoreUse)
        {
            SPI_DET_REPORT_ERROR(SPI_SID_CANCEL, SPI_E_PARAM_CONFIG);
        }
        else
        {
            Ret = (Std_ReturnType)E_OK;
        }
    }
    return Ret;
}
    #endif /* (SPI_CANCEL_API == STD_ON) */

#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

#if ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief      This function transmits a job of a sequence.
 *
 * @param[in]  JobCfgPtr: Pointer to job configuration
 * @param[in]  CoreId: ID of Core
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Successfully.
 * @retval     E_NOT_OK:  Failed
 *
 */
static Std_ReturnType Spi_SyncTransmitJob(const Spi_JobConfigType *JobCfgPtr, uint32 CoreId)
{
    Spi_ChannelType                          ChannelID;
    Spi_ChannelType                          NumChannelsInJob;
    Spi_ChannelType                          ChannelIndex;
    const Spi_Drvw_ChannelConfigType        *ChannelCfgPtr;
    const Spi_Drvw_ExternalDeviceConfigType *ExternalDeviceConfig;
    boolean                                  IsFirstChannel;
    boolean                                  IsLastChannel;
    Std_ReturnType                           Ret = (Std_ReturnType)E_OK;

    ExternalDeviceConfig = JobCfgPtr->ExternalDeviceConfig->DrvwExternalDeviceConfigPtr;

    if (NULL_PTR != JobCfgPtr->StartNotification)
    {
        JobCfgPtr->StartNotification();
    }

    NumChannelsInJob = JobCfgPtr->ChannelNum;
    for (ChannelIndex = (Spi_ChannelType)0; ChannelIndex < NumChannelsInJob; ChannelIndex++)
    {
        ChannelID = JobCfgPtr->ChannelIndexList[ChannelIndex];
        ChannelCfgPtr = SPI_CHL(CoreId, ChannelID);

        if (0U == ChannelIndex)
        {
            IsFirstChannel = (boolean)TRUE;
        }
        else
        {
            IsFirstChannel = (boolean)FALSE;
        }
        if (ChannelIndex == (NumChannelsInJob - 1U))
        {
            IsLastChannel = (boolean)TRUE;
        }
        else
        {
            IsLastChannel = (boolean)FALSE;
        }
        Ret = Spi_Drvw_TransmitChannel(ChannelCfgPtr, ExternalDeviceConfig, IsFirstChannel,
                                       IsLastChannel, (boolean)TRUE);
        if ((Std_ReturnType)E_OK != Ret)
        {
            break;
        }
    }

    return Ret;
}

/**
 * @brief      This function transmits a sequence.
 *
 * @param[in]  SeqCfgPtr: Pointer to sequence configuration
 * @param[in]  CoreId: ID of Core
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Successfully.
 * @retval     E_NOT_OK:  Failed
 *
 */
static Std_ReturnType Spi_SyncTransmitSequence(const Spi_SequenceConfigType *SeqCfgPtr,
                                               uint32                        CoreId)
{
    Spi_JobType              JobsCount;
    const Spi_JobType       *JobIndexList;
    Spi_JobType              Job;
    Spi_JobStateType        *JobState;
    const Spi_JobConfigType *JobCfgPtr;
    Std_ReturnType           Ret = (Std_ReturnType)E_OK;

    JobsCount = SeqCfgPtr->JobNum;
    JobIndexList = SeqCfgPtr->JobIndexList;
    while (0U < JobsCount)
    {
        Job = *JobIndexList;
        JobCfgPtr = SPI_JOB(CoreId, Job);

        JobState = &Spi_JobStateArray[Job];
        JobState->Result = SPI_JOB_PENDING;
        Spi_HWUnitQueueArray[JobCfgPtr->HWUnit].Status = SPI_BUSY;

        Ret = Spi_SyncTransmitJob(JobCfgPtr, CoreId);
        Spi_HWUnitQueueArray[JobCfgPtr->HWUnit].Status = SPI_IDLE;

        if ((Std_ReturnType)E_OK == Ret)
        {
            JobState->Result = SPI_JOB_OK;
            if (NULL_PTR != JobCfgPtr->EndNotification)
            {
                JobCfgPtr->EndNotification();
            }
        }
        else
        {
            do
            {   /*Z20K14xM_SAD_Spi_00007*/
                Spi_JobStateArray[*JobIndexList].Result = SPI_JOB_FAILED;
                JobCfgPtr = SPI_JOB(CoreId, *JobIndexList);
                if (NULL_PTR != JobCfgPtr->EndNotification)
                {
                    JobCfgPtr->EndNotification();
                }
                JobIndexList++;
                JobsCount--;
            }
            while (0U < JobsCount);
            JobsCount = 1U;
        }
        JobIndexList++;
        JobsCount--;
    }
    return Ret;
}
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief      This function initiate the jobs list.
 *
 * @param[in]  HWUnit: The HW peripheral
 *
 * @return     None
 */
static void Spi_InitAsyncJobsList(uint32 HWUnit)
{
    sint8 Priority;

    for (Priority = 0; Priority < (sint8)SPI_JOB_PRIORITY_LEVELS_COUNT; Priority++)
    {
        Spi_HWUnitQueueArray[HWUnit].ScheduledJobsListHead[Priority] = SPI_JOB_NULL;
        Spi_HWUnitQueueArray[HWUnit].ScheduledJobsListTail[Priority] = SPI_JOB_NULL;
    }
    Spi_HWUnitQueueArray[HWUnit].MaxScheduledPriority = SPI_PRIORITY_NULL;
}

/**
 * @brief      This function marks the jobs of a sequence as ready to be transmitted.
 *
 * @param[in]  SequenceId: The sequence ID
 * @param[in]  Sequence: Pointer to sequence configuration
 *
 * @return     Std_ReturnType: Result of Lock jobs
 * @retval     E_OK:      Successfully
 * @retval     E_NOT_OK:  Failed
 */
static Std_ReturnType Spi_LockAsyncSequence(Spi_SequenceType              SequenceId,
                                            const Spi_SequenceConfigType *Sequence)
{
    Std_ReturnType         Ret = (Std_ReturnType)E_OK;
    Spi_JobType            JobCount = Sequence->JobNum;
    Spi_JobStateType      *JobState;
    const Spi_JobType     *JobPtr = Sequence->JobIndexList;
    Spi_SequenceStateType *SequenceState = &Spi_SequenceStateArray[SequenceId];

    SchM_Enter_Spi_UpdateJobState();
    while (0U < JobCount)
    {
        JobState = &Spi_JobStateArray[*JobPtr];
        if (NULL_PTR != JobState->AsyncSequenceState)
        {
            if (JobCount < Sequence->JobNum)
            {
                do
                {
                    JobCount++;
                    JobPtr--;
                    Spi_JobStateArray[*JobPtr].AsyncSequenceState = NULL_PTR;
                }
                while (JobCount < Sequence->JobNum);
            }
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
        else
        {
            JobState->AsyncSequenceState = SequenceState;
        }
        JobCount--;
        JobPtr++;
    }
    SchM_Exit_Spi_UpdateJobState();

    return Ret;
}

/**
 * @brief     This function is called when a job is finished.
 *
 * @param[in] JobCfgPtr: Pointer to the job configuration.
 * @param[in] JobResult: Job result.
 *
 * @return    None
 */
static void Spi_JobTransferFinished(const Spi_JobConfigType *JobCfgPtr, Spi_JobResultType JobResult)
{
    Spi_HWUnitType                HWUnit = JobCfgPtr->HWUnit;
    Spi_HWUnitQueue              *HWUnitQueue = &Spi_HWUnitQueueArray[HWUnit];
    Spi_JobStateType             *JobState = JobCfgPtr->JobState;
    Spi_SequenceStateType        *SequenceState;
    const Spi_SequenceConfigType *SeqCfgPtr;
    const Spi_JobType            *Job;
    const Spi_JobConfigType      *CurrentJobCfg;
    Spi_JobType                   JobId;
    uint32                        CoreId;

    SchM_Enter_Spi_UpdateJobState();
    if ((SPI_JOB_OK != JobState->Result) && (NULL_PTR != JobState->AsyncSequenceState))
    {
        JobState->Result = JobResult;
        CoreId = JobCfgPtr->SpiCoreUse;
        SequenceState = JobState->AsyncSequenceState;
        SeqCfgPtr = SequenceState->Sequence;
        JobState->AsyncSequenceState = NULL_PTR;
        SchM_Exit_Spi_UpdateJobState();

        if (NULL_PTR != JobCfgPtr->EndNotification)
        {
            JobCfgPtr->EndNotification();
        }
        else
        {
            /* Nothing to do */
        }
        if ((SPI_JOB_FAILED == JobState->Result) && (SequenceState->Result != SPI_SEQ_CANCELLED))
        {
            SequenceState->Result = SPI_SEQ_FAILED;
        }
        else
        {
            /* Nothing to do */
        }
    #if (SPI_CANCEL_API == STD_ON)
        if ((SPI_SEQ_CANCELLED == SequenceState->Result) ||
            (SPI_SEQ_FAILED == SequenceState->Result))
    #else
        if (SPI_SEQ_FAILED == SequenceState->Result)
    #endif
        {
            Spi_UnlockRemainingJobsOfSeq(SequenceState->RemainingJobs, SeqCfgPtr);
    #if (SPI_E_HARDWARE_ERROR_ENABLE == STD_ON)
            if (SPI_SEQ_FAILED == SequenceState->Result)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)SPI_E_HARDWARE_ERROR_EVENT_ID,
                                         DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)SPI_E_HARDWARE_ERROR_EVENT_ID,
                                         DEM_EVENT_STATUS_PASSED);
            }
    #endif
            if (NULL_PTR != SeqCfgPtr->EndNotification)
            {
                SeqCfgPtr->EndNotification();
            }

            Spi_StartNextJob(HWUnitQueue, CoreId);
        }
        else
        {
            if (0U < SequenceState->RemainingJobs)
            {
                SequenceState->CurrentJobIndexPointer++;
                Job = SequenceState->CurrentJobIndexPointer;
                JobId = *Job;
                SequenceState->RemainingJobs--;
                CurrentJobCfg = SPI_JOB(CoreId, JobId);
                if (HWUnit != CurrentJobCfg->HWUnit)
                {
                    Spi_ScheduleNewJob(&Spi_HWUnitQueueArray[CurrentJobCfg->HWUnit], JobId,
                                       CurrentJobCfg);
                    Spi_StartNextJob(HWUnitQueue, CoreId);
                }
                else
                {
    #if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
                    /*SWS_Spi_00269 */
                    if (TRUE == SeqCfgPtr->Interruptible)
                    {
                        Spi_ScheduleNewJob(HWUnitQueue, JobId, CurrentJobCfg);
                        Spi_StartNextJob(HWUnitQueue, CoreId);
                    }
                    else
    #endif
                    {
                        Spi_JobStateArray[JobId].Result = SPI_JOB_PENDING;
                        HWUnitQueue->Channel = 0;
                        HWUnitQueue->Job = JobId;
                        Spi_TransferAsyncJob(CurrentJobCfg);
                    }
                }
            }
            else
            {
                SequenceState->Result = SPI_SEQ_OK;
    #if (SPI_E_HARDWARE_ERROR_ENABLE == STD_ON)
                (void)Dem_SetEventStatus((Dem_EventIdType)SPI_E_HARDWARE_ERROR_EVENT_ID,
                                         DEM_EVENT_STATUS_PASSED);
    #endif
                if (NULL_PTR != SeqCfgPtr->EndNotification)
                {
                    SeqCfgPtr->EndNotification();
                }
                Spi_StartNextJob(HWUnitQueue, CoreId);
            }
        }
    }
    else
    {
        SchM_Exit_Spi_UpdateJobState();
    }
}

/**
 * @brief     This function starts the transfer of the first scheduled job for a given HW unit.
 *
 * @param[in] HWUnitQueue: The HW Unit used for scheduling.
 * @param[in] CoreId: Core ID.
 *
 * @return    None
 *
 */
static void Spi_StartNextJob(Spi_HWUnitQueue *HWUnitQueue, uint32 CoreId)
{
    Spi_JobType  Job;
    Spi_JobType *JobListHead;
    sint8        Priority;
    sint8        MaxScheduledPriority;

    SchM_Enter_Spi_UpdateAsyncHWUnitQueue();
    MaxScheduledPriority = HWUnitQueue->MaxScheduledPriority;
    if (0 <= MaxScheduledPriority)
    {
        JobListHead = &HWUnitQueue->ScheduledJobsListHead[MaxScheduledPriority];
        Job = *JobListHead;

        *JobListHead = Spi_JobStateArray[Job].AsyncNextJob;

        if (SPI_JOB_NULL == *JobListHead)
        {
            HWUnitQueue->ScheduledJobsListTail[MaxScheduledPriority] = SPI_JOB_NULL;

            for (Priority = MaxScheduledPriority - 1; Priority >= 0; Priority--)
            {
                if (SPI_JOB_NULL != HWUnitQueue->ScheduledJobsListHead[Priority])
                {
                    break;
                }
            }
            HWUnitQueue->MaxScheduledPriority = Priority;
        }
        SchM_Exit_Spi_UpdateAsyncHWUnitQueue();

        Spi_JobStateArray[Job].Result = SPI_JOB_PENDING;
        HWUnitQueue->Channel = 0U;
        HWUnitQueue->Job = Job;
        Spi_TransferAsyncJob(SPI_JOB(CoreId, Job));
    }
    else
    {
        HWUnitQueue->Status = SPI_IDLE;
        SchM_Exit_Spi_UpdateAsyncHWUnitQueue();
    }
}

/**
 * @brief      This function initialize first channel transmission of a job.
 *
 * @param[in]  JobCfgPtr: Pointer to job configuration
 *
 * @return     None
 *
 */
static void Spi_TransferAsyncJob(const Spi_JobConfigType *JobCfgPtr)
{
    const Spi_Drvw_ExternalDeviceConfigType *ExternalDeviceConfig;
    const Spi_Drvw_ChannelConfigType        *ChannelCfgPtr;
    uint32                                   CoreId;
    boolean                                  IsLastChannel;

    CoreId = Spi_GetCoreID();
    if (NULL_PTR != JobCfgPtr->StartNotification)
    {
        JobCfgPtr->StartNotification();
    }

    if (1U < JobCfgPtr->ChannelNum)
    {
        IsLastChannel = (boolean)FALSE;
    }
    else
    {
        IsLastChannel = (boolean)TRUE;
    }

    ChannelCfgPtr = SPI_CHL(CoreId, JobCfgPtr->ChannelIndexList[0U]);
    ExternalDeviceConfig = JobCfgPtr->ExternalDeviceConfig->DrvwExternalDeviceConfigPtr;

    (void)Spi_Drvw_TransmitChannel(ChannelCfgPtr, ExternalDeviceConfig, (boolean)TRUE,
                                   IsLastChannel, (boolean)FALSE);
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/**
 * @brief      This function initiate channels state.
 *
 * @param[in]  CoreId: ID of core
 *
 * @return     None
 */
static void Spi_InitChannelsState(uint32 CoreId)
{
    uint32                            Channel;
    const Spi_Drvw_ChannelConfigType *ChannelCfgPtr;

    for (Channel = 0U; Channel <= (uint32)(SPI_CONF(CoreId)->SpiMaxChannel); Channel++)
    {
        ChannelCfgPtr = SPI_CHL(CoreId, Channel);
        if ((NULL_PTR != ChannelCfgPtr) && (CoreId == ChannelCfgPtr->SpiCoreUse))
        {
            Spi_ChannelStateArray[Channel].Flags = SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT;
            if (IB == ChannelCfgPtr->BufferType)
            {
                Spi_ChannelStateArray[Channel].Length = ChannelCfgPtr->Length;
            }
            else
            {
                ChannelCfgPtr->BufferDescriptor->TxBuffer = NULL_PTR;
                ChannelCfgPtr->BufferDescriptor->RxBuffer = NULL_PTR;
                Spi_ChannelStateArray[Channel].Length = (Spi_NumberOfDataType)0U;
            }
        }
    }
}

/**
 * @brief      This function initiate jobs state.
 *
 * @param[in]  CoreId: ID of core
 *
 * @return     None
 */
static void Spi_InitJobsState(uint32 CoreId)
{
    uint32                   Job;
    const Spi_JobConfigType *JobCfgPtr;

    /* initialize job results */
    for (Job = 0U; Job <= (uint32)(SPI_CONF(CoreId)->SpiMaxJob); Job++)
    {
        JobCfgPtr = SPI_JOB(CoreId, Job);
        if ((NULL_PTR != JobCfgPtr) && (CoreId == JobCfgPtr->SpiCoreUse))
        {
            Spi_JobStateArray[Job].Result = SPI_JOB_OK;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
            Spi_JobStateArray[Job].AsyncSequenceState = NULL_PTR;
#endif
        }
    }
}

/**
 * @brief      This function initiate sequences state.
 *
 * @param[in]  CoreId: ID of core
 *
 * @return     None
 */
static void Spi_InitSequencesState(uint32 CoreId)
{
    uint32                        Sequence;
    const Spi_SequenceConfigType *SeqCfgPtr;
#if ((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0))
    #if (SPI_CONCURRENT_SYNC_TRANSMIT_SUPPORT == STD_ON)
    Spi_HWUnitType HWUnit;
    uint32         Job;
    #endif
#endif

    for (Sequence = 0U; Sequence <= (uint32)(SPI_CONF(CoreId)->SpiMaxSequence); Sequence++)
    {
        SeqCfgPtr = SPI_SEQ(CoreId, Sequence);
        if ((NULL_PTR != SeqCfgPtr) && (CoreId == SeqCfgPtr->SpiCoreUse))
        {
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
            Spi_SequenceStateArray[Sequence].Sequence = SeqCfgPtr;
#endif
            Spi_SequenceStateArray[Sequence].Result = SPI_SEQ_OK;

#if ((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0))
    #if (SPI_CONCURRENT_SYNC_TRANSMIT_SUPPORT == STD_ON)
            Spi_SeqUsedHWUnits[Sequence] = (uint32)0;

            for (Job = 0U; Job < SeqCfgPtr->JobNum; Job++)
            {
                HWUnit = SPI_JOB(CoreId, SeqCfgPtr->JobIndexList[Job])->HWUnit;

                Spi_SeqUsedHWUnits[Sequence] |= (uint32)((uint32)1 << (HWUnit));
            }
    #else  /* (SPI_CONCURRENT_SYNC_TRANSMIT_SUPPORT == STD_OFF) */
            Spi_SeqUsedHWUnits[Sequence] = 0xFFFFFFFFU;
    #endif /* (SPI_CONCURRENT_SYNC_TRANSMIT_SUPPORT == STD_OFF) */
#endif     /* ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
        }
        else
        {
            /* Nothing to do */
        }
    }
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @brief      Service for SPI initialization.
 *             - Service ID: 0x00
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @param[in]  ConfigPtr: Pointer to configuration set
 *
 * @return     None
 */
void Spi_Init(const Spi_ConfigType *ConfigPtr)
{
    Spi_HWUnitType HWUnit;
    uint32         CoreId = Spi_GetCoreID();
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckInit(CoreId, ConfigPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

#if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
        SPI_CONF(CoreId) = ConfigPtr;
#else
    SPI_CONF(CoreId) = Spi_PreDefinedConfigPtr[CoreId];
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_OFF) */
        /* Initialize State of Channels, Jobs and Sequences */
        Spi_InitChannelsState(CoreId);
        Spi_InitJobsState(CoreId);
        Spi_InitSequencesState(CoreId);

        /* Initialize HWUnits */
        for (HWUnit = (Spi_HWUnitType)0; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
        {
            if ((NULL_PTR != SPI_HWUNIT(CoreId, HWUnit)) &&
                (CoreId == SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse))
            {
                Spi_Drvw_Init(HWUnit, SPI_HWUNIT(CoreId, HWUnit));

#if (SPI_LEVEL_DELIVERED == LEVEL1)
                Spi_Drvw_SetAsyncMode(HWUnit, SPI_DRVW_INTERRUPT_MODE);
#endif
#if (SPI_LEVEL_DELIVERED == LEVEL2)
                Spi_Drvw_SetAsyncMode(HWUnit, SPI_DRVW_POLLING_MODE);
#endif
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
                Spi_InitAsyncJobsList(HWUnit);
#endif
                Spi_HWUnitQueueArray[HWUnit].Status = SPI_IDLE;
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief      Service for SPI de-initialization.
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      de-initialisation command has been accepted
 * @retval     E_NOT_OK:  de-initialisation command has not been accepted
 *
 */
Std_ReturnType Spi_DeInit(void)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    Spi_HWUnitType HWUnit;
    uint32         CoreId;

    CoreId = Spi_GetCoreID();

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == SPI_CONF(CoreId))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(SPI_SID_DEINIT, SPI_E_UNINIT);
    }
    else
    {
#endif
        if (SPI_IDLE == Spi_GetStatus())
        {
            for (HWUnit = (Spi_HWUnitType)0; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
            {
                if ((NULL_PTR != SPI_HWUNIT(CoreId, HWUnit)) &&
                    (CoreId == SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse))
                {
                    Spi_Drvw_DeInit(HWUnit);

                    Spi_HWUnitQueueArray[HWUnit].Status = SPI_UNINIT;
                }
                else
                {
                    /* Nothing to do */
                }
            }
            /* Reset configuration pointer */
            SPI_CONF(CoreId) = NULL_PTR;
        }
        else
        {
            Ret = E_NOT_OK;
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Ret;
}

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      Service for writing one or more data to an IB SPI Handler/Driver Channel specified by
 * parameter.
 *             - Service ID: 0x02
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Channel: Channel ID
 * @param[in]  DataBufferPtr: Pointer to source data buffer. If this pointer is null, it is assumed
 * that the data to be transmitted is not relevant and the default transmit value of this channel
 * will be used instead.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Command has been accepted
 * @retval     E_NOT_OK:  Command has not been accepted
 *
 */
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr)
{
    Std_ReturnType                    Ret = (Std_ReturnType)E_OK;
    uint16                            Index;
    Spi_Drvw_ChannelStateType        *ChannelState;
    const Spi_Drvw_ChannelConfigType *ChannelCfgPtr;
    Spi_DataBufferType               *DataBufferDes;
    const Spi_DataBufferType         *DataBufferSrc;
    uint32                            CoreId;

    CoreId = Spi_GetCoreID();

    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Ret = Spi_CheckWriteIB(CoreId, Channel);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif
        ChannelState = &Spi_ChannelStateArray[Channel];
        ChannelCfgPtr = SPI_CHL(CoreId, Channel);

        SchM_Enter_Spi_UpdateChannelState();
        if (NULL_PTR != DataBufferPtr)
        {
            DataBufferDes = ChannelCfgPtr->BufferDescriptor->TxBuffer;
            DataBufferSrc = DataBufferPtr;
            for (Index = 0U; Index < ChannelCfgPtr->Length; Index++)
            {
                *DataBufferDes = *DataBufferSrc;
                DataBufferDes++;
                DataBufferSrc++;
            }
            ChannelState->Flags =
                (uint8)(ChannelState->Flags & ((uint8)(~SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT)));
        }
        else
        {
            ChannelState->Flags |= SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT;
        }
        SchM_Exit_Spi_UpdateChannelState();
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif

    return Ret;
}
#endif /* ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) ||(SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) ) */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief      Service to transmit data on the SPI bus.
 *             - Service ID: 0x03
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Sequence: Sequence ID
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Transmission command has been accepted
 * @retval     E_NOT_OK:  Transmission command has not been accepted
 *
 */
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
    Std_ReturnType                Ret = (Std_ReturnType)E_OK;
    Spi_JobType                   JobNum;
    Spi_JobType                   JobIndex;
    const Spi_SequenceConfigType *SeqCfgPtr;
    Spi_SequenceStateType        *SequenceState;
    const Spi_JobConfigType      *JobCfgPtr;
    const Spi_JobType            *Job;
    const Spi_JobType            *JobCount;
    uint32                        CoreId;

    CoreId = Spi_GetCoreID();

    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Ret = Spi_CheckAsyncTransmit(CoreId, Sequence);
    if ((Std_ReturnType)E_OK == Ret)
    {
    #endif
        SeqCfgPtr = SPI_SEQ(CoreId, Sequence);
        JobNum = SeqCfgPtr->JobNum;

        Ret = Spi_LockAsyncSequence(Sequence, SeqCfgPtr);
        if ((Std_ReturnType)E_OK != Ret)
        {
            (void)Det_ReportRuntimeError((uint16)SPI_MODULE_ID, (uint8)0, SPI_SID_ASYNC_TRANSMIT,
                                         SPI_E_SEQ_PENDING);
        }
        else
        {
            SequenceState = &Spi_SequenceStateArray[Sequence];
            SequenceState->Result = SPI_SEQ_PENDING;

            SequenceState->RemainingJobs = SeqCfgPtr->JobNum - 1U;
            Job = &SeqCfgPtr->JobIndexList[0];
            SequenceState->CurrentJobIndexPointer = Job;
            for (JobIndex = 0U; JobIndex < JobNum; JobIndex++)
            {
                JobCount = &SeqCfgPtr->JobIndexList[JobIndex];
                Spi_JobStateArray[*JobCount].Result = SPI_JOB_QUEUED;
            }
            JobCfgPtr = SPI_JOB(CoreId, *Job);
            Spi_ScheduleNewJob(&Spi_HWUnitQueueArray[JobCfgPtr->HWUnit], *Job, JobCfgPtr);
        }
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

    return Ret;
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      Service for reading synchronously one or more data from an IB SPI Handler/Driver
 * Channel specified by parameter.
 *             - Service ID: 0x04
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]   Channel: Channel ID
 * @param[out]  DataBufferPtr: Pointer to destination data buffer in RAM
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      read command has been accepted
 * @retval     E_NOT_OK:  read command has not been accepted
 *
 */
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPtr)
{
    Std_ReturnType                    Ret = (Std_ReturnType)E_OK;
    Spi_NumberOfDataType              Index;
    const Spi_Drvw_ChannelConfigType *ChannelCfgPtr;
    const Spi_DataBufferType         *DataBufferSrc;
    Spi_DataBufferType               *DataBufferDes;
    uint32                            CoreId;

    CoreId = Spi_GetCoreID();

    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Ret = Spi_CheckReadIB(CoreId, Channel, DataBufferPtr);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif
        ChannelCfgPtr = SPI_CHL(CoreId, Channel);
        DataBufferSrc = ChannelCfgPtr->BufferDescriptor->RxBuffer;
        DataBufferDes = DataBufferPtr;
        for (Index = 0U; Index < ChannelCfgPtr->Length; Index++)
        {
            *DataBufferDes = *DataBufferSrc;
            DataBufferDes++;
            DataBufferSrc++;
        }
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif

    return Ret;
}
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2)) */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
/**
 * @brief      Service to setup the buffers and the length of data for the EB SPI Handler/Driver
 * Channel specified.
 *             - Service ID: 0x05
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Channel: Channel ID
 * @param[in]  SrcDataBufferPtr: Pointer to source data buffer
 * @param[out] DesDataBufferPtr: Pointer to destination data buffer in RAM.
 * @param[in]  Length: Length (number of data elements) of the data to be transmitted from
 * SrcDataBufferPtr and/or received from DesDataBufferPtr Min.: 1 Max.: Max of data specified at
 * configuration for this channel.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Setup command has been accepted
 * @retval     E_NOT_OK:  Setup command has not been accepted
 *
 */
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, Spi_DataBufferType *SrcDataBufferPtr,
                           Spi_DataBufferType *DesDataBufferPtr, Spi_NumberOfDataType Length)
{
    Std_ReturnType                    Ret = (Std_ReturnType)E_OK;
    Spi_Drvw_ChannelStateType        *ChannelState;
    const Spi_Drvw_ChannelConfigType *ChannelCfgPtr;
    uint32                            CoreId;

    CoreId = Spi_GetCoreID();
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Ret = Spi_CheckSetupEB(CoreId, Channel, Length);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif
        ChannelState = &Spi_ChannelStateArray[Channel];
        ChannelCfgPtr = SPI_CHL(CoreId, Channel);
        ChannelCfgPtr->BufferDescriptor->TxBuffer = SrcDataBufferPtr;
        ChannelCfgPtr->BufferDescriptor->RxBuffer = DesDataBufferPtr;

        ChannelState->Length = Length;
        SchM_Enter_Spi_UpdateChannelState();
        if (NULL_PTR != SrcDataBufferPtr)
        {
            ChannelState->Flags &= (uint8)(~SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT);
        }
        else
        {
            ChannelState->Flags |= SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT;
        }

        if (NULL_PTR != DesDataBufferPtr)
        {
            ChannelState->Flags &= (uint8)(~SPI_DRVW_CHANNEL_FLAG_RX_DISCARD);
        }
        else
        {
            ChannelState->Flags |= SPI_DRVW_CHANNEL_FLAG_RX_DISCARD;
        }
        SchM_Exit_Spi_UpdateChannelState();
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return Ret;
}
#endif /* ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )   \
        */

/**
 * @brief     Service returns the SPI Handler/Driver software module status.
 *            - Service ID: 0x06
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @return    Spi_StatusType
 * @retval    SPI_UNINIT:  The driver is un-initialized
 * @retval    SPI_IDLE:    The driver has no pending transfers
 * @retval    SPI_BUSY:    The driver is busy
 *
 */
Spi_StatusType Spi_GetStatus(void)
{
    Spi_StatusType Status = SPI_IDLE;
    Spi_HWUnitType HWUnit;
    uint32         CoreId;

    CoreId = Spi_GetCoreID();

    if (NULL_PTR == SPI_CONF(CoreId))
    {
        Status = SPI_UNINIT;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        SPI_DET_REPORT_ERROR(SPI_SID_GET_STATUS, SPI_E_UNINIT);
#endif
    }
    else
    {
        /* check HWUnit busy */
        for (HWUnit = 0U; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
        {
            if ((NULL_PTR != SPI_HWUNIT(CoreId, HWUnit)) &&
                (CoreId == SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse))
            {
                if ((TRUE == Spi_SyncHWUnitsBusyStatus[HWUnit]) ||
                    (SPI_BUSY == Spi_HWUnitQueueArray[HWUnit].Status))
                {
                    Status = SPI_BUSY;
                    break;
                }
            }
        }
    }
    return Status;
}

/**
 * @brief     This service returns the last transmission result of the specified Job.
 *            - Service ID: 0x07
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Job: Job ID
 *
 * @return    Spi_JobResultType
 * @retval    SPI_JOB_OK:        The job ended successfully
 * @retval    SPI_JOB_PENDING:   The job is pending
 * @retval    SPI_JOB_FAILED:    The job has failed
 * @retval    SPI_JOB_QUEUED:    The job has been accepted
 */
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
{
    Spi_JobResultType JobResult;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32 CoreId;
    CoreId = Spi_GetCoreID();
    JobResult = Spi_CheckGetJobResult(CoreId, Job);
    if (SPI_JOB_FAILED != JobResult)
    {
#endif
        JobResult = Spi_JobStateArray[Job].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return JobResult;
}

/**
 * @brief     This service returns the last transmission result of the specified Sequence.
 *            - Service ID: 0x08
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Sequence: Sequence ID. An invalid sequence ID will return an undefined result.
 *
 * @return    Spi_SeqResultType
 * @retval    SPI_SEQ_OK:       The sequence ended successfully
 * @retval    SPI_SEQ_PENDING:  The sequence is pending
 * @retval    SPI_SEQ_FAILED:   The sequence has failed
 * @retval    SPI_SEQ_CANCELLED:The sequence has been canceled
 */
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
    Spi_SeqResultType SequenceResult;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32 CoreId;
    CoreId = Spi_GetCoreID();

    SequenceResult = Spi_CheckGetSequenceResult(CoreId, Sequence);
    if (SPI_SEQ_FAILED != SequenceResult)
    {
#endif
        SequenceResult = Spi_SequenceStateArray[Sequence].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return SequenceResult;
}

#if (SPI_VERSION_INFO_API == STD_ON)
/**
 * @brief      This service returns the version information of this module.
 *             pre-established configurations
 *             - Service ID: 0x09
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[inout] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 */
void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        SPI_DET_REPORT_ERROR(SPI_SID_GET_VERSION_INFO, SPI_E_PARAM_POINTER);
    }
    else
    {
    #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
        versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
        versioninfo->moduleID = (uint16)SPI_MODULE_ID;
        versioninfo->sw_major_version = (uint8)SPI_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)SPI_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)SPI_SW_PATCH_VERSION;
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
}
#endif /* (SPI_VERSION_INFO_API == STD_ON) */

#if ((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0))
/**
 * @brief     Service to transmit data on the SPI bus.
 *            - Service ID: 0x0a
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Sequence: Sequence ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:       Transmission command has been completed successfully
 * @retval    E_NOT_OK:   Transmission command has not been accepted
 *
 */
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    Spi_SequenceStateType        *SequenceState;
    Std_ReturnType                Ret = (Std_ReturnType)E_OK;
    Spi_HWUnitType                HWUnit;
    Spi_JobType                   JobIndex;
    const Spi_SequenceConfigType *SeqCfgPtr;
    Spi_JobType                   JobNum;
    Spi_JobType                   Job;
    const Spi_JobConfigType      *JobCfgPtr;
    uint32                        CoreId;

    CoreId = Spi_GetCoreID();

    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Ret = Spi_CheckSyncTransmit(CoreId, Sequence);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
        SeqCfgPtr = SPI_SEQ(CoreId, Sequence);
        JobNum = SeqCfgPtr->JobNum;

        SchM_Enter_Spi_UpdateSyncHWUnitStatus();
        for (HWUnit = 0U; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
        {
            if (0U !=
                ((Spi_SyncHWUnitsBusyStatus[HWUnit] << HWUnit) & Spi_SeqUsedHWUnits[Sequence]))
            {
                Ret = (Std_ReturnType)E_NOT_OK;
            }
        }

        if ((Std_ReturnType)E_NOT_OK != Ret)
        {
            SequenceState = &Spi_SequenceStateArray[Sequence];
            SequenceState->Result = SPI_SEQ_PENDING;
            /* set used HW units as busy */
            for (JobIndex = 0U; JobIndex < JobNum; JobIndex++)
            {
                Job = SeqCfgPtr->JobIndexList[JobIndex];
                JobCfgPtr = SPI_JOB(CoreId, Job);
                HWUnit = JobCfgPtr->HWUnit;
                Spi_SyncHWUnitsBusyStatus[HWUnit] = TRUE;
            }
            SchM_Exit_Spi_UpdateSyncHWUnitStatus();
            Ret = Spi_SyncTransmitSequence(SeqCfgPtr, CoreId);

            if ((Std_ReturnType)E_OK == Ret)
            {
                SequenceState->Result = SPI_SEQ_OK;
    #if (SPI_E_HARDWARE_ERROR_ENABLE == STD_ON)
                (void)Dem_SetEventStatus((Dem_EventIdType)SPI_E_HARDWARE_ERROR_EVENT_ID,
                                         DEM_EVENT_STATUS_PASSED);
    #endif
            }
            else
            {
                SequenceState->Result = SPI_SEQ_FAILED;
    #if (SPI_E_HARDWARE_ERROR_ENABLE == STD_ON)
                (void)Dem_SetEventStatus((Dem_EventIdType)SPI_E_HARDWARE_ERROR_EVENT_ID,
                                         DEM_EVENT_STATUS_FAILED);
    #endif
            }

            SchM_Enter_Spi_UpdateSyncHWUnitStatus();
            for (JobIndex = 0U; JobIndex < JobNum; JobIndex++)
            {
                Job = SeqCfgPtr->JobIndexList[JobIndex];
                JobCfgPtr = SPI_JOB(CoreId, Job);
                HWUnit = JobCfgPtr->HWUnit;
                Spi_SyncHWUnitsBusyStatus[HWUnit] = FALSE;
            }
            SchM_Exit_Spi_UpdateSyncHWUnitStatus();

            if (NULL_PTR != SeqCfgPtr->EndNotification)
            {
                SeqCfgPtr->EndNotification();
            }
            else
            {
                /* Nothing to do */
            }
        }
        else
        {
            SchM_Exit_Spi_UpdateSyncHWUnitStatus();
    #if (SPI_CONCURRENT_SYNC_TRANSMIT_SUPPORT == STD_ON)
            (void)Det_ReportRuntimeError((uint16)SPI_MODULE_ID, (uint8)0, SPI_SID_SYNC_TRANSMIT,
                                         SPI_E_SEQ_IN_PROCESS);
    #endif
        }
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif

    return Ret;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

#if (SPI_HW_STATUS_API == STD_ON)
/**
 * @brief     This service returns the status of the specified SPI Hardware microcontroller
 * peripheral.
 *            - Service ID: 0x0b
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] HWUnit: SPI Hardware microcontroller peripheral (unit) ID.
 *
 * @return    Spi_StatusType
 * @retval    SPI_UNINIT:  The peripheral is un-initialized
 * @retval    SPI_IDLE:    The peripheral is in idle state
 * @retval    SPI_BUSY:    The peripheral is busy
 *
 */
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    Spi_StatusType Status = SPI_UNINIT;
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint32         CoreId = Spi_GetCoreID();
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckHWUnit(CoreId, HWUnit, SPI_SID_GET_HWUNIT_STATUS);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif
        Status = Spi_HWUnitQueueArray[HWUnit].Status;
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return Status;
}
#endif /* (SPI_HW_STATUS_API == STD_ON) */

#if (SPI_CANCEL_API == STD_ON)
/**
 * @brief     Service cancels the specified on-going sequence transmission.
 *            - Service ID: 0x0c
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Sequence: Sequence ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK       The command ended successfully
 * @retval    E_NOT_OK   The command has failed.
 *
 */
void Spi_Cancel(Spi_SequenceType Sequence)
{
    #if ((SPI_DEV_ERROR_DETECT == STD_ON) ||                                                       \
         ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0)))
    uint32 CoreId = Spi_GetCoreID();
    #endif
    #if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0))
    const Spi_JobConfigType      *JobCfgPtr;
    boolean                       SlaveMode;
    const Spi_SequenceConfigType *SeqCfgPtr;
    #endif
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

    Ret = Spi_CheckCancel(CoreId, Sequence);
    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif
        /* @todo handle cancel */
        Spi_SequenceStateArray[Sequence].Result = SPI_SEQ_CANCELLED;
    #if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0))
        SeqCfgPtr = SPI_SEQ(CoreId, Sequence);
        JobCfgPtr = SPI_JOB(CoreId, SeqCfgPtr->JobIndexList[0U]);
        SlaveMode = SPI_HWUNIT(CoreId, JobCfgPtr->HWUnit)->PhyUnitConfigPtr->SlaveMode;
        if (TRUE == SlaveMode)
        {
            Spi_Drvw_SlaveCancel(JobCfgPtr->HWUnit);
            Spi_JobTransferFinished(JobCfgPtr, SPI_JOB_FAILED);
        }
    #endif
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}
#endif /* (SPI_CANCEL_API == STD_ON) */

#if (SPI_LEVEL_DELIVERED == LEVEL2)
/**
 * @brief     Service to set the asynchronous mechanism mode for SPI busses handled asynchronously.
 *            - Service ID: 0x0d
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Mode: New mode required.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:       Setting command has been done.
 * @retval    E_NOT_OK:   Setting command has not been accepted.
 *
 */
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    Spi_HWUnitType HWUnit;
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    uint32         CoreId;

    /* Get current coreID */
    CoreId = Spi_GetCoreID();

    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == SPI_CONF(CoreId))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
        SPI_DET_REPORT_ERROR(SPI_SID_SET_ASYNC_MODE, SPI_E_UNINIT);
    }
    else
    {
    #endif
        /*SWS_Spi_00171 SWS_Spi_00172*/
        Ret = Spi_GetHWUnitsBusyStatus(CoreId);
        if ((Std_ReturnType)E_NOT_OK != Ret)
        {
            for (HWUnit = 0U; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
            {
                if ((NULL_PTR != SPI_HWUNIT(CoreId, HWUnit)) &&
                    (CoreId == SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse) &&
                    (SPI_DRVW_PHYUNIT_ASYNC == SPI_HWUNIT(CoreId, HWUnit)->IsSync))
                {
                    if (SPI_POLLING_MODE == Mode)
                    {
                        Spi_Drvw_SetAsyncMode(HWUnit, SPI_DRVW_POLLING_MODE);
                    }
                    else
                    {
                        Spi_Drvw_SetAsyncMode(HWUnit, SPI_DRVW_INTERRUPT_MODE);
                    }
                }
            }
        }
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif

    return Ret;
}
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) */

/**
 * @brief     Service to set the asynchronous mechanism mode for a specified HWUnit.
 *
 * @param[in] HWUnit: The ID of the HWUnit to be configured.
 * @param[in] Mode: Polling or Interrupt mode
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Setting command has been done
 * @retval    E_NOT_OK: setting command has not been accepted.
 *
 */
#if ((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
Std_ReturnType Spi_SetHWUnitAsyncMode(Spi_HWUnitType HWUnit, Spi_AsyncModeType Mode)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;
    uint32         CoreId = Spi_GetCoreID();

    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Ret = Spi_CheckHWUnit(CoreId, HWUnit, SPI_SID_SET_HWUNIT_ASYNC_MODE);

    if ((Std_ReturnType)E_NOT_OK != Ret)
    {
    #endif
        if (SPI_DRVW_PHYUNIT_ASYNC != SPI_HWUNIT(CoreId, HWUnit)->IsSync)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
            SPI_DET_REPORT_ERROR(SPI_SID_SET_HWUNIT_ASYNC_MODE, SPI_E_UNINIT);
    #endif
        }
        else if (SPI_BUSY == Spi_HWUnitQueueArray[HWUnit].Status)
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if (SPI_POLLING_MODE == Mode)
            {
                Spi_Drvw_SetAsyncMode(HWUnit, SPI_DRVW_POLLING_MODE);
            }
            else
            {
                Spi_Drvw_SetAsyncMode(HWUnit, SPI_DRVW_INTERRUPT_MODE);
            }
        }
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
    #endif

    return Ret;
}
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

/**
 * @brief     This function polls SPI interrupts for asynchronous transmission.
 *            - Service ID:       0x10
 *
 * @return    None
 *
 */
void Spi_MainFunction_Handling(void)
{
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    Spi_HWUnitType HWUnit;
    uint32         CoreId;

    CoreId = Spi_GetCoreID();

    if (NULL_PTR != SPI_CONF(CoreId))
    {
        for (HWUnit = 0U; HWUnit < (Spi_HWUnitType)SPI_MAX_CFG_HWUNITS; HWUnit++)
        {
            if ((NULL_PTR != SPI_HWUNIT(CoreId, HWUnit)) &&
                (CoreId == SPI_HWUNIT(CoreId, HWUnit)->SpiCoreUse))
            {
                if (SPI_BUSY == Spi_HWUnitQueueArray[HWUnit].Status)
                {
                    Spi_Drvw_PollAsyncTransmit(HWUnit);
                }
            }
        }
    }
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */
}

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief     This function is called after a channel has been finished.
 *
 * @param[in] HwUnit: Hardware unit id.
 * @param[in] JobResultOK: Job Result OK or not.
 *
 * @return    None
 *
 */
void Spi_ChannelEndCallback(Spi_Drvw_HWUnitType HwUnit, boolean JobResultOK)
{
    uint32                                   CoreId;
    Spi_ChannelType                          ChannelIndex;
    Spi_ChannelType                          NumberOfChannels;
    Spi_ChannelType                          ChannelNumber;
    Spi_JobType                              Job;
    const Spi_Drvw_ChannelConfigType        *ChannelCfgPtr;
    boolean                                  IsLastChannel;
    const Spi_Drvw_ExternalDeviceConfigType *ExternalDeviceConfig;
    const Spi_JobConfigType                 *JobCfg;
    Spi_JobResultType                        JobResult;
    CoreId = Spi_GetCoreID();

    ChannelIndex = Spi_HWUnitQueueArray[HwUnit].Channel;
    Job = Spi_HWUnitQueueArray[HwUnit].Job;
    JobCfg = SPI_JOB(CoreId, Job);
    NumberOfChannels = JobCfg->ChannelNum;

    if (TRUE == JobResultOK)
    {
        JobResult = SPI_JOB_OK;
    }
    else
    {
        JobResult = SPI_JOB_FAILED;
    }
    if (((ChannelIndex + 1U) < NumberOfChannels) && (SPI_JOB_OK == JobResult))
    {
        Spi_HWUnitQueueArray[HwUnit].Channel++;
        ChannelIndex++;

        if (ChannelIndex == (NumberOfChannels - 1U))
        {
            IsLastChannel = (boolean)TRUE;
        }
        else
        {
            IsLastChannel = (boolean)FALSE;
        }
        ChannelNumber = JobCfg->ChannelIndexList[ChannelIndex];
        ChannelCfgPtr = SPI_CHL(CoreId, ChannelNumber);
        ExternalDeviceConfig = JobCfg->ExternalDeviceConfig->DrvwExternalDeviceConfigPtr;
        (void)Spi_Drvw_TransmitChannel(ChannelCfgPtr, ExternalDeviceConfig, (boolean)FALSE,
                                       IsLastChannel, (boolean)FALSE);
    }
    else
    {
        Spi_JobTransferFinished(JobCfg, JobResult);
    }
}
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi */

/** @} end of group Spi_Module */
