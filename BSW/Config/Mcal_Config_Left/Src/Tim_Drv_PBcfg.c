/**************************************************************************************************/
/**
 * @file      : Tim_Drv_PBcfg.c  
 * @brief     : Gpt low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drv_Configuration
 *  @brief Gpt low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tim_Drv.h"
#include "Gpt_Irq.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define TIM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define TIM_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define TIM_DRV_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Drv header file are of the same vendor */
#if (TIM_DRV_PBCFG_C_VENDOR_ID != TIM_DRV_H_VENDOR_ID)
    #error "Tim_Drv_PBcfg.c and Tim_Drv.h have different vendor ids"
#endif
/* Check if current file and Tim_Drv header file are of the same vendor */
#if ((TIM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != TIM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != TIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||  \
     (TIM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != TIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Tim_Drv_PBcfg.c and Tim_Drv.h are different"
#endif
/* Check if current file and Tim_Drv header file are of the same Software version */
#if ((TIM_DRV_PBCFG_C_SW_MAJOR_VERSION != TIM_DRV_H_SW_MAJOR_VERSION) || \
     (TIM_DRV_PBCFG_C_SW_MINOR_VERSION != TIM_DRV_H_SW_MINOR_VERSION) || \
     (TIM_DRV_PBCFG_C_SW_PATCH_VERSION != TIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Tim_Drv_PBcfg.c and Tim_Drv.h are different"
#endif

/* Check if current file and Gpt_Irq header file are of the same vendor */
#if (TIM_DRV_PBCFG_C_VENDOR_ID != GPT_IRQ_H_VENDOR_ID)
    #error "Tim_Drv_PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if current file and Gpt_Irq header file are of the same vendor */
#if ((TIM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != GPT_IRQ_H_AR_RELEASE_MINOR_VERSION) ||  \
     (TIM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != GPT_IRQ_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Tim_Drv_PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if current file and Gpt_Irq header file are of the same Software version */
#if ((TIM_DRV_PBCFG_C_SW_MAJOR_VERSION != GPT_IRQ_H_SW_MAJOR_VERSION) || \
     (TIM_DRV_PBCFG_C_SW_MINOR_VERSION != GPT_IRQ_H_SW_MINOR_VERSION) || \
     (TIM_DRV_PBCFG_C_SW_PATCH_VERSION != GPT_IRQ_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Tim_Drv_PBcfg.c and Gpt_Irq.h are different"
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

const Tim_Drv_InstanceConfigType Tim_Drv_1_InstanceConfig = 
{
    (boolean)(FALSE), /*!< Freeze Disable */
    TIM_DRV_CLK_SOURCE_FUNCTION,
#if (TIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
    (Tim_Drv_PrescalerType)1U, /*!< Clock alternate prescaler bit value */
#endif
    (Tim_Drv_PrescalerType)3U, /*!< Clock prescaler bit value */
    TIM_DRV_COUNTING_UP
};


const Tim_Drv_ChannelConfigType Tim_Drv_1_ChannelConfig[4U] = 
{
    {
        0U,/*!< Timer channel number */
        TIM_DRV_CLK_SOURCE_FUNCTION,
        &Gpt_TimeMatchCallback, /*!< Timer Interrupt Callback */
        (uint8)0U /*!< Timer callback parameters */
    }
    ,
    {
        1U,/*!< Timer channel number */
        TIM_DRV_CLK_SOURCE_FUNCTION,
        &Gpt_TimeMatchCallback, /*!< Timer Interrupt Callback */
        (uint8)1U /*!< Timer callback parameters */
    }
    ,
    {
        2U,/*!< Timer channel number */
        TIM_DRV_CLK_SOURCE_FUNCTION,
        &Gpt_TimeMatchCallback, /*!< Timer Interrupt Callback */
        (uint8)2U /*!< Timer callback parameters */
    }
    ,
    {
        3U,/*!< Timer channel number */
        TIM_DRV_CLK_SOURCE_FUNCTION,
        &Gpt_TimeMatchCallback, /*!< Timer Interrupt Callback */
        (uint8)3U /*!< Timer callback parameters */
    }
};



#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Drv_Configuration */

/** @} end of group Tim_Module */
