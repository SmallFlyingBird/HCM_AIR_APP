/*
 * DTC_Interface.c
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Channel_Interface.h"
#include "Dem.h"
#include "Rte_Dcm.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "DtcConfig.h"
#include "List_Interface.h"
#include "ComSignal_Interface.h"
#include "PowerSupply_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
#define NTC_NUM 5
#define MATRIX_NTC_NUM 2
#define MATRIX_BIN_NUM 2
#define BIN_NUM 3
#define SUPPLY_NUM 5
#define FANHSD_NUM 15
#define STEPMOTOR_NUM 13
#define E2E_NUM 11
#define BOOST_BUCK_NUM 2
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
#define SYSTEM_NUM 28
#elif (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
#define SYSTEM_NUM 17
#endif
static U_Boost_Buck_Error gu_BaseLayerSetBoostBuck_Error;

/*底层的实时错误状态*/
static uint8_t ErrorMapValRealTimer[DTC_VALUE_SIZE];
/*Dtc错误状态*/
static uint8_t DtcErrorMapVal[DTC_VALUE_SIZE];

static uint8_t LvlgSwtSetReq_CrcDetect_Flag = 0;
static uint8_t SuspPosnVertLvlFrntOrSuspPosnVertLvlRe_QFDetect_Flag = 0;
static uint8_t SteerWhlSnsr_QFDetect_Flag = 0;
// /****************************************************************
//  *                                                              *
//  *                   Global Variable Define                     *
//  *                                                              *
//  ****************************************************************/
// #if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
// const uint8_t gMap_ChannelShort2GndError[MAX_CHANNLE_NUM] = {73, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116};
// const uint8_t gMap_ChannelShort2VccError[MAX_CHANNLE_NUM] = {74, 77, 81, 85, 89, 93, 97, 101, 105, 109, 113, 117};
// const uint8_t gMap_ChannelOpenError[MAX_CHANNLE_NUM] = {75, 78, 82, 86, 90, 94, 98, 102, 106, 110, 114, 118};
// const uint8_t gMap_ChannelUVError[MAX_CHANNLE_NUM] = {0, 79, 83, 87, 91, 95, 99, 103, 107, 111, 115, 119};

// const uint8_t gMap_NtcShort2GndError[NTC_NUM] = {44, 46, 48, 50, 52};
// const uint8_t gMap_NtcOpenOrShort2Vcc[NTC_NUM] = {45, 47, 49, 51, 53};
// const uint8_t gMap_MatrixNtcError[MATRIX_NTC_NUM] = {55, 54};

// const uint8_t gMap_BinError[BIN_NUM] = {56, 57, 58};
// const uint8_t gMap_MatrixBinError[MATRIX_BIN_NUM] = {133, 134};

// const uint8_t gMap_SupplyVolError[SUPPLY_NUM] = {24, 25, 26, 27, 28};

// const uint8_t gMap_FanAndHsdError[FANHSD_NUM] = {37, 35, 36, 40, 38, 39, 43, 41, 42, 29, 30, 31, 32, 33, 34};

// const uint8_t gMap_StepMotorError[STEPMOTOR_NUM] = {69, 70, 71, 72, 0xFF, 64, 65, 66, 67, 68, 61, 62, 63};

// static List_t gListASWTrigger;
// static ListItem_t gListItem_E2E[E2E_NUM] = {
//     {.xItemValue = 128}, /*E_E2EErrorType_LvlgSwtSetReq_ChksError*/
//     {.xItemValue = 129}, /*E_E2EErrorType_SuspPosnVertLvl_QFError*/
//     {.xItemValue = 130}, /*E_E2EErrorType_SteerWhlSnsr_QFError*/
//     {.xItemValue = 21},  /*E_E2EErrorType_VehSpdLgtSafe_CounterError*/
//     {.xItemValue = 22},  /*E_E2EErrorType_VehSpdLgtSafe_CrcError*/
//     {.xItemValue = 19},  /*E_E2EErrorType_VehModMngtGlbSafe1_CounterError*/
//     {.xItemValue = 20},  /*E_E2EErrorType_VehModMngtGlbSafe1_CrcError*/
//     {.xItemValue = 17},  /*E_E2EErrorType_IndcrOutSafe_CounterError*/
//     {.xItemValue = 18},  /*E_E2EErrorType_IndcrOutSafe_CrcError*/
//     {.xItemValue = 2},   /*E_E2EErrorType_ActnOfLedLoBeam_CounterError*/
//     {.xItemValue = 3},   /*E_E2EErrorType_ActnOfLedLoBeam_CrcError*/
// };

// const uint8_t gMap_BoostBuckError[BOOST_BUCK_NUM] = {120, 122};

// const uint8_t gMap_SystemError[SYSTEM_NUM] = {0xFF, 124, 123, 0xFF, 121, 126, 127, 125, 23, 59, 60, 4, 5, 131, 132, 135, 136, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

// #elif (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
// const uint8_t gMap_ChannelShort2GndError[MAX_CHANNLE_NUM] = {63, 66, 70, 74, 78, 82, 86, 90, 94, 98, 102, 106};
// const uint8_t gMap_ChannelShort2VccError[MAX_CHANNLE_NUM] = {64, 67, 71, 75, 79, 83, 87, 91, 95, 99, 103, 107};
// const uint8_t gMap_ChannelOpenError[MAX_CHANNLE_NUM] = {65, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108};
// const uint8_t gMap_ChannelUVError[MAX_CHANNLE_NUM] = {0, 69, 73, 77, 81, 85, 89, 93, 97, 101, 105, 109};

// const uint8_t gMap_NtcShort2GndError[NTC_NUM] = {34, 36, 38, 40, 42};
// const uint8_t gMap_NtcOpenOrShort2Vcc[NTC_NUM] = {35, 37, 39, 41, 43};
// const uint8_t gMap_MatrixNtcError[MATRIX_NTC_NUM] = {45, 44};

// const uint8_t gMap_BinError[BIN_NUM] = {46, 47, 48};
// const uint8_t gMap_MatrixBinError[MATRIX_BIN_NUM] = {123, 124};

