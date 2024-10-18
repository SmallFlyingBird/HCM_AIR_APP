/**************************************************************************************************/
/**
 * @file      : Icu_PBcfg.c
 * @brief     : AUTOSAR Icu post-build configure source file
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

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Icu.h"
#include "Icu_Drvw.h"

#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
#include "CDD_Dma.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define ICU_PBCFG_C_VENDOR_ID                   0x00B3U
#define ICU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define ICU_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define ICU_PBCFG_C_SW_MAJOR_VERSION            1U
#define ICU_PBCFG_C_SW_MINOR_VERSION            2U
#define ICU_PBCFG_C_SW_PATCH_VERSION            1U


#if (ICU_PBCFG_C_VENDOR_ID != ICU_VENDOR_ID)
    #error "Vendor ID Icu_PBcfg.c and Icu.h have different"
#endif

#if ((ICU_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_PBCFG_C_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_PBcfg.c and Icu.h are different"
#endif

#if ((ICU_PBCFG_C_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION) || \
        (ICU_PBCFG_C_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION))
    #error "AutoSar version of Icu_PBcfg.c and Icu.h are different"
#endif


#if ((ICU_PBCFG_C_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION) || \
        (ICU_PBCFG_C_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION))
    #error "Software version of Icu_PBcfg.c and Icu.h are different"
#endif

#if (ICU_PBCFG_C_VENDOR_ID != ICU_DRVW_H_VENDOR_ID)
    #error "Vendor ID Icu_PBcfg.c and Icu_Drvw.h have different"
#endif

#if ((ICU_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_PBCFG_C_AR_RELEASE_MINOR_VERSION != ICU_DRVW_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_PBcfg.c and  Icu_Drvw.h are different"
#endif

#if ((ICU_PBCFG_C_SW_MAJOR_VERSION != ICU_DRVW_H_SW_MAJOR_VERSION) || \
        (ICU_PBCFG_C_SW_MINOR_VERSION != ICU_DRVW_H_SW_MINOR_VERSION))
    #error "Software version of Icu_PBcfg.c and  Icu_Drvw.h are different"
#endif

#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
    #if (ICU_PBCFG_C_VENDOR_ID != CDD_DMA_VENDOR_ID)
        #error "Vendor ID Icu_PBcfg.c and CDD_Dma.h have different"
    #endif

    #if ((ICU_PBCFG_C_AR_RELEASE_MAJOR_VERSION != CDD_DMA_AR_RELEASE_MAJOR_VERSION) || \
            (ICU_PBCFG_C_AR_RELEASE_MINOR_VERSION != CDD_DMA_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Icu_PBcfg.c and CDD_Dma.h are different"
    #endif

    #if ((ICU_PBCFG_C_SW_MAJOR_VERSION != CDD_DMA_SW_MAJOR_VERSION) || \
            (ICU_PBCFG_C_SW_MINOR_VERSION != CDD_DMA_SW_MINOR_VERSION))
        #error "Software version of Icu_PBcfg.c and CDD_Dma.h are different"
    #endif
#endif


/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
        
#if (STD_ON == ICU_TIMESTAMP_DMA_USE)
    extern void Icu_TimestampDmaDoneHandler(Icu_ChannelType channel);
#endif
        
#if (STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE)
    extern void Icu_SignalMeasurementDmaDoneHandler(Icu_ChannelType channel, uint8 InstanceId);
#endif
        
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Private_TypeDefinition */



/** @defgroup Public_FunctionDeclaration
 *  @{
 */
 
#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
#endif


/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/** 
 * @brief   Icu channel related configuration array
 */
    /* SWS_Icu_00088 */
static const Icu_ChannelConfigType Icu_ChannelConfig[1U]=
{
    /* FAN_CTR_DIAG */
    {
        (1U << (uint32)ICU_MODE_EDGE_COUNTER),
        ICU_FALLING_EDGE,
        (boolean)FALSE,
        0U,
        NULL_PTR,
#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
        ICU_INVALID_DMACHANNEL,
#endif
#if (STD_ON == ICU_OVERFLOW_NOTIFICATION_API)
        NULL_PTR,
#endif
#if (STD_ON == ICU_WAKEUP_SOURCE_REPORT)
        (Icu_WakeupSourceType)0U,
#endif
        &Icu_Drvw_HwChannelConfig[0U]
    }
};


#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"


    



const Icu_ConfigType Icu_Config=
{
    1, 
    &Icu_ChannelConfig, 
    1,
    &Icu_Drvw_HwInstanceConfig,
    (uint8)0U
};



#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu */
/** @} end of group Icu_Module */

