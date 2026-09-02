/**
 * @file    Fls_Lld.c
 * @version
 *
 * @brief   AUTOSAR Fls Driver Interface
 * @details API implementation for FLS driver
 *
 * @addtogroup FLS_DRIVER
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
 * PRQA S 0306 Rule 11.4: A conversion should not be performed between a pointer to object and
 *                        an integer type.
 *
 * PRQA S 3305 Rule 11.3: A cast shall not be performed between a pointer to object type and a
 *                        pointer to a different object type
 *
 * PRQA S 3006 Dir 4.3: Assembly language shall be encapsulated and isolated
 *
 * PRQA S 1006 Rule 1.2:  Language extensions should not be used.
 */



/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Fls.h"
#include "Fls_Lld.h"
#include "Fls_Lld_Reg.h"
#include "Det.h"
#include "SchM_Fls.h"
#include "OsIf.h"
#include "Platform_CfgDefines.h"
#include "Platform.h"
#ifndef  UNIT_TEST
#if (PLATFORM_MPU_CFG == STD_ON)
#if defined(CPU_YTM32B1ME0)||defined (CPU_YTM32B1MD1)||defined(CPU_YTM32B1MC0)
#include "core_cm33.h"
#elif defined(CPU_YTM32B1HA0)
#include "core_cm7.h"
#else
#endif
#endif
#endif



/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_DRV_VENDOR_ID_C                      (180)
#define FLS_DRV_AR_RELEASE_MAJOR_VERSION_C       (4)
#define FLS_DRV_AR_RELEASE_MINOR_VERSION_C       (4)
#define FLS_DRV_AR_RELEASE_REVISION_VERSION_C    (0)
#define FLS_DRV_SW_MAJOR_VERSION_C               (2)
#define FLS_DRV_SW_MINOR_VERSION_C               (3)
#define FLS_DRV_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FLS header file are of the same vendor */
#if (FLS_DRV_VENDOR_ID_C != FLS_VENDOR_ID)
#error "Fls_Lld.c and Fls.h have different vendor ids"
#endif

/* Check if source file and FLS header file are of the same Autosar version */
#if ((FLS_DRV_AR_RELEASE_MAJOR_VERSION_C != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_DRV_AR_RELEASE_MINOR_VERSION_C != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_DRV_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls_Lld.c and Fls.h are different"
#endif

/* Check if source file and FLS header file are of the same Software version */
#if ((FLS_DRV_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_DRV_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_DRV_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fls_Lld.c and Fls.h are different"
#endif

/* Check if source file and FLS register header file are of the same vendor */
#if (FLS_DRV_VENDOR_ID_C != FLS_LLD_REG_VENDOR_ID)
#error "Fls_Lld.c and Fls_Lld_Reg.h have different vendor ids"
#endif

