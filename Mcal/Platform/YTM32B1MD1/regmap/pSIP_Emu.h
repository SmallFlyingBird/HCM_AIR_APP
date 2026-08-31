/**
*   @file    pSIP_Emu.h
*   @version
*
*   @brief   AUTOSAR Emu register map
*   @details Register map for EMU
*
*   @addtogroup EMU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Emu
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

#ifndef PSIP_EMU_H
#define PSIP_EMU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              EMU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup EMU_Peripheral_Access_Layer EMU Peripheral Access Layer
 * @{
 */


/** EMU - Size of Registers Arrays */
#define EMU_EICHD_COUNT           (2)
#define EMU_ERINFO_COUNT           (2)

/* EMU Register Layout Typedef */
typedef struct {
    uint32 EIGCR;                              /**< Error Injection Global Control Register, offset: 0x0000 */
    uint32 EICHCR;                             /**< Error Injection Channel Control Register, offset: 0x0004 */
    uint32 RESERVED0[ 2];                      /**< RESERVED0, offset: 0x0008 */
    struct {
        uint32 ADDR;                               /**< Channel Error Injection Address Register, offset: 0x0010 */
        uint32 CHKBIT;                             /**< Error Injection CheckBit Mask Register, offset: 0x0014 */
        uint32 DATA;                               /**< Error Injection DATA Mask Register, offset: 0x0018 */
        uint32 RESERVED1;                          /**< RESERVED1, offset: 0x001C */

    } EICHD[2];
    uint32 RESERVED2[52];                      /**< RESERVED2, offset: 0x0030 */
    uint32 ERIE;                               /**< Error Report Interrupt Enable Register, offset: 0x0100 */
    uint32 ERIF;                               /**< Error Report Interrupt Flag Register, offset: 0x0104 */
    uint32 RESERVED3[ 2];                      /**< RESERVED3, offset: 0x0108 */
    struct {
        uint32 ADDR;                               /**< Error Report Address Register, offset: 0x0110 */
        uint32 SYND;                               /**< Error Report Syndrome Register, offset: 0x0114 */
        uint32 CNT;                                /**< Correctable Error Count Register, offset: 0x0118 */
        uint32 RESERVED4;                          /**< RESERVED4, offset: 0x011C */

    } ERINFO[2];

} EMU_Type, *EMU_MemMapPtr;

/** Number of instances of the EMU module. */
#define EMU_INSTANCE_COUNT                        (1u)

/* EMU base address */
#define EMU_BASE_ADDR32                                   (0x40072000U)
#define EMU                                               ((volatile EMU_Type *)(EMU_BASE_ADDR32))

/** Array initializer of EMU peripheral base addresses */
#define EMU_BASE_ADDRS                                     { EMU_BASE_ADDR32 }
/** Array initializer of EMU peripheral base pointers */
#define EMU_BASE_PTRS                                      { EMU }

#define EMU_EIGCR_OFFSET32                                 (0x0000U)                    /**< Offset for Error Injection Global Control Register */
#define EMU_EICHCR_OFFSET32                                (0x0004U)                    /**< Offset for Error Injection Channel Control Register */
#define EMU_EICHD_OFFSET32(x)                              (0x0010U + ((x) * (16U)))    /**< Offset for Channel Error Injection descriptor Register Array */

#define EMU_EICHD_ADDR_OFFSET32(x)                         (0x0010U + ((x) * (16U)))    /**< Offset for Channel Error Injection Address Register */
#define EMU_EICHD_CHKBIT_OFFSET32(x)                       (0x0014U + ((x) * (16U)))    /**< Offset for Error Injection CheckBit Mask Register */
#define EMU_EICHD_DATA_OFFSET32(x)                         (0x0018U + ((x) * (16U)))    /**< Offset for Error Injection DATA Mask Register */

#define EMU_ERIE_OFFSET32                                  (0x0100U)                    /**< Offset for Error Report Interrupt Enable Register */
#define EMU_ERIF_OFFSET32                                  (0x0104U)                    /**< Offset for Error Report Interrupt Flag Register */
#define EMU_ERINFO_OFFSET32(x)                             (0x0110U + ((x) * (16U)))    /**< Offset for Error Report Information */

#define EMU_ERINFO_ADDR_OFFSET32(x)                        (0x0110U + ((x) * (16U)))    /**< Offset for Error Report Address Register */
#define EMU_ERINFO_SYND_OFFSET32(x)                        (0x0114U + ((x) * (16U)))    /**< Offset for Error Report Syndrome Register */
#define EMU_ERINFO_CNT_OFFSET32(x)                         (0x0118U + ((x) * (16U)))    /**< Offset for Correctable Error Count Register */



/**
 * @addtogroup EMU Register Mask
 * @{
 */