// const uint8_t gMap_SupplyVolError[SUPPLY_NUM] = {14, 15, 16, 17, 18};

// const uint8_t gMap_FanAndHsdError[FANHSD_NUM] = {27, 25, 26, 30, 28, 29, 33, 31, 32, 19, 20, 21, 22, 23, 24};

// const uint8_t gMap_StepMotorError[STEPMOTOR_NUM] = {59, 60, 61, 62, 0xFF, 54, 55, 56, 57, 58, 51, 52, 53};

// static List_t gListASWTrigger;
// static ListItem_t gListItem_E2E[E2E_NUM] = {
//     {.xItemValue = 118}, /*E_E2EErrorType_LvlgSwtSetReq_ChksError*/
//     {.xItemValue = 119}, /*E_E2EErrorType_SuspPosnVertLvl_QFError*/
//     {.xItemValue = 120}, /*E_E2EErrorType_SteerWhlSnsr_QFError*/
//     {.xItemValue = 11},  /*E_E2EErrorType_VehSpdLgtSafe_CounterError*/
//     {.xItemValue = 12},  /*E_E2EErrorType_VehSpdLgtSafe_CrcError*/
//     {.xItemValue = 9},   /*E_E2EErrorType_VehModMngtGlbSafe1_CounterError*/
//     {.xItemValue = 10},  /*E_E2EErrorType_VehModMngtGlbSafe1_CrcError*/
//     {.xItemValue = 7},   /*E_E2EErrorType_IndcrOutSafe_CounterError*/
//     {.xItemValue = 8},   /*E_E2EErrorType_IndcrOutSafe_CrcError*/
//     {.xItemValue = 2},   /*E_E2EErrorType_ActnOfLedLoBeam_CounterError*/
//     {.xItemValue = 3},   /*E_E2EErrorType_ActnOfLedLoBeam_CrcError*/
// };

// const uint8_t gMap_BoostBuckError[BOOST_BUCK_NUM] = {110, 112};

// const uint8_t gMap_SystemError[SYSTEM_NUM] = {6, 114, 113, 0xFF, 111, 116, 117, 115, 13, 49, 50, 4, 5, 121, 122, 125, 126};
// #endif
// /****************************************************************
//  *                                                              *
//  *                   Private Functions Define                   *
//  *                                                              *
//  ****************************************************************/
// static uint8_t GetDtcErrorValRealTimer(const uint8_t DtcIndex)
// {
//     if (DtcIndex >= DTC_MAX_SIZE)
//         return 0;

//     if ((ErrorMapValRealTimer[(DtcIndex >> 3)] & (1 << (DtcIndex & 0x07))) == 0)
//         return 0;
//     else
//         return 1;
// }

// static uint8_t GetDtcErrorVal(const uint8_t DtcIndex)
// {
//     if (DtcIndex >= DTC_MAX_SIZE)
//         return 0;

//     if ((DtcErrorMapVal[(DtcIndex >> 3)] & (1 << (DtcIndex & 0x07))) == 0)
//         return 0;
//     else
//         return 1;
// }

// static Std_ReturnType SetErrorMapValRealTimer(const uint8_t DtcIndex)
// {

//     if (DtcIndex >= DTC_MAX_SIZE)
//         return E_NOT_OK;

//     ErrorMapValRealTimer[(DtcIndex >> 3)] |= (1 << (DtcIndex & 0x07));

//     return E_OK;
// }

// static Std_ReturnType ClearErrorMapValRealTimer(const uint8_t DtcIndex)
// {

//     if (DtcIndex >= DTC_MAX_SIZE)
//         return E_NOT_OK;

//     ErrorMapValRealTimer[(DtcIndex >> 3)] &= ~(1 << (DtcIndex & 0x07));

//     return E_OK;
// }

// static E_DtcTestState DemDtcHander(uint16 EventId, uint8_t val)
// {
//     uint8 Dtc_status = 0;
//     E_DtcTestState rtval = E_DtcState_TestNotComplete;
//     Dem_GetEventStatus(EventId, &Dtc_status);
//     if (val)
//     {

//         if (((Dtc_status & DEM_UDS_STATUS_TF) == DEM_EVENT_STATUS_PASSED) || ((Dtc_status & DEM_UDS_STATUS_TNCTOC) == 0x40) ||
//             (Dem_DebounceStatusHandle(EventId, DEM_EVENT_STATUS_PREFAILED) != E_OK))
//         {
//             Dem_SetEventStatus(EventId, DEM_EVENT_STATUS_PREFAILED);
//             rtval = E_DtcState_TestNotComplete;
//         }
//         else
//         {
//             rtval = E_DtcState_TestFailed;
//         }
//     }
//     else
//     {
//         if (((Dtc_status & DEM_UDS_STATUS_TF) == DEM_EVENT_STATUS_FAILED) || ((Dtc_status & DEM_UDS_STATUS_TNCTOC) == 0x40) ||
//             (Dem_DebounceStatusHandle(EventId, DEM_EVENT_STATUS_PREPASSED) != E_OK))
//         {
//             Dem_SetEventStatus(EventId, DEM_EVENT_STATUS_PREPASSED);
//             rtval = E_DtcState_TestNotComplete;
//         }
//         else
//         {
//             rtval = E_DtcState_TestPassed;
//         }
//     }
//     return rtval;
// }

// static void DtcProcessHander(const S_DtcConfig *DtcConfig)
// {
//     uint8_t index = 0;
//     E_DtcTestState DtcTestState;

//     index = DtcConfig->Index;
//     if ((ErrorMapValRealTimer[(index >> 3)] & (1 << (index & 0x07))) != 0)
//     {
//         DtcTestState = DemDtcHander(DtcConfig->DtcNumber, 1);
//         if (DtcTestState == E_DtcState_TestFailed)
//         {
//             DtcErrorMapVal[(index >> 3)] |= (1 << (index & 0x07));
//         }
//         else if (DtcTestState == E_DtcState_TestNotComplete)
//         {
//             DtcErrorMapVal[(index >> 3)] &= ~(1 << (index & 0x07));
//         }
//     }
//     else
//     {
//         DtcTestState = DemDtcHander(DtcConfig->DtcNumber, 0);
//         if (DtcTestState == E_DtcState_TestPassed)
//         {
//             DtcErrorMapVal[(index >> 3)] &= ~(1 << (index & 0x07));
//         }
//     }
// }

