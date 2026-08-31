/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup IntCtrl_Lld
*   @{
*/

/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 4404 Rule-10.3: The value of an expression shall not be assigned to an object with a narrower
                          essential type or of a different essential type category.
 * PRQA S 1891 Rule-10.7: If a composite expression is used as one operand of an operator in which the usual
                          arithmetic conversions are performed then the other operand shall not have wider essential type
 * PRQA S 0306 Rule-11.4: A conversion should not be performed between a pointer to object and an integer type
 * PRQA S 1006 Dir-1.1/Rule 1.2/Dir-4.2: Language extension should not be used.
 * PRQA S 3006 Dir-4.3: Assembly language shall be encapsulated and isolated.
 */

/*
*  MR12 RULE 10.3 VIOLATION: It's caused by using DevAssert() with the input paramter
*                             as "typedef unsigned char boolean" from Platform_Types.h,
*                            it's no risk for this essentially Boolean type conversion.
*/
/* PRQA S 4404 EOF */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "IntCtrl_Lld.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_LLD_VENDOR_ID_C        (180)
#define PLATFORM_INTCTRL_LLD_SW_MAJOR_VERSION_C (2)
#define PLATFORM_INTCTRL_LLD_SW_MINOR_VERSION_C (3)
#define PLATFORM_INTCTRL_LLD_SW_PATCH_VERSION_C (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Lld header file are of the same vendor */
#if (PLATFORM_INTCTRL_LLD_VENDOR_ID_C != PLATFORM_INTCTRL_LLD_VENDOR_ID)
#error "IntCtrl_Lld.c and IntCtrl_Lld.h have different vendor ids"
#endif

/* Check if current file and Fls header file are of the same Software version */
#if ((PLATFORM_INTCTRL_LLD_SW_MAJOR_VERSION_C != PLATFORM_INTCTRL_LLD_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_SW_MINOR_VERSION_C != PLATFORM_INTCTRL_LLD_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_SW_PATCH_VERSION_C != PLATFORM_INTCTRL_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of IntCtrl_Lld.c and IntCtrl_Lld.h are different"
#endif

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
#ifdef __ARMCC_VERSION
extern uint32 Image$$IVT_RAM_start$$Base;
#define IVT_RAM_START ((uint32 *) &Image$$IVT_RAM_start$$Base)
#else
extern uint32 IVT_RAM_start[1U];
#define IVT_RAM_START ((uint32 *) &IVT_RAM_start)
#endif
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
#define Call_Lld_InstIsrPrivileged(IrqNumber,NewHandler,OldHandler)  \
                OsIf_Trusted_Call3params(IntCtrl_Lld_InstIsrPrivileged,(IrqNumber),(NewHandler),(OldHandler))
#define Call_Lld_EnableIrqPrivileged(IrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Lld_EnableIrqPrivileged,(IrqNumber))
#define Call_Lld_DisableIrqPrivileged(IrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Lld_DisableIrqPrivileged,(IrqNumber))
#define Call_Lld_SetPriorityPrivileged(IrqNumber,Priority)  \
                OsIf_Trusted_Call2params(IntCtrl_Lld_SetPriPrivileged,(IrqNumber),(Priority))
#define Call_Lld_GetPriorityPrivileged(IrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Lld_GetPriPrivileged,(IrqNumber))
#define Call_Lld_ClearPendingPrivileged(IrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Lld_ClrPendingPrivileged,(IrqNumber))
#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
#define Call_Lld_SetPendingPrivileged(IrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Lld_SetPendingPrivileged,(IrqNumber))
#define Call_Lld_GetPendingPrivileged(IrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Lld_GetPendingPrivileged,(IrqNumber))
#if (INT_CTRL_LLD_CORTEXM == STD_ON)
#define Call_Lld_GetActivePrivileged(IrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Lld_GetActivePrivileged,(IrqNumber))
#endif
#endif
#if ((INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON))
#define Call_Lld_SetTargetCorePrivileged(IrqNumber,TargetCores)  \
                OsIf_Trusted_Call2params(IntCtrl_Lld_SetCpuCorePrivileged,(IrqNumber),(TargetCores))
#endif
#else
#define Call_Lld_InstIsrPrivileged(IrqNumber,NewHandler,OldHandler)  \
                IntCtrl_Lld_InstIsrPrivileged((IrqNumber),(NewHandler),(OldHandler))
#define Call_Lld_EnableIrqPrivileged(IrqNumber)  \
                IntCtrl_Lld_EnableIrqPrivileged((IrqNumber))
#define Call_Lld_DisableIrqPrivileged(IrqNumber)  \
                IntCtrl_Lld_DisableIrqPrivileged((IrqNumber))
#define Call_Lld_SetPriorityPrivileged(IrqNumber,Priority)  \
                IntCtrl_Lld_SetPriPrivileged((IrqNumber),(Priority))
#define Call_Lld_GetPriorityPrivileged(IrqNumber)  \
                IntCtrl_Lld_GetPriPrivileged((IrqNumber))
#define Call_Lld_ClearPendingPrivileged(IrqNumber)  \
                IntCtrl_Lld_ClrPendingPrivileged((IrqNumber))

#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
#define Call_Lld_SetPendingPrivileged(IrqNumber)  \
                IntCtrl_Lld_SetPendingPrivileged((IrqNumber))
#define Call_Lld_GetPendingPrivileged(IrqNumber)  \
                IntCtrl_Lld_GetPendingPrivileged((IrqNumber))
#if (INT_CTRL_LLD_CORTEXM == STD_ON)
#define Call_Lld_GetActivePrivileged(IrqNumber)  \
                IntCtrl_Lld_GetActivePrivileged((IrqNumber))
#endif
#endif /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/
#if ((INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON))
#define Call_Lld_SetTargetCorePrivileged(IrqNumber,TargetCores)  \
                IntCtrl_Lld_SetCpuCorePrivileged((IrqNumber),(TargetCores))
#endif
#endif /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
PLATFORM_FUNC static void IntCtrl_Lld_InstIsrPrivileged(IRQn_Type IrqNumber,
        const IntCtrl_Lld_IrqHandlerType NewHandler,
        IntCtrl_Lld_IrqHandlerType *const OldHandler);
PLATFORM_FUNC static void IntCtrl_Lld_EnableIrqPrivileged(IRQn_Type IrqNumber);
PLATFORM_FUNC static void IntCtrl_Lld_DisableIrqPrivileged(IRQn_Type IrqNumber);
PLATFORM_FUNC static void IntCtrl_Lld_SetPriPrivileged(IRQn_Type IrqNumber, uint8 Priority);
PLATFORM_FUNC static uint8 IntCtrl_Lld_GetPriPrivileged(IRQn_Type IrqNumber);

#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
PLATFORM_FUNC static void IntCtrl_Lld_SetPendingPrivileged(IRQn_Type IrqNumber);
PLATFORM_FUNC static void IntCtrl_Lld_ClrPendingPrivileged(IRQn_Type IrqNumber);
PLATFORM_FUNC static uint32 IntCtrl_Lld_GetPendingPrivileged(IRQn_Type IrqNumber);
#if (INT_CTRL_LLD_CORTEXM == STD_ON)
PLATFORM_FUNC static uint32 IntCtrl_Lld_GetActivePrivileged(IRQn_Type IrqNumber);
#endif
#endif
#if ((INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON))
PLATFORM_FUNC void IntCtrl_Lld_SetCpuCorePrivileged(IRQn_Type IrqNumber, uint8 TargetCores);
#endif
/*
*  MR12 Dir 4.3 VIOLATION: This function contains a mixture of in-line assembler statements and C statements.
*/
/*  PRQA S 3006 EOF */
PLATFORM_FUNC static void IntCtrl_Lld_InstIsrPrivileged
(
    IRQn_Type IrqNumber,
    const IntCtrl_Lld_IrqHandlerType NewHandler,
    IntCtrl_Lld_IrqHandlerType *const OldHandler
)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - DevIrqNumber is used to avoid compiler warning */
    sint32 DevIrqNumber = (sint32)IrqNumber;
    sint32 IrqOffset = 14;

    DevAssert((sint32)INT_CTRL_LLD_IRQ_MIN <= (DevIrqNumber + IrqOffset));  /* add 14 to support CM33 exception */
    DevAssert(DevIrqNumber <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#ifndef TESSY
    /*
    *  MR12 RULE 11.4 VIOLATION: The IVT_RAM_start must be got from the symbol generated by the linker
    *                            to get the RAM reloated interrupt vector table base address
    */
    DevAssert(SCB->VTOR >= (uint32)IVT_RAM_START); /*  PRQA S 0306 */
#endif

#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    /*
    *  MR12 RULE 11.4 VIOLATION: The SCB->VTOR register is a volatile 32-bit hardware register,
    *                            there is no risk to do ths convert/cast.
    */
    IntCtrl_Lld_IrqHandlerType *PtrVectorRam = (IntCtrl_Lld_IrqHandlerType *)SCB->VTOR;  /* PRQA S 0306 */

    /* Save the former handler pointer */
    if (OldHandler != NULL_PTR)
    {
        *OldHandler = (IntCtrl_Lld_IrqHandlerType)PtrVectorRam[((sint32)IrqNumber) + 16];
    }

    /* Set handler into vector table */
    PtrVectorRam[((sint32)IrqNumber) + 16] = NewHandler;
#if (INT_CTRL_LLD_INVALIDATE_CACHE == STD_ON)
    /* Invalidate ICache */
    SCB->ICIALLU = 0UL;
#endif

    /*
    *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
    *                                           and is switched based the toolchain supported and user selected.
    */
    __ISB(); /* PRQA S 1006 */
    __DSB(); /* PRQA S 1006 */
}

PLATFORM_FUNC static void IntCtrl_Lld_EnableIrqPrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - DevIrqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)IrqNumber);
    DevAssert((sint32)IrqNumber <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    /* Enable interrupt */
    NVIC_EnableIRQ(IrqNumber);
}

