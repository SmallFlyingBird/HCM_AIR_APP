
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : PduR_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2024/12/12 15:24:12                                         
**  Author      : yutao                                                       **
**  Vendor      :                                                             **
**  DESCRIPTION : parameter declaration of PDUR                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CFG_C_AR_MAJOR_VERSION  4U
#define PDUR_CFG_C_AR_MINOR_VERSION  2U
#define PDUR_CFG_C_AR_PATCH_VERSION  2U
#define PDUR_CFG_C_SW_MAJOR_VERSION  1U
#define PDUR_CFG_C_SW_MINOR_VERSION  0U
#define PDUR_CFG_C_SW_PATCH_VERSION  0U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PDUR_CFG_C_AR_MAJOR_VERSION != PDUR_CFG_H_AR_MAJOR_VERSION)
  #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_CFG_C_AR_MINOR_VERSION != PDUR_CFG_H_AR_MINOR_VERSION)
  #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_CFG_C_AR_PATCH_VERSION != PDUR_CFG_H_AR_PATCH_VERSION)
  #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_CFG_C_SW_MAJOR_VERSION != PDUR_CFG_H_SW_MAJOR_VERSION)
  #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_CFG_C_SW_MINOR_VERSION != PDUR_CFG_H_SW_MINOR_VERSION)
  #error "PduR.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
const PduRBswModuleType PduR_BswModuleConfigData[PDUR_BSW_MODULE_SUM] =
{
    {
        PDUR_COM,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        TRUE,/*PduRTransportProtocol*/
        FALSE,/*PduRLowerModule*/
        TRUE,/*PduRUpperModule*/
        TRUE,/*PduRRetransmission*/
        TRUE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE/*PduRUseTag*/
    },
    {
        PDUR_LINIF,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        FALSE,/*PduRTransportProtocol*/
        TRUE,/*PduRLowerModule*/
        FALSE,/*PduRUpperModule*/
        FALSE,/*PduRRetransmission*/
        TRUE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE/*PduRUseTag*/
    },
    {
        PDUR_DCM,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        FALSE,/*PduRTransportProtocol*/
        TRUE,/*PduRLowerModule*/
        FALSE,/*PduRUpperModule*/
        FALSE,/*PduRRetransmission*/
        FALSE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE/*PduRUseTag*/
    },
};



CONSTP2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) PduR_Default_value = NULL_PTR;

const PduRDestPduType PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] =
{
    { 
        PDUR_DESTPDU_Com_BCM_RLM_01,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_BCM_RLM_01,/*PduRSrcPduRef*/
		COM_RXPDU_Com_BCM_RLM_01,/*PduRDestModulePduIndex*/
		PDUR_COM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_Com_BCM_RLM_02,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_BCM_RLM_02,/*PduRSrcPduRef*/
		COM_RXPDU_Com_BCM_RLM_02,/*PduRDestModulePduIndex*/
		PDUR_COM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_RLM_RS_BCM_01,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_Com_RLM_RS_BCM_01,/*PduRSrcPduRef*/
		LINIF_TXPDU_RLM_RS_BCM_01,/*PduRDestModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_Dcm_RLM_RS_MasterReq,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_RLM_RS_MasterReq,/*PduRSrcPduRef*/
		DCM_Dcm_RLM_RS_MasterReq,/*PduRDestModulePduIndex*/
		PDUR_DCM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_Dcm_RLM_RS_MasterReq_Fun,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_RLM_RS_MasterReq_Fun,/*PduRSrcPduRef*/
		DCM_Dcm_RLM_RS_MasterReq_Fun,/*PduRDestModulePduIndex*/
		PDUR_DCM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_RLM_RS_SlaveResp,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_Dcm_RLM_RS_SlaveResp,/*PduRSrcPduRef*/
		LINTP_TXPDU_RLM_RS_SlaveResp,/*PduRDestModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
};

const PduRSrcPduType PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
		PDUR_SRCPDU_BCM_RLM_01,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		0xffff,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_BCM_RLM_02,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		0xffff,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_Com_RLM_RS_BCM_01,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		COM_TXPDU_Com_RLM_RS_BCM_01,/*PduRSrcModulePduIndex*/
		PDUR_COM,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_RLM_RS_MasterReq,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		LINTP_RXPDU_RLM_RS_MasterReq,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_RLM_RS_MasterReq_Fun,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		LINTP_RXPDU_RLM_RS_MasterReq_Fun,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_Dcm_RLM_RS_SlaveResp,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		DCM_Dcm_RLM_RS_SlaveResp,/*PduRSrcModulePduIndex*/
		PDUR_DCM,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
};


const uint16 PduR_PduRRoutingPath_BCM_RLM_01[1] = 
{
    PDUR_DESTPDU_Com_BCM_RLM_01,
};
const uint16 PduR_PduRRoutingPath_BCM_RLM_02[1] = 
{
    PDUR_DESTPDU_Com_BCM_RLM_02,
};
const uint16 PduR_PduRRoutingPath_RLM_RS_BCM_01[1] = 
{
    PDUR_DESTPDU_RLM_RS_BCM_01,
};
const uint16 PduR_PduRRoutingPath_DCM_PHY[1] = 
{
    PDUR_DESTPDU_Dcm_RLM_RS_MasterReq,
};
const uint16 PduR_PduRRoutingPath_DCM_FUN[1] = 
{
    PDUR_DESTPDU_Dcm_RLM_RS_MasterReq_Fun,
};
const uint16 PduR_PduRRoutingPath_DCM_RESP[1] = 
{
    PDUR_DESTPDU_RLM_RS_SlaveResp,
};

const PduRRoutingPathType PduR_RoutingPathConfigData0[PDUR_SRC_PDU_SUM] =
{
    {
        PDUR_SRCPDU_BCM_RLM_01,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_BCM_RLM_01,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_BCM_RLM_02,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_BCM_RLM_02,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_Com_RLM_RS_BCM_01,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_RLM_RS_BCM_01,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_RLM_RS_MasterReq,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_DCM_PHY,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_RLM_RS_MasterReq_Fun,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_DCM_FUN,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_Dcm_RLM_RS_SlaveResp,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_DCM_RESP,/*PduRDestPduIdRef*/
		TRUE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
};




const PduRRoutingTableType PduR_RoutingTableConfigData[1] =
{
   {
      PduR_RoutingPathConfigData0
   }
};





/****************************************Tx Buffer Configuration***************************************************************/






CONSTP2CONST(PduR_TxBufferTableType, AUTOMATIC, PDUR_APPL_DATA) PduR_TxBuffer = NULL_PTR;


/**********************************Tp Buffer Configuration*****************************************/




P2VAR(PduR_TpBufferTableType, AUTOMATIC, PDUR_APPL_DATA) PduR_TpBuffer = NULL_PTR;


const PduR_PBConfigType PduR_PBConfigData =
{
    0,/*PduRConfigId*/
    NULL_PTR,
    PduR_RoutingTableConfigData,
    PduR_SrcPduConfigData,
    PduR_DestPduConfigData,
};

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

