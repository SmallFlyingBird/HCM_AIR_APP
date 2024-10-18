/*
 * DtcConfig.c
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DtcConfig.h"
#include "Dem_Cfg.h"
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
#define Dtc10msStartIndex      0
#define Dtc20msStartIndex      6
#define Dtc40msStartIndex      21
#define Dtc100msStartIndex     23
#elif(VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
#define Dtc10msStartIndex      0
#define Dtc20msStartIndex      6
#define Dtc40msStartIndex      11
#define Dtc100msStartIndex     13
#endif
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
const S_DtcConfig  g_DtcCondfig[DTC_MAX_SIZE]={
    /*********************************************10ms Test cycle*********************************************/
    /*index0*/  {.DtcType=E_DtcType_Channel1_UnderVoltage,              .Index=0,   .DtcNumber=DemEventParameter_0x960221,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index1*/  {.DtcType=E_DtcType_Busoff,                             .Index=1,   .DtcNumber=DemEventParameter_0xC03788,    .DtcDetType=E_DtcDetType_BSW},
    /*index2*/  {.DtcType=E_DtcType_ActnOfLedLoBeam_CounterError,       .Index=2,   .DtcNumber=DemEventParameter_0xED8C82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index3*/  {.DtcType=E_DtcType_ActnOfLedLoBeam_CrcError,           .Index=3,   .DtcNumber=DemEventParameter_0xED8C83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index4*/  {.DtcType=E_DtcType_LowBeamFlatDerateError,             .Index=4,   .DtcNumber=DemEventParameter_0xEF1068,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index5*/  {.DtcType=E_DtcType_TIDerateError,                      .Index=5,   .DtcNumber=DemEventParameter_0xEF1168,    .DtcDetType=E_DtcDetType_ASW_Cycle}, 
    /*********************************************20ms Test cycle*********************************************/
    /*index6*/  {.DtcType=E_DtcType_Ch2MatrixLosCom_Error,              .Index=6,   .DtcNumber=DemEventParameter_0x961087,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index7*/  {.DtcType=E_DtcType_Ch3MatrixLosCom_Error,              .Index=7,   .DtcNumber=DemEventParameter_0x961187,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index8*/  {.DtcType=E_DtcType_Ch4MatrixLosCom_Error,              .Index=8,   .DtcNumber=DemEventParameter_0x961287,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index9*/  {.DtcType=E_DtcType_Ch5MatrixLosCom_Error,              .Index=9,   .DtcNumber=DemEventParameter_0x961387,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index10*/ {.DtcType=E_DtcType_Ch6MatrixLosCom_Error,              .Index=10,  .DtcNumber=DemEventParameter_0x961487,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index11*/ {.DtcType=E_DtcType_Ch7MatrixLosCom_Error,              .Index=11,  .DtcNumber=DemEventParameter_0x961587,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index12*/ {.DtcType=E_DtcType_Ch8MatrixLosCom_Error,              .Index=12,  .DtcNumber=DemEventParameter_0x961687,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index13*/ {.DtcType=E_DtcType_Ch9MatrixLosCom_Error,              .Index=13,  .DtcNumber=DemEventParameter_0x968787,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index14*/ {.DtcType=E_DtcType_Ch10MatrixLosCom_Error,             .Index=14,  .DtcNumber=DemEventParameter_0x968A87,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index15*/ {.DtcType=E_DtcType_Ch11MatrixLosCom_Error,             .Index=15,  .DtcNumber=DemEventParameter_0x96F587,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index16*/ {.DtcType=E_DtcType_Ch12MatrixLosCom_Error,             .Index=16,  .DtcNumber=DemEventParameter_0x96F687,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index17*/ {.DtcType=E_DtcType_IndcrOutSafe_CounterError,          .Index=17,  .DtcNumber=DemEventParameter_0xED8B82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index18*/ {.DtcType=E_DtcType_IndcrOutSafe_CrcError,              .Index=18,  .DtcNumber=DemEventParameter_0xED8B83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index19*/ {.DtcType=E_DtcType_VehModMngtGlbSafe1_CounterError,    .Index=19,  .DtcNumber=DemEventParameter_0xED5A82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index20*/ {.DtcType=E_DtcType_VehModMngtGlbSafe1_CrcError,        .Index=20,  .DtcNumber=DemEventParameter_0xED5A83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*********************************************40ms Test cycle*********************************************/
    /*index21*/ {.DtcType=E_DtcType_VehSpdLgtSafe_CounterError,         .Index=21,  .DtcNumber=DemEventParameter_0xED3E82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index22*/ {.DtcType=E_DtcType_VehSpdLgtSafe_CrcError,             .Index=22,  .DtcNumber=DemEventParameter_0xED3E83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*********************************************100ms Test cycle*********************************************/
    /*index23*/ {.DtcType=E_DtcType_WatchDogTimeout,                    .Index=23,  .DtcNumber=DemEventParameter_0x505547,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index24*/ {.DtcType=E_DtcType_KL15_OpenOrShort2Gnd,               .Index=24,  .DtcNumber=DemEventParameter_0x90E714,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index25*/ {.DtcType=E_DtcType_KL56_OpenOrShort2Gnd,               .Index=25,  .DtcNumber=DemEventParameter_0x95A214,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index26*/ {.DtcType=E_DtcType_EcuSupply_OverVoltage,              .Index=26,  .DtcNumber=DemEventParameter_0xEE0368,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index27*/ {.DtcType=E_DtcType_EcuSupply_UnderVoltage,             .Index=27,  .DtcNumber=DemEventParameter_0xEE0468,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index28*/ {.DtcType=E_DtcType_EcuSupply_BusSignal_Mismatch,       .Index=28,  .DtcNumber=DemEventParameter_0xF00362,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index29*/ {.DtcType=E_DtcType_FAN1_Stall,                         .Index=29,  .DtcNumber=DemEventParameter_0x95A771,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index30*/ {.DtcType=E_DtcType_FAN1ControlLine_Short2Gnd,          .Index=30,  .DtcNumber=DemEventParameter_0x95D511,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index31*/ {.DtcType=E_DtcType_FAN1ControlLine_Short2Battery,      .Index=31,  .DtcNumber=DemEventParameter_0x95D512,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index32*/ {.DtcType=E_DtcType_FAN1Supply_Short2Gnd,               .Index=32,  .DtcNumber=DemEventParameter_0x982111,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index33*/ {.DtcType=E_DtcType_FAN1Supply_OpenOrShort2Battery,     .Index=33,  .DtcNumber=DemEventParameter_0x982115,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index34*/ {.DtcType=E_DtcType_FAN1HSD_OverCurrent,                .Index=34,  .DtcNumber=DemEventParameter_0xD66419,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index35*/ {.DtcType=E_DtcType_HSD1_Short2Gnd,                     .Index=35,  .DtcNumber=DemEventParameter_0x95B211,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index36*/ {.DtcType=E_DtcType_HSD1_OpenOrShort2Battery,           .Index=36,  .DtcNumber=DemEventParameter_0x95B215,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index37*/ {.DtcType=E_DtcType_HSD1_OverCurrent,                   .Index=37,  .DtcNumber=DemEventParameter_0x95B219,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index38*/ {.DtcType=E_DtcType_HSD2_Short2Gnd,                     .Index=38,  .DtcNumber=DemEventParameter_0x95B311,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index39*/ {.DtcType=E_DtcType_HSD2_OpenOrShort2Battery,           .Index=39,  .DtcNumber=DemEventParameter_0x95B315,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index40*/ {.DtcType=E_DtcType_HSD2_OverCurrent,                   .Index=40,  .DtcNumber=DemEventParameter_0x95B319,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index41*/ {.DtcType=E_DtcType_HSD3_Short2Gnd,                     .Index=41,  .DtcNumber=DemEventParameter_0x95B411,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index42*/ {.DtcType=E_DtcType_HSD3_OpenOrShort2Battery,           .Index=42,  .DtcNumber=DemEventParameter_0x95B415,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index43*/ {.DtcType=E_DtcType_HSD3_OverCurrent,                   .Index=43,  .DtcNumber=DemEventParameter_0x95B419,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index44*/ {.DtcType=E_DtcType_NTC1_Short2Gnd,                     .Index=44,  .DtcNumber=DemEventParameter_0x957011,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index45*/ {.DtcType=E_DtcType_NTC1_OpenOrShort2Battery,           .Index=45,  .DtcNumber=DemEventParameter_0x957015,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index46*/ {.DtcType=E_DtcType_NTC2_Short2Gnd,                     .Index=46,  .DtcNumber=DemEventParameter_0x957911,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index47*/ {.DtcType=E_DtcType_NTC2_OpenOrShort2Battery,           .Index=47,  .DtcNumber=DemEventParameter_0x957915,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index48*/ {.DtcType=E_DtcType_NTC3_Short2Gnd,                     .Index=48,  .DtcNumber=DemEventParameter_0x957A11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index49*/ {.DtcType=E_DtcType_NTC3_OpenOrShort2Battery,           .Index=49,  .DtcNumber=DemEventParameter_0x957A15,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index50*/ {.DtcType=E_DtcType_NTC4_Short2Gnd,                     .Index=50,  .DtcNumber=DemEventParameter_0x957E11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index51*/ {.DtcType=E_DtcType_NTC4_OpenOrShort2Battery,           .Index=51,  .DtcNumber=DemEventParameter_0x957E15,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index52*/ {.DtcType=E_DtcType_NTC5_Short2Gnd,                     .Index=52,  .DtcNumber=DemEventParameter_0x959011,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index53*/ {.DtcType=E_DtcType_NTC5_OpenOrShort2Battery,           .Index=53,  .DtcNumber=DemEventParameter_0x959015,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index54*/ {.DtcType=E_DtcType_MatrixChip_Ntc2Error,               .Index=54,  .DtcNumber=DemEventParameter_0xEF0E86,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index55*/ {.DtcType=E_DtcType_MatrixChip_Ntc1Error,               .Index=55,  .DtcNumber=DemEventParameter_0xEF0F86,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index56*/ {.DtcType=E_DtcType_Rcod1_Error,                        .Index=56,  .DtcNumber=DemEventParameter_0xEF7001,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index57*/ {.DtcType=E_DtcType_Rcod2_Error,                        .Index=57,  .DtcNumber=DemEventParameter_0xEF7101,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index58*/ {.DtcType=E_DtcType_Rcod3_Error,                        .Index=58,  .DtcNumber=DemEventParameter_0xEF7201,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index59*/ {.DtcType=E_DtcType_LeftRightError,                     .Index=59,  .DtcNumber=DemEventParameter_0x95A401,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index60*/ {.DtcType=E_DtcType_LeftRightMismatch,                  .Index=60,  .DtcNumber=DemEventParameter_0x95D309,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index61*/ {.DtcType=E_DtcType_Hall_ElectricalFailure,             .Index=61,  .DtcNumber=DemEventParameter_0x95A301,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index62*/ {.DtcType=E_DtcType_Hall_FeedbackConstantLow,           .Index=62,  .DtcNumber=DemEventParameter_0x95A323,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index63*/ {.DtcType=E_DtcType_Hall_FeedbackConstantHigh,          .Index=63,  .DtcNumber=DemEventParameter_0x95A324,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index64*/ {.DtcType=E_DtcType_Swivel_Overload,                    .Index=64,  .DtcNumber=DemEventParameter_0x95A801,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index65*/ {.DtcType=E_DtcType_Swivel_Openload,                    .Index=65,  .DtcNumber=DemEventParameter_0x95A813,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index66*/ {.DtcType=E_DtcType_Swivel_OverUse,                     .Index=66,  .DtcNumber=DemEventParameter_0x95A863,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index67*/ {.DtcType=E_DtcType_Swivel_InterError,                  .Index=67,  .DtcNumber=DemEventParameter_0x95D096,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index68*/ {.DtcType=E_DtcType_Swivel_StepLoss,                    .Index=68,  .DtcNumber=DTC_UNDEDNFIED,                .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index69*/ {.DtcType=E_DtcType_Level_Overload,                     .Index=69,  .DtcNumber=DemEventParameter_0x95A901,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index70*/ {.DtcType=E_DtcType_Level_Openload,                     .Index=70,  .DtcNumber=DemEventParameter_0x95A913,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index71*/ {.DtcType=E_DtcType_Level_OverUse,                      .Index=71,  .DtcNumber=DemEventParameter_0x95A963,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index72*/ {.DtcType=E_DtcType_Level_InterError,                   .Index=72,  .DtcNumber=DemEventParameter_0x95D196,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index73*/ {.DtcType=E_DtcType_Channel1_Short2Gnd,                 .Index=73,  .DtcNumber=DemEventParameter_0x95AA11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index74*/ {.DtcType=E_DtcType_Channel1_Short2Battery,             .Index=74,  .DtcNumber=DemEventParameter_0x95AA12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index75*/ {.DtcType=E_DtcType_Channel1_OpenLoad,                  .Index=75,  .DtcNumber=DemEventParameter_0x95AA13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index76*/ {.DtcType=E_DtcType_Channel2_Short2Gnd,                 .Index=76,  .DtcNumber=DemEventParameter_0x95AB11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index77*/ {.DtcType=E_DtcType_Channel2_Short2Battery,             .Index=77,  .DtcNumber=DemEventParameter_0x95AB12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index78*/ {.DtcType=E_DtcType_Channel2_OpenLoad,                  .Index=78,  .DtcNumber=DemEventParameter_0x95AB13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index79*/ {.DtcType=E_DtcType_Channel2_UnderVoltage,              .Index=79,  .DtcNumber=DemEventParameter_0x961021,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index80*/ {.DtcType=E_DtcType_Channel3_Short2Gnd,                 .Index=80,  .DtcNumber=DemEventParameter_0x95AC11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index81*/ {.DtcType=E_DtcType_Channel3_Short2Battery,             .Index=81,  .DtcNumber=DemEventParameter_0x95AC12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index82*/ {.DtcType=E_DtcType_Channel3_OpenLoad,                  .Index=82,  .DtcNumber=DemEventParameter_0x95AC13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index83*/ {.DtcType=E_DtcType_Channel3_UnderVoltage,              .Index=83,  .DtcNumber=DemEventParameter_0x961121,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index84*/ {.DtcType=E_DtcType_Channel4_Short2Gnd,                 .Index=84,  .DtcNumber=DemEventParameter_0x95AD11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index85*/ {.DtcType=E_DtcType_Channel4_Short2Battery,             .Index=85,  .DtcNumber=DemEventParameter_0x95AD12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index86*/ {.DtcType=E_DtcType_Channel4_OpenLoad,                  .Index=86,  .DtcNumber=DemEventParameter_0x95AD13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index87*/ {.DtcType=E_DtcType_Channel4_UnderVoltage,              .Index=87,  .DtcNumber=DemEventParameter_0x961221,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index88*/ {.DtcType=E_DtcType_Channel5_Short2Gnd,                 .Index=88,  .DtcNumber=DemEventParameter_0x95AE11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index89*/ {.DtcType=E_DtcType_Channel5_Short2Battery,             .Index=89,  .DtcNumber=DemEventParameter_0x95AE12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index90*/ {.DtcType=E_DtcType_Channel5_OpenLoad,                  .Index=90,  .DtcNumber=DemEventParameter_0x95AE13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index91*/ {.DtcType=E_DtcType_Channel5_UnderVoltage,              .Index=91,  .DtcNumber=DemEventParameter_0x961321,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index92*/ {.DtcType=E_DtcType_Channel6_Short2Gnd,                 .Index=92,  .DtcNumber=DemEventParameter_0x95AF11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index93*/ {.DtcType=E_DtcType_Channel6_Short2Battery,             .Index=93,  .DtcNumber=DemEventParameter_0x95AF12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index94*/ {.DtcType=E_DtcType_Channel6_OpenLoad,                  .Index=94,  .DtcNumber=DemEventParameter_0x95AF13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index95*/ {.DtcType=E_DtcType_Channel6_UnderVoltage,              .Index=95,  .DtcNumber=DemEventParameter_0x961421,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index96*/ {.DtcType=E_DtcType_Channel7_Short2Gnd,                 .Index=96,  .DtcNumber=DemEventParameter_0x95B011,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index97*/ {.DtcType=E_DtcType_Channel7_Short2Battery,             .Index=97,  .DtcNumber=DemEventParameter_0x95B012,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index98*/ {.DtcType=E_DtcType_Channel7_OpenLoad,                  .Index=98,  .DtcNumber=DemEventParameter_0x95B013,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index99*/ {.DtcType=E_DtcType_Channel7_UnderVoltage,              .Index=99,  .DtcNumber=DemEventParameter_0x961521,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index100*/{.DtcType=E_DtcType_Channel8_Short2Gnd,                 .Index=100, .DtcNumber=DemEventParameter_0x95B111,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index101*/{.DtcType=E_DtcType_Channel8_Short2Battery,             .Index=101, .DtcNumber=DemEventParameter_0x95B112,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index102*/{.DtcType=E_DtcType_Channel8_OpenLoad,                  .Index=102, .DtcNumber=DemEventParameter_0x95B113,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index103*/{.DtcType=E_DtcType_Channel8_UnderVoltage,              .Index=103, .DtcNumber=DemEventParameter_0x961621,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index104*/{.DtcType=E_DtcType_Channel9_Short2Gnd,                 .Index=104, .DtcNumber=DemEventParameter_0x968711,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index105*/{.DtcType=E_DtcType_Channel9_Short2Battery,             .Index=105, .DtcNumber=DemEventParameter_0x968712,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index106*/{.DtcType=E_DtcType_Channel9_OpenLoad,                  .Index=106, .DtcNumber=DemEventParameter_0x968713,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index107*/{.DtcType=E_DtcType_Channel9_UnderVoltage,              .Index=107, .DtcNumber=DemEventParameter_0x968721,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index108*/{.DtcType=E_DtcType_Channel10_Short2Gnd,                .Index=108, .DtcNumber=DemEventParameter_0x968A11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index109*/{.DtcType=E_DtcType_Channel10_Short2Battery,            .Index=109, .DtcNumber=DemEventParameter_0x968A12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index110*/{.DtcType=E_DtcType_Channel10_OpenLoad,                 .Index=110, .DtcNumber=DemEventParameter_0x968A13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index111*/{.DtcType=E_DtcType_Channel10_UnderVoltage,             .Index=111, .DtcNumber=DemEventParameter_0x968A21,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index112*/{.DtcType=E_DtcType_Channel11_Short2Gnd,                .Index=112, .DtcNumber=DemEventParameter_0x96F511,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index113*/{.DtcType=E_DtcType_Channel11_Short2Battery,            .Index=113, .DtcNumber=DemEventParameter_0x96F512,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index114*/{.DtcType=E_DtcType_Channel11_OpenLoad,                 .Index=114, .DtcNumber=DemEventParameter_0x96F513,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index115*/{.DtcType=E_DtcType_Channel11_UnderVoltage,             .Index=115, .DtcNumber=DemEventParameter_0x96F521,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index116*/{.DtcType=E_DtcType_Channel12_Short2Gnd,                .Index=116, .DtcNumber=DemEventParameter_0x96F611,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index117*/{.DtcType=E_DtcType_Channel12_Short2Battery,            .Index=117, .DtcNumber=DemEventParameter_0x96F612,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index118*/{.DtcType=E_DtcType_Channel12_OpenLoad,                 .Index=118, .DtcNumber=DemEventParameter_0x96F613,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index119*/{.DtcType=E_DtcType_Channel12_UnderVoltage,             .Index=119, .DtcNumber=DemEventParameter_0x96F621,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index120*/{.DtcType=E_DtcType_BoostBuckError,                     .Index=120, .DtcNumber=DemEventParameter_0x95D296,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index121*/{.DtcType=E_DtcType_ECU_SpiError,                       .Index=121, .DtcNumber=DemEventParameter_0xE01449,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index122*/{.DtcType=E_DtcType_BuckOrBoost_OverTemperature,        .Index=122, .DtcNumber=DemEventParameter_0xE01498,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index123*/{.DtcType=E_DtcType_ParameterTable_VersionError,        .Index=123, .DtcNumber=DTC_UNDEDNFIED,                .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index124*/{.DtcType=E_DtcType_ParameterTable_CrcError,            .Index=124, .DtcNumber=DemEventParameter_0xE10156,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index125*/{.DtcType=E_DtcType_ChannelCurrentConfigError,          .Index=125, .DtcNumber=DemEventParameter_0xF0001C,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index126*/{.DtcType=E_DtcType_Rom_Error,                          .Index=126, .DtcNumber=DemEventParameter_0xD00246,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index127*/{.DtcType=E_DtcType_Ram_Error,                          .Index=127, .DtcNumber=DemEventParameter_0xD00544,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index128*/{.DtcType=E_DtcType_LvlgSwtSetReqChksError,             .Index=128, .DtcNumber=DemEventParameter_0x982341,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index129*/{.DtcType=E_DtcType_SuspPosnVertLvlQFError,             .Index=129, .DtcNumber=DemEventParameter_0xE79982,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index130*/{.DtcType=E_DtcType_SteerWhlSnsrQFError,                .Index=130, .DtcNumber=DemEventParameter_0xE79A82,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index131*/{.DtcType=E_DtcType_PinCodeNotWrited,                   .Index=131, .DtcNumber=DemEventParameter_0xD14B51,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index132*/{.DtcType=E_DtcType_PublicKeyNotWrited,                 .Index=132, .DtcNumber=DemEventParameter_0xD14C51,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index133*/{.DtcType=E_DtcType_MatrixRcod1_Error,                  .Index=133, .DtcNumber=DemEventParameter_0xEF1086,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index134*/{.DtcType=E_DtcType_MatrixRcod2_Error,                  .Index=134, .DtcNumber=DemEventParameter_0xEF1186,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index135*/{.DtcType=E_DtcType_DCMotor_Error,                      .Index=135, .DtcNumber=DemEventParameter_0x9DFB01,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index136*/{.DtcType=E_DtcType_CentralCfg_Error,                   .Index=136, .DtcNumber=DemEventParameter_0xE30057,    .DtcDetType=E_DtcDetType_ASW_Cycle},
};
#elif(VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
const S_DtcConfig  g_DtcCondfig[DTC_MAX_SIZE]={
    /*********************************************10ms Test cycle*********************************************/
    /*index0*/  {.DtcType=E_DtcType_Channel1_UnderVoltage,              .Index=0,   .DtcNumber=DemEventParameter_0x960221,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index1*/  {.DtcType=E_DtcType_Busoff,                             .Index=1,   .DtcNumber=DemEventParameter_0xC03788,    .DtcDetType=E_DtcDetType_BSW},
    /*index2*/  {.DtcType=E_DtcType_ActnOfLedLoBeam_CounterError,       .Index=2,   .DtcNumber=DemEventParameter_0xED8C82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index3*/  {.DtcType=E_DtcType_ActnOfLedLoBeam_CrcError,           .Index=3,   .DtcNumber=DemEventParameter_0xED8C83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index4*/  {.DtcType=E_DtcType_LowBeamFlatDerateError,             .Index=4,   .DtcNumber=DemEventParameter_0xEF1068,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index5*/  {.DtcType=E_DtcType_TIDerateError,                      .Index=5,   .DtcNumber=DemEventParameter_0xEF1168,    .DtcDetType=E_DtcDetType_ASW_Cycle}, 
    /*********************************************20ms Test cycle*********************************************/
    /*index6*/  {.DtcType=E_DtcType_MatrixChip_LossCom,                 .Index=6,   .DtcNumber=DemEventParameter_0x980E87,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index7*/  {.DtcType=E_DtcType_IndcrOutSafe_CounterError,          .Index=7,   .DtcNumber=DemEventParameter_0xED8B82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index8*/  {.DtcType=E_DtcType_IndcrOutSafe_CrcError,              .Index=8,   .DtcNumber=DemEventParameter_0xED8B83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index9*/  {.DtcType=E_DtcType_VehModMngtGlbSafe1_CounterError,    .Index=9,   .DtcNumber=DemEventParameter_0xED5A82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index10*/ {.DtcType=E_DtcType_VehModMngtGlbSafe1_CrcError,        .Index=10,  .DtcNumber=DemEventParameter_0xED5A83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*********************************************40ms Test cycle*********************************************/
    /*index11*/ {.DtcType=E_DtcType_VehSpdLgtSafe_CounterError,         .Index=11,  .DtcNumber=DemEventParameter_0xED3E82,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index12*/ {.DtcType=E_DtcType_VehSpdLgtSafe_CrcError,             .Index=12,  .DtcNumber=DemEventParameter_0xED3E83,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*********************************************100ms Test cycle*********************************************/
    /*index13*/ {.DtcType=E_DtcType_WatchDogTimeout,                    .Index=13,  .DtcNumber=DemEventParameter_0x505547,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index14*/ {.DtcType=E_DtcType_KL15_OpenOrShort2Gnd,               .Index=14,  .DtcNumber=DemEventParameter_0x90E714,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index15*/ {.DtcType=E_DtcType_KL56_OpenOrShort2Gnd,               .Index=15,  .DtcNumber=DemEventParameter_0x95A214,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index16*/ {.DtcType=E_DtcType_EcuSupply_OverVoltage,              .Index=16,  .DtcNumber=DemEventParameter_0xEE0368,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index17*/ {.DtcType=E_DtcType_EcuSupply_UnderVoltage,             .Index=17,  .DtcNumber=DemEventParameter_0xEE0468,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index18*/ {.DtcType=E_DtcType_EcuSupply_BusSignal_Mismatch,       .Index=18,  .DtcNumber=DemEventParameter_0xF00362,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index19*/ {.DtcType=E_DtcType_FAN1_Stall,                         .Index=19,  .DtcNumber=DemEventParameter_0x95A771,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index20*/ {.DtcType=E_DtcType_FAN1ControlLine_Short2Gnd,          .Index=20,  .DtcNumber=DemEventParameter_0x95D511,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index21*/ {.DtcType=E_DtcType_FAN1ControlLine_Short2Battery,      .Index=21,  .DtcNumber=DemEventParameter_0x95D512,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index22*/ {.DtcType=E_DtcType_FAN1Supply_Short2Gnd,               .Index=22,  .DtcNumber=DemEventParameter_0x982111,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index23*/ {.DtcType=E_DtcType_FAN1Supply_OpenOrShort2Battery,     .Index=23,  .DtcNumber=DemEventParameter_0x982115,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index24*/ {.DtcType=E_DtcType_FAN1HSD_OverCurrent,                .Index=24,  .DtcNumber=DemEventParameter_0xD66419,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index25*/ {.DtcType=E_DtcType_HSD1_Short2Gnd,                     .Index=25,  .DtcNumber=DemEventParameter_0x95B211,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index26*/ {.DtcType=E_DtcType_HSD1_OpenOrShort2Battery,           .Index=26,  .DtcNumber=DemEventParameter_0x95B215,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index27*/ {.DtcType=E_DtcType_HSD1_OverCurrent,                   .Index=27,  .DtcNumber=DemEventParameter_0x95B219,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index28*/ {.DtcType=E_DtcType_HSD2_Short2Gnd,                     .Index=28,  .DtcNumber=DemEventParameter_0x95B311,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index29*/ {.DtcType=E_DtcType_HSD2_OpenOrShort2Battery,           .Index=29,  .DtcNumber=DemEventParameter_0x95B315,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index30*/ {.DtcType=E_DtcType_HSD2_OverCurrent,                   .Index=30,  .DtcNumber=DemEventParameter_0x95B319,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index31*/ {.DtcType=E_DtcType_HSD3_Short2Gnd,                     .Index=31,  .DtcNumber=DemEventParameter_0x95B411,    .DtcDetType=E_DtcDetType_ASW_Cycle},    
    /*index32*/ {.DtcType=E_DtcType_HSD3_OpenOrShort2Battery,           .Index=32,  .DtcNumber=DemEventParameter_0x95B415,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index33*/ {.DtcType=E_DtcType_HSD3_OverCurrent,                   .Index=33,  .DtcNumber=DemEventParameter_0x95B419,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index34*/ {.DtcType=E_DtcType_NTC1_Short2Gnd,                     .Index=34,  .DtcNumber=DemEventParameter_0x957011,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index35*/ {.DtcType=E_DtcType_NTC1_OpenOrShort2Battery,           .Index=35,  .DtcNumber=DemEventParameter_0x957015,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index36*/ {.DtcType=E_DtcType_NTC2_Short2Gnd,                     .Index=36,  .DtcNumber=DemEventParameter_0x957911,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index37*/ {.DtcType=E_DtcType_NTC2_OpenOrShort2Battery,           .Index=37,  .DtcNumber=DemEventParameter_0x957915,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index38*/ {.DtcType=E_DtcType_NTC3_Short2Gnd,                     .Index=38,  .DtcNumber=DemEventParameter_0x957A11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index39*/ {.DtcType=E_DtcType_NTC3_OpenOrShort2Battery,           .Index=39,  .DtcNumber=DemEventParameter_0x957A15,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index40*/ {.DtcType=E_DtcType_NTC4_Short2Gnd,                     .Index=40,  .DtcNumber=DemEventParameter_0x957E11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index41*/ {.DtcType=E_DtcType_NTC4_OpenOrShort2Battery,           .Index=41,  .DtcNumber=DemEventParameter_0x957E15,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index42*/ {.DtcType=E_DtcType_NTC5_Short2Gnd,                     .Index=42,  .DtcNumber=DemEventParameter_0x959011,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index43*/ {.DtcType=E_DtcType_NTC5_OpenOrShort2Battery,           .Index=43,  .DtcNumber=DemEventParameter_0x959015,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index44*/ {.DtcType=E_DtcType_MatrixChip_Ntc2Error,               .Index=44,  .DtcNumber=DemEventParameter_0xEF0E86,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index45*/ {.DtcType=E_DtcType_MatrixChip_Ntc1Error,               .Index=45,  .DtcNumber=DemEventParameter_0xEF0F86,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index46*/ {.DtcType=E_DtcType_Rcod1_Error,                        .Index=46,  .DtcNumber=DemEventParameter_0xEF7001,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index47*/ {.DtcType=E_DtcType_Rcod2_Error,                        .Index=47,  .DtcNumber=DemEventParameter_0xEF7101,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index48*/ {.DtcType=E_DtcType_Rcod3_Error,                        .Index=48,  .DtcNumber=DemEventParameter_0xEF7201,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index49*/ {.DtcType=E_DtcType_LeftRightError,                     .Index=49,  .DtcNumber=DemEventParameter_0x95A401,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index50*/ {.DtcType=E_DtcType_LeftRightMismatch,                  .Index=50,  .DtcNumber=DemEventParameter_0x95D309,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index51*/ {.DtcType=E_DtcType_Hall_ElectricalFailure,             .Index=51,  .DtcNumber=DemEventParameter_0x95A301,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index52*/ {.DtcType=E_DtcType_Hall_FeedbackConstantLow,           .Index=52,  .DtcNumber=DemEventParameter_0x95A323,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index53*/ {.DtcType=E_DtcType_Hall_FeedbackConstantHigh,          .Index=53,  .DtcNumber=DemEventParameter_0x95A324,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index54*/ {.DtcType=E_DtcType_Swivel_Overload,                    .Index=54,  .DtcNumber=DemEventParameter_0x95A801,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index55*/ {.DtcType=E_DtcType_Swivel_Openload,                    .Index=55,  .DtcNumber=DemEventParameter_0x95A813,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index56*/ {.DtcType=E_DtcType_Swivel_OverUse,                     .Index=56,  .DtcNumber=DemEventParameter_0x95A863,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index57*/ {.DtcType=E_DtcType_Swivel_InterError,                  .Index=57,  .DtcNumber=DemEventParameter_0x95D096,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index58*/ {.DtcType=E_DtcType_Swivel_StepLoss,                    .Index=58,  .DtcNumber=DTC_UNDEDNFIED,                .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index59*/ {.DtcType=E_DtcType_Level_Overload,                     .Index=59,  .DtcNumber=DemEventParameter_0x95A901,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index60*/ {.DtcType=E_DtcType_Level_Openload,                     .Index=60,  .DtcNumber=DemEventParameter_0x95A913,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index61*/ {.DtcType=E_DtcType_Level_OverUse,                      .Index=61,  .DtcNumber=DemEventParameter_0x95A963,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index62*/ {.DtcType=E_DtcType_Level_InterError,                   .Index=62,  .DtcNumber=DemEventParameter_0x95D196,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index63*/ {.DtcType=E_DtcType_Channel1_Short2Gnd,                 .Index=63,  .DtcNumber=DemEventParameter_0x95AA11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index64*/ {.DtcType=E_DtcType_Channel1_Short2Battery,             .Index=64,  .DtcNumber=DemEventParameter_0x95AA12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index65*/ {.DtcType=E_DtcType_Channel1_OpenLoad,                  .Index=65,  .DtcNumber=DemEventParameter_0x95AA13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index66*/ {.DtcType=E_DtcType_Channel2_Short2Gnd,                 .Index=66,  .DtcNumber=DemEventParameter_0x95AB11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index67*/ {.DtcType=E_DtcType_Channel2_Short2Battery,             .Index=67,  .DtcNumber=DemEventParameter_0x95AB12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index68*/ {.DtcType=E_DtcType_Channel2_OpenLoad,                  .Index=68,  .DtcNumber=DemEventParameter_0x95AB13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index69*/ {.DtcType=E_DtcType_Channel2_UnderVoltage,              .Index=69,  .DtcNumber=DemEventParameter_0x961021,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index70*/ {.DtcType=E_DtcType_Channel3_Short2Gnd,                 .Index=70,  .DtcNumber=DemEventParameter_0x95AC11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index71*/ {.DtcType=E_DtcType_Channel3_Short2Battery,             .Index=71,  .DtcNumber=DemEventParameter_0x95AC12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index72*/ {.DtcType=E_DtcType_Channel3_OpenLoad,                  .Index=72,  .DtcNumber=DemEventParameter_0x95AC13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index73*/ {.DtcType=E_DtcType_Channel3_UnderVoltage,              .Index=73,  .DtcNumber=DemEventParameter_0x961121,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index74*/ {.DtcType=E_DtcType_Channel4_Short2Gnd,                 .Index=74,  .DtcNumber=DemEventParameter_0x95AD11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index75*/ {.DtcType=E_DtcType_Channel4_Short2Battery,             .Index=75,  .DtcNumber=DemEventParameter_0x95AD12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index76*/ {.DtcType=E_DtcType_Channel4_OpenLoad,                  .Index=76,  .DtcNumber=DemEventParameter_0x95AD13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index77*/ {.DtcType=E_DtcType_Channel4_UnderVoltage,              .Index=77,  .DtcNumber=DemEventParameter_0x961221,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index78*/ {.DtcType=E_DtcType_Channel5_Short2Gnd,                 .Index=78,  .DtcNumber=DemEventParameter_0x95AE11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index79*/ {.DtcType=E_DtcType_Channel5_Short2Battery,             .Index=79,  .DtcNumber=DemEventParameter_0x95AE12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index80*/ {.DtcType=E_DtcType_Channel5_OpenLoad,                  .Index=80,  .DtcNumber=DemEventParameter_0x95AE13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index81*/ {.DtcType=E_DtcType_Channel5_UnderVoltage,              .Index=81,  .DtcNumber=DemEventParameter_0x961321,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index82*/ {.DtcType=E_DtcType_Channel6_Short2Gnd,                 .Index=82,  .DtcNumber=DemEventParameter_0x95AF11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index83*/ {.DtcType=E_DtcType_Channel6_Short2Battery,             .Index=83,  .DtcNumber=DemEventParameter_0x95AF12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index84*/ {.DtcType=E_DtcType_Channel6_OpenLoad,                  .Index=84,  .DtcNumber=DemEventParameter_0x95AF13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index85*/ {.DtcType=E_DtcType_Channel6_UnderVoltage,              .Index=85,  .DtcNumber=DemEventParameter_0x961421,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index86*/ {.DtcType=E_DtcType_Channel7_Short2Gnd,                 .Index=86,  .DtcNumber=DemEventParameter_0x95B011,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index87*/ {.DtcType=E_DtcType_Channel7_Short2Battery,             .Index=87,  .DtcNumber=DemEventParameter_0x95B012,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index88*/ {.DtcType=E_DtcType_Channel7_OpenLoad,                  .Index=88,  .DtcNumber=DemEventParameter_0x95B013,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index89*/ {.DtcType=E_DtcType_Channel7_UnderVoltage,              .Index=89,  .DtcNumber=DemEventParameter_0x961521,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index90*/ {.DtcType=E_DtcType_Channel8_Short2Gnd,                 .Index=90,  .DtcNumber=DemEventParameter_0x95B111,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index91*/ {.DtcType=E_DtcType_Channel8_Short2Battery,             .Index=91,  .DtcNumber=DemEventParameter_0x95B112,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index92*/ {.DtcType=E_DtcType_Channel8_OpenLoad,                  .Index=92,  .DtcNumber=DemEventParameter_0x95B113,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index93*/ {.DtcType=E_DtcType_Channel8_UnderVoltage,              .Index=93,  .DtcNumber=DemEventParameter_0x961621,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index94*/ {.DtcType=E_DtcType_Channel9_Short2Gnd,                 .Index=94,  .DtcNumber=DemEventParameter_0x968711,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index95*/ {.DtcType=E_DtcType_Channel9_Short2Battery,             .Index=95,  .DtcNumber=DemEventParameter_0x968712,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index96*/ {.DtcType=E_DtcType_Channel9_OpenLoad,                  .Index=96,  .DtcNumber=DemEventParameter_0x968713,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index97*/ {.DtcType=E_DtcType_Channel9_UnderVoltage,              .Index=97,  .DtcNumber=DemEventParameter_0x968721,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index98*/ {.DtcType=E_DtcType_Channel10_Short2Gnd,                .Index=98,  .DtcNumber=DemEventParameter_0x968A11,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index99*/ {.DtcType=E_DtcType_Channel10_Short2Battery,            .Index=99,  .DtcNumber=DemEventParameter_0x968A12,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index100*/{.DtcType=E_DtcType_Channel10_OpenLoad,                 .Index=100, .DtcNumber=DemEventParameter_0x968A13,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index101*/{.DtcType=E_DtcType_Channel10_UnderVoltage,             .Index=101, .DtcNumber=DemEventParameter_0x968A21,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index102*/{.DtcType=E_DtcType_Channel11_Short2Gnd,                .Index=102, .DtcNumber=DemEventParameter_0x96F511,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index103*/{.DtcType=E_DtcType_Channel11_Short2Battery,            .Index=103, .DtcNumber=DemEventParameter_0x96F512,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index104*/{.DtcType=E_DtcType_Channel11_OpenLoad,                 .Index=104, .DtcNumber=DemEventParameter_0x96F513,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index105*/{.DtcType=E_DtcType_Channel11_UnderVoltage,             .Index=105, .DtcNumber=DemEventParameter_0x96F521,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index106*/{.DtcType=E_DtcType_Channel12_Short2Gnd,                .Index=106, .DtcNumber=DemEventParameter_0x96F611,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index107*/{.DtcType=E_DtcType_Channel12_Short2Battery,            .Index=107, .DtcNumber=DemEventParameter_0x96F612,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index108*/{.DtcType=E_DtcType_Channel12_OpenLoad,                 .Index=108, .DtcNumber=DemEventParameter_0x96F613,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index109*/{.DtcType=E_DtcType_Channel12_UnderVoltage,             .Index=109, .DtcNumber=DemEventParameter_0x96F621,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index110*/{.DtcType=E_DtcType_BoostBuckError,                     .Index=110, .DtcNumber=DemEventParameter_0x95D296,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index111*/{.DtcType=E_DtcType_ECU_SpiError,                       .Index=111, .DtcNumber=DemEventParameter_0xE01449,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index112*/{.DtcType=E_DtcType_BuckOrBoost_OverTemperature,        .Index=112, .DtcNumber=DemEventParameter_0xE01498,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index113*/{.DtcType=E_DtcType_ParameterTable_VersionError,        .Index=113, .DtcNumber=DTC_UNDEDNFIED,                .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index114*/{.DtcType=E_DtcType_ParameterTable_CrcError,            .Index=114, .DtcNumber=DemEventParameter_0xE10156,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index115*/{.DtcType=E_DtcType_ChannelCurrentConfigError,          .Index=115, .DtcNumber=DemEventParameter_0xF0001C,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index116*/{.DtcType=E_DtcType_Rom_Error,                          .Index=116, .DtcNumber=DemEventParameter_0xD00246,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index117*/{.DtcType=E_DtcType_Ram_Error,                          .Index=117, .DtcNumber=DemEventParameter_0xD00544,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index118*/{.DtcType=E_DtcType_LvlgSwtSetReqChksError,             .Index=118, .DtcNumber=DemEventParameter_0x982341,    .DtcDetType=E_DtcDetType_ASW_Trigger},
    /*index119*/{.DtcType=E_DtcType_SuspPosnVertLvlQFError,             .Index=119, .DtcNumber=DemEventParameter_0xE79982,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index120*/{.DtcType=E_DtcType_SteerWhlSnsrQFError,                .Index=120, .DtcNumber=DemEventParameter_0xE79A82,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index121*/{.DtcType=E_DtcType_PinCodeNotWrited,                   .Index=121, .DtcNumber=DemEventParameter_0xD14B51,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index122*/{.DtcType=E_DtcType_PublicKeyNotWrited,                 .Index=122, .DtcNumber=DemEventParameter_0xD14C51,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index123*/{.DtcType=E_DtcType_MatrixRcod1_Error,                  .Index=123, .DtcNumber=DemEventParameter_0xEF1086,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index124*/{.DtcType=E_DtcType_MatrixRcod2_Error,                  .Index=124, .DtcNumber=DemEventParameter_0xEF1186,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index125*/{.DtcType=E_DtcType_DCMotor_Error,                      .Index=125, .DtcNumber=DemEventParameter_0x9DFB01,    .DtcDetType=E_DtcDetType_ASW_Cycle},
    /*index126*/{.DtcType=E_DtcType_CentralCfg_Error,                   .Index=126, .DtcNumber=DemEventParameter_0xE30057,    .DtcDetType=E_DtcDetType_ASW_Cycle},

};
#endif
static S_DtcTestGroup DtcTestGroup[DTC_TEST_GROUP_NUM]={
        {0,    Config_10ms_Group_NUM,    Config_10ms_TestPeriod_NUM,    Config_10ms_OnceTest_NUM,    &(g_DtcCondfig[Dtc10msStartIndex])},
        {0,    Config_20ms_Group_NUM,    Config_20ms_TestPeriod_NUM,    Config_20ms_OnceTest_NUM,    &(g_DtcCondfig[Dtc20msStartIndex])},
        {0,    Config_40ms_Group_NUM,    Config_40ms_TestPeriod_NUM,    Config_40ms_OnceTest_NUM,    &(g_DtcCondfig[Dtc40msStartIndex])},
        {0,    Config_100ms_Group_NUM,   Config_100ms_TestPeriod_NUM,   Config_100ms_OnceTest_NUM,   &(g_DtcCondfig[Dtc100msStartIndex])},
};



/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
const S_DtcConfig *GetDtcConfig(uint8_t index)
{
    if(index >= DTC_MAX_SIZE)
        return NULL;
    
    return &(g_DtcCondfig[index]);   
}

S_DtcTestGroup *GetDtcTestGroup(void)
{
    return DtcTestGroup;
}
