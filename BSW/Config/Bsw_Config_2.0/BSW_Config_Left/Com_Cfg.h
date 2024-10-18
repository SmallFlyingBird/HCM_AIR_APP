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
**  Created on  : 2024/08/27 15:52:53                                         **
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
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu09        0u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu10        1u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu19        2u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu17        3u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU05        4u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu21        5u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu20        6u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu42        7u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu30        8u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu34        9u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu15        10u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu02        11u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu14        12u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu18        13u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU07        14u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU08        15u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU06        16u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu32        17u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu25        18u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu13        19u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu16        20u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu28        21u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu27        22u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu01        23u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu26        24u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu36        25u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPDU04        26u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu51        27u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu11        28u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu12        29u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu45        30u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu50        31u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu01        32u
#define COM_RXPDU_COM_CemBodyExpoCommonSignalIPdu22        33u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu59        34u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu60        35u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu65        36u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu67        37u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu68        38u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu69        39u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu70        40u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu71        41u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu72        42u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu73        43u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu74        44u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu75        45u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu76        46u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu77        47u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu78        48u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu79        49u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu81        50u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu80        51u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu82        52u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu83        53u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu84        54u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu85        55u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu86        56u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu87        57u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu88        58u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu89        59u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu90        60u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu115        61u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu116        62u
#define COM_RXPDU_COM_CemBodyExpoSignalIPdu63        63u
#define COM_RXPDU_ComCanNmEiraRxPdu        64u
#define COM_RXPDU_ComCanNmEraRxPdu_BodyExposedCAN_HCML        65u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_TXIPDU_NUMBER    3u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define COM_TXPDU_COM_HcmlBodyExpoSignalIPDU02        66u
#define COM_TXPDU_COM_HcmlBodyExpoSignalIPDU04        67u
#define COM_TXPDU_ComCanNmUserDataTxPdu_BodyExposedCAN_HCML        68u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_RXIPDUBUFF_SIZE        524u
#define COM_TXIPDUBUFF_SIZE        17u

#define COM_SIGNAL_BOOLBUFF_SIZE            55u
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE     16u
#define COM_SIGNAL_BOOL_INVALID_SIZE        0u

