/***********************************************************************************************/
/**
 * @file      : Linker_Ram_Z20K146M.ld
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
* 0x20000000    0x2001FFFF  128K  SRAM
*/

MEMORY
{
    SRAM                : ORIGIN = 0x20000000, LENGTH = 0x0001F000 /* 124KB */
    SRAM_STACK          : ORIGIN = 0x2001F000, LENGTH = 0x00001000 /* 4KB  */
    SRAM_END            : ORIGIN = 0x20020000, LENGTH = 0          /* End of SRAM */
}

SECTIONS
{
    .intc_vector                                ALIGN(4096)  : > SRAM
    .startup                                    ALIGN(4)     : > . /* Reset code*/
    .text.startup                               ALIGN(4)     : > .
    .text                                       ALIGN(4)     : > .
    .mcal_code                                  ALIGN(4)     : > .
    .fls_ac_code_rom                            ALIGN(4)     : > .

    .rodata                                     ALIGN(4)     : > .
    .mcal_config_data                           ALIGN(4)     : > .
    .mcal_const                                 ALIGN(4)     : > .
    .init_table                                 ALIGN(4)     : > .
    .zero_table                                 ALIGN(4)     : > .

    .mcal_ramcode                           ABS ALIGN(4)     : > .
    .data                                       ALIGN(4)     : > .
    .mcal_data                                  ALIGN(4)     : > .
    .bss                               (NOLOAD) ALIGN(16)    : > .
    .mcal_bss                          (NOLOAD) ALIGN(16)    : > .

    .stack               ALIGN(4) : {. += SIZEOF(SRAM_STACK);} > SRAM_STACK

    __STACK_END           = ADDR(SRAM_STACK);
    __STACK_TOP           = ADDR(SRAM_STACK) + SIZEOF(SRAM_STACK);

    __SRAM_START      = ADDR(SRAM);
    __SRAM_END        = ADDR(SRAM_END);

    __RAM_RAM_CODE_INIT_START     = 0;
    __RAM_RAM_CODE_INIT_END       = 0;
    __ROM_RAM_CODE_INIT_START     = 0;
    __ROM_RAM_CODE_INIT_END       = 0;

    __RAM_DATA_INIT_START         = 0;
    __RAM_DATA_INIT_END           = 0;
    __ROM_DATA_INIT_START         = 0;
    __ROM_DATA_INIT_END           = 0;

    __RAM_MCAL_DATA_INIT_START    = 0;
    __RAM_MCAL_DATA_INIT_END      = 0;
    __ROM_MCAL_DATA_INIT_START    = 0;
    __ROM_MCAL_DATA_INIT_END      = 0;

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss) + SIZEOF(.mcal_bss)) - ADDR(.bss);
    __BSS_SRAM_END                = ADDR(.mcal_bss) + SIZEOF(.mcal_bss);

    __RAM_INTERRUPT_START         = ADDR(.intc_vector);
    __ROM_INTERRUPT_START         = 0;
    __ROM_INTERRUPT_END           = 0;

    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __SRAM_INIT_FLAG              = 0;

}

OPTION ("-keep=Flash_Drv_AccessCode")
