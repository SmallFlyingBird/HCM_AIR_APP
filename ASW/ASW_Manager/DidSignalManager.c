
// /*
//  * DidSignalManager.c
//  *
//  *  Created on: 2024.04.15
//  *      Author: mihuiliang
//  */
// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "DidSignalManager.h"
// #include "AswInterfaceManager.h"
// #include "Fan.h"
// #include "SystemService_Interface.h"

// /****************************************************************
//  *                                                              *
//  *                  Private Variable Define                     *
//  *                                                              *
//  ****************************************************************/

// /****************************************************************
//  *                                                              *
//  *                   Global Variable Define                     *
//  *                                                              *
//  ****************************************************************/
// const uint16_t ChannelDidSigBaseID[MAX_CHANNLE_NUM] = {
//     DIDSIGNALNAME_ID_CH1OutputLuminosity,
//     DIDSIGNALNAME_ID_CH2OutputLuminosity,
//     DIDSIGNALNAME_ID_CH3OutputLuminosity,
//     DIDSIGNALNAME_ID_CH4OutputLuminosity,
//     DIDSIGNALNAME_ID_CH5OutputLuminosity,
//     DIDSIGNALNAME_ID_CH6OutputLuminosity,
//     DIDSIGNALNAME_ID_CH7OutputLuminosity,
//     DIDSIGNALNAME_ID_CH8OutputLuminosity,
//     DIDSIGNALNAME_ID_CH9OutputLuminosity,
//     DIDSIGNALNAME_ID_CH10OutputLuminosity,
//     DIDSIGNALNAME_ID_CH11OutputLuminosity,
//     DIDSIGNALNAME_ID_CH12OutputLuminosity,
// };

// S_DID43A8PeakData gs_DID43A8PeakDataCurr =
// {
//     .PeakCurCh1     = 0xFFFu,
//     .PeakCurCh2     = 0xFFFu,
//     .PeakCurCh3     = 0xFFFu,
//     .PeakCurCh4     = 0xFFFu,
//     .PeakCurCh5     = 0xFFFu,
//     .PeakCurCh6     = 0xFFFu,
//     .PeakCurCh7     = 0xFFFu,
//     .PeakCurCh8     = 0xFFFu,
//     .PeakTempRes1   = 0xFFu,
//     .PeakTempRes2   = 0xFFu,
//     .PeakTempRes3   = 0xFFu,
//     .PeakTempRes4   = 0xFFu,
//     .PeakTempRes5   = 0xFFu,
//     .PeakTempCtrMod = 0xFFu,
//     .PeakCurCh9     = 0xFFFu,
//     .PeakCurCh10    = 0xFFFu,
//     .PeakCurCh11    = 0xFFFu,
//     .PeakCurCh12    = 0xFFFu,
// };

// static S_DID43A8TotalData gs_DID43A8TotalDataCurr =
// {
//     .TotalRunTimeCh1     = 0xFFFFFFFFu,
//     .TotalRunTimeCh2     = 0xFFFFFFFFu,
//     .TotalRunTimeCh3     = 0xFFFFFFFFu,
//     .TotalRunTimeCh4     = 0xFFFFFFFFu,
//     .TotalRunTimeCh5     = 0xFFFFFFFFu,
//     .TotalRunTimeCh6     = 0xFFFFFFFFu,
//     .TotalRunTimeCh7     = 0xFFFFFFFFu,
//     .TotalRunTimeCh8     = 0xFFFFFFFFu,
//     .TotalNumLedDera     = 0xFFFFFFFFu,
//     .TotalNumFanStart    = 0xFFFFFFFFu,
//     .TotalNumFanStartDei = 0xFFFFFFFFu,
//     .TotalNumFanStartDef = 0xFFFFFFFFu,
//     .TotalRunTimeFan     = 0xFFFFFFFFu,
//     .TotalNumLvlStep     = 0xFFFFFFFFu,
//     .TotalNumSwlStep     = 0xFFFFFFFFu,
//     .TotalRunTimeCh9     = 0xFFFFFFFFu,
//     .TotalRunTimeCh10    = 0xFFFFFFFFu,
//     .TotalRunTimeCh11    = 0xFFFFFFFFu,
//     .TotalRunTimeCh12    = 0xFFFFFFFFu,
// };

// static S_DID43A8TotalData gs_DID43A8TotalDataClean = {0u};

