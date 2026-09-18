/********************************
 * DCMotor.h
 *
 *  Created on: 2024/7/17
 *      Author: tujiongjiong
 ********************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "PulseGenerator_Interface.h"
#include "HSDManage.h"
#include "AdcDev_Interface.h"
#include "DTC_Interface.h"
#include "Lighting.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define DCMOTOR_PWM_CYCLE       (1000u) /* 直流电机控制的PWM周期 10K */
#define DCMOTOR_TEST            (0u)
#define DCMOTOR_START_DELAY     (100U)
#define DCMOTOR_END_EARLY       (1000U)
#define DCMOTOR_PWM_STEP_DELTA  (16U)
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/* 直流电机运行状态 */
typedef enum
{
    E_DCMotRunState_OFF = 0,
    E_DCMotRunState_RUN = 1,
    E_DCMotRunState_ERR = 2
}E_DCMotRunState;

/* 直流电机故障状态信息 */
typedef union
{
    uint8_t Status;
    struct
    {
        unsigned HSDVolt :1;
        unsigned HSDHW   :1;
        unsigned Stall   :1; //堵转故障
        unsigned CtrLine :1;
        unsigned Signal  :1;
        unsigned res     :3;
    }Bits;
}U_DCMotErrStatus;


/* 直流电机运行信息 */
typedef struct
{
    uint8_t PosPwm_Last;
    uint8_t PosPwm_Curr;
    E_HSDActSta HSDActSta;
    uint16_t LastStartupTime;
    E_DCMotRunState RunState;
    U_DCMotErrStatus ErrStatus;
}S_DCMotorRunInfo;


/* 直流电机配置信息 */
typedef struct
{
    uint8 LvlType; //E_LvlType_DcMot   = 3, /* 直流电机 */
    E_HSChannel HSChannel;

    uint8_t  CntrlSCG; //直流电机控制PIN对地短路的阈值  1  未使用
    uint8_t  CntrlSCB; //直流电机控制PIN对电源短路的阈值 93  未使用
    uint16_t IOutStallHSD;  //电机HSD堵转的电流阈值 800
    uint8_t  ManLvlDCPos1;  //直流电机的档位1 38
    uint8_t  ManLvlDCPos2;  //直流电机的档位2 54
    uint8_t  ManLvlDCPos3;  //直流电机的档位3 69
    uint8_t  ManLvlDCPos4;  //直流电机的档位4 85
    uint8_t  ManLvlDCPos5;  //直流电机的档位5 85
    uint8_t  LVLSafetyPos;  //直流电机的安全位置 22
    uint8_t  CntrlLowrThd;  //直流电机的下极限位置 20
    uint8_t  CntrlUpprThd;  //直流电机的上极限位置 85
    uint16_t DeactDlyTi;    //直流电机的停用延时时间 8000
}S_DCMotorConfigInfo;

/****************************************************************
 *                                                              *
 *                     Variable                         *
 *                                                              *
 ****************************************************************/
static uint8 DcmotorCheckFlag = 0;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* 直流电机启动初始化 */
void DCMotor_Init(void);

/* 直流电机主函数 */
void DCMotor_MainFunction(uint8_t timebase);
Std_ReturnType DCMotor_GetErrStatus(void);
Std_ReturnType DCMotor_GetSIGErrStatus(void);
static void DCMotor_SetDtcErrDetect(uint8 status);
static Std_ReturnType DCMotor_GetDtcErrDetect(void);
#endif

