/**************************************************************************************************/
/**
 * @file      : Adc_Drv_Types.h
 * @brief     : Adc low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_DRV_TYPES_H
#define ADC_DRV_TYPES_H

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

#include "Std_Types.h"
#include "McalLib.h"
#include "Adc_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define ADC_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define ADC_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Adc_Drv_Cfg.h are the same vendor */
#if (ADC_DRV_TYPES_H_VENDOR_ID != ADC_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Adc_Drv_Types.h and Adc_Drv_Cfg.h are different"
#endif

/* Check if current file and Adc_Drv_Cfg.h are the same Autosar version */
#if ((ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != ADC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != ADC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != ADC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Drv_Types.h and Adc_Drv_Cfg.h are different"
#endif

/* Check if current file and Adc_Drv_Cfg.h are the same Software version */
#if ((ADC_DRV_TYPES_H_SW_MAJOR_VERSION != ADC_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (ADC_DRV_TYPES_H_SW_MINOR_VERSION != ADC_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (ADC_DRV_TYPES_H_SW_PATCH_VERSION != ADC_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Drv_Types.h and Adc_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Adc_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Adc_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief ADC conversion resolution selection
 *
 */
typedef enum
{
    ADC_DRV_RESOLUTION_12BIT = 0x00U, /*!< 12-bit resolution mode */
    ADC_DRV_RESOLUTION_10BIT = 0x01U, /*!< 10-bit resolution mode */
    ADC_DRV_RESOLUTION_8BIT = 0x02U   /*!< 8-bit resolution mode */
} Adc_Drv_ResolutionType;

/**
 * @brief  ADC Hardware average selection
 *
 */
typedef enum
{
    ADC_DRV_AVG_DISABLE =
        0x00U, /*!< ADC average function is disabled, 1 conversion per conversion data */
    ADC_DRV_AVG_4_CONV = 0x01U,  /*!< 4 conversions per conversion data */
    ADC_DRV_AVG_8_CONV = 0x02U,  /*!< 8 conversions per conversion data */
    ADC_DRV_AVG_16_CONV = 0x03U, /*!< 16 conversions per conversion data */
    ADC_DRV_AVG_32_CONV = 0x04U  /*!< 32 conversions per conversion data */
} Adc_Drv_AvgSelectType;

/**
 * @brief ADC trigger type selection
 */
typedef enum
{
    ADC_DRV_TRIGGER_SOFTWARE = 0x00U, /*!< Software trigger. */
    ADC_DRV_TRIGGER_HARDWARE = 0x01U, /*!< Hardware trigger. */
    ADC_DRV_TRIGGER_TDG = 0x02U       /*!< TDG trigger, need configuration of command buffer. */
} Adc_Drv_TriggerType;

/**
 * @brief ADC voltage reference selection
 */
typedef enum
{
    ADC_DRV_VREF_EXTERNAL = 0x00U, /*!< External Vref_H, Vref_L reference. */
    ADC_DRV_VREF_INTERNAL = 0x01U  /*!< Internal Vref_H to 5V, Vref_L to 0V reference. */
} Adc_Drv_VRefSelType;

/**
 *  @brief ADC current reference selection
 */
typedef enum
{
    ADC_DRV_IREF_EXTERNAL = 0U, /*!< IRef External reference selected*/
    ADC_DRV_IREF_INTERNAL       /*!< IRef Internal reference selected*/
} Adc_Drv_IRefSelType;

/**
 *  @brief ADC conversion mode
 */
typedef enum
{
    ADC_DRV_CONVERSION_SINGLE = 0x00U,    /*!< Single conversion */
    ADC_DRV_CONVERSION_CONTINUOUS = 0x01U /*!< Continuous conversions */
} ADC_Drv_ConversionType;

/**
 *  @brief ADC compare mode
 */
typedef enum
{
    ADC_DRV_COMPARE_MODE_DISABLED = 0x00U,    /*!< compare disabled */
    ADC_DRV_COMPARE_MODE_LESS_CVL,            /*!< compare less than CVL */
    ADC_DRV_COMPARE_MODE_GREATER_CVL,         /*!< ADC compare greater than CVL */
    ADC_DRV_COMPARE_MODE_EQUAL_CVL,           /*!< ADC compare equal to CVL */
    ADC_DRV_COMPARE_MODE_WITHIN_CVL_CVH,      /*!< ADC compare winthin range [CVL,CVH] */
    ADC_DRV_COMPARE_MODE_OUT_OF_RANGE_CVL_CVH /*!< ADC compare out of range[0,CVL) U (CVH,FULL] */
} ADC_Drv_CompareModeType;

/**
 *  @brief ADC Positive channel selection definition
 */
