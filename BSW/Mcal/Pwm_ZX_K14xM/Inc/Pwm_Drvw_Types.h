/*************************************************************************************/
/**
 * @file      : Pwm_Drvw_Types.h
 * @brief     : AUTOSAR Pwm middle level driver types definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef PWM_DRVW_TYPES_H
#define PWM_DRVW_TYPES_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Drvw
 *  @brief Pwm driver wrapper 
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Drvw_Cfg.h"
#include "Mcpwm_Pwm_Drv_Types.h"
#include "Tim_Pwm_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define PWM_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define PWM_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define PWM_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define PWM_DRVW_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Mcpwm_Pwm_Drv_Types.h are the same vendor */
#if (PWM_DRVW_TYPES_H_VENDOR_ID != MCPWM_PWM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw_Types.h and Mcpwm_Pwm_Drv_Types.h are different"
#endif
/* Check if current file and Mcpwm_Pwm_Drv_Types.h are the same AutoSar version */
#if ((PWM_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Drvw_Types.h and Mcpwm_Pwm_Drv_Types.h are different"
#endif
/* Check if current file and Mcpwm_Pwm_Drv_Types.h are the same software version */
#if ((PWM_DRVW_TYPES_H_SW_MAJOR_VERSION != MCPWM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_TYPES_H_SW_MINOR_VERSION != MCPWM_PWM_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_TYPES_H_SW_PATCH_VERSION != MCPWM_PWM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw_Types.h and Mcpwm_Pwm_Drv_Types.h are different"
#endif

/* Check if current file and Pwm_Drvw_Cfg.h are the same vendor */
#if (PWM_DRVW_TYPES_H_VENDOR_ID != PWM_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw_Types.h and Pwm_Drvw_Cfg.h are different"
#endif
/* Check if current file and Pwm_Drvw_Cfg.h are the same AutoSar version */
#if ((PWM_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    != PWM_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    != PWM_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != PWM_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Drvw_Types.h and Pwm_Drvw_Cfg.h are different"
#endif
/* Check if current file and Pwm_Drvw_Cfg.h are the same software version */
#if ((PWM_DRVW_TYPES_H_SW_MAJOR_VERSION != PWM_DRVW_CFG_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_TYPES_H_SW_MINOR_VERSION != PWM_DRVW_CFG_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_TYPES_H_SW_PATCH_VERSION != PWM_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw_Types.h and Pwm_Drvw_Cfg.h are different"
#endif

/* Check if current file and Tim_Pwm_Drv_Types.h are the same vendor */
#if (PWM_DRVW_TYPES_H_VENDOR_ID != TIM_PWM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw_Types.h and Tim_Pwm_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Pwm_Drv_Types.h are the same AutoSar version */
#if ((PWM_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm_Drvw_Types.h and Tim_Pwm_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Pwm_Drv_Types.h are the same software version */
#if ((PWM_DRVW_TYPES_H_SW_MAJOR_VERSION != TIM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_TYPES_H_SW_MINOR_VERSION != TIM_PWM_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_TYPES_H_SW_PATCH_VERSION != TIM_PWM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw_Types.h and Tim_Pwm_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
* @brief PWM module type
*/
typedef uint8 Pwm_Drvw_ModuleType;

/**
* @brief   Defines enum for a type of module
* @details DRVW type used to identify pointer to module configuration.
*
*/
typedef enum
{
    PWM_DRVW_HW_NONE   = 0x00U,        /*!< No module type */
    PWM_DRVW_HW_MCPWM  = 0x01U,        /*!< HW module: MCPWM */
    PWM_DRVW_HW_TIM    = 0x02U         /*!< HW module: TIM */
} Pwm_Drvw_HwType;

/**
* @brief   Output signal level
* @details This enumeration specifies the return type of Pwm_GetOutputState
*
*/
typedef enum 
{
    PWM_DRVW_LOW = 0x00U,   /*!< PWM level is logic low */
    PWM_DRVW_HIGH           /*!< PWM level is logic high */
} Pwm_Drvw_OutputStateType;

/**
* @brief Pwm period type
*/
typedef uint16 Pwm_Drvw_PeriodType;

/**
* @brief Pwm notification edge type
*/
typedef enum 
{
    PWM_DRVW_RISING_EDGE = 0U,
    PWM_DRVW_FALLING_EDGE,
    PWM_DRVW_BOTH_EDGE
} Pwm_Drvw_EdgeNotificationType;

/**
* @brief Pwm power state type
*/
typedef enum 
{
  PWM_DRVW_FULL_POWER = 0x00U,
  PWM_DRVW_LOW_POWER,
  PWM_DRVW_NODEFINE_POWER
} Pwm_Drvw_PowerStateType;

/**
* @brief      Defines struct for a hardware channel
* @details    DRVW type used to implement a PWM channel
*
*/
typedef struct
{
    const Pwm_Drvw_ModuleType ChnHwId;  /*!< Hw id for this channel */
    const Pwm_Drvw_HwType ChnHwType;    /*!< The type of module channel configured */ 
    const uint16 ChannelDutyCycle;      /*!< The duty cycle of this channel */ 
    const Mcpwm_Pwm_Drv_ChannelConfigType 
                * McpwmChConfig;  /*!< Pointer to the Mcpwm channel configuration structure */  
    const Tim_Pwm_Drv_ChannelConfigType 
                * TimChConfig;    /*!< Pointer to the Tim channel configuration structure */
} Pwm_Drvw_ChannelConfigType;

/**
* @brief          Defines struct for a hardware module
* @details        DRVW type used to implement a PWM HW module configuration.
*
*/
typedef struct 
{   
    uint8 HwId;                      /*!< The Id module configured */   
    const Pwm_Drvw_HwType HwType;    /*!< The type of module configured */   
    const Mcpwm_Pwm_Drv_UserCfgType 
                * McpwmHwConfig;    /*!< Pointer to the Mcpwm configuration structure */   
    const Tim_Pwm_Drv_UserCfgType * TimHwConfig;  /*!< Pointer to the Tim configuration structure */
} Pwm_Drvw_HwConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */
#ifdef __cplusplus
}
#endif
/** @} end of group Pwm_Drvw */

/** @} end of group Pwm_Module */
#endif /* PWM_DRVW_TYPES_H */
