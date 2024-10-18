/*
 * LevelingMotor.c
 *
 *  Created on: 2024��2��17��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "LevelingMotor.h"
#include "AswInterfaceManager.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_LevelingMotorInfo gs_LevelingMotorInfo;
static sint16_t g_LVLOffset = 0;
static uint32_t LowTimerHeatupTime = 0;
static uint8_t HeatUpFlag = 0;
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
 *  		目标位置 = gs_LevelingMotorInfo.DefaultPos + (目标角度-gs_LevelingMotorInfo.DefaultAngle) 	0.01745 * gs_LevelingMotorInfo.HsPerRad
 *      ->  目标角度 =(目标位置-gs_LevelingMotorInfo.DefaultPos)/(0.01745 * gs_LevelingMotorInfo.HsPerRad)
 *
 */
static Std_ReturnType ConvertMotorPosToAngle(sint16_t MotorPos, double *TargetAngle)
{
    *TargetAngle = ((double)(MotorPos - gs_LevelingMotorInfo.DefaultPos)) / (0.01745 * (double)gs_LevelingMotorInfo.HsPerRad);
    return E_OK;
}

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
    if (Get_LeLamp_pLvlBotPosdeg() < Get_LeLamp_pLvlTopPosdeg())
    {
        if ((TargetAngle < Get_LeLamp_pLvlBotPosdeg()) || (TargetAngle > Get_LeLamp_pLvlTopPosdeg()))
        {
            return E_NOT_OK;
        }
    }
    else
    {
        if ((TargetAngle > Get_LeLamp_pLvlBotPosdeg()) || (TargetAngle < Get_LeLamp_pLvlTopPosdeg()))
        {
            return E_NOT_OK;
        }
    }
#elif HCM_RIGHT_SIDE
    if (Get_RiLamp_pLvlBotPosdeg() < Get_RiLamp_pLvlTopPosdeg())
    {
        if ((TargetAngle < Get_RiLamp_pLvlBotPosdeg()) || (TargetAngle > Get_RiLamp_pLvlTopPosdeg()))
        {
            return E_NOT_OK;
        }
    }
    else
    {
        if ((TargetAngle > Get_RiLamp_pLvlBotPosdeg()) || (TargetAngle < Get_RiLamp_pLvlTopPosdeg()))
        {
            return E_NOT_OK;
        }
    }
#endif
    *TargetPos = gs_LevelingMotorInfo.DefaultPos + (TargetAngle - gs_LevelingMotorInfo.DefaultAngle) * 0.01745 * gs_LevelingMotorInfo.HsPerRad;
    return E_OK;
}

static Std_ReturnType LevelingMotorAlgoInit(void)
{
    Std_ReturnType rtval = E_OK;
    uint8 Ratio;
    /*The paramter table's unit is Half Step*/
    if (gs_LevelingMotorInfo.LevelingMotorMicroStepMode >= MotorMicroStepMode_2)
    {
        Ratio = gs_LevelingMotorInfo.LevelingMotorMicroStepMode / MotorMicroStepMode_2;
        g_LVLOffset = Get_pLVLOffset() * Ratio;
#if HCM_LEFT_SIDE
        gs_LevelingMotorInfo.BottomBlockPos = Get_LeLamp_pLvlLimBotPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.TopBlockPos = Get_LeLamp_pLvlLimTopPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.BottomLogicPos = Get_LeLamp_pLvlBotPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.TopLogicPos = Get_LeLamp_pLvlTopPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.DefaultPos = Get_LeLamp_pLvlDfltPosLe() * ((sint16)Ratio) + g_LVLOffset;
#elif HCM_RIGHT_SIDE
        gs_LevelingMotorInfo.BottomBlockPos = Get_RiLamp_pLvlLimBotPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.TopBlockPos = Get_RiLamp_pLvlLimTopPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.BottomLogicPos = Get_RiLamp_pLvlBotPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.TopLogicPos = Get_RiLamp_pLvlTopPos() * ((sint16)Ratio);
        gs_LevelingMotorInfo.DefaultPos = Get_RiLamp_pLvlDfltPosRi() * ((sint16)Ratio) + g_LVLOffset;
#endif
        gs_LevelingMotorInfo.AdditionalStep = Get_pLvlCorStepsNum() * Ratio;
        gs_LevelingMotorInfo.HsPerRad = Get_pLvlHsPerRad() * Ratio;
    }
    else
    {
        /*Full Step*/
        Ratio = MotorMicroStepMode_2;
        g_LVLOffset = Get_pLVLOffset() / Ratio;
#if HCM_LEFT_SIDE
        gs_LevelingMotorInfo.BottomBlockPos = Get_LeLamp_pLvlLimBotPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.TopBlockPos = Get_LeLamp_pLvlLimTopPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.BottomLogicPos = Get_LeLamp_pLvlBotPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.TopLogicPos = Get_LeLamp_pLvlTopPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.DefaultPos = Get_LeLamp_pLvlDfltPosLe() / ((sint16)Ratio) + g_LVLOffset;
#elif HCM_RIGHT_SIDE
        gs_LevelingMotorInfo.BottomBlockPos = Get_RiLamp_pLvlLimBotPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.TopBlockPos = Get_RiLamp_pLvlLimTopPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.BottomLogicPos = Get_RiLamp_pLvlBotPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.TopLogicPos = Get_RiLamp_pLvlTopPos() / ((sint16)Ratio);
        gs_LevelingMotorInfo.DefaultPos = Get_RiLamp_pLvlDfltPosRi() / ((sint16)Ratio) + g_LVLOffset;
#endif
        gs_LevelingMotorInfo.AdditionalStep = Get_pLvlCorStepsNum() / Ratio;
        gs_LevelingMotorInfo.HsPerRad = Get_pLvlHsPerRad() / Ratio;
    }
    gs_LevelingMotorInfo.StallErrorCnt = 0;
    gs_LevelingMotorInfo.TargetPos = 0;
    gs_LevelingMotorInfo.CurrentMotorPos = 0;
#if HCM_LEFT_SIDE
    gs_LevelingMotorInfo.DefaultAngle = (double)Get_LeLamp_pLvlDfltPosLe_deg();
#elif HCM_RIGHT_SIDE
    gs_LevelingMotorInfo.DefaultAngle = (double)Get_RiLamp_pLvlDfltPosRi_deg();
#endif

    return rtval;
}