/* Check if source file and FLS register header file are of the same Autosar version */
#if ((FLS_DRV_AR_RELEASE_MAJOR_VERSION_C != FLS_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_DRV_AR_RELEASE_MINOR_VERSION_C != FLS_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
     (FLS_DRV_AR_RELEASE_REVISION_VERSION_C != FLS_LLD_REG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls_Lld.c and Fls_Lld_Reg.h are different"
#endif

/* Check if source file and FLS register header file are of the same Software version */
#if ((FLS_DRV_SW_MAJOR_VERSION_C != FLS_LLD_REG_SW_MAJOR_VERSION) || \
     (FLS_DRV_SW_MINOR_VERSION_C != FLS_LLD_REG_SW_MINOR_VERSION) || \
     (FLS_DRV_SW_PATCH_VERSION_C != FLS_LLD_REG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fls_Lld.c and Fls_Lld_Reg.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define FLS_BLANK_DBYTE_VALUE               (0xFFFFU)

#define FLS_PC_TO_MSP_OFFSET                 (6U)
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

extern volatile MemIf_JobResultType Fls_LLDJobResult;          /* implicit zero initialization: MEMIF_JOB_OK */
extern Fls_Lld_JobType Fls_LLDJob;    /* implicit zero initialization: FLASH_JOB_NONE */
extern const Fls_ConfigType *Fls_ConfigPtr;
extern Fls_JobStateType Fls_JobState;

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
#define FLS_START_SEC_VAR_INIT_8
#include "Fls_MemMap.h"
FLS_VAR static volatile boolean Fls_Lld_UncorrectableEccFlag = FALSE;
#define FLS_STOP_SEC_VAR_INIT_8
#include "Fls_MemMap.h"
#endif

#define FLS_START_SEC_VAR_INIT_16
#include "Fls_MemMap.h"
FLS_VAR static Fls_Lld_StatusType Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR;

FLS_VAR static Fls_Lld_StatusType Fls_Lld_eWriteStatus = STATUS_FTFC_FLS_IP_ERROR;

FLS_VAR static Fls_Lld_StatusType Fls_Lld_eEraseStatus = STATUS_FTFC_FLS_IP_ERROR;
#define FLS_STOP_SEC_VAR_INIT_16
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE == STD_ON)
FLS_VAR static uint32 Fls_Lld_u32ErasedSectorAddress;
#endif
#if (STD_ON == FLS_WRITE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE == STD_ON)
FLS_VAR static uint32 Fls_Lld_u32WritedAddress;
FLS_VAR static uint32 Fls_Lld_u32WritedLength;
FLS_VAR static const uint8 *Fls_Lld_pWritedData;
#endif

#if(STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED)
FLS_VAR static uint32 Fls_Lld_u32TimeoutCounter;
#endif
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static uint32 Fls_Lld_ComputeReadSize(uint32 SrcAddress, uint32 DesAddress, uint32 ByteRemain);
static Fls_Lld_StatusType Fls_Lld_SectorWriteStatus(void);
static Fls_Lld_StatusType Fls_Lld_SectorEraseStatus(void);
static Fls_Lld_StatusType Fls_Lld_GetCtrlStatus(void);
static void Fls_Lld_BlankCheck(Fls_AddressType StartAddress, Fls_LengthType Length);
static void Fls_Lld_CompareCheck(uint32 CheckAddress, const uint8 *DataPtr, uint32 CheckSize);

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
ISR(EFM_Ecc_IRQHandler);
#endif /*(FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)*/
/*==================================================================================================
 *                                     LOCAL FUNCTION
==================================================================================================*/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
#if (PLATFORM_ENABLE_CACHE == STD_ON)
FLS_FUNC LOCAL_INLINE void Fls_Lld_CacheInvalidate(uint32 StartAddress, uint32 Length)
{
    SCB_InvalidateDCache_by_Addr((uint32 *)StartAddress, (sint32)Length);
}
#endif

#if (FLS_WEBIT_AVAILABLE==STD_ON)
/**
 * @brief Enable Flash write operation
 * @details This function will enable the Flash write by set WE in EFM_CTRL
 * @return void
 */
/* MR12 DIR 4.3 VIOLATION: The function 'Fls_Lld_SetWE' contains a mixture of in-line assembler statements and C statements.
* In this specific case, due to the need for Low-level hardware access or specific performance requirements,
* we had to use inline assembly code alongside C statements, thus, couldn't adhere to this rule.
*/
FLS_FUNC LOCAL_INLINE void Fls_Lld_SetWE(void)/* PRQA S 3006 */
{
    EFM->CTRL |= EFM_CTRL_WE_MASK;
    /* MR12 RULE 1.2 VIOLATION: This line uses the __ASM() macro for inline assembly which is not a part of standard C.
     * In this specific case, executing a 'isb and dsb' instruction for ensuring all previous instructions and data have been
     *completed before continuing, hence couldn't adhere to the rule 1.2.
     */
#ifndef UNIT_TEST
    __ASM("ISB");/* PRQA S 1006 */
    __ASM("DSB");/* PRQA S 1006 */
#endif
}
/**
 * @brief Disable Flash write operation
 * @details This function will disable the Flash write by reset WE in EFM_CTRL
 * @return void
 */
/* MR12 DIR 4.3 VIOLATION: The function 'Fls_Lld_ClearWE' contains a mixture of in-line assembler statements and C statements.
 * In this specific case, due to the need for Low-level hardware access or specific performance requirements,
 * we had to use inline assembly code alongside C statements, thus, couldn't adhere to this rule.
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_ClearWE(void)/* PRQA S 3006 */
{
    /* MR12 RULE 1.2 VIOLATION: This line uses the __ASM() macro for inline assembly which is not a part of standard C.
     * In this specific case, executing a 'isb and dsb' instruction for ensuring all previous instructions and data have been
     *completed before continuing, hence couldn't adhere to the rule 1.2.
     */
#ifndef UNIT_TEST
    __ASM("ISB");/* PRQA S 1006 */
    __ASM("DSB");/* PRQA S 1006 */
#endif
    EFM->CTRL &= ~EFM_CTRL_WE_MASK;
}

/**
 * @brief Wait WE bit is set
 * @details This function will confirm WE bit is set and the Fls write is enable
 * @param TimeOut
 * @return FLS_FUNC
 */
FLS_FUNC static boolean Fls_Lld_JudgeSetAddr(uint16 TimeOut)
{
    uint16 TimeOutCnt = TimeOut;
    boolean TempRet = FALSE;
    while (0U != TimeOutCnt)
    {
        if (0U != (EFM->STS & FLS_ADDR_SELECTED_FLAG_MASK))
        {
            TempRet = TRUE;
            break;
        }
        /*GCOVR_EXCL_START*/
        else
        {
            /*The integration test can't convered, this branch can be accessed only when the EFM hardware fails*/
            --TimeOutCnt;
        }
        /*GCOVR_EXCL_STOP*/
    }
    return TempRet;
}
#endif

/**
 * @brief            Get flash hardware status
 * @details          This function will read flash hardware status
 * @return           void
 */
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_CheckIdle(void)
{
    return ((boolean)((EFM->STS & EFM_STS_IDLE_MASK) >> EFM_STS_IDLE_SHIFT));
}

/**
 * @brief            Get flash hardware access error status
 * @details          This function will read flash hardware access error status
 * @return           boolean
 */
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_CheckErrorFlag(void)
{
    boolean TempRet = FALSE;
    if (0U != (EFM->STS & FLS_ERR_FLAGS_MASK))
    {
        TempRet = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return TempRet;
}

/**
 * @brief            Clear flash hardware access error status
 * @details          This function will clear flash hardware access error status
 * @return           void
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_ClearErrorFlag(void)
{
    EFM->STS = FLS_ERR_FLAGS_MASK;
}

/**
 * @brief            clear flash STS register
 * @details          This function will clear flash STS register
 * @return           void
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_ClearRegSTS(void)
{
    EFM->STS =  FLS_ERR_FLAGS_MASK | EFM_STS_DONE_MASK;
}

/**
 * @brief            unlock flash CMD register
 * @details          This function will unlock flash CMD register
 * @return           void
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_UnLockCMD(void)
{
    EFM->CMD_UNLOCK = FLS_EFM_CMDUNLOCK_KEY;
}

/**
 * @brief            Load the command to flash CMD register
 * @details          This function will load the command to flash CMD register without waiting for the command to finish
 * @param[in]        Command    flash command
 * @return           void
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_LoadCommand(uint8 Command)
{
    EFM->CMD = Command;
}

/**
 * @brief            Load the address to flash NVR_ADDR register
 * @details          This function will load the address to flash NVR_ADDR register
 * @param[in]        Address    flash address
 * @return           void
*/

FLS_FUNC LOCAL_INLINE void Fls_Lld_LoadNvrAddr(uint32 Address)
{
#if (FLS_WEBIT_AVAILABLE==STD_ON)
    Fls_Lld_SetWE();
#endif
#if defined(CPU_YTM32B1ME0)
    EFM->CTRL &= ~EFM_CTRL_AES_KEY_SEL_MASK;
    EFM->CTRL |= EFM_CTRL_AES_KEY_SEL((Address - FLS_NVR_FLASH_BASE_ADDR) / (FLS_NVR_FLASH_PAGE_SIZE));
#elif defined(CPU_YTM32B1MD1)
    EFM->NVR_ADDR = Address;
#elif defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)
    /* MR12 Rule 11.4 VIOLATION: In this specific case, the data address need use to
     *                           caculate aligning, it couldn't adhere to M3CM Rule-11.4.
     */
    *((uint32 *)Address) = 0x01234567U;/*PRQA S 0306*/
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
#if (FLS_WEBIT_AVAILABLE == STD_ON)
    (void)Fls_Lld_JudgeSetAddr(0x1000U);
    Fls_Lld_ClearWE();
#endif
}

/**
 * @brief            Nop command operation
 * @details          This function will load a nop command to flash CMD register
 * @return           void
*/
FLS_FUNC LOCAL_INLINE void Fls_Lld_EFMNopCommand(void)
{
    EFM->CMD = 0U;
    EFM->STS = FLS_ERR_FLAGS_MASK;
}

/**
 * @brief           Read flash one bit ecc error flag
 * @details         This function will read flash one bit ecc error flags
 * @return          uint8
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_GetUnrecoverr(void)
{
#if defined (CPU_YTM32B1ME0) || defined (CPU_YTM32B1MD1)|| defined (CPU_YTM32B1MC0)
    return ((boolean)((EFM->STS & EFM_STS_UNRECOVERR_MASK) >> EFM_STS_UNRECOVERR_SHIFT));
#elif defined (CPU_YTM32B1HA0)
    return ((boolean)((EFM->STS & EFM_STS_CI_UNRECOVERR_MASK) >> EFM_STS_CI_UNRECOVERR_SHIFT));
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
}

/**
 * @brief           Read flash two bit ecc error flag
 * @details         This function will read flash two bit ecc error flags
 * @return          uint8
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_GetRecoverr(void)
{
#if defined (CPU_YTM32B1ME0) || defined (CPU_YTM32B1MD1)|| defined (CPU_YTM32B1MC0)
    return ((boolean)((EFM->STS & EFM_STS_RECOVERR_MASK) >> EFM_STS_RECOVERR_SHIFT));
#elif defined (CPU_YTM32B1HA0)
    return ((boolean)((EFM->STS & EFM_STS_CI_RECOVERR_MASK) >> EFM_STS_CI_RECOVERR_SHIFT));
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
}

/**
 * @brief   Clear flash one bit ecc error flag
 * @details This function will clear flash ecc error flags
 * @return  void
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_ClearUnrecoverr(void)
{
#if defined (CPU_YTM32B1ME0) || defined (CPU_YTM32B1MD1)|| defined (CPU_YTM32B1MC0)
    EFM->STS = EFM_STS_UNRECOVERR_MASK;
#elif defined (CPU_YTM32B1HA0)
    EFM->STS = EFM_STS_CI_UNRECOVERR_MASK;
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
}

#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
/**
 * @brief   Clear flash one bit ecc error flag
 * @details This function will clear flash ecc error flags
 * @return  void
 */
FLS_FUNC LOCAL_INLINE void Fls_Lld_ClearRecoverr(void)
{
#if defined (CPU_YTM32B1ME0) || defined (CPU_YTM32B1MD1)|| defined (CPU_YTM32B1MC0)
    EFM->STS = EFM_STS_RECOVERR_MASK;
#elif defined (CPU_YTM32B1HA0)
    EFM->STS = EFM_STS_CI_RECOVERR_MASK;
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
}
#endif
/**
 * @file  Read flash ecc error address
 * @details This function will read flash ecc error address
 * @return uint32
 *
 */
FLS_FUNC LOCAL_INLINE uint32 Fls_Lld_GetEccErrorAddrReg(void)
{
#if defined (CPU_YTM32B1HA0)
    return (EFM->ECC_ERR_ADDR);
#elif defined (CPU_YTM32B1MC0)
    return (EFM->ECCERR_ADDR);
#else
    return (EFM->ERR_ADDR);
#endif
}

/**
 * @brief           Set flash protect register
 * @details         This function will set flash protect register
 * @return          void
*/
FLS_FUNC LOCAL_INLINE void Fls_Lld_SetProtectReg(uint8 ChnIndex, uint32 ProtectReg)
{
    EFM->ADDR_PROT[ChnIndex] = ProtectReg;
}

#if (FLS_QUICK_ERASE_FEATURE_ENABLE==STD_ON)
#if defined (CPU_YTM32B1MC0)
FLS_FUNC LOCAL_INLINE void Fls_Lld_SetTime2Reg(uint16 EraseTime)
{
    EFM->TIMING2 = EFM_TIMING2_TERASE(EraseTime);
}
#endif

#if defined (EFM_CTRL_RETRY_CFG_MASK)
FLS_FUNC LOCAL_INLINE void Fls_Lld_SetRetryCfg(void)
{
    uint32 Temp;
    Temp = EFM->CTRL;
    Temp &= ~EFM_CTRL_RETRY_CFG_MASK;
    Temp |= EFM_CTRL_RETRY_CFG(0x07);
    EFM->CTRL = Temp;
}
#endif
#endif
/**
 * @brief  Enable or disable the UNRECOVERRIE interrupt
 *
 * @param[in] Enable
 * @return void
 */
FLS_FUNC static void Fls_Lld_SetUNRECOVERRIE(boolean Enable)
{
    if (TRUE == Enable)
    {
        EFM->CTRL |= EFM_CTRL_UNRECOVERRIE_MASK;
    }
    else
    {
        EFM->CTRL &= ~EFM_CTRL_UNRECOVERRIE_MASK;
    }
}

/**
 * @brief Enable or disable the RECOVERRIE interrupt
 *
 * @param[in] Enable
 * @return void
 */
FLS_FUNC static void Fls_Lld_SetRECOVERRIE(boolean Enable)
{
    if (TRUE == Enable)
    {
        EFM->CTRL |= EFM_CTRL_RECOVERRIE_MASK;
    }
    else
    {
        EFM->CTRL &= ~EFM_CTRL_RECOVERRIE_MASK;
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


#define FLS_START_SEC_RAMCODE
#include "Fls_MemMap.h"
/**
 * @brief            operate flash in sync mode
 * @details          This function will load the command to flash CMD register and wait for the command to finish
 * @param[in]        command    flash command
 * @return           void
*/
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_LoadCommandSync(uint8 Command)
{
    Fls_Lld_StatusType TempStatus = STATUS_FTFC_FLS_IP_SUCCESS;
#ifndef UNIT_TEST
    __ASM("ISB");/* PRQA S 1006 */
    __ASM("DSB");/* PRQA S 1006 */
#endif
    EFM->CMD = Command;
#if(STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED)
    uint32 Timeout = 0U;
#if defined (CPU_YTM32B1HA0)
    if (((Command & FLS_PAGE_PROGRAM64_COMMAND_CODE) != 0U) || ((Command & FLS_PAGE_PROGRAM256_COMMAND_CODE) != 0U))
#else
    if (((Command & FLS_PAGE_PROGRAM_COMMAND_CODE) != 0U))
#endif
    {
        /*Program operation*/
        Timeout = FLS_SYNC_WRITE_TIMEOUT;
    }
    else if ((Command & FLS_SECTOR_ERASE_COMMAND_CODE) != 0U)
    {
        /*Erase operation*/
        Timeout = FLS_SYNC_ERASE_TIMEOUT;
    }
    /*GCOVR_EXCL_START*/
    else
    {
        /*The integration test can't convered, the fls sync program mode
        only supported erase and write now*/
        Timeout = FLS_BLANK_DBYTE_VALUE;
    }
    /*GCOVR_EXCL_STOP*/
    while ((0U == (EFM->STS & (EFM_STS_DONE_MASK | EFM_STS_ACCERR_MASK))) && (Timeout > 0U))
    {
        Timeout -= 1U;
    }
    if (0U == Timeout)
    {
        TempStatus = STATUS_FTFC_FLS_IP_ERROR_TIMEOUT;
    }
    else if (TRUE == Fls_Lld_CheckErrorFlag())
    {
        TempStatus = STATUS_FTFC_FLS_IP_ERROR;
    }
    else
    {
        /*Nothing to do*/
    }
#else
    while (0U == (EFM->STS & (EFM_STS_DONE_MASK | EFM_STS_ACCERR_MASK)))
    {
        /* wait until command is finished */
#ifndef UNIT_TEST
        __ASM("NOP");/*PRQA S 1006 */
#endif
    }
    if (TRUE == Fls_Lld_CheckErrorFlag())
    {
        TempStatus = STATUS_FTFC_FLS_IP_ERROR;
    }
    else
    {
        /*Nothing to do*/
    }
#endif
    return TempStatus;
}

/**
 * @brief       Load AES key command wirte
 * @details     The function write load AES key command wait completing
 * @param       Command flash command
 * @return      Fls_Lld_StatusType
 */
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_LoadAESCommand(uint8 Command)
{
    Fls_Lld_StatusType TempStatus = STATUS_FTFC_FLS_IP_SUCCESS;
#ifndef UNIT_TEST
    __ASM("ISB");/* PRQA S 1006 */
    __ASM("DSB");/* PRQA S 1006 */
#endif
    EFM->CMD_UNLOCK = FLS_EFM_CMDUNLOCK_KEY;
    EFM->CMD = Command;
#if(STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED)
    uint32 Timeout = 0U;
    Timeout = FLS_SYNC_WRITE_TIMEOUT;
    while ((0U == (EFM->STS & (EFM_STS_DONE_MASK | EFM_STS_ACCERR_MASK))) && (Timeout > 0U))
    {
        Timeout -= 1U;
    }
    if (0U == Timeout)
    {
        TempStatus = STATUS_FTFC_FLS_IP_ERROR_TIMEOUT;
    }
    else
    {
        /*GCOVR_EXCL_START*/
        if ((EFM->STS & FLS_ERR_FLAGS_MASK) != 0U)
        {
            /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
            TempStatus = STATUS_FTFC_FLS_IP_ERROR;
        }
        /*GCOVR_EXCL_STOP*/
        else
        {
            /*Nothing to do*/
        }
    }
#else
    while (0U == (EFM->STS & (EFM_STS_DONE_MASK | EFM_STS_ACCERR_MASK)))
    {
        /* wait until command is finished */
#ifndef UNIT_TEST
        __ASM("NOP");/* PRQA S 1006 */
#endif
    }
    if ((EFM->STS & FLS_ERR_FLAGS_MASK) != 0)
    {
        TempStatus = STATUS_FTFC_FLS_IP_ERROR;
    }
    else
    {
        /*Nothing to do*/
    }
#endif
    return TempStatus;
}

#define FLS_STOP_SEC_RAMCODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/**
 * @brief           Check Address is valid for P-Flash
 * @details         This function will check if the address is valid for P-Flash
 * @param[in]       Address    flash address
 * @return          boolean
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_ValidPFlash(Fls_AddressType Address)
{
    boolean TempRet = FALSE;
    if (FLS_ADDRESS_VALID_P_FLASH(Address))
    {
        TempRet = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return TempRet;
}

/**
 * @brief           Check Address is valid for D-Flash
 * @details         This function will check if the address is valid for D-Flash
 * @param[in]       Address    flash address
 * @return          boolean
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_ValidDFlash(Fls_AddressType Address)
{
    boolean TempRet = FALSE;
    if (FLS_ADDRESS_VALID_D_FLASH(Address))
    {
        TempRet = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return TempRet;
}

/**
 * @brief           Check Address is valid for FLASH
 * @details         This function will check if the address is valid for FLASH
 * @param[in]       Address    flash address
 * @return          boolean
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_ValidFlash(Fls_AddressType Address)
{
    boolean TempRet = FALSE;
    if ((TRUE == Fls_Lld_ValidPFlash(Address)) || (TRUE == Fls_Lld_ValidDFlash(Address)))
    {
        TempRet = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return TempRet;
}

/**
 * @brief           Check Address is valid for NVR-Flash
 * @details         This function will check if the address is valid for NVR-Flash
 * @param[in]       Address    flash address
 * @return          boolean
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_ValidNVRFlash(Fls_AddressType Address)
{
    boolean TempRet = FALSE;
    if (FLS_ADDRESS_VALID_NVR_FLASH(Address))
    {
        TempRet = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return TempRet;
}


/**
 *
 * @brief           Fls_Lld_SectorWriteStatus
 * @details         Checks the status of the hardware program started by the Fls_Lld_MainFunction function.
 * @return          Fls_Lld_StatusType
 */
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_SectorWriteStatus(void)
{
    Fls_Lld_StatusType ReturnCode;
    /* Check if the write job started successfully */
    if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_eWriteStatus)
    {
        /* The job started successfully, polling the controller status */
#ifdef FLS_USER_MODE_SUPPORTED
        ReturnCode = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return(Fls_Lld_GetCtrlStatus);
#else
        ReturnCode = Fls_Lld_GetCtrlStatus();
#endif
        /* The job has done, perform the verification */
#if ( FLS_WRITE_VERIFICATION_ENABLED == STD_ON )
        if (STATUS_FTFC_FLS_IP_SUCCESS == ReturnCode)
        {
            ReturnCode = Fls_Lld_CompareFlash(Fls_Lld_u32WritedAddress, Fls_Lld_u32WritedLength, Fls_Lld_pWritedData);
            /*GCOVR_EXCL_START*/
            if (STATUS_FTFC_FLS_IP_SUCCESS != ReturnCode)
            {
                /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                ReturnCode = STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY;
            }
            /*GCOVR_EXCL_STOP*/
        }
#else
#if(PLATFORM_ENABLE_CACHE == STD_ON)
        /* invalidate the cache */
        Fls_Lld_CacheInvalidate(Fls_Lld_u32WritedAddress, Fls_Lld_u32WritedLength);
#endif
#endif
    }
    /*GCOVR_EXCL_START*/
    else if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == Fls_Lld_eWriteStatus)
    {
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        ReturnCode = STATUS_FTFC_FLS_IP_ERROR_TIMEOUT;
    }
    else
    {
        /* The write job did not start successfully, return error immediately */
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        ReturnCode = STATUS_FTFC_FLS_IP_ERROR;
    }
    /*GCOVR_EXCL_STOP*/
    return ReturnCode;
}


/**
 * @brief Compute the data size
 * @details This function is used to compute the data size considering the addresses
 *           alignment and the remaining bytes.
 * @param[in]  SrcAddress the internal flash address
 * @param[in]  DesAddress the user's buffer address
 * @param[in]  ByteRemain how many bytes are left to process
 * @return uint32
 */
FLS_FUNC static uint32 Fls_Lld_ComputeReadSize(uint32 SrcAddress,
        uint32 DesAddress,
        uint32 ByteRemain
                                              )
{
    uint32 ReadSize = FLS_SIZE_1BYTE;
    /* Combine two addresses for faster alignment checking */
    uint32 CombinedAddress = SrcAddress | DesAddress;
    /* Both the lowest two bits are zero: 4 bytes aligned */
    if (0UL == (CombinedAddress & 0x03UL))
    {
        if (ByteRemain >= FLS_SIZE_4BYTE)
        {
            /* 4 bytes operation */
            ReadSize = FLS_SIZE_4BYTE;
        }
        else if (ByteRemain >= FLS_SIZE_2BYTE)
        {
            /* 2 bytes operation */
            ReadSize = FLS_SIZE_2BYTE;
        }
        else
        {
            /* 1 byte operation */
        }
    }
    /* Both the lowest one bit are zero: 2 bytes aligned */
    else if (0UL == (CombinedAddress & 0x01UL))
    {
        if (ByteRemain >= FLS_SIZE_2BYTE)
        {
            /* 2 bytes operation */
            ReadSize = FLS_SIZE_2BYTE;
        }
        else
        {
            /* 1 byte operation */
        }
    }
    else
    {
        /* 1 byte operation */
    }
    return ReadSize;
}

/**
 * @brief            flash erase status check
 * @details          This function will check the erase status
 * @return           Fls_Lld_StatusType
 */
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_SectorEraseStatus(void)
{
    Fls_Lld_StatusType ReturnCode;
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE == STD_ON)
    uint32 Length = 0U;
#endif
    /* Check if the erase job started successfully */
    if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_eEraseStatus)
    {
        /* The job started successfully, polling the controller status */
#ifdef FLS_USER_MODE_SUPPORTED
        ReturnCode = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return(Fls_Lld_GetCtrlStatus);
#else
        ReturnCode = Fls_Lld_GetCtrlStatus();
#endif
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE == STD_ON)
        if (TRUE == Fls_Lld_ValidPFlash(Fls_Lld_u32ErasedSectorAddress))
        {
            Length = FLS_PROG_FLASH_SECTOR_SIZE;
        }
        else
        {
#if defined(CPU_YTM32B1ME0)||defined (CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
            Length = FLS_DATA_FLASH_SECTOR_SIZE;
#elif defined(CPU_YTM32B1MD1)
            Length = FLS_PROG_FLASH_SECTOR_SIZE;
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
        }
#endif /* (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE == STD_ON) */
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)
        if (STATUS_FTFC_FLS_IP_SUCCESS == ReturnCode)
        {
            ReturnCode = Fls_Lld_CompareFlash(Fls_Lld_u32ErasedSectorAddress, Length, NULL_PTR);
            /*GCOVR_EXCL_START*/
            if (STATUS_FTFC_FLS_IP_SUCCESS != ReturnCode)
            {
                /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                ReturnCode = STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK;
            }
            /*GCOVR_EXCL_STOP*/
        }
#else
#if(PLATFORM_ENABLE_CACHE == STD_ON)
        /* invalidate the cache */
        Fls_Lld_CacheInvalidate(Fls_Lld_u32ErasedSectorAddress, Length);
#endif
#endif
    }
    /*GCOVR_EXCL_START*/
    else if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT ==  Fls_Lld_eEraseStatus)
    {
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        ReturnCode = STATUS_FTFC_FLS_IP_ERROR_TIMEOUT;
    }
    else
    {
        /* The erase job did not start successfully, return error immediately */
        ReturnCode = STATUS_FTFC_FLS_IP_ERROR;
    }
    /*GCOVR_EXCL_STOP*/
    return ReturnCode;
}

