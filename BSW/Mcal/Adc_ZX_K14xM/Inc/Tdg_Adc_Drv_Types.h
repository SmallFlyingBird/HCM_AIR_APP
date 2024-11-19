/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv_Types.h
 * @brief     : Tdg Adc low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TDG_ADC_DRV_TYPES_H
#define TDG_ADC_DRV_TYPES_H

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

#include "Std_Types.h"
#include "McalLib.h"
#include "Tdg_Adc_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TDG_ADC_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Tdg_Adc_Drv_Cfg header file are of the same vendor */
#if (TDG_ADC_DRV_TYPES_H_VENDOR_ID != TDG_ADC_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Tdg_Adc_Drv_Types.h and Tdg_Adc_Drv_Cfg.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Cfg header file are of the same Autosar version */
#if ((TDG_ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION !=                                              \
      TDG_ADC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||                                               \
     (TDG_ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION !=                                              \
      TDG_ADC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||                                               \
     (TDG_ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                           \
      TDG_ADC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tdg_Adc_Drv_Types.h and Tdg_Adc_Drv_Cfg.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Cfg header file are of the same Software version */
#if ((TDG_ADC_DRV_TYPES_H_SW_MAJOR_VERSION != TDG_ADC_DRV_CFG_H_SW_MAJOR_VERSION) ||               \
     (TDG_ADC_DRV_TYPES_H_SW_MINOR_VERSION != TDG_ADC_DRV_CFG_H_SW_MINOR_VERSION) ||               \
     (TDG_ADC_DRV_TYPES_H_SW_PATCH_VERSION != TDG_ADC_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Tdg_Adc_Drv_Types.h and Tdg_Adc_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((TDG_ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||         \
         (TDG_ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tdg_Adc_Drv_Types.h and Std_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief TDG Count Mode type definition
 */
typedef enum
{
    TDG_ADC_DRV_COUNT_SINGLE = 0U, /*!< single loop mode */
    TDG_ADC_DRV_COUNT_INFINITY     /*!< infinity loop mode */
} Tdg_Adc_Drv_CountModeType;

/**
 *  @brief TDG Trig Source type definition
 */
typedef enum
{
    TDG_ADC_DRV_TRIG_EXTERNAL = 0U, /*!< external trig source */
    TDG_ADC_DRV_TRIG_SW             /*!< software trig source */
} Tdg_Adc_Drv_TriggerSourceType;

/**
 *  @brief TDG Count Clear Mode type definition
 */
typedef enum
{
    TDG_ADC_DRV_CLEAR_MODULATOR = 0U, /*!< Clear counter when counter
                                    equal to modulator */
    TDG_ADC_DRV_CLEAR_DELAY           /*!< Clear counter when all channel
                                    complete delay output */
} Tdg_Adc_Drv_CountClearModeType;

/**
 *  @brief TDG Clock Divide type definition
 */
typedef enum
{
    TDG_ADC_DRV_CLK_DIVIDE_1 = 0U, /*!< TDG Clock Divide by 1*/
    TDG_ADC_DRV_CLK_DIVIDE_2,      /*!< TDG Clock Divide by 2*/
    TDG_ADC_DRV_CLK_DIVIDE_4,      /*!< TDG Clock Divide by 4*/
    TDG_ADC_DRV_CLK_DIVIDE_8,      /*!< TDG Clock Divide by 8*/
    TDG_ADC_DRV_CLK_DIVIDE_16,     /*!< TDG Clock Divide by 16*/
    TDG_ADC_DRV_CLK_DIVIDE_32,     /*!< TDG Clock Divide by 32*/
    TDG_ADC_DRV_CLK_DIVIDE_64,     /*!< TDG Clock Divide by 64*/
    TDG_ADC_DRV_CLK_DIVIDE_128     /*!< TDG Clock Divide by 128*/
} Tdg_Adc_Drv_ClockDivideType;

/**
 *  @brief TDG channel configuration update mode type definition
 */
typedef enum
{
    TDG_ADC_DRV_UPDATE_IMMEDIATELY = 0U, /*!< Immediately load configuration
                                        after update channel register */
    TDG_ADC_DRV_UPDATE_MODULATOR,        /*!< Load configuration when counter
                                        count up to equal to modulator */
    TDG_ADC_DRV_UPDATE_DELAY             /*!<  Load configuration when all
                                        channel complete delay output */
} Tdg_Adc_Drv_UpdateModeType;

/**
 *  @brief TDG Channel ID type definition
 */
typedef enum
{
    TDG_ADC_DRV_CHANNEL_0 = 0U, /*!< TDG Channel 0*/
    TDG_ADC_DRV_CHANNEL_1,      /*!< TDG Channel 1*/
    TDG_ADC_DRV_CHANNEL_2,      /*!< TDG Channel 2*/
    TDG_ADC_DRV_CHANNEL_3,      /*!< TDG Channel 3*/
    TDG_ADC_DRV_CHANNEL_4,      /*!< TDG Channel 4*/
    TDG_ADC_DRV_CHANNEL_5       /*!< TDG Channel 5*/
} Tdg_Adc_Drv_ChannelIdType;

/**
 *  @brief TDG Delay Output point ID type definition
 */
typedef enum
{
    TDG_ADC_DRV_DELAY_OUTPUT_0 = 0U, /*!< TDG Delay output 0*/
    TDG_ADC_DRV_DELAY_OUTPUT_1,      /*!< TDG Delay output 1*/
    TDG_ADC_DRV_DELAY_OUTPUT_2,      /*!< TDG Delay output 2*/
    TDG_ADC_DRV_DELAY_OUTPUT_3,      /*!< TDG Delay output 3*/
    TDG_ADC_DRV_DELAY_OUTPUT_4,      /*!< TDG Delay output 4*/
    TDG_ADC_DRV_DELAY_OUTPUT_5,      /*!< TDG Delay output 5*/
    TDG_ADC_DRV_DELAY_OUTPUT_6,      /*!< TDG Delay output 6*/
    TDG_ADC_DRV_DELAY_OUTPUT_7       /*!< TDG Delay output 7*/
} Tdg_Adc_Drv_DelayOutputIdType;

/**
 *  @brief TDG Interrupt type definition
 */
typedef enum
{
    TDG_ADC_DRV_INT_CH0 = 0U,    /*!< channel 0 INT*/
    TDG_ADC_DRV_INT_CH1,         /*!< channel 1 INT*/
    TDG_ADC_DRV_INT_CH2,         /*!< channel 2 INT*/
    TDG_ADC_DRV_INT_CH3,         /*!< channel 3 INT*/
    TDG_ADC_DRV_INT_CH4,         /*!< channel 4 INT*/
    TDG_ADC_DRV_INT_CH5,         /*!< channel 5 INT*/
    TDG_ADC_DRV_INT_RESERVERD_0, /*!< reserved */
    TDG_ADC_DRV_INT_RESERVERD_1, /*!< reserved */
    TDG_ADC_DRV_INT_ERR          /*!< Error interrupt*/
} Tdg_Adc_Drv_InterruptType;

/**
 * @brief   Defines the TDG complete delay output notification type
 */
typedef void Tdg_Adc_Drv_CompDelayOutputNotifType(uint32 ChanIdx);

/**
 * @brief   Defines the TDG error notification type
 */
typedef void Tdg_Adc_Drv_ErrorNotifType(void);

/**
 * @brief Structure defining configuration of TDG driver.
 *
 */
typedef struct
{
    Tdg_Adc_Drv_UpdateModeType     UpdateMode;    /*!< Select the configuration update mode. */
    Tdg_Adc_Drv_ClockDivideType    PrescalerDiv;  /*!< Select the prescaler divider. */
    Tdg_Adc_Drv_TriggerSourceType  TriggerSource; /*!< Select the trigger input source. */
    Tdg_Adc_Drv_CountClearModeType ClearMode;     /*!< Select the counter clear mode. */
    Tdg_Adc_Drv_CountModeType CountMode; /*!< Select the count mode, single or infinity loop. */
    uint16                    ModValue;  /*!< Modulate register value. */
    Tdg_Adc_Drv_CompDelayOutputNotifType
                               *CompDelayNotifPtr; /*!< Complete delay output notification. */
    Tdg_Adc_Drv_ErrorNotifType *ErrorNotifPtr;     /*!< Sequence error notification. */
} Tdg_Adc_Drv_ConfigType;

/**
 *  @brief TDG delay output configure struct definition
 */
typedef struct
{
    Tdg_Adc_Drv_DelayOutputIdType DelayOutputId; /*!< delay output id */
    uint16                        Offset;        /*!< delay output offset */
    boolean                       Enable;        /*!< delay output enable  */
} Tdg_Adc_Drv_DelayOutputConfigType;

/**
 *  @brief TDG Channel configure struct definition
 */
typedef struct
{
    Tdg_Adc_Drv_ChannelIdType ChannelId;      /*!< Channel Id */
    uint16                    IntDelayVal;    /*!< delay output complete interrupt delay */
    uint8                     DelayOutputNum; /*!< number of delay output point */
    const Tdg_Adc_Drv_DelayOutputConfigType *DelayOutputConfig; /*!< point to delay output config */
} Tdg_Adc_Drv_ChannelConfigType;

/**
 * @brief   Structure used to store runtime info
 */
typedef struct
{
    boolean                               InitFlag; /*!< Check if the driver was initialized. */
    Tdg_Adc_Drv_CompDelayOutputNotifType *CompDelayNotifPtr; /*!< Complete delay notification */
    Tdg_Adc_Drv_ErrorNotifType           *ErrorNotifPtr;     /*!< Sequence error notification */
} Tdg_Adc_Drv_StateStructType;

/**
 * @brief This structure is used to store TDG group configuration
 *
 */
typedef struct
{
    const boolean IsSwTrig; /*!< Is Software trigger */
    const uint8 NumOfChannel; /*!< Number of TDG channel used. */
    const Tdg_Adc_Drv_ChannelConfigType (
        *TdgChannelConfigArray)[]; /*!< Array of TDG channel configuration */
} Tdg_Adc_Drv_GroupConfigType;

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

/** @} end of group Tdg_Adc_Drv */

/** @} end of group Adc_Module */

#endif /* TDG_ADC_DRV_TYPES_H */