PLATFORM_FUNC void IntCtrl_Lld_DisableIrqPrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - DevIrqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)IrqNumber);
    DevAssert((sint32)IrqNumber <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    /* Disable interrupt */
    NVIC_DisableIRQ(IrqNumber);
}

PLATFORM_FUNC static void IntCtrl_Lld_SetPriPrivileged(IRQn_Type IrqNumber, uint8 Priority)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number and Priority - DevIrqNumber is used to avoid compiler warning */
    DevAssert((sint32)INT_CTRL_LLD_IRQ_MIN <= (sint32)IrqNumber);
    DevAssert((sint32)IrqNumber <= (sint32)INT_CTRL_LLD_IRQ_MAX);
    DevAssert(Priority < (uint8)(1U << INT_CTRL_LLD_NVIC_PRIO_BITS));
#endif /* (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    NVIC_SetPriority(IrqNumber, Priority);
}

PLATFORM_FUNC static uint8 IntCtrl_Lld_GetPriPrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_LLD_IRQ_MIN <= IrqNumber);
    DevAssert((sint32)IrqNumber <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    uint8 Priority = 0U;

    Priority = (uint8)NVIC_GetPriority(IrqNumber);

    return Priority;
}

PLATFORM_FUNC static void IntCtrl_Lld_ClrPendingPrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)IrqNumber);
    DevAssert((sint32)IrqNumber <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /* (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    NVIC_ClearPendingIRQ(IrqNumber);
}

#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
PLATFORM_FUNC static void IntCtrl_Lld_SetPendingPrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - DevIrqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)IrqNumber);
    DevAssert(((sint32)IrqNumber) <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    NVIC_SetPendingIRQ(IrqNumber);
}

PLATFORM_FUNC static uint32 IntCtrl_Lld_GetPendingPrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)IrqNumber);
    DevAssert(((sint32)IrqNumber) <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    return NVIC_GetPendingIRQ(IrqNumber);
}
#if (INT_CTRL_LLD_CORTEXM == STD_ON)
PLATFORM_FUNC static uint32 IntCtrl_Lld_GetActivePrivileged(IRQn_Type IrqNumber)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)IrqNumber);
    DevAssert(((sint32)IrqNumber) <= (sint32)INT_CTRL_LLD_IRQ_MAX);
#endif /*(INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON) */

    /* Get Active Interrupt */
    return NVIC_GetActive(IrqNumber);
}
#endif
#endif /*#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @internal
 * @brief         Initializes the configured interrupts at interrupt controller level.
 * @implements    IntCtrl_Lld_Init_Activity
 */
