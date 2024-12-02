/**************************************************************************************************/
/**
 * @file      : Lin_PBcfg.c
 * @brief     : Lin AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Configuration
 *  @brief Lin high level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif



#include "Lin.h"
#include "Lin_Drvw.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */
#define LIN_PBCFG_C_VENDOR_ID                   0x00B3U
#define LIN_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define LIN_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define LIN_PBCFG_C_SW_MAJOR_VERSION            1U
#define LIN_PBCFG_C_SW_MINOR_VERSION            2U
#define LIN_PBCFG_C_SW_PATCH_VERSION            2U

/* Checks against Lin.h */
#if (LIN_PBCFG_C_VENDOR_ID != LIN_VENDOR_ID)
    #error "Vendor ID of Lin_PBcfg.c and Lin.h are different"
#endif
#if ((LIN_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_PBCFG_C_AR_RELEASE_MINOR_VERSION    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_PBCFG_C_AR_RELEASE_REVISION_VERSION != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Lin_PBcfg.c and Lin.h are different"
#endif
#if ((LIN_PBCFG_C_SW_MAJOR_VERSION != LIN_SW_MAJOR_VERSION) || \
     (LIN_PBCFG_C_SW_MINOR_VERSION != LIN_SW_MINOR_VERSION) || \
     (LIN_PBCFG_C_SW_PATCH_VERSION != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version of Lin_PBcfg.c and Lin.h are different"
#endif


/* Checks against Lin_Drvw.h */
#if (LIN_PBCFG_C_VENDOR_ID != LIN_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Lin_PBcfg.c and Lin_Drvw.h are different"
#endif
#if ((LIN_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_PBCFG_C_AR_RELEASE_MINOR_VERSION    != LIN_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (LIN_PBCFG_C_AR_RELEASE_REVISION_VERSION != LIN_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Lin_PBcfg.c and Lin_Drvw.h are different"
#endif
#if ((LIN_PBCFG_C_SW_MAJOR_VERSION != LIN_DRVW_H_SW_MAJOR_VERSION) || \
     (LIN_PBCFG_C_SW_MINOR_VERSION != LIN_DRVW_H_SW_MINOR_VERSION) || \
     (LIN_PBCFG_C_SW_PATCH_VERSION != LIN_DRVW_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Lin_PBcfg.c and Lin_Drvw.h are different"
#endif

#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"


#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */



/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/* Configuration for Lin Channel */

/**
* @brief          LIN logic channel configuration
*
*/
static const Lin_ChannelConfigType Lin_ChannelCfg0 =
{
    Lin_GetCoreID,         /* core id of channel */

    (boolean)TRUE,
    
    (uint8)0U, /* Lin Channel ID */

    &Lin_Drvw_HwConfig0, /* Pointer to the hardware configuration*/

    
};

/* Configuration for Lin configuration */

/**
* @brief          Lin Configuration in autosar layer
*
*/
static const Lin_ConfigType Lin_Config =
{
    Lin_GetCoreID,            /** Core Id */

    {
        /* Lin logic channel configuration */
        &Lin_ChannelCfg0
    }
};

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_CONFIG_DATA_PTR
#include "Lin_MemMap.h"

/**
* @brief          Lin Configuration data for Lin_PreDefinedConfigPtr[LIN_MAX_PARTITIONS].
*
*/
const Lin_ConfigType * const Lin_PreDefinedConfigPtr[LIN_MAX_PARTITIONS] =
{

    &Lin_Config
    };

#define LIN_STOP_SEC_CONFIG_DATA_PTR
#include "Lin_MemMap.h"
/** @} end of group Global_VariableDefinition */

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

