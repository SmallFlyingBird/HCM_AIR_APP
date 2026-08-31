/**
*   @file    pSIP_Wdg.h
*   @version
*
*   @brief   AUTOSAR Wdg register map
*   @details Register map for WDG
*
*   @addtogroup WDG_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Adc
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

#ifndef PSIP_WDG_H
#define PSIP_WDG_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              WDG REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup WDG_Peripheral_Access_Layer WDG Peripheral Access Layer
 * @{
 */


/** WDG - Size of Registers Arrays */

/* WDG Register Layout Typedef */
typedef struct {
    uint32 SVCR;                               /**< Service Code Register, offset: 0x0000 */
    uint32 CR;                                 /**< Control Register, offset: 0x0004 */
    uint32 LR;                                 /**< Lock Register, offset: 0x0008 */
    uint32 TOVR;                               /**< Timer Overflow Value, offset: 0x000C */
    uint32 WVR;                                /**< Window Value Register, offset: 0x0010 */
    uint32 CNTCVR;                             /**< Counter Current Value Register, offset: 0x0014 */
    uint32 INTF;                               /**< Interrupt Flag register, offset: 0x0018 */

} WDG_Type, *WDG_MemMapPtr;

/** Number of instances of the WDG module. */
#define WDG_INSTANCE_COUNT                        (1u)

/* WDG base address */
#define WDG_BASE_ADDR32                                   (0x4006A000U)
#define WDG                                               ((volatile WDG_Type *)(WDG_BASE_ADDR32))

/** Array initializer of WDG peripheral base addresses */
#define WDG_BASE_ADDRS                                     { WDG_BASE_ADDR32 }
/** Array initializer of WDG peripheral base pointers */
#define WDG_BASE_PTRS                                      { WDG }

#define WDG_SVCR_OFFSET32                                  (0x0000U)                    /**< Offset for Service Code Register */
#define WDG_CR_OFFSET32                                    (0x0004U)                    /**< Offset for Control Register */
#define WDG_LR_OFFSET32                                    (0x0008U)                    /**< Offset for Lock Register */
#define WDG_TOVR_OFFSET32                                  (0x000CU)                    /**< Offset for Timer Overflow Value */
#define WDG_WVR_OFFSET32                                   (0x0010U)                    /**< Offset for Window Value Register */
#define WDG_CNTCVR_OFFSET32                                (0x0014U)                    /**< Offset for Counter Current Value Register */
#define WDG_INTF_OFFSET32                                  (0x0018U)                    /**< Offset for Interrupt Flag register */


/**
 * @addtogroup WDG Register Mask
 * @{
 */
/* WDG_SVCR Register */
#define WDG_SVCR_SVCODE_MASK                               (0xFFFFU)
#define WDG_SVCR_SVCODE_SHIFT                              (0U)
#define WDG_SVCR_SVCODE(x)                                 (((uint32)(((uint32)(x)) << WDG_SVCR_SVCODE_SHIFT)) & WDG_SVCR_SVCODE_MASK)
/* WDG_CR Register */
#define WDG_CR_RIA_MASK                                    (0x80U)
#define WDG_CR_RIA_SHIFT                                   (7U)
#define WDG_CR_RIA(x)                                      (((uint32)(((uint32)(x)) << WDG_CR_RIA_SHIFT)) & WDG_CR_RIA_MASK)
#define WDG_CR_WIN_MASK                                    (0x40U)
#define WDG_CR_WIN_SHIFT                                   (6U)
#define WDG_CR_WIN(x)                                      (((uint32)(((uint32)(x)) << WDG_CR_WIN_SHIFT)) & WDG_CR_WIN_MASK)
#define WDG_CR_IBR_MASK                                    (0x20U)
#define WDG_CR_IBR_SHIFT                                   (5U)
#define WDG_CR_IBR(x)                                      (((uint32)(((uint32)(x)) << WDG_CR_IBR_SHIFT)) & WDG_CR_IBR_MASK)
#define WDG_CR_CLKSRC_WIDTH                                (2)
#define WDG_CR_CLKSRC_MASK                                 (0x18U)
#define WDG_CR_CLKSRC_SHIFT                                (3U)
#define WDG_CR_CLKSRC(x)                                   (((uint32)(((uint32)(x)) << WDG_CR_CLKSRC_SHIFT)) & WDG_CR_CLKSRC_MASK)
#define WDG_CR_DSDIS_MASK                                  (0x4U)
#define WDG_CR_DSDIS_SHIFT                                 (2U)
#define WDG_CR_DSDIS(x)                                    (((uint32)(((uint32)(x)) << WDG_CR_DSDIS_SHIFT)) & WDG_CR_DSDIS_MASK)
#define WDG_CR_DBGDIS_MASK                                 (0x2U)
#define WDG_CR_DBGDIS_SHIFT                                (1U)
#define WDG_CR_DBGDIS(x)                                   (((uint32)(((uint32)(x)) << WDG_CR_DBGDIS_SHIFT)) & WDG_CR_DBGDIS_MASK)
#define WDG_CR_EN_MASK                                     (0x1U)
#define WDG_CR_EN_SHIFT                                    (0U)
#define WDG_CR_EN(x)                                       (((uint32)(((uint32)(x)) << WDG_CR_EN_SHIFT)) & WDG_CR_EN_MASK)
/* WDG_LR Register */
#define WDG_LR_HL_MASK                                     (0x2U)
#define WDG_LR_HL_SHIFT                                    (1U)
#define WDG_LR_HL(x)                                       (((uint32)(((uint32)(x)) << WDG_LR_HL_SHIFT)) & WDG_LR_HL_MASK)
#define WDG_LR_SL_MASK                                     (0x1U)
#define WDG_LR_SL_SHIFT                                    (0U)
#define WDG_LR_SL(x)                                       (((uint32)(((uint32)(x)) << WDG_LR_SL_SHIFT)) & WDG_LR_SL_MASK)
/* WDG_TOVR Register */
#define WDG_TOVR_TO_MASK                                   (0xFFFFFFFFU)
#define WDG_TOVR_TO_SHIFT                                  (0U)
#define WDG_TOVR_TO(x)                                     (((uint32)(((uint32)(x)) << WDG_TOVR_TO_SHIFT)) & WDG_TOVR_TO_MASK)
/* WDG_WVR Register */
#define WDG_WVR_WIN_MASK                                   (0xFFFFFFFFU)
#define WDG_WVR_WIN_SHIFT                                  (0U)
#define WDG_WVR_WIN(x)                                     (((uint32)(((uint32)(x)) << WDG_WVR_WIN_SHIFT)) & WDG_WVR_WIN_MASK)
/* WDG_CNTCVR Register */
#define WDG_CNTCVR_CVAL_MASK                               (0xFFFFFFFFU)
#define WDG_CNTCVR_CVAL_SHIFT                              (0U)
#define WDG_CNTCVR_CVAL(x)                                 (((uint32)(((uint32)(x)) << WDG_CNTCVR_CVAL_SHIFT)) & WDG_CNTCVR_CVAL_MASK)
/* WDG_INTF Register */
#define WDG_INTF_IF_MASK                                   (0x1U)
#define WDG_INTF_IF_SHIFT                                  (0U)
#define WDG_INTF_IF(x)                                     (((uint32)(((uint32)(x)) << WDG_INTF_IF_SHIFT)) & WDG_INTF_IF_MASK)


/**
 * @}
 */ /* end of group WDG_Register_Masks */


/**
 * @}
 */ /* end of group WDG_Peripheral_Access_Layer */

#endif /* PSIP_WDG_H */

