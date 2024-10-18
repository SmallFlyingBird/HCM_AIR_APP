/********************************
 * MotorManage.c
 *
 *  Created on: 2024/7/18
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "MotorManage.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_LvlConfigInfo gs_LvlConfigInfo;
static S_SvlConfigInfo gs_SvlConfigInfo;

static S_LvlRunInfo gs_LvlRunInfo =
{
    .PosIncre_AHB2  = 0,
    .PosIncre_TrMod = 0,
    .PosIncre_AFS   = 0,
    .PosIncre_MHL   = 0,
    .PosIncre_AHL   = 0,
    .PosCoord_Need  = 0,
    .PosCoord_Real  = 0,
    .FuncErrSta.ErrSta = 0,
    .FuncActSta.ActSta = 0
};

static S_SvlRunInfo gs_SvlRunInfo =
{
    .PosIncre_AFS  = 0,
    .PosIncre_DBL  = 0,
    .PosCoord_Need = 0,
    .PosCoord_Real = 0,
    .FuncErrSta.ErrSta = 0,
    .FuncActSta.ActSta = 0
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

/* 读取电机参数配置并存放 */
static void MotorManage_GetParameterIntoInfo(void)
{
    gs_LvlConfigInfo.LvlType = (E_LvlType)Get_pVehLvLType();

    gs_LvlConfigInfo.HsPerRad = Get_pLvlHsPerRad();
    gs_LvlConfigInfo.StepMode = Get_pLvlStepMode();

    gs_LvlConfigInfo.Safetypos = Get_pLVLSafetyposHS() * (gs_LvlConfigInfo.StepMode / 2);

#if HCM_LEFT_SIDE
    gs_LvlConfigInfo.DfltPos = Get_LeLamp_pLvlDfltPosLe() * (gs_LvlConfigInfo.StepMode / 2);
    gs_LvlConfigInfo.BotPos = Get_LeLamp_pLvlBotPos() * (gs_LvlConfigInfo.StepMode / 2);
    gs_LvlConfigInfo.TopPos = Get_LeLamp_pLvlTopPos() * (gs_LvlConfigInfo.StepMode / 2);
#elif HCM_RIGHT_SIDE
    gs_LvlConfigInfo.DfltPos = Get_RiLamp_pLvlDfltPosRi() * (gs_LvlConfigInfo.StepMode / 2);
    gs_LvlConfigInfo.BotPos = Get_RiLamp_pLvlBotPos() * (gs_LvlConfigInfo.StepMode / 2);
    gs_LvlConfigInfo.TopPos = Get_RiLamp_pLvlTopPos() * (gs_LvlConfigInfo.StepMode / 2);
#endif

    gs_LvlConfigInfo.MinDistStart = Get_pLvlMinDistStart() * (gs_LvlConfigInfo.StepMode / 2);
    gs_LvlConfigInfo.MinDistTime = Get_pLvlMinDistTime();
    gs_LvlConfigInfo.LvlOffset = Get_pLVLOffset() * (gs_LvlConfigInfo.StepMode / 2);

    gs_LvlConfigInfo.UsageInterval = Get_pLvlUsageInterval() * 1000;

/***********************************************************************************************/

    gs_SvlConfigInfo.DBLType = (E_DBLType)Get_pVehDBLType();

    gs_SvlConfigInfo.HsPerRad = Get_pSvlHsPerRad();
    gs_SvlConfigInfo.StepMode = Get_pSvlStepMode();

    gs_SvlConfigInfo.DfltPos = Get_pSvlDfltPos() * (gs_SvlConfigInfo.StepMode / 2);

#if HCM_LEFT_SIDE
    gs_SvlConfigInfo.LePos = Get_LeLamp_SvlLeftLogicPos() * (gs_SvlConfigInfo.StepMode / 2);
    gs_SvlConfigInfo.RiPos = Get_LeLamp_SvlRightLogicPos() * (gs_SvlConfigInfo.StepMode / 2);
#elif HCM_RIGHT_SIDE
    gs_SvlConfigInfo.LePos = Get_RiLamp_SvlLeftLogicPos() * (gs_SvlConfigInfo.StepMode / 2);
    gs_SvlConfigInfo.RiPos = Get_RiLamp_SvlRightLogicPos() * (gs_SvlConfigInfo.StepMode / 2);
#endif

    gs_SvlConfigInfo.MinDistStart = Get_pSvlMinDistStart() * (gs_SvlConfigInfo.StepMode / 2);
    gs_SvlConfigInfo.MinDistTime = Get_pSvlMinDistTime();

    gs_SvlConfigInfo.UsageInterval = Get_pSvlUsageInterval() * 1000;
    gs_SvlConfigInfo.LossToDflt = (E_SvlLossToDflt)Get_pFssRelFailSvlDflt();
}


