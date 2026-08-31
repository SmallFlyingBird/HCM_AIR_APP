/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mcu_PBcfg.h
 * @brief 
 * 
 */


#ifndef MCU_PB_CFG_H
#define MCU_PB_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID_PBCFG                      (180)
#define MCU_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define MCU_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define MCU_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define MCU_SW_MAJOR_VERSION_PBCFG               (2)
#define MCU_SW_MINOR_VERSION_PBCFG               (3)
#define MCU_SW_PATCH_VERSION_PBCFG               (0)

/**
 * @brief This union is utilized by Mcu_CmuNotification to indicate the detected CMU error.
 */
typedef struct {
    uint8 OUTRNG : 1;
    uint8 LOSR   : 1;
    uint8 LOSC   : 1;
} Mcu_CmuErrorType;



#define MCU_CONFIG_PB \
    extern const Mcu_ConfigType Mcu_Config;




#endif /* MCU_PB_CFG_H */

