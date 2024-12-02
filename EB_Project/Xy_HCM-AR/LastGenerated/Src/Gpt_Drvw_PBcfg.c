/**************************************************************************************************/
/**
 * @file      : Gpt_Drvw_PBcfg.c
 * @brief     : AUTOSAR Gpt - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drvw_Configuration
 *  @brief Gpt middle level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Gpt_Drvw.h"
#include "Rtc_Drv.h"
#include "Stim_Drv.h"
#include "Tim_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define GPT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define GPT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define GPT_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define GPT_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define GPT_DRVW_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if (GPT_DRVW_PBCFG_C_VENDOR_ID != GPT_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_PBcfg.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_DRVW_H_AR_RELEASE_MINOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_PBcfg.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_SW_MAJOR_VERSION != GPT_DRVW_H_SW_MAJOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_MINOR_VERSION != GPT_DRVW_H_SW_MINOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_PATCH_VERSION != GPT_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_PBcfg.c and Gpt_Drvw.h are different"
#endif

/* Check if current file and Tim_Drv header file are of the same vendor */
#if (GPT_DRVW_PBCFG_C_VENDOR_ID != TIM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_PBcfg.c and Tim_Drv.h are different"
#endif
/* Check if current file and Tim_Drv header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != TIM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != TIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != TIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_PBcfg.c and Tim_Drv.h are different"
#endif
/* Check if current file and Tim_Drv header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_SW_MAJOR_VERSION != TIM_DRV_H_SW_MAJOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_MINOR_VERSION != TIM_DRV_H_SW_MINOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_PATCH_VERSION != TIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_PBcfg.c and Tim_Drv.h are different"
#endif

/* Check if current file and Rtc_Drv header file are of the same vendor */
#if (GPT_DRVW_PBCFG_C_VENDOR_ID != RTC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_PBcfg.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != RTC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != RTC_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != RTC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_PBcfg.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_SW_MAJOR_VERSION != RTC_DRV_H_SW_MAJOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_MINOR_VERSION != RTC_DRV_H_SW_MINOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_PATCH_VERSION != RTC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_PBcfg.c and Rtc_Drv.h are different"
#endif

/* Check if current file and Stim_Drv header file are of the same vendor */
#if (GPT_DRVW_PBCFG_C_VENDOR_ID != STIM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_PBcfg.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != STIM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != STIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (GPT_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != STIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw_PBcfg.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same vendor */
#if ((GPT_DRVW_PBCFG_C_SW_MAJOR_VERSION != STIM_DRV_H_SW_MAJOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_MINOR_VERSION != STIM_DRV_H_SW_MINOR_VERSION) ||                 \
     (GPT_DRVW_PBCFG_C_SW_PATCH_VERSION != STIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw_PBcfg.c and Stim_Drv.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"


/** 

* @brief   Gpt instance related configuration array

*/
const Gpt_Drvw_HwInstanceConfigType Gpt_Drvw_InstanceConfig[1U]=
{

    {
        GPT_DRVW_STIM_MODULE, /*!< IP type */
        0U,/*!< Stim instance type */
        {
            NULL_PTR,/*!< Pointer of the stim instance configuration*/
        }
    }
};


/** 

* @brief   Gpt channels related configuration array

*/
const Gpt_Drvw_HwChannelConfigType Gpt_Drvw_ChannelConfig[3U] =
{
    /*!< GptChannelConfiguration_5MS */
    {
        GPT_DRVW_STIM_MODULE, /*!< IP type */
        0U, /*!< Instance */
        0U, /*!< Channel */
        {
            NULL_PTR, /*!< Pointer of the channel configuration*/
            NULL_PTR, /*!< Pointer of the channel configuration*/
            &Stim_Drv_ChannelConfig[0U] /*!< Pointer of the channel configuration*/
        }
    }
    ,
    /*!< GptChannelConfiguration_10MS */
    {
        GPT_DRVW_STIM_MODULE, /*!< IP type */
        0U, /*!< Instance */
        1U, /*!< Channel */
        {
            NULL_PTR, /*!< Pointer of the channel configuration*/
            NULL_PTR, /*!< Pointer of the channel configuration*/
            &Stim_Drv_ChannelConfig[1U] /*!< Pointer of the channel configuration*/
        }
    }
    ,
    /*!< GptChannelConfiguration_100MS */
    {
        GPT_DRVW_STIM_MODULE, /*!< IP type */
        0U, /*!< Instance */
        2U, /*!< Channel */
        {
            NULL_PTR, /*!< Pointer of the channel configuration*/
            NULL_PTR, /*!< Pointer of the channel configuration*/
            &Stim_Drv_ChannelConfig[2U] /*!< Pointer of the channel configuration*/
        }
    }

};


#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt_Drvw_Configuration */

/** @} end of group Gpt_Module */
