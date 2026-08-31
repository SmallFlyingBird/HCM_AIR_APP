/**
 * @file    Icu_Base.h
 * @version
 *
 * @brief   AUTOSAR Port module interface
 * @details API implementation for Icu driver
 *
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Etmr
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *   
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef ICU_BASE_H
#define ICU_BASE_H

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
/*==================================================================================================
 *                                   FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_BASE_VENDOR_ID                      (0xB4)
#define ICU_BASE_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_BASE_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_BASE_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_BASE_SW_MAJOR_VERSION               (2)
#define ICU_BASE_SW_MINOR_VERSION               (3)
#define ICU_BASE_SW_PATCH_VERSION               (0)
/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Wakeup feature is currently enabled
*/
#define ICU_CHANNEL_STATE_WKUP                  (1U)

/**
* @brief Wakeup happened on the current channel
*/
#define ICU_CHANNEL_STATE_WKUP_HAPPENED         (1U<<1U)
/**
* @brief The current channel state
*/
#define ICU_CHANNEL_STATE_RUNNING               (1U<<3U)

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
typedef enum
{
    ICU_ACTIVE = 0U, /**<    */
    ICU_IDLE = 1U,   /**<    */
} Icu_InputStateType;

typedef enum
{
    ICU_MODE_SIGNAL_EDGE_DETECT = 0U, /**<    */
    ICU_MODE_SIGNAL_MEASUREMENT = 1U, /**<    */
    ICU_MODE_TIMESTAMP = 2U,          /**<    */
    ICU_MODE_EDGE_COUNTER = 3U,       /**<    */
} Icu_MeasurementModeType;

typedef uint8   Icu_ChannelStateType;   /**< ICU Channel state type. */

/*==================================================================================================
 *                                          VARIATES
==================================================================================================*/

#endif

