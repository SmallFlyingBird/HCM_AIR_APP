/*
 * StepMotor_Interface.c
 *
 *  Created on: 2024锟斤拷1锟斤拷10锟斤拷
 *      Author: mihuiliang
 */
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AswInterfaceManager.h"
/****************************************************************
 *                                                              *
 *                  Global Private Variable Define              *
 *                                                              *
 ****************************************************************/
static Std_ReturnType LevelingMotorDevDrvState = E_NOT_OK;
static Std_ReturnType SwivelingingMotorDevDrvState = E_NOT_OK;
static S_MotorMotionAlgorithmManager g_S_MotorMotionAlgorithmManager[MAX_MOTOR_NUM] = {
    {.MotorTpye = E_MotorTpye_Leveling, .StallDetectEnFlag = 0XFF, .MotorCurCurrent = 0XFFFF, .MotorTotalSteppNumber = 0, .MotorAlgoEnableFlag = 0},
    {.MotorTpye = E_MotorTpye_Swiveling, .StallDetectEnFlag = 0XFF, .MotorCurCurrent = 0XFFFF, .MotorTotalSteppNumber = 0, .MotorAlgoEnableFlag = 0},
};

#if S32K312_EMIOS_PWM_ADAPT
static uint8_t FirstPluseFlag = 0;
#endif

/****************************************************************
 *                                                              *
 *                     Private Functions Define                 *
 *                                                              *
 ****************************************************************/

static S_MotorMotionAlgorithmManager *GetMotionAlgoByMotorTpye(E_MotorTpye MotorTpye)
{
    uint8_t i = 0;
    for (i = 0; i < MAX_MOTOR_NUM; i++)
    {
        if (g_S_MotorMotionAlgorithmManager[i].MotorTpye == MotorTpye)
            return (&g_S_MotorMotionAlgorithmManager[i]);
    }

    return NULL;
}

static void StepMotorRunStopTimerManager(S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager, uint8 timerbase)
{
    uint32_t UsageInterval;
    uint8_t OverUsageRatio, NormalUsageRatio, CurUsageRatio;
    if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Phase ||
        ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Hold2RunDelay_Phase ||
        ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Run2HoldDelay_Phase)
    {
        ptMotorAlgorithmManager->MotorStopTotalTimer += timerbase;
    }
    else
    {
        ptMotorAlgorithmManager->MotorRunTotalTimer += timerbase;
    }

    ptMotorAlgorithmManager->UsageIntervalTimer += timerbase;

    if (ptMotorAlgorithmManager->MotorTpye == E_MotorTpye_Leveling)
    {
        UsageInterval = ((uint32_t)Get_pLvlUsageInterval()) * 1000;
        OverUsageRatio = Get_pLvlOverUsage();
        NormalUsageRatio = Get_pLvlNormUsage();
    }
    else if (ptMotorAlgorithmManager->MotorTpye == E_MotorTpye_Swiveling)
    {
        UsageInterval = ((uint32_t)Get_pSvlUsageInterval()) * 1000;
        OverUsageRatio = Get_pSvlOverUsage();
        NormalUsageRatio = Get_pSvlNormUsage();
    }
    else
    {
        return;
    }

    if (ptMotorAlgorithmManager->UsageIntervalTimer >= UsageInterval)
    {
        ptMotorAlgorithmManager->UsageIntervalTimer = 0;

        CurUsageRatio = (uint8_t)((ptMotorAlgorithmManager->MotorRunTotalTimer * 100) / UsageInterval);

        if (CurUsageRatio > OverUsageRatio)
        {
            /*OverUsage*/
            Interface_SetDtcStepMotorError(ptMotorAlgorithmManager->MotorTpye, E_StepMotorErrorType_OverUse, 1);
        }
        else if (CurUsageRatio < NormalUsageRatio)
        {
            /*NormalUsage*/
            Interface_SetDtcStepMotorError(ptMotorAlgorithmManager->MotorTpye, E_StepMotorErrorType_OverUse, 0);
        }

        ptMotorAlgorithmManager->MotorRunTotalTimer = 0;
        ptMotorAlgorithmManager->MotorStopTotalTimer = 0;
    }
}

