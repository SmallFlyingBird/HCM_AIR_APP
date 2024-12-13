/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv_PBcfg.c  
 * @brief     : Tdg Adc low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Tdg_Adc_Drv_Configuration
 *  @brief Tdg Adc low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Tdg_Adc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TDG_ADC_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Tdg_Adc_Drv.h are the same vendor */
#if (TDG_ADC_DRV_PBCFG_C_VENDOR_ID != TDG_ADC_DRV_H_VENDOR_ID)
    #error "Tdg_Adc_Drv_PBcfg.c and Tdg_Adc_Drv.h have different vendor ids"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Autosar version */
#if ((TDG_ADC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TDG_ADC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (TDG_ADC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Tdg_Adc_Drv_PBcfg.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Software version */
#if ((TDG_ADC_DRV_PBCFG_C_SW_MAJOR_VERSION != TDG_ADC_DRV_H_SW_MAJOR_VERSION) || \
     (TDG_ADC_DRV_PBCFG_C_SW_MINOR_VERSION != TDG_ADC_DRV_H_SW_MINOR_VERSION) || \
     (TDG_ADC_DRV_PBCFG_C_SW_PATCH_VERSION != TDG_ADC_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Tdg_Adc_Drv_PBcfg.c and Tdg_Adc_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/**
 * @brief TDG Channel delay output of Group0 Channel0 configuration: Tdg_Adc_Drv_DelayOutputConfig_Group0_Channel0.
 */
static const Tdg_Adc_Drv_DelayOutputConfigType Tdg_Adc_Drv_DelayOutputConfig_Group0_Channel0[1U] =
{
    {
        TDG_ADC_DRV_DELAY_OUTPUT_0, /*!< DelayOutputId */
        10U, /*!< Offset */
        TRUE /*!< Enable, hard code */
    }
};

/**
 * @brief TDG Channel delay output of Group1 Channel0 configuration: Tdg_Adc_Drv_DelayOutputConfig_Group1_Channel0.
 */
static const Tdg_Adc_Drv_DelayOutputConfigType Tdg_Adc_Drv_DelayOutputConfig_Group1_Channel0[1U] =
{
    {
        TDG_ADC_DRV_DELAY_OUTPUT_0, /*!< DelayOutputId */
        10U, /*!< Offset */
        TRUE /*!< Enable, hard code */
    }
};

/**
 * @brief TDG Channel delay output of Group2 Channel0 configuration: Tdg_Adc_Drv_DelayOutputConfig_Group2_Channel0.
 */
static const Tdg_Adc_Drv_DelayOutputConfigType Tdg_Adc_Drv_DelayOutputConfig_Group2_Channel0[1U] =
{
    {
        TDG_ADC_DRV_DELAY_OUTPUT_0, /*!< DelayOutputId */
        10U, /*!< Offset */
        TRUE /*!< Enable, hard code */
    }
};


/**
 * @brief ADC Driver Group0 TDG channel Config: Adc_Drv_TdgChannelConfig_Group0[1].
 */
static const Tdg_Adc_Drv_ChannelConfigType Adc_Drv_TdgChannelConfig_Group0[1] =
{
    {
        TDG_ADC_DRV_CHANNEL_0, /*!< ChannelId */
        1U, /*!< delay output complete interrupt delay */
        1U, /*!< number of delya output point */
        Tdg_Adc_Drv_DelayOutputConfig_Group0_Channel0 /*!< pointer to delay output config */
    }
};

/**
 * @brief ADC Driver Group1 TDG channel Config: Adc_Drv_TdgChannelConfig_Group1[1].
 */
static const Tdg_Adc_Drv_ChannelConfigType Adc_Drv_TdgChannelConfig_Group1[1] =
{
    {
        TDG_ADC_DRV_CHANNEL_0, /*!< ChannelId */
        1U, /*!< delay output complete interrupt delay */
        1U, /*!< number of delya output point */
        Tdg_Adc_Drv_DelayOutputConfig_Group1_Channel0 /*!< pointer to delay output config */
    }
};

/**
 * @brief ADC Driver Group2 TDG channel Config: Adc_Drv_TdgChannelConfig_Group2[1].
 */
static const Tdg_Adc_Drv_ChannelConfigType Adc_Drv_TdgChannelConfig_Group2[1] =
{
    {
        TDG_ADC_DRV_CHANNEL_0, /*!< ChannelId */
        1U, /*!< delay output complete interrupt delay */
        1U, /*!< number of delya output point */
        Tdg_Adc_Drv_DelayOutputConfig_Group2_Channel0 /*!< pointer to delay output config */
    }
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
 * @brief TDG Driver Config for Hardware Unit ADC0: Tdg_Adc_Drv_Config_0.
 */
const Tdg_Adc_Drv_ConfigType Tdg_Adc_Drv_Config_0 =
{
    TDG_ADC_DRV_UPDATE_IMMEDIATELY, /* UpdateMode */
    (Tdg_Adc_Drv_ClockDivideType)1U, /* PrescalerDivider */
    TDG_ADC_DRV_TRIG_SW, /* TriggerSource */
    TDG_ADC_DRV_CLEAR_DELAY, /* ClearMode */
    TDG_ADC_DRV_COUNT_SINGLE, /* CountMode */
    65535U, /* ModulateValue */
    NULL_PTR, /* CompDelayNotifPtr */
    NULL_PTR /* ErrorNotifPtr */
};

/**
 * @brief TDG Driver Config for Hardware Unit ADC1: Tdg_Adc_Drv_Config_1.
 */
const Tdg_Adc_Drv_ConfigType Tdg_Adc_Drv_Config_1 =
{
    TDG_ADC_DRV_UPDATE_IMMEDIATELY, /* UpdateMode */
    (Tdg_Adc_Drv_ClockDivideType)1U, /* PrescalerDivider */
    TDG_ADC_DRV_TRIG_SW, /* TriggerSource */
    TDG_ADC_DRV_CLEAR_DELAY, /* ClearMode */
    TDG_ADC_DRV_COUNT_SINGLE, /* CountMode */
    65535U, /* ModulateValue */
    NULL_PTR, /* CompDelayNotifPtr */
    NULL_PTR /* ErrorNotifPtr */
};

/**
 * @brief TDG Drv Group0 Config: Tdg_Adc_Drv_GroupConfig_0.
 */
const Tdg_Adc_Drv_GroupConfigType Tdg_Adc_Drv_GroupConfig_0 =
{
    (boolean)TRUE, /*!< Is Software trigger */
    1U, /*!< number of TDG channel */
    &Adc_Drv_TdgChannelConfig_Group0 /*!< Pointer to TDG channe configuration */
};
/**
 * @brief TDG Drv Group1 Config: Tdg_Adc_Drv_GroupConfig_1.
 */
const Tdg_Adc_Drv_GroupConfigType Tdg_Adc_Drv_GroupConfig_1 =
{
    (boolean)TRUE, /*!< Is Software trigger */
    1U, /*!< number of TDG channel */
    &Adc_Drv_TdgChannelConfig_Group1 /*!< Pointer to TDG channe configuration */
};
/**
 * @brief TDG Drv Group2 Config: Tdg_Adc_Drv_GroupConfig_2.
 */
const Tdg_Adc_Drv_GroupConfigType Tdg_Adc_Drv_GroupConfig_2 =
{
    (boolean)TRUE, /*!< Is Software trigger */
    1U, /*!< number of TDG channel */
    &Adc_Drv_TdgChannelConfig_Group2 /*!< Pointer to TDG channe configuration */
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
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

/** @} end of group Tdg_Adc_Drv_Configuration */

/** @} end of group Adc_Module */
