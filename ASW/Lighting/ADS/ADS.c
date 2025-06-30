
#include "ADS.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "ParaMgr.h"

typedef enum{
    ADS_Close=0,
	ADS_LowLight,
	ADS_HighLight,
}ADSBrightness;

static void ADS_On(E_ChannelID id,ADSBrightness adspwm)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0;
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_ADSLight);
    pwm=pwm*pwmramp/100;
    pwm=pwm*adspwm/100;         /* calculate ads brightness */
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm);
}

static void ADS_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

void ADS_RunMainFun(void)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    E_ChannelID id=ChannelID1;

    lgmask=GetChannelMaskByLightFunction(E_ADSLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(E_ADSLight);
            if(SwitchOn==ADS_LowLight)
            {
                ADS_On(id,ParaMgr_pIntenofADML1_B);
            }
            else if(SwitchOn==ADS_HighLight)
            {
                ADS_On(id,ParaMgr_pIntenofADML2_B);
            }
            else                        /* SwitchOn=0x01/0x03 ,close the ads */
            {
                ADS_Off(id);
            }     
        }
    }
}



