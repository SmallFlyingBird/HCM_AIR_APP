/**************************************************************************************************/
/**
 * @file      : Lin_Cfg.c 
 * @brief     : AUTOSAR Lin - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Lin_Module
 *  @{
 */

/** @addtogroup Lin_Configuration
 *  @brief Lin driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif


#include "Lin.h"
#include "Lin_Drvw.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define LIN_CFG_C_VENDOR_ID                   0x00B3U
#define LIN_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define LIN_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define LIN_CFG_C_SW_MAJOR_VERSION            1U
#define LIN_CFG_C_SW_MINOR_VERSION            2U
#define LIN_CFG_C_SW_PATCH_VERSION            2U


#if (LIN_CFG_C_VENDOR_ID != LIN_VENDOR_ID)
    #error "Vendor ID of Lin_Cfg.c and Lin.h are different"
#endif
/* Check if current file and Lin_Cfg header file are of the same Autosar version */
#if ((LIN_CFG_C_AR_RELEASE_MAJOR_VERSION    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_CFG_C_AR_RELEASE_MINOR_VERSION    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_CFG_C_AR_RELEASE_REVISION_VERSION != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Cfg.c and Lin.h are different"
#endif
/* Check if current file and Lin_Cfg header file are of the same Software version */
#if ((LIN_CFG_C_SW_MAJOR_VERSION != LIN_SW_MAJOR_VERSION) || \
     (LIN_CFG_C_SW_MINOR_VERSION != LIN_SW_MINOR_VERSION) || \
     (LIN_CFG_C_SW_PATCH_VERSION != LIN_SW_PATCH_VERSION) )
    #error "Software Version of Lin_Cfg.c and Lin.h are different"
#endif

#if (LIN_CFG_C_VENDOR_ID != LIN_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Lin_Cfg.c and Lin_Drvw.h are different"
#endif
/* Check if current file and Lin_Cfg header file are of the same Autosar version */
#if ((LIN_CFG_C_AR_RELEASE_MAJOR_VERSION    != LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_CFG_C_AR_RELEASE_MINOR_VERSION    != LIN_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (LIN_CFG_C_AR_RELEASE_REVISION_VERSION != LIN_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Cfg.c and Lin_Drvw.h are different"
#endif
/* Check if current file and Lin_Cfg header file are of the same Software version */
#if ((LIN_CFG_C_SW_MAJOR_VERSION != LIN_DRVW_H_SW_MAJOR_VERSION) || \
     (LIN_CFG_C_SW_MINOR_VERSION != LIN_DRVW_H_SW_MINOR_VERSION) || \
     (LIN_CFG_C_SW_PATCH_VERSION != LIN_DRVW_H_SW_PATCH_VERSION) )
    #error "Software Version of Lin_Cfg.c and Lin_Drvw.h are different"
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

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */



#ifdef __cplusplus
}
#endif

/** @} end of group Lin_Configuration */

/** @} end of group Lin_Module */
