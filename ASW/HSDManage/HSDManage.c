/********************************
 * HSDManage.c
 *
 *  Created on: 2024/4/17
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HSDManage.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_HSDManageConfigInfo gs_HSDManageConfigInfo;
static S_HSDManageRunInfo gs_HSDManageRunInfo = 
{
    .AllHSDVoltage = 0.0,
    .HSD0Current = 0u,
    .HSD1Current = 0u,
    .HSD2Current = 0u,
    .HSD3Current = 0u,
    .HSDHWRTErrSta.HsdAndFanError = 0u,
    .HSDHWDtcErrSta.HsdAndFanError = 0u,
    .HSDCtrFbSta.State = 0u,
    .HSD0RunState = E_HSDRunState_OFF,
    .HSD1RunState = E_HSDRunState_OFF,
    .HSD2RunState = E_HSDRunState_OFF,
    .HSD3RunState = E_HSDRunState_OFF,
    .HSD0ErrSta   = E_HSDErrSta_Normal,
    .HSD1ErrSta   = E_HSDErrSta_Normal,
    .HSD2ErrSta   = E_HSDErrSta_Normal,
    .HSD3ErrSta   = E_HSDErrSta_Normal
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

/* 读取高边管理参数配置并存放 */
static Std_ReturnType HSDManage_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    switch( Get_pFanNumber() )
    {
        case 1:
            gs_HSDManageConfigInfo.HSD0Func = E_HSDFunction_NA;
            break;
        case 2:
        case 4:
            gs_HSDManageConfigInfo.HSD0Func = E_HSDFunction_Fan1;
    }
    gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_NA;
    gs_HSDManageConfigInfo.HSD2Func = E_HSDFunction_NA;
    gs_HSDManageConfigInfo.HSD3Func = E_HSDFunction_NA;
    switch( GetChannelMaskByLightFunction(E_LogoLamp) & 0x7000 )
    {
        case 0x1000:
            gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_LOGO;
            break;
        case 0x2000:
            gs_HSDManageConfigInfo.HSD2Func = E_HSDFunction_LOGO;
            break;
        case 0x4000:
            gs_HSDManageConfigInfo.HSD3Func = E_HSDFunction_LOGO;
    }
    switch( GetChannelMaskByLightFunction(E_Fan2) & 0x7000 )
    {
        case 0x1000:
            gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_Fan2;
            break;
        case 0x2000:
            gs_HSDManageConfigInfo.HSD2Func = E_HSDFunction_Fan2;
            break;
        case 0x4000:
            gs_HSDManageConfigInfo.HSD3Func = E_HSDFunction_Fan2;
    }
    switch( GetChannelMaskByLightFunction(E_SideMarkerLamp) & 0x7000 )
    {
        case 0x1000:
            gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_SML;
            break;
        case 0x2000:
            gs_HSDManageConfigInfo.HSD2Func = E_HSDFunction_SML;
            break;
        case 0x4000:
            gs_HSDManageConfigInfo.HSD3Func = E_HSDFunction_SML;
    }
    switch( GetChannelMaskByLightFunction(E_DC_Motor) & 0x7000 )
    {
        case 0x1000:
            gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_DcMot;
            break;
        case 0x2000:
            gs_HSDManageConfigInfo.HSD2Func = E_HSDFunction_DcMot;
            break;
        case 0x4000:
            gs_HSDManageConfigInfo.HSD3Func = E_HSDFunction_DcMot;
    }
    switch( GetChannelMaskByLightFunction(E_LMM_Supply) & 0x7000 )
    {
        case 0x1000:
            gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_LMM;
            break;
        case 0x2000:
            gs_HSDManageConfigInfo.HSD2Func = E_HSDFunction_LMM;
            break;
        case 0x4000:
            gs_HSDManageConfigInfo.HSD3Func = E_HSDFunction_LMM;
    }

    switch( gs_HSDManageConfigInfo.HSD0Func )
    {
        case E_HSDFunction_NA:
            gs_HSDManageConfigInfo.HSD0MaxVolt = 0;
            gs_HSDManageConfigInfo.HSD0MinVolt = 0;
            break;

        case E_HSDFunction_LMM:
        case E_HSDFunction_SML:
        case E_HSDFunction_LOGO:
            gs_HSDManageConfigInfo.HSD0MaxVolt = 202;
            gs_HSDManageConfigInfo.HSD0MinVolt = 65;
            break;

        case E_HSDFunction_Fan1:
        case E_HSDFunction_Fan2:
        case E_HSDFunction_DcMot:
            gs_HSDManageConfigInfo.HSD0MaxVolt = Get_pFanMaxVolt();
            gs_HSDManageConfigInfo.HSD0MinVolt = Get_pFanMinVolt();
            if(gs_HSDManageConfigInfo.HSD0MaxVolt > 202)
            {
                gs_HSDManageConfigInfo.HSD0MaxVolt = 202;
            }
            if(gs_HSDManageConfigInfo.HSD0MinVolt < 65)
            {
                gs_HSDManageConfigInfo.HSD0MinVolt = 65;
            }
    }
    switch( gs_HSDManageConfigInfo.HSD1Func )
    {
        case E_HSDFunction_NA:
            gs_HSDManageConfigInfo.HSD1MaxVolt = 0;
            gs_HSDManageConfigInfo.HSD1MinVolt = 0;
            break;

        case E_HSDFunction_LMM:
        case E_HSDFunction_SML:
        case E_HSDFunction_LOGO:
            gs_HSDManageConfigInfo.HSD1MaxVolt = 202;
            gs_HSDManageConfigInfo.HSD1MinVolt = 65;
            break;

        case E_HSDFunction_Fan1:
        case E_HSDFunction_Fan2:
        case E_HSDFunction_DcMot:
            gs_HSDManageConfigInfo.HSD1MaxVolt = Get_pHSDMaxVolt(E_HSChannel_HS1);
            gs_HSDManageConfigInfo.HSD1MinVolt = Get_pHSDMinVolt(E_HSChannel_HS1);
            if(gs_HSDManageConfigInfo.HSD1MaxVolt > 202)
            {
                gs_HSDManageConfigInfo.HSD1MaxVolt = 202;
            }
            if(gs_HSDManageConfigInfo.HSD1MinVolt < 65)
            {
                gs_HSDManageConfigInfo.HSD1MinVolt = 65;
            }
    }
    switch( gs_HSDManageConfigInfo.HSD2Func )
    {
        case E_HSDFunction_NA:
            gs_HSDManageConfigInfo.HSD2MaxVolt = 0;
            gs_HSDManageConfigInfo.HSD2MinVolt = 0;
            break;

        case E_HSDFunction_LMM:
        case E_HSDFunction_SML:
        case E_HSDFunction_LOGO:
            gs_HSDManageConfigInfo.HSD2MaxVolt = 202;
            gs_HSDManageConfigInfo.HSD2MinVolt = 65;
            break;

        case E_HSDFunction_Fan1:
        case E_HSDFunction_Fan2:
        case E_HSDFunction_DcMot:
            gs_HSDManageConfigInfo.HSD2MaxVolt = Get_pHSDMaxVolt(E_HSChannel_HS2);
            gs_HSDManageConfigInfo.HSD2MinVolt = Get_pHSDMinVolt(E_HSChannel_HS2);
            if(gs_HSDManageConfigInfo.HSD2MaxVolt > 202)
            {
                gs_HSDManageConfigInfo.HSD2MaxVolt = 202;
            }
            if(gs_HSDManageConfigInfo.HSD2MinVolt < 65)
            {
                gs_HSDManageConfigInfo.HSD2MinVolt = 65;
            }
    }
    switch( gs_HSDManageConfigInfo.HSD3Func )
    {
        case E_HSDFunction_NA:
            gs_HSDManageConfigInfo.HSD3MaxVolt = 0;
            gs_HSDManageConfigInfo.HSD3MinVolt = 0;
            break;

        case E_HSDFunction_LMM:
        case E_HSDFunction_SML:
        case E_HSDFunction_LOGO:
            gs_HSDManageConfigInfo.HSD3MaxVolt = 202;
            gs_HSDManageConfigInfo.HSD3MinVolt = 65;
            break;

        case E_HSDFunction_Fan1:
        case E_HSDFunction_Fan2:
        case E_HSDFunction_DcMot:
            gs_HSDManageConfigInfo.HSD3MaxVolt = Get_pHSDMaxVolt(E_HSChannel_HS3);
            gs_HSDManageConfigInfo.HSD3MinVolt = Get_pHSDMinVolt(E_HSChannel_HS3);
            if(gs_HSDManageConfigInfo.HSD3MaxVolt > 202)
            {
                gs_HSDManageConfigInfo.HSD3MaxVolt = 202;
            }
            if(gs_HSDManageConfigInfo.HSD3MinVolt < 65)
            {
                gs_HSDManageConfigInfo.HSD3MinVolt = 65;
            }
    }
    return rtval;
}

