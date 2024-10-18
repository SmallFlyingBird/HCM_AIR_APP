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
#define CACULATE_BUCK_TEMP_AVERAGE_ENABLE   1
#define BUCK_DERATE_Temp_HYS                0

#if CACULATE_BUCK_TEMP_AVERAGE_ENABLE
#define BUCKTEMP_DATABUFFER_SIZE 5
#endif

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
#if (CACULATE_BUCK_TEMP_AVERAGE_ENABLE || BUCK_DERATE_Temp_HYS)
typedef struct BuckTmpInfo{
    uint8  DataFirstCalcuComplete;
    sint16 BuckCurTemp;
#if CACULATE_BUCK_TEMP_AVERAGE_ENABLE
    uint8  BuckDataIndex;
    sint16 BuckTempData[BUCKTEMP_DATABUFFER_SIZE];
#endif
}S_BuckTmpInfo;
#endif

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatioOfBuckTemp(E_ChannelID id);
void BuckDerateMainFunction(uint8_t timebase);
#endif