/**
*   @file    ComStack_Types.h
*   @version
*
*   @brief   ComStack type define
*
*   @addtogroup GENERAL
*   @{
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

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Compiler.h"
#include "Platform_Types.h"

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
typedef uint8        PduIdType;             /* uint8, uint16                 */
typedef uint16       PduLengthType;         /* uint8, uint16, uint32         */

typedef struct
{
    uint8            *SduDataPtr;   /**< Pointer of SDU data buffer */
    uint8            *MetaDataPtr;  /**< Pointer of Meta data buffer */
    PduLengthType    SduLength;     /**< Length of SDU data buffer */
} PduInfoType;

typedef uint8        PNCHandleType;

typedef enum
{
    TP_STMIN,
    TP_BS,
    TP_BC
} TPParameterType;

typedef enum
{
    BUFREQ_OK,
    BUFREQ_E_NOT_OK,
    BUFREQ_E_BUSY,
    BUFREQ_E_OVFL
} BufReq_ReturnType;

typedef enum
{
    TP_DATACONF,
    TP_DATARETRY,
    TP_CONFPENDING
} TpDataStateType;

typedef struct
{
    TpDataStateType     TpDataState;    /**< TP data state */
    PduLengthType       TxTpDataCnt;    /**< Tx TP data count */
} RetryInfoType;

typedef uint8       NetworkHandleType;
typedef uint8       IcomConfigIdType;
typedef uint8       NotifResultType;
typedef enum
{
    ICOM_SWITCH_E_OK,
    ICOM_SWITCH_E_FAILED
} IcomSwitch_ErrorType;

#endif /* COMSTACK_TYPES_H */
/** @} */

