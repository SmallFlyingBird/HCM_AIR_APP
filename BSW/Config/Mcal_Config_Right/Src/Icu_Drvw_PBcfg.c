/**************************************************************************************************/
/**
 * @file      : Icu_Drvw_PBcfg.c
 * @brief     : AUTOSAR Icu Drvw post-build configure source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drvw
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tim_Icu_Drv.h"
#include "Cmp_Icu_Drv.h"
#include "Port_Icu_Drv.h"
#include "Icu_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ICU_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define ICU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define ICU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define ICU_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define ICU_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define ICU_DRVW_PBCFG_C_SW_PATCH_VERSION            1U


#if (ICU_DRVW_PBCFG_C_VENDOR_ID != ICU_DRVW_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_PBcfg.c and Icu_Drvw.h have different"
#endif

#if ((ICU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != ICU_DRVW_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_PBcfg.c and Icu_Drvw.h are different"
#endif

#if ((ICU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != ICU_DRVW_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_DRVW_PBCFG_C_SW_PATCH_VERSION != ICU_DRVW_H_SW_PATCH_VERSION))
    #error "AutoSar version of Icu_Drvw_PBcfg.c and Icu_Drvw.h are different"
#endif

#if ((ICU_DRVW_PBCFG_C_SW_MAJOR_VERSION != ICU_DRVW_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_SW_MINOR_VERSION != ICU_DRVW_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_PBcfg.c and Icu_Drvw.h are different"
#endif

#if (ICU_DRVW_PBCFG_C_VENDOR_ID != TIM_ICU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_PBcfg.c and Tim_Icu_Drv_PBcfg.h have different"
#endif

#if ((ICU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_PBcfg.c and  Tim_Icu_Drv_PBcfg.h are different"
#endif

#if ((ICU_DRVW_PBCFG_C_SW_MAJOR_VERSION != TIM_ICU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_SW_MINOR_VERSION != TIM_ICU_DRV_PBCFG_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_PBcfg.c and  Tim_Icu_Drv_PBcfg.h are different"
#endif

#if (ICU_DRVW_PBCFG_C_VENDOR_ID != CMP_ICU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_PBcfg.c and Cmp_Icu_Drv_PBcfg.h have different"
#endif

#if ((ICU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_PBcfg.c and  Cmp_Icu_Drv_PBcfg.h are different"
#endif

#if ((ICU_DRVW_PBCFG_C_SW_MAJOR_VERSION != CMP_ICU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_SW_MINOR_VERSION != CMP_ICU_DRV_PBCFG_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_PBcfg.c and  Cmp_Icu_Drv_PBcfg.h are different"
#endif

#if (ICU_DRVW_PBCFG_C_VENDOR_ID != PORT_ICU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_PBcfg.c and Port_Icu_Drv_PBcfg.h have different"
#endif

#if ((ICU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Drvw_PBcfg.c and  Port_Icu_Drv_PBcfg.h are different"
#endif

#if ((ICU_DRVW_PBCFG_C_SW_MAJOR_VERSION != PORT_ICU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_PBCFG_C_SW_MINOR_VERSION != PORT_ICU_DRV_PBCFG_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Drvw_PBcfg.c and  Port_Icu_Drv_PBcfg.h are different"
#endif

#if ((ICU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_ICU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_DRVW_PBCFG_C_SW_PATCH_VERSION != PORT_ICU_DRV_PBCFG_H_SW_PATCH_VERSION))
    #error "Software version of Icu_Drvw_PBcfg.c and  Port_Icu_Drv_PBcfg.h are different"
#endif

/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */


/** @defgroup Global_VariableDefinition
 *  @{
 */

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/** 
 * @brief   Icu channels related configuration array
 */
const Icu_Drvw_HwChannelConfigType Icu_Drvw_HwChannelConfig[1U] =
{
    {
        ICU_DRVW_INSTANCE_TIM,
        (uint8)0,
        (uint16)0,
        {
            &Tim_Icu_Drv_0ChannelConfig[0U],
            NULL_PTR,
            NULL_PTR,
        }
    }

};


/** 
 * @brief   Icu instance related configuration array
 */
const Icu_Drvw_HwInstanceConfigType Icu_Drvw_HwInstanceConfig[1U] =
{
    {
        ICU_DRVW_INSTANCE_TIM,
        0U,
        (uint16)0U,
        {
            &Tim_Icu_Drv_0InstanceConfig,
            NULL_PTR,
            NULL_PTR,
        }
    }

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

/** @} end of group Icu_Drvw */
/** @} end of group Icu_Module */

