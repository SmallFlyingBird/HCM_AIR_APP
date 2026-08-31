/**
 * @file    Mpu_Lld_M33_Types.h
 * @version V2.3.0
 *
 * @brief   YUNTU Mpu_Lld_M33 module interface
 * @details API implementation for Mpu_Lld_M33 driver
 *
 * @addtogroup MPU_LLD_M33_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Cortex M33 MPU
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

#ifndef MPU_LLD_M33_TYPES_H
#define MPU_LLD_M33_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0779 EOF */
/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#if defined (CPU_YTM32B1ME0) || defined (CPU_YTM32B1MD1)
#include "YTM32B1Mx_CM33_DSP_FP.h"
#elif defined (CPU_YTM32B1MC0)
#include "YTM32B1Mx_CM33.h"
#else
#error "The core is not CM33!"
#endif

/*==================================================================================================
 *                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define MPU_LLD_M33_TYPES_VENDOR_ID                      (180)
#define MPU_LLD_M33_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define MPU_LLD_M33_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define MPU_LLD_M33_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define MPU_LLD_M33_TYPES_SW_MAJOR_VERSION               (2)
#define MPU_LLD_M33_TYPES_SW_MINOR_VERSION               (3)
#define MPU_LLD_M33_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define MPU_LLD_M33_XN_SHIFT    (0U)
#define MPU_LLD_M33_XN_MASK     (0x01U)
#define MPU_LLD_M33_XN(x)       (((x) & MPU_LLD_M33_XN_MASK) >> MPU_LLD_M33_XN_SHIFT)
#define MPU_LLD_M33_NP_SHIFT    (1U)
#define MPU_LLD_M33_NP_MASK     (0x02U)
#define MPU_LLD_M33_NP(x)       (((x) & MPU_LLD_M33_NP_MASK) >> MPU_LLD_M33_NP_SHIFT)
#define MPU_LLD_M33_RO_SHIFT    (2U)
#define MPU_LLD_M33_RO_MASK     (0x04U)
#define MPU_LLD_M33_RO(x)       (((x) & MPU_LLD_M33_RO_MASK) >> MPU_LLD_M33_RO_SHIFT)
#define MPU_LLD_M33_INNER_SHIFT (0U)
#define MPU_LLD_M33_INNER_MASK  (0x0FU)
#define MPU_LLD_M33_INNER(x)    (((x) & MPU_LLD_M33_INNER_MASK))
#define MPU_LLD_M33_OUTER_SHIFT (4U)
#define MPU_LLD_M33_OUTER_MASK  (0xF0U)
#define MPU_LLD_M33_OUTER(x)    (((x) << MPU_LLD_M33_OUTER_SHIFT) & MPU_LLD_M33_OUTER_MASK)

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief   Enumeration listing the outer and inner cache policies.
 */
typedef enum
{
    MPU_M33_CACHE_POLICY_DEVICE             = 0UL,  /**< 0b0000 : Device memory */
    MPU_M33_CACHE_POLICY_DEVICE_NGNRNE      = 0UL,  /**< 0b0000 : Device memory, non-gathering, non-reordering, non-early write acknowledgement. */
    MPU_M33_CACHE_POLICY_DEVICE_NGNRE       = 4UL,  /**< 0b0100 : Device memory, non-gathering, non-reordering, early write acknowledgement. */
    MPU_M33_CACHE_POLICY_DEVICE_NGRE        = 8UL,  /**< 0b1000 : Device memory, non-gathering, reordering, early write acknowledgement. */
    MPU_M33_CACHE_POLICY_DEVICE_GRE         = 12UL, /**< 0b1100 : Device memory, gathering, reordering, early write acknowledgement. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_T_WA     = 1UL,  /**< 0b0001 : Normal memory, Outer write-through transient, write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_T_RA     = 2UL,  /**< 0b0010 : Normal memory, Outer write-through transient, read allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_T_RWA    = 3UL,  /**< 0b0011 : Normal memory, Outer write-through transient, read and write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_NO_CACHE    = 4UL,  /**< 0b0100 : Normal memory, Outer non-cacheable. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_T_WA     = 5UL,  /**< 0b0101 : Normal memory, Outer write-back transient, write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_T_RA     = 6UL,  /**< 0b0110 : Normal memory, Outer write-back transient, read allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_T_RWA    = 7UL,  /**< 0b0111 : Normal memory, Outer write-back transient, read and write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_NT       = 8UL,  /**< 0b1000 : Normal memory, Outer write-through non-transient. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_NT_WA    = 9UL,  /**< 0b1001 : Normal memory, Outer write-through non-transient, write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_NT_RA    = 10UL, /**< 0b1010 : Normal memory, Outer write-through non-transient, read allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WT_NT_RWA   = 11UL, /**< 0b1011 : Normal memory, Outer write-through non-transient, read and write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_NT       = 12UL, /**< 0b1100 : Normal memory, Outer write-back non-transient. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_NT_WA    = 13UL, /**< 0b1101 : Normal memory, Outer write-back non-transient, write allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_NT_RA    = 14UL, /**< 0b1110 : Normal memory, Outer write-back non-transient, read allocation. */
    MPU_M33_CACHE_POLICY_NORMAL_WB_NT_RWA   = 15UL, /**< 0b1111 : Normal memory, Outer write-back non-transient, read and write allocation. */
} Mpu_Lld_M33_CachePolicyType;

