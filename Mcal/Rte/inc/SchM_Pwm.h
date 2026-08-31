/**
 * @file    SchM_Pwm.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR SchM_Pwm module interface
 * @details API implementation for SchM_Pwm driver
 *
 * @addtogroup SCHM_PWM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifndef SCHM_PWM_H
#define SCHM_PWM_H

#include "Pwm_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0777,0779 EOF */
/*==================================================================================================
 *                                       INCLUDE FILES
==================================================================================================*/
#include "Pwm_Cfg.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_PWM_VENDOR_ID                      (180)
#define SCHM_PWM_AR_RELEASE_MAJOR_VERSION       (4)
#define SCHM_PWM_AR_RELEASE_MINOR_VERSION       (4)
#define SCHM_PWM_AR_RELEASE_REVISION_VERSION    (0)
#define SCHM_PWM_SW_MAJOR_VERSION               (2)
#define SCHM_PWM_SW_MINOR_VERSION               (3)
#define SCHM_PWM_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and PWM_CFG header file are of the same vendor */
#if (SCHM_PWM_VENDOR_ID != PWM_VENDOR_ID_CFG)
#error "SchM_Pwm.h and Pwm_Cfg.h have different vendor ids"
#endif

/* Check if header file and PWM_CFG header file are of the same Autosar version */
#if (( SCHM_PWM_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_PWM_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_PWM_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Pwm.h and Pwm_Cfg.h are different"
#endif

/* Check if header file and PWM_CFG header file are of the same Software version */
#if (( SCHM_PWM_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_PWM_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION_CFG) || \
      ( SCHM_PWM_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Pwm.h and Pwm_Cfg.h are different"
#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#ifndef NUMBER_OF_CORES
#define NUMBER_OF_CORES (1U)
#endif

/*==================================================================================================
 *                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#if (STD_ON == PWM_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA(void);

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10() SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10() SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA()

#else

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09(void);

RTE_FUNC extern void SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10(void);
RTE_FUNC extern void SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09()

#define SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10()
#define SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10()

#endif /* PWM_SCHM_SUPPORT */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SCHM_PWM_H */

/** @} */