PLATFORM_FUNC IntCtrl_Lld_StatusType IntCtrl_Lld_Init(const IntCtrl_Lld_CtrlConfigType *IntCtrlCtrlConfig)
{
#if (INTCTRL_LLD_ENABLE_VTOR_CONFIG == STD_ON)
    SCB->VTOR = IntCtrlCtrlConfig->VectorTableAddress;
#endif

#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    DevAssert(IntCtrlCtrlConfig != NULL_PTR);
    DevAssert(IntCtrlCtrlConfig->ConfigIrqCount <= INT_CTRL_LLD_IRQ_COUNT);
#endif
    for (uint32 IrqIdx = 0; IrqIdx < IntCtrlCtrlConfig->ConfigIrqCount; ++IrqIdx)
    {
        IntCtrl_Lld_ClearPending(IntCtrlCtrlConfig->IrqConfig[IrqIdx].IrqNumber);
        IntCtrl_Lld_SetPriority(IntCtrlCtrlConfig->IrqConfig[IrqIdx].IrqNumber,
                                IntCtrlCtrlConfig->IrqConfig[IrqIdx].IrqPriority);

        if (TRUE == IntCtrlCtrlConfig->IrqConfig[IrqIdx].IrqEnabled)
        {
            IntCtrl_Lld_EnableIrq(IntCtrlCtrlConfig->IrqConfig[IrqIdx].IrqNumber);
        }
        else
        {
            IntCtrl_Lld_DisableIrq(IntCtrlCtrlConfig->IrqConfig[IrqIdx].IrqNumber);
        }
    }

    return INTCTRL_LLD_STATUS_SUCCESS;
}

