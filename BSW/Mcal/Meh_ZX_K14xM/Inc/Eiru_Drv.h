/**************************************************************************************************/
/**
 * @file      : Eiru_Drv.h
 * @brief     : Eiru driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef EIRU_DRV_H
#define EIRU_DRV_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Eiru_Drv
 *  @brief Meh eiru diver header file
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eiru_Drv_Types.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define EIRU_DRV_H_VENDOR_ID                   0x00B3U
#define EIRU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define EIRU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define EIRU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define EIRU_DRV_H_SW_MAJOR_VERSION            1U
#define EIRU_DRV_H_SW_MINOR_VERSION            1U
#define EIRU_DRV_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Eiru_Drv_Types.h are of the same vendor
 */
#if (EIRU_DRV_TYPES_H_VENDOR_ID != EIRU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Eiru_Drv_Types.h and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Types.h are of the same Autosar version
 */
#if ((EIRU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (EIRU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != EIRU_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (EIRU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != EIRU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Eiru_Drv_Types.h and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Types.h are of the same SW version
 */
#if ((EIRU_DRV_TYPES_H_SW_MAJOR_VERSION != EIRU_DRV_H_SW_MAJOR_VERSION) ||                         \
     (EIRU_DRV_TYPES_H_SW_MINOR_VERSION != EIRU_DRV_H_SW_MINOR_VERSION) ||                         \
     (EIRU_DRV_TYPES_H_SW_PATCH_VERSION != EIRU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Eiru_Drv_Types.h and Eiru_Drv.h are different"
#endif
/** @} end of group Private_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
EIRU_DRV_CONFIG_EXT

#define MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"
/**
 * @brief      Initialize Eiru Module.
 *
 * @param[in]  EiruConfigPtr: points to the struct that stores the parameters.
 *
 * @return     none
 * 
 */
void Eiru_Drv_Init(const Eiru_Drv_SramEccConfigType *EiruConfigPtr);

/**
 * @brief      De-Initialize Eiru Module.
 *
 * @param[in]  none.
 *
 * @return     none
 * 
 */
void Eiru_Drv_DeInit(void);

/**
 * @brief      This function get ECC error cause for choosing sram.
 *
 * @param[in]  sram: select which SRAM to config:
 *                    - EIRU_DRV_SRAM_L
 *                    - EIRU_DRV_SRAM_U
 * @param[out]  cause: the cause of SRAM ERR error will be stored in the struct
 *                    that is pointed by this parameter.
 *
 * @return none
 * 
 */
void Eiru_Drv_GetSramEccErrCause(const Eiru_Drv_SramType Sram, Eiru_Drv_SramEccErrCauseType *Cause);

/**
 * @brief      This function get error status for choosing sram.
 *
 * @param[in]  sram: select which SRAM to config:
 *                    - EIRU_DRV_SRAM_L
 *                    - EIRU_DRV_SRAM_U
 * @param[in]  status: select the status to get :
 *               - EIRU_DRV_SRAM_ECC_ERR_SINGLEBIT
 *               - EIRU_DRV_SRAM_ECC_ERR_MULTIBIT
 *               - EIRU_DRV_SRAM_ECC_ERR_OVERRUN
 *
 * @return    boolean
 * @retval    FALSE: the error Status is not set
 * @retval    TRUE: the error Status is set
 * 
 */
boolean Eiru_Drv_GetSramEccErrStatus(const Eiru_Drv_SramType             Sram,
                                     const Eiru_Drv_SramEccErrStatusType Status);

/**
 * @brief      This function clear ECC error status for choosing sram.
 *
 * @param[in]  sram: select which SRAM to config:
                     - EIRU_DRV_SRAM_L
                     - EIRU_DRV_SRAM_U
 * @param[in]  status: select the status to clear.
 *
 * @return none
 * 
 */
void Eiru_Drv_ClearSramEccErrStatus(const Eiru_Drv_SramType             Sram,
                                    const Eiru_Drv_SramEccErrStatusType Status);
#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} end of group Eiru_Drv */

/** @} end of group Meh_Module */
#endif /* EIRU_DRV_H */
