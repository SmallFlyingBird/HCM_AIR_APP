/**
 * @file    Spi.c
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
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 1505 Rule 3.4:  The function is only referenced in the translation unit where it is defined.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Spi.h"
#include "Spi_Lld.h"
#include "SchM_Spi.h"
#include "OsIf.h"
#include "Det.h"

#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_C                      (180)
#define SPI_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SPI_AR_RELEASE_MINOR_VERSION_C       (4)
#define SPI_AR_RELEASE_REVISION_VERSION_C    (0)
#define SPI_SW_MAJOR_VERSION_C               (2)
#define SPI_SW_MINOR_VERSION_C               (3)
#define SPI_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_VENDOR_ID)
#error "Spi.c and Spi.h have different vendor ids"
#endif

/* Check if source file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Spi.c and Spi.h are different"
#endif

/* Check if source file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Spi.c and Spi.h are different"
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Det.h header file are of the same Software version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION))
#error "AutoSar Version Numbers of Spi.h and Det.h are different"
#endif
#endif

#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* Check if the current file and Dem.h header file are of the same version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (SPI_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION))
#error "AutoSar Version Numbers of Spi.c and Dem.h are different"
#endif
#endif /* SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON */

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#if (SPI_PRECOMPILE_SUPPORT == STD_ON)
#define SPI_UNUSED_PARAM(parma) ((void)parma)
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

SPI_VAR const Spi_ConfigType *Spi_ConfigPtr = NULL_PTR;

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief Spi Sequence State.
*/
SPI_VAR static Spi_SequenceStateType Spi_SequenceState[SPI_MAX_SEQUENCE];

/**
* @brief Spi Job State.
*/
SPI_VAR Spi_JobStateType Spi_JobState[SPI_MAX_JOB];

/**
* @brief Spi Channel State.
*/
SPI_VAR Spi_ChannelStateType Spi_ChannelState[SPI_MAX_CHANNEL];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/*==================================================================================================
                                                EXTERNAL VARIABLES
==================================================================================================*/
#if (SPI_PRECOMPILE_SUPPORT == STD_ON)
extern const Spi_ConfigType Spi_PreCompileConfig;
#endif
/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

#define SPI_START_SEC_VAR_INIT_8
#include "Spi_MemMap.h"

SPI_VAR static uint8 Spi_InitStatus = (uint8)SPI_DRIVER_DEINITIALIZE;

#define SPI_STOP_SEC_VAR_INIT_8
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief Array of HW units queues.
*/
SPI_VAR Spi_HWUnitQueueType Spi_HwUnitQueues[SPI_MAX_HW_UNIT_USED];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief Spi Sync Transmit Running HWUnits Status.
*/
SPI_VAR static volatile uint32 Spi_SyncHWUnitsBusyStatus[SPI_MAX_HW_UNIT_USED];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief Array of used HW units per Sequence:
*         The element corresponding to a given Sequence will have asserted the bits
*         corresponding to the used HW units.
*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#define   SPI_START_SEC_VAR_CLEARED_32
#include "Spi_MemMap.h"

SPI_VAR static uint32 Spi_SeqUsedHwUnits[SPI_MAX_SEQUENCE];

#define   SPI_STOP_SEC_VAR_CLEARED_32
#include "Spi_MemMap.h"
#endif

/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @brief            This function is called in order to mark the jobs of a Sequence as ready to be transmitted.
 * @details          For each Job in Sequence, the function checks if it is already
 *                   linked to another pending Sequence.
 *                   If at least one Job is already linked, the function returns E_NOT_OK.
 *                   Elsewhere, all jobs in Sequence are locked (linked to the current Sequence)
 * @param[in]        Sequence        The Sequence ID.
 * @param[in]        SequencePtr     The Sequence configuration.
 *
 * @return           Std_ReturnType
 * @retval E_OK      The given Sequence does not share its jobs with some
 *                   other sequences, and all its jobs were successfully
 *                   locked.
 * @retval E_NOT_OK  The given Sequence shares its jobs with some other
 *                   sequences. No lock performed for its jobs.
 *
 * @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
 */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
