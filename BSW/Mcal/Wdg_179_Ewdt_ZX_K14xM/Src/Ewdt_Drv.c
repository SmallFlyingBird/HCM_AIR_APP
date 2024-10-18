/**************************************************************************************************/
/**
 * @file      : Ewdt_Drv.c
 * @brief     : Ewdt low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Wdg_179_Ewdt_Module
 *  @{
 */

/** @addtogroup Ewdt_Drv
 *  @brief Ewdt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Ewdt_Drv.h"
#include "Device_Regs.h"
#include "SchM_Wdg_179_Ewdt.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define EWDT_DRV_C_VENDOR_ID                   0x00B3U
#define EWDT_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define EWDT_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define EWDT_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define EWDT_DRV_C_SW_MAJOR_VERSION            1U
#define EWDT_DRV_C_SW_MINOR_VERSION            2U
#define EWDT_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Ewdt_Drv header file are of the same vendor */
#if (EWDT_DRV_C_VENDOR_ID != EWDT_DRV_H_VENDOR_ID)
#error "Vendor ID of Ewdt_Drv.c and Ewdt_Drv.h are different"
#endif

/* Check if current file and Ewdt_Drv header file are of the same Autosar version */
#if ((EWDT_DRV_C_AR_RELEASE_MAJOR_VERSION     != EWDT_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (EWDT_DRV_C_AR_RELEASE_MINOR_VERSION     != EWDT_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (EWDT_DRV_C_AR_RELEASE_REVISION_VERSION  != EWDT_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Ewdt_Drv.c and Ewdt_Drv.h are different"
#endif