typedef enum
{
    ADC_DRV_P_CH0 = 0U,   /*!< Single mode, channel[0] and vssa */
    ADC_DRV_P_CH1 = 1U,   /*!< Single mode, channel[1] and vssa */
    ADC_DRV_P_CH2 = 2U,   /*!< Single mode, channel[2] and vssa */
    ADC_DRV_P_CH3 = 3U,   /*!< Single mode, channel[3] and vssa */
    ADC_DRV_P_CH4 = 4U,   /*!< Single mode, channel[4] and vssa */
    ADC_DRV_P_CH5 = 5U,   /*!< Single mode, channel[5] and vssa */
    ADC_DRV_P_CH6 = 6U,   /*!< Single mode, channel[6] and vssa */
    ADC_DRV_P_CH7 = 7U,   /*!< Single mode, channel[7] and vssa */
    ADC_DRV_P_CH8 = 8U,   /*!< Single mode, channel[8] and vssa */
    ADC_DRV_P_CH9 = 9U,   /*!< Single mode, channel[9] and vssa */
    ADC_DRV_P_CH10 = 10U, /*!< Single mode, channel[10] and vssa */
    ADC_DRV_P_CH11 = 11U, /*!< Single mode, channel[11] and vssa */
    ADC_DRV_P_CH12 = 12U, /*!< Single mode, channel[12] and vssa */
    ADC_DRV_P_CH13 = 13U, /*!< Single mode, channel[13] and vssa */
    ADC_DRV_P_CH14 = 14U, /*!< Single mode, channel[14] and vssa */
    ADC_DRV_P_CH15 = 15U, /*!< Single mode, channel[15] and vssa */
    ADC_DRV_P_CH16 = 16U, /*!< Single mode, channel[16] and vssa */
    ADC_DRV_P_CH17 = 17U, /*!< Single mode, channel[17] and vssa */
    ADC_DRV_P_CH18 = 18U, /*!< Single mode, channel[18] and vssa */
    ADC_DRV_P_CH19 = 19U, /*!< Single mode, channel[19] and vssa */
    ADC_DRV_P_CH20 = 20U, /*!< bandgap */
    ADC_DRV_P_CH25 = 25U, /*!< DAC */
    ADC_DRV_P_CH28 = 28U, /*!< ldo_core, only ADC0 supports this channel */
    ADC_DRV_P_CH29 = 29U, /*!< ldo_flash, only ADC0 supports this channel */
    ADC_DRV_P_CH30 = 30U  /*!< ldo_clk, only ADC0 supports this channel */
} ADC_Drv_PositiveChannelType;

/**
 *  @brief ADC interrupt type definition
 */
typedef enum
{
    ADC_DRV_FWM_INT = 0U,   /*!< ADC fifo watermark interrupt */
    ADC_DRV_FOF_INT = 1U,   /*!< ADC fifo overflow interrupt */
    ADC_DRV_TCOMP_INT = 2U, /*!< ADC complete interrupt */
    ADC_DRV_CMP_INT = 3U,   /*!< ADC compare interrupt */
    ADC_DRV_TC_ERR_INT = 5U /*!< ADC trigger conflict error interrupt*/
} ADC_Drv_InterruptType;

/**
 *  @brief ADC status type definition
 */
typedef enum
{
    ADC_DRV_STATUS_FWM_INT = 0U, /*!< ADC fifo watermark status */
    ADC_DRV_STATUS_FOF_INT,      /*!< ADC fifo overflow status */
    ADC_DRV_STATUS_TCOMP_INT,    /*!< ADC complete interrupt status */
    ADC_DRV_STATUS_CMP_INT,      /*!< ADC compare interrupt status */
    ADC_DRV_STATUS_DMA_REQ,      /*!< ADC dma request status */
    ADC_DRV_STATUS_FIFO_RDY,     /*!< ADC result fifo ready status */
    ADC_DRV_STATUS_CAL_RDY,      /*!< ADC calibration ready status */
    ADC_DRV_STATUS_ACTIVE,       /*!< ADC active status, 0: idle; 1: processing a conversion */
    ADC_DRV_STATUS_LOOP_IDLE,    /*!< ADC loop mode state machine return to idle state */
    ADC_DRV_STATUS_TC_ERR_INT    /*!< ADC trigger conflict error */
} ADC_Drv_StatusType;

/**
 *  @brief ADC TDG trigger mode type definition
 */
typedef enum
{
    ADC_DRV_LOOP_MODE = 0x00U, /*!< Loop mode for TDG trigger, loop conversion from CMD0 to CMD5*/
    ADC_DRV_MAPPING_MODE =
        0x01U /*!< Mapping mode for TDG trigger, one trigger triggers one cmd buff*/
} ADC_Drv_TdgTriggerModeType;

/**
 *  @brief ADC command buffer type definition
 */
