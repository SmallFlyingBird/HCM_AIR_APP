/********************************
 * DCMotor.c
 *
 *  Created on: 2024/7/17
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DCMotor.h"
#include "ComSignal_Interface.h"
#include "LinManager.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_DCMotorConfigInfo gs_DCMotorConfigInfo;
static S_DCMotorRunInfo gs_DCMotorRunInfo =
{
    .PosPwm_Last = 0u,
    .PosPwm_Curr = 0u,
    .HSDActSta = E_HSDActSta_NoAct,
    .LastStartupTime = 0u,
    .RunState = E_DCMotRunState_OFF,
    .ErrStatus.Status = 0u
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

/* 读取直流电机参数配置并存放  初始化用*/
static Std_ReturnType DCMotor_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;
    // gs_DCMotorConfigInfo.LvlType = (E_LvlType)Get_pVehLvLType();
    switch( GetChannelMaskByLightFunction(E_DC_Motor) )
    {
        case 0x0000:
            gs_DCMotorConfigInfo.HSChannel = E_HSChannel_HS0; /* 表示没有高边配置 */
            break;
        case 0x1000:
            gs_DCMotorConfigInfo.HSChannel = E_HSChannel_HS1;
            break;
    }
    gs_DCMotorConfigInfo.CntrlSCG     = Get_pDCMotrCntrlSCG();
    gs_DCMotorConfigInfo.CntrlSCB     = Get_pDCMotrCntrlSCB();
    gs_DCMotorConfigInfo.IOutStallHSD = Get_pIOutStallDCMotrHSD();
    gs_DCMotorConfigInfo.ManLvlDCPos1 = Get_pManLvlDCPos1();
    gs_DCMotorConfigInfo.ManLvlDCPos2 = Get_pManLvlDCPos2();
    gs_DCMotorConfigInfo.ManLvlDCPos3 = Get_pManLvlDCPos3();
    gs_DCMotorConfigInfo.ManLvlDCPos4 = Get_pManLvlDCPos4();
    gs_DCMotorConfigInfo.ManLvlDCPos5 = Get_pManLvlDCPos5();
    gs_DCMotorConfigInfo.LVLSafetyPos = Get_pLVLSafetyPosDC();
    gs_DCMotorConfigInfo.CntrlLowrThd = Get_pDCMotrCntrlLowrThd();
    gs_DCMotorConfigInfo.CntrlUpprThd = Get_pDCMotrCntrlUpprThd();
    gs_DCMotorConfigInfo.DeactDlyTi   = Get_pDCMotrDeactDlyTi();
    return rtval;
}