static Std_ReturnType CheckLvlReferenceRunPreCondition(void)
{
#if (EMC_TEST_ENABLE == 1)
    return E_OK;
#endif  /*(EMC_TEST_ENABLE == 1)*/

    Std_ReturnType rtval = E_NOT_OK;

    uint32_t SignalValue;
    static E_UsageModeSts se_LvlUsageMode_Last = E_UsageModeSts_Abdnd;
    static E_UsageModeSts se_LvlUsageMode_Curr = E_UsageModeSts_Abdnd;

    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& SignalValue);
    se_LvlUsageMode_Last = se_LvlUsageMode_Curr;
    se_LvlUsageMode_Curr = (E_UsageModeSts)SignalValue;

    S_E2EStateForFailSafe VehSpdLgtE2ESts;
    double VehSpdLgtA = 0.0;

    VehSpdLgtE2ESts = GetE2EFlagForFailSafe();
    Interface_GetSignal_VehSpdLgtA(& VehSpdLgtA);
    if (VehSpdLgtE2ESts.E2EErrorFlagForFailSafe.bits.VehSpdCntErr  == 0u &&
        VehSpdLgtE2ESts.E2EErrorFlagForFailSafe.bits.VehSpdCrcErr  == 0u &&
        VehSpdLgtE2ESts.E2EErrorFlagForFailSafe.bits.VehSpdTimeout == 0u &&
        VehSpdLgtA * 3.6 <= 4.0)
    {
        if(gs_LevelingMotorInfo.LevelingType == E_Manual_LVL)
        {
            if( (se_LvlUsageMode_Last == E_UsageModeSts_Abdnd || se_LvlUsageMode_Last == E_UsageModeSts_InActv) &&
                (se_LvlUsageMode_Curr == E_UsageModeSts_Cnvinc || se_LvlUsageMode_Curr == E_UsageModeSts_Actv || se_LvlUsageMode_Curr == E_UsageModeSts_Drvg) )
            {
                rtval = E_OK;
            }
        }
        else if(gs_LevelingMotorInfo.LevelingType == E_Automatic_LVL)
        {
#if (OEM_PLATFORM == OEM_SMART)
            if( (se_LvlUsageMode_Last == E_UsageModeSts_Abdnd || se_LvlUsageMode_Last == E_UsageModeSts_InActv || se_LvlUsageMode_Last == E_UsageModeSts_Cnvinc) &&
                (se_LvlUsageMode_Curr == E_UsageModeSts_Actv || se_LvlUsageMode_Curr == E_UsageModeSts_Drvg) )
            {
                rtval = E_OK;
            }
#elif (OEM_PLATFORM == OEM_GEELY)
            if( (se_LvlUsageMode_Last == E_UsageModeSts_Abdnd || se_LvlUsageMode_Last == E_UsageModeSts_InActv) &&
                (se_LvlUsageMode_Curr == E_UsageModeSts_Cnvinc || se_LvlUsageMode_Curr == E_UsageModeSts_Actv || se_LvlUsageMode_Curr == E_UsageModeSts_Drvg) )
            {
                rtval = E_OK;
            }
#endif
        }
    }
    return rtval;
}