/**
 * @brief            read flash EFM_STS register
 * @details          This function will read flash EFM_STS register and return
 * @return          Fls_Lld_StatusType
 */
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_GetCtrlStatus(void)
{
    Fls_Lld_StatusType RetVal;
    uint32 ErrorFlags;
    /* Check if the flash controller is idle, by polling the CCIF status bit. */
    if (TRUE == Fls_Lld_CheckIdle())
    {
        /* OK, memory controller is idle */
        /* Check if any hardware errors happened */
        ErrorFlags = Fls_Lld_CheckErrorFlag();
        if (0U == ErrorFlags)
        {
            RetVal = STATUS_FTFC_FLS_IP_SUCCESS;
        }
        else
        {
            /* clear the error flags */
            Fls_Lld_ClearErrorFlag();
            RetVal = STATUS_FTFC_FLS_IP_ERROR;
        }
    }
    else
    {
#if (STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED)
        /* Check if timeout is enabled */
        Fls_Lld_u32TimeoutCounter -= 1U;
        if (0U == Fls_Lld_u32TimeoutCounter)
        {
            /* Timeout occurred, return error */
            RetVal = STATUS_FTFC_FLS_IP_ERROR_TIMEOUT;
        }
        else
#endif
        {
            RetVal = STATUS_FTFC_FLS_IP_BUSY;
        }
    }
    return RetVal;
}


