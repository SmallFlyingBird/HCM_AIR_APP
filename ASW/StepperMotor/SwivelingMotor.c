/*
 * SwivelingMotor.c
 *
 *  Created on: 2024��2��18��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "SwivelingMotor.h"
#include "HallSensor.h"
#include "AswInterfaceManager.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_SwivelingMotorInfo gs_SwivelingMotorInfo;

static S_HallSensorInfo gs_HallSensorInfo = {
    .HallSensorPolarity = E_HallSensorPolarity_Unkown,
    .HallMotorFDMoveDir = E_HallMotorFDMoveDir_Unkown,
    .HallMotorPosMoveDir = E_HallMotorPosMoveDir_Unkown,
};

/*
 *If the project equipped with HallSensor and The HallSensor is error,this flag will be setted to 1.
 *If this flag is set to 1,the motor referncer run will use SwivelingMotorReferenceRun_WithoutHall() by using parameter->pSvlRefDirection.
 */
static uint8_t gu_HallSensorErrorFlag = 0;
static uint8_t g_IoCtrFlag = 0;
static uint8_t g_RoutineCtrFlag = 0;
static sint16_t RoutineTargetPos;

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
/*
 * 已知条件：1.默认位置(gs_LevelingMotorInfo.DefaultPos)
 *			2.默认角度(gs_LevelingMotorInfo.DefaultAngle)
 *          3.弧度与步数的关系(gs_LevelingMotorInfo.HsPerRad)
 *
 *  		目标位置 =  gs_LevelingMotorInfo.DefaultPos + (目标角度-gs_LevelingMotorInfo.DefaultAngle) 	0.01745 * gs_LevelingMotorInfo.HsPerRad
 */
static Std_ReturnType ConvertAngleToMotorPos(double TargetAngle, sint16_t *TargetPos)
{
#if HCM_LEFT_SIDE
    if (Get_LeLamp_SvlLePosdeg() < Get_LeLamp_SvlRiPosdeg())
    {
        if ((TargetAngle < Get_LeLamp_SvlLePosdeg()) || (TargetAngle > Get_LeLamp_SvlRiPosdeg()))
        {
            return E_NOT_OK;
        }
    }
    else
    {
        if ((TargetAngle > Get_LeLamp_SvlLePosdeg()) || (TargetAngle < Get_LeLamp_SvlRiPosdeg()))
        {
            return E_NOT_OK;
        }
    }
#elif HCM_RIGHT_SIDE
    if (Get_RiLamp_SvlLePosdeg() < Get_RiLamp_SvlRiPosdeg())
    {
        if ((TargetAngle < Get_RiLamp_SvlLePosdeg()) || (TargetAngle > Get_RiLamp_SvlRiPosdeg()))
        {
            return E_NOT_OK;
        }
    }
    else
    {
        if ((TargetAngle > Get_RiLamp_SvlLePosdeg()) || (TargetAngle < Get_RiLamp_SvlRiPosdeg()))
        {
            return E_NOT_OK;
        }
    }
#endif
    *TargetPos = gs_SwivelingMotorInfo.DefaultPos + (TargetAngle - gs_SwivelingMotorInfo.DefaultAngle) * 0.01745 * gs_SwivelingMotorInfo.HsPerRad;
    return E_OK;
}

static Std_ReturnType SwivelingMotorAlgoInit(void)
{
    Std_ReturnType rtval = E_OK;
    uint8 Ratio;
    /*The paramter table's unit is Half Step*/
    if (gs_SwivelingMotorInfo.SwivelingMotorMicroStepMode >= MotorMicroStepMode_2)
    {
        Ratio = gs_SwivelingMotorInfo.SwivelingMotorMicroStepMode / MotorMicroStepMode_2;

#if HCM_LEFT_SIDE
        gs_SwivelingMotorInfo.LeftBlockPos = Get_LeLamp_SvlLeftBlockPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightBlockPos = Get_LeLamp_SvlRightBlockPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.LeftLogicPos = Get_LeLamp_SvlLeftLogicPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightLogicPos = Get_LeLamp_SvlRightLogicPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.DefaultPos = Get_pSvlDfltPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.AdditionalStep = Get_pSvlCorStepsNum() * Ratio;
#elif HCM_RIGHT_SIDE
        gs_SwivelingMotorInfo.LeftBlockPos = Get_RiLamp_SvlLeftBlockPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightBlockPos = Get_RiLamp_SvlRightBlockPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.LeftLogicPos = Get_RiLamp_SvlLeftLogicPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightLogicPos = Get_RiLamp_SvlRightLogicPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.DefaultPos = Get_pSvlDfltPos() * ((sint16)Ratio);
        gs_SwivelingMotorInfo.AdditionalStep = Get_pSvlCorStepsNum() * Ratio;
#endif
        gs_SwivelingMotorInfo.HsPerRad = Get_pSvlHsPerRad() * Ratio;
    }
    else
    {
        /*Full Step*/
        Ratio = MotorMicroStepMode_2;
#if HCM_LEFT_SIDE
        gs_SwivelingMotorInfo.LeftBlockPos = Get_LeLamp_SvlLeftBlockPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightBlockPos = Get_LeLamp_SvlRightBlockPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.LeftLogicPos = Get_LeLamp_SvlLeftLogicPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightLogicPos = Get_LeLamp_SvlRightLogicPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.DefaultPos = Get_pSvlDfltPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.AdditionalStep = Get_pSvlCorStepsNum() / Ratio;
#elif HCM_RIGHT_SIDE
        gs_SwivelingMotorInfo.LeftBlockPos = Get_RiLamp_SvlLeftBlockPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightBlockPos = Get_RiLamp_SvlRightBlockPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.LeftLogicPos = Get_RiLamp_SvlLeftLogicPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.RightLogicPos = Get_RiLamp_SvlRightLogicPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.DefaultPos = Get_pSvlDfltPos() / ((sint16)Ratio);
        gs_SwivelingMotorInfo.AdditionalStep = Get_pSvlCorStepsNum() / Ratio;
#endif
        gs_SwivelingMotorInfo.HsPerRad = Get_pSvlHsPerRad() / Ratio;
    }
    gs_SwivelingMotorInfo.StallErrorCnt = 0;
    gs_SwivelingMotorInfo.TargetPos = 0;
    gs_SwivelingMotorInfo.CurrentMotorPos = 0;

    return rtval;
}
static Std_ReturnType CheckSvlReferenceRunPreCondition(void)
{
#if (EMC_TEST_ENABLE == 1)
    return E_OK;
#endif  /*(EMC_TEST_ENABLE == 1)*/

    Std_ReturnType rtval = E_NOT_OK;

    static E_UsageModeSts se_SvlUsageModeLast = E_UsageModeSts_Abdnd;
    static E_UsageModeSts se_SvlUsageModeCurr = E_UsageModeSts_Abdnd;
    uint32_t SignalValue;

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& SignalValue);
    se_SvlUsageModeLast = se_SvlUsageModeCurr;
    se_SvlUsageModeCurr = (E_UsageModeSts)SignalValue;

    double VehSpdLgtA = 0.0;

    Interface_GetSignal_VehSpdLgtA(& VehSpdLgtA);
    if(VehSpdLgtA * 3.6 <= 4.0)
    {
        if( (se_SvlUsageModeLast == E_UsageModeSts_Abdnd || se_SvlUsageModeLast == E_UsageModeSts_InActv || se_SvlUsageModeLast == E_UsageModeSts_Cnvinc) &&
            (se_SvlUsageModeCurr == E_UsageModeSts_Actv || se_SvlUsageModeCurr == E_UsageModeSts_Drvg) )
        {
            rtval = E_OK;
        }
    }
    return rtval;
}

