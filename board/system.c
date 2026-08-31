/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file system.c
 * @brief 
 * 
 */


#include "pSIP_Efm.h"
#include "pSIP_Wdg.h"
#include "YTM32B1Mx_CM33_DSP_FP.h"
#include "Mpu_Lld_Cfg.h"
#include "Mpu_Lld_M33.h"

void SystemInit(void)
{
    /* Enable CP10 and CP11 coprocessors */
    SCB->CPACR |= (3UL << 20 | 3UL << 22);    
    /* Enable the Flash arrary deep powerdown mode and Flash data prefetch. */
    EFM->CTRL |= EFM_CTRL_DPD_EN_MASK | EFM_CTRL_PREFETCH_EN_MASK;
    /* Disable the WDG. */
    WDG->SVCR = 0xB631;
    WDG->SVCR = 0xC278;
    WDG->CR &= ~WDG_CR_EN_MASK; 
    /* Enable the MPU */
    Mpu_Lld_M33_Init(&MpuConfig);
}

