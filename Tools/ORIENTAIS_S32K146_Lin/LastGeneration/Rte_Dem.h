/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.h>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-12 15:24:14>
 */
/*============================================================================*/

#ifndef RTEDEM_H
#define RTEDEM_H

#include "Dem_Types.h"

/***************************DemDataElement Part****************************************/
extern Std_ReturnType  Rte_ReadData_Timestamp( uint8* Buffer );
extern Std_ReturnType  Rte_ReadData_Odomete( uint8* Buffer );
extern Std_ReturnType  Rte_ReadDataLVBatteryVoltage( uint8* Buffer );
extern Std_ReturnType  Rte_ReadData_VehicleSpeed( uint8* Buffer );
extern Std_ReturnType  Rte_ReadData_SnapShot( uint8* Buffer );

/***************************DemDataElement Part****************************************/

#endif /*RTEDEM_H*/