// /*10ms Task*/
// static void DTCEnableConditionHander(void)
// {
//     uint32_t SignalValue;
//     static uint16_t UsageModeTransitionCnt = 510;
//     static uint16_t CarModeTransitionCnt = 510;
//     static uint32_t UsageModeVal = 0;
//     static uint32_t CarModeVal = 0;

//     static uint16_t DTCEnableConditionCnt = 0;
//     E_ChannelState ChannelState;
//     E_HSDChannelSwitchState HSDChannelSwitchState;
//     double tmpvoltage, maxvoltage;
// #if 0
//     uint8_t i = 0;
//     for (i = 0; i < DEM_ENABLE_CONDITION_NUM; i++)
//     {
//         Dem_SetEnableCondition(i, TRUE);
//     }
// #else
//     DTCEnableConditionCnt++;
//     if (DTCEnableConditionCnt >= 510)
//     {
//         DTCEnableConditionCnt = 510;
//     }

//     Interface_GetSignal_VehModMngtGlbSafe1PwrLvlElecMai(&SignalValue);
//     if (SignalValue == 1)
//     {
//         Dem_SetEnableCondition(Condition_ElectricalPower_Limited_ID, FALSE);
//         Dem_SetEnableCondition(Condition_EIPowerLevel_1_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_ElectricalPower_Limited_ID, TRUE);
//         Dem_SetEnableCondition(Condition_EIPowerLevel_1_ID, TRUE);
//     }

//     if (DTCEnableConditionCnt < 510)
//     {
//         Dem_SetEnableCondition(Condition_UsageModeTransition_ID, FALSE);
//         Dem_SetEnableCondition(Condition_CarModeTransition_ID, FALSE);
//         Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&UsageModeVal);
//         Interface_GetSignal_VehModMngtGlbSafe1CarModSts1(&CarModeVal);
//     }
//     else
//     {
//         Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&SignalValue);
//         if (SignalValue != UsageModeVal)
//         {
//             UsageModeTransitionCnt = 0;
//             UsageModeVal = SignalValue;
//         }
//         UsageModeTransitionCnt++;
//         if (UsageModeTransitionCnt >= 510)
//         {
//             UsageModeTransitionCnt = 510;
//             Dem_SetEnableCondition(Condition_UsageModeTransition_ID, TRUE);
//         }
//         else
//         {
//             Dem_SetEnableCondition(Condition_UsageModeTransition_ID, FALSE);
//         }

//         Interface_GetSignal_VehModMngtGlbSafe1CarModSts1(&SignalValue);
//         if (SignalValue != CarModeVal)
//         {
//             CarModeTransitionCnt = 0;
//             CarModeVal = SignalValue;
//         }
//         CarModeTransitionCnt++;
//         if (CarModeTransitionCnt >= 510)
//         {
//             CarModeTransitionCnt = 510;
//             Dem_SetEnableCondition(Condition_CarModeTransition_ID, TRUE);
//         }
//         else
//         {
//             Dem_SetEnableCondition(Condition_CarModeTransition_ID, FALSE);
//         }
//     }

//     if ((E_CarModSts)CarModeVal == E_CarModSts_CarModFcy || (E_CarModSts)CarModeVal == E_CarModSts_CarModTrnsp ||
//         (E_CarModSts)CarModeVal == E_CarModSts_CarModCrash)
//     {
//         Dem_SetEnableCondition(Condition_CarModes_ID, FALSE);
//     }
//     else if ((E_CarModSts)CarModeVal == E_CarModSts_CarModNorm || (E_CarModSts)CarModeVal == E_CarModSts_CarModDyno)
//     {
//         Dem_SetEnableCondition(Condition_CarModes_ID, TRUE);
//     }
//     else
//     {
//         /*信号未定义*/
//         Dem_SetEnableCondition(Condition_CarModes_ID, FALSE);
//     }

//     if ((E_UsageModeSts)UsageModeVal == E_UsageModeSts_Drvg)
//     {
//         Dem_SetEnableCondition(Condition_Usage_Active_Driving_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Usgmod_Driving_ID, TRUE);
//     }
//     else if ((E_UsageModeSts)UsageModeVal == E_UsageModeSts_Actv)
//     {
//         Dem_SetEnableCondition(Condition_Usage_Active_Driving_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Usgmod_Driving_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Usage_Active_Driving_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Usgmod_Driving_ID, FALSE);
//     }

//     Interface_GetChannelSwitchState(ChannelID1, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_1_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_1_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_1_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_1_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID2, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_2_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_2_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_2_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_2_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID3, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_3_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_3_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_3_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_3_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID4, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_4_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_4_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_4_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_4_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID5, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_5_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_5_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_5_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_5_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID6, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_6_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_6_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_6_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_6_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID7, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_7_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_7_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_7_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_7_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID8, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_8_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_8_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_8_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_8_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID9, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_9_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_9_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_9_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_9_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID10, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_10_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_10_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_10_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_10_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID11, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_11_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_11_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_11_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_11_Off_ID, TRUE);
//     }

//     Interface_GetChannelSwitchState(ChannelID12, &ChannelState);
//     if (ChannelState == CHANNEL_STATE_ON)
//     {
//         Dem_SetEnableCondition(Condition_Channel_12_On_ID, TRUE);
//         Dem_SetEnableCondition(Condition_Channel_12_Off_ID, FALSE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Channel_12_On_ID, FALSE);
//         Dem_SetEnableCondition(Condition_Channel_12_Off_ID, TRUE);
//     }

//     Interface_GetHighSideState(E_HSChannel_HS0, &HSDChannelSwitchState);
//     if (HSDChannelSwitchState == E_HSDChannelSwitchState_ON)
//     {
//         Dem_SetEnableCondition(Condition_Output_Fan_On_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Output_Fan_On_ID, FALSE);
//     }