SPI_FUNC static Std_ReturnType Spi_LockJobs(Spi_SequenceType Sequence, const Spi_SequenceConfigType *SequencePtr)
{
    Std_ReturnType Status = (Std_ReturnType)E_OK;
    Spi_JobType JobCount = SequencePtr->NumJobs;
    const Spi_JobType *JobsPtr = SequencePtr->JobIndexListPtr;
    Spi_JobStateType *JobStatePtr;
    Spi_SequenceStateType *SequenceStatePtr;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00();
    /* use an optimized implementation for one Job sequences */
    if (1u == JobCount)
    {
        JobStatePtr = &Spi_JobState[*JobsPtr];
        if (NULL_PTR == JobStatePtr->AsyncCrtSequenceStatePtr)
        {
            /* Job not yet linked => link it to the current Sequence */
            JobStatePtr->AsyncCrtSequenceStatePtr = &Spi_SequenceState[Sequence];
        }
        else
        {
            /* the Job is already locked by a pending Sequence */
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        SequenceStatePtr = &Spi_SequenceState[Sequence];
        while (0u < JobCount)
        {
            JobStatePtr = &Spi_JobState[*JobsPtr];
            if (NULL_PTR == JobStatePtr->AsyncCrtSequenceStatePtr)
            {
                /* Job not yet linked => link it to the current Sequence */
                JobStatePtr->AsyncCrtSequenceStatePtr = SequenceStatePtr;
            }
            else
            {
                /* the Job is already locked by a pending Sequence =>
                   rollback all the previous locks */
                if (JobCount < SequencePtr->NumJobs)
                {
                    do
                    {
                        ++JobCount;
                        /*
                        * @violates @ref Spi_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        --JobsPtr;
                        Spi_JobState[*JobsPtr].AsyncCrtSequenceStatePtr = NULL_PTR;
                    } while (JobCount < SequencePtr->NumJobs);
                }
                else
                {
                    /* Do nothing */
                }
                Status = (Std_ReturnType)E_NOT_OK;
                break;
            }

            /* next Job */
            --JobCount;
            /*
             * @violates @ref Spi_c_REF_6 Array indexing shall be
             *       the only allowed form of pointer arithmetic.
             */
            ++JobsPtr;
        }
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00();

    return Status;
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/**
* @brief   This function returns the Status of the SPI driver related to async HW Units.
* @details Return SPI_BUSY if at least one async HW unit is busy.
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL2.
*/
#if (SPI_LEVEL_DELIVERED == LEVEL2)
SPI_FUNC LOCAL_INLINE Spi_StatusType Spi_GetAsyncStatus(void)
{
    Spi_StatusType StatusFlag = SPI_IDLE;

    if (NULL_PTR == Spi_ConfigPtr)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_STATUS, SPI_E_UNINIT);
#endif
        StatusFlag = SPI_UNINIT;
    }
    else
    {
        /* check if at least one async HW unit is busy */
        for (Spi_HWUnitType HwUnit = 0; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
        {
            if ((SPI_BUSY == Spi_HwUnitQueues[HwUnit].Status) &&
                    (Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].IsSync == (boolean)SPI_PHYUNIT_ASYNC))
            {
                StatusFlag = SPI_BUSY;
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    return StatusFlag;
}
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) */

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
SPI_FUNC void Spi_180_DemReportStatus(uint8 EventStatus)
{
    /* Call Dem_SetEventStatus. */
    if ((uint32)STD_ON == Spi_ConfigPtr->SpiErrorHardwareCfg.State)
    {
        (void)Dem_SetEventStatus(Spi_ConfigPtr->SpiErrorHardwareCfg.Id, EventStatus);
    }
    else
    {
        /* Do nothing */
    }
}
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function will schedule a Job for a given HW unit.
* @details If the HWUnit is not busy, the transfer is started and the HW unit is
*          marked as busy.
*          If the HWUnit is not busy (another Job is in progress), the new Job is
*          scheduled in a waiting Job list, according to its Priority.
*
* @param[in]      HWUnitQueuePtr     The HW Unit to be used by the Job
* @return         void
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
*/
SPI_FUNC void Spi_ScheduleNextJob(Spi_HWUnitQueueType *HWUnitQueuePtr)
{
    Spi_JobType Job;
    Spi_JobType *JobListHeadPtr;
    sint8 Priority;
    sint8 MaxScheduledPriority;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01();
    MaxScheduledPriority = HWUnitQueuePtr->MaxScheduledPriority;
    if (0 > MaxScheduledPriority)
    {
        /* no Job waiting => mark the HWUnit as IDLE */
        HWUnitQueuePtr->Status = SPI_IDLE;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();
    }
    else
    {
        /* a Job is waiting => get the Job ID from the highest Priority queue */
        JobListHeadPtr = &HWUnitQueuePtr->ScheduledJobsListHead[MaxScheduledPriority];
        Job = *JobListHeadPtr;

        /* set the new head of the list */
        *JobListHeadPtr = Spi_JobState[Job].AsyncNextJob;

        /* if the list is empty, set the tail accordingly and adjust the
           scheduled Priority level */
        if (SPI_JOB_NULL == *JobListHeadPtr)
        {
            /* reset the tail */
            HWUnitQueuePtr->ScheduledJobsListTail[MaxScheduledPriority] = SPI_JOB_NULL;

            /* find the first non empty scheduling queue */
            for (Priority = (MaxScheduledPriority - 1); Priority >= 0; --Priority)
            {
                if (SPI_JOB_NULL != HWUnitQueuePtr->ScheduledJobsListHead[Priority])
                {
                    /* there is a scheduled Job for this Priority level */
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }

            /* Priority is set on the highest Priority queue having
               scheduled jobs, or -1 if no other jobs scheduled */
            HWUnitQueuePtr->MaxScheduledPriority = Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();

        /* mark the Job as pending */
        Spi_JobState[Job].Result = SPI_JOB_PENDING;
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
#ifdef SPI_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Spi_Lld_AsyncTransmitJob, &Spi_ConfigPtr->JobConfigPtr[Job]);
#else
        Spi_Lld_AsyncTransmitJob(&Spi_ConfigPtr->JobConfigPtr[Job]);
#endif
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
SPI_FUNC Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
    const Spi_SequenceConfigType *SequenceConfigPtr = NULL_PTR;
    const Spi_JobConfigType *JobConfigPtr = NULL_PTR;
    const Spi_JobType *CpJob;
    const Spi_JobType *CpJobCount;
    Spi_JobType JobIndex;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    Spi_JobType Job;
#endif
    Spi_SequenceStateType *SequenceStatePtr = NULL_PTR;
    Std_ReturnType RtnTemp = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else
    {
        SequenceConfigPtr = &Spi_ConfigPtr->SequenceConfigPtr[Sequence];

        if (Sequence >= Spi_ConfigPtr->MaxSequence)
        {
            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_PARAM_SEQ);
            RtnTemp = E_NOT_OK;
        }
        else if (0U == SequenceConfigPtr->NumJobs)
        {
            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_EMPTY);
            RtnTemp = E_NOT_OK;
        }
        else
        {
            for (JobIndex = 0; JobIndex < SequenceConfigPtr->NumJobs; ++JobIndex)
            {
                Job = SequenceConfigPtr->JobIndexListPtr[JobIndex];
                if (0U == Spi_ConfigPtr->JobConfigPtr[Job].NumChannels)
                {
                    (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_JOB_EMPTY);
                    RtnTemp = E_NOT_OK;
                }
                else
                {

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
                    /* Check if all EBs have been setup */
                    for (Spi_ChannelType ChannelIndex = 0; ChannelIndex < Spi_ConfigPtr->JobConfigPtr[Job].NumChannels; ++ChannelIndex)
                    {
                        if ((SPI_EB == Spi_ConfigPtr->ChannelConfigPtr[ChannelIndex].BufferType) && \
                                (0U == Spi_ConfigPtr->ChannelConfigPtr[ChannelIndex].Length))
                        {
                            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_ASYNC_TRANSMIT, SPI_E_CHANNEL_EMPTY);
                            RtnTemp = E_NOT_OK;
                        }
                    }
#endif /**( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )*/
                }
            }
            if (E_OK == RtnTemp)
#endif/**#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
            {
#if (SPI_DEV_ERROR_DETECT == STD_OFF)
                SequenceConfigPtr = &Spi_ConfigPtr->SequenceConfigPtr[Sequence];
#endif /**#if (SPI_DEV_ERROR_DETECT == STD_OFF)*/

                RtnTemp = Spi_LockJobs(Sequence, SequenceConfigPtr);
                if ((Std_ReturnType)E_OK == RtnTemp)
                {
                    SequenceStatePtr = &Spi_SequenceState[Sequence];
                    /* Mark Sequence pending */
                    SequenceStatePtr->Result = SPI_SEQ_PENDING;

                    /* Initialize Job related information */
                    SequenceStatePtr->RemainingJobs = SequenceConfigPtr->NumJobs - 1u;

                    CpJob = &SequenceConfigPtr->JobIndexListPtr[0];
                    SequenceStatePtr->CurrentJobIndexPtr = CpJob;

                    for (JobIndex = 0U; JobIndex < SequenceConfigPtr->NumJobs; ++JobIndex)
                    {
                        CpJobCount = &SequenceConfigPtr->JobIndexListPtr[JobIndex];
                        Spi_JobState[*CpJobCount].Result = SPI_JOB_QUEUED;
                    }
                    /* Schedule transmission of the first Job */
                    JobConfigPtr = &Spi_ConfigPtr->JobConfigPtr[*CpJob];

#ifdef SPI_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call3params(Spi_ScheduleJob, &Spi_HwUnitQueues[JobConfigPtr->HWUnit], *CpJob, JobConfigPtr);
#else
                    Spi_ScheduleJob(&Spi_HwUnitQueues[JobConfigPtr->HWUnit], *CpJob, JobConfigPtr);
#endif
                }
                else
                {
                    /* Call Det_ReportRuntimeError*/
                    (void)Det_ReportRuntimeError((uint16)SPI_MODULE_ID, (uint8)0, SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
                }
            }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/
    return RtnTemp;
}
#endif /**((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))*/

#if SPI_CANCEL_API == STD_ON
SPI_FUNC void Spi_Cancel(Spi_SequenceType Sequence)
{
#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0))
    const Spi_JobConfigType *JobConfig;
#endif /**((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0))*/
#if (((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0)) || (SPI_DEV_ERROR_DETECT == STD_ON))
    const Spi_SequenceConfigType *SequenceConfigPtr = NULL_PTR;
#endif /**(((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0)) || (SPI_DEV_ERROR_DETECT == STD_ON))*/
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_CANCEL, SPI_E_UNINIT);
    }
    else if (Sequence >= Spi_ConfigPtr->MaxSequence)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_CANCEL, SPI_E_PARAM_SEQ);
    }
    else
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
    {
#if (((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_LEVEL_DELIVERED != LEVEL0)) || (SPI_DEV_ERROR_DETECT == STD_ON))
        SequenceConfigPtr = &Spi_ConfigPtr->SequenceConfigPtr[Sequence];
#endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR == SequenceConfigPtr)
        {
            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_CANCEL, SPI_E_PARAM_SEQ);
        }
        else
#endif
        {
            /*Set Sequence State to cancel*/
            Spi_SequenceState[Sequence].Result = SPI_SEQ_CANCELLED;

            /* In Slave mode: Stop Sequence immediately */
#if (SPI_SLAVE_SUPPORT == STD_ON)
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
            JobConfig = &Spi_ConfigPtr->JobConfigPtr[SequenceConfigPtr->JobIndexListPtr[0U]];
#ifdef SPI_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Spi_Lld_SlaveCancel, JobConfig);
#else
            Spi_Lld_SlaveCancel(JobConfig);
#endif

#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */
#endif /* #if (SPI_SLAVE_SUPPORT == STD_ON) */
        }
    }
}
#endif /**SPI_CANCEL_API == STD_ON*/

SPI_FUNC Std_ReturnType Spi_DeInit(void)
{
    Std_ReturnType RtnTemp = E_OK;
    uint8 Instance;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_DE_INIT, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else
    {
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
        if (Spi_GetStatus() == SPI_BUSY)
        {
            RtnTemp = E_NOT_OK;
        }
        else
        {
            for (Spi_HWUnitType HwUint = 0; HwUint < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUint)
            {
                Instance = Spi_ConfigPtr->HWUnitConfigPtr[HwUint].Instance;

#ifdef SPI_ENABLE_USER_MODE_SUPPORT
                RtnTemp = OsIf_Trusted_Call_Return1param(Spi_Lld_DeInit, Instance);
#else
                RtnTemp = Spi_Lld_DeInit(Instance);
#endif
                if (E_NOT_OK == RtnTemp)
                {
                    break;
                }
                else
                {
                    Spi_HwUnitQueues[HwUint].Status = SPI_UNINIT;
                    Spi_SyncHWUnitsBusyStatus[HwUint] = 0U;
                }
            }

        }

        if (E_OK == RtnTemp)
        {
            Spi_ConfigPtr = NULL_PTR;
            Spi_InitStatus = (uint8)SPI_DRIVER_DEINITIALIZE;
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/

    return RtnTemp;
}

#if SPI_HW_STATUS_API == STD_ON
SPI_FUNC Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    Spi_StatusType Status = SPI_UNINIT;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_HW_UNIT_STATUS, SPI_E_UNINIT);
    }
    else if (HWUnit >= Spi_ConfigPtr->MaxHWUnitUsed)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_HW_UNIT_STATUS, SPI_E_PARAM_UNIT);
    }
    else
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
    {
        Status = Spi_HwUnitQueues[HWUnit].Status;
    }
    return Status;
}
#endif /**SPI_HW_STATUS_API == STD_ON*/

