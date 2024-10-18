/********************************
 * MotorManage.h
 *
 *  Created on: 2024/7/18
 *      Author: tujiongjiong
 ********************************/

#ifndef MOTORMANAGE_H_
#define MOTORMANAGE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "MotorMotion_Interface.h"
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "LevelingMotor.h"
#include "SwivelingMotor.h"
#include "DTC_Interface.h"
#include "ComSignal_Interface.h"      /* 与CAN总通讯 */
#include "SystemService_Interface.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

#define RAD_PER_DEG 0.01745    /* 弧度每度 rad/deg */
#define DEG_PER_RAD 57.29578   /* 度每弧度 deg/rad */


#if (EMC_TEST_ENABLE == 1)
#define MOTORMANAGE_TEST 1
#define USAGEMODE_TEST 1
#else
#define MOTORMANAGE_TEST 0
#define USAGEMODE_TEST 0
#endif  /*(EMC_TEST_ENABLE == 1)*/

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
/* 调平类型 */
typedef enum
{
    E_LvlType_NotAval = 0, /* 无Lvl */
    E_LvlType_MHL     = 1, /* 手动调平，有Leveling电机 */
    E_LvlType_AHL     = 2, /* 自动调平，有Leveling电机 */
    E_LvlType_DcMot   = 3, /* 直流电机 */
}E_LvlType;

/* DBL类型 */
typedef enum
{
    E_DBLType_NotAval         = 0, /* 无DBL */
    E_DBLType_MotorWoHall     = 1, /* 步进电机没有霍尔，有Swiveling电机 */
    E_DBLType_MotorWiHall     = 2, /* 步进电机有霍尔，  有Swiveling电机 */
    E_DBLType_Matrix          = 3, /* 矩阵DBL */
    E_DBLType_CornerLight     = 4, /* 角灯DBL */
    E_DBLType_MotorWoHallWiCL = 5, /* 步进电机没有霍尔有角灯，有Swiveling电机 */
    E_DBLType_MotorWiHallWiCL = 6, /* 步进电机有霍尔有角灯，  有Swiveling电机 */
    E_DBLType_MatrixWiCL      = 7  /* 矩阵有角灯 */
}E_DBLType;

/* Leveling电机功能 */
typedef enum
{
    E_LvlFunction_AHB2  = 0,
    E_LvlFunction_TrMod = 1,
    E_LvlFunction_AFS   = 2,
    E_LvlFunction_MHL   = 3,
    E_LvlFunction_AHL   = 4,
}E_LvlFunction;

/* Swiveling电机功能 */
typedef enum
{
    E_SvlFunction_AFS = 0,
    E_SvlFunction_DBL = 1,
}E_SvlFunction;

/* Leveling电机功能故障状态 */
typedef union 
{
    uint16_t ErrSta;
    struct
    {
        unsigned SigErr_AHB2  :1;
        unsigned MotErr_AHB2  :1;
        unsigned SigErr_TrMod :1;
        unsigned MotErr_TrMod :1;
        unsigned SigErr_AFS   :1;
        unsigned MotErr_AFS   :1;
        unsigned SigErr_MHL   :1;
        unsigned MotErr_MHL   :1;
        unsigned SigErr_AHL   :1;
        unsigned MotErr_AHL   :1;
        unsigned res          :6;
    }Bits;
}U_LvlFuncErrSta;

/* Swiveling电机功能故障状态 */
typedef union 
{
    uint8_t ErrSta;
    struct
    {
        unsigned SigErr_AFS   :1;
        unsigned MotErr_AFS   :1;
        unsigned SigErr_DBL   :1;
        unsigned MotErr_DBL   :1;
        unsigned res          :4;
    }Bits;
}U_SvlFuncErrSta;

/* Leveling电机功能开启状态 */
typedef union 
{
    uint8_t ActSta;
    struct
    {
        unsigned ActSta_AHB2  :1;
        unsigned ActSta_TrMod :1;
        unsigned ActSta_AFS   :1;
        unsigned ActSta_MHL   :1;
        unsigned ActSta_AHL   :1;
        unsigned res          :3;
    }Bits;
}U_LvlFuncActSta;

/* Swiveling电机功能开启状态 */
typedef union 
{
    uint8_t ActSta;
    struct
    {
        unsigned ActSta_AFS   :1;
        unsigned ActSta_DBL   :1;
        unsigned res          :6;
    }Bits;
}U_SvlFuncActSta;


