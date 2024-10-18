/*
 * LightPattern.h
 *
 *  Created on: 2024/04/09
 *      Author: SiboWANG
 */

#ifndef DYNAMICLIGHTEFFECTS_DYNAMIC_LIGHT_FUNCTION_H_
#define DYNAMICLIGHTEFFECTS_DYNAMIC_LIGHT_FUNCTION_H_


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AppCommonFunction.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define Dynamic_Effect_Simple_Execution 		0

#define Exterior_Light_Show_OffsetPrm			(uint8)20
#define Exterior_Light_Show_ContinuePrm			(uint8)10
#define Exterior_Light_Show_LowBrightnessPrm	(uint8)10
#define Exterior_Light_Show_HighBrightnessPrm	(uint8)10
#define Exterior_Light_Show_Cycle				(uint8)20
#define Light_Patterns_OffsetPrm				(uint8)20
#define Light_Patterns_ContinuePrm				(uint8)10
#define Light_Patterns_LowBrightnessPrm			(uint8)10
#define Light_Patterns_HighBrightnessPrm		(uint8)10
#define Light_Patterns_Cycle					(uint8)20
#define Dynamic_Charging_OffsetPrm				(uint8)20
#define Dynamic_Charging_ContinuePrm			(uint8)10
#define Dynamic_Charging_LowBrightnessPrm		(uint8)10
#define Dynamic_Charging_HighBrightnessPrm		(uint8)10
#define Dynamic_Charging_Cycle					(uint8)20

#define Dynamic_Light_Function_TOTAL_Groups		(uint8)24
#define Dynamic_Light_Pattern_TOTAL_Steps		(uint8)10
#define Dynamic_Light_Show_TOTAL_Steps			(uint16)300
#define Dynamic_Light_Function_Timestamp		(uint8)7
#define Dynamic_Charging_TOTAL_Steps			(uint8)3

#define Channel_Max_Output_PWM_Percentage		(uint8)100

#define Exterior_Light_Show_Execute_Info_Total_Size	(uint32)43500
#define Welcome_Pattern_Execute_Info_Total_Size		(uint32)4470

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
 typedef struct Dynamic_Light_Function_Parameters_Info{
	uint8	Dynamic_Parameters_Timestamp;
	uint8	Dynamic_Parameters_Mode;
	uint8	Dynamic_Parameters_OffsetTime;
	uint8	Dynamic_Parameters_ContinueTime;
	uint8	Dynamic_Parameters_LowBrightness;
	uint8	Dynamic_Parameters_HighBrightness;
}S_Dynamic_Light_Function_Parameters_Info;

typedef struct Dynamic_Light_Effect_Channel_And_Pixel_PWM_Inf{
	uint8	Low_High_Pixel_PWM_Info[84];
	uint8	TI_Pixel_PWM_Info[48];
	uint8	DRL_Pos_Pixel_PWM_Info[48];
	uint8	Grille_Pixel_PWM_Info[48];
	uint8	Logo_Pixel_PWM_Info[24];
	uint8	Assistant_Pixel_PWM_Info[24];
	uint8	Front_Cross_Pixel_PWM_Info[36];
	uint8	CC_Channel_PWM_Info[12];
}S_Dynamic_Light_Effect_Channel_And_Pixel_PWM_Info;

typedef struct Dynamic_Light_Effect_ReUse_Flag_Info{
	uint8	Low_High_Pixel_PWM[84];
	uint8	Low_High_Pixel_Run_Count[84];
	uint8	TI_Pixel_PWM[48];
	uint8	TI_Pixel_Run_Count[48];
	uint8	DRL_Pos_Pixel_PWM[48];
	uint8	DRL_Pos_Pixel_Run_Count[48];
	uint8	Grille_Pixel_PWM[48];
	uint8	Grille_Pixel_Run_Count[48];
	uint8	Logo_Pixel_PWM[24];
	uint8	Logo_Pixel_Run_Count[24];
	uint8	Assistant_Pixel_PWM[24];
	uint8	Assistant_Pixel_Run_Count[24];
	uint8	Front_Cross_Pixel_PWM[36];
	uint8	Front_Cross_Pixel_Run_Count[36];
}S_Dynamic_Light_Effect_ReUse_Flag_Info;

