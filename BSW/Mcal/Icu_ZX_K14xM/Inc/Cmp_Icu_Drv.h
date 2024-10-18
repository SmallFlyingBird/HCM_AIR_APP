/**************************************************************************************************/
/**
 * @file      : Cmp_Icu_Drv.h
 * @brief     : AUTOSAR Cmp Icu hardware driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CMP_ICU_DRV_H
#define CMP_ICU_DRV_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Cmp_Icu_Drv_Types.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CMP_ICU_DRV_H_VENDOR_ID                   0x00B3U
#define CMP_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMP_ICU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define CMP_ICU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define CMP_ICU_DRV_H_SW_MAJOR_VERSION            1U
#define CMP_ICU_DRV_H_SW_MINOR_VERSION            2U
#define CMP_ICU_DRV_H_SW_PATCH_VERSION            1U

#if (CMP_ICU_DRV_H_VENDOR_ID != CMP_ICU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID Cmp_Icu_Drv.h and Cmp_Icu_Drv_Types.h have different"
#endif

#if ((CMP_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (CMP_ICU_DRV_H_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Cmp_Icu_Drv.h and Cmp_Icu_Drv_Types.h are different"
#endif

#if ((CMP_ICU_DRV_H_SW_MAJOR_VERSION != CMP_ICU_DRV_TYPES_H_SW_MAJOR_VERSION) || \
        (CMP_ICU_DRV_H_SW_MINOR_VERSION != CMP_ICU_DRV_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Cmp_Icu_Drv.h and Cmp_Icu_Drv_Types.h are different"
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
CMP_ICU_DRV_CONFIG_EXT
 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief Cmp Icu Drv functions declaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  CmpIcuInstCfgPtr: Pointer that contains driver configuration data 
 *
 * @return none
 *
 */
Cmp_Icu_Drv_StatusType Cmp_Icu_Drv_Init(Cmp_Icu_Drv_IdType InstId, 
                                          const Cmp_Icu_Drv_InstanceConfigType * CmpIcuInstCfgPtr);

/**
 * @brief      The function enable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_EnableNotification(Cmp_Icu_Drv_IdType InstId);

/**
 * @brief      The function that sets up the activation condition
 *
 * @param[in]  InstId: Number of instances to be configured
 * @param[in]  ActiveEdge: edge activation type used 
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_SetActivationCondition(Cmp_Icu_Drv_IdType InstId,  
                                                   Cmp_Icu_Drv_EdgeAlignmentModeType ActiveEdge);

/**
 * @brief      The function disable Notification for timestamp
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_DisableNotification(Cmp_Icu_Drv_IdType InstId);

#if (STD_ON == CMP_ICU_DRV_DEINIT_API)
/**
 * @brief      De-Initialize a hardware Icu Instance
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
Cmp_Icu_Drv_StatusType Cmp_Icu_Drv_DeInit (Cmp_Icu_Drv_IdType InstId);
#endif

#if (STD_ON == CMP_ICU_DRV_GET_INPUT_STATE_API)
/**
 * @brief      The function get input state of the Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return input state
 *
 */
boolean Cmp_Icu_Drv_GetInputState(Cmp_Icu_Drv_IdType InstId);
#endif

#if (STD_ON == CMP_ICU_DRV_EDGE_DETECT_API)
/**
 * @brief      This function enable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_EnableEdgeDetection(Cmp_Icu_Drv_IdType InstId);

/**
 * @brief      This function disable edge detection measure mode for a given 
 *             instance and Channel
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_DisableEdgeDetection(Cmp_Icu_Drv_IdType InstId);
#endif

#if (STD_ON == CMP_ICU_DRV_SET_MODE_API)
/**
 * @brief      Sets hardware Channel into SLEEP mode
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_SetChannelSleepMode(Cmp_Icu_Drv_IdType InstId);

/**
 * @brief      Sets hardware Channel into NORMAL mode
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_SetChannelNormalMode(Cmp_Icu_Drv_IdType InstId);
#endif

/**
 * @brief      This function handles CHF interrupt of all Channels
 *
 * @param[in]  InstId: Number of instances to be configured
 *
 * @return none
 *
 */
void Cmp_Icu_Drv_ChIntHandler(Cmp_Icu_Drv_IdType InstId);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Cmp_Icu_Drv  */
/** @} end of group Icu_Module */

#endif  /* ICU_DRV_H */

