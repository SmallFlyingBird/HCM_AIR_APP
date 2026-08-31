/**
*   @file    pSIP_Ptmr.h
*   @version
*
*   @brief   AUTOSAR Ptmr register map
*   @details Register map for PTMR
*
*   @addtogroup PTMR_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Ptmr
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

#ifndef PSIP_PTMR_H
#define PSIP_PTMR_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              PTMR REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup pTMR_Peripheral_Access_Layer pTMR Peripheral Access Layer
 * @{
 */


/** pTMR - Size of Registers Arrays */
#define pTMR_CH_COUNT           (4)

/* pTMR Register Layout Typedef */
typedef struct {
    uint32 MCR;                                /**< Module Control Register, offset: 0x0000 */
    uint32 RESERVED0[63];                      /**< RESERVED0, offset: 0x0004 */
    struct {
        uint32 TSV;                                /**< Timer Start Value Register, offset: 0x0100 */
        uint32 TCV;                                /**< Timer Current Value Register, offset: 0x0104 */
        uint32 TCR;                                /**< Timer Control Register, offset: 0x0108 */
        uint32 TFR;                                /**< Timer Flag Register, offset: 0x010C */

    } CH[4];

} pTMR_Type, *pTMR_MemMapPtr;

/** Number of instances of the pTMR module. */
#define pTMR_INSTANCE_COUNT                        (1u)

/* pTMR0  base address */
#define pTMR0_BASE_ADDR32                                  (0x4005A000U)
#define pTMR0                                              ((volatile pTMR_Type *)(pTMR0_BASE_ADDR32))

/** Array initializer of pTMR peripheral base addresses */
#define pTMR_BASE_ADDRS                                    { pTMR0_BASE_ADDR32 }
/** Array initializer of pTMR peripheral base pointers */
#define pTMR_BASE_PTRS                                     { pTMR0 }

#define pTMR_MCR_OFFSET32                                  (0x0000U)                    /**< Offset for Module Control Register */
#define pTMR_CH_OFFSET32(x)                                (0x0100U + ((x) * (16U)))    /**< Offset for pTMR Channels */

#define pTMR_CH_TSV_OFFSET32(x)                            (0x0100U + ((x) * (16U)))    /**< Offset for Timer Start Value Register */
#define pTMR_CH_TCV_OFFSET32(x)                            (0x0104U + ((x) * (16U)))    /**< Offset for Timer Current Value Register */
#define pTMR_CH_TCR_OFFSET32(x)                            (0x0108U + ((x) * (16U)))    /**< Offset for Timer Control Register */
#define pTMR_CH_TFR_OFFSET32(x)                            (0x010CU + ((x) * (16U)))    /**< Offset for Timer Flag Register */



/**
 * @addtogroup pTMR Register Mask
 * @{
 */
/* pTMR_MCR Register */
#define pTMR_MCR_FRZ_MASK                                   (0x2U)
#define pTMR_MCR_FRZ_SHIFT                                  (1U)
#define pTMR_MCR_FRZ(x)                                     (((uint32)(((uint32)(x)) << pTMR_MCR_FRZ_SHIFT)) & pTMR_MCR_FRZ_MASK)
#define pTMR_MCR_EN_MASK                                    (0x1U)
#define pTMR_MCR_EN_SHIFT                                   (0U)
#define pTMR_MCR_EN(x)                                      (((uint32)(((uint32)(x)) << pTMR_MCR_EN_SHIFT)) & pTMR_MCR_EN_MASK)
/* pTMR_CH_TSV Register */
#define pTMR_CH_TSV_STVAL_MASK                                 (0xFFFFFFFFU)
#define pTMR_CH_TSV_STVAL_SHIFT                                (0U)
#define pTMR_CH_TSV_STVAL(x)                                   (((uint32)(((uint32)(x)) << pTMR_CH_TSV_STVAL_SHIFT)) & pTMR_CH_TSV_STVAL_MASK)
/* pTMR_CH_TCV Register */
#define pTMR_CH_TCV_CVAL_MASK                                  (0xFFFFFFFFU)
#define pTMR_CH_TCV_CVAL_SHIFT                                 (0U)
#define pTMR_CH_TCV_CVAL(x)                                    (((uint32)(((uint32)(x)) << pTMR_CH_TCV_CVAL_SHIFT)) & pTMR_CH_TCV_CVAL_MASK)
/* pTMR_CH_TCR Register */
#define pTMR_CH_TCR_CHAIN_MASK                                 (0x4U)
#define pTMR_CH_TCR_CHAIN_SHIFT                                (2U)
#define pTMR_CH_TCR_CHAIN(x)                                   (((uint32)(((uint32)(x)) << pTMR_CH_TCR_CHAIN_SHIFT)) & pTMR_CH_TCR_CHAIN_MASK)
#define pTMR_CH_TCR_TIE_MASK                                   (0x2U)
#define pTMR_CH_TCR_TIE_SHIFT                                  (1U)
#define pTMR_CH_TCR_TIE(x)                                     (((uint32)(((uint32)(x)) << pTMR_CH_TCR_TIE_SHIFT)) & pTMR_CH_TCR_TIE_MASK)
#define pTMR_CH_TCR_TEN_MASK                                   (0x1U)
#define pTMR_CH_TCR_TEN_SHIFT                                  (0U)
#define pTMR_CH_TCR_TEN(x)                                     (((uint32)(((uint32)(x)) << pTMR_CH_TCR_TEN_SHIFT)) & pTMR_CH_TCR_TEN_MASK)
/* pTMR_CH_TFR Register */
#define pTMR_CH_TFR_TIF_MASK                                   (0x1U)
#define pTMR_CH_TFR_TIF_SHIFT                                  (0U)
#define pTMR_CH_TFR_TIF(x)                                     (((uint32)(((uint32)(x)) << pTMR_CH_TFR_TIF_SHIFT)) & pTMR_CH_TFR_TIF_MASK)



/**
 * @}
 */ /* end of group pTMR_Register_Masks */


/**
 * @}
 */ /* end of group pTMR_Peripheral_Access_Layer */

#endif /* PSIP_PTMR_H */

