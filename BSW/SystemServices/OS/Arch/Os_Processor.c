/*===========================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Os_Processor.c>
 *  @brief      <>
 *
 * <Compiler: S32K    MCU:S32K344>
 *
 *  @author     <jiansen.zhao>
 *  @date       <04-01-2022>
 */
/*===========================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]===================================*/
/*  <VERSION>    <DATE>       <AUTHOR>          <REVISION LOG>
 *  V0.1.0      2021070705   jiansen.zhao     Initial version
 */
/*===========================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]===========================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*===========================================================================*/

/*=======[I N C L U D E S]===================================================*/
#include "Os.h"
#include "Os_Processor.h"
#include "Os_Internal.h"
/*=======[V E R S I O N  C H E C K]==========================================*/

/*=======[M A C R O S]=======================================================*/

/*=======[E X T E R N A L   D A T A]=========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint32, OS_VAR)    Os_IsrIPSR[CFG_ISR_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(uint32, AUTOMATIC, OS_VAR) Os_ArchMasterSp_New = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(uint32, AUTOMATIC, OS_VAR) Os_ArchTopStkPtr = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint32, OS_VAR) Os_ArchMasterSp_ARRAY[20] = {0U};
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR) Os_ArchTempSp = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR) Os_ArchControl = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_TaskCBExtType, AUTOMATIC, OS_VAR) Os_TaskCBExt = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(uint32, AUTOMATIC, OS_VAR) Os_IsrNestPcxStack = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(OS_ISR_ADDR, AUTOMATIC, OS_VAR) Os_IsrDAddr = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(OS_TASK_ADDR, AUTOMATIC, OS_VAR) Os_TaskDAddr = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) HardFault_Flag = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif

#pragma ghs section bss=".os_intc_vector"
uint32 IntcOsIsrVectorTable[256];
#pragma ghs section

#define OS_START_SEC_VAR_CLEARED_CLONE_32
#include "Os_MemMap.h"
VAR(uint32, OS_VAR)                         Os_IsrTempIPSR;
#define OS_STOP_SEC_VAR_CLEARED_CLONE_32
#include "Os_MemMap.h"

/*=======[I N T E R N A L   D A T A]=========================================*/
#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore0[CFG_TASK_MAX_CORE0] = {0u};
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore0[CFG_ISR_MAX_CORE0] = {0};
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(uint8, OS_VAR) Os_IntNestISR1 = 0U;
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(uint8, OS_VAR) Os_IntNestISR2 = 0U;
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_CallLevelType, OS_VAR) Os_SaveLevelISR1 = OS_LEVEL_ISR1;
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR) Os_TprotTerminateIsr = FALSE;
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR) Os_TprotTerminateTask = FALSE;
#define OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Os_MemMap.h"
#endif

static Reg_Stim_BfType *const stimRegPtr = (Reg_Stim_BfType *) STIM_BASE_ADDR;  /* PRQA S 0303 */ /* MISRA Rule 11.4 */
static Reg_Stim_WType *const stimRegWPtr = (Reg_Stim_WType *) STIM_BASE_ADDR;  /* PRQA S 3218,0303 */ /* MISRA Rule 8.9,11.4 */

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]=======*/
#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_ArchInitSystemTimer(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_ArchInitTimingProtTimer(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
void STIM_CounterStart(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

#if (CFG_OSAPPLICATION_MAX > 0 && CFG_ISR_MAX > 0 && TRUE == CFG_INT_NEST_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(StatusType, OS_CODE) Os_ArchTerminateOneNestIsr(Os_IsrType OsIsrID);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_InterruptInit(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(Os_IPLType, OS_CODE) Os_ArchGetMsr(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_ArchSetMsr(register Os_IPLType primask_val);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) Os_StartSysTimer(void);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

extern const uint32 __STACK_TOP;

extern const uint32 __OS_INTERRUPT_START;
/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]===================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_MultiCoreInitProcessor(void)
{
    switch (Os_SCB.sysCore)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case 0:
        Os_TaskCBExt = Os_TaskCBExtCore0;
        Os_IsrNestPcxStack = Os_IsrNestPcxStackCore0;
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
        Os_IsrDAddr = Os_Isr_DAddr_Core0;
        Os_TaskDAddr = Os_Task_DAddr_Core0;
#endif
        break;
#endif

        /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }
}
/*****************************************************************************/
/*
 * Brief                <Get PRIMASK register>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ipl>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchSuspendInt and so on>
 */
