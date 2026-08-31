/**
 * @file    SchM_Pwm.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR SchM_Pwm module interface
 * @details API implementation for SchM_Pwm driver
 *
 * @addtogroup SCHM_PWM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR
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

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Platform_Cfg.h"
#include "OsIf.h"
#include "SchM_Pwm.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_PWM_VENDOR_ID_C                    (180)
#define SCHM_PWM_AR_RELEASE_MAJOR_VERSION_C     (4)
#define SCHM_PWM_AR_RELEASE_MINOR_VERSION_C     (4)
#define SCHM_PWM_AR_RELEASE_REVISION_VERSION_C  (0)
#define SCHM_PWM_SW_MAJOR_VERSION_C             (2)
#define SCHM_PWM_SW_MINOR_VERSION_C             (3)
#define SCHM_PWM_SW_PATCH_VERSION_C             (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_CDDDMA header file are of the same vendor */
#if (SCHM_CDDDMA_VENDOR_ID_C != SCHM_CDDDMA_VENDOR_ID)
#error "SchM_Pwm.c and SchM_Pwm.h have different vendor ids"
#endif

/* Check if source file and SCHM_CDDDMA header file are of the same Autosar version */
#if (( SCHM_CDDDMA_AR_RELEASE_MAJOR_VERSION_C != SCHM_CDDDMA_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_CDDDMA_AR_RELEASE_MINOR_VERSION_C != SCHM_CDDDMA_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_CDDDMA_AR_RELEASE_REVISION_VERSION_C != SCHM_CDDDMA_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Pwm.c and SchM_Pwm.h are different"
#endif

/* Check if source file and SCHM_CDDDMA header file are of the same Software version */
#if (( SCHM_CDDDMA_SW_MAJOR_VERSION_C != SCHM_CDDDMA_SW_MAJOR_VERSION) || \
      ( SCHM_CDDDMA_SW_MINOR_VERSION_C != SCHM_CDDDMA_SW_MINOR_VERSION) || \
      ( SCHM_CDDDMA_SW_PATCH_VERSION_C != SCHM_CDDDMA_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Pwm.c and SchM_Pwm.h are different"
#endif
/*==================================================================================================
 *                                       LOCAL CONSTANTS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
#define ISR_STATE_MASK     ((uint32)0x000000C0UL)   /**< @brief DAIF bit I and F */
#elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
#define ISR_STATE_MASK     ((uint32)0x00000080UL)   /**< @brief CPSR bit I */
#else
#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
#define ISR_STATE_MASK     ((uint32)0x000000FFUL)   /**< @brief BASEPRI[7:0] mask */
#else
#define ISR_STATE_MASK     ((uint32)0x00000001UL)   /**< @brief PRIMASK bit 0 */
#endif
#endif
#endif
/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
#define ISR_ON(msr)            (((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)(ISR_STATE_MASK))
#elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
#define ISR_ON(msr)            (((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)(ISR_STATE_MASK))
#else
#define ISR_ON(msr)            (((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
#endif
#endif

#if (STD_ON == PWM_SCHM_SUPPORT)
/*==================================================================================================
 *                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Pwm_Msr;
RTE_VAR static volatile uint8 SchM_Pwm_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Pwm_Msr_00[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_00[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_01[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_01[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_02[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_02[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_03[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_03[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_04[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_04[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_05[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_05[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_06[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_06[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_07[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_07[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_08[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_08[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_09[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_09[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_Msr_10[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Pwm_ReentryGuard_10[NUMBER_OF_CORES];

#define RTE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

#endif /* MCAL_SCHM_LITE */

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

/**
* @brief    This function returns the MSR register value (32 bits).
* @return   uint32 This function returns the MSR register value (32 bits).
*/
RTE_FUNC uint32 SchM_Pwm_ReadMsr(void)
{
#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
    return __get_BASEPRI();
#else
    return __get_PRIMASK();
#endif
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_SCHM_LITE

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Pwm_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Pwm_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA(void)
{
    SchM_Pwm_ReentryGuard--;
    if ((TRUE == ISR_ON(SchM_Pwm_Msr)) && (0UL == SchM_Pwm_ReentryGuard))         /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_00[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_00[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_00[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_00[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_00[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_00[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_00[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_00[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_01[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_01[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_01[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_01[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_01[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_01[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_01[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_01[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_02[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_02[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_02[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_02[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_02[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_02[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_02[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_02[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_03[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_03[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_03[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_03[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_03[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_03[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_03[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_03[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_04[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_04[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_04[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_04[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_04[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_04[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_04[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_04[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_05[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_05[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_05[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_05[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_05[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_05[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_05[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_05[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_06[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_06[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_06[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_06[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_06[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_06[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_06[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_06[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_07[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_07[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_07[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_07[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_07[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_07[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_07[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_07[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_08[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_08[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_08[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_08[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_08[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_08[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_08[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_08[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_09[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_09[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_09[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_09[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_09[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_09[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_09[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_09[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Pwm_ReentryGuard_10[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Pwm_Msr_10[CoreId] = OsIf_Trusted_Call_Return(SchM_Pwm_ReadMsr);
#else
        SchM_Pwm_Msr_10[CoreId] = SchM_Pwm_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Pwm_Msr_10[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Pwm_ReentryGuard_10[CoreId];
}

RTE_FUNC void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Pwm_ReentryGuard_10[CoreId];
    if ((TRUE == ISR_ON(SchM_Pwm_Msr_10[CoreId])) && (0UL == SchM_Pwm_ReentryGuard_10[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* #if (STD_ON == PWM_SCHM_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