/**
 * @brief Verifies data written in serial flash
 * @details This function verifies data written in serial flash
 * @param[in] CheckAddress - start address of the data to be verified
 * @param[in] DataPtr - pointer to the data to be verified
 * @param[in] CheckSize - size of the data to be verified
 * @return void
 */
FLS_FUNC static void Fls_Lld_CompareCheck(uint32 CheckAddress, const uint8 *DataPtr, uint32 CheckSize)
{
    uint32 VerifyAddress = CheckAddress;
    /* MR12 Rule 11.4 VIOLATION: In this specific case, the data address need use to
     *                           caculate aligning, it couldn't adhere to M3CM Rule-11.4.
     */
    uint32 VerifyData    = (uint32)DataPtr; /*PRQA S 0306*/
    uint32 VerifySize    = CheckSize;
    uint32 ReadSize;
    boolean CompareStatus = (boolean)TRUE;
#if (PLATFORM_ENABLE_CACHE == STD_ON)
    Fls_Lld_CacheInvalidate(CheckAddress, CheckSize);
#endif
    /* Start compare operation */
    do
    {
        /* Compute the maximum read size */
        ReadSize = Fls_Lld_ComputeReadSize(VerifyAddress, VerifyData, VerifySize);
        switch (ReadSize)
        {
            case FLS_SIZE_4BYTE:
                /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                 *               value of VerifyData caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                 */
                if ((*((uint32 *)VerifyData)) != (*((uint32 *)VerifyAddress))) /*PRQA S 0306*/
                {
                    CompareStatus = (boolean)FALSE;
                }
                break;
            case FLS_SIZE_2BYTE:
                /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                 *               value of VerifyData caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                 */
                if ((*((uint16 *)VerifyData)) != (*((uint16 *)VerifyAddress))) /*PRQA S 0306*/
                {
                    CompareStatus = (boolean)FALSE;
                }
                break;
            case FLS_SIZE_1BYTE:
                /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                 *               value of VerifyData caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                 */
                if ((*((uint8 *)VerifyData)) != (*((uint8 *)VerifyAddress))) /*PRQA S 0306*/
                {
                    CompareStatus = (boolean)FALSE;
                }
                break;
            default:
                /* Do nothing */
                break;
        }
        /*Check uncorrectable ecc error,when ecc error interrupt is enable ,check the value of Fls_Lld_UncorrectableEccFlag*/
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
        if (TRUE == Fls_Lld_UncorrectableEccFlag)
#else
        if (TRUE == Fls_Lld_GetUnrecoverr())
#endif
        {
            CompareStatus = FALSE;
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
            Fls_Lld_UncorrectableEccFlag = FALSE;
#endif
            Fls_Lld_ClearUnrecoverr();
        }
        if (FALSE != CompareStatus)
        {
            /* Move to next data */
            VerifyAddress += ReadSize;
            VerifyData    += ReadSize;
            VerifySize    -= ReadSize;
        }
    } while ((FALSE !=  CompareStatus) && (0UL < VerifySize));
    /* Checking if working is successful: the requested bytes were copied and no errors happend */
    if (0UL == VerifySize)
    {
        /* Mark as success */
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_SUCCESS;
    }
    else
    {
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY;
    }
}
/**
 * @brief            Write data to the DFLASH
 * @details          This function will write 8byte data to the DFLASH
 * @param[in]        StartAddress - start address of the data to be written
 * @param[in]        SourceAddressPtr - pointer to the data to be written
 * @return           MemIf_JobResultType
*/
FLS_FUNC static MemIf_JobResultType Fls_Lld_WriteDataPage(Fls_AddressType StartAddress, const uint8 *SourceAddressPtr, uint8 WriteLength)
{
    MemIf_JobResultType LldRetVal = MEMIF_JOB_OK;
    /* Clear all error flags */
    Fls_Lld_ClearRegSTS();
    /* parsing parameters to flash */
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the SourceAddressPtr is judged 4 byte alignment in the MCAL,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
#if (FLS_WEBIT_AVAILABLE==STD_ON)
    Fls_Lld_SetWE();
#else
#if (PLATFORM_MPU_CFG == STD_ON)
    ARM_MPU_Disable();
#endif
#endif
    for (uint8 LoopCnt = 0U; LoopCnt < (WriteLength >> 2U); ++LoopCnt)
    {
        *((volatile uint32 *)(StartAddress + ((uint32)LoopCnt * 4U))) = *((const uint32 *)(&SourceAddressPtr[LoopCnt * 4U])); /* PRQA S 3305,0310 */
    }
#if (FLS_WEBIT_AVAILABLE==STD_ON)
    /*GCOVR_EXCL_START*/
    if (FALSE == Fls_Lld_JudgeSetAddr(0x1000U))
    {
        /*If SET_ADDR is not set, the EFM hardware is faulty and this operation
          fails.The hardware failure cannot be simulated, this code cannot be
          covered in integration tests*/
        LldRetVal = MEMIF_JOB_FAILED;
    }
    /*GCOVR_EXCL_STOP*/
    Fls_Lld_ClearWE();
#else
#if (PLATFORM_MPU_CFG == STD_ON)
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);
#endif
#endif
    return LldRetVal;
}
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)
/**
 * @brief            Check blank before write
 * @details          This function will check blank before write
 * @param[in]        DestAddr - start address of the data to be written
 * @param[in]        Length - length of the data to be written
 * @return           Fls_Lld_StatusType
*/
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_BlankCheckPreWrite(Fls_AddressType DestAddr, Fls_LengthType Length)
{
    Fls_Lld_StatusType ReturnCode = STATUS_FTFC_FLS_IP_SUCCESS;
    ReturnCode = Fls_Lld_CompareFlash(DestAddr, Length, NULL_PTR);
    if (STATUS_FTFC_FLS_IP_SUCCESS != ReturnCode)
    {
        Fls_LLDJobResult = MEMIF_JOB_FAILED;
        ReturnCode = STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK;
    }
    return ReturnCode;
}
#endif

/**
 * @brief            Check write successful flag
 * @details          This function will check write successful flag
 * @param[in]        ReturnCode - return code of the flash operation
 * @return           Fls_Lld_ReturnType
*/
FLS_FUNC LOCAL_INLINE Fls_Lld_ReturnType Fls_Lld_WriteRstCheck(Fls_Lld_StatusType ReturnCode)
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    if (ReturnCode == STATUS_FTFC_FLS_IP_SUCCESS)
    {
        LldRetVal = FLASH_E_OK;
        Fls_LLDJobResult = MEMIF_JOB_OK;
    }
    /*GCOVR_EXCL_START*/
    else
    {
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        LldRetVal = FLASH_E_FAILED;
        Fls_LLDJobResult = MEMIF_JOB_FAILED;
    }
    /*GCOVR_EXCL_STOP*/
    return LldRetVal;
}

/**
 * @brief            Check input parameters before write
 * @details          This function will check input parameters before write
 * @param[in]        DestAddr - start address of the data to be written
 * @param[in]        Length - length of the data to be written
 * @param[in]        JobDataSrcPtr - pointer to the data to be written
 * @param[in]        AsynchFlag - sync or asynch mode
 * @param[in]        FlsChoose - PFLASH or DFLASH,0 is PFLASH,1 is DFLASH
 * @return           boolean
*/
FLS_FUNC LOCAL_INLINE boolean Fls_Lld_AddrCheckPreWrite(const Fls_AddressType DestAddr,
        const Fls_LengthType Length,
        const uint8 *JobDataSrcPtr)
{
    boolean RetVal = (boolean)TRUE;
    if ((TRUE == Fls_Lld_ValidDFlash(DestAddr)) && \
            (TRUE == Fls_Lld_ValidDFlash((DestAddr + Length) - 1U)) && \
            (NULL_PTR != JobDataSrcPtr))
    {
#if defined(FLS_DATA_FLASH_PAGE_SIZE)
        if (((DestAddr % FLS_DATA_FLASH_PAGE_SIZE) != 0U) || \
                (Length != FLS_DATA_FLASH_PAGE_SIZE))
        {
            RetVal = TRUE;
        }
        else
        {
            RetVal = FALSE;
        }
#else
        RetVal = TRUE;
#endif
    }
    else if ((TRUE == Fls_Lld_ValidPFlash(DestAddr)) && \
             (TRUE == Fls_Lld_ValidPFlash((DestAddr + Length) - 1U)) && \
             (NULL_PTR != JobDataSrcPtr))
    {
        if (((DestAddr % FLS_PROG_FLASH_PAGE_SIZE) != 0U) || \
                (Length != FLS_PROG_FLASH_PAGE_SIZE))
        {
            RetVal = TRUE;
        }
        else
        {
            RetVal = FALSE;
        }
    }
    else
    {
        RetVal = TRUE;
    }
    return RetVal;
}

