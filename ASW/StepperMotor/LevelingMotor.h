/*
 * LevelingMotor.h
 *
 *  Created on: 2024��2��17��
 *      Author: mihuiliang
 */

#ifndef LEVELINGMOTOR_LEVELINGMOTOR_H_
#define LEVELINGMOTOR_LEVELINGMOTOR_H_
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
#define LVL_REFERENCE_RUN_STALL_DEBOUNCE 5
#define LVL_OVERUSE_DEACTIVATED_TIMER 5000 /*电机过度使用后的停止时间*/

#define LVL_MOTOR_REFERENCE_USE_STALL_DET 0 /*Leveling电机ReferenceRun使用堵转检测*/
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum
{
    E_LVL_Not_Available = 0,
    E_Manual_LVL,
    E_Automatic_LVL,
    E_DCMotor,
} E_LevelingType;

typedef enum
{
    E_LevelingMotorState_DevDrvTryInit = 0,
    E_LevelingMotorState_AlgoInit,
    E_LevelingMotorState_CheckRefRunPreCondition,
    E_LevelingMotorState_ReferenceRun,
    E_LevelingMotorState_NormalRun,
    E_LevelingMotorState_Error,
} E_LevelingMotorState;

typedef enum
{
    E_SubMode_LvlRefRun_ParamInit = 0,
    E_SubMode_LvlRefRun_GoToTopBlockPos,
    E_SubMode_LvlRefRun_GoToBottomBlockPos,
    E_SubMode_LvlRefRun_GoToBottomAdditionPos,
    E_SubMode_LvlRefRun_GoToDefaultPos,
    E_SubMode_LvlRefRun_FindTopStallPos,
    E_SubMode_LvlRefRun_FindBottomStallPos,
    E_SubMode_LvlRefRun_FindBottomAdditionPos,
    E_SubMode_LvlRefRun_WaitLeave,
    E_SubMode_LvlRefRun_RefRunError,
} E_LevelingAlgorithm_SubMode_RefRun;

typedef enum
{
    E_LvlReferenceRun_NotPerform = 0,
    E_LvlReferenceRun_Performing = 1,
    E_LvlReferenceRun_PerformCompltedOK = 2,
    E_LvlReferenceRun_PerformError = 3,
} E_LvlReferenceRunCompletedFlag;

typedef enum
{
    E_LvlRefRunSts_NoCond = 0, /* 条件不满足 */
    E_LvlRefRunSts_During = 1, /* 执行中 */
    E_LvlRefRunSts_Done   = 2, /* 完成 */
    E_LvlRefRunSts_Error  = 3  /* 执行过程中故障 */
} E_LvlRefRunSts;

typedef struct LevelingMotorInfo
{
    E_LevelingType LevelingType;
    E_LevelingMotorState LevelingMotorState;
    E_MotorMicroStepMode LevelingMotorMicroStepMode;
    E_LevelingAlgorithm_SubMode_RefRun LevelingAlgorithm_SubMode_RefRun;
    E_LvlReferenceRunCompletedFlag ReferenceRunCompletedFlag;
    uint8 StallErrorCnt;
    uint8 OpenErrorCnt;
    uint8 DrvComErrorCnt;
    uint8 DrvUVErrorCnt;
    uint8 DrvThermalShutDownErrorCnt;
    uint8 DrvTmWarningErrorCnt;
    uint16_t AdditionalStep;
    uint32_t HsPerRad;
    sint16_t BottomBlockPos;
    sint16_t TopBlockPos;
    sint16_t BottomLogicPos;
    sint16_t TopLogicPos;
    sint16_t DefaultPos;
    sint16_t CurrentMotorPos;
    sint16_t TargetPos;
    double CurrentAngle;
    double DefaultAngle;
} S_LevelingMotorInfo;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 获取电机的工作模式 */
/* 返回值：0:正常模式； 1：UDS模式 */
uint8_t LevelingMotor_GetLvlMotorRunMode(void);

E_LvlRefRunSts LevelingMotor_GetLvlRefRunSts(void);
Std_ReturnType LevelingMotor_GetLvlCurAngle(double *Angle);

Std_ReturnType LevelingMotor_StartRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType LevelingMotor_StopRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType LevelingMotor_RequestRoutineResult_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer);

Std_ReturnType LevelingMotor_StartRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType LevelingMotor_StopRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer);
Std_ReturnType LevelingMotor_RequestRoutineResult_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer);

Std_ReturnType LevelingMotor_IoCtrCallBack(E_IOCtrType IOCtrTypeState);

void LevelingMotorMainFunction(uint8_t timebase);
void LevelingMotorInit(void);

#endif /* LEVELINGMOTOR_LEVELINGMOTOR_H_ */
