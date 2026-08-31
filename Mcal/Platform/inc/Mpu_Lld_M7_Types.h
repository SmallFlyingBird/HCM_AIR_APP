/**
 * @file    Mpu_Lld_M7_Types.h
 * @version V2.3.0
 *
 * @brief   YUNTU Mpu_Lld_M7 module interface
 * @details API implementation for Mpu_Lld_M7 driver
 *
 * @addtogroup MPU_LLD_M7_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Cortex M7 MPU
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

#ifndef MPU_LLD_M7_TYPES_H
#define MPU_LLD_M7_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#if defined (CPU_YTM32B1HA0)
#include "YTM32B1Hx_CM7_DSP_FP.h"
#else
#error "The core is not CM7!"
#endif

/*==================================================================================================
 *                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define MPU_LLD_M7_TYPES_VENDOR_ID                      (180)
#define MPU_LLD_M7_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define MPU_LLD_M7_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define MPU_LLD_M7_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define MPU_LLD_M7_TYPES_SW_MAJOR_VERSION               (2)
#define MPU_LLD_M7_TYPES_SW_MINOR_VERSION               (3)
#define MPU_LLD_M7_TYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define MPU_LLD_M7_XN_SHIFT         (4U)
#define MPU_LLD_M7_XN_MASK          (0x10U)
#define MPU_LLD_M7_XN(x)            (((x) & MPU_LLD_M7_XN_MASK) >> MPU_LLD_M7_XN_SHIFT)
#define MPU_LLD_M7_AP_SHIFT         (0U)
#define MPU_LLD_M7_AP_MASK          (0x7U)
#define MPU_LLD_M7_AP(x)            (((x) & MPU_LLD_M7_AP_MASK) >> MPU_LLD_M7_AP_SHIFT)
#define MPU_LLD_M7_TEX_SHIFT        (3U)
#define MPU_LLD_M7_TEX_MASK         (0x38U)
#define MPU_LLD_M7_TEX(x)           (((x) & MPU_LLD_M7_TEX_MASK) >> MPU_LLD_M7_TEX_SHIFT)
#define MPU_LLD_M7_S_SHIFT          (2U)
#define MPU_LLD_M7_S_MASK           (0x4U)
#define MPU_LLD_M7_S(x)             (((x) & MPU_LLD_M7_S_MASK) >> MPU_LLD_M7_S_SHIFT)
#define MPU_LLD_M7_C_SHIFT          (1U)
#define MPU_LLD_M7_C_MASK           (0x2U)
#define MPU_LLD_M7_C(x)             (((x) & MPU_LLD_M7_C_MASK) >> MPU_LLD_M7_C_SHIFT)
#define MPU_LLD_M7_B_SHIFT          (0U)
#define MPU_LLD_M7_B_MASK           (0x1U)
#define MPU_LLD_M7_B(x)             (((x) & MPU_LLD_M7_B_MASK) >> MPU_LLD_M7_B_SHIFT)
#define MPU_LLD_M7_SRD_SHIFT        (0U)
#define MPU_LLD_M7_SRD_MASK         (0xFFU)
#define MPU_LLD_M7_SRD(x)           (((x) & MPU_LLD_M7_SRD_MASK) >> MPU_LLD_M7_SRD_SHIFT)
#define MPU_LLD_M7_SIZE_SHIFT       (0U)
#define MPU_LLD_M7_SIZE_MASK        (0x1FU)
#define MPU_LLD_M7_SIZE(x)          (((x) & MPU_LLD_M7_SIZE_MASK) >> MPU_LLD_M7_SIZE_SHIFT)
#define MPU_LLD_M7_C_INNER_SHIFT    (2U)

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
* @brief    Enumeration listing the outer and inner cache policies when RASR[TEX] == 0x1XX
*/
typedef enum
{
    MPU_M7_CACHE_POLICY_NO_CACHE                = 0UL,  /**< Non-cacheable */
    MPU_M7_CACHE_POLICY_W_BACK_WR_ALLOCATE      = 1UL,  /**< Write-back, write and read allocate */
    MPU_M7_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE = 2UL,  /**< Write-through, no write allocate */
    MPU_M7_CACHE_POLICY_W_BACK_NO_W_ALLOCATE    = 3UL   /**< Write-back, no write allocate */
} Mpu_Lld_M7_CachePolicyType;

