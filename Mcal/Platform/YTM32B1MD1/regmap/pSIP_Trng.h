/**
*   @file    pSIP_Trng.h
*   @version
*
*   @brief   AUTOSAR Trng register map
*   @details Register map for TRNG
*
*   @addtogroup TRNG_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Trng
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
/*==================================================================================================
==================================================================================================*/

#ifndef PSIP_TRNG_H
#define PSIP_TRNG_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              TRNG REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup TRNG_Peripheral_Access_Layer TRNG Peripheral Access Layer
 * @{
 */


/** TRNG - Size of Registers Arrays */
#define TRNG_ENT_COUNT           (8)

/* TRNG Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 STAT;                               /**< Status Register, offset: 0x0004 */
    uint32 SDCTL;                              /**< Seed Control Register, offset: 0x0008 */
    uint32 FRQMIN;                             /**< Frequency Minimum Limit Register, offset: 0x000C */
    uint32 FRQMAX;                             /**< Frequency Maximum Limit Register, offset: 0x0010 */
    uint32 FRQCNT;                             /**< Frequency Count Register, offset: 0x0014 */
    uint32 SCML;                               /**< Statistical Check Monobit Limit Register, offset: 0x0018 */
    uint32 SCMC;                               /**< Statistical Check Monobit Count Register, offset: 0x001C */
    uint32 RESERVED0[ 8];                      /**< RESERVED0, offset: 0x0020 */
    uint32 ENT[ 8];                            /**< Entropy Read Register, offset: 0x0040 */

} TRNG_Type, *TRNG_MemMapPtr;

/** Number of instances of the TRNG module. */
#define TRNG_INSTANCE_COUNT                        (1u)

/* TRNG base address */
#define TRNG_BASE_ADDR32                                  (0x40066000U)
#define TRNG                                              ((volatile TRNG_Type *)(TRNG_BASE_ADDR32))

/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                                    { TRNG_BASE_ADDR32 }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                                     { TRNG }

#define TRNG_CTRL_OFFSET32                                 (0x0000U)                    /**< Offset for Control Register */
#define TRNG_STAT_OFFSET32                                 (0x0004U)                    /**< Offset for Status Register */
#define TRNG_SDCTL_OFFSET32                                (0x0008U)                    /**< Offset for Seed Control Register */
#define TRNG_FRQMIN_OFFSET32                               (0x000CU)                    /**< Offset for Frequency Minimum Limit Register */
#define TRNG_FRQMAX_OFFSET32                               (0x0010U)                    /**< Offset for Frequency Maximum Limit Register */
#define TRNG_FRQCNT_OFFSET32                               (0x0014U)                    /**< Offset for Frequency Count Register */
#define TRNG_SCML_OFFSET32                                 (0x0018U)                    /**< Offset for Statistical Check Monobit Limit Register */
#define TRNG_SCMC_OFFSET32                                 (0x001CU)                    /**< Offset for Statistical Check Monobit Count Register */
#define TRNG_ENT_OFFSET32(x)                               (0x0040U + ((x) * (4U)))     /**< Offset for Entropy Read Register */


/**
 * @addtogroup TRNG Register Mask
 * @{
 */
