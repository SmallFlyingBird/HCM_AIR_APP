/**************************************************************************************************/
/**
 * @file      : Trng_Drv_Cfg.h  
 * @brief     : Trng driver configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TRNG_DRV_CFG_H
#define TRNG_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/* Published information */
#define TRNG_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define TRNG_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TRNG_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TRNG_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TRNG_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define TRNG_DRV_CFG_H_SW_MINOR_VERSION            2U
#define TRNG_DRV_CFG_H_SW_PATCH_VERSION            1U

/* Pre-processor switch to enable/disable development error detection for CSEc IP API */
#define TRNG_DRV_DEV_ERROR_DETECT              (STD_ON)

#define TRNG_DRV_TIMEOUT_SUPERVISION_ENABLED   (STD_ON)
#define TRNG_DRV_TIMEOUT_TYPE                  (MCALLIB_COUNTER_SOFTWARE)
#define TRNG_DRV_TIMEOUT_VALUE                 (10000U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AES_DRV_CFG_H */
