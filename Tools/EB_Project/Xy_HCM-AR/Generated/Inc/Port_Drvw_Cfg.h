/**************************************************************************************************/
/**
 * @file      : Port_Drvw_Cfg.h
 * @brief     : AUTOSAR Port drvw config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PORT_DRVW_CFG_H
#define PORT_DRVW_CFG_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Drvw_Configuration
 *  @brief Port drvw level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Port_Drvw_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define PORT_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define PORT_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define PORT_DRVW_CFG_H_SW_PATCH_VERSION            2U



/* Check if the vendor id of current file and Port_Drvw_PBcfg.h are the same */
#if (PORT_DRVW_CFG_H_VENDOR_ID != PORT_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw_Cfg.h and Port_Drvw_PBcfg.h are different"
#endif

/* Check if the autosar version of current file and Port_Drvw_PBcfg.h are the same */
#if ((PORT_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    != PORT_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    != PORT_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != PORT_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar version of Port_Drvw_Cfg.h and Port_Drvw_PBcfg.h are different"
#endif

/* Check if the software version of current file and Port_Drvw_PBcfg.h are the same*/
#if ((PORT_DRVW_CFG_H_SW_MAJOR_VERSION != PORT_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
     (PORT_DRVW_CFG_H_SW_MINOR_VERSION != PORT_DRVW_PBCFG_H_SW_MINOR_VERSION) || \
     (PORT_DRVW_CFG_H_SW_PATCH_VERSION != PORT_DRVW_PBCFG_H_SW_PATCH_VERSION)    \
    )
    #error "Software version of Port_Drvw_Cfg.h and Port_Drvw_PBcfg.h are different"
#endif

#define PORT_DRVW_DEV_ERROR_DETECT           (STD_ON)

#define PORT_DRVW_SET_PIN_DIRECTION_API      (STD_ON)

#define PORT_DRVW_SET_PIN_MODE_API           (STD_ON)

#define PORT_DRVW_NUMBER_OF_CONFIG_PINS     ((uint16)40)

#define PORT_DRVW_MAX_PINMUX_NUMBER         ((uint8)8)

#define PORT_DRVW_NUMBER_OF_UNCONFIG_PINS   (46U)

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_DRVW_CONFIG_EXT \
        PORT_DRVW_CONFIG_PB

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

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

/** @} end of group Port_Drvw_Configuration */

/** @} end of group Port_Module */

#endif /* PORT_DRVW_CFG_H */

