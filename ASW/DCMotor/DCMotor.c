
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DCMotor.h"
#include "LinManager.h"
#include "Com.h"
#include "DTC_Interface.h"
#include "Channel_Interface.h"
#include "DrvTps2HB35.h"
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


uint8_t DiffPwm = 0;
/* 直流电机调平运行 */
static Std_ReturnType DCMotor_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    uint8 StsOfLedLoBeam = 0;
    uint8 LvlgSwtSetReq = 0;
    static uint8 DCmotorRunFlag = STD_OFF;
    static uint8 LastStsOfLedLoBeam = 0;
    static uint16_t HsdStartCheckTime = 0;
    static uint16_t HsdEndCheckTime = 0;

    /* dc motor running last timer */
    if(gs_DCMotorRunInfo.LastStartupTime < 4000)
    {
        gs_DCMotorRunInfo.LastStartupTime += timebase;
    }

    gs_DCMotorRunInfo.PosPwm_Last = gs_DCMotorRunInfo.PosPwm_Curr;

    StsOfLedLoBeam=Lighting_GetLinCtrl(E_LowBeam);

    if((StsOfLedLoBeam==1) &&(0==Interface_GetChannelState(ChannelID1)))//revice the LB and no LB err
    {
        /* if dc motor last status had error , this run need close check or will report hsd error */
        if(LastStsOfLedLoBeam != StsOfLedLoBeam)
        {
            HsdEndCheckTime = 0;
        }

        if((HSDManage_GetHSDOutputCurrent(E_HSChannel_HS1) > 50)&& (gs_DCMotorRunInfo.LastStartupTime > (HsdStartCheckTime)))
        {/* DC motor start running*/
            /* open hsd check */
            Interface_SetHsdErrorCheck(STD_ON);
            /* open dc motor check*/
            DCMotor_SetDtcErrDetect(STD_ON);
        }
        else if((HSDManage_GetHSDOutputCurrent(E_HSChannel_HS1) < 10) && (gs_DCMotorRunInfo.LastStartupTime >= (HsdEndCheckTime)))
        {/* DC motor finish running*/
            Interface_SetHsdErrorCheck(STD_OFF);
            DCMotor_SetDtcErrDetect(STD_OFF);
        }

        if(gs_DCMotorRunInfo.ErrStatus.Status == 0u)
        {
            LvlgSwtSetReq = Interface_GetSignal_LvlgSwtSetReqLvlgSwtSetReq();
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
					break;
                default:
                    gs_DCMotorRunInfo.PosPwm_Curr = gs_DCMotorConfigInfo.LVLSafetyPos;
                    gs_DCMotorRunInfo.RunState = E_DCMotRunState_OFF;
            }
            if(gs_DCMotorRunInfo.PosPwm_Last > 0)
            {
                gs_DCMotorRunInfo.HSDActSta = E_HSDActSta_Act;
            }
            gs_DCMotorRunInfo.RunState = E_DCMotRunState_RUN;
        }
        else
        {
            if(( gs_DCMotorRunInfo.ErrStatus.Bits.HSDHW   == 1u ||
                gs_DCMotorRunInfo.ErrStatus.Bits.Stall   == 1u ||
                gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine == 1u )) /* 电压故障无需处理和反馈 */
            {

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
    }
    else
    {/* closed */
        Interface_SetHsdErrorCheck(STD_OFF);
        HSDManage_ResetRunInfoErrSta();
        Interface_SetDtcHSDAndFanError(5,0);
        if(gs_DCMotorRunInfo.LastStartupTime >= 4000) /* 关闭高边之前需要等待上次启动完成 */
        {
            gs_DCMotorRunInfo.HSDActSta = E_HSDActSta_NoAct;
            if(HSDManage_GetHSDSwitchState(gs_DCMotorConfigInfo.HSChannel) == E_HSDSwitchSta_OFF)
            {
                gs_DCMotorRunInfo.PosPwm_Curr = 0u;
            }
        }
        gs_DCMotorRunInfo.ErrStatus.Status = 0u; /* 清除所有故障 */
        gs_DCMotorRunInfo.RunState = E_DCMotRunState_OFF;
    }

    /* dc motor moved */
    if(gs_DCMotorRunInfo.PosPwm_Last != gs_DCMotorRunInfo.PosPwm_Curr)
    {
        if ((gs_DCMotorRunInfo.PosPwm_Last == 0u) && (gs_DCMotorRunInfo.PosPwm_Curr > 0u)) /* 开启 */
        {
            gs_DCMotorRunInfo.LastStartupTime = 0u;
        }
        else if (gs_DCMotorRunInfo.PosPwm_Last >= gs_DCMotorConfigInfo.LVLSafetyPos && gs_DCMotorRunInfo.PosPwm_Curr >= gs_DCMotorConfigInfo.LVLSafetyPos) /* 调档 */
        {
            // uint8_t DiffPwm;
            uint16_t NeedRunTime;
    
            DiffPwm = (gs_DCMotorRunInfo.PosPwm_Last > gs_DCMotorRunInfo.PosPwm_Curr) ?
                      (gs_DCMotorRunInfo.PosPwm_Last - gs_DCMotorRunInfo.PosPwm_Curr) :
                      (gs_DCMotorRunInfo.PosPwm_Curr - gs_DCMotorRunInfo.PosPwm_Last);

            NeedRunTime = 4000 * DiffPwm / (gs_DCMotorConfigInfo.CntrlUpprThd - gs_DCMotorConfigInfo.CntrlLowrThd);

            /*Get HSD stop check time*/
            if( DiffPwm > DCMOTOR_PWM_STEP_DELTA )
            {
                if(gs_DCMotorRunInfo.LastStartupTime>DCMOTOR_END_EARLY)
                {
                    HsdEndCheckTime = gs_DCMotorRunInfo.LastStartupTime - (uint16_t)DCMOTOR_END_EARLY;
                }
                else
                {
                    HsdEndCheckTime = 0;
                }
            }
            else
            {
                if(gs_DCMotorRunInfo.LastStartupTime > 4000)
                {
                    HsdEndCheckTime = 4000;
                }
                else
                {
                    HsdEndCheckTime = gs_DCMotorRunInfo.LastStartupTime;
                }
                
            }

            if (gs_DCMotorRunInfo.LastStartupTime >= NeedRunTime)
            {
                gs_DCMotorRunInfo.LastStartupTime -= NeedRunTime;
            }
            else
            {
                gs_DCMotorRunInfo.LastStartupTime = 0u;
            }
            /*Get HSD start check time*/
            HsdStartCheckTime = gs_DCMotorRunInfo.LastStartupTime + DCMOTOR_START_DELAY;
        }
    }
    
    /* Remember last LoBeam status*/
    LastStsOfLedLoBeam = StsOfLedLoBeam;

    HSDManage_SetHSDActState(gs_DCMotorConfigInfo.HSChannel, gs_DCMotorRunInfo.HSDActSta);
    Interface_EnablePulseGenerator(E_PulseGeneratorFunction_DCMotor, DCMOTOR_PWM_CYCLE, gs_DCMotorRunInfo.PosPwm_Curr);
    return rtval;
}


