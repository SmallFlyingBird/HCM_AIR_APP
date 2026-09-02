/**
 * @file    Fls.c
 * @version
 *
 * @brief   AUTOSAR Fls module interface
 * @details API implementation for FLS driver
 *
 * @addtogroup FLS_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Fls
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
#ifdef __cplusplus
extern "C" {
#endif

/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 3408 Rule 8.4: A compatible declaration is one which declares a compatible type for the
 *                       object or function being defined.
 */


/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Fls.h"
#include "Fls_Lld.h"
#include "Fls_PBcfg.h"
#include "Det.h"
#include "SchM_Fls.h"
#include "OsIf.h"
#include "Fls_Mld.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_C                      (180)
#define FLS_AR_RELEASE_MAJOR_VERSION_C       (4)
#define FLS_AR_RELEASE_MINOR_VERSION_C       (4)
#define FLS_AR_RELEASE_REVISION_VERSION_C    (0)
#define FLS_SW_MAJOR_VERSION_C               (2)
#define FLS_SW_MINOR_VERSION_C               (3)
#define FLS_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FLS header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_VENDOR_ID)
#error "Fls.c and Fls.h have different vendor ids"
#endif

/* Check if source file and FLS header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_C != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_C != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls.c and Fls.h are different"
#endif

/* Check if source file and FLS header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fls.c and Fls.h are different"
#endif


/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define FLS_TOTAL_LENGTH  (Fls_ConfigPtr->SectorList[Fls_ConfigPtr->ConfiguredSectorNumber - 1U].SectorStartAddress + \
                           Fls_ConfigPtr->SectorList[Fls_ConfigPtr->ConfiguredSectorNumber - 1U].SectorSize)
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_32
#include "Fls_MemMap.h"
#if(STD_ON == FLS_FIXED_PB_CONFIG)
extern const Fls_ConfigType Fls_PreCompileConfig;
#endif /* FLS_FIXED_PB_CONFIG */
/**
 * @brief          Fls global configuration pointer
 */
/* PRQA S 3408 Rule 8.4: Fls_ConfigPtr is declared and used in another .c file, so it couldn't
 *                       adhere to M3CM Rule-8.4
 */
FLS_VAR const Fls_ConfigType *Fls_ConfigPtr = NULL_PTR; /*PRQA S 3408*/
/**
 * @brief          Fls global job result status variable
 */
/* PRQA S 3408 Rule 8.4: Fls_JobState is declared and used in another .c file, so it couldn't
 *                       adhere to M3CM Rule-8.4
 */
FLS_VAR Fls_JobStateType Fls_JobState =  /*PRQA S 3408*/
{
    .JobResult = MEMIF_JOB_OK,
    .JobCurrentAddr = 0U,
    .JobEndAddr = 0U,
    .JobType = FLS_JOB_IDLE,
    .JobWriteDataPtr = NULL_PTR,
    .JobReadDataPtr = NULL_PTR,
    .JobStart = 0U,
    .JobSectorIt = 0U,
    .JobSectorEnd = 0U
};
#define FLS_STOP_SEC_VAR_INIT_32
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_8
#include "Fls_MemMap.h"
/**
    @brief Result of last flash hardware job
 */
/* PRQA S 3408 Rule 8.4: Fls_LLDJobResult is declared and used in another .c file, so it couldn't
 *                       adhere to M3CM Rule-8.13
 */
FLS_VAR volatile MemIf_JobResultType Fls_LLDJobResult;          /* implicit zero initialization: MEMIF_JOB_OK *//*PRQA S 3408*/
/**
    @brief Type of current flash hardware job - used for asynchronous operating mode.
 */
/* PRQA S 3408 Rule 8.4: Fls_LLDJob is declared and used in another .c file, so it couldn't
 *                       adhere to M3CM Rule-8.13
 */
FLS_VAR Fls_Lld_JobType Fls_LLDJob;    /* implicit zero initialization: FLASH_JOB_NONE *//*PRQA S 3408*/
#define FLS_STOP_SEC_VAR_CLEARED_8
#include "Fls_MemMap.h"

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/**
 * @brief Maximum number of bytes to read or compare in one cycle of Fls_MainFunction
 */
FLS_VAR static Fls_LengthType Fls_U32MaxRead;
/**
 * @brief Maximum number of bytes to write in one cycle of Fls_MainFunction
 */
FLS_VAR static Fls_LengthType Fls_U32MaxWrite;
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/*==================================================================================================
 *                                   LOCAL PROTOTYPES
==================================================================================================*/
static boolean Fls_IsSectorStartAddrAligned(Fls_AddressType TargetAddress);
static boolean Fls_IsSectorEndAddrAligned(Fls_AddressType TargetAddress);
static boolean Fls_IsSectorAddrPageAligned(Fls_AddressType TargetAddress);
static boolean Fls_IsAddrInRange(Fls_AddressType TargetAddress);
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
static boolean Fls_IsAddrWordAligned(const Fls_AddressType TargetAddress);
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
static uint16 Fls_GetSectorIndexByAddr(Fls_AddressType LogicAddress);
static void Fls_MainFunctionCheckJobResult(MemIf_JobResultType WorkResult);
static MemIf_JobResultType Fls_ExecuteJobErase(void);
static Fls_Lld_ReturnType Fls_ExecuteJobWrite(const Fls_AddressType SectorOffset, const Fls_AddressType Length);
static MemIf_JobResultType Fls_ProcessRequestedJobs(void);
static MemIf_JobResultType Fls_GetLldJobResult(void);
static void Fls_ClrLldJobResult(void);
static MemIf_JobResultType Fls_DoJobDataTransfer(const Fls_LengthType MaxTransfer);
static Fls_AddressType Fls_CalcMaxTransferAddrEnd(const Fls_LengthType MaxTransfer);
static Fls_AddressType Fls_CalcSectorTransferLength(const Fls_AddressType MaxTransferEndAddr);
static Fls_Lld_ReturnType Fls_ProcessJobDataTransfer(const Fls_AddressType SectorOffset, const Fls_AddressType Length);
static Fls_AddressType Fls_CalcSectorTransferOffset(void);
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief   Sector start address aligned check
 * @details Check the target address is sector start address or not.
 * @param[in] TargetAddress - The target address
 * @return   boolean - TRUE: TargetAddress is sector start address
