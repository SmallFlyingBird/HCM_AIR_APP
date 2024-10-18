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
**  FILENAME    : Com_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/08/27 16:02:46                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of Com                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef  COM_CFG_H
#define  COM_CFG_H

#include "ComStack_Types.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COM_CFG_H_AR_MAJOR_VERSION    4u
#define COM_CFG_H_AR_MINOR_VERSION    2u
#define COM_CFG_H_AR_PATCH_VERSION    2u
#define COM_CFG_H_SW_MAJOR_VERSION    2u
#define COM_CFG_H_SW_MINOR_VERSION    0u
#define COM_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define COM_CANCELLATION_SUPPORT                     STD_OFF
#define COM_DEV_ERROR_DETECT                         STD_ON
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API            STD_OFF
#define COM_VERSION_INFO_API                         STD_OFF
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION       STD_ON
#define COM_METADATA_SUPPORT                         STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS           STD_OFF

#define COM_IPDUGROUP_NUMBER                         10u
#define RxSPG_BodyExposedCAN_PNC38        0u
#define RxSPG_BodyExposedCAN_PNC17        1u
#define RxSPG_BodyExposedCAN_PNC16        2u
#define RxSPG_BodyExposedCAN_PNC39        3u
#define RxSPG_BodyExposedCAN_PNC24        4u
#define RxSPG_BodyExposedCAN_PNC29        5u
#define RxSPG_BodyExposedCAN_PNC18        6u
#define RxSPG_BodyExposedCAN_PNC22        7u
#define TxSPG_BodyExposedCAN        8u
#define RxSPG_BodyExposedCAN        9u

#define COM_RXIPDU_NUMBER        66u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu01        0u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu02        1u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU04        2u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU05        3u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU06        4u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU07        5u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU08        6u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu09        7u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu10        8u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu11        9u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu12        10u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu13        11u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu14        12u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu15        13u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu16        14u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu17        15u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu18        16u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu19        17u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu20        18u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu21        19u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu22        20u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu01        21u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu25        22u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu42        23u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu45        24u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu50        25u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu51        26u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu59        27u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu67        28u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu115        29u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu116        30u
#define COM_RXPDU_ComCanNmEiraRxPdu        31u
#define COM_RXPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML        32u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu07        33u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu100        34u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu101        35u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu102        36u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu103        37u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu104        38u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu105        39u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu106        40u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu107        41u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu108        42u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu109        43u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu110        44u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu111        45u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu112        46u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu113        47u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu114        48u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu29        49u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu31        50u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu33        51u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu35        52u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu37        53u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu38        54u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu61        55u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu66        56u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu91        57u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu92        58u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu93        59u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu94        60u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu95        61u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu96        62u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu97        63u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu98        64u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu99        65u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_TXIPDU_NUMBER    3u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define COM_TXPDU_COM_HcmlBodyExpoSignalIPDU04        66u
#define COM_TXPDU_COM_HcmlBodyExpoSignalIPDU02        67u
#define COM_TXPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML        68u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_RXIPDUBUFF_SIZE        524u
#define COM_TXIPDUBUFF_SIZE        17u

#define COM_SIGNAL_BOOLBUFF_SIZE            55u
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE     16u
#define COM_SIGNAL_BOOL_INVALID_SIZE        0u

#define COM_SIGNAL_8BITBUFF_SIZE            310u
#define COM_RXGROUPSIGNAL_8BITBUFF_SIZE     265u
#define COM_SIGNAL_8BIT_INVALID_SIZE        0u

#define COM_SIGNAL_16BITBUFF_SIZE           95u
#define COM_RXGROUPSIGNAL_16BITBUFF_SIZE    93u
#define COM_SIGNAL_16BIT_INVALID_SIZE       0u

#define COM_SIGNAL_32BITBUFF_SIZE           2u
#define COM_RXGROUPSIGNAL_32BITBUFF_SIZE    0u
#define COM_SIGNAL_32BIT_INVALID_SIZE       0u

#define COM_SIGNAL_64BITBUFF_SIZE           0u
#define COM_RXGROUPSIGNAL_64BITBUFF_SIZE    0u
#define COM_SIGNAL_64BIT_INVALID_SIZE       0u

#define COM_TMCTXSIGNAL_NUMBER              0u
#define COM_TMCTXGROUPSIGNAL_NUMBER         0u

#define COM_TXSIGNALGROUP_NUMBER            1u
#define igStsOfLvlgLe               0u

#define COM_RXSIGNALGROUP_NUMBER            64u
#define igVehCfgPrmExt               0u
#define igTrafficSignForADB1               1u
#define igVehObjforADB7               2u
#define igVehObjforADB5               3u
#define igVehCfgPrm               4u
#define igVehModMngtGlbSafe1               5u
#define igVehObjforADB8               6u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi               7u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi               8u
#define igVehObjforADB3               9u
#define igBrkPedlrRat               10u
#define igVehObjforADB2               11u
#define igVehObjforADB6               12u
#define igAccrPedlRat               13u
#define igBrkPedlSnsr               14u
#define igAmbTRaw               15u
#define igVehBattU               16u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi               17u
#define igLvlgSwtSetReq               18u
#define igOutdBri               19u
#define igVehObjforADB1               20u
#define igVehObjforADB4               21u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi               22u
#define igDwnLoadDynLitPrmForLedLoBeamRi               23u
#define igSteerWhlSnsr               24u
#define igDwnLoadDynLitPrmForLedHiBeamRi               25u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi               26u
#define igVehSpdLgt               27u
#define igActvnOfIndcr               28u
#define igIndcrPat               29u
#define igTrafficSignForADB2               30u
#define igVehObjforAHB               31u
#define igBrkPedlVal               32u
#define igWipgInfo               33u
#define igActnOfLedLoBeam               34u
#define igSuspPosnVertAg               35u
#define igSuspPosnVertLvl               36u
#define igDwnLoadDynLitPrmLedRiGrilleLamp               37u
#define igDwnLoadDynLitPrmLedRiSideLogoLi               38u
#define igDwnLoadDynLtgPrmForFrntRiGrp1               39u
#define igDwnLoadDynLtgPrmForFrntRiGrp2               40u
#define igDwnLoadDynLtgPrmForFrntRiGrp3               41u
#define igDwnLoadDynLtgPrmForFrntRiGrp4               42u
#define igDwnLoadDynLtgPrmForFrntRiGrp5               43u
#define igDwnLoadDynLtgPrmForFrntRiGrp6               44u
#define igDwnLoadDynLtgPrmForFrntRiGrp7               45u
#define igDwnLoadDynLtgPrmForFrntRiGrp8               46u
#define igDwnLoadDynLtgPrmForFrntRiGrp9               47u
#define igDwnLoadDynLtgPrmForFrntRiGrp10               48u
#define igDwnLoadDynLtgPrmForFrntRiGrp11               49u
#define igDwnLoadDynLtgPrmForFrntRiGrp12               50u
#define igDwnLoadDynLtgPrmForFrntRiGrp13               51u
#define igDwnLoadDynLtgPrmForFrntRiGrp14               52u
#define igDwnLoadDynLtgPrmForFrntRiGrp15               53u
#define igDwnLoadDynLtgPrmForFrntRiGrp16               54u
#define igDwnLoadDynLtgPrmForFrntRiGrp17               55u
#define igDwnLoadDynLtgPrmForFrntRiGrp18               56u
#define igDwnLoadDynLtgPrmForFrntRiGrp19               57u
#define igDwnLoadDynLtgPrmForFrntRiGrp20               58u
#define igDwnLoadDynLtgPrmForFrntRiGrp21               59u
#define igDwnLoadDynLtgPrmForFrntRiGrp22               60u
#define igDwnLoadDynLtgPrmForFrntRiGrp23               61u
#define igDwnLoadDynLtgPrmForFrntRiGrp24               62u
#define igTiAndDateIndcn               63u

