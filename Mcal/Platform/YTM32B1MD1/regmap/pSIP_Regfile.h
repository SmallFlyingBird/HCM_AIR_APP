/**
*   @file    pSIP_Regfile.h
*   @version
*
*   @brief   AUTOSAR Regfile register map
*   @details Register map for REGFILE
*
*   @addtogroup REGFILE_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Regfile
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

#ifndef PSIP_REGFILE_H
#define PSIP_REGFILE_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              REGFILE REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup REGFILE_Peripheral_Access_Layer REGFILE Peripheral Access Layer
 * @{
 */


/** REGFILE - Size of Registers Arrays */
#define REGFILE_DR_COUNT           (8)

/* REGFILE Register Layout Typedef */
typedef struct {
    uint32 DR[ 8];                             /**< DATA Register, offset: 0x0000 */

} REGFILE_Type, *REGFILE_MemMapPtr;

/** Number of instances of the REGFILE module. */
#define REGFILE_INSTANCE_COUNT                        (1u)

/* REGFILE base address */
#define REGFILE_BASE_ADDR32                               (0x40061000U)
#define REGFILE                                           ((volatile REGFILE_Type *)(REGFILE_BASE_ADDR32))

/** Array initializer of REGFILE peripheral base addresses */
#define REGFILE_BASE_ADDRS                                 { REGFILE_BASE_ADDR32 }
/** Array initializer of REGFILE peripheral base pointers */
#define REGFILE_BASE_PTRS                                  { REGFILE }

#define REGFILE_DR_OFFSET32(x)                             (0x0000U + ((x) * (4U)))     /**< Offset for DATA Register */


/**
 * @addtogroup REGFILE Register Mask
 * @{
 */
/* REGFILE_DR Register */
#define REGFILE_DR_DATA_MASK                                   (0xFFFFFFFFU)
#define REGFILE_DR_DATA_SHIFT                                  (0U)
#define REGFILE_DR_DATA(x)                                     (((uint32)(((uint32)(x)) << REGFILE_DR_DATA_SHIFT)) & REGFILE_DR_DATA_MASK)


/**
 * @}
 */ /* end of group REGFILE_Register_Masks */


/**
 * @}
 */ /* end of group REGFILE_Peripheral_Access_Layer */

#endif /* PSIP_REGFILE_H */

