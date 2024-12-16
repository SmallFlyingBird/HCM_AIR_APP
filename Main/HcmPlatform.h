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
#define MAX_CHANNLE_NUM	12

#define HCM_LEFT_SIDE  1
#define HCM_RIGHT_SIDE 0

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

typedef enum{
	ChannelID1=0,
	ChannelID2=1,
	ChannelID3=2,
	ChannelID4=3,
	ChannelID5=4,
	ChannelID6=5,
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
	E_DC_Motor=15,
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
