/**************************************************************************************************/
/**
 * @file      : Tmu_Drv_Cfg.h
 * @brief     : Tmu driver level configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TMU_DRV_CFG_H
#define TMU_DRV_CFG_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Tmu_Drv
 *  @brief Tmu driver configuration header file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define TMU_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define TMU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TMU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TMU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TMU_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define TMU_DRV_CFG_H_SW_MINOR_VERSION            2U
#define TMU_DRV_CFG_H_SW_PATCH_VERSION            2U

/**
* @brief Defines Trig mux enabled or not.
*/
#define TMU_DRV_TRIG_MUX_ENABLE     (STD_OFF)

/**
* @brief Switches development error detection ON or OFF.
*/
#define TMU_DRV_DEV_ERROR_DETECT        (STD_OFF)

/**
* @brief Defines number of input channels.
*/
#define TMU_DRV_INPUT_CHANNELS_COUNT     (83U)

/**
* @brief Defines number of output channels.
*/
#define TMU_DRV_OUTPUT_CHANNELS_COUNT     (40U)

/** @} end of Public_MacroDefinition */

/** @defgroup SwNormalQueueIndex
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

/** @} end of group Tmu_Drv */

/** @} end of group Platform_Module */

#endif /* TMU_DRV_CFG_H */
