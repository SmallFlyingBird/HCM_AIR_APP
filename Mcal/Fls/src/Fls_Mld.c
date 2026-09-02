/**
* @file    Fls_Mld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Fls_Mld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Fls_Cfg.h"
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
#include "Fls_Qspi_Types.h"
#include "Fls_Lld_Qspi.h"
#include "Fls_Lld_QspiFls.h"
#include "Fls_Qspi_Cfg.h"
#endif /*(FLS_QSPI_SECTORS_CONFIGURED == STD_ON)*/
#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)
#include "Fls_Lld.h"
#endif /*(FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)*/
#include "Fls_Mld.h"
#include "Fls.h"
#include "OsIf.h"


/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_MLD_VENDOR_ID_C                     (180)
#define FLS_MLD_AR_REL_MAJOR_VER_C              (4)
#define FLS_MLD_AR_REL_MINOR_VER_C              (4)
#define FLS_MLD_AR_REL_REVISION_VER_C           (0)
#define FLS_MLD_SW_MAJOR_VER_C                  (2)
#define FLS_MLD_SW_MINOR_VER_C                  (3)
#define FLS_MLD_SW_PATCH_VER_C                  (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FLS_MLD header file are of the same vendor */
#if (FLS_MLD_VENDOR_ID_C != FLS_MLD_VENDOR_ID)
#error "Fls_Mld.c and Fls_Mld.h have different vendor ids"
#endif

/* Check if source file and FLS_MLD header file are of the same Autosar version */
#if (( FLS_MLD_AR_REL_MAJOR_VER_C != FLS_MLD_AR_REL_MAJOR_VER) || \
      ( FLS_MLD_AR_REL_MINOR_VER_C != FLS_MLD_AR_REL_MINOR_VER) || \
      ( FLS_MLD_AR_REL_REVISION_VER_C != FLS_MLD_AR_REL_REVISION_VER))
#error "AutoSar Version Numbers of Fls_Mld.c and Fls_Mld.h are different"
#endif

/* Check if source file and FLS_MLD header file are of the same Software version */
#if (( FLS_MLD_SW_MAJOR_VER_C != FLS_MLD_SW_MAJOR_VER) || \
      ( FLS_MLD_SW_MINOR_VER_C != FLS_MLD_SW_MINOR_VER) || \
      ( FLS_MLD_SW_PATCH_VER_C != FLS_MLD_SW_PATCH_VER))
#error "Software Version Numbers of Fls_Mld.c and Fls_Mld.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
extern Fls_JobStateType Fls_JobState;
extern const Fls_ConfigType *Fls_ConfigPtr;
extern volatile MemIf_JobResultType Fls_LLDJobResult;          /* implicit zero initialization: MEMIF_JOB_OK */
extern Fls_Lld_JobType Fls_LLDJob;    /* implicit zero initialization: FLASH_JOB_NONE */
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

FLS_FUNC static Fls_Lld_ReturnType Fls_Mld_SectorEraseEfmJobs(boolean Asynch, Fls_AddressType SectorOffset)
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    Fls_AddressType EraseHwAddr;
    uint16 TempSectorIt;
    Fls_Lld_StatusType TempFlsRet = STATUS_FTFC_FLS_IP_ERROR;
    TempSectorIt = Fls_JobState.JobSectorIt;
    EraseHwAddr = Fls_ConfigPtr->SectorList[TempSectorIt].SectorHwStartAddress + SectorOffset;
#ifdef FLS_USER_MODE_SUPPORTED
    TempFlsRet = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return2param(Fls_Lld_SectorErase, EraseHwAddr, Asynch);
#else
    TempFlsRet = Fls_Lld_SectorErase(EraseHwAddr, Asynch);
#endif
    LldRetVal = Fls_Lld_TranslateReturnCode(TempFlsRet);
#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
    /*check timeout after perform erase*/
    if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == TempFlsRet)
    {
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
    }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    return LldRetVal;
}


