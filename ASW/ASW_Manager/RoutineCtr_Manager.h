/*
 * RoutineCtr_Manager.h
 *
 *  Created on: 2024.04.26
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "RoutineCtr_Interface.h"
typedef Std_ReturnType (*Dem_ReadDataFncType)(uint8* Buffer, uint16 BufSize);
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/


/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType ASW_StartRoutine_CheckProgramePrecondition(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType ASW_StopRoutine_CheckProgramePrecondition(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType ASW_RequestRoutineResult_CheckProgramePrecondition(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType ASW_StartRoutine_FanControl(const uint8_t *InBuffer,uint8_t *OutBuffer );
Std_ReturnType ASW_StopRoutine_FanControl(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType ASW_RequestRoutineResult_FanControl(const uint8_t *InBuffer,uint8_t *OutBuffer );
Std_ReturnType ASW_StartRoutine_LeftRightDetection(const uint8_t *InBuffer,uint8_t *OutBuffer );
Std_ReturnType ASW_StopRoutine_LeftRightDetection(const uint8_t *InBuffer,uint8_t *OutBuffer);
Std_ReturnType ASW_RequestRoutineResult_LeftRightDetection(const uint8_t *InBuffer,uint8_t *OutBuffer);