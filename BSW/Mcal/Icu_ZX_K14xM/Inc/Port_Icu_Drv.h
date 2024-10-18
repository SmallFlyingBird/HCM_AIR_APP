/**************************************************************************************************/
/**
 * @file      : Port_Icu_Drv.h
 * @brief     : AUTOSAR Port Icu hardware driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_ICU_DRV_H
#define PORT_ICU_DRV_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Port_Icu_Drv_Types.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define PORT_ICU_DRV_H_VENDOR_ID                   0x00B3U
#define PORT_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_ICU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_ICU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_ICU_DRV_H_SW_MAJOR_VERSION            1U
#define PORT_ICU_DRV_H_SW_MINOR_VERSION            2U
#define PORT_ICU_DRV_H_SW_PATCH_VERSION            1U

#if (PORT_ICU_DRV_H_VENDOR_ID != PORT_ICU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID Port_Icu_Drv.h and Port_Icu_Drv_Types.h have different"
#endif

#if ((PORT_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_ICU_DRV_H_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Port_Icu_Drv.h and Port_Icu_Drv_Types.h are different"
#endif

#if ((PORT_ICU_DRV_H_AR_RELEASE_REVISION_VERSION != PORT_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION) || \
        (PORT_ICU_DRV_H_SW_PATCH_VERSION != PORT_ICU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "AutoSar version of Port_Icu_Drv.h and Port_Icu_Drv_Types.h are different"
#endif

#if ((PORT_ICU_DRV_H_SW_MAJOR_VERSION != PORT_ICU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (PORT_ICU_DRV_H_SW_MINOR_VERSION != PORT_ICU_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Port_Icu_Drv.h and Port_Icu_Drv_Types.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief   Export Post-Build configurations.
 */

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

PORT_ICU_DRV_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief Port Icu Drv functions declaration
 *  @{
 */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  PortIcuInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
Port_Icu_Drv_StatusType Port_Icu_Drv_Init(Port_Icu_Drv_IdType InstId, 
                                          const Port_Icu_Drv_InstanceConfigType * PortIcuInstCfgPtr);

/**
 * @brief      The function enable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 * 
 * @return none
 *
 */
void Port_Icu_Drv_EnableNotification(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);

/**
 * @brief      The function that sets up the activation condition
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 * @param[in]  ActiveEdge: edge activation type used 
 *
 * @return none
 *
 */
void Port_Icu_Drv_SetActivationCondition(Port_Icu_Drv_IdType InstId, 
                                            Port_Icu_Drv_GpioNoType Channel, 
                                            Port_Icu_Drv_EdgeAlignmentModeType ActiveEdge);

/**
 * @brief      The function disable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 * 
 * @return none
 *
 */
void Port_Icu_Drv_DisableNotification(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);

#if (STD_ON == PORT_ICU_DRV_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
Port_Icu_Drv_StatusType Port_Icu_Drv_DeInit(Port_Icu_Drv_IdType InstId);
#endif

#if (STD_ON == PORT_ICU_DRV_GET_INPUT_STATE_API)
/**
 * @brief      The function get input state of the Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 * 
 * @return input state
 *
 */
boolean Port_Icu_Drv_GetInputState(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);
#endif

#if (STD_ON == PORT_ICU_DRV_EDGE_DETECT_API)
/**
 * @brief      This function enable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return none
 *
 */
void Port_Icu_Drv_EnableEdgeDetection(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);

/**
 * @brief      This function disable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used
 *
 * @return none
 *
 */
void Port_Icu_Drv_DisableEdgeDetection(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);
#endif

#if (STD_ON == PORT_ICU_DRV_SET_MODE_API)
/**
 * @brief      Sets hardware Channel into SLEEP mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used 
 *
 * @return none
 *
 */
void Port_Icu_Drv_SetChannelSleepMode(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);

/**
 * @brief      Sets hardware Channel into NORMAL mode
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  Channel: Hardware Channel of PORT used 
 *
 * @return none
 *
 */
void Port_Icu_Drv_SetChannelNormalMode(Port_Icu_Drv_IdType InstId, Port_Icu_Drv_GpioNoType Channel);
#endif

/**
 * @brief      This function handles CHF interrupt of all Channels
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Port_Icu_Drv_ChIntHandler(Port_Icu_Drv_IdType InstId);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Icu_Drv  */
/** @} end of group Icu_Module */

#endif  /* ICU_DRV_H */

