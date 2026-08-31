/*
* @file    SchM_Icu.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Icu
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef SCHM_ICU_H
#define SCHM_ICU_H

/**
*   @file    SchM_Icu.h
*
*   @addtogroup SCHM_ICU_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0777,0779 EOF */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Icu_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_ICU_VENDOR_ID                      (180)
#define SCHM_ICU_AR_RELEASE_MAJOR_VERSION       (4)
#define SCHM_ICU_AR_RELEASE_MINOR_VERSION       (4)
#define SCHM_ICU_AR_RELEASE_REVISION_VERSION    (0)
#define SCHM_ICU_SW_MAJOR_VERSION               (2)
#define SCHM_ICU_SW_MINOR_VERSION               (3)
#define SCHM_ICU_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and ICU_CFG header file are of the same vendor */
#if (SCHM_ICU_VENDOR_ID != ICU_VENDOR_ID_CFG)
#error "SchM_Icu.h and Icu_Cfg.h have different vendor ids"
#endif

/* Check if header file and ICU_CFG header file are of the same Autosar version */
#if (( SCHM_ICU_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_ICU_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_ICU_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Icu.h and Icu_Cfg.h are different"
#endif

/* Check if header file and ICU_CFG header file are of the same Software version */
#if (( SCHM_ICU_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_ICU_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) || \
      ( SCHM_ICU_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Icu.h and Icu_Cfg.h are different"
#endif
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

#if(STD_ON == ICU_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA(void);

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_06() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_06() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_07() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_07() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_20() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_20() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_22() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_22() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_23() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_23() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_24() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_24() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_25() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_25() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_26() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_26() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_27() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_27() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_28() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_28() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_29() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_29() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_30() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_30() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_31() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_31() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_32() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_32() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_33() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_33() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_34() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_34() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_35() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_35() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_36() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_36() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_37() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_37() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_38() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_38() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_39() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_39() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_40() SchM_Enter_Icu_ICU_EXCLUSIVE_AREA()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_40() SchM_Exit_Icu_ICU_EXCLUSIVE_AREA()

#else

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_20(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_22(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_22(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_23(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_23(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_24(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_24(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_25(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_25(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_26(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_26(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_27(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_27(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_28(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_28(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_29(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_29(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_30(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_30(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_31(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_31(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_32(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_32(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_33(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_33(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_34(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_34(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_35(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_35(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_36(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_36(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_37(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_37(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_38(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_38(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_39(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_39(void);

extern void SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_40(void);
extern void SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_40(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_06()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_06()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_07()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_07()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_20()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_20()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_22()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_22()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_23()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_23()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_24()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_24()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_25()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_25()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_26()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_26()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_27()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_27()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_28()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_28()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_29()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_29()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_30()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_30()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_31()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_31()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_32()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_32()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_33()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_33()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_34()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_34()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_35()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_35()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_36()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_36()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_37()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_37()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_38()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_38()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_39()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_39()

#define SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_40()
#define SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_40()
#endif /* STD_ON == ICU_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* End of file SchM_Icu.h */