static Std_ReturnType CaculateSvlMotorParameterByTemp(E_SwivelingMotorState SwivelingMotorState, uint16_t *AccDecStepNum, uint16_t *holdcurrent, uint16_t *runcurrent)
{
    Std_ReturnType rtval = E_OK;
    E_MotorTemperatureInfo MotorTemperatureInfo;

    rtval |= Interface_GetMotorTemperatureInfo(E_MotorTpye_Swiveling, &MotorTemperatureInfo);

    if (rtval != E_OK)
        return rtval;

    if (MotorTemperatureInfo == E_MotorMotorTemp_LowTempWarning)
    {
        *AccDecStepNum = Get_pSvlVmaxLowTemp();
        *holdcurrent = Get_pSvlIholdLowTemp();
        *runcurrent = Get_pSvlIrunLowTemp();
    }
    else if (MotorTemperatureInfo == E_MotorMotorTemp_HighTempShutDown)
    {
        return E_NOT_OK;
    }
    else
    {
        /*Normal Temperature*/
        if (SwivelingMotorState == E_SwivelingMotorState_ReferenceRunWithOutHall ||
            SwivelingMotorState == E_SwivelingMotorState_ReferenceRunWithHall)
        {
            *AccDecStepNum = Get_pSvlVmaxRef();
            *runcurrent = Get_pSvlIrunRef();
        }
        else if (SwivelingMotorState == E_SwivelingMotorState_NormalRun)
        {
            *AccDecStepNum = Get_pSvlVmaxNorm();
            *runcurrent = Get_pSvlIrunNorm();
        }
        else
        {
            *AccDecStepNum = Get_pSvlVmaxNorm();
            *runcurrent = Get_pSvlIrunNorm();
        }
        *holdcurrent = Get_pSvlIholdNorm();
    }
    return rtval;
}

/*
 *   Caculate the Motor target position of first swing.The motor move distance should be |RightBlockPos-LeftBlockPos|
 *	 The target postition will store in  gs_SwivelingMotorInfo.TargetPos
 */

static Std_ReturnType CaculateFirstHallSensorSwingPos(E_HallSensorFeedBackType HallSensorFeedBackType)
{
    Std_ReturnType reval = E_OK;
    E_HallSensorFeedBackType HallSensorActualLevel;

#if HCM_LEFT_SIDE
    if (Get_LeLamp_pSvlSensorInv() == 1)
#elif HCM_RIGHT_SIDE
    if (Get_RiLamp_pSvlSensorInv() == 1)
#endif
    {
        if (HallSensorFeedBackType == E_HallSensorFeedBackType_LowLevel)
            HallSensorActualLevel = E_HallSensorFeedBackType_HighLevel;
        else
            HallSensorActualLevel = E_HallSensorFeedBackType_LowLevel;
    }

    if (HallSensorActualLevel == E_HallSensorFeedBackType_LowLevel)
    {
        /*The motor should goto High level,so set motor pin dir to high level*/

        if (gs_HallSensorInfo.HallSensorPolarity == E_HallSensorPolarity_MotorDirPinLow_AS_LowLevel)
        {
            reval |= Interface_ResetMotorDirPinPolariy(E_MotorTpye_Swiveling, E_MotorDirPinState_HIGH);
        }
        else
        {
            reval |= Interface_ResetMotorDirPinPolariy(E_MotorTpye_Swiveling, E_MotorDirPinState_LOW);
        }
    }
    else
    {
        /*The motor should goto low level,so set motor pin dir to low level*/

        if (gs_HallSensorInfo.HallSensorPolarity == E_HallSensorPolarity_MotorDirPinLow_AS_LowLevel)
        {
            reval |= Interface_ResetMotorDirPinPolariy(E_MotorTpye_Swiveling, E_MotorDirPinState_LOW);
        }
        else
        {
            reval |= Interface_ResetMotorDirPinPolariy(E_MotorTpye_Swiveling, E_MotorDirPinState_HIGH);
        }
    }

    /*The Hall Sensor's 0 deg must be between (0 - gs_SwivelingMotorInfo.TargetPos)*/
    gs_SwivelingMotorInfo.TargetPos = (gs_SwivelingMotorInfo.RightBlockPos - gs_SwivelingMotorInfo.LeftBlockPos);

    return reval;
}

static void SvlRefRun_HallSensorSwing_Func(E_HallSensorFeedBackType HallSensorFeedBackType)
{
    uint8_t HallPass0DegFlag = 0;
    sint16 MotorCurPos;

    if (((HallSensorFeedBackType == E_HallSensorFeedBackType_LowLevel) && (gs_HallSensorInfo.HallMotorFDMoveDir == E_HallMotorFDMoveDir_HighLevel2LowLevel)) ||
        ((HallSensorFeedBackType == E_HallSensorFeedBackType_HighLevel) && (gs_HallSensorInfo.HallMotorFDMoveDir == E_HallMotorFDMoveDir_LowLevel2HighLevel)))
    {
        HallPass0DegFlag = 1;
    }

    if (HallPass0DegFlag)
    {
        /*
         * The hall motor has pass the 0 deg.
         * Record the current motor position ,then stop motor.
         */
        if (gs_HallSensorInfo.HallMotorPosMoveDir == E_HallMotorPosMoveDir_LowPosl2HighPos)
        {
            if (Interface_GetMotorCurPosition(E_MotorTpye_Swiveling, &MotorCurPos) == E_OK)
            {
                /*Rcord current motor position*/
                gs_HallSensorInfo.HallSwingHighPos = MotorCurPos;
                if (Interface_StopMotor(E_MotorTpye_Swiveling) == E_OK)
                {
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_WaitHallMotorStop;
                }
            }
        }
        else if (gs_HallSensorInfo.HallMotorPosMoveDir == E_HallMotorPosMoveDir_HighPosl2LowPos)
        {
            if (Interface_GetMotorCurPosition(E_MotorTpye_Swiveling, &MotorCurPos) == E_OK)
            {
                /*Rcord current motor position*/
                gs_HallSensorInfo.HallSwingLowPos = MotorCurPos;
                if (Interface_StopMotor(E_MotorTpye_Swiveling) == E_OK)
                {
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_WaitHallMotorStop;
                }
            }
        }
    }
    else
    {
        /*
         * The hall motor has not pass the 0 deg.
         * 1.Record the current motor position.
         * 2.If motor is stoped, it means the Hall sensor feedback signal is const HighLevel or LowLevel
         */
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase)
        {
            if (HallSensorFeedBackType == E_HallSensorFeedBackType_LowLevel)
                Interface_SetDtcHallSensorError(E_HallSensorErrorType_ConstantLow, 1);
            else
                Interface_SetDtcHallSensorError(E_HallSensorErrorType_ConstantHigh, 1);

            gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorError;
        }
        else
        {
            /*Motor is move ,Record the current motor position*/
            if (Interface_GetMotorCurPosition(E_MotorTpye_Swiveling, &MotorCurPos) == E_OK)
            {
                if (gs_HallSensorInfo.HallMotorPosMoveDir == E_HallMotorPosMoveDir_HighPosl2LowPos)
                {
                    gs_HallSensorInfo.HallSwingHighPos = MotorCurPos;
                }
                else
                {
                    gs_HallSensorInfo.HallSwingLowPos = MotorCurPos;
                }
            }
        }
    }
}

