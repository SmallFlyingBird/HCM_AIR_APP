/**************************************************************************************************/
/**
 * @file      : Platform.c
 * @brief     : Platform high level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Platform_Module
 *  @{
 */

/** @defgroup Platform
 *  @brief It provides the source code of Platform APIS.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform.h"
#include "Interrupt_Drv.h"
#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
    #include "Tmu_Drv.h"
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define PLATFORM_C_VENDOR_ID                   0x00B3U
#define PLATFORM_C_AR_RELEASE_MAJOR_VERSION    4U
#define PLATFORM_C_AR_RELEASE_MINOR_VERSION    6U
#define PLATFORM_C_AR_RELEASE_REVISION_VERSION 0U
#define PLATFORM_C_SW_MAJOR_VERSION            1U
#define PLATFORM_C_SW_MINOR_VERSION            2U
#define PLATFORM_C_SW_PATCH_VERSION            1U

/* Check if current file and Platform.h are the same vendor */
#if (PLATFORM_C_VENDOR_ID != PLATFORM_VENDOR_ID)
    #error "Vendor ID of Platform.c and Platform.h are different"
#endif
/* Check if current file and Platform.h are the same Autosar version */
#if ((PLATFORM_C_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) ||                 \
     (PLATFORM_C_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION) ||                 \
     (PLATFORM_C_AR_RELEASE_REVISION_VERSION != PLATFORM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Platform.c and Platform.h are different"
#endif
/* Check if current file and Platform.h are the same Software version */
#if ((PLATFORM_C_SW_MAJOR_VERSION != PLATFORM_SW_MAJOR_VERSION) ||                                 \
     (PLATFORM_C_SW_MINOR_VERSION != PLATFORM_SW_MINOR_VERSION) ||                                 \
     (PLATFORM_C_SW_PATCH_VERSION != PLATFORM_SW_PATCH_VERSION))
    #error "Software Version of Platform.c and Platform.h are different"
#endif

/* Check if current file and Interrupt_Drv.h are the same vendor */
#if (PLATFORM_C_VENDOR_ID != INTERRUPT_DRV_H_VENDOR_ID)
    #error "Vendor ID of Platform.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Autosar version */
