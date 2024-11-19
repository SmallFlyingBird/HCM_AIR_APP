/**************************************************************************************************/
/**
 * @file      : Uart_Drv_PBcfg.h
 * @brief     : Lin low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef UART_DRV_PBCFG_H
#define UART_DRV_PBCFG_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Drv_Configuration
 *  @brief Lin low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Inclusion of incompatible header files shall be avoided */
#define UART_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define UART_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define UART_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define UART_DRV_PBCFG_H_SW_PATCH_VERSION            2U


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"


#define UART_DRV_CONFIG \
extern Uart_Drv_TransferConfigType Uart_Drv_TransferConfigArray[UART_DRV_NUMBER_OF_INSTANCES_USED];




#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

#define UART_DRV_CONFIG_PB \
extern const Uart_Drv_ConfigType Uart_Drv_LinConfig0; \



/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

    /* uart callback function*/
#define UART_DRV_CALLBACK \
    extern void Lin_Drvw_MasterCallback(const uint8 InstanceId, const Uart_Drv_TransferConfigType *StateStructPtr);\
    extern void Lin_Drvw_SlaveCallback(const uint8 InstanceId, const Uart_Drv_TransferConfigType *StateStructPtr);





            
    






            
    



/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Lin_Drv_Configuration */

/** @} end of group Lin_Module */

#endif
