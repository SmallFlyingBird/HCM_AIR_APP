/**************************************************************************************************/
/**
 * @file      : Exception.c
 * @brief     : exception source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Platform_Module
 *  @{
 */

/** @defgroup Exception
 *  @brief It provides the source code of Exceptions.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Os_User.h"
#include "McalLib.h"
#include "CpuLoad.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define EXCEPTION_C_VENDOR_ID                   0x00B3U
#define EXCEPTION_C_AR_RELEASE_MAJOR_VERSION    4U
#define EXCEPTION_C_AR_RELEASE_MINOR_VERSION    6U
#define EXCEPTION_C_AR_RELEASE_REVISION_VERSION 0U
#define EXCEPTION_C_SW_MAJOR_VERSION            1U
#define EXCEPTION_C_SW_MINOR_VERSION            2U
#define EXCEPTION_C_SW_PATCH_VERSION            2U

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

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

void undefined_handler(void);                            /* Undefined Handler */
void NMI_Handler(void) __attribute__((weak));            /* NMI Handler */
void HardFault_Handler(void) __attribute__((weak));      /* Hard Fault Handler */
void MemManageFault_Handler(void) __attribute__((weak)); /* Reserved */
void BusFault_Handler(void) __attribute__((weak));       /* Bus Fault Handler */
void UsageFault_Handler(void) __attribute__((weak));     /* Usage Fault Handler */
void DebugMonitor_Handler(void) __attribute__((weak));   /* Debug Monitor Handler */
void PendSV_Handler(void) __attribute__((weak));         /* PendSV Handler */
void SysTick_Handler(void) __attribute__((weak));        /* SysTick Handler */
#ifdef MCAL_SUPPORT_USER_MODE
    #ifdef _IAR_C_Z20K14XM_
void SVC_Handler(void) __attribute__((naked, weak)); /* SVCall Handler */
    #endif
void SVC_Handler_Main(uint32 *svc_args);
#else
void SVC_Handler(void) __attribute__((weak)); /* SVCall Handler */
#endif /* MCAL_SUPPORT_USER_MODE */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
uint32 Os_Timer = 0;
void HardFault_Handler(void)
{
    while (TRUE)
    {
    };
}

void NMI_Handler(void)
{
    while (TRUE)
    {
    };
}

void MemManageFault_Handler(void)
{
    while (TRUE)
    {
    };
}

void BusFault_Handler(void)
{
    while (TRUE)
    {
    };
}

void UsageFault_Handler(void)
{
    while (TRUE)
    {
    };
}

void DebugMonitor_Handler(void)
{
    while (TRUE)
    {
    };
}

void PendSV_Handler(void)
{
    while (TRUE)
    {
    };
}

void SysTick_Handler(void)
{
	uint8 index;
	Os_Timer++;

	for(index = OsIndex_5ms;index<OsIndex_Total;index++)
	{
		if(TaskInfo[index].TaskExpiryPoint == Os_Timer)
		{
			TaskInfo[index].TaskState = Os_Task_Pending;
			TaskInfo[index].TaskExpiryPoint += TaskInfo[index].Cycle;
		}
	}
#if (CpuloadMonitor_Enable == STD_ON)
	if(Os_Timer%200 == 0) //200ms base time.
	{
		CpuLoad_Calculation();
	}
#endif
}

void undefined_handler(void)
{
    while (TRUE)
    {
    };
}

#ifdef MCAL_SUPPORT_USER_MODE
    #ifndef _IAR_C_Z20K14XM_
ASM_KEYWORD(".globl SVC_Handler");
ASM_KEYWORD(".weak SVC_Handler");
ASM_KEYWORD("SVC_Handler:");
ASM_KEYWORD("tst lr, #4");
ASM_KEYWORD("ite eq");
ASM_KEYWORD("mrseq r0, MSP");
ASM_KEYWORD("mrsne r0, PSP");
ASM_KEYWORD("b SVC_Handler_Main");
    #else
void SVC_Handler(void)
{
    ASM_KEYWORD("tst lr, #4");
    ASM_KEYWORD("ite eq \n\t"
                "mrseq r0, MSP \n\t"
                "mrsne r0, PSP");
    ASM_KEYWORD("b SVC_Handler_Main");
}
    #endif

void SVC_Handler_Main(uint32 *SvcArgs)
{
    uint32 SvcNum;
    SvcNum = ((uint8 *)SvcArgs[6])[-2];
    if (0U == SvcNum)
    {
        /* set privileged thread */
        ASM_KEYWORD("push {r0}");
        ASM_KEYWORD("mov r0, #0x0");
        ASM_KEYWORD("msr CONTROL, r0");
        ASM_KEYWORD("pop {r0}");
    }
    else if (1U == SvcNum)
    {
        /* suspend interrupts */
        ASM_KEYWORD("push {r0}");
        ASM_KEYWORD("mov r0, #0x10");
        ASM_KEYWORD("msr BASEPRI, r0");
        ASM_KEYWORD("pop {r0}");
    }
    else if (2U == SvcNum)
    {
        /* resume interrupts */
        ASM_KEYWORD("push {r0}");
        ASM_KEYWORD("mov r0, #0x0");
        ASM_KEYWORD("msr BASEPRI, r0");
        ASM_KEYWORD("pop {r0}");
    }
    else
    {
        /* do nothing */
    }
}
#else
void SVC_Handler(void)
{
    while (TRUE)
    {
    };
}
#endif /* MCAL_SUPPORT_USER_MODE */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Exception */

/** @} end of group Platform_Module */
