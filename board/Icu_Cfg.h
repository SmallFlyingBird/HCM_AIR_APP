/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Icu_Cfg.h
 * @brief 
 * 
 */


#ifndef ICU_CFG_H
#define ICU_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Icu_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_CFG                      (180)
#define ICU_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define ICU_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define ICU_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define ICU_SW_MAJOR_VERSION_CFG               (2)
#define ICU_SW_MINOR_VERSION_CFG               (3)
#define ICU_SW_PATCH_VERSION_CFG               (0)



/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define WKU_SUPPORT (STD_ON)
/*!
 * @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF
 * @trace ECUC_Icu_Cfg_xxxxx
 * @option STD_ON, STD_OFF
 *
 * @ref        ECUC_Icu_00232
 */
#define ICU_DEV_ERROR_DETECT (STD_ON)

/*!
 * @brief
 * @trace Switch for enabling Wakeup source reporting.
 * true: Report Wakeup source. false: Do not report Wakeup source.
 * @ref        ECUC_Icu_00233
 */
#define ICU_REPORT_WAKEUP_SOURCE (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the service Icu_DeInit() from the code.
 * true: Icu_DeInit() can be used. false: Icu_DeInit() can not be used.
 * @ref        ECUC_Icu_00234
 */
#define ICU_DE_INIT_API (STD_ON)

/**
*   @brief  Adds or removes the service Icu_CheckWakeup() from the code.
*        STD_ON: Icu_CheckWakeup() can be used.
*        STD_OFF: Icu_CheckWakeup() can not be used.
*   @ref        ECUC_Icu_00362
*/
#define ICU_WAKEUP_FUNCTIONALITY_API     (STD_ON)

/*!
 * @brief
 * @trace Adds / removes all services related to the edge counting functionality as listed below,
 * from the code: Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(), Icu_GetEdgeNumbers().
 * true: The services listed above can be used. false: The services listed above can not be used.
 * @ref        ECUC_Icu_00124
 */
#define ICU_EDGE_COUNT_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the service Icu_DisableWakeup() from the code.
 * true: Icu_DisableWakeup() can be used. false: Icu_DisableWakeup() can not be used.
 * @ref        ECUC_Icu_00235
 */
#define ICU_DISABLE_WAKEUP_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the service Icu_EnableWakeup() from the code.
 * true: Icu_EnableWakeup() can be used. false: Icu_EnableWakeup() can not be used.
 * @ref        ECUC_Icu_00236
 */
#define ICU_ENABLE_WAKEUP_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the service Icu_GetInputState() from the code.
 * true: Icu_GetDutyCycleValues() can be used. false: Icu_GetDutyCycleValues() can not be used.
 * @ref        ECUC_Icu_00237
 */
#define ICU_GET_DUTY_CYCLE_VALUES_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the service Icu_GetInputState() from the code.
 * true: Icu_GetInputState() can be used. false: Icu_GetInputState() can not be used.
 * @ref        ECUC_Icu_00238
 */
#define ICU_GET_INPUT_STATE_API (STD_ON)


/*!
 * @brief
 * @trace Adds / removes the service Icu_GetTimeElapsed() from the code.
 * true: Icu_GetTimeElapsed() can be used. false: Icu_GetTimeElapsed() can not be used.
 * @ref        ECUC_Icu_00239
 */
#define ICU_GET_TIME_ELAPSED_API (STD_ON)

/*!
 * @brief
 * @Adds / removes the service Icu_GetVersionInfo() from the code.
 * true: Icu_GetVersionInfo() can be used. false: Icu_GetVersionInfo() can not be used.
 * @ref        ECUC_Icu_00240
 */
#define ICU_GET_VERSION_INFO_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the service Icu_SetMode() from the code.
 * true: Icu_SetMode() can be used. false: Icu_SetMode() can not be used.
 * @ref        ECUC_Icu_00241
 */
#define ICU_SET_MODE_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes the services Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() from the code.
 * true: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can be used.
 * false: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can not be used.
 * @ref        ECUC_Icu_00242
 */
#define ICU_SIGNAL_MEASUREMENT_API (STD_ON)

/*!
 * @brief
 * @trace Adds / removes all services related to the timestamping functionality as listed below from the code:
 *  Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
 * true: The services listed above can be used. false: The services listed above can not be used.
 * @ref        ECUC_Icu_00123
 */
#define ICU_TIMESTAMP_API (STD_ON)

#define ICU_SIGNAL_EDGE_DETECT_API  (STD_ON)


/*!
 * @brief
 * @trace Adds / removes the services related to the edge detection functionality, from the code:
 * Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection().
 * true: These services can be used. false: These services can not be used.
 * @ref        ECUC_Icu_00356
 */
#define ICU_EDGE_DETECT_API (STD_ON)

/*!
 * @brief ISR Interrupt Enable
 * @ref
 */

#define ICU_ETMR_0_CH_6_IRQ_ENABLE 

/**
 * @brief            SchM Support.
 */
#define ICU_SCHM_SUPPORT (STD_ON)

/**
* @brief            Pre-compile Support.
*/
#define ICU_FIXED_PB_CONFIG  (STD_OFF)

/**
 * @brief            UserMode Support.
 */
#define ICU_ENABLE_USER_MODE    (STD_OFF)

#define ICU_USE_CHANNEL (1U)

#if (STD_ON == ICU_ENABLE_USER_MODE_SUPPORT)
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if (ICU_ENABLE_USER_MODE_SUPPORT == STD_ON) is defined"
#endif
#endif


#define IcuConf_IcuChannel_IcuChannel_0 (0U)



#endif

