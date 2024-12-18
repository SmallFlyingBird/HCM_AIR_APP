
#ifndef _LB_LIGHTING_H_
#define _LB_LIGHTING_H_

/* 近光灯配置信息 */
typedef struct
{
    uint16 LBChannelMask;
    E_LedGamma  LedGamma;

    uint16 SelfOnRampTime;
    uint16 SelfOffRampTime;
    uint8  SelfOnDelayTime;
    uint8  SelfOffDelayTime;
}S_LowBeamConfigInfo;

/* 近光运行状态 */
typedef enum
{
    E_LowBeamState_OffDelay = 0, /* 关闭延时 */
    E_LowBeamState_OnDelay  = 1, /* 开启延时 */
    E_LowBeamState_Run      = 2, /* 运行 */
}E_LowBeamRunState;

//近光灯运行信息
typedef struct
{
    uint8 Pwm_Self;
    uint8 Pwm_Target;
    uint8 Pwm_LastTarget;
    uint16 Cur_Target;
    E_LowBeamRunState RunState;

    uint16 OnRampTime;
    uint16 OffRampTime;
    uint8  OnDelayTime;
    uint8  OffDelayTime;
}S_LowBeamRunInfo;


void LowBeam_Init(void);
void LowBeam_MainFunction(uint8_t timebase);

#endif  
