/**************************************************************************************************/
/**
 * @file      : Flash_Drv.c  
 * @brief     : Internal flash low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv
 *  @brief Internal Flash low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Flash_Drv.h"
#include "SchM_Fls.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *	@{
 */
/* Published information */
#define FLASH_DRV_C_VENDOR_ID                   0x00B3U
#define FLASH_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_C_SW_MAJOR_VERSION            1U
#define FLASH_DRV_C_SW_MINOR_VERSION            2U
#define FLASH_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Flash_Drv.h are the same vendor */
#if (FLASH_DRV_C_VENDOR_ID != FLASH_DRV_H_VENDOR_ID) 
    #error "Vendor ID of Flash_Drv.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Autosar version */
#if((FLASH_DRV_C_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (FLASH_DRV_C_AR_RELEASE_MINOR_VERSION != FLASH_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (FLASH_DRV_C_AR_RELEASE_REVISION_VERSION != FLASH_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Flash_Drv.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Software version */
#if((FLASH_DRV_C_SW_MAJOR_VERSION != FLASH_DRV_H_SW_MAJOR_VERSION) || \
    (FLASH_DRV_C_SW_MINOR_VERSION != FLASH_DRV_H_SW_MINOR_VERSION) || \
    (FLASH_DRV_C_SW_PATCH_VERSION != FLASH_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Flash_Drv.c and Flash_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and SchM_Fls.h are the same Autosar version */
    #if ((FLASH_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_FLS_H_AR_RELEASE_MAJOR_VERSION) ||       \
         (FLASH_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_FLS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Flash_Drv.c and SchM_Fls.h are different"
    #endif

    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((FLASH_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||       \
         (FLASH_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Flash_Drv.c and Device_Regs.h are different"
    #endif
#endif

#define FLASH_DRV_CMDABT_MSK       0x00000004U
#define FLASH_DRV_ACCERR_MSK       0x00000020U
#define FLASH_DRV_PREABT_MSK       0x00000040U  

#define FLASH_DRV_DFDIF_MASK       0x00010000U
#define FLASH_DRV_SFDIF_MASK       0x00020000U
#if (STD_ON == FLASH_DRV_ECC_CHECK_INT)
#define FLASH_DRV_ECC_MASK         ((uint32)FLASH_DRV_DFDIF_MASK | (uint32)FLASH_DRV_SFDIF_MASK)
#endif

#define FLASH_DRV_W1C_MASK         ((uint32)FLASH_DRV_CMDABT_MSK | (uint32)FLASH_DRV_ACCERR_MSK\
                                  | (uint32)FLASH_DRV_PREABT_MSK | (uint32)FLASH_DRV_DFDIF_MASK\
                                  | (uint32)FLASH_DRV_SFDIF_MASK)

/**
 *  @brief Macro for Call Access Code
 */
#define FLASH_DRV_CALL_AC(Ptr2Fcn, Ptr2FcnType) ((Ptr2FcnType)(((uint32)(Ptr2Fcn)) | 0x00000001U))
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/**
 *  @brief FLASH command type definition
 */
typedef enum
{
    FLASH_DRV_CMD_PGMPHR = 0x24U,   /*!< Program data to a flash or IFR phrase */
    FLASH_DRV_CMD_ERSSCR = 0x42U    /*!< Erase a flash sector */
}Flash_Drv_CmdType;
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
uint32 Flash_Drv_ElapsedTicks;
uint32 Flash_Drv_TimeoutTicks;
#endif /* (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
Flash_Drv_ReadStateType Flash_Drv_ReadState;
#define FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h" 
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
static uint32 Flash_Drv_CurrentTicks;
#endif /* (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_PTR
#include "Fls_MemMap.h"
/**
 * @brief Pointer to current flash configuration set
 */
static const Flash_Drv_ConfigType * Flash_Drv_ConfigPtr;
#define FLS_STOP_SEC_VAR_CLEARED_PTR
#include "Fls_MemMap.h"	

#define FLS_START_SEC_CONST_PTR
#include "Fls_MemMap.h"

/*!< Flash Unit Register */
static Reg_Flash_BfType *const Fls_Drv_FlsRegBfPtr = (Reg_Flash_BfType *) FLASHC_BASE_ADDR;
static Reg_Flash_WType *const Fls_Drv_FlsRegWPtr = (Reg_Flash_WType *) FLASHC_BASE_ADDR;

#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
/*!< SCM Unit Register */
static Reg_Scm_BfType *const Fls_Drv_ScmRegBfPtr = (Reg_Scm_BfType *)SCM_BASE_ADDR;
#endif

#define FLS_STOP_SEC_CONST_PTR
#include "Fls_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

#if(FLASH_DRV_ECC_CHECK_INT == STD_ON)
ISR(Flash_Drv_EccIrqHandler);
#endif /* FLASH_DRV_ECC_CHECK_INT == STD_ON */
static boolean Flash_Drv_CheckAddr(const uint32 Addr);
static boolean Flash_Drv_CheckValidRange(const uint32 StartAddr, const uint32 Length);
static Flash_Drv_ReturnType Flash_Drv_CheckReadParam(const uint32 SrcAddress, const uint8 *DestPtr, 
                                                     const uint32 Length);
static uint32 Flash_Drv_ComputeReadSize(uint32 SrcAddr, uint32 DesAddr, uint32 Len);
static void Flash_Drv_ReadData(uint32 ReadSize, const uint32 * ReadAddr, uint32 * DesAddr);
static Flash_Drv_ReturnType Flash_Drv_CompareData(uint32 ReadSize, const uint32 * ReadAddr, 
                                                  const uint32 * CompareAddr);
static Flash_Drv_ReturnType Flash_Drv_BlankCheckData(uint32 ReadSize, const uint32 * ReadAddr);
static void Flash_Drv_ConfigCommand(Flash_Drv_CmdType Cmd, uint32 DestAddr, 
                                    const uint8 * SrcAddrPtr);
static void Flash_Drv_CallStartNotif(void);
static void Flash_Drv_CallFinishNotif(void);
static void Flash_Drv_StartCmd(void);
static Flash_Drv_ReturnType Flash_Drv_ExecuteCmd(void (*CallBack)(void), 
                                                 void (*AcFunc)(void (*CallBack)(void)));
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
static void Flash_Drv_ClearCache(void);
#endif
static void Flash_Drv_IgnoreBusErrorConfig(uint32 StartAddr, uint32 EndAddr);
static Flash_Drv_ReturnType Flash_Drv_WritePhrase(const uint32 FlashAddr,const uint8 *SourceAddrPtr,
                                                  const Flash_Drv_CmdActionType * CmdActPtr);
static uint8 Flash_Drv_GetStatus(Flash_Drv_StatusType Stat);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/**
 * @brief     Check if the input address is valid or not
 *
 * @param[in] Addr: Flash address 
 *
 * @return    boolean
 *
 */
static boolean Flash_Drv_CheckAddr(const uint32 Addr)
{
    boolean Ret;

    if(FLASH_DRV_VALID_FLASH_ADDR(Addr))
    {
        Ret = (boolean)TRUE;
    }
    else
    {
        Ret = (boolean)FALSE;
    }

    return Ret;
}

/**
 * @brief  Check the input parameters address and length range
 *
 * @param[in] StartAddr: start address 
 * @param[in] Length: the length of data in byte
 *
 * @return    boolean
 *
 */
static boolean Flash_Drv_CheckValidRange(const uint32 StartAddr, const uint32 Length)
{
    boolean Ret;
    uint32 EndAddr = StartAddr + Length - 1UL;

	Ret = Flash_Drv_CheckAddr(StartAddr);
	Ret &= Flash_Drv_CheckAddr(EndAddr);
	
    if(((boolean)TRUE == Ret) && (Length > 0U))
    {
        Ret = (boolean)TRUE;
    }
    else
    {
        Ret = (boolean)FALSE;
    }

    return Ret;
}

/**
 * @brief  Check the input parameters of read function 
 *
 * @param[in] SrcAddress: start address where to read in the flash memory.
 * @param[in] DestPtr: it points to the destination buffer start address
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 *
 */
static Flash_Drv_ReturnType Flash_Drv_CheckReadParam(const uint32 SrcAddress, const uint8 *DestPtr, 
                                                     const uint32 Length)
{
    Flash_Drv_ReturnType Ret;

    if((NULL_PTR == DestPtr) || ((boolean)FALSE == Flash_Drv_CheckValidRange(SrcAddress, Length)))
    {
        Ret = FLASH_DRV_ERR_INPUT_PARAM;
    }
    else
    {
        Ret = FLASH_DRV_SUCCESS;
    }

    return Ret;
}

/**
 * @brief Compute the data size, considering the address alignment and the length.
 *
 * @param[in]  SrcAddr: the source address
 * @param[in]  DesAddr: the destination address
 * @param[in]  Len: length in byte
 *
 * @return the data size in byte
 * @retval 1U     1 byte
 * @retval 2U     2 bytes
 * @retval 4U     4 bytes
 */
static uint32 Flash_Drv_ComputeReadSize(uint32 SrcAddr, uint32 DesAddr, uint32 Len)
{
    uint32 ReadSize = 1U;
    uint32 CombinedAddr = SrcAddr | DesAddr;

    if(0UL == (CombinedAddr & 0x03U))
    {
        if (Len >= 4U)
        {
            ReadSize = 4U;
        }
        else if(Len >= 2U)
        {
            ReadSize = 2U;
        }
		else
		{
			/*do nothing*/
		}
    }
    else if((0UL == (CombinedAddr & 0x01UL)) && (Len >= 2U))
    {
        ReadSize = 2U;
    }
	else
	{
		/*do nothing*/
	}

    return ReadSize;
}

/**
 * @brief     read data from flash with specified size
 *
 * @param[in]  ReadSize: the read size
 * @param[in]  ReadAddr: the source address
 * @param[in]  DesAddr: the destination buffer address
 *
 * @return none
 */
static void Flash_Drv_ReadData(uint32 ReadSize, const uint32 * ReadAddr, uint32 * DesAddr)
{
    uint32 ReadData = *ReadAddr;
    
    switch (ReadSize)
    {
        case 4U:
            *DesAddr = ReadData;
            break;

        case 2U:
            *DesAddr = (*DesAddr & 0xFFFF0000U) | (ReadData & 0xFFFFU);
            break;

        case 1U:
            *(uint8 *)DesAddr = (uint8)(ReadData & 0xFFU);
            break;

        default:
            /*do nothing*/
            break;
    }
}

/**
 * @brief     compare data from flash with compare buffer in specified size
 *
 * @param[in]  ReadSize: the read size
 * @param[in]  ReadAddr: the source address
 * @param[in]  CompareAddr: point to the destination buffer
 *
 * @return Flash_Drv_ReturnType
 * @retval FLASH_DRV_ERR_COMPARE
 * @retval FLASH_DRV_SUCCESS
 */
static Flash_Drv_ReturnType Flash_Drv_CompareData(uint32 ReadSize, const uint32 * ReadAddr, 
                                                  const uint32 * CompareAddr)
{
	Flash_Drv_ReturnType Ret = FLASH_DRV_ERR_COMPARE;
    uint32 ReadData = *ReadAddr;
    uint32 CompareData = *CompareAddr;

    switch (ReadSize)
    {
        case 4U:
            if(CompareData == ReadData)
            {
				Ret = FLASH_DRV_SUCCESS;
            }
            break;

        case 2U:
            if((CompareData & 0xFFFFU) == (ReadData & 0xFFFFU))
            {
				Ret = FLASH_DRV_SUCCESS;
            }
            break;

        case 1U:
            if((CompareData & 0xFFU) == (ReadData & 0xFFU))
            {
				Ret = FLASH_DRV_SUCCESS;
            }
            break;

        default:
			/*do nothing*/
            break;
    }

    return Ret;
}

/**
 * @brief     Check if the data with specified size in flash is erased value 
 *
 * @param[in]  ReadSize: the read size
 * @param[in]  ReadAddr: the source address
 *
 * @return Flash_Drv_ReturnType
 * @retval FLASH_DRV_ERR_BLANK_CHECK
 * @retval FLASH_DRV_SUCCESS
 */
static Flash_Drv_ReturnType Flash_Drv_BlankCheckData(uint32 ReadSize, const uint32 * ReadAddr)
{
	Flash_Drv_ReturnType Ret = FLASH_DRV_ERR_BLANK_CHECK;
    uint32 ReadData = *ReadAddr;

    switch (ReadSize)
    {
        case 4U:
            if(FLASH_DRV_ERASED_VALUE == ReadData)
            {
				Ret = FLASH_DRV_SUCCESS;
            }
            break;

        case 2U:
            if((uint16)FLASH_DRV_ERASED_VALUE == (ReadData & 0xFFFFU))
            {
				Ret = FLASH_DRV_SUCCESS;
            }
            break;

        case 1U:
            if((uint8)FLASH_DRV_ERASED_VALUE == (ReadData & 0xFFU))
            {
				Ret = FLASH_DRV_SUCCESS;
            }
            break;

        default:
            /*do nothing*/
            break;
    }

    return Ret;
}

/**
 * @brief     configure the command registers 
 *
 * @param[in]  Cmd: the command to be configured
 * @param[in]  DestAddr: the flash operation address
 * @param[in]  SrcAddrPtr: point to the data buffer
 * 
 * @return none
 */
static void Flash_Drv_ConfigCommand(Flash_Drv_CmdType Cmd, uint32 DestAddr, 
                                        const uint8 * SrcAddrPtr)
{
    volatile uint8 *FlashData = (volatile uint8 *)&(Fls_Drv_FlsRegWPtr->FLASH_FDATA0);

    Fls_Drv_FlsRegWPtr->FLASH_FADDR = DestAddr;
    Fls_Drv_FlsRegBfPtr->FLASH_FCMD.CMDCODE = (uint32)Cmd;

    if(SrcAddrPtr != NULL_PTR)
    {
        for(uint8 i = 0U; i < FLASH_DRV_PHRASE_SIZE; i++)
        {
            FlashData[i] = SrcAddrPtr[i];
        }
    }

	SchM_Enter_Fls_FCTRL();
    Fls_Drv_FlsRegBfPtr->FLASH_FCTRL.ABTREQ = 0U;
	SchM_Exit_Fls_FCTRL();
	
    /* clear ACCERR, CMDABT, PREABT if any is set */
    Fls_Drv_FlsRegWPtr->FLASH_FSTAT = (FLASH_DRV_CMDABT_MSK) | (FLASH_DRV_ACCERR_MSK) | 
                                      (FLASH_DRV_PREABT_MSK);
}

/**
 * @brief     call the start notification before flash erase/program 
 *
 * @param[in]  None
 *
 * @return none
 */
static void Flash_Drv_CallStartNotif(void)
{
    if (NULL_PTR != Flash_Drv_ConfigPtr->StartNotifPtr)
    {
        (Flash_Drv_ConfigPtr->StartNotifPtr)();
    }
}

/**
 * @brief     call the finish notification after flash erase/program 
 *
 * @param[in]  None
 *
 * @return none
 */
static void Flash_Drv_CallFinishNotif(void)
{
    if (NULL_PTR != Flash_Drv_ConfigPtr->FinishNotifPtr)
    {
        (Flash_Drv_ConfigPtr->FinishNotifPtr)();
    }
}

/**
 * @brief      Clear CCIF flag to start flash cmd 
 *
 * @param[in]  None
 *
 * @return     None
 */
static void Flash_Drv_StartCmd(void)
{
	uint32 PriMaskReg = 0U;
    uint32 CmdAddr = Fls_Drv_FlsRegWPtr->FLASH_FADDR;

    PriMaskReg = McalLib_ReadPriMaskReg();

	/* Suspend all interrupts */
	if (0U == PriMaskReg)
	{
	    SuspendAllInterrupts();
	}
	
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
	/* Disable cache */
	Fls_Drv_ScmRegBfPtr->SCM_MISCCTL1.CACHE_DIS = 1U;
    /* Perform cache clear */
    Fls_Drv_ScmRegBfPtr->SCM_MISCCTL1.CCACHE_CLR = 1U;
    /* Finish cache clear */
    Fls_Drv_ScmRegBfPtr->SCM_MISCCTL1.CCACHE_CLR = 0U;
#endif

    /* command is executing on PFlash or PFlash IFR */
    if(FLASH_DRV_VALID_PFLASH_ADDR(CmdAddr) || FLASH_DRV_VALID_PFLASH_IFR_ADDR(CmdAddr))
    {
        /* read DFlash */
        ASM_KEYWORD volatile (
        "PUSH  {R0, R1}\n"
        "LDR   R0, =0x01000000\n"
        "LDR   R1, [R0]\n"
        "POP   {R0, R1}\n"
        );
    }
    /* command is executing on DFlash */
    else if(FLASH_DRV_VALID_DFLASH_ADDR(CmdAddr))
    {
        /* read PFlash IFR */
        ASM_KEYWORD volatile (
        "PUSH  {R0, R1}\n"
        "LDR   R0, =0x02000000\n"
        "LDR   R1, [R0]\n"
        "POP   {R0, R1}\n"
        );
    } 
    else 
    {
        /* do nothing */
    }

    ASM_KEYWORD volatile (
        "PUSH  {R0, R1, R2}\n"
		"LDR   R0, =0x40020000\n"
		"LDR   R1, =0x80\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"STR   R1, [R0]\n"
		"LDR   R2, [R0]\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
        "POP  {R0, R1, R2}\n"
        );

#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
	/* Enable cache */
	Fls_Drv_ScmRegBfPtr->SCM_MISCCTL1.CACHE_DIS = 0U;
#endif

    /* Resume all interrupts */
    if (0U == PriMaskReg)
    {
        ResumeAllInterrupts();
    }
}

/**
 * @brief     Execute command and wait for the completion 
 *
 * @param[in] CallBack: It points to the callback function that is not in the same flash block that
 *                      flash commands is executing in. It will be called while waiting for 
 *                      completing the command.  If no callback function is needed, please set
 *                      this parameter to NULL.                    
 * @param[in] AcFunc: It points to a access code function which is in the SRAM. If it is not NULL, 
 *                    AcFunc will be called to wait for the command finishing. If it is NULL,
 *                    Flash_Drv_WaitFor() will be called to wait for the command finishing
 *
 * @return Flash_Drv_ReturnType
 * @retval FLASH_DRV_SUCCESS
 * @retval FLASH_DRV_ERR
 * @retval FLASH_DRV_ERR_TIMEOUT
 */
static Flash_Drv_ReturnType Flash_Drv_ExecuteCmd(void (*CallBack)(void), 
                                                 void (*AcFunc)(void (*CallBack)(void)))
{
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    uint32 ElapsedTicks = 0U;
#endif /* FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

    Flash_Drv_ReturnType Ret;

    if(AcFunc != NULL_PTR)
    {
        Flash_Drv_CallStartNotif();
        FLASH_DRV_CALL_AC(AcFunc,Flash_Drv_AcPtrType)(CallBack);
        Flash_Drv_CallFinishNotif();
    }
    else
    {
        /* clear CCIF to start cmd */
        Flash_Drv_StartCmd();

#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        while((Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 0U) && 
              (Flash_Drv_ElapsedTicks < Flash_Drv_TimeoutTicks))
        {
            if(CallBack != NULL_PTR)
            {
                CallBack();
            }
            (void)McalLib_GetElapsedValue(FLASH_DRV_TIMEOUT_TYPE, &Flash_Drv_CurrentTicks, &ElapsedTicks);
            Flash_Drv_ElapsedTicks += ElapsedTicks;
        }
#else
        while(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 0U)
        {
            if(CallBack != NULL_PTR)
            {
                CallBack();
            }
        }
#endif /* FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON */        
    }

	SchM_Enter_Fls_TransferStatus();
    if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF != 0U)
    {
        if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.ACCERR != 0U)
        {
            Ret = FLASH_DRV_ERR;
            /* clear ACCERR flag*/
            Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_ACCERR_MSK;
        }
        else
        {
            Ret = FLASH_DRV_SUCCESS; 
        }                    
    }
    else
    {
        Ret = FLASH_DRV_ERR_TIMEOUT;
    }
	SchM_Exit_Fls_TransferStatus();
	
    return Ret;
}

#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
/**
 * @brief      Clear cache after each flash write or erase command completion, or somewhere else 
 *             if needed.
 *
 * @param[in]  none
 *
 * @return     none
 *
 */
static void Flash_Drv_ClearCache(void)
{
    SchM_Enter_Fls_ClearCache();
	/* Perform cache clear */
    Fls_Drv_ScmRegBfPtr->SCM_MISCCTL1.CCACHE_CLR = 1U;
    /* Finish cache clear */
    Fls_Drv_ScmRegBfPtr->SCM_MISCCTL1.CCACHE_CLR = 0U;
    SchM_Exit_Fls_ClearCache();
}
#endif

/**
 * @brief      configure a range of Flash to not generate bus error when 
 *             multi-bit ECC error happens.
 *
 * @param[in]  StartAddr: The start address of flash to ignore bus error. It 
 *                        should be 16-byte aligned, the lowest 4 bits of 
 *                        starAddr shall always be 0.
 * @param[in]  EndAddr: The end address of flash to ignore bus error. It 
 *                        should be 16-byte aligned, the lowest 4 bits of 
 *                        starAddr shall always be 0.
 *
 * @return     none
 *
 */
static void Flash_Drv_IgnoreBusErrorConfig(uint32 StartAddr, uint32 EndAddr)
{
	Fls_Drv_FlsRegBfPtr->FLASH_BED_ADDR_STRT.BED_ADDR_STRT = StartAddr >> 4U;
    Fls_Drv_FlsRegBfPtr->FLASH_BED_ADDR_END.BED_ADDR_END = EndAddr >> 4U;
}

/**
 * @brief  Program a phrase of data into the flash memory array. 
 *
 * @param[in] FlashAddr: phrase start address where to write in the flash memory. This address 
 *                       should be aligned to 4 words(16 bytes)
 * @param[in] SourceAddrPtr: point to the Source buffer
 * @param[in] CmdActPtr: It points to the command action configuration.
 *
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
static Flash_Drv_ReturnType Flash_Drv_WritePhrase(const uint32 FlashAddr,const uint8 *SourceAddrPtr,
                                                  const Flash_Drv_CmdActionType * CmdActPtr)
{
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
    boolean AddrValid = Flash_Drv_CheckAddr(FlashAddr) &
                        (boolean)FLASH_DRV_PHRASE_ALIGNED(FlashAddr);

	MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(AddrValid);
#endif

    if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 0U)
    {
        Ret = FLASH_DRV_BUSY;
    }
    else
    {
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        (void)McalLib_GetCounterValue(FLASH_DRV_TIMEOUT_TYPE, &Flash_Drv_CurrentTicks);
        Flash_Drv_ElapsedTicks = 0U;
        if(CmdActPtr->AcFunc == NULL_PTR)
        {
            Flash_Drv_TimeoutTicks = McalLib_MicroSecToTicks(FLASH_DRV_TIMEOUT_TYPE, 
                                                        FLASH_DRV_TIMEOUT_WRITE);
        }
        else
        {
            Flash_Drv_TimeoutTicks = McalLib_MicroSecToTicks(MCALLIB_COUNTER_SOFTWARE, 
                                                        FLASH_DRV_TIMEOUT_WRITE_IN_AC);
        }
#endif /* (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
        
        Flash_Drv_ConfigCommand(FLASH_DRV_CMD_PGMPHR, FlashAddr, SourceAddrPtr);

        if((CmdActPtr->AsyncFlag) == FALSE)
        {
            Ret = Flash_Drv_ExecuteCmd(CmdActPtr->CallBack, CmdActPtr->AcFunc);
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
            Flash_Drv_ClearCache();
#endif
        }
        else
        {
            Flash_Drv_StartCmd();
        }            
    }

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief      Get FLASHC status
 *
 * @param[in]  Stat: the status to be get
 *
 * @return     the status
 *
 */ 
static uint8 Flash_Drv_GetStatus(Flash_Drv_StatusType Stat)
{
    uint8 Status;
    
    Status = (((Fls_Drv_FlsRegWPtr->FLASH_FSTAT) & (uint32)Stat) == 0U)? STD_IDLE: STD_ACTIVE;
    
    return Status;
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
 * @brief     De-initialize flash
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Flash_Drv_DeInit(void)
{
    /* disable interrupts and clear interrupt flag */
    Fls_Drv_FlsRegBfPtr->FLASH_FCNFG.SFDIE = 0U;
    Fls_Drv_FlsRegBfPtr->FLASH_FCNFG.DFDIE = 0U;
    Fls_Drv_FlsRegWPtr->FLASH_FSTAT = ((uint32)FLASH_DRV_DFDIF_MASK | (uint32)FLASH_DRV_SFDIF_MASK);
}

/**
 * @brief     Initialize internal flash 
 *
 * @param[in] ConfigPtr: Pointer to internal flash driver configuration parameters.
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR_HW_FAIL
 *
 */
Flash_Drv_ReturnType Flash_Drv_Init(const Flash_Drv_ConfigType* ConfigPtr)
{
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
#endif

    Flash_Drv_ConfigPtr = ConfigPtr;

	if(Flash_Drv_GetStatus(FLASH_DRV_STATUS_FAIL) == STD_ACTIVE)
    {
		Ret = FLASH_DRV_ERR_HW_FAIL;
    }
    else
    {
        if(Flash_Drv_GetStatus(FLASH_DRV_STATUS_CCIF) == STD_IDLE)
        {
		    /* flash command execution,or initialization or power mode recovery is ongoing */
            Ret = FLASH_DRV_BUSY;
        }
        else
        {
            /* clear the status when FLASH_DRV_STATUS_CCIF is SET */
            Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_W1C_MASK;
            Flash_Drv_IgnoreBusErrorConfig(ConfigPtr->IgnoreBusErrStartAddr, 
                                           ConfigPtr->IgnoreBusErrEndAddr);
            
#if(FLASH_DRV_ECC_SB_INT == STD_ON)
            Fls_Drv_FlsRegBfPtr->FLASH_FCNFG.SFDIE = 1U;
#endif

#if(FLASH_DRV_ECC_MB_INT == STD_ON)
            Fls_Drv_FlsRegBfPtr->FLASH_FCNFG.DFDIE = 1U;
#endif 
        }        
    }   

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/** 
 * @brief     Check if the flash controller is idle or not
 *
 * @param[in] none
 *
 * @return    boolean
 * @retval    TRUE: flash controller is idle
 * @retval    FALSE: flash controller is busy
 *
 */
boolean Flash_Drv_CheckIdleStatus(void)
{
    return Flash_Drv_GetStatus(FLASH_DRV_STATUS_CCIF);
}

/**
 * @brief     Abort flash operation. 
 *
 * @param[in] none
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS - command is finished successfully, so no command is aborted
 * @retval    FLASH_DRV_CMD_ABORTED
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
Flash_Drv_ReturnType Flash_Drv_Abort(void)
{
    volatile uint32 LocalCnt = 0U;
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
    volatile uint32 LoopFlag = 1U;

    /* No flash command is being executed */
    if (Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 1U)
    {
        Ret = FLASH_DRV_SUCCESS;
    }
    else
    {
		/* Abort executing flash command */
		SchM_Enter_Fls_FCTRL();
        Fls_Drv_FlsRegBfPtr->FLASH_FCTRL.ABTREQ = 1U;
		SchM_Exit_Fls_FCTRL();

        while(LoopFlag != 0U)
        {
			SchM_Enter_Fls_TransferStatus();
			if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 1U)
            {
                if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CMDABT == 1U)
                {
                    /* clear CMDABT flag */
                    Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_CMDABT_MSK;
					SchM_Exit_Fls_TransferStatus();
                    Ret = FLASH_DRV_CMD_ABORTED;
                    LoopFlag = 0U;
                }
                else
                {
                    /* clear PREABT flag */
                    Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_PREABT_MSK;
					SchM_Exit_Fls_TransferStatus();
                    Ret = FLASH_DRV_SUCCESS;
                    LoopFlag = 0U;
                }
            }
            else
            {
				SchM_Exit_Fls_TransferStatus();
				if(LocalCnt > FLASH_DRV_TIMEOUT_ABORT_WAIT_CNT)
                {
                    Ret = FLASH_DRV_ERR_TIMEOUT;
                    LoopFlag = 0U;
                }
                else
                {
                    LocalCnt++;
                }
            }
        }
    }

    return Ret;
}