/* 刷新高边供电电压值，电压值*10 */
/* 所有高边供电电压一致 */
static Std_ReturnType HSDManage_RefreshHSDSupplyVoltageValue(void)
{
    Std_ReturnType rtval = E_OK;
    double SupplyVoltage;

    rtval |= Interface_GetMaxVolBetweenKL15AndKL56(& SupplyVoltage);
    if(rtval == E_OK)
    {
        gs_HSDManageRunInfo.AllHSDVoltage = SupplyVoltage * 10;
    }
    return rtval;
}

/* 刷新高边输出电流值，mA */
static Std_ReturnType HSDManage_RefreshHSDCurrentValue(void)
{
    Std_ReturnType rtval = E_OK;
    uint16_t CurrentValueBuffer = 0u;
    
    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0SwitchSta == E_HSDSwitchSta_ON)
    {
        if(Interface_GetHighSideChannelCurrent(E_HSChannel_HS0, &CurrentValueBuffer) == E_OK)
        {
            gs_HSDManageRunInfo.HSD0Current = CurrentValueBuffer;
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0SwitchSta == E_HSDSwitchSta_OFF)
    {
        gs_HSDManageRunInfo.HSD0Current = 0u;
    }

    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1SwitchSta == E_HSDSwitchSta_ON)
    {
        if(Interface_GetHighSideChannelCurrent(E_HSChannel_HS1, &CurrentValueBuffer) == E_OK)
        {
            gs_HSDManageRunInfo.HSD1Current = CurrentValueBuffer;
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1SwitchSta == E_HSDSwitchSta_OFF)
    {
        gs_HSDManageRunInfo.HSD1Current = 0u;
    }

    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2SwitchSta == E_HSDSwitchSta_ON)
    {
        if(Interface_GetHighSideChannelCurrent(E_HSChannel_HS2, &CurrentValueBuffer) == E_OK)
        {
            gs_HSDManageRunInfo.HSD2Current = CurrentValueBuffer;
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2SwitchSta == E_HSDSwitchSta_OFF)
    {
        gs_HSDManageRunInfo.HSD2Current = 0u;
    }
    
    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3SwitchSta == E_HSDSwitchSta_ON)
    {
        if(Interface_GetHighSideChannelCurrent(E_HSChannel_HS3, &CurrentValueBuffer) == E_OK)
        {
            gs_HSDManageRunInfo.HSD3Current = CurrentValueBuffer;
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3SwitchSta == E_HSDSwitchSta_OFF)
    {
        gs_HSDManageRunInfo.HSD3Current = 0u;
    }
    return rtval;
}