/******************************************************************************/
static FUNC(Os_IPLType, OS_CODE) Os_ArchGetMsr(void) /* PRQA S 3008 */ /* MISRA Dir 4.3 */
{
    register Os_IPLType primask_reg;

    ASM(" mrs %0, primask " : "=r"(primask_reg));

    return primask_reg;
}

/*****************************************************************************/
/*
 * Brief                <Set PRIMASK register>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ipl>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchSuspendInt and so on>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ArchSetMsr(register Os_IPLType primask_val)/* PRQA S 3006 */ /* MISRA Dir 4.3 */
{
    primask_val = primask_val;              /* Eliminate QAC warnings */
    ASM(" msr primask, %0 " : : "r"(primask_val));
}

/*****************************************************************************/
/*
 * Brief                <Ipl greater than 0, disable interrupt otherwise enable interrupt>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ipl>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ResumeOSInterrupts and so on>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetIpl(Os_IPLType ipl, Os_IsrDescriptionType isrdesc)/* PRQA S 3006 */ /* MISRA Dir 4.3 */
{
    /*add comments to pass QAC.*/
    (void)isrdesc;
    /* Disable interrupt prio - 1,CAN open the max OSinterrupt self*/
    register Os_IPLType converted_prio = OS_NVIC_CONVERT_SET_PRIO(ipl);

    ASM("msr basepri, %0" : : "r"(converted_prio));
}

/******************************************************************************/
/*
 * Brief                <Get current IPL>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <0>
 * PreCondition         <None>
 * CallByAPI            <SuspendOSInterrupts and so on>
 */
/******************************************************************************/
FUNC(Os_IPLType, OS_CODE) Os_ArchGetIpl(void) /* PRQA S 3006 */ /* MISRA Dir 4.3 */
{
    register Os_IPLType result;

    ASM("MRS %0, basepri_max" : "=r"(result));

    result = OS_NVIC_CONVERT_GET_PRIO(result);

    return (result);
}

/******************************************************************************/
/*
 * Brief                <Save ccr to variable msr and disable maskable interrupt>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <SuspendAllInterrupts>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSuspendInt(P2VAR(Os_ArchMsrType, AUTOMATIC, OS_VAR) msr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Os_ArchMsrType priMask = 0;
    priMask = Os_ArchGetMsr();
    Os_ArchSetMsr((*msr) | OS_MSR_PRIMASK_BIT0); /* PRQA S 4461 */ /* MISRA Rule 10.3 */
    *msr = priMask;
}
/******************************************************************************/
/*
 * Brief                <transfer variable msr back to ccr>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ResumeAllInterrupts>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchRestoreInt(Os_ArchMsrType msr)
{
    OS_ARCH_DSYNC();

    Os_ArchSetMsr(msr); /* PRQA S 4461 */ /* MISRA Rule 10.3 */
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/*****************************************************************************/
/*
 * Brief                <SVC_Handler>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <System services>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) SVC_Handler(void)
{
    Os_SetCpuMode(OS_CPUMODE_SUPERVISOR);
}
#endif
#if (CFG_MEMORY_PROTECTION_ENABLE == TRUE)
/* Memory access error handler */
FUNC(void, OS_CODE) HardFault_Handler(void)
{
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;
    uint8 slave_num = 0u;
    uint8 MpuErrorCounter = 0;
    HardFault_Flag = 1;
    
    /*Os_ArchMpDefaultConfigSwitch();*/
    SMPU_Disable();

    for (slave_num = 0u; slave_num < (uint32)SMPU_SLV_PORT_ALL; slave_num++)
    {
        uint32 errMaster = 0xFF;

        errMaster = SMPU_GetErrAccMstNum((SMPU_SlvPort_t)slave_num); /* PRQA S 4342 */ /* MISRA Rule 10.5 */
        if (errMaster < (uint32)SMPU_SLV_PORT_ALL)
        {
            SMPU_ErrorType_t error;
            SMPU_GetAccErrCause((SMPU_SlvPort_t)slave_num, &error); /* PRQA S 4342 */ /* MISRA Rule 10.5 */

            MpuErrorCounter++;
            if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            {
                WhoHook = OS_TMPROT_HOOK_TASK;
            }
            else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
            {
                WhoHook = OS_TMPROT_HOOK_ISR;
            }
            else
            {
                /* Do nothing. */
            }
    
        }
    }
    (void) Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, WhoHook);
    

}
#else
FUNC(void, OS_CODE) HardFault_Handler(void)
{
#if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    uint32 WhoHook = OS_TMPROT_HOOK_OSAPP;

    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_TASK;
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        WhoHook = OS_TMPROT_HOOK_ISR;
    }
    else
    {
        /* Do nothing. */
    }
