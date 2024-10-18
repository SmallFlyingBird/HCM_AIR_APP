/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Can_GeneralTypes.h                                          **
**                                                                           **
**  AUTHOR      :                                                            **
**                                                                           **
**  VENDOR      :                                                            **
**                                                                           **
**  DESCRIPTION :General type definitions for CAN bus                        **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
******************************************************************************/

#ifndef CAN_GENERALTYPES
#define CAN_GENERALTYPES
#include "ComStack_Types.h"
/* CAN id Type Mixed is supported */
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
    CAN_CS_STARTED = 0x02U, /*!< CAN controller state STARTED*/
    CAN_CS_STOPPED = 0x01U, /*!< CAN controller state STOPPED*/
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
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    P2VAR(uint8, TYPEDEF, TYPEDEF) sdu;
} Can_PduType;

/*This type defines a data structure which clearly provides an Hardware Object
 * Handle including its corresponding CAN Controller and therefore CanDrv as
 * well as the specific CanId*/
typedef struct
{
    Can_IdType CanId;     /*Standard/Extended CAN ID of CAN L-PDU*/
    Can_HwHandleType Hoh; /*ID of the corresponding Hardware Object Range*/
    uint8 ControllerId;   /*ControllerId provided by CanIf clearly identify
                           the corresponding controller*/
} Can_HwType;

/*State transitions that are used by the function CAN_SetControllerMode*/
typedef enum
{
    CAN_T_START = 0x02U, /*CAN controller transition value to request state STARTED*/
    CAN_T_STOP = 0x01U,  /*CAN controller transition value to request state STOPPED*/
    CAN_T_SLEEP = 0x03U, /*CAN controller transition value to request state SLEEP*/
    CAN_T_WAKEUP = 0x01U /*transition value to request state STOPPED from state SLEEP*/
} Can_StateTransitionType;

/*Return values of CAN driver API*/
typedef enum
{
    CAN_OK,     /*success*/
    CAN_NOT_OK, /*error occurred or wakeup event occurred during sleep transition*/
    CAN_BUSY    /*transmit request could not be processed because no transmit
                 object was available*/
} Can_ReturnType;

/*Data type used for describing whether PN wakeup functionality in CanTrcv is
 * enabled or disabled.*/
typedef enum
{
    PN_ENABLED, /*PN wakeup functionality in CanTrcv is enabled*/
    PN_DISABLED /*PN wakeup functionality in CanTrcv is disabled*/
} CanTrcv_PNActivationType;

/*Provides the state of a flag in the transceiver hardware*/
typedef enum
{
    CANTRCV_FLAG_SET,    /*The flag is set in the transceiver hardware*/
    CANTRCV_FLAG_CLEARED /*The flag is cleared in the transceiver hardware*/
} CanTrcv_TrcvFlagStateType;

/*Operating modes of the CAN Transceiver Driver*/
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL = 0, /*Transceiver mode NORMAL*/
    CANTRCV_TRCVMODE_SLEEP,      /*Transceiver mode SLEEP*/
    CANTRCV_TRCVMODE_STANDBY     /*Transceiver mode STANDBY*/
} CanTrcv_TrcvModeType;

/*This type shall be used to control the CAN transceiver concerning wake up
 * events and wake up notifications*/
typedef enum
{
    CANTRCV_WUMODE_ENABLE = 0, /*notification for wakeup events enabled on the
                                addressed transceiver*/
    CANTRCV_WUMODE_DISABLE,    /*notification for wakeup events disabled on the
                                addressed transceiver*/
    CANTRCV_WUMODE_CLEAR       /*A stored wakeup event cleared on the addressed
                                transceiver*/
} CanTrcv_TrcvWakeupModeType;

/*This type denotes the wake up reason detected by the CAN transceiver in detail*/
typedef enum
{
    CANTRCV_WU_ERROR = 0,     /*Due to an error wake up reason was not detected.
                               This value may only be reported when error was
                               reported to DEM before*/
    CANTRCV_WU_NOT_SUPPORTED, /*The transceiver not support any information for
                               the wake up reason*/
    CANTRCV_WU_BY_BUS,        /*The transceiver has detected, that the network
                               has caused the wake up of the ECU*/
    CANTRCV_WU_INTERNALLY,    /*The transceiver has detected that the network
                              has woken up by the ECU via a request to NORMAL mode*/
    CANTRCV_WU_RESET,         /*The transceiver has detected, that the "wake up"
                               is due to an ECU reset*/
    CANTRCV_WU_POWER_ON,      /*The transceiver has detected, that the "wake up"
                               is due to an ECU reset after power on*/
    CANTRCV_WU_BY_PIN,        /*The transceiver has detected a wake-up event
                               at one of the transceiver's pins(not at the CAN bus)*/
    CANTRCV_WU_BY_SYSERR      /*The transceiver has detected, that the wake up
                              of the ECU was caused by a HW related device failure*/
} CanTrcv_TrcvWakeupReasonType;

#endif /*CAN_GENERALTYPES*/
