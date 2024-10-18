
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
**  FILENAME    : CanIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/09/19 08:15:01                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : cfg parameter declaration of CanIf                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define CANIF_CFG_H_AR_MAJOR_VERSION    4u
#define CANIF_CFG_H_AR_MINOR_VERSION    2u
#define CANIF_CFG_H_AR_PATCH_VERSION    2u
#define CANIF_CFG_H_SW_MAJOR_VERSION    2u
#define CANIF_CFG_H_SW_MINOR_VERSION    0u
#define CANIF_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define CANIF_CAN_AUTOSAR_422                0u
#define CANIF_CAN_AUTOSAR_431                1u
#define CANIF_CAN_AUTOSAR_440                2u

#define CANIF_CAN_AUTOSAR_VERSION            CANIF_CAN_AUTOSAR_422

#define CANIF_CANID_UINT16                  0u
#define CANIF_CANID_UINT32                  1u

#define CANIF_CAN_IDTYPE                    CANIF_CANID_UINT32

#define CANIF_SOFTWARE_FILTER_BINARY                0u
#define CANIF_SOFTWARE_FILTER_INDEX                 1u
#define CANIF_SOFTWARE_FILTER_LINEAR                2u
#define CANIF_SOFTWARE_FILTER_TABLE                 3u

#define CANIF_HRH_RANGE_SUPPORT     STD_OFF

#define CANIF_RXPDU_CANID_RANGE_SUPPORT     STD_OFF

#define CANIF_RX_STANDARD_CAN_SUPPORT     STD_ON

#define CANIF_RX_STANDARD_FD_CAN_SUPPORT     STD_OFF

#define CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT     STD_OFF

#define CANIF_RX_EXTENDED_CAN_SUPPORT     STD_OFF

#define CANIF_RX_EXTENDED_FD_CAN_SUPPORT     STD_OFF

#define CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT     STD_OFF

#define CANIF_TX_EXTENDED_CAN_SUPPORT       STD_OFF

#define CANIF_TX_EXTENDED_FD_CAN_SUPPORT        STD_OFF

#define CANIF_TX_STANDARD_CAN_SUPPORT           STD_ON

#define CANIF_TX_STANDARD_FD_CAN_SUPPORT        STD_OFF

#define CANIF_FIXED_BUFFER            STD_ON

#define CANIF_PRIVATE_DLC_CHECK       STD_ON

#define CANIF_SOFTWARE_FILTER_TYPE    CANIF_SOFTWARE_FILTER_LINEAR

#define CANIF_SUPPORT_TTCAN           STD_OFF

#define CANIF_META_DATA_SUPPORT       STD_OFF

#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT               STD_OFF

#define CANIF_PUBLIC_DEV_ERROR_DETECT                      STD_OFF

#define CANIF_PUBLIC_ICOM_SUPPORT                          STD_OFF

#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                  STD_ON

#define CANIF_PUBLIC_PN_SUPPORT                            STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_DATA_API                  STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API                 STD_OFF

#define CANIF_PUBLIC_TX_BUFFERING                          STD_OFF

#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_ON

#define CANIF_PUBLIC_VERSION_INFO_API                      STD_ON

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM              STD_OFF

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT            STD_OFF/* PRQA S 0791 */ /* MISRA Rule 5.4 */

#define CANIF_SET_BAUDRATE_API                             STD_OFF

#define CANIF_TRIGGER_TRANSMIT_SUPPORT            STD_OFF

#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT           STD_OFF

#define CANIF_WAKE_UP_SUPPORT                     STD_OFF

#define CANIF_CANDRV_WAKE_UP_SUPPORT              STD_OFF

#define CANIF_CANTRCV_WAKE_UP_SUPPORT             STD_OFF

#define CANIF_WAKEUPSOURCE_MAX                    0x3Fu
/*******************************************************************************************/

#define CANIF_RXPDU_NUMBER              68u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu09         0u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu10         1u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu19         2u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu17         3u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPDU05         4u
#define CANIF_RXPDU_CemToAllFuncBodyCanExpDiagReqNpdu         5u
#define CANIF_RXPDU_CemToHcmlBodyCanExpDiagReqNpdu         6u
#define CANIF_RXPDU_EtcToHcmlXcpPdu01         7u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu21         8u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu20         9u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu42         10u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu30         11u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu34         12u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu15         13u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu02         14u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu14         15u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu18         16u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPDU07         17u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPDU08         18u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPDU06         19u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu25         20u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu13         21u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu16         22u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu28         23u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu01         24u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu26         25u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu36         26u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu51         27u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu11         28u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu12         29u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu45         30u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu50         31u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu01         32u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPdu22         33u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu65         34u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu67         35u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu68         36u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu69         37u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu70         38u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu71         39u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu72         40u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu73         41u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu74         42u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu75         43u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu76         44u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu77         45u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu78         46u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu79         47u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu81         48u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu80         49u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu82         50u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu83         51u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu84         52u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu85         53u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu86         54u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu87         55u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu88         56u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu89         57u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu90         58u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu115         59u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu116         60u
#define CANIF_RXPDU_HcmrBodyExposedCanNmPdu1         61u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu63         62u
#define CANIF_RXPDU_CemBodyExpoCommonSignalIPDU04         63u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu59         64u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu27         65u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu32         66u
#define CANIF_RXPDU_CemBodyExpoSignalIPdu60         67u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define CANIF_TXPDU_NUMBER              5u
#define CANIF_DYNAMIC_TXPDU_NUMBER      0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CANIF_TXPDU_HcmlBodyExpoSignalIPDU02         0u
#define CANIF_TXPDU_HcmlBodyExposedCanNmPdu1         1u
#define CANIF_TXPDU_HcmlBodyExpoSignalIPDU04         2u
#define CANIF_TXPDU_HcmlToEtcXcpPdu01         3u
#define CANIF_TXPDU_HcmlToCemBodyCanExpDiagResNpdu         4u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */

#define CANIF_HRH_NUMBER           68u
#define CANIF_HOH0_HRH_0           0u
#define CANIF_HOH0_HRH_1           1u
#define CANIF_HOH0_HRH_2           2u
#define CANIF_HOH0_HRH_3           3u
#define CANIF_HOH0_HRH_4           4u
#define CANIF_HOH0_HRH_5           5u
#define CANIF_HOH0_HRH_6           6u
#define CANIF_HOH0_HRH_7           7u
#define CANIF_HOH0_HRH_8           8u
#define CANIF_HOH0_HRH_9           9u
#define CANIF_HOH0_HRH_10           10u
#define CANIF_HOH0_HRH_11           11u
#define CANIF_HOH0_HRH_12           12u
#define CANIF_HOH0_HRH_13           13u
#define CANIF_HOH0_HRH_14           14u
#define CANIF_HOH0_HRH_15           15u
#define CANIF_HOH0_HRH_16           16u
#define CANIF_HOH0_HRH_17           17u
#define CANIF_HOH0_HRH_18           18u
#define CANIF_HOH0_HRH_19           19u
#define CANIF_HOH0_HRH_20           20u
#define CANIF_HOH0_HRH_21           21u
#define CANIF_HOH0_HRH_22           22u
#define CANIF_HOH0_HRH_23           23u
#define CANIF_HOH0_HRH_24           24u
#define CANIF_HOH0_HRH_25           25u
#define CANIF_HOH0_HRH_26           26u
#define CANIF_HOH0_HRH_27           27u
#define CANIF_HOH0_HRH_28           28u
#define CANIF_HOH0_HRH_29           29u
#define CANIF_HOH0_HRH_30           30u
#define CANIF_HOH0_HRH_31           31u
#define CANIF_HOH0_HRH_32           32u
#define CANIF_HOH0_HRH_33           33u
#define CANIF_HOH0_HRH_34           34u
#define CANIF_HOH0_HRH_35           35u
#define CANIF_HOH0_HRH_36           36u
#define CANIF_HOH0_HRH_37           37u
#define CANIF_HOH0_HRH_38           38u
#define CANIF_HOH0_HRH_39           39u
#define CANIF_HOH0_HRH_40           40u
#define CANIF_HOH0_HRH_41           41u
#define CANIF_HOH0_HRH_42           42u
#define CANIF_HOH0_HRH_43           43u
#define CANIF_HOH0_HRH_44           44u
#define CANIF_HOH0_HRH_45           45u
#define CANIF_HOH0_HRH_46           46u
#define CANIF_HOH0_HRH_47           47u
#define CANIF_HOH0_HRH_48           48u
#define CANIF_HOH0_HRH_49           49u
#define CANIF_HOH0_HRH_50           50u
#define CANIF_HOH0_HRH_51           51u
#define CANIF_HOH0_HRH_52           52u
#define CANIF_HOH0_HRH_53           53u
#define CANIF_HOH0_HRH_54           54u
#define CANIF_HOH0_HRH_55           55u
#define CANIF_HOH0_HRH_56           56u
#define CANIF_HOH0_HRH_57           57u
#define CANIF_HOH0_HRH_58           58u
#define CANIF_HOH0_HRH_59           59u
#define CANIF_HOH0_HRH_60           60u
#define CANIF_HOH0_HRH_61           61u
#define CANIF_HOH0_HRH_62           62u
#define CANIF_HOH0_HRH_63           63u
#define CANIF_HOH0_HRH_64           64u
#define CANIF_HOH0_HRH_65           65u
#define CANIF_HOH0_HRH_66           66u
#define CANIF_HOH0_HRH_67           67u

#define CANIF_HTH_NUMBER           5u
#define CANIF_HOH0_HTH_0           0u
#define CANIF_HOH0_HTH_1           1u
#define CANIF_HOH0_HTH_2           2u
#define CANIF_HOH0_HTH_3           3u
#define CANIF_HOH0_HTH_4           4u

#define CANIF_TXBUFFER_NUMBER          0u
#define CANIF_RXBUFFER_NUMBER          0u

#define CANIF_RXNOTIFYSTATUS_BUFFER    0u
#define CANIF_TXNOTIFYSTATUS_BUFFER    0u

#define CANIF_CANDRIVER_NUMBER      1u
#define CANIF_CAN    0u
#define CANIF_CANCONTROLLER_NUMBER      1u
#define CANIF_CANDRV_0_BodyExposedCAN_HCML    0u

#define CANIF_TRCVDRIVER_NUMBER      0u
#define CANIF_TRCV_NUMBER      0u

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
