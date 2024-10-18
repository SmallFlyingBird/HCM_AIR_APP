/**************************************************************************************************/
/**
 * @file      : SchM_Ocu.c
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

/** @addtogroup SchM_Ocu
 *  @brief Ocu schedule manager source file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Ocu.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_OCU_C_VENDOR_ID                   0x00B3U
#define SCHM_OCU_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_OCU_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_OCU_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_OCU_C_SW_MAJOR_VERSION            1U
#define SCHM_OCU_C_SW_MINOR_VERSION            2U
#define SCHM_OCU_C_SW_PATCH_VERSION            1U
  
  /* Check if current file and SchM_Ocu.h are the same vendor */
#if (SCHM_OCU_C_VENDOR_ID != SCHM_OCU_H_VENDOR_ID)
    #error "Vendor ID of SchM_Ocu.c and SchM_Ocu.h are different"
#endif
/* Check if current file and SchM_Ocu.h are the same AutoSar version */
#if ((SCHM_OCU_C_AR_RELEASE_MAJOR_VERSION    != SCHM_OCU_H_AR_RELEASE_MAJOR_VERSION) || \
     (SCHM_OCU_C_AR_RELEASE_MINOR_VERSION    != SCHM_OCU_H_AR_RELEASE_MINOR_VERSION) || \
     (SCHM_OCU_C_AR_RELEASE_REVISION_VERSION != SCHM_OCU_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of SchM_Ocu.c and SchM_Ocu.h are different"
#endif
/* Check if current file and SchM_Ocu.h are the same Software version */
#if ((SCHM_OCU_C_SW_MAJOR_VERSION != SCHM_OCU_H_SW_MAJOR_VERSION) || \
     (SCHM_OCU_C_SW_MINOR_VERSION != SCHM_OCU_H_SW_MINOR_VERSION) || \
     (SCHM_OCU_C_SW_PATCH_VERSION != SCHM_OCU_H_SW_PATCH_VERSION))
    #error "Software Version of SchM_Ocu.c and SchM_Ocu.h are different"
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

void SchM_Enter_Ocu_StartChannelUpdate(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Ocu_StartChannelUpdate(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Ocu_StopChannelUpdate(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Ocu_StopChannelUpdate(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Ocu_SetPinStateUpdate(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Ocu_SetPinStateUpdate(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Ocu_SetPinActionUpdate(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Ocu_SetPinActionUpdate(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Ocu_NotificationUpdate(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Ocu_NotificationUpdate(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Ocu_ISRRegisterStatusUpdate(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Ocu_ISRRegisterStatusUpdate(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Ocu */

/** @} end of group Rte_Module */