/* 直流电机调平运行 */
static Std_ReturnType DCMotor_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_DCMotorRunInfo.LastStartupTime < gs_DCMotorConfigInfo.DeactDlyTi)
    {
        gs_DCMotorRunInfo.LastStartupTime += timebase;
    }
    gs_DCMotorRunInfo.PosPwm_Last = gs_DCMotorRunInfo.PosPwm_Curr;

    uint32_t StsOfLedLoBeam;
    Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);

    /* 测试 */
    /* Interface_GetSignal_ActnOfLedPosnLamp(& StsOfLedLoBeam); */

    if(StsOfLedLoBeam == 0x1u)
    {
        if(gs_DCMotorRunInfo.ErrStatus.Status == 0u)
        {
            uint32_t LvlgSwtSetReq;

            Interface_GetSignal_LvlgSwtSetReqADModCtrlInhbn(& LvlgSwtSetReq);

            switch( LvlgSwtSetReq )
            {
                case 0u:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.LVLSafetyPos;
                    break;
                case 1u:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.ManLvlDCPos1;
                    break;
                case 2u:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.ManLvlDCPos2;
                    break;
                case 3u:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.ManLvlDCPos3;
                    break;
                case 4u:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.ManLvlDCPos4;
                    break;
                case 5u:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.ManLvlDCPos5;
            }
            gs_DCMotorRunInfo.HSDActSta = E_HSDActSta_Act;
            gs_DCMotorRunInfo.RunState = E_DCMotRunState_RUN;
        }
        else
        {

            if( gs_DCMotorRunInfo.ErrStatus.Bits.HSDHW   == 1u ||
                gs_DCMotorRunInfo.ErrStatus.Bits.Stall   == 1u ||
                gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine == 1u ) /* 电压故障无需处理和反馈 */
            {
                gs_DCMotorRunInfo.HSDActSta = E_HSDActSta_NoAct;
                gs_DCMotorRunInfo.PosPwm_Curr = 0u;
                gs_DCMotorRunInfo.RunState = E_DCMotRunState_ERR;
            }
            else if(gs_DCMotorRunInfo.ErrStatus.Bits.Signal == 1u)
            {
                gs_DCMotorRunInfo.HSDActSta = E_HSDActSta_Act;
                gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.LVLSafetyPos;
                gs_DCMotorRunInfo.RunState = E_DCMotRunState_ERR;
            }
        }
        if(gs_DCMotorRunInfo.PosPwm_Last != gs_DCMotorRunInfo.PosPwm_Curr)
        {
            gs_DCMotorRunInfo.LastStartupTime = 0u;
        }
    }
    else
    {
        if(gs_DCMotorRunInfo.LastStartupTime >= gs_DCMotorConfigInfo.DeactDlyTi) /* 关闭高边之前需要等待上次启动完成 */
        {
            gs_DCMotorRunInfo.HSDActSta = E_HSDActSta_NoAct;
            gs_DCMotorRunInfo.PosPwm_Curr = 0u;
        }
        gs_DCMotorRunInfo.ErrStatus.Status = 0u; /* 清除所有故障 */
        gs_DCMotorRunInfo.RunState = E_DCMotRunState_OFF;
    }
    HSDManage_SetHSDActState(gs_DCMotorConfigInfo.HSChannel, gs_DCMotorRunInfo.HSDActSta);
    Interface_EnablePulseGenerator(E_PulseGeneratorFunction_DCMotor, DCMOTOR_PWM_CYCLE, gs_DCMotorRunInfo.PosPwm_Curr);
    return rtval;
}

/* 直流电机堵转检测 */
static Std_ReturnType DCMotor_StallDiagnose(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_DCMotorRunInfo.HSDActSta == E_HSDActSta_Act)
    {
        static uint8_t s_DCMotStallComformNum = 0u; /* 堵转确认计数 */

        if(HSDManage_GetHSDOutputCurrent(gs_DCMotorConfigInfo.HSChannel) > gs_DCMotorConfigInfo.IOutStallHSD)
        {
            if(s_DCMotStallComformNum < 2u)
                s_DCMotStallComformNum++;
        }
        else
        {
            if(s_DCMotStallComformNum > 0u)
                s_DCMotStallComformNum--;
        }
        if(s_DCMotStallComformNum >= 2u)
        {
            gs_DCMotorRunInfo.ErrStatus.Bits.Stall = 1u;
            s_DCMotStallComformNum = 0u;
        }
    }
    return rtval;
}

/* 直流电机高边和信号故障检测 */
static Std_ReturnType DCMotor_HsdAndSigErrDetect(void)
{
    Std_ReturnType rtval = E_OK;
    if(gs_DCMotorRunInfo.RunState != E_DCMotRunState_OFF)
    {
        E_HSDErrSta DCMotHSDErrSta;
        S_E2EStateForFailSafe SignalE2EState;

        DCMotHSDErrSta = HSDManage_GetHSDErrState(gs_DCMotorConfigInfo.HSChannel);
        SignalE2EState = GetE2EFlagForFailSafe();

        switch( DCMotHSDErrSta )
        {
            case E_HSDErrSta_Normal:
                gs_DCMotorRunInfo.ErrStatus.Bits.HSDVolt = 0u;
                gs_DCMotorRunInfo.ErrStatus.Bits.HSDHW = 0u;
                break;
            case E_HSDErrSta_VoltErr:
                gs_DCMotorRunInfo.ErrStatus.Bits.HSDVolt = 1u;
                break;
            case E_HSDErrSta_HWRTErr:
            case E_HSDErrSta_HWDtcErr:
                gs_DCMotorRunInfo.ErrStatus.Bits.HSDHW = 1u;
        }
        // if( SignalE2EState.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqCrcErr == 1u ||
        //     SignalE2EState.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqTimeout == 1u || 
        //     Interface_GetBusOffFlag() == 1u)
        // {
        //     gs_DCMotorRunInfo.ErrStatus.Bits.Signal = 1u;
        // }
        // else
        // {
        //     gs_DCMotorRunInfo.ErrStatus.Bits.Signal = 0u;
        // }
    }
    return rtval;
}

