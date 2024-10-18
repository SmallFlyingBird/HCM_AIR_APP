/**************************************************************************************************/
/**
 * @file      : McalLib_Cfg.c
 * @brief     : McalLib configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup McalLib_Configuration
 *  @brief McalLib configuration source file.
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "McalLib.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define MCALLIB_CFG_C_VENDOR_ID                   0x00B3U
#define MCALLIB_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_CFG_C_SW_MAJOR_VERSION            1U
#define MCALLIB_CFG_C_SW_MINOR_VERSION            2U
#define MCALLIB_CFG_C_SW_PATCH_VERSION            1U

/* Check if current file and McalLib.h are the same vendor */
#if (MCALLIB_CFG_C_VENDOR_ID != MCALLIB_VENDOR_ID)
    #error "Vendor ID of McalLib_Cfg.c and McalLib.h are different"
#endif

/* Check if current file and McalLib.h are the same Autosar version */
#if ((MCALLIB_CFG_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||                    \
     (MCALLIB_CFG_C_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION) ||                    \
     (MCALLIB_CFG_C_AR_RELEASE_REVISION_VERSION != MCALLIB_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib_Cfg.c and McalLib.h are different"
#endif

/* Check if current file and McalLib.h are the same Software version */
#if ((MCALLIB_CFG_C_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) ||                                    \
     (MCALLIB_CFG_C_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION) ||                                    \
     (MCALLIB_CFG_C_SW_PATCH_VERSION != MCALLIB_SW_PATCH_VERSION))
    #error "Software Version of McalLib_Cfg.c and McalLib.h are different"
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

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group McalLib */

/** @} end of group McalLib_Module */
