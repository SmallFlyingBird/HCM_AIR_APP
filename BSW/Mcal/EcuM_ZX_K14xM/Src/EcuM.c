/**************************************************************************************************/
/**
 * @file      : EcuM.c
 * @brief     : AUTOSAR EcuM source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup EcuM_Module
 *  @{
 */

/** @addtogroup EcuM
 *  @brief AUTOSAR EcuM source file. It is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "EcuM.h"
#ifdef ENABLE_ICU_WAKEUP_TEST
    #include "Icu.h"
#endif
#ifdef ENABLE_GPT_WAKEUP_TEST
    #include "Gpt.h"
#endif
#ifdef ENABLE_LIN_WAKEUP_TEST
    #include "LinIf.h"
#endif
#ifdef ENABLE_CAN_WAKEUP_TEST
    #include "CanIf.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define ECUM_C_VENDOR_ID                   0x00B3U
#define ECUM_C_AR_RELEASE_MAJOR_VERSION    4U
#define ECUM_C_AR_RELEASE_MINOR_VERSION    6U
#define ECUM_C_AR_RELEASE_REVISION_VERSION 0U
#define ECUM_C_SW_MAJOR_VERSION            1U
#define ECUM_C_SW_MINOR_VERSION            2U
#define ECUM_C_SW_PATCH_VERSION            2U

/* Check if current file and EcuM header file are of the same vendor */
#if (ECUM_C_VENDOR_ID != ECUM_VENDOR_ID)
    #error "EcuM.c and EcuM.h have different vendor ids"
#endif

/* Check if current file and EcuM header file are of the same Autosar version */
#if ((ECUM_C_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_C_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_C_AR_RELEASE_REVISION_VERSION != ECUM_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of EcuM.c and EcuM.h are different"
#endif

/* Check if current file and EcuM header file are of the same Software version */
#if ((ECUM_C_SW_MAJOR_VERSION != ECUM_SW_MAJOR_VERSION) || \
     (ECUM_C_SW_MINOR_VERSION != ECUM_SW_MINOR_VERSION) || \
     (ECUM_C_SW_PATCH_VERSION != ECUM_SW_PATCH_VERSION))
    #error "Software Version Numbers of EcuM.c and EcuM.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((ECUM_C_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||                  \
         (ECUM_C_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of EcuM.c and Std_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** 
 * @brief last wakeup event to EcuM (source ID)
 */
EcuM_WakeupSourceType EcuMLastWakeupEvent;

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
* @brief     This function sets the wakeup event of the ECUM.
* 
* @param[in] sources  wakeup source to be set
* 
*/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources)
{
    EcuMLastWakeupEvent = sources;
}

/**
* @brief     This function validates the wakeup event.
* 
* @param[in] sources: wakeup source to be validated
*/
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources)
{
    (void)sources;
}

/**
* @brief     This function checks the wakeup source against possible sources of wakeup.
* @details   This is a function stub only.
* 
* @param[in] WakeupSource: wakeup source ID
* 
*/
void EcuM_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#ifdef ENABLE_ICU_WAKEUP_TEST
    Icu_CheckWakeup(WakeupSource);
#endif
#ifdef ENABLE_GPT_WAKEUP_TEST
    Gpt_CheckWakeup(WakeupSource);
#endif
#ifdef ENABLE_LIN_WAKEUP_TEST
#if (LINIF_WAKEUP_SUPPORT == STD_ON)
    LinIf_CheckWakeup(WakeupSource);
#endif
#endif
#ifdef ENABLE_CAN_WAKEUP_TEST
    CanIf_CheckWakeup(WakeupSource);
#endif
    (void)WakeupSource;
}

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group EcuM */

/** @} end of group EcuM_Module */
