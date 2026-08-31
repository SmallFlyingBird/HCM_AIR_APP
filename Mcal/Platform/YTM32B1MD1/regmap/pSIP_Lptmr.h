/**
*   @file    pSIP_Lptmr.h
*   @version
*
*   @brief   AUTOSAR Lptmr register map
*   @details Register map for LPTMR
*
*   @addtogroup LPTMR_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Lptmr
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

#ifndef PSIP_LPTMR_H
#define PSIP_LPTMR_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              LPTMR REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup lpTMR_Peripheral_Access_Layer lpTMR Peripheral Access Layer
 * @{
 */


/** lpTMR - Size of Registers Arrays */

/* lpTMR Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 PRS;                                /**< Prescaler Register, offset: 0x0004 */
    uint32 DIE;                                /**< DMA and Interrupt Enable Register, offset: 0x0008 */
    uint32 STS;                                /**< Status Register, offset: 0x000C */
    uint32 CMP;                                /**< Compare Value Register, offset: 0x0010 */
    uint32 LCNT;                               /**< Latch Timer Counter Register, offset: 0x0014 */
    uint32 CNT;                                /**< Timer Current Counter Register, offset: 0x0018 */

} lpTMR_Type, *lpTMR_MemMapPtr;

/** Number of instances of the lpTMR module. */
#define lpTMR_INSTANCE_COUNT                        (1u)

/* lpTMR0  base address */
#define lpTMR0_BASE_ADDR32                                 (0x4005D000U)
#define lpTMR0                                             ((volatile lpTMR_Type *)(lpTMR0_BASE_ADDR32))

/** Array initializer of lpTMR peripheral base addresses */
#define lpTMR_BASE_ADDRS                                   { lpTMR0_BASE_ADDR32 }
/** Array initializer of lpTMR peripheral base pointers */
#define lpTMR_BASE_PTRS                                    { lpTMR0 }

#define lpTMR_CTRL_OFFSET32                                (0x0000U)                    /**< Offset for Control Register */
#define lpTMR_PRS_OFFSET32                                 (0x0004U)                    /**< Offset for Prescaler Register */
#define lpTMR_DIE_OFFSET32                                 (0x0008U)                    /**< Offset for DMA and Interrupt Enable Register */
#define lpTMR_STS_OFFSET32                                 (0x000CU)                    /**< Offset for Status Register */
#define lpTMR_CMP_OFFSET32                                 (0x0010U)                    /**< Offset for Compare Value Register */
#define lpTMR_LCNT_OFFSET32                                (0x0014U)                    /**< Offset for Latch Timer Counter Register */
#define lpTMR_CNT_OFFSET32                                 (0x0018U)                    /**< Offset for Timer Current Counter Register */


/**
 * @addtogroup lpTMR Register Mask
 * @{
 */
