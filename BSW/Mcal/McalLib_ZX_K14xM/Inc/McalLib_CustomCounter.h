/**************************************************************************************************/
/**
 * @file      : McalLib_CustomCounter.h
 * @brief     : McalLib custom counter header file. This file defines the prototype of the
 *              custom counter APIs. However, the source code of these APIs shall be provided
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MCALLIB_CUSTOMCOUNTER_H
#define MCALLIB_CUSTOMCOUNTER_H

/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup McalLib_CustomCounter
 *  @brief McalLib custom counter
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCALLIB_CUSTOMCOUNTER_H_VENDOR_ID                   0x00B3U
#define MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_CUSTOMCOUNTER_H_SW_MAJOR_VERSION            1U
#define MCALLIB_CUSTOMCOUNTER_H_SW_MINOR_VERSION            2U
#define MCALLIB_CUSTOMCOUNTER_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||     \
         (MCALLIB_CUSTOMCOUNTER_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib_CustomCounter.h and Std_Types.h are different"
    #endif
#endif

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
#define MCALLIB_START_SEC_CODE
#include "McalLib_MemMap.h"

/* prototype of custom counter initialization */
void McalLib_CustomCounter_Init(void);
/* prototype of the API to get custom counter value */
uint32 McalLib_CustomCounter_GetCounterValue(uint32 *Value);
/* prototype of the API to get elapsed value */
uint32 McalLib_CustomCounter_GetElapsedValue(uint32 *const CounterValue, uint32 *ElapsedValue);
/* prototype of the API to convert microseconds to ticks */
uint32 McalLib_CustomCounter_MicroSecToTicks(uint32 MicroSecond);
/* prototype of the API to set counter freq */
void McalLib_CustomCounter_SetCounterFreq(uint32 freq);

#define MCALLIB_STOP_SEC_CODE
#include "McalLib_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group McalLib_CustomCounter */

/** @} end of group McalLib_Module */

#endif /* MCALLIB_CUSTOMCOUNTER_H */
