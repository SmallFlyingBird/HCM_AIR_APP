/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */
#ifndef ADC_CFG_H
#define ADC_CFG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Adc_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_CFG                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define ADC_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define ADC_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define ADC_SW_MAJOR_VERSION_CFG               (2)
#define ADC_SW_MINOR_VERSION_CFG               (3)
#define ADC_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
 * @brief        Adds / removes the service Adc_DeInit() from the code.
 * @details      true: Adc_DeInit() can be used.
              false: Adc_DeInit() can not be used. 
 *
 * @ref          ECUC_Adc_00404
 */
#define ADC_DE_INIT_API                             (STD_ON)

/**
 * @brief        Switches the development error detection and notification on or off.
 * @details      * true: detection and notification is enabled.
              * false: detection and notification is disabled. 
 *
 * @ref          ECUC_Adc_00405
 */
#define ADC_DEV_ERROR_DETECT                        (STD_ON)

/**
 * @brief        Adds / removes the services Adc_StartGroupConversion() and Adc_StopGroupConversion() from the code.
 * @details      true: Adc_StartGroupConversion() and Adc_StopGroupConversion() can be used.
              false: Adc_StartGroupConversion() and Adc_StopGroupConversion() can not be used. 
 *
 * @ref          ECUC_Adc_00406
 */
#define ADC_ENABLE_START_STOP_GROUP_API             (STD_ON)

/**
 * @brief        Determines, if the group notification mechanism (the functions to enable and disable the notifications) is available at runtime.
 * @details      true: Enabled.
              false: Disabled. 
 *
 * @ref          ECUC_Adc_00105
 */
#define ADC_GRP_NOTIF_CAPABILITY                    (STD_ON)

/**
 * @brief        Adds / removes the services Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() from the code.
 * @details      true: Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() can be used.
              false: Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() can not be used. 
 *
 * @ref          ECUC_Adc_00408
 */
#define ADC_HW_TRIGGER_API                           (STD_OFF)

/**
 * @brief        Adds / removes all power state management related APIs (ADC_SetPowerState, ADC_GetCurrentPowerState, ADC_GetTargetPowerState,
 *               ADC_PreparePowerState, ADC_Main_PowerTransitionManager), indicating if the HW offers low power state management.
 * @details
 *
 * @ref          ECUC_Adc_00457
 */
#define ADC_LOW_POWER_STATES_SUPPORT                 (STD_OFF)

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief        Enables / disables the low power state of the ADCDriver when the ADC is initialized.
 */
#define ADC_LOW_POWER_STATE_ENABLE_WHEN_INIT         (STD_OFF)

/**
 * @brief        Enables / disables support of the ADCDriver to the asynchronous power state transition.
 * @details
 *
 * @ref          ECUC_Adc_00458
 */
#define ADC_POWER_STATE_ASYNCH_TRANSITION_MODE       (STD_OFF)
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */

/**
 * @brief        Adds / removes the service Adc_ReadGroup() and from the code.
 * @details      true: Adc_ReadGroup() can be used.
              false: Adc_ReadGroup() can not be used.
 *
 * @ref          ECUC_Adc_00394
 */
#define ADC_READ_GROUP_API                           (STD_ON)

/**
 * @brief        Adds / removes the service Adc_GetVersionInfo() from the code.
 * @details      true: Adc_GetVersionInfo() can be used.
              false: Adc_GetVersionInfor() can not be used.
 *
 * @ref          ECUC_Adc_00409
 */
#define ADC_VERSION_INFO_API                         (STD_ON)

/**
 * @brief        Enables or disables limit checking feature in the ADC driver.
 * @details
 *
 * @ref          ECUC_Adc_00452
 */
#define ADC_ENABLE_LIMIT_CHECK                        (STD_ON)

/**
 * @brief        Determines, if the queuing mechanism is active in case of priority mechanism disabled.
 * @details      Note: If priority mechanism is enabled, queuing mechanism is always active and the parameter ADC_ENABLE_QUEUING is not evaluated.
              true: Enabled.
              false: Disabled. 
 *
 * @ref          ECUC_Adc_00391
 */
#define ADC_ENABLE_QUEUING                            (STD_ON)

/**
* @brief           Type of prioritization mechanism ADC_PRIORITY_HW, ADC_PRIORITY_HW_SW and ADC_PRIORITY_NONE.
*/
/* SWS_Adc_00522 */
#define ADC_PRIORITY_NONE                   (0U)
#define ADC_PRIORITY_HW                     (1U)
#define ADC_PRIORITY_HW_SW                  (2U)
/**
 * @brief        Determines whether a priority mechanism is available for prioritization of the conversion requests and if available, the
 *               type of prioritization mechanism. The selection applies for groups with trigger source software and trigger source hardware.
 * @details      Two types of prioritization mechanism can be selected. The hardware prioritization mechanism (AdcPriorityHw) uses the ADC
 *               hardware features for prioritization of the software conversion requests and hardware trigger signals for groups with trigger
 *               source hardware. The mixed hardware and software prioritization mechanism (AdcPriorityHwSw) uses the ADC hardware features for
 *               prioritization of ADC hardware trigger for groups with trigger source hardware and a software implemented prioritization mechanism
 *               for groups with trigger source software. The group priorities for software triggered groups are typically configured with lower
 *               priority levels than the group priorities for hardware triggered groups. ImplementationType: Adc_PriorityImplementationType
 *
 * @ref          ECUC_Adc_00393
 * @note         option: \n
 *               ADC_PRIORITY_HW \n
 *               ADC_PRIORITY_HW_SW \n
 *               ADC_PRIORITY_NONE \n
 */