// /****************************************************************
//  *                                                              *
//  *                   Private Functions Define                   *
//  *                                                              *
//  ****************************************************************/
// static Std_ReturnType ChannelDidSigMainFunc(void)
// {
//     Std_ReturnType rtval = E_OK;
//     E_ChannelID chid;
//     uint16_t DidSig_BaseID;
//     uint16_t LfMask;
//     uint32_t Sigdata = 0;
//     double chvoltage;
//     uint16_t readdata;
//     sint16 ntctmp;
//     for (chid = ChannelID1; chid <= ChannelID12; chid++)
//     {
//         DidSig_BaseID = ChannelDidSigBaseID[chid];
//         LfMask = GetLightFunctionsMaskByChNo(chid);
//         if (LfMask == 0)
//         {
//             /*此通道未配置*/

//             /*设置Output Luminosity*/
//             Sigdata = 0;
//             Interface_SetDidSignalData(DidSig_BaseID, Sigdata);

//             /*设置LED Commanded Current*/
//             Sigdata = 4096;
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);

//             /*设置LED Actual Voltage*/
//             Sigdata = 65535;
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);

//             /*设置LED Actual Frequency*/
//             Sigdata = 65535;
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);

//             /*设置LED Function*/
//             Sigdata = 0;
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);

//             /*设置LED Thermal Resistor Temperature*/
//             Sigdata = 255;
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);
//         }
//         else
//         {
//             /*此通道配置*/

//             /*设置Output Luminosity*/
//             Sigdata = (uint32_t)Interface_GetChannelCurPWM(chid);
//             Interface_SetDidSignalData(DidSig_BaseID, Sigdata);

//             /*设置LED Commanded Current*/
//             Sigdata = (uint32_t)Interface_GetChannelCurCurrent(chid);
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);

//             /*设置LED Actual Voltage*/
//             Interface_GetChannelVoltage(chid, &chvoltage);
//             Sigdata = (uint32_t)(chvoltage * 10);
//             Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);

//             /*设置LED Actual Frequency*/
//             Interface_GetChannelFrequency(chid, &readdata);
//             Interface_SetDidSignalData((++DidSig_BaseID), (uint32_t)readdata);

//             /*设置LED Function*/
//             Interface_SetDidSignalData((++DidSig_BaseID), (uint32_t)LfMask);

//             /*设置LED Thermal Resistor Temperature*/
//             readdata = (uint16_t)Get_pLedChToNtc(chid);
//             if (readdata == 0)
//             {
//                 Interface_SetDidSignalData((++DidSig_BaseID), 255);
//             }
//             else
//             {
//                 rtval |= Interface_GetNtcTemperature((E_NtcRcodFunction)readdata, &ntctmp);
//                 if (rtval == E_OK)
//                 {
//                     Sigdata = (uint32_t)(ntctmp + 55);
//                 }
//                 else
//                 {
//                     Sigdata = 254;
//                 }
//                 Interface_SetDidSignalData((++DidSig_BaseID), Sigdata);
//             }
//         }
//     }

//     return rtval;
// }

// static void Did7022Hander(void)
// {
// }

// static void DidSignalManager_SetDID_43A8_StatisticalData(void)
// {
//     static uint8_t s_RunOnceFlag = 1u;
//     static S_DID43A8TotalData ss_DID43A8TotalDataBase = {0u};

//     if(s_RunOnceFlag == 1u || Interface_GetDid43A8WriteFlag() == 1u)
//     {
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh1,       & ss_DID43A8TotalDataBase.TotalRunTimeCh1);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh2,       & ss_DID43A8TotalDataBase.TotalRunTimeCh2);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh3,       & ss_DID43A8TotalDataBase.TotalRunTimeCh3);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh4,       & ss_DID43A8TotalDataBase.TotalRunTimeCh4);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh5,       & ss_DID43A8TotalDataBase.TotalRunTimeCh5);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh6,       & ss_DID43A8TotalDataBase.TotalRunTimeCh6);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh7,       & ss_DID43A8TotalDataBase.TotalRunTimeCh7);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh8,       & ss_DID43A8TotalDataBase.TotalRunTimeCh8);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalNumLedDera,       & ss_DID43A8TotalDataBase.TotalNumLedDera);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalNumFanStart,      & ss_DID43A8TotalDataBase.TotalNumFanStart);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalNumFanStartDeic,  & ss_DID43A8TotalDataBase.TotalNumFanStartDei);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalNumFanStartDefog, & ss_DID43A8TotalDataBase.TotalNumFanStartDef);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeFan,       & ss_DID43A8TotalDataBase.TotalRunTimeFan);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalNumLvlStep,       & ss_DID43A8TotalDataBase.TotalNumLvlStep);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalNumSwlStep,       & ss_DID43A8TotalDataBase.TotalNumSwlStep);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh9,       & ss_DID43A8TotalDataBase.TotalRunTimeCh9);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh10,      & ss_DID43A8TotalDataBase.TotalRunTimeCh10);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh11,      & ss_DID43A8TotalDataBase.TotalRunTimeCh11);
//         Interface_GetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh12,      & ss_DID43A8TotalDataBase.TotalRunTimeCh12);

