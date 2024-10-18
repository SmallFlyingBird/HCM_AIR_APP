/********************************
 * DBL.h
 *
 *  Created on: 2024/6/12
 *      Author: tujiongjiong
 ********************************/

#ifndef DBL_H_
#define DBL_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "DID_Interface.h"            /* 设置DID */
#include "ComSignal_Interface.h"      /* 与CAN总通讯 */
#include "SwivelingMotor.h"
#include "MotorManage.h"
#include "CorneringLight.h"
#include "DTC_Interface.h"
#include "Lighting.h"
#include "AFS.h"
#include "TOUR.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define SPEED_DBL_EN   10    /* DBL使能车速，km/h */
#define SPEED_DBL_DIS  5     /* DBL失能车速，km/h */
#define DEGREE_DBL_ON  20.0  /* DBL开启的方向盘角度，deg */
#define DEGREE_DBL_OFF 10.0  /* DBL关闭的方向盘角度，deg */
#define DEGREE_MIN_DIF 1.0   /* 电机DBL的方向盘最小启动角度，deg */
#define DEGREE_PXL_HYS 2.0   /* 矩阵DBL的方向盘回滞角度，deg */
#define STRW_FRTW_RATE 15.0  /* 方向盘和前轮角度比率 */



#define DBL_TEST 0

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
/* DBL DID信息 */
typedef struct
{
    enum  
    {
        DBLStatus_Off   = 0,
        DBLStatus_On    = 1,
        DBLStatus_Error = 2,
        DBLStatus_Res   = 3
    }DBLStatus;
}S_DBLDidInfo;

/* DBL运行状态 */
typedef enum
{
    E_DBLState_OFF    = 0,
    E_DBLState_Stdby  = 1,
    E_DBLState_Active = 2,
    E_DBLState_SigErr = 3,
    E_DBLState_MotErr = 4,
    E_DBLState_LBErr  = 5,
    E_DBLState_CLErr  = 6
}E_DBLState;

/* DBL运行信息 */
typedef struct
{
    E_DBLState DBLState;
    sint8_t ShiftNumTop_Last;
    sint8_t ShiftNumMddl_Last;
    sint8_t ShiftNumBttm_Last;
    sint8_t ShiftNumTop_Curr;
    sint8_t ShiftNumMddl_Curr;
    sint8_t ShiftNumBttm_Curr;
    double BendingAngle;         /* 弯曲角度，rad 左转为正 */
    const uint8_t * ptLBKinkPWM; /* 当前近光PWM指针 */
    uint8_t PxlShiftPWM[84];     /* 像素亮度偏移结果 */
}S_DBLRunInfo;



/* DBL配置信息 */
typedef struct
{
    E_DBLType  VehDBLType;

    uint8_t  CntrPxlBttm;
    uint8_t  CntrPxlMddl;
    uint8_t  CntrPxlTop;
    uint8_t  LeEdgePxlBttm;
    uint8_t  RiEdgePxlBttm;
    uint8_t  LeEdgePxlMddl;
    uint8_t  RiEdgePxlMddl;
    uint8_t  LeEdgePxlTop;
    uint8_t  RiEdgePxlTop;
    uint8_t  LeLimPxlBttm;
    uint8_t  RiLimPxlBttm;
    uint8_t  LeLimPxlMddl;
    uint8_t  RiLimPxlMddl;
    uint8_t  LeLimPxlTop;
    uint8_t  RiLimPxlTop;
    uint16_t TrnsnTime;
    uint16_t ShiftDlyTime;

    const uint8_t * ptLowBeamPWM;
    const uint8_t * ptTownLightPWM;
    const uint8_t * ptMotorWayPWM;
    const uint8_t * ptCountryLightPWM;
    const uint8_t * ptWeatherLightPWM;
    const uint8_t * ptLHTPWM;

    const uint16_t * ptLBPxlLeBdr;
    const uint16_t * ptLBPxlRiBdr;

    uint8_t  DBLCornerLightPWM;
}S_DBLConfigInfo;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 设置DBL的DID数据，4368 */
Std_ReturnType DBL_SetDID_4368_DBLStatus(void);

/* DBL近光Kink关闭 */
void DBL_LowBeamKink_OFF(void);

/* DBL近光Kink开启 */
void DBL_LowBeamKink_ON(uint8_t timebase);

/* DBL初始化 */
void DBL_Init(void);

/* DBL主函数 */
void DBL_MainFunction(uint8_t timebase);

#endif

