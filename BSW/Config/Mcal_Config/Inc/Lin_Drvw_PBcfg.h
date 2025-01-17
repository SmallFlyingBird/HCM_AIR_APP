/**************************************************************************************************/
/**
 * @file      : Lin_Drvw_PBcfg.h
 * @brief     : Lin driver wrapper - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/


#ifndef LIN_DRVW_PBCFG_H
#define LIN_DRVW_PBCFG_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Drvw_Configuration
 *  @brief Lin driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define LIN_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define LIN_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define LIN_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define LIN_DRVW_PBCFG_H_SW_PATCH_VERSION            2U



/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_DRVW_CONFIG_PB \
extern const Lin_Drvw_HwConfigType Lin_Drvw_HwConfig0;\


#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Lin_Drvw_Configuration */

/** @} end of group Lin_Module */

#endif 