FLS_FUNC static inline Fls_Lld_ReturnType Fls_Mld_SectorWriteEfmJobs(const Fls_AddressType SectorOffset,
        const Fls_AddressType Length,
        const uint8 *JobDataSrcPtr,
        const boolean Asynch
                                                                    )
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    uint32 WriteStartAddress;
    /* Get the base address of the sector and add the offset. */
    WriteStartAddress = SectorOffset + Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwStartAddress;
    /* call lld write api */
#ifdef FLS_USER_MODE_SUPPORTED
    LldRetVal = (Fls_Lld_ReturnType)OsIf_Trusted_Call_Return4param(Fls_Lld_SectorWrite, WriteStartAddress, \
                Length, JobDataSrcPtr, Asynch);
#else
    LldRetVal = Fls_Lld_SectorWrite(WriteStartAddress, Length, JobDataSrcPtr, Asynch);
#endif
    return LldRetVal;
}
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 * Function Name : Fls_Mld_Init
 * Description   : Initializes the Flash module and device.
 * @implements     Fls_Mld_Init_Activity
 ******************************************************************************/
FLS_FUNC void Fls_Mld_Init(void)
{
    Fls_LLDJobResult = MEMIF_JOB_OK;
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
    Qspi_StatusType Status;
    boolean CheckId = (boolean)FALSE;
    /* Initialize QSPI controllers */
    Status = Fls_Lld_InitControllers();
    /* Initialize external flash devices */
    if (STATUS_QSPI_SUCCESS == Status)
    {
        Status = Fls_Lld_InitMemories();
    }
    /* Check the hardware ID of the external flash devices */
    if (STATUS_QSPI_SUCCESS == Status)
    {
#ifdef FLS_USER_MODE_SUPPORTED
        CheckId = (boolean)OsIf_Trusted_Call_Return(Fls_Lld_CheckDevicesId);
#else
        CheckId = Fls_Lld_CheckDevicesId();
#endif
    }
    if ((boolean)TRUE == CheckId)
    {
        Fls_LLDJobResult = MEMIF_JOB_OK;
    }
    else
    {
        Fls_LLDJobResult = MEMIF_JOB_FAILED;
    }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (MEMIF_JOB_OK == Fls_LLDJobResult)
    {
#if (STD_ON == FLS_INTERNAL_SECTORS_PROTECTION)
#ifdef FLS_USER_MODE_SUPPORTED
        if (STATUS_FTFC_FLS_IP_SUCCESS == (Fls_Lld_StatusType)OsIf_Trusted_Call_Return1param(Fls_Lld_Init, Fls_ConfigPtr->SectorProtection))
#else
        if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_Init(Fls_ConfigPtr->SectorProtection))
#endif /* #ifdef FLS_USER_MODE_SUPPORTED */
#else
#ifdef FLS_USER_MODE_SUPPORTED
        if (STATUS_FTFC_FLS_IP_SUCCESS == (Fls_Lld_StatusType)OsIf_Trusted_Call_Return1param(Fls_Lld_Init, NULL_PTR))
#else
        if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_Init(NULL_PTR))
#endif /* #ifdef FLS_USER_MODE_SUPPORTED */
#endif /* #if (STD_ON == FLS_INTERNAL_SECTORS_PROTECTION) */
        {
            /*To avoid affecting the the external fls initialized result,Nothing to do here*/
        }
        else
        {
            Fls_LLDJobResult = MEMIF_JOB_FAILED;
        }
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
    Fls_LLDJob = FLASH_JOB_NONE;
}

/*FUNCTION**********************************************************************
 * Function Name : Fls_Mld_AbortSuspended
 * Description   : Abort suspended the Flash device operation.
 * @implements     Fls_Mld_AbortSuspended_Activity
 ******************************************************************************/
