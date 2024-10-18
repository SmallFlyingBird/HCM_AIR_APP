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
/*NTC1-NTC5  MATRIX1-MATRIX2*/
#define MAX_NTC_NUM 8

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
 *				   id : ChannelID1 - ChannelID12			        
 */
uint8_t Interface_GetChannelDerateRatioOfNtc(E_ChannelID id);
void NtcDerateMainFunction(uint8_t timebase);
#endif