SPI_FUNC Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
{

    Spi_JobResultType JobResult = SPI_JOB_FAILED;

#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_JOB_RESULT, SPI_E_UNINIT);
    }
    /* Job Valid Range - from 0 to Spi_Max_Job*/
    else if (Job >= Spi_ConfigPtr->MaxJob)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_JOB);
    }
    else
    {
#endif
        JobResult = Spi_JobState[Job].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return JobResult;
}

SPI_FUNC Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
    Spi_SeqResultType SequenceResult = SPI_SEQ_FAILED;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_SEQUENCE_RESULT, SPI_E_UNINIT);
    }
    /* Sequence Valid Range from 0 to Spi_Max_Sequence*/
    else if (Sequence >= Spi_ConfigPtr->MaxSequence)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_SEQUENCE_RESULT, SPI_E_PARAM_SEQ);
    }
    else
    {
#endif
        SequenceResult = Spi_SequenceState[Sequence].Result;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return SequenceResult;
}

SPI_FUNC Spi_StatusType Spi_GetStatus(void) /* PRQA S 1505 */
{
    Spi_StatusType StatusFlag = SPI_IDLE;
    Spi_HWUnitType HwUnit = 0;

    if (NULL_PTR == Spi_ConfigPtr)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_GET_STATUS, SPI_E_UNINIT);