#endif
#if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))

    /* OS245:  protection exception hook. */
    (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, WhoHook);
#else
    while (1)
    {

    }
#endif
}
#endif
/*****************************************************************************/
/*
 * Brief                <Os_TaskSchedule>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_PreTask>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_TaskSchedule(void)
{
    if(NULL_PTR != Os_SCB.sysRunningTCB)
    {
        Os_TaskCBExt[Os_SCB.sysRunningTaskID] = Os_ArchTempSp;/* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
    }
     #if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
     if (TRUE == Os_TprotTerminateTask)
     {
          /* PRQA S 2741,1840,2742,1842,3432,0303,3430++ */ /* MISRA Rule 14.3,10.4,11.4,20.7 */
          OS_INTERRUPT_SET_PRIO(OS_PendSV_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MIN));
          /* PRQA S 2741,1840,2742,1842,3432,0303,3430-- */ /* MISRA Rule 14.3,10.4,11.4,20.7 */
          Os_TprotTerminateTask = FALSE;
     }
     #endif
     Os_SwitchTask();
      Os_ArchTempSp = Os_TaskCBExt[Os_SCB.sysRunningTaskID];
}
/*****************************************************************************/
/*
 * Brief                <First entry task>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_PreTask>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void)
{
    /* !!!0306-MISRA Rule 11.4 */
     /* !!!0488-MISRA Rule 18.4 */
     Os_ArchTopStkPtr = (uint32 *)OS_ARCH_STACK_ALIGN((uint32)Os_SCB.sysRunningTCB->taskTop);/* PRQA S 0306,3430 */ /* MISRA Rule 11.4,20.7 */

    /*registers stacked as if auto-saved on exception.
     * The follow registers will automatic restore when exiting an exception.
     * --xPSR, PC, LR, R12, R3, R2, R1, R0--*/
    /* PRQA S 3440 ++*/ /* MISRA Rule 13.3 */
    *(--Os_ArchTopStkPtr) = 0x01000000U;              /* xPSR */
    *(--Os_ArchTopStkPtr) = (uint32)Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskEntry;/* PRQA S 0305 */ /* MISRA Rule 11.1 */
    *(--Os_ArchTopStkPtr) = (uint32)Os_TaskErrBack;   /* R14(LR) *//* PRQA S 0305 */ /* MISRA Rule 11.1 */
    *(--Os_ArchTopStkPtr) = 0U;                      /* R12 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R3 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R2 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R1 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R0 */
    /*remaining registers saved on process stack*/
    *(--Os_ArchTopStkPtr) = 0U;                      /* R11 */
    *(--Os_ArchTopStkPtr) = 0U;                      /* R10 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R9 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R8 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R7 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R6 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R5 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* R4 */
    /*CONTROL register*/
    Os_ArchTopStkPtr = Os_ArchTopStkPtr - 1;
    #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if((TRUE == Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted) &&
            (TRUE != Os_AppCfg[Os_SCB.sysRunningAppID].OsTrustedAppWithProtection))
    {
        *Os_ArchTopStkPtr = 0x00000000;
    }
    else
    {
        *Os_ArchTopStkPtr = 0x00000001;
    }
    #else
    *Os_ArchTopStkPtr = 0x00000000;
    #endif
    *(--Os_ArchTopStkPtr) = 0U;                       /* FPCAR*/
    *(--Os_ArchTopStkPtr) = 0U;                       /* FPSCR*/

    /*registers stacked as if auto-saved on exception.
     * The follow registers will automatic restore when exiting an exception.
     * --S31-S16, S15~S0--*/
    *(--Os_ArchTopStkPtr) = 0U;                       /* S31 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S30 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S29 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S28 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S27 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S26 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S25 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S24 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S23 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S22 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S21 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S20 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S19 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S18 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S17 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S16 */

    *(--Os_ArchTopStkPtr) = 0U;                       /* S15 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S14 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S13 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S12 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S11 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S10 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S9 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S8 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S7 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S6 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S5 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S4 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S3 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S2 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S1 */
    *(--Os_ArchTopStkPtr) = 0U;                       /* S0 */
    /* PRQA S 3440 --*/ /* MISRA Rule 13.3 */
    Os_TaskCBExt[Os_SCB.sysRunningTaskID] = (uint32)Os_ArchTopStkPtr;/* PRQA S 0306 */ /* MISRA Rule 11.4 */
    /* PRQA S 2741,1840,2742,1842,3432,0303,3430++ */ /* MISRA Rule 14.3,10.4,11.4,20.7 */
    OS_INTERRUPT_SET_PRIO(OS_PendSV_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MIN));
    /* PRQA S 2741,1840,2742,1842,3432,0303,3430-- */ /* MISRA Rule 14.3,10.4,11.4,20.7 */
}