//         if(Interface_GetDid43A8WriteFlag() == 1u)
//         {
//             gs_DID43A8TotalDataClean.TotalRunTimeCh1     += gs_DID43A8TotalDataCurr.TotalRunTimeCh1     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh1;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh2     += gs_DID43A8TotalDataCurr.TotalRunTimeCh2     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh2;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh3     += gs_DID43A8TotalDataCurr.TotalRunTimeCh3     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh3;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh4     += gs_DID43A8TotalDataCurr.TotalRunTimeCh4     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh4;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh5     += gs_DID43A8TotalDataCurr.TotalRunTimeCh5     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh5;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh6     += gs_DID43A8TotalDataCurr.TotalRunTimeCh6     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh6;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh7     += gs_DID43A8TotalDataCurr.TotalRunTimeCh7     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh7;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh8     += gs_DID43A8TotalDataCurr.TotalRunTimeCh8     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh8;
//             gs_DID43A8TotalDataClean.TotalNumLedDera     += gs_DID43A8TotalDataCurr.TotalNumLedDera     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalNumLedDera;
//             gs_DID43A8TotalDataClean.TotalNumFanStart    += gs_DID43A8TotalDataCurr.TotalNumFanStart    == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalNumFanStart;
//             gs_DID43A8TotalDataClean.TotalNumFanStartDei += gs_DID43A8TotalDataCurr.TotalNumFanStartDei == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalNumFanStartDei;
//             gs_DID43A8TotalDataClean.TotalNumFanStartDef += gs_DID43A8TotalDataCurr.TotalNumFanStartDef == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalNumFanStartDef;
//             gs_DID43A8TotalDataClean.TotalRunTimeFan     += gs_DID43A8TotalDataCurr.TotalRunTimeFan     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeFan;
//             gs_DID43A8TotalDataClean.TotalNumLvlStep     += gs_DID43A8TotalDataCurr.TotalNumLvlStep     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalNumLvlStep;
//             gs_DID43A8TotalDataClean.TotalNumSwlStep     += gs_DID43A8TotalDataCurr.TotalNumSwlStep     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalNumSwlStep;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh9     += gs_DID43A8TotalDataCurr.TotalRunTimeCh9     == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh9;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh10    += gs_DID43A8TotalDataCurr.TotalRunTimeCh10    == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh10;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh11    += gs_DID43A8TotalDataCurr.TotalRunTimeCh11    == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh11;
//             gs_DID43A8TotalDataClean.TotalRunTimeCh12    += gs_DID43A8TotalDataCurr.TotalRunTimeCh12    == 0xFFFFFFFFu ? 0u : gs_DID43A8TotalDataCurr.TotalRunTimeCh12;
//         }

//         Interface_SetDid43A8WriteFlag(0u);
//         s_RunOnceFlag = 0u;
//     }

//     S_DID43A8TotalData as_Value;
    
