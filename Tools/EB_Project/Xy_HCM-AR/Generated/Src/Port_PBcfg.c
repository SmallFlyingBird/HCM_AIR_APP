/**************************************************************************************************/
/**
 * @file      : Port_PBcfg.c
 * @brief     : AUTOSAR Port driver config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
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
#include "Port_Drvw.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_PBCFG_C_VENDOR_ID                   0x00B3U
#define PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_PBCFG_C_SW_MAJOR_VERSION            1U
#define PORT_PBCFG_C_SW_MINOR_VERSION            2U
#define PORT_PBCFG_C_SW_PATCH_VERSION            2U


#if (PORT_PBCFG_C_VENDOR_ID != PORT_VENDOR_ID)
    #error "Vendor ID of Port_PBCfg.c and Port.h are different"
#endif

#if ((PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Port_PBCfg.c and Port.h are different"
#endif

#if ((PORT_PBCFG_C_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION) || \
     (PORT_PBCFG_C_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION) || \
     (PORT_PBCFG_C_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
    #error "Software Version of Port_PBCfg.c and Port.h are different"
#endif

#if (PORT_PBCFG_C_VENDOR_ID != PORT_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Port_PBCfg.c and Port_Drvw.h are different"
#endif

#if ((PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PORT_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PORT_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Port_PBCfg.c and Port_Drvw.h are different"
#endif

#if ((PORT_PBCFG_C_SW_MAJOR_VERSION != PORT_DRVW_H_SW_MAJOR_VERSION) || \
     (PORT_PBCFG_C_SW_MINOR_VERSION != PORT_DRVW_H_SW_MINOR_VERSION) || \
     (PORT_PBCFG_C_SW_PATCH_VERSION != PORT_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Port_PBCfg.c and Port_Drvw.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"
/**
* @brief Array containing list of partition which used in driver
*/
static const uint8 Port_PartitionInfoTable[PORT_NUMBER_OF_PARTITION] =
{
  1
};
#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Partition information of the config pins
*/
static const uint32 Port_PinsPartitionInfoTable[PORT_NUMBER_OF_CONFIG_PINS] =
{
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 ,
    (uint32)1 
};
#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
/**
* @brief Port attribtes struct
*/
static const Port_ConfigType Port_Config =
{
    PORT_NUMBER_OF_CONFIG_PINS,
    Port_PinsPartitionInfoTable,
    Port_PartitionInfoTable,
    &Port_DrvwConfig
};
/**
* @brief Pointer to PORT Configuration
*/
const Port_ConfigType * const Port_PreDefinedConfigPtr[1] =
{
    &Port_Config
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

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
