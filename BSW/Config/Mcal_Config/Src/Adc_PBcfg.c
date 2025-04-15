/**************************************************************************************************/
/**
 * @file      : Adc_PBcfg.c
 * @brief     : Adc AUTOSAR level - Post-Build(PB) configuration file code template
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

/** @addtogroup Adc_Configuration
 *  @brief Adc AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Adc.h"
#include "Adc_Drv.h"
#include "Tdg_Adc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ADC_PBCFG_C_VENDOR_ID                   0x00B3U
#define ADC_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define ADC_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define ADC_PBCFG_C_SW_MAJOR_VERSION            1U
#define ADC_PBCFG_C_SW_MINOR_VERSION            2U
#define ADC_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Adc.h are the same vendor */
#if (ADC_PBCFG_C_VENDOR_ID != ADC_VENDOR_ID)
    #error "Adc_PBcfg.c and Adc.h have different vendor ids"
#endif

/* Check if current file and Adc.h are the same Autosar version */
#if ((ADC_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_PBCFG_C_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_PBCFG_C_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

/* Check if current file and Adc.h are the same Software version */
#if ((ADC_PBCFG_C_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION) || \
     (ADC_PBCFG_C_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION) || \
     (ADC_PBCFG_C_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same vendor */
#if (ADC_PBCFG_C_VENDOR_ID != ADC_DRV_H_VENDOR_ID)
    #error "Adc_PBcfg.c and Adc_Drv.h have different vendor ids"
#endif

/* Check if current file and Adc_Drv.h are the same Autosar version */
#if ((ADC_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_PBCFG_C_AR_RELEASE_MINOR_VERSION != ADC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_PBCFG_C_AR_RELEASE_REVISION_VERSION != ADC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Software version */
#if ((ADC_PBCFG_C_SW_MAJOR_VERSION != ADC_DRV_H_SW_MAJOR_VERSION) || \
     (ADC_PBCFG_C_SW_MINOR_VERSION != ADC_DRV_H_SW_MINOR_VERSION) || \
     (ADC_PBCFG_C_SW_PATCH_VERSION != ADC_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same vendor */
#if (ADC_PBCFG_C_VENDOR_ID != TDG_ADC_DRV_H_VENDOR_ID)
    #error "Adc_PBcfg.c and Tdg_Adc_Drv.h have different vendor ids"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Autosar version */
#if ((ADC_PBCFG_C_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_PBCFG_C_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_PBCFG_C_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Tdg_Adc_Drv.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv.h are the same Software version */
#if ((ADC_PBCFG_C_SW_MAJOR_VERSION != TDG_ADC_DRV_H_SW_MAJOR_VERSION) || \
     (ADC_PBCFG_C_SW_MINOR_VERSION != TDG_ADC_DRV_H_SW_MINOR_VERSION) || \
     (ADC_PBCFG_C_SW_PATCH_VERSION != TDG_ADC_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Tdg_Adc_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"
/**
 * @brief  Array for Adc group Result Buffer.
 */
static Adc_ValueGroupType * Adc_ResultsBufferPtr[4];
#define ADC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
 * @brief Channel Assignment of Group: Adc_ChannelAssignmentOfGroup_0[ADC_CFG_GROUP_0_CHANNEL_NUM]
 */
static const ADC_Drv_PositiveChannelType Adc_ChannelAssignmentOfGroup_0[ADC_CFG_GROUP_0_CHANNEL_NUM] =
{
    ADC_DRV_P_CH14,
    ADC_DRV_P_CH11,
    ADC_DRV_P_CH9,
    ADC_DRV_P_CH10,
    ADC_DRV_P_CH8,
    ADC_DRV_P_CH13
};

/**
 * @brief Channel Assignment of Group: Adc_ChannelAssignmentOfGroup_1[ADC_CFG_GROUP_1_CHANNEL_NUM]
 */
static const ADC_Drv_PositiveChannelType Adc_ChannelAssignmentOfGroup_1[ADC_CFG_GROUP_1_CHANNEL_NUM] =
{
    ADC_DRV_P_CH3,
    ADC_DRV_P_CH0
};

/**
 * @brief Channel Assignment of Group: Adc_ChannelAssignmentOfGroup_2[ADC_CFG_GROUP_2_CHANNEL_NUM]
 */
static const ADC_Drv_PositiveChannelType Adc_ChannelAssignmentOfGroup_2[ADC_CFG_GROUP_2_CHANNEL_NUM] =
{
    ADC_DRV_P_CH7
};

/**
 * @brief Channel Assignment of Group: Adc_ChannelAssignmentOfGroup_3[ADC_CFG_GROUP_3_CHANNEL_NUM]
 */
static const ADC_Drv_PositiveChannelType Adc_ChannelAssignmentOfGroup_3[ADC_CFG_GROUP_3_CHANNEL_NUM] =
{
    ADC_DRV_P_CH15
};



/**
 * @brief ADC HWUnit Configuration: Adc_HWUnitConfig_0
 */
static const Adc_HWUnitConfigType Adc_HWUnitConfig_0 =
{
    3U, /*!< GroupNum */
    9U, /*!< ChannelNum */
    (uint8)ADC_DRV_INTERRUPT, /*!< TransferMode */
    ADC_DRV_INVALID_DMA_CHANNEL_ID, /*!< DmaChannel */
    ADC_DRV_RESOLUTION_12BIT, /*!< Resolution */
    (boolean)FALSE, /*!< WithoutInterrupt */
    &Adc_Drv_Config_0,
    &Tdg_Adc_Drv_Config_0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,Adc_ChannelLimitCheckConfigList_0 /*!< ChannelLimitCheckingConfigs */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
};

/**
 * @brief ADC HWUnit Configuration: Adc_HWUnitConfig_1
 */
static const Adc_HWUnitConfigType Adc_HWUnitConfig_1 =
{
    1U, /*!< GroupNum */
    1U, /*!< ChannelNum */
    (uint8)ADC_DRV_INTERRUPT, /*!< TransferMode */
    ADC_DRV_INVALID_DMA_CHANNEL_ID, /*!< DmaChannel */
    ADC_DRV_RESOLUTION_12BIT, /*!< Resolution */
    (boolean)FALSE, /*!< WithoutInterrupt */
    &Adc_Drv_Config_1,
    &Tdg_Adc_Drv_Config_1
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,Adc_ChannelLimitCheckConfigList_1 /*!< ChannelLimitCheckingConfigs */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
};



/**
 * @brief ADC HWUnit Configuration: Adc_HWUnitConfigList[2]
 */
static const Adc_HWUnitConfigListType Adc_HWUnitConfigList[2] =
{
    {&Adc_HWUnitConfig_0},
    {&Adc_HWUnitConfig_1}
};



/**
 * @brief Defines all ADC groups configuration.
 */
static const Adc_GroupConfigType Adc_GroupConfigList[] =
{
    /*!< Group0 */
    {
        0, /*!< GroupId */
        (Adc_HwUnitType)0U, /*!< HwUnitId */
        ADC_ACCESS_MODE_SINGLE, /*!< AccessMode */
        ADC_CONV_MODE_ONESHOT, /*!< ConversionMode */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        0U, /*!< Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        ADC_GROUP_REPL_ABORT_RESTART, /*!< ReplacementMode */
        ADC_TRIGG_SRC_SW, /*!< TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        ADC_TRIGG_SRC_SW, /*!< HwTriggerSource */
        ADC_HW_TRIG_RISING_EDGE, /*!< TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GROUP_NOTIF_CAPABILITY)
        &ADC0_CallBack_Group0, /*!< Notification function*/
#endif /* (STD_ON == ADC_GROUP_NOTIF_CAPABILITY) */
        Adc_ResultsBufferPtr, /*!< ResultsBufferPtr */
        ADC_STREAM_BUFFER_LINEAR, /*!< Group Streaming Buffer Mode */
        (Adc_StreamNumSampleType)1U, /*!< Number of streaming samples */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        (boolean)FALSE, /*!< GroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        (Adc_ChannelIndexType)ADC_CFG_GROUP_0_CHANNEL_NUM, /*!< AssignedChannelCount */
        Adc_ChannelAssignmentOfGroup_0, /*!< AssignedChannelList */
        &Adc_Drv_GroupConfig_0, /*!< AdcGroupConfigPtr */
        &Tdg_Adc_Drv_GroupConfig_0 /*!< TdgGroupConfigPtr */
    },
    /*!< Group1 */
    {
        1, /*!< GroupId */
        (Adc_HwUnitType)0U, /*!< HwUnitId */
        ADC_ACCESS_MODE_SINGLE, /*!< AccessMode */
        ADC_CONV_MODE_ONESHOT, /*!< ConversionMode */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        0U, /*!< Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        ADC_GROUP_REPL_ABORT_RESTART, /*!< ReplacementMode */
        ADC_TRIGG_SRC_SW, /*!< TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        ADC_TRIGG_SRC_SW, /*!< HwTriggerSource */
        ADC_HW_TRIG_RISING_EDGE, /*!< TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GROUP_NOTIF_CAPABILITY)
        &ADC0_CallBack_Group1, /*!< Notification function*/
#endif /* (STD_ON == ADC_GROUP_NOTIF_CAPABILITY) */
        Adc_ResultsBufferPtr, /*!< ResultsBufferPtr */
        ADC_STREAM_BUFFER_LINEAR, /*!< Group Streaming Buffer Mode */
        (Adc_StreamNumSampleType)1U, /*!< Number of streaming samples */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        (boolean)FALSE, /*!< GroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        (Adc_ChannelIndexType)ADC_CFG_GROUP_1_CHANNEL_NUM, /*!< AssignedChannelCount */
        Adc_ChannelAssignmentOfGroup_1, /*!< AssignedChannelList */
        &Adc_Drv_GroupConfig_1, /*!< AdcGroupConfigPtr */
        &Tdg_Adc_Drv_GroupConfig_1 /*!< TdgGroupConfigPtr */
    },
    /*!< Group2 */
    {
        2, /*!< GroupId */
        (Adc_HwUnitType)1U, /*!< HwUnitId */
        ADC_ACCESS_MODE_SINGLE, /*!< AccessMode */
        ADC_CONV_MODE_ONESHOT, /*!< ConversionMode */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        0U, /*!< Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        ADC_GROUP_REPL_ABORT_RESTART, /*!< ReplacementMode */
        ADC_TRIGG_SRC_SW, /*!< TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        ADC_TRIGG_SRC_SW, /*!< HwTriggerSource */
        ADC_HW_TRIG_RISING_EDGE, /*!< TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GROUP_NOTIF_CAPABILITY)
        &ADC1_CallBack_Group0, /*!< Notification function*/
#endif /* (STD_ON == ADC_GROUP_NOTIF_CAPABILITY) */
        Adc_ResultsBufferPtr, /*!< ResultsBufferPtr */
        ADC_STREAM_BUFFER_LINEAR, /*!< Group Streaming Buffer Mode */
        (Adc_StreamNumSampleType)1U, /*!< Number of streaming samples */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        (boolean)FALSE, /*!< GroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        (Adc_ChannelIndexType)ADC_CFG_GROUP_2_CHANNEL_NUM, /*!< AssignedChannelCount */
        Adc_ChannelAssignmentOfGroup_2, /*!< AssignedChannelList */
        &Adc_Drv_GroupConfig_2, /*!< AdcGroupConfigPtr */
        &Tdg_Adc_Drv_GroupConfig_2 /*!< TdgGroupConfigPtr */
    },
    /*!< Group3 */
    {
        3, /*!< GroupId */
        (Adc_HwUnitType)0U, /*!< HwUnitId */
        ADC_ACCESS_MODE_SINGLE, /*!< AccessMode */
        ADC_CONV_MODE_ONESHOT, /*!< ConversionMode */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        0U, /*!< Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        ADC_GROUP_REPL_ABORT_RESTART, /*!< ReplacementMode */
        ADC_TRIGG_SRC_SW, /*!< TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
        ADC_TRIGG_SRC_SW, /*!< HwTriggerSource */
        ADC_HW_TRIG_RISING_EDGE, /*!< TriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GROUP_NOTIF_CAPABILITY)
        &ADC0_CallBack_Group2, /*!< Notification function*/
#endif /* (STD_ON == ADC_GROUP_NOTIF_CAPABILITY) */
        Adc_ResultsBufferPtr, /*!< ResultsBufferPtr */
        ADC_STREAM_BUFFER_LINEAR, /*!< Group Streaming Buffer Mode */
        (Adc_StreamNumSampleType)1U, /*!< Number of streaming samples */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        (boolean)FALSE, /*!< GroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        (Adc_ChannelIndexType)ADC_CFG_GROUP_3_CHANNEL_NUM, /*!< AssignedChannelCount */
        Adc_ChannelAssignmentOfGroup_3, /*!< AssignedChannelList */
        &Adc_Drv_GroupConfig_3, /*!< AdcGroupConfigPtr */
        &Tdg_Adc_Drv_GroupConfig_3 /*!< TdgGroupConfigPtr */
    },
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/**
* @brief ADC Configuration
*/
static const Adc_ConfigType Adc_Config=
{
    Adc_HWUnitConfigList, /*!< Pointer to Adc HW Unit Configuration */
    Adc_GroupConfigList, /*!< Pointer to Group configurations */
    ADC_CFG_GROUP_NUM, /*! GroupCount */
    (uint32)(0U) /*!< CoreId */
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_PTR
#include "Adc_MemMap.h"
/**
* @brief Pointer to ADC Configuration
*/
const Adc_ConfigType * const Adc_PreDefinedConfigPtr[ADC_MAX_PARTITIONS] =
{
    &Adc_Config
};

#define ADC_STOP_SEC_CONFIG_DATA_PTR
#include "Adc_MemMap.h"

/** @} end of group Global_VariableDefinition */

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

/** @} end of group Adc_Configuration */

/** @} end of group Adc_Module */