//     as_Value.TotalRunTimeCh1     = gs_DID43A8TotalDataCurr.TotalRunTimeCh1     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh1     : ss_DID43A8TotalDataBase.TotalRunTimeCh1     + gs_DID43A8TotalDataCurr.TotalRunTimeCh1;
//     as_Value.TotalRunTimeCh2     = gs_DID43A8TotalDataCurr.TotalRunTimeCh2     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh2     : ss_DID43A8TotalDataBase.TotalRunTimeCh2     + gs_DID43A8TotalDataCurr.TotalRunTimeCh2;
//     as_Value.TotalRunTimeCh3     = gs_DID43A8TotalDataCurr.TotalRunTimeCh3     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh3     : ss_DID43A8TotalDataBase.TotalRunTimeCh3     + gs_DID43A8TotalDataCurr.TotalRunTimeCh3;
//     as_Value.TotalRunTimeCh4     = gs_DID43A8TotalDataCurr.TotalRunTimeCh4     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh4     : ss_DID43A8TotalDataBase.TotalRunTimeCh4     + gs_DID43A8TotalDataCurr.TotalRunTimeCh4;
//     as_Value.TotalRunTimeCh5     = gs_DID43A8TotalDataCurr.TotalRunTimeCh5     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh5     : ss_DID43A8TotalDataBase.TotalRunTimeCh5     + gs_DID43A8TotalDataCurr.TotalRunTimeCh5;
//     as_Value.TotalRunTimeCh6     = gs_DID43A8TotalDataCurr.TotalRunTimeCh6     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh6     : ss_DID43A8TotalDataBase.TotalRunTimeCh6     + gs_DID43A8TotalDataCurr.TotalRunTimeCh6;
//     as_Value.TotalRunTimeCh7     = gs_DID43A8TotalDataCurr.TotalRunTimeCh7     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh7     : ss_DID43A8TotalDataBase.TotalRunTimeCh7     + gs_DID43A8TotalDataCurr.TotalRunTimeCh7;
//     as_Value.TotalRunTimeCh8     = gs_DID43A8TotalDataCurr.TotalRunTimeCh8     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh8     : ss_DID43A8TotalDataBase.TotalRunTimeCh8     + gs_DID43A8TotalDataCurr.TotalRunTimeCh8;
//     as_Value.TotalNumLedDera     = gs_DID43A8TotalDataCurr.TotalNumLedDera     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalNumLedDera     : ss_DID43A8TotalDataBase.TotalNumLedDera     + gs_DID43A8TotalDataCurr.TotalNumLedDera;
//     as_Value.TotalNumFanStart    = gs_DID43A8TotalDataCurr.TotalNumFanStart    == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalNumFanStart    : ss_DID43A8TotalDataBase.TotalNumFanStart    + gs_DID43A8TotalDataCurr.TotalNumFanStart;
//     as_Value.TotalNumFanStartDei = gs_DID43A8TotalDataCurr.TotalNumFanStartDei == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalNumFanStartDei : ss_DID43A8TotalDataBase.TotalNumFanStartDei + gs_DID43A8TotalDataCurr.TotalNumFanStartDei;
//     as_Value.TotalNumFanStartDef = gs_DID43A8TotalDataCurr.TotalNumFanStartDef == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalNumFanStartDef : ss_DID43A8TotalDataBase.TotalNumFanStartDef + gs_DID43A8TotalDataCurr.TotalNumFanStartDef;
//     as_Value.TotalRunTimeFan     = gs_DID43A8TotalDataCurr.TotalRunTimeFan     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeFan     : ss_DID43A8TotalDataBase.TotalRunTimeFan     + gs_DID43A8TotalDataCurr.TotalRunTimeFan;
//     as_Value.TotalNumLvlStep     = gs_DID43A8TotalDataCurr.TotalNumLvlStep     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalNumLvlStep     : ss_DID43A8TotalDataBase.TotalNumLvlStep     + gs_DID43A8TotalDataCurr.TotalNumLvlStep;
//     as_Value.TotalNumSwlStep     = gs_DID43A8TotalDataCurr.TotalNumSwlStep     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalNumSwlStep     : ss_DID43A8TotalDataBase.TotalNumSwlStep     + gs_DID43A8TotalDataCurr.TotalNumSwlStep;
//     as_Value.TotalRunTimeCh9     = gs_DID43A8TotalDataCurr.TotalRunTimeCh9     == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh9     : ss_DID43A8TotalDataBase.TotalRunTimeCh9     + gs_DID43A8TotalDataCurr.TotalRunTimeCh9;
//     as_Value.TotalRunTimeCh10    = gs_DID43A8TotalDataCurr.TotalRunTimeCh10    == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh10    : ss_DID43A8TotalDataBase.TotalRunTimeCh10    + gs_DID43A8TotalDataCurr.TotalRunTimeCh10;
//     as_Value.TotalRunTimeCh11    = gs_DID43A8TotalDataCurr.TotalRunTimeCh11    == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh11    : ss_DID43A8TotalDataBase.TotalRunTimeCh11    + gs_DID43A8TotalDataCurr.TotalRunTimeCh11;
//     as_Value.TotalRunTimeCh12    = gs_DID43A8TotalDataCurr.TotalRunTimeCh12    == 0xFFFFFFFFu ? gs_DID43A8TotalDataCurr.TotalRunTimeCh12    : ss_DID43A8TotalDataBase.TotalRunTimeCh12    + gs_DID43A8TotalDataCurr.TotalRunTimeCh12;