#endif
        StatusFlag = SPI_UNINIT;
    }
    else
    {
        /* The SPI Handler Driver software module shall be busy when any
           HWUnit is busy */
        for (HwUnit = 0u; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
        {
            if (1U == Spi_SyncHWUnitsBusyStatus[HwUnit])
            {
                StatusFlag = SPI_BUSY;
                break;
            }
            else
            {
                /*Do nothing*/
            }
        }

        /* check for busy HWUnit in async transmissions*/
        if (SPI_BUSY != StatusFlag)
        {
            /* Note: Checking for IsSync attribute for HWUnit is not really needed
                 It is preferable to skip this check in order to have a more compact code
            */
            for (HwUnit = 0u; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
            {
                if (SPI_BUSY == Spi_HwUnitQueues[HwUnit].Status)
                {
                    StatusFlag = SPI_BUSY;
                    break;
                }
                else
                {
                    /*Do nothing*/
                }
            }
        }
        else
        {
            /*Do nothing*/
        }
    }
    return StatusFlag;
}

SPI_FUNC void Spi_Init(const Spi_ConfigType *ConfigPtr)
{
    Spi_JobType Job;
    Spi_HWUnitType HwUnit;
    Std_ReturnType RtnTemp = E_OK;

#if ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    Spi_JobType JobInSeq = 0;
#endif /*#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)*/
#endif /*((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))*/

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Spi driver is in INIT State */
    if (Spi_InitStatus == (uint8)SPI_DRIVER_INITIALIZED)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED);
        RtnTemp = E_NOT_OK;
    }
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
    if (E_OK == RtnTemp)
    {
#if (SPI_PRECOMPILE_SUPPORT == STD_ON)
        Spi_ConfigPtr = &Spi_PreCompileConfig;
        SPI_UNUSED_PARAM(ConfigPtr);
#else
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Check parameters: configPtr  */
        if (NULL_PTR == ConfigPtr)
        {
            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_POINTER);
            RtnTemp = E_NOT_OK;
        }
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
        Spi_ConfigPtr = ConfigPtr;
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_ON) */

