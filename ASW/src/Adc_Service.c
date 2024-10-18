#include "Adc.h"
#include "Adc_Cfg.h"
#include "SafetyDrv.h"

static uint8 NumberCounter[3]={0,0,0};
void ADC0_GroupNotification_0()
{
    Safety_TdgOutputCheckEnd(AdcConf_AdcGroup_ADC0_Group_0);
    if(NumberCounter[0]==255){
        NumberCounter[0]=0;
    }
   NumberCounter[0]++;
}

void ADC0_GroupNotification_1()
{
    Safety_TdgOutputCheckEnd(AdcConf_AdcGroup_ADC0_Group_1);
    if(NumberCounter[1]==255){
        NumberCounter[1]=0;
    }
   NumberCounter[1]++;
}

void ADC1_GroupNotification_0()
{
    Safety_TdgOutputCheckEnd(AdcConf_AdcGroup_ADC1_Group_0);
    if(NumberCounter[2]==255){
        NumberCounter[2]=0;
    }
   NumberCounter[2]++;
}
