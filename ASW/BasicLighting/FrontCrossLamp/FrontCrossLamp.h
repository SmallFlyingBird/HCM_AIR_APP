/********************************
 * FrontCrossLamp.h
 *
 *  Created on: 2024/4/17
 *      Author: tujiongjiong
 ********************************/

#ifndef FRONTCROSSLAMP_H_
#define FRONTCROSSLAMP_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Parameter_Interface.h"   /* 读参数配置表 */
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

/* 前贯穿灯左右存在配置 */
typedef enum
{
    E_FrontCrossLampAvl_NotAvl = 0,
    E_FrontCrossLampAvl_Left   = 1,
    E_FrontCrossLampAvl_Right  = 2,
    E_FrontCrossLampAvl_Both   = 3
}E_FrontCrossLampAvl;





/* 前贯穿灯硬件归属权 */
typedef enum
{
    E_FrontCrossLampOwnership_Self = 0, /* 归贯穿灯本身 */
    E_FrontCrossLampOwnership_Posn = 1, /* 归位置灯 */
}E_FrontCrossLampOwnership;

/* 前贯穿灯运行状态 */
typedef enum
{
    E_FrontCrossLampRunState_OffDelay = 0, /* 关闭延时 */
    E_FrontCrossLampRunState_OnDelay  = 1, /* 开启延时 */
    E_FrontCrossLampRunState_Run      = 2, /* 运行 */
}E_FrontCrossLampRunState;

/* 前贯穿灯运行信息 */
typedef struct
{
    uint8_t  Pwm_Posn;
    uint8_t  Pwm_Self;
    uint8_t  Pwm_Target;
    uint8_t  Pwm_LastTarget;
    uint16_t ChannelMaskWoMtx;
    uint16_t ChannelMaskWiMtx;
    E_FrontCrossLampOwnership Ownership;
    E_FrontCrossLampRunState RunState;
    
    uint8_t  TacticN_1;
    uint16_t OnRampTime;
    uint16_t OffRampTime;
    uint8_t  OnDelayTime;
    uint8_t  OffDelayTime;
}S_FrontCrossLampRunInfo;


/* 前贯穿灯配置信息 */
typedef struct
{
    E_FrontCrossLampAvl LampAvl;
    E_LedGamma  LedGamma;

    uint8_t  SelfIntensityDuty;
    uint16_t SelfOnRampTime;
    uint16_t SelfOffRampTime;
    uint8_t  SelfOnDelayTime;
    uint8_t  SelfOffDelayTime;

    uint8_t  PosnIntensityDuty;
    uint16_t PosnOnRampTime;
    uint16_t PosnOffRampTime;
    uint8_t  PosnOnDelayTime;
    uint8_t  PosnOffDelayTime;
    
    uint8_t  PartOfPosn;
}S_FrontCrossLampConfigInfo;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* 前贯穿灯启动初始化 */
void FrontCrossLamp_Init(void);

/* 前贯穿灯主函数 */
void FrontCrossLamp_MainFunction(uint8_t timebase);

#endif

