/**************************************************************************************************/
/**
 * @file      : Icu_Types.h
 * @brief     : AUTOSAR Icu types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_TYPES_H
#define ICU_TYPES_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Icu_Drvw_Types.h"
#include "Icu_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ICU_TYPES_H_VENDOR_ID                   0x00B3U
#define ICU_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define ICU_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define ICU_TYPES_H_SW_MAJOR_VERSION            1U
#define ICU_TYPES_H_SW_MINOR_VERSION            2U
#define ICU_TYPES_H_SW_PATCH_VERSION            2U

#if (ICU_TYPES_H_VENDOR_ID != ICU_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID Icu_Types.h and Icu_Drvw_Types.h have different"
#endif
    
#if ((ICU_TYPES_H_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_TYPES_H_AR_RELEASE_MINOR_VERSION != ICU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Types.h and Icu_Drvw_Types.h are different"
#endif
    
#if ((ICU_TYPES_H_SW_MAJOR_VERSION != ICU_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
        (ICU_TYPES_H_SW_MINOR_VERSION != ICU_DRVW_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Types.h and Icu_Drvw_Types.h are different"
#endif

#if ((ICU_TYPES_H_AR_RELEASE_REVISION_VERSION != ICU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_TYPES_H_SW_PATCH_VERSION != ICU_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of Icu_Types.h and Icu_Drvw_Types.h are different"
#endif

#if (ICU_TYPES_H_VENDOR_ID != ICU_CFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Types.h and Icu_Cfg.h have different"
#endif
    
#if ((ICU_TYPES_H_AR_RELEASE_MAJOR_VERSION != ICU_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_TYPES_H_AR_RELEASE_MINOR_VERSION != ICU_CFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Types.h and Icu_Cfg.h are different"
#endif
    
#if ((ICU_TYPES_H_SW_MAJOR_VERSION != ICU_CFG_H_SW_MAJOR_VERSION) || \
        (ICU_TYPES_H_SW_MINOR_VERSION != ICU_CFG_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Types.h and Icu_Cfg.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @brief Type for giving the Icu channel number
*/
/* SWS_Icu_00278 */
typedef uint32                       Icu_ChannelType;

/** @brief Type for giving the Icu Instance ID
*/
typedef uint32                       Icu_InstanceType;

/** @brief Type for saving the timer register width value
*/
/* SWS_Icu_00290 */
typedef Icu_TimCounterWidthType      Icu_ValueType;

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief Type for saving the timestamp buffer index
*/
/* SWS_Icu_00292 */
typedef uint32                       Icu_IndexType;
#endif

#if (STD_ON == ICU_EDGE_COUNT_API)
/** @brief Type for saving edge number
*/
/* SWS_Icu_00293 */
typedef uint32                       Icu_EdgeNumberType;
#endif

#if (STD_ON == ICU_WAKEUP_SOURCE_REPORT)
/** @brief Type for saving wakeup source
*/
typedef uint32                       Icu_WakeupSourceType;
#endif 

/** @brief The notification functions shall have no parameters and no return value
*/
typedef void                         (*Icu_NotificationType)(void);

/**
 *  @brief mode type for Icu instance
 */
/* SWS_Icu_00258 */
typedef enum
{
    ICU_MODE_NORMAL = 0U, /*!< Normal operation, all used interrupts are enabled according to the
                             notification requests */
    ICU_MODE_SLEEP        /*!< Reduced power operation. In sleep mode only those notifications are
                             available which are configured as wakeup capable */
} Icu_ModeType;

#if (STD_ON == ICU_GET_INPUT_STATE_API)
/**
 *  @brief Input state of an Icu channel
 */
/* SWS_Icu_00279 */
typedef enum
{
    ICU_IDLE = 0U, /*!< No activation edge has been detected since the last call of 
                    Icu_GetInputState() or Icu_Init() */
    ICU_ACTIVE     /*!< An activation edge has been detected. */
} Icu_InputStateType;
#endif

/**
 *  @brief Definition of the measurement mode type
 */
/* SWS_Icu_00294 */
typedef enum
{
    ICU_MODE_SIGNAL_EDGE_DETECT = 0U, /*!< Mode for detecting edges */
    ICU_MODE_SIGNAL_MEASUREMENT,      /*!< Mode for measuring different times between various 
                                        configurable edges */
    ICU_MODE_TIMESTAMP,               /*!< Mode for capturing timer values on configurable edges */
    ICU_MODE_EDGE_COUNTER             /*!< Mode for counting edges on configurable edges*/
} Icu_MeasurementModeType;


