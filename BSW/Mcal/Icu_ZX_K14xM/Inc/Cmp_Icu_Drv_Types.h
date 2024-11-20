/**************************************************************************************************/
/**
 * @file      : Cmp_Icu_Drv_Types.h
 * @brief     : AUTOSAR Cmp Icu hardware types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CMP_ICU_DRV_TYPES_H
#define CMP_ICU_DRV_TYPES_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Cmp_Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Cmp_Icu_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CMP_ICU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define CMP_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMP_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CMP_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CMP_ICU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define CMP_ICU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define CMP_ICU_DRV_TYPES_H_SW_PATCH_VERSION            2U

#if ((CMP_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (CMP_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Cmp_Icu_Drv_Types.h and Cmp_Icu_Drv_Cfg.h are different"
#endif

#if ((CMP_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != CMP_ICU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION) || \
        (CMP_ICU_DRV_TYPES_H_SW_PATCH_VERSION != CMP_ICU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "AutoSar version of Cmp_Icu_Drv_Types.h and Cmp_Icu_Drv_Cfg.h are different"
#endif

#if ((CMP_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != CMP_ICU_DRV_CFG_H_SW_MAJOR_VERSION) || \
        (CMP_ICU_DRV_TYPES_H_SW_MINOR_VERSION != CMP_ICU_DRV_CFG_H_SW_MINOR_VERSION))
    #error "Software version of Cmp_Icu_Drv_Types.h and Std_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (CMP_ICU_DRV_TYPES_H_VENDOR_ID != MCALLIB_VENDOR_ID)
        #error "Vendor ID Cmp_Icu_Drv_Types.h and McalLib.h have different"
    #endif

    #if ((CMP_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
            (CMP_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Cmp_Icu_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((CMP_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) || \
            (CMP_ICU_DRV_TYPES_H_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION))
        #error "Software version of Cmp_Icu_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((CMP_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (CMP_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Cmp_Icu_Drv_Types.h and Std_Types.h are different"
    #endif

    #if ((CMP_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
            (CMP_ICU_DRV_TYPES_H_SW_MINOR_VERSION != STD_SW_MINOR_VERSION))
        #error "Software version of Cmp_Icu_Drv_Types.h and Std_Types.h are different"
    #endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */


/**
 *  @brief The notification functions shall have no parameters and no return value
 */
typedef void (* Cmp_Icu_Drv_NotificationType)(void);

/**
 *  @brief The callback type for each channel
 */
typedef void (* Cmp_Icu_Drv_CallbackType)(uint16 Param1, boolean Param2);


/**
 *  @brief CMP ID type definition
 */
typedef enum
{
    CMP_ICU_DRV_ID_0 = 0U                            /*!< CMP0  */
} Cmp_Icu_Drv_IdType;

/**
 *  @brief CMP working mode type definition
 */
typedef enum
{
    CMP_ICU_DRV_BASIC_MODE = 0U,     /*!< basic mode: the analog output is not handled by 
                                  window/filter/sample */
    CMP_ICU_DRV_WINDOW_MODE,         /*!< window mode: the analog output is processed 
                                  by window signal from TMU */
    CMP_ICU_DRV_FILTER_MODE,         /*!< filter mode: the analog output is processed 
                                  by filter*/
    CMP_ICU_DRV_SAMPLE_MODE,         /*!< sample mode: the analog output is sampled by 
                                  signal from TMU */
    CMP_ICU_DRV_WINDOW_FILTER_MODE   /*!< window + filter mode: the analog output is 
                                  first processed by window signal from TMU,
                                  then it is processed by filter */
} Cmp_Icu_Drv_ModType;

/**
 *  @brief CMP trigger type definition
 */
typedef enum
{
    CMP_ICU_DRV_SW_TRIGGER = 0U,      /*!< software trigger */
    CMP_ICU_DRV_HW_TRIGGER            /*!< hardware trigger by trigger signal from TMU*/
} Cmp_Icu_Drv_TriggerType;

/**
 *  @brief CMP speed type definition
 */
typedef enum
{
    CMP_ICU_DRV_SPEED_LOW = 0U,        /*!< speed: low */
    CMP_ICU_DRV_SPEED_HIGH             /*!< speed: high */
} Cmp_Icu_Drv_SpeedType;

/**
 *  @brief CMP hysteresis in low-speed mode type definition
 */
typedef enum
{
    CMP_ICU_DRV_HYST_LEVEL_0 = 0U,    /*!< hysteresis speed level 0: no hysteresis */
    CMP_ICU_DRV_HYST_LEVEL_1,         /*!< hysteresis in speed level 1: low/16mv:high/21mv */
    CMP_ICU_DRV_HYST_LEVEL_2,         /*!< hysteresis in speed level 2: low/25mv:high/34mv */
    CMP_ICU_DRV_HYST_LEVEL_3          /*!< hysteresis in speed level 3: low/32mv:high/45mv */
} Cmp_Icu_Drv_HystSpeedLevelType;

/**
 *  @brief CMP input selection type definition
 */