*/
FLS_FUNC static boolean Fls_IsSectorStartAddrAligned(Fls_AddressType TargetAddress)
{
    boolean RetVal = (boolean)FALSE;
    uint16 SectorIndex = 0xFFFFU;
    Fls_AddressType SectorStartAddr = 0U;
    Fls_LengthType HwSectorSize = 0xFFFFFFFFU;
    /*The TargetAddress need to be less than the total size of flash*/
    if (TargetAddress < FLS_TOTAL_LENGTH)
    {
        SectorIndex = Fls_GetSectorIndexByAddr(TargetAddress);
        SectorStartAddr = Fls_ConfigPtr->SectorList[SectorIndex].SectorStartAddress;
        HwSectorSize = Fls_ConfigPtr->SectorList[SectorIndex].PhySectorSize;
        /*The TargetAddress need to be aligned with the sector size*/
        if ((TargetAddress - SectorStartAddr) % HwSectorSize == 0U)
        {
            RetVal = (boolean)TRUE;
        }
    }
    return RetVal;
}
/**
 * @brief   Sector end address aligned check
 * @details Check the target address is sector end address or not.
 * @param[in] TargetAddress - The target address
 * @return   boolean - TRUE: TargetAddress is sector end address
*/
FLS_FUNC static boolean Fls_IsSectorEndAddrAligned(Fls_AddressType TargetAddress)
{
    boolean RetVal = (boolean)FALSE;
    uint16 SectorIndex = 0xFFFFU;
    Fls_LengthType HwSectorSize = 0xFFFFFFFFU;
    Fls_AddressType SectorStartAddr = 0U;
    /*The TargetAddress need to be less than the total size of flash*/
    if (TargetAddress <= FLS_TOTAL_LENGTH)
    {
        SectorIndex = Fls_GetSectorIndexByAddr(TargetAddress - 1U);
        HwSectorSize = Fls_ConfigPtr->SectorList[SectorIndex].PhySectorSize;
        SectorStartAddr = Fls_ConfigPtr->SectorList[SectorIndex].SectorStartAddress;
        /*The TargetAddress need to be aligned with the sector size*/
        if (0U == ((TargetAddress - SectorStartAddr) % HwSectorSize))
        {
            RetVal = (boolean)TRUE;
        }
    }
    return RetVal;
}
/**
 * @brief   Page address aligned check
 * @details Check the target address is the sector or not.
 * @param[in] TargetAddress - The target address.
 * @return   boolean - TRUE: TargetAddress is in a sector.
*/
FLS_FUNC static boolean Fls_IsSectorAddrPageAligned(Fls_AddressType TargetAddress)
{
    boolean RetVal = (boolean)FALSE;
    uint16 SectorIndex;
    SectorIndex = Fls_GetSectorIndexByAddr(TargetAddress);
    if (SectorIndex < Fls_ConfigPtr->ConfiguredSectorNumber)
    {
        if (0U == (TargetAddress & (Fls_ConfigPtr->SectorList[SectorIndex].PageSize - 1U)))
        {
            RetVal = (boolean)TRUE;
        }
    }
    else if (SectorIndex == Fls_ConfigPtr->ConfiguredSectorNumber)
    {
        if (TargetAddress == (Fls_ConfigPtr->SectorList[SectorIndex - 1U].SectorStartAddress + \
                              Fls_ConfigPtr->SectorList[SectorIndex - 1U].SectorSize))
        {
            RetVal = (boolean)TRUE;
        }
    }
    else
    {
        /*Nothing to do*/
    }
    return RetVal;
}

/**
 * @brief   Address range check
 * @details Check the target address is in the flash range or not.
 * @param[in] TargetAddress - The target address.
 * @return   boolean - TRUE: TargetAddress is in the flash range.
*/
FLS_FUNC static boolean Fls_IsAddrInRange(Fls_AddressType TargetAddress)
{
    boolean RetVal = (boolean)FALSE;
    if (TargetAddress <= FLS_TOTAL_LENGTH)
    {
        RetVal = (boolean)TRUE;
    }
    return RetVal;
}
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
/**
 * @brief        Check whether TargetAddress is word aligned
 *
 * @details      If QSPI is available and QSPI sectors are configured and
 *               if the WordAddresable option is set, check if the address
 *               is word aligned. For hyperflash memories only even addresses
 *               are allowed.
 *
 * @param[in]    TargetAddress Target address in flash memory
 *
 * @return       boolean
 *                 TRUE TargetAddress is word aligned
 *                 FALSE TargetAddress is not word aligned
 *
 * @pre          The module must be initialized
 *
 */
FLS_FUNC static boolean Fls_IsAddrWordAligned(const Fls_AddressType TargetAddress)
{
    boolean RetVal = (boolean)TRUE;
    uint16 TmpJobSectorIt = 0UL;
    const Qspi_ControllerConfigType *CtrlCfg;
    uint32 FlashInstance;
    uint32 ControllerNo;
    uint32 CtrlCfgNo;
    Fls_AddressType LastAddress;
    LastAddress = FLS_TOTAL_LENGTH;
    /* Check in case when a bad address is passed */
    if (LastAddress == TargetAddress)
    {
        TmpJobSectorIt = Fls_ConfigPtr->ConfiguredSectorNumber - 1U;
    }
    else
    {
        TmpJobSectorIt = Fls_GetSectorIndexByAddr(TargetAddress);
    }
    /* Get external flash instance */
    FlashInstance = Fls_ConfigPtr->SectorList[TmpJobSectorIt].SectFlashUnit;
    /* Only apply for external sectors */
    if (FLS_DEVICE_INSTANCE_INVALID != FlashInstance)
    {
        /* Get controller configuration */
        ControllerNo = Fls_ConfigPtr->ExtFlsCfgConfig->FlashMemCfg[FlashInstance].FlashConnectionCfg->QspiInstance;
        CtrlCfgNo = Fls_ConfigPtr->ExtFlsCfgConfig->QspiConfig[ControllerNo];
        CtrlCfg = &(Fls_ConfigPtr->ExtFlsCfgConfig->QspiUnitCfg[CtrlCfgNo]);
        if (((boolean)TRUE == CtrlCfg->WordAddresable) && (0U != (TargetAddress % 2U)))
        {
            /* The WordAddresable option is set but the address is not word aligned. */
            RetVal = (boolean)FALSE;
        }
    }
    return RetVal;
}
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

/**
 * @brief   Get sector index by address
 * @details Get the sector index by the target address.
 * @param[in] LogicAddress - The target address.
 * @return   uint16 - The sector index.
*/
FLS_FUNC static uint16 Fls_GetSectorIndexByAddr(Fls_AddressType LogicAddress)
{
    uint16 SectorIndex = FLS_INVALID_SECTOR_INDEX;
    for (SectorIndex = 0U; SectorIndex < Fls_ConfigPtr->ConfiguredSectorNumber; ++SectorIndex)
    {
        if ((LogicAddress >= Fls_ConfigPtr->SectorList[SectorIndex].SectorStartAddress)
                && (LogicAddress < (Fls_ConfigPtr->SectorList[SectorIndex].SectorStartAddress +
                                    Fls_ConfigPtr->SectorList[SectorIndex].SectorSize)))
        {
            break;
        }
    }
    return SectorIndex;
}

