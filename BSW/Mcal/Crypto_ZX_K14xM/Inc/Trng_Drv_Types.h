/**************************************************************************************************/
/**
 * @file      : Trng_Drv_Types.h
 * @brief     : Trng low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TRNG_DRV_TYPES_H
#define TRNG_DRV_TYPES_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Trng_Drv
 *  @brief Trng low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "Trng_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TRNG_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TRNG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TRNG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TRNG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TRNG_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TRNG_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TRNG_DRV_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Trng_Drv_Cfg.h are the same vendor */
#if (TRNG_DRV_TYPES_H_VENDOR_ID != TRNG_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Trng_Drv_Types.h and Trng_Drv_Cfg.h are different"
#endif
/* Check if current file and Trng_Drv_Cfg.h are the same Autosar version */
#if ((TRNG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != TRNG_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (TRNG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != TRNG_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (TRNG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != TRNG_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Trng_Drv_Types.h and Trng_Drv_Cfg.h are different"
#endif
/* Check if current file and Trng_Drv_Cfg.h are the same Software version */
#if ((TRNG_DRV_TYPES_H_SW_MAJOR_VERSION != TRNG_DRV_CFG_H_SW_MAJOR_VERSION) || \
     (TRNG_DRV_TYPES_H_SW_MINOR_VERSION != TRNG_DRV_CFG_H_SW_MINOR_VERSION) || \
     (TRNG_DRV_TYPES_H_SW_PATCH_VERSION != TRNG_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Trng_Drv_Types.h and Trng_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((TRNG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
         (TRNG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Trng_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Structure of TRNG Driver status return type
 *
 */
typedef enum
{
    TRNG_DRV_STATUS_NO_ERR               = 0x0U,    /*!< No error */
    TRNG_DRV_STATUS_INVALID_RANDOM_ERR   = 0x1U     /*!< Too many invalid random numbers */
} Trng_Drv_StatusType;

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

/** @} end of group Trng_Drv */

/** @} end of group Crypto_Module */

#endif /* TRNG_DRV_TYPES_H */
