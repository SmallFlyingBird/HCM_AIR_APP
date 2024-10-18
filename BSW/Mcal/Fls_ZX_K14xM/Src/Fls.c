/**************************************************************************************************/
/**
 * @file      : Fls.c  
 * @brief     : AUTOSAR Flash driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls
 *  @brief Flash AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls.h"
#include "Fls_Drvw.h"
#include "Det.h"

/** @defgroup Private_MacroDefinition
 *	@{
 */
/* Published information */
#define FLS_C_VENDOR_ID                   0x00B3U
#define FLS_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_C_AR_RELEASE_MINOR_VERSION    6U
#define FLS_C_AR_RELEASE_REVISION_VERSION 0U
#define FLS_C_SW_MAJOR_VERSION            1U
#define FLS_C_SW_MINOR_VERSION            2U
#define FLS_C_SW_PATCH_VERSION            1U

/* Check if current file and Fls.h are the same vendor */
#if (FLS_C_VENDOR_ID != FLS_VENDOR_ID)
	#error "Vendor ID of Fls.c and Fls.h are different"
#endif
/* Check if current file and Fls.h are the same Autosar version */
#if((FLS_C_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
    (FLS_C_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION) || \
    (FLS_C_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Fls.c and Fls.h are different"
#endif
/* Check if current file and Fls.h are the same Software version */
#if((FLS_C_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION) || \
    (FLS_C_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION) || \
    (FLS_C_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION))
    #error "Software Version of Fls.c and Fls.h are different"
#endif

/* Check if current file and Fls_Drvw.h are the same vendor */
#if (FLS_C_VENDOR_ID != FLS_DRVW_H_VENDOR_ID)
	#error "Vendor ID of Fls.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Autosar version */
