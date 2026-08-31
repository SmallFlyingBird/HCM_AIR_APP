/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Gpt_Cfg.h
 * @brief 
 * 
 */


#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG                      (180)
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define GPT_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define GPT_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define GPT_SW_MAJOR_VERSION_CFG               (2)
#define GPT_SW_MINOR_VERSION_CFG               (3)
#define GPT_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

/**
 * @brief This macro is used to indicate whether the chip supports powerdown mode.
 */
#define GPT_SUPPORT_POWERDOWN_WAKEUP                   (STD_ON)
/*==================================================================================================
 *                                       GptGeneral
==================================================================================================*/

/**
 * @brief   Pre-compile configuration constants.
 */
#define GPT_PRECOMPILE_SUPPORT              (STD_OFF)

/*==================================================================================================
 *                                       GptDriverConfiguration
==================================================================================================*/

/**
 * @brief   Switches the development error detection and notification on or off.
 * @details true: detection and notification is enabled.
 *          false: detection and notification is disabled.
 * @ref     ECUC_Gpt_00321
 */
#define GPT_DEV_ERROR_DETECT                (STD_OFF)

/**
 * @brief   GPT_REPORT_WAKEUP_SOURCE switch
 * @details Enables/Disables wakeup source reporting.
 * @ref     ECUC_Gpt_00322
 */
#define GPT_REPORT_WAKEUP_SOURCE            (STD_OFF)


/**
 * @brief   Compile switch to enable / disable the SchM code.
 */
#define GPT_SCHM_SUPPORT                    (STD_ON)

/**
 * @brief Tmr channel compare value minimum.
 *        Since the CNT register of TMR keeps increasing, the TMR channel compare value can not be too small.
 */
#define TMR_CH_CMP_VALUE_MIN    (50U)


/**
 * @brief If the application code behaves in such a way that, when entering the timer interrupt
 * process function, the current CNT value has significantly exceeded the CH_CMP value. In this case,
 * updating the CH_CMP value based on the previous value may result in an inaccurate next count,
 * it is more appropriate to update the CH_CMP value based on the current CNT value instead.
 */
#define GPT_TMR_IRQ_CMP_MODIFY     (STD_OFF)

/*==================================================================================================
 *                                       GptConfigurationOfOptApiServices
==================================================================================================*/

/**
 * @brief   GPT_DEINIT_API switch
 * @details Adds / removes the service Gpt_DeInit() from the code.
 * @ref     ECUC_Gpt_00314
 */
#define GPT_DEINIT_API                      (STD_ON)

/**
 * @brief   GPT_ENABLE_DISABLE_NOTIFICATION_API switch
 * @details Adds / removes the services Gpt_EnableNotification() and Gpt_DisableNotification from the code.
 * @ref     ECUC_Gpt_00315
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)

/**
 * @brief   GPT_TIME_ELAPSED_API switch
 * @details Adds / removes the service Gpt_GetTimeElapsed() from the code.
 * @ref     ECUC_Gpt_00317
 */
#define GPT_TIME_ELAPSED_API                (STD_ON)

/**
 * @brief   GPT_TIME_REMAINING_API switch
 * @details Adds / removes the service Gpt_GetTimeRemaining() from the code.
 * @ref     ECUC_Gpt_00318
 */
#define GPT_TIME_REMAINING_API              (STD_ON)

/**
 * @brief   GPT_VERSION_INFO_API switch
 * @details Adds / removes the service Gpt_GetVersionInfo() from the code.
 * @ref     ECUC_Gpt_00319
 */
#define GPT_VERSION_INFO_API                (STD_OFF)

/**
 * @brief   GPT_WAKEUP_FUNCTIONALITY_API switch
 * @details Adds / removes the services Gpt_SetMode(), Gpt_EnableWakeup() Gpt_DisableWakeup() and Gpt_CheckWakeup() from the code.
 *
 * @ref     ECUC_Gpt_00320
 */
#define GPT_WAKEUP_FUNCTIONALITY_API        (STD_OFF)

/**
 * @brief   GPT_PREDEFTIMER_FUNCTIONALITY_API switch
 * @details Enable/disable GPT_PREDEFTIMER_FUNCTIONALITY_API.
 */
#define GPT_PREDEFTIMER_FUNCTIONALITY_API   (STD_OFF)

/*==================================================================================================
 *                                       GptChannelConfiguration
==================================================================================================*/

/**
 * @brief   Symbolic names of configured Gpt Channels.
 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_0    (0U)

/**
 * @brief   GPT_LOGIC_CHANNEL_NUM
 * @details The maximum number of Logical channels. This is used to allocate memory space for channel runtime info.
 */
#define GPT_LOGIC_CHANNEL_NUM   (1U)

/**
 * @brief   ETMR is not support now.
 */
#define GPT_ETMR_MODULE_USED    (STD_OFF)

/**
 * @brief   RTC is used or not.
 */
#define GPT_RTC_MODULE_USED     (STD_OFF)

/**
 * @brief   LPTMR is used or not.
 */
#define GPT_LPTMR_MODULE_USED   (STD_OFF)

/**
 * @brief   PTMR is used or not.
 */
#define GPT_PTMR_MODULE_USED    (STD_ON)

/**
 * @brief   TMR is used or not.
 */
#define GPT_TMR_MODULE_USED     (STD_OFF)

    
#define GPT_LLD_PTMR_0_CH_0_ISR_USED

#define GPT_ETMR_USED_CHANNEL_NUM   (0U)
#define GPT_LPTMR_USED_CHANNEL_NUM  (0U)
#define GPT_PTMR_USED_CHANNEL_NUM   (1U)
#define GPT_TMR_USED_CHANNEL_NUM    (0U)
#define GPT_RTC_USED_CHANNEL_NUM  (0U)

/**
 * @brief   The number of HW instances.
 */
#define GPT_USED_MODULE_NUM         (1U)

/*==================================================================================================
 *                                       MACROS
==================================================================================================*/
/**
 * @brief   LPTMR channel index.
 */
#define LPTMR_0_CH_0    (0U)    /**< @brief LPTMR_0 channel 0. */

/**
 * @brief   PTMR0 channel index.
 */
#define PTMR_0_CH_0     (0U)    /**< @brief PTMR_0 channel 0. */
#define PTMR_0_CH_1     (1U)    /**< @brief PTMR_0 channel 1. */
#define PTMR_0_CH_2     (2U)    /**< @brief PTMR_0 channel 2. */
#define PTMR_0_CH_3     (3U)    /**< @brief PTMR_0 channel 3. */

/**
 * @brief   TMR0 channel index.
 */
#define TMR_0_CH_0      (0U)    /**< @brief TMR_0 channel 0. */
#define TMR_0_CH_1      (1U)    /**< @brief TMR_0 channel 1. */
#define TMR_0_CH_2      (2U)    /**< @brief TMR_0 channel 2. */
#define TMR_0_CH_3      (3U)    /**< @brief TMR_0 channel 3. */



/**
 * @brief   RTC channel index.
 */
#define RTC_0_CH_0    (0U)    /**< @brief RTC_0 channel 0. */

#ifdef __cplusplus
}
#endif

#endif /* GPT_CFG_H */

/** @} */

