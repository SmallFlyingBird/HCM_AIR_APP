/*
 * RoutineCtr_Manager.c
 *
 *  Created on: 2024.04.26
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "RoutineCtr_Manager.h"
#include "ComSignal_Interface.h"
#include "LRDirection_Interface.h"
#include "LevelingMotor.h"
#include "SwivelingMotor.h"
#include "Fan.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType ASW_StartRoutine_CheckProgramePrecondition(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    double speed;
    uint32_t signalval;

    OutBuffer[0] = (E_RoutineType_ShortRoutine << 4) + E_RoutineStatus_RoutinueCompleted;

    Interface_GetSignal_VehSpdLgtQf(&signalval);
    if (signalval != 2 && signalval != 3)
    {
        OutBuffer[1] = 0x02;
        return E_OK;
    }

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&signalval);
    if ((E_UsageModeSts)signalval == E_UsageModeSts_Drvg)
    {
        OutBuffer[1] = 0x02;
        return E_OK;
    }

    Interface_GetSignal_VehSpdLgtA(&speed);
    /*
     *  1(km/h)=0.277777(m/s)
     *  4(km/h)=1.111111(m/s)
     */
    if ((speed / 0.277777) > 3)
    {
        OutBuffer[1] = 0x02;
        return E_OK;
    }

    OutBuffer[1] = 0x01;
    return E_OK;
}

Std_ReturnType ASW_StopRoutine_CheckProgramePrecondition(const uint8_t *InBuffer, uint8_t *OutBuffer)
{

    OutBuffer[0] = (E_RoutineType_ShortRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    return E_OK;
}

Std_ReturnType ASW_RequestRoutineResult_CheckProgramePrecondition(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    return E_NOT_OK;
}

Std_ReturnType ASW_StartRoutine_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    Fan_StartRoutineCtr_FanControl(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType ASW_StopRoutine_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    Fan_StopRoutineCtr_FanControl(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType ASW_RequestRoutineResult_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    Fan_RequestRoutineResult_FanControl(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType ASW_StartRoutine_LeftRightDetection(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;

    OutBuffer[0] = (E_RoutineType_ShortRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    Interface_DirectionDection_StartRoutine();

    return rtval;
}

Std_ReturnType ASW_StopRoutine_LeftRightDetection(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;

    OutBuffer[0] = (E_RoutineType_ShortRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    rtval = Interface_DirectionDection_StopRoutine();
    return rtval;
}

Std_ReturnType ASW_RequestRoutineResult_LeftRightDetection(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    E_LR_DIRECTION side;
    Interface_DirectionDection_RequestRoutineResult(&side);
    OutBuffer[0] = (E_RoutineType_ShortRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    if (side == DIRECTION_LEFT)
        OutBuffer[1] = 00;
    else
        OutBuffer[1] = 01;
    return rtval;
}
