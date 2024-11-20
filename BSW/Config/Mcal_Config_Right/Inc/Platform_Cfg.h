/**************************************************************************************************/
/**
 * @file      : Platform_Cfg.h
 * @brief     : Platform configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PLATFORM_CFG_H
#define PLATFORM_CFG_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Platform
 *  @brief Platform configuration header file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PLATFORM_CFG_H_VENDOR_ID                   0x00B3U
#define PLATFORM_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PLATFORM_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PLATFORM_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PLATFORM_CFG_H_SW_MAJOR_VERSION            1U
#define PLATFORM_CFG_H_SW_MINOR_VERSION            2U
#define PLATFORM_CFG_H_SW_PATCH_VERSION            2U

/**
* @brief Switches development error detection ON or OFF.
*/
#define PLATFORM_DEV_ERROR_DETECT        (STD_OFF)

/**
* @brief Defines user mode support or not.
*/
#define PLATFORM_SUPPORT_USER_MODE         (STD_OFF)

/**
* @brief Defines Trig mux enabled or not.
*/
#define PLATFORM_TRIG_MUX_ENABLE     (STD_OFF)

/**
* @brief Defines Macro to get current core ID.
*/
#define Platform_GetCoreID()     ((uint32)McalLib_GetCoreID())

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"


#define PLATFORM_CONFIG_EXT \
    extern const Platform_ConfigType Platform_Configuration; \

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Platform */

/** @} end of group Platform_Module */

#endif /* PLATFORM_CFG_H */