#define COM_TXSIGNAL_NUMBER                  23u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define StsOfLedHiBeamLe_IPDU_COM_HcmlBodyExpoSignalIPDU02               0u
#define StsOfLedLoBeamLe_IPDU_COM_HcmlBodyExpoSignalIPDU02               1u
#define ExtrLiShowStoreStsFrntLe_IPDU_COM_HcmlBodyExpoSignalIPDU02               2u
#define StsOfLedLeLogoLamp_IPDU_COM_HcmlBodyExpoSignalIPDU02               3u
#define StsOfLedFrntTurnIndcrLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               4u
#define StsOfTouristModLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               5u
#define StsOfLedDaytiRunngLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               6u
#define StsOfLedFrntFogLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               7u
#define StsOfAfsLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               8u
#define StsOfAhbcLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               9u
#define StsOfSwvlgLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               10u
#define StsOfFrntSideMkrLampLe2_IPDU_COM_HcmlBodyExpoSignalIPDU04               11u
#define StsOfLedCornrgLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               12u
#define StsOfLedFrntPosnLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               13u
#define HdlampLeInpSts1_IPDU_COM_HcmlBodyExpoSignalIPDU04               14u
#define HdlampLeInpSts2_IPDU_COM_HcmlBodyExpoSignalIPDU04               15u
#define ExtrLiShowActvnFrntLeFb_IPDU_COM_HcmlBodyExpoSignalIPDU04               16u
#define DwnLoadStsFbOfHdlampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               17u
#define ExtrLiShowActvnLeLogoFb_IPDU_COM_HcmlBodyExpoSignalIPDU04               18u
#define DwnLoadStsFbOfLogoLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               19u
#define StsOfWelGbyFrntLe_IPDU_COM_HcmlBodyExpoSignalIPDU04               20u
#define isCanNmUserData_BodyExposedCAN_HCML               21u
#define LvlgMtrAgle_IPDU_COM_HcmlBodyExpoSignalIPDU02               22u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_RXSIGNAL_NUMBER               47u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define LiOprnMod_IPDU_COM_CemBodyExpoCommonSignalIPdu01             0u
#define AutWinWipgCmd_IPDU_COM_CemBodyExpoCommonSignalIPdu01             1u
#define YawRateReqdByDrvr_IPDU_COM_CemBodyExpoCommonSignalIPdu02             2u
#define ExtrLiRlyPwrDwn_IPDU_COM_CemBodyExpoCommonSignalIPDU06             3u
#define BkpOfDstTrvld_IPDU_COM_CemBodyExpoCommonSignalIPDU06             4u
#define Body2CntrForMissCom_IPDU_COM_CemBodyExpoCommonSignalIPDU07             5u
#define ActnOfLedFrntCrossLamp_IPDU_COM_CemBodyExpoCommonSignalIPDU07             6u
#define ActnOfLedGrilleLamp_IPDU_COM_CemBodyExpoCommonSignalIPDU07             7u
#define ActnOfLedRiLogoLamp_IPDU_COM_CemBodyExpoCommonSignalIPDU07             8u
#define CarTiGlb_IPDU_COM_CemBodyExpoCommonSignalIPDU07             9u
#define TooManyCars_IPDU_COM_CemBodyExpoCommonSignalIPDU08             10u
#define WipgAutFrntMod_IPDU_COM_CemBodyExpoCommonSignalIPdu21             11u
#define RainLi_IPDU_COM_CemBodyExpoCommonSignalIPdu21             12u
#define CameraStsforAHBC_IPDU_COM_CemBodyExpoCommonSignalIPdu21             13u
#define ExtrLiShowFileTxReq_IPDU_COM_CemBodyExpoSignalIPdu01             14u
#define ExtrLiShowActvnReq_IPDU_COM_CemBodyExpoSignalIPdu01             15u
#define ActnOfLedPosnLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             16u
#define ActnOfLedFrntCrossLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             17u
#define ActnOfLedGrilleLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             18u
#define ActnOfLedRiLogoLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             19u
#define ActvnOfHomeSafe_IPDU_COM_CemBodyExpoSignalIPdu42             20u
#define LitArea_IPDU_COM_CemBodyExpoSignalIPdu45             21u
#define ActvnOfApproach_IPDU_COM_CemBodyExpoSignalIPdu45             22u
#define ActvnOfCarLoctr_IPDU_COM_CemBodyExpoSignalIPdu45             23u
#define ActvnOfWaitMode_IPDU_COM_CemBodyExpoSignalIPdu45             24u
#define IndcrNoSeq_IPDU_COM_CemBodyExpoSignalIPdu45             25u
#define ActnOfLedCornrgLampRi_IPDU_COM_CemBodyExpoSignalIPdu50             26u
#define ActnOfLedDaytiRunngLamp_IPDU_COM_CemBodyExpoSignalIPdu50             27u
#define ActnOfLedFrntFogLamp_IPDU_COM_CemBodyExpoSignalIPdu50             28u
#define ActnOfLedHiBeam_IPDU_COM_CemBodyExpoSignalIPdu50             29u
#define ActnOfLedPosnLamp_IPDU_COM_CemBodyExpoSignalIPdu50             30u
#define ActvnOfAfs_IPDU_COM_CemBodyExpoSignalIPdu50             31u
#define ActvnOfAhbc_IPDU_COM_CemBodyExpoSignalIPdu50             32u
#define ActvnOfAhl_IPDU_COM_CemBodyExpoSignalIPdu50             33u
#define ActvnOfDbl_IPDU_COM_CemBodyExpoSignalIPdu50             34u
#define ActvnOfGoodByeLi_IPDU_COM_CemBodyExpoSignalIPdu50             35u
#define ActvnOfTouristMod_IPDU_COM_CemBodyExpoSignalIPdu50             36u
#define ActvnOfWelcomeLi_IPDU_COM_CemBodyExpoSignalIPdu50             37u
#define IndcrSts_IPDU_COM_CemBodyExpoSignalIPdu51             38u
#define WelcomeGoodbyeModeReq_IPDU_COM_CemBodyExpoSignalIPdu59             39u
#define WelLiFileTxReq_IPDU_COM_CemBodyExpoSignalIPdu67             40u
#define ActvnOfLiForComity_IPDU_COM_CemBodyExpoSignalIPdu115             41u
#define ActvnOfLiForSpkr_IPDU_COM_CemBodyExpoSignalIPdu115             42u
#define ActvnOfLiForWait_IPDU_COM_CemBodyExpoSignalIPdu115             43u
#define ActvnOfADB_IPDU_COM_CemBodyExpoSignalIPdu115             44u
#define isCanNmEira             45u
#define isCanNmEra_BodyExposedCAN_HCML             46u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_GWSOURCESIGNAL_UPDATE_NUMBER           0u
#define COM_ONEEVERYNFILTERSIGNAL_NUMBER           0u
#define COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER    0u

#define COM_GWSIGNAL_BOOLBUFF_SIZE          0u
#define COM_GWSIGNAL_8BITBUFF_SIZE          0u
#define COM_GWSIGNAL_16BITBUFF_SIZE         0u
#define COM_GWSIGNAL_32BITBUFF_SIZE         0u
#define COM_GWSIGNAL_64BITBUFF_SIZE         0u

