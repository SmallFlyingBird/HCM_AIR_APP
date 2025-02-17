#ifndef _SYSTEMSERVICE_INTERFACE_H_
#define _SYSTEMSERVICE_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

void Interface_AddReInitDrvDevice(void);
Std_ReturnType SystemService_MainFunction(uint8_t timebase);

#endif