static Std_ReturnType CaculateLvlMotorParameterByTemp(E_LevelingMotorState LevelingMotorState, uint16_t *AccDecStepNum, uint16_t *holdcurrent, uint16_t *runcurrent)
{
    Std_ReturnType rtval = E_OK;
#if AMBIENT_TEMPERATURE_USE_VEHICLE_TEMPERATURE
    sint32_t AmbTemp;
#else
    E_MotorTemperatureInfo MotorTemperatureInfo;
    rtval |= Interface_GetMotorTemperatureInfo(E_MotorTpye_Leveling, &MotorTemperatureInfo);

    if (rtval != E_OK)
        return rtval;
#endif

#if AMBIENT_TEMPERATURE_USE_VEHICLE_TEMPERATURE
    Interface_GetSignal_AmbTRawAmbTVal(&AmbTemp);

    if (AmbTemp < ((sint32_t)Get_pLvlLowTempThreshold()))
#else
    if (MotorTemperatureInfo == E_MotorMotorTemp_LowTempWarning)
#endif
    {
        *AccDecStepNum = Get_pLvlVmaxLowTemp();
        *holdcurrent = Get_pLvlIholdLowTemp();
        *runcurrent = Get_pLvlIrunLowTemp();
        if (HeatUpFlag == 0)
        {
            LowTimerHeatupTime = (uint32_t)Get_pLvlLowTempHeatupTime() * 1000;
            HeatUpFlag = 1;
        }
    }
#if AMBIENT_TEMPERATURE_USE_VEHICLE_TEMPERATURE
#else
    else if (MotorTemperatureInfo == E_MotorMotorTemp_HighTempShutDown)
    {
        return E_NOT_OK;
    }
#endif
    else
    {
        if (LowTimerHeatupTime == 0)
        {
            *holdcurrent = Get_pLvlIholdNorm();
            /*Normal Temperature*/
            if (LevelingMotorState == E_LevelingMotorState_ReferenceRun)
            {
                *AccDecStepNum = Get_pLvlVmaxRef();
                *runcurrent = Get_pLvlIrunRef();
            }
            else if (LevelingMotorState == E_LevelingMotorState_NormalRun)
            {
                *AccDecStepNum = Get_pLvlVmaxNorm();
                *runcurrent = Get_pLvlIrunNorm();
            }
            else
            {
                *AccDecStepNum = Get_pLvlVmaxNorm();
                *runcurrent = Get_pLvlIrunNorm();
            }
        }
        else
        {
            *AccDecStepNum = Get_pLvlVmaxLowTemp();
            *holdcurrent = Get_pLvlIholdLowTemp();
            *runcurrent = Get_pLvlIrunLowTemp();
        }
    }
    return rtval;
}

static Std_ReturnType LevelingMotorReferenceRun(void)
{

    uint16_t AccDecStepNum = 0;
    uint16_t holdcurrent, runcurrent;
    Std_ReturnType rtval = E_OK;
    E_MotorMotionState MotorMotionState;
    U_DevErrorTypt DevErrorTypt;
    U_StepMotorAndHall_Error StepMotorAndHallDTCError;

    switch (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun)
    {
    case E_SubMode_LvlRefRun_ParamInit:

        rtval |= CaculateLvlMotorParameterByTemp(E_LevelingMotorState_ReferenceRun, &AccDecStepNum, &holdcurrent, &runcurrent);
        if (rtval == E_NOT_OK)
            return E_NOT_OK;

        rtval |= Interface_SetMotorMotionParameter(E_MotorTpye_Leveling, AccDecStepNum, runcurrent, holdcurrent);
        if (rtval == E_NOT_OK)
            return E_NOT_OK;
        if (Interface_ResetMotorPosition(E_MotorTpye_Leveling, 0) == E_PosSet_OK)
        {
            gs_LevelingMotorInfo.CurrentMotorPos = 0;
            /*Clear the reference run complete flag*/
            gs_LevelingMotorInfo.ReferenceRunCompletedFlag = E_LvlReferenceRun_Performing;

            gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_GoToBottomBlockPos;
        }
        break;
    case E_SubMode_LvlRefRun_GoToTopBlockPos:
    case E_SubMode_LvlRefRun_GoToBottomBlockPos:
    case E_SubMode_LvlRefRun_GoToBottomAdditionPos:
    case E_SubMode_LvlRefRun_GoToDefaultPos:
        if (Interface_GetMotorMotionState(E_MotorTpye_Leveling) != E_MotorMotionState_Stop_Phase)
        {
            Interface_StopMotor(E_MotorTpye_Leveling);
            return E_OK;
        }

        rtval |= Interface_DisableMotorStallDetect(E_MotorTpye_Leveling);

        /********************************Caculate TargetPosition********************************/
        if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToTopBlockPos)
        {
            /*The motor current position is 0*/
            Interface_ResetMotorPosition(E_MotorTpye_Leveling, 0);
            /*Top Block is positive position,so TargetPos will positive position*/
            gs_LevelingMotorInfo.TargetPos = gs_LevelingMotorInfo.TopBlockPos - gs_LevelingMotorInfo.BottomBlockPos;
        }
        else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToBottomBlockPos)
        {
            /*The motor current position is 0*/
            Interface_ResetMotorPosition(E_MotorTpye_Leveling, 0);
            gs_LevelingMotorInfo.TargetPos = -(gs_LevelingMotorInfo.TopBlockPos - gs_LevelingMotorInfo.BottomBlockPos);
        }
        else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToBottomAdditionPos)
        {
            /* the motor current pos is bottom block position*/
            Interface_ResetMotorPosition(E_MotorTpye_Leveling, gs_LevelingMotorInfo.BottomBlockPos);

            rtval |= CaculateLvlMotorParameterByTemp(E_LevelingMotorState_ReferenceRun, &AccDecStepNum, &holdcurrent, &runcurrent);
            if (rtval == E_NOT_OK)
                return E_NOT_OK;
            /*Set motor Acc and Dec param*/
            /*HCM_SRS_5_0026*/
            Interface_SetMotorMotionParameter(E_MotorTpye_Leveling, 1, runcurrent, holdcurrent);
            gs_LevelingMotorInfo.TargetPos = gs_LevelingMotorInfo.BottomBlockPos - gs_LevelingMotorInfo.AdditionalStep;
        }
        else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToDefaultPos)
        {
            /* the motor current pos is BottomBlockPos*/
            Interface_ResetMotorPosition(E_MotorTpye_Leveling, gs_LevelingMotorInfo.BottomBlockPos);
            gs_LevelingMotorInfo.CurrentMotorPos = gs_LevelingMotorInfo.BottomBlockPos;

            rtval |= CaculateLvlMotorParameterByTemp(E_LevelingMotorState_NormalRun, &AccDecStepNum, &holdcurrent, &runcurrent);
            if (rtval == E_NOT_OK)
                return E_NOT_OK;
            /*Set motor Acc and Dec param*/
            Interface_SetMotorMotionParameter(E_MotorTpye_Leveling, AccDecStepNum, runcurrent, holdcurrent);

            gs_LevelingMotorInfo.TargetPos = gs_LevelingMotorInfo.DefaultPos;
        }
        if (Interface_SetMotorPosition(E_MotorTpye_Leveling, gs_LevelingMotorInfo.TargetPos) == E_PosSet_OK)
        {
            if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToTopBlockPos)
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_FindTopStallPos;
            else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToBottomBlockPos)
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_FindBottomStallPos;
            else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToBottomAdditionPos)
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_FindBottomAdditionPos;
            else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_GoToDefaultPos)
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_WaitLeave;
        }
        break;

    case E_SubMode_LvlRefRun_FindBottomAdditionPos:
        MotorMotionState = Interface_GetMotorMotionState(E_MotorTpye_Leveling);
        if (MotorMotionState == E_MotorMotionState_Stop_Phase)
        {
            gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_GoToDefaultPos;
        }
        break;

    case E_SubMode_LvlRefRun_FindTopStallPos:
    case E_SubMode_LvlRefRun_FindBottomStallPos:
        MotorMotionState = Interface_GetMotorMotionState(E_MotorTpye_Leveling);

        if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase ||
            MotorMotionState == E_MotorMotionState_Run_Accelerate_Phase ||
            MotorMotionState == E_MotorMotionState_Run_Decelerate_Phase)
        {
#if (LVL_MOTOR_REFERENCE_USE_STALL_DET == 1)
            /*电机处于运动状态*/
            if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase)
            {
                /*电机处于最大速度中，开机堵转检测*/
                rtval |= Interface_EnableMotorStallDetect(E_MotorTpye_Leveling);
            }
            else
            {
                /*电机处于加减速阶段，关闭堵转检测*/
                Interface_DisableMotorStallDetect(E_MotorTpye_Leveling);
            }
