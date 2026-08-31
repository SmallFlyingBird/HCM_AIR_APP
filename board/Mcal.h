/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mcal.h
 * @brief 
 * 
 */



#ifndef MCAL_H
#define MCAL_H




#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Compiler.h"
#include "Std_Types.h"

#include "Mcu.h"
#include "Mcu_PBcfg.h"
#include "Adc.h"
#include "Adc_PBcfg.h"
#include "Dio.h"
#include "EcuM.h"
#include "Det.h"
#include "Gpt.h"
#include "Gpt_PBcfg.h"
#include "Icu.h"
#include "Icu_PBcfg.h"
#include "Lin.h"
#include "Lin_PBcfg.h"
#include "Port.h"
#include "Port_PBcfg.h"
#include "Pwm.h"
#include "Pwm_PBcfg.h"
#include "Pwm_Lld_Etmr_PBcfg.h"
#include "Spi.h"
#include "Spi_PBcfg.h"
#include "Platform.h"

#ifdef MCU_CONFIG_PB
MCU_CONFIG_PB
#endif
#ifdef ADC_CONFIG_PB
ADC_CONFIG_PB
#endif
#ifdef GPT_CONFIG_PB
GPT_CONFIG_PB
#endif
#ifdef ICU_CONFIG_PB
ICU_CONFIG_PB
#endif
#ifdef LIN_CONFIG_PB
LIN_CONFIG_PB
#endif
#ifdef PORT_CONFIG_PB
PORT_CONFIG_PB
#endif
#ifdef PWM_CONFIG_PB
PWM_CONFIG_PB
#endif
#ifdef PWM_LLD_ETMR_CONFIG_PB
PWM_LLD_ETMR_CONFIG_PB
#endif
#ifdef SPI_CONFIG_PB
SPI_CONFIG_PB
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCAL_VENDOR_ID                    180
#define MCAL_MODULE_ID                    0
#define MCAL_AR_RELEASE_MAJOR_VERSION     4
#define MCAL_AR_RELEASE_MINOR_VERSION     4
#define MCAL_AR_RELEASE_REVISION_VERSION  0
#define MCAL_SW_MAJOR_VERSION             2
#define MCAL_SW_MINOR_VERSION             3
#define MCAL_SW_PATCH_VERSION             0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Compiler.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Compiler.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Std_Types.h are different"
    #endif
#endif



#define __ASM __asm  /* PRQA S 0603,0602,0844 */


#ifdef __cplusplus
}
#endif



#endif