Std_ReturnType SwivelingMotorReferenceRun_WithHall(void)
{
    Std_ReturnType rtval = E_OK;
    uint16_t AccDecStepNum = 0;
    uint16_t holdcurrent, runcurrent;
    E_HallSensorFeedBackType HallSensorFeedBackType;
    static uint8_t refrun_swings_number = 0;
    sint16 hallpos;
    E_MotorPosDirPolarity MotorPosDirPolarity;
#if HALLFEEDBACK_WAIT_NUM
    static uint8_t HallFeedBackWaitNum = 0;
#endif
    switch (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun)
    {
    case E_SubMode_SvlRefRun_ParamInit:
        rtval |= CaculateSvlMotorParameterByTemp(E_SwivelingMotorState_ReferenceRunWithOutHall, &AccDecStepNum, &holdcurrent, &runcurrent);

        rtval |= Interface_SetMotorMotionParameter(E_MotorTpye_Swiveling, AccDecStepNum, runcurrent, holdcurrent);
#if HCM_LEFT_SIDE
        gs_HallSensorInfo.HallSensorPolarity = (E_HallSensorPolarity)Get_LeLamp_pSvlSensorEdge();
#elif HCM_RIGHT_SIDE
        gs_HallSensorInfo.HallSensorPolarity = (E_HallSensorPolarity)Get_RiLamp_pSvlSensorEdge();
#endif
        if (rtval == E_NOT_OK)
            return E_NOT_OK;
        /*Set current motor position as 0 position*/
        if (Interface_ResetMotorPosition(E_MotorTpye_Swiveling, 0) == E_PosSet_OK)
        {
            if (HallSensorInf_GetHallSensorFeedBack(&HallSensorFeedBackType) == E_NOT_OK)
            {
                /*HALL has not Conversion complete*/
#if HALLFEEDBACK_WAIT_NUM
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_WaitHallConvertComplete;
                HallFeedBackWaitNum = 0;
#else
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorError;
#endif
            }
            else
            {
                if (HallSensorFeedBackType == E_HallSensorFeedBackType_UnknowLevel ||
                    HallSensorFeedBackType == E_HallSensorFeedBackType_Short2Gnd ||
                    HallSensorFeedBackType == E_HallSensorFeedBackType_Open)
                {
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorError;
                    Interface_SetDtcHallSensorError(E_HallSensorErrorType_ElectricalFailure, 1);
                }
                else
                {
                    refrun_swings_number = 0;
                    /*This is the first swing*/
                    if (CaculateFirstHallSensorSwingPos(HallSensorFeedBackType) == E_OK)
                    {
                        if (HallSensorFeedBackType == E_HallSensorFeedBackType_LowLevel)
                        {
                            gs_HallSensorInfo.HallMotorFDMoveDir = E_HallMotorFDMoveDir_LowLevel2HighLevel;
                            gs_HallSensorInfo.HallMotorPosMoveDir = E_HallMotorPosMoveDir_LowPosl2HighPos;
                        }
                        else
                        {
                            gs_HallSensorInfo.HallMotorFDMoveDir = E_HallMotorFDMoveDir_HighLevel2LowLevel;
                            gs_HallSensorInfo.HallMotorPosMoveDir = E_HallMotorPosMoveDir_LowPosl2HighPos;
                        }

                        if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_OK)
                        {
                            gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorSwing;
                            gs_HallSensorInfo.HallSwingLowPos = 0;
                            gs_HallSensorInfo.HallSwingHighPos = gs_SwivelingMotorInfo.TargetPos;
                        }
                    }
                    Interface_SetDtcHallSensorError(E_HallSensorErrorType_ElectricalFailure, 0);
                }
            }
        }
        break;
    case E_SubMode_SvlRefRun_WaitHallConvertComplete:
#if HALLFEEDBACK_WAIT_NUM
        if (HallSensorInf_GetHallSensorFeedBack(&HallSensorFeedBackType) == E_NOT_OK)
        {
            HallFeedBackWaitNum++;
            if (HallFeedBackWaitNum >= HALLFEEDBACK_WAIT_NUM)
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorError;
        }
        else
        {
            if (HallSensorFeedBackType == E_HallSensorFeedBackType_UnknowLevel ||
                HallSensorFeedBackType == E_HallSensorFeedBackType_Short2Gnd ||
                HallSensorFeedBackType == E_HallSensorFeedBackType_Open)
            {
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorError;
                Interface_SetDtcHallSensorError(E_HallSensorErrorType_ElectricalFailure, 1);
            }
            else
            {
                refrun_swings_number = 0;
                /*This is the first swing*/
                if (CaculateFirstHallSensorSwingPos(HallSensorFeedBackType) == E_OK)
                {
                    if (HallSensorFeedBackType == E_HallSensorFeedBackType_LowLevel)
                    {
                        gs_HallSensorInfo.HallMotorFDMoveDir = E_HallMotorFDMoveDir_LowLevel2HighLevel;
                        gs_HallSensorInfo.HallMotorPosMoveDir = E_HallMotorPosMoveDir_LowPosl2HighPos;
                    }
                    else
                    {
                        gs_HallSensorInfo.HallMotorFDMoveDir = E_HallMotorFDMoveDir_HighLevel2LowLevel;
                        gs_HallSensorInfo.HallMotorPosMoveDir = E_HallMotorPosMoveDir_LowPosl2HighPos;
                    }
                    if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_OK)
                    {
                        gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorSwing;
                        gs_HallSensorInfo.HallSwingLowPos = 0;
                        gs_HallSensorInfo.HallSwingHighPos = gs_SwivelingMotorInfo.TargetPos;
                    }
                }
                Interface_SetDtcHallSensorError(E_HallSensorErrorType_ElectricalFailure, 0);
            }
        }