#endif
            /*clear fault*/
            DevErrorTypt.DevError = 0;
            rtval |= Interface_GetMotorDiagnoseInfo(E_MotorTpye_Leveling, &DevErrorTypt);

            if (rtval == E_OK)
            {
                /*Spi 通信错误检测*/
                if (DevErrorTypt.bits.ComError == 1)
                {
                    rtval = E_NOT_OK;
                    gs_LevelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);

                    if (gs_LevelingMotorInfo.DrvComErrorCnt >= CNT_LIMIT_5)
                    {
                        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_InterError, 1);
                    }
                }
                else
                {
                    gs_LevelingMotorInfo.DrvComErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, DEC_LIMIT_0);
                    if (gs_LevelingMotorInfo.DrvComErrorCnt == DEC_LIMIT_0)
                    {
                        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_InterError, 0);
                    }
                }
            }

            if (rtval == E_OK)
            {
                /*开路检测*/
                if (DevErrorTypt.bits.DevOpenLoad == 1)
                {
                    rtval = E_NOT_OK;
                    gs_LevelingMotorInfo.OpenErrorCnt = CNT_INC(gs_LevelingMotorInfo.OpenErrorCnt, STEP_1, CNT_LIMIT_5);

                    if (gs_LevelingMotorInfo.OpenErrorCnt >= CNT_LIMIT_5)
                    {
                        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_OpenLoad, 1);
                    }
                }
                else
                {
                    gs_LevelingMotorInfo.OpenErrorCnt = CNT_DEC(gs_LevelingMotorInfo.OpenErrorCnt, STEP_1, DEC_LIMIT_0);
                    if (gs_LevelingMotorInfo.OpenErrorCnt == DEC_LIMIT_0)
                    {
                        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_OpenLoad, 0);
                    }
                }
            }

            StepMotorAndHallDTCError = Interface_GetStepMotorAndHallErrorState(E_ErrorType_ErrorRealTimeState);

            if ((StepMotorAndHallDTCError.bits.LevelMotor_OpenLoad == 1) || (StepMotorAndHallDTCError.bits.LevelMotor_InterError == 1))
            {
                /*电机开路或者和电机驱动芯片通信错误*/
                Interface_StopMotor(E_MotorTpye_Leveling);
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_RefRunError;
            }

            if (rtval == E_OK)
            {
                if (DevErrorTypt.bits.Stall == 1)
                {
                    gs_LevelingMotorInfo.StallErrorCnt = CNT_INC(gs_LevelingMotorInfo.StallErrorCnt, STEP_1, LVL_REFERENCE_RUN_STALL_DEBOUNCE);
                    if (gs_LevelingMotorInfo.StallErrorCnt >= LVL_REFERENCE_RUN_STALL_DEBOUNCE)
                    {
                        gs_LevelingMotorInfo.StallErrorCnt = 0;
                        if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_FindTopStallPos)
                            gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_GoToBottomBlockPos;
                        else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_FindBottomStallPos)
                            gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_GoToBottomAdditionPos;
                    }
                }
            }
        }
        else if (MotorMotionState == E_MotorMotionState_Stop_Phase)
        {
            gs_LevelingMotorInfo.StallErrorCnt = 0;
            if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_FindTopStallPos)
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_GoToBottomBlockPos;
            else if (gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun == E_SubMode_LvlRefRun_FindBottomStallPos)
                gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_GoToBottomAdditionPos;
        }
        break;

    case E_SubMode_LvlRefRun_WaitLeave:
        if (Interface_GetMotorMotionState(E_MotorTpye_Leveling) == E_MotorMotionState_Stop_Phase)
        {
            gs_LevelingMotorInfo.CurrentMotorPos = gs_LevelingMotorInfo.DefaultPos;
            gs_LevelingMotorInfo.CurrentAngle = gs_LevelingMotorInfo.DefaultAngle;
            gs_LevelingMotorInfo.ReferenceRunCompletedFlag = E_LvlReferenceRun_PerformCompltedOK;
        }
        break;
    case E_SubMode_LvlRefRun_RefRunError:
        gs_LevelingMotorInfo.ReferenceRunCompletedFlag = E_LvlReferenceRun_PerformError;
        if (Interface_GetMotorMotionState(E_MotorTpye_Leveling) == E_MotorMotionState_Stop_Phase)
        {
            Interface_SetMotorCurrent(E_MotorTpye_Leveling, 0);
        }
        break;
    }

    return rtval;
}
static void LevelingMotorDiagInNormalRun(void)
{
    Std_ReturnType rtval = E_OK;
    U_DevErrorTypt DevErrorTypt;
    E_MotorMotionState MotorMotionState;

    MotorMotionState = Interface_GetMotorMotionState(E_MotorTpye_Leveling);

    if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase ||
        MotorMotionState == E_MotorMotionState_Run_Accelerate_Phase ||
        MotorMotionState == E_MotorMotionState_Run_Decelerate_Phase)
    {
#if (LVL_MOTOR_REFERENCE_USE_STALL_DET == 1)
        if (MotorMotionState == E_MotorMotionState_Run_Max_Speed_Phase)
        {
            /*使能堵转检测*/
            Interface_EnableMotorStallDetect(E_MotorTpye_Leveling);
        }
        else
        {
            Interface_DisableMotorStallDetect(E_MotorTpye_Leveling);
        }
#endif
        DevErrorTypt.DevError = 0;
        rtval |= Interface_GetMotorDiagnoseInfo(E_MotorTpye_Leveling, &DevErrorTypt);

        if (rtval == E_OK)
        {
            /*Spi 通信错误检测*/
            if (DevErrorTypt.bits.ComError == 1)
            {
                rtval = E_NOT_OK;
                gs_LevelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
            }
            else
            {
                gs_LevelingMotorInfo.DrvComErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, DEC_LIMIT_0);
            }
        }

        if (rtval == E_OK)
        {
            /*过温检测*/
            if (DevErrorTypt.bits.TempWarning == 1)
                gs_LevelingMotorInfo.DrvTmWarningErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_LevelingMotorInfo.DrvTmWarningErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, DEC_LIMIT_0);
            /*热保护检测*/
            if (DevErrorTypt.bits.ThermalShuTDown == 1)
                gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, DEC_LIMIT_0);
            /*欠压检测*/
            if (DevErrorTypt.bits.UV == 1)
                gs_LevelingMotorInfo.DrvUVErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvUVErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_LevelingMotorInfo.DrvUVErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvUVErrorCnt, STEP_1, DEC_LIMIT_0);

            /*开路检测*/
            if (DevErrorTypt.bits.DevOpenLoad == 1)
            {
                rtval = E_NOT_OK;
                gs_LevelingMotorInfo.OpenErrorCnt = CNT_INC(gs_LevelingMotorInfo.OpenErrorCnt, STEP_1, CNT_LIMIT_5);

                if (gs_LevelingMotorInfo.OpenErrorCnt >= CNT_LIMIT_5)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_OpenLoad, 1);
            }
            else
            {
                gs_LevelingMotorInfo.OpenErrorCnt = CNT_DEC(gs_LevelingMotorInfo.OpenErrorCnt, STEP_1, DEC_LIMIT_0);
                if (gs_LevelingMotorInfo.OpenErrorCnt == DEC_LIMIT_0)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_OpenLoad, 0);
            }
        }

        if (rtval == E_OK)
        {
            /*堵转检测*/
            if (DevErrorTypt.bits.Stall == 1)
            {
                gs_LevelingMotorInfo.StallErrorCnt = CNT_INC(gs_LevelingMotorInfo.StallErrorCnt, STEP_1, CNT_LIMIT_5);
                if (gs_LevelingMotorInfo.StallErrorCnt >= CNT_LIMIT_5)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_OverLoad, 1);
            }
            else
            {
                gs_LevelingMotorInfo.StallErrorCnt = CNT_DEC(gs_LevelingMotorInfo.StallErrorCnt, STEP_1, DEC_LIMIT_0);
                if (gs_LevelingMotorInfo.StallErrorCnt == DEC_LIMIT_0)
                    Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_OverLoad, 0);
            }
        }
    }
    else
    {
        /*电机不处于最大速度，关闭检测*/
        Interface_DisableMotorStallDetect(E_MotorTpye_Leveling);

        DevErrorTypt.DevError = 0;
        rtval |= Interface_GetMotorDiagnoseInfo(E_MotorTpye_Leveling, &DevErrorTypt);

        if (rtval == E_OK)
        {
            /*Spi 通信错误检测*/
            if (DevErrorTypt.bits.ComError == 1)
            {
                rtval = E_NOT_OK;
                gs_LevelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
            }
            else
            {
                gs_LevelingMotorInfo.DrvComErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, DEC_LIMIT_0);
            }
        }

        if (rtval == E_OK)
        {
            /*过温检测*/
            if (DevErrorTypt.bits.TempWarning == 1)
                gs_LevelingMotorInfo.DrvTmWarningErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_LevelingMotorInfo.DrvTmWarningErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvTmWarningErrorCnt, STEP_1, DEC_LIMIT_0);
            /*热保护检测*/
            if (DevErrorTypt.bits.ThermalShuTDown == 1)
                gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt, STEP_1, DEC_LIMIT_0);
            /*欠压检测*/
            if (DevErrorTypt.bits.UV == 1)
                gs_LevelingMotorInfo.DrvUVErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvUVErrorCnt, STEP_1, CNT_LIMIT_5);
            else
                gs_LevelingMotorInfo.DrvUVErrorCnt = CNT_DEC(gs_LevelingMotorInfo.DrvUVErrorCnt, STEP_1, DEC_LIMIT_0);
        }
    }

    if (gs_LevelingMotorInfo.DrvComErrorCnt == CNT_LIMIT_5 || gs_LevelingMotorInfo.DrvTmWarningErrorCnt == CNT_LIMIT_5 ||
        gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt == CNT_LIMIT_5 || gs_LevelingMotorInfo.DrvUVErrorCnt == CNT_LIMIT_5)
    {
        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_InterError, 1);
    }
    else if (gs_LevelingMotorInfo.DrvComErrorCnt == DEC_LIMIT_0 && gs_LevelingMotorInfo.DrvTmWarningErrorCnt == DEC_LIMIT_0 &&
             gs_LevelingMotorInfo.DrvThermalShutDownErrorCnt == DEC_LIMIT_0 && gs_LevelingMotorInfo.DrvUVErrorCnt == DEC_LIMIT_0)
    {
        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_InterError, 0);
    }
}
static Std_ReturnType LevelingMotorNormalRun(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    static uint32_t timetick = 0;

    /*Should re-judge LevelingMotorState ,because LevelingMotorState maybe modified by referencerun request*/
    timetick += timebase;
    if (gs_LevelingMotorInfo.LevelingMotorState == E_LevelingMotorState_NormalRun)
    {
        uint16_t AccDecStepNum;
        uint16_t holdcurrent;
        uint16_t runcurrent;

        if (Interface_GetMotorMotionState(E_MotorTpye_Leveling) == E_MotorMotionState_Stop_Phase)
        {
            /*每隔1s计算电机参数*/
            if (timetick >= 1000)
            {
                if (CaculateLvlMotorParameterByTemp(E_LevelingMotorState_NormalRun, &AccDecStepNum, &holdcurrent, &runcurrent) == E_OK)
                {
                    Interface_SetMotorMotionParameter(E_MotorTpye_Leveling, AccDecStepNum, runcurrent, holdcurrent);
                }
                timetick = 0;
            }
        }

        /*对电机进行诊断*/
        LevelingMotorDiagInNormalRun();
    }
    return rtval;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 获取Leveling电机的工作模式 */
/* 返回值：0:正常模式； 1：UDS模式 */
uint8_t LevelingMotor_GetLvlMotorRunMode(void)
{
    return (g_IoCtrFlag | g_RoutineCtrFlag);
}

/*获取Leveling电机的初始化状态*/
E_LvlRefRunSts LevelingMotor_GetLvlRefRunSts(void)
{
    E_LvlRefRunSts LvlRefRunSts = E_LvlRefRunSts_NoCond;

    switch (gs_LevelingMotorInfo.ReferenceRunCompletedFlag)
    {
        case E_LvlReferenceRun_NotPerform:
            LvlRefRunSts = E_LvlRefRunSts_NoCond;
            break;
        case E_LvlReferenceRun_Performing:
            LvlRefRunSts = E_LvlRefRunSts_During;
            break;
        case E_LvlReferenceRun_PerformCompltedOK:
            LvlRefRunSts = E_LvlRefRunSts_Done;
            break;
        case E_LvlReferenceRun_PerformError:
            LvlRefRunSts = E_LvlRefRunSts_Error;
    }
    return LvlRefRunSts;
}

/*
 *获得电机当前角度
 *返回值 E_NOT_OK：电机初始化未完成
 */
Std_ReturnType LevelingMotor_GetLvlCurAngle(double *Angle)
{
    sint16_t MotorCurPos;

    if (gs_LevelingMotorInfo.LevelingMotorState != E_LevelingMotorState_NormalRun)
        return E_NOT_OK;

    if (Interface_GetMotorCurPosition(E_MotorTpye_Leveling, &MotorCurPos) == E_OK)
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

Std_ReturnType LevelingMotor_StartRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    uint32_t usgmod;
    double maxSupplyVoltage = 0.0;
    double voltage_tmp;
    double MotorAngle;

    if (gs_LevelingMotorInfo.ReferenceRunCompletedFlag != E_LvlReferenceRun_PerformCompltedOK ||
        gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available ||
        gs_LevelingMotorInfo.LevelingType == E_DCMotor)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    if (gs_LevelingMotorInfo.ReferenceRunCompletedFlag == E_LvlReferenceRun_PerformError)
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

    if (Interface_SetMotorPosition(E_MotorTpye_Leveling, RoutineTargetPos) != E_OK)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x01; /*Error*/
        return E_OK;
    }
    g_RoutineCtrFlag = 1;
    return E_OK;
}