/* 刷新高边硬件故障状态值 */
static Std_ReturnType HSDManage_RefreshHSDHWErrorStateValue(void)
{
    Std_ReturnType rtval = E_OK;

    gs_HSDManageRunInfo.HSDHWRTErrSta = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorRealTimeState);
    gs_HSDManageRunInfo.HSDHWDtcErrSta = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorDtcState);
    return rtval;
}

/* 刷新高边开关状态 */
static Std_ReturnType HSDManage_RefreshHSDSwitchState(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDChannelSwitchState HSDChannelSwitchState;

    Interface_GetHighSideState(E_HSChannel_HS0, & HSDChannelSwitchState);
    gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0SwitchSta = (E_HSDSwitchSta)HSDChannelSwitchState;

    Interface_GetHighSideState(E_HSChannel_HS1, & HSDChannelSwitchState);
    gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1SwitchSta = (E_HSDSwitchSta)HSDChannelSwitchState;

    Interface_GetHighSideState(E_HSChannel_HS2, & HSDChannelSwitchState);
    gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2SwitchSta = (E_HSDSwitchSta)HSDChannelSwitchState;

    Interface_GetHighSideState(E_HSChannel_HS3, & HSDChannelSwitchState);
    gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3SwitchSta = (E_HSDSwitchSta)HSDChannelSwitchState;
    return rtval;
}

