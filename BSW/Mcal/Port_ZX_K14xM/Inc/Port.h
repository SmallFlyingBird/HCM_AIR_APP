/**************************************************************************************************/
/**
 * @file      : Port.h
 * @brief     : AUTOSAR Port headfile
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port
 *  @brief Port AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_VENDOR_ID                   0x00B3U
#define PORT_MODULE_ID                   124U
#define PORT_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_AR_RELEASE_MINOR_VERSION    6U
#define PORT_AR_RELEASE_REVISION_VERSION 0U
#define PORT_SW_MAJOR_VERSION            1U
#define PORT_SW_MINOR_VERSION            2U
#define PORT_SW_PATCH_VERSION            1U


#if (PORT_VENDOR_ID != PORT_TYPES_H_VENDOR_ID)
    #error "Vendor id of Port.h and Port_Types.h are different"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                    \
     (PORT_AR_RELEASE_MINOR_VERSION != PORT_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                    \
     (PORT_AR_RELEASE_REVISION_VERSION != PORT_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port.h and Port_Types.h are different"
#endif

#if ((PORT_SW_MAJOR_VERSION != PORT_TYPES_H_SW_MAJOR_VERSION) ||                                    \
     (PORT_SW_MINOR_VERSION != PORT_TYPES_H_SW_MINOR_VERSION) ||                                    \
     (PORT_SW_PATCH_VERSION != PORT_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of Port.h and Port_Types.h are different"
#endif


/**
 * @brief   Port Instance ID.
 */
#define PORT_INSTANCE_ID ((uint8)0x0)

/**
 * @brief  Port Service IDs
 */
#define PORT_INIT_ID                    (0x00U)   /*!< Port service id for init function*/
#define PORT_SET_PIN_DIRECTION_ID       (0x01U)   /*!< Port service id for set pin direction function*/
#define PORT_REFRESH_PIN_DIRECTION_ID   (0x02U)   /*!< Port service id for refresh pin direction  function*/
#define PORT_GET_VERSION_INFO_ID        (0x03U)   /*!< Port service id for get version function*/
#define PORT_SET_PIN_MODE_ID            (0x04U)   /*!< Port service id for set pin mode function*/

/**
 * @brief   Port Error IDs
 */
#define PORT_E_PARAM_CONFIG             (0xF0U)   /*!< Port configuration structure pointer parameter error*/
#define PORT_E_PARAM_PIN                (0x0AU)   /*!< Port pin parameter error */
#define PORT_E_DIRECTION_UNCHANGEABLE   (0x0BU)   /*!< Port direction unchangeable error */
#define PORT_E_INIT_FAILED              (0x0CU)   /*!< Port init error */
#define PORT_E_PARAM_INVALID_MODE       (0x0DU)   /*!< Port invalid parameter error */
#define PORT_E_MODE_UNCHANGEABLE        (0x0EU)   /*!< Port mode unchangeable error */
#define PORT_E_UNINIT                   (0x0FU)   /*!< Port uinit error */
#define PORT_E_PARAM_POINTER            (0x10U)   /*!< Port pointer parameter error */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
    #define PORT_START_SEC_CONFIG_DATA_PTR
    #include "Port_MemMap.h"
extern const Port_ConfigType *const Port_PreDefinedConfigPtr[1];
    #define PORT_STOP_SEC_CONFIG_DATA_PTR
    #include "Port_MemMap.h"
#else
    #define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Port_MemMap.h"

PORT_CONFIG_EXT

    #define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Port_MemMap.h"
#endif /* (PORT_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/* Allocate defined section for PORT code */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/**
 * @brief     Initialize all ports and port pins with the configuration set
 *            pointed to by the parameter ConfigPtr.
 *
 * @param[in] ConfigPtr: Pointer to port configuration structure
 * 
 * @return    None
 */
void Port_Init(const Port_ConfigType *ConfigPtr);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
 * @brief      Set the port pin direction during runtime.
 *
 * @param[in] Pin:          Port pin index
 * @param[in] Direction:    Port pin direction
 * 
 * @return    None
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
 * @brief     Set the port pin mode of the referenced pin during runtime.
 *
 * @param[in] Pin :    Port pin index
 * @param[in] Mode:    Port pin pinmux mode
 *
 * @return    None
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_VERSION_INFO_API)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] versioninfo: Pointer to version type structure
 * 
 * @return    None
 */
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* (STD_ON == PORT_VERSION_INFO_API) */

/**
 * @brief     Refresh the direction of all configured ports to the configured direction.
 *
 * @param[in] None
 * 
 * @return    None
 */
void Port_RefreshPortDirection(void);

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Port */

/** @} end of group Port_Module */

#endif /* PORT_H */
