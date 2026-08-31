/**
*   @file    pSIP_Ptu.h
*   @version
*
*   @brief   AUTOSAR Ptu register map
*   @details Register map for PTU
*
*   @addtogroup PTU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Ptu
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

#ifndef PSIP_PTU_H
#define PSIP_PTU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              PTU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup PTU_Peripheral_Access_Layer PTU Peripheral Access Layer
 * @{
 */


/** PTU - Size of Registers Arrays */
#define PTU_CHDLYn_COUNT           (8u)

/* PTU Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 PRS;                                /**< Prescaler Select Register, offset: 0x0004 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x0008 */
    uint32 STS;                                /**< Interrupt Flag Register, offset: 0x000C */
    uint32 MOD;                                /**< Modulus Register, offset: 0x0010 */
    uint32 CNT;                                /**< Counter Current Value Register, offset: 0x0014 */
    uint32 INTDLY;                             /**< Interrupt Delay Register, offset: 0x0018 */
    uint32 RESERVED0;                          /**< RESERVED0, offset: 0x001C */
    uint32 CHCTRL;                             /**< Channel Control Register, offset: 0x0020 */
    uint32 CHSTS;                              /**< Channel Status Register, offset: 0x0024 */
    uint32 CHDLYn[ 8];                         /**< Channel Delay n Register, offset: 0x0028 */
    uint32 RESERVED1[82];                      /**< RESERVED1, offset: 0x0048 */
    uint32 POEN;                               /**< Pulse-Out Enable Register, offset: 0x0190 */
    uint32 PODLY;                              /**< Pulse-Out Delay Register, offset: 0x0194 */

} PTU_Type, *PTU_MemMapPtr;

/** Number of instances of the PTU module. */
#define PTU_INSTANCE_COUNT                        (1u)

/* PTU0  base address */
#define PTU0_BASE_ADDR32                                   (0x40046000U)
#define PTU0                                               ((volatile PTU_Type *)(PTU0_BASE_ADDR32))

/** Array initializer of PTU peripheral base addresses */
#define PTU_BASE_ADDRS                                     { PTU0_BASE_ADDR32 }
/** Array initializer of PTU peripheral base pointers */
#define PTU_BASE_PTRS                                      { PTU0 }

#define PTU_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define PTU_PRS_OFFSET32                                   (0x0004U)                    /**< Offset for Prescaler Select Register */
#define PTU_INTE_OFFSET32                                  (0x0008U)                    /**< Offset for Interrupt Enable Register */
#define PTU_STS_OFFSET32                                   (0x000CU)                    /**< Offset for Interrupt Flag Register */
#define PTU_MOD_OFFSET32                                   (0x0010U)                    /**< Offset for Modulus Register */
#define PTU_CNT_OFFSET32                                   (0x0014U)                    /**< Offset for Counter Current Value Register */
#define PTU_INTDLY_OFFSET32                                (0x0018U)                    /**< Offset for Interrupt Delay Register */
#define PTU_CHCTRL_OFFSET32                                (0x0020U)                    /**< Offset for Channel Control Register */
#define PTU_CHSTS_OFFSET32                                 (0x0024U)                    /**< Offset for Channel Status Register */
#define PTU_CHDLYn_OFFSET32(x)                             (0x0028U + ((x) * (4U)))     /**< Offset for Channel Delay n Register */
#define PTU_POEN_OFFSET32                                  (0x0190U)                    /**< Offset for Pulse-Out Enable Register */
#define PTU_PODLY_OFFSET32                                 (0x0194U)                    /**< Offset for Pulse-Out Delay Register */


/**
 * @addtogroup PTU Register Mask
 * @{
 */