/* 高边HSD0电压检测 */
static Std_ReturnType HSDManage_HSD0Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_HSDManageConfigInfo.HSD0Func == E_HSDFunction_NA)
    {
        return rtval;
    }

    static uint16_t HSD0HWErrStartTime = 0;

    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0ActSta == E_HSDActSta_Act)
    {
        if(gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_VoltErr) /* 电压检测 */
        {
            switch( gs_HSDManageConfigInfo.HSD0Func )
            {
                /* case E_HSDFunction_LMM: */
                case E_HSDFunction_SML:
                case E_HSDFunction_LOGO:
                case E_HSDFunction_Fan2:
                case E_HSDFunction_DcMot:
                    break;

                case E_HSDFunction_Fan1: /* 高边通道HSD0固定给Fan1 */
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD0MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD0MaxVolt) /* 过压 */
                    {
                        gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_OverVolt1Stop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD0MaxVolt - 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD0MinVolt + 10 ) /* 正常 */
                    {
                        gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_ON;
                    }

                    switch(gs_HSDManageRunInfo.HSD0RunState)
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_Normal;
                            break;
                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_VoltErr;
                            break;
                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_VoltErr;
                    }
            }
        }
        if(gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_HWRTErr) /* 硬件检测 */
        {
            if( gs_HSDManageRunInfo.HSDHWRTErrSta.bits.FAN1_SupplyShort2Gnd_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.FAN1_SupplyOpenOrShort2VCC_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.FAN1_HSDOverCur_ErrorConfirmed == 1 )
            {
                gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_HWRTErr;
            }
            else
            {
                gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_Normal;
            }
            
            if(HSD0HWErrStartTime < HSD_HW_TIME)
            {
                HSD0HWErrStartTime += timebase;
            }
            else
            {
                if( gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.FAN1_SupplyShort2Gnd_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.FAN1_SupplyOpenOrShort2VCC_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.FAN1_HSDOverCur_ErrorConfirmed == 1 )
                {
                    rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
                    gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_HWError;
                    gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_HWDtcErr;
                }
            }
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0ActSta == E_HSDActSta_NoAct)
    {
        switch( gs_HSDManageConfigInfo.HSD0Func )
        {
            /* case E_HSDFunction_LMM: */
            case E_HSDFunction_SML:
            case E_HSDFunction_LOGO:
            case E_HSDFunction_Fan1:
            case E_HSDFunction_Fan2:
            case E_HSDFunction_DcMot:
                rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
                HSD0HWErrStartTime = 0;
                gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_OFF;
                gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_Normal;
        }
    }
    return rtval;
}

