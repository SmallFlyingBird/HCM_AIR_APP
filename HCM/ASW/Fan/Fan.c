/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Fan.h"
#include "LinManager.h"
#include "DrvTps2HB35.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

#define FAN_DELAYOFF_TIME   2000   //delay time to off

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_FanConfigInfo gs_FanConfigInfo; /* 风扇所有配置信息 */

static S_Fan2RunInfo gs_FanRunInfo =
{
    .RunState = E_FanRunState_OFF,
};

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/* read fan parameter */
static void Fan_GetParameterIntoInfo(void)
{                                                                                                                                                                                                  
    gs_FanConfigInfo.FanToChannel        = Get_pFanToChannel();
    gs_FanConfigInfo.FanOnLedChannel     = Get_pFanOnLedCh(); 
    gs_FanConfigInfo.FanFaultSignal      = Get_pFanFaultSignal();
    gs_FanConfigInfo.FanLedTempHys       = Get_pFanLedTempHys(); 
    gs_FanConfigInfo.FanSupInrushTime    = Get_pFanSupInrushTime(); 
    gs_FanConfigInfo.FanNomCurrent       = Get_pFanNomCurrent();
    gs_FanConfigInfo.FanNomCurTol        = Get_pFanNomCurTol();
    gs_FanConfigInfo.FanLockDebTime      = Get_pFanLockDebTime();
    gs_FanConfigInfo.FanLockProtOnTime0  = Get_pFanLockProtOnTime0() * 100;
    gs_FanConfigInfo.FanLockRetryOffTime = Get_pFanLockRetryOffTime() * 1000;

    gs_FanConfigInfo.FanCoolLedTempLo    = Get_pFanCoolLedTempLo();
    gs_FanConfigInfo.FanNumber           = Get_pFanNumber();
    gs_FanConfigInfo.FanDiagInputType    = Get_pFanDiagInputType();
}

/* 读取所有LED通道状态，按位编码保存到低12位 */
static Std_ReturnType Fan_GetAllLEDChannelState(uint16_t * AllChannelState)
{
    Std_ReturnType rtval = E_OK;
    E_ChannelID ChannelID;
    E_ChannelState ChannelState;
    uint16_t AllChannelState_Temp = 0;

    for(ChannelID = ChannelID1; ChannelID < CHANNEL_NUM; ChannelID++)
    {
        rtval |= Interface_GetChannelSwitchState(ChannelID, &ChannelState);

        if(ChannelState == CHANNEL_STATE_ON)
            AllChannelState_Temp |= 1u << ChannelID;
    }
    *AllChannelState = AllChannelState_Temp;

    /* 测试 */
    // static uint8_t s_FanTestCycle = 0u;

    // if (s_FanTestCycle >= 0 && s_FanTestCycle <= 210)
    // {
    //     *AllChannelState = 0x3F;
    // }
    // else if (s_FanTestCycle >= 211 && s_FanTestCycle <= 255)
    // {
    //     *AllChannelState = 0x00;
    // }
    // if (s_FanTestCycle < 0xFF)
    // {
    //     s_FanTestCycle++;
    // }
    // else
    // {
    //     s_FanTestCycle = 0;
    // }
    return rtval;
}

/* 读取LED温度，多个LED通道取最大值 */
static Std_ReturnType Fan_GetLedTemperature(uint16_t ChannelMask, sint16_t * LedTemperature)
{
    Std_ReturnType rtval = E_OK;
    E_ChannelID ChannelID;
    sint16_t LedTemperature_Max = -50; /* 赋一个最低温度值，以便找最大值 */

    for(ChannelID = ChannelID1; ChannelID < CHANNEL_NUM; ChannelID++)
    {
        if((ChannelMask & (1 << ChannelID)) > 0) /* 寻找风扇对应的LED通道 */
        {
            E_NtcRcodFunction NTCChannel;
            sint16_t NTCChannelTemperature;

            NTCChannel = (E_NtcRcodFunction)Get_pLedChToNtc(ChannelID); /* 风扇对应的LED通道对应的NTC通道 */
            rtval |= Interface_GetNtcTemperature(NTCChannel, &NTCChannelTemperature);    /* 读取该NTC通道的温度值 */
            if(rtval == E_OK) /* 遇到未读到温度值的通道，直接跳过 */
            {
                if(LedTemperature_Max < NTCChannelTemperature) /* 找到最高的LED通道温度 */
                    LedTemperature_Max = NTCChannelTemperature;
            }
            else
            {
                break;
            }
        }
    }
    if (rtval == E_OK)
    {
       *LedTemperature = LedTemperature_Max;
    }
    return rtval;
}