/* 直流电机堵转检测 */
static Std_ReturnType DCMotor_StallDiagnose(void)
{
    Std_ReturnType rtval = E_OK;
    static uint8_t s_DCMotStallComformNum = 0u; /* 堵转确认计数 */
    static E_EnableFlag se_StallEnFlag = E_EnableFlag_DISABLE;
    if(HSDManage_GetHSDSupplyVoltage() < 9.0 || HSDManage_GetHSDSupplyVoltage() > 16.0) /* 过欠压 */
    {
        return rtval;
    }

    if(STD_ON == DCMotor_GetDtcErrDetect())
    {
        if(gs_DCMotorRunInfo.LastStartupTime < gs_DCMotorConfigInfo.DeactDlyTi)
        {
            if(HSDManage_GetHSDOutputCurrent(gs_DCMotorConfigInfo.HSChannel) > gs_DCMotorConfigInfo.IOutStallHSD) /* 统计电流超出阈值数量 */
            {
                if (s_DCMotStallComformNum < 2u)
                    s_DCMotStallComformNum++;
            }
            else
            {
                if(s_DCMotStallComformNum > 0u)
                    s_DCMotStallComformNum--;
            }
            if (s_DCMotStallComformNum >= 2u) /* 堵转阈值为2 */
            {
                gs_DCMotorRunInfo.ErrStatus.Bits.Stall = 1u;
            }
        }

    }

    return rtval;
}