typedef struct Dynamic_Light_Pattern_Welcome_Parameters_Info{
	uint8	Welcome_Patterns_Mode_1_Updated_Flag;
	uint8	Welcome_Patterns_Mode_2_Updated_Flag;
	uint8	Welcome_Patterns_Mode_3_Updated_Flag;
	uint8	Welcome_Patterns_Download_Step[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Welcome_Patterns_Download_TimeStamp[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Welcome_Patterns_Download_Finished_Status[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Welcome_Patterns_StepCount[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Welcome_Patterns_Store_Retrieve_Start_Finish_Flag;
	uint8	Welcome_Patterns_Download_Start_Finish_Flag;
	uint8	Welcome_Patterns_Mode_Stored;
	S_Dynamic_Light_Function_Parameters_Info	Welcome_Patterns_Mode_1[Dynamic_Light_Function_TOTAL_Groups][Dynamic_Light_Pattern_TOTAL_Steps];
	S_Dynamic_Light_Function_Parameters_Info	Welcome_Patterns_Mode_2[Dynamic_Light_Function_TOTAL_Groups][Dynamic_Light_Pattern_TOTAL_Steps];
	S_Dynamic_Light_Function_Parameters_Info	Welcome_Patterns_Mode_3[Dynamic_Light_Function_TOTAL_Groups][Dynamic_Light_Pattern_TOTAL_Steps];
}S_Dynamic_Light_Pattern_Welcome_Parameters_Info;

typedef struct Dynamic_Light_Pattern_Execute_Info{
	uint16	Light_Pattern_Step[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Light_Pattern_TimeStamp[Dynamic_Light_Function_TOTAL_Groups];
	uint16	Light_Pattern_TimeCount[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Light_Pattern_Actvn_Finished_Status[Dynamic_Light_Function_TOTAL_Groups];
	uint16	Light_Pattern_OffsTiPrm_t;
	uint16	Light_Pattern_ContTiPrm_t;
	uint8	Light_Pattern_LowBriPrm_t;
	uint8	Light_Pattern_UpperBriPrm_t;
	uint8	Light_Pattern_Status;
	uint8	Light_Pattern_Mode_Flag;
	uint8	Light_Pattern_Cycle_Mode;
	uint8	Light_Pattern_Welcome_Interruptted_Flag;
	uint8	Light_Pattern_Goodbye_Interruptted_Flag;
	uint8	Light_Pattern_WaitMode_Interruptted_Flag;
	uint8	Light_Pattern_Approach_Interruptted_Flag;
	uint8	Light_Pattern_HomeSafety_Interruptted_Flag;
	uint8	Light_Pattern_Locator_Interruptted_Flag;
	uint8	Light_Pattern_Group_Offset_Flag[Dynamic_Light_Function_TOTAL_Groups];
	S_Dynamic_Light_Function_Parameters_Info Light_Pattern_To_Execute[Dynamic_Light_Function_TOTAL_Groups][Dynamic_Light_Pattern_TOTAL_Steps+1];
}S_Dynamic_Light_Pattern_Execute_Info;

typedef struct Dynamic_Light_Show_Execute_Info{
	uint16	Light_Show_Control_Step[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Light_Show_Control_TimeStamp[Dynamic_Light_Function_TOTAL_Groups];
	uint16	Light_Show_Control_TimeCount[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Light_Show_Control_Finished_Status[Dynamic_Light_Function_TOTAL_Groups];
	uint16	Light_Show_Download_Step[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Light_Show_Download_TimeStamp[Dynamic_Light_Function_TOTAL_Groups];
	uint8	Light_Show_Download_Finished_Status[Dynamic_Light_Function_TOTAL_Groups];
	uint16	Light_Show_StepCount[Dynamic_Light_Function_TOTAL_Groups];
	uint16	Light_Show_OffsTiPrm_t;
	uint16	Light_Show_ContTiPrm_t;
	uint8	Light_Show_LowBriPrm_t;
	uint8	Light_Show_UpperBriPrm_t;

	uint8	Light_Show_Store_Retrieve_Start_Finish_Flag;
	uint8	Light_Show_Download_Start_Finish_Flag;
	uint8	Light_Show_Status;
	uint8	Light_Show_Interruptted_Flag;

	uint8	Light_Show_Group_Offset_Flag[Dynamic_Light_Function_TOTAL_Groups];
	S_Dynamic_Light_Function_Parameters_Info Light_Show_Parameters[Dynamic_Light_Function_TOTAL_Groups][Dynamic_Light_Show_TOTAL_Steps];
}S_Dynamic_Light_Show_Execute_Info;

typedef struct Dynamic_Charging_Execute_Info{
	uint8	Charging_PositionLight_Step;
	uint16	Charging_PositionLight_TimeCount;
	
	uint8	Charging_GrilleLamp_Step;
	uint16	Charging_GrilleLamp_TimeCount;
	
	uint8	Charging_LogoLamp_Step;
	uint16	Charging_LogoLamp_TimeCount;
	
	uint8	Charging_FrontCrossLamp_Step;
	uint16	Charging_FrontCrossLamp_TimeCount;

	uint8	Charging_PositionLight_PWM_Value;
	uint8	Charging_GrilleLamp_PWM_Value;
	uint8	Charging_LogoLamp_PWM_Value;
	uint8	Charging_FrontCrossLamp_PWM_Value;

	S_Dynamic_Light_Function_Parameters_Info Charging_Parameters[Dynamic_Charging_TOTAL_Steps+1];
}S_Dynamic_Charging_Execute_Info;

typedef struct Dynamic_Function_State_Info{
	uint8	LightID;
	uint8	LightState;
	uint8	LightErrorState;
	uint32	LightOnTime;
}S_Dynamic_Function_State_Info;

typedef struct Dynamic_Function_Signal_Info{
	uint8		Welcome_Pattern_Actvn_Signal;
	uint8		Goodbye_Pattern_Actvn_Signal;
	uint8		WelcomeGoodbyeModeReq_Signal;
	uint8		Car_Locator_Pattern_Actvn_Signal;
	uint8		Car_Approach_Pattern_Actvn_Signal;
	uint8		HomeSafety_Pattern_Actvn_Signal;
	uint8		Waitmode_Pattern_Actvn_Signal;
	uint8		ExtrLiShowFileTxReq_Signal;
	uint8		ExtrLiShowActvnReq_Signal;
	uint8		WelLiFileTxReq_Signal;
}S_Dynamic_Function_Signal_Info;

typedef enum{
	OFF_Sts=0x00,
	ON_Sts=0x01,
	ERR_Sts=0x02,
	RESD_Sts=0x03,
}E_Dynamic_Function_State_Status;

typedef enum{
	LIGHT_Welcome_ID = 0,
	LIGHT_Goodbye_ID = 1,
	LIGHT_WaitMode_ID = 2,
	LIGHT_Charging_PositionLight_ID=3,
	LIGHT_Charging_GrilleLamp_ID=4,
	LIGHT_Charging_LogoLamp_ID=5,
	LIGHT_Charging_FrontCrossLamp_ID=6,
	LIGHT_Car_Approach_ID=7,
	LIGHT_HomeSafety_ID=8,
	LIGHT_Car_Locator_ID=9,
	LIGHT_GrilleLamp_Comity=10,
	LIGHT_GrilleLamp_Spkr=11,
	LIGHT_GrilleLamp_Wait=12,
	LIGHT_FrontCrossLamp_Comity=13,
	LIGHT_Light_Show_Control_ID = 14,
	LIGHT_Light_Show_Download_ID = 15,
	LIGHT_Light_Show_Store_ID = 16,
	LIGHT_Light_Show_Retrieve_ID = 17,
	LIGHT_Welcome_Pattern_Download_ID = 18,
	LIGHT_Welcome_Pattern_Store_ID = 19,
	LIGHT_Welcome_Pattern_Retrieve_ID = 20,

	LIGHT_Function_Total_ID = 21,
}E_Dynamic_LIGHT_Function_ID;

typedef enum{
	MODE_0_NORMAL_Off = 0,
	MODE_1_NORMAL_On = 1,
	MODE_2_Gradual_On = 2,
	MODE_3_Gradual_Off = 3,
	MODE_4_Forward_Wiping_On = 4,
	MODE_5_Backward_Wiping_On = 5,
	MODE_6_Outward_Wiping_On = 6,
	MODE_7_Inward_Wiping_On = 7,
	MODE_8_Forward_Wiping_Off = 8,
	MODE_9_Backward_Wiping_Off = 9,
	MODE_10_Outward_Wiping_Off = 10,
	MODE_11_Inward_Wiping_Off = 11,
	MODE_12_Forward_Scanning = 12,
	MODE_13_Backward_Scanning = 13,
	MODE_14_Alternate_Shinning_Forward = 14,
	MODE_15_Alternate_Shinning_Backward = 15,
	MODE_16_Half_On_And_Half_Off = 16,
	MODE_17_Half_Off_And_Half_On = 17,
	MODE_18_Half_Dimming_On_Half_Off = 18,
	MODE_19_Half_Dimming_On_Half_On = 19,
	MODE_20_Half_Off_Half_Dimming_On = 20,
	MODE_21_Half_On_Half_Dimming_On = 21,
	MODE_22_Half_Dimming_Off_Half_Off = 22,
	MODE_23_Half_Dimming_Off_Half_On = 23,
	MODE_24_Half_Off_Half_Dimming_Off = 24,
	MODE_25_Half_On_Half_Dimming_Off = 25,
	MODE_26_Single_On_Unit_1_On = 26,
	MODE_27_Single_On_Unit_2_On = 27,
	MODE_28_Single_On_Unit_3_On = 28,
	MODE_29_Single_On_Unit_4_On = 29,
	MODE_30_Single_On_Unit_5_On = 30,
	MODE_31_Single_On_Unit_6_On = 31,
	MODE_32_Single_On_Unit_7_On = 32,
	MODE_33_Single_On_Unit_8_On = 33,
	MODE_34_Single_On_Unit_9_On = 34,
	MODE_35_Single_On_Unit_10_On = 35,
	MODE_36_Single_On_Unit_11_On = 36,
	MODE_37_Single_On_Unit_12_On = 37,
	MODE_38_Single_Off_Unit_1_Off = 38,
	MODE_39_Single_Off_Unit_2_Off = 39,
	MODE_40_Single_Off_Unit_3_Off = 40,
	MODE_41_Single_Off_Unit_4_Off = 41,
	MODE_42_Single_Off_Unit_5_Off = 42,
	MODE_43_Single_Off_Unit_6_Off = 43,
	MODE_44_Single_Off_Unit_7_Off = 44,
	MODE_45_Single_Off_Unit_8_Off = 45,
	MODE_46_Single_Off_Unit_9_Off = 46,
	MODE_47_Single_Off_Unit_10_Off = 47,
	MODE_48_Single_Off_Unit_11_Off = 48,
	MODE_49_Single_Off_Unit_12_Off = 49,
	MODE_50_Gradual_On_Plus_Forward_Wiping_On = 50,
	MODE_51_Gradual_On_Plus_Backward_Wiping_On = 51,
	MODE_52_Gradual_Off_Plus_Forward_Wiping_Off = 52,
	MODE_53_Gradual_Off_Plus_Backward_Wiping_Off = 53,
	MODE_54_Shinning_And_Forward_Scanning_Wiping_On = 54,
	MODE_55_Shinning_And_Backward_Scanning_Wiping_Off = 55,
	MODE_56_Shinning_Plus_Gradual_On_Plus_Forward_Wiping_On = 56,
	MODE_57_Shinning_Plus_Gradual_On_Plus_Backward_Wiping_On = 57,
	MODE_58_Flash_Plus_Gradual_Off_Plus_Forward_Wiping_On = 58,
	MODE_59_Flash_Plus_Gradual_Off_Plus_Backward_Wiping_On = 59,
	MODE_60_Alternative_Shinning_Plus_Forward_Wiping_On = 60,
	MODE_61_Alternative_Shinning_Plus_Backward_Wiping_On = 61,
	
	MODE_RESET = 255,
}E_Exterior_Light_Show_Mode;

typedef enum{
	Store_Retrieve_Reset			=	0x00,
	Store_Retrieve_Store_Start		=	0x01,
	Store_Retrieve_Store_Finish		=	0x02,
	Store_Retrieve_Retrieve_Start	=	0x03,
	Store_Retrieve_Retrieve_Finish	=	0x04,
	Store_Retrieve_Validate_Start	=	0x05,
	Store_Retrieve_Validate_Finish	=	0x06,
	Store_Retrieve_Validate_Error	=	0x07,
}E_ExtrLiShow_Store_Retrieve_Flag;

typedef enum{
	Download_Reset		=	0x00,
	Download_Start		=	0x01,
	Download_Finish		=	0x02,
	Download_Error		=	0x03,
}E_ExtrLiShow_Download_Flag;

typedef enum{
	Dynamic_Light_Status_TurnOff		= 0,
	Dynamic_Light_Status_TurnOn			= 1,
	Dynamic_Light_Status_Interrupt		= 2,
	Dynamic_Light_Status_Invalid		= 3,
}E_Dynamic_Light_Status;

typedef enum{
	ModeReq_Mode1	=	0x00,
	ModeReq_Mode2	=	0x01,
	ModeReq_Mode3	=	0x02,
	ModeReq_Mode4	=	0x03,
	ModeReq_Mode5	=	0x04,
	ModeReq_Mode6	=	0x05,
	ModeReq_Reset	=	0x06,
}E_LightPattern_Mode;

typedef enum{
	OFF_Welcome_Pattern = 0x00,
	ON_Welcome_Pattern = 0x01,
}E_Welcome_Pattern_Actvn;

typedef enum{
	OFF_Goodbye_Pattern = 0x00,
	ON_Goodbye_Pattern = 0x01,
}E_Goodbye_Pattern_Actvn;

typedef enum{
	OFF_Locator_Pattern = 0x00,
	ON_Locator_Pattern = 0x01,
}E_Locator_Pattern_Actvn;

typedef enum{
	OFF_CarApproach=0x00,
	ON_CarApproach=0x01,
}E_ActvnOfApproach;

typedef enum{
	OFF_HomeSafety=0x00,
	ON_HomeSafety=0x01,
}E_ActvnOfHomeSafe;

typedef enum{
	OFF_Charging=0x00,
	ON_Charging=0x01,
}E_ActvnOfCharging;

typedef enum{
	OFF_Waitmode=0x00,
	ON_Waitmode=0x01,
}E_ActvnOfWaitmode;

typedef enum{
	WelLiTxReq_OnOff1_Off 	= 0x00,
	WelLiTxReq_OnOff1_On	= 0x01,
}E_WelLiFileTxReq_Signal;

typedef enum{
	Req_OnOff1_Off 	= 0x00,
	Req_OnOff1_On	= 0x01,
}E_ExtrLiShowFileTxReq_Signal;

typedef enum{
	Actvn_OnOff1_Off 	= 0x00,
	Actvn_OnOff1_On 	= 0x01,
}E_ExtrLiShowActvnReq_Signal;

typedef enum{
	DwnLoad_Sts_Resd 	= 0x00,
	DwnLoad_Sts_Err	 	= 0x01,
	DwnLoad_Sts_CmplOk	= 0x02,
	DwnLoad_Sts_InProgs	= 0x03,
}E_DwnLoadStsFbOfReLampCtrl_Signal;

typedef enum{
	Actvn_Sts_Resd 		= 0x00,
	Actvn_Sts_Err	 	= 0x01,
	Actvn_Sts_CmplOk	= 0x02,
	Actvn_Sts_InProgs	= 0x03,
}E_ExtrLiShowActvnReFb_Signal;

typedef enum{
	Store_OnOff1_Off	= 0x00,
	Store_OnOff1_On		= 0x01,
}E_ExtrLiShowStoreStsRe_Signal;

typedef enum{
	FuncToGrp_None = 0,
	FuncToGrp_Low_Beam = 1,
	FuncToGrp_High_Beam = 2,
	FuncToGrp_Drl = 3,
	FuncToGrp_Pos = 4,
	FuncToGrp_TI = 5,
	FuncToGrp_Cornering_Lamp = 6,
	FuncToGrp_Fog_Lamp = 7,
	FuncToGrp_Logo_Lamp = 8,
	FuncToGrp_Front_Cross_Lamp = 9,
	FuncToGrp_Grille_Lamp = 10,
	FuncToGrp_Assistant_Light = 11,
}E_FuncToGrp;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void Dynamic_Light_Function_MainFunction(uint8 timebase);
void Dynamic_Charging_Light_MainFunction(uint8 timebase);
uint8 Interface_Store_ModeReq_Signal(void);
S_Dynamic_Function_State_Info* GetDynamicLightFunctionStateInfo(uint8 Dynamic_Light_Function_id);
uint8 Interface_Dynamic_Light_Execute_Status(void);//返回1 正在执行   返回0 没有执行
void Test_Interface_Dynamic_Light(uint8 timebase);
void Send_CC_And_Pixel_Data(void);
#endif /* DYNAMICLIGHTEFFECTS_DYNAMIC_LIGHT_FUNCTION_H_ */
