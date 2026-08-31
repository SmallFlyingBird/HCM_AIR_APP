/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Dio_Cfg.c
 * @brief 
 * 
 */



#include "Dio.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DIO_VENDOR_ID_CFG_C                      (180)
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_C       (4)
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_C       (4)
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_C    (0)
#define DIO_SW_MAJOR_VERSION_CFG_C               (2)
#define DIO_SW_MINOR_VERSION_CFG_C               (3)
#define DIO_SW_PATCH_VERSION_CFG_C               (0)

/*==================================================================================================*/

#if (DIO_CHANNEL_GROUP_NUMBER != 0)

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

/**
* @brief          List of channel groups in configuration DioConfig.
*/
DIO_CONST const Dio_ChannelGroupType Dio_ChannelGroupConfig[DIO_CHANNEL_GROUP_NUMBER] = 
{
};


#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"
#endif