#if((FLS_C_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
    (FLS_C_AR_RELEASE_MINOR_VERSION != FLS_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
    (FLS_C_AR_RELEASE_REVISION_VERSION != FLS_DRVW_H_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Fls.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Software version */
#if((FLS_C_SW_MAJOR_VERSION != FLS_DRVW_H_SW_MAJOR_VERSION) || \
    (FLS_C_SW_MINOR_VERSION != FLS_DRVW_H_SW_MINOR_VERSION) || \
    (FLS_C_SW_PATCH_VERSION != FLS_DRVW_H_SW_PATCH_VERSION))
	#error "Software Version of Fls.c and Fls_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
	/* Check if current file and Det.h are the same Autosar version */
    #if((FLS_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
        (FLS_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version of Fls.c and Det.h are different"
    #endif
#endif
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
/**
 * @brief The runtime job related parameters
 */
static Fls_JobParamType Fls_Job;
#define FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_PTR
#include "Fls_MemMap.h"
/**
 * @brief Pointer to current flash module configuration set
 */
static const Fls_ConfigType * Fls_ConfigPtr;
#define FLS_STOP_SEC_VAR_CLEARED_PTR
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/**
 * @brief Maximum number of bytes to read or compare in one cycle of Fls_MainFunction
 */
static Fls_LengthType Fls_MaxRead;
/**
 * @brief Maximum number of bytes to write in one cycle of Fls_MainFunction
 */
static Fls_LengthType Fls_MaxWrite;
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static Fls_AddressType Fls_GetLogicStartAddr(const uint32 SectorIndex);
static Fls_AddressType Fls_ConvertJobLogicAddrToPhyAddr(void);
static Fls_SectorIndexType Fls_GetSectorIndex(const Fls_AddressType TargetAddr);
#if ( FLS_DEV_ERROR_DETECT == STD_ON )
static boolean Fls_CheckAddrAlignedSectorStart(const Fls_AddressType TargetAddr);
static boolean Fls_CheckAddrAlignedSectorEnd(const Fls_AddressType TargetAddr);
static boolean Fls_CheckAddrAlignedPageStart(const Fls_AddressType TargetAddr);
static boolean Fls_CheckAddrAlignedPageEnd(const Fls_AddressType TargetAddr);
#endif
static Fls_AddressType Fls_ObtainRWEndAddr(const Fls_LengthType MaxTransferSize);
static Fls_LengthType Fls_ObtainWriteLength(const Fls_AddressType MaxWriteEndAddr);
static Fls_LengthType Fls_ObtainReadLength(const Fls_AddressType MaxReadEndAddr);
static void Fls_HandleEraseFault(Fls_Drvw_ResultType EraseJobRes);
static MemIf_JobResultType Fls_ProcessJobErase(void);
static void Fls_HandleWriteFault(Fls_Drvw_ResultType WriteJobRes);
static MemIf_JobResultType Fls_ProcessJobWrite(void);
static Fls_Drvw_ResultType Fls_DoJobRead(Fls_LengthType Len);
static MemIf_JobResultType Fls_HandleReadFault(Fls_Drvw_ResultType ReadJobRes);
static MemIf_JobResultType Fls_ProcessJobRead(void);
static MemIf_JobResultType Fls_ProcessJobs(void);
static MemIf_JobResultType Fls_HandleAsyncEraseJob(void);
static MemIf_JobResultType Fls_HandleAsyncWriteJob(void);
static MemIf_JobResultType Fls_HandleAsyncJob(void);
static void Fls_CheckJobResult(MemIf_JobResultType Result);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/** 
 * @brief     Get start address of a logical sector. 
 *
 * @param[in] SectorIndex: logical sector index
 *
 * @return    Fls_AddressType
 */
static Fls_AddressType Fls_GetLogicStartAddr(const uint32 SectorIndex)
{
    Fls_AddressType Address = 0U;

    if (0U != SectorIndex)
    {
        Address = (Fls_ConfigPtr->SectorList)[SectorIndex - 1U]->EndAddr + 1U;
    }
    else
    {
        Address = 0U;
    }

    return Address;
}

/** 
 * @brief     Convert the current job processing logic address to physical address
 *
 * @param[in] None
 *
 * @return    Fls_AddressType
 */
static Fls_AddressType Fls_ConvertJobLogicAddrToPhyAddr(void)
{
    Fls_AddressType SectorLogicStartAddr;
    Fls_AddressType SectorPhyStartAddr;

    /* Get start logical address of current sector */
    SectorLogicStartAddr = Fls_GetLogicStartAddr(Fls_Job.SectorCur);

    SectorPhyStartAddr = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->PhysicalStartAddr;

    return (Fls_Job.AddrCur - SectorLogicStartAddr + SectorPhyStartAddr);
}

/**
 * @brief       Get logical sector index by the TargetAddr. 
 *
 * @param[in]   TargetAddr: Target logical address
 *
 * @return      index of logical sector
 *    
 */
static Fls_SectorIndexType Fls_GetSectorIndex(const Fls_AddressType TargetAddr)
{
    Fls_SectorIndexType SectorIndex = 0U;

    for (SectorIndex = 0U; SectorIndex < Fls_ConfigPtr->SectorNum; SectorIndex++)
    {
        if(TargetAddr <= (((Fls_ConfigPtr->SectorList)[SectorIndex])->EndAddr))
        {
           break;
        }
    }
 
    return SectorIndex;
}

#if ( FLS_DEV_ERROR_DETECT == STD_ON )
/** 
 * @brief     Get the Flash logical end address
 *
 * @param[in] None
 *
 * @return    End address 
 */
LOCAL_INLINE uint32 Fls_GetFlashEndAddr(void)
{
    return ((Fls_ConfigPtr->SectorList)[Fls_ConfigPtr->SectorNum - 1U]->EndAddr);
}

/** 
 * @brief     Check if the address is aligned with a physical sector start address
 *
 * @param[in] TargetAddr: address in flash memory to be checked
 *
 * @return    boolean
 * @retval    TRUE
 * @retval    FALSE
 */
static boolean Fls_CheckAddrAlignedSectorStart(const Fls_AddressType TargetAddr)
{
    boolean RetVal = (boolean)FALSE;
    Fls_SectorIndexType SecIndex;
    Fls_LengthType SectorSize;
    Fls_AddressType StartAddr;

    if (TargetAddr <= Fls_GetFlashEndAddr())
    {
        SecIndex = Fls_GetSectorIndex(TargetAddr);
        SectorSize = (Fls_ConfigPtr->SectorList)[SecIndex]->SectorSize;
        StartAddr = Fls_GetLogicStartAddr(SecIndex);
        if(SectorSize != 0U)
        {
            if(0U == ((TargetAddr - StartAddr) % SectorSize))
            {
                RetVal = (boolean)TRUE;
            }
        }
    }

    return RetVal;
}

/** 
 * @brief     Check if the address is aligned with a physical sector end address
 *
 * @param[in] TargetAddr: address in flash memory to be checked
 *
 * @return    boolean
 * @retval    TRUE
 * @retval    FALSE
 */
static boolean Fls_CheckAddrAlignedSectorEnd(const Fls_AddressType TargetAddr)
{
    boolean RetVal = (boolean)FALSE;
    Fls_SectorIndexType SecIndex;
    Fls_LengthType SecSize;
    Fls_AddressType StartAddr;

    if (TargetAddr <= Fls_GetFlashEndAddr())
    {
        SecIndex = Fls_GetSectorIndex(TargetAddr);
        SecSize = (Fls_ConfigPtr->SectorList)[SecIndex]->SectorSize;
        StartAddr = Fls_GetLogicStartAddr(SecIndex);
        if(SecSize != 0U)
        {
            if(0U == ((TargetAddr + 1U - StartAddr) % SecSize))
            {
                RetVal = (boolean)TRUE;
            }
        }
    }

    return RetVal;
}

/** 
 * @brief     Check if the address is aligned with a physical page start address
 *
 * @param[in] TargetAddr: address in flash memory to be checked
 *
 * @return    boolean
 * @retval    TRUE
 * @retval    FALSE
 */
static boolean Fls_CheckAddrAlignedPageStart(const Fls_AddressType TargetAddr)
{
    boolean RetVal = (boolean)FALSE;
    Fls_SectorIndexType SecIndex;
    Fls_LengthType PageSize;
    Fls_AddressType StartAddr;

    if (TargetAddr <= Fls_GetFlashEndAddr())
    {
        SecIndex = Fls_GetSectorIndex(TargetAddr);
        StartAddr = Fls_GetLogicStartAddr(SecIndex);
        PageSize = (Fls_ConfigPtr->SectorList)[SecIndex]->PageSize;
        if(PageSize != 0U)
        {
            if(0U == ((TargetAddr - StartAddr) % PageSize))
            {
                RetVal = (boolean)TRUE;
            }
        }
    }

    return RetVal;
}

/** 
 * @brief     Check if the address is aligned with a physical page end address
 *
 * @param[in] TargetAddr: address in flash memory to be checked
 *
 * @return    boolean
 * @retval    TRUE
 * @retval    FALSE
 */
static boolean Fls_CheckAddrAlignedPageEnd(const Fls_AddressType TargetAddr)
{
    boolean RetVal = (boolean)FALSE;
    Fls_SectorIndexType SecIndex;
    Fls_LengthType PageSize;
    Fls_AddressType StartAddr;

    if (TargetAddr <= Fls_GetFlashEndAddr())
    {
        SecIndex = Fls_GetSectorIndex(TargetAddr);
        PageSize = (Fls_ConfigPtr->SectorList)[SecIndex]->PageSize;
        StartAddr = Fls_GetLogicStartAddr(SecIndex);
        if(PageSize != 0U)
        {
            if(0U == ((TargetAddr + 1U - StartAddr) % PageSize))
            {
                RetVal = (boolean)TRUE;
            }
        }
    }

    return RetVal;
}
#endif

/** 
 * @brief     Calculate the transfer end logical address in one cycle of Fls_MainFunction()
 *
 * @param[in] MaxTransferSize: the maximum transfer size
 *
 * @return    Fls_AddressType
 */
static Fls_AddressType Fls_ObtainRWEndAddr(const Fls_LengthType MaxTransferSize)
{
    Fls_AddressType TransferEndAddr = Fls_Job.AddrCur + MaxTransferSize - 1U;

    if(Fls_Job.AddrEnd < TransferEndAddr)
    {
        TransferEndAddr = Fls_Job.AddrEnd;
    }

    return TransferEndAddr;
}

/** 
 * @brief     Calculate the length to write for current sector in the current cycle of 
 *            Fls_MainFunction()
 *
 * @param[in] MaxWriteEndAddr: the end address for writing
 *
 * @return    Fls_LengthType
 */
static Fls_LengthType Fls_ObtainWriteLength(const Fls_AddressType MaxWriteEndAddr)
{
    boolean AsyncFlag =((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->WriteAsyncFlag;
    Fls_LengthType PageSize = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->PageSize;
    Fls_AddressType SectorEndAddr = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr;
    Fls_LengthType WriteLen = (MaxWriteEndAddr < SectorEndAddr) ? (MaxWriteEndAddr - Fls_Job.AddrCur
                               + 1U):(SectorEndAddr - Fls_Job.AddrCur + 1U);
    
    if(AsyncFlag == TRUE)
    {
        /* in async write mode, only write one page in one cycle of Fls_MainFunction() */
        WriteLen = (WriteLen > PageSize) ? PageSize : WriteLen;
    }

    return WriteLen;
}

/** 
 * @brief     Calculate the length to read for current sector in the current cycle of 
 *            Fls_MainFunction()
 *
 * @param[in] MaxReadEndAddr: the end address for read
 *
 * @return    Fls_LengthType
 */
static Fls_LengthType Fls_ObtainReadLength(const Fls_AddressType MaxReadEndAddr)
{
    Fls_AddressType SectorEndAddr = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr;
    Fls_LengthType ReadLen = (MaxReadEndAddr < SectorEndAddr) ? (MaxReadEndAddr - Fls_Job.AddrCur 
                              + 1U):(SectorEndAddr - Fls_Job.AddrCur + 1U);
    
    return ReadLen;
}

/** 
 * @brief     Handle erase job fault
 *
 * @param[in] EraseJobRes: result of flash erase job 
 *
 * @return    none
 */
static void Fls_HandleEraseFault(Fls_Drvw_ResultType EraseJobRes)
{
    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                FLS_SID_MAIN_FUNCTION, FLS_E_ERASE_FAILED);
	
	if (FLS_DRVW_E_BLANK_CHECK == EraseJobRes)
	{
		(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                             FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
	}
	else if (FLS_DRVW_E_TIMEOUT == EraseJobRes)
	{
		(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
			                          FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
	}
	else
	{
		/*do nothing*/
	}
}

/** 
 * @brief     Process Flash Erase Job and erase one physical sector
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_FAILED
 * @retval    MEMIF_BLOCK_INCONSISTENT
 */
static MemIf_JobResultType Fls_ProcessJobErase(void)
{
    MemIf_JobResultType Res = MEMIF_JOB_PENDING;
    boolean AsyncFlag;
    Fls_LengthType PhysicalSectorSize;
    Fls_Drvw_ResultType LowLevelRes;
	Fls_AddressType PhyAddr = Fls_ConvertJobLogicAddrToPhyAddr();

    if(Fls_Job.AddrCur > Fls_Job.AddrEnd)
    {
        Res = MEMIF_JOB_OK;
    }
    else
    {
        AsyncFlag = (Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur]->EraseAsyncFlag;

        PhysicalSectorSize = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->SectorSize;

        LowLevelRes = Fls_Drvw_EraseSector(PhyAddr, AsyncFlag);

		if (FLS_DRVW_E_PENDING == LowLevelRes)
		{
			Fls_Job.AsyncExecutingFlag = (boolean)TRUE;
		}
        else if (FLS_DRVW_E_OK != LowLevelRes)
        {
			Res = MEMIF_JOB_FAILED;
			Fls_HandleEraseFault(LowLevelRes);
        }
        else if (AsyncFlag == 0U)
        {
            Fls_Job.AddrCur += PhysicalSectorSize;

            if(Fls_Job.AddrCur > Fls_Job.AddrEnd)
            {
                Res = MEMIF_JOB_OK;
            }
            else if(Fls_Job.AddrCur > (((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr))
            {
                Fls_Job.SectorCur++;
            }
			else
			{
				/*do nothing*/
			}
        }
	    else
		{
			/*do nothing*/
		}
    }

    return Res;
}

/** 
 * @brief     Handle write job fault
 *
 * @param[in] WriteJobRes: result of flash write job
 *
 * @return    none
 */
static void Fls_HandleWriteFault(Fls_Drvw_ResultType WriteJobRes)
{
    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                    FLS_SID_MAIN_FUNCTION, FLS_E_WRITE_FAILED);
	
	if (FLS_DRVW_E_BLANK_CHECK == WriteJobRes)
	{
		(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                    FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
	}
	else if (FLS_DRVW_E_COMPARE == WriteJobRes)
	{
		(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                    FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_WRITE_FAILED);
	}
	else if (FLS_DRVW_E_TIMEOUT == WriteJobRes)
	{
		(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                     FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
	}
	else
	{
		/*do nothing*/
	}
}

/** 
 * @brief     Process Flash write Job
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_FAILED
 * @retval    MEMIF_BLOCK_INCONSISTENT
 */
static MemIf_JobResultType Fls_ProcessJobWrite(void)
{
    MemIf_JobResultType Res = MEMIF_JOB_PENDING;
    Fls_AddressType WriteEndAddr;
    Fls_Drvw_ResultType LowLevelRes = FLS_DRVW_E_OK;
    Fls_LengthType WriteLen;
    boolean AsyncFlag;
	Fls_AddressType PhyAddr;

    if(Fls_Job.AddrCur > Fls_Job.AddrEnd)
    {
        Res = MEMIF_JOB_OK;
    }
    else
    {
        WriteEndAddr = Fls_ObtainRWEndAddr(Fls_MaxWrite);

        while((Fls_Job.AddrCur <= WriteEndAddr) && (FLS_DRVW_E_OK == LowLevelRes))
        {
            WriteLen = Fls_ObtainWriteLength(WriteEndAddr);
                
            AsyncFlag = (Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur]->WriteAsyncFlag;

			PhyAddr = Fls_ConvertJobLogicAddrToPhyAddr();
			
			LowLevelRes = Fls_Drvw_WriteSector(PhyAddr, WriteLen, Fls_Job.DataSrcPtr,AsyncFlag);

            if(FLS_DRVW_E_OK == LowLevelRes)
            {
                /* update address and pointer for next write operation*/
                Fls_Job.AddrCur += WriteLen;            
                Fls_Job.DataSrcPtr = &(Fls_Job.DataSrcPtr[WriteLen]);

                /* goto next sector if the job belongs to the current sector has been finished */
                if(Fls_Job.AddrCur > (((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr))
                {
                    Fls_Job.SectorCur++;
                }
            }
        }

		if (FLS_DRVW_E_PENDING == LowLevelRes)
		{
			Fls_Job.AsyncExecutingFlag = (boolean)TRUE;
		}
        else if (FLS_DRVW_E_OK != LowLevelRes)
        {
			Res = MEMIF_JOB_FAILED;
			Fls_HandleWriteFault(LowLevelRes);
        }
        else if (Fls_Job.AddrCur > Fls_Job.AddrEnd)
        {
            /* Job is done */
            Res = MEMIF_JOB_OK;
        }
		else
		{
			/*do nothing*/
		}
    }
    
    return Res;
}

/** 
 * @brief     Do Flash Read/compare/blankcheck Job
 *
 * @param[in] Len: the data length
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_COMPARE
 * @retval    FLS_DRVW_E_FAILED
 */
static Fls_Drvw_ResultType Fls_DoJobRead(Fls_LengthType Len)
{
    Fls_Drvw_ResultType Res = FLS_DRVW_E_FAILED;
	Fls_AddressType PhyAddr = Fls_ConvertJobLogicAddrToPhyAddr();

    switch (Fls_Job.Job)
    {
        case FLS_JOB_READ:
            Res =  Fls_Drvw_ReadSector(PhyAddr, Len, Fls_Job.DataDestPtr);
            if (FLS_DRVW_E_OK != Res)
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                                FLS_SID_MAIN_FUNCTION, FLS_E_READ_FAILED);
            }

            Fls_Job.DataDestPtr = &((Fls_Job.DataDestPtr)[Len]);
            break;

#if(FLS_COMPARE_API == STD_ON)
        case FLS_JOB_COMPARE:
            Res =  Fls_Drvw_CompareSector(PhyAddr, Len, Fls_Job.DataSrcPtr);
            if (FLS_DRVW_E_OK != Res)
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                                FLS_SID_MAIN_FUNCTION, FLS_E_COMPARE_FAILED);
				if (FLS_DRVW_E_COMPARE == Res)
				{
	                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                                 FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_WRITE_FAILED);
				}
            }

            Fls_Job.DataSrcPtr = &((Fls_Job.DataSrcPtr)[Len]);
            break;
#endif /* FLS_COMPARE_API == STD_ON */

#if(FLS_BLANK_CHECK_API == STD_ON)
        case FLS_JOB_BLANK_CHECK:
            Res =  Fls_Drvw_BlankCheckSector(PhyAddr, Len);
            if (FLS_DRVW_E_OK != Res)
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                                FLS_SID_MAIN_FUNCTION, FLS_E_COMPARE_FAILED);
				if (FLS_DRVW_E_BLANK_CHECK == Res)
				{
	                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                                 FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
				}
            }
            break;
#endif /* FLS_BLANK_CHECK_API == STD_ON */

        default:
            /*do nothing*/
            break;
    }

    return Res;
}

/** 
 * @brief     Handle read job fault
 *
 * @param[in] ReadJobRes: result of flash read job
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_FAILED
 * @retval    MEMIF_BLOCK_INCONSISTENT
 * @retval    MEMIF_JOB_PENDING
 */
static MemIf_JobResultType Fls_HandleReadFault(Fls_Drvw_ResultType ReadJobRes)
{
    MemIf_JobResultType Res = MEMIF_JOB_PENDING;
	
	if((FLS_DRVW_E_FAILED == ReadJobRes) || (FLS_DRVW_E_BLANK_CHECK == ReadJobRes))
	{
		Res = MEMIF_JOB_FAILED;
	}
	else if(FLS_DRVW_E_COMPARE == ReadJobRes)
	{
		Res = MEMIF_BLOCK_INCONSISTENT;
	}
	else
	{
		/*do nothing*/
	}

	return Res;
}

/** 
 * @brief     Process Flash Read Job
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_BLOCK_INCONSISTENT
 * @retval    MEMIF_JOB_FAILED
 */
static MemIf_JobResultType Fls_ProcessJobRead(void)
{
    MemIf_JobResultType Res = MEMIF_JOB_PENDING;
    Fls_AddressType ReadEndAddr;
    Fls_Drvw_ResultType LowLevelRes = FLS_DRVW_E_OK;
    Fls_LengthType ReadLen;

    if(Fls_Job.AddrCur > Fls_Job.AddrEnd)
    {
        Res = MEMIF_JOB_OK;
    }
    else
    {
        ReadEndAddr = Fls_ObtainRWEndAddr(Fls_MaxRead);

        while((Fls_Job.AddrCur <= ReadEndAddr) && (FLS_DRVW_E_OK == LowLevelRes))
        {
            ReadLen = Fls_ObtainReadLength(ReadEndAddr);

            LowLevelRes = Fls_DoJobRead(ReadLen);

			/* update address for next read operation*/
            Fls_Job.AddrCur += ReadLen;            

            if(FLS_DRVW_E_OK == LowLevelRes)
            {
                /* goto next sector if the job belongs to the current sector has been finished */
                if(Fls_Job.AddrCur > (((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr))
                {
                    Fls_Job.SectorCur++;
                }
            }
        }
		
		if (FLS_DRVW_E_OK != LowLevelRes)
		{
			Res = Fls_HandleReadFault(LowLevelRes);
		}
        else if (Fls_Job.AddrCur > Fls_Job.AddrEnd) 
        {
            /* Job is done */
            Res = MEMIF_JOB_OK;
        }
		else
		{
			/*do nothing*/
		}
    }
    
    return Res;
}

/** 
 * @brief     Flash Jobs in main function
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_FAILED
 * @retval    MEMIF_BLOCK_INCONSISTENT
 */
static MemIf_JobResultType Fls_ProcessJobs(void)
{
    MemIf_JobResultType JobResult;

    if(Fls_Job.Job == FLS_JOB_ERASE)
    {
        JobResult = Fls_ProcessJobErase();
    }
    else if(Fls_Job.Job == FLS_JOB_WRITE)
    {
        JobResult = Fls_ProcessJobWrite();
    }
    else
    {
        JobResult = Fls_ProcessJobRead();
    }      

    return JobResult;
}

/** 
 * @brief     check the job result
 *
 * @param[in] Result: the Job result
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_FAILED
 * @retval    MEMIF_BLOCK_INCONSISTENT
 */
static void Fls_CheckJobResult(MemIf_JobResultType Result)
{
    Fls_Job.JobResult = Result;

    if (MEMIF_JOB_OK == Result)
    {
        if(NULL_PTR != Fls_ConfigPtr->JobEndNotificationPtr)
        {
            Fls_ConfigPtr->JobEndNotificationPtr();
        }
    }
    else if((MEMIF_JOB_FAILED == Result) || (MEMIF_JOB_CANCELED == Result) ||
            (MEMIF_BLOCK_INCONSISTENT == Result))
    {
        if (NULL_PTR != Fls_ConfigPtr->JobErrorNotificationPtr)
        {
            Fls_ConfigPtr->JobErrorNotificationPtr();
        }
    }
    else
    {
        /*do nothing*/
    }
}

/**
 * @brief     Handle asynchronous erase job.
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_FAILED
 *
 */
static MemIf_JobResultType Fls_HandleAsyncEraseJob(void)
{
	Fls_Drvw_ResultType Ret;
	MemIf_JobResultType Res = MEMIF_JOB_PENDING;
	Fls_AddressType PhyAddr = Fls_ConvertJobLogicAddrToPhyAddr();
	Fls_LengthType PhySectorSize = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->SectorSize;

	Ret = Fls_Drvw_HandleAsyncEraseJob(PhyAddr,PhySectorSize);

	if (Ret != FLS_DRVW_E_BUSY)
	{
		Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
		
		if (Ret != FLS_DRVW_E_OK)
		{
			Res = MEMIF_JOB_FAILED;

			(void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
						   FLS_SID_MAIN_FUNCTION, FLS_E_ERASE_FAILED);
		
			if(Ret == FLS_DRVW_E_BLANK_CHECK)
			{
				(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
											   FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
			}
			else if(Ret == FLS_DRVW_E_TIMEOUT)
			{
				(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
											   FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
			}
			else
			{
				/*do nothing*/
			}
		}
		else
		{
			Fls_Job.AddrCur += PhySectorSize;
			if(Fls_Job.AddrCur > (((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr))
			{
				Fls_Job.SectorCur++;
			}

			Res = MEMIF_JOB_OK;
		}		
	}
	
	return Res;
}

/**
 * @brief     Handle asynchronous write job.
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_FAILED
 *
 */
static MemIf_JobResultType Fls_HandleAsyncWriteJob(void)
{
	Fls_Drvw_ResultType Ret;
	MemIf_JobResultType Res = MEMIF_JOB_PENDING;
	Fls_AddressType PhyAddr = Fls_ConvertJobLogicAddrToPhyAddr();
	Fls_LengthType PageSize = ((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->PageSize;

	Ret = Fls_Drvw_HandleAsyncWriteJob(PhyAddr, Fls_Job.DataSrcPtr, PageSize);

	if(Ret != FLS_DRVW_E_BUSY)
	{
		Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
		
		if (Ret != FLS_DRVW_E_OK)
		{
			Res = MEMIF_JOB_FAILED;
			
			(void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
							FLS_SID_MAIN_FUNCTION, FLS_E_WRITE_FAILED);
		
			if(Ret == FLS_DRVW_E_COMPARE)
			{
				(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
											   FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_WRITE_FAILED);
			}
			else if(Ret == FLS_DRVW_E_TIMEOUT)
			{
				(void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
											   FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
			}
			else
			{
				/*do nothing*/
			}
		}
		else
		{
			Fls_Job.AddrCur += PageSize;
			Fls_Job.DataSrcPtr = &(Fls_Job.DataSrcPtr[PageSize]);
			if(Fls_Job.AddrCur > (((Fls_ConfigPtr->SectorList)[Fls_Job.SectorCur])->EndAddr))
			{
				Fls_Job.SectorCur++;
			}

			Res = MEMIF_JOB_OK;
		}
	}
	
	return Res;
}

/**
 * @brief     Handle asynchronous job.
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_PENDING
 * @retval    MEMIF_JOB_OK
 * @retval    MEMIF_JOB_FAILED
 *
 */
static MemIf_JobResultType Fls_HandleAsyncJob(void)
{
	MemIf_JobResultType Res = MEMIF_JOB_FAILED;
	
	if(FLS_JOB_ERASE == Fls_Job.Job)
	{
		Res = Fls_HandleAsyncEraseJob();
	}
	else if(FLS_JOB_WRITE == Fls_Job.Job)
	{
		Res = Fls_HandleAsyncWriteJob();
	}
	else
	{
		/*do nothing*/
	}

	return Res;
}

#if ( FLS_DEV_ERROR_DETECT == STD_ON )
/**
 * @brief     Check if the configuration set has been initialized 
 *
 * @param[in] ServiceId : ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckEraseWriteConfigPtr(uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if(NULL_PTR == Fls_ConfigPtr)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, ServiceId, FLS_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the start address is aligned or not 
 *
 * @param[in] StartAddr : Start address of Fls erase job
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckEraseStartAddrAlign(Fls_AddressType StartAddr)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if ((boolean)FALSE == Fls_CheckAddrAlignedSectorStart(StartAddr))
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                              FLS_SID_ERASE, FLS_E_PARAM_ADDRESS);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the end address is aligned or not 
 *
 * @param[in] EndAddr : Start address of Fls erase job
 * @param[in] Len     : Number of bytes to erase
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckEraseEndAddrAlign(Fls_AddressType EndAddr, Fls_LengthType Len)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if(((boolean)FALSE == Fls_CheckAddrAlignedSectorEnd(EndAddr)) || (0U == Len))
	{
		(void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                              FLS_SID_ERASE, FLS_E_PARAM_LENGTH);
		RetVal = (Std_ReturnType)E_NOT_OK;
	}

	return RetVal;
}

/**
 * @brief     Check if the start address is aligned or not 
 *
 * @param[in] StartAddr : Start address of Fls write job
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckWriteStartAddrAlign(Fls_AddressType StartAddr)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if((boolean)FALSE == Fls_CheckAddrAlignedPageStart(StartAddr))
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                              FLS_SID_WRITE, FLS_E_PARAM_ADDRESS);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the end address is aligned or not 
 *
 * @param[in] EndAddr : Start address of Fls write job
 * @param[in] Len     : Number of bytes to write
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckWriteEndAddrAlign(Fls_AddressType EndAddr, Fls_LengthType Len)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(((boolean)FALSE == Fls_CheckAddrAlignedPageEnd(EndAddr)) || (0U == Len))
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                              FLS_SID_WRITE, FLS_E_PARAM_LENGTH);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check the Fls module state
 *
 * @param[in] ServiceId : ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckModuleState(uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(NULL_PTR == Fls_ConfigPtr)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, ServiceId, FLS_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the start address is within the address range of the current sector
 *
 * @param[in] ServiceId : ApiId
 * @param[in] StartAddr : Start address of Fls read/compare/blankcheck job
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckStartAddr(uint8 ServiceId, Fls_AddressType StartAddr)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(StartAddr > Fls_GetFlashEndAddr())
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, ServiceId, FLS_E_PARAM_ADDRESS);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the end address is within the address range of the current sector
 *
 * @param[in] ServiceId : ApiId
 * @param[in] EndAddr   : End address of Fls read/compare/blankcheck job
 * @param[in] Len       : Numbers of bytes to handle
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckEndAddr(uint8 ServiceId, 
                                             Fls_AddressType EndAddr, 
                                             Fls_LengthType Len)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if((0U == Len) || (EndAddr > Fls_GetFlashEndAddr()))
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, ServiceId, FLS_E_PARAM_LENGTH);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the data buffer pointer is non-null
 *
 * @param[in] ServiceId     : ApiId
 * @param[in] DateBufferPtr : Pointer to data buffer
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Fls_CheckDataBufferPtr(uint8 ServiceId, const uint8* DateBufferPtr)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if(NULL_PTR == DateBufferPtr)
	{
		(void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, ServiceId, FLS_E_PARAM_DATA);
		RetVal = (Std_ReturnType)E_NOT_OK;
	}

	return RetVal;
}
#endif

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/**
 * @brief     Initializes the Flash Driver. 
 *
 * @param[in] ConfigPtr: Pointer to flash driver configuration set.
 *
 * @return    None
 *
 */
/* SWS_Fls_00249, SWS_Fls_00191 */
void Fls_Init(const Fls_ConfigType* ConfigPtr)
{
	Fls_Drvw_ResultType Ret;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
    if(ConfigPtr != NULL_PTR)
#else
    if(ConfigPtr == NULL_PTR)
#endif /* FLS_PRECOMPILE_SUPPORT == STD_ON */
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                              FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_INIT, FLS_E_BUSY);
    }
    else
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
        Fls_ConfigPtr = Fls_PreDefinedConfigPtr;
        (void)ConfigPtr;
#else
        Fls_ConfigPtr = ConfigPtr;
#endif  /* FLS_PRECOMPILE_SUPPORT == STD_ON */

        if (MEMIF_MODE_FAST == Fls_ConfigPtr->DefaultMode)
        {
            Fls_MaxRead  = Fls_ConfigPtr->MaxReadFastMode;
            Fls_MaxWrite = Fls_ConfigPtr->MaxWriteFastMode;
        }
        else
        {
            Fls_MaxRead  = Fls_ConfigPtr->MaxReadNormalMode;
            Fls_MaxWrite = Fls_ConfigPtr->MaxWriteNormalMode;
        }
		
		Ret = Fls_Drvw_Init(Fls_ConfigPtr->WrapperConfigSetPtr);
		if(Ret == FLS_DRVW_E_BUSY)
	    {
	        /* the internal flash is busy */
	        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_INIT, FLS_E_BUSY);
	    }
	    else if(Ret == FLS_DRVW_E_HW_FAIL)
	    {
	        /* the internal flash is in failed status */
	        (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
	                                       FLS_SID_INIT, FLS_E_INIT_FAILED);
	    }
#if (FLS_DEV_ERROR_DETECT == STD_ON)
		else if (Ret == FLS_DRVW_E_PARAM_DATA)
		{
			(void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                  FLS_SID_INIT, FLS_E_PARAM_DATA);
		}
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
		else
		{
			/*do nothing*/
		}

        Fls_Job.JobResult = MEMIF_JOB_OK;
        Fls_Job.AsyncExecutingFlag = 0U;
    }
}

/**
 * @brief     Erases flash sector(s). 
 *
 * @param[in] TargetAddress: Target address in flash memory.
 * @param[in] Length: Number of bytes to erase.
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Erase command has been accepted.
 * @retval    E_NOT_OK - Erase command has not been accepted.
 *
 */
/* SWS_Fls_00250 */
Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Fls_AddressType EndAddr = TargetAddress + Length - 1U;

#if(FLS_DEV_ERROR_DETECT == STD_ON)
	RetVal = Fls_CheckEraseWriteConfigPtr(FLS_SID_ERASE);
	if (E_OK == RetVal)
	{
		RetVal = Fls_CheckEraseStartAddrAlign(TargetAddress);
		RetVal |= Fls_CheckEraseEndAddrAlign(EndAddr, Length);
	}
    
    if (E_OK == RetVal)
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
#if(FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_ERASE, FLS_E_BUSY);
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_Job.SectorCur = Fls_GetSectorIndex(TargetAddress);
            Fls_Job.SectorEnd = Fls_GetSectorIndex(EndAddr);
            Fls_Job.AddrCur = TargetAddress;
            Fls_Job.AddrEnd = EndAddr;
            Fls_Job.Job = FLS_JOB_ERASE;
            Fls_Job.JobResult = MEMIF_JOB_PENDING;
            Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
        }
    }
    
    return RetVal;
}

/**
 * @brief     Writes one or more complete flash pages. 
 *
 * @param[in] TargetAddress: Target address in flash memory.
 * @param[in] SourceAddressPtr: Pointer to source data buffer
 * @param[in] Length: Number of bytes to write.
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Write command has been accepted.
 * @retval    E_NOT_OK - Write command has not been accepted.
 *
 */
/* SWS_Fls_00251 */
Std_ReturnType Fls_Write(Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, 
                         Fls_LengthType Length )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Fls_AddressType EndAddr = TargetAddress + Length - 1U;

#if(FLS_DEV_ERROR_DETECT == STD_ON)
	RetVal = Fls_CheckEraseWriteConfigPtr(FLS_SID_WRITE);
	if (E_OK == RetVal)
	{
		RetVal = Fls_CheckWriteStartAddrAlign(TargetAddress);
		RetVal |= Fls_CheckWriteEndAddrAlign(EndAddr, Length);
	}
	RetVal |= Fls_CheckDataBufferPtr(FLS_SID_WRITE, SourceAddressPtr);
    
	if (E_OK == RetVal)
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
	{
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
#if(FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_WRITE, FLS_E_BUSY);
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_Job.SectorCur = Fls_GetSectorIndex(TargetAddress);
            Fls_Job.SectorEnd = Fls_GetSectorIndex(EndAddr);
            Fls_Job.AddrCur = TargetAddress;
            Fls_Job.AddrEnd = EndAddr;
            Fls_Job.DataSrcPtr = SourceAddressPtr;
            Fls_Job.Job = FLS_JOB_WRITE;
            Fls_Job.JobResult = MEMIF_JOB_PENDING;
            Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
        }
    }
    
    return RetVal;
}

#if(FLS_CANCEL_API == STD_ON)
/**
 * @brief     Cancels an ongoing job. 
 *
 * @param[in] None
 *
 * @return    None
 *
 */
/* SWS_Fls_00252 */
void Fls_Cancel(void)
{
	Fls_Drvw_ResultType Ret;

#if(FLS_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Fls_ConfigPtr)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_CANCEL, FLS_E_UNINIT);
    }
    else
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
            Ret = Fls_Drvw_Cancel((Fls_Drvw_JobType)Fls_Job.Job);

			if((Ret == FLS_DRVW_E_OK) || (Ret == FLS_DRVW_E_CMD_ABORTED))
		    {
		        /* job is successfully aborted */
		    }
		    else
		    {
		        /* the abort request is time-out */
		        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_CANCEL,
		                                      FLS_E_TIMEOUT);
		    }

            Fls_Job.JobResult = MEMIF_JOB_CANCELED;
            Fls_Job.AsyncExecutingFlag = 0U;

            if (NULL_PTR != Fls_ConfigPtr->JobErrorNotificationPtr)
            {
                Fls_ConfigPtr->JobErrorNotificationPtr();
            }
            else
            {
                
            }           
        }
        else
        {
            Fls_Job.AsyncExecutingFlag = 0U;
        }
    }
}
#endif /* FLS_CANCEL_API == STD_ON */

