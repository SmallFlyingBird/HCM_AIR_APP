/**************************************************************************************************/
/**
 * @file      : Gpt_Irq.h
 * @brief     : Gpt interrupt header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef GPT_IRQ_H
#define GPT_IRQ_H

/**
 *   @file       Gpt_Irq.h
 *
 *   @addtogroup Gpt Driver
 *   @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_IRQ_H_VENDOR_ID                   0x00B3U
#define GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_IRQ_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_IRQ_H_AR_RELEASE_REVISION_VERSION 0U
#define GPT_IRQ_H_SW_MAJOR_VERSION            1U
#define GPT_IRQ_H_SW_MINOR_VERSION            2U
#define GPT_IRQ_H_SW_PATCH_VERSION            2U

/* Check if current file and Std_Types.h file are of the same Autosar version */
#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||                   \
         (GPT_IRQ_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Irq.h and Std_Types.h are different"
    #endif
#endif
/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief      Gpt interrupt handler and wakeup the EcuM.
 *
 * @param[in]  Channel Channel number
 *
 * @return     None
 *
 */
void Gpt_TimeMatchCallback(uint8 Channel);

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /*GPT_IRQ_H*/