/* 直流电机控制线DTC检测设置 */
static Std_ReturnType DCMotor_CtrLineDtcErrDetect(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_DCMotorRunInfo.HSDActSta == E_HSDActSta_Act)
    {
        E_AdcAccuracy AdcAccuracy;
        uint32_t AdcDigitalValue;
        static double DCMotorCtrLineVoltage; /* AD采集的电压 */

        rtval |= Interface_GetAdcAccuracy(E_AdcFunction_FanCtr, & AdcAccuracy);
        rtval |= Interface_GetAdcDigitalValue(E_AdcFunction_DcCtr, & AdcDigitalValue);
        if(rtval != E_OK)
        {
            return rtval;
        }

        switch( AdcAccuracy )
        {
            case E_AdcAccuracy_Bit8:
                DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0xFFu;
                break;
            case E_AdcAccuracy_Bit10:
                DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0x3FFu;
                break;
            case E_AdcAccuracy_Bit12:
                DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0xFFFu;
                break;
            case E_AdcAccuracy_Bit24:
                DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0xFFFFFFu;
                break;
            case E_AdcAccuracy_Bit32:
                DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0xFFFFFFFFu;
        }

        double CalculateVoltValue;
        double DetectVoltValue;
        double VoltDifferValue;
        static uint8_t s_CtrLineErrNum = 0u;

        CalculateVoltValue = HSDManage_GetHSDSupplyVoltage() * (57.0 / 61.0) * gs_DCMotorRunInfo.PosPwm_Last / 100 ;
        DetectVoltValue = DCMotorCtrLineVoltage * 57.0 / 10;
        VoltDifferValue = CalculateVoltValue >= DetectVoltValue ? CalculateVoltValue - DetectVoltValue : DetectVoltValue - CalculateVoltValue;

        if(VoltDifferValue > 1.0)
        {
            if(s_CtrLineErrNum < 10u)
                s_CtrLineErrNum++;
        }
        else
        {
            if(s_CtrLineErrNum > 0u)
                s_CtrLineErrNum--;
        }
        if(s_CtrLineErrNum >= 10u)
        {
            gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine = 1u;
            s_CtrLineErrNum = 0u;
        }
    }
    if(gs_DCMotorRunInfo.RunState == E_DCMotRunState_RUN || gs_DCMotorRunInfo.RunState == E_DCMotRunState_ERR)
    {
        if(gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine == 1u)
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 1u);
        }
        else if(gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine == 0u)
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 0u);
        }
    }
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/


/* 直流电机启动初始化 */
void DCMotor_Init(void)
{
    DCMotor_GetParameterIntoInfo();
}

#include "Pwm_Cfg.h"
#include "Dio.h"
#include "Pwm.h"

/* 直流电机主函数 */
void DCMotor_MainFunction(uint8_t timebase)
{
    uint8 dcmorena=0;
    dcmorena=Get_DCMotor_Signal();
    if(1==dcmorena)
    {
        static uint16_t Cycle = 0;
        static uint8_t Direction = 0;

        switch( Cycle )
        {
            case 0u:
                Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0);//0x4899U);//0x1999 约等于20%   //0x3399空载50V
                break;
            case 100u:
                Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0x8000*0.2);
                break;
            case 200u:
                Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0x8000*0.4);
                break;
            case 300u:
                Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0x8000*0.6);
                break;
            case 400u:
                Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0x8000*0.8);
                break;
            case 500u:
                Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0x8000);
                break;
        }
        if (Cycle == 0)
        {
            Direction = 0;
        }
        else if(Cycle == 500)
        {
            Direction = 1;
        }
        if (Direction == 0)
        {
            Cycle++;
        }
        else if (Direction == 1)
        {
            Cycle--;
        }
    }
}


