/**************************************************************************************************/
/**
 * @file      : Os_Cfg.h
 * @brief     : Os configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef OS_CFG_H
#define OS_CFG_H

/** @addtogroup  Os_Module
 *  @{
 */

/** @defgroup Os_Configuration
 *  @brief Os configuration header file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define OS_CFG_H_VENDOR_ID                   0x00B3U
#define OS_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define OS_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define OS_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define OS_CFG_H_SW_MAJOR_VERSION            1U
#define OS_CFG_H_SW_MINOR_VERSION            2U
#define OS_CFG_H_SW_PATCH_VERSION            2U

#define OsCounter_HW   0
#define OS_TICKS2NS_OsCounter_HW(x) 1000000000000U
#define OS_TICKS2US_OsCounter_HW(x) 1000000000U
#define OsCounter_SW   1
#define OS_TICKS2NS_OsCounter_SW(x) 1000000000000U
#define OS_TICKS2US_OsCounter_SW(x) 1000000000U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Os_Configuration */

/** @} end of group Os_Module */

#endif /* OS_CFG_H */