static void StepMotorAlgoDelayTimerManager(S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager, uint8 timerbase)
{
    E_PulseGeneratorFunction PulseGeneratorFunction;

    if (ptMotorAlgorithmManager->MotorTpye == E_MotorTpye_Leveling)
        PulseGeneratorFunction = E_PulseGeneratorFunction_LevelingMotor;
    else
        PulseGeneratorFunction = E_PulseGeneratorFunction_SwivelingMotor;

    if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Hold2RunDelay_Phase)
    {
        if (ptMotorAlgorithmManager->hold2run_timer_delay > 0)
        {
            ptMotorAlgorithmManager->hold2run_timer_delay = CNT_DEC(ptMotorAlgorithmManager->hold2run_timer_delay, timerbase, 0);
            if (ptMotorAlgorithmManager->hold2run_timer_delay == 0)
            {
#if S32K312_EMIOS_PWM_ADAPT
                FirstPluseFlag = 1;
#endif

                if (Interface_EnablePulseGenerator(PulseGeneratorFunction, ptMotorAlgorithmManager->AccStepArray[0], 50) == E_OK)
                {
                    ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Run_Accelerate_Phase;
                }
                else
                {
                    ptMotorAlgorithmManager->hold2run_timer_delay = CNT_INC(ptMotorAlgorithmManager->hold2run_timer_delay, timerbase, 0xFFFFFFFF);
                }
            }
        }
    }
    else if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Run2HoldDelay_Phase)
    {
        if (ptMotorAlgorithmManager->run2hold_timer_delay > 0)
        {
            ptMotorAlgorithmManager->run2hold_timer_delay = CNT_DEC(ptMotorAlgorithmManager->run2hold_timer_delay, timerbase, 0);
            if (ptMotorAlgorithmManager->run2hold_timer_delay == 0)
            {
                if (Interface_SetMotorCurrent(ptMotorAlgorithmManager->MotorTpye, ptMotorAlgorithmManager->MotorHoldCurrent) == E_OK)
                {
                    ptMotorAlgorithmManager->MotorCurCurrent = ptMotorAlgorithmManager->MotorHoldCurrent;
                    ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Stop_Phase;
                }
                else
                {
                    /*The current set failed ,then reset the current next task cycle */
                    ptMotorAlgorithmManager->run2hold_timer_delay = CNT_INC(ptMotorAlgorithmManager->run2hold_timer_delay, timerbase, 0xFFFFFFFF);
                }
            }
        }
    }
}