#define COM_SIGNAL_8BITBUFF_SIZE            316u
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
#define igDwnLoadDynLtgPrmForLedCornrgLampLe               7u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe               8u
#define igVehObjforADB3               9u
#define igBrkPedlrRat               10u
#define igVehObjforADB2               11u
#define igVehObjforADB6               12u
#define igAccrPedlRat               13u
#define igBrkPedlSnsr               14u
#define igAmbTRaw               15u
#define igVehBattU               16u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe               17u
#define igLvlgSwtSetReq               18u
#define igOutdBri               19u
#define igVehObjforADB1               20u
#define igVehObjforADB4               21u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe               22u
#define igDwnLoadDynLitPrmForLedLoBeamLe               23u
#define igSteerWhlSnsr               24u
#define igDwnLoadDynLitPrmForLedHiBeamLe               25u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe               26u
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
#define igDwnLoadDynLitPrmLedLeGrilleLamp               37u
#define igDwnLoadDynLitPrmLedLeSideLogoLi               38u
#define igDwnLoadDynLtgPrmForFrntLeGrp1               39u
#define igDwnLoadDynLtgPrmForFrntLeGrp2               40u
#define igDwnLoadDynLtgPrmForFrntLeGrp3               41u
#define igDwnLoadDynLtgPrmForFrntLeGrp4               42u
#define igDwnLoadDynLtgPrmForFrntLeGrp5               43u
#define igDwnLoadDynLtgPrmForFrntLeGrp6               44u
#define igDwnLoadDynLtgPrmForFrntLeGrp7               45u
#define igDwnLoadDynLtgPrmForFrntLeGrp8               46u
#define igDwnLoadDynLtgPrmForFrntLeGrp9               47u
#define igDwnLoadDynLtgPrmForFrntLeGrp10               48u
#define igDwnLoadDynLtgPrmForFrntLeGrp11               49u
#define igDwnLoadDynLtgPrmForFrntLeGrp12               50u
#define igDwnLoadDynLtgPrmForFrntLeGrp13               51u
#define igDwnLoadDynLtgPrmForFrntLeGrp15               52u
#define igDwnLoadDynLtgPrmForFrntLeGrp14               53u
#define igDwnLoadDynLtgPrmForFrntLeGrp16               54u
#define igDwnLoadDynLtgPrmForFrntLeGrp17               55u
#define igDwnLoadDynLtgPrmForFrntLeGrp18               56u
#define igDwnLoadDynLtgPrmForFrntLeGrp19               57u
#define igDwnLoadDynLtgPrmForFrntLeGrp20               58u
#define igDwnLoadDynLtgPrmForFrntLeGrp21               59u
#define igDwnLoadDynLtgPrmForFrntLeGrp22               60u
#define igDwnLoadDynLtgPrmForFrntLeGrp23               61u
#define igDwnLoadDynLtgPrmForFrntLeGrp24               62u
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
#define COM_RXSIGNAL_NUMBER               53u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define WipgAutFrntMod_IPDU_COM_CemBodyExpoCommonSignalIPdu21             0u
#define RainLi_IPDU_COM_CemBodyExpoCommonSignalIPdu21             1u
#define CameraStsforAHBC_IPDU_COM_CemBodyExpoCommonSignalIPdu21             2u
#define ActnOfLedPosnLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             3u
#define ActnOfLedFrntCrossLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             4u
#define ActnOfLedGrilleLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             5u
#define ActnOfLedLeLogoLampDyn_IPDU_COM_CemBodyExpoSignalIPdu42             6u
#define ActvnOfHomeSafe_IPDU_COM_CemBodyExpoSignalIPdu42             7u
#define YawRateReqdByDrvr_IPDU_COM_CemBodyExpoCommonSignalIPdu02             8u
#define CarTiGlb_IPDU_COM_CemBodyExpoCommonSignalIPDU07             9u
#define Body2CntrForMissCom_IPDU_COM_CemBodyExpoCommonSignalIPDU07             10u
#define ActnOfLedFrntCrossLamp_IPDU_COM_CemBodyExpoCommonSignalIPDU07             11u
#define ActnOfLedGrilleLamp_IPDU_COM_CemBodyExpoCommonSignalIPDU07             12u
#define ActnOfLedLeLogoLamp_IPDU_COM_CemBodyExpoCommonSignalIPDU07             13u
#define TooManyCars_IPDU_COM_CemBodyExpoCommonSignalIPDU08             14u
#define ExtrLiRlyPwrDwn_IPDU_COM_CemBodyExpoCommonSignalIPDU06             15u
#define BkpOfDstTrvld_IPDU_COM_CemBodyExpoCommonSignalIPDU06             16u
#define LiOprnMod_IPDU_COM_CemBodyExpoCommonSignalIPdu01             17u
#define AutWinWipgCmd_IPDU_COM_CemBodyExpoCommonSignalIPdu01             18u
#define IndcrSts_IPDU_COM_CemBodyExpoSignalIPdu51             19u
#define LitArea_IPDU_COM_CemBodyExpoSignalIPdu45             20u
#define ActvnOfApproach_IPDU_COM_CemBodyExpoSignalIPdu45             21u
#define ActvnOfCarLoctr_IPDU_COM_CemBodyExpoSignalIPdu45             22u
#define ActvnOfWaitMode_IPDU_COM_CemBodyExpoSignalIPdu45             23u
#define IndcrNoSeq_IPDU_COM_CemBodyExpoSignalIPdu45             24u
#define ActnOfLedCornrgLampLe_IPDU_COM_CemBodyExpoSignalIPdu50             25u
#define ActnOfLedDaytiRunngLamp_IPDU_COM_CemBodyExpoSignalIPdu50             26u
#define ActnOfLedFrntFogLamp_IPDU_COM_CemBodyExpoSignalIPdu50             27u
#define ActnOfLedHiBeam_IPDU_COM_CemBodyExpoSignalIPdu50             28u
#define ActnOfLedPosnLamp_IPDU_COM_CemBodyExpoSignalIPdu50             29u
#define ActvnOfAfs_IPDU_COM_CemBodyExpoSignalIPdu50             30u
#define ActvnOfAhbc_IPDU_COM_CemBodyExpoSignalIPdu50             31u
#define ActvnOfAhl_IPDU_COM_CemBodyExpoSignalIPdu50             32u
#define ActvnOfDbl_IPDU_COM_CemBodyExpoSignalIPdu50             33u
#define ActvnOfGoodByeLi_IPDU_COM_CemBodyExpoSignalIPdu50             34u
#define ActvnOfTouristMod_IPDU_COM_CemBodyExpoSignalIPdu50             35u
#define ActvnOfWelcomeLi_IPDU_COM_CemBodyExpoSignalIPdu50             36u
#define ExtrLiShowFileTxReq_IPDU_COM_CemBodyExpoSignalIPdu01             37u
#define ExtrLiShowActvnReq_IPDU_COM_CemBodyExpoSignalIPdu01             38u
#define WelcomeGoodbyeModeReq_IPDU_COM_CemBodyExpoSignalIPdu59             39u
#define WelLiFileTxReq_IPDU_COM_CemBodyExpoSignalIPdu67             40u
#define ActvnOfLiForComity_IPDU_COM_CemBodyExpoSignalIPdu115             41u
#define ActvnOfLiForSpkr_IPDU_COM_CemBodyExpoSignalIPdu115             42u
#define ActvnOfLiForWait_IPDU_COM_CemBodyExpoSignalIPdu115             43u
#define ActvnOfADB_IPDU_COM_CemBodyExpoSignalIPdu115             44u
#define DHUcontrolleftcorneringlamp_IPDU_COM_CemBodyExpoSignalIPdu63             45u
#define DHUcontrolleftdaytimerunninglamp_IPDU_COM_CemBodyExpoSignalIPdu63             46u
#define DHUcontrolleftfroglight_IPDU_COM_CemBodyExpoSignalIPdu63             47u
#define DHUcontrollefthighbeamlamp_IPDU_COM_CemBodyExpoSignalIPdu63             48u
#define DHUcontrolleftlowbeamlamp_IPDU_COM_CemBodyExpoSignalIPdu63             49u
#define DHUcontrolleftpositionlamp_IPDU_COM_CemBodyExpoSignalIPdu63             50u
#define isCanNmEira             51u
#define isCanNmEra_BodyExposedCAN_HCML             52u
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
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn5_IPDU_COM_CemBodyExpoCommonSignalIPdu09             53u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn6_IPDU_COM_CemBodyExpoCommonSignalIPdu09             54u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn2_IPDU_COM_CemBodyExpoCommonSignalIPdu09             55u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn3_IPDU_COM_CemBodyExpoCommonSignalIPdu09             56u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn8_IPDU_COM_CemBodyExpoCommonSignalIPdu09             57u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn4_IPDU_COM_CemBodyExpoCommonSignalIPdu09             58u
#define igVehCfgPrmExt_VehCfgPrmExtCCPBytePosn7_IPDU_COM_CemBodyExpoCommonSignalIPdu09             59u
#define igVehCfgPrmExt_VehCfgPrmExtBlkIDBytePosn1_IPDU_COM_CemBodyExpoCommonSignalIPdu09             60u
#define igTrafficSignForADB1_TrafficSignForADB1AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu10             61u
#define igTrafficSignForADB1_TrafficSignForADB1AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu10             62u
#define igTrafficSignForADB1_TrafficSignForADB1AdbDetdQly_IPDU_COM_CemBodyExpoCommonSignalIPdu10             63u
#define igTrafficSignForADB1_TrafficSignForADB1AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu10             64u
#define igTrafficSignForADB1_TrafficSignForADB1AdbVertAgTop_IPDU_COM_CemBodyExpoCommonSignalIPdu10             65u
#define igTrafficSignForADB1_TrafficSignForADB1AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu10             66u
#define igTrafficSignForADB1_TrafficSignForADB1AdbVertAgBot_IPDU_COM_CemBodyExpoCommonSignalIPdu10             67u
#define igVehObjforADB7_VehObjforADB7AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu19             68u
#define igVehObjforADB7_VehObjforADB7AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu19             69u
#define igVehObjforADB7_VehObjforADB7AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu19             70u
#define igVehObjforADB7_VehObjforADB7AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu19             71u
#define igVehObjforADB7_VehObjforADB7AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu19             72u
#define igVehObjforADB7_VehObjforADB7AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu19             73u
#define igVehObjforADB7_VehObjforADB7AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu19             74u
#define igVehObjforADB7_VehObjforADB7AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu19             75u
#define igVehObjforADB7_VehObjforADB7AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu19             76u
#define igVehObjforADB5_VehObjforADB5AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu17             77u
#define igVehObjforADB5_VehObjforADB5AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu17             78u
#define igVehObjforADB5_VehObjforADB5AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu17             79u
#define igVehObjforADB5_VehObjforADB5AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu17             80u
#define igVehObjforADB5_VehObjforADB5AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu17             81u
#define igVehObjforADB5_VehObjforADB5AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu17             82u
#define igVehObjforADB5_VehObjforADB5AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu17             83u
#define igVehObjforADB5_VehObjforADB5AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu17             84u
#define igVehObjforADB5_VehObjforADB5AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu17             85u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn6_IPDU_COM_CemBodyExpoCommonSignalIPDU05             86u
#define igVehCfgPrm_VehCfgPrmBlkIDBytePosn1_IPDU_COM_CemBodyExpoCommonSignalIPDU05             87u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn4_IPDU_COM_CemBodyExpoCommonSignalIPDU05             88u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn3_IPDU_COM_CemBodyExpoCommonSignalIPDU05             89u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn2_IPDU_COM_CemBodyExpoCommonSignalIPDU05             90u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn8_IPDU_COM_CemBodyExpoCommonSignalIPDU05             91u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn7_IPDU_COM_CemBodyExpoCommonSignalIPDU05             92u
#define igVehCfgPrm_VehCfgPrmCCPBytePosn5_IPDU_COM_CemBodyExpoCommonSignalIPDU05             93u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1Chks_IPDU_COM_CemBodyExpoCommonSignalIPdu21             94u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1CarModSts1_IPDU_COM_CemBodyExpoCommonSignalIPdu21             95u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1Cntr_IPDU_COM_CemBodyExpoCommonSignalIPdu21             96u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1EgyLvlElecSubtyp_IPDU_COM_CemBodyExpoCommonSignalIPdu21             97u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1PwrLvlElecSubtyp_IPDU_COM_CemBodyExpoCommonSignalIPdu21             98u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1CarModSubtypWdCarModSubtyp_IPDU_COM_CemBodyExpoCommonSignalIPdu21             99u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1UsgModSts_IPDU_COM_CemBodyExpoCommonSignalIPdu21             100u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1PwrLvlElecMai_IPDU_COM_CemBodyExpoCommonSignalIPdu21             101u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1EgyLvlElecMai_IPDU_COM_CemBodyExpoCommonSignalIPdu21             102u
#define igVehModMngtGlbSafe1_VehModMngtGlbSafe1FltEgyCnsWdSts_IPDU_COM_CemBodyExpoCommonSignalIPdu21             103u
#define igVehObjforADB8_VehObjforADB8AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu20             104u
#define igVehObjforADB8_VehObjforADB8AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu20             105u
#define igVehObjforADB8_VehObjforADB8AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu20             106u
#define igVehObjforADB8_VehObjforADB8AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu20             107u
#define igVehObjforADB8_VehObjforADB8AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu20             108u
#define igVehObjforADB8_VehObjforADB8AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu20             109u
#define igVehObjforADB8_VehObjforADB8AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu20             110u
#define igVehObjforADB8_VehObjforADB8AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu20             111u
#define igVehObjforADB8_VehObjforADB8AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu20             112u
#define igDwnLoadDynLtgPrmForLedCornrgLampLe_DwnLoadDynLtgPrmForLedCornrgLampLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu30             113u
#define igDwnLoadDynLtgPrmForLedCornrgLampLe_DwnLoadDynLtgPrmForLedCornrgLampLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu30             114u
#define igDwnLoadDynLtgPrmForLedCornrgLampLe_DwnLoadDynLtgPrmForLedCornrgLampLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu30             115u
#define igDwnLoadDynLtgPrmForLedCornrgLampLe_DwnLoadDynLtgPrmForLedCornrgLampLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu30             116u
#define igDwnLoadDynLtgPrmForLedCornrgLampLe_DwnLoadDynLtgPrmForLedCornrgLampLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu30             117u
#define igDwnLoadDynLtgPrmForLedCornrgLampLe_DwnLoadDynLtgPrmForLedCornrgLampLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu30             118u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe_DwnLoadDynLtgPrmForLedFrntPosnLampLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu34             119u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe_DwnLoadDynLtgPrmForLedFrntPosnLampLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu34             120u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe_DwnLoadDynLtgPrmForLedFrntPosnLampLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu34             121u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe_DwnLoadDynLtgPrmForLedFrntPosnLampLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu34             122u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe_DwnLoadDynLtgPrmForLedFrntPosnLampLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu34             123u
#define igDwnLoadDynLtgPrmForLedFrntPosnLampLe_DwnLoadDynLtgPrmForLedFrntPosnLampLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu34             124u
#define igVehObjforADB3_VehObjforADB3AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu15             125u
#define igVehObjforADB3_VehObjforADB3AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu15             126u
#define igVehObjforADB3_VehObjforADB3AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu15             127u
#define igVehObjforADB3_VehObjforADB3AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu15             128u
#define igVehObjforADB3_VehObjforADB3AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu15             129u
#define igVehObjforADB3_VehObjforADB3AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu15             130u
#define igVehObjforADB3_VehObjforADB3AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu15             131u
#define igVehObjforADB3_VehObjforADB3AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu15             132u
#define igVehObjforADB3_VehObjforADB3AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu15             133u
#define igBrkPedlrRat_BrkPedlrRatQf_IPDU_COM_CemBodyExpoCommonSignalIPdu02             134u
#define igBrkPedlrRat_BrkPedlrRatPerc_IPDU_COM_CemBodyExpoCommonSignalIPdu02             135u
#define igVehObjforADB2_VehObjforADB2AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu14             136u
#define igVehObjforADB2_VehObjforADB2AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu14             137u
#define igVehObjforADB2_VehObjforADB2AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu14             138u
#define igVehObjforADB2_VehObjforADB2AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu14             139u
#define igVehObjforADB2_VehObjforADB2AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu14             140u
#define igVehObjforADB2_VehObjforADB2AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu14             141u
#define igVehObjforADB2_VehObjforADB2AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu14             142u
#define igVehObjforADB2_VehObjforADB2AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu14             143u
#define igVehObjforADB2_VehObjforADB2AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu14             144u
#define igVehObjforADB6_VehObjforADB6AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu18             145u
#define igVehObjforADB6_VehObjforADB6AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu18             146u
#define igVehObjforADB6_VehObjforADB6AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu18             147u
#define igVehObjforADB6_VehObjforADB6AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu18             148u
#define igVehObjforADB6_VehObjforADB6AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu18             149u
#define igVehObjforADB6_VehObjforADB6AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu18             150u
#define igVehObjforADB6_VehObjforADB6AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu18             151u
#define igVehObjforADB6_VehObjforADB6AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu18             152u
#define igVehObjforADB6_VehObjforADB6AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu18             153u
#define igAccrPedlRat_AccrPedlRatCntr_IPDU_COM_CemBodyExpoCommonSignalIPDU08             154u
#define igAccrPedlRat_AccrPedlRatChks_IPDU_COM_CemBodyExpoCommonSignalIPDU08             155u
#define igAccrPedlRat_AccrPedlRatAccrPedlRat_IPDU_COM_CemBodyExpoCommonSignalIPDU08             156u
#define igBrkPedlSnsr_BrkPedlSnsrSt_IPDU_COM_CemBodyExpoCommonSignalIPDU08             157u
#define igBrkPedlSnsr_BrkPedlSnsrChks_IPDU_COM_CemBodyExpoCommonSignalIPDU08             158u
#define igBrkPedlSnsr_BrkPedlSnsrCntr_IPDU_COM_CemBodyExpoCommonSignalIPDU08             159u
#define igBrkPedlSnsr_BrkPedlSnsrQf_IPDU_COM_CemBodyExpoCommonSignalIPDU08             160u
#define igAmbTRaw_AmbTRawQly_IPDU_COM_CemBodyExpoCommonSignalIPDU08             161u
#define igAmbTRaw_AmbTRawAmbTVal_IPDU_COM_CemBodyExpoCommonSignalIPDU08             162u
#define igVehBattU_VehBattUSysU_IPDU_COM_CemBodyExpoCommonSignalIPDU06             163u
#define igVehBattU_VehBattUSysUQf_IPDU_COM_CemBodyExpoCommonSignalIPDU06             164u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe_DwnLoadDynLtgPrmForLedDaytiRunngLampLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu32             165u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe_DwnLoadDynLtgPrmForLedDaytiRunngLampLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu32             166u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe_DwnLoadDynLtgPrmForLedDaytiRunngLampLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu32             167u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe_DwnLoadDynLtgPrmForLedDaytiRunngLampLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu32             168u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe_DwnLoadDynLtgPrmForLedDaytiRunngLampLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu32             169u
#define igDwnLoadDynLtgPrmForLedDaytiRunngLampLe_DwnLoadDynLtgPrmForLedDaytiRunngLampLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu32             170u
#define igLvlgSwtSetReq_LvlgSwtSetReqADModCtrlInhbn_IPDU_COM_CemBodyExpoSignalIPdu25             171u
#define igLvlgSwtSetReq_LvlgSwtSetReqCntr_IPDU_COM_CemBodyExpoSignalIPdu25             172u
#define igLvlgSwtSetReq_LvlgSwtSetReqChks_IPDU_COM_CemBodyExpoSignalIPdu25             173u
#define igOutdBri_OutdBriChks_IPDU_COM_CemBodyExpoSignalIPdu25             174u
#define igOutdBri_OutdBriSts_IPDU_COM_CemBodyExpoSignalIPdu25             175u
#define igOutdBri_OutdBriCntr_IPDU_COM_CemBodyExpoSignalIPdu25             176u
#define igVehObjforADB1_VehObjforADB1AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu13             177u
#define igVehObjforADB1_VehObjforADB1AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu13             178u
#define igVehObjforADB1_VehObjforADB1AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu13             179u
#define igVehObjforADB1_VehObjforADB1AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu13             180u
#define igVehObjforADB1_VehObjforADB1AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu13             181u
#define igVehObjforADB1_VehObjforADB1AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu13             182u
#define igVehObjforADB1_VehObjforADB1AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu13             183u
#define igVehObjforADB1_VehObjforADB1AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu13             184u
#define igVehObjforADB1_VehObjforADB1AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu13             185u
#define igVehObjforADB4_VehObjforADB4AdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu16             186u
#define igVehObjforADB4_VehObjforADB4AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu16             187u
#define igVehObjforADB4_VehObjforADB4AdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu16             188u
#define igVehObjforADB4_VehObjforADB4AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu16             189u
#define igVehObjforADB4_VehObjforADB4AdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu16             190u
#define igVehObjforADB4_VehObjforADB4AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu16             191u
#define igVehObjforADB4_VehObjforADB4AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu16             192u
#define igVehObjforADB4_VehObjforADB4AdbObjHozlAgSpdRi_IPDU_COM_CemBodyExpoCommonSignalIPdu16             193u
#define igVehObjforADB4_VehObjforADB4AdbObjHozlAgSpdLe_IPDU_COM_CemBodyExpoCommonSignalIPdu16             194u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe_DwnLoadDynLtgPrmForLedAllWthrLampLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu28             195u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe_DwnLoadDynLtgPrmForLedAllWthrLampLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu28             196u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe_DwnLoadDynLtgPrmForLedAllWthrLampLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu28             197u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe_DwnLoadDynLtgPrmForLedAllWthrLampLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu28             198u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe_DwnLoadDynLtgPrmForLedAllWthrLampLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu28             199u
#define igDwnLoadDynLtgPrmForLedAllWthrLampLe_DwnLoadDynLtgPrmForLedAllWthrLampLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu28             200u
#define igDwnLoadDynLitPrmForLedLoBeamLe_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu27             201u
#define igDwnLoadDynLitPrmForLedLoBeamLe_DwnLoadDynLitPrmForLedLoBeamLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu27             202u
#define igDwnLoadDynLitPrmForLedLoBeamLe_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu27             203u
#define igDwnLoadDynLitPrmForLedLoBeamLe_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu27             204u
#define igDwnLoadDynLitPrmForLedLoBeamLe_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu27             205u
#define igDwnLoadDynLitPrmForLedLoBeamLe_DwnLoadDynLitPrmForLedLoBeamLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu27             206u
#define igSteerWhlSnsr_SteerWhlSnsrQf_IPDU_COM_CemBodyExpoCommonSignalIPdu01             207u
#define igSteerWhlSnsr_SteerWhlSnsrChks_IPDU_COM_CemBodyExpoCommonSignalIPdu01             208u
#define igSteerWhlSnsr_SteerWhlSnsrCntr_IPDU_COM_CemBodyExpoCommonSignalIPdu01             209u
#define igSteerWhlSnsr_SteerWhlSnsrAg_IPDU_COM_CemBodyExpoCommonSignalIPdu01             210u
#define igSteerWhlSnsr_SteerWhlSnsrAgSpd_IPDU_COM_CemBodyExpoCommonSignalIPdu01             211u
#define igDwnLoadDynLitPrmForLedHiBeamLe_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu26             212u
#define igDwnLoadDynLitPrmForLedHiBeamLe_DwnLoadDynLitPrmForLedHiBeamLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu26             213u
#define igDwnLoadDynLitPrmForLedHiBeamLe_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu26             214u
#define igDwnLoadDynLitPrmForLedHiBeamLe_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu26             215u
#define igDwnLoadDynLitPrmForLedHiBeamLe_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu26             216u
#define igDwnLoadDynLitPrmForLedHiBeamLe_DwnLoadDynLitPrmForLedHiBeamLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu26             217u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu36             218u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeModePrm_IPDU_COM_CemBodyExpoSignalIPdu36             219u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu36             220u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu36             221u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu36             222u
#define igDwnLoadDynLtgPrmForLedFrntTurnIndcrLe_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeTistamp_IPDU_COM_CemBodyExpoSignalIPdu36             223u
#define igVehSpdLgt_VehSpdLgtQf_IPDU_COM_CemBodyExpoCommonSignalIPDU04             224u
#define igVehSpdLgt_VehSpdLgtCntr_IPDU_COM_CemBodyExpoCommonSignalIPDU04             225u
#define igVehSpdLgt_VehSpdLgtChks_IPDU_COM_CemBodyExpoCommonSignalIPDU04             226u
#define igVehSpdLgt_VehSpdLgtA_IPDU_COM_CemBodyExpoCommonSignalIPDU04             227u
#define igActvnOfIndcr_ActvnOfIndcrIndcrOutCntr_IPDU_COM_CemBodyExpoSignalIPdu51             228u
#define igActvnOfIndcr_ActvnOfIndcrIndcrOut_IPDU_COM_CemBodyExpoSignalIPdu51             229u
#define igActvnOfIndcr_ActvnOfIndcrIndcrOutChks_IPDU_COM_CemBodyExpoSignalIPdu51             230u
#define igIndcrPat_IndcrPatCmd1WdTiOff_IPDU_COM_CemBodyExpoSignalIPdu51             231u
#define igIndcrPat_IndcrPatCmd1WdTiOn_IPDU_COM_CemBodyExpoSignalIPdu51             232u
#define igTrafficSignForADB2_TrafficSignForADB2AdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu11             233u
#define igTrafficSignForADB2_TrafficSignForADB2AdbDetdQly_IPDU_COM_CemBodyExpoCommonSignalIPdu11             234u
#define igTrafficSignForADB2_TrafficSignForADB2AdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu11             235u
#define igTrafficSignForADB2_TrafficSignForADB2AdbVertAgBot_IPDU_COM_CemBodyExpoCommonSignalIPdu11             236u
#define igTrafficSignForADB2_TrafficSignForADB2AdbHozlAgLe_IPDU_COM_CemBodyExpoCommonSignalIPdu11             237u
#define igTrafficSignForADB2_TrafficSignForADB2AdbHozlAgRi_IPDU_COM_CemBodyExpoCommonSignalIPdu11             238u
#define igTrafficSignForADB2_TrafficSignForADB2AdbVertAgTop_IPDU_COM_CemBodyExpoCommonSignalIPdu11             239u
#define igVehObjforAHB_VehObjforAHBAdbObjDir_IPDU_COM_CemBodyExpoCommonSignalIPdu12             240u
#define igVehObjforAHB_VehObjforAHBAdbDetdQly_IPDU_COM_CemBodyExpoCommonSignalIPdu12             241u
#define igVehObjforAHB_VehObjforAHBAdbClassn_IPDU_COM_CemBodyExpoCommonSignalIPdu12             242u
#define igVehObjforAHB_VehObjforAHBAdbClassnQly_IPDU_COM_CemBodyExpoCommonSignalIPdu12             243u
#define igVehObjforAHB_VehObjforAHBAdbAbsDist_IPDU_COM_CemBodyExpoCommonSignalIPdu12             244u
#define igVehObjforAHB_VehObjforAHBAdbTrkInfo_IPDU_COM_CemBodyExpoCommonSignalIPdu12             245u
#define igVehObjforAHB_VehObjforAHBAdbObjVertAgSpd_IPDU_COM_CemBodyExpoCommonSignalIPdu12             246u
#define igVehObjforAHB_VehObjforAHBAdbObjHozlAgSpd_IPDU_COM_CemBodyExpoCommonSignalIPdu12             247u
#define igVehObjforAHB_VehObjforAHBAdbVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu12             248u
#define igVehObjforAHB_VehObjforAHBAdbHozlAg_IPDU_COM_CemBodyExpoCommonSignalIPdu12             249u
#define igBrkPedlVal_BrkPedlValBrkPedlVal_IPDU_COM_CemBodyExpoSignalIPdu45             250u
#define igBrkPedlVal_BrkPedlValQf_IPDU_COM_CemBodyExpoSignalIPdu45             251u
#define igWipgInfo_WipgInfoWiprActv_IPDU_COM_CemBodyExpoSignalIPdu45             252u
#define igWipgInfo_WipgInfoWiprInWipgAr_IPDU_COM_CemBodyExpoSignalIPdu45             253u
#define igWipgInfo_WipgInfoWipgSpdInfo_IPDU_COM_CemBodyExpoSignalIPdu45             254u
#define igActnOfLedLoBeam_ActnOfLedLoBeamActnOfLedLoBeam_IPDU_COM_CemBodyExpoSignalIPdu50             255u
#define igActnOfLedLoBeam_ActnOfLedLoBeamChks_IPDU_COM_CemBodyExpoSignalIPdu50             256u
#define igActnOfLedLoBeam_ActnOfLedLoBeamCntr_IPDU_COM_CemBodyExpoSignalIPdu50             257u
#define igSuspPosnVertAg_SuspPosnVertAgSuspPosnVertAg_IPDU_COM_CemBodyExpoCommonSignalIPdu22             258u
#define igSuspPosnVertAg_SuspPosnVertAgGenQf_IPDU_COM_CemBodyExpoCommonSignalIPdu22             259u
#define igSuspPosnVertLvl_SuspPosnVertLvlReQf_IPDU_COM_CemBodyExpoCommonSignalIPdu22             260u
#define igSuspPosnVertLvl_SuspPosnVertLvlRe_IPDU_COM_CemBodyExpoCommonSignalIPdu22             261u
#define igSuspPosnVertLvl_SuspPosnVertLvlFrnt_IPDU_COM_CemBodyExpoCommonSignalIPdu22             262u
#define igSuspPosnVertLvl_SuspPosnVertLvlFrntQf_IPDU_COM_CemBodyExpoCommonSignalIPdu22             263u
#define igDwnLoadDynLitPrmLedLeGrilleLamp_DwnLoadDynLitPrmLedLeGrilleLampOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu60             264u
#define igDwnLoadDynLitPrmLedLeGrilleLamp_DwnLoadDynLitPrmLedLeGrilleLampTistamp_IPDU_COM_CemBodyExpoSignalIPdu60             265u
#define igDwnLoadDynLitPrmLedLeGrilleLamp_DwnLoadDynLitPrmLedLeGrilleLampLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu60             266u
#define igDwnLoadDynLitPrmLedLeGrilleLamp_DwnLoadDynLitPrmLedLeGrilleLampModePrm_IPDU_COM_CemBodyExpoSignalIPdu60             267u
#define igDwnLoadDynLitPrmLedLeGrilleLamp_DwnLoadDynLitPrmLedLeGrilleLampUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu60             268u
#define igDwnLoadDynLitPrmLedLeGrilleLamp_DwnLoadDynLitPrmLedLeGrilleLampContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu60             269u
#define igDwnLoadDynLitPrmLedLeSideLogoLi_DwnLoadDynLitPrmLedLeSideLogoLiModePrm_IPDU_COM_CemBodyExpoSignalIPdu65             270u
#define igDwnLoadDynLitPrmLedLeSideLogoLi_DwnLoadDynLitPrmLedLeSideLogoLiLowBriPrm_IPDU_COM_CemBodyExpoSignalIPdu65             271u
#define igDwnLoadDynLitPrmLedLeSideLogoLi_DwnLoadDynLitPrmLedLeSideLogoLiUpprBriPrm_IPDU_COM_CemBodyExpoSignalIPdu65             272u
#define igDwnLoadDynLitPrmLedLeSideLogoLi_DwnLoadDynLitPrmLedLeSideLogoLiTistamp_IPDU_COM_CemBodyExpoSignalIPdu65             273u
#define igDwnLoadDynLitPrmLedLeSideLogoLi_DwnLoadDynLitPrmLedLeSideLogoLiContTiPrm_IPDU_COM_CemBodyExpoSignalIPdu65             274u
#define igDwnLoadDynLitPrmLedLeSideLogoLi_DwnLoadDynLitPrmLedLeSideLogoLiOffsTiPrm_IPDU_COM_CemBodyExpoSignalIPdu65             275u
#define igDwnLoadDynLtgPrmForFrntLeGrp1_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu67             276u
#define igDwnLoadDynLtgPrmForFrntLeGrp1_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu67             277u
#define igDwnLoadDynLtgPrmForFrntLeGrp1_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu67             278u
#define igDwnLoadDynLtgPrmForFrntLeGrp1_DwnLoadDynLtgPrmForFrntLeGrp1Mode1_IPDU_COM_CemBodyExpoSignalIPdu67             279u
#define igDwnLoadDynLtgPrmForFrntLeGrp1_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp_IPDU_COM_CemBodyExpoSignalIPdu67             280u
#define igDwnLoadDynLtgPrmForFrntLeGrp1_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu67             281u
#define igDwnLoadDynLtgPrmForFrntLeGrp2_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp_IPDU_COM_CemBodyExpoSignalIPdu68             282u
#define igDwnLoadDynLtgPrmForFrntLeGrp2_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu68             283u
#define igDwnLoadDynLtgPrmForFrntLeGrp2_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu68             284u
#define igDwnLoadDynLtgPrmForFrntLeGrp2_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu68             285u
#define igDwnLoadDynLtgPrmForFrntLeGrp2_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu68             286u
#define igDwnLoadDynLtgPrmForFrntLeGrp2_DwnLoadDynLtgPrmForFrntLeGrp2Mode1_IPDU_COM_CemBodyExpoSignalIPdu68             287u
#define igDwnLoadDynLtgPrmForFrntLeGrp3_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp_IPDU_COM_CemBodyExpoSignalIPdu69             288u
#define igDwnLoadDynLtgPrmForFrntLeGrp3_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu69             289u
#define igDwnLoadDynLtgPrmForFrntLeGrp3_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu69             290u
#define igDwnLoadDynLtgPrmForFrntLeGrp3_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu69             291u
#define igDwnLoadDynLtgPrmForFrntLeGrp3_DwnLoadDynLtgPrmForFrntLeGrp3Mode1_IPDU_COM_CemBodyExpoSignalIPdu69             292u
#define igDwnLoadDynLtgPrmForFrntLeGrp3_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu69             293u
#define igDwnLoadDynLtgPrmForFrntLeGrp4_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu70             294u
#define igDwnLoadDynLtgPrmForFrntLeGrp4_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu70             295u
#define igDwnLoadDynLtgPrmForFrntLeGrp4_DwnLoadDynLtgPrmForFrntLeGrp4Mode1_IPDU_COM_CemBodyExpoSignalIPdu70             296u
#define igDwnLoadDynLtgPrmForFrntLeGrp4_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu70             297u
#define igDwnLoadDynLtgPrmForFrntLeGrp4_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp_IPDU_COM_CemBodyExpoSignalIPdu70             298u
#define igDwnLoadDynLtgPrmForFrntLeGrp4_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu70             299u
#define igDwnLoadDynLtgPrmForFrntLeGrp5_DwnLoadDynLtgPrmForFrntLeGrp5Mode1_IPDU_COM_CemBodyExpoSignalIPdu71             300u
#define igDwnLoadDynLtgPrmForFrntLeGrp5_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu71             301u
#define igDwnLoadDynLtgPrmForFrntLeGrp5_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu71             302u
#define igDwnLoadDynLtgPrmForFrntLeGrp5_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp_IPDU_COM_CemBodyExpoSignalIPdu71             303u
#define igDwnLoadDynLtgPrmForFrntLeGrp5_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu71             304u
#define igDwnLoadDynLtgPrmForFrntLeGrp5_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu71             305u
#define igDwnLoadDynLtgPrmForFrntLeGrp6_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp_IPDU_COM_CemBodyExpoSignalIPdu72             306u
#define igDwnLoadDynLtgPrmForFrntLeGrp6_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu72             307u
#define igDwnLoadDynLtgPrmForFrntLeGrp6_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu72             308u
#define igDwnLoadDynLtgPrmForFrntLeGrp6_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu72             309u
#define igDwnLoadDynLtgPrmForFrntLeGrp6_DwnLoadDynLtgPrmForFrntLeGrp6Mode1_IPDU_COM_CemBodyExpoSignalIPdu72             310u
#define igDwnLoadDynLtgPrmForFrntLeGrp6_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu72             311u
#define igDwnLoadDynLtgPrmForFrntLeGrp7_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu73             312u
#define igDwnLoadDynLtgPrmForFrntLeGrp7_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp_IPDU_COM_CemBodyExpoSignalIPdu73             313u
#define igDwnLoadDynLtgPrmForFrntLeGrp7_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu73             314u
#define igDwnLoadDynLtgPrmForFrntLeGrp7_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu73             315u
#define igDwnLoadDynLtgPrmForFrntLeGrp7_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu73             316u
#define igDwnLoadDynLtgPrmForFrntLeGrp7_DwnLoadDynLtgPrmForFrntLeGrp7Mode1_IPDU_COM_CemBodyExpoSignalIPdu73             317u
#define igDwnLoadDynLtgPrmForFrntLeGrp8_DwnLoadDynLtgPrmForFrntLeGrp8Mode1_IPDU_COM_CemBodyExpoSignalIPdu74             318u
#define igDwnLoadDynLtgPrmForFrntLeGrp8_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu74             319u
#define igDwnLoadDynLtgPrmForFrntLeGrp8_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu74             320u
#define igDwnLoadDynLtgPrmForFrntLeGrp8_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp_IPDU_COM_CemBodyExpoSignalIPdu74             321u
#define igDwnLoadDynLtgPrmForFrntLeGrp8_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu74             322u
#define igDwnLoadDynLtgPrmForFrntLeGrp8_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu74             323u
#define igDwnLoadDynLtgPrmForFrntLeGrp9_DwnLoadDynLtgPrmForFrntLeGrp9Mode1_IPDU_COM_CemBodyExpoSignalIPdu75             324u
#define igDwnLoadDynLtgPrmForFrntLeGrp9_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu75             325u
#define igDwnLoadDynLtgPrmForFrntLeGrp9_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu75             326u
#define igDwnLoadDynLtgPrmForFrntLeGrp9_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu75             327u
#define igDwnLoadDynLtgPrmForFrntLeGrp9_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu75             328u
#define igDwnLoadDynLtgPrmForFrntLeGrp9_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp_IPDU_COM_CemBodyExpoSignalIPdu75             329u
#define igDwnLoadDynLtgPrmForFrntLeGrp10_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp_IPDU_COM_CemBodyExpoSignalIPdu76             330u
#define igDwnLoadDynLtgPrmForFrntLeGrp10_DwnLoadDynLtgPrmForFrntLeGrp10Mode1_IPDU_COM_CemBodyExpoSignalIPdu76             331u
#define igDwnLoadDynLtgPrmForFrntLeGrp10_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu76             332u
#define igDwnLoadDynLtgPrmForFrntLeGrp10_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu76             333u
#define igDwnLoadDynLtgPrmForFrntLeGrp10_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu76             334u
#define igDwnLoadDynLtgPrmForFrntLeGrp10_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu76             335u
#define igDwnLoadDynLtgPrmForFrntLeGrp11_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu77             336u
#define igDwnLoadDynLtgPrmForFrntLeGrp11_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu77             337u
#define igDwnLoadDynLtgPrmForFrntLeGrp11_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp_IPDU_COM_CemBodyExpoSignalIPdu77             338u
#define igDwnLoadDynLtgPrmForFrntLeGrp11_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu77             339u
#define igDwnLoadDynLtgPrmForFrntLeGrp11_DwnLoadDynLtgPrmForFrntLeGrp11Mode1_IPDU_COM_CemBodyExpoSignalIPdu77             340u
#define igDwnLoadDynLtgPrmForFrntLeGrp11_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu77             341u
#define igDwnLoadDynLtgPrmForFrntLeGrp12_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp_IPDU_COM_CemBodyExpoSignalIPdu78             342u
#define igDwnLoadDynLtgPrmForFrntLeGrp12_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu78             343u
#define igDwnLoadDynLtgPrmForFrntLeGrp12_DwnLoadDynLtgPrmForFrntLeGrp12Mode1_IPDU_COM_CemBodyExpoSignalIPdu78             344u
#define igDwnLoadDynLtgPrmForFrntLeGrp12_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu78             345u
#define igDwnLoadDynLtgPrmForFrntLeGrp12_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu78             346u
#define igDwnLoadDynLtgPrmForFrntLeGrp12_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu78             347u
#define igDwnLoadDynLtgPrmForFrntLeGrp13_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu79             348u
#define igDwnLoadDynLtgPrmForFrntLeGrp13_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp_IPDU_COM_CemBodyExpoSignalIPdu79             349u
#define igDwnLoadDynLtgPrmForFrntLeGrp13_DwnLoadDynLtgPrmForFrntLeGrp13Mode1_IPDU_COM_CemBodyExpoSignalIPdu79             350u
#define igDwnLoadDynLtgPrmForFrntLeGrp13_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu79             351u
#define igDwnLoadDynLtgPrmForFrntLeGrp13_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu79             352u
#define igDwnLoadDynLtgPrmForFrntLeGrp13_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu79             353u
#define igDwnLoadDynLtgPrmForFrntLeGrp15_DwnLoadDynLtgPrmForFrntLeGrp15Mode1_IPDU_COM_CemBodyExpoSignalIPdu81             354u
#define igDwnLoadDynLtgPrmForFrntLeGrp15_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu81             355u
#define igDwnLoadDynLtgPrmForFrntLeGrp15_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp_IPDU_COM_CemBodyExpoSignalIPdu81             356u
#define igDwnLoadDynLtgPrmForFrntLeGrp15_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu81             357u
#define igDwnLoadDynLtgPrmForFrntLeGrp15_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu81             358u
#define igDwnLoadDynLtgPrmForFrntLeGrp15_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu81             359u
#define igDwnLoadDynLtgPrmForFrntLeGrp14_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp_IPDU_COM_CemBodyExpoSignalIPdu80             360u
#define igDwnLoadDynLtgPrmForFrntLeGrp14_DwnLoadDynLtgPrmForFrntLeGrp14Mode1_IPDU_COM_CemBodyExpoSignalIPdu80             361u
#define igDwnLoadDynLtgPrmForFrntLeGrp14_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu80             362u
#define igDwnLoadDynLtgPrmForFrntLeGrp14_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu80             363u
#define igDwnLoadDynLtgPrmForFrntLeGrp14_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu80             364u
#define igDwnLoadDynLtgPrmForFrntLeGrp14_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu80             365u
#define igDwnLoadDynLtgPrmForFrntLeGrp16_DwnLoadDynLtgPrmForFrntLeGrp16Mode1_IPDU_COM_CemBodyExpoSignalIPdu82             366u
#define igDwnLoadDynLtgPrmForFrntLeGrp16_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu82             367u
#define igDwnLoadDynLtgPrmForFrntLeGrp16_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu82             368u
#define igDwnLoadDynLtgPrmForFrntLeGrp16_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp_IPDU_COM_CemBodyExpoSignalIPdu82             369u
#define igDwnLoadDynLtgPrmForFrntLeGrp16_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu82             370u
#define igDwnLoadDynLtgPrmForFrntLeGrp16_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu82             371u
#define igDwnLoadDynLtgPrmForFrntLeGrp17_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu83             372u
#define igDwnLoadDynLtgPrmForFrntLeGrp17_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu83             373u
#define igDwnLoadDynLtgPrmForFrntLeGrp17_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp_IPDU_COM_CemBodyExpoSignalIPdu83             374u
#define igDwnLoadDynLtgPrmForFrntLeGrp17_DwnLoadDynLtgPrmForFrntLeGrp17Mode1_IPDU_COM_CemBodyExpoSignalIPdu83             375u
#define igDwnLoadDynLtgPrmForFrntLeGrp17_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu83             376u
#define igDwnLoadDynLtgPrmForFrntLeGrp17_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu83             377u
#define igDwnLoadDynLtgPrmForFrntLeGrp18_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu84             378u
#define igDwnLoadDynLtgPrmForFrntLeGrp18_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu84             379u
#define igDwnLoadDynLtgPrmForFrntLeGrp18_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu84             380u
#define igDwnLoadDynLtgPrmForFrntLeGrp18_DwnLoadDynLtgPrmForFrntLeGrp18Mode1_IPDU_COM_CemBodyExpoSignalIPdu84             381u
#define igDwnLoadDynLtgPrmForFrntLeGrp18_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu84             382u
#define igDwnLoadDynLtgPrmForFrntLeGrp18_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp_IPDU_COM_CemBodyExpoSignalIPdu84             383u
#define igDwnLoadDynLtgPrmForFrntLeGrp19_DwnLoadDynLtgPrmForFrntLeGrp19Mode1_IPDU_COM_CemBodyExpoSignalIPdu85             384u
#define igDwnLoadDynLtgPrmForFrntLeGrp19_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu85             385u
#define igDwnLoadDynLtgPrmForFrntLeGrp19_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu85             386u
#define igDwnLoadDynLtgPrmForFrntLeGrp19_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu85             387u
#define igDwnLoadDynLtgPrmForFrntLeGrp19_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp_IPDU_COM_CemBodyExpoSignalIPdu85             388u
#define igDwnLoadDynLtgPrmForFrntLeGrp19_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu85             389u
#define igDwnLoadDynLtgPrmForFrntLeGrp20_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu86             390u
#define igDwnLoadDynLtgPrmForFrntLeGrp20_DwnLoadDynLtgPrmForFrntLeGrp20Mode1_IPDU_COM_CemBodyExpoSignalIPdu86             391u
#define igDwnLoadDynLtgPrmForFrntLeGrp20_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu86             392u
#define igDwnLoadDynLtgPrmForFrntLeGrp20_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu86             393u
#define igDwnLoadDynLtgPrmForFrntLeGrp20_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp_IPDU_COM_CemBodyExpoSignalIPdu86             394u
#define igDwnLoadDynLtgPrmForFrntLeGrp20_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu86             395u
#define igDwnLoadDynLtgPrmForFrntLeGrp21_DwnLoadDynLtgPrmForFrntLeGrp21Mode1_IPDU_COM_CemBodyExpoSignalIPdu87             396u
#define igDwnLoadDynLtgPrmForFrntLeGrp21_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu87             397u
#define igDwnLoadDynLtgPrmForFrntLeGrp21_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu87             398u
#define igDwnLoadDynLtgPrmForFrntLeGrp21_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu87             399u
#define igDwnLoadDynLtgPrmForFrntLeGrp21_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp_IPDU_COM_CemBodyExpoSignalIPdu87             400u
#define igDwnLoadDynLtgPrmForFrntLeGrp21_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu87             401u
#define igDwnLoadDynLtgPrmForFrntLeGrp22_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu88             402u
#define igDwnLoadDynLtgPrmForFrntLeGrp22_DwnLoadDynLtgPrmForFrntLeGrp22Mode1_IPDU_COM_CemBodyExpoSignalIPdu88             403u
#define igDwnLoadDynLtgPrmForFrntLeGrp22_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu88             404u
#define igDwnLoadDynLtgPrmForFrntLeGrp22_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp_IPDU_COM_CemBodyExpoSignalIPdu88             405u
#define igDwnLoadDynLtgPrmForFrntLeGrp22_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu88             406u
#define igDwnLoadDynLtgPrmForFrntLeGrp22_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu88             407u
#define igDwnLoadDynLtgPrmForFrntLeGrp23_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp_IPDU_COM_CemBodyExpoSignalIPdu89             408u
#define igDwnLoadDynLtgPrmForFrntLeGrp23_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu89             409u
#define igDwnLoadDynLtgPrmForFrntLeGrp23_DwnLoadDynLtgPrmForFrntLeGrp23Mode1_IPDU_COM_CemBodyExpoSignalIPdu89             410u
#define igDwnLoadDynLtgPrmForFrntLeGrp23_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu89             411u
#define igDwnLoadDynLtgPrmForFrntLeGrp23_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu89             412u
#define igDwnLoadDynLtgPrmForFrntLeGrp23_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu89             413u
#define igDwnLoadDynLtgPrmForFrntLeGrp24_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness_IPDU_COM_CemBodyExpoSignalIPdu90             414u
#define igDwnLoadDynLtgPrmForFrntLeGrp24_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime_IPDU_COM_CemBodyExpoSignalIPdu90             415u
#define igDwnLoadDynLtgPrmForFrntLeGrp24_DwnLoadDynLtgPrmForFrntLeGrp24Mode1_IPDU_COM_CemBodyExpoSignalIPdu90             416u
#define igDwnLoadDynLtgPrmForFrntLeGrp24_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp_IPDU_COM_CemBodyExpoSignalIPdu90             417u
#define igDwnLoadDynLtgPrmForFrntLeGrp24_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness_IPDU_COM_CemBodyExpoSignalIPdu90             418u
#define igDwnLoadDynLtgPrmForFrntLeGrp24_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime_IPDU_COM_CemBodyExpoSignalIPdu90             419u
#define igTiAndDateIndcn_TiAndDateIndcnDay_IPDU_COM_CemBodyExpoSignalIPdu116             420u
#define igTiAndDateIndcn_TiAndDateIndcnYr1_IPDU_COM_CemBodyExpoSignalIPdu116             421u
#define igTiAndDateIndcn_TiAndDateIndcnMins1_IPDU_COM_CemBodyExpoSignalIPdu116             422u
#define igTiAndDateIndcn_TiAndDateIndcnMth1_IPDU_COM_CemBodyExpoSignalIPdu116             423u
#define igTiAndDateIndcn_TiAndDateIndcnHr1_IPDU_COM_CemBodyExpoSignalIPdu116             424u
#define igTiAndDateIndcn_TiAndDateIndcnSec1_IPDU_COM_CemBodyExpoSignalIPdu116             425u
#define igTiAndDateIndcn_TiAndDateIndcnDataValid_IPDU_COM_CemBodyExpoSignalIPdu116             426u
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