FLS_FUNC void Fls_Mld_AbortSuspended(void)
{
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
    Fls_HwChType HwChannel;
    Qspi_StatusType Status = STATUS_QSPI_SUCCESS;
    Fls_SectorIndexType SectorIndexIter;
    uint32 FlashInstance;
    uint32 ControllerInstance;
    uint32 LastFlashInstance = FLS_DEVICE_INSTANCE_INVALID;
    for (SectorIndexIter = Fls_JobState.JobSectorIt; SectorIndexIter <= Fls_JobState.JobSectorEnd; ++SectorIndexIter)
    {
        /* Get channel type(INTERNAL, EXTERNAL_A, B,...) to determine the HW IP used(internal or external flash). */
        HwChannel = Fls_ConfigPtr->SectorList[SectorIndexIter].SectorHwCh;
        /* Get external flash instance */
        FlashInstance = Fls_ConfigPtr->SectorList[SectorIndexIter].SectFlashUnit;
        /* Check if this channel already was checked before */
        if ((FLS_CH_QSPI == HwChannel) && (FlashInstance != LastFlashInstance))
        {
            LastFlashInstance = FlashInstance;
            /* Get controller instance */
            ControllerInstance = Fls_ConfigPtr->ExtFlsCfgConfig->FlashMemCfg[FlashInstance].FlashConnectionCfg->QspiInstance;
            /* Prepare timeout counter */
            Fls_Qspi_ElapsedTicks = 0U;
            Fls_Qspi_TimeoutTicks = QSPI_CMD_COMPLETE_TIMEOUT;
            /* Wait for the controller to become idle */
            do
            {
#ifdef FLS_USER_MODE_SUPPORTED
                Status = (Qspi_StatusType)OsIf_Trusted_Call_Return1param(Qspi_Lld_ControllerGetStatus, ControllerInstance);
#else
                Status = Qspi_Lld_ControllerGetStatus(ControllerInstance);
#endif
                ++Fls_Qspi_ElapsedTicks;
                if ((STATUS_QSPI_BUSY == Status) && (Fls_Qspi_ElapsedTicks >= Fls_Qspi_TimeoutTicks))
                {
                    Status = STATUS_QSPI_TIMEOUT;
                }
            } while (STATUS_QSPI_BUSY == Status);
            if (STATUS_QSPI_SUCCESS == Status)
            {
                /* Check that external memory is idle */
#ifdef FLS_USER_MODE_SUPPORTED
                if ((Qspi_StatusType)OsIf_Trusted_Call_Return1param(Qspi_Lld_GetMemoryStatus, FlashInstance) != STATUS_QSPI_SUCCESS)
#else
                if (Qspi_Lld_GetMemoryStatus(FlashInstance) != STATUS_QSPI_SUCCESS)
#endif
                {
                    /* Reset external memory */
                    Status = Qspi_Lld_Reset(FlashInstance);
                }
            }
            if (STATUS_QSPI_SUCCESS != Status)
            {
                /*Exit for-loop*/
                Fls_LLDJob = FLASH_JOB_NONE;
                Fls_LLDJobResult = MEMIF_JOB_FAILED;
                break;
            }
        }
    }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
}


#if (FLS_CANCEL_API == STD_ON )
/*FUNCTION**********************************************************************
 * Function Name : Fls_Mld_Cancel
 * Description   : Cancel the flash device operation.
 * @implements     Fls_Mld_Cancel_Activity
 ******************************************************************************/
FLS_FUNC void Fls_Mld_Cancel(void)
{
    Fls_HwChType HwChannel;
    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    HwChannel = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwCh;
    if (MEMIF_JOB_PENDING == Fls_LLDJobResult)
    {
#if (FLS_INTERNAL_SECTORS_CONFIGURED==STD_ON)
        if (FLS_CH_INTERN == HwChannel)
        {
#ifdef FLS_USER_MODE_SUPPORTED
            if (STATUS_FTFC_FLS_IP_SUCCESS == OsIf_Trusted_Call_Return(Fls_Lld_Cancel))
#else
            if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_Cancel())
#endif /* #ifdef FLS_USER_MODE_SUPPORTED */
            {
                /* Mark the job as canceled.*/
                Fls_LLDJob = FLASH_JOB_NONE;
                Fls_LLDJobResult = MEMIF_JOB_CANCELED;
            }
        }
#endif /* #if (FLS_INTERNAL_SECTORS_CONFIGURED==STD_ON) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
        if (FLS_CH_QSPI == HwChannel)
        {
            /* Mark the job as canceled.*/
            Fls_LLDJob = FLASH_JOB_NONE;
            Fls_LLDJobResult = MEMIF_JOB_CANCELED;
        }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
        /* Mark the internal job as canceled.*/
        Fls_LLDJob = FLASH_JOB_NONE;
        Fls_LLDJobResult = MEMIF_JOB_CANCELED;
    }
}
#endif

