/**************************************************************************************************/
/**
 * @file      : System.h
 * @brief     : It provides system APIs
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SYSTEM_H
#define SYSTEM_H

/** @addtogroup Platform_Module
 *  @{
 */

/** @defgroup System
 *  @brief It provides system APIs
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SYSTEM_H_VENDOR_ID                   0x00B3U
#define SYSTEM_H_AR_RELEASE_MAJOR_VERSION    4U
#define SYSTEM_H_AR_RELEASE_MINOR_VERSION    6U
#define SYSTEM_H_AR_RELEASE_REVISION_VERSION 0U
#define SYSTEM_H_SW_MAJOR_VERSION            1U
#define SYSTEM_H_SW_MINOR_VERSION            2U
#define SYSTEM_H_SW_PATCH_VERSION            1U

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #define FLS_AC_ERASE_ADDR (Image$$RW_IRAM2$$Base)
    #define FLS_AC_WRITE_ADDR (Image$$RW_IRAM2$$Base)

    #define Fls_Drvw_AcEraseRomStart (Image$$ER_IROM3$$Base)
    #define Fls_Drvw_AcEraseSize     (Image$$ER_IROM3$$Length)
    #define Fls_Drvw_AcWriteRomStart (Image$$ER_IROM3$$Base)
    #define Fls_Drvw_AcWriteSize     (Image$$ER_IROM3$$Length)
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

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#ifdef MCAL_SUPPORT_USER_MODE

/**
 * @brief     Suspend all interrupts.
 * @details   This function suspends all interrupts.
 *
 * @return    None
 *
 */
void Sys_SuspendAllInterrupts(void);

/**
 * @brief     Resume all interrupts.
 * @details   This function resumes all interrupts.
 *
 * @return    None
 *
 */
void Sys_ResumeAllInterrupts(void);
#endif /* MCAL_SUPPORT_USER_MODE */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group System */
/** @} end of group Platform_Module */

#endif /* SYSTEM_H */
