/********************************
 * Fan.c
 *
 *  Created on: 2024/3/22
 *      Author: tujiongjiong
 ********************************/

/* 高边HSO通道固定给风扇1 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
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
static S_FanConfigInfo gs_FanConfigInfo; /* 风扇所有配置信息 */

/* 风扇1运行信息 */
static S_Fan1RunInfo gs_Fan1RunInfo =
{
    .PwmCool     = 0,
    .PwmDefog    = 0,
    .PwmDeice    = 0,
    .PwmRun_Curr = 0,
    .PwmRun_Last = 0,
    .Fan1RunMode = Fan1RunMode_Cooling,
    .RunState    = E_FanRunState_OFF
};

/* 风扇2运行信息 */
static S_Fan2RunInfo gs_Fan2RunInfo =
{
    .RunState = E_FanRunState_OFF
};

/* 风扇DID信息 */
static S_FanDidInfo  gs_FanDidInfo =
{
    .Fan1Diagnosis       = Fan1Diagnosis_NotAval,
    .FAN2Control         = FAN2Control_NotAval,
    .Fan1Supply          = Fan1Supply_NotAval,
    .Fan1OutputControl   = 0xFF,
    .Fan1CurrentFeedback = 0xFFF,
    .Fan1StartNum        = 0xFFFFFFFF,
    .Fan1StartDeiNum     = 0xFFFFFFFF,
    .Fan1StartDefNum     = 0xFFFFFFFF,
    .Fan1Runtime         = 0xFFFFFFFF,
    .Fan1SupplyVoltage   = 0xFF
};

static E_EnableFlag ge_FanIOCtrFlag      = E_EnableFlag_DISABLE; /* DID控制状态标志 */
static E_EnableFlag ge_FanRoutineCtrFlag = E_EnableFlag_DISABLE; /* 例程控制状态标志 */
static uint8_t g_FanRoutineCtrStallErrSta = 0; /* 例程控制堵转故障状态 */

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/* 读取风扇参数配置并存放 */
static Std_ReturnType Fan_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    switch( Get_pFanNumber() )
    {
        case 1:
            gs_FanConfigInfo.FanNumber = E_FanNumber_NoFan;
            break;
        case 2:
            gs_FanConfigInfo.FanNumber = E_FanNumber_OneFan;
            break;
        case 4:
            gs_FanConfigInfo.FanNumber = E_FanNumber_TwoFans;
    }
    switch( Get_pFanControlPin() )
    {
        case 1:
            gs_FanConfigInfo.FanControlPin = E_FanControlPin_No;
            break;
        case 2:
            gs_FanConfigInfo.FanControlPin = E_FanControlPin_RPMNotAllowed;
            break;
        case 4:
            gs_FanConfigInfo.FanControlPin = E_FanControlPin_RPMAllowed;
    }
    switch( Get_pFanDefLightFct() )
    {
        case 1:
            gs_FanConfigInfo.FanDefLightFct = E_FanDefLightFct_NA;
            break;
        case 2:
            gs_FanConfigInfo.FanDefLightFct = E_FanDefLightFct_DRL;
            break;
        case 4:
            gs_FanConfigInfo.FanDefLightFct = E_FanDefLightFct_LB;
            break;
        case 8:
            gs_FanConfigInfo.FanDefLightFct = E_FanDefLightFct_DRLOrLB;
            break;
        case 16:
            gs_FanConfigInfo.FanDefLightFct = E_FanDefLightFct_Independent;
    }
    switch( Get_pFanDeiLightFct() )
    {
        case 1:
            gs_FanConfigInfo.FanDeiLightFct = E_FanDeiLightFct_NA;
            break;
        case 2:
            gs_FanConfigInfo.FanDeiLightFct = E_FanDeiLightFct_DRL;
            break;
        case 4:
            gs_FanConfigInfo.FanDeiLightFct = E_FanDeiLightFct_LB;
            break;
        case 8:
            gs_FanConfigInfo.FanDeiLightFct = E_FanDeiLightFct_DRLOrLB;
            break;
        case 16:
            gs_FanConfigInfo.FanDeiLightFct = E_FanDeiLightFct_Independent;
    }
    switch( Get_pFanDiagInputType() )
    {
        case 1:
            gs_FanConfigInfo.FanDiagInputType = E_FanDiagInputType_NoDiagnosePin;
            break;
        case 2:
            gs_FanConfigInfo.FanDiagInputType = E_FanDiagInputType_ErrorActive_L;
            break;
        case 4:
            gs_FanConfigInfo.FanDiagInputType = E_FanDiagInputType_ErrorActive_H;
            break;
        case 8:
            gs_FanConfigInfo.FanDiagInputType = E_FanDiagInputType_FixedFrequency;
            break;
        case 16:
            gs_FanConfigInfo.FanDiagInputType = E_FanDiagInputType_VariableFrequency;
    }
    switch( Get_pFanFaultSignal() )
    {
        case 1:
            gs_FanConfigInfo.FanFaultSignal = E_FanFaultSignal_No;
            break;
        case 2:
            gs_FanConfigInfo.FanFaultSignal = E_FanFaultSignal_YES;
    }
    switch( GetChannelMaskByLightFunction(E_Fan2) )
    {
        case 0x0000:
            gs_FanConfigInfo.Fan2HSDChannel = E_HSChannel_HS0; /* 表示没有高边配置 */
            break;
        case 0x1000:
            gs_FanConfigInfo.Fan2HSDChannel = E_HSChannel_HS1;
            break;
        case 0x2000:
            gs_FanConfigInfo.Fan2HSDChannel = E_HSChannel_HS2;
            break;
        case 0x4000:
            gs_FanConfigInfo.Fan2HSDChannel = E_HSChannel_HS3;
    }
    gs_FanConfigInfo.FanToChannel        = Get_pFanToChannel();
    gs_FanConfigInfo.FanOnLedChannel     = Get_pFanOnLedCh();

    gs_FanConfigInfo.FanAmbTempHys       = Get_pFanAmbTempHys();
    gs_FanConfigInfo.FanLedTempHys       = Get_pFanLedTempHys();
    gs_FanConfigInfo.FanSupInrushTime    = Get_pFanSupInrushTime();
    gs_FanConfigInfo.FanNomCurrent       = Get_pFanNomCurrent();
    gs_FanConfigInfo.FanNomCurTol        = Get_pFanNomCurTol();
    gs_FanConfigInfo.FanLockDebTime      = Get_pFanLockDebTime();
    gs_FanConfigInfo.FanLockProtOnTime0  = Get_pFanLockProtOnTime0() * 100;
    gs_FanConfigInfo.FanLockProtTimeTol0 = Get_pFanLockProtTimeTol0();
    gs_FanConfigInfo.FanLockRetryOffTime = Get_pFanLockRetryOffTime() * 1000;

    gs_FanConfigInfo.FanCoolLedTempLo    = Get_pFanCoolLedTempLo();
    gs_FanConfigInfo.FanCoolLedTempHi    = Get_pFanCoolLedTempHi();
    gs_FanConfigInfo.FanCoolPowerLo      = Get_pFanCoolPowerLo();
    gs_FanConfigInfo.FanCoolPowerHi      = Get_pFanCoolPowerHi();

    gs_FanConfigInfo.FanDefAmbTempLo     = Get_pFanDefAmbTempLo() - 40;
    gs_FanConfigInfo.FanDefAmbTempHi     = Get_pFanDefAmbTempHi() - 40;
    gs_FanConfigInfo.FanDefPowerLo       = Get_pFanDefPowerLo();
    gs_FanConfigInfo.FanDefPowerHi       = Get_pFanDefPowerHi();

    gs_FanConfigInfo.FanDeiAmbTempLo     = Get_pFanDeiAmbTempLo() - 40;
    gs_FanConfigInfo.FanDeiAmbTempHi     = Get_pFanDeiAmbTempHi() - 40;
    gs_FanConfigInfo.FanDeiPowerLo       = Get_pFanDeiPowerLo();
    gs_FanConfigInfo.FanDeiPowerHi       = Get_pFanDeiPowerHi();

    gs_FanConfigInfo.Fan2CoolLedTempLo   = Get_pFan2CoolLedTempLo();
    return rtval;
}




