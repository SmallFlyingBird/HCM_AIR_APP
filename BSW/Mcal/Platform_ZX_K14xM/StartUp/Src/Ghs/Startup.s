/*****************************************************************************************/
/* @file      : startup.s                                                                */
/* @brief     : Startup Source File.                                                     */
/*              - Platform: Z20K14xM                                                     */
/*              - Autosar Version: 4.6.0                                                 */
/* @version   : 1.2.2                                                                    */
/* @author    : Zhixin Semiconductor                                                     */
/* @note                                                                                 */
/*                                                                                       */
/* @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.   */
/*****************************************************************************************/
.section ".init_table", "a"
  .long 4
  .long __RAM_RAM_CODE_INIT_START
  .long __ROM_RAM_CODE_INIT_START
  .long __ROM_RAM_CODE_INIT_END
  .long __RAM_DATA_INIT_START
  .long __ROM_DATA_INIT_START
  .long __ROM_DATA_INIT_END
  .long __RAM_MCAL_DATA_INIT_START
  .long __ROM_MCAL_DATA_INIT_START
  .long __ROM_MCAL_DATA_INIT_END
  .long __RAM_INTERRUPT_START
  .long __ROM_INTERRUPT_START
  .long __ROM_INTERRUPT_END
.section ".zero_table", "a"
  .long 1
  .long __BSS_SRAM_START
  .long __BSS_SRAM_END

.globl __VECTOR_TABLE
.section ".startup","ax"
.thumb

.set VTOR_REG, 0xE000ED08
.set CPACR_REG, 0xE000ED88
.set CPACR_VAL, 0x00F00000

.align 2
.thumb
.globl Reset_Handler
Reset_Handler:
.globl _start
_start:
/*****************************************************/
/* Mask interrupts and initialize the registers */
/*****************************************************/
    cpsid i
    mov   r0, #0
    mov   r1, #0
    mov   r2, #0
    mov   r3, #0
    mov   r4, #0
    mov   r5, #0
    mov   r6, #0
    mov   r7, #0

/**************************************************/
/* relocate vector table to RAM. */
/**************************************************/
SetVTOR:
    ldr  r0, =VTOR_REG
    ldr  r1, =__RAM_INTERRUPT_START
    str  r1,[r0]

/**************************************************/
/* set up stack; r13 SP. */
/**************************************************/
SetStack:
    ldr  r0, =__STACK_TOP
    msr  MSP, r0
    b    EnableFPU

/**************************************************/
/* Enable FPU. */
/**************************************************/
EnableFPU:
    ldr  r0, =CPACR_REG
    ldr  r1, [r0]
    ldr  r2, =CPACR_VAL
    orr  r1, r2
    str  r1, [r0]
    dsb
    isb
    b    InitSram

/**************************************************/
/* Initialize SRAM. */
/**************************************************/
InitSram:
    ldr  r0, =__SRAM_INIT_FLAG
    cmp  r0, 0        /* Check if __SRAM_INIT_FLAG is not set */
    beq INIT_SRAM_LOOP_END
    ldr r1, =__SRAM_START
    ldr r2, =__SRAM_END

    subs    r2, r1
    subs    r2, #1
    ble INIT_SRAM_LOOP_END

    movs    r0, 0
    movs    r3, 0
INIT_SRAM_LOOP:
    stm r1!, {r0,r3}
    subs r2, #8
    bge INIT_SRAM_LOOP
INIT_SRAM_LOOP_END:
    b    CopyRomToRam

/**************************************************/
/* Copy the vector table from ROM to RAM. */
/* Copy initialized data from ROM to RAM. */
/* Copy code that should reside in RAM from ROM. */
/**************************************************/
CopyRomToRam:
    ldr  r0, =__SRAM_INIT_FLAG
    cmp  r0, 0
    beq COPY_ROM_TO_RAM_END
    ldr r0, =__INIT_TABLE
    ldm r0!, {r1}      /* r1: major loop count */
COPY_ROM_TO_RAM_START:
    subs r1, #1
    blt COPY_ROM_TO_RAM_END
    ldm r0!, {r3, r4, r5}
    subs r2, r5, r4      /* r2: copy size */
    beq COPY_ROM_TO_RAM_START
COPY_ROM_TO_RAM_LOOP:
    ldm r4!, {r6}
    stm r3!, {r6}
    subs r2, #4
    bgt COPY_ROM_TO_RAM_LOOP
    b COPY_ROM_TO_RAM_START
COPY_ROM_TO_RAM_END:
    b    InitBss

/*********************************************/
/* Clear the zero-initialized data section. */
/********************************************/
InitBss:
    ldr r0, =__ZERO_TABLE
    ldm r0!, {r1}      /* r1: major loop count */
INIT_BSS_DATA_START:
    subs r1, #1
    blt INIT_BSS_DATA_END
    ldm r0!, {r3, r4}
    subs r2, r4, r3      /* r2: copy size */
    beq INIT_BSS_DATA_START
    movs r5, #0
INIT_BSS_DATA_LOOP:
    stm r3!, {r5}
    subs r2, #4
    bgt INIT_BSS_DATA_LOOP
    b INIT_BSS_DATA_START
INIT_BSS_DATA_END:

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
_MAIN:
    cpsie i
    bl main

.align 4
.ltorg
