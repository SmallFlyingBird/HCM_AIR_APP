/**
*   @file    pSIP_Rcu.h
*   @version
*
*   @brief   AUTOSAR Rcu register map
*   @details Register map for RCU
*
*   @addtogroup RCU_MODULE
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

#ifndef PSIP_RCU_H
#define PSIP_RCU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              RCU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup RCU_Peripheral_Access_Layer RCU Peripheral Access Layer
 * @{
 */


/** RCU - Size of Registers Arrays */

/* RCU Register Layout Typedef */
typedef struct {
    uint32 RSSR;                               /**< Reset Source Status Register, offset: 0x0000 */
    uint32 RPFR;                               /**< Reset Pin Filter Register, offset: 0x0004 */

} RCU_Type, *RCU_MemMapPtr;

/** Number of instances of the RCU module. */
#define RCU_INSTANCE_COUNT                        (1u)

/* RCU base address */
#define RCU_BASE_ADDR32                                   (0x4007F000U)
#define RCU                                               ((volatile RCU_Type *)(RCU_BASE_ADDR32))

/** Array initializer of RCU peripheral base addresses */
#define RCU_BASE_ADDRS                                     { RCU_BASE_ADDR32 }
/** Array initializer of RCU peripheral base pointers */
#define RCU_BASE_PTRS                                      { RCU }

#define RCU_RSSR_OFFSET32                                  (0x0000U)                    /**< Offset for Reset Source Status Register */
#define RCU_RPFR_OFFSET32                                  (0x0004U)                    /**< Offset for Reset Pin Filter Register */


/**
 * @addtogroup RCU Register Mask
 * @{
 */
/* RCU_RSSR Register */
#define RCU_RSSR_MASK                                      (0x001F0303U)
#define RCU_RSSR_HVD_MASK                                  (0x100000U)
#define RCU_RSSR_HVD_SHIFT                                 (20U)
#define RCU_RSSR_HVD(x)                                    (((uint32)(((uint32)(x)) << RCU_RSSR_HVD_SHIFT)) & RCU_RSSR_HVD_MASK)
#define RCU_RSSR_LPACK_MASK                                (0x80000U)
#define RCU_RSSR_LPACK_SHIFT                               (19U)
#define RCU_RSSR_LPACK(x)                                  (((uint32)(((uint32)(x)) << RCU_RSSR_LPACK_SHIFT)) & RCU_RSSR_LPACK_MASK)
#define RCU_RSSR_WDG_MASK                                  (0x40000U)
#define RCU_RSSR_WDG_SHIFT                                 (18U)
#define RCU_RSSR_WDG(x)                                    (((uint32)(((uint32)(x)) << RCU_RSSR_WDG_SHIFT)) & RCU_RSSR_WDG_MASK)
#define RCU_RSSR_CMU_MASK                                  (0x20000U)
#define RCU_RSSR_CMU_SHIFT                                 (17U)
#define RCU_RSSR_CMU(x)                                    (((uint32)(((uint32)(x)) << RCU_RSSR_CMU_SHIFT)) & RCU_RSSR_CMU_MASK)
#define RCU_RSSR_LOCKUP_MASK                               (0x10000U)
#define RCU_RSSR_LOCKUP_SHIFT                              (16U)
#define RCU_RSSR_LOCKUP(x)                                 (((uint32)(((uint32)(x)) << RCU_RSSR_LOCKUP_SHIFT)) & RCU_RSSR_LOCKUP_MASK)
#define RCU_RSSR_DBG_MASK                                  (0x200U)
#define RCU_RSSR_DBG_SHIFT                                 (9U)
#define RCU_RSSR_DBG(x)                                    (((uint32)(((uint32)(x)) << RCU_RSSR_DBG_SHIFT)) & RCU_RSSR_DBG_MASK)
#define RCU_RSSR_SW_MASK                                   (0x100U)
#define RCU_RSSR_SW_SHIFT                                  (8U)
#define RCU_RSSR_SW(x)                                     (((uint32)(((uint32)(x)) << RCU_RSSR_SW_SHIFT)) & RCU_RSSR_SW_MASK)
#define RCU_RSSR_PIN_MASK                                  (0x2U)
#define RCU_RSSR_PIN_SHIFT                                 (1U)
#define RCU_RSSR_PIN(x)                                    (((uint32)(((uint32)(x)) << RCU_RSSR_PIN_SHIFT)) & RCU_RSSR_PIN_MASK)
#define RCU_RSSR_POR_LVD_MASK                              (0x1U)
#define RCU_RSSR_POR_LVD_SHIFT                             (0U)
#define RCU_RSSR_POR_LVD(x)                                (((uint32)(((uint32)(x)) << RCU_RSSR_POR_LVD_SHIFT)) & RCU_RSSR_POR_LVD_MASK)
/* RCU_RPFR Register */
#define RCU_RPFR_RSTPIN_IBE_MASK                           (0x20000U)
#define RCU_RPFR_RSTPIN_IBE_SHIFT                          (17U)
#define RCU_RPFR_RSTPIN_IBE(x)                             (((uint32)(((uint32)(x)) << RCU_RPFR_RSTPIN_IBE_SHIFT)) & RCU_RPFR_RSTPIN_IBE_MASK)
#define RCU_RPFR_RSTPIN_OBEN_MASK                          (0x10000U)
#define RCU_RPFR_RSTPIN_OBEN_SHIFT                         (16U)
#define RCU_RPFR_RSTPIN_OBEN(x)                            (((uint32)(((uint32)(x)) << RCU_RPFR_RSTPIN_OBEN_SHIFT)) & RCU_RPFR_RSTPIN_OBEN_MASK)
#define RCU_RPFR_FLTVAL_MASK                               (0xFF00U)
#define RCU_RPFR_FLTVAL_SHIFT                              (8U)
#define RCU_RPFR_FLTVAL(x)                                 (((uint32)(((uint32)(x)) << RCU_RPFR_FLTVAL_SHIFT)) & RCU_RPFR_FLTVAL_MASK)
#define RCU_RPFR_FLTSTEN_MASK                              (0x2U)
#define RCU_RPFR_FLTSTEN_SHIFT                             (1U)
#define RCU_RPFR_FLTSTEN(x)                                (((uint32)(((uint32)(x)) << RCU_RPFR_FLTSTEN_SHIFT)) & RCU_RPFR_FLTSTEN_MASK)
#define RCU_RPFR_FLTEN_MASK                                (0x1U)
#define RCU_RPFR_FLTEN_SHIFT                               (0U)
#define RCU_RPFR_FLTEN(x)                                  (((uint32)(((uint32)(x)) << RCU_RPFR_FLTEN_SHIFT)) & RCU_RPFR_FLTEN_MASK)


/**
 * @}
 */ /* end of group RCU_Register_Masks */


/**
 * @}
 */ /* end of group RCU_Peripheral_Access_Layer */

#endif /* PSIP_RCU_H */

