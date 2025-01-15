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
void SystemService_MainFunction(uint8_t timebase);

#endif