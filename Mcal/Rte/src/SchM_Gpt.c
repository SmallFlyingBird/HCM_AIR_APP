/**
 * @file    SchM_Gpt.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR SchM_Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup SCHM_GPT_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr, Ptmr, Tmr, Rtc
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
#include "SchM_Gpt.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_GPT_VENDOR_ID_C                    (180)
#define SCHM_GPT_AR_RELEASE_MAJOR_VERSION_C     (4)
#define SCHM_GPT_AR_RELEASE_MINOR_VERSION_C     (4)
#define SCHM_GPT_AR_RELEASE_REVISION_VERSION_C  (0)
#define SCHM_GPT_SW_MAJOR_VERSION_C             (2)
#define SCHM_GPT_SW_MINOR_VERSION_C             (3)
#define SCHM_GPT_SW_PATCH_VERSION_C             (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_GPT header file are of the same vendor */
#if (SCHM_GPT_VENDOR_ID_C != SCHM_GPT_VENDOR_ID)
#error "SchM_Gpt.c and SchM_Gpt.h have different vendor ids"
#endif

/* Check if source file and SCHM_GPT header file are of the same Autosar version */
#if (( SCHM_GPT_AR_RELEASE_MAJOR_VERSION_C != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_GPT_AR_RELEASE_MINOR_VERSION_C != SCHM_GPT_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_GPT_AR_RELEASE_REVISION_VERSION_C != SCHM_GPT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Gpt.c and SchM_Gpt.h are different"
#endif

/* Check if source file and SCHM_GPT header file are of the same Software version */
#if (( SCHM_GPT_SW_MAJOR_VERSION_C != SCHM_GPT_SW_MAJOR_VERSION) || \
      ( SCHM_GPT_SW_MINOR_VERSION_C != SCHM_GPT_SW_MINOR_VERSION) || \
      ( SCHM_GPT_SW_PATCH_VERSION_C != SCHM_GPT_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Gpt.c and SchM_Gpt.h are different"
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

#if (STD_ON == GPT_SCHM_SUPPORT)
/*==================================================================================================
 *                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Gpt_Msr;
RTE_VAR static volatile uint8 SchM_Gpt_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Gpt_Msr_00[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_00[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_01[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_01[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_02[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_02[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_03[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_03[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_04[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_04[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_05[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_05[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_06[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_06[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_07[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_07[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_08[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_08[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_09[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_09[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_10[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_10[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_11[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_11[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_12[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_12[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_13[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_13[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_14[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_14[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_15[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_15[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_16[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_16[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_17[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_17[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_18[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_18[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_19[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_19[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_20[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_20[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_21[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_21[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_22[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_22[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_23[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_23[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_24[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_24[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_25[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_25[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_26[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_26[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_27[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_27[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_28[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_28[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_29[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_29[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_30[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_30[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_Msr_31[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Gpt_ReentryGuard_31[NUMBER_OF_CORES];

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
RTE_FUNC uint32 SchM_Gpt_ReadMsr(void)
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

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Gpt_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(SchM_Gpt_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA(void)
{
    SchM_Gpt_ReentryGuard--;
    if ((ISR_ON(SchM_Gpt_Msr)) && (0UL == SchM_Gpt_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_00[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_00[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_00[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_00[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_00[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_00[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_00[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_00[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_01[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_01[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_01[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_01[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_01[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_01[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_01[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_01[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_02[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_02[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_02[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_02[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_02[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_02[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_02[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_02[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_03[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_03[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_03[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_03[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_03[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_03[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_03[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_03[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_04[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_04[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_04[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_04[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_04[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_04[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_04[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_04[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_05[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_05[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_05[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_05[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_05[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_05[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_05[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_05[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_06[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_06[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_06[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_06[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_06[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_06[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_06[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_06[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_07[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_07[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_07[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_07[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_07[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_07[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_07[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_07[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_08[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_08[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_08[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_08[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_08[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_08[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_08[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_08[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_09[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_09[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_09[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_09[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_09[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_09[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_09[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_09[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_10[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_10[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_10[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_10[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_10[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_10[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_10[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_10[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_11[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_11[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_11[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_11[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_11[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_11[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_11[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_11[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_12[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_12[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_12[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_12[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_12[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_12[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_12[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_12[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_13[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_13[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_13[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_13[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_13[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_13[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_13[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_13[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_14[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_14[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_14[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_14[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_14[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_14[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_14[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_14[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_15[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_15[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_15[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_15[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_15[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_15[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_15[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_15[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_16[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_16[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_16[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_16[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_16[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_16[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_16[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_16[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_17[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_17[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_17[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_17[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_17[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_17[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_17[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_17[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_18[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_18[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_18[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_18[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_18[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_18[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_18[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_18[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_19[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_19[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_19[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_19[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_19[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_19[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_19[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_19[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_20[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_20[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_20[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_20[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_20[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_20[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_20[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_20[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_21[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_21[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_21[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_21[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_21[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_21[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_21[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_21[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_22[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_22[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_22[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_22[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_22[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_22[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_22[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_22[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_23[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_23[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_23[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_23[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_23[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_23[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_23[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_23[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_24[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_24[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_24[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_24[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_24[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_24[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_24[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_24[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_25[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_25[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_25[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_25[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_25[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_25[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_25[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_25[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_26[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_26[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_26[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_26[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_26[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_26[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_26[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_26[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_27[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_27[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_27[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_27[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_27[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_27[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_27[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_27[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_28[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_28[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_28[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_28[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_28[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_28[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_28[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_28[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_29[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_29[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_29[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_29[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_29[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_29[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_29[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_29[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_30[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_30[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_30[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_30[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_30[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_30[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_30[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_30[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    if (0UL == SchM_Gpt_ReentryGuard_31[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Gpt_Msr_31[CoreId] = OsIf_Trusted_Call_Return(SchM_Gpt_ReadMsr);
#else
        SchM_Gpt_Msr_31[CoreId] = SchM_Gpt_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Gpt_Msr_31[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Gpt_ReentryGuard_31[CoreId]++;
}

RTE_FUNC void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31(void)
{
    uint32 CoreId = (uint32)OsIf_GetCoreID();
    SchM_Gpt_ReentryGuard_31[CoreId]--;
    if ((TRUE == ISR_ON(SchM_Gpt_Msr_31[CoreId])) && (0UL == SchM_Gpt_ReentryGuard_31[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif  /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* #if (STD_ON == GPT_SCHM_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