//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh1,       as_Value.TotalRunTimeCh1);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh2,       as_Value.TotalRunTimeCh2);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh3,       as_Value.TotalRunTimeCh3);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh4,       as_Value.TotalRunTimeCh4);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh5,       as_Value.TotalRunTimeCh5);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh6,       as_Value.TotalRunTimeCh6);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh7,       as_Value.TotalRunTimeCh7);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh8,       as_Value.TotalRunTimeCh8);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalNumLedDera,       as_Value.TotalNumLedDera);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalNumFanStart,      as_Value.TotalNumFanStart);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalNumFanStartDeic,  as_Value.TotalNumFanStartDei);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalNumFanStartDefog, as_Value.TotalNumFanStartDef);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeFan,       as_Value.TotalRunTimeFan);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalNumLvlStep,       as_Value.TotalNumLvlStep);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalNumSwlStep,       as_Value.TotalNumSwlStep);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh9,       as_Value.TotalRunTimeCh9);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh10,      as_Value.TotalRunTimeCh10);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh11,      as_Value.TotalRunTimeCh11);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_TotalRunTimeCh12,      as_Value.TotalRunTimeCh12);

//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh1,     gs_DID43A8PeakDataCurr.PeakCurCh1);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh2,     gs_DID43A8PeakDataCurr.PeakCurCh2);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh3,     gs_DID43A8PeakDataCurr.PeakCurCh3);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh4,     gs_DID43A8PeakDataCurr.PeakCurCh4);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh5,     gs_DID43A8PeakDataCurr.PeakCurCh5);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh6,     gs_DID43A8PeakDataCurr.PeakCurCh6);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh7,     gs_DID43A8PeakDataCurr.PeakCurCh7);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh8,     gs_DID43A8PeakDataCurr.PeakCurCh8);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakTempRes1,   gs_DID43A8PeakDataCurr.PeakTempRes1);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakTempRes2,   gs_DID43A8PeakDataCurr.PeakTempRes2);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakTempRes3,   gs_DID43A8PeakDataCurr.PeakTempRes3);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakTempRes4,   gs_DID43A8PeakDataCurr.PeakTempRes4);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakTempRes5,   gs_DID43A8PeakDataCurr.PeakTempRes5);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakTempCtrMod, gs_DID43A8PeakDataCurr.PeakTempCtrMod);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh9,     gs_DID43A8PeakDataCurr.PeakCurCh9);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh10,    gs_DID43A8PeakDataCurr.PeakCurCh10);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh11,    gs_DID43A8PeakDataCurr.PeakCurCh11);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_PeakCurCh12,    gs_DID43A8PeakDataCurr.PeakCurCh12);    
// }
// /****************************************************************
//  *                                                              *
//  *                   Global Functions Define                    *
//  *                                                              *
//  ****************************************************************/