/* Leveling电机运行信息 */
typedef struct
{
    sint16_t PosIncre_AHB2;
    sint16_t PosIncre_TrMod;
    sint16_t PosIncre_AFS;
    sint16_t PosIncre_MHL;
    sint16_t PosIncre_AHL;

    sint16_t PosCoord_Need;
    sint16_t PosCoord_Real;
    U_LvlFuncErrSta FuncErrSta;
    U_LvlFuncActSta FuncActSta;
}S_LvlRunInfo;

/* Swiveling电机运行信息 */
typedef struct
{
    sint16_t PosIncre_AFS;
    sint16_t PosIncre_DBL;

    sint16_t PosCoord_Need;
    sint16_t PosCoord_Real;
    U_SvlFuncErrSta FuncErrSta;
    U_SvlFuncActSta FuncActSta;
}S_SvlRunInfo;

/* Leveling电机管理配置信息 */
typedef struct
{
    E_LvlType LvlType;

    uint16_t HsPerRad;     /* 半步每弧度 HS/rad */
    uint8_t  StepMode;     /* 步进模式 4/8/16/32 */

    sint16_t Safetypos;    /* 安全位置 HS */
    sint16_t DfltPos;      /* 默认位置 HS */
    sint16_t BotPos;       /* 底部逻辑位置 HS */
    sint16_t TopPos;       /* 顶部逻辑位置 HS */
    uint8_t  MinDistStart; /* 最小启动步 HS */
    uint8_t  MinDistTime;  /* 考虑最小启动步的停止时间 ms */
    sint8_t  LvlOffset;    /* Leveling电机初始偏移 HS */

    uint32_t UsageInterval; /* 过度使用时间窗口宽度 ms */
}S_LvlConfigInfo;

/* Swiveling电机丢电源复位 */
typedef enum
{
    E_SvlLossToDflt_No  = 1,
    E_SvlLossToDflt_Yes = 2,
}E_SvlLossToDflt;

/* Swiveling电机管理配置信息 */
typedef struct
{
    E_DBLType DBLType;

    uint16_t HsPerRad;       /* 半步每弧度 HS/rad */
    uint8_t  StepMode;       /* 步进模式 4/8/16/32 */

    sint16_t DfltPos;
    sint16_t LePos;
    sint16_t RiPos;
    uint8_t  MinDistStart; /* 最小启动步 HS */
    uint8_t  MinDistTime;  /* 考虑最小启动步的停止时间 ms */

    uint32_t UsageInterval; /* 过度使用时间窗口宽度 ms */
    E_SvlLossToDflt LossToDflt;   /* 丢失一路供电是否回到默认位置 */
}S_SvlConfigInfo;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 任意位长度有符号数 转 32位有符号数 */
sint32_t MotorManage_ConvertSigned_xToSigned_32(uint32_t Data, uint8_t BitSize);

/* Leveling电机，大灯上下角度增量 转 电机位置增量 */
/* AngleIncre：单位rad */
sint16_t MotorManage_LvlConvertAglIncreToPosIncre(double AngleIncre);

/* Swiveling电机，大灯左右角度增量 转 电机位置增量 */
/* AngleIncre：单位rad */
sint16_t MotorManage_SvlConvertAngleIncreToPosIncre(double AngleIncre);



/* 设置Leveling电机位置增量 */
void MotorManage_SetLevelingPosIncre(E_LvlFunction LvlFunction, sint16_t PosIncre);

/* 设置Swiveling电机位置增量 */
void MotorManage_SetSwivelingPosIncre(E_SvlFunction SvlFunction, sint16_t PosIncre);

/* 获取Leveling电机功能错误状态 */
U_LvlFuncErrSta MotorManage_GetLevelingFuncErrorState(void);

/* 获取Swiveling电机功能错误状态*/
U_SvlFuncErrSta MotorManage_GetSwivelingFuncErrorState(void);

/* 设置Leveling电机功能开启状态 */
void MotorManage_SetLevelingFuncActState(E_LvlFunction LvlFunction, uint8_t Value);

/* 设置Swiveling电机功能开启状态*/
void MotorManage_SetSwivelingFuncActState(E_SvlFunction SvlFunction, uint8_t Value);



/* 电机管理初始化 */
void MotorManage_Init(void);

/* 电机管理主函数 */
void MotorManage_MainFunction(uint8_t timebase);

#endif

