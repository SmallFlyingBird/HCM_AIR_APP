#include "DID_Interface.h"
#include "lighting.h"
#include "Channel_Interface.h"
#include "Parameter_Interface.h"
#include "BuckDerate_Interface.h"
#include "NtcRcod_Interface.h"
#include "BD18397.h"
#include "LRDirection_Interface.h"
#include "PduR_Callout.h"
#include "NtcDerate_Interface.h"
#include "Dem.h"
#include "AmbiDerate_Interface.h"
#define BASETEMP   55  //read temp DID need add the data
#define DID_D900_SETBIT(bitnumber,shiftnum) (Dem_GetDTC_Status(bitnumber) << shiftnum)



//did 0x4359~0x435F
typedef struct
{
    uint8 didsignalchannel_OutputLuminosity;
	uint16 didsignalchannel_Current;
	uint16 didsignalchannel_ActualVol;
	uint16 didsignalchannel_ActualFreq;
	uint32 didsignalchannel_Function;
	uint8 didsignalchannel_ThermResTemp;
}DiDSignalChannel;
DiDSignalChannel g_DiDSignalChannel[CHANNEL_NUM]={
    {.didsignalchannel_ActualFreq=0xffff,},
    {.didsignalchannel_ActualFreq=0xffff,},
    {.didsignalchannel_ActualFreq=0xffff,},
    {.didsignalchannel_ActualFreq=0xffff,},
    {.didsignalchannel_ActualFreq=0xffff,},
    {.didsignalchannel_ActualFreq=0xffff,},
};

typedef enum
{
    DID_LB_Function=0x01,
    DID_HB_Function=0x08,
    DID_DRL_Function=0x10,
    DID_POS_Function=0X20,
    DID_TI_Function=0X40,
} E_DidChannelFunData;
  
uint32 DidChannelFunction[5]={ DID_LB_Function,DID_HB_Function,DID_DRL_Function,DID_POS_Function,DID_TI_Function};

/* did read  0x4359~0x435F */
static void DID_Interface_GetDidSignal(E_ChannelID id)
{
    double channelvol=0;
    uint8 LF=0;
    uint16 LightFuncMask=0;

    g_DiDSignalChannel[id].didsignalchannel_OutputLuminosity=Interface_GetChannelCurPWM(id);
    g_DiDSignalChannel[id].didsignalchannel_Current = Interface_GetChannelCurCurrent(id);
    Interface_GetChannelVoltage(id, &channelvol);
    g_DiDSignalChannel[id].didsignalchannel_ActualVol=(uint16)(channelvol*10);
    LightFuncMask=GetLightFunctionsMaskByChNo(id);
    
    if(g_DiDSignalChannel[id].didsignalchannel_ActualFreq==0xffff)
    {
        g_DiDSignalChannel[id].didsignalchannel_ActualFreq = BD18397GetPWMDIM();
        for(LF = E_LowBeam; LF < E_TurnIndicator_Act; LF++)
        {
           if ((LightFuncMask & (1 << LF)) != 0)
           {
               g_DiDSignalChannel[id].didsignalchannel_Function |= DidChannelFunction[LF];
           }
        }
    }
    if(Interface_GetNtcTemp(id)<=200)
    {
        g_DiDSignalChannel[id].didsignalchannel_ThermResTemp =Interface_GetNtcTemp(id)+BASETEMP;//0xff;
    }
    else
    {
        g_DiDSignalChannel[id].didsignalchannel_ThermResTemp =0xff;
    }
}

/* 
offsetbit      totalbit  name      return H-L
bit0~bit7       8        pwm       data[0]
bit9~bit19      12       cur       data[1]+data[2]
bit20~bit35     16       vol       data[2]+data[3]+data[4]
bit36~bit51     16       freq      data[4]+data[5]+data[6]
bit52~bit79     28       function  data[6]+data[7]+data[8]+data[9]
bit80~bit87     8        temp      data[10]
 */   
