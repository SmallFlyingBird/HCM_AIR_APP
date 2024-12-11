/********************************
 * Fan.h
 *
 *  Created on: 2024/3/22
 *      Author: tujiongjiong
 ********************************/

#ifndef FAN_FAN_H_
#define FAN_FAN_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "PulseGenerator_Interface.h" /* 风扇转速控制 */
#include "HSDManage.h"
#include "Channel_Interface.h"        /* 读LED通道状态 */
#include "NtcRcod_Interface.h"        /* 读NTC通道温度 */
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "DID_Interface.h"            /* 设置DID */
#include "DTC_Interface.h"
#include "ComSignal_Interface.h"
#include "AdcDev_Interface.h"
#include "RoutineCtr_Interface.h"
#include "DidSignalManager.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define FAN1_PWM_CYCLE 5000u /* 风扇1转速控制的PWM周期；us */


#define FAN_TEST 0

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/* 风扇运行状态 */
typedef enum
{
    E_FanRunState_OFF        = 0, /* 正常，关闭状态 */
    E_FanRunState_ON         = 1, /* 正常，开启状态 */
    E_FanRunState_VoltError  = 2, /* 电压故障，停机 */
    E_FanRunState_HWError    = 3, /* 硬件故障，停机 */
    E_FanRunState_StallError = 4, /* 堵转故障，停机 */
    E_FanRunState_StallDiag  = 5, /* 堵转确认状态，风扇关闭 */
    E_FanRunState_StallRetry = 6  /* 堵转重启状态，风扇开启 */
}E_FanRunState;

/* 风扇1运行信息 */
typedef struct
{
    uint8_t PwmCool;
    uint8_t PwmDefog;
    uint8_t PwmDeice;
    uint8_t PwmRun_Curr;
    uint8_t PwmRun_Last;
    enum  
    {
        Fan1RunMode_Cooling   = 0,
        Fan1RunMode_Defogging = 1,
        Fan1RunMode_Deicing   = 2
    }Fan1RunMode;
    E_FanRunState RunState;
}S_Fan1RunInfo;

/* 风扇2运行信息 */
typedef struct
{
    E_FanRunState RunState;
}S_Fan2RunInfo;


/* 风扇DID信息 */
typedef struct
{
    enum  
    {
        Fan1Diagnosis_NoErr   = 0,
        Fan1Diagnosis_Error   = 1,
        Fan1Diagnosis_NotAval = 2
    }Fan1Diagnosis;
    enum  
    {
        FAN2Control_NoActive = 0,
        FAN2Control_Active   = 1,
        FAN2Control_NotAval  = 2
    }FAN2Control;
    enum  
    {
        Fan1Supply_NoActive = 0,
        Fan1Supply_Active   = 1,
        Fan1Supply_NotAval  = 2
    }Fan1Supply;
    uint8_t  Fan1OutputControl;
    uint16_t Fan1CurrentFeedback; /* mA */

    uint32_t Fan1StartNum;   /* 此次上电的统计数据 */
    uint32_t Fan1StartDeiNum;
    uint32_t Fan1StartDefNum;
    uint32_t Fan1Runtime;

    uint8_t  Fan1SupplyVoltage; /* 实际值*10 */
}S_FanDidInfo;

/* 风扇例程控制抑制条件 */
typedef enum
{
    E_FanRoutineInhiCond_NoInhi   = 0,
    E_FanRoutineInhiCond_VoltOut  = 1,
    E_FanRoutineInhiCond_Mismatch = 2
}E_FanRoutineInhiCond;

/***************************************风扇配置信息*************************************/

/* 风扇数量 */
/* 1 = NoFan;  2 = OneFan; 4 = TwoFans; other = invalid */
/* 1 = 无风扇；2 = 单风扇；4 = 双风扇；  其他 = 无效 */
typedef enum
{
    E_FanNumber_NoFan   = 1,
    E_FanNumber_OneFan  = 2,
    E_FanNumber_TwoFans = 4
}E_FanNumber;

/* 风扇控制引脚 */
/* 1 = No; 2 = Yes (RPM not allowed); 4 = Yes (RPM allowed); other = invalid */
/* 1 = 无；2 = 有（不允许转速控制）； 4 = 有（允许转速控制）；其他 = 无效 */
typedef enum
{
    E_FanControlPin_No            = 1,
    E_FanControlPin_RPMNotAllowed = 2,
    E_FanControlPin_RPMAllowed    = 4
}E_FanControlPin;