/*****************************************************************************/
/*
 * Brief                <Os_ArchDispatch>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchDispatch(void)
{
    /* Call PendSV to switch task */
    ASM("cpsid i                            \n"
        ".set NVIC_INT_CTRL,0xE000ED04      \n"
        ".set NVIC_PENDSVSET,0x10000000     \n"
        "ldr r0, =NVIC_INT_CTRL             \n"
        "ldr r1, =NVIC_PENDSVSET            \n"
        "str r1, [r0]                       \n"
        "dsb                                \n"
        "cpsie i                            \n");

}

/*****************************************************************************/
/*
 * Brief                <Os_ArchDispatch_ISR>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchDispatch_ISR(void)
{
    /* Call PendSV to switch task */
    ASM("cpsid i                            \n"
        ".set NVIC_INT_CTRL, 0xE000ED04     \n"
        ".set NVIC_PENDSVSET, 0x10000000    \n"
        "ldr r0, =NVIC_INT_CTRL             \n"
        "ldr r1, =NVIC_PENDSVSET            \n"
        "str r1, [r0]                       \n"
        "dsb                                \n");
}

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/*****************************************************************************/
/*
 * Brief                <Os_ArchSyscall>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchSyscall(void)
{
    ASM(" svc 0                                \n"
        " nop                                  \n");
}
#endif

/*****************************************************************************/
/*
 * Brief                <Os_ArchStartScheduler>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <ShutdownOS>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchStartScheduler(void)
{
    /*notes: the code of start system timer must be lightweight, otherwise the
     * previous step 'synchronization' will not make sense*/
    Os_StartSysTimer();
    
    /*Run the scheduler*/
    Os_Dispatch(); /* System call */
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Os_ArchInitCPU>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitCPU(void)
{
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
    HardFault_Flag = 0;
#endif
    Z20_SCB->CCR |= 0x01U; /* PRQA S 0306 */ /* MISRA Rule 11.4*/

    FPU_AutoStoreFunctionClose();
    Os_InterruptInit();
    Os_ArchInitIntPrio();

#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
    Os_ArchInitSystemTimer();
#endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_ArchInitTimingProtTimer();
#endif
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************/
/*
 * Brief                <Os_ArchInitSystemTimer>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
static FUNC(void, OS_CODE) Os_ArchInitSystemTimer(void)
{

    /* Core_0 System Timer Initialize.Value = 48000000u*T - 1u (T--Second) */
    /* PRQA S 0303++ */ /* MISRA Rule 11.4*/
    OS_SYSTICK_CTRL_REG = 0x0u;
    OS_SYSTICK_COUNTER_REG = 0x0u;
    OS_SYSTICK_RELOAD_REG = CFG_REG_OSTIMER_VALUE_CORE0 - 0x1u;
    OS_SYSTICK_CTRL_REG = (OS_SYSTICK_CLK_BIT | OS_SYSTICK_INT_BIT);
    /* PRQA S 0303-- */ /* MISRA Rule 11.4*/

}

/*****************************************************************************/
/*
 * Brief                <start system timer>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
static FUNC(void, OS_CODE) Os_StartSysTimer(void)
{
#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
    /*Start SysTick counter*/
    OS_SYSTICK_CTRL_REG |= OS_SYSTICK_ENABLE_BIT; /* PRQA S 0303 */ /* MISRA Rule 11.4*/
#endif /*TRUE == CFG_SYSTEM_TIMER_ENABLE*/

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    /*Start timing protection timer*/
    STIM_CounterStart();