void DID_Interface_Read_4359to435F(E_ChannelID id,uint8 *data)
{
    DID_Interface_GetDidSignal(id); //get the channel data
    data[0]  =g_DiDSignalChannel[id].didsignalchannel_OutputLuminosity&0xff;
    data[1]  =(g_DiDSignalChannel[id].didsignalchannel_Current>>4)&0xff;
    data[2]  =((g_DiDSignalChannel[id].didsignalchannel_Current&0x0f)<<4)|((g_DiDSignalChannel[id].didsignalchannel_ActualVol>>12)&0x0f);
    data[3]  =(g_DiDSignalChannel[id].didsignalchannel_ActualVol >>4)&0xff;
    data[4]  =((g_DiDSignalChannel[id].didsignalchannel_ActualVol&0x0f)<<4)|((g_DiDSignalChannel[id].didsignalchannel_ActualFreq >>12)&0x0f);
    data[5]  =(g_DiDSignalChannel[id].didsignalchannel_ActualFreq >>4)&0xff;
    data[6]  =((g_DiDSignalChannel[id].didsignalchannel_ActualFreq &0x0f)<<4)| (g_DiDSignalChannel[id].didsignalchannel_Function>>24)&0x0f;
    data[7]  =(g_DiDSignalChannel[id].didsignalchannel_Function>>16)&0xff;
    data[8]  =(g_DiDSignalChannel[id].didsignalchannel_Function>>8)&0xff;
    data[9]  = g_DiDSignalChannel[id].didsignalchannel_Function&0xff;
    data[10] =  g_DiDSignalChannel[id].didsignalchannel_ThermResTemp&0xff; 
}


// 20250303:(BUCK0+BUCK1)/2
void DID_Interface_Read_43CF(uint8 *data)
{
    data[0]=(uint8)((Interface_GetTemp(0)+Interface_GetTemp(1))/2+BASETEMP);
}

/* 
boost temp 
*/
void DID_Interface_Read_43D2(uint8 *data)
{
    data[0] = (uint8)(Interface_GetEnviroment() + 55);
}

/*
BUF[1]APP   L=1  R=2
BUF[2]Boot  L=1  R=2
*/
void DID_Interface_Read_43DA(uint8 *data)
{
    data[0] = PduR_GetLightSide();
    data[1] = Interface_GetLRDirection();
}

/* model temp */
void DID_Interface_Read_4351(uint8 *data)
{
    data[0]=(uint8)(Interface_GetEnviroment()+55);
}

typedef union
{
    uint8 error;
    struct
    {
        uint8 tirgger :1;
        uint8 history :1;
        uint8 Record  :1;
        uint32 rcv    :6;
    }bits;
} S_DID_D900_ERROR_TYPE;
S_DID_D900_ERROR_TYPE DIDReadD900[D900_NUM];

/* 应用层设置故障接口函数 */
void Interface_SetD900Data(E_D900_Type type,Error_Type error)
{
    if(error==1)
    {
        DIDReadD900[type].bits.tirgger=1;       /* 实时故障  */
        DIDReadD900[type].bits.Record=1;        /* 记录历史故障 */
        DIDReadD900[type].bits.history=0;
    }
    else
    {
        DIDReadD900[type].bits.tirgger=0;                               /* 实时故障 */
        DIDReadD900[type].bits.history=DIDReadD900[type].bits.Record;  /*  历史故障 */
    }
}
/* 应用层读故障接口函数 */
uint8 Interface_ReadDIDData(E_D900_Type type)
{
    return DIDReadD900[type].bits.tirgger;
}
                   