//     Interface_GetHighSideState(E_HSChannel_HS1, &HSDChannelSwitchState);
//     if (HSDChannelSwitchState == E_HSDChannelSwitchState_ON)
//     {
//         Dem_SetEnableCondition(Condition_Output_HSD1_On_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Output_HSD1_On_ID, FALSE);
//     }

//     Interface_GetHighSideState(E_HSChannel_HS2, &HSDChannelSwitchState);
//     if (HSDChannelSwitchState == E_HSDChannelSwitchState_ON)
//     {
//         Dem_SetEnableCondition(Condition_Output_HSD2_On_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Output_HSD2_On_ID, FALSE);
//     }

//     Interface_GetHighSideState(E_HSChannel_HS3, &HSDChannelSwitchState);
//     if (HSDChannelSwitchState == E_HSDChannelSwitchState_ON)
//     {
//         Dem_SetEnableCondition(Condition_Output_HSD3_On_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_Output_HSD3_On_ID, FALSE);
//     }

//     if (Get_pHSDxOLEnable(E_HSChannel_HS1) == 0)
//     {
//         Dem_SetEnableCondition(Condition_pHSD1OLEnable_Set_0_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_pHSD1OLEnable_Set_0_ID, FALSE);
//     }

//     if (Get_pHSDxOLEnable(E_HSChannel_HS2) == 0)
//     {
//         Dem_SetEnableCondition(Condition_pHSD2OLEnable_Set_0_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_pHSD2OLEnable_Set_0_ID, FALSE);
//     }

//     if (Get_pHSDxOLEnable(E_HSChannel_HS3) == 0)
//     {
//         Dem_SetEnableCondition(Condition_pHSD3OLEnable_Set_0_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_pHSD3OLEnable_Set_0_ID, FALSE);
//     }
//     Interface_GetSignal_VehBattUSysU(&SignalValue);
// #if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
//     if (SignalValue >= 120) /*12V*/
//     {
//         Dem_SetEnableCondition(Condition_UBat_12V_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_UBat_12V_ID, FALSE);
//     }
//     if (SignalValue > 90 && SignalValue < 160)
//     {
//         Dem_SetEnableCondition(Condition_UBat_9_16V_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_UBat_9_16V_ID, FALSE);
//     }
// #else
//     if (SignalValue == 120) /*12V*/
//     {
//         Dem_SetEnableCondition(Condition_UBat_12V_ID, TRUE);
//         Dem_SetEnableCondition(Condition_UBat_9_16V_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_UBat_12V_ID, FALSE);
//         if (SignalValue > 90 && SignalValue < 160)
//         {
//             Dem_SetEnableCondition(Condition_UBat_9_16V_ID, TRUE);
//         }
//         else
//         {
//             Dem_SetEnableCondition(Condition_UBat_9_16V_ID, FALSE);
//         }
//     }
// #endif
//     maxvoltage = 0.0;
//     if (Interface_GetKL15Voltage(&tmpvoltage) == E_OK)
//     {
//         maxvoltage = tmpvoltage;
//     }

//     if (Interface_GetKL56Voltage(&tmpvoltage) == E_OK)
//     {
//         if (maxvoltage < tmpvoltage)
//             maxvoltage = tmpvoltage;
//     }

//     if (maxvoltage > 9.0 && maxvoltage < 16.0)
//     {
//         Dem_SetEnableCondition(Condition_V_ecu_ID, TRUE);
//     }
//     else
//     {
//         Dem_SetEnableCondition(Condition_V_ecu_ID, FALSE);
//     }
//     /* #define Condition_FAN_Active_ID 5u */
//     Dem_SetEnableCondition(Condition_FAN_Active_ID, TRUE);
//     /* #define Condition_ExtrLiRlyPwrDwn_Set_0_ID 25u */
// #endif
// }

// /****************************************************************
//  *                                                              *
//  *                   Global Functions Define                    *
//  *                                                              *
//  ****************************************************************/
// /***************************************************************通道类故障***************************************************************/
// void Interface_SetDtcChannelError(E_ChannelID index, E_ChannelErrorType errortype, uint8_t val)
// {
//     switch (errortype)
//     {
//     case E_CAHNNEL_OPEN:
//         if (val)
//             SetErrorMapValRealTimer(gMap_ChannelOpenError[index]);
//         else
//             ClearErrorMapValRealTimer(gMap_ChannelOpenError[index]);
//         break;
//     case E_CAHNNEL_SHORT2GND:
//         if (val)
//             SetErrorMapValRealTimer(gMap_ChannelShort2GndError[index]);
//         else
//             ClearErrorMapValRealTimer(gMap_ChannelShort2GndError[index]);
//         break;
//     case E_CAHNNEL_SHORT2VCC:
//         if (val)
//             SetErrorMapValRealTimer(gMap_ChannelShort2VccError[index]);
//         else
//             ClearErrorMapValRealTimer(gMap_ChannelShort2VccError[index]);
//         break;
//     case E_CAHNNEL_UNVOL:
//         if (val)
//             SetErrorMapValRealTimer(gMap_ChannelUVError[index]);
//         else
//             ClearErrorMapValRealTimer(gMap_ChannelUVError[index]);
//         break;
//     }
// }
// U_ChannelErrorState Interface_GetChannelState(E_ChannelID index, E_ErrorType ErrorType)
// {
//     U_ChannelErrorState ChannelErrorState;
//     uint8_t Dtcindex = 0;

//     ChannelErrorState.Error = 0;

//     Dtcindex = gMap_ChannelShort2GndError[index];
//     if (ErrorType == E_ErrorType_ErrorDtcState)
//     {
//         if (GetDtcErrorVal(Dtcindex) != 0)
//             ChannelErrorState.bits.Short2GndError = 1;
//     }
//     else
//     {
//         if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//             ChannelErrorState.bits.Short2GndError = 1;
//     }

//     Dtcindex = gMap_ChannelShort2VccError[index];
//     if (ErrorType == E_ErrorType_ErrorDtcState)
//     {
//         if (GetDtcErrorVal(Dtcindex) != 0)
//             ChannelErrorState.bits.Short2VCC = 1;
//     }
//     else
//     {
//         if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//             ChannelErrorState.bits.Short2VCC = 1;
//     }