/**
 * @brief           Load AES key
 * @details         This function will load AES key to AES engine
 * @param[in]       StartAddress - start address of the AES key
 * @return          void
*/
FLS_FUNC static void Fls_Lld_LoadAESKey(Fls_AddressType StartAddress)
{
    /*GCOVR_EXCL_START*/
    if ((StartAddress % FLS_NVR_FLASH_PAGE_SIZE) != 0U)
    {
        /*The integration can't convered, the StartAddress has been check aligned in Fls.c*/
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
    }
    /*GCOVR_EXCL_STOP*/
    else
    {
        /*GCOVR_EXCL_START*/
        if (FALSE == Fls_Lld_CheckIdle())
        {
            /*The integration can't convered, the state has been check aligned in Fls.c*/
            Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_BUSY;
        }
        /*GCOVR_EXCL_STOP*/
        else
        {
            /* Clear all error flags */
            Fls_Lld_ClearRegSTS();
            /*Clear cmd*/
            Fls_Lld_EFMNopCommand();
            /*Load NVR address*/
            Fls_Lld_LoadNvrAddr(StartAddress);
            /* clear the error flags and done flag */
            Fls_Lld_ClearRegSTS();
            /*disable interrupt*/
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_07();
#endif
            /*Load CMD*/
            Fls_Lld_eReadStatus = Fls_Lld_LoadAESCommand(FLS_LOAD_AES_KEY_CMD_CODE);
#if (FLS_SCHM_SUPPORT==STD_ON)
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_07();
#endif
        }
    }
}

/**
 * @brief            Read from code or data flash
 * @details          This function will read from code or data flash
 * @param[in]        StartAddress - start address of the data to be read
 * @param[in]        Length - length of the data to be read
 * @param[in]        TargetAddressPtr - pointer to the data to be read
 * @return           void
*/
FLS_FUNC static void Fls_Lld_ReadUserPartition(Fls_AddressType StartAddress, Fls_LengthType Length, uint8 *TargetAddressPtr)
{
    uint32 ReadAddress = StartAddress;
    /* MR12 Rule 11.4 VIOLATION: In this specific case, the TargetAddressPtr need use to
    *                           caculate aligning, it couldn't adhere to M3CM Rule-11.4.
    */
    uint32 DesAddress  = (uint32)TargetAddressPtr; /*PRQA S 0306*/
    uint8 *DesAddressPtr = TargetAddressPtr;
    uint32 BytesRemain = Length;
    uint32 ReadSize;
    uint32 ReadCnt = Length;
    /* Checking before reading */
    /*GCOVR_EXCL_START*/
    if ((NULL_PTR == TargetAddressPtr) || (0U == Length) || \
            (FALSE == Fls_Lld_ValidFlash(StartAddress)) || (FALSE == Fls_Lld_ValidFlash((StartAddress + Length) - 1U)))
    {
        /*The integration can't convered, the parameters have been check aligned in Fls.c*/
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
    }
    /*GCOVR_EXCL_STOP*/
    else
    {
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_SUCCESS;
    }
    if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_eReadStatus)
    {
        /* Change to busy state */
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_BUSY;
#if (PLATFORM_ENABLE_CACHE == STD_ON)
        Fls_Lld_CacheInvalidate(StartAddress, Length);
#endif
        do
        {
            /* Compute the maximum read size */
            ReadSize = Fls_Lld_ComputeReadSize(ReadAddress, DesAddress, BytesRemain);
            switch (ReadSize)
            {
                case FLS_SIZE_4BYTE:
                    /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                     *               value of DesAddress caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                     */
                    *((uint32 *)DesAddress) = *((uint32 *)ReadAddress);  /*PRQA S 0306*/
                    break;
                case FLS_SIZE_2BYTE:
                    /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                     *               value of DesAddress caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                     */
                    *((uint16 *)DesAddress) = *((uint16 *)ReadAddress); /*PRQA S 0306*/
                    break;
                case FLS_SIZE_1BYTE:
                    /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                     *               value of DesAddress caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                     */
                    *DesAddressPtr = *((uint8 *)ReadAddress);  /* Using uint8 directly to avoid pointer casting */  /*PRQA S 0306*/
                    break;
                default:
                    /* Do nothing */
                    break;
            }
            /*Check uncorrectable ecc error,when ecc error interrupt is enable ,check the value of Fls_Lld_UncorrectableEccFlag*/
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
            if (FALSE == Fls_Lld_UncorrectableEccFlag)
#else
            if (FALSE == Fls_Lld_GetUnrecoverr())
#endif
            {
                /* Move to the next data */
                ReadAddress  += ReadSize;
                DesAddress   += ReadSize;
                DesAddressPtr = &DesAddressPtr[ReadSize];
                BytesRemain  -= ReadSize;
                ReadCnt -= 1U;
            }
            else
            {
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
                Fls_Lld_UncorrectableEccFlag = FALSE;
#endif
                Fls_Lld_ClearUnrecoverr();
                break;
            }
        } while ((0U < BytesRemain) && (0U < ReadCnt));
        /* Checking if working was successful: the requested bytes were copied and no errors happend */
        if (0UL == BytesRemain)
        {
            /* Mark as success */
            Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_SUCCESS;
        }
        /*GCOVR_EXCL_START*/
        else
        {
            /* Mark as failed */
            /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
            Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR;
        }
        /*GCOVR_EXCL_STOP*/
    }
}
/**
 * @brief            Check special area is blank or not
 * @details          This function will check special area is blank or not
 * @param[in]        StartAddress - start address of the data to be checked
 * @param[in]        Length - length of the data to be checked
 * @return           void
*/
FLS_FUNC static void Fls_Lld_BlankCheck(Fls_AddressType StartAddress, Fls_LengthType Length)
{
    uint32 VerifyAddress = StartAddress;
    uint32 VerifySize = Length;
    uint32 ReadSize;
    boolean CompareStatus = (boolean)TRUE;
#if (PLATFORM_ENABLE_CACHE == STD_ON)
    Fls_Lld_CacheInvalidate(StartAddress, Length);
#endif
    /* Start compare operation */
    do
    {
        /* Compute the maximum read size */
        ReadSize = Fls_Lld_ComputeReadSize(VerifyAddress, 0UL, VerifySize);
        switch (ReadSize)
        {
            case FLS_SIZE_4BYTE:
                /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                 *               value of VerifyAddress caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                 */
                if ((uint32)FLS_ERASED_VALUE != (*((uint32 *)VerifyAddress))) /*PRQA S 0306*/
                {
                    CompareStatus = (boolean)FALSE;
                }
                break;
            case FLS_SIZE_2BYTE:
                /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                 *               value of VerifyAddress caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                 */
                if ((uint16)FLS_ERASED_VALUE != (*((uint16 *)VerifyAddress))) /*PRQA S 0306*/
                {
                    CompareStatus = (boolean)FALSE;
                }
                break;
            case FLS_SIZE_1BYTE:
                /* MR12 Rule 11.4 VIOLATION: In this specific case, need to read data in address which is the
                 *               value of VerifyAddress caculate aligning, it couldn't adhere to M3CM Rule-11.4.
                 */
                if ((uint8)FLS_ERASED_VALUE != (*((uint8 *)VerifyAddress))) /*PRQA S 0306*/
                {
                    CompareStatus = (boolean)FALSE;
                }
                break;
            default:
                /* Do nothing */
                break;
        }
        /*Check uncorrectable ecc error,when ecc error interrupt is enable ,check the value of Fls_Lld_UncorrectableEccFlag*/
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
        if (TRUE == Fls_Lld_UncorrectableEccFlag)
#else
        if (TRUE == Fls_Lld_GetUnrecoverr())
#endif
        {
            CompareStatus = FALSE;
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
            Fls_Lld_UncorrectableEccFlag = FALSE;
#endif
            Fls_Lld_ClearUnrecoverr();
        }
        /* Move to next data */
        if (FALSE != CompareStatus)
        {
            VerifyAddress += ReadSize;
            VerifySize    -= ReadSize;
        }
    } while ((FALSE !=  CompareStatus) && (0UL < VerifySize));
    /* Checking if working is successful: the requested bytes were copied and no errors happend */
    if (0UL == VerifySize)
    {
        /* Mark as success */
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_SUCCESS;
    }
    else
    {
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK;
    }
}


FLS_FUNC static Fls_Lld_StatusType Fls_Lld_ErasePreWork(Fls_AddressType StartAddress)
{
    Fls_Lld_StatusType Status = STATUS_FTFC_FLS_IP_SUCCESS;
    /*clear sts and commad*/
    Fls_Lld_ClearRegSTS();
    Fls_Lld_EFMNopCommand();
    /*disable MPU and select sector*/
#if (FLS_WEBIT_AVAILABLE==STD_ON)
    Fls_Lld_SetWE();
#else
#if (PLATFORM_MPU_CFG == STD_ON)
    ARM_MPU_Disable();
#endif
#endif
    *(volatile uint32 *)StartAddress = 0x01234567U;
#if (FLS_WEBIT_AVAILABLE==STD_ON)
    /*GCOVR_EXCL_START*/
    if (FALSE == Fls_Lld_JudgeSetAddr(0x100U))
    {
        /*If SET_ADDR is not set, the EFM hardware is faulty and this operation
        fails.The hardware failure cannot be simulated, this code cannot be
        covered in integration tests*/
        Status = STATUS_FTFC_FLS_IP_ERROR;
    }
    /*GCOVR_EXCL_STOP*/
    Fls_Lld_ClearWE();
#else
#if (PLATFORM_MPU_CFG == STD_ON)
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);
#endif
#endif
#if(STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED)
    Fls_Lld_u32TimeoutCounter = FLS_ASYNC_ERASE_TIMEOUT;