#if(FLS_GET_STATUS_API == STD_ON)
/**
 * @brief     Returns the driver state. 
 *
 * @param[in] None
 *
 * @return    MemIf_StatusType
 * @retval    MEMIF_UNINIT
 * @retval    MEMIF_IDLE
 * @retval    MEMIF_BUSY
 *
 */
/* SWS_Fls_00253 */
MemIf_StatusType Fls_GetStatus(void)
{
    MemIf_StatusType RetVal;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        RetVal = MEMIF_UNINIT;
    }
    else if (MEMIF_JOB_PENDING == Fls_Job.JobResult)
    {
        RetVal = MEMIF_BUSY;
    }
    else
    {
        RetVal = MEMIF_IDLE;
    }

    return RetVal;
}
#endif /* FLS_GET_STATUS_API == STD_ON */

#if(FLS_GET_JOB_RESULT_API == STD_ON)
/**
 * @brief     Returns the result of the last job.
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK              Successfully completed job.
 * @retval    MEMIF_JOB_FAILED          The job has not been finished successfully.
 * @retval    MEMIF_JOB_PENDING         The job has not yet been finished.
 * @retval    MEMIF_JOB_CANCELED        The job has been canceled.
 * @retval    MEMIF_BLOCK_INCONSISTENT  1. The requested block is inconsistent, it may contain 
 *                                      corrupted data. 2. Block is NOT found.
 * @retval    MEMIF_BLOCK_INVALID       The requested block has been marked as invalid, the 
 *                                      requested operation can not be performed.
 *
 */