//     Dtcindex = gMap_ChannelOpenError[index];
//     if (ErrorType == E_ErrorType_ErrorDtcState)
//     {
//         if (GetDtcErrorVal(Dtcindex) != 0)
//             ChannelErrorState.bits.OpenError = 1;
//     }
//     else
//     {
//         if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//             ChannelErrorState.bits.OpenError = 1;
//     }

//     Dtcindex = gMap_ChannelUVError[index];
//     if (ErrorType == E_ErrorType_ErrorDtcState)
//     {
//         if (GetDtcErrorVal(Dtcindex) != 0)
//             ChannelErrorState.bits.UnderVoltage = 1;
//     }
//     else
//     {
//         if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//             ChannelErrorState.bits.UnderVoltage = 1;
//     }

//     return ChannelErrorState;
// }

// /***************************************************************NTC类故障***************************************************************/
// void Interface_SetDtcNtcError(E_NtcSignalNo ntcno, E_NtcErrorType ntcerror, uint8_t val)
// {
//     uint8_t Dtcindex = 0;

//     if (ntcno >= NTC_NUM)
//         return;

//     switch (ntcerror)
//     {
//     case E_NtcErrorType_OpenOrShort2Vcc:
//         Dtcindex = gMap_NtcOpenOrShort2Vcc[ntcno];
//         break;
//     case E_NtcErrorType_Short2Gnd:
//         Dtcindex = gMap_NtcShort2GndError[ntcno];
//         break;
//     case E_NtcErrorType_MatrixNtc1Error:
//         Dtcindex = gMap_MatrixNtcError[0];
//         break;
//     case E_NtcErrorType_MatrixNtc2Error:
//         Dtcindex = gMap_MatrixNtcError[1];
//         break;
//     }

//     if (val)
//     {
//         SetErrorMapValRealTimer(Dtcindex);
//     }
//     else
//     {
//         ClearErrorMapValRealTimer(Dtcindex);
//     }
// }

// U_Ntc_Error Interface_GetNtcErrorState(E_ErrorType ErrorType)
// {
//     U_Ntc_Error rtval;
//     uint8_t Dtcindex = 0;
//     E_NtcSignalNo NtcSignalNo;

//     rtval.NtcError = 0;
//     for (NtcSignalNo = E_NtcSsignalNo_NTC1; NtcSignalNo <= E_NtcSsignalNo_NTC5; NtcSignalNo++)
//     {
//         Dtcindex = gMap_NtcOpenOrShort2Vcc[NtcSignalNo];
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(Dtcindex) != 0)
//                 rtval.NtcError |= (1 << (NtcSignalNo * 2));
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//                 rtval.NtcError |= (1 << (NtcSignalNo * 2));
//         }

//         Dtcindex = gMap_NtcShort2GndError[NtcSignalNo];
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(Dtcindex) != 0)
//                 rtval.NtcError |= (1 << (NtcSignalNo * 2 + 1));
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//                 rtval.NtcError |= (1 << (NtcSignalNo * 2 + 1));
//         }
//     }

//     Dtcindex = gMap_MatrixNtcError[0];
//     if (ErrorType == E_ErrorType_ErrorDtcState)
//     {
//         if (GetDtcErrorVal(Dtcindex) != 0)
//             rtval.bits.MatrixNtc1_ErrorConfirmed = 1;
//     }
//     else
//     {
//         if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//             rtval.bits.MatrixNtc1_ErrorConfirmed = 1;
//     }

//     Dtcindex = gMap_MatrixNtcError[1];
//     if (ErrorType == E_ErrorType_ErrorDtcState)
//     {
//         if (GetDtcErrorVal(Dtcindex) != 0)
//             rtval.bits.MatrixNtc2_ErrorConfirmed = 1;
//     }
//     else
//     {
//         if (GetDtcErrorValRealTimer(Dtcindex) != 0)
//             rtval.bits.MatrixNtc2_ErrorConfirmed = 1;
//     }

//     return rtval;
// }
// /***************************************************************BIN类故障***************************************************************/
// void Interface_SetDtcBinError(E_BinType BinType, uint8_t val)
// {
//     if (BinType <= E_BinType_Bin3)
//     {
//         if (val)
//             SetErrorMapValRealTimer(gMap_BinError[BinType]);
//         else
//             ClearErrorMapValRealTimer(gMap_BinError[BinType]);
//     }
//     else if (BinType <= E_BinType_MatrixBin2)
//     {
//         if (val)
//             SetErrorMapValRealTimer(gMap_MatrixBinError[(BinType - E_BinType_MatrixBin1)]);
//         else
//             ClearErrorMapValRealTimer(gMap_MatrixBinError[(BinType - E_BinType_MatrixBin1)]);
//     }
// }

// U_Bin_Error Interface_GetBinErrorState(E_ErrorType ErrorType)
// {
//     U_Bin_Error rtval;
//     uint8_t i = 0;
//     rtval.BinError = 0;
//     for (i = 0; i < BIN_NUM; i++)
//     {
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(gMap_BinError[i]) != 0)
//                 rtval.BinError |= (1 << i);
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(gMap_BinError[i]) != 0)
//                 rtval.BinError |= (1 << i);
//         }
//     }

//     for (i = 0; i < MATRIX_BIN_NUM; i++)
//     {
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(gMap_MatrixBinError[i]) != 0)
//                 rtval.BinError |= (1 << (i + BIN_NUM));
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(gMap_MatrixBinError[i]) != 0)
//                 rtval.BinError |= (1 << (i + BIN_NUM));
//         }
//     }
//     return rtval;
// }

/***************************************************************输入电压类故障***************************************************************/
void Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType SupplyVoltageErrorType, uint8_t val)
{
    // if (val)
    //     SetErrorMapValRealTimer(gMap_SupplyVolError[SupplyVoltageErrorType]);
    // else
    //     ClearErrorMapValRealTimer(gMap_SupplyVolError[SupplyVoltageErrorType]);
}

// U_SupplyVoltage_Error Interface_GetSupplyVoltageErrorState(E_ErrorType ErrorType)
// {
//     U_SupplyVoltage_Error rtval;
//     uint8_t i = 0;