#endif
    return Status;
}

#if (FLS_QUICK_ERASE_FEATURE_ENABLE==STD_ON)
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_SectorSyncRetryErase(Fls_AddressType StartAddress)
{
    Fls_Lld_StatusType Status = STATUS_FTFC_FLS_IP_SUCCESS;
    /*disable interrrupt*/
#if (FLS_SCHM_SUPPORT==STD_ON)
    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
#endif
    Status = Fls_Lld_ErasePreWork(StartAddress);
    if (STATUS_FTFC_FLS_IP_SUCCESS == Status)
    {
        /* clear the error flags and done flag */
        Fls_Lld_ClearRegSTS();
        /*Unlock the command */
        Fls_Lld_UnLockCMD();
        /*Write command*/
        Status = Fls_Lld_LoadCommandSync(FLS_ERASE_RETRY_COMMAND_CODE);
    }
#if (FLS_SCHM_SUPPORT==STD_ON)
    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
#endif
    return Status;
}

FLS_FUNC static Fls_Lld_StatusType Fls_Lld_SectorSyncQuickErase(Fls_AddressType StartAddress)
{
    uint8 LoopCnt;
    Fls_Lld_StatusType Status = STATUS_FTFC_FLS_IP_SUCCESS;
    Fls_LLDJob = FLASH_JOB_ERASE;
    Fls_LLDJobResult = MEMIF_JOB_PENDING;
#if defined (CPU_YTM32B1MC0)
    Fls_Lld_SetTime2Reg(FLS_QUICK_ERASE_TIME_LIMIT);
    EFM->CTRL |= EFM_CTRL_CMD_VERIFY_EN_MASK;
#endif
#if defined (EFM_CTRL_RETRY_CFG_MASK)
    Fls_Lld_SetRetryCfg();
#endif
    for (LoopCnt = 0; LoopCnt < FLS_QUICK_ERASE_MAX_REPEAT_COUNT; LoopCnt++)
    {
        Status = Fls_Lld_SectorSyncRetryErase(StartAddress);
        if (STATUS_FTFC_FLS_IP_SUCCESS == Status)
        {
            break;
        }
    }
    /*GCOVR_EXCL_START*/
    if ((Status != STATUS_FTFC_FLS_IP_SUCCESS) && (LoopCnt >= FLS_QUICK_ERASE_MAX_REPEAT_COUNT))
    {
        Fls_Lld_eEraseStatus = Status;
        Fls_LLDJobResult  = MEMIF_JOB_FAILED;
    }
    /*GCOVR_EXCL_STOP*/
    else
    {
        (void)Fls_Lld_SectorSyncRetryErase(StartAddress);
        Fls_Lld_eEraseStatus = STATUS_FTFC_FLS_IP_SUCCESS;
        Fls_LLDJobResult  = MEMIF_JOB_OK;
    }
    return Status;
}
#else
FLS_FUNC static Fls_Lld_StatusType Fls_Lld_SectorSyncErase(Fls_AddressType StartAddress)
{
    Fls_Lld_StatusType Status = STATUS_FTFC_FLS_IP_SUCCESS;
    Fls_LLDJob = FLASH_JOB_ERASE;
#if (FLS_SCHM_SUPPORT==STD_ON)
    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
#endif
    Status = Fls_Lld_ErasePreWork(StartAddress);
    if (STATUS_FTFC_FLS_IP_SUCCESS == Status)
    {
        /* clear the error flags and done flag */
        Fls_Lld_ClearRegSTS();
        /*Unlock the command */
        Fls_Lld_UnLockCMD();
        /* wait for flash to be idle */
        Status = Fls_Lld_LoadCommandSync(FLS_SECTOR_ERASE_COMMAND_CODE);
        if (Status == STATUS_FTFC_FLS_IP_SUCCESS)
        {
            Fls_LLDJobResult  = MEMIF_JOB_OK;
            Fls_Lld_eEraseStatus = STATUS_FTFC_FLS_IP_SUCCESS;
        }
        /*GCOVR_EXCL_START*/
        else
        {
            /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
            Fls_LLDJobResult  = MEMIF_JOB_FAILED;
            Fls_Lld_eEraseStatus = Status;
        }
        /*GCOVR_EXCL_STOP*/
    }
#if (FLS_SCHM_SUPPORT==STD_ON)
    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
#endif
    return Status;
}
#endif

FLS_FUNC static Fls_Lld_StatusType Fls_Lld_SectorAsyncErase(Fls_AddressType StartAddress)
{
    Fls_Lld_StatusType ReturnCode = STATUS_FTFC_FLS_IP_SUCCESS;
    Fls_LLDJob = FLASH_JOB_ERASE;
#if (FLS_SCHM_SUPPORT==STD_ON)
    /*disable interrupt*/
    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
#endif
    ReturnCode = Fls_Lld_ErasePreWork(StartAddress);
    if (STATUS_FTFC_FLS_IP_SUCCESS == ReturnCode)
    {
        /* clear the error flags and done flag */
        Fls_Lld_ClearRegSTS();
        /*Unlock the command */
        Fls_Lld_UnLockCMD();
        /*Write command*/
        Fls_Lld_LoadCommand(FLS_SECTOR_ERASE_COMMAND_CODE);
        Fls_LLDJobResult = MEMIF_JOB_PENDING;
        ReturnCode = STATUS_FTFC_FLS_IP_BUSY;
        Fls_Lld_eEraseStatus = STATUS_FTFC_FLS_IP_SUCCESS;
    }
    /*GCOVR_EXCL_START*/
    else
    {
        Fls_Lld_eEraseStatus = ReturnCode;
        Fls_LLDJobResult = MEMIF_JOB_FAILED;
    }
    /*GCOVR_EXCL_STOP*/
#if (FLS_SCHM_SUPPORT==STD_ON)
    /*disable interrupt*/
    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
#endif
    return ReturnCode;
}


/**
 * @brief Enable or disable the ecc error interrupt
 *
 * @param[in] EccIntcEnable
 * @return void
 */
FLS_FUNC static void Fls_Lld_EccErrorIntcConfig(boolean EccIntcEnable)
{
    if (TRUE == EccIntcEnable)
    {
        /*Enable the flash ecc error interrupt*/
        Fls_Lld_SetUNRECOVERRIE(TRUE);
        Fls_Lld_SetRECOVERRIE(TRUE);
    }
    else
    {
        /*Disable the flash ecc error interrupt*/
        Fls_Lld_SetUNRECOVERRIE(FALSE);
        Fls_Lld_SetRECOVERRIE(FALSE);
    }
}
#if (FLS_HANDLE_BUSFAULT_INDEPENDENT == STD_ON)
/**
 * @brief Enable  the bus fault exception
 *
 * @return void
 */
FLS_FUNC static void Fls_Lld_EnableBusFault(void)
{
    /*Enable usageFault exception*/
    SCB->SHCSR |= SCB_SHCSR_BUSFAULTENA_Msk;/*PRQA S 0306*/
    SCB->CCR |= SCB_CCR_BFHFNMIGN_Msk;/*PRQA S 0306*/
}
#endif
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/***************************************************************************************************
*                                          Fls_Lld_GetOneBitEccErrFlag
****************************************************************************************************/
FLS_FUNC boolean Fls_Lld_GetOneBitEccErrFlag(void)
{
    return (Fls_Lld_GetRecoverr());
}
/***************************************************************************************************
*                                          Fls_Lld_GetTwoBitEccErrFlag
****************************************************************************************************/
FLS_FUNC boolean Fls_Lld_GetTwoBitEccErrFlag(void)
{
    return (Fls_Lld_GetUnrecoverr());
}
/***************************************************************************************************
*                                          Fls_Lld_GetEccErrAddr
****************************************************************************************************/
FLS_FUNC Fls_AddressType Fls_Lld_GetEccErrAddr(void)
{
    return (Fls_Lld_GetEccErrorAddrReg());
}

/***************************************************************************************************
*                                          Fls_Lld_Init
****************************************************************************************************/
FLS_FUNC Fls_Lld_StatusType Fls_Lld_Init(Fls_SectorProtectType const *SectorProtCfg)
{
    Fls_Lld_StatusType RetVal = STATUS_FTFC_FLS_IP_SUCCESS;
    /* check if Flash currently idle */
    if (TRUE == Fls_Lld_CheckIdle())
    {
        /* clear all error flags */
        Fls_Lld_ClearRegSTS();
        /* [SWS_Fls_00048] If supported by hardware, the function Fls_Init shall set the
            flash memory erase/write protection as provided in the configuration set. */
        Fls_JobState.JobResult = MEMIF_JOB_OK;
        Fls_JobState.JobCurrentAddr = (Fls_AddressType)0U;
        Fls_JobState.JobEndAddr = (Fls_AddressType)0U;
        Fls_JobState.JobType = (Fls_JobType)FLS_JOB_IDLE;
        Fls_JobState.JobWriteDataPtr = NULL_PTR;
        Fls_JobState.JobReadDataPtr = NULL_PTR;
        Fls_LLDJobResult  = MEMIF_JOB_OK;
#if (FLS_INTERNAL_SECTORS_PROTECTION==STD_ON)
        for (uint8 LoopCnt = 0; LoopCnt < FLS_INTERNAL_BLOCK_NUM; ++LoopCnt)
        {
            Fls_Lld_SetProtectReg(LoopCnt, ~(SectorProtCfg[LoopCnt]));
        }
#else
        for (uint8 LoopCnt = 0; LoopCnt < FLS_INTERNAL_BLOCK_NUM; ++LoopCnt)
        {
            Fls_Lld_SetProtectReg(LoopCnt, 0xFFFFFFFFU);
        }
#endif
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE == STD_ON)
        Fls_Lld_EccErrorIntcConfig(TRUE);
#else
        Fls_Lld_EccErrorIntcConfig(FALSE);
#endif
#if (FLS_HANDLE_BUSFAULT_INDEPENDENT == STD_ON)
        Fls_Lld_EnableBusFault();
#endif
    }
    /*GCOVR_EXCL_START*/
    else
    {
        /* Flash is busy, return error */
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        Fls_JobState.JobResult = MEMIF_JOB_FAILED;
        Fls_LLDJobResult  = MEMIF_JOB_FAILED;
        RetVal = STATUS_FTFC_FLS_IP_ERROR;
    }
    /*GCOVR_EXCL_STOP*/
    return RetVal;
}