/* 获取电源供电数量 */
static uint8_t MotorManage_GetHCMSupplyNum(void)
{
    uint8_t HCMSupplyNum = 0;

    U_SupplyVoltage_Error SupplyVoltErr;

    SupplyVoltErr = Interface_GetSupplyVoltageErrorState(E_ErrorType_ErrorDtcState);
    if( SupplyVoltErr.bits.KL15_SHORT2GND_OPEN_ErrorConfirmed == 1u ||
        SupplyVoltErr.bits.KL56_SHORT2GND_OPEN_ErrorConfirmed == 1u )
    {
        HCMSupplyNum = 1u;
    }
    else
    {
        HCMSupplyNum = 2u;
    }
    return HCMSupplyNum;
}

/* 限制位置坐标范围 */
static sint16_t MotorManage_LimitPositionCoord(sint16_t PosCoord, sint16_t PositivePos, sint16_t NegativePos)
{
    if(PosCoord > PositivePos)
    {
        PosCoord = PositivePos;
    }
    else if(PosCoord < NegativePos)
    {
        PosCoord = NegativePos;
    }
    return PosCoord;
}

/* Leveling电机运行 */
static Std_ReturnType MotorManage_LevelingRun(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    uint8_t HCMSupplyNumber = 0;

    HCMSupplyNumber = MotorManage_GetHCMSupplyNum();

    if(gs_LvlRunInfo.FuncErrSta.ErrSta == 0u && HCMSupplyNumber == 2u)
    {
        gs_LvlRunInfo.PosCoord_Need = gs_LvlRunInfo.PosIncre_AHB2 +
                                      gs_LvlRunInfo.PosIncre_TrMod +
                                      gs_LvlRunInfo.PosIncre_AFS +
                                      gs_LvlRunInfo.PosIncre_MHL +
                                      gs_LvlRunInfo.PosIncre_AHL +
                                      gs_LvlConfigInfo.LvlOffset +
                                      gs_LvlConfigInfo.DfltPos;

        gs_LvlRunInfo.PosCoord_Need = MotorManage_LimitPositionCoord(gs_LvlRunInfo.PosCoord_Need, gs_LvlConfigInfo.TopPos, gs_LvlConfigInfo.BotPos);
    }
    else
    {
        gs_LvlRunInfo.PosCoord_Need = gs_LvlConfigInfo.Safetypos;
        gs_LvlRunInfo.PosCoord_Real = gs_LvlRunInfo.PosCoord_Need;
    }

    static uint8_t LvlMotorStopTime = 0;
    if(Interface_GetMotorMotionState(E_MotorTpye_Leveling) == E_MotorMotionState_Stop_Phase) /* 电机停止时间累计，用于考虑最低启动步数 */
    {
        if(LvlMotorStopTime < gs_LvlConfigInfo.MinDistTime)
            LvlMotorStopTime += timebase;
    }
    else
    {
        LvlMotorStopTime = 0;
    }

    uint16_t PosDiff;

    PosDiff = gs_LvlRunInfo.PosCoord_Need >= gs_LvlRunInfo.PosCoord_Real ?
              (uint16_t)(gs_LvlRunInfo.PosCoord_Need - gs_LvlRunInfo.PosCoord_Real) :
              (uint16_t)(gs_LvlRunInfo.PosCoord_Real - gs_LvlRunInfo.PosCoord_Need);

    if(LvlMotorStopTime >= gs_LvlConfigInfo.MinDistTime)
    {
        if(PosDiff > gs_LvlConfigInfo.MinDistStart)
        {
            gs_LvlRunInfo.PosCoord_Real = gs_LvlRunInfo.PosCoord_Need;
        }
    }
    else
    {
        gs_LvlRunInfo.PosCoord_Real = gs_LvlRunInfo.PosCoord_Need;
    }
    Interface_SetMotorPosition(E_MotorTpye_Leveling, gs_LvlRunInfo.PosCoord_Real);

    return rtval;
}

