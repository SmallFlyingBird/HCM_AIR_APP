/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016-2023)                                          **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : portasm.s                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : i-soft-os                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : Exception and Interrupt Handling Entry                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform r19                         **
**  Version :   AUTOSAR classic Platform R19--Function Safety                 **
**                                                                            **
*******************************************************************************/
    .thumb2

    .long Os_SCB
    .long Os_ArchTempSp
    .long Os_TaskSchedule
    .long Os_IsrTempIPSR
    .long Os_TaskCBExt

#define ASM_NULL                0
#define SYSRUNNINGTCB_OFFSET    0
#define SYSRUNNINGTASKID_OFFSET 10
#define FPU_FPCAR               0xE000EF38

/*****************************************************************************/
/*
 * Brief                <Switch tasks>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <System services>
 * REQ ID               <None>
 */
/*****************************************************************************/
.global PendSV_Handler
PendSV_Handler:
    cpsid i
    ldr r0, =Os_SCB
    ldr r0, [r0]
    cmp r0, 0
    beq	lable
    ldr r1, = Os_ArchTempSp
    mrs r0, psp
    sub r0, r0, #0x2C
    sub r0, r0, #0x80
    str r0, [r1]
    vmrs r1, FPSCR
    ldr r2, = 0xE000EF38
    ldr r2, [r2]
    mrs r3,control
    vstmia r0, {s0-s15}
    add r0, r0, #0x40
    vstmia r0, {s16-s31}
    add r0, r0, #0x40
    stmia r0, {r1-r11}
lable:
    dsb
    isb

    PUSH {LR}
    bl Os_TaskSchedule
    POP {LR}

    cpsid i
    ldr r0, =Os_ArchTempSp
    ldr r0, [r0]
    vldmia r0, {s0-s15}
    add r0, r0, #0x40
    vldmia r0, {s16-s31}
    add r0, r0, #0x40
    ldmia r0, {r1-r11}
    add r0, r0, #0x2C
    ldr r1, = 0xE000EF38
    str r2, [r1]
    vmsr FPSCR, r1
    msr control,r3
    msr psp, r0
    tst lr, #0x8
    it ne
    movne lr, #0xfffffffd
    dsb
    isb
    cpsie i
    bx lr

/*****************************************************************************/
/*
 * Brief                <terminate isr>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <System services>
 * REQ ID               <None>
 */
/*****************************************************************************/
.global TERMINATEISR_ISR
TERMINATEISR_ISR:
    push {r0}
    ldr r0, =Os_IsrTempIPSR
    ldr r0, [r0]
    ORR  R0, R0, #0x01000000U
    push {r0}  /*xpsr*/
    ldr r0, =TERMINATEISR_ISR_1
    push {r0}   /*PC*/
    push {R14}   /*LR*/
    push {R12}
    push {R3}
    push {R2}
    push {R1}
    push {R0}
    mov lr, #0xfffffff1
    bx lr 

/*****************************************************************************/
/*
 * Brief                <terminate isr cat1>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <System services>
 * REQ ID               <None>
 */
/*****************************************************************************/
TERMINATEISR_ISR_1:
    pop {r0}
    bx lr

    .end


/*=======[E N D   O F   F I L E]==============================================*/

