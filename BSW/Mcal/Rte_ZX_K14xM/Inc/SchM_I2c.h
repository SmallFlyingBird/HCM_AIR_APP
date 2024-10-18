/**************************************************************************************************/
/**
 * @file      : SchM_I2c.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_I2C_H
#define SCHM_I2C_H

/** @addtogroup  Mcal Driver
 *  @{
 */

/** @addtogroup  I2c Driver
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup SchM_I2c_Public_Defines
 *  @{
 */
#define SCHM_I2C_H_VENDOR_ID                   0x00B3U       
#define SCHM_I2C_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_I2C_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_I2C_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_I2C_H_SW_MAJOR_VERSION            1U
#define SCHM_I2C_H_SW_MINOR_VERSION            2U
#define SCHM_I2C_H_SW_PATCH_VERSION            1U
   
/** @} end of group SchM_I2c_Public_Defines */

/** @defgroup SchM_I2c_Public_FunctionDeclaration
 *  @{
 */     
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group SchM_I2c_Public_FunctionDeclaration */

#ifdef __cplusplus
    }
#endif
        
/** @} end of group I2c Driver  */
/** @} end of group Mcal Driver */

#endif    /* SCHM_I2C_H */


