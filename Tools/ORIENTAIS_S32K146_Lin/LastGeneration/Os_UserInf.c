/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_UserInf.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-12 15:24:14>
 */
/*============================================================================*/


/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V2.0.0       20170615     shi.shu      Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 *	 V3.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Os_Extend.h"
#include "Os_Processor.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_USERAPP_C_AR_MAJOR_VERSION     4U
#define OS_USERAPP_C_AR_MINOR_VERSION     2U
#define OS_USERAPP_C_AR_PATCH_VERSION     2U
#define OS_USERAPP_C_SW_MAJOR_VERSION     1U
#define OS_USERAPP_C_SW_MINOR_VERSION     0U
#define OS_USERAPP_C_SW_PATCH_VERSION     0U 

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_USERAPP_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif 
#if (OS_USERAPP_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif
#if (OS_USERAPP_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Patch Version"
#endif
#if (OS_USERAPP_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif

/*=======[T A S K S]==========================================*/
/*OsTask_Init: Core0(CPU0),Type = BASIC, Priority = 7*/
TASK(OsTask_Init)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_1ms: Core0(CPU0),Type = BASIC, Priority = 6*/
TASK(OsTask_1ms)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_2ms: Core0(CPU0),Type = BASIC, Priority = 5*/
TASK(OsTask_2ms)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_5ms: Core0(CPU0),Type = BASIC, Priority = 4*/
TASK(OsTask_5ms)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_10ms: Core0(CPU0),Type = BASIC, Priority = 3*/
TASK(OsTask_10ms)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_50ms: Core0(CPU0),Type = BASIC, Priority = 2*/
TASK(OsTask_50ms)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_100ms: Core0(CPU0),Type = BASIC, Priority = 1*/
TASK(OsTask_100ms)
{
    /* please insert your code here ... */    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

/*=======[ALARM CALL BACK]==========================================*/

/*=======[H O O K S]================================================*/
FUNC(void, OS_APPL_CODE) IdleHook_Core0(void)
{
    /* please insert your code here ... */    
    while(1);								 	
}
void StartupHook(void)
{
    /* please insert your code here ... */
}

void ShutdownHook(StatusType Error)
{
    /* please insert your code here ... */
}




/*=======[I S R S]================================================*/
/*
 *ISR(ADC0_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_ADC0_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(ADC1_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_ADC1_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(DMA0_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_DMA0_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(ERM_double_fault_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_ERM_double_fault_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(ERM_single_fault_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_ERM_single_fault_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(FTFC_Fault_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_FTFC_Fault_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(LPIT0_Ch0_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_LPIT0_Ch0_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(LPUART0_RxTx_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_LPUART0_RxTx_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(LPUART1_RxTx_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_LPUART1_RxTx_IRQHandler)
{
	/* please insert your code here ... */
	
}

/*
 *ISR(LVD_LVW_IRQHandler: Core0(CPU0))
 */
ISR(ISR_OS_LVD_LVW_IRQHandler)
{
	/* please insert your code here ... */
	
}



/*=======[E N D   O F   F I L E]==============================================*/


