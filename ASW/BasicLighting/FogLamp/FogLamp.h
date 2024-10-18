/********************************
 * FogLamp.h
 *
 *  Created on: 2024/4/15
 *      Author: tujiongjiong
 ********************************/

#ifndef FOGLAMP_H_
#define FOGLAMP_H_

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
#include "CorneringLight.h"

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


/* 雾灯DID信息 */
typedef struct
{
    enum  
    {
        FogLampStatus_Off   = 0,
        FogLampStatus_On    = 1,
        FogLampStatus_Error = 2,
        FogLampStatus_Res   = 3
    }FogLampStatus;
}S_FogLampDidInfo;



/* 雾灯运行状态 */
typedef enum
{
    E_FogLampState_OffDelay = 0, /* 关闭延时 */
    E_FogLampState_OnDelay  = 1, /* 开启延时 */
    E_FogLampState_Run      = 2, /* 运行 */
}E_FogLampRunState;

/* 雾灯运行信息 */
typedef struct
{
    uint8_t Pwm_AFS;
    uint8_t Pwm_Basic;
    uint8_t Pwm_Target;
    uint8_t Pwm_LastTarget;
    uint16_t ChannelMask;
    E_FogLampRunState RunState;
}S_FogLampRunInfo;

/* 雾灯配置信息 */
typedef struct
{
    uint16_t CLChannelMask;
    uint16_t FLChannelMask;
    E_LedGamma  LedGamma;
    uint8_t  IntensityDuty;
    uint16_t OnRampTime;
    uint16_t OffRampTime;
    uint8_t  OnDelayTime;
    uint8_t  OffDelayTime;
}S_FogLampConfigInfo;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 设置雾灯的DID数据，4368 */
Std_ReturnType FogLamp_SetDID_4368_FogLampStatus(void);




/* 雾灯AFS设置PWM */
void FogLamp_SetPwmOfAFS(uint8_t PwmValue);


/* 雾灯启动初始化 */
void FogLamp_Init(void);

/* 雾灯主函数 */
void FogLamp_MainFunction(uint8_t timebase);

#endif