/**
 * @brief   Check job result in main function
 * @details This function is used to check the job result and call notification. It's called in main function.
 * @param[in] WorkResult - The job result.
 * @return   void
*/
FLS_FUNC static void Fls_MainFunctionCheckJobResult(MemIf_JobResultType WorkResult)
{
    Fls_JobState.JobResult = WorkResult;
    if (MEMIF_JOB_OK == WorkResult)
    {
        if (NULL_PTR != Fls_ConfigPtr->JobEndNotificationFunPtr)
        {
            /* Call FlsJobEndNotification function if configured */
            Fls_ConfigPtr->JobEndNotificationFunPtr();
        }
    }
    else if ((MEMIF_JOB_FAILED == WorkResult) ||
             (MEMIF_JOB_CANCELED == WorkResult) ||
             (MEMIF_BLOCK_INCONSISTENT == WorkResult)
            )
    {
        if (NULL_PTR != Fls_ConfigPtr->JobErrorNotificationFunPtr)
        {
            /* Call FlsJobErrorNotification function if configured */
            Fls_ConfigPtr->JobErrorNotificationFunPtr();
        }
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 * @brief       Calculate sector offset to read, write, or compare
 *              from current sector
 *
 * @details      Calculate sector offset in bytes for low-level driver
 *               services
 *
 * @return       Fls_AddressType
 * @retval      0 .. (FLS_SECTOR_SIZE - 1)
 *
 * @pre         The module must be initialized, Fls_u32JobSectorIt internal job
 *              variable must contain index of current logical sector,
 *              Fls_u32JobAddrIt must contain current logical address
 *
 */
FLS_FUNC static Fls_AddressType Fls_CalcSectorTransferOffset(void)
{
    Fls_AddressType SectorAddrStart;
    /* Get first address of Fls_u32JobSectorIt sector */
    if (0U != Fls_JobState.JobSectorIt)
    {
        SectorAddrStart = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorStartAddress;
    }
    else
    {
        /* First sector starts with address 0 */
        SectorAddrStart = 0U;
    }
    /* Calculate the sector offset */
    return (Fls_JobState.JobCurrentAddr - SectorAddrStart);
}

/**
 * @brief            FLS Execute Erase job
 * @details          This function will execute erase job
 * @return           MemIf_JobResultType
 */
FLS_FUNC static MemIf_JobResultType Fls_ExecuteJobErase(void)
{
    uint16 TempSectorIt;
    MemIf_JobResultType TempJobResult = MEMIF_JOB_PENDING;
    boolean Asynch;
    Fls_Lld_ReturnType LldRetVal;
    Fls_LengthType PhysicalSectorSize;
    Fls_AddressType SectorTransferOffset;
    if (Fls_JobState.JobCurrentAddr > Fls_JobState.JobEndAddr)
    {
        /* No more sectors to erase */
        TempJobResult = MEMIF_JOB_OK;
    }
    else
    {
        TempSectorIt = Fls_JobState.JobSectorIt;
        /* Get the Fls_Lld_SectorErase function operation mode */
        if (0U != Fls_ConfigPtr->SectorList[TempSectorIt].AsyncAccess)
        {
            /* The sector write is performed in an asynchronous manner, it is ASYNC mode. */
            Asynch = (boolean)TRUE;
        }
        else
        {
            /* The sector write is SYNC */
            Asynch = (boolean)FALSE;
        }
        PhysicalSectorSize = Fls_ConfigPtr->SectorList[TempSectorIt].PhySectorSize;
        /* Calculate offset of the sector inside sector group */
        SectorTransferOffset = Fls_CalcSectorTransferOffset();
        LldRetVal = Fls_Mid_SectorErase(SectorTransferOffset, PhysicalSectorSize, Asynch);
        Fls_JobState.JobCurrentAddr += PhysicalSectorSize;
        if ((Fls_JobState.JobCurrentAddr > Fls_JobState.JobEndAddr) && (FLASH_E_OK == LldRetVal))
        {
            TempJobResult = MEMIF_JOB_OK;
        }
        else if (FLASH_E_FAILED == LldRetVal)
        {
            (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_ERASE_FAILED);
            TempJobResult = MEMIF_JOB_FAILED;
        }
        else
        {
            /* The erase operation is either:
                1. For ASYNCHRONOUS operation: pending (FLASH_E_PENDING) in hardware, or
                2. For SYNCHRONOUS operation: finished (FLASH_E_OK) and there are more sectors to erase.

                1. If the operation is Async, than the sector is increased in
                   Fls_Lld_LLDMainFunction()(for Async erase).
                   when completing the job.
                2. If the operation is Sync erase, than the sector is increased below because the job is complete.
            */
            if ((0U == Fls_ConfigPtr->SectorList[TempSectorIt].AsyncAccess) && \
                    (Fls_JobState.JobCurrentAddr >= (Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorStartAddress + \
                            Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorSize)) && \
                    (Fls_JobState.JobCurrentAddr <= Fls_JobState.JobEndAddr))
            {
                Fls_JobState.JobSectorIt += 1U;
            }
        }
    }
    return TempJobResult;
}
/**
 * @brief             FLS Execute Write job
 * @details           This function will execute write job
 * @param[in]         SectorOffset the offset of the sector
 * @param[in]         Length the length of the data to be written
 * @return            Fls_Lld_ReturnType
 */
FLS_FUNC static Fls_Lld_ReturnType Fls_ExecuteJobWrite(const Fls_AddressType SectorOffset,
        const Fls_AddressType Length)
{
    uint16 SectorIndex;
    Fls_Lld_ReturnType TempJobResult;
    SectorIndex = Fls_JobState.JobSectorIt;
    /* Page program */
    TempJobResult = Fls_Mld_SectorWrite(SectorOffset, Length, Fls_JobState.JobWriteDataPtr, \
                                        Fls_ConfigPtr->SectorList[SectorIndex].AsyncAccess);
    if (FLASH_E_FAILED == TempJobResult)
    {
        /* An error will be reported */
        (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_WRITE_FAILED);
    }
#if ( (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) || (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) )
    /* A verification has been failed, convert to FLASH_E_FAILED */
    else if (FLASH_E_BLOCK_INCONSISTENT == TempJobResult)
    {
        TempJobResult = FLASH_E_FAILED;
        (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
    }
    else
    {
        /* empty else at the end of an else-if structure */
    }
#endif /* (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) || (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) */
    return TempJobResult;
}

/**
* @brief            FLS job processing
* @details          This function will process the requested jobs
* @return           void
*/
FLS_FUNC static MemIf_JobResultType Fls_ProcessRequestedJobs(void)
{
    MemIf_JobResultType WorkResult;
    /* Flash is initialized and a job is pending */
    switch (Fls_JobState.JobType)
    {
        /**** MODIFY jobs ****/
        /* Start current job or start a new batch of current job or verify status of current job. */
        case FLS_JOB_ERASE:
            WorkResult = Fls_ExecuteJobErase();
            break;
        case FLS_JOB_WRITE:
            WorkResult = Fls_DoJobDataTransfer(Fls_U32MaxWrite);
            break;
        /**** READ jobs ****/
        /* FLS_JOB_READ, FLS_JOB_BLANK_CHECK and FLS_JOB_COMPARE jobs are always synchronous */
        case FLS_JOB_READ:
        case FLS_JOB_COMPARE:
        case FLS_JOB_BLANK_CHECK:
            WorkResult = Fls_DoJobDataTransfer(Fls_U32MaxRead);
            break;
        default:
            WorkResult = MEMIF_JOB_PENDING;
            break;
    }
    return WorkResult;
}


/**
 *  @brief   Read, write, or compare flash data
 *  @details Call Fls_ProcessJobDataTransfer function to read, write,
 *       or compare flash data. The functions ensures that only pre-configured
 *       maximum number of bytes is read, written, or compared during
 *       one cycle of the Fls_MainFunction call
 * @param[in] MaxTransfer Maximum number of bytes to transfer
 *  @return MemIf_JobResultType
 */
FLS_FUNC static MemIf_JobResultType Fls_DoJobDataTransfer(const Fls_LengthType MaxTransfer)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_PENDING;
    uint16 SectorItTemp;
    Fls_AddressType SectorAddrEndTemp = 0U;
    /* No more data to write */
    if (Fls_JobState.JobCurrentAddr > Fls_JobState.JobEndAddr)
    {
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
        Fls_AddressType MaxTransferAddrEnd;
        Fls_Lld_ReturnType TransferRetVal;
        /* Last address to transfer data to/from in this call of the Fls_MainFunction() functions */
        MaxTransferAddrEnd = Fls_CalcMaxTransferAddrEnd(MaxTransfer);
        /* Transfer sector by sector until the MaxTransferAddrEnd address is reached or error is detected */
        do
        {
            Fls_AddressType SectorTransferOffset;
            Fls_AddressType SectorTransferLength;
            SectorItTemp = Fls_JobState.JobSectorIt;
            /* Calculate offset and length of the sector data transfer */
            SectorTransferOffset = Fls_JobState.JobCurrentAddr - Fls_ConfigPtr->SectorList[SectorItTemp].SectorStartAddress;
            SectorTransferLength = Fls_CalcSectorTransferLength(MaxTransferAddrEnd);
            /* Update the Fls_JobAddressIt iterator.*/
            Fls_JobState.JobCurrentAddr += SectorTransferLength;
            /* Call Low-level driver to transfer data to/from physical flash device */
            TransferRetVal = Fls_ProcessJobDataTransfer(SectorTransferOffset, SectorTransferLength);
            if (FLASH_E_OK == TransferRetVal)   /* If the previous(SYNC job) has finished successfully */
            {
                SectorAddrEndTemp = Fls_ConfigPtr->SectorList[SectorItTemp].SectorStartAddress + \
                                    Fls_ConfigPtr->SectorList[SectorItTemp].SectorSize;
                if (Fls_JobState.JobCurrentAddr >= SectorAddrEndTemp)
                {
                    /* Move on to the next sector */
                    Fls_JobState.JobSectorIt += 1U;
                }
            }
        } while ((Fls_JobState.JobCurrentAddr <= MaxTransferAddrEnd) &&
                 (FLASH_E_OK == TransferRetVal)
                );
        if (FLASH_E_FAILED == TransferRetVal)
        {
            RetVal = MEMIF_JOB_FAILED;
        }
        else if (FLASH_E_BLOCK_INCONSISTENT == TransferRetVal)
        {
            /* compare job only */
            RetVal = MEMIF_BLOCK_INCONSISTENT;
        }
        else if ((Fls_JobState.JobCurrentAddr > Fls_JobState.JobEndAddr) &&
                 (FLASH_E_OK == TransferRetVal)
                )
        {
            /* All desired job data has been successfully transferred */
            RetVal = MEMIF_JOB_OK;
        }
        else
        {
            /* The write operation is either pending (FLASH_E_PENDING)
            in hardware in case of asynchronous operation or
            finished (FLASH_E_OK) in case of synchronous operation
            and there is more pages to write */
        }
    }
    return RetVal;
}
/**
 * @brief       Calculate last logical address to operate from in current cycle of Fls_MainFunction
 * @details      Calculate last logical address of Fls_DoJobDataTransfer
 *               loop to limit number of bytes transferred to/from flash memory
 *               in one cycle of Fls_MainFunction
 * @param[in]    MaxTransfer Maximum number of bytes to read, write, or compare
 *               in current cycle of Fls_MainFunction
 * @return       Fls_AddressType
 */
FLS_FUNC static Fls_AddressType Fls_CalcMaxTransferAddrEnd(const Fls_LengthType MaxTransfer)
{
    Fls_AddressType MaxTransferEndAddr = Fls_JobState.JobEndAddr;
    /* Adjust the MaxTransferEndAddr address to transfer only
        the MaxTransfer bytes in one Fls_MainFunction() call */
    if (MaxTransferEndAddr >= (Fls_JobState.JobCurrentAddr + MaxTransfer))
    {
        MaxTransferEndAddr = (Fls_JobState.JobCurrentAddr + MaxTransfer) - 1U;
    }
    else
    {
        /* No adjustment is necessary. Job will finish in this cycle
            of Fls_MainFunction */
    }
    return MaxTransferEndAddr;
}

/**
 * @brief       Calculate number of bytes to operate from current sector
 * @details      Calculate sector transfer length for low-level driver
 *               services
 * @param[in]    MaxTransferEndAddr Last address to read, write,
 *               or compare data from in this cycle of Fls_MainFunction
 * @return      Fls_AddressType
 *
 */
FLS_FUNC static Fls_AddressType Fls_CalcSectorTransferLength(const Fls_AddressType MaxTransferEndAddr)
{
    Fls_AddressType SectorEndAddr;
    Fls_AddressType MaxTransferAddr = MaxTransferEndAddr;
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    uint32 TransferSize = 0U;
    uint32 InterfaceSize = 0U;
#endif
    /* Get last address of Fls_u32JobSectorIt sector */
    SectorEndAddr = (Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorStartAddress + \
                     Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorSize) - 1U;
    /* Adjust SectorEndAddr based on hardware implementation */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_JOB_WRITE == Fls_JobState.JobType)
    {
        InterfaceSize = Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].PageSize;
        TransferSize = (MaxTransferAddr - Fls_JobState.JobCurrentAddr) + 1U;
        if (TransferSize > (InterfaceSize - (Fls_JobState.JobCurrentAddr % InterfaceSize)))
        {
            MaxTransferAddr = (Fls_JobState.JobCurrentAddr + (InterfaceSize - \
                               (Fls_JobState.JobCurrentAddr % InterfaceSize))) - 1U;
        }
    }
#endif
    /* Adjust the SectorEndAddr according to max number of bytes to transfer
        during one cycle of Fls_MainFunction */
    if (SectorEndAddr > MaxTransferAddr)
    {
        SectorEndAddr = MaxTransferAddr;
    }
    else
    {
        /* No adjustment is necessary. There is more sectors to transfer */
    }
    /* Calculate number of bytes to read from the sector */
    return ((SectorEndAddr - Fls_JobState.JobCurrentAddr) + 1U);
}

