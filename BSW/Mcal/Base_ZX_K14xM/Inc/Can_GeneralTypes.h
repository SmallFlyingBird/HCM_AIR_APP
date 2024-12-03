/**************************************************************************************************/
/**
 * @file      : Can_GeneralTypes.h
 * @brief     : AUTOSAR Can General types definition
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_GENERALTYPES_H
#define CAN_GENERALTYPES_H

/** @addtogroup  Base_Module
 *  @{
 */

/** @defgroup Can_General_Types
 *  @brief AUTOSAR standard types definition
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "ComStack_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* published information */

#define CAN_GENERAL_VENDOR_ID                   0x00B3U
#define CAN_GENERAL_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_GENERAL_AR_RELEASE_MINOR_VERSION    6U
#define CAN_GENERAL_AR_RELEASE_REVISION_VERSION 0U
#define CAN_GENERAL_SW_MAJOR_VERSION            1U
#define CAN_GENERAL_SW_MINOR_VERSION            2U
#define CAN_GENERAL_SW_PATCH_VERSION            2U

/**
 * @brief  Extension to Std_ReturnType
 * @details transmit request could not be processed because no transmit object was available
 */
#define CAN_BUSY (0x02U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief   CAN identifier type. Represents the Identifier of an L-PDU. The two most significant
 *          bits specify the frame type: 00 CAN message with Standard CAN ID 01 CAN FD frame with
 *          Standard CAN ID 10 CAN message with Extended CAN ID 11 CAN FD frame with Extended CAN ID
 */
typedef uint32 Can_IdType;

/**
 * @brief   CAN hardware object type. Type definition of can hardware unit. Use the extended range
 *          when there are more than 255 can hardware units of hardware.
 */

#ifdef CAN_MBCOUNTEXTENSION
    #if (CAN_MBCOUNTEXTENSION == STD_ON)
typedef uint32 Can_HwHandleType
    #else
typedef uint8 Can_HwHandleType
    #endif
#else
typedef uint8 Can_HwHandleType;
#endif

    /**
     * @brief  Error states of a CAN controller.
     */
    typedef enum
{
    CAN_ERRORSTATE_ACTIVE = 0U, /*!< The CAN controller takes fully part in communication */
    CAN_ERRORSTATE_PASSIVE,     /*!< The CAN controller takes part in communication, but does
                                   not send active error frames*/
    CAN_ERRORSTATE_BUSOFF       /*!< The CAN controller does not take part in communication*/

} Can_ErrorStateType;

/**
 * @brief  State of ControllerMode .
 */
typedef enum
{
    CAN_CS_UNINIT = 0x00U,  /*!< CAN controller state UNINIT*/
    CAN_CS_STARTED = 0x01U, /*!< CAN controller state STARTED*/
    CAN_CS_STOPPED = 0x02U, /*!< CAN controller state STOPPED*/
    CAN_CS_SLEEP = 0x03U    /*!< CAN controller state SLEEP*/
} Can_ControllerStateType;

/**
 * @brief  represents a superset of CAN Error Types which typical CAN HW is able to report
 */
typedef enum
{
    CAN_ERROR_BIT_MONITORING1 = 0x01U,       /*!< A 0 was transmitted and a 1 was read back*/
    CAN_ERROR_BIT_MONITORING0 = 0x02U,       /*!< A 1 was transmitted and a 0 was read back*/
    CAN_ERROR_BIT = 0x03U,                   /*!< The HW reports a CAN bit error*/
    CAN_ERROR_CHECK_ACK_FAILED = 0x04U,      /*!< Acknowledgement check failed */
    CAN_ERROR_ACK_DELIMITER = 0x05U,         /*!< Acknowledgement delimiter check failed*/
    CAN_ERROR_ARBITRATION_LOST = 0x06U,      /*!< The sender lost in arbitration.*/
    CAN_ERROR_OVERLOAD = 0x07U,              /*!< CAN overload detected via an overload frame */
    CAN_ERROR_CHECK_FORM_FAILED = 0x08U,     /*!< Violations of the fixed frame format */
    CAN_ERROR_CHECK_STUFFING_FAILED = 0x09U, /*!< Stuffing bits not as expected */
    CAN_ERROR_CHECK_CRC_FAILED = 0x0AU,      /*!< CRC failed */
    CAN_ERROR_BUS_LOCK = 0x0BU,              /*!< Bus lock */
} Can_ErrorType;

/**
 * @brief  Can Pdu type .This type unites PduId (swPduHandle), SduLength (length), SduData (sdu),
 * and Can Id (id) for any CAN L-SDU.
 */
typedef struct
{
    PduIdType  swPduHandle; /*!< identifier of a PDU*/
    uint8      length;      /*!< PDU data length*/
    Can_IdType id;          /*!< PDU Frame identifier*/
    uint8     *sdu;         /*!< PDU transported Data*/
} Can_PduType;

/**
 * @brief  Can Hardware Object type. This type defines a data structure which clearly provides an
 * Hardware Object Handle including its corresponding CAN Controller and therefore CanDrv as well as
 * the specific CanId.
 */
typedef struct
{
    Can_IdType       CanId;        /*!< Standard/Extended CAN ID of CAN L-PDU*/
    Can_HwHandleType Hoh;          /*!< ID of the corresponding Hardware Object Range*/
    uint8            ControllerId; /*!< ControllerId provided by CanIf clearly identify the
                                                         corresponding controller*/
} Can_HwType;

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

/** @} end of group Can_General_Types */
/** @} end of group Base_Module */

#endif /* CAN_GENERALTYPES_H */
