/**
*   @file    pSIP_Ipc.h
*   @version
*
*   @brief   AUTOSAR Ipc register map
*   @details Register map for IPC
*
*   @addtogroup IPC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Ipc
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

#ifndef PSIP_IPC_H
#define PSIP_IPC_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              IPC REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup IPC_Peripheral_Access_Layer IPC Peripheral Access Layer
 * @{
 */


/** IPC - Size of Registers Arrays */
#define IPC_CTRL_COUNT           (128)

/* IPC Register Layout Typedef */
typedef struct {
    uint32 CTRL[128];                           /**< Control Register, offset: 0x0000 */

} IPC_Type, *IPC_MemMapPtr;

/** Number of instances of the IPC module. */
#define IPC_INSTANCE_COUNT                        (1u)

/* IPC base address */
#define IPC_BASE_ADDR32                                   (0x4007D000U)
#define IPC                                               ((volatile IPC_Type *)(IPC_BASE_ADDR32))

/** Array initializer of IPC peripheral base addresses */
#define IPC_BASE_ADDRS                                     { IPC_BASE_ADDR32 }
/** Array initializer of IPC peripheral base pointers */
#define IPC_BASE_PTRS                                      { IPC }

#define IPC_CTRL_OFFSET32(x)                               (0x0000U + ((x) * (4U)))     /**< Offset for Control Register */


/**
 * @addtogroup IPC Register Mask
 * @{
 */
/* IPC_CTRL Register */
#define IPC_CTRL_DIV_WIDTH                                 (4)
#define IPC_CTRL_DIV_MASK                                  (0xF0000U)
#define IPC_CTRL_DIV_SHIFT                                 (16U)
#define IPC_CTRL_DIV(x)                                    (((uint32)(((uint32)(x)) << IPC_CTRL_DIV_SHIFT)) & IPC_CTRL_DIV_MASK)
#define IPC_CTRL_SRCSEL_WIDTH                              (3)
#define IPC_CTRL_SRCSEL_MASK                               (0x700U)
#define IPC_CTRL_SRCSEL_SHIFT                              (8U)
#define IPC_CTRL_SRCSEL(x)                                 (((uint32)(((uint32)(x)) << IPC_CTRL_SRCSEL_SHIFT)) & IPC_CTRL_SRCSEL_MASK)
#define IPC_CTRL_SWREN_MASK                                (0x2U)
#define IPC_CTRL_SWREN_SHIFT                               (1U)
#define IPC_CTRL_SWREN(x)                                  (((uint32)(((uint32)(x)) << IPC_CTRL_SWREN_SHIFT)) & IPC_CTRL_SWREN_MASK)
#define IPC_CTRL_CLKEN_MASK                                (0x1U)
#define IPC_CTRL_CLKEN_SHIFT                               (0U)
#define IPC_CTRL_CLKEN(x)                                  (((uint32)(((uint32)(x)) << IPC_CTRL_CLKEN_SHIFT)) & IPC_CTRL_CLKEN_MASK)


/**
 * @}
 */ /* end of group IPC_Register_Masks */


/**
 * @}
 */ /* end of group IPC_Peripheral_Access_Layer */

#endif /* PSIP_IPC_H */

