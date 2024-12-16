
/*============================================================================*/
/*  Copyright (C) 2009-2018, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <ComM_Cfg.c>
 *  @brief      <>
 *
 *  <MCU:TC1782>
 *
 *  @author     <>
 *  @date       2024/12/12 15:33:32
 */
/*============================================================================*/


/*=======[V E R S I O N  I N F O R M A T I O N]===================================================*/
#define COMM_CFG_C_AR_MAJOR_VERSION  4u
#define COMM_CFG_C_AR_MINOR_VERSION  2u
#define COMM_CFG_C_AR_PATCH_VERSION  2u
#define COMM_CFG_C_SW_MAJOR_VERSION  1u
#define COMM_CFG_C_SW_MINOR_VERSION  0u
#define COMM_CFG_C_SW_PATCH_VERSION  0u

/*================================[I N C L U D E S]===============================================*/
#include "ComM_Cfg.h"
#include "ComM.h"

/*=======[V E R S I O N  C H E C K]===============================================================*/
#if (COMM_CFG_C_AR_MAJOR_VERSION != COMM_CFG_H_AR_MAJOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Major Version"
#endif /*COMM_CFG_C_AR_MAJOR_VERSION != COMM_CFG_H_AR_MAJOR_VERSION */
#if (COMM_CFG_C_AR_MINOR_VERSION != COMM_CFG_H_AR_MINOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Minor Version"
#endif /*COMM_CFG_C_AR_MINOR_VERSION != COMM_CFG_H_AR_MINOR_VERSION */
#if (COMM_CFG_C_AR_PATCH_VERSION != COMM_CFG_H_AR_PATCH_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Patch Version"
#endif /*COMM_CFG_C_AR_PATCH_VERSION != COMM_CFG_H_AR_PATCH_VERSION */
#if (COMM_CFG_C_SW_MAJOR_VERSION != COMM_CFG_H_SW_MAJOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Major Version"
#endif /*COMM_CFG_C_SW_MAJOR_VERSION != COMM_CFG_H_SW_MAJOR_VERSION */
#if (COMM_CFG_C_SW_MINOR_VERSION != COMM_CFG_H_SW_MINOR_VERSION)
    #error "ComM_Cfg.c:Mismatch in Specification Minor Version"
#endif /*COMM_CFG_C_SW_MINOR_VERSION != COMM_CFG_H_SW_MINOR_VERSION */

/*===========================[E X T E R N A L   D A T A]==========================================*/
#define COMM_START_SEC_CONST_BOOLEAN
#include "ComM_MemMap.h"
CONST(boolean, COMM_CONST) ComMPncEnabledcfg = FALSE;    /*ComMPncEnabled*/

#define COMM_STOP_SEC_CONST_BOOLEAN
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "ComM_MemMap.h"

CONST(ComM_ChannelCfgType, COMM_CONST) ComM_ChannelConfig[COMM_NUMBER_OF_CHANNELS] =
{
    {
        COMM_BUS_TYPE_LIN,/*ComMBusType*/
        0u,    /*ComMCDDBusPrefix*/
        FALSE,   /*ComMFullCommRequestNotificationEnabled*/
        5u,  /*ComMMainFunctionPeriod*/
        FALSE, /*ComMNoWakeUpInhibitionNvmStorage*/
        COMM_LIGHT,   /*ComMNmVariant*/
        10000u, /*rev*/ /*ComMNmLightTimeout*/
    },
    {
        COMM_BUS_TYPE_LIN,/*ComMBusType*/
        0u,    /*ComMCDDBusPrefix*/
        FALSE,   /*ComMFullCommRequestNotificationEnabled*/
        5u,  /*ComMMainFunctionPeriod*/
        FALSE, /*ComMNoWakeUpInhibitionNvmStorage*/
        COMM_LINSLAVE,   /*ComMNmVariant*/
        0u, /*rev*/ /*ComMNmLightTimeout*/
    },
};

CONST(uint8, COMM_CONST) ComM_ChannelMapConfig[2][1] =
{
     {0x1u},
     {0x2u},
};


CONST(ComM_UserCfgType, COMM_CONST) ComM_UserConfig[COMM_NUMBER_OF_USERS] =
{
    {
        &ComM_ChannelMapConfig[0][0],/*UserToChannelMap*/
    },
    {
        &ComM_ChannelMapConfig[1][0],/*UserToChannelMap*/
    },
};








CONST(ComM_ConfigType, COMM_CONST) ComM_Config =
{
	&ComMPncEnabledcfg,	/*pComMPncEnabled, Multiplicity 0...1*/
	
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "ComM_MemMap.h"