/* FAN Cool function */
static Std_ReturnType Fan_Fan1CoolingLED(void)
{
    Std_ReturnType rtval = E_OK;
    uint16_t AllChnlSts;

    rtval |= Fan_GetAllLEDChannelState( &AllChnlSts ); /* 读取所有LED通道状态 */

    if((gs_FanConfigInfo.FanToChannel & AllChnlSts) > 0) /* 有对应LED通道开启，开始打开风扇 */
    {
        sint16_t LedTemperature = -50;
        uint16_t OnlyOnLedChnl;
        uint16_t OnlyRdNtcChnl;

        OnlyOnLedChnl = gs_FanConfigInfo.FanToChannel & gs_FanConfigInfo.FanOnLedChannel;
        OnlyRdNtcChnl = gs_FanConfigInfo.FanToChannel ^ gs_FanConfigInfo.FanOnLedChannel;

        if((OnlyOnLedChnl & AllChnlSts) > 0) /* 直接开启风扇的LED通道打开，设置温度为最大值 */
        {
            LedTemperature = 150;
        }
        else if((OnlyRdNtcChnl & AllChnlSts) > 0)
        {
            rtval |= Fan_GetLedTemperature( OnlyRdNtcChnl & AllChnlSts, &LedTemperature ); /* 读LED温度 */
            if (rtval == E_NOT_OK)
            {
                return rtval;
            }
        }
        if (gs_FanRunInfo.RunState == E_FanRunState_ON || gs_FanRunInfo.RunState == E_FanRunState_OFF)
        {
            if(LedTemperature >= gs_FanConfigInfo.FanCoolLedTempLo) /* 高温打开 */
                gs_FanRunInfo.RunState = E_FanRunState_ON;
            else if(LedTemperature < gs_FanConfigInfo.FanCoolLedTempLo - gs_FanConfigInfo.FanLedTempHys) /* 低温滞后关闭 */
                gs_FanRunInfo.RunState = E_FanRunState_OFF;
        }
    }
    else /* 关闭风扇 */
    {
        gs_FanRunInfo.RunState = E_FanRunState_OFF;
    }
    return rtval;
}


/* FAN Run */
static Std_ReturnType Fan_Fan1Running(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    static uint16_t DelayOffTime = 0;

    Fan_Fan1CoolingLED(); // FAN Cooling Function
    if(gs_FanRunInfo.RunState == E_FanRunState_ON)
    {
        DelayOffTime = 0;
        HSDManage_SetHSDActState(E_HSChannel_HS1, E_HSDActSta_Act); //open fan
    }
    else if(gs_FanRunInfo.RunState == E_FanRunState_OFF)
    {
        if(DelayOffTime < FAN_DELAYOFF_TIME)
            DelayOffTime += timebase;
        if(DelayOffTime >= FAN_DELAYOFF_TIME) //delay 2s 
        {
            HSDManage_SetHSDActState(E_HSChannel_HS1, E_HSDActSta_NoAct); //close fan
        }  
    }
    return rtval;
}
/* 风扇1堵转诊断 */
static Std_ReturnType Fan_Fan1StallDiagnose(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    if( gs_FanRunInfo.RunState == E_FanRunState_HWError ||
        gs_FanRunInfo.RunState == E_FanRunState_VoltError ||
        gs_FanRunInfo.RunState == E_FanRunState_StallError ) /* 风扇已经故障，退出 */
    {
        return rtval;
    }

    static uint16_t s_FanDiagTime  = 0; /* 诊断计时 */
    static uint16_t s_FanPauseTime = 0; /* 暂停计时 */
    static uint16_t s_FanRetryTime = 0; /* 总重试计时 */
    static uint8_t  s_FanStallErrFlag = 0u;

    switch (gs_FanRunInfo.RunState)
    {
        case E_FanRunState_OFF:
            s_FanDiagTime  = 0;
            s_FanPauseTime = 0;
            s_FanRetryTime = 0;
            s_FanStallErrFlag = 0u;
            break;

        case E_FanRunState_ON:
            if(HSDManage_GetHSDOutputCurrent(E_HSChannel_HS1) > gs_FanConfigInfo.FanNomCurrent * (100 + gs_FanConfigInfo.FanNomCurTol) / 100) /* 检测到堵转 */
                s_FanStallErrFlag |= 1;
            if(s_FanDiagTime < gs_FanConfigInfo.FanSupInrushTime) /* 等待诊断时间 */
                s_FanDiagTime += timebase;
            else /* 计时时间到，开始查看诊断结果 */
            {
                if(s_FanStallErrFlag == 1u)
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS1, E_HSDActSta_NoAct); /* 关闭风扇 */
                    gs_FanRunInfo.RunState = E_FanRunState_StallRetry;
                    s_FanDiagTime = 0;
                    s_FanStallErrFlag = 0u;
                }
            }
            break;

        case E_FanRunState_StallRetry:
            if(s_FanPauseTime < gs_FanConfigInfo.FanLockProtOnTime0) /* 等待重启时间 */
                s_FanPauseTime += timebase;
            else  /* 计时时间到，开始重启 */
            {
                HSDManage_SetHSDActState(E_HSChannel_HS1, E_HSDActSta_Act); /* 打开风扇 */
                gs_FanRunInfo.RunState = E_FanRunState_StallDiag;
                s_FanPauseTime = 0;
            }
            break;

        case E_FanRunState_StallDiag:
            if(HSDManage_GetHSDOutputCurrent(E_HSChannel_HS1) > gs_FanConfigInfo.FanNomCurrent * (100 + gs_FanConfigInfo.FanNomCurTol) / 100) /* 还是检测到堵转 */
                s_FanStallErrFlag |= 1;
            if(s_FanDiagTime < gs_FanConfigInfo.FanSupInrushTime) /* 等待诊断时间 */
                s_FanDiagTime += timebase;
            else /* 计时时间到，开始查看诊断结果 */
            {
                if(s_FanStallErrFlag == 1u)
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS1, E_HSDActSta_NoAct); /* 关闭风扇 */
                    gs_FanRunInfo.RunState = E_FanRunState_StallRetry;
                    s_FanDiagTime = 0;
                    s_FanStallErrFlag = 0u;
                }
                else /* 堵转恢复，风扇继续运行 */
                {
                    gs_FanRunInfo.RunState = E_FanRunState_ON;
                    s_FanDiagTime = 0;
                    s_FanRetryTime = 0;
                }
            }
    }
    if(gs_FanRunInfo.RunState == E_FanRunState_StallDiag || gs_FanRunInfo.RunState == E_FanRunState_StallRetry)
    {
        if(s_FanRetryTime < gs_FanConfigInfo.FanLockRetryOffTime) /* 等待重试关闭 */
            s_FanRetryTime += timebase;
        else  /* 重试时间到，确认堵转故障 */
        {
            HSDManage_SetHSDActState(E_HSChannel_HS1, E_HSDActSta_NoAct); /* 关闭风扇 */
            gs_FanRunInfo.RunState = E_FanRunState_StallError;
        }
    }
    return rtval;
}

