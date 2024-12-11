/*
 * DtcConfig.h
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_DID_DTC_INTERFACE_DTCCONFIG_H_
#define ASW_INTERFACE_DID_DTC_INTERFACE_DTCCONFIG_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
/*一共DTC的个数*/
#define DTC_MAX_SIZE 137
#define DTC_VALUE_SIZE 18 /*138个DTC，需要18个 uint8_t 数据*/
#elif(VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
/*一共DTC的个数*/
#define DTC_MAX_SIZE 127
#define DTC_VALUE_SIZE 16 /*127个DTC，需要16个 uint8_t 数据*/
#endif

#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
#define Config_10ms_TestPeriod_NUM 6
#define Config_20ms_TestPeriod_NUM 15
#define Config_40ms_TestPeriod_NUM 2
#define Config_100ms_TestPeriod_NUM 114
#elif(VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
#define Config_10ms_TestPeriod_NUM 6
#define Config_20ms_TestPeriod_NUM 5
#define Config_40ms_TestPeriod_NUM 2
#define Config_100ms_TestPeriod_NUM 114
#endif

#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
#define Config_10ms_OnceTest_NUM 6
#define Config_20ms_OnceTest_NUM 8
#define Config_40ms_OnceTest_NUM 1
#define Config_100ms_OnceTest_NUM 12
#elif(VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
/*The dem_setevent in 10ms Task*/
#define Config_10ms_OnceTest_NUM 6
#define Config_20ms_OnceTest_NUM 3
#define Config_40ms_OnceTest_NUM 1
#define Config_100ms_OnceTest_NUM 12
#endif

#define Config_10ms_Group_NUM 1
#define Config_20ms_Group_NUM 2
#define Config_40ms_Group_NUM 4
#define Config_100ms_Group_NUM 10

#define DTC_TEST_GROUP_NUM 4

#define DTC_UNDEDNFIED 0xFFFFFFFF

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
/*
 *DTC检测类型
 *E_DtcDetType_BSW ：由基础软件检测 ，比如Busoff故障
 *E_DtcDetType_ASW_Cycle:由于ASW周期检测
 *E_DtcDetType_ASW_Trigger:由于ASW触发式检测
 */