/* lpTMR_CTRL Register */
#define lpTMR_CTRL_PINSEL_MASK                               (0x30U)
#define lpTMR_CTRL_PINSEL_SHIFT                              (4U)
#define lpTMR_CTRL_PINSEL(x)                                 (((uint32)(((uint32)(x)) << lpTMR_CTRL_PINSEL_SHIFT)) & lpTMR_CTRL_PINSEL_MASK)
#define lpTMR_CTRL_PINPOL_MASK                               (0x8U)
#define lpTMR_CTRL_PINPOL_SHIFT                              (3U)
#define lpTMR_CTRL_PINPOL(x)                                 (((uint32)(((uint32)(x)) << lpTMR_CTRL_PINPOL_SHIFT)) & lpTMR_CTRL_PINPOL_MASK)
#define lpTMR_CTRL_TMODE_MASK                                (0x4U)
#define lpTMR_CTRL_TMODE_SHIFT                               (2U)
#define lpTMR_CTRL_TMODE(x)                                  (((uint32)(((uint32)(x)) << lpTMR_CTRL_TMODE_SHIFT)) & lpTMR_CTRL_TMODE_MASK)
#define lpTMR_CTRL_MODE_MASK                                 (0x2U)
#define lpTMR_CTRL_MODE_SHIFT                                (1U)
#define lpTMR_CTRL_MODE(x)                                   (((uint32)(((uint32)(x)) << lpTMR_CTRL_MODE_SHIFT)) & lpTMR_CTRL_MODE_MASK)
#define lpTMR_CTRL_EN_MASK                                   (0x1U)
#define lpTMR_CTRL_EN_SHIFT                                  (0U)
#define lpTMR_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << lpTMR_CTRL_EN_SHIFT)) & lpTMR_CTRL_EN_MASK)
/* lpTMR_PRS Register */
#define lpTMR_PRS_PRES_WIDTH                                 (4)
#define lpTMR_PRS_PRES_MASK                                  (0x78U)
#define lpTMR_PRS_PRES_SHIFT                                 (3U)
#define lpTMR_PRS_PRES(x)                                    (((uint32)(((uint32)(x)) << lpTMR_PRS_PRES_SHIFT)) & lpTMR_PRS_PRES_MASK)
#define lpTMR_PRS_BYPASS_MASK                                (0x4U)
#define lpTMR_PRS_BYPASS_SHIFT                               (2U)
#define lpTMR_PRS_BYPASS(x)                                  (((uint32)(((uint32)(x)) << lpTMR_PRS_BYPASS_SHIFT)) & lpTMR_PRS_BYPASS_MASK)
#define lpTMR_PRS_CLKSEL_MASK                                (0x3U)
#define lpTMR_PRS_CLKSEL_SHIFT                               (0U)
#define lpTMR_PRS_CLKSEL(x)                                  (((uint32)(((uint32)(x)) << lpTMR_PRS_CLKSEL_SHIFT)) & lpTMR_PRS_CLKSEL_MASK)
/* lpTMR_DIE Register */
#define lpTMR_DIE_DMAEN_MASK                                 (0x2U)
#define lpTMR_DIE_DMAEN_SHIFT                                (1U)
#define lpTMR_DIE_DMAEN(x)                                   (((uint32)(((uint32)(x)) << lpTMR_DIE_DMAEN_SHIFT)) & lpTMR_DIE_DMAEN_MASK)
#define lpTMR_DIE_IE_MASK                                    (0x1U)
#define lpTMR_DIE_IE_SHIFT                                   (0U)
#define lpTMR_DIE_IE(x)                                      (((uint32)(((uint32)(x)) << lpTMR_DIE_IE_SHIFT)) & lpTMR_DIE_IE_MASK)
/* lpTMR_STS Register */
#define lpTMR_STS_CCF_MASK                                   (0x1U)
#define lpTMR_STS_CCF_SHIFT                                  (0U)
#define lpTMR_STS_CCF(x)                                     (((uint32)(((uint32)(x)) << lpTMR_STS_CCF_SHIFT)) & lpTMR_STS_CCF_MASK)
/* lpTMR_CMP Register */
#define lpTMR_CMP_CMP_MASK                                   (0xFFFFU)
#define lpTMR_CMP_CMP_SHIFT                                  (0U)
#define lpTMR_CMP_CMP(x)                                     (((uint32)(((uint32)(x)) << lpTMR_CMP_CMP_SHIFT)) & lpTMR_CMP_CMP_MASK)
/* lpTMR_LCNT Register */
#define lpTMR_LCNT_LCVAL_MASK                                (0xFFFFU)
#define lpTMR_LCNT_LCVAL_SHIFT                               (0U)
#define lpTMR_LCNT_LCVAL(x)                                  (((uint32)(((uint32)(x)) << lpTMR_LCNT_LCVAL_SHIFT)) & lpTMR_LCNT_LCVAL_MASK)
/* lpTMR_CNT Register */
#define lpTMR_CNT_CVAL_WIDTH                                 (16)
#define lpTMR_CNT_CVAL_MASK                                  (0xFFFFU)
#define lpTMR_CNT_CVAL_SHIFT                                 (0U)
#define lpTMR_CNT_CVAL(x)                                    (((uint32)(((uint32)(x)) << lpTMR_CNT_CVAL_SHIFT)) & lpTMR_CNT_CVAL_MASK)


/**
 * @}
 */ /* end of group lpTMR_Register_Masks */


/**
 * @}
 */ /* end of group lpTMR_Peripheral_Access_Layer */

#endif /* PSIP_LPTMR_H */

