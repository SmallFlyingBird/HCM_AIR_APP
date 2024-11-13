
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "RoutineCtr_Interface.h"
#include "RoutineCtr_Manager.h"
#include "Dcm.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_RountineCtrInfo gs_RountineCtrInfo[MAX_ROUTINECTR_NUM] = {
    {
        E_RountineCrtFuntion_CheckProgramePrecondition,
        .StartRoutine = StartRoutine_CheckProgramePrecondition,
        .StopRoutine = StopRoutine_CheckProgramePrecondition,
        .RequestRoutineResult = RequestRoutineResult_CheckProgramePrecondition,
    },
    {
        E_RountineCrtFuntion_FanControl,
        .StartRoutine = StartRoutine_FanControl,
        .StopRoutine = StopRoutine_FanControl,
        .RequestRoutineResult = RequestRoutineResult_FanControl,
    },
    {
        E_RountineCrtFuntion_LeftRightDetection,
        .StartRoutine = StartRoutine_LeftRightDetection,
        .StopRoutine = StopRoutine_LeftRightDetection,
        .RequestRoutineResult = RequestRoutineResult_LeftRightDetection,
    },
};

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

static S_RountineCtrInfo *GetRountineCtrInfo(E_RountineCrtFuntion RountineCrtFuntion)
{
    uint8_t i = 0;

    for (i = 0; i < MAX_ROUTINECTR_NUM; i++)
    {
        if (gs_RountineCtrInfo[i].RountineCrtFuntion == RountineCrtFuntion)
            return &(gs_RountineCtrInfo[i]);
    }

    return NULL;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

/********************************Routine control call back******************************************/
Std_ReturnType StartRoutine_CheckProgramePrecondition(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;

    rtval = ASW_StartRoutine_CheckProgramePrecondition(InBuffer, OutBuffer);

    return rtval;
}

Std_ReturnType StopRoutine_CheckProgramePrecondition(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;

    rtval = ASW_StopRoutine_CheckProgramePrecondition(InBuffer, OutBuffer);

    return rtval;
}

Std_ReturnType RequestRoutineResult_CheckProgramePrecondition(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;

    rtval = ASW_RequestRoutineResult_CheckProgramePrecondition(InBuffer, OutBuffer);

    return rtval;
}

Std_ReturnType StartRoutine_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    rtval = ASW_StartRoutine_FanControl(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType StopRoutine_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    rtval = ASW_StopRoutine_FanControl(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType RequestRoutineResult_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    rtval = ASW_RequestRoutineResult_FanControl(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType StartRoutine_LeftRightDetection(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    rtval = ASW_StartRoutine_LeftRightDetection(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType StopRoutine_LeftRightDetection(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    rtval = ASW_StopRoutine_LeftRightDetection(InBuffer, OutBuffer);
    return rtval;
}

Std_ReturnType RequestRoutineResult_LeftRightDetection(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    rtval = ASW_RequestRoutineResult_LeftRightDetection(InBuffer, OutBuffer);
    return rtval;
}

/**************************************************BSW call back***********************************************************************/
Std_ReturnType Interface_StartRoutineCallBack(E_RountineCrtFuntion RountineCrtFuntion, const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    S_RountineCtrInfo *RountineCtrInfo = NULL;
    uint8_t result;
    RountineCtrInfo = GetRountineCtrInfo(RountineCrtFuntion);
    if (RountineCtrInfo == NULL)
        return E_NOT_OK;
    if (RountineCtrInfo->StartRoutine == NULL)
        return E_NOT_OK;

    rtval |= RountineCtrInfo->StartRoutine(InBuffer, OutBuffer);

    return rtval;
}

Std_ReturnType Interface_StopRoutineCallBack(E_RountineCrtFuntion RountineCrtFuntion, const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    S_RountineCtrInfo *RountineCtrInfo = NULL;

    RountineCtrInfo = GetRountineCtrInfo(RountineCrtFuntion);
    if (RountineCtrInfo == NULL)
        return E_NOT_OK;

    if (RountineCtrInfo->StopRoutine == NULL)
        return E_NOT_OK;

    rtval |= RountineCtrInfo->StopRoutine(InBuffer, OutBuffer);

    return rtval;
}

Std_ReturnType Interface_RequestRoutineResultCallBack(E_RountineCrtFuntion RountineCrtFuntion, const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    S_RountineCtrInfo *RountineCtrInfo = NULL;
    uint8_t result;
    RountineCtrInfo = GetRountineCtrInfo(RountineCrtFuntion);
    if (RountineCtrInfo == NULL)
        return E_NOT_OK;

    if (RountineCtrInfo->RequestRoutineResult == NULL)
        return E_NOT_OK;

    rtval |= RountineCtrInfo->RequestRoutineResult(InBuffer, OutBuffer);

    return rtval;
}

void Interface_RoutineCtr_MainFunction(uint8_t timebase)
{
    static Dcm_SesCtrlType CurSesCtrlType = DCM_DEFAULT_SESSION;
    Dcm_SesCtrlType SesCtrlTypetmp;
    uint8_t i = 0;
    E_RoutineType RoutineType;
    E_RoutineStatus RoutineStatus;

    Dcm_GetSesCtrlType(&SesCtrlTypetmp);

    if (SesCtrlTypetmp != CurSesCtrlType)
    {
        CurSesCtrlType = SesCtrlTypetmp;

        if (SesCtrlTypetmp == DCM_DEFAULT_SESSION)
        {
            /*从别的会话模式跳转到默认会话模式*/
            for (i = 0; i < MAX_ROUTINECTR_NUM; i++)
            {
                gs_RountineCtrInfo[i].StopRoutine(&RoutineType, &RoutineStatus);
            }
        }
    }
}