/* 读取所有LED通道状态，按位编码保存到低12位 */
static Std_ReturnType Fan_GetAllLEDChannelState(uint16_t * AllChannelState)
{
    Std_ReturnType rtval = E_OK;
    E_ChannelID ChannelID;
    E_ChannelState ChannelState;
    uint16_t AllChannelState_Temp = 0;

    for(ChannelID = ChannelID1; ChannelID <= ChannelID12; ChannelID++)
    {
        rtval |= Interface_GetChannelSwitchState(ChannelID, &ChannelState);

        if(ChannelState == CHANNEL_STATE_ON)
            AllChannelState_Temp |= 1u << ChannelID;
    }
    *AllChannelState = AllChannelState_Temp;

    return rtval;
}

/* 读取LED温度，多个LED通道取最大值 */
static Std_ReturnType Fan_GetLedTemperature(uint16_t ChannelMask, sint16_t * LedTemperature)
{
    Std_ReturnType rtval = E_OK;
    E_ChannelID ChannelID;
    sint16_t LedTemperature_Max = -50; /* 赋一个最低温度值，以便找最大值 */

    for(ChannelID = ChannelID1; ChannelID <= ChannelID12; ChannelID++)
    {
        if((ChannelMask & (1 << ChannelID)) > 0) /* 寻找风扇对应的LED通道 */
        {
            E_NtcRcodFunction NTCChannel;
            sint16_t NTCChannelTemperature;

            NTCChannel = (E_NtcRcodFunction)Get_pLedChToNtc(ChannelID); /* 风扇对应的LED通道对应的NTC通道 */
            rtval = Interface_GetNtcTemperature(NTCChannel, &NTCChannelTemperature);    /* 读取该NTC通道的温度值 */
            if(rtval == E_OK) /* 遇到未读到温度值的通道，直接跳过 */
            {
                if(LedTemperature_Max < NTCChannelTemperature) /* 找到最高的LED通道温度 */
                    LedTemperature_Max = NTCChannelTemperature;
            }
        }
    }
    if(LedTemperature_Max != -50) /* 读到有效NTC温度 */
    {
        *LedTemperature = LedTemperature_Max;
        return E_OK;
    }
    else  /* 没有读到任何有效NTC温度 */
    {
        return E_NOT_OK;
    }
}

/* 风扇1冷却，设置转速 */
static Std_ReturnType Fan_Fan1CoolingLED(void)
{
    Std_ReturnType rtval = E_OK;
    uint16_t AllChannelState;

    rtval |= Fan_GetAllLEDChannelState( &AllChannelState ); /* 读取所有LED通道状态 */

    if((gs_FanConfigInfo.FanToChannel & AllChannelState) > 0) /* 有对应LED通道开启，开始打开风扇1 */
    {
        sint16_t  LedTemperature = 0;

        if((gs_FanConfigInfo.FanOnLedChannel & AllChannelState) > 0) /* 直接开启风扇的LED通道打开，设置温度为最大值 */
        {
            LedTemperature = 150;
        }
        else
        {
            rtval |= Fan_GetLedTemperature( gs_FanConfigInfo.FanToChannel & AllChannelState, &LedTemperature ); /* 读LED温度 */
            if(rtval != E_OK)
            {
                return rtval;
            }
        }

        switch( gs_FanConfigInfo.FanControlPin )      /* 匹配风扇1转速控制引脚配置 */
        {
            case E_FanControlPin_No:             /* 风扇1无控制引脚 */
            case E_FanControlPin_RPMNotAllowed:  /* 风扇1不允许转速控制 */
                if(LedTemperature >= gs_FanConfigInfo.FanCoolLedTempLo) /* 高温打开 */
                    gs_Fan1RunInfo.PwmCool = 100;
                else if(LedTemperature < gs_FanConfigInfo.FanCoolLedTempLo - gs_FanConfigInfo.FanLedTempHys) /* 低温滞后关闭 */
                    gs_Fan1RunInfo.PwmCool = 0;
                break;

            case E_FanControlPin_RPMAllowed:     /* 风扇1允许转速控制 */
                if(LedTemperature >= gs_FanConfigInfo.FanCoolLedTempHi)  /* 风扇1最大转速段 */
                    gs_Fan1RunInfo.PwmCool = gs_FanConfigInfo.FanCoolPowerHi;
                else if(LedTemperature < gs_FanConfigInfo.FanCoolLedTempLo - gs_FanConfigInfo.FanLedTempHys)   /* 风扇1滞后关闭 */
                    gs_Fan1RunInfo.PwmCool = 0;
                else if(LedTemperature >= gs_FanConfigInfo.FanCoolLedTempLo && LedTemperature < gs_FanConfigInfo.FanCoolLedTempHi) /* 风扇1冷却线性控制段 */
                {
                    double CoolSlope; /* 线性冷却斜率 */

                    CoolSlope = (gs_FanConfigInfo.FanCoolPowerHi - gs_FanConfigInfo.FanCoolPowerLo) / (gs_FanConfigInfo.FanCoolLedTempHi - gs_FanConfigInfo.FanCoolLedTempLo);
                    gs_Fan1RunInfo.PwmCool = (LedTemperature - gs_FanConfigInfo.FanCoolLedTempLo) * CoolSlope + gs_FanConfigInfo.FanCoolPowerLo;
                }
        }
    }
    else /* 关闭风扇1 */
    {
        switch( gs_FanConfigInfo.FanControlPin ) /* 匹配风扇1转速控制引脚配置 */
        {
            case E_FanControlPin_No:             /* 风扇1无控制引脚 */
            case E_FanControlPin_RPMNotAllowed:  /* 风扇1不允许转速控制 */
            case E_FanControlPin_RPMAllowed:     /* 风扇1允许转速控制 */
                gs_Fan1RunInfo.PwmCool = 0;
        }
    }
    return rtval;
}

/* 风扇2冷却 */
static Std_ReturnType Fan_Fan2CoolingLED(void)
{
    Std_ReturnType rtval = E_OK;
    uint16_t AllChannelState;
    uint16_t LBHBChannel;
    sint16_t LedTemperature;

    rtval |= Fan_GetAllLEDChannelState( &AllChannelState ); /* 读取所有LED通道状态 */

    LBHBChannel = GetChannelMaskByLightFunction(E_LowBeamFlat)  |
                  GetChannelMaskByLightFunction(E_LowBeamKink)  |
                  GetChannelMaskByLightFunction(E_HighBeamSail) |
                  GetChannelMaskByLightFunction(E_HighBeamSpot);

    rtval |= Fan_GetLedTemperature( LBHBChannel & AllChannelState, &LedTemperature ); /* 读LED温度 */
    if(rtval != E_OK) /* 此次没有读到有效温度，退出 */
    {
        return rtval;
    }

#if FAN_TEST
    static uint8_t TemperatureTest = 0;
    static uint8_t Direction = 0;
    if (TemperatureTest == 0)
    {
        Direction = 0;
    }
    else if(TemperatureTest == 100)
    {
        Direction = 1;
    }
    if (Direction == 0)
    {
        TemperatureTest++;
    }
    else if (Direction == 1)
    {
        TemperatureTest--;
    }
    LedTemperature = TemperatureTest;
#endif

    if(LedTemperature >= gs_FanConfigInfo.Fan2CoolLedTempLo)  /* 高温打开 */
    {
        if(gs_Fan2RunInfo.RunState == E_FanRunState_OFF)
        {
            gs_Fan2RunInfo.RunState = E_FanRunState_ON;
        }
    }
    else if(LedTemperature < gs_FanConfigInfo.Fan2CoolLedTempLo - gs_FanConfigInfo.FanLedTempHys) /* 低温滞后关闭 */
    {
        gs_Fan2RunInfo.RunState = E_FanRunState_OFF;
    }

    E_UsageModeSts UsageMode;
    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& UsageMode);
    switch( UsageMode )
    {
        case E_UsageModeSts_Abdnd:
        case E_UsageModeSts_InActv:
        case E_UsageModeSts_Cnvinc:
            HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_NoAct); /* 关闭风扇2 */
            break;

        case E_UsageModeSts_Actv:
        case E_UsageModeSts_Drvg:
            if(gs_Fan2RunInfo.RunState == E_FanRunState_ON)
            {
                HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_Act);  /* 打开风扇2 */
            }
            else if(gs_Fan2RunInfo.RunState == E_FanRunState_OFF)
            {
                HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_NoAct); /* 关闭风扇2 */
            }
    }

    return rtval;
}