#endif /*TRUE == CFG_TIMING_PROTECTION_ENABLE*/
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*****************************************************************************/
/*
 * Brief                <init STM Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
void STIM_CounterStart(void)
{
    stimRegWPtr->STIM_CNTn[0] = 0;
    stimRegWPtr->STIM_CVn[0] = 3000; /* Fstim = 40M/4 = 10M, 1/10M = 0.1us, 0.1us*10000 = 1ms */
    stimRegPtr->STIM_SCn[0].EN = 0; /* Stim channel n is disabled. */
    stimRegPtr->STIM_SCn[0].IE = 1; /* Stim channel n interrupt request is enabled. */
    stimRegPtr->STIM_SCn[0].RSTDIS = 0; /* Stim channel n counter resets and increases from 0 when counter match. */
    stimRegPtr->STIM_SCn[0].MODE = 0; /* Stim channel n counter operates in free counting mode. */
    stimRegPtr->STIM_SCn[0].PSEN = 1; /* The prescaler or glitch filter was enabled. A counter clock source will be divided and, the input pulse glitch can be filtered. */
    stimRegPtr->STIM_SCn[0].PSDIV = 1; /* Divide the STIM counter clock source by 4 */
    stimRegPtr->STIM_SCn[0].CLKS = 2; /* Select OSC-40M clock as the clock source. */
    stimRegPtr->STIM_SCn[0].EN = 1; /* Stim channel n is enabled. */
}

/*****************************************************************************/
/*
 * Brief                <init STM Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
void STIM0_ClearStatusFlags(void)
{
    stimRegPtr->STIM_SCn[0].FLAG = 1;
}

/*****************************************************************************/
/*
 * Brief                <init STM Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
static FUNC(void, OS_CODE) Os_ArchInitTimingProtTimer(void)
{
    #if 0
    OS_STIM_CTRL &= 0xEFFFU;                     /* disable Stim */
    OS_STIM_CNT = 0;
    OS_STIM_CV = CFG_REG_TP_TIMER_VALUE_CORE0;
    OS_STIM_CTRL |= 0x2000U; /* Enable Interrupt */
    #endif
    STIM_CounterStart();
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_ISR_MAX > 0)
/*****************************************************************************/
/*
 * Brief                <Disable all interrupts in os_app during TerminateApplication.>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchDisableIntInApp(P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg)
{
    uint16 i;
    uint16 osIsrRefCnt;
    Os_IsrType osIsrId;
    uint32 osIsrRegVal;

    osIsrRefCnt = posCurAppCfg->OsAppIsrRefCnt;

    for (i = 0; i < osIsrRefCnt; i++)
    {
        osIsrId = Os_GetObjLocalId(posCurAppCfg->OsAppObjectRef[OBJECT_ISR][i]);

        osIsrRegVal = Os_IsrCfg[osIsrId].OsIsrSrc;

        OS_INTERRUPT_CLEAR_PENDING(osIsrRegVal); /* PRQA S 1840,1842,3432,0303 */ /* MISRA Rule 10.4,11.4,20.7 */
        OS_INTERRUPT_DISABLE(osIsrRegVal); /* PRQA S 1840,4542,1842,0303,3432,2004,1841,1843 */ /* MISRA Rule 10.4,10.1,11.4,20.7,15.7,20.7*/
    }
    if((HardFault_Flag == (uint16)1) && (Os_SCB.sysOsLevel == OS_LEVEL_ISR2))
    {
        Os_IsrTempIPSR = Os_IsrCfg[Os_IntCfgIsrId].OsIsrSrc;
        TERMINATEISR_ISR();
    }
}

#if (TRUE == CFG_INT_NEST_ENABLE)
static FUNC(StatusType, OS_CODE) Os_ArchTerminateOneNestIsr(Os_IsrType OsIsrID)
{
    uint8 i;

    for (i = 0; i < Os_IntNestISR2; i++)
    {
        /* find out the Isr nested position and reclaim its context saving area */
        if (OsIsrID == Os_SCB.sysIsrNestQueue[i])
        {
            break;
        }
    }

    /* Not find out the Isr Id in the IsrStack from the SCB,
     * not include outermost_isr. */
    if (i >= Os_IntNestISR2)
    {
        return E_NOT_OK;
    }

    /* Moving the following nested ISR2s to shift one position left */
    while (i < (Os_IntNestISR2 - (uint8)1))
    {
        Os_SCB.sysIsrNestQueue[i] = Os_SCB.sysIsrNestQueue[i + 1]; /* PRQA S 0404,1860 */ /* MISRA Rule 1.3,13.2,10.4 */

        if (i < (Os_IntNestISR2 - (uint8)2))
        {
            Os_IsrNestPcxStack[i + 1] = Os_IsrNestPcxStack[i + 2]; /* PRQA S 0404,1860 */ /* MISRA Rule 1.3,13.2,10.4 */
        }

        i++;
    }

    return E_OK;
}

