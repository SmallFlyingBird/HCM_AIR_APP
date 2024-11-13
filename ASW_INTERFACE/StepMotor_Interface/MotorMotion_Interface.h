// /*
//  * StepMotor_Interface.h
//  *
//  *  Created on: 2024��1��10��
//  *      Author: mihuiliang
//  */

// #ifndef ASW_INTERFACE_STEPMOTOR_INTERFACE_MOTORMOTION_INTERFACE_H_
// #define ASW_INTERFACE_STEPMOTOR_INTERFACE_MOTORMOTION_INTERFACE_H_
// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "MotorDrvDev_Interface.h"
// #include "HcmPlatform.h"

// /****************************************************************
//  *                                                              *
//  *                      Macro Define                            *
//  *                                                              *
//  ****************************************************************/
// #define MOTORMOTION_INTERFACE_VERSION_HIGH_BYTE 				0
// #define MOTORMOTION_INTERFACE_VERSION_MIDDLE_BYTE 				0
// #define MOTORMOTION_INTERFACE_VERSION_LOW_BYTE 					0

// #define DEC_STOP_MOTO_POS_ENABLE	1
// /****************************************************************
//  *                                                              *
//  *                     Data Type Define                         *
//  *                                                              *
//  ****************************************************************/


// typedef enum{
// 	E_MotorMotionState_Stop_Phase=0,
// 	E_MotorMotionState_Stop_Hold2RunDelay_Phase,
// 	E_MotorMotionState_Stop_Run2HoldDelay_Phase,
// 	E_MotorMotionState_Run_Accelerate_Phase,
// 	E_MotorMotionState_Run_Max_Speed_Phase,
// 	E_MotorMotionState_Run_Decelerate_Phase,
// }E_MotorMotionState;


// /*��ʾ����MotorDirPinState�ĸߵ�ƽΪ��λ�ã������Ե͵�ƽΪ��λ��*/
// typedef enum{
// 	E_MotorPosDirPolarity_Default=0,
// 	E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR=1,
// 	E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR=2,
// }E_MotorPosDirPolarity;


// typedef enum{
// 	E_PosSet_OK=0,
// 	E_PosSet_Error=1,
// 	E_PosSet_Pending=2,
// }E_SetPosState;

// typedef enum{
// 	E_MOTOR_NO_STOP_FLAG=0,
// 	E_MOTOR_IMMEDIATE_STOP=1,
// 	E_MOTOR_DEC_STOP=2,
// }E_MotorStopFlag;



// typedef struct MotorMotionAlgorithmManager{
// 	E_MotorTpye MotorTpye;
// 	E_MotorPosDirPolarity MotorPosDirPolarity;
// 	E_MotorDirPinState MotorCurDirPinState;
// 	E_MotorMotionState MotorState;
// 	E_MotorStopFlag MotorStopFlag;
// 	uint8_t StallDetectEnFlag;              /*堵转检测打开标记位*/
//     uint8_t OpenDetectEnFlag;               /*开路检测打开标记位*/
// 	uint8 MotorAlgoEnableFlag;
// 	uint16_t MotorCurCurrent;				/*�����ǰ����(mA)*/
// 	uint16_t MotorRunCurrent;				/*����˶�����(mA)*/
// 	uint16_t MotorHoldCurrent;
// 	uint16_t AccDecStepNum;
// 	uint16_t AccPluseNum;
// 	uint16_t DecPluseNum;
// 	uint16_t MaxSpeeedPluseNum;
// 	uint16_t AccPluseArray_index;
// 	uint16_t DecPluseArray_index;
// 	uint16_t MaxSpeeedPluseArray_index;
// 	sint16 MotorCurPosition;
// 	sint16 MotorTargetPosition;
// 	uint16_t config_hold2run_timer_delay;
// 	uint16_t hold2run_timer_delay;
// 	uint16_t config_run2hold_timer_delay;
// 	uint16_t run2hold_timer_delay;
// 	uint16_t *AccStepArray;
// 	uint16_t *DecStepArray;
// 	uint32 MotorTotalSteppNumber;
// 	uint32 MotorRunTotalTimer;
// 	uint32 MotorStopTotalTimer;
// 	uint32 UsageIntervalTimer;
// }S_MotorMotionAlgorithmManager;

// /****************************************************************
//  *                                                              *
//  *                      Functions Define                        *
//  *                                                              *
//  ****************************************************************/
// Std_ReturnType Interface_ResetMotorDirPinPolariy(E_MotorTpye MotorTpye,E_MotorDirPinState PinState);
// Std_ReturnType Interface_SetMotorCurrent(E_MotorTpye MotorTpye,uint16_t current);
// Std_ReturnType Interface_GetMotorDevDrvState(E_MotorTpye MotorTpye);
// Std_ReturnType Interface_GetMotorTemperatureInfo(E_MotorTpye MotorTpye, E_MotorTemperatureInfo* MotorTemperatureInfo);
// Std_ReturnType Interface_GetMotorDiagnoseInfo(E_MotorTpye MotorTpye, U_DevErrorTypt* DevErrorTypt);
// Std_ReturnType Interface_PulseGeneratorCallBack(E_MotorTpye MotorTpye);
// E_SetPosState Interface_SetMotorPosition(E_MotorTpye MotorTpye, sint16 Position);
// E_SetPosState Interface_ResetMotorPosition(E_MotorTpye MotorTpye,sint16 Position);
// Std_ReturnType Interface_SetMotorMotionParameter(E_MotorTpye MotorTpye,uint16_t AccDecStepNum,uint16_t RunCurrent,uint16_t HoldCurrent);
// Std_ReturnType Interface_StopMotor(E_MotorTpye MotorTpye);
// Std_ReturnType Interface_GetMotorCurPosition(E_MotorTpye MotorTpye,sint16 *curpos);
// E_MotorMotionState Interface_GetMotorMotionState(E_MotorTpye MotorTpye);
// Std_ReturnType Interface_EnableMotorStallDetect(E_MotorTpye MotorTpye);
// Std_ReturnType Interface_DisableMotorStallDetect(E_MotorTpye MotorTpye);
// void MotorMotionMainFunction(uint8_t timebase);
// Std_ReturnType SwivelingMotorMotionInterfaceInit(void);
// Std_ReturnType LevelingMotorMotionInterfaceInit(void);
// #endif /* ASW_INTERFACE_STEPMOTOR_INTERFACE_MOTORMOTION_INTERFACE_H_ */
