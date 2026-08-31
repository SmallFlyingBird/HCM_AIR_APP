/**
*   @file    YTM32B1Hx_CM7_DSP_FP.h
*   @version V2.3.0
*
*   @brief   YTM32B1Hx CM7 core implementation configuration
*
*   @addtogroup YTM32B1HX_CM33_DSP_FP
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

/* PRQA S 0602,0603 EOF */

#ifndef YTM32B1HX_CM7_DSP_FP_H
#define YTM32B1HX_CM7_DSP_FP_H

/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM7_REV               0x0102U /* Core revision r1p2 */
#define __SAUREGION_PRESENT     0U      /* SAU regions present */
#define __MPU_PRESENT           1U      /* MPU present */
#define __VTOR_PRESENT          1U      /* VTOR present */
#define __NVIC_PRIO_BITS        4U      /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig  0U      /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT           1U      /* FPU present */
#define __DSP_PRESENT           1U      /* DSP extension present */
#define __ICACHE_PRESENT        1U      /* ICACHE extension present */
#define __DCACHE_PRESENT        1U      /* ICACHE extension present */
#define __DTCM_PRESENT          1U      /* DTCM extension present */
#if defined(MCAL_ENABLE_QUA_FAULT_INJECTION)
#define MCAL_QUA_FAULT_INJECTION(x) \
    do {\
        x;\
    } while (0)
#else
#define MCAL_QUA_FAULT_INJECTION(x)
#endif

#include "IntCtrl_Lld_TypesDef.h"
#include "core_cm7.h"


#endif /* YTM32B1HX_CM7_DSP_FP_H */