/*****************************************************************************/
/*
 * Brief                <Terminate Isr2 platform process in TerminateApplication>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchAppTerminateIsrProc(Os_IsrType OsIsrID)
{
    uint32 ulRet = E_OK;

    /* Isr_nest process. */
    /* Just find out the nested corresponding ISR2s(excluding the running one) */
    if (OsIsrID != Os_SCB.sysRunningIsrCat2Id)
    {
        /* Terminate one isr */
        ulRet = Os_ArchTerminateOneNestIsr(OsIsrID);

        if (E_OK == ulRet)
        {
            if (Os_IntNestISR2 > (uint8)0)
            {
                Os_IntNestISR2--;
            }

            if (Os_SCB.sysDispatchLocker > (uint8)0)
            {
                Os_SCB.sysDispatchLocker--;
            }
            Os_IsrTempIPSR = Os_IsrIPSR[Os_IntNestISR2-(uint8)1];
            TERMINATEISR_ISR();
        }
    }

    return;
}
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */
#endif /* #if (CFG_ISR_MAX > 0) */

/*****************************************************************************/
/*
 * Brief                <TerminateTask arch_process in TerminateApplication.>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchAppTerminateTaskProc(Os_TaskType OsTaskID)
{
    /*add comments to pass QAC.*/
    (void)OsTaskID;
    /* do nothing:This interface is implemented in AURIX */
    return;
}

#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*****************************************************************************/
/*
 * Brief                <Call by Spin-lock API>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
uint32 Os_CmpSwapW(uint32* address, uint32 compareVal, uint32 exchangedVal)
{
    uint32 ret = 0;
    (void)address;
    (void)compareVal;
    (void)exchangedVal;
    return ret;
}

/*****************************************************************************/
/*
 * Brief                <Installation interrupted>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_InterruptInstall(uint8 id, uint8 prio, uint32 srcType, Os_isrhnd isrProc)
{
    (void)srcType;
    /* PRQA S 4542,4391,3430,1840,2004,3432,1841,1862,1860,0303,1863,1891++ */ /* MISRA Rule 10.1,10.8,20.7,10.4,15.7,20.7,11.4,10.7 */
    OS_INTERRUPT_INSTALL(id, prio, srcType);
    /* PRQA S 4542,4391,3430,1840,2004,3432,1841,1862,1860,0303,1863,1891-- */ /* MISRA Rule 10.1,10.8,20.7,10.4,15.7,20.7,11.4,10.7 */
    /* Save the former handler pointer */
    if (isrProc != NULL_PTR)
    {
        /* Set handler into vector table */
        IntcOsIsrVectorTable[id] = (uint32)isrProc; /* PRQA S 0305 */ /* MISRA Rule 11.1 */
    }
}

