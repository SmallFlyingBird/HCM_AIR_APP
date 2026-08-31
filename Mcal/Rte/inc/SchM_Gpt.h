/**
 * @file    SchM_Gpt.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR SchM_Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup SCHM_GPT_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr, Ptmr, Tmr, Rtc
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

#ifndef SCHM_GPT_H
#define SCHM_GPT_H

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0777,0779 EOF */
/*==================================================================================================
 *                                         INCLUDE FILES
==================================================================================================*/
#include "Gpt_Cfg.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_GPT_VENDOR_ID                      (180U)
#define SCHM_GPT_AR_RELEASE_MAJOR_VERSION       (4U)
#define SCHM_GPT_AR_RELEASE_MINOR_VERSION       (4U)
#define SCHM_GPT_AR_RELEASE_REVISION_VERSION    (0U)
#define SCHM_GPT_SW_MAJOR_VERSION               (2)
#define SCHM_GPT_SW_MINOR_VERSION               (3)
#define SCHM_GPT_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and GPT_CFG header file are of the same vendor */
#if (SCHM_GPT_VENDOR_ID != GPT_VENDOR_ID_CFG)
#error "SchM_Gpt.h and Gpt_Cfg.h have different vendor ids"
#endif

/* Check if header file and GPT_CFG header file are of the same Autosar version */
#if (( SCHM_GPT_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_GPT_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_GPT_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Gpt.h and Gpt_Cfg.h are different"
#endif

/* Check if header file and GPT_CFG header file are of the same Software version */
#if (( SCHM_GPT_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_GPT_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
      ( SCHM_GPT_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Gpt.h and Gpt_Cfg.h are different"
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

#if (STD_ON == GPT_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA(void);

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31() SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31() SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA()

#else

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30(void);

RTE_FUNC extern void SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31(void);
RTE_FUNC extern void SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30()

#define SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31()
#define SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31()

#endif /* GPT_SCHM_SUPPORT */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SCHM_GPT_H */

/** @} */

