/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_EcuM.h>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-24 16:09:13>
 */
/*============================================================================*/

/* Rte_EcuM.h */

#ifndef RTE_ECUM_H
#define RTE_ECUM_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Type.h"
#include "Rte_ModeHandling.h"
#include "Rte_EcuM_Type.h"
/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/
/** API functions */
Std_ReturnType SchM_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode);
Std_ReturnType  SchM_SwitchAck_currentMode_currentMode(void);


#endif

