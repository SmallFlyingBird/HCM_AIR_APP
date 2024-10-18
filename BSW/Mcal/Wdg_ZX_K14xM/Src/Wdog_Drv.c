/**************************************************************************************************/
/**
 * @file      : Wdg_Drv.c
 * @brief     : Wdg low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drv
 *  @brief Wdg low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Wdog_Drv.h"
#include "Device_Regs.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDOG_DRV_C_VENDOR_ID                   0x00B3U
#define WDOG_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define WDOG_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define WDOG_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define WDOG_DRV_C_SW_MAJOR_VERSION            1U
#define WDOG_DRV_C_SW_MINOR_VERSION            2U
#define WDOG_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Wdg_Drv header file are of the same vendor */
#if (WDOG_DRV_C_VENDOR_ID != WDOG_DRV_H_VENDOR_ID)
#error "Vendor ID of Wdg_Drv.c and Wdg_Drv.h are different"
#endif

/* Check if current file and Wdg_Drv header file are of the same Autosar version */
#if ((WDOG_DRV_C_AR_RELEASE_MAJOR_VERSION     != WDOG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (WDOG_DRV_C_AR_RELEASE_MINOR_VERSION     != WDOG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (WDOG_DRV_C_AR_RELEASE_REVISION_VERSION  != WDOG_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Wdg_Drv.c and Wdg_Drv.h are different"
#endif

