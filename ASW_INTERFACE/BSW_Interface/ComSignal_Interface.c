#include "ComSignal_Interface.h"
#include "HcmPlatform.h"

extern Frame_ZcudZcud_Lin2Fr01 Frame_Zcud01 ;
extern Frame_ZcudZcud_Lin2Fr02 Frame_Zcud02 ;
/****************************************************************
 *                                                              *
 *                  Get Base Signal                             *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam(void)
{
    return Frame_Zcud01.Byte2.Bits.ActnOfLedLoBeamActnOfLedLoBeam;
}

Std_ReturnType Interface_GetSignal_ActnOfLedHiBeam(void)
{
    return Frame_Zcud01.Byte1.Bits.ActnOfLedHiBeam;
}

Std_ReturnType Interface_GetSignal_ActnOfLedDaytiRunngLamp(void)
{
    return Frame_Zcud01.Byte0.Bits.ActnOfLedDaytiRunngLamp;
}

Std_ReturnType Interface_GetSignal_ActnOfLedPosnLamp(void)
{
    return Frame_Zcud01.Byte1.Bits.ActnOfLedPosnLamp;
}

Std_ReturnType Interface_GetSignal_ActnOfLedFrntCrossLamp(void)
{
    return Frame_Zcud01.Byte0.Bits.ActnOfLedFrntCrossLamp;
}

Std_ReturnType Interface_GetSignal_FrntCrossPrm(void)
{
    return Frame_Zcud01.Byte0.Bits.ActnOfLedFrntCrossLamp;
}

Std_ReturnType Interface_GetSignal_ActvnOfIndcrIndcrOut(void)
{
    return Frame_Zcud01.Byte5.Bits.ActvnOfIndcrIndcrOut;
}

Std_ReturnType Interface_GetSignal_IndcrSts(void)
{
    return Frame_Zcud01.Byte5.Bits.IndcrSts;  
}

//流水信号 灯具不支持

//直流电机信号
Std_ReturnType Interface_GetSignal_ClrDTCOfLINHCMLR(void)
{
#ifdef HCM_AIR_LEFT
    return Frame_Zcud02.Byte1.Bits.ClrDTCOfLINHCML2; //获取左边电机开关信号
#elif HCM_AIR_RIGHT
    return Frame_Zcud02.Byte2.Bits.ClrDTCOfLINHCMR2; //获取右边电机开关信号
#endif
}

//获取电机开关等级信号 1~5级
Std_ReturnType Interface_GetSignal_LvlgSwtSetReqLvlgSwtSetReq(void)
{
    return Frame_Zcud02.Byte1.Bits.LvlgSwtSetReqLvlgSwtSetReq;
}






