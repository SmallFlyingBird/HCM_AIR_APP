/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_EcuM.c>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-22 15:38:09>
 */
/*============================================================================*/

/* Rte_EcuM.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "Rte_EcuM.h"
#include "Rte_ModeHandling.h"

/*******************************************************************************
 **                        Global Function                                    **
******************************************************************************/

/*******************************************************************************
*Function-Name        SchM_Switch_currentMode_currentMode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Std_ReturnType SchM_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode)
{
	return RTE_E_OK;
}

Std_ReturnType  SchM_SwitchAck_currentMode_currentMode(void)
{
	return RTE_E_OK;
}




