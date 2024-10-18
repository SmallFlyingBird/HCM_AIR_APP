/**************************************************************************************************/
/**
 * @file      : Aes_Drv_Types.h
 * @brief     : Aes low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef AES_DRV_TYPES_H
#define AES_DRV_TYPES_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Aes_Drv_Types
 *  @brief Aes low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "Aes_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define AES_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define AES_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define AES_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define AES_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define AES_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define AES_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define AES_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Aes_Drv_Cfg.h are the same vendor */
#if (AES_DRV_TYPES_H_VENDOR_ID != AES_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Aes_Drv_Types.h and Aes_Drv_Cfg.h are different"
#endif

/* Check if current file and Aes_Drv_Cfg.h are the same Autosar version */
#if ((AES_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != AES_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (AES_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != AES_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (AES_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != AES_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Aes_Drv_Types.h and Aes_Drv_Cfg.h are different"
#endif

/* Check if current file and Aes_Drv_Cfg.h are the same Software version */
#if ((AES_DRV_TYPES_H_SW_MAJOR_VERSION != AES_DRV_CFG_H_SW_MAJOR_VERSION) || \
     (AES_DRV_TYPES_H_SW_MINOR_VERSION != AES_DRV_CFG_H_SW_MINOR_VERSION) || \
     (AES_DRV_TYPES_H_SW_PATCH_VERSION != AES_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Aes_Drv_Types.h and Aes_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((AES_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
         (AES_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Aes_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief Structure of AES Driver status return type
 *
 */
typedef enum
{
    AES_DRV_STATUS_NO_ERR               = 0x0U,      /*!< No error */
    AES_DRV_STATUS_ALG_ERR              = 0x1U,      /*!< Unauthorized algorithm */
    AES_DRV_STATUS_KEYSIZE_ALG_ERR      = 0x2U,      /*!< Unauthorized key size for algorithm */
    AES_DRV_STATUS_CIPHER_DIRECTION_ERR = 0x3U,      /*!< Unauthorized cipher direction */
    AES_DRV_STATUS_MODE_ERR             = 0x4U,      /*!< Unauthorized mode */
    AES_DRV_STATUS_ALG_MODE_ERR         = 0x5U,      /*!< Unauthorized algorithm for mode */
    AES_DRV_STATUS_DIRECTION_MODE_ERR   = 0x6U,      /*!< Unauthorized direction for mode */
    AES_DRV_STATUS_KEYSIZE_MODE_ERR     = 0x7U,      /*!< Unauthorized key size for mode */
    AES_DRV_STATUS_KEYID_ERR            = 0x8U,      /*!< KeyID out of range error */
    AES_DRV_STATUS_UNKNOWN_SETUP_ERR    = 0xFFU,     /*!< Unknown setup error */
    AES_DRV_STATUS_TIMEOUT              = 0x100U,    /*!< Function operation timeout */
    AES_DRV_STATUS_INPUT_ERROR          = 0x102U,    /*!< Input parameter not supported */
    AES_DRV_STATUS_BUSY_ERROR           = 0x103U     /*!< Aes module is busy */
} Aes_Drv_StatusType;

/**
 * @brief AES supported AlgorithmMode(without steps)
 *
 */
typedef enum
{
    AES_DRV_ECB = 0x00U,  /*!< ECB mode */
    AES_DRV_CBC = 0x01U,  /*!< CBC mode */
    AES_DRV_OFB = 0x02U,  /*!< OFB mode */
    AES_DRV_CTR = 0x03U,  /*!< CTR mode */
    AES_DRV_CFB = 0x04U,  /*!< CFB mode */
    AES_DRV_XTS = 0x07U,  /*!< XTS mode */
    AES_DRV_NONE = 0x0FU  /*!< Invalid mode */
} Aes_Drv_AlgorithmModeType;

/**
 * @brief Defines AES function select type
 *
 */
typedef enum
{
    AES_DRV_ENCRYPTION = 0x00U, /*!< AES encryption */
    AES_DRV_DECRYPTION = 0x01U  /*!< AES decryption */
} Aes_Drv_CryptFunctionType;
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

/** @} end of group Aes_Drv_Types */

/** @} end of group Crypto_Module */

#endif /* AES_DRV_TYPES_H */