Std_ReturnType LevelingMotor_StopRoutineCtr_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        return E_OK;
    }

    Interface_StopMotor(E_MotorTpye_Leveling);
    OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    g_RoutineCtrFlag = 0;
    return E_OK;
}

Std_ReturnType LevelingMotor_RequestRoutineResult_MotorMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        OutBuffer[1] = 0x05; /*Mismatch*/
        return E_OK;
    }

    if (Interface_GetMotorMotionState(E_MotorTpye_Leveling) != E_MotorMotionState_Stop_Phase)
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

Std_ReturnType LevelingMotor_StartRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    uint32_t usgmod;
    double maxSupplyVoltage = 0.0;
    double voltage_tmp;

    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
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
    gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_ParamInit;
    gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_ReferenceRun;
    OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueExcecutes;
    OutBuffer[1] = 0x00; /*No inhibition*/
    g_RoutineCtrFlag = 1;
    return E_OK;
}

Std_ReturnType LevelingMotor_StopRoutineCtr_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{

    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueAborted;
        return E_OK;
    }

    Interface_StopMotor(E_MotorTpye_Leveling);
    OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    g_RoutineCtrFlag = 0;
    return E_OK;
}

Std_ReturnType LevelingMotor_RequestRoutineResult_RefernceMove(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    uint32_t usgmod;
    double maxSupplyVoltage = 0.0;
    double voltage_tmp;

    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
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

    if (gs_LevelingMotorInfo.ReferenceRunCompletedFlag == E_LvlReferenceRun_Performing)
    {
        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueExcecutes;

        OutBuffer[1] = 0x00;
    }
    else if (gs_LevelingMotorInfo.ReferenceRunCompletedFlag == E_LvlReferenceRun_PerformCompltedOK)
    {

        OutBuffer[0] = (E_RoutineType_LongRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
        OutBuffer[1] = 0x00;
    }
    else if (gs_LevelingMotorInfo.ReferenceRunCompletedFlag == E_LvlReferenceRun_PerformError)
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

Std_ReturnType LevelingMotor_IoCtrCallBack(E_IOCtrType IOCtrTypeState)
{
    E_SetPosState rtval;
    uint8_t IOCtrMask;
    uint32_t IoctrDataVal;
    sint16_t TargetPos;
    double SlewingAngle;
    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
        return E_NOT_OK;

    if (IOCtrTypeState == E_IOCtrType_ReturnControl)
    {
        g_IoCtrFlag = 0;
    }
    else if (IOCtrTypeState == E_IOCtrType_FreeCurState)
    {
        Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampCtrlModLvlMotor, &IOCtrMask);
        if ((IOCtrMask & 0x80) != 0)
        {
            g_IoCtrFlag = 1;
            /*Free the motor : stop motor*/
            Interface_StopMotor(E_MotorTpye_Leveling);
        }
    }
    else if (IOCtrTypeState == E_IOCtrType_ShortTermAdjustment)
    {
        if (gs_LevelingMotorInfo.LevelingMotorState != E_LevelingMotorState_NormalRun)
            return E_NOT_OK;

        Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampCtrlModLvlMotor, &IOCtrMask);
        if ((IOCtrMask & 0x80) != 0) /*Slewing Angle Mask*/
        {
            Interface_GetDidSignalIoctrData(DIDSIGNALNAME_ID_LvlSlewingAngle, &IoctrDataVal);
            SlewingAngle = ((double)IoctrDataVal - 2046.0) / 100;
            g_IoCtrFlag = 1;
            /*control motor to 2F request posiotion*/
            if (ConvertAngleToMotorPos(SlewingAngle, &TargetPos) != E_OK)
                return E_NOT_OK;
            while (1)
            {
                rtval = Interface_SetMotorPosition(E_MotorTpye_Leveling, TargetPos);
                if (rtval == E_PosSet_OK)
                {
                    Interface_SetDidSignalData(DIDSIGNALNAME_ID_LvlSlewingAngle, IoctrDataVal);
                    return E_OK;
                }
                break;
                if (rtval == E_PosSet_Error)
                    return E_NOT_OK;
            }
        }
    }
    else
    {
        return E_NOT_OK;
    }

    return E_OK;
}