#define COM_TXGROUPSIGNAL_NUMBER        3u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define igStsOfLvlgLe_StsOfLvlgLeCntr_IPDU_COM_HcmlBodyExpoSignalIPDU04             23u
#define igStsOfLvlgLe_StsOfLvlgLeStsOfLvlgLe_IPDU_COM_HcmlBodyExpoSignalIPDU04             24u
#define igStsOfLvlgLe_StsOfLvlgLeChks_IPDU_COM_HcmlBodyExpoSignalIPDU04             25u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_RXGROUPSIGNAL_NUMBER        374u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn5_IPDU_COM_CemBodyExpoCommonSignalIPdu09             47u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn6_IPDU_COM_CemBodyExpoCommonSignalIPdu09             48u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn2_IPDU_COM_CemBodyExpoCommonSignalIPdu09             49u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn3_IPDU_COM_CemBodyExpoCommonSignalIPdu09             50u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn8_IPDU_COM_CemBodyExpoCommonSignalIPdu09             51u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn4_IPDU_COM_CemBodyExpoCommonSignalIPdu09             52u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn7_IPDU_COM_CemBodyExpoCommonSignalIPdu09             53u
#define igVehCfgPrmExt_VehCfgPrmExtBlkIDBytePosn1_IPDU_COM_CemBodyExpoCommonSignalIPdu09             54u
#define igTrafficSignForADB1_TrafficSignForADB1AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu10             55u
#define igTrafficSignForADB1_TrafficSignForADB1AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu10             56u
#define igTrafficSignForADB1_TrafficSignForADB1AdbDetdQly_IPDU_COM_CemBodyExpoCommonSignalIPdu10             57u
#define igTrafficSignForADB1_TrafficSignForADB1AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu10             58u
#define igTrafficSignForADB1_TrafficSignForADB1AdbVertAgTop_IPDU_COM_CemBodyExpoCommonSignalIPdu10             59u
#define igTrafficSignForADB1_TrafficSignForADB1AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu10             60u
#define igTrafficSignForADB1_TrafficSignForADB1AdbVertAgBot_IPDU_COM_CemBodyExpoCommonSignalIPdu10             61u
#define igVehObjforADB7_VehObjforADB7AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu19             62u
#define igVehObjforADB7_VehObjforADB7AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu19             63u
#define igVehObjforADB7_VehObjforADB7AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu19             64u
#define igVehObjforADB7_VehObjforADB7AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu19             65u
#define igVehObjforADB7_VehObjforADB7AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu19             66u
#define igVehObjforADB7_VehObjforADB7AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu19             67u
#define igVehObjforADB7_VehObjforADB7AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu19             68u
#define igVehObjforADB7_VehObjforADB7AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu19             69u
#define igVehObjforADB7_VehObjforADB7AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu19             70u
#define igVehObjforADB5_VehObjforADB5AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu17             71u
#define igVehObjforADB5_VehObjforADB5AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu17             72u
#define igVehObjforADB5_VehObjforADB5AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu17             73u
#define igVehObjforADB5_VehObjforADB5AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu17             74u
#define igVehObjforADB5_VehObjforADB5AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu17             75u
#define igVehObjforADB5_VehObjforADB5AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu17             76u
#define igVehObjforADB5_VehObjforADB5AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu17             77u
#define igVehObjforADB5_VehObjforADB5AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu17             78u
#define igVehObjforADB5_VehObjforADB5AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu17             79u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn6_IPDU_COM_CemBodyExpoCommonSignalIPDU05             80u
#define igVehCfgPrm_VehCfgPrmBlkIDBytePosn1_IPDU_COM_CemBodyExpoCommonSignalIPDU05             81u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn4_IPDU_COM_CemBodyExpoCommonSignalIPDU05             82u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn3_IPDU_COM_CemBodyExpoCommonSignalIPDU05             83u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn2_IPDU_COM_CemBodyExpoCommonSignalIPDU05             84u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn8_IPDU_COM_CemBodyExpoCommonSignalIPDU05             85u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn7_IPDU_COM_CemBodyExpoCommonSignalIPDU05             86u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn5_IPDU_COM_CemBodyExpoCommonSignalIPDU05             87u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1Chks_IPDU_COM_CemBodyExpoCommonSignalIPdu21             88u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1CarModSts1_IPDU_COM_CemBodyExpoCommonSignalIPdu21             89u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1Cntr_IPDU_COM_CemBodyExpoCommonSignalIPdu21             90u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1EgyLvlElecSubtyp_IPDU_COM_CemBodyExpoCommonSignalIPdu21             91u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1PwrLvlElecSubtyp_IPDU_COM_CemBodyExpoCommonSignalIPdu21             92u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_IPDU_COM_CemBodyExpoCommonSignalIPdu21             93u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1UsgModSts_IPDU_COM_CemBodyExpoCommonSignalIPdu21             94u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1PwrLvlElecMai_IPDU_COM_CemBodyExpoCommonSignalIPdu21             95u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1EgyLvlElecMai_IPDU_COM_CemBodyExpoCommonSignalIPdu21             96u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1FltEgyCnsWdSts_IPDU_COM_CemBodyExpoCommonSignalIPdu21             97u
#define igVehObjforADB8_VehObjforADB8AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu20             98u
#define igVehObjforADB8_VehObjforADB8AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu20             99u
#define igVehObjforADB8_VehObjforADB8AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu20             100u
#define igVehObjforADB8_VehObjforADB8AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu20             101u
#define igVehObjforADB8_VehObjforADB8AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu20             102u
#define igVehObjforADB8_VehObjforADB8AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu20             103u
#define igVehObjforADB8_VehObjforADB8AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu20             104u
#define igVehObjforADB8_VehObjforADB8AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu20             105u
#define igVehObjforADB8_VehObjforADB8AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu20             106u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi_DwnLoadDynLtgPrmForLedCornrgLampRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu31             107u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi_DwnLoadDynLtgPrmForLedCornrgLampRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu31             108u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi_DwnLoadDynLtgPrmForLedCornrgLampRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu31             109u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi_DwnLoadDynLtgPrmForLedCornrgLampRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu31             110u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi_DwnLoadDynLtgPrmForLedCornrgLampRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu31             111u
#define igDwnLoadDynLtgPrmForLedCornrgLampRi_DwnLoadDynLtgPrmForLedCornrgLampRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu31             112u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi_DwnLoadDynLtgPrmForLedFrntPosnLampRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu35             113u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi_DwnLoadDynLtgPrmForLedFrntPosnLampRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu35             114u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi_DwnLoadDynLtgPrmForLedFrntPosnLampRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu35             115u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi_DwnLoadDynLtgPrmForLedFrntPosnLampRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu35             116u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi_DwnLoadDynLtgPrmForLedFrntPosnLampRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu35             117u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampRi_DwnLoadDynLtgPrmForLedFrntPosnLampRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu35             118u
#define igVehObjforADB3_VehObjforADB3AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu15             119u
#define igVehObjforADB3_VehObjforADB3AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu15             120u
#define igVehObjforADB3_VehObjforADB3AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu15             121u
#define igVehObjforADB3_VehObjforADB3AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu15             122u
#define igVehObjforADB3_VehObjforADB3AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu15             123u
#define igVehObjforADB3_VehObjforADB3AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu15             124u
#define igVehObjforADB3_VehObjforADB3AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu15             125u
#define igVehObjforADB3_VehObjforADB3AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu15             126u
#define igVehObjforADB3_VehObjforADB3AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu15             127u
#define igBrkPedlrRat_BrkPedlrRatQf_IPDU_COM_CemBodyExpoCommonSignalIPdu02             128u
#define igBrkPedlrRat_BrkPedlrRatPerc_IPDU_COM_CemBodyExpoCommonSignalIPdu02             129u
#define igVehObjforADB2_VehObjforADB2AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu14             130u
#define igVehObjforADB2_VehObjforADB2AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu14             131u
#define igVehObjforADB2_VehObjforADB2AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu14             132u
#define igVehObjforADB2_VehObjforADB2AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu14             133u
#define igVehObjforADB2_VehObjforADB2AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu14             134u
#define igVehObjforADB2_VehObjforADB2AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu14             135u
#define igVehObjforADB2_VehObjforADB2AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu14             136u
#define igVehObjforADB2_VehObjforADB2AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu14             137u
#define igVehObjforADB2_VehObjforADB2AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu14             138u
#define igVehObjforADB6_VehObjforADB6AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu18             139u
#define igVehObjforADB6_VehObjforADB6AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu18             140u
#define igVehObjforADB6_VehObjforADB6AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu18             141u
#define igVehObjforADB6_VehObjforADB6AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu18             142u
#define igVehObjforADB6_VehObjforADB6AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu18             143u
#define igVehObjforADB6_VehObjforADB6AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu18             144u
#define igVehObjforADB6_VehObjforADB6AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu18             145u
#define igVehObjforADB6_VehObjforADB6AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu18             146u
#define igVehObjforADB6_VehObjforADB6AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu18             147u
#define igAccrPedlRat_AccrPedlRatCntr_IPDU_COM_CemBodyExpoCommonSignalIPDU08             148u
#define igAccrPedlRat_AccrPedlRatChks_IPDU_COM_CemBodyExpoCommonSignalIPDU08             149u
#define igAccrPedlRat_AccrPedlRatAccrPedlRat_IPDU_COM_CemBodyExpoCommonSignalIPDU08             150u
#define igBrkPedlSnsr_BrkPedlSnsrSt_IPDU_COM_CemBodyExpoCommonSignalIPDU08             151u
#define igBrkPedlSnsr_BrkPedlSnsrChks_IPDU_COM_CemBodyExpoCommonSignalIPDU08             152u
#define igBrkPedlSnsr_BrkPedlSnsrCntr_IPDU_COM_CemBodyExpoCommonSignalIPDU08             153u
#define igBrkPedlSnsr_BrkPedlSnsrQf_IPDU_COM_CemBodyExpoCommonSignalIPDU08             154u
#define igAmbTRaw_AmbTRawQly_IPDU_COM_CemBodyExpoCommonSignalIPDU08             155u
#define igAmbTRaw_AmbTRawAmbTVal_IPDU_COM_CemBodyExpoCommonSignalIPDU08             156u
#define igVehBattU_VehBattUSysU_IPDU_COM_CemBodyExpoCommonSignalIPDU06             157u
#define igVehBattU_VehBattUSysUQf_IPDU_COM_CemBodyExpoCommonSignalIPDU06             158u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi_DwnLoadDynLtgPrmForLedDaytiRunngLampRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu33             159u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi_DwnLoadDynLtgPrmForLedDaytiRunngLampRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu33             160u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi_DwnLoadDynLtgPrmForLedDaytiRunngLampRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu33             161u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi_DwnLoadDynLtgPrmForLedDaytiRunngLampRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu33             162u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi_DwnLoadDynLtgPrmForLedDaytiRunngLampRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu33             163u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampRi_DwnLoadDynLtgPrmForLedDaytiRunngLampRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu33             164u
#define igLvlgSwtSetReq_LvlgSwtSetReqADModCtrlInhbn_IPDU_COM_CemBodyExpoSignalIPdu25             165u
#define igLvlgSwtSetReq_LvlgSwtSetReqCntr_IPDU_COM_CemBodyExpoSignalIPdu25             166u
#define igLvlgSwtSetReq_LvlgSwtSetReqChks_IPDU_COM_CemBodyExpoSignalIPdu25             167u
#define igOutdBri_OutdBriChks_IPDU_COM_CemBodyExpoSignalIPdu25             168u
#define igOutdBri_OutdBriSts_IPDU_COM_CemBodyExpoSignalIPdu25             169u
#define igOutdBri_OutdBriCntr_IPDU_COM_CemBodyExpoSignalIPdu25             170u
#define igVehObjforADB1_VehObjforADB1AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu13             171u
#define igVehObjforADB1_VehObjforADB1AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu13             172u
#define igVehObjforADB1_VehObjforADB1AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu13             173u
#define igVehObjforADB1_VehObjforADB1AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu13             174u
#define igVehObjforADB1_VehObjforADB1AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu13             175u
#define igVehObjforADB1_VehObjforADB1AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu13             176u
#define igVehObjforADB1_VehObjforADB1AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu13             177u
#define igVehObjforADB1_VehObjforADB1AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu13             178u
#define igVehObjforADB1_VehObjforADB1AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu13             179u
#define igVehObjforADB4_VehObjforADB4AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu16             180u
#define igVehObjforADB4_VehObjforADB4AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu16             181u
#define igVehObjforADB4_VehObjforADB4AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu16             182u
#define igVehObjforADB4_VehObjforADB4AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu16             183u
#define igVehObjforADB4_VehObjforADB4AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu16             184u
#define igVehObjforADB4_VehObjforADB4AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu16             185u
#define igVehObjforADB4_VehObjforADB4AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu16             186u
#define igVehObjforADB4_VehObjforADB4AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu16             187u
#define igVehObjforADB4_VehObjforADB4AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu16             188u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi_DwnLoadDynLtgPrmForLedAllWthrLampRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu29             189u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi_DwnLoadDynLtgPrmForLedAllWthrLampRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu29             190u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi_DwnLoadDynLtgPrmForLedAllWthrLampRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu29             191u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi_DwnLoadDynLtgPrmForLedAllWthrLampRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu29             192u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi_DwnLoadDynLtgPrmForLedAllWthrLampRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu29             193u
#define igDwnLoadDynLtgPrmForLedAllWthrLampRi_DwnLoadDynLtgPrmForLedAllWthrLampRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu29             194u
#define igDwnLoadDynLitPrmForLedLoBeamRi_DwnLoadDynLitPrmForLedLoBeamRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu07             195u
#define igDwnLoadDynLitPrmForLedLoBeamRi_DwnLoadDynLitPrmForLedLoBeamRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu07             196u
#define igDwnLoadDynLitPrmForLedLoBeamRi_DwnLoadDynLitPrmForLedLoBeamRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu07             197u
#define igDwnLoadDynLitPrmForLedLoBeamRi_DwnLoadDynLitPrmForLedLoBeamRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu07             198u
#define igDwnLoadDynLitPrmForLedLoBeamRi_DwnLoadDynLitPrmForLedLoBeamRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu07             199u
#define igDwnLoadDynLitPrmForLedLoBeamRi_DwnLoadDynLitPrmForLedLoBeamRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu07             200u
#define igSteerWhlSnsr_SteerWhlSnsrQf_IPDU_COM_CemBodyExpoCommonSignalIPdu01             201u
#define igSteerWhlSnsr_SteerWhlSnsrChks_IPDU_COM_CemBodyExpoCommonSignalIPdu01             202u
#define igSteerWhlSnsr_SteerWhlSnsrCntr_IPDU_COM_CemBodyExpoCommonSignalIPdu01             203u
#define igSteerWhlSnsr_SteerWhlSnsrAg_IPDU_COM_CemBodyExpoCommonSignalIPdu01             204u
#define igSteerWhlSnsr_SteerWhlSnsrAgSpd_IPDU_COM_CemBodyExpoCommonSignalIPdu01             205u
#define igDwnLoadDynLitPrmForLedHiBeamRi_DwnLoadDynLitPrmForLedHiBeamRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu38             206u
#define igDwnLoadDynLitPrmForLedHiBeamRi_DwnLoadDynLitPrmForLedHiBeamRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu38             207u
#define igDwnLoadDynLitPrmForLedHiBeamRi_DwnLoadDynLitPrmForLedHiBeamRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu38             208u
#define igDwnLoadDynLitPrmForLedHiBeamRi_DwnLoadDynLitPrmForLedHiBeamRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu38             209u
#define igDwnLoadDynLitPrmForLedHiBeamRi_DwnLoadDynLitPrmForLedHiBeamRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu38             210u
#define igDwnLoadDynLitPrmForLedHiBeamRi_DwnLoadDynLitPrmForLedHiBeamRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu38             211u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu37             212u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiModePrm_IPDU_COM_CemBodyExpoSignalIPdu37             213u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu37             214u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu37             215u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu37             216u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrRi_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiTistamp_IPDU_COM_CemBodyExpoSignalIPdu37             217u
#define igVehSpdLgt_VehSpdLgtQf_IPDU_COM_CemBodyExpoCommonSignalIPDU04             218u
#define igVehSpdLgt_VehSpdLgtCntr_IPDU_COM_CemBodyExpoCommonSignalIPDU04             219u
#define igVehSpdLgt_VehSpdLgtChks_IPDU_COM_CemBodyExpoCommonSignalIPDU04             220u
#define igVehSpdLgt_VehSpdLgtA_IPDU_COM_CemBodyExpoCommonSignalIPDU04             221u
#define igActvnOfIndcr_ActvnOfIndcrIndcrOutCntr_IPDU_COM_CemBodyExpoSignalIPdu51             222u
#define igActvnOfIndcr_ActvnOfIndcrIndcrOut_IPDU_COM_CemBodyExpoSignalIPdu51             223u
#define igActvnOfIndcr_ActvnOfIndcrIndcrOutChks_IPDU_COM_CemBodyExpoSignalIPdu51             224u
#define igIndcrPat_IndcrPatCmd1WdTiOff_IPDU_COM_CemBodyExpoSignalIPdu51             225u
#define igIndcrPat_IndcrPatCmd1WdTiOn_IPDU_COM_CemBodyExpoSignalIPdu51             226u
#define igTrafficSignForADB2_TrafficSignForADB2AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu11             227u
#define igTrafficSignForADB2_TrafficSignForADB2AdbDetdQly_IPDU_COM_CemBodyExpoCommonSignalIPdu11             228u
#define igTrafficSignForADB2_TrafficSignForADB2AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu11             229u
#define igTrafficSignForADB2_TrafficSignForADB2AdbVertAgBot_IPDU_COM_CemBodyExpoCommonSignalIPdu11             230u
#define igTrafficSignForADB2_TrafficSignForADB2AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu11             231u
#define igTrafficSignForADB2_TrafficSignForADB2AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu11             232u
#define igTrafficSignForADB2_TrafficSignForADB2AdbVertAgTop_IPDU_COM_CemBodyExpoCommonSignalIPdu11             233u
#define igVehObjforAHB_VehObjforAHBAdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu12             234u
#define igVehObjforAHB_VehObjforAHBAdbDetdQly_IPDU_COM_CemBodyExpoCommonSignalIPdu12             235u
#define igVehObjforAHB_VehObjforAHBAdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu12             236u
#define igVehObjforAHB_VehObjforAHBAdbClassnQly_IPDU_COM_CemBodyExpoCommonSignalIPdu12             237u
#define igVehObjforAHB_VehObjforAHBAdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu12             238u
#define igVehObjforAHB_VehObjforAHBAdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu12             239u
#define igVehObjforAHB_VehObjforAHBAdbObjVertAgSpd_IPDU_COM_CemBodyExpoCommonSignalIPdu12             240u
#define igVehObjforAHB_VehObjforAHBAdbObjHozlAgSpd_IPDU_COM_CemBodyExpoCommonSignalIPdu12             241u
#define igVehObjforAHB_VehObjforAHBAdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu12             242u
#define igVehObjforAHB_VehObjforAHBAdbHozlAg_IPDU_COM_CemBodyExpoCommonSignalIPdu12             243u
#define igBrkPedlVal_BrkPedlValBrkPedlVal_IPDU_COM_CemBodyExpoSignalIPdu45             244u
#define igBrkPedlVal_BrkPedlValQf_IPDU_COM_CemBodyExpoSignalIPdu45             245u
#define igWipgInfo_WipgInfoWiprActv_IPDU_COM_CemBodyExpoSignalIPdu45             246u
#define igWipgInfo_WipgInfoWiprInWipgAr_IPDU_COM_CemBodyExpoSignalIPdu45             247u
#define igWipgInfo_WipgInfoWipgSpdInfo_IPDU_COM_CemBodyExpoSignalIPdu45             248u
#define igActnOfLedLoBeam_ActnOfLedLoBeamActnOfLedLoBeam_IPDU_COM_CemBodyExpoSignalIPdu50             249u
#define igActnOfLedLoBeam_ActnOfLedLoBeamChks_IPDU_COM_CemBodyExpoSignalIPdu50             250u
#define igActnOfLedLoBeam_ActnOfLedLoBeamCntr_IPDU_COM_CemBodyExpoSignalIPdu50             251u
#define igSuspPosnVertAg_SuspPosnVertAgSuspPosnVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu22             252u
#define igSuspPosnVertAg_SuspPosnVertAgGenQf_IPDU_COM_CemBodyExpoCommonSignalIPdu22             253u
#define igSuspPosnVertLvl_SuspPosnVertLvlReQf_IPDU_COM_CemBodyExpoCommonSignalIPdu22             254u
#define igSuspPosnVertLvl_SuspPosnVertLvlRe_IPDU_COM_CemBodyExpoCommonSignalIPdu22             255u
#define igSuspPosnVertLvl_SuspPosnVertLvlFrnt_IPDU_COM_CemBodyExpoCommonSignalIPdu22             256u
#define igSuspPosnVertLvl_SuspPosnVertLvlFrntQf_IPDU_COM_CemBodyExpoCommonSignalIPdu22             257u
#define igDwnLoadDynLitPrmLedRiGrilleLamp_DwnLoadDynLitPrmLedRiGrilleLampOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu61             258u
#define igDwnLoadDynLitPrmLedRiGrilleLamp_DwnLoadDynLitPrmLedRiGrilleLampTistamp_IPDU_COM_CemBodyExpoSignalIPdu61             259u
#define igDwnLoadDynLitPrmLedRiGrilleLamp_DwnLoadDynLitPrmLedRiGrilleLampLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu61             260u
#define igDwnLoadDynLitPrmLedRiGrilleLamp_DwnLoadDynLitPrmLedRiGrilleLampModePrm_IPDU_COM_CemBodyExpoSignalIPdu61             261u
#define igDwnLoadDynLitPrmLedRiGrilleLamp_DwnLoadDynLitPrmLedRiGrilleLampUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu61             262u
#define igDwnLoadDynLitPrmLedRiGrilleLamp_DwnLoadDynLitPrmLedRiGrilleLampContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu61             263u
#define igDwnLoadDynLitPrmLedRiSideLogoLi_DwnLoadDynLitPrmLedRiSideLogoLiModePrm_IPDU_COM_CemBodyExpoSignalIPdu66             264u
#define igDwnLoadDynLitPrmLedRiSideLogoLi_DwnLoadDynLitPrmLedRiSideLogoLiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu66             265u
#define igDwnLoadDynLitPrmLedRiSideLogoLi_DwnLoadDynLitPrmLedRiSideLogoLiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu66             266u
#define igDwnLoadDynLitPrmLedRiSideLogoLi_DwnLoadDynLitPrmLedRiSideLogoLiTistamp_IPDU_COM_CemBodyExpoSignalIPdu66             267u
#define igDwnLoadDynLitPrmLedRiSideLogoLi_DwnLoadDynLitPrmLedRiSideLogoLiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu66             268u
#define igDwnLoadDynLitPrmLedRiSideLogoLi_DwnLoadDynLitPrmLedRiSideLogoLiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu66             269u
#define igDwnLoadDynLtgPrmForFrntRiGrp1_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu91             270u
#define igDwnLoadDynLtgPrmForFrntRiGrp1_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu91             271u
#define igDwnLoadDynLtgPrmForFrntRiGrp1_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu91             272u
#define igDwnLoadDynLtgPrmForFrntRiGrp1_DwnLoadDynLtgPrmForFrntLeGrp1Mode1_IPDU_COM_CemBodyExpoSignalIPdu91             273u
#define igDwnLoadDynLtgPrmForFrntRiGrp1_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp_IPDU_COM_CemBodyExpoSignalIPdu91             274u
#define igDwnLoadDynLtgPrmForFrntRiGrp1_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu91             275u
#define igDwnLoadDynLtgPrmForFrntRiGrp2_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp_IPDU_COM_CemBodyExpoSignalIPdu92             276u
#define igDwnLoadDynLtgPrmForFrntRiGrp2_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu92             277u
#define igDwnLoadDynLtgPrmForFrntRiGrp2_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu92             278u
#define igDwnLoadDynLtgPrmForFrntRiGrp2_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu92             279u
#define igDwnLoadDynLtgPrmForFrntRiGrp2_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu92             280u
#define igDwnLoadDynLtgPrmForFrntRiGrp2_DwnLoadDynLtgPrmForFrntLeGrp2Mode1_IPDU_COM_CemBodyExpoSignalIPdu92             281u
#define igDwnLoadDynLtgPrmForFrntRiGrp3_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp_IPDU_COM_CemBodyExpoSignalIPdu93             282u
#define igDwnLoadDynLtgPrmForFrntRiGrp3_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu93             283u
#define igDwnLoadDynLtgPrmForFrntRiGrp3_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu93             284u
#define igDwnLoadDynLtgPrmForFrntRiGrp3_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu93             285u
#define igDwnLoadDynLtgPrmForFrntRiGrp3_DwnLoadDynLtgPrmForFrntLeGrp3Mode1_IPDU_COM_CemBodyExpoSignalIPdu93             286u
#define igDwnLoadDynLtgPrmForFrntRiGrp3_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu93             287u
#define igDwnLoadDynLtgPrmForFrntRiGrp4_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu94             288u
#define igDwnLoadDynLtgPrmForFrntRiGrp4_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu94             289u
#define igDwnLoadDynLtgPrmForFrntRiGrp4_DwnLoadDynLtgPrmForFrntLeGrp4Mode1_IPDU_COM_CemBodyExpoSignalIPdu94             290u
#define igDwnLoadDynLtgPrmForFrntRiGrp4_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu94             291u
#define igDwnLoadDynLtgPrmForFrntRiGrp4_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp_IPDU_COM_CemBodyExpoSignalIPdu94             292u
#define igDwnLoadDynLtgPrmForFrntRiGrp4_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu94             293u
#define igDwnLoadDynLtgPrmForFrntRiGrp5_DwnLoadDynLtgPrmForFrntLeGrp5Mode1_IPDU_COM_CemBodyExpoSignalIPdu95             294u
#define igDwnLoadDynLtgPrmForFrntRiGrp5_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu95             295u
#define igDwnLoadDynLtgPrmForFrntRiGrp5_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu95             296u
#define igDwnLoadDynLtgPrmForFrntRiGrp5_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp_IPDU_COM_CemBodyExpoSignalIPdu95             297u
#define igDwnLoadDynLtgPrmForFrntRiGrp5_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu95             298u
#define igDwnLoadDynLtgPrmForFrntRiGrp5_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu95             299u
#define igDwnLoadDynLtgPrmForFrntRiGrp6_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp_IPDU_COM_CemBodyExpoSignalIPdu96             300u
#define igDwnLoadDynLtgPrmForFrntRiGrp6_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu96             301u
#define igDwnLoadDynLtgPrmForFrntRiGrp6_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu96             302u
#define igDwnLoadDynLtgPrmForFrntRiGrp6_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu96             303u
#define igDwnLoadDynLtgPrmForFrntRiGrp6_DwnLoadDynLtgPrmForFrntLeGrp6Mode1_IPDU_COM_CemBodyExpoSignalIPdu96             304u
#define igDwnLoadDynLtgPrmForFrntRiGrp6_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu96             305u
#define igDwnLoadDynLtgPrmForFrntRiGrp7_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu97             306u
#define igDwnLoadDynLtgPrmForFrntRiGrp7_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp_IPDU_COM_CemBodyExpoSignalIPdu97             307u
#define igDwnLoadDynLtgPrmForFrntRiGrp7_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu97             308u
#define igDwnLoadDynLtgPrmForFrntRiGrp7_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu97             309u
#define igDwnLoadDynLtgPrmForFrntRiGrp7_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu97             310u
#define igDwnLoadDynLtgPrmForFrntRiGrp7_DwnLoadDynLtgPrmForFrntLeGrp7Mode1_IPDU_COM_CemBodyExpoSignalIPdu97             311u
#define igDwnLoadDynLtgPrmForFrntRiGrp8_DwnLoadDynLtgPrmForFrntLeGrp8Mode1_IPDU_COM_CemBodyExpoSignalIPdu98             312u
#define igDwnLoadDynLtgPrmForFrntRiGrp8_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu98             313u
#define igDwnLoadDynLtgPrmForFrntRiGrp8_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu98             314u
#define igDwnLoadDynLtgPrmForFrntRiGrp8_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp_IPDU_COM_CemBodyExpoSignalIPdu98             315u
#define igDwnLoadDynLtgPrmForFrntRiGrp8_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu98             316u
#define igDwnLoadDynLtgPrmForFrntRiGrp8_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu98             317u
#define igDwnLoadDynLtgPrmForFrntRiGrp9_DwnLoadDynLtgPrmForFrntLeGrp9Mode1_IPDU_COM_CemBodyExpoSignalIPdu99             318u
#define igDwnLoadDynLtgPrmForFrntRiGrp9_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu99             319u
#define igDwnLoadDynLtgPrmForFrntRiGrp9_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu99             320u
#define igDwnLoadDynLtgPrmForFrntRiGrp9_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu99             321u
#define igDwnLoadDynLtgPrmForFrntRiGrp9_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu99             322u
#define igDwnLoadDynLtgPrmForFrntRiGrp9_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp_IPDU_COM_CemBodyExpoSignalIPdu99             323u
#define igDwnLoadDynLtgPrmForFrntRiGrp10_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp_IPDU_COM_CemBodyExpoSignalIPdu100             324u
#define igDwnLoadDynLtgPrmForFrntRiGrp10_DwnLoadDynLtgPrmForFrntLeGrp10Mode1_IPDU_COM_CemBodyExpoSignalIPdu100             325u
#define igDwnLoadDynLtgPrmForFrntRiGrp10_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu100             326u
#define igDwnLoadDynLtgPrmForFrntRiGrp10_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu100             327u
#define igDwnLoadDynLtgPrmForFrntRiGrp10_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu100             328u
#define igDwnLoadDynLtgPrmForFrntRiGrp10_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu100             329u
#define igDwnLoadDynLtgPrmForFrntRiGrp11_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu101             330u
#define igDwnLoadDynLtgPrmForFrntRiGrp11_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu101             331u
#define igDwnLoadDynLtgPrmForFrntRiGrp11_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp_IPDU_COM_CemBodyExpoSignalIPdu101             332u
#define igDwnLoadDynLtgPrmForFrntRiGrp11_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu101             333u
#define igDwnLoadDynLtgPrmForFrntRiGrp11_DwnLoadDynLtgPrmForFrntLeGrp11Mode1_IPDU_COM_CemBodyExpoSignalIPdu101             334u
#define igDwnLoadDynLtgPrmForFrntRiGrp11_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu101             335u
#define igDwnLoadDynLtgPrmForFrntRiGrp12_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp_IPDU_COM_CemBodyExpoSignalIPdu102             336u
#define igDwnLoadDynLtgPrmForFrntRiGrp12_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu102             337u
#define igDwnLoadDynLtgPrmForFrntRiGrp12_DwnLoadDynLtgPrmForFrntLeGrp12Mode1_IPDU_COM_CemBodyExpoSignalIPdu102             338u
#define igDwnLoadDynLtgPrmForFrntRiGrp12_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu102             339u
#define igDwnLoadDynLtgPrmForFrntRiGrp12_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu102             340u
#define igDwnLoadDynLtgPrmForFrntRiGrp12_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu102             341u
#define igDwnLoadDynLtgPrmForFrntRiGrp13_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu103             342u
#define igDwnLoadDynLtgPrmForFrntRiGrp13_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp_IPDU_COM_CemBodyExpoSignalIPdu103             343u
#define igDwnLoadDynLtgPrmForFrntRiGrp13_DwnLoadDynLtgPrmForFrntLeGrp13Mode1_IPDU_COM_CemBodyExpoSignalIPdu103             344u
#define igDwnLoadDynLtgPrmForFrntRiGrp13_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu103             345u
#define igDwnLoadDynLtgPrmForFrntRiGrp13_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu103             346u
#define igDwnLoadDynLtgPrmForFrntRiGrp13_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu103             347u
#define igDwnLoadDynLtgPrmForFrntRiGrp14_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp_IPDU_COM_CemBodyExpoSignalIPdu104             348u
#define igDwnLoadDynLtgPrmForFrntRiGrp14_DwnLoadDynLtgPrmForFrntLeGrp14Mode1_IPDU_COM_CemBodyExpoSignalIPdu104             349u
#define igDwnLoadDynLtgPrmForFrntRiGrp14_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu104             350u
#define igDwnLoadDynLtgPrmForFrntRiGrp14_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu104             351u
#define igDwnLoadDynLtgPrmForFrntRiGrp14_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu104             352u
#define igDwnLoadDynLtgPrmForFrntRiGrp14_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu104             353u
#define igDwnLoadDynLtgPrmForFrntRiGrp15_DwnLoadDynLtgPrmForFrntLeGrp15Mode1_IPDU_COM_CemBodyExpoSignalIPdu105             354u
#define igDwnLoadDynLtgPrmForFrntRiGrp15_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu105             355u
#define igDwnLoadDynLtgPrmForFrntRiGrp15_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp_IPDU_COM_CemBodyExpoSignalIPdu105             356u
#define igDwnLoadDynLtgPrmForFrntRiGrp15_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu105             357u
#define igDwnLoadDynLtgPrmForFrntRiGrp15_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu105             358u
#define igDwnLoadDynLtgPrmForFrntRiGrp15_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu105             359u
#define igDwnLoadDynLtgPrmForFrntRiGrp16_DwnLoadDynLtgPrmForFrntLeGrp16Mode1_IPDU_COM_CemBodyExpoSignalIPdu106             360u
#define igDwnLoadDynLtgPrmForFrntRiGrp16_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu106             361u
#define igDwnLoadDynLtgPrmForFrntRiGrp16_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu106             362u
#define igDwnLoadDynLtgPrmForFrntRiGrp16_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp_IPDU_COM_CemBodyExpoSignalIPdu106             363u
#define igDwnLoadDynLtgPrmForFrntRiGrp16_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu106             364u
#define igDwnLoadDynLtgPrmForFrntRiGrp16_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu106             365u
#define igDwnLoadDynLtgPrmForFrntRiGrp17_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu107             366u
#define igDwnLoadDynLtgPrmForFrntRiGrp17_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu107             367u
#define igDwnLoadDynLtgPrmForFrntRiGrp17_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp_IPDU_COM_CemBodyExpoSignalIPdu107             368u
#define igDwnLoadDynLtgPrmForFrntRiGrp17_DwnLoadDynLtgPrmForFrntLeGrp17Mode1_IPDU_COM_CemBodyExpoSignalIPdu107             369u
#define igDwnLoadDynLtgPrmForFrntRiGrp17_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu107             370u
#define igDwnLoadDynLtgPrmForFrntRiGrp17_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu107             371u
#define igDwnLoadDynLtgPrmForFrntRiGrp18_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu108             372u
#define igDwnLoadDynLtgPrmForFrntRiGrp18_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu108             373u
#define igDwnLoadDynLtgPrmForFrntRiGrp18_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu108             374u
#define igDwnLoadDynLtgPrmForFrntRiGrp18_DwnLoadDynLtgPrmForFrntLeGrp18Mode1_IPDU_COM_CemBodyExpoSignalIPdu108             375u
#define igDwnLoadDynLtgPrmForFrntRiGrp18_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu108             376u
#define igDwnLoadDynLtgPrmForFrntRiGrp18_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp_IPDU_COM_CemBodyExpoSignalIPdu108             377u
#define igDwnLoadDynLtgPrmForFrntRiGrp19_DwnLoadDynLtgPrmForFrntLeGrp19Mode1_IPDU_COM_CemBodyExpoSignalIPdu109             378u
#define igDwnLoadDynLtgPrmForFrntRiGrp19_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu109             379u
#define igDwnLoadDynLtgPrmForFrntRiGrp19_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu109             380u
#define igDwnLoadDynLtgPrmForFrntRiGrp19_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu109             381u
#define igDwnLoadDynLtgPrmForFrntRiGrp19_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp_IPDU_COM_CemBodyExpoSignalIPdu109             382u
#define igDwnLoadDynLtgPrmForFrntRiGrp19_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu109             383u
#define igDwnLoadDynLtgPrmForFrntRiGrp20_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu110             384u
#define igDwnLoadDynLtgPrmForFrntRiGrp20_DwnLoadDynLtgPrmForFrntLeGrp20Mode1_IPDU_COM_CemBodyExpoSignalIPdu110             385u
#define igDwnLoadDynLtgPrmForFrntRiGrp20_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu110             386u
#define igDwnLoadDynLtgPrmForFrntRiGrp20_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu110             387u
#define igDwnLoadDynLtgPrmForFrntRiGrp20_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp_IPDU_COM_CemBodyExpoSignalIPdu110             388u
#define igDwnLoadDynLtgPrmForFrntRiGrp20_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu110             389u
#define igDwnLoadDynLtgPrmForFrntRiGrp21_DwnLoadDynLtgPrmForFrntLeGrp21Mode1_IPDU_COM_CemBodyExpoSignalIPdu111             390u
#define igDwnLoadDynLtgPrmForFrntRiGrp21_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu111             391u
#define igDwnLoadDynLtgPrmForFrntRiGrp21_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu111             392u
#define igDwnLoadDynLtgPrmForFrntRiGrp21_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu111             393u
#define igDwnLoadDynLtgPrmForFrntRiGrp21_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp_IPDU_COM_CemBodyExpoSignalIPdu111             394u
#define igDwnLoadDynLtgPrmForFrntRiGrp21_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu111             395u
#define igDwnLoadDynLtgPrmForFrntRiGrp22_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu112             396u
#define igDwnLoadDynLtgPrmForFrntRiGrp22_DwnLoadDynLtgPrmForFrntLeGrp22Mode1_IPDU_COM_CemBodyExpoSignalIPdu112             397u
#define igDwnLoadDynLtgPrmForFrntRiGrp22_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu112             398u
#define igDwnLoadDynLtgPrmForFrntRiGrp22_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp_IPDU_COM_CemBodyExpoSignalIPdu112             399u
#define igDwnLoadDynLtgPrmForFrntRiGrp22_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu112             400u
#define igDwnLoadDynLtgPrmForFrntRiGrp22_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu112             401u
#define igDwnLoadDynLtgPrmForFrntRiGrp23_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp_IPDU_COM_CemBodyExpoSignalIPdu113             402u
#define igDwnLoadDynLtgPrmForFrntRiGrp23_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu113             403u
#define igDwnLoadDynLtgPrmForFrntRiGrp23_DwnLoadDynLtgPrmForFrntLeGrp23Mode1_IPDU_COM_CemBodyExpoSignalIPdu113             404u
#define igDwnLoadDynLtgPrmForFrntRiGrp23_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu113             405u
#define igDwnLoadDynLtgPrmForFrntRiGrp23_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu113             406u
#define igDwnLoadDynLtgPrmForFrntRiGrp23_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu113             407u
#define igDwnLoadDynLtgPrmForFrntRiGrp24_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu114             408u
#define igDwnLoadDynLtgPrmForFrntRiGrp24_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu114             409u
#define igDwnLoadDynLtgPrmForFrntRiGrp24_DwnLoadDynLtgPrmForFrntLeGrp24Mode1_IPDU_COM_CemBodyExpoSignalIPdu114             410u
#define igDwnLoadDynLtgPrmForFrntRiGrp24_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp_IPDU_COM_CemBodyExpoSignalIPdu114             411u
#define igDwnLoadDynLtgPrmForFrntRiGrp24_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu114             412u
#define igDwnLoadDynLtgPrmForFrntRiGrp24_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu114             413u
#define igTiAndDateIndcn_TiAndDateIndcnDay_IPDU_COM_CemBodyExpoSignalIPdu116             414u
#define igTiAndDateIndcn_TiAndDateIndcnYr1_IPDU_COM_CemBodyExpoSignalIPdu116             415u
#define igTiAndDateIndcn_TiAndDateIndcnMins1_IPDU_COM_CemBodyExpoSignalIPdu116             416u
#define igTiAndDateIndcn_TiAndDateIndcnMth1_IPDU_COM_CemBodyExpoSignalIPdu116             417u
#define igTiAndDateIndcn_TiAndDateIndcnHr1_IPDU_COM_CemBodyExpoSignalIPdu116             418u
#define igTiAndDateIndcn_TiAndDateIndcnSec1_IPDU_COM_CemBodyExpoSignalIPdu116             419u
#define igTiAndDateIndcn_TiAndDateIndcnDataValid_IPDU_COM_CemBodyExpoSignalIPdu116             420u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_GWMAPPING_NUMBER         0u
#define COM_GW_SOURCE_DESCRIPTION_NUMBER     0u
#define COM_GW_DESTINATION_DESCRIPTION_NUMBER        0u

