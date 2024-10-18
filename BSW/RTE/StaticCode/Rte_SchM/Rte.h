/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte.h>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-22 15:38:09>
 */
/*============================================================================*/

/* Rte.h */

#ifndef RTE_H
#define RTE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Std_Types.h"

/* Errors */
#define RTE_E_OK					((Std_ReturnType) 0)
#define RTE_E_INVALID				((Std_ReturnType) 1)
#define RTE_E_COMMS_ERROR			((Std_ReturnType) 128)
#define RTE_E_TIMEOUT				((Std_ReturnType) 129)
#define RTE_E_LIMIT					((Std_ReturnType) 130)
#define RTE_E_NO_DATA				((Std_ReturnType) 131)
#define RTE_E_TRANSMIT_ACK			((Std_ReturnType) 132)
#define RTE_E_NEVER_RECEIVED    	((Std_ReturnType) 133)
#define RTE_E_UNCONNECTED    	    ((Std_ReturnType) 134)
/* Overlayd errors */
#define RTE_E_LOST_DATA				((Std_ReturnType) 64)
#define RTE_E_MAX_AGE_EXCEEDED		((Std_ReturnType) 64)
#define RTE_FLAG_INVALID 			(uint8) 2
#define RTE_FLAG_COM_STOPPED 		(uint8) 4
#define RTE_FLAG_TX_TIMEOUT 		(uint8) 8
#define RTE_FLAG_RX_TIMEOUT 		(uint8) 16
#define RTE_FLAG_TRANSMIT_ACK 		(uint8) 64
/* SchM Errors */
#define SCHM_E_OK 					((Std_ReturnType) 0U)
#define SCHM_E_LIMIT 				((Std_ReturnType) 130U)
#define SCHM_E_NO_DATA 				((Std_ReturnType) 131U)
#define SCHM_E_TRANSMIT_ACK 		((Std_ReturnType) 132U)
#define SCHM_E_IN_EXCLUSIVE_AREA 	((Std_ReturnType) 135U)
#define SCHM_E_IN_TIMEOUT 			((Std_ReturnType) 129U)
#define SCHM_E_DEV_DEFECT 			((Std_ReturnType) 191U)




#endif

