/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file IntrCtrl_Lld_CfgDefines.h
 * @brief 
 * 
 */


#ifndef INTCTRL_LLD_CFG_DEFINES_H_
#define INTCTRL_LLD_CFG_DEFINES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_LLD_CFG_DEFINES_VENDOR_ID                          (180)
#define PLATFORM_INTCTRL_LLD_CFG_DEFINES_SW_MAJOR_VERSION                   (2)
#define PLATFORM_INTCTRL_LLD_CFG_DEFINES_SW_MINOR_VERSION                   (3)
#define PLATFORM_INTCTRL_LLD_CFG_DEFINES_SW_PATCH_VERSION                   (0)

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Development error detection */
#define INT_CTRL_LLD_DEV_ERROR_DETECT            (STD_ON)


/* MSI target core count */
#define INTCTRL_LLD_MSI_CORE_CNT                   (0U)

/* MSI vector min */
#define INTCTRL_LLD_DIRECTED_CPU_INT_MIN           (0)

/* MSI vector max */
#define INTCTRL_LLD_DIRECTED_CPU_INT_MAX           (0)

/* VTOR address configuration enable */
#define INTCTRL_LLD_ENABLE_VTOR_CONFIG             (STD_ON)

/* Core count */
#define INTCTRL_LLD_CORE_MASK                      (1U)

/* System interrupt routing through MSCM */
#define INT_CTRL_LLD_MSCM_SYSTEM_INTERRUPT_ROUTER  (STD_OFF)

/* INCT CTRL LLD standalone APIs */
#define INT_CTRL_LLD_STANDALONE_APIS               (STD_OFF)

/* First implemented interrupt vector */
#define INT_CTRL_LLD_IRQ_MIN                       (DMA0_IRQn)

/* Last implemented interrupt vector */
#define INT_CTRL_LLD_IRQ_MAX                       (WKU_IRQn)

/* The interrupt counter value*/
#define INT_CTRL_LLD_IRQ_COUNT                     (100U)
/* Arm Cortex M33 */
#define INT_CTRL_LLD_CORTEXM      STD_ON
#define INT_CTRL_LLD_CORTEXR      STD_OFF
#define INT_CTRL_LLD_CORTEXA      STD_OFF   

 
/* Number of priority bits implemented */
#define INT_CTRL_LLD_NVIC_PRIO_BITS                (3U)

/*Interrupt Router Shared Peripheral Routing Control Register*/
#define INT_CTRL_LLD_ROUTING_CONTROL_REGISTER      (STD_OFF)

/* This instruction invalidates the entire instruction cache or caches */
#define INT_CTRL_LLD_INVALIDATE_CACHE              (STD_OFF)


/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Int Ctrl PLATFORM driver code can be executed from both supervisor and user mode.
*/
#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

#endif /* INTCTRL_LLD_CFG_DEFINES_H_ */

