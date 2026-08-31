/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file yt_linker.ld
 * @brief 
 * 
 */











/* MEMORY MAP */
MEMORY
{
    IVT   (RX) : ORIGIN = 0x0, LENGTH = 0x400
    TEXT   (RX) : ORIGIN = 0x400, LENGTH = 0x7fc00
    IVT_RAM   (RW) : ORIGIN = 0x1fff8000, LENGTH = 0x400
    STACK   (RW) : ORIGIN = 0x20007c00, LENGTH = 0x400
    RAM   (RW) : ORIGIN = 0x1fff8400, LENGTH = 0xf800
}
/* SECTIONS */
SECTIONS
{
    .IVT  : {
        
        IVT_start = .;
        isr_vector_region_start = .;
        KEEP(*(.isr_vector))
        isr_vector_region_end = .;
        
        IVT_end = .;
    } > IVT
   
    


    .TEXT  : {
        
        TEXT_start = .;
        rodata_region_start = .;
        *(.rodata)
        *(.rodata*)
        rodata_region_end = .;
        
        text_region_start = .;
        *(.text)
        *(.text*)
        text_region_end = .;
        
        mcal_text_region_start = .;
        *(.mcal_text)
        mcal_text_region_end = .;
        
        mcal_const_region_start = .;
        *(.mcal_const)
        mcal_const_region_end = .;
        
        mcal_const_cfg_region_start = .;
        *(.mcal_const_cfg)
        mcal_const_cfg_region_end = .;
        
        mcal_const_no_cacheable_region_start = .;
        *(.mcal_const_no_cacheable)
        mcal_const_no_cacheable_region_end = .;
        
        TEXT_end = .;
    } > TEXT
   
    


    .ARM  : {
        
        ARM_start = .;
        ARM_region_start = .;
        *(.ARM)
        *(.ARM*)
        ARM_region_end = .;
        
        ARM_end = .;
    } > TEXT
   
    


    CODE_RAM_rom_start_not_align = .;
    CODE_RAM_rom_start = CODE_RAM_rom_start_not_align + (4 - CODE_RAM_rom_start_not_align % 4);
   
    CODE_RAM_rom_end = CODE_RAM_rom_start + CODE_RAM_ram_end - CODE_RAM_ram_start;
    


    DATA_RAM_rom_start_not_align = CODE_RAM_rom_end;
    DATA_RAM_rom_start = DATA_RAM_rom_start_not_align + (4 - DATA_RAM_rom_start_not_align % 4);
   
    DATA_RAM_rom_end = DATA_RAM_rom_start + DATA_RAM_ram_end - DATA_RAM_ram_start;
    


    .IVT_RAM  : {
        
        . = ALIGN(1024);
        IVT_RAM_start = .;
        . += 0X400;
        IVT_RAM_end = .;
    } > IVT_RAM
   
    


    .STACK  : {
        
        STACK_start = .;
        . += 1024;
        STACK_end = .;
    } > STACK
   
    


    .BSS  (NOLOAD): {
        
        BSS_start = .;
        bss_region_start = .;
        *(.bss)
        *(.bss*)
        bss_region_end = .;
        
        mcal_bss_region_start = .;
        *(.mcal_bss)
        mcal_bss_region_end = .;
        
        mcal_bss_no_cacheable_region_start = .;
        *(.mcal_bss_no_cacheable)
        mcal_bss_no_cacheable_region_end = .;
        
        BSS_end = .;
    } > RAM
   
    


    .CODE_RAM  : AT(CODE_RAM_rom_start) {
        
        . = ALIGN(4);
        CODE_RAM_ram_start = .;
        CODE_RAM_start = .;
        ramcode_region_start = .;
        *(.ramcode)
        ramcode_region_end = .;
        
        CODE_RAM_end = .;
        CODE_RAM_ram_end = .;
    } > RAM
   
    
    ASSERT((CODE_RAM_ram_end - CODE_RAM_ram_start) == (CODE_RAM_rom_end - CODE_RAM_rom_start), "Copy Section CODE_RAM Size non-aligned")


    .DATA_RAM  : AT(DATA_RAM_rom_start) {
        
        . = ALIGN(4);
        DATA_RAM_ram_start = .;
        DATA_RAM_start = .;
        data_region_start = .;
        *(.data)
        *(.data*)
        data_region_end = .;
        
        mcal_data_region_start = .;
        *(.mcal_data)
        mcal_data_region_end = .;
        
        mcal_data_no_cacheable_region_start = .;
        *(.mcal_data_no_cacheable)
        mcal_data_no_cacheable_region_end = .;
        
        DATA_RAM_end = .;
        DATA_RAM_ram_end = .;
    } > RAM
   
    
    ASSERT((DATA_RAM_ram_end - DATA_RAM_ram_start) == (DATA_RAM_rom_end - DATA_RAM_rom_start), "Copy Section DATA_RAM Size non-aligned")


    IVT_memory_start = ORIGIN(IVT);
    IVT_memory_end = ORIGIN(IVT) + LENGTH(IVT);
    IVT_memory_size = LENGTH(IVT);
    TEXT_memory_start = ORIGIN(TEXT);
    TEXT_memory_end = ORIGIN(TEXT) + LENGTH(TEXT);
    TEXT_memory_size = LENGTH(TEXT);
    IVT_RAM_memory_start = ORIGIN(IVT_RAM);
    IVT_RAM_memory_end = ORIGIN(IVT_RAM) + LENGTH(IVT_RAM);
    IVT_RAM_memory_size = LENGTH(IVT_RAM);
    STACK_memory_start = ORIGIN(STACK);
    STACK_memory_end = ORIGIN(STACK) + LENGTH(STACK);
    STACK_memory_size = LENGTH(STACK);
    RAM_memory_start = ORIGIN(RAM);
    RAM_memory_end = ORIGIN(RAM) + LENGTH(RAM);
    RAM_memory_size = LENGTH(RAM);
}