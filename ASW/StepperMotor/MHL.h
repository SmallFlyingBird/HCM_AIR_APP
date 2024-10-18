/********************************
 * MHL.h
 *
 *  Created on: 2024/7/20
 *      Author: tujiongjiong
 ********************************/

#ifndef MHL_H_
#define MHL_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Parameter_Interface.h"      /* 读参数配置表 */
#include "MotorManage.h"
#include "LevelingMotor.h"
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


/* MHL配置信息 */
typedef struct
{
    E_LvlType LvlType;
    
    uint8_t  StepMode; /* 步进模式 4/8/16/32 */
    sint16_t DfltPos;  /* 默认位置 HS */
    sint16_t MHLPos1Incre;
    sint16_t MHLPos2Incre;
    sint16_t MHLPos3Incre;
    sint16_t MHLPos4Incre;
    sint16_t MHLPos5Incre;
}S_MHLConfigInfo;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* 辅助灯启动初始化 */
void MHL_Init(void);

/* 辅助灯主函数 */
void MHL_MainFunction(uint8_t timebase);

#endif