#if ((STD_ON == ICU_GET_TIMEELAPSED_API) || (STD_ON == ICU_SIGNAL_MEASUREMENT_API))
/**
 *  @brief Definition of the measurement property type
 */
/* SWS_Icu_00295 */
typedef enum
{
    ICU_LOW_TIME = 0U, /*!< The channel is configured for reading the elapsed Signal Low Time */
    ICU_HIGH_TIME,     /*!< The channel is configured for reading the elapsed Signal High Time */                              
    ICU_PERIOD_TIME,   /*!< The channel is configured for reading the elapsed Signal Period Time */
    ICU_DUTY_CYCLE     /*!< The channel is configured to read values which are needed for 
                        calculating the duty cycle (coherent Active and Period Time) */
} Icu_SignalMeasurementPropertyType;
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
/**
 *  @brief Definition of the timestamp buffer type
 */
/* SWS_Icu_00296 */
typedef enum
{
    ICU_LINEAR_BUFFER = 0U, /*!< The buffer will just be filled once */
    ICU_CIRCULAR_BUFFER     /*!< After reaching the end of the buffer, the driver restarts at the 
                                beginning of the buffer */
} Icu_TimestampBufferType;
#endif

/**
 *  @brief Definition of the type of activation
 */
/* SWS_Icu_00289 */
typedef enum
{
    ICU_RISING_EDGE = 0U, /*!< An appropriate action shall be executed when a rising edge occurs 
                            on the ICU input signal */
    ICU_FALLING_EDGE,     /*!< An appropriate action shall be executed when a falling edge occurs 
                            on the ICU input signal */
    ICU_BOTH_EDGES        /*!< An appropriate action shall be executed when either a rising 
                            or falling edge */
} Icu_ActivationType;

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
/**
 * @brief Structure that contains ICU Duty cycle parameters
 * */
/* SWS_Icu_00291 */
typedef struct
{
    Icu_ValueType ActiveTime; /*!< Low or High time value */
    Icu_ValueType PeriodTime; /*!< Period time value */
} Icu_DutyCycleType;
#endif

/**
 * @brief Structure that contains channel configuration
 * */
typedef struct
{
    uint8 ChOptMode;               /*!< measurement mode mask code */
    Icu_ActivationType ActiveEdge; /*!< type of activation */
    boolean WakeupCapable;         /*!< wakeup capability enable
                                     - TRUE: enable channel capability
                                     - FALSE: disable channel capability */
    uint8  ChProperty;             /*!< channel property for measurement mode */
    Icu_NotificationType ChNotificationFun;                          
                                   /*!< notification function for TIME_STAMP or EDGE_COUNTER mode */
#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
    uint32 DmaLogicCh;             /*!< dma logic channel Id */
#endif
#if (STD_ON == ICU_OVERFLOW_NOTIFICATION_API)
    Icu_NotificationType ChOvfNotificationFun; /*!< overflow notification function */
#endif 
#if (STD_ON == ICU_WAKEUP_SOURCE_REPORT)
    Icu_WakeupSourceType ChWakeupSource; 
                                   /*!< EcuM wakeup source Id */         
#endif 
    const Icu_Drvw_HwChannelConfigType * DrvwHwChCfgPtr; 
                                   /*!< Pointer to the hardware channel pointer configuration */
} Icu_ChannelConfigType;

/**
 * @brief Structure that contains initialization data
 * */
/* SWS_Icu_00280 SWS_Icu_00281 SWS_Icu_00039 */
typedef struct
{
    uint32 IcuChSumNum; /*!< The number of configured logical channels */
    const Icu_ChannelConfigType (* IcuChCfgPtr)[]; /*!< Pointer to the list of Icu 
                                                    configured channels */
    uint32 IcuInstSumNum; /*!< The number of driver instances configured */
    const Icu_Drvw_HwInstanceConfigType (* IcuHwInstCfgPtr)[]; /*!< Pointer to the list of Icu 
                                                            configured instances */
    uint8 CoreId; /*!< core Id */
} Icu_ConfigType;

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

/** @} end of group Icu  */
/** @} end of group Icu_Module */

#endif  /* ICU_TYPES_H */

