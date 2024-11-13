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
#include "SystemService_Interface.h"
#include "AdcDev_Interface.h"
#include "DTC_Interface.h"
#include "Lighting.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define DCMOTOR_PWM_CYCLE 100u /* 直流电机控制的PWM周期；us */


#define DCMOTOR_TEST 0u

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
        unsigned Stall   :1;
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

    uint8_t  CntrlSCG;
    uint8_t  CntrlSCB;
    uint16_t IOutStallHSD;
    uint8_t  ManLvlDCPos1;
    uint8_t  ManLvlDCPos2;
    uint8_t  ManLvlDCPos3;
    uint8_t  ManLvlDCPos4;
    uint8_t  ManLvlDCPos5;
    uint8_t  LVLSafetyPos;
    uint8_t  CntrlLowrThd;
    uint8_t  CntrlUpprThd;
    uint16_t DeactDlyTi;
}S_DCMotorConfigInfo;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* 直流电机启动初始化 */
void DCMotor_Init(void);

/* 直流电机主函数 */
void DCMotor_MainFunction(uint8_t timebase);

#endif

