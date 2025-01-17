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
#include "LinManager.h"
#include "Com.h"

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
    
    gs_DCMotorConfigInfo.HSChannel = E_HSChannel_HS1;
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
    uint8 StsOfLedLoBeam=0;
    uint8 LvlgSwtSetReq=0;
    uint8 dcswitch=0;
    if(gs_DCMotorRunInfo.LastStartupTime < gs_DCMotorConfigInfo.DeactDlyTi)
    {
        gs_DCMotorRunInfo.LastStartupTime += timebase;
    }
    gs_DCMotorRunInfo.PosPwm_Last = gs_DCMotorRunInfo.PosPwm_Curr;

	StsOfLedLoBeam=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedLoBeamActnOfLedLoBeam;

	#ifdef LeftAir
	dcswitch = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.ClrDTCOfLINHCML2;
	#endif
	
	#ifdef RightAir
	dcswitch = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.ClrDTCOfLINHCMR2;
	#endif
	
    if((StsOfLedLoBeam==1)&&(dcswitch==1)) //收到近光灯开信号 直流电机开信号
    {
        if(gs_DCMotorRunInfo.ErrStatus.Status == 0u)
        {
            LvlgSwtSetReq = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.LvlgSwtSetReqLvlgSwtSetReq;
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

/* 直流电机高边电压故障和信号故障检测 */
static Std_ReturnType DCMotor_HsdAndSigErrDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta DCMotHSDErrSta;
    if(gs_DCMotorRunInfo.RunState != E_DCMotRunState_OFF)
    {
        DCMotHSDErrSta = HSDManage_GetHSDErrState(gs_DCMotorConfigInfo.HSChannel);
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
    }
    return rtval;
}

/* 直流电机控制线DTC检测设置 */
    double CalculateVoltValue;
    double DetectVoltValue;
    double VoltDifferValue;
static Std_ReturnType DCMotor_CtrLineDtcErrDetect(void)
{
    Std_ReturnType rtval = E_OK;
    uint32_t AdcDigitalValue;
    static double DCMotorCtrLineVoltage; /* AD采集的电压 */

    static uint8_t s_CtrLineErrNum = 0u;

    if(gs_DCMotorRunInfo.HSDActSta == E_HSDActSta_Act)//电机处于激活状态
    {
        rtval |= Interface_GetAdcDigitalValue(E_AdcFunction_DcCtr, & AdcDigitalValue); //DC_Ctrl 采样值
        if(rtval != E_OK)
        {
            return rtval;
        }

        DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0xFFFu;
        CalculateVoltValue = HSDManage_GetHSDSupplyVoltage() * (57.0 / 61.0) * gs_DCMotorRunInfo.PosPwm_Last / 100 ;
        DetectVoltValue = DCMotorCtrLineVoltage * 57.0 / 10;
        VoltDifferValue = (CalculateVoltValue >= DetectVoltValue) ? (CalculateVoltValue - DetectVoltValue) : (DetectVoltValue - CalculateVoltValue);

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
            // gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine = 1u;
            s_CtrLineErrNum = 0u;
        }
    }
    if(gs_DCMotorRunInfo.RunState == E_DCMotRunState_RUN || gs_DCMotorRunInfo.RunState == E_DCMotRunState_ERR)
    {
//设置DTC错误
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

/* 直流电机主函数 */
void DCMotor_MainFunction(uint8_t timebase)
{
    DCMotor_Run(timebase);
    DCMotor_StallDiagnose(); //堵转故障 
    DCMotor_HsdAndSigErrDetect(); //电压故障 硬件故障
    DCMotor_CtrLineDtcErrDetect(); //DC_Ctrl控制线错误 设置输出的电压和DC_Ctrl的电压值有出入
}