void DID_Interface_Read_D900(uint8 *data)
{ 
    data[0]  = (DIDReadD900[NTC1_OL].error       &0x03) |((DIDReadD900[NTC1_SCB].error      <<2)  &0x0c) |((DIDReadD900[NTC1_SCG].error      <<4)&0x30) | ((DIDReadD900[WDG_Safety_SPI].error<<6)&0xC0);
    data[1]  = (DIDReadD900[NTC3_SCG].error      &0x03) |((DIDReadD900[NTC4_SCG].error      <<2)  &0x0c) |((DIDReadD900[NTC2_SCB].error      <<4)&0x30) | ((DIDReadD900[NTC2_SCG ].error     <<6)&0xC0);
    data[2]  = (DIDReadD900[NTC4_SCB].error      &0x03) |((DIDReadD900[NTC2_OL].error       <<2)  &0x0c) |((DIDReadD900[NTC3_OL].error       <<4)&0x30) | ((DIDReadD900[NTC3_SCB ].error     <<6)&0xC0);
    data[3]  = (DIDReadD900[NTC5_OL].error       &0x03) |((DIDReadD900[NTC5_SCB].error      <<2)  &0x0c) |((DIDReadD900[NTC5_SCG].error      <<4)&0x30) | ((DIDReadD900[NTC4_OL ].error      <<6)&0xC0);
    data[4]  = (DIDReadD900[LR_Detection].error  &0x03) |((DIDReadD900[Rcod3_Fail].error    <<2)  &0x0c) |((DIDReadD900[Rcod2_Fail].error    <<4)&0x30) | ((DIDReadD900[Rcod1_Fail].error    <<6)&0xC0);
    data[5]  = (DIDReadD900[Channel1_UV].error   &0x03) |((DIDReadD900[Channel1_OL].error   <<2)  &0x0c) |((DIDReadD900[Channel1_SCB].error  <<4)&0x30) | ((DIDReadD900[Channel1_SCG].error  <<6)&0xC0);
    data[6]  = (DIDReadD900[Channel2_UV].error   &0x03) |((DIDReadD900[Channel2_OL].error   <<2)  &0x0c) |((DIDReadD900[Channel2_SCB].error  <<4)&0x30) | ((DIDReadD900[Channel2_SCG].error  <<6)&0xC0);
    data[7]  = (DIDReadD900[Channel3_UV].error   &0x03) |((DIDReadD900[Channel3_OL].error   <<2)  &0x0c) |((DIDReadD900[Channel3_SCB].error  <<4)&0x30) | ((DIDReadD900[Channel3_SCG].error  <<6)&0xC0);
    data[8]  = (DIDReadD900[Channel4_UV].error   &0x03) |((DIDReadD900[Channel4_OL].error   <<2)  &0x0c) |((DIDReadD900[Channel4_SCB].error  <<4)&0x30) | ((DIDReadD900[Channel4_SCG].error  <<6)&0xC0);
    data[9]  = (DIDReadD900[Channel5_UV].error   &0x03) |((DIDReadD900[Channel5_OL].error   <<2)  &0x0c) |((DIDReadD900[Channel5_SCB].error  <<4)&0x30) | ((DIDReadD900[Channel5_SCG].error  <<6)&0xC0);
    data[10] = (DIDReadD900[Channel6_UV].error   &0x03) |((DIDReadD900[Channel6_OL].error   <<2)  &0x0c) |((DIDReadD900[Channel6_SCB].error  <<4)&0x30) | ((DIDReadD900[Channel6_SCG].error  <<6)&0xC0);
    data[11] = (DIDReadD900[HSD2_SCB_OL].error   &0x03) |((DIDReadD900[HSD2_SCG].error      <<2)  &0x0c) |((DIDReadD900[HSD1_SCB_OL].error   <<4)&0x30) | ((DIDReadD900[HSD1_SCG ].error     <<6)&0xC0);
    data[12] = (DIDReadD900[Side_Detection].error&0x03) |((DIDReadD900[In_LED_driver].error <<2)  &0x0c) |((DIDReadD900[HSD3_SCB_OL].error   <<4)&0x30) | ((DIDReadD900[HSD3_SCG].error      <<6)&0xC0);
    data[13] = (DIDReadD900[DC_Motor_Fail].error &0x03) |((DIDReadD900[CC_OverRange].error  <<2)  &0x0c) |((DIDReadD900[TI_E2E_failure].error<<4)&0x30) | ((DIDReadD900[LB_E2E_failure].error<<6)&0xC0);
    data[14] = (DIDReadD900[CalData_fail].error  &0x03) |((DIDReadD900[Parameter_Fail].error<<2)  &0x0c) |((DIDReadD900[KL56_Too_Low].error  <<4)&0x30) | ((DIDReadD900[KL56_Too_High].error <<6)&0xC0) ;
    data[15] = 0 ;
}
            