/* 获取环境温度 */
static Std_ReturnType Fan_GetAmbientTemperature(sint16_t * AmbTemp)
{
    Std_ReturnType rtval = E_OK;
    sint32_t AmbTemp_Buff;

    rtval |= Interface_GetSignal_AmbTRawAmbTVal(& AmbTemp_Buff);
    * AmbTemp = AmbTemp_Buff;
    return rtval;
}

/* 风扇1独立于灯光除雾，设置转速 */
static Std_ReturnType Fan_Fan1DefoggingIndependent(void)
{
    Std_ReturnType rtval = E_OK;
    sint16_t AmbTemp;

    rtval |= Fan_GetAmbientTemperature(&AmbTemp); /* 读环境温度 */

    switch( gs_FanConfigInfo.FanControlPin ) /* 匹配风扇1转速控制引脚配置 */
    {
        case E_FanControlPin_No:             /* 风扇1无控制引脚 */
        case E_FanControlPin_RPMNotAllowed:  /* 风扇1不允许转速控制 */
            if(AmbTemp <= gs_FanConfigInfo.FanDefAmbTempHi) /* 低温开启 */
                gs_Fan1RunInfo.PwmDefog = 100;
            else if(AmbTemp > gs_FanConfigInfo.FanDefAmbTempHi + gs_FanConfigInfo.FanAmbTempHys) /* 高温滞后关闭 */
                gs_Fan1RunInfo.PwmDefog = 0;
            break;

        case E_FanControlPin_RPMAllowed:     /* 风扇1允许转速控制 */
            if(AmbTemp <= gs_FanConfigInfo.FanDefAmbTempLo)  /* 风扇1最大转速段 */
                gs_Fan1RunInfo.PwmDefog = gs_FanConfigInfo.FanDefPowerHi;
            else if(AmbTemp > gs_FanConfigInfo.FanDefAmbTempHi + gs_FanConfigInfo.FanAmbTempHys)  /* 风扇1滞后关闭 */
                gs_Fan1RunInfo.PwmDefog = 0;
            else if(AmbTemp > gs_FanConfigInfo.FanDefAmbTempLo && AmbTemp <= gs_FanConfigInfo.FanDefAmbTempHi) /* 风扇1除雾线性控制段 */
            {
                double CoolSlope; /* 线性冷却斜率 */

                CoolSlope = (gs_FanConfigInfo.FanDefPowerHi - gs_FanConfigInfo.FanDefPowerLo) / (gs_FanConfigInfo.FanDefAmbTempHi - gs_FanConfigInfo.FanDefAmbTempLo);
                gs_Fan1RunInfo.PwmDefog = (gs_FanConfigInfo.FanDefAmbTempHi - AmbTemp) * CoolSlope + gs_FanConfigInfo.FanDefAmbTempLo;
            }
    }
    return rtval;
}

/* 风扇1除雾 */
static Std_ReturnType Fan_Fan1Defogging(void)
{
    Std_ReturnType rtval = E_OK;
    uint32_t StsOfLedDaytiRunngLamp;
    uint32_t StsOfLedLoBeam;

    switch( gs_FanConfigInfo.FanDefLightFct ) /* 读取风扇1除雾必须激活的灯光功能配置 */
    {
        case E_FanDefLightFct_NA:
            break;

        case E_FanDefLightFct_DRL:
            rtval |= Interface_GetSignal_StsOfLedDaytiRunngLamp(& StsOfLedDaytiRunngLamp);
            if(StsOfLedDaytiRunngLamp == 0x1)
            {
                rtval |= Fan_Fan1DefoggingIndependent();
            }
            break;

        case E_FanDefLightFct_LB:
            rtval |= Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedLoBeam == 0x1)
            {
                rtval |= Fan_Fan1DefoggingIndependent();
            }
            break;

        case E_FanDefLightFct_DRLOrLB:
            rtval |= Interface_GetSignal_StsOfLedDaytiRunngLamp(& StsOfLedDaytiRunngLamp);
            rtval |= Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedDaytiRunngLamp == 0x1 || StsOfLedLoBeam == 0x1)
            {
                rtval |= Fan_Fan1DefoggingIndependent();
            }
            break;

        case E_FanDefLightFct_Independent:
            rtval |= Fan_Fan1DefoggingIndependent();
    }
    return rtval;
}

/* 风扇1独立于灯光除冰，设置转速 */
static Std_ReturnType Fan_Fan1DeicingIndependent(void)
{
    Std_ReturnType rtval = E_OK;
    sint16_t AmbTemp;

    rtval |= Fan_GetAmbientTemperature(&AmbTemp); /* 读环境温度 */

    switch( gs_FanConfigInfo.FanControlPin ) /* 匹配风扇1转速控制引脚配置 */
    {
        case E_FanControlPin_No:             /* 风扇1无控制引脚 */
        case E_FanControlPin_RPMNotAllowed:  /* 风扇1不允许转速控制 */
            if(AmbTemp <= gs_FanConfigInfo.FanDeiAmbTempHi) /* 低温开启 */
                gs_Fan1RunInfo.PwmDeice = 100;

            else if(AmbTemp > gs_FanConfigInfo.FanDeiAmbTempHi + gs_FanConfigInfo.FanAmbTempHys) /* 高温滞后关闭 */
                gs_Fan1RunInfo.PwmDeice = 0;
            break;

        case E_FanControlPin_RPMAllowed:     /* 风扇1允许转速控制 */
            if(AmbTemp <= gs_FanConfigInfo.FanDeiAmbTempLo)  /* 风扇1最大转速段 */
                gs_Fan1RunInfo.PwmDeice = gs_FanConfigInfo.FanDeiPowerHi;

            else if(AmbTemp > gs_FanConfigInfo.FanDeiAmbTempHi + gs_FanConfigInfo.FanAmbTempHys)  /* 风扇1滞后关闭 */
                gs_Fan1RunInfo.PwmDeice = 0;

            else if(AmbTemp > gs_FanConfigInfo.FanDeiAmbTempLo && AmbTemp <= gs_FanConfigInfo.FanDeiAmbTempHi) /* 风扇1除雾线性控制段 */
            {
                double CoolSlope; /* 线性冷却斜率 */

                CoolSlope = (gs_FanConfigInfo.FanDeiPowerHi - gs_FanConfigInfo.FanDeiPowerLo) / (gs_FanConfigInfo.FanDeiAmbTempHi - gs_FanConfigInfo.FanDeiAmbTempLo);
                gs_Fan1RunInfo.PwmDeice = (gs_FanConfigInfo.FanDeiAmbTempHi - AmbTemp) * CoolSlope + gs_FanConfigInfo.FanDeiAmbTempLo;
            }
    }
    return rtval;
}

/* 风扇1除冰 */
static Std_ReturnType Fan_Fan1Deicing(void)
{
    Std_ReturnType rtval = E_OK;
    uint32_t StsOfLedDaytiRunngLamp;
    uint32_t StsOfLedLoBeam;

    switch( gs_FanConfigInfo.FanDeiLightFct ) /* 读取风扇1除雾必须激活的灯光功能配置 */
    {
        case E_FanDeiLightFct_NA:
            break;

        case E_FanDeiLightFct_DRL:
            rtval |= Interface_GetSignal_StsOfLedDaytiRunngLamp(& StsOfLedDaytiRunngLamp);
            if(StsOfLedDaytiRunngLamp == 0x1)
            {
                rtval |= Fan_Fan1DeicingIndependent();
            }
            break;

        case E_FanDeiLightFct_LB:
            rtval |= Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedLoBeam == 0x1)
            {
                rtval |= Fan_Fan1DeicingIndependent();
            }
            break;

        case E_FanDeiLightFct_DRLOrLB:
            rtval |= Interface_GetSignal_StsOfLedDaytiRunngLamp(& StsOfLedDaytiRunngLamp);
            rtval |= Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedDaytiRunngLamp == 0x1 || StsOfLedLoBeam == 0x1)
            {
                rtval |= Fan_Fan1DeicingIndependent();
            }
            break;

        case E_FanDeiLightFct_Independent:
            rtval |= Fan_Fan1DeicingIndependent();
    }
    return rtval;
}

