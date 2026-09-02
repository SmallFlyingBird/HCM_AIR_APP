#include "Adc.h"
#include "Adc_Cfg.h"
#include "SafetyDrv.h"

static uint8 NumberCounter[4]={0,0,0,0};
void ADC0_CallBack_Group0()
{
    //Safety_TdgOutputCheckEnd(AdcConf_AdcGroup_Adc0_Group_0);
    if(NumberCounter[0]==255){
        NumberCounter[0]=0;
    }
   NumberCounter[0]++;
}

void ADC0_CallBack_Group1()
{
    //Safety_TdgOutputCheckEnd(AdcConf_AdcGroup_Adc0_Group_1);
    if(NumberCounter[1]==255){
        NumberCounter[1]=0;
    }
   NumberCounter[1]++;
}

void ADC1_CallBack_Group0()
{
    //Safety_TdgOutputCheckEnd(AdcConf_AdcGroup_Adc1_Group_0);
    if(NumberCounter[2]==255){
        NumberCounter[2]=0;
    }
   NumberCounter[2]++;
}

