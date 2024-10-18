/***********************************************************************************************/
/**
 * @file      : Linker_Flash_Z20K148M.ld
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
* 0x00000000    0x001FFFFF  2M    Program Flash
* 0x01000000    0x0101FFFF  128K  Data Flash
* 0x1FFE0000    0x2001FFFF  256K  SRAM
*/
DEFAULTS 
{
    boot_offsize = 0x00022000 /*0x0 or 0x00022000*/
}
MEMORY
{   
    PFLASH_INTERRUPTS    : ORIGIN = 0x00000000 + boot_offsize, LENGTH  = 0x00000400 /* 1KB */    /* Do not change this section */
    PFLASH_MEM           : ORIGIN = 0x00000400 + boot_offsize, LENGTH  = 0x001E0000 - boot_offsize - 0x400 /* ~1999k */ 
    BOOTS_SHARE_DID      : ORIGIN = 0x001E0000, LENGTH = 0x00002000 /* ~8k */
    PFLASH_CALDATA_CRC   : ORIGIN = 0x001E2000, LENGTH = 0x00000004 /* 4bytes */
    PFLASH_CALDATA_SIZE  : ORIGIN = 0x001E2004, LENGTH = 0x00000004 /* 4bytes */
    PFLASH_CALDATA       : ORIGIN = 0x001E2008, LENGTH = 0x00002000 - 0x8 /* ~8k-8bytes */
    PARATABLE_VBT        : ORIGIN = 0x001E4000, LENGTH = 0x100  /*0x100*/ 
    PARATABLE_CRC        : ORIGIN = 0x001E4100, LENGTH = 0x8  /*0x8*/
    PARATABLE_MEM        : ORIGIN = 0x001E4108, LENGTH = 0x0000E000-0x00000100-0x08  /*~56k-0x100-0x08*/ 
    PFLASH_STL           : ORIGIN = 0x001F2000, LENGTH = 0x0000E000  /*~56k*/ 

    SRAM1                : ORIGIN = 0x1FFE0000, LENGTH = 0x00020000
    SRAM_STL_DATA        : ORIGIN = 0x20000000, LENGTH = 0x00000040
    SRAM2                : ORIGIN = 0x20000040, LENGTH = 0x0001BFC0
    SRAM_STL_STK         : ORIGIN = 0x2001C000, LENGTH = 0x00001000         /* 4KB Independent stack for core tst*/

    SRAM_CALDATA_CRC     : ORIGIN = 0x2001D000, LENGTH = 0x00000004         /* 4bytes */
    SRAM_CALDATA_SIZE    : ORIGIN = 0x2001D004, LENGTH = 0x00000004         /* 4bytes */
    SRAM_CALDATA         : ORIGIN = 0x2001D008, LENGTH = 0x00002000 - 0x8   /* ~8KB */ 

    SRAM_STACK           : ORIGIN = 0x2001F000, LENGTH = 0x00001000         /* 4KB  */
    SRAM_END             : ORIGIN = 0x20020000, LENGTH = 0                  /* End of SRAM */
}

SECTIONS
{
    .dataparatable                               ALIGN(4)     : > PARATABLE_MEM 
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
    .test_vectors                               ALIGN(4096)   : > .
    /* ROM sections for initialized data */
    .ROM.mcal_ramcode             ROM(.mcal_ramcode)            ALIGN(4)      : > .
    .ROM.data                     ROM(.data)                    ALIGN(4)      : > .
    .ROM.mcal_data                ROM(.mcal_data)               ALIGN(4)      : > .

    .ROM.CalData 		                    		            ALIGN(4)      : > PFLASH_CALDATA

    .intc_vector_ram   ALIGN(4096) PAD(SIZEOF(.intc_vector))  : > SRAM1
    .os_intc_vector                              ALIGN(4096)  : > SRAM1
    .tst0                                       ALIGN(4)      : > .
    .mcal_data                                  ALIGN(4)      : > .
    .bss                               (NOLOAD) ALIGN(16)     : > .
    .tst1                                       ALIGN(4)      : > .
    .mcal_bss                          (NOLOAD) ALIGN(16)     : > .
    .tst2                                       ALIGN(4)      : > .  

    .stl_data                                   ALIGN(4)      : > SRAM_STL_DATA 

    .tst3                                       ALIGN(4)      : > SRAM2

    .mcal_ramcode                           ABS ALIGN(4)      : > .
    .data                                       ALIGN(4)      : > .
    .fls_ac_code_ram                            ALIGN(4)      : {. += SIZEOF(.fls_ac_code_rom);} > .
                                                                        
    .stl_stack                                  ALIGN(8)        : {. += SIZEOF(SRAM_STL_STK);} > SRAM_STL_STK

    /* XCP section */
    .CalData_Crc                         		    ALIGN(4)        : > SRAM_CALDATA_CRC
    .CalData_Size                         		    ALIGN(4)        : > SRAM_CALDATA_SIZE
    .CalData                         		    ALIGN(4)        : > SRAM_CALDATA

    .stack                                      ALIGN(4)        : {. += SIZEOF(SRAM_STACK);} > SRAM_STACK

    __STACK_END         = ADDR(SRAM_STACK);
    __STACK_TOP         = ADDR(SRAM_STACK) + SIZEOF(SRAM_STACK);

    __SRAM_START         = ADDR(SRAM1);
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
                                  
    __OS_INTERRUPT_START          = ADDR(.os_intc_vector);
    __OS_INTERRUPT_END            = ADDR(.os_intc_vector) + SIZEOF(.os_intc_vector);

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

    /* XCP section */
    __RAM_CAL_START 		  = ADDR(.CalData);
    __ROM_CAL_START 	  	  = ADDR(.ROM.CalData);
    __ROM_CAL_END   		  = ADDR(.ROM.CalData) + SIZEOF(.ROM.CalData);   

    /* STL */
    test_vectors_base         = ADDR(.test_vectors);
   __process_stack_end__      = ADDR(.stl_stack);
   __stack_end__              = ADDR(.stack);
}

OPTION ("-keep=Flash_Drv_AccessCode")
