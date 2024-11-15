/*
 * HcmPlatform.h
 *
 *  Created on: 2024��1��9��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_BASE_HCMPLATFORM_H_
#define ASW_INTERFACE_BASE_HCMPLATFORM_H_
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
/**************************************************
 *                                                *
 *                Macro Define                    *
 *                                                *
 **************************************************/
#define MIHUILIANG		0
#define TUJIONGJIONG	1
#define QINGHAIGANG		1
#define WANGSIBO		1
#define ECU_SAFETY		1


#if (QINGHAIGANG)
#define QHG_TESTIF_LED		0	/* 0:点灯运行; 1:测试接口; */
#define QHG_DMONI_orXCP		0	/* 0:XCP(正式程序); 1:DMONI */

#define LGT_DIS_LRE			0	/* L/R Error,    0:Enable; not 0:Disable */
#define LGT_DIS_ADB			0	/* ADB Lighting, 0:Enable; not 0:Disable */
#endif	/*QINGHAIGANG*/

#define	VER_SW_MAJOR	0		/*主版本号，0~255*/
#define VER_SW_MINOR	2		/*次版本号，0~255*/
#define VER_SW_REVIS	4		/*修订版本，0~255*/

#define CONFIG_GEN1_MAX 8

#define NULL ((void*)0)
#define MAX_CHANNLE_NUM	12

#define HCM_LEFT_SIDE  0
#define HCM_RIGHT_SIDE 1

#define S32K312_EMIOS_PWM_ADAPT	0

#define EMC_TEST_ENABLE 0

#define AMBIENT_TEMPERATURE_USE_VEHICLE_TEMPERATURE 1

/*基础软件平台2.0或者3.0*/
#define BASE_TECH_2_0 0x20
#define BASE_TECH_3_0 0x30
#define BASE_TECH_PLATFORM BASE_TECH_2_0

/*主机厂平台配置*/
#define OEM_SMART 0
#define OEM_GEELY 1
#define OEM_PLATFORM OEM_SMART

/*车辆平台配置*/
#define VEHICLE_SMART_HS11 0
#define VEHICLE_GEELY_G636 1
#define VEHICLE_GEELY_FX11 2
#define VEHICLE_PLATFORM VEHICLE_SMART_HS11

/* makeQ\env.mk configure */
#if (QINGHAIGANG)

#ifdef BUILD_PROJECT_ID
#		define QHG_TESTIF_LED		0		/*Lighting Interface Test*/
#		define QHG_DMONI_orXCP      0       /*Enable DMoni / Disable XCP*/
#   	define LGT_DIS_LRE          0       /*Disable LR error check*/
#		define EMC_TEST_ENABLE 		0		/*EMC Test Special*/
#	if (BUILD_PROJECT_ID == 1)
#		define QHG_TESTIF_LED		0
#		define QHG_DMONI_orXCP      1
#   	define LGT_DIS_LRE          1
#       define EMC_TEST_ENABLE 	    1		/**/
#	endif  /*(BUILD_PROJECT_ID == 1)*/
#endif	/*BUILD_LE0RI*/

#ifdef BUILD_LE0RI
#	if (BUILD_LE0RI == 0)
#		define HCM_LEFT_SIDE 	1
#		define HCM_RIGHT_SIDE 	0
#	else
#		define HCM_LEFT_SIDE 	0
#		define HCM_RIGHT_SIDE 	1
#	endif
#endif	/*BUILD_LE0RI*/

#ifdef BUILD_CUSTOMER
#	if (BUILD_CUSTOMER == 0)
#		define OEM_PLATFORM		OEM_SMART
#	endif	/*(BUILD_CUSTOMER == 0)*/
#	if (BUILD_CUSTOMER == 1)
#		define OEM_PLATFORM		OEM_GEELY
#	endif	/*(BUILD_CUSTOMER == 1)*/
#endif	/*BUILD_CUSTOMER*/

#ifdef BUILD_DMONI_CAN
#	define QHG_DMONI_orXCP	BUILD_DMONI_CAN
#endif	/*BUILD_DMONI_CAN*/

#endif  /*QINGHAIGANG*/


#if (HCM_LEFT_SIDE)
#define FIF0_DATA_01	0
#else
#define FIF0_DATA_01	1
#endif

/**************************************************
 *                                                *
 *              Data Type Define                  *
 *                                                *
 **************************************************/
typedef unsigned char  		uint8_t;
typedef unsigned short  	uint16_t;
typedef unsigned int 		uint32_t;
typedef unsigned long long 	uint64_t;

typedef signed char 		sint8_t;
typedef signed short  		sint16_t;
typedef signed int 			sint32_t;
typedef signed long long 	sint64_t;

typedef signed short        int16_t;

typedef enum
{
	E_EnableFlag_DISABLE, 
	E_EnableFlag_ENABLE
}E_EnableFlag;

/* 灯光伽马曲线 */
typedef enum
{
    E_LedGamma_Step     = 1,
    E_LedGamma_Linear   = 2,
    E_LedGamma_Exponent = 3
}E_LedGamma;

typedef enum{
	ChannelID1=0,
	ChannelID2=1,
	ChannelID3=2,
	ChannelID4=3,
	ChannelID5=4,
	ChannelID6=5,
	ChannelID7=6,
	ChannelID8=7,
	ChannelID9=8,
	ChannelID10=9,
	ChannelID11=10,
	ChannelID12=11,
}E_ChannelID;

typedef enum{
	E_LowBeamFlat=0,
	E_LowBeamKink=1,
	E_HighBeamSail=2,
	E_HighBeamSpot=3,
	E_DaytimeRunningLight=4,
	E_PositionLight=5,
	E_TurnIndicator=6,
	E_CorneringLight=7,
	E_FogLamp=8,
	E_LogoLamp=9,
	E_FrontCrossLamp=10,
	E_GrilleLamp=11,
	E_AssistantLight=12,
	E_Fan2 = 13,
	E_SideMarkerLamp=14,
	E_DynamicLightCircuit=15,
	E_DC_Motor=16,
	E_LMM_Supply=17,
}Light_Functions;

typedef enum{
	E_MatrixChipFunction_None=0,
	E_MatrixChipFunction_LowBeamHighBeam=1,
	E_MatrixChipFunction_Ti,
	E_MatrixChipFunction_DRL_POS,
	E_MatrixChipFunction_Grille,
	E_MatrixChipFunction_Logo,
	E_MatrixChipFunction_Assistant,
	E_MatrixChipFunction_FrontCross,
}E_MatrixChipFunction;

typedef enum{
	Group1 = 0,
	Group2 = 1,
	Group3 = 2,
	Group4 = 3,
	Group5 = 4,
	Group6 = 5,
	Group7 = 6,
	Group8 = 7,
	Group9 = 8,
	Group10 = 9,
	Group11 = 10,
	Group12 = 11,
	Group13 = 12,
	Group14 = 13,
	Group15 = 14,
	Group16 = 15,
	Group17 = 16,
	Group18 = 17,
	Group19 = 18,
	Group20 = 19,
	Group21 = 20,
	Group22 = 21,
	Group23 = 22,
	Group24 = 23,

}E_LED_Group_ID;


#endif /* ASW_INTERFACE_BASE_HCMPLATFORM_H_ */