/* Swiveling电机运行 */
static Std_ReturnType MotorManage_SwivelingRun(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    uint8_t HCMSupplyNumber = 0;

    switch( gs_SvlConfigInfo.LossToDflt )
    {
        case E_SvlLossToDflt_No:
            HCMSupplyNumber = 2u;
            break;
        case E_SvlLossToDflt_Yes:
            HCMSupplyNumber = MotorManage_GetHCMSupplyNum();
    }

    if(gs_SvlRunInfo.FuncErrSta.ErrSta == 0u && HCMSupplyNumber == 2u)
    {
        gs_SvlRunInfo.PosCoord_Need = gs_SvlRunInfo.PosIncre_AFS +
                                      gs_SvlRunInfo.PosIncre_DBL +
                                      gs_SvlConfigInfo.DfltPos;

        gs_SvlRunInfo.PosCoord_Need = MotorManage_LimitPositionCoord(gs_SvlRunInfo.PosCoord_Need, gs_SvlConfigInfo.RiPos, gs_SvlConfigInfo.LePos);
    }
    else
    {
        gs_SvlRunInfo.PosCoord_Need = gs_SvlConfigInfo.DfltPos;
        gs_SvlRunInfo.PosCoord_Real = gs_SvlRunInfo.PosCoord_Need;
    }

    static uint8_t SvlMotorStopTime = 0;
    if(Interface_GetMotorMotionState(E_MotorTpye_Swiveling) == E_MotorMotionState_Stop_Phase) /* 电机停止时间累计，用于考虑最低启动步数 */
    {
        if(SvlMotorStopTime < gs_SvlConfigInfo.MinDistTime)
            SvlMotorStopTime += timebase;
    }
    else
    {
        SvlMotorStopTime = 0;
    }

    uint16_t PosDiff;

    PosDiff = gs_SvlRunInfo.PosCoord_Need >= gs_SvlRunInfo.PosCoord_Real ?
              (uint16_t)(gs_SvlRunInfo.PosCoord_Need - gs_SvlRunInfo.PosCoord_Real) :
              (uint16_t)(gs_SvlRunInfo.PosCoord_Real - gs_SvlRunInfo.PosCoord_Need);

    if(SvlMotorStopTime >= gs_SvlConfigInfo.MinDistTime)
    {
        if(PosDiff > gs_SvlConfigInfo.MinDistStart)
        {
            gs_SvlRunInfo.PosCoord_Real = gs_SvlRunInfo.PosCoord_Need;
        }
    }
    else
    {
        gs_SvlRunInfo.PosCoord_Real = gs_SvlRunInfo.PosCoord_Need;
    }
    Interface_SetMotorPosition(E_MotorTpye_Swiveling, gs_SvlRunInfo.PosCoord_Real);
    return rtval;
}


