/********************************
 * HSDManage.h
 *
 *  Created on: 2024/7/15
 *      Author: tujiongjiong
 ********************************/

#ifndef HSDMANAGE_H_
#define HSDMANAGE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "HighSide_Interface.h"
#include "PowerSupply_Interface.h"    /* 读供电电压作为高边通道电压 */
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "DTC_Interface.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define HSD_HW_TIME 5000 /* 打开高边后开始检测DTC的延时时间 */


/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/* 高边控制的激活状态 */
typedef enum
{
    E_HSDActSta_NoAct = 0, /* 不激活 */
    E_HSDActSta_Act   = 1, /* 激活 */
}E_HSDActSta;

/* 高边反馈的开关状态 */
typedef enum
{
    E_HSDSwitchSta_OFF = 0, /* 关闭 */
    E_HSDSwitchSta_ON  = 1, /* 开启 */
}E_HSDSwitchSta;

/* 高边控制和反馈状态 */
typedef union
{
    uint8_t State;
    struct
    {
        E_HSDActSta    HSD0ActSta    : 1;
        E_HSDSwitchSta HSD0SwitchSta : 1;
        E_HSDActSta    HSD1ActSta    : 1;
        E_HSDSwitchSta HSD1SwitchSta : 1;
    }Bits;
}U_HSDCtrFbSta;

/* 高边故障状态 */
typedef enum
{
    E_HSDErrSta_Normal   = 0, /* 正常 */
    E_HSDErrSta_VoltErr  = 1, /* 电压故障 */
    E_HSDErrSta_HWRTErr  = 2, /* 硬件实时故障 */
    E_HSDErrSta_HWDtcErr = 3  /* 硬件DTC故障 */
}E_HSDErrSta;

/* 高边运行状态 */
typedef enum
{
    E_HSDRunState_OFF            = 0, /* 正常，关闭 */
    E_HSDRunState_ON             = 1, /* 正常，开启 */
    E_HSDRunState_UnderVoltStop  = 2, /* 欠压暂停 */
    E_HSDRunState_OverVolt1Delay = 3, /* 过压一级延时 */
    E_HSDRunState_OverVolt1Stop  = 4, /* 过压一级暂停 */
    E_HSDRunState_OverVolt2Delay = 5, /* 过压二级延时 */
    E_HSDRunState_OverVolt2Stop  = 6, /* 过压二级暂停 */
    E_HSDRunState_HWError        = 7  /* 硬件故障停机 */
}E_HSDRunState;

/* 高边管理运行信息 */
typedef struct
{
    double   AllHSDVoltage; /* 实际值*10 */
    uint16_t HSD0Current;   /* mA */
    uint16_t HSD1Current;   /* mA */
    
    // U_HSDAndFan_Error HSDHWRTErrSta;
    // U_HSDAndFan_Error HSDHWDtcErrSta;

    U_HSDCtrFbSta HSDCtrFbSta;

    E_HSDRunState HSD0RunState;
    E_HSDRunState HSD1RunState;

    E_HSDErrSta HSD0ErrSta;
    E_HSDErrSta HSD1ErrSta;
}S_HSDManageRunInfo;


/* 高边配置的功能 */
typedef enum
{
    E_HSDFunction_NA    = 0,
    E_HSDFunction_Fan2  = 1,
    E_HSDFunction_DcMot = 2,
}E_HSDFunction;


/* 高边管理运行信息 */
typedef struct
{
    uint8_t HSD0MaxVolt; /* 实际值*10 */
    uint8_t HSD0MinVolt; /* 实际值*10 */
    uint8_t HSD1MaxVolt; /* 实际值*10 */
    uint8_t HSD1MinVolt; /* 实际值*10 */
    E_HSDFunction HSD0Func;
    E_HSDFunction HSD1Func;
}S_HSDManageConfigInfo;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 获取高边输入电压值 */
double HSDManage_GetHSDSupplyVoltage(void);

/* 获取高边输出电流值，单位mA */
uint16_t HSDManage_GetHSDOutputCurrent(E_HSChannel HSChannel);

/* 获取高边开关状态 */
E_HSDSwitchSta HSDManage_GetHSDSwitchState(E_HSChannel HSChannel);

/* 设置高边激活状态 */
void HSDManage_SetHSDActState(E_HSChannel HSChannel, E_HSDActSta ActSta);

/* 获取高边故障状态 */
E_HSDErrSta HSDManage_GetHSDErrState(E_HSChannel HSChannel);

/* 辅助灯启动初始化 */
void HSDManage_Init(void);

/* 辅助灯主函数 */
void HSDManage_MainFunction(uint8_t timebase);

#endif

