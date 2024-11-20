/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv.h
 * @brief     : Tdg Adc low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TDG_ADC_DRV_H
#define TDG_ADC_DRV_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Tdg_Adc_Drv
 *  @brief Tdg Adc low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tdg_Adc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TDG_ADC_DRV_H_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_H_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_H_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Tdg_Adc_Drv_Types.h are the same vendor */
#if (TDG_ADC_DRV_H_VENDOR_ID != TDG_ADC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Tdg_Adc_Drv.h and Tdg_Adc_Drv_Types.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Types.h are the same Autosar version */
#if ((TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION !=                                                 \
      TDG_ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tdg_Adc_Drv.h and Tdg_Adc_Drv_Types.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Types.h are the same Software version */
#if ((TDG_ADC_DRV_H_SW_MAJOR_VERSION != TDG_ADC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (TDG_ADC_DRV_H_SW_MINOR_VERSION != TDG_ADC_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (TDG_ADC_DRV_H_SW_PATCH_VERSION != TDG_ADC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Tdg_Adc_Drv.h and Tdg_Adc_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
TDG_ADC_DRV_CONFIG_EXT

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief   Declaration of callback functions.
 */
TDG_ADC_DRV_FUNC_DECL_EXT

/**
 * @brief     This function initializes group configuration.
 *
 * @param[in] Group:     Group Id
 * @param[in] GrpCfgPtr: Pointer to Group Configuration.
 *
 * @return    None.
 *
 */
void Tdg_Adc_Drv_InitGroupConfig(const uint16 Group, const Tdg_Adc_Drv_GroupConfigType *GrpCfgPtr);

/**
 * @brief     This function initializes the TDG module.
 *
 * @param[in] Instance: TDG instance number
 * @param[in] Config: TDG Configuration
 *
 * @return    None
 */
void Tdg_Adc_Drv_Init(const uint32 Instance, const Tdg_Adc_Drv_ConfigType *const Config);

/**
 * @brief     This function de-initializes the TDG module.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_DeInit(const uint32 Instance);

/**
 * @brief     This function starts the conversion on the specified hardware Unit.
 *
 * @param[in] Instance: Hardware Unit
 * @param[in] Group: Group Id
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType Tdg_Adc_Drv_StartConversion(const uint8 Instance, const uint16 Group);

/**
 * @brief     This function stops the current conversion of a group.
 *
 * @param[in] Instance: Hardware Unit
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType Tdg_Adc_Drv_StopConversion(const uint8 Instance);

/**
 * @brief     Trigger the TDG with a software trigger.
 * @details   This function triggers the TDG with a software trigger.
 *            When the TDG is set to use the software trigger as input, calling this function
 *            triggers the TDG.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_SwTrigger(const uint32 Instance);

/**
 * @brief     This function Handles Tdg complete delay output interrupt.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_TcoIntHandler(const uint32 Instance);

/**
 * @brief     This function Handles Tdg sequence error interrupt.
 *
 * @param[in] Instance: TDG instance number
 *
 * @return    None
 */
void Tdg_Adc_Drv_ErrIntHandler(const uint32 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Tdg_Adc_Drv */

/** @} end of group Adc_Module */

#endif /* TDG_ADC_DRV_H */