/**
 * @brief        Calculate offset of current sector
 * @details      Calculate sector transfer offset for low-level driver
 *               services
 * @param[in]    SectorOffset Start address of current sector
 * @param[in]    Length The length of data to be transferred
 * @return      Fls_AddressType
 *
 */
FLS_FUNC static Fls_Lld_ReturnType Fls_ProcessJobDataTransfer(const Fls_AddressType SectorOffset, const Fls_AddressType Length)
{
    Fls_Lld_ReturnType TransferRetVal = FLASH_E_FAILED;
    /* Call Low-level driver to transfer data to/from physical flash device */
    switch (Fls_JobState.JobType)
    {
        case FLS_JOB_WRITE:
            TransferRetVal =  Fls_ExecuteJobWrite(SectorOffset, Length);
            /* Update the source data pointer for next write */
            Fls_JobState.JobWriteDataPtr = &(Fls_JobState.JobWriteDataPtr[Length]);
            break;
        case FLS_JOB_READ:
            TransferRetVal =  Fls_Mld_SectorRead(SectorOffset, Length, Fls_JobState.JobReadDataPtr, NULL_PTR);
            if (FLASH_E_FAILED == TransferRetVal)
            {
                (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_READ_FAILED);
            }
            /* Update the destination data pointer for next read */
            Fls_JobState.JobReadDataPtr = &(Fls_JobState.JobReadDataPtr[Length]);
            break;
#if ( FLS_COMPARE_API == STD_ON )
        case FLS_JOB_COMPARE:
            TransferRetVal =  Fls_Mld_SectorRead(SectorOffset, Length, NULL_PTR, Fls_JobState.JobWriteDataPtr);
            if ((FLASH_E_BLOCK_INCONSISTENT == TransferRetVal) || (FLASH_E_FAILED == TransferRetVal))
            {
                (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_COMPARE_FAILED);
            }
            /* Update the source data pointer for next compare */
            Fls_JobState.JobWriteDataPtr = &(Fls_JobState.JobWriteDataPtr[Length]);
            break;
#endif /* FLS_COMPARE_API == STD_ON */
#if ( FLS_BLANK_CHECK_API == STD_ON )
        case FLS_JOB_BLANK_CHECK:
            TransferRetVal =  Fls_Mld_SectorRead(SectorOffset, Length, NULL_PTR, NULL_PTR);
            if ((FLASH_E_BLOCK_INCONSISTENT == TransferRetVal) || (FLASH_E_FAILED == TransferRetVal))
            {
                (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_COMPARE_FAILED);
            }
            break;
#endif /* FLS_BLANK_CHECK_API == STD_ON */
        default:
            ; /* Do nothing - should not happen in Fully Trusted Environment;
            "default" clause added to fulfil MISRA Rule 15.3 */
            break;
    }
    return TransferRetVal;
}

