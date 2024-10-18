/*
 * PulseGeneratorDrv.h
 *
 *  Created on: 2024��2��17��
 *      Author: mihuiliang
 */

#ifndef CDD_DRIVER_PULSEGENERATORDRV_PULSEGENERATORDRV_H_
#define CDD_DRIVER_PULSEGENERATORDRV_PULSEGENERATORDRV_H_

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
#define MAX_PULSEGENERATOR_NUM 5

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
Std_ReturnType CddDriver_PulseGeneratorInit(void);
#endif /* CDD_DRIVER_PULSEGENERATORDRV_PULSEGENERATORDRV_H_ */
