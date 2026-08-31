/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file IntrCtrl_Lld_Cfg.h
 * @brief 
 * 
 */


#ifndef INTCTRL_LLD_CFG_H_
#define INTCTRL_LLD_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Lld_TypesDef.h"
#include "YTM32B1Mx_CM33_DSP_FP.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_LLD_CFG_VENDOR_ID                          (180)
#define PLATFORM_INTCTRL_LLD_CFG_SW_MAJOR_VERSION                   (2)
#define PLATFORM_INTCTRL_LLD_CFG_SW_MINOR_VERSION                   (3)
#define PLATFORM_INTCTRL_LLD_CFG_SW_PATCH_VERSION                   (0)
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Lld_TypesDef header file are of the same vendor */
#if (PLATFORM_INTCTRL_LLD_CFG_VENDOR_ID != PLATFORM_INTCTRL_LLD_TYPESDEF_TYPES_VENDOR_ID)
    #error "IntCtrl_Lld_Cfg.h and IntCtrl_Lld_TypesDef.h have different vendor ids"
#endif

/* Check if current file and Fls header file are of the same Software version */
#if ((PLATFORM_INTCTRL_LLD_CFG_SW_MAJOR_VERSION != PLATFORM_INTCTRL_LLD_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_CFG_SW_MINOR_VERSION != PLATFORM_INTCTRL_LLD_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_LLD_CFG_SW_PATCH_VERSION != PLATFORM_INTCTRL_LLD_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Lld_Cfg.h and IntCtrl_Lld_TypesDef.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* Definition of the configuration structure for Platform MLD */
extern const IntCtrl_Lld_CtrlConfigType IntCtrlConfig;


/* Declaration of interrupt handlers 
 * NOTE: For application specific handlers, these functions must be implemented in the application code!
 */


#endif /* INTCTRL_LLD_CFG_H_ */