//     rtval.SupplyVoltageError = 0;
//     for (i = 0; i < SUPPLY_NUM; i++)
//     {
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(gMap_SupplyVolError[i]) != 0)
//                 rtval.SupplyVoltageError |= (1 << i);
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(gMap_SupplyVolError[i]) != 0)
//                 rtval.SupplyVoltageError |= (1 << i);
//         }
//     }

//     return rtval;
// }

/***************************************************************风扇高边类故障***************************************************************/
void Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType HSDAndFanErrorType, uint8_t val)
{
    // if (val)
    //     SetErrorMapValRealTimer(gMap_FanAndHsdError[HSDAndFanErrorType]);
    // else
    //     ClearErrorMapValRealTimer(gMap_FanAndHsdError[HSDAndFanErrorType]);
}

// U_HSDAndFan_Error Interface_GetHSDAndFanErrorState(E_ErrorType ErrorType)
// {
//     U_HSDAndFan_Error rtval;
//     uint8_t i = 0;

//     rtval.HsdAndFanError = 0;
//     for (i = 0; i < FANHSD_NUM; i++)
//     {
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(gMap_FanAndHsdError[i]) != 0)
//                 rtval.HsdAndFanError |= (1 << i);
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(gMap_FanAndHsdError[i]) != 0)
//                 rtval.HsdAndFanError |= (1 << i);
//         }
//     }

//     return rtval;
// }

// // /***************************************************************步进电机类故障***************************************************************/
// // void Interface_SetDtcStepMotorError(E_MotorTpye MotorTpye, E_StepMotorErrorType StepMotorErrorType, uint8_t val)
// // {
// //     uint8_t DtcIndex;
// //     if (val)
// //     {
// //         if (MotorTpye == E_MotorTpye_Leveling)
// //             DtcIndex = gMap_StepMotorError[StepMotorErrorType];
// //         else
// //             DtcIndex = gMap_StepMotorError[(StepMotorErrorType + E_StepMotorErrorType_StepLoss + 1)];

// //         SetErrorMapValRealTimer(DtcIndex);
// //     }
// //     else
// //     {
// //         if (MotorTpye == E_MotorTpye_Leveling)
// //             DtcIndex = gMap_StepMotorError[StepMotorErrorType];
// //         else
// //             DtcIndex = gMap_StepMotorError[(StepMotorErrorType + E_StepMotorErrorType_StepLoss + 1)];

// //         ClearErrorMapValRealTimer(DtcIndex);
// //     }
// // }
// void Interface_SetDtcHallSensorError(E_HallSensorErrorType HallSensorErrorType, uint8_t val)
// {
//     if (val)
//         SetErrorMapValRealTimer(gMap_StepMotorError[(10 + HallSensorErrorType)]);
//     else
//         ClearErrorMapValRealTimer(gMap_StepMotorError[(10 + HallSensorErrorType)]);
// }

// U_StepMotorAndHall_Error Interface_GetStepMotorAndHallErrorState(E_ErrorType ErrorType)
// {
//     U_StepMotorAndHall_Error rtval;
//     uint8_t i = 0;

//     rtval.StepMotor_Error = 0;
//     for (i = 0; i < STEPMOTOR_NUM; i++)
//     {
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(gMap_StepMotorError[i]) != 0)
//                 rtval.StepMotor_Error |= (1 << i);
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(gMap_StepMotorError[i]) != 0)
//                 rtval.StepMotor_Error |= (1 << i);
//         }
//     }
//     return rtval;
// }

// /***************************************************************E2E类故障***************************************************************/

// /*
//  *关闭SuspPosnVertLvl信号和SuspPosnVertLvlRe信号QF的检测
//  *调用此函数后，底层将不会检测该DTC
//  */
// void Interface_DisableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect(void)
// {
//     SuspPosnVertLvlFrntOrSuspPosnVertLvlRe_QFDetect_Flag = 0;
// }
// /*
//  *开启SuspPosnVertLvl信号和SuspPosnVertLvlRe信号QF的检测
//  *调用此函数后，底层将检测该DTC
//  */
// void Interface_EnableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect(void)
// {
//     SuspPosnVertLvlFrntOrSuspPosnVertLvlRe_QFDetect_Flag = 1;
// }
// /*
//  *获取SuspPosnVertLvl信号和SuspPosnVertLvlRe信号QF的检测标记位
//  *1：表示检测开启
//  *0：表示检测关闭
//  */

// uint8_t Interface_GetSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect_Flag(void)
// {
//     return SuspPosnVertLvlFrntOrSuspPosnVertLvlRe_QFDetect_Flag;
// }

// /*
//  *关闭SteerWhlSnsr信号QF的检测
//  *调用此函数后，底层将不会检测该DTC
//  */
// void Interface_DisableSteerWhlSnsr_QF_Detect(void)
// {
//     SteerWhlSnsr_QFDetect_Flag = 0;
// }
// /*
//  *开启SteerWhlSnsr信号QF的检测
//  *调用此函数后，底层将检测该DTC
//  */
// void Interface_EnableSteerWhlSnsr_QF_Detect(void)
// {
//     SteerWhlSnsr_QFDetect_Flag = 1;
// }
// /*
//  *获取SteerWhlSnsr信号QF的检测标记位
//  *1：表示检测开启
//  *0：表示检测关闭
//  */

// uint8_t Interface_GetSteerWhlSnsr_QF_Detect_Flag(void)
// {
//     return SteerWhlSnsr_QFDetect_Flag;
// }

// /*
//  *关闭LvlgSwtSetReq信号CRC的检测
//  *调用此函数后，底层将不会检测该DTC
//  */
// void Interface_DisableLvlgSwtSetReq_CRC_Detect(void)
// {
//     LvlgSwtSetReq_CrcDetect_Flag = 0;
// }
// /*
//  *开启SteerWhlSnsr信号CRC的检测
//  *调用此函数后，底层将检测该DTC
//  */
// void Interface_EnableLvlgSwtSetReq_CRC_Detect(void)
// {
//     LvlgSwtSetReq_CrcDetect_Flag = 1;
// }
// /*
//  *获取SteerWhlSnsr信号CRC的检测标记位
//  *1：表示检测开启
//  *0：表示检测关闭
//  */