/**
 * @brief     Erase one flash sector 
 *
 * @param[in] Addr: sector start address in flash memory.
 * @param[in] CmdActPtr: It points to the command action configuration.
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
Flash_Drv_ReturnType Flash_Drv_EraseSector(const uint32 Addr, 
                                           const Flash_Drv_CmdActionType * CmdActPtr)
{
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
    boolean AddrValid = Flash_Drv_CheckAddr(Addr) &
		                (boolean)FLASH_DRV_SECTOR_ALIGNED(Addr);

    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(AddrValid);
#endif

    if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 0U)
    {
        Ret = FLASH_DRV_BUSY;
    }
    else
    {
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        (void)McalLib_GetCounterValue(FLASH_DRV_TIMEOUT_TYPE, &Flash_Drv_CurrentTicks);
        Flash_Drv_ElapsedTicks = 0U;
        if(CmdActPtr->AcFunc == NULL_PTR)
        {
            Flash_Drv_TimeoutTicks = McalLib_MicroSecToTicks(FLASH_DRV_TIMEOUT_TYPE, 
                                                        FLASH_DRV_TIMEOUT_ERASE);
        }
        else
        {
            Flash_Drv_TimeoutTicks = McalLib_MicroSecToTicks(MCALLIB_COUNTER_SOFTWARE, 
                                                        FLASH_DRV_TIMEOUT_ERASE_IN_AC);
        }
#endif /* (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
        
        Flash_Drv_ConfigCommand(FLASH_DRV_CMD_ERSSCR, Addr, NULL_PTR);

        if((CmdActPtr->AsyncFlag) == FALSE)
        {
            Ret = Flash_Drv_ExecuteCmd(CmdActPtr->CallBack, CmdActPtr->AcFunc);
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
            Flash_Drv_ClearCache();
#endif
        }
        else
        {
            Flash_Drv_StartCmd();
        }            
    }

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief  Program data with specified length into the flash memory array. 
 *
 * @param[in] FlashAddr: phrase start address where to write in the flash memory. This address 
 *                       should be aligned to 4 words(16 bytes)
 * @param[in] Len: the length of data to be written. This length should be aligned to 
 *                 4 words(16 bytes).
 * @param[in] SourceAddrPtr: point to the Source buffer
 * @param[in] CmdActPtr: It points to the command action configuration.
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
Flash_Drv_ReturnType Flash_Drv_Write(const uint32 FlashAddr, const uint32 Len,
                                     const uint8 *SourceAddrPtr,  
                                     const Flash_Drv_CmdActionType * CmdActPtr)
{
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
    uint32 Count;
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
    boolean ParaValid = (Flash_Drv_CheckAddr(FlashAddr)) & 
                 (boolean)(FLASH_DRV_PHRASE_ALIGNED(FlashAddr) && FLASH_DRV_PHRASE_ALIGNED(Len));

	MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(ParaValid);
#endif

    for(Count = 0U; Count < Len; Count += 16U)
    {
        Ret = Flash_Drv_WritePhrase((FlashAddr + Count), &(SourceAddrPtr[Count]), CmdActPtr);

        if(Ret != FLASH_DRV_SUCCESS)
        {
            break;
        }
    }

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief  Read data from the flash memory array. 
 *
 * @param[in] SrcAddr: start address where to read in the flash memory.
 * @param[in] DestAddrPtr: it points to the destination buffer start address
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 * @retval    FLASH_DRV_ERR_ECC_M
 *
 */
