;  ***************************************************************************************
;  @file      : Startup.s                                                                 
;  @brief     : Startup Source File.                                                      
;               - Platform: Z20K14xM                                                      
;               - Autosar Version: 4.6.0                                                  
;  @version   : 1.2.1                                                                     
;  @author    : Zhixin Semiconductor                                                      
;  @note                                                                                  
;                                                                                         
;  @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.    
; ****************************************************************************************


    PRESERVE8
    THUMB

    AREA    |.text|, CODE, READONLY
    EXPORT  __SRAM_START
    EXPORT  __SRAM_END

    IMPORT  |Image$$ARM_LIB_STACK$$ZI$$Limit|
    IMPORT  main
    IMPORT  __VECTOR_TABLE
		
    IMPORT  |Image$$RW_IRAM0$$Base|
    IMPORT  |Image$$RW_IRAM1$$Base|
    IMPORT  |Load$$RW_IRAM1$$Base|
    IMPORT  |Load$$RW_IRAM1$$Limit|
    IMPORT  |Image$$RW_IRAM3$$Base|
    IMPORT  |Image$$RW_IRAM3$$Limit|
    IMPORT  |Image$$RW_IRAM3$$Length|
		IF :LNOT: :DEF:START_FROM_SRAM
    IMPORT  |Load$$ER_IROM1$$Base|
    IMPORT  |Load$$ER_IROM1$$Limit|
    IMPORT  |Image$$ER_IROM3$$Base|
    IMPORT  |Image$$ER_IROM3$$Limit|
    IMPORT  |Image$$ER_IROM3$$Length|
        ENDIF
	IMPORT  |Image$$RW_IRAM2$$Base|	
    IMPORT  |Image$$RW_IRAM2$$Limit|	
    IMPORT  |Image$$RW_IRAM2$$Length|		

__SRAM_START             DCD |Image$$RW_IRAM0$$Base|
__SRAM_END               DCD |Image$$ARM_LIB_STACK$$ZI$$Limit|

__RAM_INIT_START         DCD |Image$$RW_IRAM1$$Base|
        IF :LNOT: :DEF:START_FROM_SRAM
__ROM_INIT_START         DCD |Load$$RW_IRAM1$$Base|
__ROM_INIT_END           DCD |Load$$RW_IRAM1$$Limit|
        ELSE
__ROM_INIT_START         DCD 0
__ROM_INIT_END           DCD 0
        ENDIF

__RAM_INTERRUPT_START    DCD |Image$$RW_IRAM0$$Base|
        IF :LNOT: :DEF:START_FROM_SRAM
__ROM_INTERRUPT_START    DCD |Load$$ER_IROM1$$Base|
__ROM_INTERRUPT_END      DCD |Load$$ER_IROM1$$Limit|
        ELSE
__ROM_INTERRUPT_START    DCD 0
__ROM_INTERRUPT_END      DCD 0
        ENDIF

__BSS_SRAM_START         DCD |Image$$RW_IRAM3$$Base|
__BSS_SRAM_END           DCD |Image$$RW_IRAM3$$Limit|

__STACK_TOP              DCD |Image$$ARM_LIB_STACK$$ZI$$Limit|
VTOR_REG                 DCD 0xE000ED08
CPACR_REG                DCD 0xE000ED88
CPACR_VAL                DCD 0x00F00000
        IF :LNOT: :DEF:START_FROM_SRAM
__SRAM_INIT_FLAG         DCD 1
        ELSE
__SRAM_INIT_FLAG         DCD 0
        ENDIF

    AREA    |.init_table|, DATA, READONLY
__INIT_TABLE
    DCD 2
    DCD __RAM_INIT_START
    DCD __ROM_INIT_START
    DCD __ROM_INIT_END
    DCD __RAM_INTERRUPT_START
    DCD __ROM_INTERRUPT_START
    DCD __ROM_INTERRUPT_END  
__INIT_TABLE_END

    AREA    |.zero_table|, DATA, READONLY
__ZERO_TABLE
    DCD 1
    DCD __BSS_SRAM_START
    DCD __BSS_SRAM_END
__ZERO_TABLE_END

    AREA    |.startup|, CODE, READONLY