#define COM_TXTPPDU_SUPPORT          STD_OFF
#define COM_RXTPPDU_SUPPORT          STD_OFF

/* Macro for Optimize */
#define COM_SIGNAL_GW_ENABLE    STD_OFF

#define COM_TMS_ENABLE    STD_OFF

#define COM_TX_MODE_DIRECT_ENABLE    STD_OFF

#define COM_TX_MODE_MIXED_ENABLE    STD_OFF

#define COM_TX_MODE_DIRECT_N_TIMES_ENABLE   STD_OFF

#define COM_TX_MODE_MIXED_N_TIMES_ENABLE    STD_OFF

#define COM_MDT_ENABLE  STD_OFF

#define COM_TX_IPDU_COUNTER_ENABLE  STD_OFF

#define COM_RX_IPDU_COUNTER_ENABLE  STD_OFF

#define COM_IPDU_REPLICATION_ENABLE      STD_OFF

#define COM_TX_SIGNAL_NOTIFICATION_ENABLE   STD_ON

#define COM_RX_SIGNAL_NOTIFICATION_ENABLE   STD_ON

#define COM_RX_SIGNAL_TIMEOUT_ENABLE    STD_OFF

#define COM_TX_SIGNAL_TIMEOUT_ENABLE    STD_OFF

