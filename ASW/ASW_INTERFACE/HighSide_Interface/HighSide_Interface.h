#ifndef HIGHSIDE_INTERFACE_HIGHSIDE_INTERFACE_H_
#define HIGHSIDE_INTERFACE_HIGHSIDE_INTERFACE_H_

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

#define FAN_HSCHANNEL	0
#define CHANNEL_SIZE    2

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef enum {
	E_HighSideDrvDevType_Tps2HB35=0,
}E_HighSideDrvDevType;

typedef enum{
	E_HSChannel_HS0=0,   /*This HS channel is used for Fan*/
	E_HSChannel_HS1=1,
}E_HSChannel;

typedef enum{
	E_HighSideDataType_DeviceInit=0,
	E_HighSideDataType_ChannelSwitch=1,
	E_HighSideDataType_ChannelCurrent=2,
	E_HighSideDataType_ChannelDiagInfo=3,
	E_HighSideDataType_DeviceMainFunction=4,
}E_HighSideDataType;

typedef enum{
	E_HSDChannelSwitchState_OFF=0,
	E_HSDChannelSwitchState_ON=1,
}E_HSDChannelSwitchState;

typedef union{
	uint8_t DiagInfo;
	struct{
		uint8_t Short2GND	    :1;
		uint8_t OverCurrent     :1;
        uint8_t OpenOrShort2Vcc :1;
		uint8_t	rcvd		    :5;
	}bits;
}U_HSChannelDiagInfo;

typedef struct{
    uint8_t Short2GndErrCnt;
    uint8_t OverCurrentErrCnt;
    uint8_t OpenOrShort2VccErrCnt;
}S_HSDErrCnt;

typedef struct HighSideDevInitDataSrc{
	uint8_t Device_id;
}S_HighSideDevInitDataSrc;

typedef struct HighSideSwitchStateDataSrc{
	E_HSChannel HSChannel;
	E_HSDChannelSwitchState HsdState;
}S_HighSideSwitchStateDataSrc;

typedef struct HighSideCurrentDataSrc{
	E_HSChannel HSChannel;
	uint16_t current;			/*Unit :mA*/
}S_HighSideCurrentDataSrc;

typedef struct HighSideDiagDataSrc{
	E_HSChannel HSChannel;
	U_HSChannelDiagInfo HSChannelDiagInfo;
}S_HighSideDiagDataSrc;

typedef struct HighSideDataPackets{
	E_HighSideDataType HighSideDataType;
	void * datasrc;
}S_HighSidekDataPackets;

typedef struct HighSideDevMainFuncDataSrc{
	uint8_t Device_id;
}S_HighSideDevMainFuncDataSrc;

typedef struct HighSideDrv_Dev{
	uint8_t Device_id;
	uint8_t HsdChMappingMask;
	Std_ReturnType (*DeviceInit)(void* ptr);
	Std_ReturnType (*DeviceDeInit)(void* ptr);
	Std_ReturnType (*Read)(void* ptr);
	Std_ReturnType (*Write)(void* ptr);
	Std_ReturnType (*MainFunction)(void * ptr);
	struct HighSideDrv_Dev *ptNext;
}S_HighSideDrv_Dev;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*
 *Function: Get HSD channel current (Unit:mA)
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			HSChannel:	E_HSChannel_HS0-1,
 *			current: mA
 */
Std_ReturnType Interface_GetHighSideChannelCurrent(E_HSChannel HSChannel,uint16_t* current);
Std_ReturnType Interface_GetHighSideChannelDiagInfo(E_HSChannel HSChannel,U_HSChannelDiagInfo* HSChannelDiagInfo);
Std_ReturnType Interface_GetHighSideState(E_HSChannel HSChannel, E_HSDChannelSwitchState *Sts);
Std_ReturnType Interface_SetHighSideState(E_HSChannel HSChannel,E_HSDChannelSwitchState Sts);
Std_ReturnType HighSide_Interface_Mainfunction(uint8_t timebase);
Std_ReturnType Interface_HighSideInit(void);
Std_ReturnType HighSideDrvDev_Register(S_HighSideDrv_Dev* Drv_Dev);
Std_ReturnType Interface_GetHsdError(E_HSChannel hsdid);
#endif /* HIGHSIDE_INTERFACE_HIGHSIDE_INTERFACE_H_ */