/* 风扇1运行 */
static Std_ReturnType Fan_Fan1Running(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    static E_EnableFlag DelayOffFlag = E_EnableFlag_DISABLE; /* 延时关闭，防止通道对应温度满足时，通道频繁开关导致风扇频繁开关 */
    static uint16_t DelayOffTime = 0;

    rtval |= Fan_Fan1CoolingLED();
    rtval |= Fan_Fan1Defogging();
    rtval |= Fan_Fan1Deicing();

    /* 测试 */
#if 0
    static uint16_t Cycle = 0;
    static uint8_t Direction = 0;
    if (Cycle == 0)
    {
        Direction = 0;
    }
    else if(Cycle == 50)
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

    if (Direction == 0)
    {
        gs_Fan1RunInfo.PwmCool = 20;
    }
    else if (Direction == 1)
    {
        gs_Fan1RunInfo.PwmCool = 84;
    }
#endif

    gs_Fan1RunInfo.PwmRun_Last = gs_Fan1RunInfo.PwmRun_Curr;

    E_UsageModeSts UsageMode;
    Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& UsageMode);
    switch( UsageMode )
    {
        case E_UsageModeSts_Abdnd:
        case E_UsageModeSts_InActv:
        case E_UsageModeSts_Cnvinc:
            gs_Fan1RunInfo.PwmRun_Curr = 0u;
            break;

        case E_UsageModeSts_Actv:
        case E_UsageModeSts_Drvg:
            if(gs_Fan1RunInfo.PwmCool >= gs_Fan1RunInfo.PwmDefog && gs_Fan1RunInfo.PwmCool >= gs_Fan1RunInfo.PwmDeice)
            {
                gs_Fan1RunInfo.PwmRun_Curr = gs_Fan1RunInfo.PwmCool;
                gs_Fan1RunInfo.Fan1RunMode = Fan1RunMode_Cooling;
            }
            else if(gs_Fan1RunInfo.PwmDefog >= gs_Fan1RunInfo.PwmDeice)
            {
                gs_Fan1RunInfo.PwmRun_Curr = gs_Fan1RunInfo.PwmDefog;
                gs_Fan1RunInfo.Fan1RunMode = Fan1RunMode_Defogging;
            }
            else
            {
                gs_Fan1RunInfo.PwmRun_Curr = gs_Fan1RunInfo.PwmDeice;
                gs_Fan1RunInfo.Fan1RunMode = Fan1RunMode_Deicing;
            }
    }

    if(gs_Fan1RunInfo.PwmRun_Last == 0 && gs_Fan1RunInfo.PwmRun_Curr > 0) /* 风扇1开启时间节点 */
    {
        DelayOffFlag = E_EnableFlag_DISABLE;
        gs_Fan1RunInfo.RunState = E_FanRunState_ON;

        gs_FanDidInfo.Fan1StartNum++;
        if(gs_Fan1RunInfo.Fan1RunMode == Fan1RunMode_Defogging)
            gs_FanDidInfo.Fan1StartDefNum++;
        else if(gs_Fan1RunInfo.Fan1RunMode == Fan1RunMode_Deicing)
            gs_FanDidInfo.Fan1StartDeiNum++;
    }
    else if(gs_Fan1RunInfo.PwmRun_Last > 0 && gs_Fan1RunInfo.PwmRun_Curr == 0) /* 风扇1关闭时间节点 */
    {
        if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
        {
            DelayOffFlag = E_EnableFlag_ENABLE;
            DelayOffTime = 0;
        }
        else
        {
            gs_Fan1RunInfo.RunState = E_FanRunState_OFF;
        }
    }

    if(DelayOffFlag == E_EnableFlag_ENABLE) /* 风扇1延时关闭 */
    {
        DelayOffTime += timebase;
        if(DelayOffTime >= 2000) /* 延时2s关闭 */
        {
            gs_Fan1RunInfo.RunState = E_FanRunState_OFF;
            DelayOffFlag = E_EnableFlag_DISABLE;
        }
    }

    switch( gs_FanConfigInfo.FanControlPin )       /* 匹配风扇1转速控制引脚配置 */
    {
        case E_FanControlPin_No:             /* 风扇1无控制引脚 */
            if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1*/
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_OFF)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1 */
            }
            break;

        case E_FanControlPin_RPMNotAllowed:  /* 风扇1不允许转速控制 */
        case E_FanControlPin_RPMAllowed:     /* 风扇1允许转速控制 */
            if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1高边供电*/
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_OFF)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
            }
            rtval |= Interface_EnablePulseGenerator(E_PulseGeneratorFunction_FanPwmControl, FAN1_PWM_CYCLE, gs_Fan1RunInfo.PwmRun_Curr); /* 跟随当前转速 */
    }
    return rtval;
}




/* 读取一次风扇1诊断引脚诊断结果，四种故障电平合一 */
static uint8_t Fan_GetFan1DiagnosInput(void)
{
    E_PinState Fan1DiagnosState;
    uint8_t Fan1DiagnosResult = 0u;
    static uint32_t BothEdgeNum_Last = 0u;
    static uint32_t BothEdgeNum_Curr = 0u;

    switch( gs_FanConfigInfo.FanDiagInputType ) /* 匹配风扇1故障输入类型 */
    {
        case E_FanDiagInputType_ErrorActive_L:
            Interface_GetPinState(E_PulseGeneratorFunction_FanDiag, & Fan1DiagnosState);
            if(Fan1DiagnosState == E_PinState_Low)
            {
                Fan1DiagnosResult = 1u;
            }
            else
            {
                Fan1DiagnosResult = 0u;
            }
            break;

        case E_FanDiagInputType_ErrorActive_H:
            Interface_GetPinState(E_PulseGeneratorFunction_FanDiag, & Fan1DiagnosState);
            if(Fan1DiagnosState == E_PinState_High)
            {
                Fan1DiagnosResult = 1u;
            }
            else
            {
                Fan1DiagnosResult = 0u;
            }
            break;

        case E_FanDiagInputType_FixedFrequency:
        case E_FanDiagInputType_VariableFrequency:
            BothEdgeNum_Last = BothEdgeNum_Curr;
            Interface_RequestResult(E_PulseGeneratorFunction_FanDiag, & BothEdgeNum_Curr);
            if((BothEdgeNum_Curr - BothEdgeNum_Last) == 0)
            {
                Fan1DiagnosResult = 1u;
            }
            else
            {
                Fan1DiagnosResult = 0u;
            }
    }
    return Fan1DiagnosResult;
}

