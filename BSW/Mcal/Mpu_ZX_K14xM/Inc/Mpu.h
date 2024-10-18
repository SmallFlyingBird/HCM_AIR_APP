/**************************************************************************************************/
/**
 * @file      : Mpu.h
 * @brief     : System memory protect unit header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MPU_H
#define MPU_H

/** @addtogroup Mpu_Module
 *  @{
 */

/** @addtogroup Mpu
 *  @brief Mpu handle api header file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mpu_Types.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MPU_VENDOR_ID                   0x00B3U
#define MPU_MODULE_ID                   MPU_CFG_H_MODULE_ID
#define MPU_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_AR_RELEASE_MINOR_VERSION    6U
#define MPU_AR_RELEASE_REVISION_VERSION 0U
#define MPU_SW_MAJOR_VERSION            1U
#define MPU_SW_MINOR_VERSION            1U
#define MPU_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Mpu_Types.h are of the same vendor
 */
#if (MPU_VENDOR_ID != MPU_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mpu.h and Mpu_Types.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Types.h are of the same Autosar version
 */
#if ((MPU_AR_RELEASE_MAJOR_VERSION != MPU_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (MPU_AR_RELEASE_MINOR_VERSION != MPU_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (MPU_AR_RELEASE_REVISION_VERSION != MPU_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu.h and Mpu_Types.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_Types.h are of the same SW version
 */
#if ((MPU_SW_MAJOR_VERSION != MPU_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (MPU_SW_MINOR_VERSION != MPU_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (MPU_SW_PATCH_VERSION != MPU_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mpu.h and Mpu_Types.h are different"
#endif

/**
 * @brief Specifies the InstanceId of this module instance.
 */
#define MPU_INSTANCE_ID ((uint8)0x0U)

/**
 * @brief Service Ids for Mpu APIs
 */
#define MPU_SID_INIT             ((uint8)0x01U) /* Initialize MPU module */
#define MPU_SID_GET_VERSION_INFO ((uint8)0x02U) /* Get Version Info */
/**
 * @brief Development errors
 */
#define MPU_E_NULL_POINTER          ((uint8)0x02U)
#define MPU_E_PARAM_INVALID         ((uint8)0x03U)
#define MPU_E_ALREADY_INITIALIZED   ((uint8)0x04U)
/** @} end of group Private_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#if (MPU_PRECOMPILE_SUPPORT == STD_ON)
    #define MPU_START_SEC_CONFIG_DATA_PTR
    #include "Mpu_MemMap.h"

extern const Mpu_ConfigType *const Mpu_PreDefinedConfigPtr;

    #define MPU_STOP_SEC_CONFIG_DATA_PTR
    #include "Mpu_MemMap.h"
#else
    #define MPU_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Mpu_MemMap.h"

MPU_CONFIG_EXT

    #define MPU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Mpu_MemMap.h"
#endif /* (MPU_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */
/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MPU_START_SEC_CODE
#include "Mpu_MemMap.h"
#if (MPU_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersionInfoPtr: Pointer to where to store the version information of this module.
 *
 * @return    None
 */
void Mpu_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
#endif /* (MPU_VERSION_INFO_API == STD_ON) */

/**
 * @brief      Init Mpu global config and memory region config.
 *
 * @param[in]  ConfigPtr: Global configuration for Mpu.
 * 
 * @return     None
 * 
 */
void Mpu_Init(const Mpu_ConfigType *ConfigPtr);

/**
 * @brief      This is an interrupt handler function ,and will be called by BusFault_Handler.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Mpu_SmpuErrorCallBack(void);

#define MPU_STOP_SEC_CODE
#include "Mpu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Template */

/** @} end of group Template_Module */

#endif /* MPU_H */