/* Check if current file and Ewdt_Drv header file are of the same software version */
#if ((EWDT_DRV_C_SW_MAJOR_VERSION != EWDT_DRV_H_SW_MAJOR_VERSION) || \
    (EWDT_DRV_C_SW_MINOR_VERSION != EWDT_DRV_H_SW_MINOR_VERSION) || \
    (EWDT_DRV_C_SW_PATCH_VERSION != EWDT_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Ewdt_Drv.c and Ewdt_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((EWDT_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (EWDT_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Ewdt_Drv.c and Device_Regs.h are different"
    #endif
    /* Check if current file and SchM_Wdg_179_Ewdt.h file are of the same Autosar version */
    #if ((EWDT_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_WDG_179_EWDT_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (EWDT_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_WDG_179_EWDT_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Ewdt_Drv.c and SchM_Wdg_179_Ewdt.h are different"
    #endif
#endif     /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define EWDT_CS_INTE_MASK              (0x00000010U)
#define EWDT_CS_WAITE_MASK             (0x00000004U)
#define EWDT_CS_DEBUGE_MASK            (0x00000002U)
#define EWDT_CS_EWDTE_MASK             (0x00000001U)
#define EWDT_CS_INPE_MASK              (0x00000020U)
#define EWDT_CS_INPP_MASK              (0x00000040U)

#define EWDT_CS_INTE_SHIFT             (4U)
#define EWDT_CS_WAITE_SHIFT            (2U)
#define EWDT_CS_DEBUGE_SHIFT           (1U)
#define EWDT_CS_INPE_SHIFT             (5U)
#define EWDT_CS_INPP_SHIFT             (6U)

#define EWDT_CS_INPP_SET(x) \
        (((uint32)(((uint32)(x)) << EWDT_CS_INPP_SHIFT)) & EWDT_CS_INPP_MASK)

#define EWDT_CS_INPE_SET(x) \
        (((uint32)(((uint32)(x)) << EWDT_CS_INPE_SHIFT)) & EWDT_CS_INPE_MASK)

#define EWDT_CS_WAITE_SET(x) \
        (((uint32)(((uint32)(x)) << EWDT_CS_WAITE_SHIFT)) & EWDT_CS_WAITE_MASK)
        
#define EWDT_CS_DEBUGE_SET(x) \
        (((uint32)(((uint32)(x)) << EWDT_CS_DEBUGE_SHIFT)) & EWDT_CS_DEBUGE_MASK)
        
#define EWDT_CS_INTE_SET(x) \
        (((uint32)(((uint32)(x)) << EWDT_CS_INTE_SHIFT)) & EWDT_CS_INTE_MASK)


/** @} end of Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define WDG_179_EWDT_START_SEC_CONST_PTR
#include "Wdg_179_Ewdt_MemMap.h"

/**
 *  @brief Ewdt base address define 
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule*/
static Reg_Ewdt_BfType *const Ewdt_Drv_EwdtRegBfPtr = (Reg_Ewdt_BfType *)EWDT_BASE_ADDR;
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule*/
static Reg_Ewdt_WType *const Ewdt_Drv_EwdtRegWPtr= (Reg_Ewdt_WType *)EWDT_BASE_ADDR;

#define WDG_179_EWDT_STOP_SEC_CONST_PTR
#include "Wdg_179_Ewdt_MemMap.h"

#define WDG_179_EWDT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_179_Ewdt_MemMap.h"

static Ewdt_Drv_CallbackPtrType Ewdt_Drv_IntCallbackPtr;

#define WDG_179_EWDT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_179_Ewdt_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_START_SEC_CODE
#else
#define WDG_179_EWDT_START_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"


/**
 * @brief convert config parameters into CS register value
 *
 * @param[in] ConfigPtr: point to config structure.
 * @param[out] CsValue: point to the address to store the value for CS register
 * 
 * @return The status
 * @retval EWDT_DRV_STATUS_SUCCESS
 * @retval EWDT_DRV_STATUS_ERROR 
 */
static Ewdt_Drv_StatusType Ewdt_ConvertConfigToCsValue(const Ewdt_Drv_ConfigType * ConfigPtr, 
                                                       uint32 *CsValue)
{ 
    Ewdt_Drv_StatusType Status = EWDT_DRV_STATUS_SUCCESS;

#if (EWDT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (EWDT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(ConfigPtr != NULL_PTR);
#endif

    
    if (ConfigPtr->WindowValue >= ConfigPtr->TimeoutValue)
    {
        Status = EWDT_DRV_STATUS_ERROR;
    }
    else
    {
        *CsValue |= EWDT_CS_INPE_SET(ConfigPtr->INPortEnable);
        *CsValue |= EWDT_CS_INPP_SET(ConfigPtr->IsInPortHighActive);
        *CsValue |= EWDT_CS_WAITE_SET(ConfigPtr->OpMode.WaitMode);
        *CsValue |= EWDT_CS_DEBUGE_SET(ConfigPtr->OpMode.DebugMode);
        *CsValue |= EWDT_CS_INTE_SET(ConfigPtr->IntEnable);
        *CsValue |= EWDT_CS_EWDTE_MASK;
    }

#if (EWDT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/** @} end of Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
 * @brief Ewdt initialization.
 *
 * @param[in] ConfigPtr Ewdt_Drv_ConfigType pointer.
 * 
 * @return The status of the ewdt initialization:
 * @retval EWDT_DRV_STATUS_SUCCESS
 * @retval EWDT_DRV_STATUS_ERROR
 */
Ewdt_Drv_StatusType Ewdt_Drv_Init(const Ewdt_Drv_ConfigType * const ConfigPtr)
{
    Reg_Ewdt_WType * Base_w = (Reg_Ewdt_WType *)(Ewdt_Drv_EwdtRegWPtr);
    Ewdt_Drv_StatusType Status = EWDT_DRV_STATUS_SUCCESS;

    uint32 CsValue = 0U;
    uint32 CsBackup = 0U;
    uint32 ComphBackup = 0U;
    uint32 CompLBackup = 0U;
#if (EWDT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (EWDT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(ConfigPtr != NULL_PTR);
#endif

    Status = Ewdt_ConvertConfigToCsValue(ConfigPtr,&CsValue);

    if(EWDT_DRV_STATUS_SUCCESS == Status)
    { 
        if(0U != ConfigPtr->IntEnable)
        {
            Ewdt_Drv_IntCallbackPtr = ConfigPtr->IntCallbackPtr;
        }
        else
        {
            Ewdt_Drv_IntCallbackPtr = NULL_PTR;
        }

        Base_w->EWDT_COMPH = ConfigPtr->TimeoutValue;

        Base_w->EWDT_COMPL = ConfigPtr->WindowValue;
  
        Base_w->EWDT_CS = CsValue;

        ComphBackup = Base_w->EWDT_COMPH;
        CompLBackup = Base_w->EWDT_COMPL;
        CsBackup =  Base_w->EWDT_CS;

        if((CsValue == CsBackup) && (ComphBackup == ConfigPtr->TimeoutValue) && 
           (CompLBackup == ConfigPtr->WindowValue))
        {
            Status = EWDT_DRV_STATUS_SUCCESS;
        }
        else
        {
            Status = EWDT_DRV_STATUS_ERROR;
        }
    }

#if (EWDT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Status;
}


/**
 * @brief Refresh the Ewdt
 *
 * @param[in] CbBeforeRefresh: call back function before refresh
 * @param[in] CbAfterRefresh: call back function after refresh
 * 
 * @return   None
 */
void Ewdt_Drv_Refresh(Ewdt_Drv_CallbackPtrType CbBeforeRefresh,
                      Ewdt_Drv_CallbackPtrType CbAfterRefresh)
{  
    /* call the call back function to do some user defined actions before refresh , for example,
    halt DMA */
    if(NULL_PTR != CbBeforeRefresh)
    {
        CbBeforeRefresh();
    }

    SchM_Enter_Wdg_179_Ewdt_WriteRegData();

    ASM_KEYWORD (
        "PUSH  {R0, R1, R2}\n"
        "LDR   R0, =0x40061014\n"
        "LDR   R1, =0xB2C5D3A8\n"
        "LDR   R2, =0x1D7E4C5F\n"
        "STR   R1, [R0]\n"
        "STR   R2, [R0]\n"
        "POP  {R0, R1, R2}\n"
        );

    SchM_Exit_Wdg_179_Ewdt_WriteRegData();
   
    /* call the call back function to do some user defined actions after refresh, for example,
    resume DMA */
    if(NULL_PTR != CbAfterRefresh)
    {
        CbAfterRefresh();
    }
    
}

/**
* @brief    This function handles the EWDT interrupt request.
*
* @param[in] None
* 
* @return   None     
*/
void Ewdt_Drv_IntHandler(void)
{
    Reg_Ewdt_BfType * Base = (Ewdt_Drv_EwdtRegBfPtr);
    if (1U == Base->EWDT_CS.INTF)
    {
        Base->EWDT_CS.INTF = 1U;
        if(Ewdt_Drv_IntCallbackPtr !=  NULL_PTR)
        {
            Ewdt_Drv_IntCallbackPtr();
        }
    }
}

#if (EWDT_DRV_RUN_IN_ROM == 1U)
#define WDG_179_EWDT_STOP_SEC_CODE
#else
#define WDG_179_EWDT_STOP_SEC_RAMCODE
#endif
#include "Wdg_179_Ewdt_MemMap.h"

/** @} end of Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
/** @} end of group Ewdt_Drv */

/** @} end of group Wdg_179_Ewdt_Module */
