// /*
//  * MotorDrvDev_Interface.h
//  *
//  *  Created on: 2024��1��11��
//  *      Author: mihuiliang
//  */

// #ifndef ASW_INTERFACE_STEPMOTOR_INTERFACE_MOTORDRVDEV_INTERFACE_H_
// #define ASW_INTERFACE_STEPMOTOR_INTERFACE_MOTORDRVDEV_INTERFACE_H_


// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "HcmPlatform.h"

// /****************************************************************
//  *                                                              *
//  *                      Macro Define                            *
//  *                                                              *
//  ****************************************************************/
// /*�汾�� 0.0.0*/
// #define MOTORDRVDEV_INTERFACE_VERSION_HIGH_BYTE 				0
// #define MOTORDRVDEV_INTERFACE_VERSION_MIDDLE_BYTE 			0
// #define MOTORDRVDEV_INTERFACE_VERSION_LOW_BYTE 				0
// #define MAX_MOTOR_NUM 2

// /****************************************************************
//  *                                                              *
//  *                     Data Type Define                         *
//  *                                                              *
//  ****************************************************************/
// typedef enum{
// 	E_MotorTpye_NoAllacated=0,
// 	E_MotorTpye_Leveling=1,
// 	E_MotorTpye_Swiveling=2,
// }E_MotorTpye;

// typedef enum{
// 	E_MotorDrvDev_TI8889=0,
// 	E_MotorDrvDev_NCV70517=1,
// }E_MotorDrvDevType;

// typedef enum{
// 	MotorMicroStepMode_1=1,									
// 	MotorMicroStepMode_2=2,									
// 	MotorMicroStepMode_4=4,									
// 	MotorMicroStepMode_8=8,									
// 	MotorMicroStepMode_16=16,								
// 	MotorMicroStepMode_32=32,								
// 	MotorMicroStepMode_64=64,	
// 	MotorMicroStepMode_128=128,
// 	MotorMicroStepMode_256=256,							
// }E_MotorMicroStepMode;

// typedef enum{
// 	E_MotorMotorTemp_Normal=0,
// 	E_MotorMotorTemp_LowTempWarning,
// 	E_MotorMotorTemp_HighTempWarning,
// 	E_MotorMotorTemp_HighTempShutDown,
// }E_MotorTemperatureInfo;

// typedef union{
// 	struct{
// 	uint8_t DevShort 			:1;
// 	uint8_t DevOpenLoad	 		:1;
// 	uint8_t Stall				:1;
//     uint8_t ComError			:1;  /*通信出错*/
//     uint8_t TempWarning			:1;  /*温度警告*/
//     uint8_t ThermalShuTDown		:1;  /*过温关断*/
//     uint8_t UV		            :1;  /*欠压*/
// 	}bits;
// 	uint8_t DevError;
// }U_DevErrorTypt;

// typedef enum{
// 	E_MotorDrvDataType_DevInit=0,							/*�豸��ʼ��*/
// 	E_MotorDrvDataType_DevDeInit,							/*�豸ȥ��ʼ��*/
// 	E_MotorDrvDataType_DevStepMode,							/*���΢��ģʽ*/
// 	E_MotorDrvDataType_DevStallThreshold,					/*�����ת��ֵ*/
// 	E_MotorDrvDataType_DevStallDetectSwitchState,			/*�����ת��⿪��*/
// 	E_MotorDrvDataType_DevDiagnose,							/*������*/
// 	E_MotorDrvDataType_DevTemperature,						/*�豸�¶�*/
// 	E_MotorDrvDataType_DevOutputCurrent,					/*�������*/
// 	E_MotorDrvDataType_DevDirPolarity,						/*���������*/
//     E_MotorDrvDataType_DevOpenLoadDetectSwitchState,        /*电机开路检测开关*/
// }E_MotorDrvDataType;

// typedef enum{
// 	E_MotorDirPinState_LOW=0,
// 	E_MotorDirPinState_HIGH=1,
// }E_MotorDirPinState;
// /*************************************************************DataSrc********************************************************************************/
// typedef struct DevOpenLoadDetectSwitchStateSrc{
// 	uint8_t OpenLoadDetectState;							/*0:Disbale   1:Enable*/
// }S_DevOpenLoadDetectSwitchStateSrc;

// typedef struct DevStallDetectSwitchStateDataSrc{
// 	uint8_t StallDetectState;							/*0:Disbale   1:Enable*/
// }S_DevStallDetectSwitchStateDataSrc;

// typedef struct MotorDrvInitDataSrc{
// 	E_MotorMicroStepMode MicroStepMode;
// 	E_MotorDirPinState   DirPinState;
// 	uint8_t stallthreshold;
// 	uint16_t outputcurrent;
// }S_MotorDrvInitDataSrc;

// typedef struct MotorDrvDirPolarityDataSrc{
// 	E_MotorDirPinState MotorDirPinState;
// }S_MotorDrvDirPolarityDataSrc;

// typedef struct MotorDrvOutputCurrentDataSrc{
// 	uint16_t MotorCurrent;
// }S_MotorDrvOutputCurrentDataSrc;

// typedef struct MotorDrvStepModeDataSrc{
// 	E_MotorMicroStepMode MotorMicroStepMode;
// }S_MotorDrvStepModeDataSrc;

// typedef struct MotorTemperatureDataSrc{
// 	E_MotorTemperatureInfo MotorTemperatureInfo;
// }S_MotorTemperatureDataSrc;

// typedef struct MotorDiagnoseDataSrc{
// 	U_DevErrorTypt DevErrorTypt;
// }S_MotorDiagnoseDataSrc;

// /*************************************************************DataPackets********************************************************************************/
// typedef struct MotorDrvDataPackets{
// 	E_MotorDrvDataType MotorDrvDataType;
// 	uint8_t Device_id;
// 	void * datasrc;					/*ָ�������ö�����͵�����Դ*/
// }S_MotorDrvDataPackets;


// typedef struct MotorDrv_Dev{
// 	E_MotorDrvDevType DeviceType;										/*�豸����*/
// 	E_MotorTpye MotorType;												/*�������*/
// 	uint8_t Device_id;													/*�豸ID*/
// 	Std_ReturnType (*DeviceInit)(void *ptr);							/*�豸��ʼ��*/
// 	Std_ReturnType (*DeviceDeInit)(void *ptr);							/*�豸ȥ��ʼ��*/
// 	Std_ReturnType (*Read)(void *ptr);
// 	Std_ReturnType (*Write)(void *ptr);
// 	Std_ReturnType (*Mainfunction)(void *ptr);
// 	struct MotorDrv_Dev *ptNext;										/*ָ����һ��*/
// }S_MotorDrv_Dev;

// /****************************************************************
//  *                                                              *
//  *                   Global Functions                           *
//  *                                                              *
//  ****************************************************************/
// S_MotorDrv_Dev* GetMotorDrvByMotorTpye(E_MotorTpye MotorType);
// Std_ReturnType MotorDrvDev_Register(S_MotorDrv_Dev* Drv_Dev);


// #endif /* ASW_INTERFACE_STEPMOTOR_INTERFACE_MOTORDRVDEV_INTERFACE_H_ */