#if (SPI_DEV_ERROR_DETECT == STD_ON)
        if (E_OK == RtnTemp)
        {
            /* configuration sizes must be checked for  Post Build & Link Time configurations */
            if (Spi_ConfigPtr->MaxChannel > SPI_MAX_CHANNEL)
            {
                (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_CHANNEL);
                RtnTemp = E_NOT_OK;
            }
            else if (Spi_ConfigPtr->MaxJob > SPI_MAX_JOB)
            {
                (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_JOB);
                RtnTemp = E_NOT_OK;
            }
            else if (Spi_ConfigPtr->MaxSequence > SPI_MAX_SEQUENCE)
            {
                (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_INIT, SPI_E_PARAM_SEQ);
                RtnTemp = E_NOT_OK;
            }
            else
            {
                /* Do nothing*/
            }
        }
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
        if (E_OK == RtnTemp)
        {
            for (Spi_ChannelType Channel = 0; Channel < Spi_ConfigPtr->MaxChannel; ++Channel)
            {
                /* Check if configured buffers are External (EB) */
                if (SPI_EB == Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferType)
                {
                    /* Initialize all buffers */
                    Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferDescriptorPtr->BufferTXPtr = NULL_PTR;
                    Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferDescriptorPtr->BufferRXPtr = NULL_PTR;

                    /* Channel length is zero for unconfigured external buffers */
                    Spi_ChannelState[Channel].Length = 0;
                }
                else
                {
                    /* Setup Channel length according to configuration */
                    Spi_ChannelState[Channel].Length = Spi_ConfigPtr->ChannelConfigPtr[Channel].Length;
                }
                Spi_ChannelState[Channel].Flags = SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }

            /* initialize Job results */
            for (Job = 0; Job < Spi_ConfigPtr->MaxJob; ++Job)
            {
                Spi_JobState[Job].Result = SPI_JOB_OK;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
                /* mark the Job as unlocked / not linked to a pending async Sequence */
                Spi_JobState[Job].AsyncCrtSequenceStatePtr = NULL_PTR;
#endif /*#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))*/

#ifdef SPI_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call2params(Spi_Lld_SetPcsPolarityMode, Spi_ConfigPtr, Job);
#else
                Spi_Lld_SetPcsPolarityMode(Spi_ConfigPtr, Job);
#endif
            }
            /* initialize Sequence*/
            for (Spi_SequenceType Sequence = 0; Sequence < Spi_ConfigPtr->MaxSequence; ++Sequence)
            {
                /* initialize Sequence results */
                Spi_SequenceState[Sequence].Result = SPI_SEQ_OK;
                Spi_SequenceState[Sequence].SequencePtr = &Spi_ConfigPtr->SequenceConfigPtr[Sequence];
#if ((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
                /* initialize the map of used HWUnits per Sequence */
                Spi_SeqUsedHwUnits[Sequence] = (uint32)0;
                for (Job = 0; Job < Spi_ConfigPtr->SequenceConfigPtr[Sequence].NumJobs; ++Job)
                {
                    JobInSeq = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr[Job];
                    HwUnit = Spi_ConfigPtr->JobConfigPtr[JobInSeq].HWUnit;
                    Spi_SeqUsedHwUnits[Sequence] |= (uint32)1U << HwUnit;
                }
#else /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
                /* mark all HW units as used by the sync transmission, in order to
                   force the mutual exclusion of Spi_SyncTransmit() calls */
                Spi_SeqUsedHwUnits[Sequence] = 0xFFFFFFFFU;
#endif /*#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)*/
#endif /*((SPI_LEVEL_DELIVERED == LEVEL0) || (SPI_LEVEL_DELIVERED == LEVEL2))*/
            }

            /* initialize all external device HWUnits */
            for (HwUnit = 0; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
            {
                /* initialize global State pointer*/
                (void)Spi_Lld_GlobalStateInit(HwUnit);

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
                /* initialize the Job lists => no scheduled Job for the unit */
                for (uint8 Priority = 0; Priority < SPI_JOB_PRIORITY_LEVELS_COUNT; ++Priority)
                {
                    Spi_HwUnitQueues[HwUnit].ScheduledJobsListHead[Priority] = SPI_JOB_NULL;
                    Spi_HwUnitQueues[HwUnit].ScheduledJobsListTail[Priority] = SPI_JOB_NULL;
                }
                /* no scheduled Job => MaxScheduledPriority is -1 */
                Spi_HwUnitQueues[HwUnit].MaxScheduledPriority = -1;
#endif
                Spi_HwUnitQueues[HwUnit].Status = SPI_IDLE;

                /* Initialize the Spi Sync Transmit Running HWUnits Status. */
                Spi_SyncHWUnitsBusyStatus[HwUnit] = 0U;
            }
        }
        else
        {
            Spi_ConfigPtr = NULL_PTR;
        }
    }
}

