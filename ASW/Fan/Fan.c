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
#include "LinManager.h"
#include "DrvTps2HB35.h"
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

/* 风扇2运行信息 */
static S_Fan2RunInfo gs_Fan2RunInfo =
{
    .RunState = E_FanRunState_OFF
};

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/* 读取风扇参数配置并存放 */
static Std_ReturnType Fan_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FanConfigInfo.Fan2HSDChannel = E_HSChannel_HS0; /* 表示没有高边配置 */
    gs_FanConfigInfo.FanToChannel        = Get_pFanToChannel();
    gs_FanConfigInfo.FanOnLedChannel     = Get_pFanOnLedCh();

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

    return rtval;
}

/* 读取LED温度，多个LED通道取最大值 */
static Std_ReturnType Fan_GetLedTemperature(uint16_t ChannelMask, sint16_t * LedTemperature)
{

}

/* 风扇2冷却 */
static Std_ReturnType Fan_Fan2CoolingLED(void)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}

/* 风扇1运行 */
static Std_ReturnType Fan_Fan1Running(uint8_t timebase)
{
    
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

/* 风扇启动初始化 */
void Fan_Init(void)
{
    Fan_GetParameterIntoInfo();
}

/* 风扇主函数 */
void Fan_MainFunction(uint8_t timebase)
{
    uint8 fans=0;
    static uint8 flag=0;//配合硬件测试
    fans=Get_FAN_Signal();
    if(fans==1)
    {
        flag=1;
        FAN_Open();
    }
    else if(flag==1)
    {
        FAN_Close();
    }
}


/* 风扇1与近光灯故障同步设置 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t Fan_GetFanFaultSignal(void)
{
   
}







