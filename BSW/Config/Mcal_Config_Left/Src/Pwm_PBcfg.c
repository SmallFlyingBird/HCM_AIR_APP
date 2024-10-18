/*************************************************************************************/
/**
 * @file      : Pwm_PBcfg.c  
 * @brief     : Pwm AUTOSAR level - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Configuration
 *  @brief Pwm AUTOSAR level configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm.h"
#include "Pwm_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PWM_PBCFG_C_VENDOR_ID                   0x00B3U
#define PWM_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PWM_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PWM_PBCFG_C_SW_MAJOR_VERSION            1U
#define PWM_PBCFG_C_SW_MINOR_VERSION            2U
#define PWM_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Pwm.h are the same vendor */
#if (PWM_PBCFG_C_VENDOR_ID != PWM_VENDOR_ID)
    #error "Vendor ID of Pwm_PBcfg.c and Pwm.h are different"
#endif
/* Check if current file and Pwm.h are the same Autosar version */
#if ((PWM_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_PBCFG_C_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Pwm_PBcfg.c and Pwm.h are different"
#endif
/* Check if current file and Pwm.h are the same Software version */
#if ((PWM_PBCFG_C_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
     (PWM_PBCFG_C_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
     (PWM_PBCFG_C_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software Version of Pwm_PBcfg.c and Pwm.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


/** @brief  Prototypes of PWM channels User Notifications */
extern void ALS_PWM_Notification(void);

extern void AFS_PWM_Notification(void);

/**
* @brief        Array of configured PWM channels
*
*/
static const Pwm_ChannelConfigType Pwm_Channels[PWM_PB_CFG_CHANNELS_COUNT] =
{
    /* ALS_NXT */
    {      
        .ChannelId = (Pwm_ChannelType)0U, /*!< Channel Id */      
        .PwmChnClass = PWM_VARIABLE_PERIOD, /*!< Channel class */      
        .DrvwChannelCfg = &Pwm_Drvw_Ch0_Config, /*!< Ip channel configuration */      
        .ChannelIdleState = PWM_LOW, /*!< The state of the channel output in idle mode */
        .PwmChannelNotificationPtr = &ALS_PWM_Notification /*!< Pointer to pwm channel notification function */
    },
     /* AFS_NXT */
    {      
        .ChannelId = (Pwm_ChannelType)1U, /*!< Channel Id */      
        .PwmChnClass = PWM_VARIABLE_PERIOD, /*!< Channel class */      
        .DrvwChannelCfg = &Pwm_Drvw_Ch1_Config, /*!< Ip channel configuration */      
        .ChannelIdleState = PWM_LOW, /*!< The state of the channel output in idle mode */
        .PwmChannelNotificationPtr = &AFS_PWM_Notification /*!< Pointer to pwm channel notification function */
    },
     /* FAN_CTR */
    {      
        .ChannelId = (Pwm_ChannelType)2U, /*!< Channel Id */      
        .PwmChnClass = PWM_FIXED_PERIOD, /*!< Channel class */      
        .DrvwChannelCfg = &Pwm_Drvw_Ch2_Config, /*!< Ip channel configuration */      
        .ChannelIdleState = PWM_LOW, /*!< The state of the channel output in idle mode */
        .PwmChannelNotificationPtr = NULL_PTR /*!< Pointer to pwm channel notification function */
    },
     /* DC_MOTOR */
    {      
        .ChannelId = (Pwm_ChannelType)3U, /*!< Channel Id */      
        .PwmChnClass = PWM_FIXED_PERIOD, /*!< Channel class */      
        .DrvwChannelCfg = &Pwm_Drvw_Ch3_Config, /*!< Ip channel configuration */      
        .ChannelIdleState = PWM_LOW, /*!< The state of the channel output in idle mode */
        .PwmChannelNotificationPtr = NULL_PTR /*!< Pointer to pwm channel notification function */
    }
 };

/**
* @brief PWM Configuration
*/
const Pwm_ConfigType Pwm_Config =
{
    .NumChannels = (Pwm_ChannelType)PWM_PB_CFG_CHANNELS_COUNT, /*!< Number of configured PWM channels */
    &Pwm_Channels, /*!< Pointer to array of PWM channels */
    .NumModules = (Pwm_HwNumType)PWM_PB_CFG_INSTANCES_COUNT, /*!< Number of Pwm configured instances */
    &Pwm_Instances /*!< Pointer to the list of Pwm configured channels */
};



#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

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
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Pwm_Configuration */

/** @} end of group Pwm_Module */
