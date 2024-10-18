/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : PduR_PBcfg.h                                                **
**                                                                            **
**  Created on  : 2024/03/26 15:24:41                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_PBCFG_H
#define  PDUR_PBCFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_PBCFG_H_AR_MAJOR_VERSION  4u
#define PDUR_PBCFG_H_AR_MINOR_VERSION  2u
#define PDUR_PBCFG_H_AR_PATCH_VERSION  2u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define PDUR_SRC_PDU_SUM           72u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU02          0u
#define PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU04          1u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu09          2u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu10          3u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19          4u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu17          5u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05          6u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu21          7u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20          8u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu42          9u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu30          10u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu34          11u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu15          12u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02          13u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu14          14u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18          15u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU07          16u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU08          17u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06          18u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu32          19u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu25          20u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13          21u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu16          22u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu28          23u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu27          24u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01          25u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu26          26u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu36          27u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU04          28u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu51          29u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu11          30u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu12          31u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu45          32u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu50          33u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu01          34u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu22          35u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu59          36u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu60          37u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu65          38u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu67          39u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu68          40u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu69          41u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu70          42u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu71          43u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu72          44u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu73          45u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu74          46u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu75          47u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu76          48u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu77          49u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu78          50u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu79          51u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu81          52u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu80          53u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu82          54u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu83          55u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu84          56u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu85          57u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu86          58u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu87          59u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu88          60u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu89          61u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu90          62u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu115          63u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu116          64u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu63          65u
#define PDUR_SRCPDU_CanTp_Rx_Phy          66u
#define PDUR_SRCPDU_CanTp_Rx_Fun          67u
#define PDUR_SRCPDU_HcmlToVgmDiagDcmIpdu          68u
#define PDUR_SRCPDU_CanNmEiraRxPdu          69u
#define PDUR_SRCPDU_CanNmEraRxPdu_BodyExposedCAN_HCML          70u
#define PDUR_SRCPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML          71u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define PDUR_DEST_PDU_SUM              72u

#define PDUR_DEST_GATEWAY_TP_PDU_SUM   0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_DESTPDU_HcmlBodyExpoSignalIPDU02          0u
#define PDUR_DESTPDU_HcmlBodyExpoSignalIPDU04          1u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu09          2u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu10          3u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu19          4u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu17          5u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU05          6u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu21          7u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu20          8u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu42          9u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu30          10u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu34          11u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu15          12u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu02          13u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu14          14u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu18          15u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU07          16u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU08          17u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU06          18u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu32          19u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu25          20u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu13          21u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu16          22u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu28          23u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu27          24u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu01          25u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu26          26u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu36          27u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU04          28u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu51          29u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu11          30u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu12          31u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu45          32u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu50          33u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu01          34u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu22          35u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu59          36u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu60          37u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu65          38u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu67          39u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu68          40u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu69          41u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu70          42u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu71          43u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu72          44u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu73          45u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu74          46u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu75          47u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu76          48u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu77          49u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu78          50u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu79          51u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu81          52u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu80          53u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu82          54u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu83          55u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu84          56u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu85          57u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu86          58u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu87          59u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu88          60u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu89          61u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu90          62u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu115          63u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu116          64u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu63          65u
#define PDUR_DESTPDU_VgmToHcmlDiagDcmIpdu          66u
#define PDUR_DESTPDU_VgmToAllFuncDiagDcmIpdu          67u
#define PDUR_DESTPDU_CanTp_Tx          68u
#define PDUR_DESTPDU_ComCanNmEiraRxPdu          69u
#define PDUR_DESTPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML          70u
#define PDUR_DESTPDU_CanNmUserDataTxPdu_BodyExposedCAN_HCML          71u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define PDUR_ROUTING_PATH_GROUP_SUM        0u

#define PDUR_SRC_UP_MULTICAST_TX_IF_SUM              0u
#define PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM           0u

#define PDUR_DEFAULT_VALUE_LENGTH           0u
#define PDUR_DEFAULT_VALUE_PDU                  0u

#endif  /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

