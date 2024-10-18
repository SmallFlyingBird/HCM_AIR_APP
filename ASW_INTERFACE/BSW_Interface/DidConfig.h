/*
 * DidConfig.h
 *
 *  Created on: 2024��1��15��
 *      Author: mihuiliang
 */
#ifndef _DIDCONFIG_H_
#define _DIDCONFIG_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"

#include "Rte_Dcm_Type.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define DID_CONFIG_VERSION_HIGH_BYTE 		1
#define DID_CONFIG_VERSION_MIDDLE_BYTE 		0
#define DID_CONFIG_VERSION_LOW_BYTE 		1


#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
#define DidIoCtr_NUM	18
#define DidConfig_NUM	44
#define DidSignal_NUM	294
#else
#define DidIoCtr_NUM	18
#define DidConfig_NUM	43
#define DidSignal_NUM	293
#endif

#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
#define DIDSIGNALE_8BIT_SIZE				195
#define DIDSIGNALE_16BIT_SIZE				66
#define DIDSIGNALE_32BIT_SIZE				33
#else
#define DIDSIGNALE_8BIT_SIZE				195
#define DIDSIGNALE_16BIT_SIZE				65
#define DIDSIGNALE_32BIT_SIZE				33
#endif

#define DIDNAME_ID_HeadlampFan 						0				/*434B*/
#define DIDNAME_ID_HeadlampCtrlModTemp				1				/*4351*/
#define DIDNAME_ID_HeadlampCtrlInputVol				2				/*4357*/
#define DIDNAME_ID_HeadlampSideMarkerLight			3				/*4358*/
#define DIDNAME_ID_HeadlampCtrlLEDCh1				4				/*4359*/
#define DIDNAME_ID_HeadlampCtrlLEDCh2				5				/*435B*/
#define DIDNAME_ID_HeadlampCtrlLEDCh3				6				/*435C*/
#define DIDNAME_ID_HeadlampCtrlLEDCh4				7				/*435D*/
#define DIDNAME_ID_HeadlampCtrlLEDCh5				8				/*435E*/
#define DIDNAME_ID_HeadlampCtrlLEDCh6				9				/*435F*/
#define DIDNAME_ID_HeadlampCtrlLEDCh7				10				/*4360*/
#define DIDNAME_ID_HeadlampCtrlLEDCh8				11				/*4361*/
#define DIDNAME_ID_HeadlampCtrlLEDCh9				12				/*4362*/
#define DIDNAME_ID_HeadlampCtrlLEDCh10				13				/*4363*/
#define DIDNAME_ID_HeadlampCtrlLEDCh11				14				/*4364*/
#define DIDNAME_ID_HeadlampCtrlLEDCh12				15				/*4367*/
#define DIDNAME_ID_HeadlampCtrlModLvlMotor			16				/*4365*/
#define DIDNAME_ID_HeadlampCtrlModSwlMotor			17				/*4366*/
#define DIDNAME_ID_HeadlampSts						18				/*4368*/
#define DIDNAME_ID_ControlModCfgData				19				/*437C*/
#define DIDNAME_ID_ControlModStaticData				20				/*43A8*/
#define DIDNAME_ID_HeadlampSeqIndic					21				/*43A9*/
#define DIDNAME_ID_SideDet							22				/*43CA*/
#define DIDNAME_ID_HeadlampCtrlBuck4Temp			23				/*43CE*/
#define DIDNAME_ID_HeadlampCtrlBuck1Temp			24				/*43CF*/
#define DIDNAME_ID_HeadlampCtrlBuck2Temp			25				/*43D0*/
#define DIDNAME_ID_HeadlampCtrlBuck3Temp			26				/*43D1*/
#define DIDNAME_ID_HeadlampCtrlBoostTemp			27				/*43D2*/
#define DIDNAME_ID_HeadlampCtrlLRDirVol				28				/*43D3*/
#define DIDNAME_ID_HeadlampCtrlHallInputVol			29				/*43D4*/
#define DIDNAME_ID_HeadlampCtrlFanSupplyVol			30				/*43D5*/
#define DIDNAME_ID_HeadlampCtrlLedDrvErr			31				/*43D7*/
#define DIDNAME_ID_HeadlampCtrlSwlMotorDrvErr		32				/*43D8*/
#define DIDNAME_ID_HeadlampCtrlLvlMotorDrvErr		33				/*43D9*/
#define DIDNAME_ID_HeadlampCtrlSideOfECU			34				/*43DA*/
#define DIDNAME_ID_HeadlampPixelCtrl				35				/*7022*/
#define DIDNAME_ID_CarMode							36				/*D134*/
#define DIDNAME_ID_GlobalRealTime					37				/*DD00*/
#define DIDNAME_ID_TotalDistance					38				/*DD01*/
#define DIDNAME_ID_VehicleBatteryVoltage			39				/*DD02*/
#define DIDNAME_ID_UsageMode						40				/*DD0A*/
#define DIDNAME_ID_ElectricPowerLevel				41				/*DD0C*/
#define DIDNAME_ID_GNSSTime				            42				/*DD07*/
#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
#define DIDNAME_ID_VehicleSpeed				        43				/*DD06*/
#endif 


