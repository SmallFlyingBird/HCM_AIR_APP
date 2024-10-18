/**************************************************************************************************/
/**
 * @file      : Rte_Csm_Type.h
 * @brief     : AUTOSAR Rte Crypto Service Manager header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef RTE_CSM_TYPE_H
#define RTE_CSM_TYPE_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup Rte_Csm_Type
 *  @brief Rte CSM type
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTE_CSM_TYPE_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTE_CSM_TYPE_H_AR_RELEASE_MINOR_VERSION    6U
#define RTE_CSM_TYPE_H_AR_RELEASE_REVISION_VERSION 0U
#define RTE_CSM_TYPE_H_SW_MAJOR_VERSION            1U
#define RTE_CSM_TYPE_H_SW_MINOR_VERSION            2U
#define RTE_CSM_TYPE_H_SW_PATCH_VERSION            1U

/**
 * @brief  Extension to Std_ReturnType macro definition.
 */
#define CRYPTO_E_BUSY               ((Std_ReturnType)0x02U)
#define CRYPTO_E_ENTROPY_EXHAUSTED  ((Std_ReturnType)0x04U)
#define CRYPTO_E_KEY_READ_FAIL      ((Std_ReturnType)0x06U)
#define CRYPTO_E_KEY_WRITE_FAIL     ((Std_ReturnType)0x07U)
#define CRYPTO_E_KEY_NOT_AVAILABLE  ((Std_ReturnType)0x08U)
#define CRYPTO_E_KEY_NOT_VALID      ((Std_ReturnType)0x09U)
#define CRYPTO_E_KEY_SIZE_MISMATCH  ((Std_ReturnType)0x0AU)
#define CRYPTO_E_JOB_CANCELED       ((Std_ReturnType)0x0CU)
#define CRYPTO_E_KEY_EMPTY          ((Std_ReturnType)0x0DU)
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  Enumeration which operation shall be performed. This enumeration is constructed from a
 *         bit mask, where the first bit indicates "Start", the second "Update" and the third 
 *         "Finish".
 */
typedef enum
{
    CRYPTO_OPERATIONMODE_START           = 0x1U,
    CRYPTO_OPERATIONMODE_UPDATE          = 0x2U,
    CRYPTO_OPERATIONMODE_STREAMSTART     = 0x3U,
    CRYPTO_OPERATIONMODE_FINISH          = 0x4U,
    CRYPTO_OPERATIONMODE_SINGLECALL      = 0x7U,
    CRYPTO_OPERATIONMODE_SAVE_CONTEXT    = 0x8U,
    CRYPTO_OPERATIONMODE_RESTORE_CONTEXT = 0x10U
} Crypto_OperationModeType;

/**
 * @brief  Enumeration of the result type of verification operations.
 */
typedef enum 
{
    CRYPTO_E_VER_OK     = 0x0U,
    CRYPTO_E_VER_NOT_OK = 0x1U
} Crypto_VerifyResultType;

/**
 * @brief  Enumeration for key status.
 */
typedef enum 
{
    CRYPTO_KEYSTATUS_INVALID            = 0x0U,
    CRYPTO_KEYSTATUS_VALID              = 0x1U,
    CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS = 0x2U
} Crypto_KeyStatusType;

/**
 * @brief  Return for Std_ReturnType for Cryptostack.
 */
typedef Std_ReturnType Crypto_ResultType;

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

/** @} end of group Rte_Csm_Type */

/** @} end of group Rte_Module */

#endif /* RTE_CSM_TYPE_H */
