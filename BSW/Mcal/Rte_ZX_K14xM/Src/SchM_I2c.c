/**************************************************************************************************/
/**
 * @file      : SchM_I2c.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Mcal Driver
 *  @{
 */

/** @addtogroup  I2c Driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "SchM_I2c.h"

/** @defgroup SchM_I2c_Private_Defines
 *  @{
 */
#define SCHM_I2C_C_VENDOR_ID                   0x00B3U
#define SCHM_I2C_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_I2C_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_I2C_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_I2C_C_SW_MAJOR_VERSION            1U
#define SCHM_I2C_C_SW_MINOR_VERSION            2U
#define SCHM_I2C_C_SW_PATCH_VERSION            1U

#if (SCHM_I2C_C_VENDOR_ID != SCHM_I2C_H_VENDOR_ID)
    #error "SchM_I2c.c and SchM_I2c.h have different vendor ids"
#endif
                            
#if ((SCHM_I2C_C_AR_RELEASE_MAJOR_VERSION != SCHM_I2C_H_AR_RELEASE_MAJOR_VERSION) || \
        (SCHM_I2C_C_AR_RELEASE_MINOR_VERSION != SCHM_I2C_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of SchM_I2c.c and SchM_I2c.h are different"
#endif
                            
#if ((SCHM_I2C_C_SW_MAJOR_VERSION != SCHM_I2C_H_SW_MAJOR_VERSION) || \
        (SCHM_I2C_C_SW_MINOR_VERSION != SCHM_I2C_H_SW_MINOR_VERSION))
    #error "Software version of SchM_I2c.c and SchM_I2c.h are different"
#endif

#if ((SCHM_I2C_C_AR_RELEASE_REVISION_VERSION != SCHM_I2C_H_AR_RELEASE_REVISION_VERSION) || \
        (SCHM_I2C_C_SW_PATCH_VERSION != SCHM_I2C_H_SW_PATCH_VERSION))
    #error "Software version of SchM_I2c.c and SchM_I2c.h are different"
#endif


#ifdef MCAL_ASR_VER_CHECK_ENABLE
    #if (SCHM_I2C_C_VENDOR_ID != STD_VENDOR_ID)
        #error "SchM_I2c.c and Std_Types.h have different vendor ids"
    #endif
                             
    #if ((SCHM_I2C_C_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
          (SCHM_I2C_C_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of SchM_I2c.c and Std_Types.h are different"
    #endif
                             
    #if ((SCHM_I2C_C_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
          (SCHM_I2C_C_SW_MINOR_VERSION != STD_SW_MINOR_VERSION))
        #error "Software version of SchM_I2c.c and Std_Types.h are different"
    #endif

    #if (SCHM_I2C_C_VENDOR_ID != MCALLIB_VENDOR_ID)
        #error "SchM_I2c.c and McalLib.h have different vendor ids"
    #endif
                             
    #if ((SCHM_I2C_C_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
          (SCHM_I2C_C_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of SchM_I2c.c and McalLib.h are different"
    #endif
                             
    #if ((SCHM_I2C_C_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) || \
          (SCHM_I2C_C_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION))
        #error "Software version of SchM_I2c.c and McalLib.h are different"
    #endif
        
#endif


/** @} end of group SchM_I2c_Private_Defines */

/** @defgroup SchM_I2c_Private_Type
 *  @{
 */

/** @} end of group SchM_I2c_Private_Type */

/** @defgroup SchM_I2c_Public_Macro
 *  @{
 */

/** @} end of group SchM_I2c_Public_Macro */

/** @defgroup SchM_I2c_Private_Variables
 *  @{
 */

/** @} end of group SchM_I2c_Private_Variables */

/** @defgroup SchM_I2c_Global_Variables
 *  @{
 */

/** @} end of group SchM_I2c_Global_Variables */

/** @defgroup SchM_I2c_Private_FunctionDeclaration
 *  @{
 */

/** @} end of group SchM_I2c_Private_FunctionDeclaration */

/** @defgroup SchM_I2c_Private_Functions
 *  @{
 */

/** @} end of group SchM_I2c_Private_Functions */

/** @defgroup SchM_I2c_Public_Functions
 *  @{
 */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"


#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group SchM_I2c_Public_Functions */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c Driver */
/** @} end of group Mcal Driver */