/* Leveling电机故障检测 */
static Std_ReturnType MotorManage_LevelingFaultDetection(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    S_E2EStateForFailSafe SignalE2EState;
    uint8_t VehSpdSigErrSta;

    /* 车速信号故障检测 */
    uint32_t VehSpdLgtQf;
    SignalE2EState = GetE2EFlagForFailSafe();
    Interface_GetSignal_VehSpdLgtQf(& VehSpdLgtQf);
    if( SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdTimeout == 1 ||
        SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdCntErr == 1  ||
        SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdCrcErr == 1  ||
        VehSpdLgtQf < 2u ||
        Interface_GetBusOffFlag() == 1u )
    {
        VehSpdSigErrSta = 1u;
    }
    else
    {
        VehSpdSigErrSta = 0u;
    }

    if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_AHB2 == 1u)
    {
        if(VehSpdSigErrSta == 1u)
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AHB2  = 1u;
        }
        else
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AHB2  = 0u;
        }
    }
    else if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_AHB2 == 0u)
    {
        gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AHB2  = 0u;
    }
    if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_TrMod == 1u)
    {
        if(VehSpdSigErrSta == 1u)
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_TrMod = 1u;
        }
        else
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_TrMod = 0u;
        }
    }
    else if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_TrMod == 0u)
    {
        gs_LvlRunInfo.FuncErrSta.Bits.SigErr_TrMod  = 0u;
    }
    if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_AFS == 1u)
    {
        if(VehSpdSigErrSta == 1u)
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AFS   = 1u;
        }
        else
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AFS   = 0u;
        }
    }
    else if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_AFS == 0u)
    {
        gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AFS  = 0u;
    }
    if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_MHL == 1u)
    {
        if( VehSpdSigErrSta == 1u ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqCrcErr == 1u ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqTimeout == 1u )
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_MHL   = 1u;
        }
        else
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_MHL   = 0u;
        }
        Interface_EnableLvlgSwtSetReq_CRC_Detect();
    }
    else if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_MHL == 0u)
    {
        gs_LvlRunInfo.FuncErrSta.Bits.SigErr_MHL   = 0u;
        Interface_DisableLvlgSwtSetReq_CRC_Detect();
    }
    if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_AHL == 1u)
    {
        uint32_t SuspPosnVertLvlFrntQf;
        uint32_t SuspPosnVertLvlReQf;
        Interface_GetSignal_SuspPosnVertLvlFrntQf(& SuspPosnVertLvlFrntQf);
        Interface_GetSignal_SuspPosnVertLvlReQf(& SuspPosnVertLvlReQf);

        if( VehSpdSigErrSta == 1u ||
            SuspPosnVertLvlFrntQf == 0u ||
            SuspPosnVertLvlReQf == 0u )
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AHL   = 1u;
        }
        else
        {
            gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AHL   = 0u;
        }
        Interface_EnableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect();
    }
    else if(gs_LvlRunInfo.FuncActSta.Bits.ActSta_AHL == 0u)
    {
        gs_LvlRunInfo.FuncErrSta.Bits.SigErr_AHL   = 0u;
        Interface_DisableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect();
    }

    /* 电机故障检测 */
    static uint8_t LvlFixedErrFlag = 0u;
    U_StepMotorAndHall_Error LvlErrorStatus;
    LvlErrorStatus = Interface_GetStepMotorAndHallErrorState(E_ErrorType_ErrorRealTimeState);
    if( LvlErrorStatus.bits.LevelMotor_OverLoad == 1u ||
        LvlErrorStatus.bits.LevelMotor_OpenLoad == 1u ||
        LvlErrorStatus.bits.LevelMotor_InterError == 1u ||
        LvlErrorStatus.bits.LevelMotor_StepLoss == 1u ) /* 不可恢复 */
    {
        gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AHB2  = 1u;
        gs_LvlRunInfo.FuncErrSta.Bits.MotErr_TrMod = 1u;
        gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AFS   = 1u;
        gs_LvlRunInfo.FuncErrSta.Bits.MotErr_MHL   = 1u;
        gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AHL   = 1u;
        LvlFixedErrFlag = 1u;
    }
    if(LvlFixedErrFlag == 0u)
    {
        /* 电机过度使用，禁用5s */
        static uint32_t LvlWindowTime = 0u;
        static uint16_t LvlForbidTime = 5000u;

        LvlWindowTime += timebase;
        if(LvlWindowTime >= gs_LvlConfigInfo.UsageInterval)
        {
            if(LvlErrorStatus.bits.LevelMotor_OverUse == 1u)
            {
                LvlForbidTime = 0u;
            }
            LvlWindowTime = 0u;
        }
        if(LvlForbidTime < 5000u)
        {
            LvlForbidTime += timebase;
        }
        else
        {
            LvlErrorStatus.bits.LevelMotor_OverUse = 0u;
        }

        if(LvlErrorStatus.bits.LevelMotor_OverUse == 1u)
        {
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AHB2  = 1u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_TrMod = 1u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AFS   = 1u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_MHL   = 1u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AHL   = 1u;
        }
        else
        {
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AHB2  = 0u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_TrMod = 0u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AFS   = 0u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_MHL   = 0u;
            gs_LvlRunInfo.FuncErrSta.Bits.MotErr_AHL   = 0u;
        }
    }
    return rtval;
}