/* EMU_EIGCR Register */
#define EMU_EIGCR_GEN_MASK                                 (0x1U)
#define EMU_EIGCR_GEN_SHIFT                                (0U)
#define EMU_EIGCR_GEN(x)                                   (((uint32)(((uint32)(x)) << EMU_EIGCR_GEN_SHIFT)) & EMU_EIGCR_GEN_MASK)
/* EMU_EICHCR Register */
#define EMU_EICHCR_CH1EN_MASK                              (0x2U)
#define EMU_EICHCR_CH1EN_SHIFT                             (1U)
#define EMU_EICHCR_CH1EN(x)                                (((uint32)(((uint32)(x)) << EMU_EICHCR_CH1EN_SHIFT)) & EMU_EICHCR_CH1EN_MASK)
#define EMU_EICHCR_CH0EN_MASK                              (0x1U)
#define EMU_EICHCR_CH0EN_SHIFT                             (0U)
#define EMU_EICHCR_CH0EN(x)                                (((uint32)(((uint32)(x)) << EMU_EICHCR_CH0EN_SHIFT)) & EMU_EICHCR_CH0EN_MASK)
/* EMU_EICHD_ADDR Register */
#define EMU_EICHD_ADDR_ADDR_MASK                                 (0xFFFFFFFFU)
#define EMU_EICHD_ADDR_ADDR_SHIFT                                (0U)
#define EMU_EICHD_ADDR_ADDR(x)                                   (((uint32)(((uint32)(x)) << EMU_EICHD_ADDR_ADDR_SHIFT)) & EMU_EICHD_ADDR_ADDR_MASK)
/* EMU_EICHD_CHKBIT Register */
#define EMU_EICHD_CHKBIT_CHKBIT_MASK                             (0x7FU)
#define EMU_EICHD_CHKBIT_CHKBIT_SHIFT                            (0U)
#define EMU_EICHD_CHKBIT_CHKBIT(x)                               (((uint32)(((uint32)(x)) << EMU_EICHD_CHKBIT_CHKBIT_SHIFT)) & EMU_EICHD_CHKBIT_CHKBIT_MASK)
/* EMU_EICHD_DATA Register */
#define EMU_EICHD_DATA_DATA_MASK                                 (0xFFFFFFFFU)
#define EMU_EICHD_DATA_DATA_SHIFT                                (0U)
#define EMU_EICHD_DATA_DATA(x)                                   (((uint32)(((uint32)(x)) << EMU_EICHD_DATA_DATA_SHIFT)) & EMU_EICHD_DATA_DATA_MASK)

/* EMU_ERIE Register */
#define EMU_ERIE_NCIE_WIDTH                                (2)
#define EMU_ERIE_NCIE_MASK                                 (0x30000U)
#define EMU_ERIE_NCIE_SHIFT                                (16U)
#define EMU_ERIE_NCIE(x)                                   (((uint32)(((uint32)(x)) << EMU_ERIE_NCIE_SHIFT)) & EMU_ERIE_NCIE_MASK)
#define EMU_ERIE_SCIE_WIDTH                                (2)
#define EMU_ERIE_SCIE_MASK                                 (0x3U)
#define EMU_ERIE_SCIE_SHIFT                                (0U)
#define EMU_ERIE_SCIE(x)                                   (((uint32)(((uint32)(x)) << EMU_ERIE_SCIE_SHIFT)) & EMU_ERIE_SCIE_MASK)
/* EMU_ERIF Register */
#define EMU_ERIF_NCIF_WIDTH                                (2)
#define EMU_ERIF_NCIF_MASK                                 (0x30000U)
#define EMU_ERIF_NCIF_SHIFT                                (16U)
#define EMU_ERIF_NCIF(x)                                   (((uint32)(((uint32)(x)) << EMU_ERIF_NCIF_SHIFT)) & EMU_ERIF_NCIF_MASK)
#define EMU_ERIF_SCIF_WIDTH                                (2)
#define EMU_ERIF_SCIF_MASK                                 (0x3U)
#define EMU_ERIF_SCIF_SHIFT                                (0U)
#define EMU_ERIF_SCIF(x)                                   (((uint32)(((uint32)(x)) << EMU_ERIF_SCIF_SHIFT)) & EMU_ERIF_SCIF_MASK)
/* EMU_ERINFO_ADDR Register */
#define EMU_ERINFO_ADDR_ADDR_MASK                                 (0xFFFFFFFFU)
#define EMU_ERINFO_ADDR_ADDR_SHIFT                                (0U)
#define EMU_ERINFO_ADDR_ADDR(x)                                   (((uint32)(((uint32)(x)) << EMU_ERINFO_ADDR_ADDR_SHIFT)) & EMU_ERINFO_ADDR_ADDR_MASK)
/* EMU_ERINFO_SYND Register */
#define EMU_ERINFO_SYND_SYNDROME_MASK                             (0x7FU)
#define EMU_ERINFO_SYND_SYNDROME_SHIFT                            (0U)
#define EMU_ERINFO_SYND_SYNDROME(x)                               (((uint32)(((uint32)(x)) << EMU_ERINFO_SYND_SYNDROME_SHIFT)) & EMU_ERINFO_SYND_SYNDROME_MASK)
/* EMU_ERINFO_CNT Register */
#define EMU_ERINFO_CNT_CNT_MASK                                   (0xFFU)
#define EMU_ERINFO_CNT_CNT_SHIFT                                  (0U)
#define EMU_ERINFO_CNT_CNT(x)                                     (((uint32)(((uint32)(x)) << EMU_ERINFO_CNT_CNT_SHIFT)) & EMU_ERINFO_CNT_CNT_MASK)



/**
 * @}
 */ /* end of group EMU_Register_Masks */


/**
 * @}
 */ /* end of group EMU_Peripheral_Access_Layer */

#endif /* PSIP_EMU_H */