/* 风扇1堵转诊断 */
static Std_ReturnType Fan_Fan1StallDiagnose(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if( gs_Fan1RunInfo.RunState == E_FanRunState_HWError ||
        gs_Fan1RunInfo.RunState == E_FanRunState_VoltError ||
        gs_Fan1RunInfo.RunState == E_FanRunState_StallError ) /* 风扇已经故障，退出 */
    {
        return rtval;
    }

    static uint16_t FanSupInrushTime_Counter    = 0;
    static uint16_t FanLockDebTime_Counter      = 0;
    static uint16_t FanLockProtOnTime0_Counter  = 0;
    static uint16_t FanLockRetryOffTime_Counter = 0;

    switch( gs_FanConfigInfo.FanDiagInputType ) /* 匹配风扇1故障输入类型 */
    {
        case E_FanDiagInputType_NoDiagnosePin: /* 没有故障输入引脚，依靠电流诊断 */
            if(gs_Fan1RunInfo.RunState == E_FanRunState_OFF) /* 等待诊断开始时间的过程中，风扇关闭，则把计时清零重置 */
            {
                if(FanSupInrushTime_Counter != 0)
                    FanSupInrushTime_Counter = 0;
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
            {
                if(FanSupInrushTime_Counter * timebase < gs_FanConfigInfo.FanSupInrushTime) /* 用任务循环时间计时，等待诊断开始时间 */
                    FanSupInrushTime_Counter++;
                else /* 计时时间到，开始诊断 */
                {
                    if(HSDManage_GetHSDOutputCurrent(E_HSChannel_HS0) > gs_FanConfigInfo.FanNomCurrent * (100 + gs_FanConfigInfo.FanNomCurTol) / 100) /* 堵转 */
                    {
                        HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                        gs_Fan1RunInfo.RunState = E_FanRunState_StallDiag;
                        FanSupInrushTime_Counter = 0;
                    }
                }
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_StallDiag)
            {
                if(FanLockProtOnTime0_Counter * timebase < gs_FanConfigInfo.FanLockProtOnTime0) /* 用任务循环时间计时，等待重启时间 */
                    FanLockProtOnTime0_Counter++;
                else  /* 计时时间到，开始重启 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1高边供电 */
                    gs_Fan1RunInfo.RunState = E_FanRunState_StallRetry;
                    FanLockProtOnTime0_Counter = 0;
                }
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_StallRetry)
            {
                if(FanSupInrushTime_Counter * timebase < gs_FanConfigInfo.FanSupInrushTime) /* 用任务循环时间计时，等待诊断开始时间 */
                    FanSupInrushTime_Counter++;
                else /* 计时时间到，开始诊断 */
                {
                    if(HSDManage_GetHSDOutputCurrent(E_HSChannel_HS0) > gs_FanConfigInfo.FanNomCurrent * (100 + gs_FanConfigInfo.FanNomCurTol) / 100) /* 还是堵转 */
                    {
                        HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                        gs_Fan1RunInfo.RunState = E_FanRunState_StallDiag;
                        FanSupInrushTime_Counter = 0;
                    }
                    else /* 堵转恢复，风扇继续运行 */
                    {
                        gs_Fan1RunInfo.RunState = E_FanRunState_ON;
                        FanSupInrushTime_Counter = 0;
                        FanLockRetryOffTime_Counter = 0;
                    }
                }
            }

            if(gs_Fan1RunInfo.RunState == E_FanRunState_StallDiag || gs_Fan1RunInfo.RunState == E_FanRunState_StallRetry)
            {
                if(FanLockRetryOffTime_Counter * timebase < gs_FanConfigInfo.FanLockRetryOffTime) /* 用任务循环时间计时，等待关闭重试时间 */
                    FanLockRetryOffTime_Counter++;
                else  /* 关闭重试时间到，不再进行诊断和重启 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                    gs_Fan1RunInfo.RunState = E_FanRunState_StallError;
                    FanSupInrushTime_Counter = 0;
                    FanLockProtOnTime0_Counter = 0;
                    FanLockRetryOffTime_Counter = 0;
                }
            }
            break;

        case E_FanDiagInputType_ErrorActive_L:
        case E_FanDiagInputType_ErrorActive_H:
        case E_FanDiagInputType_FixedFrequency:
        case E_FanDiagInputType_VariableFrequency: /* 有故障输入引脚，依靠故障电平输入诊断 */
            if(gs_Fan1RunInfo.RunState == E_FanRunState_OFF) /* 等待诊断开始时间或等待故障输入持续时间的过程中，风扇关闭，则把计时清零重置 */
            {
                if(FanSupInrushTime_Counter != 0)
                    FanSupInrushTime_Counter = 0;
                if(FanLockDebTime_Counter != 0)
                    FanLockDebTime_Counter = 0;
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
            {
                if(FanSupInrushTime_Counter * timebase < gs_FanConfigInfo.FanSupInrushTime) /* 用任务循环时间计时，等待诊断开始时间 */
                    FanSupInrushTime_Counter++;
                else /* 计时时间到，开始诊断 */
                {
                    if(Fan_GetFan1DiagnosInput() == 1) /* 诊断输入有故障 */
                    {
                        if(FanLockDebTime_Counter * timebase < gs_FanConfigInfo.FanLockDebTime) /* 用任务循环时间计时，等待故障输入持续时间 */
                            FanLockDebTime_Counter++;
                        else /* 计时时间到，确定堵转 */
                        {
                            HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                            gs_Fan1RunInfo.RunState = E_FanRunState_StallDiag;
                            FanLockDebTime_Counter = 0;
                            FanSupInrushTime_Counter = 0;
                        }
                    }
                    else /* 诊断输入无故障，或故障输入持续时间不足 */
                    {
                        if(FanLockDebTime_Counter != 0)
                            FanLockDebTime_Counter = 0;
                    }
                }
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_StallDiag)
            {
                if(FanLockProtOnTime0_Counter * timebase < gs_FanConfigInfo.FanLockProtOnTime0) /* 用任务循环时间计时，等待重启时间 */
                    FanLockProtOnTime0_Counter++;
                else  /* 计时时间到，开始重启 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1高边供电 */
                    gs_Fan1RunInfo.RunState = E_FanRunState_StallRetry;
                    FanLockProtOnTime0_Counter = 0;
                }
            }
            else if(gs_Fan1RunInfo.RunState == E_FanRunState_StallRetry)
            {
                if(FanSupInrushTime_Counter * timebase < gs_FanConfigInfo.FanSupInrushTime) /* 用任务循环时间计时，等待诊断开始时间 */
                    FanSupInrushTime_Counter++;
                else /* 计时时间到，开始诊断 */
                {
                    if(Fan_GetFan1DiagnosInput() == 1) /* 诊断输入有故障 */
                    {
                        if(FanLockDebTime_Counter * timebase < gs_FanConfigInfo.FanLockDebTime) /* 用任务循环时间计时，等待故障输入持续时间 */
                            FanLockDebTime_Counter++;
                        else /* 计时时间到，确定堵转 */
                        {
                            HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                            gs_Fan1RunInfo.RunState = E_FanRunState_StallDiag;
                            FanLockDebTime_Counter = 0;
                            FanSupInrushTime_Counter = 0;
                        }
                    }
                    else /* 诊断输入无故障，或故障输入持续时间不足，堵转恢复，风扇继续运行 */
                    {
                        gs_Fan1RunInfo.RunState = E_FanRunState_ON;
                        FanSupInrushTime_Counter = 0;
                        FanLockDebTime_Counter = 0;
                        FanLockRetryOffTime_Counter = 0;
                    }
                }
            }

            if(gs_Fan1RunInfo.RunState == E_FanRunState_StallDiag || gs_Fan1RunInfo.RunState == E_FanRunState_StallRetry)
            {
                if(FanLockRetryOffTime_Counter * timebase < gs_FanConfigInfo.FanLockRetryOffTime) /* 用任务循环时间计时，等待关闭重试时间 */
                    FanLockRetryOffTime_Counter++;
                else  /* 关闭重试时间到，不再进行诊断和重启 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                    gs_Fan1RunInfo.RunState = E_FanRunState_StallError;
                    FanSupInrushTime_Counter = 0;
                    FanLockDebTime_Counter = 0;
                    FanLockProtOnTime0_Counter = 0;
                    FanLockRetryOffTime_Counter = 0;
                }
            }
    }
    return rtval;
}

/* 风扇1电压和硬件检测 */
static Std_ReturnType Fan_Fan1VoltHWDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta Fan1HSDErrSta;

    Fan1HSDErrSta = HSDManage_GetHSDErrState(E_HSChannel_HS0);

    if(gs_Fan1RunInfo.RunState == E_FanRunState_ON || gs_Fan1RunInfo.RunState == E_FanRunState_VoltError) /* 风扇1开启时查看硬件故障状态 */
    {
        if(Fan1HSDErrSta == E_HSDErrSta_Normal)
        {
            gs_Fan1RunInfo.RunState = E_FanRunState_ON;
        }
        else if(Fan1HSDErrSta == E_HSDErrSta_VoltErr)
        {
            gs_Fan1RunInfo.RunState = E_FanRunState_VoltError;
        }
    }
    if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
    {
        U_HSDAndFan_Error FanHWErrorState;

        switch( gs_FanConfigInfo.FanControlPin )
        {
            case E_FanControlPin_No:            /* 风扇1无控制引脚 */
                if(Fan1HSDErrSta == E_HSDErrSta_HWDtcErr)
                {
                    gs_Fan1RunInfo.RunState = E_FanRunState_HWError;
                }
                break;

            case E_FanControlPin_RPMNotAllowed: /* 风扇1不允许转速控制 */
            case E_FanControlPin_RPMAllowed:    /* 风扇1允许转速控制 */
                FanHWErrorState = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorDtcState);
                if( FanHWErrorState.bits.FAN1_CtrLineShort2Gnd_ErrorConfirmed == 1 ||
                    FanHWErrorState.bits.FAN1_CtrLineShort2VCC_ErrorConfirmed == 1 ||
                    Fan1HSDErrSta == E_HSDErrSta_HWDtcErr )
                {
                    gs_Fan1RunInfo.RunState = E_FanRunState_HWError;
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                }
        }
    }
    return rtval;
}

/* 风扇2电压和硬件检测 */
static Std_ReturnType Fan_Fan2VoltHWDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta Fan2HSDErrSta;

    Fan2HSDErrSta = HSDManage_GetHSDErrState(gs_FanConfigInfo.Fan2HSDChannel);

    if(gs_Fan2RunInfo.RunState != E_FanRunState_OFF) /* 风扇1开启时查看硬件故障状态 */
    {
        if(Fan2HSDErrSta == E_HSDErrSta_Normal)
        {
            gs_Fan2RunInfo.RunState = E_FanRunState_ON;
        }
        else if(Fan2HSDErrSta == E_HSDErrSta_VoltErr)
        {
            gs_Fan2RunInfo.RunState = E_FanRunState_VoltError;
        }
        else if(Fan2HSDErrSta == E_HSDErrSta_HWDtcErr)
        {
            gs_Fan2RunInfo.RunState = E_FanRunState_HWError;
        }
    }
    return rtval;
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 风扇启动例程控制 */
Std_ReturnType Fan_StartRoutineCtr_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta Fan1HSDErrSta;
    E_HSDErrSta Fan2HSDErrSta;

    switch( gs_FanConfigInfo.FanNumber )
    {
        case E_FanNumber_NoFan:
            OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueAborted;
            OutBuffer[1] = E_FanRoutineInhiCond_Mismatch;
            break;

        case E_FanNumber_OneFan:
            Fan1HSDErrSta = HSDManage_GetHSDErrState(E_HSChannel_HS0);
            if(Fan1HSDErrSta == E_HSDErrSta_VoltErr)
            {
                OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueAborted;
                OutBuffer[1] = E_FanRoutineInhiCond_VoltOut;
            }
            else if(Fan1HSDErrSta == E_HSDErrSta_Normal)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1高边供电*/
                OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
                OutBuffer[1] = E_FanRoutineInhiCond_NoInhi;
            }
            break;

        case E_FanNumber_TwoFans:
            Fan1HSDErrSta = HSDManage_GetHSDErrState(E_HSChannel_HS0);
            Fan2HSDErrSta = HSDManage_GetHSDErrState(gs_FanConfigInfo.Fan2HSDChannel);
            if(Fan1HSDErrSta == E_HSDErrSta_VoltErr && Fan2HSDErrSta == E_HSDErrSta_VoltErr)
            {
                OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueAborted;
                OutBuffer[1] = E_FanRoutineInhiCond_VoltOut;
            }
            else if(Fan1HSDErrSta == E_HSDErrSta_Normal && Fan2HSDErrSta == E_HSDErrSta_Normal)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1高边供电*/
                HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_Act);  /* 打开风扇2 */
                OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
                OutBuffer[1] = E_FanRoutineInhiCond_NoInhi;
            }
    }
    ge_FanRoutineCtrFlag = E_EnableFlag_ENABLE;
    return rtval;
}