/**
 * @brief          Returns the LLD JobResult
 * @details        This function returns the LLD JobResult
 * @return         MemIf_JobResultType
 */
FLS_FUNC static MemIf_JobResultType Fls_GetLldJobResult(void)
{
    return Fls_LLDJobResult;
}

/**
 * @brief          Clear the status of job result.
 * @details        This function clears the status of job result.
 * @return         void
 */
FLS_FUNC static void Fls_ClrLldJobResult(void)
{
    Fls_LLDJobResult = MEMIF_JOB_OK;
    Fls_LLDJob = FLASH_JOB_NONE;
}
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*************************************************************************************************
 *                      Fls_Init                                                                 *
 *************************************************************************************************/
FLS_FUNC void Fls_Init(const Fls_ConfigType *ConfigPtr)
{
#if (FLS_FIXED_PB_CONFIG == STD_ON)
    /* Static PB config enabled, ConfigPtr should be NULL */
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Static PB config disabled, ConfigPtr should have a value */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_PARAM_CONFIG);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00268] If development error detection for the module Fls is enabled:
            the function Fls_Init shall check that the FLS module is currently not busy
            (FLS module state is not MEMIF_BUSY). If this check fails, the function
            Fls_Init shall raise the development error FLS_E_BUSY. */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_BUSY);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
#if (FLS_FIXED_PB_CONFIG == STD_ON)
        /* save pre-build configuration */
        Fls_ConfigPtr = &Fls_PreCompileConfig;
#else
        /* [SWS_Fls_00191] The function Fls_Init shall store the pointer to the given configuration
                set in a variable in order to allow the FLS module access to the configuration set
                contents during runtime. */
        Fls_ConfigPtr = ConfigPtr;
#endif
        /* Set the max number of bytes to read/write
                during Fls_MainFunction call */
        if (MEMIF_MODE_SLOW == Fls_ConfigPtr->DefaultMode)
        {
            Fls_U32MaxRead = Fls_ConfigPtr->MaxReadNormalMode;
            Fls_U32MaxWrite = Fls_ConfigPtr->MaxWriteNormalMode;
        }
        else
        {
            Fls_U32MaxRead = Fls_ConfigPtr->MaxReadFastMode;
            Fls_U32MaxWrite = Fls_ConfigPtr->MaxWriteFastMode;
        }
        /* [SWS_Fls_00014] The function Fls_Init shall initialize the FLS module
            (software) and all flash memory relevant registers (hardware) with parameters
            provided in the given configuration set. */
        Fls_Mld_Init();
        if (MEMIF_JOB_OK != Fls_GetLldJobResult())
        {
            /* Fls module not initialized */
            Fls_ConfigPtr = NULL_PTR;
            Fls_ClrLldJobResult();
        }
        else
        {
            Fls_JobState.JobResult = MEMIF_JOB_OK;
        }
    }
}

/*************************************************************************************************
 *                      Fls_Erase                                                                *
 *************************************************************************************************/
FLS_FUNC Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00065] If development error detection for the module Fls is enabled:
            the function Fls_Erase shall check that the FLS module has been initialized.
            If this check fails, the function Fls_Erase shall reject the erase request,
            raise the development error FLS_E_UNINIT and return with E_NOT_OK. */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_UNINIT);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (FALSE == Fls_IsSectorStartAddrAligned(TargetAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /*[SWS_Fls_00020] If development error detection for the module Fls is enabled: the
        function Fls_Erase shall check that the erase start address (FlsBaseAddress +
        TargetAddress) is aligned to a flash sector boundary and that it lies within the
        specified lower and upper flash address boundaries. If this check fails, the function
        Fls_Erase shall reject the erase request, raise the development error
        FLS_E_PARAM_ADDRESS and return with E_NOT_OK. (SRS_BSW_00323, SRS_Fls_12136, SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((0U == Length) || (FALSE == Fls_IsSectorEndAddrAligned(TargetAddress + Length)))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00021] If development error detection for the module Fls is enabled: the
        function Fls_Erase shall check that the erase length is greater than 0 and that the erase
        end address (erase start address + length) is aligned to a flash sector boundary and that
        it lies within the specified upper flash address boundary. If this check fails, the function
        Fls_Erase shall reject the erase request, raise the development error FLS_E_PARAM_LENGTH and
        return with E_NOT_OK.  (SRS_BSW_00323, SRS_Fls_12136, SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
#if (FLS_SCHM_SUPPORT==STD_ON)
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_02();
#endif
        if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
        {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            /* [SWS_Fls_00023] If development error detection for the module Fls is enabled:
                the function Fls_Erase shall check that the FLS module is currently not busy.
                If this check fails, the function Fls_Erase shall reject the erase request,
                raise the development error FLS_E_BUSY and return with E_NOT_OK. */
            (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_BUSY);
#endif
            RetVal = E_NOT_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_02();
#endif
        }
        else
        {
            /* [SWS_Fls_00331] The function Fls_Erase shall copy the given parameters to Fls
                module internal variables and initiate a erase job. (SRS_Fls_12135) */
            Fls_JobState.JobCurrentAddr = TargetAddress;
            Fls_JobState.JobEndAddr = (TargetAddress + Length) - 1U;
            Fls_JobState.JobSectorIt = Fls_GetSectorIndexByAddr(TargetAddress);
            Fls_JobState.JobSectorEnd = Fls_GetSectorIndexByAddr(Fls_JobState.JobEndAddr);
            Fls_JobState.JobType = FLS_JOB_ERASE;
            /* [SWS_Fls_00333] After initiating the erase job, the function Fls_Erase shall set
                the job result to MEMIF_JOB_PENDING.  (SRS_Fls_12135) */
            Fls_JobState.JobResult = MEMIF_JOB_PENDING;
            /*write flag to start request*/
            Fls_JobState.JobStart = 1U;
            /* Write command accepted */
            RetVal = E_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_02();
#endif
        }
    }
    return RetVal;
}

