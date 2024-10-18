/**************************************************************************************************/
/**
 * @file      : Det.h
 * @brief     : AUTOSAR Det header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DET_H
#define DET_H

/** @addtogroup Det_Module
 *  @{
 */

/** @addtogroup Det
 *  @brief AUTOSAR Det header file. It is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define DET_VENDOR_ID                   0x00B3U
#define DET_MODULE_ID                   15U
#define DET_AR_RELEASE_MAJOR_VERSION    4U
#define DET_AR_RELEASE_MINOR_VERSION    6U
#define DET_AR_RELEASE_REVISION_VERSION 0U
#define DET_SW_MAJOR_VERSION            1U
#define DET_SW_MINOR_VERSION            2U
#define DET_SW_PATCH_VERSION            1U

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

void Det_Init(void);

Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId,
                                      uint8 ErrorId);

Std_ReturnType Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId,
                                        uint8 FaultId);

void Det_Start(void);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Det */

/** @} end of group Det_Module */

#endif /* DET_H */
