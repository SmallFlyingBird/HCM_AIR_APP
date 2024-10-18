/********************************
 * CorneringLight.h
 *
 *  Created on: 2024/4/15
 *      Author: tujiongjiong
 ********************************/

#ifndef CORNERINGLIGHT_H_
#define CORNERINGLIGHT_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Parameter_Interface.h"   /* 读参数配置表 */
#include "DID_Interface.h"         /* 设置DID */
#include "ComSignal_Interface.h"   /* 与CAN总通讯 */
#include "LampManager.h"
#include "Lighting.h"

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

/* 角灯DID信息 */
typedef struct
{
    enum  
    {
        CorneringLightStatus_Off   = 0,
        CorneringLightStatus_On    = 1,
        CorneringLightStatus_Error = 2,
        CorneringLightStatus_Res   = 3
    }CorneringLightStatus;
}S_CorneringLightDidInfo;



/* 角灯硬件归属权 */
typedef enum
{
    E_CorneringLightOwnership_Self = 0, /* 归角灯本身 */
    E_CorneringLightOwnership_Fog  = 1, /* 归雾灯 */
}E_CorneringLightOwnership;

/* 角灯运行状态 */
typedef enum
{
    E_CorneringLightState_OffDelay = 0, /* 关闭延时 */
    E_CorneringLightState_OnDelay  = 1, /* 开启延时 */
    E_CorneringLightState_Run      = 2, /* 运行 */
}E_CorneringLightRunState;

/* 角灯运行信息 */
typedef struct
{
    uint8_t Pwm_Fog;
    uint8_t Pwm_DBL;
    uint8_t Pwm_AFS;
    uint8_t Pwm_Self;
    uint8_t Pwm_Target;
    uint8_t Pwm_LastTarget;
    uint16_t ChannelMask;
    E_CorneringLightOwnership Ownership;
    E_CorneringLightRunState RunState;

    uint8_t  TacticN_1;
    uint16_t OnRampTime;
    uint16_t OffRampTime;
    uint8_t  OnDelayTime;
    uint8_t  OffDelayTime;
}S_CorneringLightRunInfo;

/* 角灯配置信息 */
typedef struct
{
    uint16_t CLChannelMask;
    uint16_t FLChannelMask;
    E_LedGamma  LedGamma;

    uint8_t  SelfIntensityDuty;
    uint16_t SelfOnRampTime;
    uint16_t SelfOffRampTime;
    uint8_t  SelfOnDelayTime;
    uint8_t  SelfOffDelayTime;

    uint16_t FogOnRampTime;
    uint16_t FogOffRampTime;
    uint8_t  FogOnDelayTime;
    uint8_t  FogOffDelayTime;
}S_CorneringLightConfigInfo;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 设置角灯的DID数据，4368 */
Std_ReturnType CorneringLight_SetDID_4368_CorneringLightStatus(void);



/* 角灯AFS设置PWM */
void CorneringLight_SetPwmOfAFS(uint8_t PwmValue);

/* 角灯DBL设置PWM */
void CorneringLight_SetPwmOfDBL(uint8_t PwmValue);

/* 角灯Fog设置PWM */
void CorneringLight_SetPwmOfFog(uint8_t PwmValue);

/* 获取角灯实时故障状态 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t CorneringLight_GetCLRealTimeErrSta(void);

/* 角灯启动初始化 */
void CorneringLight_Init(void);

/* 角灯主函数 */
void CorneringLight_MainFunction(uint8_t timebase);

#endif