// /* 设置DID 43A8信号的值 */
// /* 峰值Peak设置当前最大值；无该配置不设值或设置无效值（无效值参考变量gs_DID43A8PeakDataCurr的初始化值) */
// /* 总计值Total设置此次上电以来的累计值；无该配置不设值或设置无效值（无效值参考变量gs_DID43A8TotalDataCurr的初始化值) */
// void DidSignalManager_SetDid43A8SignalData(uint16_t DidSignalID, uint32_t Value)
// {
//     switch ( DidSignalID )
//     {
//         /* 峰值Peak */
//         case DIDSIGNALNAME_ID_PeakCurCh1:
//             gs_DID43A8PeakDataCurr.PeakCurCh1 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh2:
//             gs_DID43A8PeakDataCurr.PeakCurCh2 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh3:
//             gs_DID43A8PeakDataCurr.PeakCurCh3 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh4:
//             gs_DID43A8PeakDataCurr.PeakCurCh4 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh5:
//             gs_DID43A8PeakDataCurr.PeakCurCh5 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh6:
//             gs_DID43A8PeakDataCurr.PeakCurCh6 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh7:
//             gs_DID43A8PeakDataCurr.PeakCurCh7 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh8:
//             gs_DID43A8PeakDataCurr.PeakCurCh8 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakTempRes1:
//             gs_DID43A8PeakDataCurr.PeakTempRes1 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakTempRes2:
//             gs_DID43A8PeakDataCurr.PeakTempRes2 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakTempRes3:
//             gs_DID43A8PeakDataCurr.PeakTempRes3 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakTempRes4:
//             gs_DID43A8PeakDataCurr.PeakTempRes4 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakTempRes5:
//             gs_DID43A8PeakDataCurr.PeakTempRes5 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakTempCtrMod:
//             gs_DID43A8PeakDataCurr.PeakTempCtrMod = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh9:
//             gs_DID43A8PeakDataCurr.PeakCurCh9 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh10:
//             gs_DID43A8PeakDataCurr.PeakCurCh10 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh11:
//             gs_DID43A8PeakDataCurr.PeakCurCh11 = Value;
//             break;
//         case DIDSIGNALNAME_ID_PeakCurCh12:
//             gs_DID43A8PeakDataCurr.PeakCurCh12 = Value;
//             break;

//         /* 总计值Total */
//         case DIDSIGNALNAME_ID_TotalRunTimeCh1:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh1 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh1;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh2:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh2 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh2;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh3:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh3 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh3;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh4:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh4 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh4;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh5:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh5 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh5;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh6:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh6 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh6;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh7:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh7 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh7;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh8:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh8 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh8;
//             break;
//         case DIDSIGNALNAME_ID_TotalNumLedDera:
//             gs_DID43A8TotalDataCurr.TotalNumLedDera = Value - gs_DID43A8TotalDataClean.TotalNumLedDera;
//             break;
//         case DIDSIGNALNAME_ID_TotalNumFanStart:
//             gs_DID43A8TotalDataCurr.TotalNumFanStart = Value - gs_DID43A8TotalDataClean.TotalNumFanStart;
//             break;
//         case DIDSIGNALNAME_ID_TotalNumFanStartDeic:
//             gs_DID43A8TotalDataCurr.TotalNumFanStartDei = Value - gs_DID43A8TotalDataClean.TotalNumFanStartDei;
//             break;
//         case DIDSIGNALNAME_ID_TotalNumFanStartDefog:
//             gs_DID43A8TotalDataCurr.TotalNumFanStartDef = Value - gs_DID43A8TotalDataClean.TotalNumFanStartDef;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeFan:
//             gs_DID43A8TotalDataCurr.TotalRunTimeFan = Value - gs_DID43A8TotalDataClean.TotalRunTimeFan;
//             break;
//         case DIDSIGNALNAME_ID_TotalNumLvlStep:
//             gs_DID43A8TotalDataCurr.TotalNumLvlStep = Value - gs_DID43A8TotalDataClean.TotalNumLvlStep;
//             break;
//         case DIDSIGNALNAME_ID_TotalNumSwlStep:
//             gs_DID43A8TotalDataCurr.TotalNumSwlStep = Value - gs_DID43A8TotalDataClean.TotalNumSwlStep;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh9:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh9 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh9;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh10:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh10 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh10;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh11:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh11 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh11;
//             break;
//         case DIDSIGNALNAME_ID_TotalRunTimeCh12:
//             gs_DID43A8TotalDataCurr.TotalRunTimeCh12 = Value - gs_DID43A8TotalDataClean.TotalRunTimeCh12;
//     }
// }

// /*Did信号主函数，建议放在100ms任务中*/
// void DidSignalManagerMainFunction(uint8_t timebase)
// {
//     double double_data;
//     uint32_t u32Data;
//     int16_t s16Data;
//     uint16_t LMMSupplyFlag = 0;
//     double MaxVoltage;
//     U_ChannelErrorState ChannelErrorState;
//     /****************************************434B****************************************/
//     Fan_SetDID_434B_Fan();

