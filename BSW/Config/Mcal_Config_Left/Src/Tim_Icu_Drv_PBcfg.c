/**************************************************************************************************/
/**
 * @file      : Tim_Icu_Drv_PBcfg.c
 * @brief     : AUTOSAR Tim Icu Drv post-build configure source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Icu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_ICU_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define TIM_ICU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_ICU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_ICU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_ICU_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define TIM_ICU_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define TIM_ICU_DRV_PBCFG_C_SW_PATCH_VERSION            2U


#if (TIM_ICU_DRV_PBCFG_C_VENDOR_ID != TIM_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Tim_Icu_Drv_PBcfg.c and Tim_Icu_Drv.h have different"
#endif

#if ((TIM_ICU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (TIM_ICU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Tim_Icu_Drv_PBcfg.c and Tim_Icu_Drv.h are different"
#endif

#if ((TIM_ICU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != TIM_ICU_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (TIM_ICU_DRV_PBCFG_C_SW_PATCH_VERSION != TIM_ICU_DRV_H_SW_PATCH_VERSION))
    #error "AutoSar version of Tim_Icu_Drv_PBcfg.c and Tim_Icu_Drv.h are different"
#endif

#if ((TIM_ICU_DRV_PBCFG_C_SW_MAJOR_VERSION != TIM_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (TIM_ICU_DRV_PBCFG_C_SW_MINOR_VERSION != TIM_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Tim_Icu_Drv_PBcfg.c and Tim_Icu_Drv.h are different"
#endif


/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */



/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

void Icu_EventNotification(uint16 Channel, boolean OvfFlag);

void Icu_WakeupAndOvfNotification(uint16 Channel, boolean OvfFlag);

void Icu_SetupChannelStateHandler(uint16 Channel, uint8 Mask, boolean OptType);



#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/** 
 * @brief   Icu tim channel related configuration array
 */
const Tim_Icu_Drv_ChannelConfigType Tim_Icu_Drv_2ChannelConfig[1U] = 
{
    {
        (uint8)0,
        TIM_ICU_DRV_NO_MEAS,
        TIM_ICU_DRV_INPUT_RISING_EDGE,
        TIM_ICU_DRV_ONE_PULSE_CAPTURE,
        TIM_ICU_DRV_MODE_EDGE_COUNTER,
        TIM_ICU_DRV_DMA_DISABLE,
        TIM_ICU_DRV_INPUT_FILTER_1,
        (uint8)0,
        &Icu_WakeupAndOvfNotification,
        &Icu_SetupChannelStateHandler,
        NULL_PTR,
        NULL_PTR,
#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
        TIM_ICU_DRV_NO_TIMESTAMP,
#endif
    }
};
/** 
 * @brief   Icu tim channel global related configuration array
 */
static const Tim_Icu_Drv_GlobalConfigType Tim_Icu_Drv_2GlobalConfig = 
{
    (uint16)0,
    TIM_ICU_DRV_CLK_DIVIDE_1,
    TIM_ICU_DRV_FUNCTION_CLOCK,
    TIM_ICU_DRV_DEBUG_MODE_0,
};
/** 
 * @brief   Icu tim instance related configuration array
 */
const Tim_Icu_Drv_InstanceConfigType Tim_Icu_Drv_2InstanceConfig = 
{
    (uint8)1,
    &Tim_Icu_Drv_2GlobalConfig,
    &Tim_Icu_Drv_2ChannelConfig
};
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

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

/** @} end of group Icu_Drv */
/** @} end of group Icu_Module */

