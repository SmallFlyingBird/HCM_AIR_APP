/**************************************************************************************************/
/**
 * @file      : CryIf.h
 * @brief     : CryIf AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CRYIF_H
#define CRYIF_H

/** @addtogroup CryIf_Module
 *  @{
 */

/** @addtogroup CryIf
 *  @brief CryIf AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_GeneralTypes.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYIF_VENDOR_ID                   0x00B3U
#define CRYIF_AR_RELEASE_MAJOR_VERSION    4U
#define CRYIF_AR_RELEASE_MINOR_VERSION    6U
#define CRYIF_AR_RELEASE_REVISION_VERSION 0U
#define CRYIF_SW_MAJOR_VERSION            1U
#define CRYIF_SW_MINOR_VERSION            2U
#define CRYIF_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Crypto_GeneralTypes.h are the same Autosar version */
    #if ((CRYIF_AR_RELEASE_MAJOR_VERSION != CRYPTO_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION) || \
         (CRYIF_AR_RELEASE_MINOR_VERSION != CRYPTO_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of CryIf.h and Crypto_GeneralTypes.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
 * @brief      Notifies the CRYIF about the completion of the request with the result of the 
 *             cryptographic operation.
 *
 * @param[in]  job: Points to the completed job's information structure. It contains a callback
 *             ID to identify which job is finished.
 * @param[out] result: Contains the result of the cryptographic operation.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * 
 */
void CryIf_CallbackNotification (Crypto_JobType* job, Crypto_ResultType result);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group CryIf */

/** @} end of group CryIf_Module */

#endif /* CRYIF_H */

