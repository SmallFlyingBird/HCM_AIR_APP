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
#include "HSDManage.h"
#include "Channel_Interface.h"        /* 读LED通道状态 */
#include "NtcRcod_Interface.h"        /* 读NTC通道温度 */
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "AdcDev_Interface.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

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

/* 风扇2运行信息 */
typedef struct
{
    E_FanRunState RunState;
    // E_FanRunState RunStateLast;
}S_Fan2RunInfo;


/***************************************风扇配置信息*************************************/

/* 风扇数量 */
/* 1 = NoFan;  other = invalid */
/* 1 = 无风扇；其他 = 无效 */
typedef enum
{
    E_FanNumber_NoFan   = 1,
    E_FanNumber_OneFan  = 2,
    E_FanNumber_TwoFans = 4,
}E_FanNumber;

/* 风扇与近光灯故障同步 */
typedef enum
{
    E_FanFaultSignal_No       = 1,
    E_FanFaultSignal_YES      = 2
}E_FanFaultSignal;

/* FAN Control Pin*/
/* 1 = No; 2 = Yes (RPM not allowed); 4 = Yes (RPM allowed); other = invalid */
// typedef enum
// {
//     E_FanControlPin_No            = 1,
//     E_FanControlPin_RPMNotAllowed = 2,
//     E_FanControlPin_RPMAllowed    = 4
// }E_FanControlPin;

/* Diag Type
1 = no diag pin available；
2 = logical input: error is active on 0L；
4 = logical input: error is active on 1L；
8 = fixed frequency input, error active on 0L or 1L；
16 = variable frequency input (FAN Speed), error active on 0L or 1L invalid
*/
typedef enum
{
    E_FanDiagInputType_NoDiagnosePin     = 1,
    E_FanDiagInputType_ErrorActive_L     = 2,
    E_FanDiagInputType_ErrorActive_H     = 4,
    E_FanDiagInputType_FixedFrequency    = 8,
    E_FanDiagInputType_VariableFrequency = 16
}E_FanDiagInputType;

/* FAN parameter Read and Save */
typedef struct
{
    uint16_t FanToChannel;  //风扇对应的LED channel通道
    uint16_t FanOnLedChannel;  //当对应channel功能点亮时，FAN1需要打开
    uint8_t  FanFaultSignal;     // Show if the Low Beam failure signal shall be set also for FAN failure (1 = No; 2 = Yes; other = invalid) 
    uint8_t  FanLedTempHys;     // Hysteresis to be used with LED temperature 

    uint16_t FanSupInrushTime;  // 风扇开启到诊断延时时间 ms

    uint16_t FanNomCurrent;  //正常电流，用来判断是否堵转
    uint8_t  FanNomCurTol;   //额定电流公差，用来判断是否堵转 % 
    
    uint16_t FanLockDebTime; //出现堵转到确认堵转的延时时间 ms

    uint16_t  FanLockProtOnTime0; //堵转后关闭风扇的时间 ms 
    // uint8_t   FanLockProtTimeTol0; //没有使用 % 
    uint16_t  FanLockRetryOffTime; //确认堵转关闭风扇的延时时间  ms

    uint8_t  FanCoolLedTempLo;   //Below this LED temperature the FAN power shall be 0
    // uint8_t  FanCoolLedTempHi;   //Above this LED temperature the FAN power shall be pFanCoolPowerHi
    // uint8_t  FanCoolPowerLo;    //FAN power to be used when temperature is pFanCoolLedTempLo
    // uint8_t  FanCoolPowerHi;   //FAN power to be used when temperature is above pFanCoolLedTempHi

    E_FanNumber FanNumber;         //1 = NoFan; 2 = OneFan; 4 = TwoFans; other = invalid
    // E_FanControlPin FanControlPin;     //1 = No; 2 = Yes (RPM not allowed); 4 = Yes (RPM allowed); other = invalid
    E_FanDiagInputType FanDiagInputType;  
}S_FanConfigInfo;

/****************************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* FAN  */
void Fan_Init(void);

/* 风扇主函数 */
void Fan_MainFunction(uint8_t timebase);


/* 风扇1与近光灯故障同步设置 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t Fan_GetFanFaultSignal(void);

#endif