/* 高边HSD1电压检测 */
static Std_ReturnType HSDManage_HSD1Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_HSDManageConfigInfo.HSD1Func == E_HSDFunction_NA)
    {
        return rtval;
    }

    static uint16_t HSD1HWErrStartTime = 0;

    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1ActSta == E_HSDActSta_Act)
    {
        if(gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_VoltErr) /* 电压检测 */
        {
            static uint16_t HSD1OverVolt1DelayTime = 0;
            static uint16_t HSD1OverVolt2DelayTime = 0;

            switch( gs_HSDManageConfigInfo.HSD1Func )
            {
                /* case E_HSDFunction_LMM: */
                case E_HSDFunction_SML:
                case E_HSDFunction_LOGO:
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD1MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD1MinVolt + 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD1MaxVolt - 10 ) /* 正常或恢复正常 */
                    {
                        gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_ON;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD1MaxVolt && gs_HSDManageRunInfo.AllHSDVoltage <= 265) /* 过压一级延时 */
                    {
                        if(gs_HSDManageRunInfo.HSD1RunState != E_HSDRunState_OverVolt1Stop && gs_HSDManageRunInfo.HSD1RunState != E_HSDRunState_OverVolt2Stop)
                        {
                            if(gs_HSDManageRunInfo.HSD1RunState != E_HSDRunState_OverVolt1Delay)
                            {
                                HSD1OverVolt1DelayTime = 0;
                                gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OverVolt1Delay;
                            }
                        }
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > 265) /* 过压二级延时 */
                    {
                        if(gs_HSDManageRunInfo.HSD1RunState != E_HSDRunState_OverVolt1Stop && gs_HSDManageRunInfo.HSD1RunState != E_HSDRunState_OverVolt2Stop)
                        {
                            if(gs_HSDManageRunInfo.HSD1RunState != E_HSDRunState_OverVolt2Delay)
                            {
                                HSD1OverVolt2DelayTime = 0;
                                gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OverVolt2Delay;
                            }
                        }
                    }

                    switch( gs_HSDManageRunInfo.HSD1RunState )
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
                            break;

                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_VoltErr;
                            break;

                        case E_HSDRunState_OverVolt1Delay:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
                            HSD1OverVolt1DelayTime += timebase;
                            if(HSD1OverVolt1DelayTime >= 63000u) /* 延时时间到，故障 */
                            {
                                gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OverVolt1Stop;
                            }
                            break;

                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_VoltErr;
                            break;

                        case E_HSDRunState_OverVolt2Delay:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
                            HSD1OverVolt2DelayTime += timebase;
                            if(HSD1OverVolt2DelayTime >= 400u) /* 延时时间到，故障 */
                            {
                                gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OverVolt2Stop;
                            }
                            break;

                        case E_HSDRunState_OverVolt2Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_VoltErr;
                    }
                    break;

                case E_HSDFunction_Fan1:
                case E_HSDFunction_Fan2:
                case E_HSDFunction_DcMot:
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD1MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD1MaxVolt) /* 过压 */
                    {
                        gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OverVolt1Stop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD1MaxVolt - 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD1MinVolt + 10 ) /* 正常 */
                    {
                        gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_ON;
                    }

                    switch(gs_HSDManageRunInfo.HSD1RunState)
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
                            break;
                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_VoltErr;
                            break;
                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_VoltErr;
                    }
            }
        }
        if(gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_HWRTErr) /* 硬件检测 */
        {
            if( gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD1_OverCur_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD1_Shor2Gnd_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD1_OpenOrShort2Vcc_ErrorConfirmed == 1 )
            {
                gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_HWRTErr;
            }
            else
            {
                gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
            }
            
            if(HSD1HWErrStartTime < HSD_HW_TIME)
            {
                HSD1HWErrStartTime += timebase;
            }
            else
            {
                if( gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD1_OverCur_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD1_Shor2Gnd_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD1_OpenOrShort2Vcc_ErrorConfirmed == 1 )
                {
                    rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                    gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_HWError;
                    gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_HWDtcErr;
                }
            }
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1ActSta == E_HSDActSta_NoAct)
    {
        switch( gs_HSDManageConfigInfo.HSD1Func )
        {
            /* case E_HSDFunction_LMM: */
            case E_HSDFunction_SML:
            case E_HSDFunction_LOGO:
            case E_HSDFunction_Fan1:
            case E_HSDFunction_Fan2:
            case E_HSDFunction_DcMot:
                rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                HSD1HWErrStartTime = 0;
                gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OFF;
                gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
        }
    }
    return rtval;
}