//     /****************************************4351****************************************/
// #if BOOST_TEMP_USE_NTC
//     if (Interface_GetBoostTemperature(&s16Data) == E_OK)
//     {
//         if (s16Data < -55)
//             s16Data = -55;
//         if (s16Data > 200)
//             s16Data = 200;
//         u32Data = (uint32_t)(s16Data + 55);
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_Temperature, u32Data);
//     }
//     else
//     {
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_Temperature, 0);
//     }
// #endif
//     /****************************************4357****************************************/
//     Interface_GetKL15Voltage(&double_data);
//     u32Data = (uint32_t)(double_data * 10);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_IgnitionRelay, u32Data);

//     Interface_GetKL56Voltage(&double_data);
//     u32Data = (uint32_t)(double_data * 10);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_ExteriorLightRelay, u32Data);

//     /****************************************4358****************************************/
//     // SiderMarkerLamp_SetDID_4358_SML();

//     /****************************************4359 435B-4364 4367****************************************/
//     ChannelDidSigMainFunc();

//     // /****************************************4365****************************************/
//     // if (LevelingMotor_GetLvlCurAngle(&double_data) == E_OK)
//     // {
//     //     /*
//     //      *（DidSignalVal -2046）/100=CurAngle
//     //      * -> DidSignalVal=(CurAngle *100) +2046
//     //      */
//     //     u32Data = double_data * 100 + 2046;
//     // }
//     // else
//     // {
//     //     u32Data = 4095;
//     // }
//     // Interface_SetDidSignalData(DIDSIGNALNAME_ID_LvlSlewingAngle, u32Data);
//     // u32Data = (uint32_t)LevelingMotor_GetLvlRefRunSts();
//     // Interface_SetDidSignalData(DIDSIGNALNAME_ID_LvlStsRefRun, u32Data);

//     /****************************************4366****************************************/
//     // if (SwivelingMotor_GetSvlCurAngle(&double_data) == E_OK)
//     // {
//     //     /*
//     //      *（DidSignalVal -2046）/100=CurAngle
//     //      * -> DidSignalVal=(CurAngle *100) +2046
//     //      */
//     //     u32Data = double_data * 100 + 2046;
//     // }
//     // else
//     // {
//     //     u32Data = 4095;
//     // }
//     // Interface_SetDidSignalData(DIDSIGNALNAME_ID_SwlSlewingAngle, u32Data);
//     // u32Data = (uint32_t)SwivelingMotor_GetSvlRefRunSts();
//     // Interface_SetDidSignalData(DIDSIGNALNAME_ID_SwlStsRefRun, u32Data);

//     /****************************************4368****************************************/
//     // SiderMarkerLamp_SetDID_4368_SMLStatus();
//     // CorneringLight_SetDID_4368_CorneringLightStatus();
//     // FogLamp_SetDID_4368_FogLampStatus();
//     // AHL_SetDID_4368_AHLStatus();
//     // DBL_SetDID_4368_DBLStatus();

//     /****************************************437C****************************************/

//     /****************************************43A8****************************************/
//     DidSignalManager_SetDID_43A8_StatisticalData();

//     /****************************************43A9****************************************/

//     /****************************************43CA****************************************/
//     u32Data = 0x66;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_SideDetShort2VCC, u32Data);
//     u32Data = 0x66;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_SideDetOpen, u32Data);
//     u32Data = 0x55;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_SideDetShort2GND, u32Data);

//     /****************************************43CE****************************************/
//     if (Interface_GetBuckTempterature(E_BuckNo4, &s16Data) == E_OK)
//         u32Data = (uint32_t)(s16Data + 55);
//     else
//         u32Data = 200;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_Buck4Temp, u32Data);

//     /****************************************43CF****************************************/
//     if (Interface_GetBuckTempterature(E_BuckNo1, &s16Data) == E_OK)
//         u32Data = (uint32_t)(s16Data + 55);
//     else
//         u32Data = 200;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_Buck1Temp, u32Data);

//     /****************************************43D0****************************************/
//     if (Interface_GetBuckTempterature(E_BuckNo2, &s16Data) == E_OK)
//         u32Data = (uint32_t)(s16Data + 55);
//     else
//         u32Data = 200;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_Buck2Temp, u32Data);

//     /****************************************43D1****************************************/
//     if (Interface_GetBuckTempterature(E_BuckNo3, &s16Data) == E_OK)
//         u32Data = (uint32_t)(s16Data + 55);
//     else
//         u32Data = 200;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_Buck3Temp, u32Data);

