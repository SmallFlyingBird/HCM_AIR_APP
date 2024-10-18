/********************************
 * SiderMarkerLamp.c
 *
 *  Created on: 2024/4/12
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "SiderMarkerLamp.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_SMLConfigInfo gs_SMLConfigInfo;

static S_SMLRunInfo gs_SMLRunInfo = 
{
    .RunState = E_SMLRunState_OFF
};

static S_SMLDidInfo gs_SMLDidInfo =
{
    .SMLOutputStatus = SMLOutputStatus_NotAvl,
    .CurrentFeedback = 0xFFFF,
    .SMLStatus       = SMLStatus_Res
};

static E_EnableFlag ge_SMLDIDCtrFlag = E_EnableFlag_DISABLE; /* DID控制状态标志 */

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

/* 读取示廓灯参数配置并存放 */
static Std_ReturnType SML_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;
    
    switch( GetChannelMaskByLightFunction(E_SideMarkerLamp) & 0x7000 )
    {
        case 0x0000:
            gs_SMLConfigInfo.SMLHSDChannel = E_HSChannel_HS0; /* 表示没有高边配置 */
            break;
        case 0x1000:
            gs_SMLConfigInfo.SMLHSDChannel = E_HSChannel_HS1;
            break;
        case 0x2000:
            gs_SMLConfigInfo.SMLHSDChannel = E_HSChannel_HS2;
            break;
        case 0x4000:
            gs_SMLConfigInfo.SMLHSDChannel = E_HSChannel_HS3;
            break;
    }
    return rtval;
}

/* 示廓灯高边诊断 */
static Std_ReturnType SML_HSDDiagnose(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if(gs_SMLRunInfo.RunState != E_SMLRunState_OFF)
    {
        E_HSDErrSta SMLErrSta;

        SMLErrSta = HSDManage_GetHSDErrState(gs_SMLConfigInfo.SMLHSDChannel);
        
        if(SMLErrSta == E_HSDErrSta_Normal)
        {
            gs_SMLRunInfo.RunState = E_SMLRunState_ON;
        }
        else if(SMLErrSta == E_HSDErrSta_VoltErr)
        {
            gs_SMLRunInfo.RunState = E_SMLRunState_VoltErr;
        }
        else if(SMLErrSta == E_HSDErrSta_HWRTErr || SMLErrSta == E_HSDErrSta_HWDtcErr)
        {
            gs_SMLRunInfo.RunState = E_SMLRunState_HWErr;
        }
    }
    return rtval;
}


/* 打开示廓灯 */
static Std_ReturnType SML_SwitchON(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_SMLRunInfo.RunState == E_SMLRunState_OFF)
    {
        HSDManage_SetHSDActState(gs_SMLConfigInfo.SMLHSDChannel, E_HSDActSta_Act);
        gs_SMLRunInfo.RunState = E_SMLRunState_ON;
    }
    return rtval;
}

/* 关闭示廓灯 */
static Std_ReturnType SML_SwitchOFF(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_SMLRunInfo.RunState != E_SMLRunState_OFF)
    {
        HSDManage_SetHSDActState(gs_SMLConfigInfo.SMLHSDChannel, E_HSDActSta_NoAct);
        gs_SMLRunInfo.RunState = E_SMLRunState_OFF;
    }
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 示廓灯DID控制回调函数 */
Std_ReturnType SiderMarkerLamp_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    if(gs_SMLConfigInfo.SMLHSDChannel == E_HSChannel_HS0) /* 没有示廓灯 */
    {
        rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_SMLOutputStatus, (uint32_t)gs_SMLDidInfo.SMLOutputStatus);
        return rtval;
    }

    uint8_t  DIDControlMask;
    uint32_t DIDIoctrData;

    switch( IOCtrTypeState )
    {
        case E_IOCtrType_ReturnControl:
            ge_SMLDIDCtrFlag = E_EnableFlag_DISABLE;
            break;

        case E_IOCtrType_FreeCurState:
            ge_SMLDIDCtrFlag = E_EnableFlag_ENABLE;

            rtval |= Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampSideMarkerLight, &DIDControlMask);
            if(DIDControlMask & 0x80) /* 示廓灯输出控制 */
            {
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_SMLOutputStatus, (uint32_t)gs_SMLDidInfo.SMLOutputStatus);
            }
            break;

        case E_IOCtrType_ShortTermAdjustment:
            ge_SMLDIDCtrFlag = E_EnableFlag_ENABLE;

            rtval |= Interface_GetDidIoctrMask(DIDNAME_ID_HeadlampSideMarkerLight, &DIDControlMask);

            if(DIDControlMask & 0x80) /* 示廓灯输出控制 */
            {
                rtval |= Interface_GetDidSignalIoctrData(DIDSIGNALNAME_ID_SMLOutputStatus, &DIDIoctrData);

                if(DIDIoctrData == 0u) /* 激活信号 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act);
                    gs_SMLDidInfo.SMLOutputStatus = SMLOutputStatus_Active;
                }
                else if(DIDIoctrData == 1u) /* 关闭信号 */
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct);
                    gs_SMLDidInfo.SMLOutputStatus = SMLOutputStatus_NoActive;
                }
                rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_SMLOutputStatus, (uint32_t)gs_SMLDidInfo.SMLOutputStatus);
            }
    }
    return rtval;
}

