
#ifndef _COMSIGNAL_INTERFACE_H_
#define _COMSIGNAL_INTERFACE_H_
#include "Ex_Lin.h"
#include "Platform_Types.h"
#include "Std_Types.h"
/****************************************************************
 *                                                              *
 *                  Get Base Signal                             *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam(void);
Std_ReturnType Interface_GetSignal_ActnOfLedHiBeam(void);
Std_ReturnType Interface_GetSignal_ActnOfLedDaytiRunngLamp(void);
Std_ReturnType Interface_GetSignal_ActnOfLedPosnLamp(void);
Std_ReturnType Interface_GetSignal_ActnOfLedFrntCrossLamp(void);
Std_ReturnType Interface_GetSignal_FrntCrossPrm(void);
Std_ReturnType Interface_GetSignal_ActvnOfIndcrIndcrOut(void);
Std_ReturnType Interface_GetSignal_IndcrSts(void);
Std_ReturnType Interface_GetSignal_IndcrNoSeq(void);
//获取左边电机开关信号
Std_ReturnType Interface_GetSignal_ClrDTCOfLINHCMLR(void);
//获取电机开关等级信号 1~5级
Std_ReturnType Interface_GetSignal_LvlgSwtSetReqLvlgSwtSetReq(void);
/****************************************************************
 *                                                              *
 *                  Get Dyn Signal                                  *
 *                                                              *
 ****************************************************************/


#endif