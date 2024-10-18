/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-07-10 15:25:47>
 */
/*============================================================================*/

#ifndef RTEDEM_H
#define RTEDEM_H

#include "Dem_Types.h"

extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD00_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD01_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD02_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0A_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0B_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0C_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_20_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_21_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_OC_5_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD07_ReadData( uint8* Buffer );
#endif /*RTEDEM_H*/
