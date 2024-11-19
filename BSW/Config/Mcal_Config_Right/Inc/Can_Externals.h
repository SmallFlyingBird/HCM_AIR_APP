/***************************************************************************************************/
/**
 * @file      : Can_Externals.h  
 * @brief     : Can external header file. 
 *               - Platform: Z20K14xM
 *               - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_EXTERNALS_H
#define CAN_EXTERNALS_H

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CAN_EXTERNALS_H_VENDOR_ID                   0x00B3U
#define CAN_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_EXTERNALS_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_EXTERNALS_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_EXTERNALS_H_SW_MAJOR_VERSION            1U
#define CAN_EXTERNALS_H_SW_MINOR_VERSION            2U
#define CAN_EXTERNALS_H_SW_PATCH_VERSION            2U


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
 


extern boolean Interface_CanRcvMessageCallOut(uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth, const uint8* CanSduPtr);



/** @} end of group Public_FunctionDeclaration */



#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H */
