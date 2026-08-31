/**
* @file    SchM_Spi.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Spi
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
*   @file    SchM_Spi.c
*
*   @addtogroup SCHM_SPI_MODULE
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
#include "SchM_Spi.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_SPI_VENDOR_ID_C                      (180)
#define SCHM_SPI_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SCHM_SPI_AR_RELEASE_MINOR_VERSION_C       (4)
#define SCHM_SPI_AR_RELEASE_REVISION_VERSION_C    (0)
#define SCHM_SPI_SW_MAJOR_VERSION_C               (2)
#define SCHM_SPI_SW_MINOR_VERSION_C               (3)
#define SCHM_SPI_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_SPI header file are of the same vendor */
#if (SCHM_SPI_VENDOR_ID_C != SCHM_SPI_VENDOR_ID)
#error "SchM_Spi.c and SchM_Spi.h have different vendor ids"
#endif

/* Check if source file and SCHM_SPI header file are of the same Autosar version */
#if (( SCHM_SPI_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_SPI_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_SPI_AR_RELEASE_REVISION_VERSION_C != SCHM_SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Spi.c and SchM_Spi.h are different"
#endif

/* Check if source file and SCHM_SPI header file are of the same Software version */
#if (( SCHM_SPI_SW_MAJOR_VERSION_C != SCHM_SPI_SW_MAJOR_VERSION) || \
      ( SCHM_SPI_SW_MINOR_VERSION_C != SCHM_SPI_SW_MINOR_VERSION) || \
      ( SCHM_SPI_SW_PATCH_VERSION_C != SCHM_SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Spi.c and SchM_Spi.h are different"
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

#if(STD_ON == SPI_SCHM_SUPPORT)
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Spi_Msr;
RTE_VAR static volatile uint8 SchM_Spi_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Spi_Msr_00;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_00;

RTE_VAR static volatile uint32 SchM_Spi_Msr_01;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_01;

RTE_VAR static volatile uint32 SchM_Spi_Msr_02;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_02;

RTE_VAR static volatile uint32 SchM_Spi_Msr_03;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_03;

RTE_VAR static volatile uint32 SchM_Spi_Msr_04;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_04;

RTE_VAR static volatile uint32 SchM_Spi_Msr_05;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_05;

RTE_VAR static volatile uint32 SchM_Spi_Msr_06;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_06;

RTE_VAR static volatile uint32 SchM_Spi_Msr_07;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_07;

RTE_VAR static volatile uint32 SchM_Spi_Msr_08;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_08;

RTE_VAR static volatile uint32 SchM_Spi_Msr_09;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_09;

RTE_VAR static volatile uint32 SchM_Spi_Msr_10;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_10;

RTE_VAR static volatile uint32 SchM_Spi_Msr_11;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_11;

RTE_VAR static volatile uint32 SchM_Spi_Msr_12;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_12;

RTE_VAR static volatile uint32 SchM_Spi_Msr_13;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_13;

RTE_VAR static volatile uint32 SchM_Spi_Msr_14;
RTE_VAR static volatile uint32 SchM_Spi_ReentryGuard_14;

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
RTE_FUNC uint32 SchM_Spi_ReadMsr(void)
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

RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Spi_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (ISR_ON(SchM_Spi_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA(void)
{
    SchM_Spi_ReentryGuard--;
    if ((ISR_ON(SchM_Spi_Msr)) && (0UL == SchM_Spi_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_00(void)
{
    if (0UL == SchM_Spi_ReentryGuard_00)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_00 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_00 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_00++;
}

RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_00(void)
{
    SchM_Spi_ReentryGuard_00--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_00)) && (0UL == SchM_Spi_ReentryGuard_00))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**************************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01(void)
{
    if (0UL == SchM_Spi_ReentryGuard_01)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_01 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_01 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_01++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01(void)
{
    SchM_Spi_ReentryGuard_01--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_01)) && (0UL == SchM_Spi_ReentryGuard_01))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/***************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02(void)
{
    if (0UL == SchM_Spi_ReentryGuard_02)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_02 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_02 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_02++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02(void)
{
    SchM_Spi_ReentryGuard_02--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_02)) && (0UL == SchM_Spi_ReentryGuard_02))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03(void)
{
    if (0UL == SchM_Spi_ReentryGuard_03)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_03 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_03 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_03++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03(void)
{
    SchM_Spi_ReentryGuard_03--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_03)) && (0UL == SchM_Spi_ReentryGuard_03))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04(void)
{
    if (0UL == SchM_Spi_ReentryGuard_04)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_04 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_04 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_04)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_04++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04(void)
{
    SchM_Spi_ReentryGuard_04--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_04)) && (0UL == SchM_Spi_ReentryGuard_04))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05(void)
{
    if (0UL == SchM_Spi_ReentryGuard_05)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_05 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_05 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_05)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_05++;
}

RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05(void)
{
    SchM_Spi_ReentryGuard_05--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_05)) && (0UL == SchM_Spi_ReentryGuard_05))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06(void)
{
    if (0UL == SchM_Spi_ReentryGuard_06)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_06 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_06 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_06)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_06++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06(void)
{
    SchM_Spi_ReentryGuard_06--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_06)) && (0UL == SchM_Spi_ReentryGuard_06))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07(void)
{
    if (0UL == SchM_Spi_ReentryGuard_07)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_07 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_07 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_07)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_07++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07(void)
{
    SchM_Spi_ReentryGuard_07--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_07)) && (0UL == SchM_Spi_ReentryGuard_07))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08(void)
{
    if (0UL == SchM_Spi_ReentryGuard_08)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_08 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_08 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_08)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_08++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08(void)
{
    SchM_Spi_ReentryGuard_08--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_08)) && (0UL == SchM_Spi_ReentryGuard_08))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09(void)
{
    if (0UL == SchM_Spi_ReentryGuard_09)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_09 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_09 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_09)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_09++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09(void)
{
    SchM_Spi_ReentryGuard_09--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_09)) && (0UL == SchM_Spi_ReentryGuard_09))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_10(void)
{
    if (0UL == SchM_Spi_ReentryGuard_10)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_10 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_10 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_10)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_10++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_10(void)
{
    SchM_Spi_ReentryGuard_10--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_10)) && (0UL == SchM_Spi_ReentryGuard_10))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11(void)
{
    if (0UL == SchM_Spi_ReentryGuard_11)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_11 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_11 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_11)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_11++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11(void)
{
    SchM_Spi_ReentryGuard_11--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_11)) && (0UL == SchM_Spi_ReentryGuard_11))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_12(void)
{
    if (0UL == SchM_Spi_ReentryGuard_12)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_12 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_12 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_12)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_12++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_12(void)
{
    SchM_Spi_ReentryGuard_12--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_12)) && (0UL == SchM_Spi_ReentryGuard_12))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_13(void)
{
    if (0UL == SchM_Spi_ReentryGuard_13)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_13 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_13 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_13)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_13++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_13(void)
{
    SchM_Spi_ReentryGuard_13--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_13)) && (0UL == SchM_Spi_ReentryGuard_13))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
/**********************************************************************************/
/**********************************************************************************/
RTE_FUNC void SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_14(void)
{
    if (0UL == SchM_Spi_ReentryGuard_14)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Spi_Msr_14 = OsIf_Trusted_Call_Return(SchM_Spi_ReadMsr);
#else
        SchM_Spi_Msr_14 = SchM_Spi_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Spi_Msr_14)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Spi_ReentryGuard_14++;
}
RTE_FUNC void SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14(void)
{
    SchM_Spi_ReentryGuard_14--;
    if ((TRUE == ISR_ON(SchM_Spi_Msr_14)) && (0UL == SchM_Spi_ReentryGuard_14))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* STD_ON == SPI_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file SchM_Spi.c */

