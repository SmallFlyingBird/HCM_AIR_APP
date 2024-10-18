/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Intvet.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-09-30 11:04:15>
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
#define     OS_ARCH_INT_CORE0                  OS_ARCH_INT_CPU0

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
FUNC(void, OS_CODE_FAST) OS_ADC0_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ADC0_IRQn_ID));
    ISR_OS_ADC0_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_ADC1_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ADC1_IRQn_ID));
    ISR_OS_ADC1_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_BUSOFF_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_BUSOFF_IRQn_ID));
    ISR_OS_CAN6_BUSOFF_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_ECC_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_ECC_IRQn_ID));
    ISR_OS_CAN6_ECC_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_ERROR_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_ERROR_IRQn_ID));
    ISR_OS_CAN6_ERROR_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_MSG_0_31_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_MSG_0_31_IRQn_ID));
    ISR_OS_CAN6_MSG_0_31_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_MSG_32_63_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_MSG_32_63_IRQn_ID));
    ISR_OS_CAN6_MSG_32_63_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_MSG_64_95_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_MSG_64_95_IRQn_ID));
    ISR_OS_CAN6_MSG_64_95_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_MSG_96_127_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_MSG_96_127_IRQn_ID));
    ISR_OS_CAN6_MSG_96_127_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_RX_WARNING_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_RX_WARNING_IRQn_ID));
    ISR_OS_CAN6_RX_WARNING_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_SELF_WKUP_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_SELF_WKUP_IRQn_ID));
    ISR_OS_CAN6_SELF_WKUP_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CAN6_TX_WARNING_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CAN6_TX_WARNING_IRQn_ID));
    ISR_OS_CAN6_TX_WARNING_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CMU0_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CMU0_IRQn_ID));
    ISR_OS_CMU0_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CMU1_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CMU1_IRQn_ID));
    ISR_OS_CMU1_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_CMU2_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_CMU2_IRQn_ID));
    ISR_OS_CMU2_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_MCPWM0_CH_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_MCPWM0_CH_IRQn_ID));
    ISR_OS_MCPWM0_CH_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_MCPWM1_CH_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_MCPWM1_CH_IRQn_ID));
    ISR_OS_MCPWM1_CH_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_SERU_CHANNEL_ERR_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SERU_CHANNEL_ERR_IRQn_ID));
    ISR_OS_SERU_CHANNEL_ERR_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_SERU_PARITY_ERR_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SERU_PARITY_ERR_IRQn_ID));
    ISR_OS_SERU_PARITY_ERR_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_STIM_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_STIM_IRQn_ID));
    ISR_OS_STIM_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_TIM0_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_TIM0_IRQn_ID));
    ISR_OS_TIM0_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_TIM1_IRQHandler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_TIM1_IRQn_ID));
    ISR_OS_TIM1_IRQn();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_DMA_CH12_TX_COMPLETE_IRQHandler(void)
{
    OS_ARCH_ISR1_PROLOGUE(Os_GetObjLocalId(CFG_DMA_CH12_TX_COMPLETE_IRQn_ID));
    ISR_OS_DMA_CH12_TX_COMPLETE_IRQn();
    OS_ARCH_ISR1_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) OS_DMA_CH13_TX_COMPLETE_IRQHandler(void)
{
    OS_ARCH_ISR1_PROLOGUE(Os_GetObjLocalId(CFG_DMA_CH13_TX_COMPLETE_IRQn_ID));
    ISR_OS_DMA_CH13_TX_COMPLETE_IRQn();
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
                Os_InterruptInstall(OS_SysTick_IRQn, 10, OS_ARCH_INT_CORE0, SysTick_Handler);
                Os_InterruptInstall(OS_ADC0_IRQn, 5, OS_ARCH_INT_CORE0, OS_ADC0_IRQHandler);
                Os_InterruptInstall(OS_ADC1_IRQn, 5, OS_ARCH_INT_CORE0, OS_ADC1_IRQHandler);
                Os_InterruptInstall(OS_CAN6_BUSOFF_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_BUSOFF_IRQHandler);
                Os_InterruptInstall(OS_CAN6_ECC_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_ECC_IRQHandler);
                Os_InterruptInstall(OS_CAN6_ERROR_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_ERROR_IRQHandler);
                Os_InterruptInstall(OS_CAN6_MSG_0_31_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_MSG_0_31_IRQHandler);
                Os_InterruptInstall(OS_CAN6_MSG_32_63_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_MSG_32_63_IRQHandler);
                Os_InterruptInstall(OS_CAN6_MSG_64_95_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_MSG_64_95_IRQHandler);
                Os_InterruptInstall(OS_CAN6_MSG_96_127_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_MSG_96_127_IRQHandler);
                Os_InterruptInstall(OS_CAN6_RX_WARNING_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_RX_WARNING_IRQHandler);
                Os_InterruptInstall(OS_CAN6_SELF_WKUP_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_SELF_WKUP_IRQHandler);
                Os_InterruptInstall(OS_CAN6_TX_WARNING_IRQn, 5, OS_ARCH_INT_CORE0, OS_CAN6_TX_WARNING_IRQHandler);
                Os_InterruptInstall(OS_CMU0_IRQn, 4, OS_ARCH_INT_CORE0, OS_CMU0_IRQHandler);
                Os_InterruptInstall(OS_CMU1_IRQn, 4, OS_ARCH_INT_CORE0, OS_CMU1_IRQHandler);
                Os_InterruptInstall(OS_CMU2_IRQn, 4, OS_ARCH_INT_CORE0, OS_CMU2_IRQHandler);
                Os_InterruptInstall(OS_DMA_CH12_TX_COMPLETE_IRQn, 11, OS_ARCH_INT_CORE0, OS_DMA_CH12_TX_COMPLETE_IRQHandler);
                Os_InterruptInstall(OS_DMA_CH13_TX_COMPLETE_IRQn, 11, OS_ARCH_INT_CORE0, OS_DMA_CH13_TX_COMPLETE_IRQHandler);
                Os_InterruptInstall(OS_MCPWM0_CH_IRQn, 5, OS_ARCH_INT_CORE0, OS_MCPWM0_CH_IRQHandler);
                Os_InterruptInstall(OS_MCPWM1_CH_IRQn, 5, OS_ARCH_INT_CORE0, OS_MCPWM1_CH_IRQHandler);
                Os_InterruptInstall(OS_SERU_CHANNEL_ERR_IRQn, 5, OS_ARCH_INT_CORE0, OS_SERU_CHANNEL_ERR_IRQHandler);
                Os_InterruptInstall(OS_SERU_PARITY_ERR_IRQn, 5, OS_ARCH_INT_CORE0, OS_SERU_PARITY_ERR_IRQHandler);
                Os_InterruptInstall(OS_STIM_IRQn, 6, OS_ARCH_INT_CORE0, OS_STIM_IRQHandler);
                Os_InterruptInstall(OS_TIM0_IRQn, 5, OS_ARCH_INT_CORE0, OS_TIM0_IRQHandler);
                Os_InterruptInstall(OS_TIM1_IRQn, 5, OS_ARCH_INT_CORE0, OS_TIM1_IRQHandler);
        break;
        default:
        break;
    }
    return;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/

