/**
*   @file    pSIP_Wku.h
*   @version
*
*   @brief   AUTOSAR Wku register map
*   @details Register map for WKU
*
*   @addtogroup WKU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Wku
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

#ifndef PSIP_WKU_H
#define PSIP_WKU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              WKU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup WKU_Peripheral_Access_Layer WKU Peripheral Access Layer
 * @{
 */


/** WKU - Size of Registers Arrays */
#define WKU_PCR_COUNT           (32)
#define WKU_PFR_COUNT           (1)

/* WKU Register Layout Typedef */
typedef struct {
    uint8 PCR[16];                            /**< Pin Control Register, offset: 0x0000 */
    uint32 RESERVED0[ 4];                      /**< RESERVED0, offset: 0x0010 */
    uint32 PFR[ 1];                            /**< Pin Flag Register, offset: 0x0020 */
    uint32 RPCR;                               /**< Reset Pin Control Register, offset: 0x0024 */
    uint32 MER;                                /**< Module Enable Register, offset: 0x0028 */

} WKU_Type, *WKU_MemMapPtr;

/** Number of instances of the WKU module. */
#define WKU_INSTANCE_COUNT                        (1u)

/* WKU base address */
#define WKU_BASE_ADDR32                                   (0x40062000U)
#define WKU                                               ((volatile WKU_Type *)(WKU_BASE_ADDR32))

/** Array initializer of WKU peripheral base addresses */
#define WKU_BASE_ADDRS                                     { WKU_BASE_ADDR32 }
/** Array initializer of WKU peripheral base pointers */
#define WKU_BASE_PTRS                                      { WKU }

#define WKU_PCR_OFFSET8(x)                                (0x0000U + ((x) * (1U)))     /**< Offset for Pin Control Register */
#define WKU_PFR_OFFSET32(x)                                (0x0020U + ((x) * (4U)))     /**< Offset for Pin Flag Register */
#define WKU_RPCR_OFFSET32                                  (0x0024U)                    /**< Offset for Reset Pin Control Register */
#define WKU_MER_OFFSET32                                   (0x0028U)                    /**< Offset for Module Enable Register */


/**
 * @addtogroup WKU Register Mask
 * @{
 */
/* WKU_PCR Register */
#define WKU_PCR_WUPIE_MASK                                 (0x10U)
#define WKU_PCR_WUPIE_SHIFT                                (4U)
#define WKU_PCR_WUPIE(x)                                   (((uint32)(((uint32)(x)) << WKU_PCR_WUPIE_SHIFT)) & WKU_PCR_WUPIE_MASK)
#define WKU_PCR_WUPFE_MASK                                 (0x4U)
#define WKU_PCR_WUPFE_SHIFT                                (2U)
#define WKU_PCR_WUPFE(x)                                   (((uint32)(((uint32)(x)) << WKU_PCR_WUPFE_SHIFT)) & WKU_PCR_WUPFE_MASK)
#define WKU_PCR_WUPE_MASK                                  (0x3U)
#define WKU_PCR_WUPE_SHIFT                                 (0U)
#define WKU_PCR_WUPE(x)                                    (((uint32)(((uint32)(x)) << WKU_PCR_WUPE_SHIFT)) & WKU_PCR_WUPE_MASK)
/* WKU_PFR Register */
#define WKU_PFR_WUF_WIDTH                                  (32)
#define WKU_PFR_WUF_MASK                                   (0xFFFFFFFFU)
#define WKU_PFR_WUF_SHIFT                                  (0U)
#define WKU_PFR_WUF(x)                                     (((uint32)(((uint32)(x)) << WKU_PFR_WUF_SHIFT)) & WKU_PFR_WUF_MASK)
/* WKU_RPCR Register */
#define WKU_RPCR_WURPFE_MASK                               (0x4U)
#define WKU_RPCR_WURPFE_SHIFT                              (2U)
#define WKU_RPCR_WURPFE(x)                                 (((uint32)(((uint32)(x)) << WKU_RPCR_WURPFE_SHIFT)) & WKU_RPCR_WURPFE_MASK)
#define WKU_RPCR_WURPE_MASK                                (0x1U)
#define WKU_RPCR_WURPE_SHIFT                               (0U)
#define WKU_RPCR_WURPE(x)                                  (((uint32)(((uint32)(x)) << WKU_RPCR_WURPE_SHIFT)) & WKU_RPCR_WURPE_MASK)
/* WKU_MER Register */
#define WKU_MER_WUME_WIDTH                                 (4)
#define WKU_MER_WUME_MASK                                  (0xFU)
#define WKU_MER_WUME_SHIFT                                 (0U)
#define WKU_MER_WUME(x)                                    (((uint32)(((uint32)(x)) << WKU_MER_WUME_SHIFT)) & WKU_MER_WUME_MASK)


/**
 * @}
 */ /* end of group WKU_Register_Masks */


/**
 * @}
 */ /* end of group WKU_Peripheral_Access_Layer */

#endif /* PSIP_WKU_H */