/*434B*/
#define DIDSIGNALNAME_ID_Fan1Diagnosis 			0
#define DIDSIGNALNAME_ID_FAN2Control 			1
#define DIDSIGNALNAME_ID_Fan1supply 			2
#define DIDSIGNALNAME_ID_Fan1OutputControl 		3
#define DIDSIGNALNAME_ID_Fan1CurrentFeedback	4
/*4351*/
#define DIDSIGNALNAME_ID_Temperature			5
/*4357*/
#define DIDSIGNALNAME_ID_IgnitionRelay			6
#define DIDSIGNALNAME_ID_ExteriorLightRelay		7
/*4358*/
#define DIDSIGNALNAME_ID_SMLOutputStatus		8
#define DIDSIGNALNAME_ID_SMLCurFB				9
/*4359*/
#define DIDSIGNALNAME_ID_CH1OutputLuminosity	10
#define DIDSIGNALNAME_ID_CH1Current				11
#define DIDSIGNALNAME_ID_CH1ActualVol			12
#define DIDSIGNALNAME_ID_CH1ActualFreq			13
#define DIDSIGNALNAME_ID_CH1Function			14
#define DIDSIGNALNAME_ID_CH1ThermResTemp		15
/*435B*/
#define DIDSIGNALNAME_ID_CH2OutputLuminosity	16
#define DIDSIGNALNAME_ID_CH2Current				17
#define DIDSIGNALNAME_ID_CH2ActualVol			18
#define DIDSIGNALNAME_ID_CH2ActualFreq			19
#define DIDSIGNALNAME_ID_CH2Function			20
#define DIDSIGNALNAME_ID_CH2ThermResTemp		21
/*435C*/
#define DIDSIGNALNAME_ID_CH3OutputLuminosity	22
#define DIDSIGNALNAME_ID_CH3Current				23
#define DIDSIGNALNAME_ID_CH3ActualVol			24
#define DIDSIGNALNAME_ID_CH3ActualFreq			25
#define DIDSIGNALNAME_ID_CH3Function			26
#define DIDSIGNALNAME_ID_CH3ThermResTemp		27
/*435D*/
#define DIDSIGNALNAME_ID_CH4OutputLuminosity	28
#define DIDSIGNALNAME_ID_CH4Current				29
#define DIDSIGNALNAME_ID_CH4ActualVol			30
#define DIDSIGNALNAME_ID_CH4ActualFreq			31
#define DIDSIGNALNAME_ID_CH4Function			32
#define DIDSIGNALNAME_ID_CH4ThermResTemp		33
/*435E*/
#define DIDSIGNALNAME_ID_CH5OutputLuminosity	34
#define DIDSIGNALNAME_ID_CH5Current				35
#define DIDSIGNALNAME_ID_CH5ActualVol			36
#define DIDSIGNALNAME_ID_CH5ActualFreq			37
#define DIDSIGNALNAME_ID_CH5Function			38
#define DIDSIGNALNAME_ID_CH5ThermResTemp		39
/*435F*/
#define DIDSIGNALNAME_ID_CH6OutputLuminosity	40
#define DIDSIGNALNAME_ID_CH6Current				41
#define DIDSIGNALNAME_ID_CH6ActualVol			42
#define DIDSIGNALNAME_ID_CH6ActualFreq			43
#define DIDSIGNALNAME_ID_CH6Function			44
#define DIDSIGNALNAME_ID_CH6ThermResTemp		45
/*4360*/
#define DIDSIGNALNAME_ID_CH7OutputLuminosity	46
#define DIDSIGNALNAME_ID_CH7Current				47
#define DIDSIGNALNAME_ID_CH7ActualVol			48
#define DIDSIGNALNAME_ID_CH7ActualFreq			49
#define DIDSIGNALNAME_ID_CH7Function			50
#define DIDSIGNALNAME_ID_CH7ThermResTemp		51
/*4361*/
#define DIDSIGNALNAME_ID_CH8OutputLuminosity	52
#define DIDSIGNALNAME_ID_CH8Current				53
#define DIDSIGNALNAME_ID_CH8ActualVol			54
#define DIDSIGNALNAME_ID_CH8ActualFreq			55
#define DIDSIGNALNAME_ID_CH8Function			56
#define DIDSIGNALNAME_ID_CH8ThermResTemp		57
/*4362*/
#define DIDSIGNALNAME_ID_CH9OutputLuminosity	58
#define DIDSIGNALNAME_ID_CH9Current				59
#define DIDSIGNALNAME_ID_CH9ActualVol			60
#define DIDSIGNALNAME_ID_CH9ActualFreq			61
#define DIDSIGNALNAME_ID_CH9Function			62
#define DIDSIGNALNAME_ID_CH9ThermResTemp		63
/*4363*/
#define DIDSIGNALNAME_ID_CH10OutputLuminosity	64
#define DIDSIGNALNAME_ID_CH10Current			65
#define DIDSIGNALNAME_ID_CH10ActualVol			66
#define DIDSIGNALNAME_ID_CH10ActualFreq			67
#define DIDSIGNALNAME_ID_CH10Function			68
#define DIDSIGNALNAME_ID_CH10ThermResTemp		69
/*4364*/
#define DIDSIGNALNAME_ID_CH11OutputLuminosity	70
#define DIDSIGNALNAME_ID_CH11Current			71
#define DIDSIGNALNAME_ID_CH11ActualVol			72
#define DIDSIGNALNAME_ID_CH11ActualFreq			73
#define DIDSIGNALNAME_ID_CH11Function			74
#define DIDSIGNALNAME_ID_CH11ThermResTemp		75
/*4367*/
#define DIDSIGNALNAME_ID_CH12OutputLuminosity	76
#define DIDSIGNALNAME_ID_CH12Current			77
#define DIDSIGNALNAME_ID_CH12ActualVol			78
#define DIDSIGNALNAME_ID_CH12ActualFreq			79
#define DIDSIGNALNAME_ID_CH12Function			80
#define DIDSIGNALNAME_ID_CH12ThermResTemp		81
/*4365*/
#define DIDSIGNALNAME_ID_LvlSlewingAngle		82
#define DIDSIGNALNAME_ID_LvlStsRefRun			83
/*4366*/
#define DIDSIGNALNAME_ID_SwlSlewingAngle		84
#define DIDSIGNALNAME_ID_SwlStsRefRun			85
/*4368*/
#define DIDSIGNALNAME_ID_StsOfHB				86
#define DIDSIGNALNAME_ID_StsOfLB				87
#define DIDSIGNALNAME_ID_StsOfTI				88
#define DIDSIGNALNAME_ID_StsOfPL				89
#define DIDSIGNALNAME_ID_StsOfDRL				90
#define DIDSIGNALNAME_ID_StsOfFog				91
#define DIDSIGNALNAME_ID_StsOfCorner			92
#define DIDSIGNALNAME_ID_StsOfSML				93
#define DIDSIGNALNAME_ID_StsOfDBL				94
#define DIDSIGNALNAME_ID_StsOfAHL				95
#define DIDSIGNALNAME_ID_StsOfAFS				96
#define DIDSIGNALNAME_ID_StsOfAHBC				97
#define DIDSIGNALNAME_ID_StsOftTourist			98
#define DIDSIGNALNAME_ID_StsOfLightShowAct		99
#define DIDSIGNALNAME_ID_StsOfLightShowDoload	100
/*437C*/
#define DIDSIGNALNAME_ID_Ch1MaxCur				101
#define DIDSIGNALNAME_ID_Ch2MaxCur				102
#define DIDSIGNALNAME_ID_Ch3MaxCur				103
#define DIDSIGNALNAME_ID_Ch4MaxCur				104
#define DIDSIGNALNAME_ID_Ch5MaxCur				105
#define DIDSIGNALNAME_ID_Ch6MaxCur				106
#define DIDSIGNALNAME_ID_Ch7MaxCur				107
#define DIDSIGNALNAME_ID_Ch8MaxCur				108
#define DIDSIGNALNAME_ID_SideOfVehicle			109
#define DIDSIGNALNAME_ID_ProDateSecond			110
#define DIDSIGNALNAME_ID_ProDateMinute			111
#define DIDSIGNALNAME_ID_ProDateHour			112
#define DIDSIGNALNAME_ID_ProDateDay				113
#define DIDSIGNALNAME_ID_ProDateMonth			114
#define DIDSIGNALNAME_ID_ProDateYear			115
#define DIDSIGNALNAME_ID_ProDateReserved		116
#define DIDSIGNALNAME_ID_Ch9MaxCur				117
#define DIDSIGNALNAME_ID_Ch10MaxCur				118
#define DIDSIGNALNAME_ID_Ch11MaxCur				119
#define DIDSIGNALNAME_ID_Ch12MaxCur				120
/*43A8*/
#define DIDSIGNALNAME_ID_PeakCurCh1				121
#define DIDSIGNALNAME_ID_TotalRunTimeCh1		122
#define DIDSIGNALNAME_ID_PeakCurCh2				123
#define DIDSIGNALNAME_ID_TotalRunTimeCh2		124
#define DIDSIGNALNAME_ID_PeakCurCh3				125
#define DIDSIGNALNAME_ID_TotalRunTimeCh3		126
#define DIDSIGNALNAME_ID_PeakCurCh4				127
#define DIDSIGNALNAME_ID_TotalRunTimeCh4		128
#define DIDSIGNALNAME_ID_PeakCurCh5				129
#define DIDSIGNALNAME_ID_TotalRunTimeCh5		130
#define DIDSIGNALNAME_ID_PeakCurCh6				131
#define DIDSIGNALNAME_ID_TotalRunTimeCh6		132
#define DIDSIGNALNAME_ID_PeakCurCh7				133
#define DIDSIGNALNAME_ID_TotalRunTimeCh7		134
#define DIDSIGNALNAME_ID_PeakCurCh8				135
#define DIDSIGNALNAME_ID_TotalRunTimeCh8		136
#define DIDSIGNALNAME_ID_PeakTempRes1			137
#define DIDSIGNALNAME_ID_PeakTempRes2			138
#define DIDSIGNALNAME_ID_PeakTempRes3			139
#define DIDSIGNALNAME_ID_PeakTempRes4			140
#define DIDSIGNALNAME_ID_PeakTempRes5			141
#define DIDSIGNALNAME_ID_PeakTempCtrMod			142
#define DIDSIGNALNAME_ID_TotalNumLedDera		143
#define DIDSIGNALNAME_ID_TotalNumFanStart		144
#define DIDSIGNALNAME_ID_TotalNumFanStartDeic	145
#define DIDSIGNALNAME_ID_TotalNumFanStartDefog	146
#define DIDSIGNALNAME_ID_TotalRunTimeFan		147
#define DIDSIGNALNAME_ID_TotalNumLvlStep		148
#define DIDSIGNALNAME_ID_TotalNumSwlStep		149
#define DIDSIGNALNAME_ID_PeakCurCh9				150
#define DIDSIGNALNAME_ID_TotalRunTimeCh9		151
#define DIDSIGNALNAME_ID_PeakCurCh10			152
#define DIDSIGNALNAME_ID_TotalRunTimeCh10		153
#define DIDSIGNALNAME_ID_PeakCurCh11			154
#define DIDSIGNALNAME_ID_TotalRunTimeCh11		155
#define DIDSIGNALNAME_ID_PeakCurCh12			156
#define DIDSIGNALNAME_ID_TotalRunTimeCh12		157
/*43A9*/
#define DIDSIGNALNAME_ID_SeqIndcSts				158
#define DIDSIGNALNAME_ID_SeqCurFeedBack			159
/*43CA*/
#define DIDSIGNALNAME_ID_SideDetShort2VCC		160
#define DIDSIGNALNAME_ID_SideDetOpen			161
#define DIDSIGNALNAME_ID_SideDetShort2GND		162
/*43CE*/
#define DIDSIGNALNAME_ID_Buck4Temp				163
/*43CF*/
#define DIDSIGNALNAME_ID_Buck1Temp				164
/*43D0*/
#define DIDSIGNALNAME_ID_Buck2Temp				165
/*43D1*/
#define DIDSIGNALNAME_ID_Buck3Temp				166
/*43D2*/
#define DIDSIGNALNAME_ID_BoostTemp				167
/*43D3*/
#define DIDSIGNALNAME_ID_LRVol					168
/*43D4*/
#define DIDSIGNALNAME_ID_HallVol				169
/*43D5*/
#define DIDSIGNALNAME_ID_FanSupplyVol			170
/*43D7*/
#define DIDSIGNALNAME_ID_Ch1DrvErr				171
#define DIDSIGNALNAME_ID_Ch2DrvErr				172
#define DIDSIGNALNAME_ID_Ch3DrvErr				173
#define DIDSIGNALNAME_ID_Ch4DrvErr				174
#define DIDSIGNALNAME_ID_Ch5DrvErr				175
#define DIDSIGNALNAME_ID_Ch6DrvErr				176
#define DIDSIGNALNAME_ID_Ch7DrvErr				177
#define DIDSIGNALNAME_ID_Ch8DrvErr				178
#define DIDSIGNALNAME_ID_Ch9DrvErr				179
#define DIDSIGNALNAME_ID_Ch10DrvErr				180
#define DIDSIGNALNAME_ID_Ch11DrvErr				181
#define DIDSIGNALNAME_ID_Ch12DrvErr				182
/*43D8*/
#define DIDSIGNALNAME_ID_SwlDrvComLoss			183
#define DIDSIGNALNAME_ID_SwlDrvTemWarn			184
#define DIDSIGNALNAME_ID_SwlDrvTemShutDown		185
#define DIDSIGNALNAME_ID_SwlDrvUnderVol			186
#define DIDSIGNALNAME_ID_SwlDrvRegFail			187
#define DIDSIGNALNAME_ID_SwlDrvReserved			188
/*43D9*/
#define DIDSIGNALNAME_ID_LvlDrvComLoss			189
#define DIDSIGNALNAME_ID_LvlDrvTemWarn			190
#define DIDSIGNALNAME_ID_LvlDrvTemShutDown		191
#define DIDSIGNALNAME_ID_LvlDrvUnderVol			192
#define DIDSIGNALNAME_ID_LvlDrvRegFail			193
#define DIDSIGNALNAME_ID_LvlDrvReserved			194
/*43DA*/
#define DIDSIGNALNAME_ID_AppSideDet				195
#define DIDSIGNALNAME_ID_BootSideDet			196
/*7022*/
#define DIDSIGNALNAME_ID_Pixel1Acv				197
#define DIDSIGNALNAME_ID_Pixel2Acv				198
#define DIDSIGNALNAME_ID_Pixel3Acv				199
#define DIDSIGNALNAME_ID_Pixel4Acv				200
#define DIDSIGNALNAME_ID_Pixel5Acv				201
#define DIDSIGNALNAME_ID_Pixel6Acv				202
#define DIDSIGNALNAME_ID_Pixel7Acv				203
#define DIDSIGNALNAME_ID_Pixel8Acv				204
#define DIDSIGNALNAME_ID_Pixel9Acv				205
#define DIDSIGNALNAME_ID_Pixel10Acv				206
#define DIDSIGNALNAME_ID_Pixel11Acv				207
#define DIDSIGNALNAME_ID_Pixel12Acv				208
#define DIDSIGNALNAME_ID_Pixel13Acv				209
#define DIDSIGNALNAME_ID_Pixel14Acv				210
#define DIDSIGNALNAME_ID_Pixel15Acv				211
#define DIDSIGNALNAME_ID_Pixel16Acv				212
#define DIDSIGNALNAME_ID_Pixel17Acv				213
#define DIDSIGNALNAME_ID_Pixel18Acv				214
#define DIDSIGNALNAME_ID_Pixel19Acv				215
#define DIDSIGNALNAME_ID_Pixel20Acv				216
#define DIDSIGNALNAME_ID_Pixel21Acv				217
#define DIDSIGNALNAME_ID_Pixel22Acv				218
#define DIDSIGNALNAME_ID_Pixel23Acv				219
#define DIDSIGNALNAME_ID_Pixel24Acv				220
#define DIDSIGNALNAME_ID_Pixel25Acv				221
#define DIDSIGNALNAME_ID_Pixel26Acv				222
#define DIDSIGNALNAME_ID_Pixel27Acv				223
#define DIDSIGNALNAME_ID_Pixel28Acv				224
#define DIDSIGNALNAME_ID_Pixel29Acv				225
#define DIDSIGNALNAME_ID_Pixel30Acv				226
#define DIDSIGNALNAME_ID_Pixel31Acv				227
#define DIDSIGNALNAME_ID_Pixel32Acv				228
#define DIDSIGNALNAME_ID_Pixel33Acv				229
#define DIDSIGNALNAME_ID_Pixel34Acv				230
#define DIDSIGNALNAME_ID_Pixel35Acv				231
#define DIDSIGNALNAME_ID_Pixel36Acv				232
#define DIDSIGNALNAME_ID_Pixel37Acv				233
#define DIDSIGNALNAME_ID_Pixel38Acv				234
#define DIDSIGNALNAME_ID_Pixel39Acv				235
#define DIDSIGNALNAME_ID_Pixel40Acv				236
#define DIDSIGNALNAME_ID_Pixel41Acv				237
#define DIDSIGNALNAME_ID_Pixel42Acv				238
#define DIDSIGNALNAME_ID_Pixel43Acv				239
#define DIDSIGNALNAME_ID_Pixel44Acv				240
#define DIDSIGNALNAME_ID_Pixel45Acv				241
#define DIDSIGNALNAME_ID_Pixel46Acv				242
#define DIDSIGNALNAME_ID_Pixel47Acv				243
#define DIDSIGNALNAME_ID_Pixel48Acv				244
#define DIDSIGNALNAME_ID_Pixel49Acv				245
#define DIDSIGNALNAME_ID_Pixel50Acv				246
#define DIDSIGNALNAME_ID_Pixel51Acv				247
#define DIDSIGNALNAME_ID_Pixel52Acv				248
#define DIDSIGNALNAME_ID_Pixel53Acv				249
#define DIDSIGNALNAME_ID_Pixel54Acv				250
#define DIDSIGNALNAME_ID_Pixel55Acv				251
#define DIDSIGNALNAME_ID_Pixel56Acv				252
#define DIDSIGNALNAME_ID_Pixel57Acv				253
#define DIDSIGNALNAME_ID_Pixel58Acv				254
#define DIDSIGNALNAME_ID_Pixel59Acv				255
#define DIDSIGNALNAME_ID_Pixel60Acv				256
#define DIDSIGNALNAME_ID_Pixel61Acv				257
#define DIDSIGNALNAME_ID_Pixel62Acv				258
#define DIDSIGNALNAME_ID_Pixel63Acv				259
#define DIDSIGNALNAME_ID_Pixel64Acv				260
#define DIDSIGNALNAME_ID_Pixel65Acv				261
#define DIDSIGNALNAME_ID_Pixel66Acv				262
#define DIDSIGNALNAME_ID_Pixel67Acv				263
#define DIDSIGNALNAME_ID_Pixel68Acv				264
#define DIDSIGNALNAME_ID_Pixel69Acv				265
#define DIDSIGNALNAME_ID_Pixel70Acv				266
#define DIDSIGNALNAME_ID_Pixel71Acv				267
#define DIDSIGNALNAME_ID_Pixel72Acv				268
#define DIDSIGNALNAME_ID_Pixel73Acv				269
#define DIDSIGNALNAME_ID_Pixel74Acv				270
#define DIDSIGNALNAME_ID_Pixel75Acv				271
#define DIDSIGNALNAME_ID_Pixel76Acv				272
#define DIDSIGNALNAME_ID_Pixel77Acv				273
#define DIDSIGNALNAME_ID_Pixel78Acv				274
#define DIDSIGNALNAME_ID_Pixel79Acv				275
#define DIDSIGNALNAME_ID_Pixel80Acv				276
#define DIDSIGNALNAME_ID_Pixel81Acv				277
#define DIDSIGNALNAME_ID_Pixel82Acv				278
#define DIDSIGNALNAME_ID_Pixel83Acv				279
#define DIDSIGNALNAME_ID_Pixel84Acv				280
/*D134*/
#define DIDSIGNALNAME_ID_CarMode				281
/*DD00*/
#define DIDSIGNALNAME_ID_GlobalRealTime			282
/*DD01*/
#define DIDSIGNALNAME_ID_GlobalTotalDistance	283
/*DD02*/
#define DIDSIGNALNAME_ID_VehBatteryVol			284
/*DD0A*/
#define DIDSIGNALNAME_ID_UsageMode				285
/*DD0C*/
#define DIDSIGNALNAME_ID_ElectricPowerLevel		286
/*DD07*/
#define DIDSIGNALNAME_ID_GNSSUTCTimeYear		287
#define DIDSIGNALNAME_ID_GNSSUTCTimeMonth		288
#define DIDSIGNALNAME_ID_GNSSUTCTimeDay		    289
#define DIDSIGNALNAME_ID_GNSSUTCTimeHour		290
#define DIDSIGNALNAME_ID_GNSSUTCTimeMinute		291
#define DIDSIGNALNAME_ID_GNSSUTCTimeSecond		292
#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
/*DD06*/
#define DIDSIGNALNAME_ID_VehicleSpeed		    293
#endif
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
struct DidSignal;

