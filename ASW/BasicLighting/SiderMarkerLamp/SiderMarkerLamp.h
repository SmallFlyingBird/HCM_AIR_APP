/********************************
 * SiderMarkerLamp.h
 *
 *  Created on: 2024/4/12
 *      Author: tujiongjiong
 ********************************/

#ifndef SIDERMARKERLAMP_H_
#define SIDERMARKERLAMP_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "HSDManage.h"
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "DID_Interface.h"            /* 设置DID */
#include "ComSignal_Interface.h"      /* 与CAN总通讯 */
#include "DTC_Interface.h"

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

/* 示廓灯DID信息 */
typedef struct
{
    enum  
    {
        SMLOutputStatus_Active    = 0,
        SMLOutputStatus_NoActive  = 1,
        SMLOutputStatus_NotConfig = 254,
        SMLOutputStatus_NotAvl    = 255
    }SMLOutputStatus;
    uint16_t CurrentFeedback;
    
    enum  
    {
        SMLStatus_Off   = 0,
        SMLStatus_On    = 1,
        SMLStatus_Error = 2,
        SMLStatus_Res   = 3
    }SMLStatus;
}S_SMLDidInfo;



/* 示廓灯运行状态 */
typedef enum
{
    E_SMLRunState_OFF     = 0, /* 正常，关闭状态 */
    E_SMLRunState_ON      = 1, /* 正常，开启状态 */
    E_SMLRunState_VoltErr = 2, /* 电压故障，暂停 */
    E_SMLRunState_HWErr   = 3, /* 硬件故障，停机 */
}E_SMLRunState;


/* 示廓灯配置信息 */
typedef struct
{
    E_SMLRunState RunState;
}S_SMLRunInfo;


/* 示廓灯配置信息 */
typedef struct
{
    E_HSChannel SMLHSDChannel;
}S_SMLConfigInfo;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 示廓灯DID控制回调函数 */
Std_ReturnType SiderMarkerLamp_IoCtrCallback(E_IOCtrType IOCtrTypeState);

/* 设置示廓灯的DID数据，4358 */
Std_ReturnType SiderMarkerLamp_SetDID_4358_SML(void);

/* 设置示廓灯的DID数据，4368 */
Std_ReturnType SiderMarkerLamp_SetDID_4368_SMLStatus(void);



/* 示廓灯启动初始化 */
void SiderMarkerLamp_Init(void);

/* 示廓灯主函数 */
void SiderMarkerLamp_MainFunction(uint8_t timebase);

#endif