static Std_ReturnType SetMotorDriverDirPinState(E_MotorTpye MotorTpye, E_MotorDirPinState PinState)
{
    Std_ReturnType rtval = E_OK;
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    S_MotorDrvDirPolarityDataSrc MotorDrvDirPolarityDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_MotorDrv_Dev *MotorDevTmp = NULL;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    if (ptMotorAlgorithmManager->MotorCurDirPinState == PinState)
        return E_OK;

    MotorDrvDirPolarityDataSrc.MotorDirPinState = PinState;
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevDirPolarity;
    MotorDrvDataPackets.datasrc = (void *)&MotorDrvDirPolarityDataSrc;

    rtval |= MotorDevTmp->Write((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
        ptMotorAlgorithmManager->MotorCurDirPinState = PinState;

    return rtval;
}
/*
 *电机开路检测控制
 *val=1 ：开启电机驱动芯片开路检测
 *val=0 ：关闭电机驱动芯片开路检测
 */
static Std_ReturnType MotorOpenLoadDetCtr(E_MotorTpye MotorTpye, uint8_t val)
{
    Std_ReturnType rtval = E_OK;
    S_MotorDrv_Dev *MotorDevTmp = NULL;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_DevOpenLoadDetectSwitchStateSrc DevOpenLoadDetectSwitchStateSrc;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);
    if (MotorDevTmp == NULL)
        return E_NOT_OK;

    DevOpenLoadDetectSwitchStateSrc.OpenLoadDetectState = val;
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevOpenLoadDetectSwitchState;
    MotorDrvDataPackets.datasrc = (void *)(&DevOpenLoadDetectSwitchStateSrc);

    rtval |= MotorDevTmp->Write((void *)(&MotorDrvDataPackets));

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

/*
 * Attention : This function will reset Motor drv dir pinstate and Motor motion algo's MotorPosDirPolarity
 */
Std_ReturnType Interface_ResetMotorDirPinPolariy(E_MotorTpye MotorTpye, E_MotorDirPinState PinState)
{
    Std_ReturnType rtval = E_OK;
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    S_MotorDrvDirPolarityDataSrc MotorDrvDirPolarityDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_MotorDrv_Dev *MotorDevTmp = NULL;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    if (ptMotorAlgorithmManager->MotorCurDirPinState == PinState)
    {
        if (PinState == E_MotorDirPinState_LOW)
            ptMotorAlgorithmManager->MotorPosDirPolarity = E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR;
        else
            ptMotorAlgorithmManager->MotorPosDirPolarity = E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR;
        return E_OK;
    }

    MotorDrvDirPolarityDataSrc.MotorDirPinState = PinState;
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevDirPolarity;
    MotorDrvDataPackets.datasrc = (void *)&MotorDrvDirPolarityDataSrc;

    rtval |= MotorDevTmp->Write((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
    {
        ptMotorAlgorithmManager->MotorCurDirPinState = PinState;
        if (PinState == E_MotorDirPinState_LOW)
            ptMotorAlgorithmManager->MotorPosDirPolarity = E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR;
        else
            ptMotorAlgorithmManager->MotorPosDirPolarity = E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR;
    }

    return rtval;
}

Std_ReturnType Interface_SetMotorCurrent(E_MotorTpye MotorTpye, uint16_t current)
{
    Std_ReturnType rtval = E_OK;
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    S_MotorDrvOutputCurrentDataSrc MotorDrvOutputCurrentDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_MotorDrv_Dev *MotorDevTmp = NULL;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    if (current == ptMotorAlgorithmManager->MotorCurCurrent)
        return E_OK;

    MotorDrvOutputCurrentDataSrc.MotorCurrent = current;
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevOutputCurrent;
    MotorDrvDataPackets.datasrc = (void *)(&MotorDrvOutputCurrentDataSrc);

    rtval |= MotorDevTmp->Write((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
        ptMotorAlgorithmManager->MotorCurCurrent = current;

    return rtval;
}

Std_ReturnType Interface_GetMotorDevDrvState(E_MotorTpye MotorTpye)
{
    if (MotorTpye == E_MotorTpye_Leveling)
        return LevelingMotorDevDrvState;
    else if (MotorTpye == E_MotorTpye_Swiveling)
        return SwivelingingMotorDevDrvState;

    return E_NOT_OK;
}

Std_ReturnType Interface_GetMotorTemperatureInfo(E_MotorTpye MotorTpye, E_MotorTemperatureInfo *MotorTemperatureInfo)
{
    Std_ReturnType rtval = E_OK;
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    S_MotorTemperatureDataSrc MotorTemperatureDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_MotorDrv_Dev *MotorDevTmp = NULL;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    /*MotorTemperatureDataSrc.MotorTemperatureInfo=E_MotorMotorTemp_Normal;*/
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevTemperature;
    MotorDrvDataPackets.datasrc = (void *)(&MotorTemperatureDataSrc);

    rtval |= MotorDevTmp->Read((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
        *MotorTemperatureInfo = MotorTemperatureDataSrc.MotorTemperatureInfo;
    else
        *MotorTemperatureInfo = E_MotorMotorTemp_Normal;

    return rtval;
}

Std_ReturnType Interface_GetMotorDiagnoseInfo(E_MotorTpye MotorTpye, U_DevErrorTypt *DevErrorTypt)
{
    Std_ReturnType rtval = E_OK;
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    S_MotorDiagnoseDataSrc MotorDiagnoseDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_MotorDrv_Dev *MotorDevTmp = NULL;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevDiagnose;
    MotorDrvDataPackets.datasrc = (void *)(&MotorDiagnoseDataSrc);

    rtval |= MotorDevTmp->Read((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
    {
        DevErrorTypt->DevError = MotorDiagnoseDataSrc.DevErrorTypt.DevError;
        if (MotorDiagnoseDataSrc.DevErrorTypt.bits.ComError == 1)
        {
            Interface_SetSpiError(E_SpiErrorDevice_MotorDrv, MotorDevTmp->Device_id);
        }
        else
        {
            Interface_ClearSpiError(E_SpiErrorDevice_MotorDrv, MotorDevTmp->Device_id);
        }
    }
    else
        DevErrorTypt->DevError = 0;

    return rtval;
}

Std_ReturnType Interface_PulseGeneratorCallBack(E_MotorTpye MotorTpye)
{
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    Std_ReturnType rtval = E_OK;
    E_PulseGeneratorFunction PulseGeneratorFunction;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    if (MotorTpye == E_MotorTpye_Leveling)
    {
        PulseGeneratorFunction = E_PulseGeneratorFunction_LevelingMotor;
    }
    else if (MotorTpye == E_MotorTpye_Swiveling)
    {
        PulseGeneratorFunction = E_PulseGeneratorFunction_SwivelingMotor;
    }
    else
    {
        return E_NOT_OK;
    }

#if S32K312_EMIOS_PWM_ADAPT
    if (FirstPluseFlag == 1)
    {
        FirstPluseFlag = 0;
        return E_OK;
    }
#endif

    ptMotorAlgorithmManager->MotorTotalSteppNumber++;
    if (ptMotorAlgorithmManager->MotorCurPosition < ptMotorAlgorithmManager->MotorTargetPosition)
    {
        ptMotorAlgorithmManager->MotorCurPosition++;
    }
    else if (ptMotorAlgorithmManager->MotorCurPosition > ptMotorAlgorithmManager->MotorTargetPosition)
    {
        ptMotorAlgorithmManager->MotorCurPosition--;
    }

    if (ptMotorAlgorithmManager->MotorCurPosition == ptMotorAlgorithmManager->MotorTargetPosition)
    {
        if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Run_Decelerate_Phase)
        {
            Interface_DisablePulseGenerator(PulseGeneratorFunction, ptMotorAlgorithmManager->DecStepArray[0], 0);
            ptMotorAlgorithmManager->run2hold_timer_delay = ptMotorAlgorithmManager->config_run2hold_timer_delay;
            ptMotorAlgorithmManager->hold2run_timer_delay = 0;

            if (ptMotorAlgorithmManager->run2hold_timer_delay == 0)
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Stop_Phase;
            else
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Stop_Run2HoldDelay_Phase;
        }
    }
    switch (ptMotorAlgorithmManager->MotorState)
    {
    case E_MotorMotionState_Stop_Phase:
        break;
    case E_MotorMotionState_Run_Accelerate_Phase:
        ptMotorAlgorithmManager->AccPluseArray_index++;
        if (ptMotorAlgorithmManager->AccPluseArray_index < ptMotorAlgorithmManager->AccPluseNum)
        {
            Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->AccStepArray[ptMotorAlgorithmManager->AccPluseArray_index], 50);
        }
        else
        {
            if (ptMotorAlgorithmManager->MaxSpeeedPluseNum > 0)
            {
                Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->AccStepArray[(ptMotorAlgorithmManager->AccPluseNum - 1)], 50);
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Run_Max_Speed_Phase;
            }
            else
            {
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Run_Decelerate_Phase;
                Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->DecStepArray[ptMotorAlgorithmManager->DecPluseArray_index], 50);
            }
        }
        break;
    case E_MotorMotionState_Run_Max_Speed_Phase:
        if (ptMotorAlgorithmManager->MotorStopFlag == E_MOTOR_DEC_STOP)
        {
            Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->DecStepArray[ptMotorAlgorithmManager->DecPluseArray_index], 50);
            ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Run_Decelerate_Phase;
            ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_NO_STOP_FLAG;
        }
        else
        {
            ptMotorAlgorithmManager->MaxSpeeedPluseArray_index++;
            if (ptMotorAlgorithmManager->MaxSpeeedPluseArray_index < ptMotorAlgorithmManager->MaxSpeeedPluseNum)
            {
                Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->AccStepArray[(ptMotorAlgorithmManager->AccPluseNum - 1)], 50);
            }
            else
            {
                Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->DecStepArray[(ptMotorAlgorithmManager->DecPluseArray_index)], 50);
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Run_Decelerate_Phase;
            }
        }
        break;
    case E_MotorMotionState_Run_Decelerate_Phase:

        if (ptMotorAlgorithmManager->DecPluseArray_index == 0)
        {
            Interface_DisablePulseGenerator(PulseGeneratorFunction, ptMotorAlgorithmManager->DecStepArray[ptMotorAlgorithmManager->DecPluseArray_index], 0);
            ptMotorAlgorithmManager->MotorTargetPosition = ptMotorAlgorithmManager->MotorCurPosition;

            ptMotorAlgorithmManager->run2hold_timer_delay = ptMotorAlgorithmManager->config_run2hold_timer_delay;
            ptMotorAlgorithmManager->hold2run_timer_delay = 0;

            if (ptMotorAlgorithmManager->run2hold_timer_delay == 0)
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Stop_Phase;
            else
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Stop_Run2HoldDelay_Phase;

            ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_NO_STOP_FLAG;
        }
        else
        {
            ptMotorAlgorithmManager->DecPluseArray_index--;
            Interface_SetPulseGnerator(PulseGeneratorFunction, ptMotorAlgorithmManager->DecStepArray[ptMotorAlgorithmManager->DecPluseArray_index], 50);
        }
        break;
    }
}

E_SetPosState Interface_SetMotorPosition(E_MotorTpye MotorTpye, sint16 Position)
{
    E_SetPosState rtval = E_PosSet_OK;
    uint16_t pluse = 0;
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;
    E_PulseGeneratorFunction PulseGeneratorFunction;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
        return E_PosSet_Error;

    if (Position == ptMotorAlgorithmManager->MotorTargetPosition)
        return E_PosSet_OK;

    if (MotorTpye == E_MotorTpye_Leveling)
    {
        PulseGeneratorFunction = E_PulseGeneratorFunction_LevelingMotor;
    }
    else if (MotorTpye == E_MotorTpye_Swiveling)
    {
        PulseGeneratorFunction = E_PulseGeneratorFunction_SwivelingMotor;
    }
    else
    {
        return E_PosSet_Error;
    }

    if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Phase ||
        ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Hold2RunDelay_Phase ||
        ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Run2HoldDelay_Phase)
    {

        if (Position == ptMotorAlgorithmManager->MotorCurPosition)
        {
            /*电机处于静止状态，设置的位置等于当前位置*/
            return E_PosSet_OK;
        }
        /**************************************************************Motor is in stop phase**************************************************************/
        pluse = (Position > ptMotorAlgorithmManager->MotorCurPosition) ? (Position - ptMotorAlgorithmManager->MotorCurPosition) : (ptMotorAlgorithmManager->MotorCurPosition - Position);
        if (pluse > (ptMotorAlgorithmManager->AccDecStepNum * 2))
        {
            ptMotorAlgorithmManager->AccPluseNum = ptMotorAlgorithmManager->AccDecStepNum;
            ptMotorAlgorithmManager->DecPluseNum = ptMotorAlgorithmManager->AccDecStepNum;
            ptMotorAlgorithmManager->MaxSpeeedPluseNum = pluse - ptMotorAlgorithmManager->AccDecStepNum * 2;
        }
        else
        {
            ptMotorAlgorithmManager->AccPluseNum = pluse / 2;
            ptMotorAlgorithmManager->DecPluseNum = pluse - ptMotorAlgorithmManager->AccPluseNum;
            ptMotorAlgorithmManager->MaxSpeeedPluseNum = 0;
        }

        ptMotorAlgorithmManager->AccPluseArray_index = 0;
        ptMotorAlgorithmManager->DecPluseArray_index = ptMotorAlgorithmManager->DecPluseNum - 1;
        ptMotorAlgorithmManager->MaxSpeeedPluseArray_index = 0;
        if (Position > ptMotorAlgorithmManager->MotorCurPosition)
        {
            if ((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR) &&
                (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_HIGH))
            {
                if (SetMotorDriverDirPinState(MotorTpye, E_MotorDirPinState_LOW) == E_OK)
                    ptMotorAlgorithmManager->MotorCurDirPinState = E_MotorDirPinState_LOW;
                else
                    return E_PosSet_Error;
            }
            else if ((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR) &&
                     (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_LOW))
            {
                if (SetMotorDriverDirPinState(MotorTpye, E_MotorDirPinState_HIGH) == E_OK)
                    ptMotorAlgorithmManager->MotorCurDirPinState = E_MotorDirPinState_HIGH;
                else
                    return E_PosSet_Error;
            }
        }
        else
        {
            if ((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR) &&
                (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_LOW))
            {
                if (SetMotorDriverDirPinState(MotorTpye, E_MotorDirPinState_HIGH) == E_OK)
                    ptMotorAlgorithmManager->MotorCurDirPinState = E_MotorDirPinState_HIGH;
                else
                    return E_PosSet_Error;
            }
            else if ((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR) &&
                     (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_HIGH))
            {
                if (SetMotorDriverDirPinState(MotorTpye, E_MotorDirPinState_LOW) == E_OK)
                    ptMotorAlgorithmManager->MotorCurDirPinState = E_MotorDirPinState_LOW;
                else
                    return E_PosSet_Error;
            }
        }

        if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Hold2RunDelay_Phase)
        {
            ptMotorAlgorithmManager->MotorTargetPosition = Position;
            return E_PosSet_OK;
        }

        if (Interface_SetMotorCurrent(MotorTpye, ptMotorAlgorithmManager->MotorRunCurrent) == E_OK)
        {
            ptMotorAlgorithmManager->MotorCurCurrent = ptMotorAlgorithmManager->MotorRunCurrent;

            ptMotorAlgorithmManager->hold2run_timer_delay = ptMotorAlgorithmManager->config_hold2run_timer_delay;
            ptMotorAlgorithmManager->run2hold_timer_delay = 0;

            if (ptMotorAlgorithmManager->hold2run_timer_delay == 0)
            {
                if (Interface_EnablePulseGenerator(PulseGeneratorFunction, ptMotorAlgorithmManager->AccStepArray[0], 50) == E_OK)
                {
#if S32K312_EMIOS_PWM_ADAPT
                    FirstPluseFlag = 1;
#endif
                    ptMotorAlgorithmManager->MotorTargetPosition = Position;
                    ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Run_Accelerate_Phase;

                    rtval = E_PosSet_OK;
                }
                else
                {
                    rtval = E_PosSet_Error;
                }
            }
            else
            {
                ptMotorAlgorithmManager->MotorState = E_MotorMotionState_Stop_Hold2RunDelay_Phase;
                ptMotorAlgorithmManager->MotorTargetPosition = Position;
                rtval = E_PosSet_OK;
            }
        }
        else
        {
            /*set current failed */
            return E_PosSet_Error;
        }
    }
    else if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Run_Max_Speed_Phase)
    {
        /**************************************************************Motor is in max speed phase**************************************************************/
        if (Position >= ptMotorAlgorithmManager->MotorCurPosition)
        {
            if (((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR) && (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_LOW)) ||
                ((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR) && (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_HIGH)))
            {
                pluse = Position - ptMotorAlgorithmManager->MotorCurPosition;
                if (pluse > ptMotorAlgorithmManager->AccDecStepNum)
                {
                    ptMotorAlgorithmManager->MaxSpeeedPluseNum = pluse - ptMotorAlgorithmManager->AccDecStepNum;
                    ptMotorAlgorithmManager->MotorTargetPosition = Position;
                    rtval = E_PosSet_OK;
                }
                else
                {
#if DEC_STOP_MOTO_POS_ENABLE
                    ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_DEC_STOP;
#else
                    ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_IMMEDIATE_STOP;
#endif
                    rtval = E_PosSet_Pending;
                }
            }
            else
            {

#if DEC_STOP_MOTO_POS_ENABLE
                ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_DEC_STOP;
#else
                ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_IMMEDIATE_STOP;
#endif
                rtval = E_PosSet_Pending;
            }
        }
        else
        {
            if (((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR) && (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_HIGH)) ||
                ((ptMotorAlgorithmManager->MotorPosDirPolarity == E_MotorPosDirPolarity_PINHIGH_AS_POSTIVE_DIR) && (ptMotorAlgorithmManager->MotorCurDirPinState == E_MotorDirPinState_LOW)))
            {
                /*计算剩余脉冲数量*/
                pluse = ptMotorAlgorithmManager->MotorCurPosition - Position;
                if (pluse > ptMotorAlgorithmManager->AccDecStepNum)
                {
                    ptMotorAlgorithmManager->MaxSpeeedPluseNum = pluse - ptMotorAlgorithmManager->AccDecStepNum;
                    ptMotorAlgorithmManager->MotorTargetPosition = Position;
                    rtval = E_PosSet_OK;
                }
                else
                {

#if DEC_STOP_MOTO_POS_ENABLE
                    ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_DEC_STOP;
#else
                    ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_IMMEDIATE_STOP;
#endif
                    rtval = E_PosSet_Pending;
                }
            }
            else
            {

#if DEC_STOP_MOTO_POS_ENABLE
                ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_DEC_STOP;
#else
                ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_IMMEDIATE_STOP;
#endif
                rtval = E_PosSet_Pending;
            }
        }
    }
    else
    {
        /**************************************************************Motor is in Acc or Dec  phase**************************************************************/
        rtval = E_PosSet_Pending;
    }

    return rtval;
}