#if (INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON)
/**
 * @internal
 * @brief         Initializes the configured routing interrupts.
 * @implements    IntCtrl_Lld_ConfigIrqRouting_Activity
 */
PLATFORM_FUNC IntCtrl_Lld_StatusType IntCtrl_Lld_ConfigIrqRouting(const IntCtrl_Lld_GlobalRouteConfigType *routeConfig)
{
#if (INT_CTRL_LLD_DEV_ERROR_DETECT == STD_ON)
    DevAssert(routeConfig != NULL_PTR);
    DevAssert(routeConfig->ConfigIrqCount <= INT_CTRL_LLD_IRQ_COUNT);
#endif
    uint32 IrqIdx;
    for (IrqIdx = 0; IrqIdx < routeConfig->ConfigIrqCount; IrqIdx++)
    {
#if (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON)
        /* Configure routing */
        IntCtrl_Lld_SetTargetCores(routeConfig->IrqConfig[IrqIdx].IrqNumber,
                                   routeConfig->IrqConfig[IrqIdx].TargetCores);
#endif
        /* Install the configured handler */
        IntCtrl_Lld_InstallHandler(routeConfig->IrqConfig[IrqIdx].IrqNumber,
                                   routeConfig->IrqConfig[IrqIdx].Handler,
                                   NULL_PTR);
    }
    return INTCTRL_LLD_STATUS_SUCCESS;
}
#endif

