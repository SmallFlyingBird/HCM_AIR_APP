/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Intvet.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-16 14:21:13>
 */
/*============================================================================*/


/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V2.0.0       20170503     zuxiong.ding Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_Internal.h"
#include "Os_Processor.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_VECTOR_C_AR_MAJOR_VERSION     4U
#define OS_VECTOR_C_AR_MINOR_VERSION     2U
#define OS_VECTOR_C_AR_PATCH_VERSION     2U
#define OS_VECTOR_C_SW_MAJOR_VERSION     1U
#define OS_VECTOR_C_SW_MINOR_VERSION     0U
#define OS_VECTOR_C_SW_PATCH_VERSION     0U 

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_VECTOR_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif 
#if (OS_VECTOR_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif
#if (OS_VECTOR_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Patch Version"
#endif
#if (OS_VECTOR_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define		OS_ARCH_INT_CORE0                  OS_ARCH_INT_CPU0

/*==========[I S R]===========================================================*/
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
/* --------------------CORE0-------------------- */
FUNC(void, OS_CODE) SysTick_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_SysTick_IRQn_ID));
    Os_ArchSystemTimerCore0();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) ADC0_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_ADC0_IRQn_ID)); 

    ISR_OS_ADC0_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) ADC1_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_ADC1_IRQn_ID)); 

    ISR_OS_ADC1_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) DMA0_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_DMA0_IRQn_ID)); 

    ISR_OS_DMA0_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) ERM_double_fault_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_ERM_double_fault_IRQn_ID)); 

    ISR_OS_ERM_double_fault_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) ERM_single_fault_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_ERM_single_fault_IRQn_ID)); 

    ISR_OS_ERM_single_fault_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) FTFC_Fault_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_FTFC_Fault_IRQn_ID)); 

    ISR_OS_FTFC_Fault_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) LPIT0_Ch0_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_LPIT0_Ch0_IRQn_ID)); 

    ISR_OS_LPIT0_Ch0_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) LPUART1_RxTx_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_LPUART1_RxTx_IRQn_ID)); 

    ISR_OS_LPUART1_RxTx_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) LVD_LVW_IRQHandler(void) 
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_OS_LVD_LVW_IRQn_ID)); 

    ISR_OS_LVD_LVW_IRQHandler();

    OS_ARCH_ISR2_EPILOGUE(); 
}
FUNC(void, OS_CODE_FAST) LPUART0_RxTx_IRQHandler(void) 
{
    OS_ARCH_ISR1_PROLOGUE(Os_GetObjLocalId(CFG_OS_LPUART0_RxTx_IRQn_ID)); 

    ISR_OS_LPUART0_RxTx_IRQHandler();

    OS_ARCH_ISR1_EPILOGUE(); 
}
/* ------------------Interrupt install-------------------- */
FUNC(void, OS_CODE) Os_IntHandler(void)
{
	/* Just ignore this interrupt.  */
	while(1){}
}
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchInitIntPrio(void)
{
    Os_CoreIdType coreID = Os_SCB.sysCore;

    switch(coreID)
    {
		case 0:		       
				Os_InterruptInstall(OS_SysTick_IRQn, 11, OS_ARCH_INT_CORE0, SysTick_Handler);	       
				Os_InterruptInstall(OS_ADC0_IRQn, 7, OS_ARCH_INT_CORE0, ADC0_IRQHandler);
				Os_InterruptInstall(OS_ADC1_IRQn, 7, OS_ARCH_INT_CORE0, ADC1_IRQHandler);
				Os_InterruptInstall(OS_DMA0_IRQn, 4, OS_ARCH_INT_CORE0, DMA0_IRQHandler);
				Os_InterruptInstall(OS_ERM_double_fault_IRQn, 4, OS_ARCH_INT_CORE0, ERM_double_fault_IRQHandler);
				Os_InterruptInstall(OS_ERM_single_fault_IRQn, 4, OS_ARCH_INT_CORE0, ERM_single_fault_IRQHandler);
				Os_InterruptInstall(OS_FTFC_Fault_IRQn, 4, OS_ARCH_INT_CORE0, FTFC_Fault_IRQHandler);
				Os_InterruptInstall(OS_LPIT0_Ch0_IRQn, 8, OS_ARCH_INT_CORE0, LPIT0_Ch0_IRQHandler);
				Os_InterruptInstall(OS_LPUART0_RxTx_IRQn, 13, OS_ARCH_INT_CORE0, LPUART0_RxTx_IRQHandler);
				Os_InterruptInstall(OS_LPUART1_RxTx_IRQn, 10, OS_ARCH_INT_CORE0, LPUART1_RxTx_IRQHandler);
				Os_InterruptInstall(OS_LVD_LVW_IRQn, 4, OS_ARCH_INT_CORE0, LVD_LVW_IRQHandler);
     			break;
		default:
				break;
    }

	return;
} 


#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/

