
/**
*   @file    YTM32B1Mx_CM33_DSP_FP.h
*   @version V2.3.0
*
*   @brief   YTM32B1Mxx CM33 core implementation configuration
*
*   @addtogroup YTM32B1Mxx_CM33_DSP_FP
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

#ifndef YTM32B1MX_CM33_DSP_FP_H
#define YTM32B1MX_CM33_DSP_FP_H

/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM33_REV              0x0004U /* Core revision r0p4 */
#define __SAUREGION_PRESENT     0U      /* SAU regions present */
#define __MPU_PRESENT           1U      /* MPU present */
#define __VTOR_PRESENT          1U      /* VTOR present */
#define __NVIC_PRIO_BITS        3U      /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig  0U      /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT           1U      /* FPU present */
#define __DSP_PRESENT           1U      /* DSP extension present */
#if defined(MCAL_ENABLE_QUA_FAULT_INJECTION)
#define MCAL_QUA_FAULT_INJECTION(x) \
    do {\
        x;\
    } while (0)
#else
#define MCAL_QUA_FAULT_INJECTION(x)
#endif

#include "IntCtrl_Lld_TypesDef.h"
#include "core_cm33.h"


#endif /* YTM32B1MX_CM33_DSP_FP_H */

