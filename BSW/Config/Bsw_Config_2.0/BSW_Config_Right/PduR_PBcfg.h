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
**  Created on  : 2024/05/10 10:38:41                                         **
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
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu01          0u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu02          1u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU04          2u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU05          3u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU06          4u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU07          5u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPDU08          6u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu09          7u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu10          8u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu11          9u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu12          10u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu13          11u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu14          12u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu15          13u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu16          14u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu17          15u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu18          16u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu19          17u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu20          18u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu21          19u
#define PDUR_SRCPDU_CemBodyExpoCommonSignalIPdu22          20u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu01          21u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu25          22u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu42          23u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu45          24u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu50          25u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu51          26u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu59          27u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu67          28u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu115          29u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu116          30u
#define PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU02          31u
#define PDUR_SRCPDU_COM_HcmlBodyExpoSignalIPDU04          32u
#define PDUR_SRCPDU_CanTp_Rx_Phy          33u
#define PDUR_SRCPDU_CanTp_Rx_Fun          34u
#define PDUR_SRCPDU_HcmlToVgmDiagDcmIpdu          35u
#define PDUR_SRCPDU_CanNmEiraRxPdu          36u
#define PDUR_SRCPDU_CanNmEraRxPdu_BodyExposedCAN_HCML          37u
#define PDUR_SRCPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML          38u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu07          39u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu100          40u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu101          41u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu102          42u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu103          43u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu104          44u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu105          45u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu106          46u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu107          47u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu108          48u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu109          49u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu110          50u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu111          51u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu112          52u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu113          53u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu114          54u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu29          55u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu31          56u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu33          57u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu35          58u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu37          59u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu38          60u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu61          61u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu66          62u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu91          63u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu92          64u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu93          65u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu94          66u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu95          67u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu96          68u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu97          69u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu98          70u
#define PDUR_SRCPDU_CemBodyExpoSignalIPdu99          71u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define PDUR_DEST_PDU_SUM              72u

#define PDUR_DEST_GATEWAY_TP_PDU_SUM   0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu01          0u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu02          1u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU04          2u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU05          3u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU06          4u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU07          5u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPDU08          6u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu09          7u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu10          8u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu11          9u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu12          10u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu13          11u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu14          12u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu15          13u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu16          14u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu17          15u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu18          16u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu19          17u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu20          18u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu21          19u
#define PDUR_DESTPDU_COM_CemBodyExpoCommonSignalIPdu22          20u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu01          21u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu25          22u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu42          23u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu45          24u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu50          25u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu51          26u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu59          27u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu67          28u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu115          29u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu116          30u
#define PDUR_DESTPDU_HcmlBodyExpoSignalIPDU02          31u
#define PDUR_DESTPDU_HcmlBodyExpoSignalIPDU04          32u
#define PDUR_DESTPDU_VgmToHcmlDiagDcmIpdu          33u
#define PDUR_DESTPDU_VgmToAllFuncDiagDcmIpdu          34u
#define PDUR_DESTPDU_CanTp_Tx          35u
#define PDUR_DESTPDU_ComCanNmEiraRxPdu          36u
#define PDUR_DESTPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML          37u
#define PDUR_DESTPDU_CanNmUserDataTxPdu_BodyExposedCAN_HCML          38u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu07          39u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu100          40u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu101          41u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu102          42u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu103          43u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu104          44u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu105          45u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu106          46u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu107          47u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu108          48u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu109          49u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu110          50u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu111          51u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu112          52u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu113          53u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu114          54u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu29          55u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu31          56u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu33          57u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu35          58u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu37          59u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu38          60u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu61          61u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu66          62u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu91          63u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu92          64u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu93          65u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu94          66u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu95          67u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu96          68u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu97          69u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu98          70u
#define PDUR_DESTPDU_COM_CemBodyExpoSignalIPdu99          71u
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

