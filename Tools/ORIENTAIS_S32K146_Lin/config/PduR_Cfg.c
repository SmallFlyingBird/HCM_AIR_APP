
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
**  Created on  : 2024/12/16 14:21:11                                         
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
        PDUR_DESTPDU_Dcm_HCML_MasterReq,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_HCML_MasterReq,/*PduRSrcPduRef*/
		DCM_Dcm_HCML_MasterReq,/*PduRDestModulePduIndex*/
		PDUR_DCM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_Dcm_Hcml_MasterReq_Fun,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_Hcml_MasterReq_Fun,/*PduRSrcPduRef*/
		DCM_Dcm_Hcml_MasterReq_Fun,/*PduRDestModulePduIndex*/
		PDUR_DCM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_HCML_SlaveResp,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_Dcm_HCML_SlaveResp,/*PduRSrcPduRef*/
		LINTP_TXPDU_HCML_SlaveResp,/*PduRDestModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_HcmlZcud_Lin2Fr01,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_Com_HcmlZcud_Lin2Fr01,/*PduRSrcPduRef*/
		LINIF_TXPDU_HcmlZcud_Lin2Fr01,/*PduRDestModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_Com_ZcudZcud_Lin2Fr01,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_ZcudZcud_Lin2Fr01,/*PduRSrcPduRef*/
		COM_RXPDU_Com_ZcudZcud_Lin2Fr01,/*PduRDestModulePduIndex*/
		PDUR_COM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
    { 
        PDUR_DESTPDU_Com_ZcudZcud_Lin2Fr02,/*PduRDestPduHandleId*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,/*PduRGatewayDirectTxStateIndex*/
        0xffff,/*PduRTpThreshold*/
		0xffff,/*GateWayTpRunTimeIndex*/
		TRUE,/*PduRTransmissionConfirmation*/
		PDUR_SRCPDU_ZcudZcud_Lin2Fr02,/*PduRSrcPduRef*/
		COM_RXPDU_Com_ZcudZcud_Lin2Fr02,/*PduRDestModulePduIndex*/
		PDUR_COM,/*BswModuleIndex*/
		0xffff,/*PduRDestTxBufferRef*/
		NULL_PTR/*PduRDefaultValueRef*/
    },
};

const PduRSrcPduType PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
		PDUR_SRCPDU_HCML_MasterReq,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		LINTP_RXPDU_HCML_MasterReq,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_Hcml_MasterReq_Fun,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		LINTP_RXPDU_Hcml_MasterReq_Fun,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_Dcm_HCML_SlaveResp,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		DCM_Dcm_HCML_SlaveResp,/*PduRSrcModulePduIndex*/
		PDUR_DCM,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_Com_HcmlZcud_Lin2Fr01,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		COM_TXPDU_Com_HcmlZcud_Lin2Fr01,/*PduRSrcModulePduIndex*/
		PDUR_COM,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_ZcudZcud_Lin2Fr01,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		0xffff,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
    {
		PDUR_SRCPDU_ZcudZcud_Lin2Fr02,/*PduRSourcePduHandleId*/
		TRUE,/*PduRSrcPduUpTxConf*/
		0xffff,/*UpTxconfirmStateIndex*/
		0xffff,/*PduRSrcModulePduIndex*/
		PDUR_LINIF,/*BswModuleIndex*/
		
		0xffff/*TxTpMulticastIndex*/
	},
};


const uint16 PduR_PduRRoutingPath_DCM_PHY[1] = 
{
    PDUR_DESTPDU_Dcm_HCML_MasterReq,
};
const uint16 PduR_PduRRoutingPath_DCM_FUN[1] = 
{
    PDUR_DESTPDU_Dcm_Hcml_MasterReq_Fun,
};
const uint16 PduR_PduRRoutingPath_DCM_RESP[1] = 
{
    PDUR_DESTPDU_HCML_SlaveResp,
};
const uint16 PduR_PduRRoutingPath_HcmlZcud_Lin2Fr01[1] = 
{
    PDUR_DESTPDU_HcmlZcud_Lin2Fr01,
};
const uint16 PduR_PduRRoutingPath_ZcudZcud_Lin2Fr01[1] = 
{
    PDUR_DESTPDU_Com_ZcudZcud_Lin2Fr01,
};
const uint16 PduR_PduRRoutingPath_ZcudZcud_Lin2Fr02[1] = 
{
    PDUR_DESTPDU_Com_ZcudZcud_Lin2Fr02,
};

const PduRRoutingPathType PduR_RoutingPathConfigData0[PDUR_SRC_PDU_SUM] =
{
    {
        PDUR_SRCPDU_HCML_MasterReq,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_DCM_PHY,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_Hcml_MasterReq_Fun,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_DCM_FUN,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_Dcm_HCML_SlaveResp,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_DCM_RESP,/*PduRDestPduIdRef*/
		TRUE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_Com_HcmlZcud_Lin2Fr01,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_HcmlZcud_Lin2Fr01,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_ZcudZcud_Lin2Fr01,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_ZcudZcud_Lin2Fr01,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
		FALSE,/*TpPduIsSF*/
		FALSE,/*GatewayOnTheFly*/
		0xffff/*PduRTpMaxThreshold*/
	},
    {
        PDUR_SRCPDU_ZcudZcud_Lin2Fr02,/*PduRSrcPduId*/
		1,/*PduDestSum*/
		PduR_PduRRoutingPath_ZcudZcud_Lin2Fr02,/*PduRDestPduIdRef*/
		FALSE,/*TpRoute*/
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

