/**************************************************************************************************/
/**
 * @file      : SchM_Icu.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_ICU_H
#define SCHM_ICU_H

/** @addtogroup  Mcal Driver
 *  @{
 */

/** @addtogroup  Icu Driver
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup SchM_Icu_Public_Defines
 *  @{
 */
#define SCHM_ICU_H_VENDOR_ID                   0x00B3U       
#define SCHM_ICU_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_ICU_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_ICU_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_ICU_H_SW_MAJOR_VERSION            1U
#define SCHM_ICU_H_SW_MINOR_VERSION            2U
#define SCHM_ICU_H_SW_PATCH_VERSION            1U
   
/** @} end of group SchM_Icu_Public_Defines */

/** @defgroup SchM_Icu_Public_FunctionDeclaration
 *  @{
 */     
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

extern void SchM_Enter_Icu_TimValue(void);
extern void SchM_Exit_Icu_TimValue(void);
extern void SchM_Enter_Icu_TimSetChannelState(void);
extern void SchM_Exit_Icu_TimSetChannelState(void);
extern void SchM_Enter_Icu_TimSetDmaParam(void);
extern void SchM_Exit_Icu_TimSetDmaParam(void);
extern void SchM_Enter_Icu_TimSetChannelModeCfg(void);
extern void SchM_Exit_Icu_TimSetChannelModeCfg(void);
extern void SchM_Enter_Icu_TimSetChannelStatePtr(void);
extern void SchM_Exit_Icu_TimSetChannelStatePtr(void);
extern void SchM_Enter_Icu_CmpSetActiveEdge(void);
extern void SchM_Exit_Icu_CmpSetActiveEdge(void);
extern void SchM_Enter_Icu_CmpSetChannelState(void);
extern void SchM_Exit_Icu_CmpSetChannelState(void);
extern void SchM_Enter_Icu_CmpGetInputState(void);
extern void SchM_Exit_Icu_CmpGetInputState(void);
extern void SchM_Enter_Icu_PortSetActiveEdge(void);
extern void SchM_Exit_Icu_PortSetActiveEdge(void);
extern void SchM_Enter_Icu_PortSetChannelState(void);
extern void SchM_Exit_Icu_PortSetChannelState(void);
extern void SchM_Enter_Icu_PortGetInputState(void);
extern void SchM_Exit_Icu_PortGetInputState(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group SchM_Icu_Public_FunctionDeclaration */

#ifdef __cplusplus
    }
#endif
        
/** @} end of group Icu Driver  */
/** @} end of group Mcal Driver */

#endif    /* SCHM_ICU_H */


