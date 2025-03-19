/**************************************************************************************************/
/**
 * @file      : Lin_Drvw_PBcfg.c
 * @brief     : Lin driver wrapper - Post-Build(PB) configuration file code template
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

/** @addtogroup Lin_Drvw_Configuration
 *  @brief Lin middle level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Lin_Drvw.h"
#include "Uart_Drv.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */
#define LIN_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define LIN_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define LIN_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define LIN_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define LIN_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define LIN_DRVW_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if Lin_Drvw.h and Lin_Drvw_PBcfg.c are of the same vendor */
#if ( LIN_DRVW_H_VENDOR_ID != LIN_DRVW_PBCFG_C_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw.h and Lin_Drvw_PBcfg.c are different"
#endif
/* Check if Lin_Drvw.h file and Lin_Drvw_PBcfg.c file are of the same Autosar version */
#if ((LIN_DRVW_H_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_DRVW_H_AR_RELEASE_MINOR_VERSION != LIN_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION) || \
     (LIN_DRVW_H_AR_RELEASE_REVISION_VERSION != LIN_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Drvw.h and Lin_Drvw_PBcfg.c are different"
#endif
#if ((LIN_DRVW_H_SW_MAJOR_VERSION != LIN_DRVW_PBCFG_C_SW_MAJOR_VERSION) || \
     (LIN_DRVW_H_SW_MINOR_VERSION != LIN_DRVW_PBCFG_C_SW_MINOR_VERSION) || \
     (LIN_DRVW_H_SW_PATCH_VERSION != LIN_DRVW_PBCFG_C_SW_PATCH_VERSION))
    #error "Software Version of Lin_Drvw.h and Lin_Drvw_PBcfg.c are different"
#endif

/* Check if Uart_Drv.h and Lin_Drvw_PBcfg.c are of the same vendor */
#if (UART_DRV_H_VENDOR_ID != LIN_DRVW_PBCFG_C_VENDOR_ID)
    #error "Vendor ID of Uart_Drv.h and Lin_Drvw_PBcfg.c are different"
#endif
/* Check if Uart_Drv_Cfg.h file and Lin_Drvw_PBcfg.c file are of the same Autosar version */
#if ((UART_DRV_H_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION) || \
     (UART_DRV_H_AR_RELEASE_MINOR_VERSION != LIN_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION) || \
     (UART_DRV_H_AR_RELEASE_REVISION_VERSION != LIN_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Uart_Drv.h and Lin_Drvw_PBcfg.c are different"
#endif

#if ((UART_DRV_H_SW_MAJOR_VERSION != LIN_DRVW_PBCFG_C_SW_MAJOR_VERSION) || \
     (UART_DRV_H_SW_MINOR_VERSION != LIN_DRVW_PBCFG_C_SW_MINOR_VERSION) || \
     (UART_DRV_H_SW_PATCH_VERSION != LIN_DRVW_PBCFG_C_SW_PATCH_VERSION))
    #error "Software Version of Uart_Drv.h and Lin_Drvw_PBcfg.c are different"
#endif

#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"



#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

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
*
* @brief          Hardware configuration in wrapper layer
*
*/
const Lin_Drvw_HwConfigType Lin_Drvw_HwConfig0 =
{
        (uint8)UART_DRV_ID_3,
#if (LIN_DRVW_WAKEUP_DETECTION == STD_ON)
    (boolean)FALSE, /* Wakeup support enabled */
    (EcuM_WakeupSourceType)((uint32)1UL << 6U), /* When Wakeup support, Wakeup Source transmitted to the Ecu State Manager  */

#endif
    LIN_DRVW_NODE_SLAVE, /* Lin Node Type */
    &Uart_Drv_LinConfig0
};

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"

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

/** @} end of group Lin_Drvw_Configuration */

/** @} end of group Lin_Module */

