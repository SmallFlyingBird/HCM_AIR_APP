/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:36>
 */
/*============================================================================*/

#include "Rte_Dem.h"
#include "Rte_Dcm.h"
#define DEM_UNUSED(a) (void)(a)
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK includes>
 */

/* custom code.... */

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD00_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD00_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD00_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD01_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD01_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD01_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD02_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD02_ReadData>
    */
    /* custom code.... */
    DEM_UNUSED(Buffer);
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD02_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0A_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0A_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0A_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0B_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0B_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0B_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0C_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD0C_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD0C_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_20_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_20_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD00_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_21_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_DTC_TimeStamp_21_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD00_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_OC_5_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_OC_5_ReadData>
    */
    /* custom code.... */
    *Buffer = 0x00;
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD07_ReadData( uint8* Buffer )
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Call_Dem_CS_DataServices_DemDataElementClass_Did_0xDD07_ReadData>
    */
    /* custom code.... */
    Rte_Call_Dcm_CSDataServices_DcmDspData_0xDD07_ReadData(DCM_INITIAL, Buffer, NULL_PTR);
    DEM_UNUSED(Buffer);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