/* SWS_Fls_00254 */
MemIf_JobResultType Fls_GetJobResult ( void )
{
    MemIf_JobResultType RetVal;

#if (FLS_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Fls_ConfigPtr)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_GET_JOB_RESULT, 
                               FLS_E_UNINIT);
        RetVal = MEMIF_JOB_FAILED;
    }
    else
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        RetVal = Fls_Job.JobResult;
    }
    return RetVal;
}
#endif /* FLS_GET_JOB_RESULT_API == STD_ON */

/**
 * @brief     Reads from flash memory. 
 *
 * @param[in] SourceAddress: Source address in flash memory.
 * @param[in] Length: Number of bytes to read.
 * @param[out] TargetAddressPtr: Pointer to target data buffer
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Read command has been accepted.
 * @retval    E_NOT_OK - Read command has not been accepted.
 *
 */
/* SWS_Fls_00256 */
Std_ReturnType Fls_Read(Fls_AddressType SourceAddress, uint8* TargetAddressPtr, 
                        Fls_LengthType Length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Fls_AddressType EndAddr = SourceAddress + Length - 1U;

#if(FLS_DEV_ERROR_DETECT == STD_ON)
	RetVal = Fls_CheckModuleState(FLS_SID_READ);
	if (E_OK == RetVal)
	{
		RetVal = Fls_CheckStartAddr(FLS_SID_READ, SourceAddress);
		RetVal |= Fls_CheckEndAddr(FLS_SID_READ, EndAddr, Length);
	}
	RetVal |= Fls_CheckDataBufferPtr(FLS_SID_READ, TargetAddressPtr);
    
	if (E_OK == RetVal)
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
#if(FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_READ, FLS_E_BUSY);
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_Job.SectorCur = Fls_GetSectorIndex(SourceAddress);
            Fls_Job.SectorEnd = Fls_GetSectorIndex(EndAddr);
            Fls_Job.AddrCur = SourceAddress;
            Fls_Job.AddrEnd = EndAddr;
            Fls_Job.DataDestPtr = TargetAddressPtr;
            Fls_Job.Job = FLS_JOB_READ;
            Fls_Job.JobResult = MEMIF_JOB_PENDING;
            Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
        }
    }
    
    return RetVal;
}

