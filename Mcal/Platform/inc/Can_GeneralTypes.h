/**
 * @file                   Can_GeneralTypes.h
 * @version                V2.3.0
 *
 * @brief                  AUTOSAR Can_GeneralTypes module interface
 * @details                API implementation for CAN_GENERALTYPES driver
 *
 * @addtogroup             GENERAL
 * @{
 */
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V2.3.0
*
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef CAN_GENERALTYPES_H
#define CAN_GENERALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "ComStack_Types.h"
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief This type defines a data structure which clearly provides an Hardware Object Handle
 *        including its corresponding CAN Controller and therefore CanDrv as well as the specific
 *        CanId
 * @note trace: SWS_Can_00429
 */
typedef uint32 Can_IdType;

#if (defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0))
/**
 * @brief Represents the hardware object handles of a CAN hardware unit. For CAN hardware units with
 *        more than 255 HW objects use extended range.
 * @note trace: SWS_CAN_00429
 */
 typedef uint8 Can_HwHandleType;
 #else
 /**
 * @brief Represents the hardware object handles of a CAN hardware unit. For CAN hardware units with
 *        more than 255 HW objects use extended range.
 * @note trace: SWS_CAN_00429
 */
typedef uint16 Can_HwHandleType;
#endif
/**
 * @brief This type defines a data structure which clearly provides an Hardware Object Handle
 *        including its corresponding CAN Controller and therefore CanDrv as well as the specific
 *        CanId
 * @note  trace: SWS_CAN_00496
 */
typedef struct
{
    Can_IdType CanId;       /*!< Can ID of Corresponding mailbox*/
    Can_HwHandleType Hoh;   /*!< Hardware object handle Id*/
    uint8 ControllerId;     /*!< Can controller ID */
} Can_HwType;

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
* @brief CAN Transceiver modes.
* @details Operating modes of the CAN Transceiver Driver.
*
*/
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL = 0U, /**< @brief Transceiver mode NORMAL */
    CANTRCV_TRCVMODE_STANDBY,     /**< @brief Transceiver mode STANDBY */
    CANTRCV_TRCVMODE_SLEEP        /**< @brief Transceiver mode SLEEP */
} CanTrcv_TrcvModeType;

/**
* @brief          
* @details   This type shall be used to control the CAN transceiver concerning wake up events and wake up notifications.     
* According to [SWS_CanTrcv_00164] it should be present in Can_GeneralTypes.h
*/
typedef enum
{
	CANTRCV_WUMODE_ENABLE = 0x00,   /* The notification for wakeup events is enabled on the addressed transceiver. */
	CANTRCV_WUMODE_DISABLE = 0x01,  /* The notification for wakeup events is disabled on the addressed transceiver. */
	CANTRCV_WUMODE_CLEAR = 0x02	 	/* A stored wakeup event is cleared on the addressed transceiver. */
} CanTrcv_TrcvWakeupModeType;

/**
* @brief          
* @details   This type denotes the wake up reason detected by the CAN transceiver in detail.
* According to [SWS_CanTrcv_00165] it should be present in Can_GeneralTypes.h
*/
typedef enum
{
	CANTRCV_WU_ERROR	 		= 0, /* Due to an error wake up reason was not detected. This value may only be reported when error was reported to DEM before. */
	CANTRCV_WU_NOT_SUPPORTED 	= 1, /* The transceiver does not support any information for the wake up reason.  */
	CANTRCV_WU_BY_BUS			= 2, /* The transceiver has detected, that the network has caused the wake up of the ECU. */
	CANTRCV_WU_INTERNALLY		= 3, /* The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode. */
	CANTRCV_WU_RESET			= 4, /* The transceiver has detected, that the "wake up" is due to an ECU reset. */
	CANTRCV_WU_POWER_ON			= 5, /* The transceiver has detected, that the "wake up" is due to an ECU reset after power on. */
	CANTRCV_WU_BY_PIN			= 6, /* The transceiver has detected a wake-up event at one of the transceiver's pins (not at the CAN bus). */
	CANTRCV_WU_BY_SYSERR		= 7  /* The transceiver has detected, that the wake up of the ECU was caused by a HW related device failure. */
} CanTrcv_TrcvWakeupReasonType;

/**
* @brief          CAN Controller State Modes of operation.
* @details        States that are used by the several ControllerMode functions
* @implements     Can_ControllerStateType_enum
*/
typedef enum
{
    CAN_CS_UNINIT  = 0U,    /**< @brief CAN controller state UNINIT */
    CAN_CS_STARTED,         /**< @brief CAN controller state STARTED */
    CAN_CS_STOPPED,         /**< @brief CAN controller state STOPPED */
    CAN_CS_SLEEP            /**< @brief CAN controller state SLEEP */
} Can_ControllerStateType;

/**
* @brief          CAN Controller State Modes of operation.
* @details        Error states of a CAN controller
* @implements     Can_ErrorStateType_enum
*/
typedef enum
{
    CAN_ERRORSTATE_ACTIVE = 0U,     /**< @brief The CAN controller takes fully part in communication. */
    CAN_ERRORSTATE_PASSIVE,         /**< @brief The CAN controller takes part in communication, but does not send active error frames. */
    CAN_ERRORSTATE_BUSOFF           /**< @brief The CAN controller does not take part in communication. */
} Can_ErrorStateType;

/**
 * @brief State transitions that are used by the function CAN_SetControllerMode
 * @note trace: SWS_Can_00417
 */
typedef enum{
    CAN_T_START,
    CAN_T_STOP,
    CAN_T_SLEEP,
    CAN_T_WAKEUP
} Can_StateTransitionType;



/**
 * @brief Return values of CAN driver API
 * @note trace: SWS_Can_00039
 */
typedef enum {
    CAN_OK,
    CAN_NOT_OK,
    CAN_BUSY,
    CAN_DMA_INIT_FAILED
} Can_ReturnType;


/**
 * @brief This type unites PduId (swPduHandle), SduLength (length),
 *      SduData (sdu), and CanId (id) for any CAN L-SDU
 * @note trace: SWS_Can_00415
 */
typedef struct
{
    PduIdType swPduHandle;  /*!< ID of Can L-PDU */
    uint8 length;           /*!< Length of Can L-PDU in bytes */
    Can_IdType id;          /*!< Can ID of Can L-PDU */
    uint8 *sdu;             /*!< Pointer to Can L-PDU data buffer */
} Can_PduType;



#ifdef __cplusplus
}
#endif

#endif /* CAN_GENERALTYPES_H */
/** @} */