#endif
        break;

    case E_SubMode_SvlRefRun_HallSensorSwing:
        if (HallSensorInf_GetHallSensorFeedBack(&HallSensorFeedBackType) == E_OK)
        {
            SvlRefRun_HallSensorSwing_Func(HallSensorFeedBackType);
        }
        else
        {
            gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorError;
        }
        break;

    case E_SubMode_SvlRefRun_WaitHallMotorStop:
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase)
        {
            /*The motot stop*/
            refrun_swings_number++;
            if (refrun_swings_number >= HALLSENSOR_REFRUN_SWING_NUM)
            {
                /*
                 *HallSensor Motor reference run conplete.
                 *1.Reset this position as SvlSensorPos position
                 *2.Reset motor dir
                 *3.goto 0 deg
                 */
#if HCM_LEFT_SIDE
                hallpos = Get_LeLamp_pSvlSensorPos();
#elif HCM_RIGHT_SIDE
                hallpos = Get_RiLamp_pSvlSensorPos();
#endif
                /*1*/
                Interface_ResetMotorPosition(E_MotorTpye_Swiveling, hallpos);

#if HCM_LEFT_SIDE
                MotorPosDirPolarity = Get_LeLamp_pLvlPolSeq();
#elif HCM_RIGHT_SIDE
                MotorPosDirPolarity = Get_RiLamp_pLvlPolSeq();
#endif
                /*2*/
                if (MotorPosDirPolarity == E_MotorPosDirPolarity_PINLOW_AS_POSTIVE_DIR)
                {
                    Interface_ResetMotorDirPinPolariy(E_MotorTpye_Swiveling, E_MotorDirPinState_LOW);
                }
                else
                {
                    Interface_ResetMotorDirPinPolariy(E_MotorTpye_Swiveling, E_MotorDirPinState_HIGH);
                }

                /*3*/
                /*In most cases ,the default degree is 0 degree.If not ,should caculate the 0 ° position*/
                if (Get_SvlDfltPosdeg() == 5000)
                {
                    gs_SwivelingMotorInfo.TargetPos = gs_SwivelingMotorInfo.DefaultPos;
                    if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_OK)
                    {
                        gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_WaitLeave;
                    }
                }
                else
                {
                    /*todo*/
                    gs_SwivelingMotorInfo.TargetPos = gs_SwivelingMotorInfo.DefaultPos;
                    if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_OK)
                    {
                        gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_WaitLeave;
                    }
                }
            }
            else
            {
                /*contiue swing*/

                /*Inverse gs_HallSensorInfo.HallMotorFDMoveDir*/
                if (gs_HallSensorInfo.HallMotorFDMoveDir == E_HallMotorFDMoveDir_LowLevel2HighLevel)
                {
                    gs_HallSensorInfo.HallMotorFDMoveDir = E_HallMotorFDMoveDir_HighLevel2LowLevel;
                }
                else
                {
                    gs_HallSensorInfo.HallMotorFDMoveDir = E_HallMotorFDMoveDir_LowLevel2HighLevel;
                }

                /*
                 * Inverse gs_HallSensorInfo.HallMotorPosMoveDir
                 * Set motor position
                 */
                if (gs_HallSensorInfo.HallMotorPosMoveDir == E_HallMotorPosMoveDir_LowPosl2HighPos)
                {
                    gs_SwivelingMotorInfo.TargetPos = gs_HallSensorInfo.HallSwingLowPos;
                    if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_OK)
                    {
                        gs_HallSensorInfo.HallMotorPosMoveDir = E_HallMotorPosMoveDir_HighPosl2LowPos;
                        gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorSwing;
                    }
                }
                else if (gs_HallSensorInfo.HallMotorPosMoveDir == E_HallMotorPosMoveDir_HighPosl2LowPos)
                {
                    gs_SwivelingMotorInfo.TargetPos = gs_HallSensorInfo.HallSwingHighPos;
                    if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_OK)
                    {
                        gs_HallSensorInfo.HallMotorPosMoveDir = E_HallMotorPosMoveDir_LowPosl2HighPos;
                        gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_HallSensorSwing;
                    }
                }
            }
        }
        break;

    case E_SubMode_SvlRefRun_HallSensorError:
        /**If this flag is set to 1,the motor referncer run whill use SwivelingMotorReferenceRun_WithoutHall() by use parameter->pSvlRefDirection.*/
        gu_HallSensorErrorFlag = 1;
        gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_ParamInit;
        gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_ReferenceRunWithOutHall;
        break;

    case E_SubMode_SvlRefRun_WaitLeave:
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase)
        {
            gs_SwivelingMotorInfo.CurrentMotorPos = gs_SwivelingMotorInfo.DefaultPos;

            gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag = E_SvlReferenceRun_PerformCompltedOK;
        }
        break;
    }

    return rtval;
}

Std_ReturnType SwivelingMotorReferenceRun_WithoutHall(void)
{
    Std_ReturnType rtval = E_OK;
    uint16_t AccDecStepNum = 0;
    uint16_t holdcurrent, runcurrent;
    E_MotorMotionState MotorMotionState;
    U_DevErrorTypt DevErrorTypt;
    U_StepMotorAndHall_Error StepMotorAndHallDTCError;
    switch (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun)
    {
    case E_SubMode_SvlRefRun_ParamInit:
        rtval |= CaculateSvlMotorParameterByTemp(E_SwivelingMotorState_ReferenceRunWithOutHall, &AccDecStepNum, &holdcurrent, &runcurrent);

        rtval |= Interface_SetMotorMotionParameter(E_MotorTpye_Swiveling, AccDecStepNum, runcurrent, holdcurrent);

        if (rtval == E_NOT_OK)
            return E_NOT_OK;
        /*Set cur motor position as 0 position*/
        if (Interface_ResetMotorPosition(E_MotorTpye_Swiveling, 0) == E_PosSet_OK)
        {
            gs_SwivelingMotorInfo.CurrentMotorPos = 0;
            gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag = E_SvlReferenceRun_Performing;
#if HCM_LEFT_SIDE
            if (gu_HallSensorErrorFlag == 1)
            {
                if (Get_LeLamp_pSvlRefDirection() == 1)
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToLeftBlockPos;
                else
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToRightBlockPos;
            }
            else
            {
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToLeftBlockPos;
            }
#elif HCM_RIGHT_SIDE
            if (gu_HallSensorErrorFlag == 1)
            {
                if (Get_RiLamp_pSvlRefDirection() == 1)
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToLeftBlockPos;
                else
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToRightBlockPos;
            }
            else
            {
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToLeftBlockPos;
            }
#endif
        }
        break;
    case E_SubMode_SvlRefRun_GoToLeftBlockPos:
    case E_SubMode_SvlRefRun_GoToRightBlockPos:
    case E_SubMode_SvlRefRun_GoToAdditionPos:
    case E_SubMode_SvlRefRun_GoToDefaultPos:
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) != E_MotorMotionState_Stop_Phase)
        {
            Interface_StopMotor(E_MotorTpye_Swiveling);
            return E_OK;
        }

        rtval |= Interface_DisableMotorStallDetect(E_MotorTpye_Swiveling);

        /********************************Caculate TargetPosition********************************/

        if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToLeftBlockPos)
        {
            /*The motor current position is 0*/
            Interface_ResetMotorPosition(E_MotorTpye_Swiveling, 0);

            /*Right position is positive position,so TargetPos will positive position*/
            gs_SwivelingMotorInfo.TargetPos = -(gs_SwivelingMotorInfo.RightBlockPos - gs_SwivelingMotorInfo.LeftBlockPos);
        }
        else if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToRightBlockPos)
        {
            /*The motor current position is 0*/
            Interface_ResetMotorPosition(E_MotorTpye_Swiveling, 0);

            gs_SwivelingMotorInfo.TargetPos = gs_SwivelingMotorInfo.RightBlockPos - gs_SwivelingMotorInfo.LeftBlockPos;
        }
        else if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToAdditionPos)
        {
#if HCM_LEFT_SIDE
            Interface_ResetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.LeftBlockPos);