#if(FLS_COMPARE_API == STD_ON)
/**
 * @brief     Compares the contents of an area of flash memory with that of an application data 
 *            buffer. 
 *
 * @param[in] SourceAddress: Source address in flash memory.
 * @param[in] Length: Number of bytes to compare.
 * @param[out] TargetAddressPtr: Pointer to target data buffer
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Compare command has been accepted.
 * @retval    E_NOT_OK - Compare command has not been accepted.
 *
 */
/* SWS_Fls_00257 */
Std_ReturnType Fls_Compare(Fls_AddressType SourceAddress, const uint8* TargetAddressPtr, 
                           Fls_LengthType Length )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Fls_AddressType EndAddr = SourceAddress + Length - 1U;

#if(FLS_DEV_ERROR_DETECT == STD_ON)
	RetVal = Fls_CheckModuleState(FLS_SID_COMPARE);
	if (E_OK == RetVal)
	{
		RetVal = Fls_CheckStartAddr(FLS_SID_COMPARE, SourceAddress);
		RetVal |= Fls_CheckEndAddr(FLS_SID_COMPARE, EndAddr, Length);
	}
	RetVal |= Fls_CheckDataBufferPtr(FLS_SID_COMPARE, TargetAddressPtr);

	if (E_OK == RetVal)
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
#if(FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_COMPARE, FLS_E_BUSY);
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_Job.SectorCur = Fls_GetSectorIndex(SourceAddress);
            Fls_Job.SectorEnd = Fls_GetSectorIndex(EndAddr);
            Fls_Job.AddrCur = SourceAddress;
            Fls_Job.AddrEnd = EndAddr;
            Fls_Job.DataSrcPtr = TargetAddressPtr;
            Fls_Job.Job = FLS_JOB_COMPARE;
            Fls_Job.JobResult = MEMIF_JOB_PENDING;
            Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
        }
    }
    
    return RetVal;
}
#endif /* FLS_COMPARE_API == STD_ON */

