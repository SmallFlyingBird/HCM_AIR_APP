/********************************************************************/
/*  Copyright (C) 2009-2025, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  File         : mpu_driver.c
 *  Brief        :
 *
 *  Revision History:
 *
 *      1. 2020-12-23: Initial version, add this file.
 *
 */
/*******************************************************************/

#include "mpu_hw_access.h"
#include "Compiler.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Table of base addresses for MPU instances. */
/* static MPU_Type * const s_mpuBase[MPU_INSTANCE_COUNT] = MPU_BASE_PTRS;*/

/*******************************************************************************
 * Code
 *******************************************************************************/

/*!
 * @brief Calculate log2(n) size for a specific region
 *
 * @param[in] u32StartAddr Region Start address
 * @param[in] u32EndAddr    Region End address
 *
 * @return Region size as a power of 2
 */
static uint32 Mpu_CalculateRegionSize(uint32 u32StartAddr, uint32 u32EndAddr)
{
    uint32 finalSize = 0UL;
    u32EndAddr = u32EndAddr - u32StartAddr;
    while (u32EndAddr > 0)
    {
        finalSize++;
        u32EndAddr >>= 1;
    }

    return finalSize;
}
/*!
 * @brief Configure memory type
 *
 * @param[out] pRegionAttr RASR register where to save the attributes
 * @param[in]  eType         Memory type
 *
 * @return void
 */
static void Mpu_SetMemoryType(uint32* pRegionAttr, Mpu_M7_Ip_MemoryType eType)
{
    
}

/*!
 * @brief Set inner and outer cache policies
 *
 * @param[out] pRegionAttr    RASR register where to save the attributes
 * @param[in]  eInnerPolicy  Inner cache policy
 * @param[in]  eOuterPolicy  Outer cache policy
 *
 * @return void
 */
static void Mpu_SetCachePolicies(
    uint32* pRegionAttr,
    Mpu_M7_Ip_CachePolicyType eInnerPolicy,
    Mpu_M7_Ip_CachePolicyType eOuterPolicy)
{
    
}

/*!
 * @brief Set access rights
 *
 * @param[out] pRegionAttr    RASR register where to save the attributes
 * @param[in]  eAccessRights Region access rights
 *
 * @return void
 */
static void Mpu_ComputeAccessRights(uint32* pRegionAttr, Mpu_M7_Ip_AccessRightsType eAccessRights)
{
    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MPU_DRV_Init
 * Description    : Sets the MPU regions according to user input, and then enables the MPU.
 * Please note that access rights for region 0 will always be configured and
 * regionCnt takes values between 1 and the maximum region count supported by the hardware.
 * E.g. In S32K144 the number of supported regions is 8.
 * The user must make sure that the clock is enabled.
 *
 * Implements     : MPU_DRV_Init_Activity
 *END**************************************************************************/
status_t MPU_DRV_Init(Mpu_M7_Ip_ConfigType* pConfig)
{
    status_t retStatus = STATUS_SUCCESS;

    
    return retStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MPU_DRV_Deinit
 * Description    : De-initializes the MPU region by resetting and disabling MPU module.
 *
 * Implements     : MPU_DRV_Deinit_Activity
 *END**************************************************************************/
void MPU_DRV_Deinit()
{
    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MPU_DRV_SetRegionConfig
 * Description    : Sets the region configuration.
 *
 * Implements     : MPU_DRV_SetRegionConfig_Activity
 *END**************************************************************************/
status_t MPU_DRV_SetRegionConfig(uint8 u8RegionNum, const mpu_user_config_t* pUserConfigPtr)
{
    
    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MPU_DRV_GetDetailErrorAccessInfo
 * Description    : Checks and gets the MPU access error detail information
 * for a slave port.
 *
 * Implements     : MPU_DRV_GetDetailErrorAccessInfo_Activity
 *END**************************************************************************/
boolean MPU_DRV_GetDetailErrorAccessInfo(Mpu_M7_Ip_ErrorDetailsType* pErrorDetails)
{
    boolean result = FALSE;
    
    return result;
}

/*******************************************************************************
 * EOF
 *******************************************************************************/