SPI_FUNC void Spi_MainFunction_Handling(void)
{
    uint8 Instance;

    if (NULL_PTR != Spi_ConfigPtr)
    {
        for (Spi_HWUnitType HwUnit = 0u; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
        {
            if (FALSE == Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].IsSync)
            {
                Instance = Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].Instance;
                if (SPI_BUSY == Spi_HwUnitQueues[HwUnit].Status)
                {
#ifdef SPI_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call1param(Spi_Lld_IrqPolling, Instance);
#else
                    Spi_Lld_IrqPolling(Instance);
#endif
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_MAIN_FUNCTION_HANDLING, SPI_E_UNINIT);
    }
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
}

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2))
SPI_FUNC Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPointer)
{
    const Spi_DataBufferType *DataSrcPtr = NULL_PTR;
    Spi_DataBufferType *DataDecPtr = NULL_PTR;
    const Spi_ChannelConfigType *ChannelConfigPtr = NULL_PTR;
    Std_ReturnType RtnTemp = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_READ_IB, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else if ((Channel >= Spi_ConfigPtr->MaxChannel) || (SPI_EB == Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferType))
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_READ_IB, SPI_E_PARAM_CHANNEL);
        RtnTemp = E_NOT_OK;
    }
    else if (NULL_PTR == DataBufferPointer)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_READ_IB, SPI_E_PARAM_POINTER);
        RtnTemp = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
    if (E_OK == RtnTemp)
    {
        ChannelConfigPtr = &Spi_ConfigPtr->ChannelConfigPtr[Channel];
        DataSrcPtr = ChannelConfigPtr->BufferDescriptorPtr->BufferRXPtr;
        DataDecPtr = DataBufferPointer;
        for (Spi_NumberOfDataType DataReadlIndex = 0; DataReadlIndex < ChannelConfigPtr->Length; ++DataReadlIndex)
        {
            *DataDecPtr = *DataSrcPtr;
            ++DataDecPtr;
            ++DataSrcPtr;
        }
    }
    return RtnTemp;
}
#endif /**( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )*/

