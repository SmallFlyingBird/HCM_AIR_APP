/**
*   @file    pSIP_Efm.h
*   @version
*
*   @brief   AUTOSAR Efm register map
*   @details Register map for EFM
*
*   @addtogroup EFM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Efm
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

#ifndef PSIP_EFM_H
#define PSIP_EFM_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              EFM REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup EFM_Peripheral_Access_Layer EFM Peripheral Access Layer
 * @{
 */


/** EFM - Size of Registers Arrays */
#define EFM_NVR_DATA_COUNT           (2)
#define EFM_ADDR_PROT_COUNT           (2)

/* EFM Register Layout Typedef */
typedef struct {
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 STS;                                /**< Status Register, offset: 0x0004 */
    uint32 CMD;                                /**< Command Register, offset: 0x0008 */
    uint32 RESERVED0[ 1];                      /**< RESERVED0, offset: 0x000C */
    uint32 TIMING1;                            /**< Timing 1 Control Register, offset: 0x0010 */
    uint32 TIMING2;                            /**< Timing 2 Control Register, offset: 0x0014 */
    uint32 NVR_ADDR;                           /**< NVR Access Address, offset: 0x0018 */
    uint32 NVR_DATA[ 2];                       /**< NVR Access Data, offset: 0x001C */
    uint32 ADDR_PROT[ 2];                      /**< Address Protect, offset: 0x0024 */
    uint32 RESERVED1[ 1];                      /**< RESERVED1, offset: 0x002C */
    uint32 ERR_ADDR;                           /**< EFM Unrecovery ECC Error Address, offset: 0x0030 */
    uint32 RESERVED2[115];                      /**< RESERVED2, offset: 0x0034 */
    uint32 CMD_UNLOCK;                         /**< EFM Command Unlock, offset: 0x0200 */
    uint32 CUS_KEY;                            /**< EFM Customer Key, offset: 0x0204 */
    uint32 RESERVED3[62];                      /**< RESERVED3, offset: 0x0208 */
    uint32 CTRL_OVRD;                          /**< Override Control Register, offset: 0x0300 */
    uint32 RESERVED_16;                        /**< RESERVED_16, offset: 0x0304 */
    uint32 RESERVED_17;                        /**< RESERVED_17, offset: 0x0308 */

} EFM_Type, *EFM_MemMapPtr;

/** Number of instances of the EFM module. */
#define EFM_INSTANCE_COUNT                        (1u)

/* EFM base address */
#define EFM_BASE_ADDR32                                   (0x40010000U)
#define EFM                                               ((volatile EFM_Type *)(EFM_BASE_ADDR32))

/** Array initializer of EFM peripheral base addresses */
#define EFM_BASE_ADDRS                                     { EFM_BASE_ADDR32 }
/** Array initializer of EFM peripheral base pointers */
#define EFM_BASE_PTRS                                      { EFM }

#define EFM_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define EFM_STS_OFFSET32                                   (0x0004U)                    /**< Offset for Status Register */
#define EFM_CMD_OFFSET32                                   (0x0008U)                    /**< Offset for Command Register */
#define EFM_TIMING1_OFFSET32                               (0x0010U)                    /**< Offset for Timing 1 Control Register */
#define EFM_TIMING2_OFFSET32                               (0x0014U)                    /**< Offset for Timing 2 Control Register */
#define EFM_NVR_ADDR_OFFSET32                              (0x0018U)                    /**< Offset for NVR Access Address */
#define EFM_NVR_DATA_OFFSET32(x)                           (0x001CU + ((x) * (4U)))     /**< Offset for NVR Access Data */
#define EFM_ADDR_PROT_OFFSET32(x)                          (0x0024U + ((x) * (4U)))     /**< Offset for Address Protect */
#define EFM_ERR_ADDR_OFFSET32                              (0x0030U)                    /**< Offset for EFM Unrecovery ECC Error Address */
#define EFM_CMD_UNLOCK_OFFSET32                            (0x0200U)                    /**< Offset for EFM Command Unlock */
#define EFM_CUS_KEY_OFFSET32                               (0x0204U)                    /**< Offset for EFM Customer Key */
#define EFM_CTRL_OVRD_OFFSET32                             (0x0300U)                    /**< Offset for Override Control Register */