#elif HCM_RIGHT_SIDE
            Interface_ResetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.RightBlockPos);
#endif

            rtval |= CaculateSvlMotorParameterByTemp(E_SwivelingMotorState_ReferenceRunWithOutHall, &AccDecStepNum, &holdcurrent, &runcurrent);
            if (rtval == E_NOT_OK)
                return E_NOT_OK;

            Interface_SetMotorMotionParameter(E_MotorTpye_Swiveling, 1, runcurrent, holdcurrent);
#if HCM_LEFT_SIDE
            gs_SwivelingMotorInfo.TargetPos = gs_SwivelingMotorInfo.LeftBlockPos - gs_SwivelingMotorInfo.AdditionalStep;
#elif HCM_RIGHT_SIDE
            gs_SwivelingMotorInfo.TargetPos = gs_SwivelingMotorInfo.RightBlockPos + gs_SwivelingMotorInfo.AdditionalStep;
#endif
        }
        else if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToDefaultPos)
        {
#if HCM_LEFT_SIDE
            Interface_ResetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.LeftBlockPos);
            gs_SwivelingMotorInfo.CurrentMotorPos = gs_SwivelingMotorInfo.LeftBlockPos;
#elif HCM_RIGHT_SIDE
            Interface_ResetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.RightBlockPos);
            gs_SwivelingMotorInfo.CurrentMotorPos = gs_SwivelingMotorInfo.RightBlockPos;
#endif
            rtval |= CaculateSvlMotorParameterByTemp(E_SwivelingMotorState_NormalRun, &AccDecStepNum, &holdcurrent, &runcurrent);
            if (rtval == E_NOT_OK)
                return E_NOT_OK;

            /*Set motor Acc and Dec param*/
            Interface_SetMotorMotionParameter(E_MotorTpye_Swiveling, AccDecStepNum, runcurrent, holdcurrent);

            gs_SwivelingMotorInfo.TargetPos = gs_SwivelingMotorInfo.DefaultPos;
        }

        if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.TargetPos) == E_PosSet_OK)
        {
            if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToLeftBlockPos)
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_FindLeftStallPos;
            else if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToRightBlockPos)
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_FindRightStallPos;
            else if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToAdditionPos)
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_FindAdditionPos;
            else if (gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun == E_SubMode_SvlRefRun_GoToDefaultPos)
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_WaitLeave;
        }
        break;
    case E_SubMode_SvlRefRun_FindAdditionPos:
        MotorMotionState = Interface_GetMotorMotionState(E_MotorTpye_Swiveling);
        if (MotorMotionState == E_MotorMotionState_Stop_Phase)
        {
            gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToDefaultPos;
        }
        break;
    case E_SubMode_SvlRefRun_FindLeftStallPos:
    case E_SubMode_SvlRefRun_FindRightStallPos:
        MotorMotionState = Interface_GetMotorMotionState(E_MotorTpye_Swiveling);
        if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase ||
            MotorMotionState == E_MotorMotionState_Run_Accelerate_Phase ||
            MotorMotionState == E_MotorMotionState_Run_Decelerate_Phase)
        {
#if (SVL_MOTOR_REFERENCE_USE_STALL_DET == 1)
            if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase)
            {
                /*电机处于最大速度，开启堵转检测*/
                rtval |= Interface_EnableMotorStallDetect(E_MotorTpye_Swiveling);
            }
            else
            {
                /*电机处于加减速阶段，关闭堵转检测*/
                Interface_DisableMotorStallDetect(E_MotorTpye_Swiveling);
            }
#endif
            /*clear fault*/
            DevErrorTypt.DevError = 0;
            rtval |= Interface_GetMotorDiagnoseInfo(E_MotorTpye_Swiveling, &DevErrorTypt);

            if (rtval == E_OK)
            {
                if (DevErrorTypt.bits.ComError == 1)
                {
                    gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
                    rtval = E_NOT_OK;
                }
                else
                {
                    gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, DEC_LIMIT_0);
                }

                /*检测电机开路*/
                if (rtval == E_OK)
                {
                    if (DevErrorTypt.bits.DevOpenLoad == 1)
                    {
                        rtval = E_NOT_OK;
                        gs_SwivelingMotorInfo.OpenErrorCnt = CNT_INC(gs_SwivelingMotorInfo.OpenErrorCnt, STEP_1, CNT_LIMIT_5);
                        if (gs_SwivelingMotorInfo.OpenErrorCnt >= CNT_LIMIT_5)
                            Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_OpenLoad, 1);
                    }
                    else
                    {
                        gs_SwivelingMotorInfo.OpenErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.OpenErrorCnt, STEP_1, DEC_LIMIT_0);
                        if (gs_SwivelingMotorInfo.OpenErrorCnt <= DEC_LIMIT_0)
                            Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_OpenLoad, 0);
                    }
                }

                StepMotorAndHallDTCError = Interface_GetStepMotorAndHallErrorState(E_ErrorType_ErrorRealTimeState);
                if ((StepMotorAndHallDTCError.bits.SwivelMotor_OpenLoad == 1) || (StepMotorAndHallDTCError.bits.SwivelMotor_InterError == 1))
                {
                    /*电机开路或者和电机驱动芯片通信错误*/
                    Interface_StopMotor(E_MotorTpye_Swiveling);
                    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_Error;
                }
                if (rtval == E_OK)
                {
                    if (DevErrorTypt.bits.Stall == 1)
                    {
                        gs_SwivelingMotorInfo.StallErrorCnt = CNT_INC(gs_SwivelingMotorInfo.StallErrorCnt, STEP_1, SVL_REFERENCE_RUN_STALL_DEBOUNCE);
                        if (gs_SwivelingMotorInfo.StallErrorCnt >= SVL_REFERENCE_RUN_STALL_DEBOUNCE)
                        {
                            gs_SwivelingMotorInfo.StallErrorCnt = 0;
                            gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToAdditionPos;
                        }
                    }
                }
            }
        }
        else if (MotorMotionState == E_MotorMotionState_Stop_Phase)
        {
            gs_SwivelingMotorInfo.StallErrorCnt = 0;
            gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_GoToAdditionPos;
        }
        break;

    case E_SubMode_SvlRefRun_WaitLeave:
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase)
        {
            gs_SwivelingMotorInfo.CurrentMotorPos = gs_SwivelingMotorInfo.DefaultPos;

            gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag = E_SvlReferenceRun_PerformCompltedOK;
        }
        break;
    case E_SubMode_SvlRefRun_Error:
        gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag = E_SvlReferenceRun_PerformError;
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase)
        {
            Interface_SetMotorCurrent(E_MotorTpye_Swiveling, 0);
        }
        break;
    }

    return rtval;
}

