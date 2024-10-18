#ifndef _ROUTINECTR_INTERFACE_H_
#define _ROUTINECTR_INTERFACE_H_
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
#define MAX_ROUTINECTR_NUM 7

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum{
    E_RountineCrtFuntion_CheckProgramePrecondition=0,
    E_RountineCrtFuntion_LevelingMotorReferenceRun,
    E_RountineCrtFuntion_SwivelingMotorReferenceRun,
    E_RountineCrtFuntion_LevellingMotorMove,
    E_RountineCrtFuntion_SwivelingMotorMove,
    E_RountineCrtFuntion_FanControl,
    E_RountineCrtFuntion_LeftRightDetection,
}E_RountineCrtFuntion;

typedef enum{
    E_RoutineType_ShortRoutine=1,
    E_RoutineType_LongRoutine=2,
    E_RoutineType_ContinuousRoutine=3,
}E_RoutineType;

typedef enum{
    E_RoutineStatus_RoutinueCompleted=0,
    E_RoutineStatus_RoutinueAborted=1,
    E_RoutineStatus_RoutinueExcecutes=2,
}E_RoutineStatus;

typedef struct RountineCtrInfo{
    E_RountineCrtFuntion RountineCrtFuntion;
    Std_ReturnType (*StartRoutine)(const uint8_t *InBuffer,uint8_t *OutBuffer);
    Std_ReturnType (*StopRoutine)(const uint8_t *InBuffer,uint8_t *OutBuffer);
    Std_ReturnType (*RequestRoutineResult)(const uint8_t *InBuffer,uint8_t *OutBuffer);
}S_RountineCtrInfo;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/  
Std_ReturnType StartRoutine_CheckProgramePrecondition(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_CheckProgramePrecondition(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_CheckProgramePrecondition(const uint8_t *InBuffer,uint8_t *OutBuffer);

Std_ReturnType StartRoutine_LevelingMotorReferenceRun(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_LevelingMotorReferenceRun(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_LevelingMotorReferenceRun(const uint8_t *InBuffer,uint8_t *OutBuffer);

Std_ReturnType StartRoutine_SwivelingMotorReferenceRun(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_SwivelingMotorReferenceRun(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_SwivelingMotorReferenceRun(const uint8_t *InBuffer,uint8_t *OutBuffer);

Std_ReturnType StartRoutine_LevellingMotorMove(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_LevellingMotorMove(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_LevellingMotorMove(const uint8_t *InBuffer,uint8_t *OutBuffer);

Std_ReturnType StartRoutine_SwivelingMotorMove(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_SwivelingMotorMove(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_SwivelingMotorMove(const uint8_t *InBuffer,uint8_t *OutBuffer);

Std_ReturnType StartRoutine_FanControl(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_FanControl(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_FanControl(const uint8_t *InBuffer,uint8_t *OutBuffer);

Std_ReturnType StartRoutine_LeftRightDetection(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType StopRoutine_LeftRightDetection(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType RequestRoutineResult_LeftRightDetection(const uint8_t *InBuffer,uint8_t *OutBuffer); 


Std_ReturnType Interface_StartRoutineCallBack(E_RountineCrtFuntion RountineCrtFuntion, const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType Interface_StopRoutineCallBack(E_RountineCrtFuntion RountineCrtFuntion, const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion RountineCrtFuntion, const uint8_t *InBuffer,uint8_t *OutBuffer);


void Interface_RoutineCtr_MainFunction(uint8_t timebase);
#endif