/* TRNG_CTRL Register */
#define TRNG_CTRL_RTY_CT_MASK                               (0xF000000U)
#define TRNG_CTRL_RTY_CT_SHIFT                              (24U)
#define TRNG_CTRL_RTY_CT(x)                                 (((uint32)(((uint32)(x)) << TRNG_CTRL_RTY_CT_SHIFT)) & TRNG_CTRL_RTY_CT_MASK)
#define TRNG_CTRL_LRUN_MAX_MASK                             (0xFF0000U)
#define TRNG_CTRL_LRUN_MAX_SHIFT                            (16U)
#define TRNG_CTRL_LRUN_MAX(x)                               (((uint32)(((uint32)(x)) << TRNG_CTRL_LRUN_MAX_SHIFT)) & TRNG_CTRL_LRUN_MAX_MASK)
#define TRNG_CTRL_FRQ_CT_IE_MASK                            (0x400U)
#define TRNG_CTRL_FRQ_CT_IE_SHIFT                           (10U)
#define TRNG_CTRL_FRQ_CT_IE(x)                              (((uint32)(((uint32)(x)) << TRNG_CTRL_FRQ_CT_IE_SHIFT)) & TRNG_CTRL_FRQ_CT_IE_MASK)
#define TRNG_CTRL_ENT_VAL_IE_MASK                           (0x200U)
#define TRNG_CTRL_ENT_VAL_IE_SHIFT                          (9U)
#define TRNG_CTRL_ENT_VAL_IE(x)                             (((uint32)(((uint32)(x)) << TRNG_CTRL_ENT_VAL_IE_SHIFT)) & TRNG_CTRL_ENT_VAL_IE_MASK)
#define TRNG_CTRL_HW_ERR_IE_MASK                            (0x100U)
#define TRNG_CTRL_HW_ERR_IE_SHIFT                           (8U)
#define TRNG_CTRL_HW_ERR_IE(x)                              (((uint32)(((uint32)(x)) << TRNG_CTRL_HW_ERR_IE_SHIFT)) & TRNG_CTRL_HW_ERR_IE_MASK)
#define TRNG_CTRL_FOR_SCLK_MASK                             (0x80U)
#define TRNG_CTRL_FOR_SCLK_SHIFT                            (7U)
#define TRNG_CTRL_FOR_SCLK(x)                               (((uint32)(((uint32)(x)) << TRNG_CTRL_FOR_SCLK_SHIFT)) & TRNG_CTRL_FOR_SCLK_MASK)
#define TRNG_CTRL_UNLOCK_MASK                               (0x20U)
#define TRNG_CTRL_UNLOCK_SHIFT                              (5U)
#define TRNG_CTRL_UNLOCK(x)                                 (((uint32)(((uint32)(x)) << TRNG_CTRL_UNLOCK_SHIFT)) & TRNG_CTRL_UNLOCK_MASK)
#define TRNG_CTRL_CLK_OUT_MASK                              (0x10U)
#define TRNG_CTRL_CLK_OUT_SHIFT                             (4U)
#define TRNG_CTRL_CLK_OUT(x)                                (((uint32)(((uint32)(x)) << TRNG_CTRL_CLK_OUT_SHIFT)) & TRNG_CTRL_CLK_OUT_MASK)
#define TRNG_CTRL_OSC_DIV_MASK                              (0xCU)
#define TRNG_CTRL_OSC_DIV_SHIFT                             (2U)
#define TRNG_CTRL_OSC_DIV(x)                                (((uint32)(((uint32)(x)) << TRNG_CTRL_OSC_DIV_SHIFT)) & TRNG_CTRL_OSC_DIV_MASK)
#define TRNG_CTRL_TRNG_EN_MASK                              (0x2U)
#define TRNG_CTRL_TRNG_EN_SHIFT                             (1U)
#define TRNG_CTRL_TRNG_EN(x)                                (((uint32)(((uint32)(x)) << TRNG_CTRL_TRNG_EN_SHIFT)) & TRNG_CTRL_TRNG_EN_MASK)
#define TRNG_CTRL_SWR_MASK                                  (0x1U)
#define TRNG_CTRL_SWR_SHIFT                                 (0U)
#define TRNG_CTRL_SWR(x)                                    (((uint32)(((uint32)(x)) << TRNG_CTRL_SWR_SHIFT)) & TRNG_CTRL_SWR_MASK)
/* TRNG_STAT Register */
#define TRNG_STAT_FRQ_CT_IF_MASK                            (0x400U)
#define TRNG_STAT_FRQ_CT_IF_SHIFT                           (10U)
#define TRNG_STAT_FRQ_CT_IF(x)                              (((uint32)(((uint32)(x)) << TRNG_STAT_FRQ_CT_IF_SHIFT)) & TRNG_STAT_FRQ_CT_IF_MASK)
#define TRNG_STAT_ENT_VAL_IF_MASK                           (0x200U)
#define TRNG_STAT_ENT_VAL_IF_SHIFT                          (9U)
#define TRNG_STAT_ENT_VAL_IF(x)                             (((uint32)(((uint32)(x)) << TRNG_STAT_ENT_VAL_IF_SHIFT)) & TRNG_STAT_ENT_VAL_IF_MASK)
#define TRNG_STAT_HW_ERR_IF_MASK                            (0x100U)
#define TRNG_STAT_HW_ERR_IF_SHIFT                           (8U)
#define TRNG_STAT_HW_ERR_IF(x)                              (((uint32)(((uint32)(x)) << TRNG_STAT_HW_ERR_IF_SHIFT)) & TRNG_STAT_HW_ERR_IF_MASK)
#define TRNG_STAT_IDLE_MASK                                 (0x20U)
#define TRNG_STAT_IDLE_SHIFT                                (5U)
#define TRNG_STAT_IDLE(x)                                   (((uint32)(((uint32)(x)) << TRNG_STAT_IDLE_SHIFT)) & TRNG_STAT_IDLE_MASK)
#define TRNG_STAT_FCT_VAL_MASK                              (0x2U)
#define TRNG_STAT_FCT_VAL_SHIFT                             (1U)
#define TRNG_STAT_FCT_VAL(x)                                (((uint32)(((uint32)(x)) << TRNG_STAT_FCT_VAL_SHIFT)) & TRNG_STAT_FCT_VAL_MASK)
/* TRNG_SDCTL Register */
#define TRNG_SDCTL_ENT_DLY_MASK                             (0xFFFF0000U)
#define TRNG_SDCTL_ENT_DLY_SHIFT                            (16U)
#define TRNG_SDCTL_ENT_DLY(x)                               (((uint32)(((uint32)(x)) << TRNG_SDCTL_ENT_DLY_SHIFT)) & TRNG_SDCTL_ENT_DLY_MASK)
#define TRNG_SDCTL_SAMP_SIZE_MASK                           (0xFFFFU)
#define TRNG_SDCTL_SAMP_SIZE_SHIFT                          (0U)
#define TRNG_SDCTL_SAMP_SIZE(x)                             (((uint32)(((uint32)(x)) << TRNG_SDCTL_SAMP_SIZE_SHIFT)) & TRNG_SDCTL_SAMP_SIZE_MASK)
/* TRNG_FRQMIN Register */
#define TRNG_FRQMIN_FRQ_MIN_MASK                            (0x3FFFFFU)
#define TRNG_FRQMIN_FRQ_MIN_SHIFT                           (0U)
#define TRNG_FRQMIN_FRQ_MIN(x)                              (((uint32)(((uint32)(x)) << TRNG_FRQMIN_FRQ_MIN_SHIFT)) & TRNG_FRQMIN_FRQ_MIN_MASK)
/* TRNG_FRQMAX Register */
#define TRNG_FRQMAX_FRQ_MAX_MASK                            (0x3FFFFFU)
#define TRNG_FRQMAX_FRQ_MAX_SHIFT                           (0U)
#define TRNG_FRQMAX_FRQ_MAX(x)                              (((uint32)(((uint32)(x)) << TRNG_FRQMAX_FRQ_MAX_SHIFT)) & TRNG_FRQMAX_FRQ_MAX_MASK)
/* TRNG_FRQCNT Register */
#define TRNG_FRQCNT_FRQ_CT_MASK                             (0x3FFFFFU)
#define TRNG_FRQCNT_FRQ_CT_SHIFT                            (0U)
#define TRNG_FRQCNT_FRQ_CT(x)                               (((uint32)(((uint32)(x)) << TRNG_FRQCNT_FRQ_CT_SHIFT)) & TRNG_FRQCNT_FRQ_CT_MASK)
/* TRNG_SCML Register */
#define TRNG_SCML_MONO_RNG_MASK                             (0xFFFF0000U)
#define TRNG_SCML_MONO_RNG_SHIFT                            (16U)
#define TRNG_SCML_MONO_RNG(x)                               (((uint32)(((uint32)(x)) << TRNG_SCML_MONO_RNG_SHIFT)) & TRNG_SCML_MONO_RNG_MASK)
#define TRNG_SCML_MONO_MAX_MASK                             (0xFFFFU)
#define TRNG_SCML_MONO_MAX_SHIFT                            (0U)
#define TRNG_SCML_MONO_MAX(x)                               (((uint32)(((uint32)(x)) << TRNG_SCML_MONO_MAX_SHIFT)) & TRNG_SCML_MONO_MAX_MASK)
/* TRNG_SCMC Register */
#define TRNG_SCMC_MONO_CT_MASK                              (0xFFFFU)
#define TRNG_SCMC_MONO_CT_SHIFT                             (0U)
#define TRNG_SCMC_MONO_CT(x)                                (((uint32)(((uint32)(x)) << TRNG_SCMC_MONO_CT_SHIFT)) & TRNG_SCMC_MONO_CT_MASK)
/* TRNG_ENT Register */
#define TRNG_ENT_ENT_MASK                                   (0xFFFFFFFFU)
#define TRNG_ENT_ENT_SHIFT                                  (0U)
#define TRNG_ENT_ENT(x)                                     (((uint32)(((uint32)(x)) << TRNG_ENT_ENT_SHIFT)) & TRNG_ENT_ENT_MASK)


/**
 * @}
 */ /* end of group TRNG_Register_Masks */


/**
 * @}
 */ /* end of group TRNG_Peripheral_Access_Layer */

#endif /* PSIP_TRNG_H */