/*
 * 已知条件：1.默认位置(gs_SwivelingMotorInfo.DefaultPos)
 *			2.默认角度(gs_SwivelingMotorInfo.DefaultAngle)
 *          3.弧度与步数的关系(gs_SwivelingMotorInfo.HsPerRad)
 *
 *  		目标位置 = gs_SwivelingMotorInfo.DefaultPos + (目标角度-gs_SwivelingMotorInfo.DefaultAngle) 	0.01745 * gs_SwivelingMotorInfo.HsPerRad
 *      ->  目标角度 =(目标位置-gs_SwivelingMotorInfo.DefaultPos)/(0.01745 * gs_SwivelingMotorInfo.HsPerRad)
 *

 */
static Std_ReturnType ConvertMotorPosToAngle(sint16_t MotorPos, double *TargetAngle)
{
    *TargetAngle = ((double)(MotorPos - gs_SwivelingMotorInfo.DefaultPos)) / (0.01745 * (double)gs_SwivelingMotorInfo.HsPerRad);
    return E_OK;
}

static void SwivelingMotorDiagInNormalRun(void)
{
    Std_ReturnType rtval = E_OK;
    U_DevErrorTypt DevErrorTypt;
    E_MotorMotionState MotorMotionState;

    MotorMotionState = Interface_GetMotorMotionState(E_MotorTpye_Swiveling);

    if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase ||
        MotorMotionState == E_MotorMotionState_Run_Accelerate_Phase ||
        MotorMotionState == E_MotorMotionState_Run_Decelerate_Phase)
    {
#if (SVL_MOTOR_REFERENCE_USE_STALL_DET == 1)
        if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase)
        {
            /*使能堵转检测*/
            Interface_EnableMotorStallDetect(E_MotorTpye_Swiveling);
        }
        else
        {
            Interface_DisableMotorStallDetect(E_MotorTpye_Swiveling);
        }
#endif
        DevErrorTypt.DevError = 0;
        rtval |= Interface_GetMotorDiagnoseInfo(E_MotorTpye_Swiveling, &DevErrorTypt);

        if (rtval == E_OK)
        {
            /*Spi 通信错误检测*/
            if (DevErrorTypt.bits.ComError == 1)
            {
                rtval = E_NOT_OK;
                gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
            }
            else
            {
                gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, DEC_LIMIT_0);
            }
        }

        if (rtval == E_OK)
        {
            /*过温检测*/
            if (DevErrorTypt.bits.TempWarning == 1)
                gs_SwivelingMotorInfo.DrvTmWarningErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_SwivelingMotorInfo.DrvTmWarningErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, DEC_LIMIT_0);
            /*热保护检测*/
            if (DevErrorTypt.bits.ThermalShuTDown == 1)
                gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, DEC_LIMIT_0);
            /*欠压检测*/
            if (DevErrorTypt.bits.UV == 1)
                gs_SwivelingMotorInfo.DrvUVErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvUVErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_SwivelingMotorInfo.DrvUVErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvUVErrorCnt, STEP_1, DEC_LIMIT_0);

            /*开路检测*/
            if (DevErrorTypt.bits.DevOpenLoad == 1)
            {
                rtval = E_NOT_OK;
                gs_SwivelingMotorInfo.OpenErrorCnt = CNT_INC(gs_SwivelingMotorInfo.OpenErrorCnt, STEP_1, CNT_LIMIT_5);

                if (gs_SwivelingMotorInfo.OpenErrorCnt >= CNT_LIMIT_5)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_OpenLoad, 1);
            }
            else
            {
                gs_SwivelingMotorInfo.OpenErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.OpenErrorCnt, STEP_1, DEC_LIMIT_0);
                if (gs_SwivelingMotorInfo.OpenErrorCnt == DEC_LIMIT_0)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_OpenLoad, 0);
            }
        }

        if (rtval == E_OK)
        {
            /*堵转检测*/
            if (DevErrorTypt.bits.Stall == 1)
            {
                gs_SwivelingMotorInfo.StallErrorCnt = CNT_INC(gs_SwivelingMotorInfo.StallErrorCnt, STEP_1, CNT_LIMIT_5);
                if (gs_SwivelingMotorInfo.StallErrorCnt >= CNT_LIMIT_5)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_OverLoad, 1);
            }
            else
            {
                gs_SwivelingMotorInfo.StallErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.StallErrorCnt, STEP_1, DEC_LIMIT_0);
                if (gs_SwivelingMotorInfo.StallErrorCnt == DEC_LIMIT_0)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_OverLoad, 0);
            }
        }
    }
    else
    {
        /*电机不处于最大速度，关闭检测*/
        Interface_DisableMotorStallDetect(E_MotorTpye_Swiveling);

        DevErrorTypt.DevError = 0;
        rtval |= Interface_GetMotorDiagnoseInfo(E_MotorTpye_Swiveling, &DevErrorTypt);

        if (rtval == E_OK)
        {
            /*Spi 通信错误检测*/
            if (DevErrorTypt.bits.ComError == 1)
            {
                rtval = E_NOT_OK;
                gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
            }
            else
            {
                gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, DEC_LIMIT_0);
            }
        }

        if (rtval == E_OK)
        {
            /*过温检测*/
            if (DevErrorTypt.bits.TempWarning == 1)
                gs_SwivelingMotorInfo.DrvTmWarningErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_SwivelingMotorInfo.DrvTmWarningErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, DEC_LIMIT_0);
            /*热保护检测*/
            if (DevErrorTypt.bits.ThermalShuTDown == 1)
                gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, DEC_LIMIT_0);
            /*欠压检测*/
            if (DevErrorTypt.bits.UV == 1)
                gs_SwivelingMotorInfo.DrvUVErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvUVErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_SwivelingMotorInfo.DrvUVErrorCnt = CNT_DEC(gs_SwivelingMotorInfo.DrvUVErrorCnt, STEP_1, DEC_LIMIT_0);
        }
    }

    if (gs_SwivelingMotorInfo.DrvComErrorCnt == CNT_LIMIT_5 || gs_SwivelingMotorInfo.DrvTmWarningErrorCnt == CNT_LIMIT_5 ||
        gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt == CNT_LIMIT_5 || gs_SwivelingMotorInfo.DrvUVErrorCnt == CNT_LIMIT_5)
    {
        Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_InterError, 1);
    }
    else if (gs_SwivelingMotorInfo.DrvComErrorCnt == DEC_LIMIT_0 && gs_SwivelingMotorInfo.DrvTmWarningErrorCnt == DEC_LIMIT_0 &&
             gs_SwivelingMotorInfo.DrvThermalShutDownErrorCnt == DEC_LIMIT_0 && gs_SwivelingMotorInfo.DrvUVErrorCnt == DEC_LIMIT_0)
    {
        Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_InterError, 0);
    }
}