#if SPI_LEVEL_DELIVERED == LEVEL2
SPI_FUNC Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    Std_ReturnType RtnTemp = E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        /*check pointer is not NULL*/
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SET_ASYNC_MODE, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else
    {
#endif /*(SPI_DEV_ERROR_DETECT == STD_ON)*/
        if (SPI_BUSY == Spi_GetAsyncStatus())
        {
            RtnTemp = E_NOT_OK;
        }
        else
        {
            /*set the async mode for each HW Unit;*/
            for (Spi_HWUnitType HwUnit = 0; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
            {
                if (FALSE == Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].IsSync)
                {
                    Spi_Lld_SetAsyncMode(HwUnit, Mode);
                }
                else
                {
                    /*Do nothing*/
                }
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return RtnTemp;
}
#endif/*#if SPI_LEVEL_DELIVERED == LEVEL2*/

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
SPI_FUNC Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, Spi_DataBufferType *SrcDataBufferPtr, \
                                    Spi_DataBufferType *DesDataBufferPtr, Spi_NumberOfDataType Length)
{
    Spi_ChannelStateType *ChannelStatePtr;
    const Spi_ChannelConfigType *ChannelConfigPtr;
    Std_ReturnType RtnTemp = E_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else if ((Channel >= Spi_ConfigPtr->MaxChannel) || (SPI_IB == Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferType))
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_PARAM_CHANNEL);
        RtnTemp = E_NOT_OK;
    }

    else if ((Length > Spi_ConfigPtr->ChannelConfigPtr[Channel].Length) || (0u == Length))
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_PARAM_LENGTH);
        RtnTemp = E_NOT_OK;
    }
    /* Length and Framesize - aren't compatible */
    /* If 8 < Framesize =< 16: Length must be divisible by 2 */
    else if ((Spi_ConfigPtr->ChannelConfigPtr[Channel].DataWidth > 8U) && (Spi_ConfigPtr->ChannelConfigPtr[Channel].DataWidth < 17U))
    {
        if (0U != (Length % 2U))
        {
            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_PARAM_LENGTH);
            RtnTemp = E_NOT_OK;
        }
    }
    /* If 16 < Framesize =< 32: Length must be divisible by 4 */
    else if ((Spi_ConfigPtr->ChannelConfigPtr[Channel].DataWidth > 16U) && (Spi_ConfigPtr->ChannelConfigPtr[Channel].DataWidth < 33U))
    {
        if (0U != (Length % 4U))
        {
            (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SETUP_EB, SPI_E_PARAM_LENGTH);
            RtnTemp = E_NOT_OK;
        }
    }
    else
    {
        /* Do nothing */
    }
    if (E_OK == RtnTemp)
    {
#endif /**(SPI_DEV_ERROR_DETECT == STD_ON)*/
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02();
        ChannelConfigPtr = &Spi_ConfigPtr->ChannelConfigPtr[Channel];
        ChannelConfigPtr->BufferDescriptorPtr->BufferTXPtr = SrcDataBufferPtr;
        ChannelConfigPtr->BufferDescriptorPtr->BufferRXPtr = DesDataBufferPtr;

        ChannelStatePtr = &Spi_ChannelState[Channel];
        ChannelStatePtr->Length = Length;

        /* if source data pointer is zero, transmit default value */
        if (NULL_PTR == SrcDataBufferPtr)
        {
            ChannelStatePtr->Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
        }
        else
        {
            ChannelStatePtr->Flags &= (uint8)(~SPI_CHANNEL_FLAG_TX_DEFAULT_U8);
        }

        /* if destination data pointer is zero, discard receiving data */
        if (NULL_PTR == DesDataBufferPtr)
        {
            ChannelStatePtr->Flags |= SPI_CHANNEL_FLAG_RX_DISCARD_U8;
        }
        else
        {
            ChannelStatePtr->Flags &= (uint8)(~SPI_CHANNEL_FLAG_RX_DISCARD_U8);
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* #if (SPI_DEV_ERROR_DETECT == STD_ON)*/

    return RtnTemp;
}
#endif /**( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )*/

#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)
SPI_FUNC Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    Spi_JobType JobIndex = 0;
    Spi_HWUnitType HwUnit = 0;
    Std_ReturnType RtnTemp = E_OK;
    Spi_JobType JobInSeq = 0;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    Spi_ChannelType ChannelInJob = 0;
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else if (Sequence >= Spi_ConfigPtr->MaxSequence)
    {
        /* Check if parameter Sequence valid*/
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_SEQ);
        RtnTemp = E_NOT_OK;
    }
    else
    {
        for (JobIndex = 0; JobIndex < Spi_ConfigPtr->SequenceConfigPtr[Sequence].NumJobs; ++JobIndex)
        {
            JobInSeq = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr[JobIndex];
            HwUnit = Spi_ConfigPtr->JobConfigPtr[JobInSeq].HWUnit;

            if ((boolean)SPI_PHYUNIT_ASYNC == Spi_ConfigPtr->HWUnitConfigPtr[HwUnit].IsSync)
            {
                /* HwUnit is not prearranged for dedicated Synchronous transmission */
                (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_UNIT);
                RtnTemp = E_NOT_OK;
            }
            else
            {
                /* Do nothing*/
            }

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
            if (E_OK == RtnTemp)
            {
                /* Check if all EBs have been setup */
                for (Spi_ChannelType ChannelIndex = 0; ChannelIndex < Spi_ConfigPtr->JobConfigPtr[JobInSeq].NumChannels; ++ChannelIndex)
                {
                    ChannelInJob = Spi_ConfigPtr->JobConfigPtr[JobInSeq].ChannelLinkPtr[ChannelIndex];

                    if ((SPI_EB == Spi_ConfigPtr->ChannelConfigPtr[ChannelInJob].BufferType) && (0U == Spi_ChannelState[ChannelInJob].Length))
                    {
                        /* An used EB not initialized  */
                        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_UNIT);
                        RtnTemp = E_NOT_OK;
                        break;
                    }
                }
            }
#endif/*#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )*/

            if (E_NOT_OK == RtnTemp)
            {
                break;
            }
        }
