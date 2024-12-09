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
#include "ComSignal_Interface.h"
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
}S_Fan2RunInfo;


/***************************************风扇配置信息*************************************/

/* 风扇数量 */
/* 1 = NoFan;  2 = OneFan; 4 = TwoFans; other = invalid */
/* 1 = 无风扇；2 = 单风扇；4 = 双风扇；  其他 = 无效 */
typedef enum
{
    E_FanNumber_NoFan   = 1,
    E_FanNumber_OneFan  = 2,
}E_FanNumber;

/* 风扇与近光灯故障同步 */
typedef enum
{
    E_FanFaultSignal_No       = 1,
    E_FanFaultSignal_YES      = 2
}E_FanFaultSignal;

/* 风扇配置信息，用于读取参数配置表并存放所有配置信息 */
typedef struct
{
    E_HSChannel        Fan2HSDChannel;

    uint16_t FanToChannel;
    uint16_t FanOnLedChannel;

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
}S_FanConfigInfo;

/****************************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

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

