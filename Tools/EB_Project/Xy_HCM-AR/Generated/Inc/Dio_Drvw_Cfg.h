/**************************************************************************************************/
/**
 * @file      : Dio_Drvw_Cfg.h  
 * @brief     : Dio driver wrapper - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DIO_DRVW_CFG_H
#define DIO_DRVW_CFG_H

/** @addtogroup Dio_Module
 *  @{
 */

/** @addtogroup Dio_Drvw_Configuration
 *  @brief Dio driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
*/
/* Published information */
#define DIO_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define DIO_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define DIO_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define DIO_DRVW_CFG_H_SW_PATCH_VERSION            2U

/**
* @brief          Enable or Disable function for flipping channel.
*
*/
#define DIO_DRVW_FLIP_CHANNEL_API    (STD_ON)

/**
* @brief          Enable or Disable function for mask channel.
*
*/
#define DIO_DRVW_MASKEDWRITEPORT_API  (STD_OFF)

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

/** @} end of group Dio_Drvw_Configuration */

/** @} end of group Dio_Module */

#endif 
