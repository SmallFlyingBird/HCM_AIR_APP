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

#define NULL ((void*)0)
#define MAX_CHANNLE_NUM	6

#define HCM_LEFT_SIDE  1
#define HCM_RIGHT_SIDE 0

#if (HCM_LEFT_SIDE)
#define FIF0_DATA_01	0
#else
#define FIF0_DATA_01	1
#endif

#define	VER_SW_MAJOR	0		/*主版本号，0~255*/
#define VER_SW_MINOR	4		/*次版本号，0~255*/
#define VER_SW_REVIS	0		/*修订版本，0~255*/

#define APP_E2E_FUN     0
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

typedef enum{
	ChannelID1=0,
	ChannelID1_Tap=1,
	ChannelID2=2,
	ChannelID2_Alt=3,
	ChannelID3=4,
	ChannelID4=5,
	CHANNEL_NUM=6,
}E_ChannelID;

/* 灯光伽马曲线 */
typedef enum
{
    E_LedGamma_Step     = 1,
    E_LedGamma_Linear   = 2,
    E_LedGamma_Exponent = 3
}E_LedGamma;

typedef enum{
	E_LowBeamKink=0,
	E_HighBeamSpot=1,
	E_DaytimeRunningLight=2,
	E_PositionLight=3,
	E_TurnIndicator=4,
	E_CorneringLight=5,
	E_FogLamp=6,
	E_LogoLamp=7,
	E_FrontCrossLamp=8,	
	E_GrilleLamp=9,
	E_AssistantLight=10,
	E_TurnIndicator_Act =11,
	E_Fan2 = 12,
	E_DC_Motor=13,
}Light_Functions;

typedef enum{
	Group1 = 0,
	Group2 = 1,
	Group3 = 2,
	Group4 = 3,
	Group5 = 4,
	Group6 = 5,
	Group7 = 6,
	Group8 = 7,
}E_LED_Group_ID;


#endif /* ASW_INTERFACE_BASE_HCMPLATFORM_H_ */
