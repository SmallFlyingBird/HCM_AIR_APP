/**
* @file    OsIf.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : OsIf
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
*   @file    OsIf.c
*
*   @addtogroup OSIF_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 1006 Dir-1.1/Rule 1.2/Dir-4.2: Language extension should not be used.
 * PRQA S 3006 Dir-4.3: Assembly language shall be encapsulated and isolated.
 */

/*  
*  MR12 Dir 4.3 VIOLATION: The following function contains a mixture of in-line assembler statements and C statements.
*                          Sys_GoToSupervisor();
*                          Sys_SuspendInterrupts();
*                          Sys_ResumeInterrupts();
*/
/*  PRQA S 3006 EOF */

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "OsIf.h"
#include "Mcal.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION                                
==================================================================================================*/
#define OSIF_VENDOR_ID_C                      (180)
#define OSIF_AR_RELEASE_MAJOR_VERSION_C       (4)
#define OSIF_AR_RELEASE_MINOR_VERSION_C       (4)
#define OSIF_AR_RELEASE_REVISION_VERSION_C    (0)
#define OSIF_SW_MAJOR_VERSION_C               (2)
#define OSIF_SW_MINOR_VERSION_C               (3)
#define OSIF_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS                                      
==================================================================================================*/
/* Check if source file and OSIF header file are of the same vendor */
#if (OSIF_VENDOR_ID_C != OSIF_VENDOR_ID)
#error "OsIf.c and OsIf.h have different vendor ids"
#endif

/* Check if source file and OSIF header file are of the same Autosar version */
#if (( OSIF_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
      ( OSIF_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) || \
      ( OSIF_AR_RELEASE_REVISION_VERSION_C != OSIF_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of OsIf.c and OsIf.h are different"
#endif

/* Check if source file and OSIF header file are of the same Software version */
#if (( OSIF_SW_MAJOR_VERSION_C != OSIF_SW_MAJOR_VERSION) || \
      ( OSIF_SW_MINOR_VERSION_C != OSIF_SW_MINOR_VERSION) || \
      ( OSIF_SW_PATCH_VERSION_C != OSIF_SW_PATCH_VERSION))
#error "Software Version Numbers of OsIf.c and OsIf.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES                                       
==================================================================================================*/
/*==================================================================================================
                                                LOCAL VARIABLES                                        
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS                                        
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS                                           
==================================================================================================*/

#define SVC_GoToSupervisor()      __ASM("svc 0x0")
#define SVC_GoToUser()            __ASM("svc 0x1")

/*==================================================================================================
*                                       GLOBAL FUNCTIONS DECLARES
==================================================================================================*/

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT  
    extern uint32 Startup_GetControlRegisterValue(void);
    extern uint32 Startup_GetAipsRegisterValue(void);
    extern void Suspend_Interrupts(void);
    extern void Resume_Interrupts(void);
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/

/*==================================================================================================
                                                LOCAL FUNCTIONS                                        
==================================================================================================*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
PLATFORM_FUNC LOCAL_INLINE void Direct_GoToUser(void);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
PLATFORM_FUNC LOCAL_INLINE void Direct_GoToUser(void)
{
    /*  
    *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
    *                                           and is switched based the toolchain supported and user selected.
    */
    __ASM("push {r0}");      /* PRQA S 1006 */
    __ASM("mrs r0, CONTROL");/* PRQA S 1006 */
    __ASM("orr r0, r0, #0x1");/* PRQA S 1006 */
    __ASM("msr CONTROL, r0");/* PRQA S 1006 */
    __ASM("pop {r0}");       /* PRQA S 1006 */
}
#endif

/*==================================================================================================
                                                GLOBAL FUNCTIONS                                       
==================================================================================================*/

#if !defined(USING_OS_AUTOSAROS)
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT

PLATFORM_FUNC uint32 Sys_GoToSupervisor(void)
{
    uint32 ControlRegValue;
    uint32 AipsRegValue;
    uint32 SwitchToSupervisor;

    /* if it's 0 then Thread mode is already in supervisor mode */
    ControlRegValue = Startup_GetControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    AipsRegValue = Startup_GetAipsRegisterValue();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0U == (ControlRegValue & 1u)) || (0u < (AipsRegValue & 0xFFu)))
    {
        SwitchToSupervisor = 0U;
    }
    else
    {
        SwitchToSupervisor = 1U;
        /*  
        *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The SVC_GoToSupervisor() uses the __ASM() which is aassembly extension is implemented in compiler.h
        *                                           and it is switched based the toolchain supported and user selected.
        */
        SVC_GoToSupervisor(); /* PRQA S 1006 */
    }

    return SwitchToSupervisor;
}

/*================================================================================================*/
/**
* @brief Sys_GoToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32 value passed as parameter
*/
/*================================================================================================*/
PLATFORM_FUNC uint32 Sys_GoToUser_Return(uint32 SwitchToSupervisor, uint32 ReturnValue)
{
    if (1UL == SwitchToSupervisor)
    {
        Direct_GoToUser();
    }

    return ReturnValue;
}

PLATFORM_FUNC uint32 Sys_GoToUser(void)
{
    Direct_GoToUser();
    return 0UL;
}

/*================================================================================================*/
/**
* @brief Sys_SuspendInterrupts
* @details Suspend Interrupts
*/
/*================================================================================================*/
PLATFORM_FUNC void Sys_SuspendInterrupts(void)
{
    uint32 ControlRegValue;
    uint32 AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    ControlRegValue = Startup_GetControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    AipsRegValue = Startup_GetAipsRegisterValue();

    if((0U == (ControlRegValue & 1u)) || (0u < (AipsRegValue & 0xFFu)))
    {
        Suspend_Interrupts();
    }
    else
    {  
       /*  
       *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
       *                                           and is switched based the toolchain supported and user selected.
       */
        __ASM(" svc 0x3"); /* PRQA S 1006 */
    }
}


/*================================================================================================*/
/**
* @brief Sys_ResumeInterrupts
* @details Resume Interrupts
*/
/*================================================================================================*/
PLATFORM_FUNC void Sys_ResumeInterrupts(void)
{
    uint32 ControlRegValue;
    uint32 AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    ControlRegValue = Startup_GetControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    AipsRegValue = Startup_GetAipsRegisterValue();

    if((0U == (ControlRegValue & 1u)) || (0u < (AipsRegValue & 0xFFu)))
    {
        Resume_Interrupts();
    }
    else
    {
       /*  
       *  MR12 Dir-1.1/Rule 1.2/Dir-4.2 VIOLATION: The __ASM() assembly extension is implemented in compiler.h
       *                                           and is switched based the toolchain supported and user selected.
       */
        __ASM(" svc 0x2"); /* PRQA S 1006 */
    }
}

#endif /* def MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief Sys_GetCoreID
* @details Function used to get the ID of the currently executing thread
*/
PLATFORM_FUNC uint8 Sys_GetCoreID(void)
{
    return 0;
}

#endif /* !defined(USING_OS_AUTOSAROS) */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file OsIf.c */