#if(FLS_SET_MODE_API == STD_ON)
/**
 * @brief     Sets the flash driver's operation mode.
 *
 * @param[in] Mode: MEMIF_MODE_SLOW - Slow read access / normal SPI access
 *                  MEMIF_MODE_FAST - Fast read access / SPI burst access.
 *
 * @return    None
 *
 */
/* SWS_Fls_00258 */
void Fls_SetMode(MemIf_ModeType Mode)
{
#if(FLS_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Fls_ConfigPtr)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_SET_MODE, FLS_E_UNINIT);
    }
    else if (MEMIF_JOB_PENDING == Fls_Job.JobResult)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_SET_MODE, FLS_E_BUSY);
    }
    else
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        switch (Mode)
        {
            case MEMIF_MODE_FAST:
                Fls_MaxRead  = Fls_ConfigPtr->MaxReadFastMode;
                Fls_MaxWrite = Fls_ConfigPtr->MaxWriteFastMode;
                break;

            case MEMIF_MODE_SLOW:
                Fls_MaxRead  = Fls_ConfigPtr->MaxReadNormalMode;
                Fls_MaxWrite = Fls_ConfigPtr->MaxWriteNormalMode;
                break;

            default:
                /*do nothing*/
                break;
        }
    }
}
#endif /* FLS_SET_MODE_API == STD_ON */

