/*
* @file    Icu_Lld_Reg.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Lld_Reg
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
#ifndef ICU_LLD_REG_H
#define ICU_LLD_REG_H

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "Icu_Cfg.h"

#include "pSIP_Pctrl.h"
#include "pSIP_Etmr.h"
#include "pSIP_Gpio.h"
#include "pSIP_Acmp.h"
#include "pSIP_Cim.h"
#if(WKU_SUPPORT == STD_ON)
#include "pSIP_Wku.h"
#endif
#if defined(CPU_YTM32B1ME0)
#include "YTM32B1ME0_features.h"
#elif defined(CPU_YTM32B1MD1)
#include "YTM32B1MD1_features.h"
#elif defined(CPU_YTM32B1HA0)
#include "YTM32B1HA0_features.h"
#include "pSIP_Mpwm.h"
#elif defined(CPU_YTM32B1MC0)
#include "YTM32B1MC0_features.h"
#endif

/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION                                
==================================================================================================*/
#define ICU_LLD_REG_VENDOR_ID                      (180)
#define ICU_LLD_REG_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_LLD_REG_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_LLD_REG_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_LLD_REG_SW_MAJOR_VERSION               (2)
#define ICU_LLD_REG_SW_MINOR_VERSION               (3)
#define ICU_LLD_REG_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS                                       
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS                                        
==================================================================================================*/
/*==================================================================================================
                                                ENUMS                                        
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES                                           
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* End of file Icu_Lld_Reg.h */

