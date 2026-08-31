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

#ifndef System_LLD_H_
#define System_LLD_H_

/**
*   @file
*
*   @defgroup   System_Lld System LLD
*   @ingroup    Platform
*
*   @addtogroup System_Lld
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "System_Lld_Cfg.h"
#include "Devassert.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_SYSTEM_LLD_VENDOR_ID                         (180)
#define PLATFORM_SYSTEM_LLD_AR_RELEASE_MAJOR_VERSION          (4)
#define PLATFORM_SYSTEM_LLD_AR_RELEASE_MINOR_VERSION          (4)
#define PLATFORM_SYSTEM_LLD_AR_RELEASE_REVISION_VERSION       (0)
#define PLATFORM_SYSTEM_LLD_SW_MAJOR_VERSION                  (2)
#define PLATFORM_SYSTEM_LLD_SW_MINOR_VERSION                  (3)
#define PLATFORM_SYSTEM_LLD_SW_PATCH_VERSION                  (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Lld_Cfg header file are of the same vendor */
#if (PLATFORM_SYSTEM_LLD_VENDOR_ID != PLATFORM_SYSTEM_LLD_CFG_TYPES_VENDOR_ID)
#error "System_Lld.h and System_Lld_Cfg.h have different vendor ids"
#endif

/* Check if current file and System_Lld_Cfg header file are of the same Software version */
#if ((PLATFORM_SYSTEM_LLD_SW_MAJOR_VERSION != PLATFORM_SYSTEM_LLD_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_SW_MINOR_VERSION != PLATFORM_SYSTEM_LLD_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_SW_PATCH_VERSION != PLATFORM_SYSTEM_LLD_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of System_Lld.h and System_Lld_Cfg.h are different"
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if ((SYSTEM_LLD_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
/**
 * @brief         Enables/disables core-related interrupt exceptions.
 *
 * @details       This function is non-reentrant and configures core-related interrupt
 *                exceptions, as defined per each platform.
 *
 * @param[in]     Irq: core-related interrupt event.
 * @param[in]     Enable: FALSE - disable interrupt, TRUE - enable interrupt.
 * @return        void
 * @implements    System_Lld_ConfigIrq_Activity
 *
 * */
void System_Lld_ConfigIrq(System_Lld_IrqType Irq, boolean Enable);
#endif

#endif /* System_LLD_H_ */

/** @} */

