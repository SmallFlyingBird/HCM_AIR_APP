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


#ifndef SPI_CFG_H
#define SPI_CFG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Spi_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_CFG                      (180)
#define SPI_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define SPI_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define SPI_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define SPI_SW_MAJOR_VERSION_CFG               (2)
#define SPI_SW_MINOR_VERSION_CFG               (3)
#define SPI_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/**
 * @brief       Spi slave support
*/
 #define SPI_SLAVE_SUPPORT                          (STD_OFF)

/**
 * @brief        This parameter enables or not DMA function.
 * @details
 *
 * @ref
 */
#define SPI_DMA_USED                                (STD_OFF)

/**
 * @brief        Spi timeout value for synchonous transmission.
 * @details
 */
#define SPI_TIMEOUT_VALUE                           (10000U)

/**
 * @brief        Switches the Spi_Cancel function ON or OFF.
 * @details
 *
 * @ref          ECUC_Spi_00226
 */
#define SPI_CANCEL_API                              (STD_ON)

/**
 * @brief        Switches the development error detection and notification on or off.
 * @details      * true: detection and notification is enabled.
                 * false: detection and notification is disabled.
 *
 * @ref          ECUC_Spi_00228
 */
#define SPI_DEV_ERROR_DETECT                        (STD_ON)

/**
 * @brief        Switches the Spi_GetHWUnitStatus function ON or OFF.
 * @details
 *
 * @ref          ECUC_Spi_00229
 */
#define SPI_HW_STATUS_API                           (STD_ON)

/**
 * @brief        Switches the Interruptible Sequences handling functionality ON or OFF.
 * @details
 *
 * @ref          ECUC_Spi_00230
 */
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED               (STD_ON)

/**
 * @brief        Specifies whether concurrent Spi_SyncTransmit() calls for different sequences shall be configurable.
 * @details
 *
 * @ref          ECUC_Spi_00237
 */
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT        (STD_OFF)

/**
 * @brief        Switches the Spi_GetVersionInfo function ON or OFF.
 * @details
 *
 * @ref          ECUC_Spi_00232
 */
#define SPI_VERSION_INFO_API                        (STD_ON)

/**
* @brief Define precompile support.
* @details Define precompile support if VARIANT-PRE-COMPILE or VARIANT-LINK-TIME is selected and number of variant <=1.
*/
#define SPI_PRECOMPILE_SUPPORT                      (STD_OFF)

/**
 * @brief        Switches the Production Error Detection and Notification ON.
 * @implements   SPI_DEM_REPORT_ERROR_STATUS_define
 *
 * @ref          ECUC_Spi_00241
 */
#define SPI_ENABLE_DEM_REPORT_ERROR_STATUS          (STD_OFF)

/* Only Internal Buffers are allowed in Handler Driver.*/
#define USAGE0                                      0x00U
/* Only External Buffers are allowed in Handler Driver.*/
#define USAGE1                                      0x01U
/* Both Buffer types are allowed in Handler Driver. */
#define USAGE2                                      0x02U
/**
 * @brief        Selects the SPI Handler/Driver Channel Buffers usage allowed and delivered.
 * @details
 *             IB = 0;
 *             EB = 1;
 *             IB/EB = 2;
 *
 * @ref          ECUC_Spi_00227
 */
#define SPI_CHANNEL_BUFFERS_ALLOWED                 (USAGE2)

/* The LEVEL 0 Simple Synchronous SPI Handler Driver functionalities are selected.*/
#define LEVEL0                                      0x00U
/* The LEVEL 1 Basic Asynchronous SPI Handler Driver functionalities are selected.*/
#define LEVEL1                                      0x01U
/* The LEVEL 2 Enhanced SPI Handler Driver functionalities are selected. */
#define LEVEL2                                      0x02U
/**
 * @brief        Selects the SPI Handler/Driver level of scalable functionality that is available and delivered.
 * @details
 *               0-2
 * @ref          ECUC_Spi_00231
 */
#define SPI_LEVEL_DELIVERED                        (LEVEL2)

/*
 * @brief Spi instance status initialization data
 */
#define SPI_HWUNIT_INIT                            {0xFFU, 0xFFU, 0xFFU, 0xFFU}

/**
 * @brief        This parameter defines the cycle time of the function Spi_MainFunction_Handling in seconds. 
 *               The parameter is not used by the driver it self, but it is used by upper layer.
 * @details
 *
 * @ref          ECUC_Spi_00242
 */
#define SPI_MAIN_FUNCTION_PERIOD                    (0.01U)

/**
 * @brief        Number of different SPI hardware micro controller peripherals (units/busses) available and handled by this SPI Handler/Driver module.
 * @details
 *
 * @ref          ECUC_Spi_00236
 */
#define SPI_MAX_HW_UNIT_USED                        (1U)

/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL Spi driver codes will work and support sync/atomic operation with CPU global interrupt 
*        enable/disable for key resource protection.
*        Disable it can reduce code size, but may cause potential risks when access to some critical resource!
*/
#define SPI_SCHM_SUPPORT                             (STD_ON)


#ifdef SPI_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if SPI_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPI_CFG_H */

/** @} */

