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
**  FILENAME    : LinIf_Internal.c                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>   <DATE>     <AUTHOR>   <REVISION LOG> 
 * V1.0.0      20200721   HuRongbo   Initial version
 * V1.0.1      20201117   HuRongbo   Fix bug when receive broadcast NAD return
 *                                   NULL_PTR
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "LinIf_Cfg.h"
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Types.h"
#include "LinTp_Internal.h"
#include "LinIf_Internal.h"
#include "LinIf_Slave.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define LINTP_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief: Gets the configuration pointer by receive 'NAD'
 * Param-Name[in]: ch: LinIf channel
 *                 Nad: received 'NAD'
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: const LinTp_RxNSduType*
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST), LINIF_CODE)
LinTp_GetRxNSduByNad(NetworkHandleType ch, uint8 Nad)
{
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) rxNSdu =
                                                        &LINTP_GET_RXNSDU(0u);
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_CONST) retRxNSdu = NULL_PTR;
    uint16 idx = LINTP_GET_RXNSDU_NUM;
    boolean findFlag = FALSE;

    while (idx--)
    {
        if(rxNSdu->LinTpRxNSduChannelRef == LINIF_GET_COMM_NETWORK(ch))
        {
            if(rxNSdu->LinTpRxNSduNad == LINTP_BROADCAST_REQ_NAD)
            {
                findFlag = TRUE;
            }
            else
            {
                if(rxNSdu->LinTpRxNSduNad == Nad)
                {
                    findFlag = TRUE;
                }
            }

            if(TRUE == findFlag)
            {
                retRxNSdu = rxNSdu;
                break;
            }
        }

        rxNSdu++;
    }
    return retRxNSdu;
}

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


#endif /* #if (LINIF_TP_SUPPORTED == STD_ON) */
