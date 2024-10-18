/**************************************************************************************************/
/**
 * @file      : Seru_Drv.h
 * @brief     : Seru driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SERU_DRV_H
#define SERU_DRV_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Seru_Drv
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Seru_Drv_Types.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SERU_DRV_H_VENDOR_ID                   0x00B3U
#define SERU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_H_SW_MAJOR_VERSION            1U
#define SERU_DRV_H_SW_MINOR_VERSION            1U
#define SERU_DRV_H_SW_PATCH_VERSION            0U
/**
 *  @brief Check if current file and Seru_Drv_Types.h are of the same vendor
 */
#if (SERU_DRV_H_VENDOR_ID != SERU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv.h and Seru_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv_Types.h are of the same Autosar version
 */
#if ((SERU_DRV_H_AR_RELEASE_MAJOR_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (SERU_DRV_H_AR_RELEASE_MINOR_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (SERU_DRV_H_AR_RELEASE_REVISION_VERSION != SERU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Seru_Drv.h and Seru_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv_Types.h are of the same SW version
 */
#if ((SERU_DRV_H_SW_MAJOR_VERSION != SERU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (SERU_DRV_H_SW_MINOR_VERSION != SERU_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (SERU_DRV_H_SW_PATCH_VERSION != SERU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv.h and Seru_Drv_Types.h are different"
#endif

#define SERU_DRV_CONFIG_KEY (0x7f1a2dfeU) /*!< SERU Config Mode Key*/
#define SERU_DRV_NORMAL_KEY (0x6cc92dd9U) /*!< SERU Normal Mode Key*/

/** @} end of Private_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
SERU_DRV_CONFIG_EXT

#define MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

/**
 * @brief        This function can set SERU to config mode or normal mode
 *
 * @param[in]    SeruMode: Select SERU mode
 *                       - SERU_DRV_CONFIG_MODE : SERU is in config mode.
 *                       - SERU_DRV_NORMAL_MODE : SERU is in normal mode.
 *
 * @return       None.
 * 
 */
void Seru_Drv_Init(const Seru_Drv_ConfigType *SeruConfig);

/**
 * @brief        This function will De-Initialize SERU Module.
 *
 * @param[in]    None.
 *
 * @return       None.
 * 
 */
void Seru_Drv_DeInit(void);

#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU Parity Error interrupt handler.
 *
 * @param[in]  none
 *
 * @return none
 * 
 */
void Seru_Drv_ParityIrqHandler(void);
#endif

#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU channel Error interrupt handler
 *
 * @param[in]  none
 *
 * @return none
 * 
 */
void Seru_Drv_IrqHandler(void);
#endif
#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"

#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU self test callback function
 *
 * @param[in]  None
 *
 * @return     boolean
 * @retval     TRUE:  SERU self-test is executing now.
 * @retval     FALSE: SERU self-test is not triggered.
 *
 */
extern boolean Mstp_SeruSelfTestCallbackFunction(void);
#endif
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
/** @} end of group Seru_Drv */

/** @} end of group Meh_Module */

#endif /* SERU_DRV_H */