/**
 * @brief   Enumeration listing the shareability domain of this region for Normal memory.
 */
typedef enum
{
    MPU_M33_MEM_NORMAL_NOSHARE      = 0x00U,    /**< 0b00U : Non-shareable. */
    MPU_M33_MEM_NORMAL_OUTER_SHARE  = 0x02U,    /**< 0b10U : Outer shareable. */
    MPU_M33_MEM_NORMAL_INNER_SHARE  = 0x03U     /**< 0b11U : Inner shareable. */
} Mpu_Lld_M33_ShareType;

/**
 * @brief   Enumeration listing access permissions.
 */
typedef enum
{
    /* Format: AP_XN
     * AP = 2 bit : Define Privileged & Unprivileged Access Right
     * XN = 1 bit : Execute Allow or not
     */
    MPU_M33_PRIV_RW_UNPRIV_NONE     = 0x01U,    /**< 0b001U : rw-|--- */
    MPU_M33_PRIV_RWX_UNPRIV_NONE    = 0x00U,    /**< 0b000U : rwx|--- */
    MPU_M33_PRIV_RW_UNPRIV_RW       = 0x03U,    /**< 0b011U : rw-|rw- */
    MPU_M33_PRIV_RWX_UNPRIV_RWX     = 0x02U,    /**< 0b010U : rwx|rwx */
    MPU_M33_PRIV_R_UNPRIV_NONE      = 0x05U,    /**< 0b101U : r--|--- */
    MPU_M33_PRIV_RX_UNPRIV_NONE     = 0x04U,    /**< 0b100U : r-x|--- */
    MPU_M33_PRIV_R_UNPRIV_R         = 0x07U,    /**< 0b111U : r--|r-- */
    MPU_M33_PRIV_RX_UNPRIV_RX       = 0x06U     /**< 0b110U : r-x|r-x */
} Mpu_Lld_M33_AccessRightsType;

/*==================================================================================================
 *                                    STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief   Configuration structure for MPU Attributes.
 */
typedef struct
{
    uint8 AttributeIndex;
    uint8 Attribute;
} Mpu_Lld_M33_AttrCfgType;

/**
 * @brief   Configuration structure for MPU regions.
 */
typedef struct
{
    uint8 RegionIndex;
    ARM_MPU_Region_t Region;
} Mpu_Lld_M33_RegionCfgType;

/**
 * @brief   Configuration structure for MPU settings.
 */
typedef struct
{
    /** @brief Enables the default memory map background region */
    boolean DefaultMapEn;
    /** @brief Enables use of the MPU when in the hard fault, non-maskable interrupt, and FAULTMASK escalated handlers  */
    boolean RunHFNMIEn;
    /** @brief Enable Memory Manage Fault Exception Handler */
    boolean MemManageIrqEn;
    /** @brief Number of MPU attributes */
    uint8 AttributeCount;
    /** @brief Configuration for MPU attributes */
    const Mpu_Lld_M33_AttrCfgType *AttributeConfig;
    /** @brief Number of MPU regions */
    uint8 RegionCount;
    /** @brief Configuration for MPU regions */
    const Mpu_Lld_M33_RegionCfgType *RegionConfig;
} Mpu_Lld_M33_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* MPU_LLD_M33_TYPES_H */