/* 高边HSD2电压检测 */
static Std_ReturnType HSDManage_HSD2Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_HSDManageConfigInfo.HSD2Func == E_HSDFunction_NA)
    {
        return rtval;
    }

    static uint16_t HSD2HWErrStartTime = 0;

    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2ActSta == E_HSDActSta_Act)
    {
        if(gs_HSDManageRunInfo.HSD2ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD2ErrSta == E_HSDErrSta_VoltErr) /* 电压检测 */
        {
            static uint16_t HSD2OverVolt1DelayTime = 0;
            static uint16_t HSD2OverVolt2DelayTime = 0;

            switch( gs_HSDManageConfigInfo.HSD2Func )
            {
                /* case E_HSDFunction_LMM: */
                case E_HSDFunction_SML:
                case E_HSDFunction_LOGO:
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD2MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD2MinVolt + 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD2MaxVolt - 10 ) /* 正常或恢复正常 */
                    {
                        gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_ON;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD2MaxVolt && gs_HSDManageRunInfo.AllHSDVoltage <= 265) /* 过压一级延时 */
                    {
                        if(gs_HSDManageRunInfo.HSD2RunState != E_HSDRunState_OverVolt1Stop && gs_HSDManageRunInfo.HSD2RunState != E_HSDRunState_OverVolt2Stop)
                        {
                            if(gs_HSDManageRunInfo.HSD2RunState != E_HSDRunState_OverVolt1Delay)
                            {
                                HSD2OverVolt1DelayTime = 0;
                                gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_OverVolt1Delay;
                            }
                        }
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > 265) /* 过压二级延时 */
                    {
                        if(gs_HSDManageRunInfo.HSD2RunState != E_HSDRunState_OverVolt1Stop && gs_HSDManageRunInfo.HSD2RunState != E_HSDRunState_OverVolt2Stop)
                        {
                            if(gs_HSDManageRunInfo.HSD2RunState != E_HSDRunState_OverVolt2Delay)
                            {
                                HSD2OverVolt2DelayTime = 0;
                                gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_OverVolt2Delay;
                            }
                        }
                    }

                    switch( gs_HSDManageRunInfo.HSD2RunState )
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_Normal;
                            break;

                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_VoltErr;
                            break;

                        case E_HSDRunState_OverVolt1Delay:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_Normal;
                            HSD2OverVolt1DelayTime += timebase;
                            if(HSD2OverVolt1DelayTime >= 63000u) /* 延时时间到，故障 */
                            {
                                gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_OverVolt1Stop;
                            }
                            break;

                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_VoltErr;
                            break;

                        case E_HSDRunState_OverVolt2Delay:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_Normal;
                            HSD2OverVolt2DelayTime += timebase;
                            if(HSD2OverVolt2DelayTime >= 400u) /* 延时时间到，故障 */
                            {
                                gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_OverVolt2Stop;
                            }
                            break;

                        case E_HSDRunState_OverVolt2Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_VoltErr;
                    }
                    break;

                case E_HSDFunction_Fan1:
                case E_HSDFunction_Fan2:
                case E_HSDFunction_DcMot:
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD2MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD2MaxVolt) /* 过压 */
                    {
                        gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_OverVolt1Stop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD2MaxVolt - 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD2MinVolt + 10 ) /* 正常 */
                    {
                        gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_ON;
                    }

                    switch(gs_HSDManageRunInfo.HSD2RunState)
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_Normal;
                            break;
                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_VoltErr;
                            break;
                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_VoltErr;
                    }
            }
        }
        if(gs_HSDManageRunInfo.HSD2ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD2ErrSta == E_HSDErrSta_HWRTErr) /* 硬件检测 */
        {
            if( gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD2_OverCur_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD2_Shor2Gnd_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD2_OpenOrShort2Vcc_ErrorConfirmed == 1 )
            {
                gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_HWRTErr;
            }
            else
            {
                gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_Normal;
            }

            if(HSD2HWErrStartTime < HSD_HW_TIME)
            {
                HSD2HWErrStartTime += timebase;
            }
            else
            {
                if( gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD2_OverCur_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD2_Shor2Gnd_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD2_OpenOrShort2Vcc_ErrorConfirmed == 1 )
                {
                    rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                    gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_HWError;
                    gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_HWDtcErr;
                }
            }
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2ActSta == E_HSDActSta_NoAct)
    {
        switch( gs_HSDManageConfigInfo.HSD2Func )
        {
            /* case E_HSDFunction_LMM: */
            case E_HSDFunction_SML:
            case E_HSDFunction_LOGO:
            case E_HSDFunction_Fan1:
            case E_HSDFunction_Fan2:
            case E_HSDFunction_DcMot:
                rtval |= Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
                HSD2HWErrStartTime = 0;
                gs_HSDManageRunInfo.HSD2RunState = E_HSDRunState_OFF;
                gs_HSDManageRunInfo.HSD2ErrSta = E_HSDErrSta_Normal;
        }
    }
    return rtval;
}

