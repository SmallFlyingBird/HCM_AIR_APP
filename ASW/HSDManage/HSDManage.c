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
    // .HSDHWRTErrSta.HsdAndFanError = 0u,
    // .HSDHWDtcErrSta.HsdAndFanError = 0u,
    .HSDCtrFbSta.State = 0u,
    .HSD0RunState = E_HSDRunState_OFF,
    .HSD1RunState = E_HSDRunState_OFF,
    .HSD0ErrSta   = E_HSDErrSta_Normal,
    .HSD1ErrSta   = E_HSDErrSta_Normal,
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

    gs_HSDManageConfigInfo.HSD0Func = E_HSDFunction_NA;
    gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_NA;
    if( GetChannelMaskByLightFunction(E_Fan2) & 0x40 ) gs_HSDManageConfigInfo.HSD0Func = E_HSDFunction_Fan;
    if( GetChannelMaskByLightFunction(E_DC_Motor) & 0x80 ) gs_HSDManageConfigInfo.HSD1Func = E_HSDFunction_DcMot;
    switch( gs_HSDManageConfigInfo.HSD0Func )
    {
        case E_HSDFunction_NA:
            gs_HSDManageConfigInfo.HSD0MaxVolt = 0;
            gs_HSDManageConfigInfo.HSD0MinVolt = 0;
            break;
        case E_HSDFunction_Fan:
            gs_HSDManageConfigInfo.HSD0MaxVolt = Get_pHSDMaxVolt(E_HSChannel_HS0);
            gs_HSDManageConfigInfo.HSD0MinVolt = Get_pHSDMinVolt(E_HSChannel_HS0);
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
    return rtval;
}

/* 刷新高边供电电压值，电压值*10 */
/* 所有高边供电电压一致 */
static Std_ReturnType HSDManage_RefreshHSDSupplyVoltageValue(void)
{
    Std_ReturnType rtval = E_OK;
    double SupplyVoltage;

    rtval |= Interface_GetKL56Voltage(& SupplyVoltage);
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
    return rtval;
}

/* 刷新高边硬件故障状态值 */
static Std_ReturnType HSDManage_RefreshHSDHWErrorStateValue(void)
{
    Std_ReturnType rtval = E_OK;

    // gs_HSDManageRunInfo.HSDHWRTErrSta = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorRealTimeState);
    // gs_HSDManageRunInfo.HSDHWDtcErrSta = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorDtcState);
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
    return rtval;
}

/* 高边HSD0电压检测 */
static Std_ReturnType HSDManage_HSD0Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_HSDManageConfigInfo.HSD0Func == E_HSDFunction_Fan)
    {
        static uint16_t HSD0HWErrStartTime = 0;

        if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0ActSta == E_HSDActSta_Act)
        {
            if(gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_VoltErr) /* 电压检测 */
            {
                if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD0MinVolt) /* 欠压 */
                {
                    gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_UVStop;
                }
                else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD0MaxVolt) /* 过压 */
                {
                    gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_OVStop;
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
                    case E_HSDRunState_UVStop:
                    case E_HSDRunState_OVStop:
                        rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
                        gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_VoltErr;
                }
            }
            if(gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD0ErrSta == E_HSDErrSta_HWRTErr) /* 硬件检测 */
            {
                if (0)
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
                    if (0)
                    {
                        rtval |= Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
                        gs_HSDManageRunInfo.HSD0RunState = E_HSDRunState_HWErr;
                        gs_HSDManageRunInfo.HSD0ErrSta = E_HSDErrSta_HWDtcErr;
                    }
                }
            }
        }
        else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD0ActSta == E_HSDActSta_NoAct)
        {
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

    if(gs_HSDManageConfigInfo.HSD1Func == E_HSDFunction_DcMot)
    {
        static uint16_t HSD1HWErrStartTime = 0;

        if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1ActSta == E_HSDActSta_Act)
        {
            if(gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_VoltErr) /* 电压检测 */
            {
                if(gs_HSDManageRunInfo.AllHSDVoltage < gs_HSDManageConfigInfo.HSD1MinVolt) /* 欠压 */
                {
                    gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_UVStop;
                }
                else if(gs_HSDManageRunInfo.AllHSDVoltage > gs_HSDManageConfigInfo.HSD1MaxVolt) /* 过压 */
                {
                    gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OVStop;
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
                    case E_HSDRunState_UVStop:
                    case E_HSDRunState_OVStop:
                        rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                        gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_VoltErr;
                }
            }
            if(gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_Normal || gs_HSDManageRunInfo.HSD1ErrSta == E_HSDErrSta_HWRTErr) /* 硬件检测 */
            {
                if (0)
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
                    if (0)
                    {
                        rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
                        gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_HWErr;
                        gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_HWDtcErr;
                    }
                }
            }
        }
        else if(gs_HSDManageRunInfo.HSDCtrFbSta.Bits.HSD1ActSta == E_HSDActSta_NoAct)
        {
            rtval |= Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
            HSD1HWErrStartTime = 0;
            gs_HSDManageRunInfo.HSD1RunState = E_HSDRunState_OFF;
            gs_HSDManageRunInfo.HSD1ErrSta = E_HSDErrSta_Normal;
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
        gs_HSDManageConfigInfo.HSD1Func == E_HSDFunction_NA  ) /* 所有高边都没有配置功能 */
    {
        return;
    }
    
    HSDManage_RefreshHSDSupplyVoltageValue();
    HSDManage_RefreshHSDCurrentValue();
    HSDManage_RefreshHSDHWErrorStateValue();
    HSDManage_RefreshHSDSwitchState();
    HSDManage_HSD0Run(timebase);
    HSDManage_HSD1Run(timebase);
}