// /****************************************43D2****************************************/
// // #if BOOST_TEMP_USE_NTC
// //     if (Interface_GetBoostTemperature(&s16Data) == E_OK)
// // #else
// //     if (Interface_GetBoostTemperature(E_BoostkNo1, &s16Data) == E_OK)
// // #endif
// //         u32Data = (uint32_t)(s16Data + 55);
// //     else
//         u32Data = 200;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_BoostTemp, u32Data);

//     /****************************************43D3****************************************/
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_LRVol, 255);
//     /****************************************43D4****************************************/
//     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     if (LMMSupplyFlag == 0)
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_HallVol, 0);
//     else
//     {
//         if ((LMMSupplyFlag & (1 << 15)) != 0)
//             Interface_SetDidSignalData(DIDSIGNALNAME_ID_HallVol, 5);
//         else
//         {
//             if (Interface_GetMaxVolBetweenKL15AndKL56(&MaxVoltage) == E_OK)
//                 Interface_SetDidSignalData(DIDSIGNALNAME_ID_HallVol, (uint32_t)(MaxVoltage * 10));
//             else
//                 Interface_SetDidSignalData(DIDSIGNALNAME_ID_HallVol, 255);
//         }
//     }
//     /****************************************43D5****************************************/
//     Fan_SetDID_43D5_FanSupplyVoltage();
//     /****************************************43D7****************************************/
//     for (E_ChannelID index = ChannelID1; index <= ChannelID12; index++)
//     {
//         ChannelErrorState = Interface_GetChannelState(index, E_ErrorType_ErrorDtcState);
//         if (ChannelErrorState.Error == 0)
//             Interface_SetDidSignalData((DIDSIGNALNAME_ID_Ch1DrvErr + index), 0);
//         else
//             Interface_SetDidSignalData((DIDSIGNALNAME_ID_Ch1DrvErr + index), 1);
//     }
//     /****************************************43D8****************************************/
//     /****************************************43D9****************************************/
//     /****************************************43DA****************************************/
//     if (Interface_GetAppLRDection() == DIRECTION_LEFT)
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_AppSideDet, 0x01);
//     else
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_AppSideDet, 0x02);

//     if (Interface_GetBootLRDection() == DIRECTION_LEFT)
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_BootSideDet, 0x01);
//     else
//         Interface_SetDidSignalData(DIDSIGNALNAME_ID_BootSideDet, 0x02);

//     /****************************************7022****************************************/
//     Did7022Hander();

//     /****************************************D134****************************************/
//     Interface_GetSignal_VehModMngtGlbSafe1CarModSts1(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_CarMode, (uint8_t)u32Data);

//     /****************************************D214****************************************/

//     /****************************************DD00****************************************/
//     Interface_GetSignal_CarTiGlb(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GlobalRealTime, u32Data);

//     /****************************************DD01****************************************/
//     Interface_GetSignal_BkpOfDstTrvld(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GlobalTotalDistance, u32Data);

//     /****************************************DD02****************************************/
//     Interface_GetSignal_VehBattUSysU(&u32Data);
//     u32Data = u32Data * 4 / 10;
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_VehBatteryVol, u32Data);

//     /****************************************DD07****************************************/
//     Interface_GetSignal_TiAndDateIndcnYr1(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GNSSUTCTimeYear, u32Data);

//     Interface_GetSignal_TiAndDateIndcnMth1(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GNSSUTCTimeMonth, u32Data);

//     Interface_GetSignal_TiAndDateIndcnDay(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GNSSUTCTimeDay, u32Data);

//     Interface_GetSignal_TiAndDateIndcnHr1(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GNSSUTCTimeHour, u32Data);

//     Interface_GetSignal_TiAndDateIndcnMins1(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GNSSUTCTimeMinute, u32Data);

//     Interface_GetSignal_TiAndDateIndcnSec1(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_GNSSUTCTimeSecond, u32Data);

//     /****************************************DD0A****************************************/
//     Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_UsageMode, u32Data);

//     /****************************************DD0B****************************************/

//     /****************************************DD0C****************************************/
//     Interface_GetSignal_VehModMngtGlbSafe1PwrLvlElecMai(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_ElectricPowerLevel, u32Data);

// #if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
//     /****************************************DD06****************************************/
//     Interface_GetSignal_VehSpdLgtA_CanBusVal(&u32Data);
//     Interface_SetDidSignalData(DIDSIGNALNAME_ID_VehicleSpeed, u32Data);
// #endif
// }



