/********************************
 * LogoLamp.h
 *
 *  Created on: 2024/4/15
 *      Author: tujiongjiong
 ********************************/

#ifndef LOGOLAMP_H_
#define LOGOLAMP_H_

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
#include "DTC_Interface.h"
#include "HSDManage.h"

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

/* 前贯穿灯硬件归属权 */
typedef enum
{
    E_LogoLampOwnership_Self = 0, /* 归LOGO灯本身 */
    E_LogoLampOwnership_LB   = 1, /* 归近光灯 */
    E_LogoLampOwnership_Posn = 2, /* 归位置灯 */
}E_LogoLampOwnership;

/* LOGO灯运行状态 */
typedef enum
{
    E_LogoLampRunState_OffDelay = 0, /* 关闭延时 */
    E_LogoLampRunState_OnDelay  = 1, /* 开启延时 */
    E_LogoLampRunState_Run      = 2, /* 运行 */
}E_LogoLampRunState;

/* LOGO灯运行信息 */
typedef struct
{
    uint8_t Pwm_Posn;
    uint8_t Pwm_LB;
    uint8_t Pwm_Self;
    uint8_t Pwm_Target;
    uint8_t Pwm_LastTarget;
    uint16_t ChannelMaskWoMtx;
    uint16_t ChannelMaskWiMtx;
    E_LogoLampOwnership Ownership;
    E_LogoLampRunState RunState;
    
    uint8_t  TacticN_1;
    uint16_t OnRampTime;
    uint16_t OffRampTime;
    uint8_t  OnDelayTime;
    uint8_t  OffDelayTime;
}S_LogoLampRunInfo;

/* LOGO灯配置信息 */
typedef struct
{
    E_LedGamma  LedGamma;

    uint16_t SelfOnRampTime;
    uint16_t SelfOffRampTime;
    uint8_t  SelfOnDelayTime;
    uint8_t  SelfOffDelayTime;

    uint16_t LBOnRampTime;
    uint16_t LBOffRampTime;
    uint8_t  LBOnDelayTime;
    uint8_t  LBOffDelayTime;

    uint8_t  PosnIntensityDuty;
    uint16_t PosnOnRampTime;
    uint16_t PosnOffRampTime;
    uint8_t  PosnOnDelayTime;
    uint8_t  PosnOffDelayTime;

    uint8_t  PartOfLBOrPosn;
    E_HSChannel HSDChannel; /* LOGO灯新增需求，需要用到高边 */
}S_LogoLampConfigInfo;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 获取LOGO灯作为近光灯或位置灯一部分时的故障状态 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t LogoLamp_GetLogoLampErrorState(void);

/* LOGO灯启动初始化 */
void LogoLamp_Init(void);

/* LOGO灯主函数 */
void LogoLamp_MainFunction(uint8_t timebase);

#endif