/*****************************************************************************/
/*
 * Brief                <Remove interruption>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_InterruptUnload(uint8 id, uint8 prio, uint32 srcType, Os_isrhnd isrProc)
{
    (void)srcType;
    (void)prio;
    /* PRQA S 1862,4391,2004,3432,0303,4542,1860,1863,1891,1841++ */ /* MISRA Rule 10.4,10.8,15.7,10.1,11.4,20.7*/
    OS_INTERRUPT_Unload(id, prio, srcType);
    /* PRQA S 1862,4391,2004,3432,0303,4542,1860,1863,1891,1841-- */ /* MISRA Rule 10.4,10.8,15.7,10.1,11.4,20.7 */
    /* Clean the former handler pointer */
    if (isrProc != NULL_PTR)
    {
        /* Set handler into vector table */
        IntcOsIsrVectorTable[((uint32)id)] = (uint32)Os_IntHandler; /* PRQA S 0305 */ /* MISRA Rule 11.1 */
    }

}
/*****************************************************************************/
/*
 * Brief                <Installation interrupt by default>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
static FUNC(void, OS_CODE) Os_InterruptInit(void)
{
    uint32 index;
    uint32 addr = (uint32)&__OS_INTERRUPT_START; /* PRQA S 0306 */ /* MISRA Rule 11.4 */
    uint32 stack = (uint32)&__STACK_TOP; /* PRQA S 0306 */ /* MISRA Rule 11.4 */

    Z20_SCB->VTOR = addr; /* PRQA S 0306 */ /* MISRA Rule 11.4 */
    for (index = 0; index < OS_NVIC_NUM; index++)
    {
        if (index >= 16u)                                                      /* User interrupt */
        {
            /* PRQA S 1840,4542,1842,0303,3432,2004,1841,1843++ */ /* MISRA Rule 10.4,10.1,11.4,20.7,15.7,20.7*/
            OS_INTERRUPT_DISABLE(index);                                       /* Disable interrupt */
            /* PRQA S 1840,4542,1842,0303,3432,2004,1841,1843-- */ /* MISRA Rule 10.4,10.1,11.4,20.7,15.7,20.7*/

            /* PRQA S 1840,1842,3432,0303++ */ /* MISRA Rule 10.4,11.4,20.7 */
            OS_INTERRUPT_CLEAR_PENDING(index);                                 /* Clear pending interrupt */
            /* PRQA S 1840,1842,3432,0303-- */ /* MISRA Rule 10.4,11.4,20.7 */

            /* PRQA S 1840,1842,3432,0303,3430++ */ /* MISRA Rule 10.4,11.4,20.7 */
            OS_INTERRUPT_SET_PRIO(index, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MIN)); /* Set interrupt priority to MIN */
            /* PRQA S 1840,1842,3432,0303,3430-- */ /* MISRA Rule 10.4,11.4,20.7 */
            IntcOsIsrVectorTable[index] = (uint32) &Os_IntHandler;  /* PRQA S 0305 */ /* MISRA Rule 11.1 */
        }
        else if (0u == index )                                                  /* HardFault */
        {
            IntcOsIsrVectorTable[OS_INITSTACK_IRQn] = stack;
        }
        else if (1u == index )                                                  /* HardFault */
        {
            IntcOsIsrVectorTable[OS_RESET_IRQn] = (uint32) (&Reset_Handler + 1);  /* PRQA S 2753,0493,0305 */ /* MISRA Rule 1.1,11.1 */
        }
        else if (2u == index )                                                  /* HardFault */
        {
            IntcOsIsrVectorTable[OS_NonMaskableInt_IRQn] = (uint32) &NMI_Handler;  /* PRQA S 0305 */ /* MISRA Rule 11.1 */
        }
        else if (3u == index )                                                  /* HardFault */
        {
            IntcOsIsrVectorTable[OS_HardFault_IRQn] = (uint32) &HardFault_Handler;  /* PRQA S 0305 */ /* MISRA Rule 11.1 */
        }
        else if (5u == index )                                                  /* HardFault */
        {
            IntcOsIsrVectorTable[OS_BusFault_IRQn] = (uint32) &BusFault_Handler;  /* PRQA S 0305 */ /* MISRA Rule 11.1 */
        }
        else if (6u == index )                                                  /* HardFault */
        {
            IntcOsIsrVectorTable[OS_UsageFault_IRQn] = (uint32) &UsageFault_Handler;  /* PRQA S 0305 */ /* MISRA Rule 11.1 */
        }
        #if (CFG_SRV_SHELLOS == TRUE)
        else if (11u == index)                                                 /* SVC */
        {
            /* PRQA S 2741,0303,1842,2742,3432,1840,3430,0305++ */ /* MISRA Rule 10.4,11.4,20.7,14.3,11.1 */
            OS_INTERRUPT_SET_PRIO(OS_SVCall_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MAX));
            /* PRQA S 2741,0303,1842,2742,3432,1840,3430,0305-- */ /* MISRA Rule 10.4,11.4,20.7,14.3,11.1 */
            IntcOsIsrVectorTable[OS_SVCall_IRQn] = (uint32) (&SVC_Handler);  /* PRQA S 0305 */ /* MISRA Rule 11.1 */
        }
        #endif
        else if (14u == index )                                                 /* PendSV */
        {
            /* PRQA S 2741,0303,1842,2742,3432,1840,3430,0305++ */ /* MISRA Rule 10.4,11.4,20.7,14.3,11.1 */
            OS_INTERRUPT_SET_PRIO(OS_PendSV_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MAX));
            /* PRQA S 2741,0303,1842,2742,3432,1840,3430,0305-- */ /* MISRA Rule 10.4,11.4,20.7,14.3,11.1 */
            IntcOsIsrVectorTable[OS_PendSV_IRQn] = (uint32) (&PendSV_Handler + 1);  /* PRQA S 0493 */ /* MISRA Rule 1.1 */
        }
        else if (15u == index )                                                 /* SysTick */
        {
            /* Default */
        }
        else
        {
            /* Default */
        }
    }
}

