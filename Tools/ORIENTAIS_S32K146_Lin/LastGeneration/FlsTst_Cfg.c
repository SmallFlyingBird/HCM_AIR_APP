/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <FlsTst_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-12 15:24:14>
 */
/*============================================================================*/


/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>      <AUTHOR>         <REVISION LOG>
 *   V1.0.0     20210916     Huangyin         Initial version
 */
/*============================================================================*/


/*============================[I N C L U D E S]===============================*/
#include "FlsTst.h"
/*============================================================================*/

/*===================[V E R S I O N  I N F O R M A T I O N]===================*/
#define FLSTST_CFG_C_AR_MAJOR_VERSION     4U
#define FLSTST_CFG_C_AR_MINOR_VERSION     2U
#define FLSTST_CFG_C_AR_PATCH_VERSION     2U
#define FLSTST_CFG_C_SW_MAJOR_VERSION     1U
#define FLSTST_CFG_C_SW_MINOR_VERSION     0U
#define FLSTST_CFG_C_SW_PATCH_VERSION     0U 
/*============================================================================*/

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (FLSTST_CFG_C_AR_MAJOR_VERSION != FLSTST_CFG_H_AR_MAJOR_VERSION)
    #error "FlsTst_Cfg.c:Mismatch in Specification Major Version"
#endif 
#if (FLSTST_CFG_C_AR_MINOR_VERSION != FLSTST_CFG_H_AR_MINOR_VERSION)
    #error "FlsTst_Cfg.c:Mismatch in Specification Minor Version"
#endif
#if (FLSTST_CFG_C_AR_PATCH_VERSION != FLSTST_CFG_H_AR_PATCH_VERSION)
    #error "FlsTst_Cfg.c:Mismatch in Specification Patch Version"
#endif
#if (FLSTST_CFG_C_SW_MAJOR_VERSION != FLSTST_CFG_H_SW_MAJOR_VERSION)
    #error "FlsTst_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (FLSTST_CFG_C_SW_MINOR_VERSION != FLSTST_CFG_H_SW_MINOR_VERSION)
    #error "FlsTst_Cfg.c:Mismatch in Specification Minor Version"
#endif

#define FLSTST_START_SEC_CONST_UNSPECIFIED
#include "FlsTst_MemMap.h"
CONST( FlsTst_BlockBgndType, FLSTST_CONST) FlsTst_BlockBgnd[FLSTST_BGND_BLOCK_NUM];
CONST( FlsTst_BlockFgndType, FLSTST_CONST) FlsTst_BlockFgnd[FLSTST_FGND_BLOCK_NUM];

CONST( FlsTst_BlockBgndType, FLSTST_CONST) FlsTst_BlockBgnd[FLSTST_BGND_BLOCK_NUM] =
{
    {          
        0u,                 /* BgndBlockIndex   */
        0x10000u,           /* BlockBaseAddress */
        0x96000u,           /* BlcokLength      */
        0xF0010u,            /* SignatureAddress */
        FLSTST_32BIT_CRC,   /* TestAlgorithm    */
    }
};
CONST( FlsTst_BlockFgndType, FLSTST_CONST) FlsTst_BlockFgnd[FLSTST_FGND_BLOCK_NUM] =
{
     {          
    	0u,                 /* BgndBlockIndex   */
        0x10000u,           /* BlockBaseAddress */
        0x96000u,           /* BlcokLength      */
        0xF0010u,            /* SignatureAddress */
        FLSTST_32BIT_CRC,   /* TestAlgorithm    */
    }
};
CONST( FlsTst_ConfigType, FLSTST_CONST) FlsTst_Config=
{
    &FlsTst_BlockBgnd[0],         /* FlsTst_BgndBlockPtr*/
    &FlsTst_BlockFgnd[0],         /* FlsTst_BgndBlockPtr*/
    FlsTst_Notify                      /* FlsTstUserCallBack */
};
#define FLSTST_STOP_SEC_CONST_UNSPECIFIED
#include "FlsTst_MemMap.h"
