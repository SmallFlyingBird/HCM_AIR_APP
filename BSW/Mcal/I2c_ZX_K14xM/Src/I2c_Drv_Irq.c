/**************************************************************************************************/
/**
 * @file      : I2c_Drv_Irq.c
 * @brief     : AUTOSAR I2c hardware interrupt driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  I2c_Module
 *  @{
 */

/** @addtogroup  I2c_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "I2c_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define I2C_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define I2C_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define I2C_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define I2C_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define I2C_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define I2C_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define I2C_DRV_IRQ_C_SW_PATCH_VERSION            2U

#if (I2C_DRV_IRQ_C_VENDOR_ID != I2C_DRV_H_VENDOR_ID)
    #error "Vendor ID of I2c_Drv_Irq.c and I2c_Drv.h are different"
#endif

#if ((I2C_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != I2C_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (I2C_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != I2C_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (I2C_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != I2C_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of I2c_Drv_Irq.c and I2c_Drv.h are different"
#endif

#if ((I2C_DRV_IRQ_C_SW_MAJOR_VERSION != I2C_DRV_H_SW_MAJOR_VERSION) ||                             \
     (I2C_DRV_IRQ_C_SW_MINOR_VERSION != I2C_DRV_H_SW_MINOR_VERSION) ||                             \
     (I2C_DRV_IRQ_C_SW_PATCH_VERSION != I2C_DRV_H_SW_PATCH_VERSION))
    #error "Software version of I2c_Drv_Irq.c and I2c_Drv.h are different"
#endif

/** @} end of group Private_MacroDefinition */

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
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

ISR(I2c_Drv_0_ChIrqHandler);

#if (I2C_DRV_INSTANCE_NUM == 2U)
ISR(I2c_Drv_1_ChIrqHandler);
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief  I2c 0 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(I2c_Drv_0_ChIrqHandler)
{
    I2c_Drv_ChIntHandler(I2C_DRV_ID_0);
    EXIT_INTERRUPT();
}

#if (I2C_DRV_INSTANCE_NUM == 2U)
/**
 * @brief  I2c 1 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
ISR(I2c_Drv_1_ChIrqHandler)
{
    I2c_Drv_ChIntHandler(I2C_DRV_ID_1);
    EXIT_INTERRUPT();
}
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group I2c_Drv */
/** @} end of group I2c_Module */