/* PTU_CTRL Register */
#define PTU_CTRL_SWTRIG_MASK                               (0x80U)
#define PTU_CTRL_SWTRIG_SHIFT                              (7U)
#define PTU_CTRL_SWTRIG(x)                                 (((uint32)(((uint32)(x)) << PTU_CTRL_SWTRIG_SHIFT)) & PTU_CTRL_SWTRIG_MASK)
#define PTU_CTRL_DMAEN_MASK                                (0x40U)
#define PTU_CTRL_DMAEN_SHIFT                               (6U)
#define PTU_CTRL_DMAEN(x)                                  (((uint32)(((uint32)(x)) << PTU_CTRL_DMAEN_SHIFT)) & PTU_CTRL_DMAEN_MASK)
#define PTU_CTRL_TRIGSEL_MASK                              (0x20U)
#define PTU_CTRL_TRIGSEL_SHIFT                             (5U)
#define PTU_CTRL_TRIGSEL(x)                                (((uint32)(((uint32)(x)) << PTU_CTRL_TRIGSEL_SHIFT)) & PTU_CTRL_TRIGSEL_MASK)
#define PTU_CTRL_CONT_MASK                                 (0x10U)
#define PTU_CTRL_CONT_SHIFT                                (4U)
#define PTU_CTRL_CONT(x)                                   (((uint32)(((uint32)(x)) << PTU_CTRL_CONT_SHIFT)) & PTU_CTRL_CONT_MASK)
#define PTU_CTRL_LDMD_MASK                                 (0xCU)
#define PTU_CTRL_LDMD_SHIFT                                (2U)
#define PTU_CTRL_LDMD(x)                                   (((uint32)(((uint32)(x)) << PTU_CTRL_LDMD_SHIFT)) & PTU_CTRL_LDMD_MASK)
#define PTU_CTRL_LDOK_MASK                                 (0x2U)
#define PTU_CTRL_LDOK_SHIFT                                (1U)
#define PTU_CTRL_LDOK(x)                                   (((uint32)(((uint32)(x)) << PTU_CTRL_LDOK_SHIFT)) & PTU_CTRL_LDOK_MASK)
#define PTU_CTRL_EN_MASK                                   (0x1U)
#define PTU_CTRL_EN_SHIFT                                  (0U)
#define PTU_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << PTU_CTRL_EN_SHIFT)) & PTU_CTRL_EN_MASK)
/* PTU_PRS Register */
#define PTU_PRS_DIV_MASK                                   (0x1CU)
#define PTU_PRS_DIV_SHIFT                                  (2U)
#define PTU_PRS_DIV(x)                                     (((uint32)(((uint32)(x)) << PTU_PRS_DIV_SHIFT)) & PTU_PRS_DIV_MASK)
#define PTU_PRS_MULT_MASK                                  (0x3U)
#define PTU_PRS_MULT_SHIFT                                 (0U)
#define PTU_PRS_MULT(x)                                    (((uint32)(((uint32)(x)) << PTU_PRS_MULT_SHIFT)) & PTU_PRS_MULT_MASK)
/* PTU_INTE Register */
#define PTU_INTE_IE_MASK                                   (0x1U)
#define PTU_INTE_IE_SHIFT                                  (0U)
#define PTU_INTE_IE(x)                                     (((uint32)(((uint32)(x)) << PTU_INTE_IE_SHIFT)) & PTU_INTE_IE_MASK)
/* PTU_STS Register */
#define PTU_STS_IF_MASK                                    (0x1U)
#define PTU_STS_IF_SHIFT                                   (0U)
#define PTU_STS_IF(x)                                      (((uint32)(((uint32)(x)) << PTU_STS_IF_SHIFT)) & PTU_STS_IF_MASK)
/* PTU_MOD Register */
#define PTU_MOD_MOD_MASK                                   (0xFFFFU)
#define PTU_MOD_MOD_SHIFT                                  (0U)
#define PTU_MOD_MOD(x)                                     (((uint32)(((uint32)(x)) << PTU_MOD_MOD_SHIFT)) & PTU_MOD_MOD_MASK)
/* PTU_CNT Register */
#define PTU_CNT_CNT_MASK                                   (0xFFFFU)
#define PTU_CNT_CNT_SHIFT                                  (0U)
#define PTU_CNT_CNT(x)                                     (((uint32)(((uint32)(x)) << PTU_CNT_CNT_SHIFT)) & PTU_CNT_CNT_MASK)
/* PTU_INTDLY Register */
#define PTU_INTDLY_INTDLY_MASK                             (0xFFFFU)
#define PTU_INTDLY_INTDLY_SHIFT                            (0U)
#define PTU_INTDLY_INTDLY(x)                               (((uint32)(((uint32)(x)) << PTU_INTDLY_INTDLY_SHIFT)) & PTU_INTDLY_INTDLY_MASK)
/* PTU_CHCTRL Register */
#define PTU_CHCTRL_CHDLYEN_MASK                            (0xFF00U)
#define PTU_CHCTRL_CHDLYEN_SHIFT                           (8U)
#define PTU_CHCTRL_CHDLYEN(x)                              (((uint32)(((uint32)(x)) << PTU_CHCTRL_CHDLYEN_SHIFT)) & PTU_CHCTRL_CHDLYEN_MASK)
#define PTU_CHCTRL_CHEN_MASK                               (0xFFU)
#define PTU_CHCTRL_CHEN_SHIFT                              (0U)
#define PTU_CHCTRL_CHEN(x)                                 (((uint32)(((uint32)(x)) << PTU_CHCTRL_CHEN_SHIFT)) & PTU_CHCTRL_CHEN_MASK)
/* PTU_CHSTS Register */
#define PTU_CHSTS_CHF_MASK                                 (0xFF0000U)
#define PTU_CHSTS_CHF_SHIFT                                (16U)
#define PTU_CHSTS_CHF(x)                                   (((uint32)(((uint32)(x)) << PTU_CHSTS_CHF_SHIFT)) & PTU_CHSTS_CHF_MASK)
/* PTU_CHDLYn Register */
#define PTU_CHDLYn_CHDLYn_MASK                             (0xFFFFU)
#define PTU_CHDLYn_CHDLYn_SHIFT                            (0U)
#define PTU_CHDLYn_CHDLYn(x)                               (((uint32)(((uint32)(x)) << PTU_CHDLYn_CHDLYn_SHIFT)) & PTU_CHDLYn_CHDLYn_MASK)
/* PTU_POEN Register */
#define PTU_POEN_POEN_MASK                                 (0x1U)
#define PTU_POEN_POEN_SHIFT                                (0U)
#define PTU_POEN_POEN(x)                                   (((uint32)(((uint32)(x)) << PTU_POEN_POEN_SHIFT)) & PTU_POEN_POEN_MASK)
/* PTU_PODLY Register */
#define PTU_PODLY_PODLY1_MASK                              (0xFFFF0000U)
#define PTU_PODLY_PODLY1_SHIFT                             (16U)
#define PTU_PODLY_PODLY1(x)                                (((uint32)(((uint32)(x)) << PTU_PODLY_PODLY1_SHIFT)) & PTU_PODLY_PODLY1_MASK)
#define PTU_PODLY_PODLY0_MASK                              (0xFFFFU)
#define PTU_PODLY_PODLY0_SHIFT                             (0U)
#define PTU_PODLY_PODLY0(x)                                (((uint32)(((uint32)(x)) << PTU_PODLY_PODLY0_SHIFT)) & PTU_PODLY_PODLY0_MASK)


/**
 * @}
 */ /* end of group PTU_Register_Masks */


/**
 * @}
 */ /* end of group PTU_Peripheral_Access_Layer */

#endif /* PSIP_PTU_H */