#if(FLS_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersioninfoPtr: Pointer to where to store the version information of this module.
 *
 * @return    None
 *
 */
/* SWS_Fls_00259 */
void Fls_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
#if ( FLS_DEV_ERROR_DETECT == STD_ON )
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, FLS_SID_GET_VERSION_INFO, 
                               FLS_E_PARAM_POINTER);
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        VersionInfoPtr->vendorID = (uint16)FLS_VENDOR_ID;
        VersionInfoPtr->moduleID = (uint16)FLS_MODULE_ID;        
        VersionInfoPtr->sw_major_version = (uint8)FLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FLS_SW_PATCH_VERSION;
#if ( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_VERSION_INFO_API == STD_ON */

#if(FLS_BLANK_CHECK_API == STD_ON)
/**
 * @brief     The function Fls_BlankCheck shall verify, whether a given memory area has been erased 
 *            but not (yet) programmed. The function shall limit the maximum number of checked flash
 *            cells per main function cycle to the configured value FlsMaxReadNormalMode or 
 *            FlsMaxReadFastMode respectively. 
 *
 * @param[in] TargetAddress: Address in flash memory from which the blank check should be started
 * @param[in] Length: Number of bytes to be checked for erase pattern
 *
 * @return    Std_ReturnType
 * @retval    E_OK - request for blank checking has been accepted by the module
 * @retval    E_NOT_OK - request for blank checking has not been accepted by the module
 *
 */