/**
 * @brief   Enumeration listing access permissions.
 */
typedef enum
{
    /* Format: X_R_AP
     * X  = 1 bit : Execute Allow or not
     * R  = 1 bit : Reserved
     * AP = 3 bit : Define Privileged & Unprivileged Access Right
     */
    MPU_M7_PRIV_UNPRIV_NONE     = 0x00U,    /**< 0b00000000 : ---|--- */
    MPU_M7_PRIV_RW_UNPRIV_NONE  = 0x01U,    /**< 0b00000001 : rw-|--- */
    MPU_M7_PRIV_RWX_UNPRIV_NONE = 0x11U,    /**< 0b00010001 : rwx|--- */
    MPU_M7_PRIV_RW_UNPRIV_R     = 0x02U,    /**< 0b00000010 : rw-|r-- */
    MPU_M7_PRIV_RWX_UNPRIV_RX   = 0x12U,    /**< 0b00010010 : rwx|r-x */
    MPU_M7_PRIV_RW_UNPRIV_RW    = 0x03U,    /**< 0b00000011 : rw-|rw- */
    MPU_M7_PRIV_RWX_UNPRIV_RWX  = 0x13U,    /**< 0b00010011 : rwx|rwx */
    MPU_M7_PRIV_R_UNPRIV_NONE   = 0x05U,    /**< 0b00000101 : r--|--- */
    MPU_M7_PRIV_RX_UNPRIV_NONE  = 0x15U,    /**< 0b00010101 : r-x|--- */
    MPU_M7_PRIV_R_UNPRIV_R      = 0x06U,    /**< 0b00000110 : r--|r-- */
    MPU_M7_PRIV_RX_UNPRIV_RX    = 0x16U     /**< 0b00010110 : r-x|r-x */
} Mpu_Lld_M7_AccessRightsType;

/**
* @brief    Enumeration listing the memory and cache attributes when RASR[TEX] == 0x0XX
*/
typedef enum
{
    /* Format: TEX_S_C_B
     * TEX  = 3 bit : Type extension field
     * S    = 1 bit : Shareable
     * C    = 1 bit : Cacheable
     * B    = 1 bit : Bufferable
     */
    MPU_M7_MEM_STRONG_ORDER         = 0x00U,    /**< 0b00000000,  MPU_M7_MEMORY_TYPE_STRONG_ORDER  */
    MPU_M7_MEM_DEVICE_SHARED        = 0x01U,    /**< 0b00000001,  MPU_M7_MEMORY_TYPE_DEVICE_SHARED */
    MPU_M7_MEM_NORMAL_IO_WR_THROUGH = 0x02U,    /**< 0b00000010,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_THROUGH */
    MPU_M7_MEM_NORMAL_IO_WR_BACK1   = 0x03U,    /**< 0b00000011,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_BACK1 */
    MPU_M7_MEM_NORMAL_IO_NO_CACHE   = 0x08U,    /**< 0b00001000,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_NO_CACHE */
    MPU_M7_MEM_NORMAL_IO_WR_BACK2   = 0x0BU,    /**< 0b00001011,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_BACK2 */
    MPU_M7_MEM_DEVICE_NOSHARE       = 0x10U,    /**< 0b00010000,  MPU_M7_MEMORY_TYPE_DEVICE_NOSHARE */
    MPU_M7_MEM_NORMAL_CACHEABLE     = 0x20U     /**< 0b00100000   MPU_M7_MEMORY_TYPE_NORMAL_CACHEABLE */
} Mpu_Lld_M7_MemoryType;

/*==================================================================================================
 *                                    STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief   Configuration structure for MPU regions.
 */
typedef struct
{
    uint8 RegionIndex;
    ARM_MPU_Region_t Region;
} Mpu_Lld_M7_RegionCfgType;

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
    /** @brief Number of MPU regions */
    uint8 RegionCount;
    /** @brief Configuration for MPU regions */
    const Mpu_Lld_M7_RegionCfgType *RegionConfig;
} Mpu_Lld_M7_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* MPU_LLD_M7_TYPES_H */

