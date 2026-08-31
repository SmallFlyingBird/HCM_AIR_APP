/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef INTCTRL_LLD_DEVICE_REGISTERS_H_
#define INTCTRL_LLD_DEVICE_REGISTERS_H_

/**
*   @file
*
*   @addtogroup IntCtrl_Lld
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#define PLATFORM_INTCTRL_LLD_DEVICE_REGISTERS_TYPES_VENDOR_ID                    (180)
#define PLATFORM_INTCTRL_LLD_DEVICE_REGISTERS_SW_MAJOR_VERSION                   (2)
#define PLATFORM_INTCTRL_LLD_DEVICE_REGISTERS_SW_MINOR_VERSION                   (3)
#define PLATFORM_INTCTRL_LLD_DEVICE_REGISTERS_SW_PATCH_VERSION                   (0)


#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
#include "core_CM33_nvic.h"
#include "core_CM33_scb.h"
#include "core_CM33_systick.h"
#include "pSIP_Cim.h"
#endif

#if defined(UNIT_TEST)
#include "inc/fakeCM33Nvic.h"
#include "inc/fakeCM33Scb.h"
#include "inc/fakeCM33Systick.h"
#include "inc/fakeCim.h"
#endif



#endif /* INTCTRL_LLD_DEVICE_REGISTERS_H_ */

/** @} */

