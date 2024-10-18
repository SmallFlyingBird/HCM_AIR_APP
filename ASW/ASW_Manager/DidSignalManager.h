/*
 * DidSignalManager.c
 *
 *  Created on: 2024.04.15
 *      Author: mihuiliang
 */

#ifndef DIDSIGNALMANAGER_H_
#define DIDSIGNALMANAGER_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
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

/* DID 43A8 峰值数据 */
typedef struct
{
    uint16_t PeakCurCh1;
    uint16_t PeakCurCh2;
    uint16_t PeakCurCh3;
    uint16_t PeakCurCh4;
    uint16_t PeakCurCh5;
    uint16_t PeakCurCh6;
    uint16_t PeakCurCh7;
    uint16_t PeakCurCh8;
    uint8_t  PeakTempRes1;
    uint8_t  PeakTempRes2;
    uint8_t  PeakTempRes3;
    uint8_t  PeakTempRes4;
    uint8_t  PeakTempRes5;
    uint8_t  PeakTempCtrMod;
    uint16_t PeakCurCh9;
    uint16_t PeakCurCh10;
    uint16_t PeakCurCh11;
    uint16_t PeakCurCh12;
}S_DID43A8PeakData;

/* DID 43A8 总计数据 */
typedef struct
{
    uint32_t TotalRunTimeCh1;
    uint32_t TotalRunTimeCh2;
    uint32_t TotalRunTimeCh3;
    uint32_t TotalRunTimeCh4;
    uint32_t TotalRunTimeCh5;
    uint32_t TotalRunTimeCh6;
    uint32_t TotalRunTimeCh7;
    uint32_t TotalRunTimeCh8;
    uint32_t TotalNumLedDera;
    uint32_t TotalNumFanStart;
    uint32_t TotalNumFanStartDei;
    uint32_t TotalNumFanStartDef;
    uint32_t TotalRunTimeFan;
    uint32_t TotalNumLvlStep;
    uint32_t TotalNumSwlStep;
    uint32_t TotalRunTimeCh9;
    uint32_t TotalRunTimeCh10;
    uint32_t TotalRunTimeCh11;
    uint32_t TotalRunTimeCh12;
}S_DID43A8TotalData;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

/* 设置DID 43A8信号的值 */
/* 峰值Peak设置当前最大值；无该配置不设值或设置无效值（无效值参考变量gs_DID43A8PeakDataCurr的初始化值) */
/* 总计值Total设置此次上电以来的累计值；无该配置不设值或设置无效值（无效值参考变量gs_DID43A8TotalDataCurr的初始化值) */
void DidSignalManager_SetDid43A8SignalData(uint16_t DidSignalID, uint32_t Value);

void DidSignalManagerMainFunction(uint8_t timebase);


#endif
