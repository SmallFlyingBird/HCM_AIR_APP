/**************************************************************************************************/
/**
 * @file      : Lin_Cfg.h  
 * @brief     : Lin AUTOSAR level - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/


#ifndef LIN_CFG_H
#define LIN_CFG_H


/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Configuration
 *  @brief Lin high level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "McalLib.h"
#include "Lin_PBcfg.h"



/** @defgroup Public_MacroDefinition
 *  @{
 */
#define LIN_CFG_H_VENDOR_ID                   0x00B3U
#define LIN_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_CFG_H_SW_MAJOR_VERSION            1U
#define LIN_CFG_H_SW_MINOR_VERSION            2U
#define LIN_CFG_H_SW_PATCH_VERSION            2U

/* Check if Lin_PBcfg header file and Lin configuration header file are of the same vendor */
#if (LIN_PBCFG_H_VENDOR_ID != LIN_CFG_H_VENDOR_ID)
    #error "Vendor ID of Lin_PBcfg.h and Lin_Cfg.h are different"
#endif
    /* Check if Lin_PBcfg header file and Lin configuration header file are of the same Autosar version */
#if ((LIN_PBCFG_H_AR_RELEASE_MAJOR_VERSION      != LIN_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_PBCFG_H_AR_RELEASE_MINOR_VERSION      != LIN_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (LIN_PBCFG_H_AR_RELEASE_REVISION_VERSION   != LIN_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_PBcfg.h and Lin_Cfg.h are different"
#endif
/* Check if Lin_PBcfg header file and Lin configuration header file are of the same software version */
#if ((LIN_PBCFG_H_SW_MAJOR_VERSION != LIN_CFG_H_SW_MAJOR_VERSION) || \
     (LIN_PBCFG_H_SW_MINOR_VERSION != LIN_CFG_H_SW_MINOR_VERSION) || \
     (LIN_PBCFG_H_SW_PATCH_VERSION != LIN_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_PBcfg.h and Lin_Cfg.h are different"
#endif







/**
* @brief          Pre-compile Support.
*/
#define LIN_PRECOMPILE_SUPPORT  (STD_ON) 

/**
* @brief   Defines LIN_E_TIMEOUT_ENABLE support or not
*/
#define LIN_E_TIMEOUT_ENABLE  (STD_OFF) /* Disable Production Error Detection */ 


/**
* @brief          Support for version info API.
*
*/
#define LIN_VERSION_INFO_API (STD_ON)  /* Enable API Lin_GetVersionInfo      */

/**
* @brief   Switches the development error detection and Notification ON or OFF.
*
*/
#define LIN_DEV_ERROR_DETECT        (UART_DRV_DEV_ERROR_DETECT)

/**
* @brief        Z20K14x not support multicore, it's default to 1
*
*/
#define LIN_MAX_PARTITIONS     ((uint32)1U)

/**
* @brief          Multicore is enabled or not
*
*/
#define LIN_MULTICORE_SUPPORT   (STD_OFF) /* Multicore is disabled */

/**
* @brief          Defines get lin core id.
*
*/
#define Lin_GetCoreID     ((uint32)McalLib_GetCoreID())

/**
* @brief          LIN node type: master/slave.
*
*/
#define LIN_MASTER_SUPPORT          (LIN_DRVW_MASTER_SUPPORT)

/**
* @brief          Lin Wakeup detection 
*
*/
#define LIN_WAKEUP_DETECTION        (LIN_DRVW_WAKEUP_DETECTION)

/**
* @brief   Number of Channels configured.
*
*/
#define LIN_NUMBER_OF_INSTANCES_USED      (LIN_DRVW_NUMBER_OF_INSTANCES_USED)

/**
* @brief  Switches the UART software simulate LIN timeout ON or OFF.
*
*/
#define LIN_SOFTWARE_SIMULATION_TIMEOUT              (LIN_DRVW_SOFTWARE_SIMULATION_TIMEOUT)

/**
* @brief  Lin polling.
*
*/
#define LIN_SOFTWARE_POLLING              (LIN_DRVW_SOFTWARE_POLLING)
/**
* @brief   Total number of available hardware lin channels.
*
*/
#define LIN_INSTANCE_NUM  (LIN_DRVW_INSTANCE_NUM)

/**
* @brief Symbolic Names for configured channels.
*/

#define LinConf_LinChannel_LinChannel_1                           ((uint8)0U)


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

/** @} end of group Lin_Configuration */

/** @} end of group Lin_Module */

#endif /* LIN_CFG_H */