E_SetPosState Interface_ResetMotorPosition(E_MotorTpye MotorTpye, sint16 Position)
{
    E_SetPosState rtval = E_PosSet_OK;

    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
        return E_PosSet_Error;

    if (ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Phase ||
        ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Hold2RunDelay_Phase ||
        ptMotorAlgorithmManager->MotorState == E_MotorMotionState_Stop_Run2HoldDelay_Phase)
    {
        ptMotorAlgorithmManager->MotorCurPosition = Position;
        ptMotorAlgorithmManager->MotorTargetPosition = Position;
        rtval = E_PosSet_OK;
    }
    else
    {
        rtval = E_PosSet_Pending;
    }

    return rtval;
}

Std_ReturnType Interface_SetMotorMotionParameter(E_MotorTpye MotorTpye, uint16_t AccDecStepNum, uint16_t RunCurrent, uint16_t HoldCurrent)
{

    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;
    if (ptMotorAlgorithmManager->MotorState != E_MotorMotionState_Stop_Phase)
        return E_NOT_OK;

    ptMotorAlgorithmManager->AccDecStepNum = AccDecStepNum;
    ptMotorAlgorithmManager->MotorRunCurrent = RunCurrent;
    ptMotorAlgorithmManager->MotorHoldCurrent = HoldCurrent;

    return E_OK;
}

