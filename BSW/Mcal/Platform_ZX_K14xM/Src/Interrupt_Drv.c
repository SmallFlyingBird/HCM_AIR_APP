/**************************************************************************************************/
/**
 * @file      : Interrupt_Drv.c
 * @brief     : Interrupt Control low level driver source file
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

/** @defgroup Interrupt_Drv
 *  @brief It provides the source code of Interrupt_Drv APIS.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Interrupt_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define INTERRUPT_DRV_C_VENDOR_ID                   0x00B3U
#define INTERRUPT_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define INTERRUPT_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define INTERRUPT_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define INTERRUPT_DRV_C_SW_MAJOR_VERSION            1U
#define INTERRUPT_DRV_C_SW_MINOR_VERSION            2U
#define INTERRUPT_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Interrupt_Drv.h are the same vendor */
#if (INTERRUPT_DRV_C_VENDOR_ID != INTERRUPT_DRV_H_VENDOR_ID)
    #error "Interrupt_Drv.c and Interrupt_Drv.h have different vendor ids"
#endif
/* Check if current file and Interrupt_Drv.h are the same Autosar version */
#if ((INTERRUPT_DRV_C_AR_RELEASE_MAJOR_VERSION != INTERRUPT_DRV_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (INTERRUPT_DRV_C_AR_RELEASE_MINOR_VERSION != INTERRUPT_DRV_H_AR_RELEASE_MINOR_VERSION) ||     \
     (INTERRUPT_DRV_C_AR_RELEASE_REVISION_VERSION != INTERRUPT_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Interrupt_Drv.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Software version */
#if ((INTERRUPT_DRV_C_SW_MAJOR_VERSION != INTERRUPT_DRV_H_SW_MAJOR_VERSION) ||                     \
     (INTERRUPT_DRV_C_SW_MINOR_VERSION != INTERRUPT_DRV_H_SW_MINOR_VERSION) ||                     \
     (INTERRUPT_DRV_C_SW_PATCH_VERSION != INTERRUPT_DRV_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Interrupt_Drv.c and Interrupt_Drv.h are different"
#endif

#define INTERRUPT_DRV_NVIC_PRIO_BITS (4U) /*!< Number of Bits used for Priority Levels */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
extern uint32 __SRAM_START;
#else
extern uint32 __SRAM_START[1U];
#endif
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
 * @brief     This function initializes the configured interrupts.
 *
 * @param[in] ConfigPtr: pointer to configuration structure for interrupts.
 *
 * @return    None.
 */
void Interrupt_Drv_Init(const Interrupt_Drv_ConfigType *ConfigPtr)
{
    uint32 IrqIdx;
#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(ConfigPtr != NULL_PTR);
    MCALLIB_DEV_ASSERT(ConfigPtr->ConfigIrqCount <= INTERRUPT_DRV_IRQ_COUNT);
#endif /*(INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */
    for (IrqIdx = 0U; IrqIdx < ConfigPtr->ConfigIrqCount; IrqIdx++)
    {
        Interrupt_Drv_SetPriority(ConfigPtr->IrqConfigList[IrqIdx].IrqNumber,
                                  ConfigPtr->IrqConfigList[IrqIdx].IrqPriority);

        if (TRUE == ConfigPtr->IrqConfigList[IrqIdx].IrqEnabled)
        {
            Interrupt_Drv_EnableIrq(ConfigPtr->IrqConfigList[IrqIdx].IrqNumber);
        }
        else
        {
            Interrupt_Drv_DisableIrq(ConfigPtr->IrqConfigList[IrqIdx].IrqNumber);
        }
    }
#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function installs a handler for an IRQ.
 * @details    This function is non-reentrant; it installs an new ISR for an interrupt line.
 * This function works only when the interrupt vector table resides in RAM.
 *
 * @param[in]  IrqNumber: Interrupt Number.
 * @param[in]  NewHandler: Pointer to the new interrupt handler.
 * @param[out] OldHandlerPtr: Pointer to store the old interrupt handler. Pass NULL_PTR if not used.
 *
 * @return     None.
 */
void Interrupt_Drv_InstallHandler(IRQn_Type                           IrqNumber,
                                  const Interrupt_Drv_IrqHandlerType  NewHandler,
                                  Interrupt_Drv_IrqHandlerType *const OldHandlerPtr)
{
    /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
    object, no side effects forseen by violating this rule. */
    uint32 *VectorsPtr = (uint32 *)Z20_SCB->VTOR;
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    uint32 ModeSwiched;
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    ModeSwiched = Sys_EnterPrivilegedMode();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number is used to avoid compiler warning */
    MCALLIB_DEV_ASSERT(INTERRUPT_DRV_FIRST_IRQ <= IrqNumber);
    MCALLIB_DEV_ASSERT((sint32)IrqNumber <= (sint32)INTERRUPT_DRV_LAST_IRQ);
    /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
    object, no side effects forseen by violating this rule. */
    MCALLIB_DEV_ASSERT(Z20_SCB->VTOR >= (uint32)__SRAM_START);
#endif /*(INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */

    /* Save the former handler pointer */
    if (OldHandlerPtr != NULL_PTR)
    {
        /* MISRA2012 Rule-11.1 violation: Convert a value of interrupt handler from vector
        table to a pointer object, no side effects forseen by violating this rule. */
        *OldHandlerPtr = (Interrupt_Drv_IrqHandlerType)VectorsPtr[((sint32)IrqNumber) + 16];
    }

    /* Set handler into vector table */
    /* MISRA2012 Rule-11.1 violation: Convert a value of interrupt handler from vector
    table to a pointer object, no side effects forseen by violating this rule. */
    VectorsPtr[((sint32)IrqNumber) + 16] = (uint32)NewHandler;

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    if (1U == ModeSwiched)
    {
        Sys_EnterNonPrivilegedMode();
    }
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function enable an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    None.
 */
void Interrupt_Drv_EnableIrq(IRQn_Type IrqNumber)
{
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    uint32 ModeSwiched;
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    ModeSwiched = Sys_EnterPrivilegedMode();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    MCALLIB_DEV_ASSERT(0 <= (sint32)IrqNumber);
    MCALLIB_DEV_ASSERT((sint32)IrqNumber <= (sint32)INTERRUPT_DRV_LAST_IRQ);
#endif /* (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */

    /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
    object, no side effects forseen by violating this rule. */
    Z20_NVIC->ISER[(((uint32)IrqNumber) >> 5UL)] = (uint32)(1UL << (((uint32)IrqNumber) & 0x1FUL));

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    if (1U == ModeSwiched)
    {
        Sys_EnterNonPrivilegedMode();
    }
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function disables an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    None.
 */
void Interrupt_Drv_DisableIrq(IRQn_Type IrqNumber)
{
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    uint32 ModeSwiched;
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    ModeSwiched = Sys_EnterPrivilegedMode();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    MCALLIB_DEV_ASSERT(0 <= (sint32)IrqNumber);
    MCALLIB_DEV_ASSERT((sint32)IrqNumber <= (sint32)INTERRUPT_DRV_LAST_IRQ);
#endif /* (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */

    /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
    object, no side effects forseen by violating this rule. */
    Z20_NVIC->ICER[(((uint32)IrqNumber) >> 5UL)] = (uint32)(1UL << (((uint32)IrqNumber) & 0x1FUL));
    MCALLIB_DATA_SYNC_BARRIER();
    MCALLIB_INSTRUCTION_SYNC_BARRIER();

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    if (1U == ModeSwiched)
    {
        Sys_EnterNonPrivilegedMode();
    }
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function sets the priority for an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 * @param[in] Priority: Priority to be set.
 *
 * @return    None.
 */
void Interrupt_Drv_SetPriority(IRQn_Type IrqNumber, uint32 Priority)
{
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    uint32 ModeSwiched;
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    ModeSwiched = Sys_EnterPrivilegedMode();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    MCALLIB_DEV_ASSERT(((sint32)INTERRUPT_DRV_FIRST_IRQ + 2) <= (sint32)IrqNumber);
    MCALLIB_DEV_ASSERT((sint32)IrqNumber <= (sint32)INTERRUPT_DRV_LAST_IRQ);
    MCALLIB_DEV_ASSERT(Priority < (uint8)(1U << INTERRUPT_DRV_PRIO_BITS_NUM));
#endif /* (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */

    if ((sint32)IrqNumber >= 0)
    {
        /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
        object, no side effects forseen by violating this rule. */
        Z20_NVIC->IP[((uint32)IrqNumber)] =
            (uint8)(Priority << (8U - INTERRUPT_DRV_NVIC_PRIO_BITS));
    }
    else
    {
        /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
        object, no side effects forseen by violating this rule. */
        /* MISRA2012 Dir-1.1 violation: The computational formula already considers the converting a
        negative value to unsigned object, no side effects forseen by violating this rule. */
        Z20_SCB->SHP[(((uint32)IrqNumber) & 0xFU) - 4U] =
            (uint8)(Priority << (8U - INTERRUPT_DRV_NVIC_PRIO_BITS));
    }
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    if (1U == ModeSwiched)
    {
        Sys_EnterNonPrivilegedMode();
    }
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function gets the priority for an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    uint32: the priority of the interrupt.
 */
uint32 Interrupt_Drv_GetPriority(IRQn_Type IrqNumber)
{
    uint32 Prio = 0U;
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    uint32 ModeSwiched;
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    ModeSwiched = Sys_EnterPrivilegedMode();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    MCALLIB_DEV_ASSERT(((sint32)INTERRUPT_DRV_FIRST_IRQ + 2) <= (sint32)IrqNumber);
    MCALLIB_DEV_ASSERT((sint32)IrqNumber <= (sint32)INTERRUPT_DRV_LAST_IRQ);
#endif /* (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */

    if ((sint32)IrqNumber >= 0)
    {
        /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
        object, no side effects forseen by violating this rule. */
        Prio = (((uint32)Z20_NVIC->IP[((uint32)IrqNumber)] >> (8U - INTERRUPT_DRV_NVIC_PRIO_BITS)));
    }
    else
    {
        /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
        object, no side effects forseen by violating this rule. */
        /* MISRA2012 Dir-1.1 violation: The computational formula already considers the converting a
        negative value to unsigned object, no side effects forseen by violating this rule. */
        Prio = (((uint32)Z20_SCB->SHP[(((uint32)IrqNumber) & 0xFU) - 4U] >>
                 (8U - INTERRUPT_DRV_NVIC_PRIO_BITS)));
    }
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    if (1U == ModeSwiched)
    {
        Sys_EnterNonPrivilegedMode();
    }
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return Prio;
}

/**
 * @brief     This function clears the pending flag for an interrupt request.
 *
 * @param[in] IrqNumber: Interrupt Number.
 *
 * @return    None.
 */
void Interrupt_Drv_ClearPending(IRQn_Type IrqNumber)
{
#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    uint32 ModeSwiched;
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    ModeSwiched = Sys_EnterPrivilegedMode();
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    MCALLIB_DEV_ASSERT(0 <= (sint32)IrqNumber);
    MCALLIB_DEV_ASSERT((sint32)IrqNumber <= (sint32)INTERRUPT_DRV_LAST_IRQ);
#endif /* (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON) */

    /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer
    object, no side effects forseen by violating this rule. */
    Z20_NVIC->ICPR[(((uint32)IrqNumber) >> 5UL)] = (uint32)(1UL << (((uint32)IrqNumber) & 0x1FUL));

#if (INTERRUPT_DRV_SUPPORT_USER_MODE == STD_ON)
    if (1U == ModeSwiched)
    {
        Sys_EnterNonPrivilegedMode();
    }
#endif

#if (INTERRUPT_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Interrupt_Drv */

/** @} end of group Platform_Module */