/*************************************************************************************************
 *                      Fls_Write                                                                *
 *************************************************************************************************/
FLS_FUNC Std_ReturnType Fls_Write(Fls_AddressType TargetAddress, const uint8 *SourceAddressPtr, Fls_LengthType Length)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00066] If development error detection for the module Fls is enabled:
            the function Fls_Write shall check that the FLS module has been initialized.
            If this check fails, the function Fls_Write shall reject the write request,
            raise the development error FLS_E_UNINIT and return with E_NOT_OK. (SRS_BSW_00406) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_UNINIT);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (TRUE != Fls_IsSectorAddrPageAligned(TargetAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00026] If development error detection for the module Fls is enabled: the
            function Fls_Write shall check that the write start address (FlsBaseAddress +
            TargetAddress) is aligned to a flash page boundary and that it lies within the
            specified lower and upper flash address boundaries. If this check fails, the function
            Fls_Write shall reject the write request, raise the development error
            FLS_E_PARAM_ADDRESS and return with E_NOT_OK. (SRS_BSW_00323, SRS_Fls_12135, SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((TRUE != Fls_IsSectorAddrPageAligned(TargetAddress + Length)) || (0U == Length))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00027] If development error detection for the module Fls is enabled:
            the function Fls_Write shall check that the write length is greater than 0, that
            the write end address (write start address + length) is aligned to a flash page boundary
            and that it lies within the specified upper flash address boundary. If this check fails,
            the function Fls_Write shall reject the write request, raise the development error
            FLS_E_PARAM_LENGTH and return with E_NOT_OK.  (SRS_BSW_00323, SRS_Fls_12135, SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == SourceAddressPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00157] If development error detection for the module Fls is enabled:
            the function Fls_Write shall check the given data buffer pointer for not being
            a null pointer. If the data buffer pointer is a null pointer, the function
            Fls_Write shall reject the write request, raise the development error
            FLS_E_PARAM_DATA and return with E_NOT_OK.  (SRS_BSW_00323) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_DATA);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
#if (FLS_SCHM_SUPPORT==STD_ON)
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_03();
#endif
        if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
        {
            /* [SWS_Fls_00030] If development error detection for the module Fls is enabled:
                the function Fls_Write shall check that the FLS module is currently not busy.
                If this check fails, the function Fls_Write shall reject the write request,
                raise the development error FLS_E_BUSY and return with E_NOT_OK.  (SRS_Fls_12143) */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_BUSY);
#endif
            RetVal = E_NOT_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_03();
#endif
        }
        else
        {
            Fls_JobState.JobCurrentAddr = TargetAddress;
            Fls_JobState.JobEndAddr = (TargetAddress + Length) - 1U;
            Fls_JobState.JobSectorIt = Fls_GetSectorIndexByAddr(TargetAddress);
            Fls_JobState.JobSectorEnd = Fls_GetSectorIndexByAddr(Fls_JobState.JobEndAddr);
            Fls_JobState.JobType = FLS_JOB_WRITE;
            Fls_JobState.JobWriteDataPtr = SourceAddressPtr;
            Fls_JobState.JobResult = MEMIF_JOB_PENDING;
            Fls_JobState.JobStart = 1U;
            /* Write command accepted */
            RetVal = E_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_03();
#endif
        }
    }
    return RetVal;
}

#if (STD_ON == FLS_CANCEL_API)
/*************************************************************************************************
 *                      Fls_Cancel                                                                *
 *************************************************************************************************/
FLS_FUNC void Fls_Cancel(void)
{
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00356] If development error detection for the module Fls is enabled:
        the function Fls_Cancel shall check that the FLS module has been initialized.
        If this check fails, the function Fls_Cancel shall raise the development error
        FLS_E_UNINIT and return. (SWS_BSW_00406) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_CANCEL, FLS_E_UNINIT);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
        {
            Fls_Mld_Cancel();
            /* If underlying hardware job was successfully cancelled */
            if (MEMIF_JOB_CANCELED == Fls_GetLldJobResult())
            {
                /* Update global job result status */
                Fls_JobState.JobResult = MEMIF_JOB_CANCELED;
            }
            if (NULL_PTR != Fls_ConfigPtr->JobErrorNotificationFunPtr)
            {
                /* Call FlsJobErrorNotification function if configured */
                Fls_ConfigPtr->JobErrorNotificationFunPtr();
            }
            else
            {
                /* Callback notification configured as null pointer */
            }
        }
        else
        {
            /* no pending job */
        }
    }
}
#endif

#if (STD_ON == FLS_GET_STATUS_API)
/*************************************************************************************************
 *                      Fls_GetStatus                                                            *
 *************************************************************************************************/
FLS_FUNC MemIf_StatusType Fls_GetStatus(void)
{
    MemIf_StatusType RetVal = MEMIF_UNINIT;
    /* check if flash module is initialized */
    if (NULL_PTR == Fls_ConfigPtr)
    {
        RetVal = MEMIF_UNINIT;
    }
    else if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
    {
        RetVal = MEMIF_BUSY;
    }
    else
    {
        RetVal = MEMIF_IDLE;
    }
    return RetVal;
}
#endif

#if (STD_ON == FLS_GET_JOB_RESULT_API)
/*************************************************************************************************
 *                      Fls_GetJobResult                                                         *
 *************************************************************************************************/
FLS_FUNC MemIf_JobResultType Fls_GetJobResult(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00358] If development error detection for the module Fls is enabled:
            the function Fls_GetJobResult shall check that the FLS module has been initialized.
            If this check fails, the function Fls_GetJobResult shall raise the development error
            FLS_E_UNINIT and return with MEMIF_JOB_FAILED.  (SRS_BSW_00406) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_GET_JOB_RESULT, FLS_E_UNINIT);
        RetVal = MEMIF_JOB_FAILED;
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        RetVal = Fls_JobState.JobResult;
    }
    return RetVal;
}
#endif

/*************************************************************************************************
 *                      Fls_Read                                                                 *
 *************************************************************************************************/
