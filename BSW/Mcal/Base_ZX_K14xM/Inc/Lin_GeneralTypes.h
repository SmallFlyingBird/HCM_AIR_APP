/**************************************************************************************************/
/**
 * @file      : Lin_GeneralTypes.h
 * @brief     : AUTOSAR LIN driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef LIN_GENERAL_TPYES_H
#define LIN_GENERAL_TPYES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* published information */
#define LIN_GENERAL_H_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_GENERAL_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_GENERAL_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_GENERAL_H_SW_MAJOR_VERSION            1U
#define LIN_GENERAL_H_SW_MINOR_VERSION            2U
#define LIN_GENERAL_H_SW_PATCH_VERSION            1U

/**
 * @brief  Represents all valid protected identifier used by Lin_SendFrame().
 *         The LIN identifier (0...0x3F) together with its two parity bits
 */
typedef uint8 Lin_FramePidType;

/**
 * @brief  This type is used to specify the number of SDU data bytes to copy
 *         Data length of a LIN Frame:1-8
 * @details [SWS_Lin_00231]
 */
typedef uint8 Lin_FrameDlType;

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  This type is used to specify the Checksum model to be used for the LIN Frame.
 * @details [SWS_Lin_00229]
 */
typedef enum
{
    LIN_ENHANCED_CS, /*!<  Enhanced checksum model */
	LIN_CLASSIC_CS /*!<  Classic checksum model */
} Lin_FrameCsModelType;

/**
 * @brief  This type is used to specify whether the frame processor is required to
 *         transmit the response part of the LIN frame.
 * @details [SWS_Lin_00230]
 */
typedef enum
{
    LIN_FRAMERESPONSE_TX,    /*!< Response is generated from this node */
    LIN_FRAMERESPONSE_RX,    /*!< Response is generated from another node and is relevant for this
                                node. */
    LIN_FRAMERESPONSE_IGNORE /*!< Response is generated from another node and is irrelevant for this
                                node */
} Lin_FrameResponseType;

/**
 * @brief  LIN operation states for a LIN channel or frame, as returned
 *        by the API service Lin_GetStatus().
 *        [SWS_Lin_00200]The return states LIN_TX_OK, LIN_TX_BUSY,
 *        LIN_TX_HEADER_ERROR, LIN_TX_ERROR, LIN_RX_OK, LIN_RX_BUSY,
 *        LIN_RX_ERROR , LIN_RX_NO_RESPONSE and LIN_OPERATIONAL are substates
 *        of the channel state LIN_CH_OPERATIONAL.
 */
typedef enum
{
    LIN_NOT_OK,  /*!< LIN frame operation return value. Development or production error occurred */
    LIN_TX_OK,   /*!< LIN frame operation return value. Successful transmission. */
    LIN_TX_BUSY, /*!< LIN frame operation return value. Ongoing transmission(Header or Response).*/
    LIN_TX_HEADER_ERROR, /*!< LIN frame operation return value. Erroneous header transmission such
                            as:
                            - Mismatch between sent and read back data
                            - Identifier parity error or
                            - Physical bus error */
    LIN_TX_ERROR, /*!< LIN frame operation return value. Erroneous response transmission such as:
                                            - Mismatch between sent and read back data
                                            - Physical bus error */
    LIN_RX_OK,    /*!< LIN frame operation return value. Reception of correct response. */
    LIN_RX_BUSY,  /*!< LIN frame operation return value. Ongoing reception:
                                          at least one response byte has been received, but the
                     checksum byte has not been received. */
    LIN_RX_ERROR, /*!< LIN frame operation return value. Erroneous response reception such as:
                                          - Framing error
                                          - Overrun error
                                          - Checksum error or
                                          - Short response  */
    LIN_RX_NO_RESPONSE, /*!< LIN frame operation return value. No response byte has been received so
                           far. */
    LIN_OPERATIONAL,    /*!< LIN channel state return value. Normal operation;
                            the related LIN channel is ready to transmit next
                           header.    No data from previous frame available (e.g. after
                           initialization)*/
    LIN_CH_SLEEP        /*!< LIN channel state return value. Sleep state operation;
                            in this state wake-up detection from slave nodes is
                           enabled.*/
} Lin_StatusType;

/**
 * @brief  This type represents the slave error types that are detected
 *         during header reception and response transmission / reception.
 */
typedef enum
{
    LIN_ERR_HEADER,       /*!< Error in header */
    LIN_ERR_RESP_STOPBIT, /*!< Framing error in response */
    LIN_ERR_RESP_CHKSUM,  /*!< Framing error in response */
    LIN_ERR_RESP_DATABIT, /*!< Monitoring error of transmitted data bit in response */
    LIN_ERR_NO_RESP,      /*!< No response */
    LIN_ERR_INC_RESP      /*!< Incomplete response */
} Lin_SlaveErrorType;

/**
 * @brief  This Type is used to provide PID, checksum model, data length and SDU
 *         pointer from the LIN Interface to the LIN driver.
 * @details [SWS_Lin_00232]
 */
typedef struct
{
    Lin_FramePidType      Pid;    /*!< protected identifier */
    Lin_FrameCsModelType  Cs;     /*!< checksum model */
    Lin_FrameResponseType Drc;    /*!< transmit the response part of the LIN frame */
    Lin_FrameDlType       Dl;     /*!< data length */
    uint8                *SduPtr; /*!< data */
} Lin_PduType;

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

#endif /* LIN_GENERAL_TPYES_H */