/* 高边HSD3电压检测 */
static Std_ReturnType HSDManage_HSD3Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_HSDManageConfigInfo.HSD3Func == E_HSDFunction_NA)
    {
        return rtval;
    }

    static uint16_t HSD3HWErrStartTime = 0;

    if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3ActSta == E_HSDActSta_Act)
    {
        if(gs_HSDManageRunInfo.HSD3ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD3ErrSta == E_HSDErrSta_VoltErr) /* 电压检测 */
        {

            static uint16_t HSD3OverVolt1DelayTime = 0;
            static uint16_t HSD3OverVolt2DelayTime = 0;

            switch( gs_HSDManageConfigInfo.HSD3Func )
            {
                /* case E_HSDFunction_LMM: */
                case E_HSDFunction_SML:
                case E_HSDFunction_LOGO:
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD3MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD3MinVolt + 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD3MaxVolt - 10 ) /* 正常或恢复正常 */
                    {
                        gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_ON;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD3MaxVolt && gs_HSDManageRunInfo.AllHSDVoltage <= 265) /* 过压一级延时 */
                    {
                        if(gs_HSDManageRunInfo.HSD3RunState != E_HSDRunState_OverVolt1Stop && gs_HSDManageRunInfo.HSD3RunState != E_HSDRunState_OverVolt2Stop)
                        {
                            if(gs_HSDManageRunInfo.HSD3RunState != E_HSDRunState_OverVolt1Delay)
                            {
                                HSD3OverVolt1DelayTime = 0;
                                gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_OverVolt1Delay;
                            }
                        }
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > 265) /* 过压二级延时 */
                    {
                        if(gs_HSDManageRunInfo.HSD3RunState != E_HSDRunState_OverVolt1Stop && gs_HSDManageRunInfo.HSD3RunState != E_HSDRunState_OverVolt2Stop)
                        {
                            if(gs_HSDManageRunInfo.HSD3RunState != E_HSDRunState_OverVolt2Delay)
                            {
                                HSD3OverVolt2DelayTime = 0;
                                gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_OverVolt2Delay;
                            }
                        }
                    }

                    switch( gs_HSDManageRunInfo.HSD3RunState )
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_Normal;
                            break;

                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_VoltErr;
                            break;

                        case E_HSDRunState_OverVolt1Delay:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_Normal;
                            HSD3OverVolt1DelayTime += timebase;
                            if(HSD3OverVolt1DelayTime >= 63000u) /* 延时时间到，故障 */
                            {
                                gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_OverVolt1Stop;
                            }
                            break;

                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_VoltErr;
                            break;

                        case E_HSDRunState_OverVolt2Delay:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_Normal;
                            HSD3OverVolt2DelayTime += timebase;
                            if(HSD3OverVolt2DelayTime >= 400u) /* 延时时间到，故障 */
                            {
                                gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_OverVolt2Stop;
                            }
                            break;

                        case E_HSDRunState_OverVolt2Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_VoltErr;
                    }
                    break;

                case E_HSDFunction_Fan1:
                case E_HSDFunction_Fan2:
                case E_HSDFunction_DcMot:
                    if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD3MinVolt) /* 欠压 */
                    {
                        gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_UnderVoltStop;
                    }
                    else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD3MaxVolt) /* 过压 */
                    {
                        gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_OverVolt1Stop;
                    }
                    else if( gs_HSDManageRunInfo.AllHSDVoltage <= gs_HSDManageConfigInfo.HSD3MaxVolt - 10 &&
                            gs_HSDManageRunInfo.AllHSDVoltage >= gs_HSDManageConfigInfo.HSD3MinVolt + 10 ) /* 正常 */
                    {
                        gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_ON;
                    }

                    switch(gs_HSDManageRunInfo.HSD3RunState)
                    {
                        case E_HSDRunState_ON:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_ON);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_Normal;
                            break;
                        case E_HSDRunState_UnderVoltStop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_VoltErr;
                            break;
                        case E_HSDRunState_OverVolt1Stop:
                            rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                            gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_VoltErr;
                    }
            }
        }
        if(gs_HSDManageRunInfo.HSD3ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD3ErrSta == E_HSDErrSta_HWRTErr) /* 硬件检测 */
        {
            if( gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD3_OverCur_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD3_Shor2Gnd_ErrorConfirmed == 1 ||
                gs_HSDManageRunInfo.HSDHWRTErrSta.bits.HSD3_OpenOrShort2Vcc_ErrorConfirmed == 1 )
            {
                gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_HWRTErr;
            }
            else
            {
                gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_Normal;
            }
            if(HSD3HWErrStartTime < HSD_HW_TIME)
            {
                HSD3HWErrStartTime += timebase;
            }
            else
            {
                if( gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD3_OverCur_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD3_Shor2Gnd_ErrorConfirmed == 1 ||
                    gs_HSDManageRunInfo.HSDHWDtcErrSta.bits.HSD3_OpenOrShort2Vcc_ErrorConfirmed == 1 )
                {
                    rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                    gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_HWError;
                    gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_HWDtcErr;
                }
            }
        }
    }
    else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3ActSta == E_HSDActSta_NoAct)
    {
        switch( gs_HSDManageConfigInfo.HSD3Func )
        {
            /* case E_HSDFunction_LMM: */
            case E_HSDFunction_SML:
            case E_HSDFunction_LOGO:
            case E_HSDFunction_Fan1:
            case E_HSDFunction_Fan2:
            case E_HSDFunction_DcMot:
                rtval |= Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
                HSD3HWErrStartTime = 0;
                gs_HSDManageRunInfo.HSD3RunState = E_HSDRunState_OFF;
                gs_HSDManageRunInfo.HSD3ErrSta = E_HSDErrSta_Normal;
        }
    }
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 获取高边输入电压值 */
double HSDManage_GetHSDSupplyVoltage(void)
{
    return gs_HSDManageRunInfo.AllHSDVoltage / 10;
}