/* 风扇停止例程控制 */
Std_ReturnType Fan_StopRoutineCtr_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    switch( gs_FanConfigInfo.FanNumber )
    {
        case E_FanNumber_NoFan:
            OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueAborted;
            break;

        case E_FanNumber_OneFan:
            HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电*/
            OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
            break;

        case E_FanNumber_TwoFans:
            HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电*/
            HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_NoAct);  /* 关闭风扇2 */
            OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
    }
    ge_FanRoutineCtrFlag = E_EnableFlag_DISABLE;
    return rtval;
}

/* 风扇请求例程控制结果 */
Std_ReturnType Fan_RequestRoutineResult_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;
    switch( gs_FanConfigInfo.FanNumber )
    {
        case E_FanNumber_NoFan:
            OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueAborted;
            OutBuffer[1] = E_FanRoutineInhiCond_Mismatch;
            OutBuffer[2] = 0x00;
            OutBuffer[3] = 0x00;
            OutBuffer[4] = 0x00;
            OutBuffer[5] = 0x00;
            OutBuffer[6] = 0x00;
            break;

        case E_FanNumber_OneFan:
        case E_FanNumber_TwoFans:
            switch( gs_FanConfigInfo.FanDiagInputType ) /* 匹配风扇1故障输入类型 */
            {
                case E_FanDiagInputType_NoDiagnosePin: /* 没有故障输入引脚，依靠电流诊断 */
                    if(g_FanRoutineCtrStallErrSta == 1u) /* 堵转 */
                    {
                        OutBuffer[2] = 0x10;
                    }
                    else if(g_FanRoutineCtrStallErrSta == 0u)
                    {
                        OutBuffer[2] = 0x00;
                    }
                    break;

                case E_FanDiagInputType_ErrorActive_L:
                case E_FanDiagInputType_ErrorActive_H:
                case E_FanDiagInputType_FixedFrequency:
                case E_FanDiagInputType_VariableFrequency: /* 有故障输入引脚，依靠故障电平输入诊断 */
                    if(g_FanRoutineCtrStallErrSta == 1u) /* 堵转 */
                    {
                        OutBuffer[2] = 0x10;
                    }
                    else if(g_FanRoutineCtrStallErrSta == 0u)
                    {
                        OutBuffer[2] = 0x00;
                    }
            }
            OutBuffer[0] = (E_RoutineType_ContinuousRoutine << 4) + E_RoutineStatus_RoutinueCompleted;
            OutBuffer[1] = E_FanRoutineInhiCond_NoInhi;
            OutBuffer[3] = 0xFF;
            OutBuffer[4] = 0xFF;
            OutBuffer[5] = 0xFF;
            OutBuffer[6] = 0xFF;
    }
    return rtval;
}



