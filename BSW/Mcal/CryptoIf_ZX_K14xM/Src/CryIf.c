/**************************************************************************************************/
/**
 * @file      : CryIf.c
 * @brief     : CryIf AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
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

#include "CryIf.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYIF_C_VENDOR_ID                   0x00B3U
#define CRYIF_C_AR_RELEASE_MAJOR_VERSION    4U
#define CRYIF_C_AR_RELEASE_MINOR_VERSION    6U
#define CRYIF_C_AR_RELEASE_REVISION_VERSION 0U
#define CRYIF_C_SW_MAJOR_VERSION            1U
#define CRYIF_C_SW_MINOR_VERSION            2U
#define CRYIF_C_SW_PATCH_VERSION            1U

/* Check if current file and CryIf.h are the same vendor */
#if (CRYIF_C_VENDOR_ID != CRYIF_VENDOR_ID)
    #error "Vendor ID of CryIf.c and CryIf.h are different"
#endif
/* Check if current file and CryIf.h are the same Autosar version */
#if ((CRYIF_C_AR_RELEASE_MAJOR_VERSION != CRYIF_AR_RELEASE_MAJOR_VERSION) || \
     (CRYIF_C_AR_RELEASE_MINOR_VERSION != CRYIF_AR_RELEASE_MINOR_VERSION) || \
     (CRYIF_C_AR_RELEASE_REVISION_VERSION != CRYIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of CryIf.c and CryIf.h are different"
#endif
/* Check if current file and CryIf.h are the same Software version */
#if ((CRYIF_C_SW_MAJOR_VERSION != CRYIF_SW_MAJOR_VERSION) || \
     (CRYIF_C_SW_MINOR_VERSION != CRYIF_SW_MINOR_VERSION) || \
     (CRYIF_C_SW_PATCH_VERSION != CRYIF_SW_PATCH_VERSION))
    #error "Software Version of CryIf.c and CryIf.h are different"
#endif
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
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
 * @return     None
 * 
 */
void CryIf_CallbackNotification (Crypto_JobType* job, Crypto_ResultType result)
{
    (void)job;
    (void)result;
}

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group CryIf */

/** @} end of group CryIf_Module */