#define COM_RX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE      STD_OFF

#define COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE     STD_OFF

#define COM_RX_SIGNAL_UPDATE_BIT_ENABLE     STD_ON

#define COM_TX_SIGNAL_UPDATE_BIT_ENABLE     STD_ON

#define COM_RX_SIGNAL_INVALID_DATA_ENABLE   STD_OFF

#define COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE     STD_ON

#define COM_TX_SIG_PROP_TRIGGERED_ENABLE    STD_OFF

#define COM_TX_SIG_PROP_TRIGGERED_ON_CHANGE_ENABLE  STD_OFF

#define COM_TX_SIG_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE     STD_OFF

#define COM_TX_SIG_PROP_TRIG_NO_REPETITION_ENABLE   STD_OFF

#define COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE     STD_ON

#define COM_RX_SIGNAL_FILTER_ENABLE     STD_OFF

#define COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_TX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE     STD_ON

#define COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE   STD_ON

#define COM_TX_SIG_GROUP_NOTIFICATION_ENABLE    STD_OFF

#define COM_RX_SIG_GROUP_NOTIFICATION_ENABLE    STD_ON

#define COM_RX_SIG_GROUP_TIMEOUT_ENABLE     STD_ON

#define COM_TX_SIG_GROUP_TIMEOUT_ENABLE     STD_OFF