/* 风扇DID控制回调函数 */
Std_ReturnType Fan_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    if(gs_FanConfigInfo.FanNumber == E_FanNumber_NoFan) /* 没有风扇 */
    {
        rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_FAN2Control, (uint32_t)gs_FanDidInfo.FAN2Control);
        rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1supply, (uint32_t)gs_FanDidInfo.Fan1Supply);
        rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1OutputControl, gs_FanDidInfo.Fan1OutputControl);
        return rtval;
    }

    uint8_t  DIDControlMask;
    uint32_t DIDIoctrData;

    switch( IOCtrTypeState )
    {
        case E_IOCtrType_ReturnControl:
            ge_FanIOCtrFlag = E_EnableFlag_DISABLE;
            break;

        case E_IOCtrType_FreeCurState:
            ge_FanIOCtrFlag = E_EnableFlag_ENABLE;

            rtval |= Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampFan, &DIDControlMask);

            if(DIDControlMask & 0x40) /* 风扇2开关控制 */
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_FAN2Control, (uint32_t)gs_FanDidInfo.FAN2Control);
            if(DIDControlMask & 0x20) /* 风扇1供电控制 */
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1supply, (uint32_t)gs_FanDidInfo.Fan1Supply);
            if(DIDControlMask & 0x10) /* 风扇1转速控制 */
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1OutputControl, gs_FanDidInfo.Fan1OutputControl);
            break;

        case E_IOCtrType_ShortTermAdjustment:
            ge_FanIOCtrFlag = E_EnableFlag_ENABLE;

            rtval |= Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampFan, &DIDControlMask);

            if(DIDControlMask & 0x40) /* 风扇2开关控制 */
            {
                rtval |= Interface_GetDidSignalIoctrData(DIDSIGNALNAME_ID_FAN2Control, &DIDIoctrData);

                if(DIDIoctrData == 0x0u)  /* 关闭信号 */
                {
                    HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_NoAct); /* 关闭风扇2 */
                    gs_FanDidInfo.FAN2Control = FAN2Control_NoActive;
                }
                else if(DIDIoctrData == 0x1u) /* 打开信号 */
                {
                    HSDManage_SetHSDActState(gs_FanConfigInfo.Fan2HSDChannel, E_HSDActSta_Act);  /* 打开风扇2 */
                    gs_FanDidInfo.FAN2Control = FAN2Control_Active;
                }
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_FAN2Control, (uint32_t)gs_FanDidInfo.FAN2Control);
            }

            if(DIDControlMask & 0x20) /* 风扇1供电控制 */
            {
                rtval |= Interface_GetDidSignalIoctrData(DIDSIGNALNAME_ID_Fan1supply, &DIDIoctrData);

                if(DIDIoctrData == 0x0u) /* 关闭信号 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); /* 关闭风扇1高边供电 */
                    gs_FanDidInfo.Fan1Supply = Fan1Supply_NoActive;
                }
                else if(DIDIoctrData == 0x1u) /* 开启信号 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); /* 打开风扇1高边供电*/
                    gs_FanDidInfo.Fan1Supply = Fan1Supply_Active;
                }
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1supply, (uint32_t)gs_FanDidInfo.Fan1Supply);
            }

            if(DIDControlMask & 0x10) /* 风扇1转速控制 */
            {
                rtval |= Interface_GetDidSignalIoctrData(DIDSIGNALNAME_ID_Fan1OutputControl, &DIDIoctrData);

                switch( gs_FanConfigInfo.FanControlPin ) /* 匹配风扇1转速控制引脚配置 */
                {
                    case E_FanControlPin_No:             /* 风扇1无控制引脚 */
                        break;

                    case E_FanControlPin_RPMNotAllowed:  /* 风扇1不允许转速控制 */
                        if(DIDIoctrData > 0)
                        {
                            rtval |= Interface_EnablePulseGenerator(E_PulseGeneratorFunction_FanPwmControl, FAN1_PWM_CYCLE, 100);
                            gs_FanDidInfo.Fan1OutputControl = 100;
                        }
                        else
                        {
                            rtval |= Interface_DisablePulseGenerator(E_PulseGeneratorFunction_FanPwmControl, FAN1_PWM_CYCLE, 0);
                            gs_FanDidInfo.Fan1OutputControl = 0;
                        }
                        break;

                    case E_FanControlPin_RPMAllowed:     /* 风扇1允许转速控制 */
                        if(DIDIoctrData > 100)
                        {
                            DIDIoctrData = 100;
                        }
                        rtval |= Interface_EnablePulseGenerator(E_PulseGeneratorFunction_FanPwmControl, FAN1_PWM_CYCLE, DIDIoctrData); /* 调节转速 */
                        gs_FanDidInfo.Fan1OutputControl = DIDIoctrData;
                }
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1OutputControl, gs_FanDidInfo.Fan1OutputControl);
            }
    }
    return rtval;
}

/* 设置风扇的DID数据，434B */
Std_ReturnType Fan_SetDID_434B_Fan(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1Diagnosis,       (uint32_t)gs_FanDidInfo.Fan1Diagnosis);
    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_FAN2Control,         (uint32_t)gs_FanDidInfo.FAN2Control);
    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1supply,          (uint32_t)gs_FanDidInfo.Fan1Supply);
    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1OutputControl,   gs_FanDidInfo.Fan1OutputControl);
    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_Fan1CurrentFeedback, gs_FanDidInfo.Fan1CurrentFeedback);

    return rtval;
}

/* 设置风扇的DID数据，43D5 */
Std_ReturnType Fan_SetDID_43D5_FanSupplyVoltage(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_FanSupplyVol, gs_FanDidInfo.Fan1SupplyVoltage);

    return rtval;
}







/* 风扇启动初始化 */
void Fan_Init(void)
{
    Fan_GetParameterIntoInfo();

    if(gs_FanConfigInfo.FanNumber != E_FanNumber_NoFan) /* 有风扇 */
    {
        /* 诊断引脚输入初始化*/
        switch( gs_FanConfigInfo.FanDiagInputType )
        {
            case E_FanDiagInputType_ErrorActive_L:
            case E_FanDiagInputType_ErrorActive_H:
                Interface_SetPinMode(E_PulseGeneratorFunction_FanDiag, E_PinMode_GPIO);
                break;

            case E_FanDiagInputType_FixedFrequency:
            case E_FanDiagInputType_VariableFrequency:
                Interface_SetPinMode(E_PulseGeneratorFunction_FanDiag, E_PinMode_ICU);
                Interface_IcuStart(E_PulseGeneratorFunction_FanDiag, E_PinMode_IcuBothEdge);
        }
        gs_FanDidInfo.Fan1StartNum    = 0u;
        gs_FanDidInfo.Fan1StartDeiNum = 0u;
        gs_FanDidInfo.Fan1StartDefNum = 0u;
        gs_FanDidInfo.Fan1Runtime     = 0u;
    }
}

