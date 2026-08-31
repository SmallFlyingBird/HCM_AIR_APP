/*
* @file    SchM_Dio.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Dio
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef SCHM_DIO_H
#define SCHM_DIO_H

/**
*   @file    SchM_Dio.h
*
*   @addtogroup SCHM_DIO_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Dio_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_DIO_VENDOR_ID                      (180)
#define SCHM_DIO_AR_RELEASE_MAJOR_VERSION       (4)
#define SCHM_DIO_AR_RELEASE_MINOR_VERSION       (4)
#define SCHM_DIO_AR_RELEASE_REVISION_VERSION    (0)
#define SCHM_DIO_SW_MAJOR_VERSION               (2)
#define SCHM_DIO_SW_MINOR_VERSION               (3)
#define SCHM_DIO_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and DIO_CFG header file are of the same vendor */
#if (SCHM_DIO_VENDOR_ID != DIO_VENDOR_ID_CFG)
#error "SchM_Dio.h and Dio_Cfg.h have different vendor ids"
#endif

/* Check if header file and DIO_CFG header file are of the same Autosar version */
#if (( SCHM_DIO_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_DIO_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_DIO_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Dio.h and Dio_Cfg.h are different"
#endif

/* Check if header file and DIO_CFG header file are of the same Software version */
#if (( SCHM_DIO_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_DIO_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION_CFG) || \
      ( SCHM_DIO_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Dio.h and Dio_Cfg.h are different"
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

#if(STD_ON == DIO_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

extern void SchM_Enter_Dio_DIO_EXCLUSIVE_AREA(void);
extern void SchM_Exit_Dio_DIO_EXCLUSIVE_AREA(void);

#define SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00() SchM_Enter_Dio_DIO_EXCLUSIVE_AREA()
#define SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00() SchM_Exit_Dio_DIO_EXCLUSIVE_AREA()

#else

extern void SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00()
#define SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00()


#endif /* STD_ON == DIO_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* End of file SchM_Dio.h */

