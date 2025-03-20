
#ifndef NTCRCOD_INTERFACE_NTCRCOD_INTERFACE_H_
#define NTCRCOD_INTERFACE_NTCRCOD_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AdcDev_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define NTCRCOD_BUFFER_ARRAY_NUM 5
#define MAX_NTCRCOD_NUM 6

#define RCOD_DETECT_DELAY 0

#define NTC_HYSTERESIS_0_5								409			/*0.5V*/
#define NTCSIGNAL_SHORT2GND_ADVAL_THRESHOLD				164			/*0.2v*/
#define NTCSIGNAL_OPEN_OR_SHORT2VCC_ADVAL_THRESHOLD		4063		/*4.96v*/

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum{
	E_NtcRcodFunction_NONE=0,
	E_NtcRcodFunction_Ntc1=1,//NTC
	E_NtcRcodFunction_Ntc2,
	E_NtcRcodFunction_Ntc3,
	E_NtcRcodFunction_Ntc4,
	E_NtcRcodFunction_Ntc5,
    E_NtcRcodFunction_Ntc6,

	E_NtcRcodFunction_Rcod1,//BIN
	E_NtcRcodFunction_Rcod2,
	E_NtcRcodFunction_Rcod3,
}E_NtcRcodFunction;


typedef struct NtcRcodInfo{
	E_NtcRcodFunction NtcRcodFunction;
	E_AdcFunction NtcRcodMapToAdcFunction;    
	uint8_t  bufferindex;	
	uint8_t  DataFirstCalcuComplete;
	uint8_t Short2GndFlag;
	uint8_t OpenOrShort2VccFlag;
	sint16 	NtcTemp;
	uint16_t RcodCurrent;
	uint16_t  DefaultRcodIndrexOrFaultNtcTemp;
	uint16_t Map2ChannelMask;
	uint32_t Databuffer[NTCRCOD_BUFFER_ARRAY_NUM];
	uint32_t DataMeanlValue;
}S_NtcRcodInfo;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*
 *Function: Get Channel Mask .
 *return value:  E_OK : Get Channel Mask successfully
 *      		 E_NOT_OK : Get Channel Mask fail (fail reason may be: 1. para->NtcRcodFunction NTC is not congfiged
 * 																		  )
 *Parameter:
 *				   NtcRcodFunction : all enum type of E_NtcRcodFunction        
 */
Std_ReturnType Interface_GetNtcRcodMap2ChannelMask(E_NtcRcodFunction NtcRcodFunction,uint16_t* channelmask);
/*
 *Function: Get Ntc temperature .
 *return value:  E_OK : Get Ntc temperature successfully
 *      		 E_NOT_OK : Get Ntc temperature fail (fail reason may be: 1. para->NtcRcodFunction NTC is not congfiged
 * 																		  2. Ntc temp has not caculated completely)
 *Parameter:
 *				   NtcRcodFunction : E_NtcRcodFunction_Ntc1 - E_NtcRcodFunction_Ntc5,
 *									 E_NtcRcodFunction_MatrixNtc1,E_NtcRcodFunction_MatrixNtc2	        
 */
Std_ReturnType Interface_GetNtcTemperature(E_NtcRcodFunction NtcRcodFunction,sint16* tmp);
Std_ReturnType Interface_NtcRcodInit(void);

Std_ReturnType RcodInterface_Mainfunction(uint8_t timebase);
Std_ReturnType NtcInterface_Mainfunction(uint8_t timebase);

sint16 Interface_GetNtcTemp(E_ChannelID id);//get ntc temp
uint8 Interface_GetChannelNtcError(E_ChannelID id);
#endif /* NTCRCOD_INTERFACE_NTCRCOD_INTERFACE_H_ */
