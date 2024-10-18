/**************************************************************************************************/
/**
 * @file      : Adc_Drv.h
 * @brief     : Adc low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_DRV_H
#define ADC_DRV_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Drv
 *  @brief Adc low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Adc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_DRV_H_VENDOR_ID                   0x00B3U
#define ADC_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_H_SW_MAJOR_VERSION            1U
#define ADC_DRV_H_SW_MINOR_VERSION            2U
#define ADC_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Adc_Drv_Types.h are the same vendor */
#if (ADC_DRV_H_VENDOR_ID != ADC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Adc_Drv.h and Adc_Drv_Types.h are different"
#endif

/* Check if current file and Adc_Drv_Types.h are the same Autosar version */
#if ((ADC_DRV_H_AR_RELEASE_MAJOR_VERSION != ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (ADC_DRV_H_AR_RELEASE_MINOR_VERSION != ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (ADC_DRV_H_AR_RELEASE_REVISION_VERSION != ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Drv.h and Adc_Drv_Types.h are different"
#endif

/* Check if current file and Adc_Drv_Types.h are the same Software version */
#if ((ADC_DRV_H_SW_MAJOR_VERSION != ADC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (ADC_DRV_H_SW_MINOR_VERSION != ADC_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (ADC_DRV_H_SW_PATCH_VERSION != ADC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Drv.h and Adc_Drv_Types.h are different"
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
ADC_DRV_CONFIG_EXT

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief   Declaration of ADC interrupt process functions.
 */
ADC_DRV_FUNC_DECL_EXT

/**
 * @brief     This function initializes group configuration.
 *
 * @param[in] Group:     Group Id
 * @param[in] GrpCfgPtr: Pointer to Group Configuration.
 *
 * @return    None.
 *
 */
void Adc_Drv_InitGroupConfig(const uint16 Group, const Adc_Drv_GroupConfigType *GrpCfgPtr);

/**
 * @brief     Initialize ADC module.
 * @details   This function initializes the ADC module by configuring all available features.
 *
 * @param[in] Instance: ADC instance number
 * @param[in] ConfigPtr: configuration struct pointer
 *
 * @return    None
 */
void Adc_Drv_Init(const uint8 Instance, const Adc_Drv_ConfigType *const ConfigPtr);

/**
 * @brief     Deinitialize ADC module.
 * @details   This function disables and resets the ADC module.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    None
 */
void Adc_Drv_DeInit(const uint8 Instance);

/**
 * @brief     This function returns the value of the conversion complete status.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    boolean: conversion complete status
 * @retval    TRUE: completed
 * @retval    FALSE: not completed
 */
boolean Adc_Drv_GetConvCompleteFlag(const uint8 Instance);

/**
 * @brief     This function retrieves the last conversion result for the
 *            selected control channel.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    uint16: converted data
 */
uint16 Adc_Drv_GetConvData(const uint8 Instance);

/**
 * @brief     This function disables complete interrupt of ADC hardware unit
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    None
 *
 */
void Adc_Drv_DisableCompInterrupt(const uint8 Instance);

/**
 * @brief     This function disables dma of ADC hardware unit
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    None
 *
 */
void Adc_Drv_DisableDma(const uint8 Instance);

/**
 * @brief     This function returns the register address of ADC data.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    uint32: register address of ADC data
 */
uint32 Adc_Drv_GetDataAddress(const uint8 Instance);

/**
 * @brief     This function configures adc registers to start conversion.
 *
 * @param[in] Instance: ADC Hardware Unit id
 * @param[in] Group: Group Id
 * @param[in] ChannelNum: channel number of group to be started
 * @param[in] ChannelList: pointer to the channel list
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Adc_Drv_StartConversion(const uint8 Instance, const uint16 Group, uint8 ChannelNum,
                                       const ADC_Drv_PositiveChannelType *ChannelList);

/**
 * @brief     This function stops the current conversion.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    Std_ReturnType: E_OK or E_NOT_OK.
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 *
 */
Std_ReturnType Adc_Drv_StopConversion(const uint8 Instance);

/**
 * @brief     This function performs a calibration of the ADC.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    Std_ReturnType: the calibration result
 * @retval    E_OK: calibration successful
 * @retval    E_NOT_OK: calibration failed
 */
Std_ReturnType Adc_Drv_Calibrate(const uint8 Instance);

/**
 * @brief     This function performs a self test of the ADC.
 *
 * @param[in] Instance: ADC Hardware Unit id
 *
 * @return    Std_ReturnType: the self test result
 * @retval    E_OK: self test successful
 * @retval    E_NOT_OK: self test failed
 */
Std_ReturnType Adc_Drv_SelfTest(const uint8 Instance);

/**
 * @brief     This function handles the ADC interrupt.
 *
 * @param[in] Instance: ADC instance number
 *
 * @return    None
 */
void Adc_Drv_IntHandler(const uint8 Instance);

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv */

/** @} end of group Adc_Module */

#endif /* ADC_DRV_H */
