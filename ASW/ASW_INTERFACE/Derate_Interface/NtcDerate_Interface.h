#ifndef _NTCDERATE_INTERFACE_H_
#define _NTCDERATE_INTERFACE_H_
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
/*NTC1-NTC5 */
#define MAX_NTC_NUM 6

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef struct{
    uint8_t TemperatureValied;
    sint16 CurTemperature;
}S_CurNtcTmperatureInfo;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*
 *Function: Get channel derate ratio of NtcTemp.
 *return value:  0->100  means 0%->100%
 *Parameter:
 *				   id : ChannelID1 - ChannelID4			        
 */
uint8_t Interface_GetChannelDerateRatioOfNtc(E_ChannelID id);
void NtcDerateMainFunction(uint8_t timebase);
sint16 Interface_GetEnviroment(void);
#endif

