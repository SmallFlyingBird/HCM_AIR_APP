#ifndef _BUCKDERATE_INTERFACE_H_
#define _BUCKDERATE_INTERFACE_H_

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
#define BUCKTEMP_DATABUFFER_SIZE 5

#define BUCK_OVER_TEMP_THREHOLD	   130

#define	BuckDerateTemp1 	130
#define	BuckDerateRatio1 	100

#define	BuckDerateTemp2 	135
#define	BuckDerateRatio2 	95

#define	BuckDerateTemp3 	145
#define	BuckDerateRatio3 	60

#define	BuckDerateTemp4 	150
#define	BuckDerateRatio4 	55

#define	BuckDerateTemp5 	153
#define	BuckDerateRatio5 	55

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef struct BuckTmpInfo{
    uint8  DataFirstCalcuComplete;
    sint16 BuckCurTemp;
    uint8  BuckDataIndex;
    sint16 BuckTempData[BUCKTEMP_DATABUFFER_SIZE];
}S_BuckTmpInfo;


/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatioOfBuckTemp(E_ChannelID id);
void BuckDerateMainFunction(uint8_t timebase);
#endif
