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
DiDSignalChannel g_DiDSignalChannel[CHANNEL_NUM];

typedef enum
{
    DID_LB_Function=0x02,
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

    g_DiDSignalChannel[id].didsignalchannel_OutputLuminosity=Interface_GetSignal_ChannelPwm(id);
    g_DiDSignalChannel[id].didsignalchannel_Current = Interface_GetSignal_ChannelCurrent(id);
    Interface_GetChannelVoltage(id, &channelvol);
    g_DiDSignalChannel[id].didsignalchannel_ActualVol=(uint16)(channelvol*10);
    g_DiDSignalChannel[id].didsignalchannel_ActualFreq = BD18397GetPWMDIM();
    LightFuncMask=GetLightFunctionsMaskByChNo(id);
    for(LF = E_LowBeam; LF < E_TurnIndicator_Act; LF++)
    {
       if ((LightFuncMask & (1 << LF)) != 0)
       {
           g_DiDSignalChannel[id].didsignalchannel_Function = DidChannelFunction[LF];
       }
    }
    g_DiDSignalChannel[id].didsignalchannel_ThermResTemp =Interface_GetNtcTemp(id)+BASETEMP;//0xff;
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
    data[0]=(uint8)((Interface_GetTemp(0)+Interface_GetTemp(1))/2+BASETEMP);
}

void DID_Interface_Read_D900(uint8 *data)
{
    /* byte0   bit0~1:spi error     bit2~3:NTC1 SCG     bit4~5:NTC1 SCB     bit6~7:NTC1 OL */
    data[0] = 0;

    /* byte1   bit0~1:NTC2 SCG      bit2~3:NTC2 SCB     bit4~5:NTC2 OL      bit6~7:NTC3 SCG */
    data[1] = 0;
    /* byte2   bit0~1:NTC3 SCB      bit2~3:NTC3 OL      bit4~5:NTC4 SCG     bit6~7:NTC4 SCB */
    data[2] = 0;
    /* byte3   bit0~1:NTC4 OL       bit2~3:NTC5 SCG     bit4~5:NTC5 SCB     bit6~7:NTC5 OL */
    data[3] = 0;
    /* byte4   bit0~1:Rcod1 Error   bit2~3:Rcod2 Error  bit4~5:Rcod3 Error  bit6~7:L/R identify error */
    data[4] = 0;
    /* byte5   bit0~1:channel1 SCG    bit2~3:channel1 SCB   bit4~5:channel1 OL  bit6~7:channel1 SCG UV */
    data[5] = DID_D900_SETBIT(14,0) | DID_D900_SETBIT(14,2) | DID_D900_SETBIT(14,4) | DID_D900_SETBIT(14,6);
    /* byte6   bit0~1:channel2 SCG    bit2~3:channel2 SCB   bit4~5:channel2 OL  bit6~7:channel1 SCG UV */
    data[6] = DID_D900_SETBIT(16,0) | DID_D900_SETBIT(16,2) | DID_D900_SETBIT(16,4) | DID_D900_SETBIT(16,6);
    /* byte7   bit0~1:channel3 SCG    bit2~3:channel3 SCB   bit4~5:channel3 OL  bit6~7:channel1 SCG UV */
    data[7] = DID_D900_SETBIT(18,0) | DID_D900_SETBIT(18,2) | DID_D900_SETBIT(18,4) | DID_D900_SETBIT(18,6);
    /* byte8   bit0~1:channel4 SCG    bit2~3:channel4 SCB   bit4~5:channel4 OL  bit6~7:channel1 SCG UV */
    /* byte9   bit0~1:channel5 SCG    bit2~3:channel5 SCB   bit4~5:channel5 OL  bit6~7:channel1 SCG UV */
    /* byte10   bit0~1:channel6 SCG    bit2~3:channel6 SCB   bit4~5:channel6 OL  bit6~7:channel1 SCG UV */
    /* byte11   bit0~1:HSD1 SCG        bit2~3:HSD1 SCB/OL    bit4~5:HSD2 SCG     bit6~7:HSD2 SCB/OL */
    data[11] = 0;
    /* byte12  bit0~1:HSD3 SCG        bit2~3:HSD3 SCB/OL   bit4~5:Reserve  bit6~7: Reserve*/
    /* byte13  bit0~1:LB E2E      bit2~3:TI E2E   bit4~5:Reserve  bit6~7:Dcmotor */
    data[13] = 0;
    /* byte14  bit0~1:      bit2~3:   bit4~5:  bit6~7: */
    /* byte15  bit0~1:      bit2~3:   bit4~5:  bit6~7: */

}