/*
 * ASW_Manager.h
 *
 *  Created on: 2024.04.07
 *      Author: mihuiliang
 */
#ifndef _ASW_MANAGER_H_
#define _ASW_MANAGER_H_
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
void ASW_Manager_MainFunction_5ms(void);
void ASW_Manager_MainFunction_10ms(void);
void ASW_Manager_MainFunction_20ms(void);
void ASW_Manager_MainFunction_50ms(void);
void ASW_Manager_MainFunction_100ms(void);
Std_ReturnType ASW_Manager_Init(void);
#endif