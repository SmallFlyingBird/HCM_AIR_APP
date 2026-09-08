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
    BOOT : ORIGIN = 0x0, LENGTH = 0x38000
    ParmemtTable : ORIGIN = 0x78000, LENGTH = 0x7000
    SHARE_DID_INFO : ORIGIN = 0x7f000, LENGTH = 0x400
    FL_BLOCK_INTEGERITY : ORIGIN = 0x7f400, LENGTH = 1024
    FL_PUBLICKY : ORIGIN = 0x7f800, LENGTH = 1024
    FL_SECURIT : ORIGIN = 0x7fc00, LENGTH = 1024
    IVT : ORIGIN = 0x38000, LENGTH = 0x400
    TEXT : ORIGIN = 0x38400, LENGTH = 0x23000
    IVT_RAM : ORIGIN = 0x1fff8000, LENGTH = 0x400
    STACK : ORIGIN = 0x20007c00, LENGTH = 0x400
    RAM : ORIGIN = 0x1fff8400, LENGTH = 0xF800
}
/* SECTIONS */
SECTIONS
{
    PAR ALIGN(4) : 
    {
        
        . = ALIGN(4);
        PAR_start = .;
        Parament_region_start = .;
        *(.Parament)
        Parament_region_end = .;
        
        PAR_end = .;
    } > ParmemtTable
   
    SHARE ALIGN(4) : 
    {
        
        . = ALIGN(4);
        SHARE_start = .;
        DID_region_start = .;
        *(.DID)
        DID_region_end = .;
        
        SHARE_end = .;
    } > SHARE_DID_INFO
   
    INFO ALIGN(4) : 
    {
        
        . = ALIGN(4);
        INFO_start = .;
        FL_BLOCK_region_start = .;
        *(.FL_BLOCK)
        FL_BLOCK_region_end = .;
        
        INFO_end = .;
    } > FL_BLOCK_INTEGERITY
   
    FL_PUBLICKY ALIGN(4) : 
    {
        
        . = ALIGN(4);
        FL_PUBLICKY_start = .;
        PUBLICKY_region_start = .;
        *(.PUBLICKY)
        PUBLICKY_region_end = .;
        
        FL_PUBLICKY_end = .;
    } > FL_PUBLICKY
   
    SECURITY ALIGN(4) : 
    {
        
        . = ALIGN(4);
        SECURITY_start = .;
        SECURITY_region_start = .;
        *(.SECURITY)
        SECURITY_region_end = .;
        
        SECURITY_end = .;
    } > FL_SECURIT
   
    IVT  : 
    {
        
        IVT_start = .;
        isr_vector_region_start = .;
        *(.isr_vector)
        isr_vector_region_end = .;
        
        IVT_end = .;
    } > IVT
   
    TEXT  : 
    {
        
        TEXT_start = .;
        rodata_region_start = .;
        *(.rodata)
        "*(.rodata*)"
        rodata_region_end = .;
        
        text_region_start = .;
        *(.text)
        "*(.text*)"
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
   
    ARM  : 
    {
        
        ARM_start = .;
        ARM_region_start = .;
        *(.ARM)
        "*(.ARM*)"
        ARM_region_end = .;
        
        ARM_end = .;
    } > TEXT
   
    CODE_RAM_rom ALIGN(4) ROM_NOCOPY(CODE_RAM) :> TEXT
    CODE_RAM_rom_start = ADDR(CODE_RAM_rom);
    CODE_RAM_rom_end = ENDADDR(CODE_RAM_rom);
   
    DATA_RAM_rom ALIGN(4) ROM_NOCOPY(DATA_RAM) :> TEXT
    DATA_RAM_rom_start = ADDR(DATA_RAM_rom);
    DATA_RAM_rom_end = ENDADDR(DATA_RAM_rom);
   
    IVT_RAM ALIGN(1024) : 
    {
        
        . = ALIGN(1024);
        IVT_RAM_start = .;
        . += 0X400;
        IVT_RAM_end = .;
    } > IVT_RAM
   
    STACK  : 
    {
        
        STACK_start = .;
        . += 1024;
        STACK_end = .;
    } > STACK
   
    BSS  (NOLOAD): 
    {
        
        BSS_start = .;
        bss_region_start = .;
        *(.bss)
        "*(.bss*)"
        bss_region_end = .;
        
        mcal_bss_region_start = .;
        *(.mcal_bss)
        mcal_bss_region_end = .;
        
        mcal_bss_no_cacheable_region_start = .;
        *(.mcal_bss_no_cacheable)
        mcal_bss_no_cacheable_region_end = .;
        
        BSS_end = .;
    } > RAM
   
    CODE_RAM ALIGN(4) : 
    {
        
        . = ALIGN(4);
        CODE_RAM_ram_start = .;
        CODE_RAM_start = .;
        ramcode_region_start = .;
        *(.ramcode)
        ramcode_region_end = .;
        
        CODE_RAM_end = .;
        CODE_RAM_ram_end = .;
    } > RAM
   
    DATA_RAM ALIGN(4) : 
    {
        
        . = ALIGN(4);
        DATA_RAM_ram_start = .;
        DATA_RAM_start = .;
        data_region_start = .;
        *(.data)
        "*(.data*)"
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
   
    BOOT_memory_start = ADDR(BOOT);
    BOOT_memory_end = ADDR(BOOT) + SIZEOF(BOOT);
    BOOT_memory_size = SIZEOF(BOOT);
    ParmemtTable_memory_start = ADDR(ParmemtTable);
    ParmemtTable_memory_end = ADDR(ParmemtTable) + SIZEOF(ParmemtTable);
    ParmemtTable_memory_size = SIZEOF(ParmemtTable);
    SHARE_DID_INFO_memory_start = ADDR(SHARE_DID_INFO);
    SHARE_DID_INFO_memory_end = ADDR(SHARE_DID_INFO) + SIZEOF(SHARE_DID_INFO);
    SHARE_DID_INFO_memory_size = SIZEOF(SHARE_DID_INFO);
    FL_BLOCK_INTEGERITY_memory_start = ADDR(FL_BLOCK_INTEGERITY);
    FL_BLOCK_INTEGERITY_memory_end = ADDR(FL_BLOCK_INTEGERITY) + SIZEOF(FL_BLOCK_INTEGERITY);
    FL_BLOCK_INTEGERITY_memory_size = SIZEOF(FL_BLOCK_INTEGERITY);
    FL_PUBLICKY_memory_start = ADDR(FL_PUBLICKY);
    FL_PUBLICKY_memory_end = ADDR(FL_PUBLICKY) + SIZEOF(FL_PUBLICKY);
    FL_PUBLICKY_memory_size = SIZEOF(FL_PUBLICKY);
    FL_SECURIT_memory_start = ADDR(FL_SECURIT);
    FL_SECURIT_memory_end = ADDR(FL_SECURIT) + SIZEOF(FL_SECURIT);
    FL_SECURIT_memory_size = SIZEOF(FL_SECURIT);
    IVT_memory_start = ADDR(IVT);
    IVT_memory_end = ADDR(IVT) + SIZEOF(IVT);
    IVT_memory_size = SIZEOF(IVT);
    TEXT_memory_start = ADDR(TEXT);
    TEXT_memory_end = ADDR(TEXT) + SIZEOF(TEXT);
    TEXT_memory_size = SIZEOF(TEXT);
    IVT_RAM_memory_start = ADDR(IVT_RAM);
    IVT_RAM_memory_end = ADDR(IVT_RAM) + SIZEOF(IVT_RAM);
    IVT_RAM_memory_size = SIZEOF(IVT_RAM);
    STACK_memory_start = ADDR(STACK);
    STACK_memory_end = ADDR(STACK) + SIZEOF(STACK);
    STACK_memory_size = SIZEOF(STACK);
    RAM_memory_start = ADDR(RAM);
    RAM_memory_end = ADDR(RAM) + SIZEOF(RAM);
    RAM_memory_size = SIZEOF(RAM);
}