typedef enum
{
    E_DtcDetType_BSW = 0,
    E_DtcDetType_ASW_Cycle = 1,
    E_DtcDetType_ASW_Trigger = 2,
} E_DtcDetType;
typedef enum
{
    E_DtcType_KL15_OpenOrShort2Gnd = 0,
    E_DtcType_KL56_OpenOrShort2Gnd,
    E_DtcType_EcuSupply_OverVoltage,
    E_DtcType_EcuSupply_UnderVoltage,
    E_DtcType_EcuSupply_BusSignal_Mismatch,
    E_DtcType_Channel1_Short2Gnd,
    E_DtcType_Channel1_Short2Battery,
    E_DtcType_Channel1_OpenLoad,
    E_DtcType_Channel1_UnderVoltage,
    E_DtcType_Channel2_Short2Gnd,
    E_DtcType_Channel2_Short2Battery,
    E_DtcType_Channel2_OpenLoad,
    E_DtcType_Channel2_UnderVoltage,
    E_DtcType_Channel3_Short2Gnd,
    E_DtcType_Channel3_Short2Battery,
    E_DtcType_Channel3_OpenLoad,
    E_DtcType_Channel3_UnderVoltage,
    E_DtcType_Channel4_Short2Gnd,
    E_DtcType_Channel4_Short2Battery,
    E_DtcType_Channel4_OpenLoad,
    E_DtcType_Channel4_UnderVoltage,
    E_DtcType_Channel5_Short2Gnd,
    E_DtcType_Channel5_Short2Battery,
    E_DtcType_Channel5_OpenLoad,
    E_DtcType_Channel5_UnderVoltage,
    E_DtcType_Channel6_Short2Gnd,
    E_DtcType_Channel6_Short2Battery,
    E_DtcType_Channel6_OpenLoad,
    E_DtcType_Channel6_UnderVoltage,
    E_DtcType_Channel7_Short2Gnd,
    E_DtcType_Channel7_Short2Battery,
    E_DtcType_Channel7_OpenLoad,
    E_DtcType_Channel7_UnderVoltage,
    E_DtcType_Channel8_Short2Gnd,
    E_DtcType_Channel8_Short2Battery,
    E_DtcType_Channel8_OpenLoad,
    E_DtcType_Channel8_UnderVoltage,
    E_DtcType_Channel9_Short2Gnd,
    E_DtcType_Channel9_Short2Battery,
    E_DtcType_Channel9_OpenLoad,
    E_DtcType_Channel9_UnderVoltage,
    E_DtcType_Channel10_Short2Gnd,
    E_DtcType_Channel10_Short2Battery,
    E_DtcType_Channel10_OpenLoad,
    E_DtcType_Channel10_UnderVoltage,
    E_DtcType_Channel11_Short2Gnd,
    E_DtcType_Channel11_Short2Battery,
    E_DtcType_Channel11_OpenLoad,
    E_DtcType_Channel11_UnderVoltage,
    E_DtcType_Channel12_Short2Gnd,
    E_DtcType_Channel12_Short2Battery,
    E_DtcType_Channel12_OpenLoad,
    E_DtcType_Channel12_UnderVoltage,
    E_DtcType_HSD1_OverCurrent,
    E_DtcType_HSD1_Short2Gnd,
    E_DtcType_HSD1_OpenOrShort2Battery,
    E_DtcType_HSD2_OverCurrent,
    E_DtcType_HSD2_Short2Gnd,
    E_DtcType_HSD2_OpenOrShort2Battery,
    E_DtcType_HSD3_OverCurrent,
    E_DtcType_HSD3_Short2Gnd,
    E_DtcType_HSD3_OpenOrShort2Battery,
    E_DtcType_FAN1_Stall,
    E_DtcType_FAN1ControlLine_Short2Gnd,
    E_DtcType_FAN1ControlLine_Short2Battery,
    E_DtcType_FAN1Supply_Short2Gnd,
    E_DtcType_FAN1Supply_OpenOrShort2Battery,
    E_DtcType_FAN1HSD_OverCurrent,
    E_DtcType_NTC1_Short2Gnd,
    E_DtcType_NTC1_OpenOrShort2Battery,
    E_DtcType_NTC2_Short2Gnd,
    E_DtcType_NTC2_OpenOrShort2Battery,
    E_DtcType_NTC3_Short2Gnd,
    E_DtcType_NTC3_OpenOrShort2Battery,
    E_DtcType_NTC4_Short2Gnd,
    E_DtcType_NTC4_OpenOrShort2Battery,
    E_DtcType_NTC5_Short2Gnd,
    E_DtcType_NTC5_OpenOrShort2Battery,
    E_DtcType_Rcod1_Error,
    E_DtcType_Rcod2_Error,
    E_DtcType_Rcod3_Error,
    E_DtcType_Hall_ElectricalFailure,
    E_DtcType_Hall_FeedbackConstantLow,
    E_DtcType_Hall_FeedbackConstantHigh,
    E_DtcType_Swivel_Overload,
    E_DtcType_Swivel_Openload,
    E_DtcType_Swivel_OverUse,
    E_DtcType_Swivel_InterError,
    E_DtcType_Swivel_StepLoss,
    E_DtcType_Level_Overload,
    E_DtcType_Level_Openload,
    E_DtcType_Level_OverUse,
    E_DtcType_Level_InterError,
    E_DtcType_Level_StepLoss,
    E_DtcType_Busoff,
    E_DtcType_ParameterTable_CrcError,
    E_DtcType_ParameterTable_VersionError,
    E_DtcType_LvlgSwtSetReqChksError,
    E_DtcType_SuspPosnVertLvlQFError,
    E_DtcType_SteerWhlSnsrQFError,
    E_DtcType_VehSpdLgtSafe_CounterError,
    E_DtcType_VehSpdLgtSafe_CrcError,
    E_DtcType_VehModMngtGlbSafe1_CounterError,
    E_DtcType_VehModMngtGlbSafe1_CrcError,
    E_DtcType_IndcrOutSafe_CounterError,
    E_DtcType_IndcrOutSafe_CrcError,
    E_DtcType_ActnOfLedLoBeam_CounterError,
    E_DtcType_ActnOfLedLoBeam_CrcError,
    E_DtcType_MatrixChip_LossCom,
    E_DtcType_MatrixChip_Ntc1Error,
    E_DtcType_MatrixChip_Ntc2Error,
    E_DtcType_ECU_OverTemperature,
    E_DtcType_ECU_SpiError,
    E_DtcType_BuckOrBoost_OverTemperature,
    E_DtcType_Rom_Error,
    E_DtcType_Ram_Error,
    E_DtcType_BoostBuckError,
    E_DtcType_ChannelCurrentConfigError,
    E_DtcType_WatchDogTimeout,
    E_DtcType_LeftRightError,
    E_DtcType_LeftRightMismatch,
    E_DtcType_LowBeamFlatDerateError,
    E_DtcType_TIDerateError,
    E_DtcType_PinCodeNotWrited,
    E_DtcType_PublicKeyNotWrited,
    E_DtcType_MatrixRcod1_Error,
    E_DtcType_MatrixRcod2_Error,
    E_DtcType_DCMotor_Error,
    E_DtcType_CentralCfg_Error,
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
    E_DtcType_Ch2MatrixLosCom_Error,
    E_DtcType_Ch3MatrixLosCom_Error,
    E_DtcType_Ch4MatrixLosCom_Error,
    E_DtcType_Ch5MatrixLosCom_Error,
    E_DtcType_Ch6MatrixLosCom_Error,
    E_DtcType_Ch7MatrixLosCom_Error,
    E_DtcType_Ch8MatrixLosCom_Error,
    E_DtcType_Ch9MatrixLosCom_Error,
    E_DtcType_Ch10MatrixLosCom_Error,
    E_DtcType_Ch11MatrixLosCom_Error,
    E_DtcType_Ch12MatrixLosCom_Error,
#endif
} E_DtcType;

typedef struct DtcConfig
{
    E_DtcType DtcType;
    uint8_t Index;
    uint32_t DtcNumber;
    E_DtcDetType DtcDetType;
} S_DtcConfig;

typedef struct DtcTestGroup
{
    uint8_t CurTestGroup;   /*当前检测到哪一组*/
    uint8_t GroupNum;       /*一共有多少组*/
    uint8_t DtcTestNum;     /*一共有多少个DTC*/
    uint8_t OnceDtcTestNum; /*每组检测多少个DTC*/
    const S_DtcConfig *DtcInfo;
} S_DtcTestGroup;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
const S_DtcConfig *GetDtcConfig(uint8_t index);
S_DtcTestGroup *GetDtcTestGroup(void);

#endif /* ASW_INTERFACE_DID_DTC_INTERFACE_DTCCONFIG_H_ */
