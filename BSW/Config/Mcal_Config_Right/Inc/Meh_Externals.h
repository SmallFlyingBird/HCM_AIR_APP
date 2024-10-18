/**************************************************************************************************/
/**
 * @file      : Meh_Externals.h
 * @brief     : Meh externals header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MEH_EXTERNALS_H
#define MEH_EXTERNALS_H

/** @addtogroup  Meh_Module
 *  @{
 */
#include "Meh_Types.h"
/** @defgroup Meh
 *  @brief Meh configuration header file
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MEH_EXTERNALS_H_VENDOR_ID                   0x00B3U
#define MEH_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_EXTERNALS_H_AR_RELEASE_MINOR_VERSION    6U
#define MEH_EXTERNALS_H_AR_RELEASE_REVISION_VERSION 0U
#define MEH_EXTERNALS_H_SW_MAJOR_VERSION            1U
#define MEH_EXTERNALS_H_SW_MINOR_VERSION            1U
#define MEH_EXTERNALS_H_SW_PATCH_VERSION            0U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Meh_Externals.h and Meh_Types.h are of the same AUTOSAR version */
    #if ((MEH_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION != MEH_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (MEH_EXTERNALS_H_AR_RELEASE_MINOR_VERSION != MEH_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Meh_Externals.h and Meh_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define MEH_SERU_PARITY_ERRORNOTIFICATIONPTR SeruParityErrorCallbackFunc

#define MEH_SERU_CHANNEL_ERRORNOTIFICATIONPTR SeruChannelErrorCallbackFunc

#define MEH_EIRU_ERRORNOTIFICATIONPTR EiruErrorCallback

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/**
 * @brief      Meh Seru parity Callback Error Notification
 * @details    This is a external function and shall be implemented by user.
 *
 * @param[in]  None
 * 
 * @return     None
 * 
 */
extern void SeruParityErrorCallbackFunc(void);


/**
 * @brief      Meh Seru Channel Callback Error Notification
 * @details    This is a external function and shall be implemented by user.
 *
 * @param[in]  SeruCh: Seru channel number.
 * 
 * @return     None
 * 
 */
extern void SeruChannelErrorCallbackFunc(uint32 SeruCh);


/**
 * @brief      Meh Eiru Callback Error Notification
 * @details    This is a external function and shall be implemented by user.
 *
 * @param[in]  Sram: sram type.
 * @param[in]  ErrorStatus: Error status.
 * @param[in]  ErrorCausePtr: Pointer to Error Cause.
 * 
 * @return     None
 */
extern void EiruErrorCallback(const Meh_SramType             Sram,
                                          const Meh_SramEccErrStatusType ErrorStatus,
                                          Meh_SramEccErrCauseType       *ErrorCausePtr);
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Meh_externals */

/** @} end of group Meh_Module */
#endif /* MEH_EXTERNALS_H */