Flash_Drv_ReturnType Flash_Drv_Read(uint32 SrcAddr, uint8 const *DestAddrPtr, uint32 Length)
{
    Flash_Drv_ReturnType Ret = Flash_Drv_CheckReadParam(SrcAddr, DestAddrPtr, Length);
    uint32 RemainBytes = Length;
    uint32 ReadAddr = SrcAddr;
    uint32 CurDesAddr  = (uint32)DestAddrPtr;
    uint32 ReadSize = 1U;

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(FLASH_DRV_SUCCESS == Ret);
#endif

    Flash_Drv_ReadState.Status = FLASH_DRV_READ_BUSY;
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
    Flash_Drv_ClearCache();
#endif
    while((RemainBytes > 0U) && (Flash_Drv_ReadState.Status != FLASH_DRV_READ_ERROR))
    {
#if(FLASH_DRV_ECC_CHECK_INT == STD_ON)
        Flash_Drv_ReadState.Address = ReadAddr;
#endif /* FLASH_DRV_ECC_CHECK_INT == STD_ON */
        /* clear error status */
        Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_DFDIF_MASK;
        Fls_Drv_FlsRegWPtr->FLASH_MBE_STATE = 1U;

        ReadSize = Flash_Drv_ComputeReadSize(ReadAddr, CurDesAddr, RemainBytes);
        
        Flash_Drv_ReadData(ReadSize, (uint32 *)ReadAddr, (uint32 *)CurDesAddr);
#if(FLASH_DRV_ECC_MB_INT == STD_OFF)
        if(Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_FLAG != 0U)
        {
            if((ReadAddr >> 4U) == Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_ADDR)
            {
                Flash_Drv_ReadState.Status = FLASH_DRV_READ_ERROR;
            }
        }
#endif /* FLASH_DRV_ECC_MB_INT == STD_OFF */

        ReadAddr += ReadSize;
        CurDesAddr += ReadSize;
        RemainBytes -= ReadSize;
    }

    if (FLASH_DRV_READ_ERROR == Flash_Drv_ReadState.Status)
    {
        Ret = FLASH_DRV_ERR_ECC_M;
    }
    
    Flash_Drv_ReadState.Status = FLASH_DRV_READ_IDLE;
	
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief  Compare data in the flash memory with the expected value. 
 *
 * @param[in] SrcAddr: start address where to read in the flash memory.
 * @param[in] CompareBufPtr: it points to the start address where the expected values are stored
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS - all the values are the same as the expected value
 * @retval    FLASH_DRV_ERR_ECC_M
 * @retval    FLASH_DRV_ERR_COMPARE
 *
 */
Flash_Drv_ReturnType Flash_Drv_Compare(uint32 SrcAddr, const uint8 *CompareBufPtr, uint32 Length)
{
    Flash_Drv_ReturnType Ret = Flash_Drv_CheckReadParam(SrcAddr, CompareBufPtr, Length);
    uint32 RemainBytes = Length;
    uint32 ReadAddr = SrcAddr;
    uint32 CurCompareAddr  = (uint32)CompareBufPtr;
    uint32 ReadSize = 1U;

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(FLASH_DRV_SUCCESS == Ret);
#endif

    Flash_Drv_ReadState.Status = FLASH_DRV_READ_BUSY;
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
    Flash_Drv_ClearCache();
#endif

    while((RemainBytes > 0U) && (Flash_Drv_ReadState.Status != FLASH_DRV_READ_ERROR) && 
          (Ret == FLASH_DRV_SUCCESS))
    {
#if(FLASH_DRV_ECC_CHECK_INT == STD_ON)
        Flash_Drv_ReadState.Address = ReadAddr;
#endif /* FLASH_DRV_ECC_CHECK_INT == STD_ON */
        /* clear error status */
        Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_DFDIF_MASK;
        Fls_Drv_FlsRegWPtr->FLASH_MBE_STATE = 1U;

        ReadSize = Flash_Drv_ComputeReadSize(ReadAddr, CurCompareAddr, RemainBytes);
        Ret = Flash_Drv_CompareData(ReadSize, (uint32 *)ReadAddr, (uint32 *)CurCompareAddr);

#if(FLASH_DRV_ECC_MB_INT == STD_OFF)
        if(Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_FLAG != 0U)
        {
            if((ReadAddr >> 4U) == Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_ADDR)
            {
                Flash_Drv_ReadState.Status = FLASH_DRV_READ_ERROR;
            }
        }
#endif /* FLASH_DRV_ECC_MB_INT == STD_OFF */

        ReadAddr += ReadSize;
        CurCompareAddr += ReadSize;
        RemainBytes -= ReadSize;
    }

    if((FLASH_DRV_READ_ERROR == Flash_Drv_ReadState.Status) && (FLASH_DRV_SUCCESS == Ret)) 
    {
        /* exit loop due to ECC error */
        Ret = FLASH_DRV_ERR_ECC_M;
    }
    else
    {
    	
    }
    
    Flash_Drv_ReadState.Status = FLASH_DRV_READ_IDLE;
	
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief  Check if the data value in the flash memory is the erased value. 
 *
 * @param[in] SrcAddr: start address where to check in the flash memory.
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS - all the data checked are erased value
 * @retval    FLASH_DRV_ERR_ECC_M
 * @retval    FLASH_DRV_ERR_BLANK_CHECK
 *
 */
Flash_Drv_ReturnType Flash_Drv_CheckBlank(uint32 SrcAddr, uint32 Length)
{
    Flash_Drv_ReturnType Ret = FLASH_DRV_SUCCESS;
    uint32 RemainBytes = Length;
    uint32 ReadAddr = SrcAddr;
    uint32 ReadSize = 1U;
#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
    boolean ParamCheck = Flash_Drv_CheckValidRange(SrcAddr, Length);

	MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT(TRUE == ParamCheck);
#endif

    Flash_Drv_ReadState.Status = FLASH_DRV_READ_BUSY;
#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
    Flash_Drv_ClearCache();
#endif

    while((RemainBytes > 0U) && (Flash_Drv_ReadState.Status != FLASH_DRV_READ_ERROR) && 
          (Ret == FLASH_DRV_SUCCESS))
    {
#if(FLASH_DRV_ECC_CHECK_INT == STD_ON)
        Flash_Drv_ReadState.Address = ReadAddr;
#endif /* FLASH_DRV_ECC_CHECK_INT == STD_ON */
        /* clear error status */
        Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_DFDIF_MASK;
        Fls_Drv_FlsRegWPtr->FLASH_MBE_STATE = 1U;

        ReadSize = Flash_Drv_ComputeReadSize(ReadAddr, 0U, RemainBytes);
        Ret = Flash_Drv_BlankCheckData(ReadSize, (uint32 *)ReadAddr);
            
#if(FLASH_DRV_ECC_MB_INT == STD_OFF)
        if(Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_FLAG != 0U)
        {
            if((ReadAddr >> 4U) == Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_ADDR)
            {
                Flash_Drv_ReadState.Status = FLASH_DRV_READ_ERROR;
            }
        }
#endif /* FLASH_DRV_ECC_MB_INT == STD_OFF */

        ReadAddr += ReadSize;
        RemainBytes -= ReadSize;
    }

    if((FLASH_DRV_READ_ERROR == Flash_Drv_ReadState.Status) && (FLASH_DRV_SUCCESS == Ret)) 
    {
        /* exit loop due to ECC error */
        Ret = FLASH_DRV_ERR_ECC_M;
    }
    else
    {

    }
    
    Flash_Drv_ReadState.Status = FLASH_DRV_READ_IDLE;

#if (STD_ON == FLASH_DRV_DEV_ERROR_DETECT)
	MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

/**
 * @brief      Poll the erase/program command complete status. If timeout supervisor is enabled, 
 *             it checks if it is timeout and command is not completed yet. It can be called when
 *             erase/program in asynchronous mode. If it is required, cache is cleared after erase
 *             /program is completed.
 *
 * @param[in]  None
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR
 * @retval    FLASH_DRV_ERR_TIMEOUT
 */
Flash_Drv_ReturnType Flash_Drv_PollEraseWriteStatus(void)
{
    Flash_Drv_ReturnType Ret;
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    uint32 ElapsedTicks;
#endif /* FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON */
	
	SchM_Enter_Fls_TransferStatus();
    if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.CCIF == 1U)
    {
        if(Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.ACCERR != 0U)
        {
            Ret = FLASH_DRV_ERR;
            /* clear ACCERR flag*/
            Fls_Drv_FlsRegWPtr->FLASH_FSTAT = FLASH_DRV_ACCERR_MSK;
			SchM_Exit_Fls_TransferStatus();
        }
        else
        {
			SchM_Exit_Fls_TransferStatus();
			Ret = FLASH_DRV_SUCCESS; 
        }

#if(FLASH_DRV_SYNCHRONIZE_CACHE == STD_ON)
        Flash_Drv_ClearCache();
#endif                 
    }
    else
    {
    	SchM_Exit_Fls_TransferStatus();
#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        (void)McalLib_GetElapsedValue(FLASH_DRV_TIMEOUT_TYPE, &Flash_Drv_CurrentTicks, &ElapsedTicks);
        Flash_Drv_ElapsedTicks += ElapsedTicks;

        if(Flash_Drv_ElapsedTicks > Flash_Drv_TimeoutTicks)
        {
            Ret = FLASH_DRV_ERR_TIMEOUT;
        }
        else        
#endif /* FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON */
        {
            Ret = FLASH_DRV_BUSY;
        }
    }

    return Ret;
}


/**
 * @brief      Get flash block number from address
 *
 * @param[in]  Address: the address
 *
 * @return    the flash block number
 * @retval    FLASH_DRV_BLOCK_INVALID
 * @retval    FLASH_DRV_BLOCK_PFLASH
 * @retval    FLASH_DRV_BLOCK_DFLASH
 *
 */ 
uint32 Flash_Drv_GetBlockNumFromAddr(uint32 Address)
{
    uint32 BlockNum;

    if((Address >= FLASH_DRV_DFLASH_BASE_ADDR) && (Address <= FLASH_DRV_DFLASH_END_ADDR))
    {
        BlockNum = FLASH_DRV_BLOCK_DFLASH;
    }
    else if(Address <= FLASH_DRV_PFLASH_END_ADDR)
    {
        BlockNum = FLASH_DRV_BLOCK_PFLASH;
    }
    else if((Address >= FLASH_DRV_PFLASH_IFR_BASE_ADDR) && 
            (Address <= FLASH_DRV_PFLASH_IFR_END_ADDR))
    {
        BlockNum = FLASH_DRV_BLOCK_PFLASH;
    }
    else
    {
        BlockNum = FLASH_DRV_BLOCK_INVALID;
    }

    return BlockNum;
}

#if(FLASH_DRV_ECC_CHECK_INT == STD_ON)
/**
 * @brief      Flash ECC interrupt handler.
 *             
 * @param[in]  None
 *
 * @return     None
 *
 * Note: Flash_Drv_ReadState.Status shall be set to FLASH_DRV_READ_ERROR for multi-bit ECC 
 *       error processing in case that the interrupt handler is redefined by users.
 */
ISR(Flash_Drv_EccIrqHandler)
{
    uint32 Status;

    /* get interrput status */
    Status = (Fls_Drv_FlsRegWPtr->FLASH_FSTAT & FLASH_DRV_ECC_MASK);
    Status &= Fls_Drv_FlsRegWPtr->FLASH_FCNFG;
    
    /* clear interrput status */
    Fls_Drv_FlsRegWPtr->FLASH_FSTAT = Status;

    /* process single bit ECC error interrput */
    if(0U != (Status & FLASH_DRV_SFDIF_MASK))
    {
        if(NULL_PTR != Flash_Drv_ConfigPtr->SingleBitIntCallback)
        {
            Flash_Drv_ConfigPtr->SingleBitIntCallback();
        }
    }

    /* process multi bits ECC error interrput */
    if((0U != (Status & FLASH_DRV_DFDIF_MASK)) &&
       (Flash_Drv_ReadState.Status == FLASH_DRV_READ_BUSY) &&
       ((Flash_Drv_ReadState.Address >> 4) == Fls_Drv_FlsRegBfPtr->FLASH_MBE_STATE.MBE_ADDR))
    {
        Flash_Drv_ReadState.Status = FLASH_DRV_READ_ERROR;
        
        if(NULL_PTR != Flash_Drv_ConfigPtr->MultiBitIntCallback)
        {
            Flash_Drv_ConfigPtr->MultiBitIntCallback();
        }
    }

    EXIT_INTERRUPT();
}
#endif /* FLASH_DRV_ECC_CHECK_INT == STD_ON */

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv */

/** @} end of group Fls_Module */