/*****************************************************************************/
/*
 * Brief                <Os_ArchGetCoreID>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return               <CoreId>
 * PreCondition         <None>
 * CallByAPI            <GetCoreID>
 */
/*****************************************************************************/
FUNC(Os_CoreIdType, OS_CODE) Os_ArchGetCoreID(void)
{
    /* S32K344 just have only one core */
    return 0;
}

/******************************************************************************/
/*
 * Brief                <Os_ArchStartCore>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-coreId[in]     <selects the core which to start>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartCore>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchStartCore(Os_CoreIdType coreId)
{
    (void)coreId;
}

/******************************************************************************/
/*
 * Brief                <Get the Core Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <selects the core which to get mode>
 * Return               <Os_CoreModeType,the core mode>
 * PreCondition         <None>
 * CallByAPI            <Os_SetCoreMode>
 */
/******************************************************************************/
FUNC(Os_CoreModeType, OS_CODE) Os_GetCoreMode(Os_CoreIdType core)
{
    (void)core;
    Os_CoreModeType coreMode = OS_CORE_MODE_UNKNOWN;
    return coreMode;
}

/******************************************************************************/
/*
 * Brief                <Set the Core Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <boolean,the result of setting>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 */
/******************************************************************************/
FUNC(boolean, OS_CODE) Os_SetCoreMode(Os_CoreIdType core, Os_CoreModeType coreMode)
{
    (void)core;
    (void)coreMode;
    boolean returnCode = TRUE;

    return returnCode;
}
/******************************************************************************/
/*
 * Brief                <Close FPU auto store function>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <non-reentrant>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <System Init>
 */
/******************************************************************************/
FUNC(void, OS_CODE) FPU_AutoStoreFunctionClose(void)
{
    __asm("LDR.W R0, =0xE000EF34");

    __asm("LDR R1, [R0]");

    __asm("AND R1, R1, #0x7FFFFFFF");

    __asm("STR R1, [R0]"); /*  wait for store to complete  */

    __asm("DSB");

    __asm("ISB");
    /*OS_REG32(0xE000ED88U) |= 0x03 << 20;*/ 
}

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/******************************************************************************/
/*
 * Brief                <Get the CPU Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <Os_CPUModeType,the CPU mode>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 */
/******************************************************************************/
FUNC(Os_CPUModeType, OS_CODE) Os_GetCpuMode(void)
{
    Os_ArchGetControl();

    Os_ArchControl &= 0x1u;
    if (Os_ArchControl != (uint32)0)
    {
        return OS_CPUMODE_USER0;
    }
    else
    {
        return OS_CPUMODE_SUPERVISOR;
    }
}
#endif
/******************************************************************************/
/*
 * Brief                <Set the CPU Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <Os_CPUModeType,the CPU mode>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SetCpuMode(Os_CPUModeType mode)/* PRQA S 3006 */ /* MISRA Dir 4.3 */
{
    if (OS_CPUMODE_SUPERVISOR == mode)
    {
        ASM("mrs r0,control               \n"
            "and r0,r0,#0xFFFFFFFE        \n"
            "msr control, r0              \n");
    }
    else
    {
        ASM("mrs r0,control               \n"
            "orr r0,r0,#0x01              \n"
            "msr control, r0              \n");
    }
}

/******************************************************************************/
/*
 * Brief                <Get the Control Value>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <Os_CPUModeType,the CPU mode>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 */
/******************************************************************************/
uint32 getControlValue(void)/* PRQA S 3008 */ /* MISRA Dir 4.3 */
{
    register uint32 result;

    __asm("MRS %0, control" : "=r"(result));

    return result;
}

/******************************************************************************/
/*
 * Brief                < Get IPSR Register >
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
FUNC(uint32, OS_CODE) Os_GetIsrIPSR(void)/* PRQA S 3008 */ /* MISRA Dir 4.3 */
{
    uint32 result;

    ASM ("MRS %0, ipsr" : "=r" (result) );
    
    return(result);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