/**
 * @addtogroup EFM Register Mask
 * @{
 */
/* EFM_CTRL Register */
#define EFM_CTRL_DPD_EN_MASK                               (0x80000000U)
#define EFM_CTRL_DPD_EN_SHIFT                              (31U)
#define EFM_CTRL_DPD_EN(x)                                 (((uint32)(((uint32)(x)) << EFM_CTRL_DPD_EN_SHIFT)) & EFM_CTRL_DPD_EN_MASK)
#define EFM_CTRL_RETRY_CFG_MASK                            (0x70000000U)
#define EFM_CTRL_RETRY_CFG_SHIFT                           (28U)
#define EFM_CTRL_RETRY_CFG(x)                              (((uint32)(((uint32)(x)) << EFM_CTRL_RETRY_CFG_SHIFT)) & EFM_CTRL_RETRY_CFG_MASK)
#define EFM_CTRL_PRESCALER_MASK                            (0xFF0000U)
#define EFM_CTRL_PRESCALER_SHIFT                           (16U)
#define EFM_CTRL_PRESCALER(x)                              (((uint32)(((uint32)(x)) << EFM_CTRL_PRESCALER_SHIFT)) & EFM_CTRL_PRESCALER_MASK)
#define EFM_CTRL_PREFETCH_EN_MASK                          (0x8000U)
#define EFM_CTRL_PREFETCH_EN_SHIFT                         (15U)
#define EFM_CTRL_PREFETCH_EN(x)                            (((uint32)(((uint32)(x)) << EFM_CTRL_PREFETCH_EN_SHIFT)) & EFM_CTRL_PREFETCH_EN_MASK)
#define EFM_CTRL_RWS_MASK                                  (0xF00U)
#define EFM_CTRL_RWS_SHIFT                                 (8U)
#define EFM_CTRL_RWS(x)                                    (((uint32)(((uint32)(x)) << EFM_CTRL_RWS_SHIFT)) & EFM_CTRL_RWS_MASK)
#define EFM_CTRL_ACCERRIE_MASK                             (0x8U)
#define EFM_CTRL_ACCERRIE_SHIFT                            (3U)
#define EFM_CTRL_ACCERRIE(x)                               (((uint32)(((uint32)(x)) << EFM_CTRL_ACCERRIE_SHIFT)) & EFM_CTRL_ACCERRIE_MASK)
#define EFM_CTRL_UNRECOVERRIE_MASK                         (0x4U)
#define EFM_CTRL_UNRECOVERRIE_SHIFT                        (2U)
#define EFM_CTRL_UNRECOVERRIE(x)                           (((uint32)(((uint32)(x)) << EFM_CTRL_UNRECOVERRIE_SHIFT)) & EFM_CTRL_UNRECOVERRIE_MASK)
#define EFM_CTRL_RECOVERRIE_MASK                           (0x2U)
#define EFM_CTRL_RECOVERRIE_SHIFT                          (1U)
#define EFM_CTRL_RECOVERRIE(x)                             (((uint32)(((uint32)(x)) << EFM_CTRL_RECOVERRIE_SHIFT)) & EFM_CTRL_RECOVERRIE_MASK)
#define EFM_CTRL_DONEIE_MASK                               (0x1U)
#define EFM_CTRL_DONEIE_SHIFT                              (0U)
#define EFM_CTRL_DONEIE(x)                                 (((uint32)(((uint32)(x)) << EFM_CTRL_DONEIE_SHIFT)) & EFM_CTRL_DONEIE_MASK)
/* EFM_STS Register */
#define EFM_STS_BOOT_INFO_MASK                             (0x8000U)
#define EFM_STS_BOOT_INFO_SHIFT                            (15U)
#define EFM_STS_BOOT_INFO(x)                               (((uint32)(((uint32)(x)) << EFM_STS_BOOT_INFO_SHIFT)) & EFM_STS_BOOT_INFO_MASK)
#define EFM_STS_CUS_KEY_MATCH_MASK                         (0x2000U)
#define EFM_STS_CUS_KEY_MATCH_SHIFT                        (13U)
#define EFM_STS_CUS_KEY_MATCH(x)                           (((uint32)(((uint32)(x)) << EFM_STS_CUS_KEY_MATCH_SHIFT)) & EFM_STS_CUS_KEY_MATCH_MASK)
#define EFM_STS_IDLE_MASK                                  (0x80U)
#define EFM_STS_IDLE_SHIFT                                 (7U)
#define EFM_STS_IDLE(x)                                    (((uint32)(((uint32)(x)) << EFM_STS_IDLE_SHIFT)) & EFM_STS_IDLE_MASK)
#define EFM_STS_FAIL_MASK                                  (0x40U)
#define EFM_STS_FAIL_SHIFT                                 (6U)
#define EFM_STS_FAIL(x)                                    (((uint32)(((uint32)(x)) << EFM_STS_FAIL_SHIFT)) & EFM_STS_FAIL_MASK)
#define EFM_STS_ACCERR_MASK                                (0x8U)
#define EFM_STS_ACCERR_SHIFT                               (3U)
#define EFM_STS_ACCERR(x)                                  (((uint32)(((uint32)(x)) << EFM_STS_ACCERR_SHIFT)) & EFM_STS_ACCERR_MASK)
#define EFM_STS_UNRECOVERR_MASK                            (0x4U)
#define EFM_STS_UNRECOVERR_SHIFT                           (2U)
#define EFM_STS_UNRECOVERR(x)                              (((uint32)(((uint32)(x)) << EFM_STS_UNRECOVERR_SHIFT)) & EFM_STS_UNRECOVERR_MASK)
#define EFM_STS_RECOVERR_MASK                              (0x2U)
#define EFM_STS_RECOVERR_SHIFT                             (1U)
#define EFM_STS_RECOVERR(x)                                (((uint32)(((uint32)(x)) << EFM_STS_RECOVERR_SHIFT)) & EFM_STS_RECOVERR_MASK)
#define EFM_STS_DONE_MASK                                  (0x1U)
#define EFM_STS_DONE_SHIFT                                 (0U)
#define EFM_STS_DONE(x)                                    (((uint32)(((uint32)(x)) << EFM_STS_DONE_SHIFT)) & EFM_STS_DONE_MASK)
/* EFM_CMD Register */
#define EFM_CMD_CMD_MASK                                   (0xFFU)
#define EFM_CMD_CMD_SHIFT                                  (0U)
#define EFM_CMD_CMD(x)                                     (((uint32)(((uint32)(x)) << EFM_CMD_CMD_SHIFT)) & EFM_CMD_CMD_MASK)
/* EFM_TIMING1 Register */
#define EFM_TIMING1_TPREPROG_MASK                          (0xFFFF0000U)
#define EFM_TIMING1_TPREPROG_SHIFT                         (16U)
#define EFM_TIMING1_TPREPROG(x)                            (((uint32)(((uint32)(x)) << EFM_TIMING1_TPREPROG_SHIFT)) & EFM_TIMING1_TPREPROG_MASK)
#define EFM_TIMING1_TPROG_MASK                             (0xFFFFU)
#define EFM_TIMING1_TPROG_SHIFT                            (0U)
#define EFM_TIMING1_TPROG(x)                               (((uint32)(((uint32)(x)) << EFM_TIMING1_TPROG_SHIFT)) & EFM_TIMING1_TPROG_MASK)
/* EFM_TIMING2 Register */
#define EFM_TIMING2_TERASE_RETRY_MASK                      (0xFFFF0000U)
#define EFM_TIMING2_TERASE_RETRY_SHIFT                     (16U)
#define EFM_TIMING2_TERASE_RETRY(x)                        (((uint32)(((uint32)(x)) << EFM_TIMING2_TERASE_RETRY_SHIFT)) & EFM_TIMING2_TERASE_RETRY_MASK)
#define EFM_TIMING2_TERASE_MASK                            (0xFFFFU)
#define EFM_TIMING2_TERASE_SHIFT                           (0U)
#define EFM_TIMING2_TERASE(x)                              (((uint32)(((uint32)(x)) << EFM_TIMING2_TERASE_SHIFT)) & EFM_TIMING2_TERASE_MASK)
/* EFM_NVR_ADDR Register */
#define EFM_NVR_ADDR_NVR_ADDR_MASK                         (0xFFFFFFFFU)
#define EFM_NVR_ADDR_NVR_ADDR_SHIFT                        (0U)
#define EFM_NVR_ADDR_NVR_ADDR(x)                           (((uint32)(((uint32)(x)) << EFM_NVR_ADDR_NVR_ADDR_SHIFT)) & EFM_NVR_ADDR_NVR_ADDR_MASK)
/* EFM_NVR_DATA Register */
#define EFM_NVR_DATA_EFM_NVR_DATA_MASK                     (0xFFFFFFFFU)
#define EFM_NVR_DATA_EFM_NVR_DATA_SHIFT                    (0U)
#define EFM_NVR_DATA_EFM_NVR_DATA(x)                       (((uint32)(((uint32)(x)) << EFM_NVR_DATA_EFM_NVR_DATA_SHIFT)) & EFM_NVR_DATA_EFM_NVR_DATA_MASK)
/* EFM_ADDR_PROT Register */
#define EFM_ADDR_PROT_ADDR_PROT_MASK                       (0xFFFFFFFFU)
#define EFM_ADDR_PROT_ADDR_PROT_SHIFT                      (0U)
#define EFM_ADDR_PROT_ADDR_PROT(x)                         (((uint32)(((uint32)(x)) << EFM_ADDR_PROT_ADDR_PROT_SHIFT)) & EFM_ADDR_PROT_ADDR_PROT_MASK)
/* EFM_ERR_ADDR Register */
#define EFM_ERR_ADDR_ECC_ERR_ADDR_MASK                     (0xFFFFFFFFU)
#define EFM_ERR_ADDR_ECC_ERR_ADDR_SHIFT                    (0U)
#define EFM_ERR_ADDR_ECC_ERR_ADDR(x)                       (((uint32)(((uint32)(x)) << EFM_ERR_ADDR_ECC_ERR_ADDR_SHIFT)) & EFM_ERR_ADDR_ECC_ERR_ADDR_MASK)
/* EFM_CMD_UNLOCK Register */
#define EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_MASK                 (0xFFFFFFFFU)
#define EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_SHIFT                (0U)
#define EFM_CMD_UNLOCK_CMD_UNLOCK_KEY(x)                   (((uint32)(((uint32)(x)) << EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_SHIFT)) & EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_MASK)
/* EFM_CUS_KEY Register */
#define EFM_CUS_KEY_CUS_KEY_MASK                           (0xFFFFFFU)
#define EFM_CUS_KEY_CUS_KEY_SHIFT                          (0U)
#define EFM_CUS_KEY_CUS_KEY(x)                             (((uint32)(((uint32)(x)) << EFM_CUS_KEY_CUS_KEY_SHIFT)) & EFM_CUS_KEY_CUS_KEY_MASK)
/* EFM_CTRL_OVRD Register */
#define EFM_CTRL_OVRD_DBG_DISABLE_MASK                     (0x2U)
#define EFM_CTRL_OVRD_DBG_DISABLE_SHIFT                    (1U)
#define EFM_CTRL_OVRD_DBG_DISABLE(x)                       (((uint32)(((uint32)(x)) << EFM_CTRL_OVRD_DBG_DISABLE_SHIFT)) & EFM_CTRL_OVRD_DBG_DISABLE_MASK)


/**
 * @}
 */ /* end of group EFM_Register_Masks */


/**
 * @}
 */ /* end of group EFM_Peripheral_Access_Layer */

#endif /* PSIP_EFM_H */

