/*
 * Boost_Interface.h
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_CHANNEL_INTERFACE_BOOST_INTERFACE_H_
#define ASW_INTERFACE_CHANNEL_INTERFACE_BOOST_INTERFACE_H_
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
#define BOOST_INTERFACE_VERSION_HIGH_BYTE 0
#define BOOST_INTERFACE_VERSION_MIDDLE_BYTE 0
#define BOOST_INTERFACE_VERSION_LOW_BYTE 0

/*Boost的最大电压*/
#define BOOST_MAX_VOLATGE 50

/*Boost升压使用固定值*/
#define BOOST_VOLTAGE_FIX_ENABLE 0

#if BOOST_VOLTAGE_FIX_ENABLE 
#define BOOST_INIT_VOLTAGE 45
#endif

#define BOOST_TEMP_USE_NTC 1

#define BOOST_OVER_TEMPERATURE_THRESOLD 130
#define BOOST_TEMPERATURE_HYSTERESIS    5

#if BOOST_TEMP_USE_NTC
#define BOOST_NTC_SIZE 34
#define ADC_BUFFER_SIZE 5
#endif
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef union
{
	uint8_t DiagState;
	struct
	{
		uint8_t LostCom : 1;
		uint8_t LostCfg : 1;
	} Bits;
} U_BoostDiagState;

typedef enum
{
	E_BoostDrvDevType_Tps92682 = 0,
	E_BoostDrvDevType_BD18354 = 1,
} E_BoostDrvDevType;

typedef enum
{
	E_BoostkNo1 = 0,
	E_BoostkNo2 = 1,
	E_BoostkNo3 = 2,
	E_BoostkNo4 = 3,
	E_BoostkNo5 = 4,
	E_BoostkNo6 = 5,
	E_BoostkNo7 = 6,
	E_BoostkNo8 = 7,
	E_BoostkNo9 = 8,
} E_BoostkNo;

typedef enum
{
	E_BoostDataType_BoostInit = 0,
	E_BoostDataType_BoostDeInit,
    E_BoostDataType_BoostMainFunction,
	E_BoostDataType_BoostTemperature,
	E_BoostDataType_BoostOutputVoltage,
    E_BoostDataType_BoostDiagState,
} E_BoostDataType;

typedef struct BoostInitDataSrc
{
	E_BoostkNo BoostkNo;
	uint8_t InitVoltage;
} S_BoostInitDataSrc;

typedef struct BoostTemperatureDataSrc
{
	E_BoostkNo BoostkNo;
	int16_t BoostTemp;
} S_BoostTemperatureDataSrc;

typedef struct BoostOutputVoltageDataSrc
{
	E_BoostkNo BoostkNo;
	uint8_t Voltage;
} S_BoostOutputVoltageDataSrc;


typedef struct BoostDiagStateDataSrc
{
	E_BoostkNo BoostkNo;
	U_BoostDiagState BoostDiagState;
} S_BoostDiagStateDataSrc;

typedef struct BoostMainFuncDataSrc
{
	E_BoostkNo BoostkNo;
} S_BoostMainFuncDataSrc;


typedef struct BoostDataPackets
{
	E_BoostDataType BoostDataTypes;
	void *datasrc;
} S_BoostDataPackets;

typedef struct BoostDrv_Dev
{
	E_BoostDrvDevType BoostDrvDevType;
	E_BoostkNo dev_id;
	Std_ReturnType (*DeviceInit)(void *ptr);
	Std_ReturnType (*DeviceDeInit)(void *ptr);
	Std_ReturnType (*Read)(void *ptr);
	Std_ReturnType (*Write)(void *ptr);
	Std_ReturnType (*MainFunction)(void *ptr);
	struct BoostDrv_Dev *ptNext;
} S_BoostDrv_Dev;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*boost主函数，主要用于计算boostADC的值*/
void BoostInterfaceMainFunction(uint8_t timebase);
Std_ReturnType Interface_SetBoostOutputVoltage(E_BoostkNo BoostkNo, double voltage);
#if BOOST_TEMP_USE_NTC
Std_ReturnType Interface_GetBoostTemperature(sint16_t *Temp);
#else
Std_ReturnType Interface_GetBoostTemperature(E_BoostkNo BoostkNo,sint16_t *Temp);
#endif
Std_ReturnType Interface_BoostInit(uint8_t InitVoltage);
Std_ReturnType BoostDrvDev_Register(S_BoostDrv_Dev *Drv_Dev);
#endif /* ASW_INTERFACE_CHANNEL_INTERFACE_BOOST_INTERFACE_H_ */
