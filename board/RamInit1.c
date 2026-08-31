/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file RamInit1.c
 * @brief 
 * 
 */


#include "Platform_Types.h"
#include "pSIP_Rcu.h"

#define WORD_ALIGN_MASK (3U)
#define WORD_SHIFT      (2U)

typedef enum
{
    INIT_NULL = 0U,   /*!< No initialization */
    INIT_NORMAL = 1U, /*!< Normal initialization */
    INIT_POR = 2U,    /*!< Power on reset initialization */
} RamInitType;

typedef struct
{
    uint32 *RamStart;   /*!< Start address of section in RAM */
    uint32 *RomStart;   /*!< Start address of section in ROM */
    uint32 *RomEnd;     /*!< End address of section in ROM */
    RamInitType InitType;   /*!< Type of initialization,*/
} RamCopyLayoutType;

typedef struct
{
    uint32 *RamStart;   /*!< Start address of section in RAM */
    uint32 *RamEnd;     /*!< End address of section in RAM */
    RamInitType InitType;   /*!< Type of initialization*/
} RamZeroLayoutType;

extern uint32 CODE_RAM_ram_start[1U];
extern uint32 CODE_RAM_rom_start[1U];
extern uint32 CODE_RAM_rom_end[1U];
extern uint32 DATA_RAM_ram_start[1U];
extern uint32 DATA_RAM_rom_start[1U];
extern uint32 DATA_RAM_rom_end[1U];

extern uint32 BSS_start[1U];
extern uint32 BSS_end[1U];

const RamCopyLayoutType CopyLayout[2]={
    {
        .RamStart=CODE_RAM_ram_start,
        .RomStart=CODE_RAM_rom_start,
        .RomEnd=CODE_RAM_rom_end,
        .InitType=INIT_NORMAL,
    },
    {
        .RamStart=DATA_RAM_ram_start,
        .RomStart=DATA_RAM_rom_start,
        .RomEnd=DATA_RAM_rom_end,
        .InitType=INIT_NORMAL,
    },
};

const RamZeroLayoutType ZeroLayout[1]={
    {
        .RamStart=BSS_start,
        .RamEnd=BSS_end,
        .InitType=INIT_NORMAL,
    },
};

/**
 * @brief Check MCU is power on reset or not, user can override this function
 * @return 1: POR, 0: Not POR
 */
#define RCU_RSSR_POR_MASK   (0x1U)
static boolean IsPOR(void)
{
    boolean RetVal = FALSE;
    /* Check if the MCU is power on reset or not */
    if (RCU_RSSR_POR_MASK == (RCU->RSSR & RCU_RSSR_POR_MASK))
    {
        RetVal = TRUE;
    }
    return RetVal;
}



/**
 * @brief RamInit1 for copying initialized data and zeroing uninitialized data
 */
void RamInit1(){
    boolean IsPor = IsPOR();
    const uint32 *Rom32;
    const uint8 *Rom8;
    uint32 *Ram32;
    uint8 *Ram8;
    volatile uint8 DataPad;
    volatile uint32 Len = 0U;
    uint32 Size = 0U;
    uint32 MajorLoopCnt = 0U;
    uint32 MinorLoopCnt = 0U;

    /* Copy initialized table */
    Len = 2;
    for (MajorLoopCnt = 0U; MajorLoopCnt < Len; ++MajorLoopCnt)
    {
         if(((CopyLayout[MajorLoopCnt].InitType == INIT_POR) && (IsPor != TRUE)) || (CopyLayout[MajorLoopCnt].InitType == INIT_NULL))
        {
            continue;
        }
        Rom32 = (const uint32 *)CopyLayout[MajorLoopCnt].RomStart;
        Ram32 = (uint32 *)CopyLayout[MajorLoopCnt].RamStart;
        Size = (uint32)CopyLayout[MajorLoopCnt].RomEnd - (uint32)CopyLayout[MajorLoopCnt].RomStart;
        /* Make sure the data area to be copied must be aligned with 4. Then, copy 4 bytes at per one read */
        DataPad = Size & WORD_ALIGN_MASK;
        Size = (Size - DataPad) >> WORD_SHIFT;
        for (MinorLoopCnt = 0U; MinorLoopCnt < Size; ++MinorLoopCnt)
        {
            Ram32[MinorLoopCnt] = Rom32[MinorLoopCnt];
        }
        /* For the rest of data, copy 1 bytes at per one read */
        Rom8 = (uint8 *) & (Rom32[MinorLoopCnt]);
        Ram8 = (uint8 *) & (Ram32[MinorLoopCnt]);
        for (MinorLoopCnt = 0U; MinorLoopCnt < DataPad; ++MinorLoopCnt)
        {
            Ram8[MinorLoopCnt] = Rom8[MinorLoopCnt];
        }
    }

    /* Clear zero table */
    Len = 1;
    for (MajorLoopCnt = 0U; MajorLoopCnt < Len; ++MajorLoopCnt)
    {
        if(((ZeroLayout[MajorLoopCnt].InitType == INIT_POR) && (IsPor != TRUE)) || (ZeroLayout[MajorLoopCnt].InitType == INIT_NULL))
        {
            continue;
        }
        Ram32 = (uint32 *)ZeroLayout[MajorLoopCnt].RamStart;
        Size = (uint32)ZeroLayout[MajorLoopCnt].RamEnd - (uint32)ZeroLayout[MajorLoopCnt].RamStart;
        /* Make sure the data area to be zeroed must be aligned with 4. Then, zero 4 bytes at per one read */
        DataPad = Size & WORD_ALIGN_MASK;
        Size = (Size - DataPad) >> WORD_SHIFT;        
        for (MinorLoopCnt = 0U; MinorLoopCnt < Size; ++MinorLoopCnt)
        {
            Ram32[MinorLoopCnt] = 0U;
        }
        /* For the rest of data, zero 1 bytes at per one read */
        Ram8 = (uint8 *) & (Ram32[MinorLoopCnt]);
        for (MinorLoopCnt = 0U; MinorLoopCnt < DataPad; ++MinorLoopCnt)
        {
            Ram8[MinorLoopCnt] = 0U;
        }
    }
}


