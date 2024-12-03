/**************************************************************************************************/
/**
 * @file      : ComStack_Types.h
 * @brief     : AUTOSAR Can Communication stack types definition
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/** @addtogroup  Base_Module
 *  @{
 */

/** @defgroup ComStack_Types
 *  @brief AUTOSAR standard types definition
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define COMSTACK_VENDOR_ID                   0x00B3U
#define COMSTACK_AR_RELEASE_MAJOR_VERSION    4U
#define COMSTACK_AR_RELEASE_MINOR_VERSION    6U
#define COMSTACK_AR_RELEASE_REVISION_VERSION 0U
#define COMSTACK_SW_MAJOR_VERSION            1U
#define COMSTACK_SW_MINOR_VERSION            2U
#define COMSTACK_SW_PATCH_VERSION            2U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief   CAN PDU lenght type.
 */
typedef uint32 PduLengthType;

/**
 * @brief   CAN PDU identifier type.
 */
typedef uint16 PduIdType;

/**
 * @brief   Variables of this type shall be used to store the basic information about a PDU of
 *          any type, namely a pointer variable pointing to its SDU (payload), a pointer to
 *          Meta Data of the PDU, and the corresponding length of the SDU in bytes.
 */
typedef struct
{
    uint8 *SduDataPtr; /*!< Pointer to the payload data of the PDU*/
    uint8
        *MetaDataPtr;        /*!< Pointer to the meta data (e.g. CAN ID,
                                                              socket ID, diagnostic addresses) of the PDU*/
    PduLengthType SduLength; /*!< Length of the SDU in bytes.*/

} PduInfoType;

/**
 * @brief   IcomConfigIdType defines the configuration ID. An ID of 0 is the default
 *          configuration. An ID greater than 0 shall identify a configuration for Pretended
 *          Networking.
 */
typedef uint8 IcomConfigIdType;

/**
 * @brief   IcomSwitch_ErrorType defines the errors which can occur when activating or
 *          deactivating Pretended Networking
 */
typedef enum
{
    ICOM_SWITCH_E_OK = 0U, /*!< The activation of Pretended Networking was successful.*/
    ICOM_SWITCH_E_FAILED,  /*!< The activation of Pretended Networking was not successful.*/

} IcomSwitch_ErrorType;

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

/** @} end of group ComStack_Types */
/** @} end of group Base_Module */

#endif /* COMSTACK_TYPES_H */
