/***********************************************************************************************/
/**
 * @file      : Linker_Flash_Z20K146M.ld
 * @brief     : Linker script file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 ***********************************************************************************************/
/*
* Memory:
* 0x00000000    0x000FFFFF  1M    Program Flash
* 0x01000000    0x0101FFFF  128K  Data Flash
* 0x20000000    0x2001FFFF  128K  SRAM
*/

MEMORY
{
    PFLASH_INTERRUPTS    : ORIGIN = 0x00000000, LENGTH = 0x00000400 /* 1KB */    /* Do not change this section */
    PFLASH_MEM           : ORIGIN = 0x00000400, LENGTH = 0x000FFC00 /* ~1MB */ 
    SRAM                 : ORIGIN = 0x20000000, LENGTH = 0x0001F000 /* 124K */
    SRAM_STACK           : ORIGIN = 0x2001F000, LENGTH = 0x00001000 /* 4KB */
    SRAM_END             : ORIGIN = 0x20020000, LENGTH = 0          /* End of SRAM */
}

SECTIONS
{
    .intc_vector                                 ALIGN(4096)  : > PFLASH_INTERRUPTS
    .startup                                     ALIGN(4)     : > PFLASH_MEM
    .text.startup                                ALIGN(4)     : > .
    .text                                        ALIGN(4)     : > .
    .mcal_code                                   ALIGN(4)     : > .
    .fls_ac_code_rom                             ALIGN(4)     : > .

    .rodata                                     ALIGN(4)      : > .
    .mcal_config_data                           ALIGN(4)      : > .
    .mcal_const                                 ALIGN(4)      : > .
    .init_table                                 ALIGN(4)      : > .
    .zero_table                                 ALIGN(4)      : > .

    /* ROM sections for initialized data */
    .ROM.mcal_ramcode             ROM(.mcal_ramcode)            ALIGN(4)      : > .
    .ROM.data                     ROM(.data)                    ALIGN(4)      : > .
    .ROM.mcal_data                ROM(.mcal_data)               ALIGN(4)      : > .

    .intc_vector_ram     ALIGN(4096) PAD(SIZEOF(.intc_vector))  : > SRAM

    .mcal_ramcode                           ABS ALIGN(4)      : > .
    .data                                       ALIGN(4)      : > .
    .mcal_data                                  ALIGN(4)      : > .
    .bss                               (NOLOAD) ALIGN(16)     : > .
    .mcal_bss                          (NOLOAD) ALIGN(16)     : > .

    .fls_ac_code_ram     ALIGN(4) : {. += SIZEOF(.fls_ac_code_rom);} > .

    .stack               ALIGN(4) : {. += SIZEOF(SRAM_STACK);} > SRAM_STACK

    __STACK_END         = ADDR(SRAM_STACK);
    __STACK_TOP         = ADDR(SRAM_STACK) + SIZEOF(SRAM_STACK);

    __SRAM_START         = ADDR(SRAM);
    __SRAM_END           = ADDR(SRAM_END);
                                  
    __RAM_RAM_CODE_INIT_START     = ADDR(.mcal_ramcode);
    __RAM_RAM_CODE_INIT_END       = ADDR(.mcal_ramcode) + SIZEOF(.mcal_ramcode);
    __ROM_RAM_CODE_INIT_START     = ADDR(.ROM.mcal_ramcode);
    __ROM_RAM_CODE_INIT_END       = ADDR(.ROM.mcal_ramcode) + SIZEOF(.ROM.mcal_ramcode);

    __RAM_DATA_INIT_START         = ADDR(.data);
    __RAM_DATA_INIT_END           = ADDR(.data) + SIZEOF(.data);
    __ROM_DATA_INIT_START         = ADDR(.ROM.data);
    __ROM_DATA_INIT_END           = ADDR(.ROM.data) + SIZEOF(.ROM.data);

    __RAM_MCAL_DATA_INIT_START    = ADDR(.mcal_data);
    __RAM_MCAL_DATA_INIT_END      = ADDR(.mcal_data) + SIZEOF(.mcal_data);
    __ROM_MCAL_DATA_INIT_START    = ADDR(.ROM.mcal_data);
    __ROM_MCAL_DATA_INIT_END      = ADDR(.ROM.mcal_data) + SIZEOF(.ROM.mcal_data);

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss) + SIZEOF(.mcal_bss)) - ADDR(.bss);
    __BSS_SRAM_END                = ADDR(.mcal_bss) + SIZEOF(.mcal_bss);

    __RAM_INTERRUPT_START         = ADDR(.intc_vector_ram);
    __ROM_INTERRUPT_START         = ADDR(.intc_vector);
    __ROM_INTERRUPT_END           = ADDR(.intc_vector) + SIZEOF(.intc_vector);
                                  
    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __SRAM_INIT_FLAG                    = 1;

    /* Fls module access code support */    
    Fls_Drvw_AcEraseRomStart         = ADDR(.fls_ac_code_rom);
    Fls_Drvw_AcEraseRomEnd           = ADDR(.fls_ac_code_rom) + SIZEOF(.fls_ac_code_rom);
    Fls_Drvw_AcEraseSize             = SIZEOF(.fls_ac_code_rom);

    Fls_Drvw_AcWriteRomStart         = ADDR(.fls_ac_code_rom);
    Fls_Drvw_AcWriteRomEnd           = ADDR(.fls_ac_code_rom) + SIZEOF(.fls_ac_code_rom);
    Fls_Drvw_AcWriteSize             = SIZEOF(.fls_ac_code_rom);

    FLS_AC_ERASE_ADDR        = ADDR(.fls_ac_code_ram);
    FLS_AC_WRITE_ADDR        = ADDR(.fls_ac_code_ram);

}

OPTION ("-keep=Flash_Drv_AccessCode")