typedef enum{
	E_SignalSort_Motorola=0,
	E_SignalSort_Intel,
}E_SignalSort;



typedef enum{
	E_IoCtrlMaskSupport_NoMask=0,
	E_IoCtrlMaskSupport_MaskAtStartByte,
	E_IoCtrlMaskSupport_MaskAtEndByte,
}E_IoCtrlMaskSupport;

typedef union{
	uint8_t DidPermissions;
	struct{
		uint8_t Service_0x22 	:1;
		uint8_t Service_0x2E 	:1;
		uint8_t Service_0x2F 	:1;
	}bits;
}U_DidPermissions;

typedef enum{
	E_IOCtrType_ReturnControl=0,
	E_IOCtrType_FreeCurState=2,
	E_IOCtrType_ShortTermAdjustment=3,
}E_IOCtrType;

typedef struct IoCtrInfo{
	E_IOCtrType CurIoCtrState;
	E_IoCtrlMaskSupport IoCtrlMaskSupport;
	uint8_t* DidIOCtrlDataSrc;		
	Std_ReturnType (*IoCtrCallBack)(E_IOCtrType IOCtrTypeState);
}S_IoCtrInfo;

typedef struct DidConfig{
	uint8_t DidDataLength;				/*byte*/
	U_DidPermissions DidPermissions;
	uint8_t *DidDataSrc;
	S_IoCtrInfo *IoCtrInfo;
	Std_ReturnType (*Init)(Dcm_OpStatusType OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode);  
}S_DidConfig;


typedef struct DidSignal{
	E_SignalSort SignalSort;			/*�ź����ͣ�Ħ�������������ض�*/
	uint8_t DidSignalLengths;			/*bits*/
	uint16_t SignalRunTimeBufferID;		/*�ź�����RunTimeBuffer���������*/
	uint16_t DidSignalLSBBits;			/*�ź����λ���ڵ�bitλ*/
	uint16_t BelongToDidIndex;			/*��������һ��DID����*/
}S_DidSignal;

/****************************************************************
 *                                                              *
 *                   Global Variable                            *
 *                                                              *
 ****************************************************************/
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType ResettAllIoctrToDefault(void);
Std_ReturnType SetDidIoCtrState(uint8_t DidNameId,E_IOCtrType IOCtrType);
const S_DidConfig *GetDidConfig(uint16_t index);
const S_DidSignal* GetDidSignal(uint16_t index);

#endif