/**
 * @internal
 * @brief         Installs a handler for an IRQ.
 * @implements    IntCtrl_Lld_InstallHandler_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_InstallHandler(IRQn_Type IrqNumber,
        const IntCtrl_Lld_IrqHandlerType NewHandler,
        IntCtrl_Lld_IrqHandlerType *const OldHandler)
{
    Call_Lld_InstIsrPrivileged(IrqNumber, NewHandler, OldHandler);
}

/**
 * @internal
 * @brief         Enables an interrupt request.
 * @implements    IntCtrl_Lld_EnableIrq_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_EnableIrq(IRQn_Type IrqNumber)
{
    Call_Lld_EnableIrqPrivileged(IrqNumber);
}

/**
 * @internal
 * @brief         Disables an interrupt request.
 * @implements    IntCtrl_Lld_DisableIrq_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_DisableIrq(IRQn_Type IrqNumber)
{
    Call_Lld_DisableIrqPrivileged(IrqNumber);
}

/**
 * @internal
 * @brief         Sets the Priority for an interrupt request.
 * @implements    IntCtrl_Lld_SetPriority_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_SetPriority(IRQn_Type IrqNumber, uint8 Priority)
{
    Call_Lld_SetPriorityPrivileged(IrqNumber, Priority);
}

/**
 * @internal
 * @brief         Gets the Priority for an interrupt request.
 * @implements    IntCtrl_Lld_GetPriority_Activity
 */
PLATFORM_FUNC uint8 IntCtrl_Lld_GetPriority(IRQn_Type IrqNumber)
{
    return (uint8)Call_Lld_GetPriorityPrivileged(IrqNumber);
}

/**
 * @internal
 * @brief         Clears the pending flag for an interrupt request.
 * @implements    IntCtrl_Lld_ClearPending_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_ClearPending(IRQn_Type IrqNumber)
{
    Call_Lld_ClearPendingPrivileged(IrqNumber);
}


#if (INT_CTRL_LLD_STANDALONE_APIS == STD_ON)
/**
 * @internal
 * @brief         Sets the pending flag for an interrupt request.
 * @implements    IntCtrl_Lld_SetPending_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_SetPending(IRQn_Type IrqNumber)
{
    Call_Lld_SetPendingPrivileged(IrqNumber);
}

/**
 * @internal
 * @brief         Gets the pending flag for an interrupt request.
 * @implements    IntCtrl_Lld_GetPending_Activity
 */
PLATFORM_FUNC boolean IntCtrl_Lld_GetPending(IRQn_Type IrqNumber)
{
    return (Call_Lld_GetPendingPrivileged(IrqNumber) > 0U) ? TRUE : FALSE;
}

/**
 * @internal
 * @brief         Gets the active flag for an interrupt request.
 * @implements    IntCtrl_Lld_GetActive_Activity
 */
#if (INT_CTRL_LLD_CORTEXM == STD_ON)
PLATFORM_FUNC boolean IntCtrl_Lld_GetActive(IRQn_Type IrqNumber)
{
    /*Gets the active flag for an interrupt request */
    return (Call_Lld_GetActivePrivileged(IrqNumber) > 0U) ? TRUE : FALSE;
}
#endif
#endif /* INT_CTRL_LLD_STANDALONE_APIS*/

#if ((INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_LLD_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @internal
 * @brief         Sets the target cores for an interrupt request.
 * @implements    IntCtrl_Lld_SetTargetCores_Activity
 */
PLATFORM_FUNC void IntCtrl_Lld_SetTargetCores(IRQn_Type IrqNumber, uint8 TargetCores)
{
    /* Sets the target cores for an interrupt request */
    Call_Lld_SetTargetCorePrivileged(IrqNumber, TargetCores);
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */

