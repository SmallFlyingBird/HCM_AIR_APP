/**
* @file    exceptions.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : exceptions
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

/**
*   @file    exceptions.c
*
*   @addtogroup EXCEPTIONS_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 0306 Rule-11.4: A conversion should not be performed between a pointer to object and an integer type
 * PRQA S 1006 Dir-1.1/Rule 1.2/Dir-4.2: Language extension should not be used.
 */

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/

#include "Platform_Types.h"
#include "Mcal.h"
#include "Platform_CfgDefines.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EXCEPTIONS_VENDOR_ID_C                      (180)
#define EXCEPTIONS_AR_RELEASE_MAJOR_VERSION_C       (4)
#define EXCEPTIONS_AR_RELEASE_MINOR_VERSION_C       (4)
#define EXCEPTIONS_AR_RELEASE_REVISION_VERSION_C    (0)
#define EXCEPTIONS_SW_MAJOR_VERSION_C               (2)
#define EXCEPTIONS_SW_MINOR_VERSION_C               (3)
#define EXCEPTIONS_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
void SVCHandler_Main(const uint32 *SvcArgs);   /* NOSONAR, it's used by the SVC exception handler */
void Suspend_Interrupts(void);
void Resume_Interrupts(void);
void SVC_Handler(void);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT

void __attribute__((naked)) SVC_Handler(void)
{
    /*
     *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
     *                                           and is switched based the toolchain supported and user selected.
     */
    /* PRQA S 1006 EOF */
    __ASM("tst lr, #4\n"\
          "ite eq\n" \
          "mrseq   r0, MSP\n" \
          "mrsne   r0, PSP\n");
    /* stack pointer is passed to SVCHandler_Main, it will be used to extract the parameter given to svc call*/
    __ASM("ldr    r1,=SVCHandler_Main"); /* PRQA S 1006 */
    __ASM("bx     r1"); /* PRQA S 1006 */
}
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/*
*  MR12 Dir 4.3 VIOLATION: This function contains a mixture of in-line assembler statements and C statements.
*/
/*  PRQA S 3006 EOF */
void SVCHandler_Main(const uint32 *SvcArgs)
{
    uint32 SvcNumber;
    /* Stack contains:    * r0, r1, r2, r3, r12, r14, the return address and xPSR   */
    /* First argument (r0) is SvcArgs[0]  */
    /* SvcArgs[6] =  SP + 0x18  PC(r15) */
    /* ((char *)SvcArgs[6])[-2]; = first two bytes, lsb, of the instruction which caused the SVC */
    /* this will nto work if optimization compiler options are changed*/
    /*
    *  MR12 RULE 11.4 VIOLATION: This C code expression is easier to read and understand, and is full-validated.
    */
    SvcNumber = ((uint8 *)SvcArgs[PLATFORM_PC_OFFSET_OF_MSP])[-2]; /*  PRQA S 0306 */  /* NOSONAR */
    switch (SvcNumber)
    {
        case 1:
            /* Handle SVC 01*/
            /*
            *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
            *                                           and is switched based the toolchain supported and user selected.
            */
            __ASM("mov   r0, #0x1");    /* PRQA S 1006 */  /* Set User mode for Thread mode */
            __ASM("msr   CONTROL, r0"); /* PRQA S 1006 */
            break;
        case 0:
            /* Handle SVC 00*/
            /*
            *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
            *                                           and is switched based the toolchain supported and user selected.
            */
            __ASM("mov   r0, #0x0");    /* PRQA S 1006 */  /* Set Supervisor mode for Thread mode */
            __ASM("msr   CONTROL, r0"); /* PRQA S 1006 */
            break;
        case 2:
            /* Handle SVC 02*/
            Resume_Interrupts();
            break;
        case 3:
            /* Handle SVC 03*/
            Suspend_Interrupts();
            break;
        default:
            /* Unknown SVC*/
            break;
    }
}

void Suspend_Interrupts(void)
{
    /*
    *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
    *                                           and is switched based the toolchain supported and user selected.
    */
    __ASM("push {r0}");       /* PRQA S 1006 */
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
    __ASM("mov   r0, #0x20"); /* PRQA S 1006 */
#elif defined(CPU_YTM32B1HA0)
    __ASM("mov   r0, #0x10"); /* PRQA S 1006 */
#else
#error "Unsupported CPU"
#endif
    __ASM(" msr BASEPRI, r0");/* PRQA S 1006 */
    __ASM("pop {r0}");        /* PRQA S 1006 */
}

void Resume_Interrupts(void)
{
    /*
    *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
    *                                           and is switched based the toolchain supported and user selected.
    */
    __ASM("push {r0}");      /* PRQA S 1006 */
    __ASM("mov   r0, #0x0"); /* PRQA S 1006 */
    __ASM("msr BASEPRI, r0");/* PRQA S 1006 */
    __ASM("pop {r0}");       /* PRQA S 1006 */
}
#endif

#ifdef __ICCARM__
#pragma default_function_attributes =
#endif

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file exceptions.c */

