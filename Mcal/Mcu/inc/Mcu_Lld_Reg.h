/**
* @file    Mcu_Lld_Reg.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Mcu_Lld_Reg
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef MCU_LLD_REG_H
#define MCU_LLD_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "pSIP_Scu.h"
#include "pSIP_Rcu.h"
#include "pSIP_Ipc.h"
#include "pSIP_Pcu.h"
#include "pSIP_Efm.h"
#if defined (UNIT_TEST)
#include "fakeSCB.h"
#endif
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION                                
==================================================================================================*/
#define MCU_LLD_REG_VENDOR_ID                      (180)
#define MCU_LLD_REG_AR_RELEASE_MAJOR_VERSION       (4)
#define MCU_LLD_REG_AR_RELEASE_MINOR_VERSION       (4)
#define MCU_LLD_REG_AR_RELEASE_REVISION_VERSION    (0)
#define MCU_LLD_REG_SW_MAJOR_VERSION               (2)
#define MCU_LLD_REG_SW_MINOR_VERSION               (3)
#define MCU_LLD_REG_SW_PATCH_VERSION               (0)
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

#endif /* End of file Mcu_Lld_Reg.h */

