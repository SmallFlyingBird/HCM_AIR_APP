/**************************************************************************************************/
/**
 * @file      : Lin_Drvw_Cfg.h  
 * @brief     : Lin driver wrapper - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef LIN_DRVW_CFG_H
#define LIN_DRVW_CFG_H

/**
 * @file Lin_Drvw_Cfg.h
 * @brief Lin middle level driver header file.
 * 
 */

/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Drvw_Cfg
 *  @brief Lin middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Lin_Drvw_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define LIN_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define LIN_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U 
#define LIN_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define LIN_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define LIN_DRVW_CFG_H_SW_PATCH_VERSION            2U

/* Check if Lin_Drvw_PBcfg.h and Lin_Drvw_Cfg.h are of the same vendor */
#if (LIN_DRVW_PBCFG_H_VENDOR_ID != LIN_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw_PBcfg.h and Lin_Drvw_Cfg.h are different"
#endif
/* Check if Lin.h file and Lin_Drvw.h file are of the same Autosar version */
#if ((LIN_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION != LIN_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (LIN_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION != LIN_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Drvw_PBcfg.h and Lin_Drvw_Cfg.h are different"
#endif

#if ((LIN_DRVW_PBCFG_H_SW_MAJOR_VERSION != LIN_DRVW_CFG_H_SW_MAJOR_VERSION) || \
     (LIN_DRVW_PBCFG_H_SW_MINOR_VERSION != LIN_DRVW_CFG_H_SW_MINOR_VERSION) || \
     (LIN_DRVW_PBCFG_H_SW_PATCH_VERSION != LIN_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of  Lin_Drvw_PBcfg.h and Lin_Drvw_Cfg.h are different"
#endif




#define LIN_DRVW_CONFIG_EXT \
    LIN_DRVW_CONFIG_PB

/**
*
* @brief          Lin Wakeup detection on/off
*
*/
#define LIN_DRVW_WAKEUP_DETECTION        (STD_OFF) /* Support wakeup detection */

/**
* @brief   User configured the number of LIN.
*
*/
#define LIN_DRVW_NUMBER_OF_INSTANCES_USED     (UART_DRV_NUMBER_OF_INSTANCES_USED)


/**
* @brief  UART software simulate LIN timeout ON or OFF
*
*/
#define LIN_DRVW_SOFTWARE_SIMULATION_TIMEOUT     (UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)


/**
* @brief  Lin polling.
*
*/
#define LIN_DRVW_SOFTWARE_POLLING     (UART_DRV_SOFTWARE_POLLING)


/**
* @brief   Total number of available hardware lin channels.
*
*/
#define LIN_DRVW_INSTANCE_NUM  (UART_DRV_INSTANCE_NUM)

/**
* @brief          Lin config master node
*
*/
#define LIN_DRVW_MASTER_SUPPORT  (STD_OFF) /* not config to be master node */


/**
* @brief          Lin config slave node
*
*/
#define LIN_DRVW_SLAVE_SUPPORT  (STD_ON) /* config to be slave node */


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

/** @} end of group Lin_Drvw_Cfg */

/** @} end of group Lin_Module */

#endif /*LIN_DRVW_CFG_H*/
