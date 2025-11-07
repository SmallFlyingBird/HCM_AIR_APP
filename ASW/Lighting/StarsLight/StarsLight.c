#include "HcmPlatform.h"
#include "StarsLight.h"
#include "Dio_Cfg.h"
#include "ParaMgr.h"
#include "Lighting.h"
#include "Pwm_service.h"
#include "PduR_Callout.h"
/* 
hardware pin : PTB9 HW_OUT1 Trigger  X1-2
采用左侧HCM的Trig1实现星空灯的开、关、呼吸点亮
*/



void Interface_StarsLight_Ctrl(E_HwOutID id,uint8 per) 
{ 
    uint16 duty=0;
    uint16 setting=0;
    if(per>100)
    {
        per=100;
    }
    duty=(0x8000*(100-per))/100;
    if(id==HWOUT1)
    {
        PWM_Config_Trigger_Ctrl(duty);
    }
    else if(id==HWOUT2)
    {
        PWM_Config_Trigger_Ctr2(duty);
    }
}

static void StarOn(E_HwOutID id)
{
    Interface_StarsLight_Ctrl(id,100);
}

static void StarOff(E_HwOutID id)
{
    Interface_StarsLight_Ctrl(id,0);
}

/* the light to HWOUT1 HWOUT2 */
Std_ReturnType StarsLight_RunMainFun(void)
{
    uint16 lgmask1=0,lgmask2=0;
    uint8 SwitchOn=0;
    Light_Functions lf;
    uint8 StarOnFlag1=0;
    uint8 StarOnFlag2=0;
    #if 0
/* setting = 2000000/parameter */
    PWM_Config_Trigger_Ctrl(0);
    #elif 1
    if(ParaMgr_pStarrySkyLightEnable_B==0)
    {
        return E_NOT_OK;
    }
    if(PduR_GetLightSide()==AIR_437C_Direction_RIGHT)
    {
        return E_NOT_OK;
    }
    if(GetLgtStsEna_Charge()==1)
    {
        StarOff(HWOUT1);
        StarOff(HWOUT2);
    }
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        return E_OK;
    }
    lgmask1=ParaMgr_HW_OUT1_LF_MASK_W;
    for(lf=E_DaytimeRunningLight;lf<=E_ADSLight;lf++)
    {
        if(((lgmask1>>lf)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(lf);
            if(SwitchOn==ACT_ON)
            {
                StarOnFlag1=1;
            }
        }
    }
    lgmask2=ParaMgr_HW_OUT2_LF_MASK_W;
    for(lf=E_DaytimeRunningLight;lf<=E_ADSLight;lf++)
    {
        if(((lgmask2>>lf)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(lf);
            if(SwitchOn==ACT_ON)
            {
                StarOnFlag2=1;
            }
        }
    }
    if(StarOnFlag1==1)
    {
        StarOn(HWOUT1);
    }
    else 
    {
        StarOff(HWOUT1);
    }
    if(StarOnFlag2==1)
    {
        StarOn(HWOUT2);
    }
    else 
    {
        StarOff(HWOUT2);
    }
    #endif
    return E_OK;
    /* 
如果检测到ADS灯的硬件故障，则需要反馈ADS灯的错误状态；
如果检测到ADS灯的NTC故障，则需要反馈ADS灯的错误状态
    */
}
