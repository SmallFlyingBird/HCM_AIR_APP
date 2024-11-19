/**************************************************************************************************/
/**
 * @file      : Uart_Drv_PBcfg.c  
 * @brief     : Lin low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Drv_Configuration
 *  @brief Lin low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif


#include "Uart_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define UART_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define UART_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define UART_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define UART_DRV_PBCFG_C_SW_PATCH_VERSION            2U

/* Checks against Uart_Drv.h */
#if (UART_DRV_H_VENDOR_ID != UART_DRV_PBCFG_C_VENDOR_ID)
    #error "Vendor ID of Uart_Drv.h and Uart_Drv_PBcfg.c are different"
#endif
/* Check if Lin_Drv.h file and Lin_Drv_PBcfg.c file are of the same Autosar version */
#if ((UART_DRV_H_AR_RELEASE_MAJOR_VERSION != UART_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION) ||  \
     (UART_DRV_H_AR_RELEASE_MINOR_VERSION != UART_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION) ||  \
     (UART_DRV_H_AR_RELEASE_REVISION_VERSION != UART_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Uart_Drv.h and Uart_Drv_PBcfg.c are different"
#endif
#if ((UART_DRV_H_SW_MAJOR_VERSION != UART_DRV_PBCFG_C_SW_MAJOR_VERSION) ||  \
     (UART_DRV_H_SW_MINOR_VERSION != UART_DRV_PBCFG_C_SW_MINOR_VERSION) ||  \
     (UART_DRV_H_SW_PATCH_VERSION != UART_DRV_PBCFG_C_SW_PATCH_VERSION))
    #error "Software Version of Uart_Drv.h and Uart_Drv_PBcfg.c are different"
#endif
/* clang-format off */
/** @} end of Private_MacroDefinition */


/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/**
* @brief          Hardware configuration in driver layer
*/
const Uart_Drv_ConfigType Uart_Drv_LinConfig0 =
{

    3U, /*!< Hardware instance */
    (uint32)0x4eU, /*!< integer Baudrate divisor */
    (uint32)0x2U, /*!< franction Baudrate divisor */

    UART_DRV_NODE_MASTER, /*!< Master node */

    13U, /*!< Break length bits */
    1U,    /*!< delimeter bits */
   
    (boolean)0U, /*!< Disable Autosync feature */
    
    &Lin_Drvw_MasterCallback, /*!< Master node */

    &Uart_Drv_TransferConfigArray[0U], /*!< transfer config */
#if (STD_ON == UART_DRV_SOFTWARE_SIMULATION_TIMEOUT)

    3000U, /*!< Header timeout timer after receive break */
    1000U,    /*!< Response timeout timer for 1 byte */
	
#endif

   (uint8)11U, /*!< wake up 11bits */
#if (UART_DRV_WAKEUP_DETECTION == STD_ON)
    (uint8)1U, /*!< calculate wake up bit */
#endif
    24000000U, /*!< Channel clock */
};

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

/** @} end of group Global_VariableDefinition */

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

/** @} end of group Lin_Drv_Configuration */

/** @} end of group Lin_Module */