/* 直流电机HSD故障检测 */
static Std_ReturnType DCMotor_HsdAndSigErrDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta DCMotHSDErrSta;

    if(HSDManage_GetHSDSupplyVoltage() >= 9.0 && HSDManage_GetHSDSupplyVoltage() <= 16.0) /* 电压正常 */
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
            default:
                break;
        }
    }
    else
    {
        rtval = E_NOT_OK;
    }

    return rtval;
}
/* 1.1 HSD故障
HSD短路故障，或者直流电机堵转，反馈StsOfLvlgLe/ StsOfLvlgRi == 0x02 [err] 
DTCGroup3bit2 =1，DID D900设置对应故障状态位。
关闭HSD1输出，电机停在当前位置；
 */
Std_ReturnType DCMotor_GetErrStatus(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta DCMotHSDErrSta;
    if(gs_DCMotorRunInfo.RunState != E_DCMotRunState_OFF)
    {
        DCMotHSDErrSta = HSDManage_GetHSDErrState(gs_DCMotorConfigInfo.HSChannel);
        if(DCMotHSDErrSta==E_HSDErrSta_Normal)
        {
            rtval|= E_OK;
        }
        else
        {
            rtval|= E_NOT_OK;
        }
        if( gs_DCMotorRunInfo.ErrStatus.Bits.Stall ==0)
        {
            rtval|= E_OK;
        }
        else
        {
            rtval|= E_NOT_OK;
        }
    }
    return rtval;
}
/* 
DTC group4 bit 0
DC-motor 控制脚故障（控制线的开路/对电源短路/对地短路、超过了范围），反馈StsOfLvlgLe/ StsOfLvlgRi == 0x02 [err] 记录HCML2DTCGroup4bit0 =1，DID D900设置对应故障状态位。
关闭HSD1输出，电机停在当前位置；
 */
Std_ReturnType DCMotor_GetSIGErrStatus(void)
{
    Std_ReturnType rtval = E_OK;
    if(gs_DCMotorRunInfo.RunState != E_DCMotRunState_OFF)
    {
        if(gs_DCMotorRunInfo.ErrStatus.Status!=0)
        {
            rtval= E_NOT_OK;
        }
    }
    return rtval;
}

