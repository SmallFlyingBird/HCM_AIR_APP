/**************************************************************************************************/
/**
 * @file      : SchM_Crc.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SCHM_CRC_H
#define SCHM_CRC_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup SchM_Crc
 *  @brief Crc schedule manager header file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SCHM_CRC_H_VENDOR_ID                   0x00B3U
#define SCHM_CRC_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_CRC_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_CRC_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_CRC_H_SW_MAJOR_VERSION            1U
#define SCHM_CRC_H_SW_MINOR_VERSION            2U
#define SCHM_CRC_H_SW_PATCH_VERSION            2U

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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

extern void SchM_Enter_Crc_CrcGetLock(void);
extern void SchM_Exit_Crc_CrcGetLock(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Crc */

/** @} end of group Rte_Module */

#endif /* SCHM_CRC_H */
