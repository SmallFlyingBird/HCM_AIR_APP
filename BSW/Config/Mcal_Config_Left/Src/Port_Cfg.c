/**************************************************************************************************/
/**
 * @file      : Port_Cfg.c
 * @brief     : AUTOSAR Port driver
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Configuration
 *  @brief Port AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_CFG_C_VENDOR_ID                   0x00B3U
#define PORT_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_CFG_C_SW_MAJOR_VERSION            1U
#define PORT_CFG_C_SW_MINOR_VERSION            2U
#define PORT_CFG_C_SW_PATCH_VERSION            1U

#if (PORT_CFG_C_VENDOR_ID != PORT_VENDOR_ID)
    #error "Vendor id of Port_Cfg.c and Port.h are different"
#endif

#if ((PORT_CFG_C_AR_RELEASE_MAJOR_VERSION    != PORT_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_CFG_C_AR_RELEASE_MINOR_VERSION    != PORT_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_CFG_C_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar version of Port_Cfg.c and Port.h are different"
#endif

#if ((PORT_CFG_C_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) || \
     (PORT_CFG_C_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) || \
     (PORT_CFG_C_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software version of Port_Cfg.c and Port.h are different"
#endif

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

/** @} end of group Port_Configuration */

/** @} end of group Port_Module */

/* End of File */