FLS_FUNC Std_ReturnType Fls_Read(Fls_AddressType SourceAddress, uint8 *TargetAddressPtr, Fls_LengthType Length)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00099] If development error detection for the module Fls is enabled:
            the function Fls_Read shall check that the driver has been initialized. If this
            check fails, the function Fls_Read shall reject the read request, raise the
            development error FLS_E_UNINIT and return with E_NOT_OK.  (SRS_BSW_00406) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_UNINIT);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (TRUE != Fls_IsAddrInRange(SourceAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00097] If development error detection for the module Fls is enabled: the
            function Fls_Read shall check that the read start address (FlsBaseAddress +
            SourceAddress) lies within the specified lower and upper flash address
            boundaries. If this check fails, the function Fls_Read shall reject the read job, raise
            development error FLS_E_PARAM_ADDRESS and return with E_NOT_OK.
            (SRS_BSW_00323, SRS_Fls_12134, SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((0U == Length) || (TRUE != Fls_IsAddrInRange(SourceAddress + Length)))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00098] If development error detection for the module Fls is enabled:
            the function Fls_Read shall check that the read length is greater than 0 and
            that the read end address (read start address + length) lies within the specified
            upper flash address boundary. If this check fails, the function Fls_Read shall
            reject the read job, raise the development error FLS_E_PARAM_LENGTH and return
            with E_NOT_OK.  (SRS_BSW_00323, SRS_Fls_12134, SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == TargetAddressPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00158] If development error detection for the module Fls is enabled:
        the function Fls_Read shall check the given data buffer pointer for not being a null
        pointer. If the data buffer pointer is a null pointer, the function Fls_Read shall
        reject the read request, raise the development error FLS_E_PARAM_DATA and return with
        E_NOT_OK.  (SRS_Fls_00323) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_DATA);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
    else if ((boolean)FALSE == Fls_IsAddrWordAligned(SourceAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report Error if SourceAddress is not aligned */
        (void) Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((boolean)FALSE == Fls_IsAddrWordAligned(SourceAddress + Length))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report Error if SourceAddress + Length is not aligned */
        (void) Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif /*(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)*/
    else
    {
#if (FLS_SCHM_SUPPORT==STD_ON)
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_06();
#endif
        if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
        {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            /* [SWS_Fls_00100] If development error detection for the module Fls is enabled:
                the function Fls_Read shall check that the driver is currently not busy. If this
                check fails, the function Fls_Read shall reject the read request, raise the
                development error FLS_E_BUSY and return with E_NOT_OK.  (SRS_Fls_12143) */
            (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_BUSY);
#endif
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_06();
#endif
        }
        else
        {
            /* [SWS_Fls_00337] The function Fls_Read shall copy the given parameters to FLS
                module internal variables and initiate a read job.  (SRS_Fls_12134) */
            Fls_JobState.JobCurrentAddr = SourceAddress;
            Fls_JobState.JobEndAddr = (SourceAddress + Length) - 1U;
            Fls_JobState.JobSectorIt = Fls_GetSectorIndexByAddr(SourceAddress);
            Fls_JobState.JobSectorEnd = Fls_GetSectorIndexByAddr(Fls_JobState.JobEndAddr);
            Fls_JobState.JobType = FLS_JOB_READ;
            Fls_JobState.JobReadDataPtr = TargetAddressPtr;
            /* [SWS_Fls_00338] After initiating a read job, the function Fls_Read shall set the
                FLS module status to MEMIF_BUSY.  (SRS_Fls_12134) */
            /* [SWS_Fls_00339] After initiating a read job, the function Fls_Read shall set the
                FLS module job result to MEMIF_JOB_PENDING.  (SRS_Fls_12134)*/
            Fls_JobState.JobResult = MEMIF_JOB_PENDING;
            Fls_JobState.JobStart = 1U;
            /* Write command accepted */
            RetVal = E_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_06();
#endif
        }
    }
    return RetVal;
}

/*************************************************************************************************
 *                      Fls_MainFunction                                                         *
 *************************************************************************************************/
FLS_FUNC void Fls_MainFunction(void)
{
    if ((NULL_PTR != Fls_ConfigPtr) /* FLS is initialized */
            && (MEMIF_JOB_PENDING == Fls_JobState.JobResult) /* FLS job is pending */
       )
    {
        MemIf_JobResultType WorkResult = MEMIF_JOB_OK;
        if (1U == Fls_JobState.JobStart)
        {
            /* Clear result of hardware job */
            Fls_ClrLldJobResult();
            Fls_JobState.JobStart = 0U;
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
            Fls_Mld_AbortSuspended();
#endif /* FLS_QSPI_SECTORS_CONFIGURED == STD_ON */
        }
        /* Check the status of pending jobs. */
        if (FLASH_JOB_NONE != Fls_LLDJob)
        {
            Fls_Mld_MainFunction();
        }
        WorkResult = Fls_GetLldJobResult();
        if (MEMIF_JOB_OK == WorkResult)
        {
            /* Flash is initialized and a job is pending */
            WorkResult = Fls_ProcessRequestedJobs();
        }
        Fls_MainFunctionCheckJobResult(WorkResult);
    }
    else
    {
        /* no pending job */
        /* [SWS_Fls_00039] The function Fls_MainFunction shall return without any
            action if no job is pending.  (SRS_Fls_12144) */
    }
}

#if (STD_ON == FLS_COMPARE_API)
/*************************************************************************************************
 *                      Fls_Compare                                                              *
 *************************************************************************************************/
FLS_FUNC Std_ReturnType Fls_Compare(Fls_AddressType SourceAddress, const uint8 *TargetAddressPtr, Fls_LengthType Length)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00152] If development error detection for the module Fls is enabled:
            the function Fls_Compare shall check that the driver has been initialized.
            If this check fails, the function Fls_Compare shall reject the compare job,
            raise the development error FLS_E_UNINIT and return with E_NOT_OK.  (SRS_Fls_13301) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_UNINIT);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == TargetAddressPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00273] If development error detection for the module Fls is enabled:
            the function Fls_Compare shall check the given data buffer pointer for not being
            a null pointer. If the data buffer pointer is a null pointer, the function Fls_Compare
            shall reject the request, raise the development error FLS_E_PARAM_DATA and return
            with E_NOT_OK.  (RS_BRF_01064) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_DATA);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (TRUE != Fls_IsAddrInRange(SourceAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00150] If development error detection for the module Fls is enabled:
            the function Fls_Compare shall check that the compare start address
            (FlsBaseAddress + SourceAddress) lies within the specified lower and upper
            flash address boundaries. If this check fails, the function Fls_Compare shall
            reject the compare job, raise the development error FLS_E_PARAM_ADDRESS and
            return with E_NOT_OK.  (SRS_Fls_13301) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((0U == Length) || (TRUE != Fls_IsAddrInRange(SourceAddress + Length)))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00151] If If development error detection for the module Fls is enabled:
            the function Fls_Compare shall check that the given length is greater than 0 and
            that the compare end address (compare start address + length) lies within the
            specified upper flash address boundary. If this check fails, the function Fls_Compare
            shall reject the compare job, raise the development error FLS_E_PARAM_LENGTH and
            return with E_NOT_OK.  (SRS_Fls_13301) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
    else if ((boolean)FALSE == Fls_IsAddrWordAligned(SourceAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report Error if SourceAddress is not aligned */
        (void) Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((boolean)FALSE == Fls_IsAddrWordAligned(SourceAddress + Length))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report Error if SourceAddress + Length is not aligned */
        (void) Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif /*(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)*/
    else
    {
#if (FLS_SCHM_SUPPORT==STD_ON)
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_04();
#endif
        if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
        {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            /* [SWS_Fls_00153] If development error detection for the module Fls is enabled:
                the function Fls_Compare shall check that the driver is currently not busy.
                If this check fails, the function Fls_Compare shall reject the compare job,
                raise the development error FLS_E_BUSY and return with E_NOT_OK.  (SRS_Fls_13301) */
            (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_BUSY);
#endif
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_04();
#endif
        }
        else
        {
            /* [SWS_Fls_00341] The function Fls_Compare shall copy the given parameters to
                Fls module internal variables and initiate a compare job.  (SRS_Fls_13301) */
            Fls_JobState.JobCurrentAddr = SourceAddress;
            Fls_JobState.JobEndAddr = (SourceAddress + Length) - 1U;
            Fls_JobState.JobSectorIt = Fls_GetSectorIndexByAddr(SourceAddress);
            Fls_JobState.JobSectorEnd = Fls_GetSectorIndexByAddr(Fls_JobState.JobEndAddr);
            Fls_JobState.JobType = FLS_JOB_COMPARE;
            /* Compare will reuse write data pointer */
            Fls_JobState.JobWriteDataPtr = TargetAddressPtr;
            /* [SWS_Fls_00342] After initiating the compare job, the function Fls_Compare shall
                set the status to MEMIF_BUSY.  (SRS_Fls_13301) */
            /* [SWS_Fls_00343] After initiating the compare job, the function Fls_Compare shall
                set the job result to MEMIF_JOB_PENDING.  (SRS_Fls_13301) */
            Fls_JobState.JobResult = MEMIF_JOB_PENDING;
            /* [SWS_Fls_00344] After initiating the compare job, the function Fls_Compare shall
                return with E_OK.  (SRS_Fls_13301) */
            /* Write command accepted */
            RetVal = E_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_04();
#endif
        }
    }
    return RetVal;
}
#endif

#if (STD_ON == FLS_SET_MODE_API)
/*************************************************************************************************
 *                      Fls_SetMode                                                              *
 *************************************************************************************************/
FLS_FUNC void Fls_SetMode(MemIf_ModeType Mode)
{
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_SET_MODE, FLS_E_UNINIT);
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_SET_MODE, FLS_E_BUSY);
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Set the max number of bytes to read/write
            during Fls_MainFunction call */
        switch (Mode)
        {
            case MEMIF_MODE_FAST:
                Fls_U32MaxRead  = Fls_ConfigPtr->MaxReadFastMode;
                Fls_U32MaxWrite = Fls_ConfigPtr->MaxWriteFastMode;
                break;
            case MEMIF_MODE_SLOW:
                Fls_U32MaxRead  = Fls_ConfigPtr->MaxReadNormalMode;
                Fls_U32MaxWrite = Fls_ConfigPtr->MaxWriteNormalMode;
                break;
            default:
                ; /* Do nothing - should not happen in Fully Trusted Environment;
                   'default' clause added to fulfil MISRA Rule 15.3 */
                break;
        }
    }
}
#endif/* (STD_ON == FLS_SET_MODE_API) */

