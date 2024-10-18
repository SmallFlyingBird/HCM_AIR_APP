/**************************************************************************************************/
/**
 * @file      : Mpu_Types.h
 * @brief     : System memory protect unit types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MPU_TYPES_H
#define MPU_TYPES_H

/** @addtogroup  Mpu_Module
 *  @{
 */

/** @addtogroup  Mpu
 *  @brief Mpu Types
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Mpu_Cfg.h"
#include "Smpu_Drv_Types.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MPU_TYPES_H_VENDOR_ID                   0x00B3U
#define MPU_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define MPU_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define MPU_TYPES_H_SW_MAJOR_VERSION            1U
#define MPU_TYPES_H_SW_MINOR_VERSION            1U
#define MPU_TYPES_H_SW_PATCH_VERSION            0U
/**
 *  @brief Check if current file and Smpu_Drv_Types.h are of the same vendor
 */
#if (MPU_TYPES_H_VENDOR_ID != SMPU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mpu_Types.h and Smpu_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv_Types.h are of the same Autosar version
 */
#if ((MPU_TYPES_H_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (MPU_TYPES_H_AR_RELEASE_MINOR_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (MPU_TYPES_H_AR_RELEASE_REVISION_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu_Types.h and Smpu_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv_Types.h are of the same SW version
 */
#if ((MPU_TYPES_H_SW_MAJOR_VERSION != SMPU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (MPU_TYPES_H_SW_MINOR_VERSION != SMPU_DRV_TYPES_H_SW_MINOR_VERSION) ||                        \
     (MPU_TYPES_H_SW_PATCH_VERSION != SMPU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mpu_Types.h and Smpu_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Cfg.h are of the same vendor
 */
#if (MPU_TYPES_H_VENDOR_ID != MPU_CFG_H_VENDOR_ID)
    #error "Vendor ID of Mpu_Types.h and Mpu_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Cfg.h are of the same Autosar version
 */
#if ((MPU_TYPES_H_AR_RELEASE_MAJOR_VERSION != MPU_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MPU_TYPES_H_AR_RELEASE_MINOR_VERSION != MPU_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MPU_TYPES_H_AR_RELEASE_REVISION_VERSION != MPU_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu_Types.h and Mpu_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Cfg.h are of the same SW version
 */
#if ((MPU_TYPES_H_SW_MAJOR_VERSION != MPU_CFG_H_SW_MAJOR_VERSION) ||                               \
     (MPU_TYPES_H_SW_MINOR_VERSION != MPU_CFG_H_SW_MINOR_VERSION) ||                               \
     (MPU_TYPES_H_SW_PATCH_VERSION != MPU_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mpu_Types.h and Mpu_Cfg.h are different"
#endif

/** @} end of group Private_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief SMPU slave port type definition
 */
typedef enum
{
    MPU_SLV_PORT_0 = 0U, /*!< Slave port 0,indicate flash  */
    MPU_SLV_PORT_1,      /*!< Slave port 1,indicate sraml  */
    MPU_SLV_PORT_2,      /*!< Slave port 2,indicate sramu  */
} Mpu_SlavePortType;

typedef Smpu_Drv_SalveErrorType Mpu_SalveErrorType;

typedef Smpu_Drv_RegionConfigType Mpu_RegionConfigType;

/**
 *  @brief Error callback function type
 */
typedef void(*Mpu_ErrCallBackFunType)(const uint8              SlavePort,
                                     const Mpu_SalveErrorType *ErrorTypePtr);

/**
 *  @brief MPU init configure struct definition
 */
typedef struct
{
    boolean               GlobalMpuControlState;
    uint8                 RegionConfigNum;
    const Mpu_RegionConfigType *MpuRegionConfigPtr;
} Mpu_ConfigType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Mpu */

/** @} end of group Mpu_Module */
#endif /* MPU_TYPES_H */