void LevelingMotorMainFunction(uint8_t timebase)
{
    U_StepMotorAndHall_Error StepMotorAndHallError;
    U_DevErrorTypt DevErrorTypt;

    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
        return;

    if ((0 + timebase) > LowTimerHeatupTime)
        LowTimerHeatupTime = 0;
    else
        LowTimerHeatupTime -= timebase;

    switch (gs_LevelingMotorInfo.LevelingMotorState)
    {
    case E_LevelingMotorState_DevDrvTryInit:
        if (LevelingMotorMotionInterfaceInit() == E_OK)
            gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_AlgoInit;
        else
        {
            DevErrorTypt.DevError = 0;
            if (Interface_GetMotorDiagnoseInfo(E_MotorTpye_Leveling, &DevErrorTypt) == E_OK)
            {
                if (DevErrorTypt.bits.ComError == 1)
                {
                    /*通信出错*/
                    gs_LevelingMotorInfo.DrvComErrorCnt = CNT_INC(gs_LevelingMotorInfo.DrvComErrorCnt, STEP_1, CNT_LIMIT_5);
                    if (gs_LevelingMotorInfo.DrvComErrorCnt >= CNT_LIMIT_5)
                    {
                        Interface_SetDtcStepMotorError(E_MotorTpye_Leveling, E_StepMotorErrorType_InterError, 1);
                        gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_Error;
                    }
                }
            }
        }
        break;
    case E_LevelingMotorState_AlgoInit:
        if (LevelingMotorAlgoInit() == E_OK)
            gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_CheckRefRunPreCondition;
        break;
    case E_LevelingMotorState_CheckRefRunPreCondition:
        if (CheckLvlReferenceRunPreCondition() == E_OK)
        {
            gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_ParamInit;
            gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_ReferenceRun;
        }
        break;
    case E_LevelingMotorState_ReferenceRun:
        if (LevelingMotorReferenceRun() == E_OK)
        {
            if (gs_LevelingMotorInfo.ReferenceRunCompletedFlag == E_LvlReferenceRun_PerformCompltedOK)
            {
                gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_NormalRun;
            }
        }
        break;
    case E_LevelingMotorState_NormalRun:
        if (g_IoCtrFlag == 0 && g_RoutineCtrFlag == 0)
        {
            LevelingMotorNormalRun(timebase);

#if (OEM_PLATFORM == OEM_GEELY)
            if(Get_pAHBCType != 0u) /* 自适应远光灯的再次初始化 */
            {
                static uint8_t CameraStsforAHBC_Last = 0xFFu;
                static uint8_t CameraStsforAHBC_Curr = 0xFFu;
                uint32_t SignalValue;
                E_UsageModeSts UsageModeSts;
                S_E2EStateForFailSafe VehSpdLgtE2ESts;
                double VehSpdLgtA = 0.0;

                Interface_GetSignal_CameraStsforAHBC(& SignalValue);
                CameraStsforAHBC_Last = CameraStsforAHBC_Curr;
                CameraStsforAHBC_Curr = (uint8_t)SignalValue;

                if(CameraStsforAHBC_Last != 0xFFu && CameraStsforAHBC_Curr != 0xFFu) /* 需要前后值不是初始化值 */
                {
                    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& SignalValue);
                    UsageModeSts = (E_UsageModeSts)SignalValue;

                    VehSpdLgtE2ESts = GetE2EFlagForFailSafe();
                    Interface_GetSignal_VehSpdLgtA(& VehSpdLgtA);

                    if (VehSpdLgtE2ESts.E2EErrorFlagForFailSafe.bits.VehSpdCntErr  == 0u &&
                        VehSpdLgtE2ESts.E2EErrorFlagForFailSafe.bits.VehSpdCrcErr  == 0u &&
                        VehSpdLgtE2ESts.E2EErrorFlagForFailSafe.bits.VehSpdTimeout == 0u &&
                        VehSpdLgtA * 3.6 <= 4.0 &&
                        UsageModeSts == E_UsageModeSts_Drvg &&
                        CameraStsforAHBC_Last <= 2u && 
                        CameraStsforAHBC_Curr == 3u)
                    {
                        gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_ParamInit;
                        gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_ReferenceRun;
                    }
                }
            }
#endif

            /*SSDS:电机开路或者堵转后，电机不能动，直到下一个上电周期*/
            StepMotorAndHallError = Interface_GetStepMotorAndHallErrorState(E_ErrorType_ErrorDtcState);
            if (StepMotorAndHallError.bits.LevelMotor_OpenLoad == 1 || StepMotorAndHallError.bits.LevelMotor_OverLoad == 1)
            {
                gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_Error;
            }
        }
        break;
    case E_LevelingMotorState_Error:
        if (Interface_GetMotorMotionState(E_MotorTpye_Leveling) == E_MotorMotionState_Stop_Phase)
        {
            Interface_SetMotorCurrent(E_MotorTpye_Leveling, 0);
        }
        break;
    }
}

void LevelingMotorInit(void)
{
    gs_LevelingMotorInfo.ReferenceRunCompletedFlag = E_LvlReferenceRun_NotPerform;

    gs_LevelingMotorInfo.LevelingType = (E_LevelingType)Get_pVehLvLType();

    if (gs_LevelingMotorInfo.LevelingType == E_LVL_Not_Available || gs_LevelingMotorInfo.LevelingType == E_DCMotor)
    {
        return;
    }

    gs_LevelingMotorInfo.LevelingMotorMicroStepMode = (E_MotorMicroStepMode)Get_pLvlStepMode();

    if (Interface_GetMotorDevDrvState(E_MotorTpye_Leveling) == E_NOT_OK)
        gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_DevDrvTryInit;
    else
        gs_LevelingMotorInfo.LevelingMotorState = E_LevelingMotorState_AlgoInit;

    gs_LevelingMotorInfo.LevelingAlgorithm_SubMode_RefRun = E_SubMode_LvlRefRun_ParamInit;
}