#if (STD_ON == FLS_BLANK_CHECK_API)
/*************************************************************************************************
 *                      Fls_BlankCheck                                                              *
 *************************************************************************************************/
FLS_FUNC Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType RetVal = E_NOT_OK;
    if (NULL_PTR == Fls_ConfigPtr)
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00382] If development error detection for the module FLS is enabled:
            the function Fls_BlankCheck shall check that the driver has been initialized.
            If this check fails, the function Fls_BlankCheck shall reject the verification
            request, raise the development error FLS_E_UNINIT and return with E_NOT_OK.
            (SRS_BSW_00406) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_UNINIT);
#endif /*FLS_DEV_ERROR_DETECT == STD_ON*/
    }
    else if (TRUE != Fls_IsAddrInRange(TargetAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00380] If development error detection for the module FLS is enabled;
            the function Fls_BlankCheck shall check that the verification start address
            (FlsBaseAddress + TargetAddress) lies within the specified lower and upper
            flash address boundaries. If this check fails, the function Fls_BlankCheck
            shall reject the verification job, raise the development error FLS_E_PARAM_ADDRESS
            and return withE_NOT_OK. (SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_ADDRESS);
#endif /*FLS_DEV_ERROR_DETECT == STD_ON*/
    }
    else if ((0U == Length) || (TRUE != Fls_IsAddrInRange(TargetAddress + Length)))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* [SWS_Fls_00381] If development error detection for the module FLS is enabled:
            the function Fls_BlankCheck shall check that the given length is greater than 0
            and that the verification end address (verification start address + length) lies
            within the specified upper flash address boundary. If this check fails, the function
            Fls_BlankCheck shall reject the verification job, raise the development error
            FLS_E_PARAM_LENGTHandreturnwithE_NOT_OK. (SRS_Fls_12159) */
        (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_LENGTH);
#endif /*FLS_DEV_ERROR_DETECT == STD_ON*/
    }
#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
    else if ((boolean)FALSE == Fls_IsAddrWordAligned(TargetAddress))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report Error if SourceAddress is not aligned */
        (void) Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_ADDRESS);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((boolean)FALSE == Fls_IsAddrWordAligned(TargetAddress + Length))
    {
#if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report Error if SourceAddress + Length is not aligned */
        (void) Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_LENGTH);
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif /*(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)*/
    else
    {
#if (FLS_SCHM_SUPPORT==STD_ON)
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_05();
#endif
        if (MEMIF_JOB_PENDING == Fls_JobState.JobResult)
        {
            /* [SWS_Fls_00383] If development error detection for the module FLS is enabled:
                the function Fls_BlankCheck shall check that the driver is currently not busy.
                If this check fails, the function Fls_BlankCheck shall reject the verification
                request, raise the development error FLS_E_BUSY and return with E_NOT_OK.
                (SRS_BSW_00406) */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_BUSY);
#endif
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_05();
#endif
        }
        else
        {
            Fls_JobState.JobCurrentAddr = TargetAddress;
            Fls_JobState.JobEndAddr = (TargetAddress + Length) - 1U;
            Fls_JobState.JobSectorIt = Fls_GetSectorIndexByAddr(TargetAddress);
            Fls_JobState.JobSectorEnd = Fls_GetSectorIndexByAddr(Fls_JobState.JobEndAddr);
            Fls_JobState.JobType = FLS_JOB_BLANK_CHECK;
            /* [SWS_Fls_00375]  After initiating the verification job, the function
            Fls_BlankCheck shall set the FLS module status to MEMIF_BUSY.  (SRS_Fls_12144) */
            /* [SWS_Fls_00376] After initiating the verification job, the function
            Fls_BlankCheck shall set the FLS module job result to MEMIF_JOB_PENDING. (SRS_Fls_12144) */
            Fls_JobState.JobResult = MEMIF_JOB_PENDING;
            RetVal = E_OK;
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_05();
#endif
        }
    }
    return RetVal;
}
#endif

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

