/*
* @file    SchM_Adc.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Adc
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef SCHM_ADC_H
#define SCHM_ADC_H

/**
*   @file    SchM_Adc.h
*
*   @addtogroup SCHM_ADC_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0777,0779 EOF */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Adc_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_ADC_VENDOR_ID                      (180)
#define SCHM_ADC_AR_RELEASE_MAJOR_VERSION       (4)
#define SCHM_ADC_AR_RELEASE_MINOR_VERSION       (4)
#define SCHM_ADC_AR_RELEASE_REVISION_VERSION    (0)
#define SCHM_ADC_SW_MAJOR_VERSION               (2)
#define SCHM_ADC_SW_MINOR_VERSION               (3)
#define SCHM_ADC_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and ADC_CFG header file are of the same vendor */
#if (SCHM_ADC_VENDOR_ID != ADC_VENDOR_ID_CFG)
#error "SchM_Adc.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if header file and ADC_CFG header file are of the same Autosar version */
#if (( SCHM_ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Adc.h and Adc_Cfg.h are different"
#endif

/* Check if header file and ADC_CFG header file are of the same Software version */
#if (( SCHM_ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_CFG) || \
      ( SCHM_ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Adc.h and Adc_Cfg.h are different"
#endif
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/

/* Number of cores id */
#ifndef NUMBER_OF_CORES
#define NUMBER_OF_CORES         (uint8)(1U)
#endif /* NUMBER_OF_CORES */

/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/

#if(STD_ON == ADC_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA(void);

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06() SchM_Enter_Adc_ADC_EXCLUSIVE_AREA()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06() SchM_Exit_Adc_ADC_EXCLUSIVE_AREA()

#else

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05()

#define SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06()
#define SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06()

#endif /* (STD_ON == ADC_SCHM_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* End of file SchM_Adc.h */

