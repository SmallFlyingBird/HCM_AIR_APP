/**************************************************************************************************/
/**
 * @file      : Rte_Dem_Type.h
 * @brief     : AUTOSAR Rte Dem type definition file. It is a stub file. Integrators shall replace
 *this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef RTE_DEM_TYPE_H
#define RTE_DEM_TYPE_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup Rte_Dem_Type
 *  @brief Rte Dem type definition file. It is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTE_DEM_TYPE_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTE_DEM_TYPE_H_AR_RELEASE_MINOR_VERSION    6U
#define RTE_DEM_TYPE_H_AR_RELEASE_REVISION_VERSION 0U
#define RTE_DEM_TYPE_H_SW_MAJOR_VERSION            1U
#define RTE_DEM_TYPE_H_SW_MINOR_VERSION            2U
#define RTE_DEM_TYPE_H_SW_PATCH_VERSION            1U

#define DEM_EVENT_STATUS_PASSED    (Dem_EventStatusType)0x00U /*! @brief dem event passed */
#define DEM_EVENT_STATUS_FAILED    (Dem_EventStatusType)0x01U /*! @brief dem event failed */
#define DEM_EVENT_STATUS_PREPASSED (Dem_EventStatusType)0x02U /*! @brief dem event pre-passed */
#define DEM_EVENT_STATUS_PREFAILED (Dem_EventStatusType)0x03U /*! @brief dem event pre-failed */
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED                                                     \
    (Dem_EventStatusType)0x04U /*! @brief dem event pre-failed */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

typedef uint16 Dem_EventIdType; /*! @brief dem event ID type */

typedef uint8 Dem_EventStatusType; /*! @brief dem event status type */

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

/** @} end of group Rte_Dem */

/** @} end of group Rte_Module */

#endif /* RTE_DEM_TYPE_H */
