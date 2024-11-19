/**************************************************************************************************/
/**
 * @file      : McalLib_Cfg.h
 * @brief     : McalLib configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MCALLIB_CFG_H
#define MCALLIB_CFG_H

/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup McalLib_Configuration
 *  @brief McalLib configuration header file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define MCALLIB_CFG_H_VENDOR_ID                   0x00B3U
#define MCALLIB_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_CFG_H_SW_MAJOR_VERSION            1U
#define MCALLIB_CFG_H_SW_MINOR_VERSION            2U
#define MCALLIB_CFG_H_SW_PATCH_VERSION            2U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if((MCALLIB_CFG_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (MCALLIB_CFG_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib_Cfg.h and Std_Types.h are different"
    #endif
#endif

/**
 * @brief Defines McalLib instance ID
*/
#define MCALLIB_INSTANCE                         (0U)

/**
 * @brief Defines number of cores
*/
#define MCALLIB_CORE_NUM                         (1U)

/**
 * @brief Defines development error detection enable or not
*/
#define MCALLIB_DEV_ERROR_DETECT                 (STD_OFF)

/**
 * @brief Defines development assertion enable or not
*/
#define MCALLIB_DEV_ASSERT_ENABLE                (STD_OFF)

/**
 * @brief Defines user mode support or not
*/
#define MCALLIB_ENABLE_USER_MODE_SUPPORT         (STD_OFF)

#ifndef MCAL_SUPPORT_USER_MODE
    #if (STD_ON == MCALLIB_ENABLE_USER_MODE_SUPPORT)
        #error MCALLIB_ENABLE_USER_MODE_SUPPORT == STD_ON when MCAL_SUPPORT_USER_MODE is not defined. For running McalLib in user mode, MCAL_SUPPORT_USER_MODE needs to be defined.
    #endif /* (STD_ON == MCALLIB_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_SUPPORT_USER_MODE */

/**
 * @brief Defines OS counter enable or not
*/
#define MCALLIB_OS_COUNTER_ENABLE                (STD_OFF)

/**
 * @brief Defines Customer counter enable or not
*/
#define MCALLIB_CUSTOM_COUNTER_ENABLE            (STD_OFF)


/**
 * @brief Defines Fault Injection tests enable or not
*/
#define MCAL_FAULT_INJECTION    (STD_OFF)

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

/** @} end of group McalLib_Configuration */

/** @} end of group McalLib_Module */

#endif /* MCALLIB_CFG_H */
