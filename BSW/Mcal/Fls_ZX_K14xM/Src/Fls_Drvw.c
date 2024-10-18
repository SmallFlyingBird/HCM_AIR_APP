/**************************************************************************************************/
/**
 * @file      : Fls_Drvw.c  
 * @brief     : Fls driver wrapper layer source file
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

/** @addtogroup Fls_Drvw
 *  @brief Flash driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Drvw.h"
#include "Flash_Drv.h"

/** @defgroup Private_MacroDefinition
 *	@{
 */
/* Published information */
#define FLS_DRVW_C_VENDOR_ID                   0x00B3U
#define FLS_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define FLS_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define FLS_DRVW_C_SW_MAJOR_VERSION            1U
#define FLS_DRVW_C_SW_MINOR_VERSION            2U
#define FLS_DRVW_C_SW_PATCH_VERSION            1U

/* Check if current file and Flash_Drv.h are the same vendor */
#if (FLS_DRVW_C_VENDOR_ID != FLASH_DRV_H_VENDOR_ID)
	#error "Vendor ID of Fls_Drvw.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Autosar version */
#if((FLS_DRVW_C_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (FLS_DRVW_C_AR_RELEASE_MINOR_VERSION != FLASH_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (FLS_DRVW_C_AR_RELEASE_REVISION_VERSION != FLASH_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_Drvw.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Software version */
#if((FLS_DRVW_C_SW_MAJOR_VERSION != FLASH_DRV_H_SW_MAJOR_VERSION) || \
    (FLS_DRVW_C_SW_MINOR_VERSION != FLASH_DRV_H_SW_MINOR_VERSION) || \
    (FLS_DRVW_C_SW_PATCH_VERSION != FLASH_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Drvw.c and Flash_Drv.h are different"
#endif

/* Check if current file and Fls_Drvw.h are the same vendor */
#if (FLS_DRVW_C_VENDOR_ID != FLS_DRVW_H_VENDOR_ID)
	#error "Vendor ID of Fls_Drvw.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Autosar version */
#if((FLS_DRVW_C_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
    (FLS_DRVW_C_AR_RELEASE_MINOR_VERSION != FLS_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
    (FLS_DRVW_C_AR_RELEASE_REVISION_VERSION != FLS_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_Drvw.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Software version */
#if((FLS_DRVW_C_SW_MAJOR_VERSION != FLS_DRVW_H_SW_MAJOR_VERSION) || \
    (FLS_DRVW_C_SW_MINOR_VERSION != FLS_DRVW_H_SW_MINOR_VERSION) || \
    (FLS_DRVW_C_SW_PATCH_VERSION != FLS_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Drvw.c and Fls_Drvw.h are different"
#endif
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_VAR_CLEARED_PTR
#include "Fls_MemMap.h"
static const Fls_Drvw_ConfigType * Fls_DrvwConfigPtr;
#define FLS_STOP_SEC_VAR_CLEARED_PTR
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
#define FLS_START_SEC_VAR_CLEARED_BOOLEAN
#include "Fls_MemMap.h"
static boolean Fls_Drvw_Acloaded;
#define FLS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/**
 * @brief Flash Block number of ACErase function
 */
static uint32  FLs_Drvw_AcEraseBlock;
/**
 * @brief Flash Block number of ACWrite function
 */
static uint32  FLs_Drvw_AcWriteBlock;
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
#endif
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
static uint32 Fls_Drvw_GetBlockNumFromAddr(uint32 Address);
#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
static void Fls_Drvw_LoadAC(Fls_Drvw_JobType Job);
static void Fls_Drvw_UnloadAC(Fls_Drvw_JobType Job);
static void Fls_Drvw_CheckLoadAC(Fls_Drvw_JobType Job, uint32 AcBlock, 
                                 Fls_Drvw_AddrType Addr, boolean AsyncFlag);
static void Fls_Drvw_CheckUnloadAC(Fls_Drvw_JobType Job);
#endif
static Fls_Drvw_ResultType Fls_Drvw_TranslateReturnCode(Flash_Drv_ReturnType ReturnCode);
static Fls_Drvw_ResultType Fls_Drvw_HandleEraseStatus(Flash_Drv_ReturnType Ret,
                                                      Fls_Drvw_AddrType PhyAddr, 
                                                      Fls_Drvw_LenType Length);
static Fls_Drvw_ResultType Fls_Drvw_HandleWriteStatus(Flash_Drv_ReturnType Ret,
		                                              Fls_Drvw_AddrType PhyAddr, 
                                                      const uint8 *DataSrcPtr, 
                                                      Fls_Drvw_LenType Length);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/**
 * @brief      Get flash block number from address
 *
 * @param[in]  Address: the address
 *
 * @return    the block number
 * @retval    0: the address is invalid and not in any flash block
 * @retval    1: PFLASH block
 * @retval    2: DFLASH block
 *
 */ 
static uint32 Fls_Drvw_GetBlockNumFromAddr(uint32 Address)
{
    return Flash_Drv_GetBlockNumFromAddr(Address);
}

/**
 * @brief     Translate the return code from Flash_Drv_ReturnType into Fls_Drvw_ResultType. It is
 *            called by sector operation functions like Fls_Drvw_ReadSector(), 
 *            Fls_Drvw_CompareSector(),Fls_Drvw_BlankCheckSector, Fls_Drvw_EraseSector(), 
 *            Fls_Drvw_WriteSector().
 *
 * @param[in] ReturnCode: the return code to be tanslated
 * 
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_COMPARE
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_HW_FAIL
 * @retval    FLS_DRVW_E_CMD_ABORTED
 * @retval    FLS_DRVW_E_FAILED
 */
static Fls_Drvw_ResultType Fls_Drvw_TranslateReturnCode(Flash_Drv_ReturnType ReturnCode)
{
    Fls_Drvw_ResultType Res;

    switch(ReturnCode)
    {
        case FLASH_DRV_SUCCESS:
            Res = FLS_DRVW_E_OK;
            break;

        case FLASH_DRV_BUSY:
            /* the internal flash should not be busy when sector operation functions are called
            one possible reason is that the last operation is time-out, that is a hardware issue */
            Res = FLS_DRVW_E_BUSY;
            break;

        case FLASH_DRV_ERR_BLANK_CHECK:
			Res = FLS_DRVW_E_BLANK_CHECK;
			break;
				
        case FLASH_DRV_ERR_COMPARE:
			Res = FLS_DRVW_E_COMPARE;
			break;
        
        case FLASH_DRV_ERR_TIMEOUT:
            Res = FLS_DRVW_E_TIMEOUT;
            break;
		
        case FLASH_DRV_ERR_HW_FAIL:
            Res = FLS_DRVW_E_HW_FAIL;
            break;

		case FLASH_DRV_CMD_ABORTED:
            Res = FLS_DRVW_E_CMD_ABORTED;
            break;

        default:
            Res = FLS_DRVW_E_FAILED;
            break;
    }

    return Res;
}

#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
/**
 * @brief     Load the access code into SRAM
 *
 * @param[in] Job: the current job
 *
 * @return    None
 */
static void Fls_Drvw_LoadAC(Fls_Drvw_JobType Job)
{
    const uint32 *RomPtr;
    uint32 *RamPtr;
    uint32 AcWordSize;
    uint32 Cnt;

    if (FLS_DRVW_JOB_ERASE == Job)
    {
        RomPtr = (const uint32 *)(&Fls_Drvw_AcEraseRomStart); 
        /* MISRA2012 Rule-11.1 violation: Convert a pointer to function to an integral value, 
        no side effects forseen by violating this rule */
        /* MISRA2012 Rule-11.4 violation: Convert an integral value to a pointer to object, 
        no side effects forseen by violating this rule */  
        RamPtr = (uint32*)((uint32)(Fls_DrvwConfigPtr->AcErasePtr));
        /* MISRA2012 Rule-11.4 violation: Convert a pointer to object to an integral value, 
        no side effects forseen by violating this rule */   
        AcWordSize = ((uint32)(&Fls_Drvw_AcEraseSize) + 3U)/4U ;
    }
    else
    {
        RomPtr = (const uint32 *)(&Fls_Drvw_AcWriteRomStart);
        /* MISRA2012 Rule-11.1 violation: Convert a pointer to function to an integral value, 
        no side effects forseen by violating this rule */
        /* MISRA2012 Rule-11.4 violation: Convert an integral value to a pointer to object, 
        no side effects forseen by violating this rule */ 
        RamPtr = (uint32*)((uint32)(Fls_DrvwConfigPtr->AcWritePtr));
        /* MISRA2012 Rule-11.4 violation: Convert a pointer to object to an integral value, 
        no side effects forseen by violating this rule */
        AcWordSize = ((uint32)(&Fls_Drvw_AcWriteSize) + 3U)/4U;
    }

    for (Cnt = 0U; Cnt < AcWordSize; Cnt += 1U)
    {
        RamPtr[Cnt] = RomPtr[Cnt];
    }
}

/**
 * @brief     Unload the access code from SRAM
 *
 * @param[in] Job: the current job
 *
 * @return    None
 */
static void Fls_Drvw_UnloadAC(Fls_Drvw_JobType Job)
{
    uint32 *RamPtr;
    uint32 AcWordSize;
    uint32 Cnt;

    if (FLS_DRVW_JOB_ERASE == Job)
    {
        /* MISRA2012 Rule-11.1 violation: Convert a pointer to function to an integral value, 
        no side effects forseen by violating this rule */
        /* MISRA2012 Rule-11.4 violation: Convert an integral value to a pointer to object, 
        no side effects forseen by violating this rule */ 
        RamPtr = (uint32*)((uint32)(Fls_DrvwConfigPtr->AcErasePtr));
        /* MISRA2012 Rule-11.4 violation: Convert a pointer to object to an integral value, 
        no side effects forseen by violating this rule */
        AcWordSize = ((uint32)(&Fls_Drvw_AcEraseSize) + 3U)/4U ;
    }
    else
    {
        /* MISRA2012 Rule-11.1 violation: Convert a pointer to function to an integral value, 
        no side effects forseen by violating this rule */
        /* MISRA2012 Rule-11.4 violation: Convert an integral value to a pointer to object, 
        no side effects forseen by violating this rule */ 
        RamPtr = (uint32*)((uint32)(Fls_DrvwConfigPtr->AcWritePtr));
        /* MISRA2012 Rule-11.4 violation: Convert a pointer to object to an integral value, 
        no side effects forseen by violating this rule */
        AcWordSize = ((uint32)(&Fls_Drvw_AcWriteSize) + 3U)/4U;
    }

    for (Cnt = 0U; Cnt < AcWordSize; Cnt += 1U)
    {
        RamPtr[Cnt] =  0U;
    }
}

/**
 * @brief     Check if Access code need to be loaded from flash to SRAM, if yes, access code will be
 *            loaded
 * @param[in] Job: the current job
 * @param[in] AcBlock: the flash block number where the access code is
 * @param[in] Addr: the address where the flash need to be written or erased
 * @param[in] AsyncFlag: it indicates if the operation is in asynchronous mode
 *
 * @return    None
 */
static void Fls_Drvw_CheckLoadAC(Fls_Drvw_JobType Job, uint32 AcBlock, 
                                 Fls_Drvw_AddrType Addr, boolean AsyncFlag)
{
    uint32 AddrBlock;

    if(AsyncFlag == FALSE)
    {
        AddrBlock = Fls_Drvw_GetBlockNumFromAddr(Addr);

        if(AddrBlock == AcBlock)
        {
            Fls_Drvw_LoadAC(Job);
            Fls_Drvw_Acloaded = (boolean)TRUE;
        }
    }    
}

/**
 * @brief     Check if Access code has been loaded from flash to SRAM, if yes, unload the access 
 *            code 
 *
 * @param[in] Job: the current job
 *
 * @return    None
 */
static void Fls_Drvw_CheckUnloadAC(Fls_Drvw_JobType Job)
{
    if (TRUE == Fls_Drvw_Acloaded)
    {
        Fls_Drvw_UnloadAC(Job);
        Fls_Drvw_Acloaded = (boolean)FALSE;
    }
}
#endif /* STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START */

/**
 * @brief     Handle the erase status of internal flash
 *
 * @param[in] Ret: erase status from internal flash
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] Length: the length of data in byte
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * 
 */
static Fls_Drvw_ResultType Fls_Drvw_HandleEraseStatus(Flash_Drv_ReturnType Ret,
                                                 Fls_Drvw_AddrType PhyAddr, Fls_Drvw_LenType Length)
{
    if(Ret != FLASH_DRV_BUSY)
    {
#if(FLS_DRVW_ERASE_VERIFICATION_ENABLED == STD_ON)
        if(Ret == FLASH_DRV_SUCCESS)
        {
            Ret = Flash_Drv_CheckBlank(PhyAddr, Length);
        }
#endif /* FLS_DRVW_ERASE_VERIFICATION_ENABLED == STD_ON*/
    }

    return Fls_Drvw_TranslateReturnCode(Ret);
}

/**
 * @brief     Handle the write status of internal flash
 *
 * @param[in] Ret: write status from internal flash
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] DataSrcPtr: Pointer to the source data buffer
 * @param[in] Length: the length of data in byte
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_BUSY   
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_COMPARE
 * 
 */
static Fls_Drvw_ResultType Fls_Drvw_HandleWriteStatus(Flash_Drv_ReturnType Ret,
		                Fls_Drvw_AddrType PhyAddr, const uint8 *DataSrcPtr, Fls_Drvw_LenType Length)
{
    if(Ret != FLASH_DRV_BUSY)
    {
#if(FLS_DRVW_WRITE_VERIFICATION_ENABLED == STD_ON)
        if(Ret == FLASH_DRV_SUCCESS)
        {
            Ret = Flash_Drv_Compare(PhyAddr, DataSrcPtr, Length);
        }
#endif /* FLS_DRVW_WRITE_VERIFICATION_ENABLED == STD_ON*/
    }

    return Fls_Drvw_TranslateReturnCode(Ret);
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/**
 * @brief     Initialize flash 
 *
 * @param[in] ConfigPtr: Pointer to driver wrapper configuration set parameters.
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_HW_FAIL
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_PARAM_DATA
 *
 */
Fls_Drvw_ResultType Fls_Drvw_Init(const Fls_Drvw_ConfigType * ConfigPtr)
{
    Flash_Drv_ReturnType Ret;
	Fls_Drvw_ResultType Res;

    Fls_DrvwConfigPtr = ConfigPtr;
    
    Ret = Flash_Drv_Init(Fls_DrvwConfigPtr->DriverConfigSetPtr);
    Res = Fls_Drvw_TranslateReturnCode(Ret);
	
#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
    /* MISRA2012 Rule-11.4 violation: Convert a pointer to object to an integral value, 
    no side effects forseen by violating this rule.
    The following two lines of code also violate this rule with the same reason. */
	FLs_Drvw_AcEraseBlock = Fls_Drvw_GetBlockNumFromAddr((uint32)(&Fls_Drvw_AcEraseRomStart));
	FLs_Drvw_AcWriteBlock = Fls_Drvw_GetBlockNumFromAddr((uint32)(&Fls_Drvw_AcWriteRomStart));

	if(Res == FLS_DRVW_E_OK)
	{		
	    if((FLs_Drvw_AcEraseBlock == 0U) || (FLs_Drvw_AcWriteBlock == 0U))
	    {
			Res = FLS_DRVW_E_PARAM_DATA;
	    }
	}
#endif

	return Res;
}

#if(FLS_DRVW_CANCEL_API == STD_ON)
/**
 * @brief     Cancel flash job 
 *
 * @param[in] Job: the current job
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_CMD_ABORTED
 * @retval    FLS_DRVW_E_TIMEOUT
 *
 */
Fls_Drvw_ResultType Fls_Drvw_Cancel(Fls_Drvw_JobType Job)
{
    Flash_Drv_ReturnType Ret;

    /* cancel the internal flash command if some flash command is executing */
    Ret = Flash_Drv_Abort();

#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
	Fls_Drvw_CheckUnloadAC(Job);
#endif /* #if (STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START) */

	return Fls_Drvw_TranslateReturnCode(Ret);
}
#endif /* FLS_DRVW_CANCEL_API == STD_ON */

/**
 * @brief     Handle asynchronous erase job 
 *
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] Length: the length of data in byte
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 *
 */
Fls_Drvw_ResultType Fls_Drvw_HandleAsyncEraseJob(Fls_Drvw_AddrType PhyAddr, Fls_Drvw_LenType Length)
{
    Flash_Drv_ReturnType Ret;
	Fls_Drvw_ResultType Res = FLS_DRVW_E_FAILED;

    Ret = Flash_Drv_PollEraseWriteStatus();

    Res = Fls_Drvw_HandleEraseStatus(Ret, PhyAddr, Length);

    return Res;
}

/**
 * @brief     Handle asynchronous write job 
 *
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] DataSrcPtr: Pointer to the source data buffer
 * @param[in] Length: the length of data in byte
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_COMPARE
 *
 */
Fls_Drvw_ResultType Fls_Drvw_HandleAsyncWriteJob(Fls_Drvw_AddrType PhyAddr, 
                                                  const uint8 * DataSrcPtr, Fls_Drvw_LenType Length)
{
    Flash_Drv_ReturnType Ret;
	Fls_Drvw_ResultType Res = FLS_DRVW_E_FAILED;

    Ret = Flash_Drv_PollEraseWriteStatus();

    Res = Fls_Drvw_HandleWriteStatus(Ret, PhyAddr, DataSrcPtr, Length);

    return Res;
}

/**
 * @brief      Read flash data from a logical sector
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be read
 * @param[in]  DataDestPtr: Pointer to the destination buffer where to store the readout data
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_FAILED
 *
 */
Fls_Drvw_ResultType Fls_Drvw_ReadSector(Fls_Drvw_AddrType PhyAddr, 
                                        const Fls_Drvw_LenType Len, 
                                        uint8 const * DataDestPtr)
{
    Flash_Drv_ReturnType Ret;

    Ret = Flash_Drv_Read(PhyAddr, DataDestPtr, Len);

    return Fls_Drvw_TranslateReturnCode(Ret);
}

#if(FLS_DRVW_COMPARE_API == STD_ON)
/**
 * @brief      Compare flash data in a logical sector with the data in a buffer
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be read
 * @param[in]  DataSrcPtr: Pointer to a source buffer where the compare data is stored
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_COMPARE
 * @retval    FLS_DRVW_E_FAILED
 *
 */
Fls_Drvw_ResultType Fls_Drvw_CompareSector(Fls_Drvw_AddrType PhyAddr, 
                                           const Fls_Drvw_LenType Len, 
                                           const uint8 * DataSrcPtr)
{
    Flash_Drv_ReturnType Ret;

    Ret = Flash_Drv_Compare(PhyAddr, DataSrcPtr, Len);

    return Fls_Drvw_TranslateReturnCode(Ret);
}
#endif

#if(FLS_DRVW_BLANK_CHECK_API == STD_ON)
/**
 * @brief      Check if the flash data is equal to the erased value
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be read
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_FAILED
 *
 */
Fls_Drvw_ResultType Fls_Drvw_BlankCheckSector(Fls_Drvw_AddrType PhyAddr, const Fls_Drvw_LenType Len)
{
    Flash_Drv_ReturnType Ret;

    Ret = Flash_Drv_CheckBlank(PhyAddr, Len);

    return Fls_Drvw_TranslateReturnCode(Ret);
}
#endif

/**
 * @brief     Erase a physical sector in the current working logical sector
 *
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] AsyncFlag: it indicates if the operation is in asynchronous mode
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_PENDING
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_TIMEOUT
 *
 */
Fls_Drvw_ResultType Fls_Drvw_EraseSector(Fls_Drvw_AddrType PhyAddr, const boolean AsyncFlag)
{
    Flash_Drv_ReturnType Ret;
    Flash_Drv_CmdActionType CmdAct;
    Fls_Drvw_ResultType Res;

    CmdAct.AsyncFlag = AsyncFlag;
    CmdAct.CallBack = Fls_DrvwConfigPtr->AcCallbackPtr;
    CmdAct.AcFunc = NULL_PTR;

#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
    Fls_Drvw_CheckLoadAC(FLS_DRVW_JOB_ERASE, FLs_Drvw_AcEraseBlock, PhyAddr, AsyncFlag);
    if(Fls_Drvw_Acloaded  != 0U)
    {
        CmdAct.AcFunc = Fls_DrvwConfigPtr->AcErasePtr;
    }
#endif /* #if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START) */

    Ret = Flash_Drv_EraseSector(PhyAddr, &CmdAct);

    if(Ret != FLASH_DRV_SUCCESS)
    {
        Res = Fls_Drvw_TranslateReturnCode(Ret);
    }
    else
    {
        if(AsyncFlag == 0U)
        {
#if(FLS_DRVW_ERASE_VERIFICATION_ENABLED == STD_ON)
            Ret = Flash_Drv_CheckBlank(PhyAddr, FLASH_DRV_SECTOR_SIZE);
#endif /* FLS_DRVW_ERASE_VERIFICATION_ENABLED == STD_ON*/
            Res = Fls_Drvw_TranslateReturnCode(Ret);
        }
        else
        {
            /* for Async mode */
            Res = FLS_DRVW_E_PENDING;
        }
    }
	
#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
	Fls_Drvw_CheckUnloadAC(FLS_DRVW_JOB_ERASE);
#endif /* #if (STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START) */

    return Res;
}

/**
 * @brief      Write data in the current working logical sector
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be written
 * @param[in]  DataSrcPtr: Pointer to the data buffer that will be written into flash
 * @param[in]  AsyncFlag: it indicates if the operation is in asynchronous mode
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_COMPARE
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_PENDING
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_TIMEOUT
 *
 */
Fls_Drvw_ResultType Fls_Drvw_WriteSector(Fls_Drvw_AddrType PhyAddr,
                                                 Fls_Drvw_LenType Len, 
                                                 const uint8 * DataSrcPtr, 
                                                 const boolean AsyncFlag )
{
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
    Flash_Drv_CmdActionType CmdAct;
    Fls_Drvw_ResultType Res;

    CmdAct.AsyncFlag = AsyncFlag;
    CmdAct.CallBack = Fls_DrvwConfigPtr->AcCallbackPtr;
    CmdAct.AcFunc = NULL_PTR;
	
#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
	Fls_Drvw_CheckLoadAC(FLS_DRVW_JOB_WRITE, FLs_Drvw_AcWriteBlock, PhyAddr, AsyncFlag);
	if(Fls_Drvw_Acloaded  != 0U)
	{
		CmdAct.AcFunc = Fls_DrvwConfigPtr->AcWritePtr;
	}
#endif /* #if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START) */

#if(FLS_DRVW_ERASE_VERIFICATION_ENABLED == STD_ON)
    Ret = Flash_Drv_CheckBlank(PhyAddr, Len);
    
    if(Ret == FLASH_DRV_SUCCESS)
#endif /* FLS_DRVW_ERASE_VERIFICATION_ENABLED == STD_ON */
    {
        Ret = Flash_Drv_Write(PhyAddr, Len, DataSrcPtr, &CmdAct);
    }

    if(Ret != FLASH_DRV_SUCCESS)
    {
        Res = Fls_Drvw_TranslateReturnCode(Ret);
    }
    else
    {
        if(AsyncFlag == 0U)
        {
#if(FLS_DRVW_WRITE_VERIFICATION_ENABLED == STD_ON)
            Ret = Flash_Drv_Compare(PhyAddr, DataSrcPtr, Len);
#endif /* FLS_DRVW_WRITE_VERIFICATION_ENABLED == STD_ON*/
            Res = Fls_Drvw_TranslateReturnCode(Ret);
        }
        else
        {
            /* for Async mode */
            Res = FLS_DRVW_E_PENDING;
        }
    }

#if(STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START)
	Fls_Drvw_CheckUnloadAC(FLS_DRVW_JOB_WRITE);
#endif /* #if (STD_ON == FLS_DRVW_AC_LOAD_ON_JOB_START) */

    return Res;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls_Drvw */

/** @} end of group Fls_Module */