/* SWS_Fls_00371 */
Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    Fls_AddressType EndAddr = TargetAddress + Length - 1U;

#if(FLS_DEV_ERROR_DETECT == STD_ON)
	RetVal = Fls_CheckModuleState(FLS_SID_BLANK_CHECK);
	if (E_OK == RetVal)
	{
		RetVal = Fls_CheckStartAddr(FLS_SID_BLANK_CHECK, TargetAddress);
		RetVal |= Fls_CheckEndAddr(FLS_SID_BLANK_CHECK, EndAddr, Length);
	}

	if (E_OK == RetVal)
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
	{
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
#if(FLS_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FLS_MODULE_ID, FLS_INSTANCE, 
                                  FLS_SID_BLANK_CHECK, FLS_E_BUSY);
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_Job.SectorCur = Fls_GetSectorIndex(TargetAddress);
            Fls_Job.SectorEnd = Fls_GetSectorIndex(EndAddr);
            Fls_Job.AddrCur = TargetAddress;
            Fls_Job.AddrEnd = EndAddr;
            Fls_Job.Job = FLS_JOB_BLANK_CHECK;
            Fls_Job.JobResult = MEMIF_JOB_PENDING;
            Fls_Job.AsyncExecutingFlag = (boolean)FALSE;
        }
    }
    
    return RetVal;
}
#endif /* FLS_BLANK_CHECK_API == STD_ON */

/**
 * @brief     Performs the processing of jobs.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
/* SWS_Fls_00255 */
void Fls_MainFunction(void)
{
    MemIf_JobResultType Result = MEMIF_JOB_OK;

    if(NULL_PTR != Fls_ConfigPtr)
    {
        if(MEMIF_JOB_PENDING == Fls_Job.JobResult)
        {
            if(TRUE == Fls_Job.AsyncExecutingFlag)
            {
                Result = Fls_HandleAsyncJob();                
            }
  
            if(Result == MEMIF_JOB_OK)
            {
                Result = Fls_ProcessJobs();
            }

            Fls_CheckJobResult(Result);
        }
    }
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls */

/** @} end of group Fls_Module */
