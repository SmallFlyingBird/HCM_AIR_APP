/*
 * Buck_Interface.h
 *
 *  Created on: 2024��1��11��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_CHANNEL_INTERFACE_BUCK_INTERFACE_H_
#define ASW_INTERFACE_CHANNEL_INTERFACE_BUCK_INTERFACE_H_

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

/*�汾�� 0.0.0*/
#define BUCK_INTERFACE_VERSION_HIGH_BYTE 0
#define BUCK_INTERFACE_VERSION_MIDDLE_BYTE 0
#define BUCK_INTERFACE_VERSION_LOW_BYTE 0

#define MAX_SUPPORT_BUCK_NUM 10

#define LIST_ALL_BUCK_AT_ONCE 1

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef enum
{
	E_BuckDrvDev_Tps92520 = 0,
	E_BuckDrvDev_BD18398 = 1,
} E_BuckDrvDevType;

typedef enum
{
	E_BuckNo1 = 0,
	E_BuckNo2 = 1,
	E_BuckNo3 = 2,
	E_BuckNo4 = 3,
	E_BuckNo5 = 4,
	E_BuckNo6 = 5,
	E_BuckNo7 = 6,
	E_BuckNo8 = 7,
	E_BuckNo9 = 8,
	E_BuckNo10 = 9,
} E_BuckNo;

typedef struct BuckLimpHomeDataSrc
{
    E_BuckNo BuckNo;
    uint8_t LimpHomeState;
} S_BuckLimpHomeDataSrc;

typedef enum
{
	E_BuckDataType_BuckInit = 0,
	E_BuckDataType_BuckDeInit,
	E_BuckDataType_ChannelPWM,
	E_BuckDataType_ChannelCurrent,
	E_BuckDataType_ChannelSwitchState,
	E_BuckDataType_ChannelVoltage,
	E_BuckDataType_ChannelDiagState,
	E_BuckDataType_ChannelFrequency,
	E_BuckDataType_BuckTemperature,
	E_BuckDataType_BuckMainFunction,
    E_BuckDataType_BuckDiagState,
	E_BuckDataType_BuckLimpHomeSwitch,
} E_BuckDataType;

typedef enum
{
	CHANNEL_STATE_OFF = 0,
	CHANNEL_STATE_ON = 1,
} E_ChannelState;

typedef union
{
	uint8_t DiagState;
	struct
	{
		uint8_t OpenError : 1;
		uint8_t Short2Gnd : 1;
		uint8_t Pending : 1;
	} Bits;
} U_ChannelDiagState;

typedef union
{
    uint8_t BuckDiagState;
    struct{
        uint8_t LostCom : 1;
        uint8_t LostConfig : 1;
    };
}U_BuckDiagState;

typedef struct BuckInitDataSrc
{
	E_BuckNo BuckNo;
} S_BuckInitDataSrc;

typedef struct BuckDeInitDataSrc
{
	E_BuckNo BuckNo;
} S_BuckDeInitDataSrc;

typedef struct BuckDiagStateDataSrc
{
	E_BuckNo BuckNo;
    U_BuckDiagState BuckDiagState;
} S_BuckDiagStateDataSrc;

typedef struct ChannelPwmDataSrc
{
	E_ChannelID ChannelID;
	uint8_t PwmValue; /*PwmValue : 0-100%*/
} S_ChannelPwmDataSrc;

typedef struct ChannelCurrentDataSrc
{
	E_ChannelID ChannelID;
	uint16_t CurrentValue; /*CurrentValue : 0-65535(mA)*/
} S_ChannelCurrentDataSrc;

typedef struct ChannelSwitchStateDataSrc
{
	E_ChannelID ChannelID;
	E_ChannelState SwitchStateValue; /*CHANNEL_STATE_OFF :channel close ; CHANNEL_STATE_ON :channel open*/
} S_ChannelSwitchStateDataSrc;

typedef struct ChannelVoltageDataSrc
{
	E_ChannelID ChannelID;
	double ChannelVoltageValue; /*ChannelVoltage: (V)*/
} S_ChannelVoltageDataSrc;

typedef struct ChannelFrequencyDataSrc
{
	E_ChannelID ChannelID;
	uint16_t ChannelFrequency; /*ChannelFrequency: 0-65535*/
} S_ChannelFrequencyDataSrc;

typedef struct ChannelDiagStateDataSrc
{
	E_ChannelID ChannelID;
	U_ChannelDiagState ChannelDiagState;
} S_ChannelDiagStateDataSrc;

typedef struct BuckTemperatureDataSrc
{
	E_BuckNo BuckNo;
	int16_t BuckTemp; /*BuckTemp: (¡æ)*/
} S_BuckTemperatureStateDataSrc;

typedef struct BuckMainFunctionDataSrc
{
	E_BuckNo BuckNo;
} S_BuckMainFunctionDataSrc;

typedef struct BuckDataPackets
{
	E_BuckDataType BuckDataType;
	void *datasrc;
} S_BuckDataPackets;

typedef struct BuckDrv_Dev
{
	E_BuckDrvDevType BuckDeviceType;
	E_BuckNo Device_id;
	uint16_t ChannelMappingMask;
	Std_ReturnType (*DeviceInit)(void *ptr);
	Std_ReturnType (*DeviceDeInit)(void *ptr);
	Std_ReturnType (*Read)(void *ptr);
	Std_ReturnType (*Write)(void *ptr);
	Std_ReturnType (*MainFunction)(void *ptr);
	struct BuckDrv_Dev *ptNext;
} S_BuckDrv_Dev;

/****************************************************************
 *                                                              *
 *                      Functions Define                        *
 *                                                              *
 ****************************************************************/
/*
 *Function: Get buck channel mask
 *Std_ReturnType:  E_NOT_OK : Buck not finded
 *                 E_OK
 *Parameter:
 *			buckid:E_BuckNo1-E_BuckNo9
 *			chmask: poit (if Std_ReturnType = E_OK,  chmask will be set)
 */
Std_ReturnType Interface_GetBuckChannelMask(E_BuckNo buckid, uint16_t *chmask);
/*
 *Function: Get buck temperature
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			E_BuckNo:E_BuckNo1-E_BuckNo9
 *			temp: -32768 - +32767 ��
 */
Std_ReturnType Interface_GetBuckTempterature(E_BuckNo buckid, int16_t *temp);
S_BuckDrv_Dev *GetBuckDrvDevByChId(E_ChannelID id);
Std_ReturnType BuckInterfaceMainFuntion(uint8_t timebase);
Std_ReturnType Interface_BuckInit(void);
Std_ReturnType BuckDrvDev_Register(S_BuckDrv_Dev *Drv_Dev);
#endif /* ASW_INTERFACE_CHANNEL_INTERFACE_BUCK_INTERFACE_H_ */
