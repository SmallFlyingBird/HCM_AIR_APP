#include "ComSignal_Interface.h"


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








