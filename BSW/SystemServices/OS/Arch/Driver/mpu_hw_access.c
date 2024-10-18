/********************************************************************/
/*  Copyright (C) 2009-2025, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  File         : mpu_hw_access.c
 *  Brief        :
 *
 *  Revision History:
 *
 *      1. 2020-12-23: Initial version, add this file.
 *
 */
/*******************************************************************/

#include "mpu_hw_access.h"

/*******************************************************************************
 * Definitions
 *******************************************************************************/
/* Reset value of all master access right in region 0 */
#define REGION_0_ACCESS_RIGHT_RESET_VALUE (0x0061F7DFU)
/* Reset value of end address */
#define END_ADDRESS_RESET_VALUE (0x1FU)
/* Default value of privilege right */
#define DEFAULT_PRIVILEGE_RIGHT (MPU_SUPERVISOR_RWX_USER_RWX)
/* Default value of access right */
#define DEFAULT_ACCESS_RIGHT (MPU_RW)
/* Mask and Shift of access right */
#define MPU_USER_MASK        (0x07U)
#define MPU_USER_SHIFT       (0U)
#define MPU_SUPERVISOR_MASK  (0x18U)
#define MPU_SUPERVISOR_SHIFT (3U)
#define MPU_W_MASK           (0x20U)
#define MPU_W_SHIFT          (5U)
#define MPU_R_MASK           (0x40U)
#define MPU_R_SHIFT          (6U)
/*******************************************************************************
 * EOF
 *******************************************************************************/
