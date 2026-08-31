/**
*   @file    pSIP_Rtc.h
*   @version
*
*   @brief   AUTOSAR Rtc register map
*   @details Register map for RTC
*
*   @addtogroup RTC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Rtc
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

#ifndef PSIP_RTC_H
#define PSIP_RTC_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              RTC REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */


/** RTC - Size of Registers Arrays */

/* RTC Register Layout Typedef */
typedef struct {
    uint32 SEC;                                /**< Second Register, offset: 0x0000 */
    uint32 RESERVED_1;                         /**< RESERVED_1, offset: 0x0004 */
    uint32 CMP;                                /**< Compensation Register, offset: 0x0008 */
    uint32 ALM;                                /**< Alarm Register, offset: 0x000C */
    uint32 EN;                                 /**< Enable Register, offset: 0x0010 */
    uint32 CTRL;                               /**< Control Register, offset: 0x0014 */
    uint32 INTF;                               /**< Interrupt Flag Register, offset: 0x0018 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x001C */

} RTC_Type, *RTC_MemMapPtr;

/** Number of instances of the RTC module. */
#define RTC_INSTANCE_COUNT                        (1u)

/* RTC0  base address */
#define RTC0_BASE_ADDR32                                   (0x40060000U)
#define RTC0                                               ((volatile RTC_Type *)(RTC0_BASE_ADDR32))

/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                                     { RTC0_BASE_ADDR32 }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                                      { RTC0 }

#define RTC_SEC_OFFSET32                                   (0x0000U)                    /**< Offset for Second Register */
#define RTC_CMP_OFFSET32                                   (0x0008U)                    /**< Offset for Compensation Register */
#define RTC_ALM_OFFSET32                                   (0x000CU)                    /**< Offset for Alarm Register */
#define RTC_EN_OFFSET32                                    (0x0010U)                    /**< Offset for Enable Register */
#define RTC_CTRL_OFFSET32                                  (0x0014U)                    /**< Offset for Control Register */
#define RTC_INTF_OFFSET32                                  (0x0018U)                    /**< Offset for Interrupt Flag Register */
#define RTC_INTE_OFFSET32                                  (0x001CU)                    /**< Offset for Interrupt Enable Register */


/**
 * @addtogroup RTC Register Mask
 * @{
 */