/* 直流电机控制脚故障检测,不报开路 */
static Std_ReturnType DCMotor_CtrLineDtcErrDetect(void)
{
    Std_ReturnType rtval = E_OK;

    if(HSDManage_GetHSDSupplyVoltage() < 9.0 || HSDManage_GetHSDSupplyVoltage() > 16.0) /* 过欠压 */
    {
        return rtval;
    }

    static uint8_t s_CtrLineErrNum = 0u;
    static uint8_t s_OLErrNum = 1u; /* 开路故障包括电源和控制线开路 */

    if( HSDManage_GetHSDSwitchState(gs_DCMotorConfigInfo.HSChannel) == E_HSDSwitchSta_ON &&
        HSDManage_GetHSDErrState(gs_DCMotorConfigInfo.HSChannel) == E_HSDErrSta_Normal &&
        (gs_DCMotorRunInfo.ErrStatus.Status & 0x0F) == 0u )
    {
        uint32_t AdcDigitalValue = 0;
        double DCMotorCtrLineVoltage; /* AD采集的电压 */
        rtval |= Interface_GetAdcDigitalValue(E_AdcFunction_DcCtr, & AdcDigitalValue);
        if(rtval == E_OK)
        {
            DCMotorCtrLineVoltage = 5.0 * AdcDigitalValue / 0xFFFu;
            double CalculateVoltValue; /* 控制线理论计算电压值 */
            double DetectVoltValue;    /* 控制线实际检测电压值 */
            double VoltDifferValue;    /* 控制线电压偏差值 */

            CalculateVoltValue = (HSDManage_GetHSDSupplyVoltage() + 0.07 - 0.45) * gs_DCMotorRunInfo.PosPwm_Last / 100.0 ; /* +0.07是实际输入电压，再-0.45是实际输出电压 */
            DetectVoltValue = DCMotorCtrLineVoltage * 57.0 / 10.0 + 0.05; /* +0.05是ADC检测与实际测量的偏差 */
            VoltDifferValue = CalculateVoltValue >= DetectVoltValue ? CalculateVoltValue - DetectVoltValue : DetectVoltValue - CalculateVoltValue;

            if(VoltDifferValue > 2.0) /* 控制线故障阈值2.0V */
            {
                if(s_CtrLineErrNum < 10u)
                {
                    s_CtrLineErrNum++;
                }

            }
            else
            {
                if(s_CtrLineErrNum > 0u)
                {
                    s_CtrLineErrNum--;
                }

            }
        }

        static E_EnableFlag  se_OLDetEnFlag = E_EnableFlag_DISABLE;
        static uint8_t  s_ValidCurrentNum = 0u;

        if( (gs_DCMotorRunInfo.PosPwm_Last > 0u) &&
            (gs_DCMotorRunInfo.PosPwm_Curr > 0u) &&
            (gs_DCMotorRunInfo.PosPwm_Last != gs_DCMotorRunInfo.PosPwm_Curr) ) /* 电机变换位置 */
        {
            s_ValidCurrentNum = 0u;
            se_OLDetEnFlag = E_EnableFlag_ENABLE;
        }
        if(se_OLDetEnFlag == E_EnableFlag_ENABLE)
        {
            if(gs_DCMotorRunInfo.LastStartupTime < gs_DCMotorConfigInfo.DeactDlyTi)
            {
                if(HSDManage_GetHSDOutputCurrent(gs_DCMotorConfigInfo.HSChannel) > 5u) /* 统计电流大于5mA的数量 */
                {
                    if(s_ValidCurrentNum < 0xFFu)
                    {
                        s_ValidCurrentNum++;
                    }
                }
            }
            else
            {
                if(s_ValidCurrentNum == 0u)
                {
                    if(s_OLErrNum < 2u) /* 需要累计2次调节故障 */
                    {
                        s_OLErrNum++;
                    }
                }
                else
                {
                    if(s_OLErrNum > 0u)
                    {
                        s_OLErrNum--;
                    }
                }
                se_OLDetEnFlag = E_EnableFlag_DISABLE;
            }
        }

        static uint8_t s_LatestErrSts = 0u;  /* 最新故障状态 */
        static uint8_t s_LastOnErrType = 0u; /* 上次开启时的故障禁止类型：1：控制线电压；2：开路 */

        if(s_CtrLineErrNum >= 10u || s_OLErrNum >= 2u) /* 有任一故障 */
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 1u);
            s_LatestErrSts = 1u;
        }
        else if(s_CtrLineErrNum == 0u && s_LastOnErrType == 1u) /* 上次开启时控制线电压故障，此次清除 */
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 0u);
            s_LatestErrSts = 0u;
            s_LastOnErrType = 0u;
        }
        else if(s_OLErrNum == 0u && s_LastOnErrType == 2u) /* 上次开启时开路故障，此次清除 */
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 0u);
            s_LatestErrSts = 0u;
            s_LastOnErrType = 0u;
        }
        else if(s_CtrLineErrNum == 0u && s_OLErrNum == 0u) /* 此次两项都无故障 */
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 0u);
            s_LatestErrSts = 0u;
        }
        else if (s_LatestErrSts == 1u) /* 清除偶发故障 */
        {
            Interface_SetSystemError(E_SystemErrorType_DCMotorError, 0u);
            s_LatestErrSts = 0u;
        }

        if (s_LatestErrSts == 1u)
        {
            gs_DCMotorRunInfo.ErrStatus.Bits.CtrLine = 1u; /* 需要DTC和当前开启周期都是故障状态 */
            if(s_CtrLineErrNum >= 10u) /* 保存此次故障禁止类型 */
            {
                s_LastOnErrType = 1u;
            }
            else if (s_OLErrNum >= 2u)
            {
                s_LastOnErrType = 2u;
            }
            s_LatestErrSts = 0u;
        }
    }
    else if (gs_DCMotorRunInfo.RunState == E_DCMotRunState_OFF) /* 复位故障计数 */
    {
        s_CtrLineErrNum = 0u;
        s_OLErrNum = 1u;
    }
    return rtval;
}


static void DCMotor_SetDtcErrDetect(uint8 status)
{
    DcmotorCheckFlag = status;
}

static Std_ReturnType DCMotor_GetDtcErrDetect(void)
{
    return DcmotorCheckFlag;
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
#include "Dio_Service.h"
#include "Pwm.h"
#include "Dio_Cfg.h"
#include "Dio.h"
/* 直流电机主函数 */
void DCMotor_MainFunction(uint8_t timebase)
{
    {
        DCMotor_Run(timebase);
        DCMotor_StallDiagnose(); //DC_Motor Stall error check
        DCMotor_HsdAndSigErrDetect(); //DC_Motor HSD error check
        DCMotor_CtrLineDtcErrDetect(); //DC_Motor Ctrl控制线错误 设置输出的电压和DC_Ctrl的电压值有出入
    }  
}


