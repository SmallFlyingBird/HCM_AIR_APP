/**************************************************************************************************/
/**
 * @file      : Device_Regs.h
 * @brief     : Z20K14xM device header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef DEVICE_REGS_H
#define DEVICE_REGS_H

#include "Device_Cfg.h"
#if (defined(DEV_Z20K148M))
    #include "Z20K148M.h"
    #include "Os_Processor.h"
#elif (defined(DEV_Z20K146M))
    #include "Z20K146M.h"
#elif (defined(DEV_Z20K144M))
    #include "Z20K144M.h"
#else
    #error "No valid CPU defined!"
#endif

#define DEVICE_REGS_H_VENDOR_ID                   0x00B3U
#define DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION    4U
#define DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION    6U
#define DEVICE_REGS_H_AR_RELEASE_REVISION_VERSION 0U
#define DEVICE_REGS_H_SW_MAJOR_VERSION            1U
#define DEVICE_REGS_H_SW_MINOR_VERSION            2U
#define DEVICE_REGS_H_SW_PATCH_VERSION            1U

/* Check if current file and Device_Cfg.h are the same vendor */
#if (DEVICE_REGS_H_VENDOR_ID != DEVICE_CFG_H_VENDOR_ID)
    #error "Vendor ID of Device_Regs.h and Device_Cfg.h are different"
#endif

/* Check if current file and Device_Cfg.h are the same Autosar version */
#if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != DEVICE_CFG_H_AR_RELEASE_MAJOR_VERSION) ||        \
        (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != DEVICE_CFG_H_AR_RELEASE_MINOR_VERSION) ||        \
        (DEVICE_REGS_H_AR_RELEASE_REVISION_VERSION != DEVICE_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Device_Regs.h and Device_Cfg.h are different"
#endif

/* Check if current file and Device_Cfg.h are the same Software version */
#if ((DEVICE_REGS_H_SW_MAJOR_VERSION != DEVICE_CFG_H_SW_MAJOR_VERSION) ||                        \
        (DEVICE_REGS_H_SW_MINOR_VERSION != DEVICE_CFG_H_SW_MINOR_VERSION) ||                        \
        (DEVICE_REGS_H_SW_PATCH_VERSION != DEVICE_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Device_Regs.h and Device_Cfg.h are different"
#endif

#ifdef DEV_Z20K148M
    /* Check if current file and Z20K148M.h are the same vendor */
    #if (DEVICE_REGS_H_VENDOR_ID != Z20K148M_H_VENDOR_ID)
        #error "Vendor ID of Device_Regs.h and Z20K148M.h are different"
    #endif

    /* Check if current file and Z20K148M.h are the same Autosar version */
    #if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != Z20K148M_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != Z20K148M_H_AR_RELEASE_MINOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_REVISION_VERSION != Z20K148M_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version of Device_Regs.h and Z20K148M.h are different"
    #endif

    /* Check if current file and Z20K148M.h are the same Software version */
    #if ((DEVICE_REGS_H_SW_MAJOR_VERSION != Z20K148M_H_SW_MAJOR_VERSION) ||                        \
         (DEVICE_REGS_H_SW_MINOR_VERSION != Z20K148M_H_SW_MINOR_VERSION) ||                        \
         (DEVICE_REGS_H_SW_PATCH_VERSION != Z20K148M_H_SW_PATCH_VERSION))
        #error "Software Version of Device_Regs.h and Z20K148M.h are different"
    #endif
#endif /*DEV_Z20K148M*/

#ifdef DEV_Z20K146M
    /* Check if current file and Z20K146M.h are the same vendor */
    #if (DEVICE_REGS_H_VENDOR_ID != Z20K146M_H_VENDOR_ID)
        #error "Vendor ID of Device_Regs.h and Z20K146M.h are different"
    #endif

    /* Check if current file and Z20K146M.h are the same Autosar version */
    #if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != Z20K146M_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != Z20K146M_H_AR_RELEASE_MINOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_REVISION_VERSION != Z20K146M_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version of Device_Regs.h and Z20K146M.h are different"
    #endif

    /* Check if current file and Z20K146M.h are the same Software version */
    #if ((DEVICE_REGS_H_SW_MAJOR_VERSION != Z20K146M_H_SW_MAJOR_VERSION) ||                        \
         (DEVICE_REGS_H_SW_MINOR_VERSION != Z20K146M_H_SW_MINOR_VERSION) ||                        \
         (DEVICE_REGS_H_SW_PATCH_VERSION != Z20K146M_H_SW_PATCH_VERSION))
        #error "Software Version of Device_Regs.h and Z20K146M.h are different"
    #endif
#endif /*DEV_Z20K146M*/

#ifdef DEV_Z20K144M
    /* Check if current file and Z20K144M.h are the same vendor */
    #if (DEVICE_REGS_H_VENDOR_ID != Z20K144M_H_VENDOR_ID)
        #error "Vendor ID of Device_Regs.h and Z20K144M.h are different"
    #endif

    /* Check if current file and Z20K144M.h are the same Autosar version */
    #if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != Z20K144M_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != Z20K144M_H_AR_RELEASE_MINOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_REVISION_VERSION != Z20K144M_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version of Device_Regs.h and Z20K144M.h are different"
    #endif

    /* Check if current file and Z20K144M.h are the same Software version */
    #if ((DEVICE_REGS_H_SW_MAJOR_VERSION != Z20K144M_H_SW_MAJOR_VERSION) ||                        \
         (DEVICE_REGS_H_SW_MINOR_VERSION != Z20K144M_H_SW_MINOR_VERSION) ||                        \
         (DEVICE_REGS_H_SW_PATCH_VERSION != Z20K144M_H_SW_PATCH_VERSION))
        #error "Software Version of Device_Regs.h and Z20K144M.h are different"
    #endif
#endif /*DEV_Z20K144M*/

#endif /* DEVICE_REGS_H */