/*
* FAN1 Vol and HW check
*/
static Std_ReturnType Fan_Fan1VoltHWDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta Fan1HSDErrSta;

    Fan1HSDErrSta = HSDManage_GetHSDErrState(E_HSChannel_HS1); //get HSD1 error

    if(gs_FanRunInfo.RunState == E_FanRunState_ON || gs_FanRunInfo.RunState == E_FanRunState_VoltError) /* 风扇1开启时查看硬件故障状态 */
    {
        if(Fan1HSDErrSta == E_HSDErrSta_Normal)
        {
            gs_FanRunInfo.RunState = E_FanRunState_ON;
        }
        else if(Fan1HSDErrSta == E_HSDErrSta_VoltErr)
        {
            gs_FanRunInfo.RunState = E_FanRunState_VoltError;
        }
    }
    if(gs_FanRunInfo.RunState == E_FanRunState_ON)
    {
        if(Fan1HSDErrSta == E_HSDErrSta_HWDtcErr)
        {
            gs_FanRunInfo.RunState = E_FanRunState_HWError;
        }
    }
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

/* 风扇启动初始化 */
void Fan_Init(void)
{
    Fan_GetParameterIntoInfo();
}

/* FAN main function 
* RUN + STALL + VoltHW //后期添加代码
* DID +DTC
 */
void Fan_MainFunction(uint8_t timebase)
{
    if(gs_FanConfigInfo.FanNumber != E_FanNumber_OneFan) /* 没有风扇，直接退出 */
    {
        return;
    }

    Fan_Fan1Running(timebase);
    Fan_Fan1StallDiagnose(timebase);
    Fan_Fan1VoltHWDetect();
}


/* FAN err with LB err
return :0 means no err; 1 means err
*/
uint8_t Fan_GetFanFaultSignal(void)
{
    // switch( gs_FanConfigInfo.FanFaultSignal )
    // {
    //     case E_FanFaultSignal_No:
    //         break;

    //     case E_FanFaultSignal_YES:
    //     if( gs_FanRunInfo.RunState == E_FanRunState_HWError ||
    //         gs_FanRunInfo.RunState == E_FanRunState_VoltError ||
    //         gs_FanRunInfo.RunState == E_FanRunState_StallError )
    //     {
    //         return E_NOT_OK;
    //     }
    // }
    return E_OK;
}




