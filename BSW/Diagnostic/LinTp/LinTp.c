/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinIf.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for LinIf                                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Version Information Definitions                       **
*******************************************************************************/

/*******************************************************************************
**                               Includes                                     **
*******************************************************************************/
#include "LinIf_Cfg.h"
#include "LinTp.h"
#include "LinTp_Slave.h"
#include "LinTp_Internal.h"
#include "LinIf_Internal.h"
#include "LinIf_Types.h"
#include "PduR_Callout.h"
/*******************************************************************************
**                             Version Check                                  **
*******************************************************************************/

/*******************************************************************************
**                            Macros Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Runtime Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define LINTP_START_SEC_CODE
#include "LinIf_MemMap.h"

static FUNC(P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST), LINIF_CODE)
LinTp_GetTxNSdu(PduIdType txSduId);

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define LINTP_START_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"
/* The status of LINTP */
VAR(LinTp_StateType, LINIF_VAR) LinTp_Status = LINTP_UNINIT;

#define LINTP_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"

#define LINTP_START_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"
/* Global configuration pointer of LINTP */
P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST)
LinTp_ConfigPtr = NULL_PTR;

#define LINTP_STOP_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
#define LINTP_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LIN Transport Layer.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the LIN Transport Protocol
 *                                configuration
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Init (
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
)
{
    /*@req <SWS_LinIf_00427> */
    LinTp_ConfigPtr = ConfigPtr;

    LinTp_SlaveInit();

    /*@req <SWS_LinIf_00320> */
    /* Set the status of LINTP */
    LinTp_Status = LINTP_INIT;
}

/******************************************************************************/
/*
 * Brief               Initializes the LIN Transport Layer after select side
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the LIN Transport Protocol
 *                                configuration
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Side_Init (void)
{
    if(0x02 == PduR_GetDirection())
    {
        LinTp_Init(&LinTp_PCConfig_R);
    }
    else
    {
        LinTp_Init(&LinTp_PCConfig_L);
    }
}



/******************************************************************************/
/*
 * Brief               Requests the transfer of segmented data.
 * ServiceId           0x41
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      LinTpTxSduId: This parameter contains the unique
 *                                   identifier of the N-SDU to be transmitted
 *                     LinTpTxInfoPtr: A pointer to a structure with N-SDU
 *                                     related data
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK: The request can be started successfully
 *                     E_NOT_OK: The request can not be started
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_Transmit (
    PduIdType LinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) LinTpTxInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST)
    tx = LinTp_GetTxNSdu(LinTpTxSduId);
    
    ret = LinTp_SlaveTransmit(tx, LinTpTxInfoPtr);

    return ret;
}

/******************************************************************************/
/*
 * Brief               Shutdowns the LIN TP
 * ServiceId           0x43
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Shutdown(void)
{
    LinTp_SlaveShutdown();

    /*@req <SWS_LinIf_00484>*/
    /* Reset the status of LINTP */
    LinTp_Status = LINTP_UNINIT;
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               Gets configured TxNSdu pointer by parameter 'txSduId'
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      txSduId: tx sdu id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Configured TxNSdu address(Not found return NULL_PTR)
 */
/******************************************************************************/
static FUNC(P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST), LINIF_CODE)
LinTp_GetTxNSdu(PduIdType txSduId)
{
    P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST) retTxNSdu = NULL_PTR;
    P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST) tx;
    uint16 idx = LINTP_GET_TXNSDU_NUM;;

    if(LINTP_INIT == LinTp_Status)
    {
        tx = &LINTP_GET_TXNSDU(0u);

        while (idx > 0u)
        {
            if (tx->LinTpTxNSduId == txSduId)
            {
                retTxNSdu = tx;
            }
            tx++;
            idx--;
        }
    }

    return retTxNSdu;
}

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"