/* 风扇故障输入类型 */
typedef enum
{
    E_FanDiagInputType_NoDiagnosePin     = 1,
    E_FanDiagInputType_ErrorActive_L     = 2,
    E_FanDiagInputType_ErrorActive_H     = 4,
    E_FanDiagInputType_FixedFrequency    = 8,
    E_FanDiagInputType_VariableFrequency = 16
}E_FanDiagInputType;

/* 风扇与近光灯故障同步 */
typedef enum
{
    E_FanFaultSignal_No       = 1,
    E_FanFaultSignal_YES      = 2
}E_FanFaultSignal;

/* 风扇除雾必须激活的灯光功能 */
typedef enum
{
    E_FanDefLightFct_NA          = 1, /* 不启用除雾 */
    E_FanDefLightFct_DRL         = 2,
    E_FanDefLightFct_LB          = 4,
    E_FanDefLightFct_DRLOrLB     = 8,
    E_FanDefLightFct_Independent = 16 /* 除雾独立 */
}E_FanDefLightFct;

/* 风扇除冰必须激活的灯光功能 */
typedef enum
{
    E_FanDeiLightFct_NA          = 1,
    E_FanDeiLightFct_DRL         = 2,
    E_FanDeiLightFct_LB          = 4,
    E_FanDeiLightFct_DRLOrLB     = 8,
    E_FanDeiLightFct_Independent = 16
}E_FanDeiLightFct;

/* 风扇配置信息，用于读取参数配置表并存放所有配置信息 */
typedef struct
{
    E_FanNumber        FanNumber;
    E_FanControlPin    FanControlPin;
    E_FanDiagInputType FanDiagInputType;
    E_FanFaultSignal   FanFaultSignal;
    E_FanDefLightFct   FanDefLightFct;
    E_FanDeiLightFct   FanDeiLightFct;
    E_HSChannel        Fan2HSDChannel;

    uint16_t FanToChannel;
    uint16_t FanOnLedChannel;

    uint8_t  FanAmbTempHys;
    uint8_t  FanLedTempHys;

    uint16_t FanSupInrushTime; /* ms */

    uint16_t FanNomCurrent;
    uint8_t  FanNomCurTol;   /* % */
    
    uint16_t FanLockDebTime; /* ms */

    uint8_t  FanLockProtOnTime0;  /* ms */
    uint8_t  FanLockProtTimeTol0; /* % */
    uint8_t  FanLockRetryOffTime; /* ms */

    uint8_t  FanCoolLedTempLo;
    uint8_t  FanCoolLedTempHi;
    uint8_t  FanCoolPowerLo;
    uint8_t  FanCoolPowerHi;

    sint8_t  FanDefAmbTempLo; /* 实际值 */
    sint8_t  FanDefAmbTempHi; /* 实际值 */
    uint8_t  FanDefPowerLo;
    uint8_t  FanDefPowerHi;

    sint8_t  FanDeiAmbTempLo; /* 实际值 */
    sint8_t  FanDeiAmbTempHi; /* 实际值 */
    uint8_t  FanDeiPowerLo;
    uint8_t  FanDeiPowerHi;

    uint8_t  Fan2CoolLedTempLo;
}S_FanConfigInfo;

/****************************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 风扇启动例程控制 */
Std_ReturnType Fan_StartRoutineCtr_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer);

/* 风扇停止例程控制 */
Std_ReturnType Fan_StopRoutineCtr_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer);

/* 风扇请求例程控制结果 */
Std_ReturnType Fan_RequestRoutineResult_FanControl(const uint8_t *InBuffer, uint8_t *OutBuffer);



/* 风扇DID控制回调函数 */
Std_ReturnType Fan_IoCtrCallback(E_IOCtrType IOCtrTypeState);

/* 设置风扇的DID数据，434B */
Std_ReturnType Fan_SetDID_434B_Fan(void);

/* 设置风扇的DID数据，43D5 */
Std_ReturnType Fan_SetDID_43D5_FanSupplyVoltage(void);




/* 风扇启动初始化 */
void Fan_Init(void);

/* 风扇主函数 */
void Fan_MainFunction(uint8_t timebase);

/* 风扇1控制线DTC检测设置 */
Std_ReturnType Fan_Fan1CtrLineDtcErrDetect_10ms(void);

/* 风扇1与近光灯故障同步设置 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t Fan_GetFanFaultSignal(void);

#endif