/* Swiveling电机故障检测 */
static Std_ReturnType MotorManage_SwivelingFaultDetection(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    S_E2EStateForFailSafe SignalE2EState;
    uint8_t VehSpdSigErrSta;

    /* 车速信号故障检测 */
    uint32_t VehSpdLgtQf;
    SignalE2EState = GetE2EFlagForFailSafe();
    Interface_GetSignal_VehSpdLgtQf(& VehSpdLgtQf);
    if( SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdTimeout == 1 ||
        SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdCntErr == 1  ||
        SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdCrcErr == 1  ||
        VehSpdLgtQf < 2 ||
        Interface_GetBusOffFlag() == 1u )
    {
        VehSpdSigErrSta = 1u;
    }
    else
    {
        VehSpdSigErrSta = 0u;
    }

    if(gs_SvlRunInfo.FuncActSta.Bits.ActSta_AFS == 1u)
    {
        if(VehSpdSigErrSta == 1u)
        {
            gs_SvlRunInfo.FuncErrSta.Bits.SigErr_AFS = 1u;
        }
        else
        {
            gs_SvlRunInfo.FuncErrSta.Bits.SigErr_AFS = 0u;
        }
    }
    else if(gs_SvlRunInfo.FuncActSta.Bits.ActSta_AFS == 0u)
    {
        gs_SvlRunInfo.FuncErrSta.Bits.SigErr_AFS = 0u;
    }
    if(gs_SvlRunInfo.FuncActSta.Bits.ActSta_DBL == 1u)
    {
        uint32_t SteerWhlSnsrQf;
        Interface_GetSignal_SteerWhlSnsrQf(& SteerWhlSnsrQf);

        if( VehSpdSigErrSta == 1u ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.SteerWhlSnsrTimeout == 1 ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.SteerWhlSnsrCntErr == 1  ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.SteerWhlSnsrCrcErr == 1  ||
            SteerWhlSnsrQf == 0u )
        {
            gs_SvlRunInfo.FuncErrSta.Bits.SigErr_DBL = 1u;
        }
        else
        {
            gs_SvlRunInfo.FuncErrSta.Bits.SigErr_DBL = 0u;
        }
        Interface_EnableSteerWhlSnsr_QF_Detect();
    }
    else if(gs_SvlRunInfo.FuncActSta.Bits.ActSta_DBL == 0u)
    {
        gs_SvlRunInfo.FuncErrSta.Bits.SigErr_DBL = 0u;
        Interface_DisableSteerWhlSnsr_QF_Detect();
    }

    /* 电机故障检测 */
    static uint8_t SvlFixedErrFlag = 0;
    U_StepMotorAndHall_Error SvlErrorStatus;
    SvlErrorStatus = Interface_GetStepMotorAndHallErrorState(E_ErrorType_ErrorRealTimeState);
    if( SvlErrorStatus.bits.SwivelMotor_OverLoad == 1u ||
        SvlErrorStatus.bits.SwivelMotor_OpenLoad == 1u ||
        SvlErrorStatus.bits.SwivelMotor_InterError == 1u ||
        SvlErrorStatus.bits.SwivelMotor_StepLoss == 1u ) /* 不可恢复 */
    {
        gs_SvlRunInfo.FuncErrSta.Bits.MotErr_AFS = 1u;
        gs_SvlRunInfo.FuncErrSta.Bits.MotErr_DBL = 1u;
        SvlFixedErrFlag = 1u;
    }
    if(SvlFixedErrFlag == 0u)
    {
        /* 电机过度使用，禁用5s */
        static uint32_t SvlWindowTime = 0u;
        static uint16_t SvlForbidTime = 5000u;

        SvlWindowTime += timebase;
        if(SvlWindowTime >= gs_SvlConfigInfo.UsageInterval)
        {
            if(SvlErrorStatus.bits.SwivelMotor_OverUse == 1u)
            {
                SvlForbidTime = 0u;
            }
            SvlWindowTime = 0u;
        }
        if(SvlForbidTime < 5000u)
        {
            SvlForbidTime += timebase;
        }
        else
        {
            SvlErrorStatus.bits.SwivelMotor_OverUse = 0u;
        }

        if(SvlErrorStatus.bits.SwivelMotor_OverUse == 1u)
        {
            gs_SvlRunInfo.FuncErrSta.Bits.MotErr_AFS = 1u;
            gs_SvlRunInfo.FuncErrSta.Bits.MotErr_DBL = 1u;
        }
        else
        {
            gs_SvlRunInfo.FuncErrSta.Bits.MotErr_AFS = 0u;
            gs_SvlRunInfo.FuncErrSta.Bits.MotErr_DBL = 0u;
        }
    }
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 任意位长度有符号数 转 32位有符号数 */
sint32_t MotorManage_ConvertSigned_xToSigned_32(uint32_t Data, uint8_t BitSize)
{
    uint8_t i;

    if(Data & (1 << (BitSize - 1))) /* 负数 */
    {
        for(i = 0; i < 32 - BitSize; i++) /* 只需把所有多出的高位置1 */
        {
            Data |= 1 << (BitSize + i);
        }
    }
    return Data;
}

/* Leveling电机，大灯上下角度增量 转 电机位置增量 */
/* AngleIncre：单位rad */
sint16_t MotorManage_LvlConvertAglIncreToPosIncre(double AngleIncre)
{
    return (sint16_t)(AngleIncre * gs_LvlConfigInfo.HsPerRad * (gs_LvlConfigInfo.StepMode / 2)); /* 返回位置偏移量 */
}

/* Swiveling电机，大灯左右角度增量 转 电机位置增量 */
/* AngleIncre：单位rad */
sint16_t MotorManage_SvlConvertAngleIncreToPosIncre(double AngleIncre)
{
    return (sint16_t)(AngleIncre * gs_SvlConfigInfo.HsPerRad * (gs_SvlConfigInfo.StepMode / 2)); /* 返回位置偏移量 */
}


/* 设置Leveling电机位置增量 */
void MotorManage_SetLevelingPosIncre(E_LvlFunction LvlFunction, sint16_t PosIncre)
{
    switch( LvlFunction )
    {
        case E_LvlFunction_AHB2:
            gs_LvlRunInfo.PosIncre_AHB2 = PosIncre;
            break;
        case E_LvlFunction_TrMod:
            gs_LvlRunInfo.PosIncre_TrMod = PosIncre;
            break;
        case E_LvlFunction_AFS:
            gs_LvlRunInfo.PosIncre_AFS = PosIncre;
            break;
        case E_LvlFunction_MHL:
            gs_LvlRunInfo.PosIncre_MHL = PosIncre;
            break;
        case E_LvlFunction_AHL:
            gs_LvlRunInfo.PosIncre_AHL = PosIncre;
    }
}

/* 设置Swiveling电机位置增量 */
void MotorManage_SetSwivelingPosIncre(E_SvlFunction SvlFunction, sint16_t PosIncre)
{
    switch( SvlFunction )
    {
        case E_SvlFunction_AFS:
            gs_SvlRunInfo.PosIncre_AFS = PosIncre;
            break;
        case E_SvlFunction_DBL:
            gs_SvlRunInfo.PosIncre_DBL = PosIncre;
    }
}

/* 获取Leveling电机功能错误状态 */
U_LvlFuncErrSta MotorManage_GetLevelingFuncErrorState(void)
{
    return gs_LvlRunInfo.FuncErrSta;
}

/* 获取Swiveling电机功能错误状态*/
U_SvlFuncErrSta MotorManage_GetSwivelingFuncErrorState(void)
{
    return gs_SvlRunInfo.FuncErrSta;
}

/* 设置Leveling电机功能开启状态 */
void MotorManage_SetLevelingFuncActState(E_LvlFunction LvlFunction, uint8_t Value)
{
    switch( LvlFunction )
    {
        case E_LvlFunction_AHB2:
            gs_LvlRunInfo.FuncActSta.Bits.ActSta_AHB2 = Value;
            break;
        case E_LvlFunction_TrMod:
            gs_LvlRunInfo.FuncActSta.Bits.ActSta_TrMod = Value;
            break;
        case E_LvlFunction_AFS:
            gs_LvlRunInfo.FuncActSta.Bits.ActSta_AFS = Value;
            break;
        case E_LvlFunction_MHL:
            gs_LvlRunInfo.FuncActSta.Bits.ActSta_MHL = Value;
            break;
        case E_LvlFunction_AHL:
            gs_LvlRunInfo.FuncActSta.Bits.ActSta_AHL = Value;
    }
}

/* 设置Swiveling电机功能开启状态*/
void MotorManage_SetSwivelingFuncActState(E_SvlFunction SvlFunction, uint8_t Value)
{
    switch( SvlFunction )
    {
        case E_SvlFunction_AFS:
            gs_SvlRunInfo.FuncActSta.Bits.ActSta_AFS = Value;
            break;
        case E_SvlFunction_DBL:
            gs_SvlRunInfo.FuncActSta.Bits.ActSta_DBL = Value;
    }
}

/* 电机管理初始化 */
void MotorManage_Init(void)
{
    MotorManage_GetParameterIntoInfo();
}

#if MOTORMANAGE_TEST
uint8_t test_level_autorun = 1;
uint8_t test_swive_autorun = 1;
#endif

/* 电机管理主函数 */
void MotorManage_MainFunction(uint8_t timebase)
{
    if( gs_LvlConfigInfo.LvlType == E_LvlType_MHL ||
        gs_LvlConfigInfo.LvlType == E_LvlType_AHL ) /* 有Leveling电机 */
    {
        if(LevelingMotor_GetLvlRefRunSts() == E_LvlRefRunSts_Done && LevelingMotor_GetLvlMotorRunMode() == 0u) /* 需要参考运行完成 */
        {
#if (EMC_TEST_ENABLE == 0)
            MotorManage_LevelingFaultDetection(timebase);
#endif  /*(EMC_TEST_ENABLE == 0)*/
            MotorManage_LevelingRun(timebase);

#if (OEM_PLATFORM == OEM_SMART)
            double LvlMotorAngle;

            LvlMotorAngle = (double)gs_LvlRunInfo.PosCoord_Real / (gs_LvlConfigInfo.StepMode / 2) / gs_LvlConfigInfo.HsPerRad * DEG_PER_RAD;
            Interface_SetSignal_LvlgMtrAgle((uint32_t)((LvlMotorAngle + 5.0) * 50.0)); /* 反馈当前LVL电机角度 */
#endif
        }
#if (OEM_PLATFORM == OEM_SMART)
        else
        {
            Interface_SetSignal_LvlgMtrAgle((uint32_t)((0.0 + 5.0) * 50.0)); /* 反馈当前LVL电机角度 */
        }
#endif
    }
#if (OEM_PLATFORM == OEM_SMART)
    else
    {
        Interface_SetSignal_LvlgMtrAgle((uint32_t)((0.0 + 5.0) * 50.0)); /* 反馈当前LVL电机角度 */
    }
#endif

    if( gs_SvlConfigInfo.DBLType == E_DBLType_MotorWoHall ||
        gs_SvlConfigInfo.DBLType == E_DBLType_MotorWiHall ||
        gs_SvlConfigInfo.DBLType == E_DBLType_MotorWoHallWiCL ||
        gs_SvlConfigInfo.DBLType == E_DBLType_MotorWiHallWiCL )  /* 有Swiveling电机 */
    {
        if(SwivelingMotor_GetSvlRefRunSts() == E_SvlRefRunSts_Done && SwivelingMotor_GetSvlMotorRunMode() == 0u) /* 需要参考运行完成 */
        {
#if (EMC_TEST_ENABLE == 0)
            MotorManage_SwivelingFaultDetection(timebase);
#endif  /*(EMC_TEST_ENABLE == 0)*/
            MotorManage_SwivelingRun(timebase);
        }
    }

#if USAGEMODE_TEST
    Interface_SetSignal_VehModMngtGlbSafe1UsgModSts(11u);
#endif

#if MOTORMANAGE_TEST
        static sint16_t LevelingMotorPosTest = 0;
        static uint8_t Direction = 0;
        if (LevelingMotorPosTest == -200)
        {
            Direction = 0;
        }
        else if(LevelingMotorPosTest == 200)
        {
            Direction = 1;
        }
        if (Direction == 0)
        {
            LevelingMotorPosTest++;
        }
        else if (Direction == 1)
        {
            LevelingMotorPosTest--;
        }

        if (Direction == 0)
        {
            if (test_level_autorun)
            {MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, 700);}
            if (test_swive_autorun)
            {MotorManage_SetSwivelingPosIncre(E_SvlFunction_DBL, 700);}
        }
        else if (Direction == 1)
        {
            if (test_level_autorun)
            { MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, -700);}
            if (test_swive_autorun)
            {MotorManage_SetSwivelingPosIncre(E_SvlFunction_DBL, -700);}
        }

        uint32_t ActnOfLedLoBeam;
        Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam(& ActnOfLedLoBeam);
        if(ActnOfLedLoBeam == 1u)
        {
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, 0);
            MotorManage_SetSwivelingPosIncre(E_SvlFunction_DBL, 0);
        }
#endif
}