typedef enum
{
    ADC_DRV_CMD_BUFFER_0 = 0x00U, /*!< Command buffer 0 */
    ADC_DRV_CMD_BUFFER_1 = 0x01U, /*!< Command buffer 1 */
    ADC_DRV_CMD_BUFFER_2 = 0x02U, /*!< Command buffer 2 */
    ADC_DRV_CMD_BUFFER_3 = 0x03U, /*!< Command buffer 3 */
    ADC_DRV_CMD_BUFFER_4 = 0x04U, /*!< Command buffer 4 */
    ADC_DRV_CMD_BUFFER_5 = 0x05U  /*!< Command buffer 5 */
} ADC_Drv_CmdBufferType;

/**
 * @brief  Defines ADC transfer mode, DMA and Interrupt.
 */
typedef enum
{
    ADC_DRV_INTERRUPT = 0U, /*!< Interrupt transfer. */
    ADC_DRV_DMA             /*!< DMA transfer. */
} Adc_Drv_TransferModeType;

/**
 * @brief Defines the notification function for conversion complete.
 *
 */
typedef void Adc_Drv_CompleteNotificationType(uint8 Instance);

/**
 * @brief Defines the notification function for trigger conflict error.
 */
typedef void Adc_Drv_TriggerConflictErrorNotificationType(void);

/**
 * @brief   Structure defining channel configuration of ADC
 *
 */
typedef struct
{
    uint8                       ChnIdx;          /*!< Logic Channel Index */
    ADC_Drv_PositiveChannelType Channel;         /*!< Selection of input channel for measurement */
    boolean                     InterruptEnable; /*!< Enable interrupts for this channel */
} Adc_Drv_ChannelConfigType;

/**
 * @brief   Structure defining configuration of ADC driver
 *
 */
typedef struct
{
    Adc_Drv_AvgSelectType   AvgSel;      /*!< Selection for number of samples used for averaging */
    Adc_Drv_ResolutionType  Resolution;  /*!< ADC resolution (8,10,12 bit) */
    Adc_Drv_TriggerType     TriggerMode; /*!< ADC trigger mode */
    Adc_Drv_VRefSelType     VoltageRef;  /*!< Voltage reference used */
    ADC_Drv_ConversionType  ConvMode;    /*!< single or continuous conversion mode */
    ADC_Drv_CompareModeType CompareMode; /*!< compare mode */
    boolean                 CompareGreaterThanEnable; /*!< Enable Greater-Than functionality */
    boolean                 CompareRangeFuncEnable;   /*!< Enable Range functionality */
    uint16                  CompVal1;                 /*!< First Compare Value */
    uint16                  CompVal2;                 /*!< Second Compare Value */
    uint16 UsrCalibrationEnable; /*!< Calibration enable. If enabled, user can configure gain and
                                    offset */
    uint16 UsrGain;              /*!< User-configurable gain */
    uint16 UsrOffset; /*!< User-configurable Offset (2's complement, subtracted from result) */
    const Adc_Drv_ChannelConfigType *ChannelConfigList;      /*!< channel configuration */
    const uint8                      ConfiguredChannelCount; /*!< Configured channel count */
    Adc_Drv_CompleteNotificationType
        *ConversionCompleteNotification; /*!< notification for conversion complete */
    Adc_Drv_TriggerConflictErrorNotificationType
        *TriggerErrorNotification;              /*!< notification for trigger conflict error */
    const Adc_Drv_TransferModeType TransferMode; /*!< DMA or Interrupt mode */
    const uint8                    DmaChannel;   /*!< Dma channel number for HWUnit */
    const uint8 WithoutInterrupt; /*!< Enables or Disables the ADC and DMA interrupts */
} Adc_Drv_ConfigType;

/**
 * @brief This structure is used to store ADC runtime info
 *
 */
typedef struct
{
    boolean InitFlag; /*!< Check if the driver was initialized. */
    Adc_Drv_CompleteNotificationType
        *ConversionCompleteNotification; /*!< notification for conversion complete */
    Adc_Drv_TriggerConflictErrorNotificationType
        *TriggerErrorNotification; /*!< notification for trigger conflict error */
} Adc_Drv_StateStructType;

/**
 * @brief This structure is used to store ADC group configuration
 *
 */
typedef struct
{
    const Adc_Drv_AvgSelectType AverageSelect;  /*!< Average selection of group */
    uint16                      StableTime;     /*!< ADC Stable time */
    uint16                      SampleTime;     /*!< ADC Sample time */
    ADC_Drv_TdgTriggerModeType  TdgTriggerMode; /*!< TDG trigger mode, Loop or mapping */
} Adc_Drv_GroupConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv */

/** @} end of group Adc_Module */

#endif /* ADC_DRV_TYPES_H */
