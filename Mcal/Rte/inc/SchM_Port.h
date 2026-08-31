/*
* @file    SchM_Port.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Port
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef SCHM_PORT_H
#define SCHM_PORT_H

/**
*   @file    SchM_Port.h
*
*   @addtogroup SCHM_PORT_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0777,0779 EOF */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Port_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_PORT_VENDOR_ID                      (180)
#define SCHM_PORT_AR_RELEASE_MAJOR_VERSION       (4)
#define SCHM_PORT_AR_RELEASE_MINOR_VERSION       (4)
#define SCHM_PORT_AR_RELEASE_REVISION_VERSION    (0)
#define SCHM_PORT_SW_MAJOR_VERSION               (2)
#define SCHM_PORT_SW_MINOR_VERSION               (3)
#define SCHM_PORT_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and PORT_CFG header file are of the same vendor */
#if (SCHM_PORT_VENDOR_ID != PORT_VENDOR_ID_CFG)
#error "SchM_Port.h and Port_Cfg.h have different vendor ids"
#endif

/* Check if header file and PORT_CFG header file are of the same Autosar version */
#if (( SCHM_PORT_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_PORT_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_PORT_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Port.h and Port_Cfg.h are different"
#endif

/* Check if header file and PORT_CFG header file are of the same Software version */
#if (( SCHM_PORT_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_PORT_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION_CFG) || \
      ( SCHM_PORT_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Port.h and Port_Cfg.h are different"
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

#if(STD_ON == PORT_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

extern void SchM_Enter_Port_PORT_EXCLUSIVE_AREA(void);
extern void SchM_Exit_Port_PORT_EXCLUSIVE_AREA(void);

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00() SchM_Enter_Port_PORT_EXCLUSIVE_AREA()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00() SchM_Exit_Port_PORT_EXCLUSIVE_AREA()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01() SchM_Enter_Port_PORT_EXCLUSIVE_AREA()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01() SchM_Exit_Port_PORT_EXCLUSIVE_AREA()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02() SchM_Enter_Port_PORT_EXCLUSIVE_AREA()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02() SchM_Exit_Port_PORT_EXCLUSIVE_AREA()

#else

extern void SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02()

#endif  /* (STD_ON == PORT_SCHM_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* End of file SchM_Port.h */

