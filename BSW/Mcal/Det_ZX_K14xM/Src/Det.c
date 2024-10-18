/**************************************************************************************************/
/**
 * @file      : Det.c
 * @brief     : AUTOSAR Det source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Det_Module
 *  @{
 */

/** @addtogroup Det
 *  @brief AUTOSAR Det source file. It is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Det.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define DET_C_VENDOR_ID                   0x00B3U
#define DET_C_AR_RELEASE_MAJOR_VERSION    4U
#define DET_C_AR_RELEASE_MINOR_VERSION    6U
#define DET_C_AR_RELEASE_REVISION_VERSION 0U
#define DET_C_SW_MAJOR_VERSION            1U
#define DET_C_SW_MINOR_VERSION            2U
#define DET_C_SW_PATCH_VERSION            1U

/* Check if current file and Det header file are of the same vendor */
#if (DET_C_VENDOR_ID != DET_VENDOR_ID)
    #error "Det.c and Det.h have different vendor ids"
#endif

/* Check if current file and Det header file are of the same Autosar version */
#if ((DET_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                           \
     (DET_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION) ||                           \
     (DET_C_AR_RELEASE_REVISION_VERSION != DET_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Det.c and Det.h are different"
#endif

/* Check if current file and Det header file are of the same Software version */
#if ((DET_C_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION) ||                                           \
     (DET_C_SW_MINOR_VERSION != DET_SW_MINOR_VERSION) ||                                           \
     (DET_C_SW_PATCH_VERSION != DET_SW_PATCH_VERSION))
    #error "Software Version Numbers of Det.c and Det.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((DET_C_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||                       \
         (DET_C_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Spi.c and Std_Types.h are different"
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

void Det_Init(void)
{
}

Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
    return E_OK;
}

Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
    return E_OK;
}

Std_ReturnType Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId,
                                        uint8 FaultId)
{
    (void)ModuleId;
    (void)InstanceId;
    (void)ApiId;
    (void)FaultId;
    return E_OK;
}

void Det_Start(void)
{
}

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Det */

/** @} end of group Det_Module */