#endif/*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
        if (E_OK == RtnTemp)
        {
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03();
            /* check if there are HW units already running */
            for (HwUnit = 0u; HwUnit < Spi_ConfigPtr->MaxHWUnitUsed; ++HwUnit)
            {
                if (0U != ((Spi_SyncHWUnitsBusyStatus[HwUnit] << HwUnit) & Spi_SeqUsedHwUnits[Sequence])) /*NOSONAR, no memory overruns here*/
                {
                    RtnTemp = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    /* Do nothing */
                }
            }
            if (E_OK == RtnTemp)
            {
                /* Set the Sequence as pending*/
                Spi_SequenceState[Sequence].Result = SPI_SEQ_PENDING;
                /* set used HW units as busy */
                for (JobIndex = 0; JobIndex < Spi_ConfigPtr->SequenceConfigPtr[Sequence].NumJobs; ++JobIndex)
                {
                    JobInSeq = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr[JobIndex];
                    /* Logical Spi HWUnit */
                    HwUnit = Spi_ConfigPtr->JobConfigPtr[JobInSeq].HWUnit;
                    Spi_SyncHWUnitsBusyStatus[HwUnit] = 1U;
                }
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03();

#ifdef SPI_ENABLE_USER_MODE_SUPPORT
                RtnTemp = OsIf_Trusted_Call_Return1param(Spi_Lld_SyncTransmit, Sequence);
#else
                RtnTemp = Spi_Lld_SyncTransmit(Sequence);
#endif

                if (E_OK == RtnTemp)
                {
                    /* Set the Sequence as OK */
                    Spi_SequenceState[Sequence].Result = SPI_SEQ_OK;
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                    /* Report to DEM */
                    Spi_180_DemReportStatus(DEM_EVENT_STATUS_PASSED);
#endif
                }
                else
                {
                    /* Set the Sequence as FAILED */
                    Spi_SequenceState[Sequence].Result = SPI_SEQ_FAILED;
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                    /* Report to DEM */
                    Spi_180_DemReportStatus(DEM_EVENT_STATUS_FAILED);
#endif
                }
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04();
                /* set used HW units as idle */
                for (JobIndex = 0; JobIndex < Spi_ConfigPtr->SequenceConfigPtr[Sequence].NumJobs; ++JobIndex)
                {
                    JobInSeq = Spi_ConfigPtr->SequenceConfigPtr[Sequence].JobIndexListPtr[JobIndex];
                    /* Logical Spi HWUnit */
                    HwUnit = Spi_ConfigPtr->JobConfigPtr[JobInSeq].HWUnit;
                    Spi_SyncHWUnitsBusyStatus[HwUnit] = 0U;
                }
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04();

                if (NULL_PTR != Spi_ConfigPtr->SequenceConfigPtr[Sequence].SeqEndNotification)
                {
                    Spi_ConfigPtr->SequenceConfigPtr[Sequence].SeqEndNotification();
                }
            }
            else
            {
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03();
#if ((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0))
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
                /* Call Det_ReportRuntimeError */
                (void)Det_ReportRuntimeError((uint16)SPI_MODULE_ID, (uint8) 0, SPI_SID_SYNC_TRANSMIT, SPI_E_SEQ_IN_PROCESS);
#endif /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON) */
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) */
            }
        }
        else
        {
            /* Do nothing */
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/

    return RtnTemp;
}
#endif /**#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)*/

#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) ||  (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
SPI_FUNC Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr)
{
    const Spi_DataBufferType *TxBufferSrcPtr = NULL_PTR;
    Spi_DataBufferType *TxBufferDecPtr = NULL_PTR;
    Std_ReturnType RtnTemp = E_OK;
    Spi_ChannelStateType *ChannelStatePtr;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_ConfigPtr)
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_WRITE_IB, SPI_E_UNINIT);
        RtnTemp = E_NOT_OK;
    }
    else if ((Channel >= Spi_ConfigPtr->MaxChannel) || (Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferType == SPI_EB))
    {
        (void)Det_ReportError((uint16)SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SID_WRITE_IB, SPI_E_PARAM_CHANNEL);
        RtnTemp = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

#endif /*#if (SPI_DEV_ERROR_DETECT == STD_ON)*/
    if (E_OK == RtnTemp)
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05();
        ChannelStatePtr = &Spi_ChannelState[Channel];
        if (NULL_PTR == DataBufferPtr)
        {
            ChannelStatePtr->Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
        }
        else
        {
            TxBufferSrcPtr = DataBufferPtr;
            TxBufferDecPtr = Spi_ConfigPtr->ChannelConfigPtr[Channel].BufferDescriptorPtr->BufferTXPtr;

            for (Spi_NumberOfDataType DataWriteIndex = 0; DataWriteIndex < Spi_ConfigPtr->ChannelConfigPtr[Channel].Length; ++DataWriteIndex)
            {
                *TxBufferDecPtr = *TxBufferSrcPtr;
                ++TxBufferSrcPtr;
                ++TxBufferDecPtr;
            }
            ChannelStatePtr->Flags &= ((uint8)(~SPI_CHANNEL_FLAG_TX_DEFAULT_U8));
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();
    }
    return RtnTemp;
}
#endif /**( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )*/

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

