/*************************************************************************************/
/**
 * @file      : Pwm_Types.h
 * @brief     : Pwm AUTOSAR level type definition file 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef PWM_TYPES_H
#define PWM_TYPES_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm
 *  @brief Pwm AUTOSAR level
 *  @{
 */


#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Drvw_Types.h"
#include "Pwm_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PWM_TYPES_H_VENDOR_ID                   0x00B3U
#define PWM_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_TYPES_H_SW_MAJOR_VERSION            1U
#define PWM_TYPES_H_SW_MINOR_VERSION            2U
#define PWM_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Pwm_Drvw_Types.h are the same vendor */
#if (PWM_TYPES_H_VENDOR_ID != PWM_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID Pwm_Types.h and Pwm_Drvw_Types.h are different"
#endif

/* Check if current file and Pwm_Drvw_Types.h are the same AUTOSAR version */
#if ((PWM_TYPES_H_AR_RELEASE_MAJOR_VERSION    != PWM_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_TYPES_H_AR_RELEASE_MINOR_VERSION    != PWM_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_TYPES_H_AR_RELEASE_REVISION_VERSION != PWM_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Types.h and Pwm_Drvw_Types.h are different"
#endif

/* Check if current file and Pwm_Drvw_Types.h are the same software version */
#if ((PWM_TYPES_H_SW_MAJOR_VERSION != PWM_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
     (PWM_TYPES_H_SW_MINOR_VERSION != PWM_DRVW_TYPES_H_SW_MINOR_VERSION) || \
     (PWM_TYPES_H_SW_PATCH_VERSION != PWM_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Types.h and Pwm_Drvw_Types.h are different"
#endif

/* Check if current file and Pwm_Cfg.h are the same vendor */
#if (PWM_TYPES_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Types.h and Pwm_Cfg.h and are different"
#endif
/* Check if current file and Pwm_Cfg.h are the same Autosar version */
#if ((PWM_TYPES_H_AR_RELEASE_MAJOR_VERSION != PWM_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (PWM_TYPES_H_AR_RELEASE_MINOR_VERSION != PWM_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (PWM_TYPES_H_AR_RELEASE_REVISION_VERSION != PWM_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Types.h and Pwm_Cfg.h are different"
#endif
/* Check if current file and Pwm_Cfg header file are the same Software version */
#if ((PWM_TYPES_H_SW_MAJOR_VERSION != PWM_CFG_H_SW_MAJOR_VERSION) ||                     \
     (PWM_TYPES_H_SW_MINOR_VERSION != PWM_CFG_H_SW_MINOR_VERSION) ||                     \
     (PWM_TYPES_H_SW_PATCH_VERSION != PWM_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Types.h and Pwm_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
* @brief Pwm channel type
*/
typedef uint8 Pwm_ChannelType;

/**
* @brief Pwm hardware instance number type
*/
typedef uint8 Pwm_HwNumType;

/**
* @brief Pwm period type
*/
typedef Pwm_Drvw_PeriodType Pwm_PeriodType;

/**
* @brief   Output signal level
* @details This enumeration specifies the return type of Pwm_GetOutputState
*
*/
typedef enum 
{
    PWM_HIGH = 0x00U,                  /*!< PWM level is logic high */
    PWM_LOW                            /*!< PWM level is logic low */
} Pwm_OutputStateType;

/**
* @brief Pwm notification edge type
*/
typedef enum 
{
    PWM_RISING_EDGE = 0U,
    PWM_FALLING_EDGE,
    PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

/**
* @brief Pwm channel class type
*/
typedef enum 
{
    PWM_VARIABLE_PERIOD = 0x00U,
    PWM_FIXED_PERIOD,
    PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

/**
* @brief Pwm notification callback function type
*/
typedef void (*Pwm_NotifyType)(void);

/**
* @brief Pwm channel configuration type
*/
typedef struct 
{
    const Pwm_ChannelType ChannelId;                    /*!< Id for the logical channel */
    const Pwm_ChannelClassType PwmChnClass;             /*!< Channel class type: Variable/Fixed period */
    const Pwm_Drvw_ChannelConfigType * DrvwChannelCfg;  /*!< The type of ip channel configured */
    const Pwm_OutputStateType ChannelIdleState;         /*!< The state of the channel output in idle mode */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    const Pwm_NotifyType PwmChannelNotificationPtr;     /*!< Pointer to pwm channel notification function */
#endif /* PWM_NOTIFICATION_SUPPORTED */
} Pwm_ChannelConfigType;

/**
* @brief Pwm Configuration Type
*/
typedef struct 
{
    const Pwm_ChannelType NumChannels;                  /*!< Number of Pwm configured channels */
    const Pwm_ChannelConfigType (*PwmChannelConfigs)[]; /*!< Pointer to the list of Pwm configured channels */
    const Pwm_HwNumType NumModules;                     /*!< Number of Pwm configured Hw module */
    const Pwm_Drvw_HwConfigType (*PwmHwConfig)[];       /*!< Pointer to the list of Pwm configured HW instance */
} Pwm_ConfigType;

/**
* @brief Pwm Power Status Request Result Type
*/
typedef enum 
{
    PWM_SERVICE_ACCEPTED = 0x00U,
    PWM_NOT_INIT,
    PWM_SEQUENCE_ERROR,
    PWM_HW_FAILURE,
    PWM_POWER_STATE_NOT_SUPP,
    PWM_TRANS_NOT_POSSIBLE
} Pwm_PowerStateRequestResultType;

/**
* @brief Pwm power state type
*/
typedef enum
{
    PWM_FULL_POWER = 0x00U,
    PWM_LOW_POWER,
    PWM_NODEFINE_POWER
} Pwm_PowerStateType;

#if (PWM_DEV_ERROR_DETECT  == STD_ON)
/**
* @brief Enumeration containing the possible states of the PWM driver
*/
typedef enum
{
    PWM_STATE_UNINIT = 0x00U,    /*!< Pwm driver is not initialized */
    PWM_STATE_IDLE   = 0x01U     /*!< Pwm driver is initialized and running */
} Pwm_GlobalStateType;
#endif /* PWM_DEV_ERROR_DETECT */

/**
* @brief State structure for the PWM driver
*/
typedef struct
{
#if (PWM_DEV_ERROR_DETECT  == STD_ON)
    Pwm_GlobalStateType PwmGlobalState;        /*!< Variable storing the current state of the Pwm driver */
#endif /* PWM_DEV_ERROR_DETECT */
    Pwm_PowerStateType PwmCurrentPowerState;   /*!< Pointer to the top level configuration structure - valid only when the driver is in the initialized state */
    Pwm_PowerStateType PwmTargetPowerState;    /*!< Variable storing the target power state of the PWM driver */
} Pwm_DriverStateType;

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

/** @} end of group Pwm */

/** @} end of group Pwm_Module */
#endif /* PWM_TYPES_H */