Std_ReturnType Interface_StopMotor(E_MotorTpye MotorTpye)
{
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    if ((ptMotorAlgorithmManager->MotorStopFlag == E_MOTOR_NO_STOP_FLAG) &&
        (ptMotorAlgorithmManager->MotorState != E_MotorMotionState_Run_Decelerate_Phase) &&
        (ptMotorAlgorithmManager->MotorState != E_MotorMotionState_Stop_Run2HoldDelay_Phase) &&
        (ptMotorAlgorithmManager->MotorState != E_MotorMotionState_Stop_Phase))
    {
#if DEC_STOP_MOTO_POS_ENABLE
        ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_DEC_STOP;
#else
        ptMotorAlgorithmManager->MotorStopFlag = E_MOTOR_IMMEDIATE_STOP;
#endif
    }

    return E_OK;
}

Std_ReturnType Interface_GetMotorCurPosition(E_MotorTpye MotorTpye, sint16 *curpos)
{

    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
        return E_NOT_OK;

    *curpos = ptMotorAlgorithmManager->MotorCurPosition;

    return E_OK;
}
E_MotorMotionState Interface_GetMotorMotionState(E_MotorTpye MotorTpye)
{
    S_MotorMotionAlgorithmManager *ptMotorAlgorithmManager = NULL;

    ptMotorAlgorithmManager = GetMotionAlgoByMotorTpye(MotorTpye);

    if (ptMotorAlgorithmManager == NULL)
    {
        return E_MotorMotionState_Stop_Phase;
    }

    return ptMotorAlgorithmManager->MotorState;
}