/* 获取高边输出电流值，单位mA */
uint16_t HSDManage_GetHSDOutputCurrent(E_HSChannel HSChannel)
{
    switch( HSChannel )
    {
        case E_HSChannel_HS0:
            return gs_HSDManageRunInfo.HSD0Current;
        case E_HSChannel_HS1:
            return gs_HSDManageRunInfo.HSD1Current;
        case E_HSChannel_HS2:
            return gs_HSDManageRunInfo.HSD2Current;
        case E_HSChannel_HS3:
            return gs_HSDManageRunInfo.HSD3Current;
    }
    return 0u;
}

/* 获取高边开关状态 */
E_HSDSwitchSta HSDManage_GetHSDSwitchState(E_HSChannel HSChannel)
{
    switch( HSChannel )
    {
        case E_HSChannel_HS0:
            return gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0SwitchSta;
        case E_HSChannel_HS1:
            return gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1SwitchSta;
        case E_HSChannel_HS2:
            return gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2SwitchSta;
        case E_HSChannel_HS3:
            return gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3SwitchSta;
    }
    return E_HSDSwitchSta_OFF;
}

/* 设置高边激活状态 */
void HSDManage_SetHSDActState(E_HSChannel HSChannel, E_HSDActSta ActSta)
{
    switch( HSChannel )
    {
        case E_HSChannel_HS0:
            gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0ActSta = ActSta;
            break;

        case E_HSChannel_HS1:
            gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1ActSta = ActSta;
            break;

        case E_HSChannel_HS2:
            gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD2ActSta = ActSta;
            break;

        case E_HSChannel_HS3:
            gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD3ActSta = ActSta;
    }
}

/* 获取高边故障状态 */
E_HSDErrSta HSDManage_GetHSDErrState(E_HSChannel HSChannel)
{
    switch( HSChannel )
    {
        case E_HSChannel_HS0:
            return gs_HSDManageRunInfo.HSD0ErrSta;
        case E_HSChannel_HS1:
            return gs_HSDManageRunInfo.HSD1ErrSta;
        case E_HSChannel_HS2:
            return gs_HSDManageRunInfo.HSD2ErrSta;
        case E_HSChannel_HS3:
            return gs_HSDManageRunInfo.HSD3ErrSta;
    }
    return E_HSDErrSta_Normal;
}



/* 高边管理启动初始化 */
void HSDManage_Init(void)
{
    HSDManage_GetParameterIntoInfo();
}

/* 高边管理主函数 */
void HSDManage_MainFunction(uint8_t timebase)
{
    if( gs_HSDManageConfigInfo.HSD0Func == E_HSDFunction_NA &&
        gs_HSDManageConfigInfo.HSD1Func == E_HSDFunction_NA &&
        gs_HSDManageConfigInfo.HSD2Func == E_HSDFunction_NA &&
        gs_HSDManageConfigInfo.HSD3Func == E_HSDFunction_NA ) /* 所有高边都没有配置功能 */
    {
        return;
    }
    
    HSDManage_RefreshHSDSupplyVoltageValue();
    HSDManage_RefreshHSDCurrentValue();
    HSDManage_RefreshHSDHWErrorStateValue();
    HSDManage_RefreshHSDSwitchState();
    HSDManage_HSD0Run(timebase);
    HSDManage_HSD1Run(timebase);
    HSDManage_HSD2Run(timebase);
    HSDManage_HSD3Run(timebase);
}


