#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "HighSide_Interface.h"

//配置表 mapping 风扇对应高边1 直流电机对应高边2
void HsdM_Init(void)
{
    GetChannelMaskByLightFunction(E_Fan2);
    GetChannelMaskByLightFunction(E_DC_Motor);
}



