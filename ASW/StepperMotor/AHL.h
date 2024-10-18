/********************************
 * AHL.h
 *
 *  Created on: 2024/5/6
 *      Author: tujiongjiong
 ********************************/

#ifndef AHL_H_
#define AHL_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "DID_Interface.h"            /* 设置DID */
#include "ComSignal_Interface.h"      /* 与CAN总通讯 */
#include "LevelingMotor.h"
#include "MotorMotion_Interface.h"
#include "MotorManage.h"
#include "Lighting.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define STATIC_FILT_TIME  0    /* 静态调平滤波时间 ms */
#define LB_DISTANCE 35         /* 近光灯照射水平距离 m */

#define BUMPY_ANGLE_THRES 1    /* 颠簸路面角度阈值 deg */
#define BUMPY_COUNT_ENTER 10   /* 颠簸路面模式进入数 */
#define BUMPY_COUNT_QUIT  2    /* 颠簸路面模式退出数 */

#define SLOPE_ANGLE_THRES 0.5  /* 坡道角度阈值 deg */
#define SLOPE_CONFRM_TIME 2000 /* 坡道模式确认时间 ms */

#define RAPID_FIXED_ANGLE 1.2  /* 急加减速固定偏移角度 deg */
#define RAPID_ACCSP_THRES 6.0  /* 急加减速加速度阈值 km/h/s */
#define RAPID_KEEP_TIME   2000 /* 急加减速保持时间 ms */


#define AHL_TEST 0


/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
/* AHL DID信息 */
typedef struct
{
    enum  
    {
        AHLStatus_Off   = 0,
        AHLStatus_On    = 1,
        AHLStatus_Error = 2,
        AHLStatus_Res   = 3
    }AHLStatus;
}S_AHLDidInfo;

/* AHL运行模式 */
typedef enum
{
    E_AHLMode_OFF             = 0, /* 关闭 */
    E_AHLMode_Static          = 1, /* 静态模式 */
    E_AHLMode_Dyna_Bumpy      = 2, /* 动态颠簸模式 */
    E_AHLMode_Dyna_Slope      = 3, /* 动态坡道模式 */
    E_AHLMode_Dyna_RapidAccel = 4, /* 动态急加速模式 */
    E_AHLMode_Dyna_RapidBrake = 5, /* 动态急减速模式 */
    E_AHLMode_ERROR           = 6  /* AHL故障 */
}E_AHLMode;

/* AHL运行信息 */
typedef struct
{
    E_AHLMode AHLMode;

    double   Static_AngleIncre;     /* 静态模式保存的车辆倾角，弧度，仰为正方向 */
    sint16_t Static_PosIncre;       /* 静态模式位置增量，也作为动态坡道模式的基础值 */

    double   Dynamic_SlopeAngleIncre;
    sint16_t Dynamic_SlopePosIncre; /* 动态坡道模式位置增量，作为动态急加减速模式的基础值 */

    sint16_t Dynamic_RpAccPosIncre; /* 动态急加速模式位置增量 */
    sint16_t Dynamic_RpBrkPosIncre; /* 动态急减速模式位置增量 */

    double AccelerateSpeed;         /* 车辆加速度值 m/s*s */
}S_AHLRunInfo;

/* AHL配置信息 */
typedef struct
{
    E_LvlType LvlType;
    
    double WheelBase;        /* 前后轴距 m */
    double HeadlampOverhang; /* 大灯与前轴的水平间距 m */
    double HeadlampHeight;   /* 大灯与地面的垂直高度 m */
}S_AHLConfigInfo;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 设置AHL的DID数据，4368 */
Std_ReturnType AHL_SetDID_4368_AHLStatus(void);


/* AHL初始化 */
void AHL_Init(void);

/* AHL主函数 */
/* 固定放到50ms任务中 */
void AHL_MainFunction_50ms(void);

#endif

