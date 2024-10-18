/**************************************************************************************************/
/**
 * @file      : SchM_Port.c
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

/** @addtogroup SchM_Port
 *  @brief Port schedule manager source file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Port.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_PORT_C_VENDOR_ID                   0x00B3U
#define SCHM_PORT_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_PORT_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_PORT_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_PORT_C_SW_MAJOR_VERSION            1U
#define SCHM_PORT_C_SW_MINOR_VERSION            2U
#define SCHM_PORT_C_SW_PATCH_VERSION            1U

#if (SCHM_PORT_C_VENDOR_ID != SCHM_PORT_VENDOR_ID)
    #error "Vendor ID of SchM_Pwm.c and SchM_Pwm.h are different"
#endif

#if ((SCHM_PORT_C_AR_RELEASE_MAJOR_VERSION != SCHM_PORT_AR_RELEASE_MAJOR_VERSION) ||           \
        (SCHM_PORT_C_AR_RELEASE_MINOR_VERSION != SCHM_PORT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of SchM_Port.c and SchM_Port.h are different"
#endif

#if ((SCHM_PORT_C_AR_RELEASE_REVISION_VERSION != SCHM_PORT_AR_RELEASE_REVISION_VERSION) ||                           \
        (SCHM_PORT_C_SW_MAJOR_VERSION != SCHM_PORT_SW_MAJOR_VERSION))
    #error "Software version of SchM_Port.c and SchM_Port.h are different"
#endif

#if ((SCHM_PORT_C_SW_MINOR_VERSION != SCHM_PORT_SW_MINOR_VERSION) ||                           \
        (SCHM_PORT_C_SW_PATCH_VERSION != SCHM_PORT_SW_PATCH_VERSION))
    #error "Software version of SchM_Port.c and SchM_Port.h are different"
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

void SchM_Enter_Port_WritePortPcr(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Port_WritePortPcr(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Port_WriteGpioPddr(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Port_WriteGpioPddr(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Port */

/** @} end of group Rte_Module */
