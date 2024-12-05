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

    return rtval;
}

/* 读取LED温度，多个LED通道取最大值 */
static Std_ReturnType Fan_GetLedTemperature(uint16_t ChannelMask, sint16_t * LedTemperature)
{

}

/* 风扇1冷却，设置转速 */
static Std_ReturnType Fan_Fan1CoolingLED(void)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
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

/* 读取一次风扇1诊断引脚诊断结果，四种故障电平合一 */
static uint8_t Fan_GetFan1DiagnosInput(void)
{

}

/* 风扇1堵转诊断 */
static Std_ReturnType Fan_Fan1StallDiagnose(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

/* 风扇1电压和硬件检测 */
static Std_ReturnType Fan_Fan1VoltHWDetect(void)
{
    Std_ReturnType rtval = E_OK;
    E_HSDErrSta Fan1HSDErrSta;

   
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
  
}

/* 风扇停止例程控制 */
Std_ReturnType Fan_StopRoutineCtr_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
  
}

/* 风扇请求例程控制结果 */
Std_ReturnType Fan_RequestRoutineResult_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

/* 风扇DID控制回调函数 */
Std_ReturnType Fan_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
  
}

/* 设置风扇的DID数据，434B */
Std_ReturnType Fan_SetDID_434B_Fan(void)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

/* 设置风扇的DID数据，43D5 */
Std_ReturnType Fan_SetDID_43D5_FanSupplyVoltage(void)
{
    Std_ReturnType rtval = E_OK;

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
                Interface_SetPinMode(E_PulseGeneratorFunction_FanDiag, E_PinMode_GPIO);//作为IO口使用
                break;

            case E_FanDiagInputType_FixedFrequency:
            case E_FanDiagInputType_VariableFrequency:
                Interface_SetPinMode(E_PulseGeneratorFunction_FanDiag, E_PinMode_ICU);//做输入捕获功能，每次进中断都计数值++
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
  
}

/* 风扇1控制线DTC检测设置 */
Std_ReturnType Fan_Fan1CtrLineDtcErrDetect_10ms(void)
{
 
}


/* 风扇1与近光灯故障同步设置 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t Fan_GetFanFaultSignal(void)
{
   
}