/* 风扇主函数 */
void Fan_MainFunction(uint8_t timebase)
{
    if(gs_FanConfigInfo.FanNumber == E_FanNumber_NoFan) /* 没有风扇，直接退出 */
    {
        return;
    }

    if(ge_FanIOCtrFlag == E_EnableFlag_DISABLE && ge_FanRoutineCtrFlag == E_EnableFlag_DISABLE) /* 正常工作模式 */
    {
        Fan_Fan1Running(timebase);
        Fan_Fan1StallDiagnose(timebase);
        Fan_Fan1VoltHWDetect();

        /* 设置堵转DTC */
        if(gs_Fan1RunInfo.RunState == E_FanRunState_StallError)
        {
            Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_FAN1_Stall, 1);
        }
        else
        {
            Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_FAN1_Stall, 0);
        }

        /* 设置风扇DID */
        if( gs_Fan1RunInfo.RunState == E_FanRunState_VoltError ||
            gs_Fan1RunInfo.RunState == E_FanRunState_HWError ||
            gs_Fan1RunInfo.RunState == E_FanRunState_StallError ) /* 设置风扇1故障状态DID */
        {
            gs_FanDidInfo.Fan1Diagnosis = Fan1Diagnosis_Error;
        }
        else
        {
            gs_FanDidInfo.Fan1Diagnosis = Fan1Diagnosis_NoErr;
        }
        if(HSDManage_GetHSDSwitchState(E_HSChannel_HS0) == E_HSDSwitchSta_ON)
        {
            gs_FanDidInfo.Fan1Supply = Fan1Supply_Active;
        }
        else
        {
            gs_FanDidInfo.Fan1Supply = Fan1Supply_NoActive;
        }
        switch( gs_FanConfigInfo.FanControlPin )
        {
            case E_FanControlPin_RPMNotAllowed:
            case E_FanControlPin_RPMAllowed:
                gs_FanDidInfo.Fan1OutputControl = gs_Fan1RunInfo.PwmRun_Curr;
        }
        gs_FanDidInfo.Fan1CurrentFeedback = HSDManage_GetHSDOutputCurrent(E_HSChannel_HS0); /* 设置风扇1电流值DID */
        if(gs_Fan1RunInfo.RunState == E_FanRunState_ON)
        {
            gs_FanDidInfo.Fan1Runtime += timebase; /* 风扇1运行时间DID累计；ms */
        }
        gs_FanDidInfo.Fan1SupplyVoltage = (uint8_t)(HSDManage_GetHSDSupplyVoltage() * 10);

        /* 有风扇2 */
        if(gs_FanConfigInfo.FanNumber == E_FanNumber_TwoFans)
        {
            Fan_Fan2CoolingLED();
            Fan_Fan2VoltHWDetect();

            if(HSDManage_GetHSDSwitchState(gs_FanConfigInfo.Fan2HSDChannel) == E_HSDSwitchSta_ON)
            {
                gs_FanDidInfo.FAN2Control = FAN2Control_Active;
            }
            else
            {
                gs_FanDidInfo.FAN2Control = FAN2Control_NoActive;
            }
        }

        /* 设置DID 43A8 风扇统计数据 */
        DidSignalManager_SetDid43A8SignalData(DIDSIGNALNAME_ID_TotalNumFanStart,      gs_FanDidInfo.Fan1StartNum);
        DidSignalManager_SetDid43A8SignalData(DIDSIGNALNAME_ID_TotalNumFanStartDeic,  gs_FanDidInfo.Fan1StartDeiNum);
        DidSignalManager_SetDid43A8SignalData(DIDSIGNALNAME_ID_TotalNumFanStartDefog, gs_FanDidInfo.Fan1StartDefNum);
        DidSignalManager_SetDid43A8SignalData(DIDSIGNALNAME_ID_TotalRunTimeFan,       gs_FanDidInfo.Fan1Runtime);
    }
    else if(ge_FanRoutineCtrFlag == E_EnableFlag_ENABLE) /* 例程控制模式下检测堵转状态 */
    {
        static uint8_t FanStallComformNum = 0u;

        switch( gs_FanConfigInfo.FanDiagInputType ) /* 匹配风扇1故障输入类型 */
        {
            case E_FanDiagInputType_NoDiagnosePin: /* 没有故障输入引脚，依靠电流诊断 */
                if(HSDManage_GetHSDOutputCurrent(E_HSChannel_HS0) > gs_FanConfigInfo.FanNomCurrent * (100 + gs_FanConfigInfo.FanNomCurTol) / 100) /* 堵转 */
                {
                    if(FanStallComformNum < 10u)
                        FanStallComformNum++;
                }
                else
                {
                    if(FanStallComformNum > 0u)
                        FanStallComformNum--;
                }
                break;

            case E_FanDiagInputType_ErrorActive_L:
            case E_FanDiagInputType_ErrorActive_H:
            case E_FanDiagInputType_FixedFrequency:
            case E_FanDiagInputType_VariableFrequency: /* 有故障输入引脚，依靠故障电平输入诊断 */
                if(Fan_GetFan1DiagnosInput() == 1u) /* 堵转 */
                {
                    if(FanStallComformNum < 10u)
                        FanStallComformNum++;
                }
                else
                {
                    if(FanStallComformNum > 0u)
                        FanStallComformNum--;
                }
        }
        if(FanStallComformNum >= 10u)
        {
            g_FanRoutineCtrStallErrSta = 1u;
        }
        else if(FanStallComformNum <= 5u)
        {
            g_FanRoutineCtrStallErrSta = 0u;
        }
    }
}

/* 风扇1控制线DTC检测设置 */
Std_ReturnType Fan_Fan1CtrLineDtcErrDetect_10ms(void)
{
    Std_ReturnType rtval = E_OK;
    E_AdcAccuracy Fan1CtrLineAdcAccuracy;
    uint32_t AdcDigitalValue;
    static uint8_t Fan1CtrLineVoltage[10] = {0}; /* AD采集的电压，结果*10 */
    static uint8_t VoltageGetNum = 0;

    switch( gs_FanConfigInfo.FanControlPin )
    {
        case E_FanControlPin_No:            /* 风扇1无控制引脚 */
            break;

        case E_FanControlPin_RPMNotAllowed: /* 风扇1不允许转速控制 */
        case E_FanControlPin_RPMAllowed:    /* 风扇1允许转速控制 */
            rtval |= Interface_GetAdcAccuracy(E_AdcFunction_FanCtr, & Fan1CtrLineAdcAccuracy);
            rtval |= Interface_GetAdcDigitalValue(E_AdcFunction_FanCtr, & AdcDigitalValue);
            if(rtval != E_OK)
            {
                return rtval;
            }
            switch( Fan1CtrLineAdcAccuracy )
            {
                case E_AdcAccuracy_Bit8:
                    Fan1CtrLineVoltage[VoltageGetNum++] = 50u * AdcDigitalValue / 0xFFu;
                    break;
                case E_AdcAccuracy_Bit10:
                    Fan1CtrLineVoltage[VoltageGetNum++] = 50u * AdcDigitalValue / 0x3FFu;
                    break;
                case E_AdcAccuracy_Bit12:
                    Fan1CtrLineVoltage[VoltageGetNum++] = 50u * AdcDigitalValue / 0xFFFu;
                    break;
                case E_AdcAccuracy_Bit24:
                    Fan1CtrLineVoltage[VoltageGetNum++] = 50u * AdcDigitalValue / 0xFFFFFFu;
                    break;
                case E_AdcAccuracy_Bit32:
                    Fan1CtrLineVoltage[VoltageGetNum++] = 50u * AdcDigitalValue / 0xFFFFFFFFu;
            }
            if(VoltageGetNum == 10) /* 接收到一组数据 */
            {
                if(gs_Fan1RunInfo.PwmRun_Last >= 20) /* 开始检测对地短路 */
                {
                    uint8_t i;
                    uint8_t HighLevelNum = 0;
                    static uint8_t Short2GndNum = 0;

                    for(i = 0; i < 10; i++)
                    {
                        if(Fan1CtrLineVoltage[i] > 15)
                        {
                            HighLevelNum++;
                        }
                    }
                    if(HighLevelNum == 0) /* 检测到一次对地短路 */
                    {
                        if(Short2GndNum < 50)
                        {
                            Short2GndNum++;
                        }
                    }
                    else
                    {
                        if(Short2GndNum > 0)
                        {
                            Short2GndNum--;
                        }
                    }
                    if(Short2GndNum == 50) /* 达到对地短路阈值 */
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_FAN1_CtrLineShort2Gnd, 1);
                    }
                    else if(Short2GndNum == 0)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_FAN1_CtrLineShort2Gnd, 0);
                    }
                }
                else if(gs_Fan1RunInfo.PwmRun_Last <= 80) /* 开始检测对电源短路 */
                {
                    uint8_t i;
                    uint8_t LowLevelNum = 0;
                    static uint8_t Short2VCCNum = 0;

                    for(i = 0; i < 10; i++)
                    {
                        if(Fan1CtrLineVoltage[i] < 15)
                        {
                            LowLevelNum++;
                        }
                    }
                    if(LowLevelNum == 0) /* 检测到一次对电源短路 */
                    {
                        if(Short2VCCNum < 50)
                        {
                            Short2VCCNum++;
                        }
                    }
                    else
                    {
                        if(Short2VCCNum > 0)
                        {
                            Short2VCCNum--;
                        }
                    }
                    if(Short2VCCNum == 50) /* 达到对电源短路阈值 */
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_FAN1_CtrLineShort2VCC, 1);
                    }
                    else if(Short2VCCNum == 0)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_FAN1_CtrLineShort2VCC, 0);
                    }
                }
                VoltageGetNum = 0;
            }
    }
    return rtval;
}


/* 风扇1与近光灯故障同步设置 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t Fan_GetFanFaultSignal(void)
{
    switch( gs_FanConfigInfo.FanFaultSignal )
    {
        case E_FanFaultSignal_No:
            break;

        case E_FanFaultSignal_YES:
        if( gs_Fan1RunInfo.RunState == E_FanRunState_HWError ||
            gs_Fan1RunInfo.RunState == E_FanRunState_VoltError ||
            gs_Fan1RunInfo.RunState == E_FanRunState_StallError )
        {
            return 1;
        }
    }
    return 0;
}






