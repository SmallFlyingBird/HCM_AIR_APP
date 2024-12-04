/*
 * AswInterfaceManager.h
 *
 *  Created on: 2024��1��15��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_ASW_INTERFACE_MANAGER_ASWINTERFACEMANAGER_H_
#define ASW_INTERFACE_ASW_INTERFACE_MANAGER_ASWINTERFACEMANAGER_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AdcDev_Interface.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "DerateRatioManager_Interface.h"
#include "GeneralFunction.h"
#include "HcmPlatform.h"
#include "HighSide_Interface.h"
#include "List_Interface.h"
#include "LRDirection_Interface.h"
#include "NtcRcod_Interface.h"
#include "PowerSupply_Interface.h"
#include "PulseGenerator_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
/*�汾�� 0.0.0*/
#define ASW_INTERFACE_VERSION_HIGH_BYTE 		0
#define ASW_INTERFACE_VERSION_MIDDLE_BYTE 		0
#define ASW_INTERFACE_VERSION_LOW_BYTE 			0

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
void ASWInterfaceManagerMainFunc_2ms(void);
void ASWInterfaceManagerMainFunc_10ms(void);
void ASWInterfaceManagerMainFunc_20ms(void);
void ASWInterfaceManagerMainFunc_100ms(void);
void ASWInterfaceManagerMainFunc_1s(void);
Std_ReturnType AswInterfaceManagerInit(void);

#endif /* ASW_INTERFACE_ASW_INTERFACE_MANAGER_ASWINTERFACEMANAGER_H_ */
