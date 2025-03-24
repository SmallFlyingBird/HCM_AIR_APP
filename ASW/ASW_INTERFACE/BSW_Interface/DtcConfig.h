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

#define DTC_MAX_SIZE   86
#define DTC_VALUE_SIZE 11 /*86 DTC，need 11 uint8_t data*/

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
    /*index0*/  E_DtcType_Channel1_UnderVoltage             =0,      
    /*index1*/  E_DtcType_Busoff                            =1,      
    /*index2*/  E_DtcType_ActnOfLedLoBeam_CounterError      =2,      
    /*index3*/  E_DtcType_ActnOfLedLoBeam_CrcError          =3,      
    /*index4*/  E_DtcType_LowBeamFlatDerateError            =4,      
    /*index5*/  E_DtcType_TIDerateError                     =5,      
    /*index17*/ E_DtcType_IndcrOutSafe_CounterError         =6,      
    /*index18*/ E_DtcType_IndcrOutSafe_CrcError             =7,      

    /*index23*/ E_DtcType_WatchDogTimeout                   =8,      
    /*index24*/ E_DtcType_KL15_OpenOrShort2Gnd              =9,        
    /*index25*/ E_DtcType_KL56_OpenOrShort2Gnd              =10,     
    /*index26*/ E_DtcType_EcuSupply_OverVoltage             =11,     
    /*index27*/ E_DtcType_EcuSupply_UnderVoltage            =12,     
    /*index28*/ E_DtcType_EcuSupply_BusSignal_Mismatch      =13,     
    /*index29*/ E_DtcType_FAN1_Stall                        =14,     
    /*index30*/ E_DtcType_FAN1ControlLine_Short2Gnd         =15,  

    /*index31*/ E_DtcType_FAN1ControlLine_Short2Battery     =16,     
    /*index32*/ E_DtcType_FAN1Supply_Short2Gnd              =17,     
    /*index33*/ E_DtcType_FAN1Supply_OpenOrShort2Battery    =18,     
    /*index34*/ E_DtcType_FAN1HSD_OverCurrent               =19,     
    /*index35*/ E_DtcType_HSD1_Short2Gnd                    =20,     
    /*index36*/ E_DtcType_HSD1_OpenOrShort2Battery          =21,     
    /*index37*/ E_DtcType_HSD1_OverCurrent                  =22,       
    /*index38*/ E_DtcType_HSD2_Short2Gnd                    =23,  

    /*index39*/ E_DtcType_HSD2_OpenOrShort2Battery          =24,     
    /*index40*/ E_DtcType_HSD2_OverCurrent                  =25,           
    /*index44*/ E_DtcType_NTC1_Short2Gnd                    =26,     
    /*index45*/ E_DtcType_NTC1_OpenOrShort2Battery          =27,     
    /*index46*/ E_DtcType_NTC2_Short2Gnd                    =28,     
    /*index47*/ E_DtcType_NTC2_OpenOrShort2Battery          =29,     
    /*index48*/ E_DtcType_NTC3_Short2Gnd                    =30,     
    /*index49*/ E_DtcType_NTC3_OpenOrShort2Battery          =31,  

    /*index50*/ E_DtcType_NTC4_Short2Gnd                    =32,     
    /*index51*/ E_DtcType_NTC4_OpenOrShort2Battery          =33,     
    /*index52*/ E_DtcType_NTC5_Short2Gnd                    =34,     
    /*index53*/ E_DtcType_NTC5_OpenOrShort2Battery          =35,     
    /*index56*/ E_DtcType_Rcod1_Error                       =36,     
    /*index57*/ E_DtcType_Rcod2_Error                       =37,     
    /*index58*/ E_DtcType_Rcod3_Error                       =38,     
    /*index59*/ E_DtcType_LeftRightError                    =39,   

    /*index60*/ E_DtcType_LeftRightMismatch                 =40,     
    /*index61*/ E_DtcType_Hall_ElectricalFailure            =41,     
    /*index62*/ E_DtcType_Hall_FeedbackConstantLow          =42,     
    /*index63*/ E_DtcType_Hall_FeedbackConstantHigh         =43,     
    /*index73*/ E_DtcType_Channel1_Short2Gnd                =44,     
    /*index74*/ E_DtcType_Channel1_Short2Battery            =45,     
    /*index75*/ E_DtcType_Channel1_OpenLoad                 =46,     
    /*index88*/ E_DtcType_Channel1Tap_Short2Gnd             =47,

    /*index89*/ E_DtcType_Channel1Tap_Short2Battery         =48,     
    /*index90*/ E_DtcType_Channel1Tap_OpenLoad              =49,     
    /*index91*/ E_DtcType_Channel1Tap_UnderVoltage          =50,     
    /*index76*/ E_DtcType_Channel2_Short2Gnd                =51,     
    /*index77*/ E_DtcType_Channel2_Short2Battery            =52,     
    /*index78*/ E_DtcType_Channel2_OpenLoad                 =53,     
    /*index79*/ E_DtcType_Channel2_UnderVoltage             =54,     
    /*index92*/ E_DtcType_Channel2Alt_Short2Gnd             =55,

    /*index93*/ E_DtcType_Channel2Alt_Short2Battery         =56,     
    /*index94*/ E_DtcType_Channel2Alt_OpenLoad              =57,     
    /*index95*/ E_DtcType_Channel2Alt_UnderVoltage          =58,     
    /*index80*/ E_DtcType_Channel3_Short2Gnd                =59,     
    /*index81*/ E_DtcType_Channel3_Short2Battery            =60,     
    /*index82*/ E_DtcType_Channel3_OpenLoad                 =61,     
    /*index83*/ E_DtcType_Channel3_UnderVoltage             =62,     
    /*index84*/ E_DtcType_Channel4_Short2Gnd                =63,   

    /*index85*/ E_DtcType_Channel4_Short2Battery            =64,     
    /*index86*/ E_DtcType_Channel4_OpenLoad                 =65,     
    /*index87*/ E_DtcType_Channel4_UnderVoltage             =66,     
    /*index120*/E_DtcType_BoostBuckError                    =67,     
    /*index121*/E_DtcType_ECU_SpiError                      =68,     
    /*index122*/E_DtcType_BuckOrBoost_OverTemperature       =69,     
    /*index123*/E_DtcType_ParameterTable_VersionError       =70,     
    /*index124*/E_DtcType_ParameterTable_CrcError           =71,
         
    /*index125*/E_DtcType_ChannelCurrentConfigError         =72,     
    /*index135*/E_DtcType_DCMotor_Error                     =73,     
    /*index136*/E_DtcType_CentralCfg_Error                  =74,   
} E_DtcType;

typedef struct DtcConfig
{
    E_DtcType DtcType;
    uint8_t Index;
    // uint32_t DtcNumber; //dem xxx
    E_DtcDetType DtcDetType;
} S_DtcConfig;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

#endif /* ASW_INTERFACE_DID_DTC_INTERFACE_DTCCONFIG_H_ */
