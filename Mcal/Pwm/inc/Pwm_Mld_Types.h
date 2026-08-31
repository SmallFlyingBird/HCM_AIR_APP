/**
 * @file    Pwm_Mld_Types.h
 * @version V2.3.0
 *
 * @brief   YUNTU Pwm_Mld module interface
 * @details API implementation for Pwm_Mld driver
 *
 * @addtogroup PWM_MLD_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : eTMR, MPWM
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifndef PWM_MLD_TYPES_H
#define PWM_MLD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Pwm_Mld_Cfg.h"
#if (PWM_ETMR_USED == STD_ON)
#include "Pwm_Lld_Etmr_Types.h"
#endif
#if (PWM_MPWM_USED == STD_ON)
#include "Pwm_Lld_Mpwm_Types.h"
#endif

/*==================================================================================================
 *                                   FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_MLD_TYPES_VENDOR_ID                      (180)
#define PWM_MLD_TYPES_MODULE_ID             (121)
#define PWM_MLD_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_MLD_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_MLD_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_MLD_TYPES_SW_MAJOR_VERSION               (2)
#define PWM_MLD_TYPES_SW_MINOR_VERSION               (3)
#define PWM_MLD_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Mld_Types.h and Pwm_Mld_Cfg.h are of the same vendor */
#if (PWM_MLD_TYPES_VENDOR_ID != PWM_MLD_CFG_VENDOR_ID)
#error "Pwm_Mld_Types.h and Pwm_Mld_Cfg.h have different vendor ids"
#endif
/* Check if Pwm_Mld_Types.h and Pwm_Mld_Cfg.h are of the same Autosar version */
#if ((PWM_MLD_TYPES_AR_RELEASE_MAJOR_VERSION != PWM_MLD_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_TYPES_AR_RELEASE_MINOR_VERSION != PWM_MLD_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_TYPES_AR_RELEASE_REVISION_VERSION != PWM_MLD_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld_Types.h and Pwm_Mld_Cfg.h are different"
#endif
/* Check if Pwm_Mld_Types.h and Pwm_Mld_Cfg.h are of the same software version */
#if ((PWM_MLD_TYPES_SW_MAJOR_VERSION != PWM_MLD_CFG_SW_MAJOR_VERSION) || \
     (PWM_MLD_TYPES_SW_MINOR_VERSION != PWM_MLD_CFG_SW_MINOR_VERSION) || \
     (PWM_MLD_TYPES_SW_PATCH_VERSION != PWM_MLD_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld_Types.h and Pwm_Mld_Cfg.h are different"
#endif

#if (PWM_ETMR_USED == STD_ON)
/* Check if Pwm_Mld_Types.h and Pwm_Lld_Etmr_Types.h are of the same vendor */
#if (PWM_MLD_TYPES_VENDOR_ID != PWM_LLD_ETMR_TYPES_VENDOR_ID)
#error "Pwm_Mld_Types.h and Pwm_Lld_Etmr_Types.h have different vendor ids"
#endif
/* Check if Pwm_Mld_Types.h and Pwm_Lld_Etmr_Types.h are of the same Autosar version */
#if ((PWM_MLD_TYPES_AR_RELEASE_MAJOR_VERSION != PWM_LLD_ETMR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_TYPES_AR_RELEASE_MINOR_VERSION != PWM_LLD_ETMR_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_TYPES_AR_RELEASE_REVISION_VERSION != PWM_LLD_ETMR_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld_Types.h and Pwm_Lld_Etmr_Types.h are different"
#endif
/* Check if Pwm_Mld_Types.h and Pwm_Lld_Etmr_Types.h are of the same software version */
#if ((PWM_MLD_TYPES_SW_MAJOR_VERSION != PWM_LLD_ETMR_TYPES_SW_MAJOR_VERSION) || \
     (PWM_MLD_TYPES_SW_MINOR_VERSION != PWM_LLD_ETMR_TYPES_SW_MINOR_VERSION) || \
     (PWM_MLD_TYPES_SW_PATCH_VERSION != PWM_LLD_ETMR_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld_Types.h and Pwm_Lld_Etmr_Types.h are different"
#endif
#endif

#if (PWM_MPWM_USED == STD_ON)
/* Check if Pwm_Mld_Types.h and Pwm_Lld_Mpwm_Types.h are of the same vendor */
#if (PWM_MLD_TYPES_VENDOR_ID != PWM_LLD_MPWM_TYPES_VENDOR_ID)
#error "Pwm_Mld_Types.h and Pwm_Lld_Mpwm_Types.h have different vendor ids"
#endif
/* Check if Pwm_Mld_Types.h and Pwm_Lld_Mpwm_Types.h are of the same Autosar version */
#if ((PWM_MLD_TYPES_AR_RELEASE_MAJOR_VERSION != PWM_LLD_MPWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_MLD_TYPES_AR_RELEASE_MINOR_VERSION != PWM_LLD_MPWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_MLD_TYPES_AR_RELEASE_REVISION_VERSION != PWM_LLD_MPWM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Mld_Types.h and Pwm_Lld_Mpwm_Types.h are different"
#endif
/* Check if Pwm_Mld_Types.h and Pwm_Lld_Mpwm_Types.h are of the same software version */
#if ((PWM_MLD_TYPES_SW_MAJOR_VERSION != PWM_LLD_MPWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_MLD_TYPES_SW_MINOR_VERSION != PWM_LLD_MPWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_MLD_TYPES_SW_PATCH_VERSION != PWM_LLD_MPWM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Mld_Types.h and Pwm_Lld_Mpwm_Types.h are different"
#endif
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
 * @brief   Defines enum for a type of instance.
 */
typedef enum
{
    PWM_MLD_INST_ETMR   = 0x00U,    /**< Pwm Mld Instance eTMR */
    PWM_MLD_INST_MPWM   = 0x01U,    /**< Pwm Mld Instance MPWM */
    PWM_MLD_INST_CNT    = 0x02U     /**< Pwm Mld Instance Count */
} Pwm_Mld_InstType;

/**
 * @brief   Defines enum for a type of channel.
 */
typedef enum
{
    PWM_MLD_CHN_ETMR    = 0x00U,    /**< Pwm Mld Channel eTMR */
    PWM_MLD_CHN_MPWM    = 0x01U,    /**< Pwm Mld Channel MPWM */
    PWM_MLD_CHN_CNT     = 0x02U     /**< Pwm Mld Channel Count */
} Pwm_Mld_ChType;

/**
 * @brief   Defines struct for a type of PWM configuration.
 */
typedef struct
{
    uint8 InstId;                                   /**< Instance ID */
    Pwm_Mld_InstType InstType;                      /**< Instance Type */
#if (PWM_ETMR_USED == STD_ON)
    const Pwm_Lld_Etmr_InstCfgType *EtmrInstCfg;    /**< eTMR Instance Configuration */
#endif
} Pwm_Mld_InstCfgType;

/**
 * @brief   Defines struct for a type of PWM channel configuration.
 */
typedef struct
{
    uint8 ChInstId;                             /**< Channel Instance ID */
    Pwm_Mld_ChType ChType;                      /**< Channel Type */
    uint16 ChDutyCycle;                         /**< Channel Duty Cycle */
#if (PWM_ETMR_USED == STD_ON)
    const Pwm_Lld_Etmr_ChCfgType *EtmrChCfg;    /**< eTMR Channel Configuration */
#endif
#if (PWM_MPWM_USED == STD_ON)
    const Pwm_Lld_Mpwm_ChCfgType *MpwmChCfg;    /**< MPWM Channel Configuration */
#endif
} Pwm_Mld_ChCfgType;

#ifdef __cplusplus
}
#endif

#endif /* PWM_MLD_TYPES_H */

/** @} */

