/*
* @file    Icu_Etmr_Irq.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Irq
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef ICU_ETMR_IRQ_H
#define ICU_ETMR_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "Icu_Lld_Reg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION                                
==================================================================================================*/
#define ICU_ETMR_IRQ_VENDOR_ID                      (180)
#define ICU_ETMR_IRQ_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_ETMR_IRQ_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_ETMR_IRQ_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_EMR_IRQ_SW_MAJOR_VERSION                (2)
#define ICU_ETMR_IRQ_SW_MINOR_VERSION               (3)
#define ICU_ETMR_IRQ_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS                                       
==================================================================================================*/
#define ICU_ETMR_ISR(IsrName) void IsrName(void)    /*!< Macro for ISR declaration */
/*==================================================================================================
                                                EXTERNAL CONSTANTS                                        
==================================================================================================*/
extern volatile eTMR_Type * const Icu_Etmr_Common_gBaseAddress32[eTMR_INSTANCE_COUNT];
/*==================================================================================================
                                                ENUMS                                        
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES                                           
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* End of file Icu_Etmr_Irq.h */

