
#ifndef _DERATERATIOMANAGER_INTERFACE_H_
#define _DERATERATIOMANAGER_INTERFACE_H_
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
typedef enum _Derate_
{
    DERA_UN = 0,    /* Un-Derate */
    DERA_ECU,       /* for Buck temperature */
    DERA_LED,       /* for LED board temperature */
    DERA_AMB,       /* for Ambient temperature */
    DERA_OUV,       /* for Over/Under Voltage */
}E_Derate_t;

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatio(E_ChannelID id);
E_Derate_t Interface_GetChannelDerateFor(E_ChannelID id);
void DerateRatioManagerFuncmain(uint8_t timebase);
#endif

