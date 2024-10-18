/**************************************************************************************************/
/**
 * @file      : Meh.h
 * @brief     : Meh Extended MicroController Error Handle header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MEH_H
#define MEH_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Meh
 *  @brief Extended MicroController Error Handle
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Meh_Types.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define MEH_VENDOR_ID                   0x00B3U
#define MEH_MODULE_ID                   MEH_CFG_H_MODULE_ID
#define MEH_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_AR_RELEASE_MINOR_VERSION    6U
#define MEH_AR_RELEASE_REVISION_VERSION 0U
#define MEH_SW_MAJOR_VERSION            1U
#define MEH_SW_MINOR_VERSION            1U
#define MEH_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Meh_Types.h are of the same vendor
 */
#if (MEH_VENDOR_ID != MEH_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Meh.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Types.h are of the same Autosar version
 */
#if ((MEH_AR_RELEASE_MAJOR_VERSION != MEH_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (MEH_AR_RELEASE_MINOR_VERSION != MEH_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (MEH_AR_RELEASE_REVISION_VERSION != MEH_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Types.h are of the same SW version
 */
#if ((MEH_SW_MAJOR_VERSION != MEH_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (MEH_SW_MINOR_VERSION != MEH_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (MEH_SW_PATCH_VERSION != MEH_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Meh.h and Meh_Types.h are different"
#endif

/**
 * @brief Specifies the InstanceId of this module instance.
 */
#define MEH_INSTANCE_ID                       ((uint8)0x0U)

/**
 * @brief Service Ids for Meh APIs
 */
#define MEH_SID_INIT                          ((uint8)0x01U) /* Initialize MEH module */
#define MEH_SID_GET_VERSION_INFO              ((uint8)0x02U) /* Get Version Info */
#define MEH_SID_MAIN_FUNCTION                 ((uint8)0x03U)
#define MEH_SID_DEINIT                        ((uint8)0x04U)


/**
 * @brief Development errors
 */
#define MEH_E_UNINIT               ((uint8)0x01U)
#define MEH_E_NULL_POINTER         ((uint8)0x02U)
#define MEH_E_PARAM_INVALID        ((uint8)0x03U)
#define MEH_E_ALREADY_INITIALIZED  ((uint8)0x04U)

/** @} end of group Private_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (MEH_PRECOMPILE_SUPPORT == STD_ON)
    #define MEH_START_SEC_CONFIG_DATA_PTR
    #include "Meh_MemMap.h"

extern const Meh_ConfigType *const Meh_PreDefinedConfigPtr;

    #define MEH_STOP_SEC_CONFIG_DATA_PTR
    #include "Meh_MemMap.h"
#else
    #define MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Meh_MemMap.h"

MEH_CONFIG_EXT

    #define MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Meh_MemMap.h"
#endif /* (MEH_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

#if (MEH_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersionInfoPtr: Pointer to where to store the version information of this module.
 *
 * @return    None
 * 
 */
void Meh_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
#endif /* (MEH_VERSION_INFO_API == STD_ON) */

/**
 * @brief      The function initializes the Meh driver.
 *
 * @param[in]  ConfigPtr:Configuration for meh
 * 
 * @return     None
 * 
 */
void Meh_Init(const Meh_ConfigType *ConfigPtr);

/**
 * @brief      The function De-initializes the Meh driver.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Meh_DeInit(void);

/**
 * @brief      The function check Eiru Status and get mem error info.
 *
 * @param[in]  None
 * 
 * @return     None
 */
void Meh_MainFunction(void);

/**
 * @brief      This function should be called by bus fault handler to handle multi bit error.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
void Meh_CheckEccMultiBitError(void);

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Meh */
/** @} end of group Meh_Module */

#endif /* MEH_H */