/***************************************************************************************************
*                                          Fls_Lld_SectorErase
****************************************************************************************************/
FLS_FUNC Fls_Lld_StatusType Fls_Lld_SectorErase(Fls_AddressType StartAddress, boolean Async)
{
    Fls_Lld_StatusType ReturnCode;
    /*Check EFM Busy or not*/
    /*GCOVR_EXCL_START*/
    if (FALSE == Fls_Lld_CheckIdle())
    {
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        ReturnCode = STATUS_FTFC_FLS_IP_BUSY;
        Fls_Lld_eEraseStatus = STATUS_FTFC_FLS_IP_BUSY;
    }
    /*GCOVR_EXCL_STOP*/
    else
    {
#if (STD_ON == FLS_ERASE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE == STD_ON)
        Fls_Lld_u32ErasedSectorAddress = StartAddress;
#endif /* FLS_ERASE_VERIFICATION_ENABLED */
        /*Check addr and sector*/
        if (TRUE == Fls_Lld_ValidFlash(StartAddress))
        {
            if (TRUE == Async)
            {
                ReturnCode = Fls_Lld_SectorAsyncErase(StartAddress);
            }
            else
            {
#if (FLS_QUICK_ERASE_FEATURE_ENABLE==STD_ON)
                ReturnCode = Fls_Lld_SectorSyncQuickErase(StartAddress);
#else
                ReturnCode = Fls_Lld_SectorSyncErase(StartAddress);
#endif
            }
        }
        else
        {
            ReturnCode = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
            Fls_Lld_eEraseStatus = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
        }
    }
    return ReturnCode;
}

/***************************************************************************************************
*                                          Fls_Lld_ReadFlash
****************************************************************************************************/
FLS_FUNC Fls_Lld_StatusType Fls_Lld_ReadFlash(Fls_AddressType StartAddress, Fls_LengthType Length, uint8 *TargetAddressPtr)
{
    /* Checking before reading */
    if (TRUE == Fls_Lld_ValidFlash(StartAddress))
    {
        Fls_Lld_ReadUserPartition(StartAddress, Length, TargetAddressPtr);
    }
    else if (TRUE == Fls_Lld_ValidNVRFlash(StartAddress))
    {
        Fls_Lld_LoadAESKey(StartAddress);
    }
    else
    {
        /*The integration can't convered, the parameters have been checked in fls.c*/
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
    }
    return Fls_Lld_eReadStatus;
}

/***************************************************************************************************
*                                          Fls_Lld_CompareFlash
****************************************************************************************************/
FLS_FUNC Fls_Lld_StatusType Fls_Lld_CompareFlash(Fls_AddressType StartAddress, Fls_LengthType Length, const uint8 *SourceAddressPtr)
{
    uint32 SrcAddress = StartAddress;
    /* Checking before comparing */
    if ((0U == Length) || (FALSE == Fls_Lld_ValidFlash(StartAddress)) || (FALSE == Fls_Lld_ValidFlash((StartAddress + Length) - 1U)))
    {
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
    }
    else
    {
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_SUCCESS;
    }
    if (STATUS_FTFC_FLS_IP_SUCCESS == Fls_Lld_eReadStatus)
    {
        /* Change to busy state */
        Fls_Lld_eReadStatus = STATUS_FTFC_FLS_IP_BUSY;
#if (PLATFORM_ENABLE_CACHE == STD_ON)
        Fls_Lld_CacheInvalidate(StartAddress, Length);
#endif
        /* Choose the type of comparison */
        if (NULL_PTR != SourceAddressPtr)
        {
            /* Verify the written data */
            Fls_Lld_CompareCheck(SrcAddress, SourceAddressPtr, Length);
        }
        else
        {
            /* Blank check */
            Fls_Lld_BlankCheck(SrcAddress, Length);
        }
    }
    return Fls_Lld_eReadStatus;
}
/***************************************************************************************************
*                                          Fls_Lld_MainFunction
****************************************************************************************************/
FLS_FUNC void Fls_Lld_MainFunction(void)
{
    Fls_Lld_StatusType ReturnCode = STATUS_FTFC_FLS_IP_ERROR;
    /* some hardware job (asynchronous) is pending */
    if (FLASH_JOB_ERASE == Fls_LLDJob)
    {
#ifdef FLS_USER_MODE_SUPPORTED
        ReturnCode = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return(Fls_Lld_SectorEraseStatus);
#else
        ReturnCode = Fls_Lld_SectorEraseStatus();
#endif
        if (STATUS_FTFC_FLS_IP_BUSY != ReturnCode)
        {
            /* Erase operation finished at EFM level - successfully or with errors  */
            if (STATUS_FTFC_FLS_IP_SUCCESS != ReturnCode)
            {
                /* Sector lock was ok, but IP operation failed */
                Fls_LLDJobResult = MEMIF_JOB_FAILED;
                (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_ERASE_FAILED);
                /* Report Runtime error when comparing is incorrect */
                if (STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK == ReturnCode)/*GCOVR_EXCL_START*/
                {
                    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
                }
                /*GCOVR_EXCL_STOP*/
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
                /*check timeout after checking status fail*/
                else if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == ReturnCode)/*GCOVR_EXCL_START*/
                {
                    /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
                }
                /*GCOVR_EXCL_STOP*/
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
                else
                {
                    /* Do nothing - blank statement added to fulfil MISRA Rule 15.7 */
                }
            }
            else
            {
                /* Everything was ok */
                Fls_LLDJob = FLASH_JOB_NONE;
                Fls_LLDJobResult = MEMIF_JOB_OK;
                if ((Fls_JobState.JobCurrentAddr <= Fls_JobState.JobEndAddr) && \
                        (Fls_JobState.JobCurrentAddr >= (Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorStartAddress + \
                                Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorSize)))
                {
                    /* Move on to the next sector */
                    Fls_JobState.JobSectorIt += 1U;
                }
            }
        }
    }
    /* Write hardware job (asynchronous) is pending */
    else if (FLASH_JOB_WRITE == Fls_LLDJob)
    {
#ifdef FLS_USER_MODE_SUPPORTED
        ReturnCode = (Fls_Lld_StatusType)OsIf_Trusted_Call_Return(Fls_Lld_SectorWriteStatus);
#else
        ReturnCode = Fls_Lld_SectorWriteStatus();
#endif
        if (STATUS_FTFC_FLS_IP_BUSY != ReturnCode)
        {
            /* Erase operation finished at IP level - successfully or with errors or timed out */
            if (STATUS_FTFC_FLS_IP_SUCCESS != ReturnCode)
            {
                /* Sector lock was ok, but IP operation failed */
                Fls_LLDJobResult = MEMIF_JOB_FAILED;
                (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_WRITE_FAILED);
                /* Report Runtime error when comparing is incorrect */
                if (STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK == ReturnCode)/*GCOVR_EXCL_START*/
                {
                    /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
                }
                /*GCOVR_EXCL_STOP*/
                else if (STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY == ReturnCode)/*GCOVR_EXCL_START*/
                {
                    /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_WRITE_FAILED);
                }
                /*GCOVR_EXCL_STOP*/
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
                /*check timeout after checking status fail*/
                else if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == ReturnCode)/*GCOVR_EXCL_START*/
                {
                    /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_TIMEOUT);
                }
                /*GCOVR_EXCL_STOP*/
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
                else
                {
                    /* Do nothing - blank statement added to fulfil MISRA Rule 15.7 */
                }
            }
            else
            {
                /* Everything was ok */
                Fls_LLDJob = FLASH_JOB_NONE;
                Fls_LLDJobResult = MEMIF_JOB_OK;
                if ((Fls_JobState.JobCurrentAddr >= (Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorStartAddress + \
                                                     Fls_ConfigPtr->SectorList[Fls_JobState.JobSectorIt].SectorSize)) && \
                        (Fls_JobState.JobCurrentAddr <= Fls_JobState.JobEndAddr))
                {
                    /* Move on to the next sector */
                    Fls_JobState.JobSectorIt += 1U;
                }
            }
        }
    }
    else
    {
        /* Do nothing - should not happen in Fully Trusted Environment;
        'else' clause added to fulfil MISRA Rule 14.10 */
    }
}
/***************************************************************************************************
*                                          Fls_Lld_SectorWrite
****************************************************************************************************/
FLS_FUNC Fls_Lld_ReturnType Fls_Lld_SectorWrite(const Fls_AddressType DestAddr,
        const Fls_LengthType Length,
        const uint8 *JobDataSrcPtr,
        const boolean AsynchFlag
                                               )
{
    Fls_Lld_ReturnType LldRetVal = FLASH_E_FAILED;
    Fls_Lld_StatusType ReturnCode = STATUS_FTFC_FLS_IP_SUCCESS;
    /*Check EFM Busy or not*/
    if (FALSE == Fls_Lld_CheckIdle())
    {
        ReturnCode = STATUS_FTFC_FLS_IP_BUSY;
        LldRetVal = FLASH_E_PENDING;
    }
    else
    {
        if (TRUE == Fls_Lld_ValidFlash(DestAddr))
        {
            if (TRUE == Fls_Lld_AddrCheckPreWrite(DestAddr, Length, JobDataSrcPtr))/*GCOVR_EXCL_START*/
            {
                /*The integration can't convered, this parameter has been checked in fls.c*/
                ReturnCode = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
                LldRetVal = FLASH_E_FAILED;
                Fls_LLDJobResult = MEMIF_JOB_FAILED;
            }
            /*GCOVR_EXCL_STOP*/
            else
            {
                uint8 CmdCode = 0;
                MemIf_JobResultType TempRetVal = MEMIF_JOB_OK;
                /* Verify blank check before writing the data */
#if ( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
                ReturnCode = Fls_Lld_BlankCheckPreWrite(DestAddr, Length);
                if (STATUS_FTFC_FLS_IP_SUCCESS == ReturnCode)
                {
#endif
#if (STD_ON==FLS_WRITE_VERIFICATION_ENABLED)||(PLATFORM_ENABLE_CACHE==STD_ON)
                    Fls_Lld_u32WritedAddress = DestAddr;
                    Fls_Lld_u32WritedLength = Length;
                    Fls_Lld_pWritedData = JobDataSrcPtr;
#endif
                    /*disable interrupt */
#if (FLS_SCHM_SUPPORT==STD_ON)
                    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_01();
#endif
                    Fls_Lld_EFMNopCommand();
                    Fls_LLDJob = FLASH_JOB_WRITE;
#if defined (CPU_YTM32B1HA0)
                    if (TRUE == Fls_Lld_ValidPFlash(DestAddr))
                    {
                        CmdCode = FLS_PAGE_PROGRAM256_COMMAND_CODE;
                        TempRetVal = Fls_Lld_WriteDataPage(DestAddr, JobDataSrcPtr, FLS_PROG_FLASH_PAGE_SIZE);
                    }
                    else
                    {
                        CmdCode = FLS_PAGE_PROGRAM64_COMMAND_CODE;
                        TempRetVal = Fls_Lld_WriteDataPage(DestAddr, JobDataSrcPtr, FLS_DATA_FLASH_PAGE_SIZE);
                    }
#else
                    CmdCode = FLS_PAGE_PROGRAM_COMMAND_CODE;
                    TempRetVal = Fls_Lld_WriteDataPage(DestAddr, JobDataSrcPtr, FLS_PROG_FLASH_PAGE_SIZE);
#endif
                    if (TempRetVal == MEMIF_JOB_OK)
                    {
                        /* clear the error flags and done flag */
                        Fls_Lld_ClearRegSTS();
                        /*CMD unlock*/
                        Fls_Lld_UnLockCMD();
                        if (FALSE == AsynchFlag)
                        {
                            ReturnCode = Fls_Lld_LoadCommandSync(CmdCode);
                            /*enable interrupt */
#if (FLS_SCHM_SUPPORT==STD_ON)
                            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01();
#endif
                            LldRetVal = Fls_Lld_WriteRstCheck(ReturnCode);
                        }
                        else
                        {
#if(STD_ON == FLS_TIMEOUT_SUPERVISION_ENABLED)
                            Fls_Lld_u32TimeoutCounter = FLS_ASYNC_WRITE_TIMEOUT;
#endif
                            Fls_Lld_LoadCommand(CmdCode);
                            /*enable interrupt */
#if (FLS_SCHM_SUPPORT==STD_ON)
                            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01();
#endif
                            Fls_LLDJobResult = MEMIF_JOB_PENDING;
                            LldRetVal = FLASH_E_PENDING;
                        }
                    }
                    /*GCOVR_EXCL_START*/
                    else
                    {
                        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
                        ReturnCode = STATUS_FTFC_FLS_IP_ERROR;
                        LldRetVal = FLASH_E_FAILED;
                        Fls_LLDJobResult = MEMIF_JOB_FAILED;
                    }
                    /*GCOVR_EXCL_STOP*/
#if ( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
                }
                else
                {
                    ReturnCode = STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK;
                    LldRetVal = FLASH_E_BLOCK_INCONSISTENT;
                    Fls_LLDJobResult = MEMIF_JOB_FAILED;
                }
#endif
            }
        }
        else
        {
            ReturnCode = STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM;
            LldRetVal = FLASH_E_FAILED;
            Fls_LLDJobResult = MEMIF_JOB_FAILED;
        }
    }
    Fls_Lld_eWriteStatus = ReturnCode;
    return LldRetVal;
}