/* RTC_SEC Register */
#define RTC_SEC_SEC_MASK                                   (0xFFFFFFFFU)
#define RTC_SEC_SEC_SHIFT                                  (0U)
#define RTC_SEC_SEC(x)                                     (((uint32)(((uint32)(x)) << RTC_SEC_SEC_SHIFT)) & RTC_SEC_SEC_MASK)
/* RTC_CMP Register */
#define RTC_CMP_CMPIVS_MASK                                (0xFF000000U)
#define RTC_CMP_CMPIVS_SHIFT                               (24U)
#define RTC_CMP_CMPIVS(x)                                  (((uint32)(((uint32)(x)) << RTC_CMP_CMPIVS_SHIFT)) & RTC_CMP_CMPIVS_MASK)
#define RTC_CMP_CMPVS_MASK                                 (0xFF0000U)
#define RTC_CMP_CMPVS_SHIFT                                (16U)
#define RTC_CMP_CMPVS(x)                                   (((uint32)(((uint32)(x)) << RTC_CMP_CMPVS_SHIFT)) & RTC_CMP_CMPVS_MASK)
#define RTC_CMP_CMPIV_MASK                                 (0xFF00U)
#define RTC_CMP_CMPIV_SHIFT                                (8U)
#define RTC_CMP_CMPIV(x)                                   (((uint32)(((uint32)(x)) << RTC_CMP_CMPIV_SHIFT)) & RTC_CMP_CMPIV_MASK)
#define RTC_CMP_CMPV_MASK                                  (0xFFU)
#define RTC_CMP_CMPV_SHIFT                                 (0U)
#define RTC_CMP_CMPV(x)                                    (((uint32)(((uint32)(x)) << RTC_CMP_CMPV_SHIFT)) & RTC_CMP_CMPV_MASK)
/* RTC_ALM Register */
#define RTC_ALM_ALM_MASK                                   (0xFFFFFFFFU)
#define RTC_ALM_ALM_SHIFT                                  (0U)
#define RTC_ALM_ALM(x)                                     (((uint32)(((uint32)(x)) << RTC_ALM_ALM_SHIFT)) & RTC_ALM_ALM_MASK)
/* RTC_EN Register */
#define RTC_EN_EN_MASK                                     (0x1U)
#define RTC_EN_EN_SHIFT                                    (0U)
#define RTC_EN_EN(x)                                       (((uint32)(((uint32)(x)) << RTC_EN_EN_SHIFT)) & RTC_EN_EN_MASK)
/* RTC_CTRL Register */
#define RTC_CTRL_DBGDIS_MASK                               (0x40U)
#define RTC_CTRL_DBGDIS_SHIFT                              (6U)
#define RTC_CTRL_DBGDIS(x)                                 (((uint32)(((uint32)(x)) << RTC_CTRL_DBGDIS_SHIFT)) & RTC_CTRL_DBGDIS_MASK)
#define RTC_CTRL_UNLOCK_MASK                               (0x20U)
#define RTC_CTRL_UNLOCK_SHIFT                              (5U)
#define RTC_CTRL_UNLOCK(x)                                 (((uint32)(((uint32)(x)) << RTC_CTRL_UNLOCK_SHIFT)) & RTC_CTRL_UNLOCK_MASK)
#define RTC_CTRL_CLKOUTEN_MASK                             (0x10U)
#define RTC_CTRL_CLKOUTEN_SHIFT                            (4U)
#define RTC_CTRL_CLKOUTEN(x)                               (((uint32)(((uint32)(x)) << RTC_CTRL_CLKOUTEN_SHIFT)) & RTC_CTRL_CLKOUTEN_MASK)
#define RTC_CTRL_CLKOUTSEL_MASK                            (0x8U)
#define RTC_CTRL_CLKOUTSEL_SHIFT                           (3U)
#define RTC_CTRL_CLKOUTSEL(x)                              (((uint32)(((uint32)(x)) << RTC_CTRL_CLKOUTSEL_SHIFT)) & RTC_CTRL_CLKOUTSEL_MASK)
#define RTC_CTRL_CLKSEL_WIDTH                              (2)
#define RTC_CTRL_CLKSEL_MASK                               (0x6U)
#define RTC_CTRL_CLKSEL_SHIFT                              (1U)
#define RTC_CTRL_CLKSEL(x)                                 (((uint32)(((uint32)(x)) << RTC_CTRL_CLKSEL_SHIFT)) & RTC_CTRL_CLKSEL_MASK)
#define RTC_CTRL_SWRST_MASK                                (0x1U)
#define RTC_CTRL_SWRST_SHIFT                               (0U)
#define RTC_CTRL_SWRST(x)                                  (((uint32)(((uint32)(x)) << RTC_CTRL_SWRST_SHIFT)) & RTC_CTRL_SWRST_MASK)
/* RTC_INTF Register */
#define RTC_INTF_SECIF_MASK                                (0x4U)
#define RTC_INTF_SECIF_SHIFT                               (2U)
#define RTC_INTF_SECIF(x)                                  (((uint32)(((uint32)(x)) << RTC_INTF_SECIF_SHIFT)) & RTC_INTF_SECIF_MASK)
#define RTC_INTF_ALMIF_MASK                                (0x2U)
#define RTC_INTF_ALMIF_SHIFT                               (1U)
#define RTC_INTF_ALMIF(x)                                  (((uint32)(((uint32)(x)) << RTC_INTF_ALMIF_SHIFT)) & RTC_INTF_ALMIF_MASK)
#define RTC_INTF_OVFIF_MASK                                (0x1U)
#define RTC_INTF_OVFIF_SHIFT                               (0U)
#define RTC_INTF_OVFIF(x)                                  (((uint32)(((uint32)(x)) << RTC_INTF_OVFIF_SHIFT)) & RTC_INTF_OVFIF_MASK)
/* RTC_INTE Register */
#define RTC_INTE_SECOCS_MASK                               (0x700U)
#define RTC_INTE_SECOCS_SHIFT                              (8U)
#define RTC_INTE_SECOCS(x)                                 (((uint32)(((uint32)(x)) << RTC_INTE_SECOCS_SHIFT)) & RTC_INTE_SECOCS_MASK)
#define RTC_INTE_SECIE_MASK                                (0x4U)
#define RTC_INTE_SECIE_SHIFT                               (2U)
#define RTC_INTE_SECIE(x)                                  (((uint32)(((uint32)(x)) << RTC_INTE_SECIE_SHIFT)) & RTC_INTE_SECIE_MASK)
#define RTC_INTE_ALMIE_MASK                                (0x2U)
#define RTC_INTE_ALMIE_SHIFT                               (1U)
#define RTC_INTE_ALMIE(x)                                  (((uint32)(((uint32)(x)) << RTC_INTE_ALMIE_SHIFT)) & RTC_INTE_ALMIE_MASK)
#define RTC_INTE_OVFIE_MASK                                (0x1U)
#define RTC_INTE_OVFIE_SHIFT                               (0U)
#define RTC_INTE_OVFIE(x)                                  (((uint32)(((uint32)(x)) << RTC_INTE_OVFIE_SHIFT)) & RTC_INTE_OVFIE_MASK)


/**
 * @}
 */ /* end of group RTC_Register_Masks */


/**
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */

#endif /* PSIP_RTC_H */