Std_ReturnType Interface_EnableMotorStallDetect(E_MotorTpye MotorTpye)
{
    Std_ReturnType rtval = E_OK;
    S_MotorDrv_Dev *MotorDevTmp = NULL;
    S_MotorMotionAlgorithmManager *MotorMotionAlgo = NULL;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_DevStallDetectSwitchStateDataSrc DataSrc;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);
    MotorMotionAlgo = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || MotorMotionAlgo == NULL)
        return E_NOT_OK;

    if (MotorMotionAlgo->StallDetectEnFlag == 1)
        return E_OK;

    DataSrc.StallDetectState = 1;
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevStallDetectSwitchState;
    MotorDrvDataPackets.datasrc = (void *)(&DataSrc);

    rtval |= MotorDevTmp->Write((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
        MotorMotionAlgo->StallDetectEnFlag = 1;

    return rtval;
}
Std_ReturnType Interface_DisableMotorStallDetect(E_MotorTpye MotorTpye)
{
    Std_ReturnType rtval = E_OK;
    S_MotorDrv_Dev *MotorDevTmp = NULL;
    S_MotorMotionAlgorithmManager *MotorMotionAlgo = NULL;
    S_MotorDrvDataPackets MotorDrvDataPackets;
    S_DevStallDetectSwitchStateDataSrc DataSrc;

    MotorDevTmp = GetMotorDrvByMotorTpye(MotorTpye);
    MotorMotionAlgo = GetMotionAlgoByMotorTpye(MotorTpye);

    if (MotorDevTmp == NULL || MotorMotionAlgo == NULL)
        return E_NOT_OK;

    if (MotorMotionAlgo->StallDetectEnFlag == 0)
        return E_OK;

    DataSrc.StallDetectState = 0;
    MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
    MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevStallDetectSwitchState;
    MotorDrvDataPackets.datasrc = (void *)(&DataSrc);

    rtval |= MotorDevTmp->Write((void *)(&MotorDrvDataPackets));

    if (rtval == E_OK)
        MotorMotionAlgo->StallDetectEnFlag = 0;

    return rtval;
}

/*
 *suggest to put this function into 1-5ms task
 *
 */
void MotorMotionMainFunction(uint8_t timebase)
{
    uint8 index = 0;
    for (index = 0; index < MAX_MOTOR_NUM; index++)
    {
        if (g_S_MotorMotionAlgorithmManager[index].MotorAlgoEnableFlag == 0)
            continue;

        StepMotorAlgoDelayTimerManager(&(g_S_MotorMotionAlgorithmManager[index]), timebase);
        StepMotorRunStopTimerManager(&(g_S_MotorMotionAlgorithmManager[index]), timebase);

        if (g_S_MotorMotionAlgorithmManager[index].MotorState <= E_MotorMotionState_Stop_Run2HoldDelay_Phase)
        {
            /*电机处于静止状态，关闭开路检测*/
            if (g_S_MotorMotionAlgorithmManager[index].OpenDetectEnFlag == 1)
            {
                if (MotorOpenLoadDetCtr(g_S_MotorMotionAlgorithmManager[index].MotorTpye, 0) == E_OK)
                {
                    g_S_MotorMotionAlgorithmManager[index].OpenDetectEnFlag = 0;
                }
            }
        }
        else
        {
            /*电机处于运动状态，开启开路检测*/
            if (g_S_MotorMotionAlgorithmManager[index].OpenDetectEnFlag == 0)
            {
                if (MotorOpenLoadDetCtr(g_S_MotorMotionAlgorithmManager[index].MotorTpye, 1) == E_OK)
                {
                    g_S_MotorMotionAlgorithmManager[index].OpenDetectEnFlag = 1;
                }
            }
        }
    }
}

Std_ReturnType SwivelingMotorMotionInterfaceInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_MotorDrv_Dev *MotorDevTmp = NULL;
    S_MotorMotionAlgorithmManager *MotorMotionAlgo = NULL;
    S_MotorDrvInitDataSrc MotorDrvInitDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;

    if (Get_pVehDBLType() == 1 || Get_pVehDBLType() == 2 || Get_pVehDBLType() == 5 || Get_pVehDBLType() == 6)
    {
        /*Swiveling Motor configed*/
        MotorDevTmp = GetMotorDrvByMotorTpye(E_MotorTpye_Swiveling);
        MotorMotionAlgo = GetMotionAlgoByMotorTpye(E_MotorTpye_Swiveling);
        if (MotorDevTmp == NULL || MotorMotionAlgo == NULL)
            return E_NOT_OK;

        /***************************Init Motor Motion Algorithm********************************/
        MotorMotionAlgo->MotorCurPosition = 0;
        MotorMotionAlgo->MotorTargetPosition = 0;
        MotorMotionAlgo->config_hold2run_timer_delay = Get_pSvlPreTime();
        MotorMotionAlgo->config_run2hold_timer_delay = Get_pSvlPostTime();
        MotorMotionAlgo->MotorAlgoEnableFlag = 1;
        MotorMotionAlgo->AccStepArray = Get_pSvlAccArray();
        MotorMotionAlgo->DecStepArray = Get_pSvlBrakeArray();
#if HCM_LEFT_SIDE
        MotorMotionAlgo->MotorPosDirPolarity = Get_LeLamp_pSvlPolSeq();
#elif HCM_RIGHT_SIDE
        MotorMotionAlgo->MotorPosDirPolarity = Get_RiLamp_pSvlPolSeq();
#endif
        if (MotorMotionAlgo->MotorPosDirPolarity == E_MotorPosDirPolarity_Default)
        {
            MotorMotionAlgo->MotorPosDirPolarity = E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR;
        }

        /******************************Init pluse Generater*************************************/
        /********************************Init Motor Drv*****************************************/
        MotorDrvInitDataSrc.MicroStepMode = Get_pSvlStepMode();
        MotorDrvInitDataSrc.stallthreshold = Get_pSvlstalldetethreshold();
        MotorDrvInitDataSrc.outputcurrent = Get_pSvlIholdNorm();

        if (MotorMotionAlgo->MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR)
        {
            MotorDrvInitDataSrc.DirPinState = E_MotorDirPinState_LOW;
            MotorMotionAlgo->MotorCurDirPinState = E_MotorDirPinState_LOW;
        }
        else
        {
            MotorDrvInitDataSrc.DirPinState = E_MotorDirPinState_HIGH;
            MotorMotionAlgo->MotorCurDirPinState = E_MotorDirPinState_HIGH;
        }

        MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
        MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevInit;
        MotorDrvDataPackets.datasrc = (void *)(&MotorDrvInitDataSrc);

        rtval |= MotorDevTmp->DeviceInit((void *)(&MotorDrvDataPackets));

        if (rtval == E_OK)
        {
            MotorMotionAlgo->MotorCurCurrent = Get_pLvlIholdNorm();
        }

        SwivelingingMotorDevDrvState = rtval;
    }
    return rtval;
}

Std_ReturnType LevelingMotorMotionInterfaceInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_MotorDrv_Dev *MotorDevTmp = NULL;
    S_MotorMotionAlgorithmManager *MotorMotionAlgo = NULL;
    S_MotorDrvInitDataSrc MotorDrvInitDataSrc;
    S_MotorDrvDataPackets MotorDrvDataPackets;

    if (Get_pVehLvLType() == 1 || Get_pVehLvLType() == 2)
    {
        /*Leveling Motor configed*/
        MotorDevTmp = GetMotorDrvByMotorTpye(E_MotorTpye_Leveling);
        MotorMotionAlgo = GetMotionAlgoByMotorTpye(E_MotorTpye_Leveling);
        if (MotorDevTmp == NULL || MotorMotionAlgo == NULL)
            return E_NOT_OK;

        /***************************Init Motor Motion Algorithm********************************/
        MotorMotionAlgo->MotorCurPosition = 0;
        MotorMotionAlgo->MotorTargetPosition = 0;
        MotorMotionAlgo->config_hold2run_timer_delay = Get_pLvlPreTime();
        MotorMotionAlgo->config_run2hold_timer_delay = Get_pLvlPostTime();
        MotorMotionAlgo->MotorAlgoEnableFlag = 1;
        MotorMotionAlgo->AccStepArray = Get_pLvlAccArray();
        MotorMotionAlgo->DecStepArray = Get_pLvlBrakeArray();
#if HCM_LEFT_SIDE
        MotorMotionAlgo->MotorPosDirPolarity = Get_LeLamp_pLvlPolSeq();
#elif HCM_RIGHT_SIDE
        MotorMotionAlgo->MotorPosDirPolarity = Get_RiLamp_pLvlPolSeq();
#endif
        if (MotorMotionAlgo->MotorPosDirPolarity == E_MotorPosDirPolarity_Default)
        {
            MotorMotionAlgo->MotorPosDirPolarity = E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR;
        }

        /******************************Init pluse Generater*************************************/

        /********************************Init Motor Drv*****************************************/
        MotorDrvInitDataSrc.MicroStepMode = Get_pLvlStepMode();
        MotorDrvInitDataSrc.stallthreshold = Get_pLvlstalldetethreshold();
        MotorDrvInitDataSrc.outputcurrent = Get_pLvlIholdNorm();

        if (MotorMotionAlgo->MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR)
        {
            MotorDrvInitDataSrc.DirPinState = E_MotorDirPinState_LOW;
            MotorMotionAlgo->MotorCurDirPinState = E_MotorDirPinState_LOW;
        }
        else
        {
            MotorDrvInitDataSrc.DirPinState = E_MotorDirPinState_HIGH;
            MotorMotionAlgo->MotorCurDirPinState = E_MotorDirPinState_HIGH;
        }

        MotorDrvDataPackets.Device_id = MotorDevTmp->Device_id;
        MotorDrvDataPackets.MotorDrvDataType = E_MotorDrvDataType_DevInit;
        MotorDrvDataPackets.datasrc = (void *)(&MotorDrvInitDataSrc);

        rtval |= MotorDevTmp->DeviceInit((void *)(&MotorDrvDataPackets));

        if (rtval == E_OK)
        {
            MotorMotionAlgo->MotorCurCurrent = Get_pLvlIholdNorm();
        }

        LevelingMotorDevDrvState = rtval;
    }

    return rtval;
}