/* Check if current file and Wdg_Drv header file are of the same software version */
#if ((WDOG_DRV_C_SW_MAJOR_VERSION != WDOG_DRV_H_SW_MAJOR_VERSION) || \
    (WDOG_DRV_C_SW_MINOR_VERSION != WDOG_DRV_H_SW_MINOR_VERSION) || \
    (WDOG_DRV_C_SW_PATCH_VERSION != WDOG_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Wdg_Drv.c and Wdg_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((WDOG_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (WDOG_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Wdg_Drv.c and Device_Regs.h are different"
    #endif
#endif     /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */


#define WDOG_CS_CLKS_MASK              (0x00000300U)
#define WDOG_CS_CFGUA_MASK             (0x00000040U)
#define WDOG_CS_WINE_MASK              (0x00000020U)
#define WDOG_CS_INTE_MASK              (0x00000010U)
#define WDOG_CS_STOPE_MASK             (0x00000008U)
#define WDOG_CS_WAITE_MASK             (0x00000004U)
#define WDOG_CS_DEBUGE_MASK            (0x00000002U)
#define WDOG_CS_WDOGE_MASK             (0x00000001U)


#define WDOG_CS_CLKS_SHIFT             (8U)
#define WDOG_CS_CFGUA_SHIFT            (6U)
#define WDOG_CS_WINE_SHIFT             (5U)
#define WDOG_CS_INTE_SHIFT             (4U)
#define WDOG_CS_STOPE_SHIFT            (3U)
#define WDOG_CS_WAITE_SHIFT            (2U)
#define WDOG_CS_DEBUGE_SHIFT           (1U)



#define WDOG_CS_CLKS_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_CLKS_SHIFT)) & WDOG_CS_CLKS_MASK)
        
#define WDOG_CS_CFGUA_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_CFGUA_SHIFT)) & WDOG_CS_CFGUA_MASK)
        
#define WDOG_CS_WINE_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_WINE_SHIFT)) & WDOG_CS_WINE_MASK)
        
#define WDOG_CS_STOPE_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_STOPE_SHIFT)) & WDOG_CS_STOPE_MASK)
        
#define WDOG_CS_WAITE_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_WAITE_SHIFT)) & WDOG_CS_WAITE_MASK)
        
#define WDOG_CS_DEBUGE_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_DEBUGE_SHIFT)) & WDOG_CS_DEBUGE_MASK)
        
#define WDOG_CS_INTE_SET(x) \
        (((uint32)(((uint32)(x)) << WDOG_CS_INTE_SHIFT)) & WDOG_CS_INTE_MASK)


/** @} end of Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define WDG_START_SEC_CONST_PTR
#include "Wdg_MemMap.h"

/**
 *  @brief Wdog base address define 
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule*/
static Reg_Wdog_BfType *const Wdg_Drv_WdgRegBfPtr = (Reg_Wdog_BfType *)WDOG_BASE_ADDR;
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule*/
static Reg_Wdog_WType *const Wdg_Drv_WdgRegWPtr= (Reg_Wdog_WType *)WDOG_BASE_ADDR;

#define WDG_STOP_SEC_CONST_PTR
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_MemMap.h"

static Wdog_Drv_CallbackPtrType Wdog_Drv_IntCallbackPtr;

#define WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"


LOCAL_INLINE void Wdog_Drv_Unlock(void)
{
    ASM_KEYWORD (
            "PUSH  {R0, R1, R2}\n"
            "LDR   R0, =0x40052014\n"
            "LDR   R1, =0xB0D9A1C4\n"
            "LDR   R2, =0x1A1E3B0F\n"
            "STR   R1, [R0]\n"
            "STR   R2, [R0]\n"
            "POP  {R0, R1, R2}\n"
            );
}

/**
 * @brief check if the WDOG update is allowed.
 * 
 * @param[in] None
 *
 * @return the result
 * @retval FALSE
 * @retval TRUE
 */
LOCAL_INLINE boolean Wdog_Drv_IsUpdateAllowed(void)
{
    const Reg_Wdog_BfType * Base = (Wdg_Drv_WdgRegBfPtr);
    return (1U == Base->WDOG_CS.CFGUA) ? TRUE : FALSE;
}

/**
 * @brief Wait for the last configuration of the WDOG taking effect.
 *
 * @param[in] None
 * 
 * @return the Status of the wdog:
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_TIMEOUT
 */
static Wdog_Drv_StatusType Wdog_Drv_WaitForConfigComplete(void)
{
    uint32 Loop = 0U;
    const Reg_Wdog_BfType * Base = (Wdg_Drv_WdgRegBfPtr);
    Wdog_Drv_StatusType Status = WDOG_DRV_STATUS_SUCCESS;
    while ( 1U != Base->WDOG_CS.CFGUF)
    {
        if (Loop > WDOG_DRV_HW_WAIT_TIMEOUT_CYCLE)
        {
            Status = WDOG_DRV_STATUS_TIMEOUT;
            break;
        }

        Loop++;
    }
    return Status;
}

/**
 * @brief convert config parameters into CS register value
 *
 * @param[in] ConfigPtr: point to config structure.
 * @param[out] CsValue: point to the address to store the value for CS register
 * 
 * @return the Status
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 */
static Wdog_Drv_StatusType Wdog_ConvertConfigToCsValue(const Wdog_Drv_ConfigType * ConfigPtr, 
                                                       uint32 *CsValue)
{
    const Reg_Wdog_WType * Base_w = (Reg_Wdog_WType *)(Wdg_Drv_WdgRegWPtr);    
    Wdog_Drv_StatusType Status = WDOG_DRV_STATUS_SUCCESS;

#if (WDOG_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (WDOG_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(ConfigPtr != NULL_PTR);
#endif

    *CsValue = Base_w->WDOG_CS;
    
    if (((0U != ConfigPtr->WindowEnable) && (ConfigPtr->WindowValue >= ConfigPtr->TimeoutValue)) || \
        (ConfigPtr->TimeoutValue <= 0U))
    {
        Status = WDOG_DRV_STATUS_ERROR;
    }
    else
    {
        *CsValue &= ~(WDOG_CS_CLKS_MASK | WDOG_CS_WINE_MASK | WDOG_CS_STOPE_MASK | WDOG_CS_WAITE_MASK |              \
                        WDOG_CS_DEBUGE_MASK | WDOG_CS_INTE_MASK | WDOG_CS_CFGUA_MASK);
        *CsValue |= WDOG_CS_CLKS_SET(ConfigPtr->ClkSource);
        *CsValue |= WDOG_CS_WINE_SET(ConfigPtr->WindowEnable);
        *CsValue |= WDOG_CS_STOPE_SET(ConfigPtr->OpMode.StopMode);
        *CsValue |= WDOG_CS_WAITE_SET(ConfigPtr->OpMode.WaitMode);
        *CsValue |= WDOG_CS_DEBUGE_SET(ConfigPtr->OpMode.DebugMode);
        *CsValue |= WDOG_CS_INTE_SET(ConfigPtr->IntEnable);
        *CsValue |= WDOG_CS_CFGUA_SET(ConfigPtr->UpdateEnable);
        *CsValue |= WDOG_CS_WDOGE_MASK;
    }

#if (WDOG_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/** @} end of Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
 * @brief Wdog initialization.
 *
 * @param[in] ConfigPtr Wdog_Drv_ConfigType pointer.
 * 
 * @return the Status of the wdog:
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 * @retval WDOG_DRV_STATUS_TIMEOUT
 */
Wdog_Drv_StatusType Wdog_Drv_Init(const Wdog_Drv_ConfigType * const ConfigPtr)
{
    Reg_Wdog_WType * Base_w = (Reg_Wdog_WType *)(Wdg_Drv_WdgRegWPtr);
    Wdog_Drv_StatusType Status = WDOG_DRV_STATUS_SUCCESS;
    boolean UpdateAllowed = Wdog_Drv_IsUpdateAllowed();
    uint32 CsValue;
#if (WDOG_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (WDOG_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(ConfigPtr != NULL_PTR);
#endif

    if(UpdateAllowed == FALSE)
    {
        Status = WDOG_DRV_STATUS_ERROR;
    }
    else
    {
        Status = Wdog_ConvertConfigToCsValue(ConfigPtr,&CsValue);
    }

    if(WDOG_DRV_STATUS_SUCCESS == Status)
    {        
        SchM_Enter_Wdg_WriteRegData();

        Wdog_Drv_Unlock();
        Base_w->WDOG_TMO = ConfigPtr->TimeoutValue;
        Status = Wdog_Drv_WaitForConfigComplete();

        if(WDOG_DRV_STATUS_SUCCESS == Status)
        {    
            if (0U != ConfigPtr->WindowEnable)
            {
                Wdog_Drv_Unlock();
                Base_w->WDOG_WIN = ConfigPtr->WindowValue;
                Status = Wdog_Drv_WaitForConfigComplete();
            }   
        }

        if(WDOG_DRV_STATUS_SUCCESS == Status)
        {
            Wdog_Drv_Unlock();
            Base_w->WDOG_CS = CsValue;
            Status = Wdog_Drv_WaitForConfigComplete();
        }

        SchM_Exit_Wdg_WriteRegData();

        if(0U != ConfigPtr->IntEnable)
        {
            Wdog_Drv_IntCallbackPtr = ConfigPtr->IntCallbackPtr;
        }
        else
        {
            Wdog_Drv_IntCallbackPtr = NULL_PTR;
        }
    }

#if (WDOG_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Status;
}

#if (WDOG_DRV_DISABLE_ALLOWED == STD_ON)
/**
 * @brief Wdog de-initialization. It resets the register values and disable the WDOG
 *
 * @param[in] None
 * 
 * @return the deinit Status of the wdog
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 * @retval WDOG_DRV_STATUS_TIMEOUT
 */
Wdog_Drv_StatusType Wdog_Drv_DeInit(void)
{
    Reg_Wdog_WType * Base_w = (Reg_Wdog_WType *)(Wdg_Drv_WdgRegWPtr);
    Wdog_Drv_StatusType Status = WDOG_DRV_STATUS_SUCCESS;

    if (Wdog_Drv_IsUpdateAllowed())
    {
        SchM_Enter_Wdg_WriteRegData();
        Wdog_Drv_Unlock();
        Base_w->WDOG_CS = (0x01040040U);
        Status = Wdog_Drv_WaitForConfigComplete();

        if(WDOG_DRV_STATUS_SUCCESS == Status)
        {
            Wdog_Drv_Unlock();
            Base_w->WDOG_TMO = (0x1FFFFU);
            Status = Wdog_Drv_WaitForConfigComplete();

            if(WDOG_DRV_STATUS_SUCCESS == Status)
            {
                Wdog_Drv_Unlock();
                Base_w->WDOG_WIN = (0x0U);
                Status = Wdog_Drv_WaitForConfigComplete();

            }
        }
        SchM_Exit_Wdg_WriteRegData();
        Wdog_Drv_IntCallbackPtr = NULL_PTR;
    }
    else
    {
        Status = WDOG_DRV_STATUS_ERROR;
    }
    return Status;
}
#endif

/**
 * @brief Refresh the Wdog
 *
 * @param[in] CbBeforeRefresh: call back function before refresh
 * @param[in] CbAfterRefresh: call back function after refresh
 * 
 * @return   None
 */
void Wdog_Drv_Refresh(Wdog_Drv_CallbackPtrType CbBeforeRefresh,
                      Wdog_Drv_CallbackPtrType CbAfterRefresh)
{ 
    /* call the call back function to do some user defined actions before refresh , for example,
    halt DMA */
    if(NULL_PTR != CbBeforeRefresh)
    {
        CbBeforeRefresh();
    }

    SchM_Enter_Wdg_WriteRegData();

    ASM_KEYWORD (
        "PUSH  {R0, R1, R2}\n"
        "LDR   R0, =0x40052014\n"
        "LDR   R1, =0xA0C4B1D6U\n"
        "LDR   R2, =0x1E0D0C7BU\n"
        "STR   R1, [R0]\n"
        "STR   R2, [R0]\n"
        "POP  {R0, R1, R2}\n"
        );

    SchM_Exit_Wdg_WriteRegData();
   
    /* call the call back function to do some user defined actions after refresh, for example,
    resume DMA */
    if(NULL_PTR != CbAfterRefresh)
    {
        CbAfterRefresh();
    }
    
}

/**
 * @brief Set WDOG timeout value.
 *
 * @param[in] WindowValue wdog window value.
 * @param[in] Timeout wdog timeout value
 * 
 * @return the Status of the wdog:
 * @retval WDOG_DRV_STATUS_SUCCESS
 * @retval WDOG_DRV_STATUS_ERROR 
 * @retval WDOG_DRV_STATUS_TIMEOUT
 * 
 */
Wdog_Drv_StatusType Wdog_Drv_SetTimeout(uint32 Timeout, uint32 WindowValue)
{
    Reg_Wdog_BfType * Base = (Wdg_Drv_WdgRegBfPtr);
    Wdog_Drv_StatusType Status = WDOG_DRV_STATUS_SUCCESS;

    /* If allowed reconfigures WDOG */
    if (TRUE == Wdog_Drv_IsUpdateAllowed())
    {
        SchM_Enter_Wdg_WriteRegData();
        Wdog_Drv_Unlock();
        Base->WDOG_TMO.TMO = Timeout;
        /* If enable window mode */
        if (WindowValue > 0U)
        {
            /* Set window value for the WDOG */
            Wdog_Drv_Unlock();
            Base->WDOG_WIN.WIN = WindowValue;
            Wdog_Drv_Unlock();
            Base->WDOG_CS.WINE = 1;
        }
        SchM_Exit_Wdg_WriteRegData();
        Status = Wdog_Drv_WaitForConfigComplete();
    }
    else
    {
        Status = WDOG_DRV_STATUS_ERROR;
    }
    return Status;
}

/**
* @brief    This function handles the WDOG interrupt request.
*
* @param[in] None
* 
* @return   None     
*/
void Wdog_Drv_IntHandler(void)
{
    Reg_Wdog_BfType * Base = (Wdg_Drv_WdgRegBfPtr);
    if (1U == Base->WDOG_CS.INTF)
    {
        Base->WDOG_CS.INTF = 1U;
        if(Wdog_Drv_IntCallbackPtr !=  NULL_PTR)
        {
            Wdog_Drv_IntCallbackPtr();
        }
    }
}

#if (WDG_DRV_RUN_IN_ROM == 1U)
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/** @} end of Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
/** @} end of group Wdg_Drv */

/** @} end of group Wdg_Module */