#if ((PLATFORM_C_AR_RELEASE_MAJOR_VERSION != INTERRUPT_DRV_H_AR_RELEASE_MAJOR_VERSION) ||          \
     (PLATFORM_C_AR_RELEASE_MINOR_VERSION != INTERRUPT_DRV_H_AR_RELEASE_MINOR_VERSION) ||          \
     (PLATFORM_C_AR_RELEASE_REVISION_VERSION != INTERRUPT_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Platform.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Software version */
#if ((PLATFORM_C_SW_MAJOR_VERSION != INTERRUPT_DRV_H_SW_MAJOR_VERSION) ||                          \
     (PLATFORM_C_SW_MINOR_VERSION != INTERRUPT_DRV_H_SW_MINOR_VERSION) ||                          \
     (PLATFORM_C_SW_PATCH_VERSION != INTERRUPT_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Platform.c and Interrupt_Drv.h are different"
#endif
#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
    /* Check if current file and Tmu_Drv.h are the same vendor */
    #if (PLATFORM_C_VENDOR_ID != TMU_DRV_H_VENDOR_ID)
        #error "Vendor ID of Platform.c and Tmu_Drv.h are different"
    #endif
    /* Check if current file and Tmu_Drv.h are the same Autosar version */
    #if ((PLATFORM_C_AR_RELEASE_MAJOR_VERSION != TMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (PLATFORM_C_AR_RELEASE_MINOR_VERSION != TMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||            \
         (PLATFORM_C_AR_RELEASE_REVISION_VERSION != TMU_DRV_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version of Platform.c and Tmu_Drv.h are different"
    #endif
    /* Check if current file and Tmu_Drv.h are the same Software version */
    #if ((PLATFORM_C_SW_MAJOR_VERSION != TMU_DRV_H_SW_MAJOR_VERSION) ||                            \
         (PLATFORM_C_SW_MINOR_VERSION != TMU_DRV_H_SW_MINOR_VERSION) ||                            \
         (PLATFORM_C_SW_PATCH_VERSION != TMU_DRV_H_SW_PATCH_VERSION))
        #error "Software Version of Platform.c and Tmu_Drv.h are different"
    #endif
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Det header file are of the same Autosar version */
        #if ((PLATFORM_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||              \
             (PLATFORM_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version of Platform_Cfg.h and Det.h are different"
        #endif
    #endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/
#endif     /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief         This function initializes the interrupts based on configuration.
 *
 * @param[in]     ConfigPtr: Pointer to platform configuration.
 *
 * @return        None
 *
 */
void Platform_Init(const Platform_ConfigType *ConfigPtr)
{
    uint8                           CoreId;
    uint32                          IrqIndex = 0;
    const Interrupt_Drv_ConfigType *IntCfgPtr;

    CoreId = (uint8)Platform_GetCoreID();
    (void)CoreId;
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != ConfigPtr)
    {
        (void)Det_ReportError((uint16)PLATFORM_MODULE_ID, 0U, PLATFORM_SID_INIT,
                              PLATFORM_E_PARAM_POINTER);
    }
    else
    {
#endif /*(PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
        if (NULL_PTR != Platform_Configuration.TmuConfigPtr)
        {
            Tmu_Drv_Init(Platform_Configuration.TmuConfigPtr);
        }
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */

        /* Initialize interrupts at interrupt controller level */
        if (NULL_PTR != Platform_Configuration.InterruptConfigPtr)
        {
            IntCfgPtr = Platform_Configuration.InterruptConfigPtr;
            for (IrqIndex = 0; IrqIndex < IntCfgPtr->ConfigIrqCount; IrqIndex++)
            {
                Interrupt_Drv_InstallHandler(IntCfgPtr->IrqConfigList[IrqIndex].IrqNumber,
                                             IntCfgPtr->IrqConfigList[IrqIndex].IrqHandler,
                                             NULL_PTR);
                Interrupt_Drv_SetPriority(IntCfgPtr->IrqConfigList[IrqIndex].IrqNumber,
                                          IntCfgPtr->IrqConfigList[IrqIndex].IrqPriority);
                if (TRUE == IntCfgPtr->IrqConfigList[IrqIndex].IrqEnabled)
                {
                    Interrupt_Drv_EnableIrq(IntCfgPtr->IrqConfigList[IrqIndex].IrqNumber);
                }
                else
                {
                    Interrupt_Drv_DisableIrq(IntCfgPtr->IrqConfigList[IrqIndex].IrqNumber);
                }
            }
        }

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/
}

/**
 * @brief         This function enables/disables an interrupt request.
 *
 * @param[in]     IrqNumber: Interrupt Number.
 * @param[in]     Enable: TRUE - enable interrupt, FALSE - disable interrupt.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_SetIrq(IRQn_Type IrqNumber, boolean Enable)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INTERRUPT_DRV_LAST_IRQ) ||
        ((sint32)INTERRUPT_DRV_FIRST_IRQ > (sint32)IrqNumber))
    {
        (void)Det_ReportError(PLATFORM_MODULE_ID, 0U, PLATFORM_SID_SET_IRQ,
                              PLATFORM_E_PARAM_OUT_OF_RANGE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

        if (TRUE == Enable)
        {
            Interrupt_Drv_EnableIrq(IrqNumber);
        }
        else
        {
            Interrupt_Drv_DisableIrq(IrqNumber);
        }

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

    return Ret;
}

/**
 * @brief         This function sets the priority of an interrupt request.
 *
 * @param[in]     IrqNumber: Interrupt Number.
 * @param[in]     Priority: Priority to be set.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_SetIrqPriority(IRQn_Type IrqNumber, uint32 Priority)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INTERRUPT_DRV_LAST_IRQ) ||
        ((sint32)INTERRUPT_DRV_FIRST_IRQ > (sint32)IrqNumber) ||
        (Priority >= (uint8)(1U << INTERRUPT_DRV_PRIO_BITS_NUM)))
    {
        (void)Det_ReportError(PLATFORM_MODULE_ID, 0U, PLATFORM_SID_SET_IRQ_PRIO,
                              PLATFORM_E_PARAM_OUT_OF_RANGE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

        Interrupt_Drv_SetPriority(IrqNumber, Priority);

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

    return Ret;
}

/**
 * @brief         This function gets the priority of an interrupt request.
 *
 * @param[in]     IrqNumber: interrupt number for which priority is returned.
 * @param[out]    PriorityPtr: output parameter storing the priority of the interrupt.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_GetIrqPriority(IRQn_Type IrqNumber, uint32 *PriorityPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INTERRUPT_DRV_LAST_IRQ) ||
        ((sint32)INTERRUPT_DRV_FIRST_IRQ > (sint32)IrqNumber))
    {
        (void)Det_ReportError(PLATFORM_MODULE_ID, 0U, PLATFORM_SID_GET_IRQ_PRIO,
                              PLATFORM_E_PARAM_OUT_OF_RANGE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if (PriorityPtr == NULL_PTR)
    {
        (void)Det_ReportError(PLATFORM_MODULE_ID, 0U, PLATFORM_SID_GET_IRQ_PRIO,
                              PLATFORM_E_PARAM_POINTER);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

        *PriorityPtr = Interrupt_Drv_GetPriority(IrqNumber);

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

    return Ret;
}

/**
 * @brief         This function installs a new handler for an interrupt request.
 *
 * @param[in]     IrqNumber: Interrupt Number.
 * @param[in]     NewHandler: Pointer for the new handler.
 * @param[out]    OldHandlerPtr: Pointer to store the old handler. Pass NULL_PTR if not used.
 *
 * @return        Std_ReturnType: E_OK or E_NOT_OK;
 * @retval        E_OK: Successful
 * @retval        E_NOT_OK: Failed
 */
Std_ReturnType Platform_InstallIrqHandler(IRQn_Type                      IrqNumber,
                                          const Platform_IrqHandlerType  NewHandler,
                                          Platform_IrqHandlerType *const OldHandlerPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)IrqNumber > (sint32)INTERRUPT_DRV_LAST_IRQ) ||
        ((sint32)INTERRUPT_DRV_FIRST_IRQ > (sint32)IrqNumber))
    {
        (void)Det_ReportError(PLATFORM_MODULE_ID, 0U, PLATFORM_SID_INSTALL_HANDLER,
                              PLATFORM_E_PARAM_OUT_OF_RANGE);
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

        Interrupt_Drv_InstallHandler(IrqNumber, NewHandler, OldHandlerPtr);

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (PLATFORM_DEV_ERROR_DETECT == STD_ON)*/

    return Ret;
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Platform */

/** @} end of group Platform_Module */