/*FUNCTION**********************************************************************
 * Function Name : Fls_Mld_MainFunction
 * Description   : In case Async Operation is ongoing this function will complete
                   the following job:
 *                 - Erase
 *                 - Erase on Interleaved sectors
 *                 - Write
 *                 - Erase blank Check
 * @implements     Fls_Mld_MainFunction_Activity
 ******************************************************************************/
FLS_FUNC void Fls_Mld_MainFunction(void)
{
    Fls_HwChType HwChannel;
    /* Get channel type(INTERNAL, EXTERNAL_A1, A2,...) to determine the HW IP used(internal or external flash). */
    HwChannel = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwCh;
    if (MEMIF_JOB_PENDING == Fls_LLDJobResult)
    {
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
        if (FLS_CH_INTERN == HwChannel)
        {
            Fls_Lld_MainFunction();
        }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
        if (FLS_CH_QSPI == HwChannel)
        {
            Fls_Lld_LLDMainFunctionQspiJobs();
        }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    }   /* if (MEMIF_JOB_PENDING == Fls_LLDJobResult) */
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
    }
}

/*FUNCTION**********************************************************************
 * Function Name : Fls_Mld_SectorRead
 * Description   : Route Fls read, blank check, compare job to appropriate lld function.
 * @implements     Fls_Mld_SectorRead_Activity
 ******************************************************************************/
FLS_FUNC Fls_Lld_ReturnType Fls_Mld_SectorRead(const Fls_AddressType SectorOffset,
        const Fls_AddressType Length,
        uint8 *JobDataDestPtr,
        const uint8 *JobDataSrcPtr
                                              )
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    Fls_HwChType HwChannel;
#if ( (FLS_COMPARE_API == STD_OFF) && (FLS_BLANK_CHECK_API == STD_OFF) )
    (void)JobDataSrcPtr;
#endif  /* (( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON )) */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    Fls_Lld_StatusType ReturnCode = STATUS_FTFC_FLS_IP_ERROR;
    uint32 ReadStartAddress = 0U;
#endif /* #if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    Qspi_StatusType Status = STATUS_QSPI_SUCCESS;
    uint32 FlashInstance;
    Fls_AddressType ReadAddr;
#endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    HwChannel = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwCh;
    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == HwChannel)
    {
        /* Get the base address of the sector. */
        ReadStartAddress = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwStartAddress;
        /* Add the offset */
        ReadStartAddress += SectorOffset;
        /* Decide whether the job is a Read, a compare, or a blank check. */
        if (NULL_PTR != JobDataDestPtr)
        {
#ifdef FLS_USER_MODE_SUPPORTED
            ReturnCode = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return3param(Fls_Lld_ReadFlash, ReadStartAddress, Length, JobDataDestPtr);
#else
            ReturnCode = Fls_Lld_ReadFlash(ReadStartAddress, Length, JobDataDestPtr);
#endif
        }
#if (( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
        else
        {
#ifdef FLS_USER_MODE_SUPPORTED
            ReturnCode = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return3param(Fls_Lld_CompareFlash, ReadStartAddress, Length, JobDataSrcPtr);
#else
            ReturnCode = Fls_Lld_CompareFlash(ReadStartAddress, Length, JobDataSrcPtr);
#endif
        }
#endif  /* (( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON )) */
        LldRetVal = Fls_Lld_TranslateReturnCode(ReturnCode);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == HwChannel)
    {
        /* Get external flash instance */
        FlashInstance = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectFlashUnit;
        /* Initialize job parameters */
        /* Compute target address : sector address + offset */
        ReadAddr = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwStartAddress + SectorOffset;
        /* Decide whether the job is a Read, a compare, or a blank check. */
        if (NULL_PTR != JobDataDestPtr)
        {
#ifdef FLS_USER_MODE_SUPPORTED
            Status = (Qspi_StatusType)OsIf_Trusted_Call_Return4param(Qspi_Lld_Read, FlashInstance, ReadAddr, JobDataDestPtr, Length);
#else
            Status = Qspi_Lld_Read(FlashInstance, ReadAddr, JobDataDestPtr, Length);
#endif
        }
#if ( FLS_COMPARE_API == STD_ON )
        else if (NULL_PTR != JobDataSrcPtr)
        {
#ifdef FLS_USER_MODE_SUPPORTED
            Status = (Qspi_StatusType)OsIf_Trusted_Call_Return4param(Qspi_Lld_ProgramVerify, FlashInstance, ReadAddr, JobDataSrcPtr, Length);
#else
            Status = Qspi_Lld_ProgramVerify(FlashInstance, ReadAddr, JobDataSrcPtr, Length);
#endif
        }
#endif /*#if ( FLS_COMPARE_API == STD_ON ) */
#if ( FLS_BLANK_CHECK_API == STD_ON )
        else
        {
#ifdef FLS_USER_MODE_SUPPORTED
            Status = (Qspi_StatusType)OsIf_Trusted_Call_Return3param(Qspi_Lld_EraseVerify, FlashInstance, ReadAddr, Length);
#else
            Status = Qspi_Lld_EraseVerify(FlashInstance, ReadAddr, Length);
#endif
        }
#endif /*#if ( FLS_BLANK_CHECK_API == STD_ON ) */
        (void)JobDataSrcPtr;
        if (STATUS_QSPI_SUCCESS != Status)
        {
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            /*check timeout after checking Status fail*/
            if (STATUS_QSPI_TIMEOUT == Status)
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
            }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
#if ( FLS_COMPARE_API == STD_ON )
            if (STATUS_QSPI_ERROR_PROGRAM_VERIFY == Status)
            {
                LldRetVal = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                LldRetVal = FLASH_E_FAILED;
            }
#else
            LldRetVal = FLASH_E_FAILED;
#endif /*#if ( FLS_COMPARE_API == STD_ON ) */
        }
        else
        {
            LldRetVal = FLASH_E_OK;
        }
    } /* FLS_CH_QSPI == HwChannel */
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    return LldRetVal;
}

/*FUNCTION**********************************************************************
 * Function Name : Fls_Mid_SectorErase
 * Description   : Route the erase job to appropriate Lld function.
 * @implements     Fls_Mid_SectorErase_Activity
 ******************************************************************************/
FLS_FUNC Fls_Lld_ReturnType Fls_Mid_SectorErase(const Fls_AddressType SectorOffset,
        const Fls_LengthType PhysicalSectorSize,
        const boolean Asynch
                                               )
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    Fls_HwChType HwChannel;
    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    HwChannel = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwCh;
    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == HwChannel)
    {
        LldRetVal = Fls_Mld_SectorEraseEfmJobs(Asynch, SectorOffset);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == HwChannel)
    {
        LldRetVal = Fls_Lld_SectorEraseQspiJobs(Asynch, SectorOffset, PhysicalSectorSize);
    }
#else
    /*Fix warning: unused variable*/
    (void)PhysicalSectorSize;
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    return LldRetVal;
}

/*FUNCTION**********************************************************************
 * Function Name : Fls_Mld_SectorWrite
 * Description   : Route the write job to appropriate Lld function.
 * @implements     Fls_Mld_SectorWrite_Activity
 ******************************************************************************/
FLS_FUNC Fls_Lld_ReturnType Fls_Mld_SectorWrite(const Fls_AddressType SectorOffset,
        const Fls_AddressType Length,
        const uint8 *JobDataSrcPtr,
        const boolean Asynch
                                               )
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    Fls_HwChType HwChannel;
    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    HwChannel = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorHwCh;
    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == HwChannel)
    {
        LldRetVal = Fls_Mld_SectorWriteEfmJobs(SectorOffset, Length, JobDataSrcPtr, Asynch);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == HwChannel)
    {
        LldRetVal = Fls_Lld_SectorWriteQspiJobs(SectorOffset, Length, JobDataSrcPtr, Asynch);
    }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    return LldRetVal;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Fls_Mld.c */