/***************************************************************************************************
*                                          Fls_Lld_Cancel
****************************************************************************************************/
FLS_FUNC Fls_Lld_StatusType Fls_Lld_Cancel(void)
{
    Fls_Lld_StatusType RetVal;
    /* Wait for current pending operation to finish, as there is no hardware way to abort it */
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    uint32 TimeOutCnt = FLS_ABORT_TIMEOUT;
    while ((0U == Fls_Lld_CheckIdle()) && (TimeOutCnt > 0U))
    {
        /* wait until command is finished or timeout*/
        TimeOutCnt -= 1U;
    }
    if (0U != Fls_Lld_CheckIdle())
    {
        /* OK, memory idle */
        RetVal = STATUS_FTFC_FLS_IP_SUCCESS;
    }
    /*GCOVR_EXCL_START*/
    else if (0U == TimeOutCnt)
    {
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        /*error,time out*/
        RetVal = STATUS_FTFC_FLS_IP_ERROR_TIMEOUT;
    }
    /*GCOVR_EXCL_STOP*/
#else
    while (0U == Fls_Lld_CheckIdle())
    {
        /* wait until command is finished */
    }
    if (0U != Fls_Lld_CheckIdle())
    {
        /* OK, memory idle */
        RetVal = STATUS_FTFC_FLS_IP_SUCCESS;
    }
#endif
    /*GCOVR_EXCL_START*/
    else
    {
        /*The integration can't convered, this branch can be accessed only when the EFM hardware fails*/
        /* error, memory controller not idle */
        RetVal = STATUS_FTFC_FLS_IP_ERROR;
    }
    /*GCOVR_EXCL_STOP*/
    return RetVal;
}

/***************************************************************************************************
*                                          Fls_Lld_TranslateReturnCode
****************************************************************************************************/
FLS_FUNC Fls_Lld_ReturnType Fls_Lld_TranslateReturnCode(Fls_Lld_StatusType ReturnCode)
{
    Fls_Lld_ReturnType LldRetVal;
    /* Translate the return code from IPV to HLD */
    switch (ReturnCode)
    {
        case STATUS_FTFC_FLS_IP_SUCCESS:
            /* Operation succeeded */
            LldRetVal = FLASH_E_OK;
            break;
        case STATUS_FTFC_FLS_IP_BUSY:
            /* Operation is pending */
            LldRetVal = FLASH_E_PENDING;
            break;
        case STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK:
            /* Content of flash memory doesn't match with erased value */
            LldRetVal = FLASH_E_BLOCK_INCONSISTENT;
            (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_ERASE_FAILED);
            break;
        case STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY:
            /* Content of flash memory doesn't match with data buffer */
            LldRetVal = FLASH_E_BLOCK_INCONSISTENT;
            (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_VERIFY_WRITE_FAILED);
            break;
        default:
            /* Operation failed due to hardware error */
            LldRetVal = FLASH_E_FAILED;
            break;
    }
    return LldRetVal;
}

/***************************************************************************************************
*                                          Fls_Lld_TranslateReturnCode
****************************************************************************************************/
FLS_FUNC uint16 Fls_Lld_GetPhycSectorSize(Fls_AddressType DestAddr)
{
    uint16 SectorSize;
    if (TRUE == Fls_Lld_ValidPFlash(DestAddr))
    {
        SectorSize = FLS_PROG_FLASH_SECTOR_SIZE;
    }
    else
    {
#if defined(CPU_YTM32B1ME0)||defined(CPU_YTM32B1HA0)||defined (CPU_YTM32B1MC0)
        SectorSize = FLS_DATA_FLASH_SECTOR_SIZE;
#elif defined(CPU_YTM32B1MD1)
        SectorSize = FLS_PROG_FLASH_SECTOR_SIZE;
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
    }
    return SectorSize;
}
#if (FLS_HANDLE_BUSFAULT_INDEPENDENT==STD_ON)
/***************************************************************************************************
*                                          Fls_Lld_TranslateReturnCode
****************************************************************************************************/
FLS_FUNC void Fls_Lld_BusFaultHandler(uint32 *pStack)
{
    if (TRUE == Fls_Lld_GetUnrecoverr())
    {
        uint32 TempMspTopAddr;
        TempMspTopAddr = (uint32)pStack;
        /* set the new pc into the stack pointer*/
        *(uint32 *)(TempMspTopAddr + FLS_PC_TO_MSP_OFFSET * sizeof(uint32)) += 2U;
    }
    /*Call the call back function for app busfault handler*/
    if (Fls_ConfigPtr->BusFaultNotificationFunPtr != NULL_PTR)
    {
        Fls_ConfigPtr->BusFaultNotificationFunPtr();
    }
    SCB->CFSR = SCB_CFSR_BUSFAULTSR_Msk | SCB_CFSR_PRECISERR_Msk; /*PRQA S 0306*/
}
#endif /*(FLS_HANDLE_BUSFAULT_INDEPENDENT==STD_ON)*/
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)
/***************************************************************************************************
*                                          EFM_Ecc_IRQHandler
****************************************************************************************************/
FLS_FUNC ISR(EFM_Ecc_IRQHandler)
{
    /*Notification to App*/
    if (Fls_ConfigPtr->EccErrorNotificationFunPtr != NULL_PTR)
    {
        Fls_ConfigPtr->EccErrorNotificationFunPtr();
    }
    /*Clear the interrupt flag*/
    if (TRUE == Fls_Lld_GetUnrecoverr())
    {
        Fls_Lld_UncorrectableEccFlag = TRUE;
        Fls_Lld_ClearUnrecoverr();
    }
    else
    {
        Fls_Lld_ClearRecoverr();
    }
}
#endif /*(FLS_ECC_ERROR_INTERRUPT_ENABLE==STD_ON)*/

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

