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
static Std_ReturnType Fan_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FanConfigInfo.Fan2HSDChannel      = E_HSChannel_HS0;
    gs_FanConfigInfo.FanToChannel        = Get_pFanToChannel();
    gs_FanConfigInfo.FanOnLedChannel     = Get_pFanOnLedCh(); 
    gs_FanConfigInfo.FanFaultSignal      = Get_pFanFaultSignal();
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
    return rtval;
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


/* FAN Cool function */
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
        if(LedTemperature >= gs_FanConfigInfo.FanCoolLedTempLo) /* 高温打开 */
            gs_FanRunInfo.RunState = E_FanRunState_ON;
        else if(LedTemperature < gs_FanConfigInfo.FanCoolLedTempLo - gs_FanConfigInfo.FanLedTempHys) /* 低温滞后关闭 */
            gs_FanRunInfo.RunState = E_FanRunState_OFF;
    }
    else /* 关闭风扇1 */
    {
        gs_FanRunInfo.RunState = E_FanRunState_OFF;
    }
    return rtval;
}


/* 风扇2电压和硬件检测 */
static Std_ReturnType Fan_Fan2VoltHWDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta Fan2HSDErrSta;

    Fan2HSDErrSta = HSDManage_GetHSDErrState(gs_FanConfigInfo.Fan2HSDChannel);

    if(gs_FanRunInfo.RunState != E_FanRunState_OFF) /* 风扇1开启时查看硬件故障状态 */
    {
        if(Fan2HSDErrSta == E_HSDErrSta_Normal)
        {
            gs_FanRunInfo.RunState = E_FanRunState_ON;
        }
        else if(Fan2HSDErrSta == E_HSDErrSta_VoltErr)
        {
            gs_FanRunInfo.RunState = E_FanRunState_VoltError;
        }
        else if(Fan2HSDErrSta == E_HSDErrSta_HWDtcErr)
        {
            gs_FanRunInfo.RunState = E_FanRunState_HWError;
        }
    }
    return rtval;
}

/* 风扇启动初始化 */
void Fan_Init(void)
{
    Fan_GetParameterIntoInfo();
}

/* FAN Run */
static Std_ReturnType Fan_Fan1Running(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    static uint16_t DelayOffTime = 0;

    Fan_Fan1CoolingLED(); // FAN Cooling Function
    switch( gs_FanConfigInfo.FanControlPin )      
    {
        case E_FanControlPin_No:            //NO Control Pin
            if(gs_FanRunInfo.RunState == E_FanRunState_ON)
            {
                DelayOffTime=0;
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); //open fan
            }
            else if(gs_FanRunInfo.RunState == E_FanRunState_OFF)
            {
                DelayOffTime += timebase;
                if(DelayOffTime >= FAN_DELAYOFF_TIME) //delay 2s 
                {
                    HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); //close fan
                }  
            }
            break;

        case E_FanControlPin_RPMNotAllowed: 
        case E_FanControlPin_RPMAllowed:     
            if(gs_FanRunInfo.RunState == E_FanRunState_ON)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_Act); 
            }
            else if(gs_FanRunInfo.RunState == E_FanRunState_OFF)
            {
                HSDManage_SetHSDActState(E_HSChannel_HS0, E_HSDActSta_NoAct); 
            }
            //need add PWM control
    }
    return rtval;
}

/* FAN main function 
* RUN + STALL + VoltHW //后期添加代码
* DID +DTC
 */
void Fan_MainFunction(uint8_t timebase)
{
    if(gs_FanConfigInfo.FanNumber == E_FanNumber_NoFan) /* 没有风扇，直接退出 */
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
    switch( gs_FanConfigInfo.FanFaultSignal )
    {
        case E_FanFaultSignal_No:
            break;

        case E_FanFaultSignal_YES:
        if( gs_FanRunInfo.RunState == E_FanRunState_HWError ||
            gs_FanRunInfo.RunState == E_FanRunState_VoltError ||
            gs_FanRunInfo.RunState == E_FanRunState_StallError )
        {
            return E_NOT_OK;
        }
    }
    return E_OK;
}