static Std_ReturnType SwivelingMotorNormalRun(uint8_t timebase)
{
    SwivelingMotorDiagInNormalRun();
    return E_OK;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 获取Swiveling电机的工作模式 */
/* 返回值：0:正常模式； 1：UDS模式 */
uint8_t SwivelingMotor_GetSvlMotorRunMode(void)
{
    return (g_IoCtrFlag | g_RoutineCtrFlag);
}

/*获取Swiveling电机的初始化状态*/
E_SvlRefRunSts SwivelingMotor_GetSvlRefRunSts(void)
{
    E_SvlRefRunSts SvlRefRunSts = E_SvlRefRunSts_NoCond;

    switch (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag)
    {
        case E_SvlReferenceRun_NotPerform:
            SvlRefRunSts = E_SvlRefRunSts_NoCond;
            break;
        case E_SvlReferenceRun_Performing:
            SvlRefRunSts = E_SvlRefRunSts_During;
            break;
        case E_SvlReferenceRun_PerformCompltedOK:
            SvlRefRunSts = E_SvlRefRunSts_Done;
            break;
        case E_SvlReferenceRun_PerformError:
            SvlRefRunSts = E_SvlRefRunSts_Error;
    }
    return SvlRefRunSts;
}

/*
 *获得电机当前角度
 *返回值 E_NOT_OK：电机初始化未完成
 */
Std_ReturnType SwivelingMotor_GetSvlCurAngle(double *Angle)
{
    sint16_t MotorCurPos;

    if (gs_SwivelingMotorInfo.SwivelingMotorState != E_SwivelingMotorState_NormalRun)
        return E_NOT_OK;

    if (Interface_GetMotorCurPosition(E_MotorTpye_Swiveling, &MotorCurPos) == E_OK)
    {
        /*把当前位置换算成角度值*/
        ConvertMotorPosToAngle(MotorCurPos, Angle);
    }
    else
    {
        return E_NOT_OK;
    }

    return E_OK;
}

Std_ReturnType SwivelingMotor_StartRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    uint32_t usgmod;
    double maxSupplyVoltage = 0.0;
    double voltage_tmp;
    double MotorAngle;

    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    if (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag == E_SvlReferenceRun_PerformError)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x01; /*Error*/
        return E_OK;
    }

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&usgmod);
    if ((E_UsageModeSts)usgmod == E_UsageModeSts_Drvg)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x03; /*Vehicle driving*/
        return E_OK;
    }

    if (Interface_GetKL15Voltage(&voltage_tmp) == E_OK)
    {
        maxSupplyVoltage = voltage_tmp;
    }
    if (Interface_GetKL56Voltage(&voltage_tmp) == E_OK)
    {
        if (maxSupplyVoltage < voltage_tmp)
            maxSupplyVoltage = voltage_tmp;
    }

    if (maxSupplyVoltage < 9.0 || maxSupplyVoltage > 16.0)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x04; /*Voltage out of range*/
        return E_OK;
    }

    /**************************************start routine**************************************/
    MotorAngle = ((uint16_t)InBuffer[0] << 4) + ((uint16_t)InBuffer[1] >> 4);
    MotorAngle = (MotorAngle - 2046) / 100;
    if (ConvertAngleToMotorPos(MotorAngle, &RoutineTargetPos) != E_OK)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    if (Interface_SetMotorPosition(E_MotorTpye_Swiveling, RoutineTargetPos) != E_OK)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x01; /*Error*/
        return E_OK;
    }
    g_RoutineCtrFlag = 1;
    return E_OK;
}

Std_ReturnType SwivelingMotor_StopRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        return E_OK;
    }

    Interface_StopMotor(E_MotorTpye_Swiveling);
    OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    g_RoutineCtrFlag = 0;
    return E_OK;
}

Std_ReturnType SwivelingMotor_RequestRoutineResult_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) != E_MotorMotionState_Stop_Phase)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueExcecutes;
        OutBuffer[1] = 0x00;
    }
    else
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
        OutBuffer[1] = 0x00;
    }
    return E_OK;
}

Std_ReturnType SwivelingMotor_StartRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    uint32_t usgmod;
    double maxSupplyVoltage = 0.0;
    double voltage_tmp;

    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&usgmod);
    if ((E_UsageModeSts)usgmod == E_UsageModeSts_Drvg)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x03; /*Vehicle driving*/
        return E_OK;
    }

    if (Interface_GetKL15Voltage(&voltage_tmp) == E_OK)
    {
        maxSupplyVoltage = voltage_tmp;
    }
    if (Interface_GetKL56Voltage(&voltage_tmp) == E_OK)
    {
        if (maxSupplyVoltage < voltage_tmp)
            maxSupplyVoltage = voltage_tmp;
    }

    if (maxSupplyVoltage < 9.0 || maxSupplyVoltage > 16.0)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x04; /*Voltage out of range*/
        return E_OK;
    }

    /**************************************start routine**************************************/
    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_ParamInit;

    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_SwivelingMotorWithoutHallSensor ||
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_DBL_SwivelingMotorWithoutHallSensor_WithCorner)
        gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_ReferenceRunWithOutHall;
    else
        gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_ReferenceRunWithHall;

    OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueExcecutes;
    OutBuffer[1] = 0x00; /*No inhibition*/
    g_RoutineCtrFlag = 1;
    return E_OK;
}

Std_ReturnType SwivelingMotor_StopRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{

    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        return E_OK;
    }

    Interface_StopMotor(E_MotorTpye_Swiveling);
    OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    g_RoutineCtrFlag = 0;
    return E_OK;
}

Std_ReturnType SwivelingMotor_RequestRoutineResult_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    uint32_t usgmod;
    double maxSupplyVoltage = 0.0;
    double voltage_tmp;

    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(&usgmod);
    if ((E_UsageModeSts)usgmod == E_UsageModeSts_Drvg)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x03; /*Vehicle driving*/
        return E_OK;
    }

    if (Interface_GetKL15Voltage(&voltage_tmp) == E_OK)
    {
        maxSupplyVoltage = voltage_tmp;
    }
    if (Interface_GetKL56Voltage(&voltage_tmp) == E_OK)
    {
        if (maxSupplyVoltage < voltage_tmp)
            maxSupplyVoltage = voltage_tmp;
    }

    if (maxSupplyVoltage < 9.0 || maxSupplyVoltage > 16.0)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x04; /*Voltage out of range*/
        return E_OK;
    }

    if (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag == E_SvlReferenceRun_Performing)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueExcecutes;

        OutBuffer[1] = 0x00;
    }
    else if (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag == E_SvlReferenceRun_PerformCompltedOK)
    {

        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
        OutBuffer[1] = 0x00;
    }
    else if (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag == E_SvlReferenceRun_PerformError)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
        OutBuffer[1] = 0x01; /*error*/
    }
    else
    {
        /*never get here*/
        return E_NOT_OK;
    }
    return E_OK;
}