typedef enum
{
    CMP_ICU_DRV_IN0 = 0U,           /*!< CMP0_IN0 pin*/
    CMP_ICU_DRV_IN1,                /*!< CMP0_IN1 pin*/
    CMP_ICU_DRV_IN2,                /*!< CMP0_IN2 pin */
    CMP_ICU_DRV_IN3,                /*!< CMP0_IN3 pin */
    CMP_ICU_DRV_IN4,                /*!< CMP0_IN4 pin*/ 
    CMP_ICU_DRV_IN5,                /*!< CMP0_IN5 pin*/
    CMP_ICU_DRV_IN6,                /*!< CMP0_IN6 pin*/  
    CMP_ICU_DRV_IN7,                /*!< CMP0_IN7 pin*/
    CMP_ICU_DRV_IN8,                /*!< CMP0_IN8 pin*/   
    CMP_ICU_DRV_IN9,                /*!< CMP0_IN9 pin*/
    CMP_ICU_DRV_IN10,               /*!< CMP0_IN10 pin*/    
    CMP_ICU_DRV_IN11,               /*!< CMP0_IN11 pin*/
    CMP_ICU_DRV_IN12,               /*!< CMP0_IN12 pin*/    
    CMP_ICU_DRV_IN_DACOUT = 15U      /*!< DAC Output */
} Cmp_Icu_Drv_InputType;

/**
 *  @brief  Filter sample count type definition
 */
typedef enum
{
    CMP_ICU_DRV_FILTER_BYPASSED = 0U,                   /*!< Filter is bypassed */
    CMP_ICU_DRV_FILTER_1_CONSECUTIVE_SAMPLE,            /*!< 1 consecutive sample must agree */
    CMP_ICU_DRV_FILTER_3_CONSECUTIVE_SAMPLE,            /*!< 3 consecutive sample must agree */
    CMP_ICU_DRV_FILTER_4_CONSECUTIVE_SAMPLE,            /*!< 4 consecutive sample must agree */
    CMP_ICU_DRV_FILTER_5_CONSECUTIVE_SAMPLE,            /*!< 5 consecutive sample must agree */
    CMP_ICU_DRV_FILTER_6_CONSECUTIVE_SAMPLE,            /*!< 6 consecutive sample must agree */
    CMP_ICU_DRV_FILTER_7_CONSECUTIVE_SAMPLE,            /*!< 7 consecutive sample must agree */
    CMP_ICU_DRV_FILTER_8_CONSECUTIVE_SAMPLE             /*!< 8 consecutive sample must agree */
} Cmp_Icu_Drv_FilterSampleCountType;

/**
 *  @brief CMP output level when window is closed type definition
 */
typedef enum
{
    CMP_ICU_DRV_WIN_OUT_LVL_LAST = 0U,    /*!< COUTA hold the value of the last sample */
    CMP_ICU_DRV_WIN_OUT_LVL_0,           /*!< COUTA is 0 when window is closed */
    CMP_ICU_DRV_WIN_OUT_LVL_1            /*!< COUTA is 1 when window is closed */
} Cmp_Icu_Drv_WinOutLvlType;

/**
 *  @brief CMP Edge-Alignment Mode type definition
 */
typedef enum
{
    CMP_ICU_DRV_INPUT_DISABLED     = 0U, /*!< CMP input capture disabled*/
    CMP_ICU_DRV_INPUT_RISING_EDGE,       /*!< CMP input capture only on rising edge*/
    CMP_ICU_DRV_INPUT_FALLING_EDGE,      /*!< CMP input capture only on falling edge*/
    CMP_ICU_DRV_INPUT_BOTH_EDGES         /*!< CMP input capture both on rising and falling edge*/
} Cmp_Icu_Drv_EdgeAlignmentModeType;

/**
 *  @brief CMP output selection type definition
 */
typedef enum
{ 
    CMP_ICU_DRV_OUT_FILTER_SAMPLE = 0U,  /*!< output after filter/sample */
    CMP_ICU_DRV_OUT_WINDOW               /*!< output after window */
} Cmp_Icu_Drv_OutputType;

/**
 *  @brief CMP Dac output voltage type definition
 */
typedef enum
{ 
    CMP_ICU_DRV_DAC_DISABLE = 0U,  /*!< Disable dac function */
    CMP_ICU_DRV_DAC_ENABLE         /*!< Enable dac function*/
} Cmp_Icu_Drv_DacConfigStateType;

/**
 *  @brief  DAC reference voltage type definition
 */
typedef enum
{
    CMP_ICU_DRV_DAC_VREF_VDDA = 0U,      /*!< VDDA */
    CMP_ICU_DRV_DAC_VREF_VREFH           /*!< VREFH */
} Cmp_Icu_Drv_DacVrefType;

/**
 *  @brief  Generic operation type definition
 */
typedef enum
{
    CMP_ICU_DRV_STATUS_SUCCESS                 = 0U, /*!< Generic operation success status */
    CMP_ICU_DRV_STATUS_ERROR                         /*!< Generic operation failure status */
} Cmp_Icu_Drv_StatusType;

