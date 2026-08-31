/**
* @file    SchM_Adc.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Adc
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
*   @file    SchM_Adc.c
*
*   @addtogroup SCHM_ADC_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "OsIf.h"
#include "SchM_Adc.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_ADC_VENDOR_ID_C                      (180)
#define SCHM_ADC_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SCHM_ADC_AR_RELEASE_MINOR_VERSION_C       (4)
#define SCHM_ADC_AR_RELEASE_REVISION_VERSION_C    (0)
#define SCHM_ADC_SW_MAJOR_VERSION_C               (2)
#define SCHM_ADC_SW_MINOR_VERSION_C               (3)
#define SCHM_ADC_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_ADC header file are of the same vendor */
#if (SCHM_ADC_VENDOR_ID_C != SCHM_ADC_VENDOR_ID)
#error "SchM_Adc.c and SchM_Adc.h have different vendor ids"
#endif

/* Check if source file and SCHM_ADC header file are of the same Autosar version */
#if (( SCHM_ADC_AR_RELEASE_MAJOR_VERSION_C != SCHM_ADC_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_ADC_AR_RELEASE_MINOR_VERSION_C != SCHM_ADC_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_ADC_AR_RELEASE_REVISION_VERSION_C != SCHM_ADC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Adc.c and SchM_Adc.h are different"
#endif

/* Check if source file and SCHM_ADC header file are of the same Software version */
#if (( SCHM_ADC_SW_MAJOR_VERSION_C != SCHM_ADC_SW_MAJOR_VERSION) || \
      ( SCHM_ADC_SW_MINOR_VERSION_C != SCHM_ADC_SW_MINOR_VERSION) || \
      ( SCHM_ADC_SW_PATCH_VERSION_C != SCHM_ADC_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Adc.c and SchM_Adc.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
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

#if(STD_ON == ADC_SCHM_SUPPORT)
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Adc_Msr;
RTE_VAR static volatile uint8 SchM_Adc_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Adc_Msr_00;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_00;
RTE_VAR static volatile uint32 SchM_Adc_Msr_01;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_01;
RTE_VAR static volatile uint32 SchM_Adc_Msr_02;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_02;
RTE_VAR static volatile uint32 SchM_Adc_Msr_03;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_03;
RTE_VAR static volatile uint32 SchM_Adc_Msr_04;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_04;
RTE_VAR static volatile uint32 SchM_Adc_Msr_05;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_05;
RTE_VAR static volatile uint32 SchM_Adc_Msr_06;
RTE_VAR static volatile uint32 SchM_Adc_ReentryGuard_06;

#define RTE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

#endif /* MCAL_SCHM_LITE */

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

/**
* @brief   This function returns the MSR register value (32 bits).
* @details This function returns the MSR register value (32 bits).
*
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits).
*
* @pre  None
* @post None
*
*/
RTE_FUNC uint32 SchM_Adc_ReadMsr(void)
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
                                                GLOBAL FUNCTIONS
==================================================================================================*/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_SCHM_LITE

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Adc_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA(void)
{
    SchM_Adc_ReentryGuard--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr)) && (0UL == SchM_Adc_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00(void)
{
    if (0UL == SchM_Adc_ReentryGuard_00)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_00 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_00 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_00++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00(void)
{
    SchM_Adc_ReentryGuard_00--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_00)) && (0UL == SchM_Adc_ReentryGuard_00))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01(void)
{
    if (0UL == SchM_Adc_ReentryGuard_01)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_01 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_01 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_01++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01(void)
{
    SchM_Adc_ReentryGuard_01--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_01)) && (0UL == SchM_Adc_ReentryGuard_01))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02(void)
{
    if (0UL == SchM_Adc_ReentryGuard_02)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_02 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_02 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_02++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02(void)
{
    SchM_Adc_ReentryGuard_02--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_02)) && (0UL == SchM_Adc_ReentryGuard_02))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03(void)
{
    if (0UL == SchM_Adc_ReentryGuard_03)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_03 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_03 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_03++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03(void)
{
    SchM_Adc_ReentryGuard_03--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_03)) && (0UL == SchM_Adc_ReentryGuard_03))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04(void)
{
    if (0UL == SchM_Adc_ReentryGuard_04)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_04 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_04 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_04)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_04++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04(void)
{
    SchM_Adc_ReentryGuard_04--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_04)) && (0UL == SchM_Adc_ReentryGuard_04))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05(void)
{
    if (0UL == SchM_Adc_ReentryGuard_05)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_05 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_05 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_05)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_05++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05(void)
{
    SchM_Adc_ReentryGuard_05--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_05)) && (0UL == SchM_Adc_ReentryGuard_05))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06(void)
{
    if (0UL == SchM_Adc_ReentryGuard_06)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Adc_Msr_06 = OsIf_Trusted_Call_Return(SchM_Adc_ReadMsr);
#else
        SchM_Adc_Msr_06 = SchM_Adc_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Adc_Msr_06)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Adc_ReentryGuard_06++;
}

RTE_FUNC void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06(void)
{
    SchM_Adc_ReentryGuard_06--;
    if ((TRUE == ISR_ON(SchM_Adc_Msr_06)) && (0UL == SchM_Adc_ReentryGuard_06))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* STD_ON == ADC_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file SchM_Adc.c */