/* 设置示廓灯的DID数据，4358 */
Std_ReturnType SiderMarkerLamp_SetDID_4358_SML(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_SMLOutputStatus, (uint32_t)gs_SMLDidInfo.SMLOutputStatus);
    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_SMLCurFB, gs_SMLDidInfo.CurrentFeedback);

    return rtval;
}

/* 设置示廓灯的DID数据，4368 */
Std_ReturnType SiderMarkerLamp_SetDID_4368_SMLStatus(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_StsOfSML, (uint32_t)gs_SMLDidInfo.SMLStatus);

    return rtval;
}


/* 示廓灯启动初始化 */
void SiderMarkerLamp_Init(void)
{
    SML_GetParameterIntoInfo();
}

/* 示廓灯主函数 */
void SiderMarkerLamp_MainFunction(uint8_t timebase)
{
    if(gs_SMLConfigInfo.SMLHSDChannel == E_HSChannel_HS0) /* 没有示廓灯配置 */
    {
        return;
    }

    if(ge_SMLDIDCtrFlag == E_EnableFlag_DISABLE) /* DID控制不使能 */
    {
        uint32_t ActnOfLedPosnLamp;

        Interface_GetSignal_ActnOfLedPosnLamp(&ActnOfLedPosnLamp);
        if(ActnOfLedPosnLamp) /* 开灯 */
        {
            SML_SwitchON();

            SML_HSDDiagnose(timebase);

            if(gs_SMLRunInfo.RunState == E_SMLRunState_ON)
            {
                Interface_SetSignal_StsOfFrntSideMkrLamp2( 0x01 ); /* 反馈开启 */
            }
            else if(gs_SMLRunInfo.RunState == E_SMLRunState_HWErr)
            {
                Interface_SetSignal_StsOfFrntSideMkrLamp2( 0x02 ); /* 反馈故障 */
            }
        }
        else /* 关灯 */
        {
            SML_SwitchOFF();

            if(gs_SMLRunInfo.RunState == E_SMLRunState_OFF)
            {
                Interface_SetSignal_StsOfFrntSideMkrLamp2( 0x00 ); /* 反馈关闭 */
            }
        }
        
        /* 设置DID */
        if(HSDManage_GetHSDSwitchState(gs_SMLConfigInfo.SMLHSDChannel) == E_HSDSwitchSta_ON)
        {
            gs_SMLDidInfo.SMLOutputStatus = SMLOutputStatus_Active;
        }
        else
        {
            gs_SMLDidInfo.SMLOutputStatus = SMLOutputStatus_NoActive;
        }
        gs_SMLDidInfo.CurrentFeedback = HSDManage_GetHSDOutputCurrent(gs_SMLConfigInfo.SMLHSDChannel);
        switch( gs_SMLRunInfo.RunState )
        {
            case E_SMLRunState_OFF:
                gs_SMLDidInfo.SMLStatus = SMLStatus_Off;
                break;

            case E_SMLRunState_ON:
                gs_SMLDidInfo.SMLStatus = SMLStatus_On;
                break;

            case E_SMLRunState_VoltErr:
            case E_SMLRunState_HWErr:
                gs_SMLDidInfo.SMLStatus = SMLStatus_Error;
        }
    }
}