/**
 * @brief Structure that store Input capture parameters for each channel
 */
typedef struct
{
    Cmp_Icu_Drv_SpeedType Speed; /*!< Comparator speed */
    Cmp_Icu_Drv_ModType Mode; /*!< CMP work mode */
    Cmp_Icu_Drv_HystSpeedLevelType HystSpeedLevel; /*!< Speed level comparator hysteresis */
    Cmp_Icu_Drv_EdgeAlignmentModeType ActiveEdge; /*!< Edge alignment Mode for signal measurement */      
    Cmp_Icu_Drv_FilterSampleCountType FilterSampleCount; /*!< Filter sample count Value */
    Cmp_Icu_Drv_DacVrefType DacVref; /*!< DAC reference select */
    Cmp_Icu_Drv_InputType PInput; /*!< positive input selection */ 
    Cmp_Icu_Drv_InputType NInput; /*!< Negative input selection */
    Cmp_Icu_Drv_TriggerType Trigger; /*!< Cmp Trigger */
    Cmp_Icu_Drv_WinOutLvlType WinOutLvl; /*!< CMP output level when window is closed */
    Cmp_Icu_Drv_OutputType   OutputCfg; /*!< CMP output selection */
    Cmp_Icu_Drv_DacConfigStateType DacConfig; /*!< CMP dac state config selection */
    uint16 CmpFilterSamplePeriod;  /*!< Filter sample period */
    uint16 DacOutputVoltageConfig;  /*!< DAC output voltage*/
    uint16 CallbackParam; /*!< The parameters of callback functions for channels events */
    Cmp_Icu_Drv_CallbackType CallbackFun; /*!< The callback function for 
                                                        channels edge detect events */ 
    Cmp_Icu_Drv_NotificationType ChNotificationFun; /*!< The notification functions for 
                                                                        SIGNAL_EDGE_DETECT mode */                                                               
} Cmp_Icu_Drv_ChannelConfigType;

/**
 * @brief Structure that store channel operation state
 */
typedef struct
{
    Cmp_Icu_Drv_SpeedType Speed; /*!< Comparator speed */
    Cmp_Icu_Drv_ModType Mode; /*!< CMP work mode */
    Cmp_Icu_Drv_HystSpeedLevelType HystSpeedLevel; /*!< Speed level comparator hysteresis */
    Cmp_Icu_Drv_EdgeAlignmentModeType ActiveEdge; /*!< Type of edge used for activation */
    Cmp_Icu_Drv_FilterSampleCountType FilterSampleCount; /*!< Filter sample count Value */
    Cmp_Icu_Drv_WinOutLvlType WinOutLvl; /*!< CMP output level when window is closed */
    Cmp_Icu_Drv_DacVrefType DacVref; /*!< DAC reference select */
    Cmp_Icu_Drv_InputType PInput; /*!< positive input selection */ 
    Cmp_Icu_Drv_InputType NInput; /*!< Negative input selection */
    uint16 CmpFilterSamplePeriod;  /*!< Filter sample period */
    uint16 DacOutputVoltageConfig;  /*!< DAC output voltage*/
    Cmp_Icu_Drv_TriggerType Trigger; /*!< Cmp Trigger */
    Cmp_Icu_Drv_OutputType OutputCfg; /*!< CMP output selection */
    Cmp_Icu_Drv_DacConfigStateType DacConfig; /*!< CMP dac state config selection */
    uint8 Pad1; /*!< pad */        
    Cmp_Icu_Drv_CallbackType CallbackFun; /*!< Calback for other types of measurement */
    uint16 CallbackParam; /*!< Logic channel for which callback is executed */
    Cmp_Icu_Drv_NotificationType ChNotificationFun; /*!< The notification functions for 
                                                                        SIGNAL_EDGE_DETECT mode */
    boolean NotifyEnable;   /*!< determines whether Notifications are enabled or not
                                 - TRUE: enable notification 
                                 - FALSE: disable notification */
#if (STD_ON == CMP_ICU_DRV_GET_INPUT_STATE_API)
    boolean InputStatus;
#endif
} Cmp_Icu_Drv_ChannelStateType;

/**
 * @brief Structure that driver configuration
 */
typedef struct
{
    uint32 ChSumNum; /*!< Number of input capture channel used */
    const Cmp_Icu_Drv_ChannelConfigType (*ChCfgPtr)[]; /*!< Edge detection channels configuration */
} Cmp_Icu_Drv_InstanceConfigType;

/**
 * @brief used by the drv driver for internal logic
 */
typedef struct
{
    boolean InstInitFlag;   /*!< Module initialization state
                             - TRUE: initialization 
                             - FALSE: de-initialization */
    uint16 ChfClrMask; /*!< Mask with channels not verified for spurious interrupt */
} Cmp_Icu_Drv_InstanceStateType;


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

/** @} end of group Cmp_Icu_Drv  */
/** @} end of group Icu_Module */

#endif  /* CMP_ICU_DRV_TYPES_H */

