/**************************************************************************************************/
/**
 * @file      : Lin_Types.h
 * @brief     : AUTOSAR LIN driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved. 
 **************************************************************************************************/
#ifndef LIN_TYPES_H
#define LIN_TYPES_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Lin
 *  @brief Lin
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin_Cfg.h"
#include "Lin_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define LIN_TYPES_H_VENDOR_ID                   0x00B3U
#define LIN_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_TYPES_H_SW_MAJOR_VERSION            1U
#define LIN_TYPES_H_SW_MINOR_VERSION            2U
#define LIN_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Lin_Defines header file are of the same vendor */
#if (LIN_TYPES_H_VENDOR_ID != LIN_CFG_H_VENDOR_ID)
    #error "Vendor ID of Lin_Types.h and Lin_Cfg.h are different"
#endif
/* Check if current file and Lin_Defines header file are of the same Autosar version */
#if ((LIN_TYPES_H_AR_RELEASE_MAJOR_VERSION != LIN_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (LIN_TYPES_H_AR_RELEASE_MINOR_VERSION != LIN_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (LIN_TYPES_H_AR_RELEASE_REVISION_VERSION != LIN_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Types.h and Lin_Cfg.h are different"
#endif
/* Check if current file and Lin_Defines header file are of the same Software version */
#if ((LIN_TYPES_H_SW_MAJOR_VERSION != LIN_CFG_H_SW_MAJOR_VERSION) ||                               \
     (LIN_TYPES_H_SW_MINOR_VERSION != LIN_CFG_H_SW_MINOR_VERSION) ||                               \
     (LIN_TYPES_H_SW_PATCH_VERSION != LIN_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_Types.h and Lin_Cfg.h are different"
#endif

/* Check if current file and Lin_Drvw_Types header file are of the same vendor */
#if (LIN_TYPES_H_VENDOR_ID != LIN_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Lin_Types.h and Lin_Drvw_Types.h are different"
#endif
/* Check if current file and Lin_Drvw_Types header file are of the same Autosar version */
#if ((LIN_TYPES_H_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (LIN_TYPES_H_AR_RELEASE_MINOR_VERSION != LIN_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (LIN_TYPES_H_AR_RELEASE_REVISION_VERSION != LIN_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Types.h and Lin_Drvw_Types.h are different"
#endif
/* Check if current file and Lin_Drvw_Types header file are of the same Software version */
#if ((LIN_TYPES_H_SW_MAJOR_VERSION != LIN_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (LIN_TYPES_H_SW_MINOR_VERSION != LIN_DRVW_TYPES_H_SW_MINOR_VERSION) ||                        \
     (LIN_TYPES_H_SW_PATCH_VERSION != LIN_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_Types.h and Lin_Drvw_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if((LIN_TYPES_H_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (LIN_TYPES_H_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Lin_Types.h and EcuM.h are different"
    #endif
#endif

/**
 * @brief Return code for timeout error.
 */
#define LIN_TIMEOUT_ERROR 0x02

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief          LIN hardware channel configuration.
 *
 */
/*SWS_Lin_00269*/
typedef struct
{
    uint32  ChannelCoreId;                 /*!< @brief LIN Channel core id.*/
    boolean AllocatedPartition;            /*!< @brief LIN Channel is allocated partition or not.*/
    uint8   LinChannelId;                  /*!< Lin physical Channel ID */
    const Lin_Drvw_HwConfigType *HwConfig; /*!< Pointer to precompile configuration structure */

} Lin_ChannelConfigType;

/**
 * @brief    This is the type of the external data structure containing the overall initialization 
 *           data for the LIN driver and the SFR settings affecting the LIN channels. A pointer to 
 *           such a structure is provided to the LIN driver initialization routine for configuration 
 *           of the driver, LIN hardware unit and LIN hardware channels.
 *  
 */
/* SWS_Lin_00227 */
typedef struct
{
    uint32 PartitionCoreId; /*!< Partition core id is 0 now. */
    const Lin_ChannelConfigType *Lin_ChannelArrayPtr[LIN_NUMBER_OF_INSTANCES_USED];/*!< The used
                                                                  hardware channel configuration. */
} Lin_ConfigType;

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

/** @} end of group Lin */

/** @} end of group Lin_Module */

#endif /* LIN_TYPES_H */
