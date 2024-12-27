/**************************************************************************************************/
/**
 * @file      : Dem_Cfg.h
 * @brief     : Dem configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DEM_CFG_H
#define DEM_CFG_H

/** @addtogroup  Dem_Module
 *  @{
 */

/** @defgroup Dem_Configuration
 *  @brief Dem configuration header file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define DEM_CFG_H_VENDOR_ID                   0x00B3U
#define DEM_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DEM_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DEM_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DEM_CFG_H_SW_MAJOR_VERSION            1U
#define DEM_CFG_H_SW_MINOR_VERSION            2U
#define DEM_CFG_H_SW_PATCH_VERSION            2U

      
    
#define DemConf_DemEventParameter_LIN_E_TIMEOUT   ((Dem_EventIdType) 0x1)
    
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR   ((Dem_EventIdType) 0x2)
    
#define DemConf_DemEventParameter_WDG_E_MODE_FAILED   ((Dem_EventIdType) 0x4)
    
#define DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED   ((Dem_EventIdType) 0x5)
    
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE   ((Dem_EventIdType) 0x6)
    


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

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Dem_Configuration */

/** @} end of group Dem_Module */

#endif /* DEM_CFG_H */
