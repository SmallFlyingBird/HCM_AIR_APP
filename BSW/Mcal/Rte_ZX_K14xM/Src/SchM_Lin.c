/**************************************************************************************************/
/**
 * @file      : SchM_Lin.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup SchM_Lin
 *  @brief Lin schedule manager source file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Lin.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_LIN_C_VENDOR_ID                   0x00B3U
#define SCHM_LIN_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_LIN_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_LIN_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_LIN_C_SW_MAJOR_VERSION            1U
#define SCHM_LIN_C_SW_MINOR_VERSION            2U
#define SCHM_LIN_C_SW_PATCH_VERSION            1U

#if (SCHM_LIN_C_VENDOR_ID != SCHM_LIN_H_VENDOR_ID)
    #error "SchM_Lin.c and SchM_Lin.h have different vendor ids"
#endif

#if ((SCHM_LIN_C_AR_RELEASE_MAJOR_VERSION != SCHM_LIN_H_AR_RELEASE_MAJOR_VERSION) ||           \
        (SCHM_LIN_C_AR_RELEASE_MINOR_VERSION != SCHM_LIN_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of SchM_Lin.c and SchM_Lin.h are different"
#endif

#if ((SCHM_LIN_C_SW_MAJOR_VERSION != SCHM_LIN_H_SW_MAJOR_VERSION) ||                           \
        (SCHM_LIN_C_SW_MINOR_VERSION != SCHM_LIN_H_SW_MINOR_VERSION))
    #error "Software version of SchM_Lin.c and SchM_Lin.h are different"
#endif

#if ((SCHM_LIN_C_AR_RELEASE_REVISION_VERSION != SCHM_LIN_H_AR_RELEASE_REVISION_VERSION) ||        \
        (SCHM_LIN_C_SW_PATCH_VERSION != SCHM_LIN_H_SW_PATCH_VERSION))
    #error "Software version of SchM_Lin.c and SchM_Lin.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (SCHM_LIN_C_VENDOR_ID != MCALLIB_VENDOR_ID)
        #error "SchM_Lin.c and McalLib.h have different vendor ids"
    #endif

    #if ((SCHM_LIN_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||              \
         (SCHM_LIN_C_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of SchM_Lin.c and McalLib.h are different"
    #endif

    #if ((SCHM_LIN_C_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) ||                              \
         (SCHM_LIN_C_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION))
        #error "Software version of SchM_Lin.c and McalLib.h are different"
    #endif
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

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Enter_Lin_UartLcr(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Lin_UartLcr(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_GlobalChecksum(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Lin_GlobalChecksum(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_UartChecksumReg(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Lin_UartChecksumReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_UartLinRspLenReg(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Lin_UartLinRspLenReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_PrepareSendData(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Lin_PrepareSendData(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_UartLinControlReg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Lin_UartLinControlReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_FifoOperation(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Lin_FifoOperation(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Lin_IntOperation(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Lin_IntOperation(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Lin */

/** @} end of group Rte_Module */
