/**
*   @file    pSIP_Pctrl.h
*   @version
*
*   @brief   AUTOSAR Pctrl register map
*   @details Register map for PCTRL
*
*   @addtogroup PCTRL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Pctrl
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

#ifndef PSIP_PCTRL_H
#define PSIP_PCTRL_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              PCTRL REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup PCTRL_Peripheral_Access_Layer PCTRL Peripheral Access Layer
 * @{
 */


/** PCTRL - Size of Registers Arrays */
#define PCTRL_PCR_COUNT           (32)

/* PCTRL Register Layout Typedef */
typedef struct {
    uint32 PCR[32];                            /**< Port Control Register, offset: 0x0000 */

} PCTRL_Type, *PCTRL_MemMapPtr;

/** Number of instances of the PCTRL module. */
#define PCTRL_INSTANCE_COUNT                        (5u)

/* PCTRLA  base address */
#define PCTRLA_BASE_ADDR32                                 (0x40012000U)
#define PCTRLA                                             ((volatile PCTRL_Type *)(PCTRLA_BASE_ADDR32))
/* PCTRLB  base address */
#define PCTRLB_BASE_ADDR32                                 (0x40013000U)
#define PCTRLB                                             ((volatile PCTRL_Type *)(PCTRLB_BASE_ADDR32))
/* PCTRLC  base address */
#define PCTRLC_BASE_ADDR32                                 (0x40014000U)
#define PCTRLC                                             ((volatile PCTRL_Type *)(PCTRLC_BASE_ADDR32))
/* PCTRLD  base address */
#define PCTRLD_BASE_ADDR32                                 (0x40015000U)
#define PCTRLD                                             ((volatile PCTRL_Type *)(PCTRLD_BASE_ADDR32))
/* PCTRLE  base address */
#define PCTRLE_BASE_ADDR32                                 (0x40016000U)
#define PCTRLE                                             ((volatile PCTRL_Type *)(PCTRLE_BASE_ADDR32))

/** Array initializer of PCTRL peripheral base addresses */
#define PCTRL_BASE_ADDRS                                   { PCTRLA_BASE_ADDR32,  PCTRLB_BASE_ADDR32,  PCTRLC_BASE_ADDR32,  PCTRLD_BASE_ADDR32,  PCTRLE_BASE_ADDR32 }
/** Array initializer of PCTRL peripheral base pointers */
#define PCTRL_BASE_PTRS                                    { PCTRLA,  PCTRLB,  PCTRLC,  PCTRLD,  PCTRLE }

#define PCTRL_PCR_OFFSET32(x)                              (0x0000U + ((x) * (4U)))     /**< Offset for Port Control Register */

#define PCTRL_BASE_ADDR32(port)                            ((uint32)0x40012000U + ((uint32)(port) * (uint32)0x00001000))
#define PCTRL_PCR_ADDR32(port, pin)                        ((uint32)(PCTRL_BASE_ADDR32(port) + PCTRL_PCR_OFFSET32(pin)))

/**
 * @addtogroup PCTRL Register Mask
 * @{
 */
/* PCTRL_PCR Register */
#define PCTRL_PCR_MUX_WIDTH                                  (3)
#define PCTRL_PCR_MUX_MASK                                   (0x700U)
#define PCTRL_PCR_MUX_SHIFT                                  (8U)
#define PCTRL_PCR_MUX(x)                                     (((uint32)(((uint32)(x)) << PCTRL_PCR_MUX_SHIFT)) & PCTRL_PCR_MUX_MASK)
#define PCTRL_PCR_DSE_MASK                                   (0x40U)
#define PCTRL_PCR_DSE_SHIFT                                  (6U)
#define PCTRL_PCR_DSE(x)                                     (((uint32)(((uint32)(x)) << PCTRL_PCR_DSE_SHIFT)) & PCTRL_PCR_DSE_MASK)
#define PCTRL_PCR_PFE_MASK                                   (0x10U)
#define PCTRL_PCR_PFE_SHIFT                                  (4U)
#define PCTRL_PCR_PFE(x)                                     (((uint32)(((uint32)(x)) << PCTRL_PCR_PFE_SHIFT)) & PCTRL_PCR_PFE_MASK)
#define PCTRL_PCR_SRE_MASK                                   (0x4U)
#define PCTRL_PCR_SRE_SHIFT                                  (2U)
#define PCTRL_PCR_SRE(x)                                     (((uint32)(((uint32)(x)) << PCTRL_PCR_SRE_SHIFT)) & PCTRL_PCR_SRE_MASK)
#define PCTRL_PCR_PE_MASK                                    (0x2U)
#define PCTRL_PCR_PE_SHIFT                                   (1U)
#define PCTRL_PCR_PE(x)                                      (((uint32)(((uint32)(x)) << PCTRL_PCR_PE_SHIFT)) & PCTRL_PCR_PE_MASK)
#define PCTRL_PCR_PS_MASK                                    (0x1U)
#define PCTRL_PCR_PS_SHIFT                                   (0U)
#define PCTRL_PCR_PS(x)                                      (((uint32)(((uint32)(x)) << PCTRL_PCR_PS_SHIFT)) & PCTRL_PCR_PS_MASK)


/**
 * @}
 */ /* end of group PCTRL_Register_Masks */


/**
 * @}
 */ /* end of group PCTRL_Peripheral_Access_Layer */

#endif /* PSIP_PCTRL_H */

