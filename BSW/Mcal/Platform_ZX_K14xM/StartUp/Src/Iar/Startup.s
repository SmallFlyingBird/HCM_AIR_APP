/*****************************************************************************************/
/* @file      : startup.s                                                                */
/* @brief     : Startup Source File.                                                     */
/*              - Platform: Z20K14xM                                                     */
/*              - Autosar Version: 4.6.0                                                 */
/* @version   : 1.2.1                                                                    */
/* @author    : Zhixin Semiconductor                                                     */
/* @note                                                                                 */
/*                                                                                       */
/* @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.   */
/*****************************************************************************************/
#define VTOR_REG (0xE000ED08)
#define CPACR_REG (0xE000ED88)
#define CPACR_VAL (0x00F00000)

    EXTERN main
    EXTERN __VECTOR_TABLE
    EXTERN __STACK_TOP
    EXTERN __SRAM_INIT_FLAG
    EXTERN __SRAM_START
    EXTERN __SRAM_END
    EXTERN bssBlock$$Base
    EXTERN bssBlock$$Limit
    EXTERN .mcal_ramcode$$Base
    EXTERN .mcal_ramcode_init$$Base
    EXTERN .mcal_ramcode_init$$Limit
    EXTERN .data$$Base
    EXTERN .data_init$$Base
    EXTERN .data_init$$Limit
    EXTERN .mcal_data$$Base
    EXTERN .mcal_data_init$$Base
    EXTERN .mcal_data_init$$Limit
    EXTERN .intvec$$Base
    EXTERN .intvec_init$$Base
    EXTERN .intvec_init$$Limit
    PUBLIC  _start

    SECTION .init_table:CONST(4)
__INIT_TABLE
    DCD 4
    DCD .mcal_ramcode$$Base
    DCD .mcal_ramcode_init$$Base
    DCD .mcal_ramcode_init$$Limit
    DCD .data$$Base
    DCD .data_init$$Base
    DCD .data_init$$Limit
    DCD .mcal_data$$Base
    DCD .mcal_data_init$$Base
    DCD .mcal_data_init$$Limit
    DCD .intvec$$Base
    DCD .intvec_init$$Base
    DCD .intvec_init$$Limit
__INIT_TABLE_END

    SECTION .zero_table:CONST(4)
__ZERO_TABLE
    DCD 1
    DCD bssBlock$$Base
    DCD bssBlock$$Limit
__ZERO_TABLE_END

    THUMB
    PUBWEAK Reset_Handler
    SECTION .startup:CODE:REORDER:NOROOT(2)
_start:
Reset_Handler:
/*****************************************************/
/* Mask interrupts and initialize the registers */
/*****************************************************/
    CPSID   I
    LDR     R1,=0
    LDR     R2,=0
    LDR     R3,=0
    LDR     R4,=0
    LDR     R5,=0
    LDR     R6,=0
    LDR     R7,=0
    MOV     R8,R1
    MOV     R9,R1
    MOV     R10,R1
    MOV     R11,R1
    MOV     R12,R1

/**************************************************/
/* relocate vector table to RAM. */
/**************************************************/
SetVTOR:
    LDR R0, =VTOR_REG
    LDR R1, =__VECTOR_TABLE
    STR  r1,[r0]

/**************************************************/
/* set up stack; r13 SP. */
/**************************************************/
SetStack:
    LDR  r0, =__STACK_TOP
    MSR  MSP, r0
    B    EnableFPU

/**************************************************/
/* Enable FPU. */
/**************************************************/
EnableFPU:
    LDR  r0, =CPACR_REG
    LDR  r1, [r0]
    LDR  r2, =CPACR_VAL
    ORR  r1, r1, r2
    STR  r1, [r0]
    DSB
    ISB
    B    InitSram

/**************************************************/
/* Initialize SRAM. */
/**************************************************/
InitSram:
    LDR  R0, =__SRAM_INIT_FLAG
    CMP  R0, #0         /* Check if __SRAM_INIT_FLAG is not set */
    BEQ INIT_SRAM_LOOP_END
    LDR R1, =__SRAM_START
    LDR R2, =__SRAM_END
    
    SUBS    R2, R2, R1
    SUBS    R2, #1
    BLE INIT_SRAM_LOOP_END

    MOVS    R0, #0
    MOVS    R3, #0
INIT_SRAM_LOOP:
    STM R1!, {R0, R3}
    SUBS R2, #8
    BGE INIT_SRAM_LOOP
INIT_SRAM_LOOP_END:
    B    CopyRomToRam

/**************************************************/
/* Copy the vector table from ROM to RAM. */
/* Copy initialized data from ROM to RAM. */
/* Copy code that should reside in RAM from ROM. */
/**************************************************/
CopyRomToRam:
    LDR  R0, =__SRAM_INIT_FLAG
    CMP  R0, #0         /* Check if __SRAM_INIT_FLAG is not set */
    BEQ COPY_ROM_TO_RAM_END
    LDR R0, =__INIT_TABLE
    LDM R0!, {R1}      /* r1: major loop count */
COPY_ROM_TO_RAM_START:
    SUBS R1, #1
    BLT COPY_ROM_TO_RAM_END
    LDM R0!, {R3, R4, R5}
    SUBS R2, R5, R4      /* r2: copy size */
    beq COPY_ROM_TO_RAM_START
COPY_ROM_TO_RAM_LOOP:
    LDM R4!, {R6}
    STM R3!, {R6}
    SUBS R2, #4
    BGT COPY_ROM_TO_RAM_LOOP
    B COPY_ROM_TO_RAM_START
COPY_ROM_TO_RAM_END:
    B InitBss

/*********************************************/
/* Clear the zero-initialized data section. */
/********************************************/
InitBss:
    LDR R0, =__ZERO_TABLE
    LDM R0!, {R1}      /* r1: major loop count */
INIT_BSS_DATA_START:
    SUBS R1, #1
    BLT INIT_BSS_DATA_END
    LDM R0!, {R3, R4}
    SUBS R2, R4, R3      /* r2: copy size */
    BEQ INIT_BSS_DATA_START
    MOVS R5, #0
INIT_BSS_DATA_LOOP:
    STM R3!, {R5}
    SUBS R2, #4
    BGT INIT_BSS_DATA_LOOP
    B INIT_BSS_DATA_START
INIT_BSS_DATA_END:

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
_MAIN:
    CPSIE i
    BL main

  END