Reset_Handler   PROC
    ALIGN   4
    EXPORT  Reset_Handler             [WEAK]

    CPSID   I      ;Mask interrupts
    ;Init the registers
    LDR     R1,=0
    LDR     R2,=0
    LDR     R3,=0
    LDR     R4,=0
    LDR     R5,=0
    LDR     R6,=0
    LDR     R7,=0
    MOV     R8,R7
    MOV     R9,R7
    MOV     R10,R7
    MOV     R11,R7
    MOV     R12,R7

    ;relocate vector table to RAM.
SetVTOR
    LDR R0, =VTOR_REG
    LDR R0, [R0]
    LDR R1, =__RAM_INTERRUPT_START
    LDR R1, [R1]
    STR R1,[R0]

    ; set up stack; R13 SP.
SetStack
    LDR  R0, =__STACK_TOP
    LDR  R0, [R0]
    MSR MSP, R0
    B    EnableFPU

    ; Enable FPU. 
EnableFPU
    LDR  R0, =CPACR_REG
    LDR  R0, [R0]
    LDR  R1, [R0]
    LDR  R2, =CPACR_VAL
    LDR  R2, [R2]
    ORR  R1, R1, R2
    STR  R1, [R0]
    DSB
    ISB
    B    InitSram

    ; Initialize SRAM. 
InitSram
    LDR  R0, =__SRAM_INIT_FLAG
    LDR  R0, [R0]
    CMP  R0, #0        ; Check if __SRAM_INIT_FLAG is not set
    BEQ INIT_SRAM_LOOP_END
    LDR R1, =__SRAM_START
    LDR R1, [R1]
    LDR R2, =__SRAM_END
    LDR R2, [R2]
    
    SUBS    R2, R2, R1
    SUBS    R2, #1
    BLE INIT_SRAM_LOOP_END
    MOVS    R0, #0
    MOVS    R3, #0
INIT_SRAM_LOOP
    STM R1!, {R0, R3}
    SUBS R2, #8
    BGE INIT_SRAM_LOOP
INIT_SRAM_LOOP_END
    B    CopyRomToRam

    ; Copy the vector table from ROM to RAM. 
    ; Copy initialized data from ROM to RAM. 
    ; Copy code that should reside in RAM from ROM. 
CopyRomToRam
    LDR  R0, =__SRAM_INIT_FLAG
    LDR  R0, [R0]
    CMP  R0, #0         ; Check if __SRAM_INIT_FLAG is not set
    BEQ COPY_ROM_TO_RAM_END
    LDR R0, =__INIT_TABLE
    LDM R0!, {R1}       ; R1: major loop count
COPY_ROM_TO_RAM_START
    SUBS R1, #1
    BLT COPY_ROM_TO_RAM_END
    LDM R0!, {R3, R4, R5}
	LDR R3,  [R3]
	LDR R4,  [R4]
	LDR R5,  [R5]
    SUBS R2, R5, R4      ; R2: copy size 
    beq COPY_ROM_TO_RAM_START
COPY_ROM_TO_RAM_LOOP
    LDM R4!, {R6}
    STM R3!, {R6}
    SUBS R2, #4
    BGT COPY_ROM_TO_RAM_LOOP
    B COPY_ROM_TO_RAM_START
COPY_ROM_TO_RAM_END
    B InitBss

    ; Clear the zero-initialized data section. 
InitBss
    LDR R0, =__ZERO_TABLE
    LDM R0!, {R1}      ; R1: major loop count
INIT_BSS_DATA_START
    SUBS R1, #1
    BLT INIT_BSS_DATA_END
    LDM R0!, {R3, R4}
    SUBS R2, R4, R3      ; R2: copy size
    BEQ INIT_BSS_DATA_START
    MOVS R5, #0
INIT_BSS_DATA_LOOP
    STM R3!, {R5}
    SUBS R2, #4
    BGT INIT_BSS_DATA_LOOP
    B INIT_BSS_DATA_START
INIT_BSS_DATA_END


    ; Call Main Routine                                              
_MAIN
    CPSIE i
    BL main
    ENDP
    ALIGN
    END