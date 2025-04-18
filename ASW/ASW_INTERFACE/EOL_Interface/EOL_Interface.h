

#ifndef EOL_INTERFACE_H_
#define EOL_INTERFACE_H_

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
uint16_t Interface_EOLGetChannelMaskByLightFunction(Light_Functions lf);
uint16_t Interface_GetEOLChannelTableNormalCurrent(E_ChannelID id);
void Interface_SetFanSwitchOff(void);
void Interface_SetFanSwitchOn(void);
#endif 