// uint8_t Interface_GetLvlgSwtSetReq_CRC_Detect_Flag(void)
// {
//     return LvlgSwtSetReq_CrcDetect_Flag;
// }

// void Interface_SetDtcE2EError(E_E2EErrorType E2EErrorType, uint8_t val)
// {
//     uint8_t DtcIndex;
//     DtcIndex = (uint8_t)(gListItem_E2E[E2EErrorType].xItemValue);

//     if (val)
//         SetErrorMapValRealTimer(DtcIndex);
//     else
//         ClearErrorMapValRealTimer(DtcIndex);

//     if (E2EErrorType != E_E2EErrorType_SuspPosnVertLvl_QFError && E2EErrorType != E_E2EErrorType_SteerWhlSnsr_QFError)
//     {
//         if (IsListItemInList(&gListASWTrigger, &(gListItem_E2E[E2EErrorType])) == 0)
//             ListItemInsertEnd(&gListASWTrigger, &(gListItem_E2E[E2EErrorType]));
//     }
// }

// U_E2E_Error Interface_GetE2EErrorState(E_ErrorType ErrorType)
// {
//     U_E2E_Error rtval;
//     uint8_t DtcIndex;
//     uint8_t i = 0;

//     rtval.E2EError = 0;
//     for (i = 0; i < E2E_NUM; i++)
//     {
//         DtcIndex = (uint8_t)(gListItem_E2E[i].xItemValue);
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(DtcIndex) != 0)
//                 rtval.E2EError |= (1 << i);
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(DtcIndex) != 0)
//                 rtval.E2EError |= (1 << i);
//         }
//     }
//     return rtval;
// }

// /*获得功能安全的E2E标记位，超时，CRC错误和Counter错误*/
// S_E2EStateForFailSafe GetE2EFlagForFailSafe(void)
// {
//     return gs_E2EStateForFailSafe;
// }
// /***************************************************************Boost buck类故障***************************************************************/
// void Interface_SetDtcBuckOverTempError(uint8_t val)
// {
//     if (val)
//     {
//         gu_BaseLayerSetBoostBuck_Error.bits.Buckx_OVER_TEMP_CONFIRMED = 1;
//         SetErrorMapValRealTimer(gMap_BoostBuckError[1]);
//     }
//     else
//     {
//         // gu_BaseLayerSetBoostBuck_Error.bits.Buckx_OVER_TEMP_CONFIRMED = 0;
//         // if (gu_BaseLayerSetBoostBuck_Error.bits.Boostx_OVER_TEMP_CONFIRMED == 0)
//         //     ClearErrorMapValRealTimer(gMap_BoostBuckError[1]);
//     }
// }

// // void Interface_SetDtcBoostOverTempError(uint8_t val)
// // {
// //     if (val)
// //     {
// //         gu_BaseLayerSetBoostBuck_Error.bits.Boostx_OVER_TEMP_CONFIRMED = 1;
// //         SetErrorMapValRealTimer(gMap_BoostBuckError[1]);
// //     }
// //     else
// //     {
// //         gu_BaseLayerSetBoostBuck_Error.bits.Boostx_OVER_TEMP_CONFIRMED = 0;
// //         if (gu_BaseLayerSetBoostBuck_Error.bits.Buckx_OVER_TEMP_CONFIRMED == 0)
// //             ClearErrorMapValRealTimer(gMap_BoostBuckError[1]);
// //     }
// // }

// void Interface_SetDtcBuckInterError(uint8_t val)
// {
//     if (val)
//     {
//         gu_BaseLayerSetBoostBuck_Error.bits.Buckx_InterError = 1;
//         SetErrorMapValRealTimer(gMap_BoostBuckError[0]);
//     }
//     else
//     {
//         // gu_BaseLayerSetBoostBuck_Error.bits.Buckx_InterError = 0;
//         // if (gu_BaseLayerSetBoostBuck_Error.bits.Boostx_InterError == 0)
//         //     ClearErrorMapValRealTimer(gMap_BoostBuckError[0]);
//     }
// }

// // void Interface_SetDtcBoostInterError(uint8_t val)
// // {
// //     if (val)
// //     {
// //         gu_BaseLayerSetBoostBuck_Error.bits.Boostx_InterError = 1;
// //         SetErrorMapValRealTimer(gMap_BoostBuckError[0]);
// //     }
// //     else
// //     {
// //         gu_BaseLayerSetBoostBuck_Error.bits.Boostx_InterError = 0;
// //         if (gu_BaseLayerSetBoostBuck_Error.bits.Buckx_InterError == 0)
// //             ClearErrorMapValRealTimer(gMap_BoostBuckError[0]);
// //     }
// // }

// // U_Boost_Buck_Error Interface_GetBoostBuckErrorState(E_ErrorType ErrorType)
// // {
// //     U_Boost_Buck_Error rtval;
// //     uint8_t i = 0;

// //     rtval.Boost_Buck_Error = 0;

// //     if (ErrorType == E_ErrorType_ErrorDtcState)
// //     {
// //         if (GetDtcErrorVal(gMap_BoostBuckError[0]) != 0)
// //         {
// //             rtval.bits.Buckx_InterError = 1;
// //             rtval.bits.Boostx_InterError = 1;
// //         }

// //         if (GetDtcErrorVal(gMap_BoostBuckError[1]) != 0)
// //         {
// //             rtval.bits.Buckx_OVER_TEMP_CONFIRMED = 1;
// //             rtval.bits.Boostx_OVER_TEMP_CONFIRMED = 1;
// //         }
// //     }
// //     else
// //     {
// //         rtval = gu_BaseLayerSetBoostBuck_Error;
// //     }
// //     return rtval;
// // }

// /***************************************************************系统类故障***************************************************************/
// void Interface_SetSystemError(E_SystemErrorType SystemErrorType, uint8_t val)
// {
//     if (val)
//         SetErrorMapValRealTimer(gMap_SystemError[SystemErrorType]);
//     else
//         ClearErrorMapValRealTimer(gMap_SystemError[SystemErrorType]);
// }

