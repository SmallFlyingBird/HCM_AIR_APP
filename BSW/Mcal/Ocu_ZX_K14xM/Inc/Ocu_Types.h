/**************************************************************************************************/
/**
 * @file      : Ocu_Types.h
 * @brief     : Ocu AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Ocu_Types
 *  @brief Ocu driver
 *  @{
 */

#ifndef OCU_TYPES_H
#define OCU_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Ocu_Drvw_Types.h"
#include "Ocu_cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define OCU_TYPES_H_VENDOR_ID                   0x00B3U
#define OCU_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define OCU_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define OCU_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define OCU_TYPES_H_SW_MAJOR_VERSION            1U
#define OCU_TYPES_H_SW_MINOR_VERSION            2U
#define OCU_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Ocu_Drvw_Types.h are the same vendor */
#if (OCU_TYPES_H_VENDOR_ID != OCU_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Types.h and Ocu_Drvw_Types.h are different"
#endif
/* Check if current file and Ocu_Drvw_Types.h are the same Autosar version */
#if ((OCU_TYPES_H_AR_RELEASE_MAJOR_VERSION != OCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (OCU_TYPES_H_AR_RELEASE_MINOR_VERSION != OCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (OCU_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      OCU_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Types.h and Ocu_Drvw_Types.h are different"
#endif
/* Check if current file and Ocu_Drvw_Types.h are the same Software version */
#if ((OCU_TYPES_H_SW_MAJOR_VERSION != OCU_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (OCU_TYPES_H_SW_MINOR_VERSION != OCU_DRVW_TYPES_H_SW_MINOR_VERSION) ||                    \
     (OCU_TYPES_H_SW_PATCH_VERSION != OCU_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Types.h and Ocu_Drvw_Types.h are different"
#endif

/* Check if current file and Ocu_Cfg.h are the same vendor */
#if (OCU_TYPES_H_VENDOR_ID != OCU_CFG_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Types.h Ocu_Cfg.h and are different"
#endif
/* Check if current file and Ocu_Cfg.h are the same Autosar version */
#if ((OCU_TYPES_H_AR_RELEASE_MAJOR_VERSION != OCU_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (OCU_TYPES_H_AR_RELEASE_MINOR_VERSION != OCU_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (OCU_TYPES_H_AR_RELEASE_REVISION_VERSION != OCU_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Types.h and Ocu_Cfg.h are different"
#endif
/* Check if current file and Ocu_Cfg header file are the same Software version */
#if ((OCU_TYPES_H_SW_MAJOR_VERSION != OCU_CFG_H_SW_MAJOR_VERSION) ||                     \
     (OCU_TYPES_H_SW_MINOR_VERSION != OCU_CFG_H_SW_MINOR_VERSION) ||                     \
     (OCU_TYPES_H_SW_PATCH_VERSION != OCU_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Types.h and Ocu_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/**
 * @brief States of the Ocu driver
 */
#if (OCU_DEV_ERROR_DETECT == STD_ON)
typedef enum
{
    OCU_STATE_UNINIT = 0x00, /*!< uninitialized */
    OCU_STATE_IDLE           /*!< idle */
} Ocu_GlobalStateType;
#endif

/**
 * @brief Automatic action (by hardware) to be performed on a pin attached to an OCU 
 *        channel.
 */
typedef enum
{
    OCU_SET_LOW = 0, /*!< The channel pin will be set LOW upon compare match. */
    OCU_SET_HIGH = 1, /*!< The channel pin will be set HIGH upon compare match. */
    OCU_TOGGLE = 2, /*!< The channel pin will be set to the opposite of its current level upon compare match. */
    OCU_DISABLE = 3 /*!< The channel pin will remain at its current level upon compare match. */
} Ocu_PinActionType;

/**
 * @brief Status of a channel which was selected
 */
typedef enum
{
    OCU_STATUS_UNINITIALIZED = 0, /*!< uninitialized */
    OCU_STATUS_STOPPED,           /*!< stopped */
    OCU_STATUS_RUNNING            /*!< running */
} Ocu_ChannelStatusType;

/**
 * @brief Type for reading the counter and writing the threshold values (in number of ticks).
 */
typedef uint16 Ocu_ValueType;

/**
 * @brief Numeric identifier of an OCU channel.
 */
typedef uint16 Ocu_ChannelType;

/**
 * @brief Ocu notification typedef
 */
typedef void (*Ocu_NotificationType)(void);

/**
 * @brief Ocu output state type typedef
 */
typedef struct
{
    boolean  OutputPinEnable; /*!< Channel pin output enable */
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    const Ocu_NotificationType ChNotification; /*!< Pointer to channel notification callback function */
#endif
} Ocu_ChannelConfigType;

/**
 * @brief Return information after setting a new threshold value.
 */
typedef enum
{
    OCU_CM_IN_REF_INTERVAL = 0, /*!< The compare match will occur inside the current reference interval. */
    OCU_CM_OUT_REF_INTERVAL /*!< The compare match will not occur inside the current reference interval. */
} Ocu_ReturnType;

/**
 * @brief Output state of the pin linked to an OCU channel.
 */
typedef enum
{ 
    OCU_LOW = 0, /*!< The pin associated to an OCU channel is in high state. */
    OCU_HIGH     /*!< The pin associated to an OCU channel is in low state. */
} Ocu_PinStateType;

/**
 * @brief This is the type of the data structure containing the initialization data for the OCU 
 *        driver.
 */
typedef struct
{
    const Ocu_ChannelType NumChannels; /*!< Number of OCU channels configured */
    const Ocu_ChannelConfigType (*OcuChannelsConfigPtr)[]; /*!< Pointer to the OCU channel configuration */
    const Ocu_Drvw_ConfigType *TimConfig; /*!< Point to TIM configuration structure */
    const Ocu_ChannelType (*Ocu_Channel_UseMap)[]; /*!< Maps of channel used */
    uint8 CoreId; /*!< Current Core id */
} Ocu_ConfigType;

/**
 * @brief Instance error report id of OCU driver.
 */
#define OCU_INSTANCE_ID             (0U)

/**
 * @brief Ocu init service id 
 */
#define OCU_SID_INIT                (0x00U)

/**
 * @brief Ocu deinit service id 
 */
#define OCU_SID_DEINIT              (0x01U)

/**
 * @brief Ocu start channel service id 
 */
#define OCU_SID_START_CHANNEL        (0x02U)

/**
 * @brief Ocu stop channel service id 
 */
#define OCU_SID_STOP_CHANNEL         (0x03U)

/**
 * @brief Ocu set pin state channel service id 
 */
#define OCU_SID_SET_PIN_STATE          (0x04U)

/**
 * @brief Ocu set pin action channel service id 
 */
#define OCU_SID_SET_PIN_ACTION         (0x05U)

/**
 * @brief Ocu get counter channel service id 
 */
#define OCU_SID_GET_COUNTER           (0x06U)

/**
 * @brief Ocu set absolute threshold service id 
 */
#define OCU_SID_SET_ABSOLUTE_THRESHOLD  (0x07U)

/**
 * @brief Ocu set relative threshold service id 
 */
#define OCU_SID_SET_RELATIVE_THRESHOLD  (0x08U)

/**
 * @brief Ocu get version service id
 */
#define OCU_SID_GET_VERSION_INFO        (0x09U)

/**
 * @brief Ocu disable notification service id
 */
#define OCU_SID_DISABLE_NOTIFICATION   (0x0AU)

/**
 * @brief Ocu enable notification service id
 */
#define OCU_SID_ENABLE_NOTIFICATION    (0x0BU)

/**
 * @brief API services other than Ocu_GetVersionInfo() and Ocu_init() used without module 
 *        initialization
 */
#define OCU_E_UNINIT                    (0x02U)

/**
 * @brief API service used with an invalid channel Identifier.
 */
#define OCU_E_PARAM_INVALID_CHANNEL     (0x03U)

/**
 * @brief API Ocu_SetPinState() called with an invalid pin state or when the channel is in 
 *        the RUNNING state.
 */
#define OCU_E_PARAM_INVALID_STATE      (0x04U)

/**
 * @brief API Ocu_SetPinAction() called with an invalid pin action.
 */
#define OCU_E_PARAM_INVALID_ACTION     (0x05U)

/**
 * @brief Usage of Ocu_DisableNotification() or Ocu_EnableNotification() on a channel 
 *        where a NULL pointer is configured as the notification function.
 */
#define OCU_E_NO_VALID_NOTIF           (0x06U)

/**
 * @brief API Ocu_Init() called while the OCU driver has already been initialized
 */
#define OCU_E_ALREADY_INITIALIZED      (0x07U)

/**
 * @brief API Ocu_GetVersionInfo() is called with a NULL parameter.
 */
#define OCU_E_PARAM_POINTER            (0x08U)

/**
 * @brief API Ocu_StartChannel() called on a channel that is in state RUNNING.
 */
#define OCU_E_BUSY                      (0x09U)

/**
 * @brief Ocu_SetPinState() or Ocu_SetPinAction() called for a channel that doesn't 
 *        have an associated output pin.
 */
#define OCU_E_PARAM_NO_PIN              (0x0AU)

/**
 * @brief OCU initialization has been failed, e.g. selected configuration set doesn't exist.
 */
#define OCU_E_INIT_FAILED               (0x0BU)

/**
 * @brief Ocu error id defined in autosar, invalid value.
 */
#define OCU_E_PARAM_INVALID_VALUE       (0x1BU)

#ifdef __cplusplus
}
#endif

/** @} end of group Ocu_Types */

/** @} end of group Ocu_Module */

#endif    /*OCU_TYPES_H*/