#define ADC_PRIORITY_IMPLEMENTATION                (ADC_PRIORITY_NONE)

/**
* @brief           Type of alignment mechanism ADC_ALIGN_RIGHT, ADC_ALIGN_LEFT.
*/
/* SWS_Adc_00525 */
#define ADC_ALIGN_RIGHT                     (0U)
#define ADC_ALIGN_LEFT                      (1U)

/**
 * @brief  Suppoted aligned automatically by hardware
 *
 */
#define ADC_ALIGN_AUTOMATIC                  FALSE

/**
* @brief           Result Alignment.
*/
#define ADC_RESULT_ALIGNMENT                (ADC_ALIGN_RIGHT)

/**
 * @brief        Determines, max queue depth configured across all configset.
 */
#define ADC_QUEUE_MAX_DEPTH_MAX                     (2U)

/**
* @brief            Pre-compile Support.
*/
#define ADC_FIXED_PB_CONFIG  (STD_OFF)

/**
 * @brief          Max number of ADC Hw units.
 */
#define ADC_MAX_HW_UNITS                            (1U)

/**
 * @brief          Max number of ADC Groups can be configured.
 */
#define ADC_MAX_GROUPS                              (6U)


/**
 * @brief         This is a timeout value.
 */
#define ADC_TIMEOUT_VALUE                   (100000U)


/**
 * @brief         Adc ERRATA ERR0002 
 */
#define ADC_ERRATA_ERR0002


#ifdef ADC_USER_MODE_SUPPORTED
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if ADC_USER_MODE_SUPPORTED is defined"
#endif
#endif
/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL Adc driver codes will work and support sync/atomic operation with CPU global interrupt
*        enable/disable for key resource protection.Disable it can reduce code size, but may cause potential risks when access to some critical
*        resource!
*/
#define ADC_SCHM_SUPPORT  (STD_ON) 



/**
 * @brief          ADC Hw units definition.
 */
#define ADC_0 (0U)

/**
 * @brief          ADC0 Channel definition.
 */
#define ADC0_SE0_ADCH0 (0U)
#define ADC0_SE1_ADCH1 (1U)
#define ADC0_SE2_ADCH2 (2U)
#define ADC0_SE3_ADCH3 (3U)
#define ADC0_SE4_ADCH4 (4U)
#define ADC0_SE5_ADCH5 (5U)
#define ADC0_SE6_ADCH6 (6U)
#define ADC0_SE7_ADCH7 (7U)
#define ADC0_SE8_ADCH8 (8U)
#define ADC0_SE9_ADCH9 (9U)
#define ADC0_SE10_ADCH10 (10U)
#define ADC0_SE11_ADCH11 (11U)
#define ADC0_SE12_ADCH12 (12U)
#define ADC0_SE13_ADCH13 (13U)
#define ADC0_SE14_ADCH14 (14U)
#define ADC0_SE15_ADCH15 (15U)
#define ADC0_SE16_ADCH16 (16U)
#define ADC0_SE17_ADCH17 (17U)
#define ADC0_SE18_ADCH18 (18U)
#define ADC0_SE19_ADCH19 (19U)
#define ADC0_SE20_ADCH20 (20U)
#define ADC0_SE21_ADCH21 (21U)
#define ADC0_SE22_ADCH22 (22U)
#define ADC0_SE23_ADCH23 (23U)
#define ADC0_SE24_ADCH24 (24U)
#define ADC0_SE25_ADCH25 (25U)
#define ADC0_SE26_ADCH26 (26U)
#define ADC0_SE27_ADCH27 (27U)
#define ADC0_SE28_ADCH28 (28U)
#define ADC0_SE29_ADCH29 (29U)
#define ADC0_SE30_ADCH30 (30U)
#define ADC0_SE31_ADCH31 (31U)
#define ADC0_TEMP_INT0_ADCH32 (32U)
#define ADC0_PMCVREF_INT0_ADCH33 (33U)
#define ADC0_VREFH_INT0_ADCH34 (34U)
#define ADC0_VREFL_INT0_ADCH35 (35U)
#define ADC0_RESERVE_ADCH36 (36U)
#define ADC0_VSS_INT0_ADCH37 (37U)


/*==================================================================================================
                                                ENUMS
==================================================================================================*/

#endif /* ADC_CFG_H */

