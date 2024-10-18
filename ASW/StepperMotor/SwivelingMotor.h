/*
 * SwivelingMotor.h
 *
 *  Created on: 2024��2��18��
 *      Author: mihuiliang
 */

#ifndef STEPPERMOTOR_SWIVELINGMOTOR_H_
#define STEPPERMOTOR_SWIVELINGMOTOR_H_


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "MotorMotion_Interface.h"
#include "DidConfig.h"
#include "RoutineCtr_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define SVL_REFERENCE_RUN_STALL_DEBOUNCE  5
#define SVL_OVERUSE_DEACTIVATED_TIMER 5000

#define SVL_MOTOR_REFERENCE_USE_STALL_DET 0 /*Swiveling电机ReferenceRun使用堵转检测*/
/*The number of get hall feedback if HallSensorInf_GetHallSensorFeedBack==E_NOT_OK*/
#define HALLFEEDBACK_WAIT_NUM			  3		

#define HALLSENSOR_REFRUN_SWING_NUM  	  3  
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum
{
    E_SvlRefRunSts_NoCond = 0, /* 条件不满足 */
    E_SvlRefRunSts_During = 1, /* 执行中 */
    E_SvlRefRunSts_Done   = 2, /* 完成 */
    E_SvlRefRunSts_Error  = 3  /* 执行过程中故障 */
}E_SvlRefRunSts;

typedef enum{
	E_SwivelingType_NoSwivelingMotor=0,
	E_SwivelingType_SwivelingMotorWithoutHallSensor=1,
	E_SwivelingType_SwivelingMotorWitHallSensor=2,
	E_SwivelingType_Matrix=3,
	E_SwivelingType_DBL_WithCorner=4,
	E_SwivelingType_DBL_SwivelingMotorWithoutHallSensor_WithCorner=5,
	E_SwivelingType_DBL_SwivelingMotorWitHallSensor_WithCorner=6,
	E_SwivelingType_DBL_MatrixmatrixWithCorner=7,
}E_SwivelingType;

typedef enum{
	E_SwivelingMotorState_DevDrvTryInit=0,
	E_SwivelingMotorState_AlgoInit,
	E_SwivelingMotorState_CheckRefRunPreCondition,
	E_SwivelingMotorState_ReferenceRunWithOutHall,
	E_SwivelingMotorState_ReferenceRunWithHall,
	E_SwivelingMotorState_NormalRun,
    E_SwivelingMotorState_Error,
}E_SwivelingMotorState;


typedef enum{
	E_SubMode_SvlRefRun_ParamInit=0,
	E_SubMode_SvlRefRun_GoToLeftBlockPos,
	E_SubMode_SvlRefRun_GoToRightBlockPos,
	E_SubMode_SvlRefRun_GoToAdditionPos,
	E_SubMode_SvlRefRun_GoToDefaultPos,
	E_SubMode_SvlRefRun_FindLeftStallPos,
	E_SubMode_SvlRefRun_FindRightStallPos,
	E_SubMode_SvlRefRun_FindAdditionPos,
	E_SubMode_SvlRefRun_WaitLeave,
	E_SubMode_SvlRefRun_WaitHallConvertComplete,
	E_SubMode_SvlRefRun_HallSensorError,
	E_SubMode_SvlRefRun_HallSensorSwing,
	E_SubMode_SvlRefRun_WaitHallMotorStop,
    E_SubMode_SvlRefRun_Error,
}E_SwivelingAlgorithm_SubMode_RefRun;

typedef enum{
	E_SvlReferenceRun_NotPerform=0,
	E_SvlReferenceRun_Performing=1,
	E_SvlReferenceRun_PerformCompltedOK=2,
	E_SvlReferenceRun_PerformError=3,
}E_SvlReferenceRunCompletedFlag;


typedef struct SwivelingMotorInfo{
	E_SwivelingType  SwivelingType;
	E_SwivelingMotorState SwivelingMotorState;
	E_MotorMicroStepMode SwivelingMotorMicroStepMode;
	E_SwivelingAlgorithm_SubMode_RefRun SwivelingAlgorithm_SubMode_RefRun;
	E_SvlReferenceRunCompletedFlag SvlReferenceRunCompletedFlag;
	uint8 StallErrorCnt;
    uint8 OpenErrorCnt;
    uint8 DrvComErrorCnt;
    uint8 DrvUVErrorCnt;
    uint8 DrvThermalShutDownErrorCnt;
    uint8 DrvTmWarningErrorCnt;
	uint16 AdditionalStep;
	uint32_t HsPerRad;
	sint16 LeftBlockPos;
	sint16 RightBlockPos;
	sint16 LeftLogicPos;
	sint16 RightLogicPos;
	sint16 DefaultPos;
	sint16 TargetPos;
	sint16 CurrentMotorPos;
	uint16 DefaultAngle;
}S_SwivelingMotorInfo;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 获取Swiveling电机的工作模式 */
/* 返回值：0:正常模式； 1：UDS模式 */
uint8_t SwivelingMotor_GetSvlMotorRunMode(void);

Std_ReturnType SwivelingMotor_GetSvlCurAngle(double *Angle);
E_SvlRefRunSts SwivelingMotor_GetSvlRefRunSts(void);

Std_ReturnType SwivelingMotor_StartRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType SwivelingMotor_StopRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType SwivelingMotor_RequestRoutineResult_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer);

Std_ReturnType SwivelingMotor_StartRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType SwivelingMotor_StopRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType SwivelingMotor_RequestRoutineResult_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer);

Std_ReturnType SwivelingMotor_IoCtrCallBack(E_IOCtrType IOCtrTypeState);

void SwivelingMotorMainFunction(uint8_t timebase);
void SwivelingMotorInit(void);

#endif /* STEPPERMOTOR_SWIVELINGMOTOR_H_ */