#define COM_RX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE    STD_ON

#define COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE    STD_OFF

#define COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE  STD_ON

#define COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE  STD_ON

#define COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE  STD_ON

#define COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE    STD_OFF

#define COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE   STD_OFF

#define COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE     STD_OFF

#define COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE  STD_OFF

#define COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE  STD_OFF

#define COM_RX_SIG_GROUP_INVALID_DATA_ACTION_NOTIFY_ENABLE  STD_ON

#define COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE      STD_OFF

#define COM_TX_SIGNAL_TYPE_UINT8_N_ENABLE     STD_OFF

#define COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE   STD_OFF

#define COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE   STD_OFF

#define COM_RX_GRP_SIGNAL_FILTER_ENABLE     STD_OFF

#define COM_GW_DEST_SIG_UPDATE_BIT_ENABLE   STD_OFF

#define COM_GW_SRC_SIG_UPDATE_BIT_ENABLE    STD_OFF

#define COM_TX_IPDU_CALLOUT_ENABLE     STD_OFF

#define COM_RX_IPDU_CALLOUT_ENABLE     STD_OFF

#define COM_TX_SIG_INITIAL_VALUE_ONLY_ENABLE  STD_OFF

#define COM_RX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE     STD_ON

#define COM_TX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE     STD_ON

#define COM_TX_IPDU_TYPE_TP_ENABLE     STD_OFF

#define COM_RX_SIGNAL_TIMEOUT_ACTION_REPLACE_ENABLE     STD_OFF

#define COM_RX_SIG_GROUP_TIMEOUT_ACTION_REPLACE_ENABLE     STD_OFF

#define COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE     STD_OFF

#define COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_SIGNAL_SIGNED_TYPE_ENABLE     STD_OFF

#endif

