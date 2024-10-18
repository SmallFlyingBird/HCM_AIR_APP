/**************************************************************************************************/
/**
 * @file      : Rte_NvM_Type.h
 * @brief     : AUTOSAR Rte Nvm Manager header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef RTE_NVM_TYPE_H
#define RTE_NVM_TYPE_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup Rte_Nvm_Type
 *  @brief Rte NVM type
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
#define RTE_NVM_TYPE_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTE_NVM_TYPE_H_AR_RELEASE_MINOR_VERSION    6U
#define RTE_NVM_TYPE_H_AR_RELEASE_REVISION_VERSION 0U
#define RTE_NVM_TYPE_H_SW_MAJOR_VERSION            1U
#define RTE_NVM_TYPE_H_SW_MINOR_VERSION            2U
#define RTE_NVM_TYPE_H_SW_PATCH_VERSION            1U
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
typedef uint16 NvM_BlockIdType;

typedef enum
{
    NVM_READ_BLOCK = 0x00U,
    NVM_WRITE_BLOCK = 0x01U,
    NVM_RESTORE_BLOCK_DEFAULTS = 0x02U,
    NVM_ERASE_NV_BLOCK = 0x03U,
    NVM_INVALIDATE_NV_BLOCK = 0x04U,
    NVM_READ_ALL_BLOCK = 0x05U
}NvM_BlockRequestType;

typedef enum
{
    NVM_INIT_READ_BLOCK = 0x00U,
    NVM_INIT_RESTORE_BLOCK_DEFAULTS = 0x01U,
    NVM_INIT_READ_ALL_BLOCK = 0x02U,
    NVM_INIT_FIRST_INIT_ALL = 0x03U
}NvM_InitBlockRequestType;

typedef enum
{
    NVM_REQ_OK = 0x00U,
    NVM_REQ_NOT_OK = 0x01U,
    NVM_REQ_PENDING = 0x02U,
    NVM_REQ_INTEGRITY_FAILED = 0x03U,
    NVM_REQ_BLOCK_SKIPPED = 0x04U,
    NVM_REQ_NV_INVALIDATED = 0x05U,
    NVM_REQ_CANCELED = 0x06U,
    NVM_REQ_RESTORED_DEFAULTS = 0x08U
}NvM_RequestResultType;
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Rte_Nvm_Type */

/** @} end of group Rte_Module */

#endif /* RTE_NVM_TYPE_H */
