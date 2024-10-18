/**************************************************************************************************/
/**
 * @file      : SchM_Icu.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Mcal Driver
 *  @{
 */

/** @addtogroup  Icu Driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Icu.h"

/** @defgroup SchM_Icu_Private_Defines
 *  @{
 */
#define SCHM_ICU_C_VENDOR_ID                   0x00B3U
#define SCHM_ICU_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_ICU_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_ICU_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_ICU_C_SW_MAJOR_VERSION            1U
#define SCHM_ICU_C_SW_MINOR_VERSION            2U
#define SCHM_ICU_C_SW_PATCH_VERSION            1U

#if (SCHM_ICU_C_VENDOR_ID != SCHM_ICU_H_VENDOR_ID)
    #error "SchM_Icu.c and SchM_Icu.h have different vendor ids"
#endif

#if ((SCHM_ICU_C_AR_RELEASE_MAJOR_VERSION != SCHM_ICU_H_AR_RELEASE_MAJOR_VERSION) ||           \
        (SCHM_ICU_C_AR_RELEASE_MINOR_VERSION != SCHM_ICU_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of SchM_Icu.c and SchM_Icu.h are different"
#endif

#if ((SCHM_ICU_C_SW_MAJOR_VERSION != SCHM_ICU_H_SW_MAJOR_VERSION) ||                           \
        (SCHM_ICU_C_SW_MINOR_VERSION != SCHM_ICU_H_SW_MINOR_VERSION))
    #error "Software version of SchM_Icu.c and SchM_Icu.h are different"
#endif

#if ((SCHM_ICU_C_AR_RELEASE_REVISION_VERSION != SCHM_ICU_H_AR_RELEASE_REVISION_VERSION) ||                           \
        (SCHM_ICU_C_SW_PATCH_VERSION != SCHM_ICU_H_SW_PATCH_VERSION))
    #error "Software version of SchM_Icu.c and SchM_Icu.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (SCHM_ICU_C_VENDOR_ID != MCALLIB_VENDOR_ID)
        #error "SchM_Icu.c and McalLib.h have different vendor ids"
    #endif

    #if ((SCHM_ICU_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||              \
         (SCHM_ICU_C_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of SchM_Icu.c and McalLib.h are different"
    #endif

    #if ((SCHM_ICU_C_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) ||                              \
         (SCHM_ICU_C_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION))
        #error "Software version of SchM_Icu.c and McalLib.h are different"
    #endif
#endif

/** @} end of group SchM_Icu_Private_Defines */

/** @defgroup SchM_Icu_Private_Type
 *  @{
 */

/** @} end of group SchM_Icu_Private_Type */

/** @defgroup SchM_Icu_Public_Macro
 *  @{
 */

/** @} end of group SchM_Icu_Public_Macro */

/** @defgroup SchM_Icu_Private_Variables
 *  @{
 */

/** @} end of group SchM_Icu_Private_Variables */

/** @defgroup SchM_Icu_Global_Variables
 *  @{
 */

/** @} end of group SchM_Icu_Global_Variables */

/** @defgroup SchM_Icu_Private_FunctionDeclaration
 *  @{
 */

/** @} end of group SchM_Icu_Private_FunctionDeclaration */

/** @defgroup SchM_Icu_Private_Functions
 *  @{
 */

/** @} end of group SchM_Icu_Private_Functions */

/** @defgroup SchM_Icu_Public_Functions
 *  @{
 */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

void SchM_Enter_Icu_TimValue(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_TimValue(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_TimSetChannelState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_TimSetChannelState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_TimSetDmaParam(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_TimSetDmaParam(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_TimSetChannelModeCfg(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_TimSetChannelModeCfg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_TimSetChannelStatePtr(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_TimSetChannelStatePtr(void)
{
    ResumeAllInterrupts();
}
 
void SchM_Enter_Icu_CmpSetActiveEdge(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_CmpSetActiveEdge(void)
{
    ResumeAllInterrupts();
} 

void SchM_Enter_Icu_CmpSetChannelState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_CmpSetChannelState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_CmpGetInputState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_CmpGetInputState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_PortSetActiveEdge(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_PortSetActiveEdge(void)
{
    ResumeAllInterrupts();
} 

void SchM_Enter_Icu_PortSetChannelState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_PortSetChannelState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Icu_PortGetInputState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Icu_PortGetInputState(void)
{
    ResumeAllInterrupts();
}


#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group SchM_Icu_Public_Functions */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu Driver */
/** @} end of group Mcal Driver */