Std_ReturnType SwivelingMotor_IoCtrCallBack(E_IOCtrType IOCtrTypeState)
{
    uint8_t IOCtrMask;
    uint32_t MotorAngle;
    uint32_t IoctrDataVal;
    sint16_t TargetPos;
    double SlewingAngle;
    E_SetPosState rtval;

    if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_NoSwivelingMotor ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_Matrix ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_WithCorner ||
        gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_DBL_MatrixmatrixWithCorner)
    {
        return E_NOT_OK;
    }
    if (IOCtrTypeState == E_IOCtrType_ReturnControl)
    {
        g_IoCtrFlag = 0;
    }
    else if (IOCtrTypeState == E_IOCtrType_FreeCurState)
    {
        Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampCtrlModSwlMotor, &IOCtrMask);
        if ((IOCtrMask & 0x80) != 0)
        {

            g_IoCtrFlag = 1;
            /*Free the motor : stop motor*/
            Interface_StopMotor(E_MotorTpye_Swiveling);

            // Interface_SetDidSignalData(DIDSIGNALNAME_ID_SwlSlewingAngle, MotorAngle);
        }
    }
    else if (IOCtrTypeState == E_IOCtrType_ShortTermAdjustment)
    {
        if (gs_SwivelingMotorInfo.SwivelingMotorState != E_SwivelingMotorState_NormalRun)
            return E_NOT_OK;

        Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampCtrlModSwlMotor, &IOCtrMask);
        if ((IOCtrMask & 0x80) != 0) /*Slewing Angle Mask*/
        {
            Interface_GetDidSignalIoctrData(DIDSIGNALNAME_ID_SwlSlewingAngle, &IoctrDataVal);
            SlewingAngle = ((double)IoctrDataVal - 2046.0) / 100;
            g_IoCtrFlag = 1;
            /*control motor to 2F request posiotion*/
            if (ConvertAngleToMotorPos(SlewingAngle, &TargetPos) != E_OK)
                return E_NOT_OK;
            while (1)
            {
                rtval = Interface_SetMotorPosition(E_MotorTpye_Swiveling, TargetPos);
                if (rtval == E_PosSet_OK)
                {
                    Interface_SetDidSignalData(DIDSIGNALNAME_ID_SwlSlewingAngle, IoctrDataVal);
                    return E_OK;
                }
                break;
                if (rtval == E_PosSet_Error)
                    return E_NOT_OK;
            }
        }
    }
}

void SwivelingMotorMainFunction(uint8_t timebase)
{
    U_StepMotorAndHall_Error StepMotorAndHallError;
    U_DevErrorTypt DevErrorTypt;
#if 0
    static uint32_t EmcSwivelingMotorTestTimer = 0;
#endif /*EMC_TEST_ENABLE*/

    if (gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_SwivelingMotorWithoutHallSensor &&
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_SwivelingMotorWitHallSensor &&
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_DBL_SwivelingMotorWithoutHallSensor_WithCorner &&
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_DBL_SwivelingMotorWitHallSensor_WithCorner)
        return;

    switch (gs_SwivelingMotorInfo.SwivelingMotorState)
    {
    case E_SwivelingMotorState_DevDrvTryInit:
        if (SwivelingMotorMotionInterfaceInit() == E_OK)
            gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_AlgoInit;
        else
        {
            DevErrorTypt.DevError = 0;
            if (Interface_GetMotorDiagnoseInfo(E_MotorTpye_Swiveling, &DevErrorTypt) == E_OK)
            {
                if (DevErrorTypt.bits.ComError == 1)
                {
                    /*通信出错*/
                    gs_SwivelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_SwivelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
                    if (gs_SwivelingMotorInfo.DrvComErrorCnt >= CNT_LIMIT_5)
                    {
                        Interface_SetDtcStepMotorError(E_MotorTpye_Swiveling, E_StepMotorErrorType_InterError, 1);
                        gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_Error;
                    }
                }
            }
        }
        break;
    case E_SwivelingMotorState_AlgoInit:
        if (SwivelingMotorAlgoInit() == E_OK)
            gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_CheckRefRunPreCondition;
        break;

    case E_SwivelingMotorState_CheckRefRunPreCondition:
        if (CheckSvlReferenceRunPreCondition() == E_OK)
        {
            if (gs_SwivelingMotorInfo.SwivelingType == E_SwivelingType_SwivelingMotorWithoutHallSensor ||
                gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_DBL_SwivelingMotorWithoutHallSensor_WithCorner)
                gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_ReferenceRunWithOutHall;
            else
                gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_ReferenceRunWithHall;
        }
        break;
    case E_SwivelingMotorState_ReferenceRunWithOutHall:
        if (SwivelingMotorReferenceRun_WithoutHall() == E_OK)
        {
            if (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag == E_SvlReferenceRun_PerformCompltedOK)
            {
                /*leave reference run mode, reset submode_RefRun*/
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_ParamInit;
                gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_NormalRun;
            }
        }
        break;
    case E_SwivelingMotorState_ReferenceRunWithHall:
        if (SwivelingMotorReferenceRun_WithHall() == E_OK)
        {
            if (gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag == E_SvlReferenceRun_PerformCompltedOK)
            {
                gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_ParamInit;
                gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_NormalRun;
            }
        }
        break;

    case E_SwivelingMotorState_NormalRun:
        if (g_IoCtrFlag == 0 && g_RoutineCtrFlag == 0)
        {
            SwivelingMotorNormalRun(timebase);
            StepMotorAndHallError = Interface_GetStepMotorAndHallErrorState(E_ErrorType_ErrorDtcState);
            if (StepMotorAndHallError.bits.SwivelMotor_OpenLoad == 1 || StepMotorAndHallError.bits.SwivelMotor_OverLoad == 1)
            {
                /*SSDS:电机开路或者堵转后，电机不能动，直到下一个上电周期*/
                gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_Error;
            }
        }

#if 0
        EmcSwivelingMotorTestTimer += timebase;

        if (EmcSwivelingMotorTestTimer <= 3000)
        {
            Interface_SetMotorPosition(E_MotorTpye_Swiveling, 500);
        }
        else if (EmcSwivelingMotorTestTimer <= 6000)
        {
            Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SwivelingMotorInfo.DefaultPos);
        }
        else
        {
            EmcSwivelingMotorTestTimer = 0;
        }
#else  /*EMC_TEST_ENABLE*/
#endif /*EMC_TEST_ENABLE*/
        break;

    case E_SwivelingMotorState_Error:
        /*此状态无法返回，除非重新上下电*/
        if (Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase)
        {
            Interface_SetMotorCurrent(E_MotorTpye_Swiveling, 0);
        }
        break;
    }
}

void SwivelingMotorInit(void)
{
    gs_SwivelingMotorInfo.SvlReferenceRunCompletedFlag = E_SvlReferenceRun_NotPerform;

    gs_SwivelingMotorInfo.SwivelingType = (E_SwivelingType)Get_pVehDBLType();

    if (gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_SwivelingMotorWithoutHallSensor &&
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_SwivelingMotorWitHallSensor &&
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_DBL_SwivelingMotorWithoutHallSensor_WithCorner &&
        gs_SwivelingMotorInfo.SwivelingType != E_SwivelingType_DBL_SwivelingMotorWitHallSensor_WithCorner)
        return;

    gs_SwivelingMotorInfo.SwivelingMotorMicroStepMode = (E_MotorMicroStepMode)Get_pSvlStepMode();

    if (Interface_GetMotorDevDrvState(E_MotorTpye_Swiveling) == E_NOT_OK)
        gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_DevDrvTryInit;
    else
        gs_SwivelingMotorInfo.SwivelingMotorState = E_SwivelingMotorState_AlgoInit;

    gs_SwivelingMotorInfo.SwivelingAlgorithm_SubMode_RefRun = E_SubMode_SvlRefRun_ParamInit;
}
