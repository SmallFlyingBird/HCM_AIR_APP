/********************************
 * GrilleLamp.h
 *
 *  Created on: 2024/4/17
 *      Author: tujiongjiong
 ********************************/

#ifndef GRILLELAMP_H_
#define GRILLELAMP_H_

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

/* 格栅灯左右存在配置 */
typedef enum
{
    E_GrilleLampAvl_NotAvl = 0,
    E_GrilleLampAvl_Left   = 1,
    E_GrilleLampAvl_Right  = 2,
    E_GrilleLampAvl_Both   = 3
}E_GrilleLampAvl;


/* 格栅灯运行状态 */
typedef enum
{
    E_GrilleLampRunState_OffDelay = 0, /* 关闭延时 */
    E_GrilleLampRunState_OnDelay  = 1, /* 开启延时 */
    E_GrilleLampRunState_Run      = 2, /* 运行 */
}E_GrilleLampRunState;

/* 格栅灯运行信息 */
typedef struct
{
    uint8_t Pwm_Basic;
    uint8_t Pwm_Target;
    uint8_t Pwm_LastTarget;
    uint16_t ChannelMaskWoMtx;
    uint16_t ChannelMaskWiMtx;
    E_GrilleLampRunState GrilleLampRunState;
}S_GrilleLampRunInfo;


/* 格栅灯配置信息 */
typedef struct
{
    E_GrilleLampAvl LampAvl;
    uint8_t  IntensityDuty;
    E_LedGamma  LedGamma;
    uint16_t OnRampTime;
    uint16_t OffRampTime;
    uint8_t  OnDelayTime;
    uint8_t  OffDelayTime;
}S_GrilleLampConfigInfo;




/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* 格栅灯启动初始化 */
void GrilleLamp_Init(void);

/* 格栅灯主函数 */
void GrilleLamp_MainFunction(uint8_t timebase);

#endif