// U_System_Error Interface_GetSystemErrorState(E_ErrorType ErrorType)
// {
//     U_System_Error rtval;
//     uint8_t i = 0;

//     rtval.SystemError = 0;
//     for (i = 0; i < SYSTEM_NUM; i++)
//     {
//         if (ErrorType == E_ErrorType_ErrorDtcState)
//         {
//             if (GetDtcErrorVal(gMap_SystemError[i]) != 0)
//                 rtval.SystemError |= (1 << i);
//         }
//         else
//         {
//             if (GetDtcErrorValRealTimer(gMap_SystemError[i]) != 0)
//                 rtval.SystemError |= (1 << i);
//         }
//     }

//     return rtval;
// }

// /*10ms Task*/
// Std_ReturnType DtcInterfaceMainFunction(uint8_t timebase)
// {
//     uint8_t i = 0;
//     uint8_t j = 0;
//     uint8_t dtcstartindex = 0;
//     uint8_t testnum = 0;
//     S_DtcTestGroup *DtcTestGroup = NULL;
//     uint8_t dtcindex;

//     DTCEnableConditionHander();

//     DtcTestGroup = GetDtcTestGroup();

//     for (i = 0; i < E2E_NUM; i++)
//     {
//         if (IsListItemInList(&gListASWTrigger, &(gListItem_E2E[i])) == 1)
//         {

//             dtcindex = (uint8_t)(gListItem_E2E[i].xItemValue);

//             DtcProcessHander(GetDtcConfig(dtcindex));

//             ListItemRemove(&(gListItem_E2E[i]));
//         }
//     }

//     for (i = 0; i < DTC_TEST_GROUP_NUM; i++)
//     {
//         dtcstartindex = DtcTestGroup[i].CurTestGroup * DtcTestGroup[i].OnceDtcTestNum;
//         if (dtcstartindex < (DtcTestGroup[i].DtcTestNum))
//         {
//             if ((dtcstartindex + DtcTestGroup[i].OnceDtcTestNum) < DtcTestGroup[i].DtcTestNum)
//             {
//                 testnum = DtcTestGroup[i].OnceDtcTestNum;
//             }
//             else
//             {
//                 testnum = DtcTestGroup[i].DtcTestNum - dtcstartindex;
//             }
//             for (j = 0; j < testnum; j++)
//             {
//                 if (DtcTestGroup[i].DtcInfo[(dtcstartindex + j)].DtcDetType != E_DtcDetType_ASW_Cycle)
//                     continue;

//                 if (DtcTestGroup[i].DtcInfo[(dtcstartindex + j)].DtcNumber == DTC_UNDEDNFIED)
//                     continue;

//                 DtcProcessHander(&(DtcTestGroup[i].DtcInfo[(dtcstartindex + j)]));
//             }
//         }

//         DtcTestGroup[i].CurTestGroup++;
//         if (DtcTestGroup[i].CurTestGroup >= (DtcTestGroup[i].GroupNum))
//             DtcTestGroup[i].CurTestGroup = 0;
//     }
// }

// Std_ReturnType Interface_DtcInit(void)
// {
//     Std_ReturnType rtval = E_OK;
//     uint8_t i = 0;
//     uint8_t HcmVariant;
//     uint16_t chmask;
//     uint16_t LMMSupplyFlag = 0;

//     FL_PublicKeyAndSecConstInfoType *PublicKeyAndSecConstInfoType;

//     rtval |= ListInit(&gListASWTrigger);
//     for (i = 0; i < E2E_NUM; i++)
//     {
//         rtval |= ListItemInit(&(gListItem_E2E[i]));
//     }

//     PublicKeyAndSecConstInfoType = FL_PUBLICKEY_SECCONST_NVM_INFO_ADDRESS;

//     if (PublicKeyAndSecConstInfoType->PublicKeyWritten == FL_OPERATE_SUCCEESSD_FLAG)
//     {
//         Interface_SetSystemError(E_SystemErrorType_PublicKeyNotWrited, 0);
//     }
//     else
//     {
//         Interface_SetSystemError(E_SystemErrorType_PublicKeyNotWrited, 1);
//     }

//     if (PublicKeyAndSecConstInfoType->securityConstantWritten == FL_OPERATE_SUCCEESSD_FLAG)
//     {
//         Interface_SetSystemError(E_SystemErrorType_PinCodeNotWrited, 0);
//     }
//     else
//     {
//         Interface_SetSystemError(E_SystemErrorType_PinCodeNotWrited, 1);
//     }

//     HcmVariant = (E_HCMVariantType)Get_Variant();

//     switch (HcmVariant)
//     {
//     // case E_HCMVariantType_Gen1RD_DC_6CH:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if ((chmask >> 6) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD_NOMO:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD_NOMO_DC:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD_DC_PLUS1:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD_PLUS1:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if (Get_MatrixRealisation() == 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD_PLUS2:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if (Get_MatrixRealisation() == 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     // case E_HCMVariantType_Gen1RD_PLUS3:
//     //     chmask = Interface_GetChannelMask();
//     //     LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//     //     if (Get_MatrixRealisation() == 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((chmask >> 8) != 0)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//     //     //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//     //     else
//     //         Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//     //     break;
//     case E_HCMVariantType_Gen2RDL:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     case E_HCMVariantType_Gen2RDL_NOMO:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     case E_HCMVariantType_Gen2RDH:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     case E_HCMVariantType_Gen2RDH_NOMO:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     case E_HCMVariantType_Gen2RDH_DC:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     case E_HCMVariantType_Gen2RD_FULL:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     case E_HCMVariantType_Gen2RD_MAX1:
//         LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
//         if (Get_MatrixRealisation() == 0)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if (Get_pVehDBLType() != 2 && Get_pVehDBLType() != 6 && Get_pSensorType() == 2)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else if ((Get_pVehDBLType() == 2 || Get_pVehDBLType() == 6) && Get_pSensorType() == 1)
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         // else if (Get_MatrixRealisation() != 0 && Interface_GetMatrixChipRegisterNumer() == 0)
//         //     Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
//         else
//             Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
//         break;
//     }

//     return rtval;
// }
