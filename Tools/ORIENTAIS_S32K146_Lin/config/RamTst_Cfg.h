

/*  Copyright (C) 2021, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       <RamTst_Cfg.h>
 *  brief
 *
 *  <Compiler: GHS 202014  MCU:S32K14X>
 *
 *  author     <Xin.Liu>
 *  date       <2024-12-16>
 */
/*============================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>   <REVISION LOG>
 *  V1.0.0     20210914     Xin.Liu   Initial version
 */
/*============================================================================*/

#ifndef RAMTST_CFG_H_
#define RAMTST_CFG_H_

#define RAMTST_CFG_H_SW_MAJOR_VERSION 1u /*Major Version*/
#define RAMTST_CFG_H_SW_MINOR_VERSION 0u /*Minor Version*/
#define RAMTST_CFG_H_SW_PATCH_VERSION 0u /*Patch Version*/
#define RAMTST_CFG_H_AR_MAJOR_VERSION 4u /*Autosar Major Version*/
#define RAMTST_CFG_H_AR_MINOR_VERSION 2u /*Autosar Minor Version*/
#define RAMTST_CFG_H_AR_PATCH_VERSION 2u /*Autosar Patch Version*/


#define RAMTST_DEV_ERROR_DETECT             STD_ON


#define RAM_SAFERESERVEAREA_START  (uint32)0x1fffe000u
#define RAM_SAFERESERVEAREA_END    (uint32)0x1fffefffu

#define RAM_LOCAL_VAR_AREA_START  (uint32)0x1ffff000u
#define RAM_LOCAL_VAR_AREA_END    (uint32)0x1ffff7ffu


#define RAMTST_BLOCK_NUM    6u
#define RAMTST_ALGPARAMS_NUM    1u

/************************************  API ENABLE  *****************************************/
#define RAMTST_STOP_API_ENABLE                               STD_ON
#define RAMTST_ALLOW_API_ENABLE                              STD_ON
#define RAMTST_SUSPEND_API_ENABLE                            STD_ON
#define RAMTST_RESUME_API_ENABLE                             STD_ON
#define RAMTST_GET_EXECUTION_STATUS_API_ENABLE               STD_ON
#define RAMTST_GET_TEST_RESULT_API_ENABLE                    STD_ON
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_API_ENABLE          STD_ON
#define RAMTST_VERSIONINFO_API_ENABLE                        STD_ON
#define RAMTST_GET_ALGPARAMS_API_ENABLE                      STD_ON
#define RAMTST_GET_TEST_ALGORITHM_API_ENABLE                 STD_ON
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_API_ENABLE         STD_ON
#define RAMTST_SELECT_ALGPARAMS_API_ENABLE                   STD_ON
#define RAMTST_CHANGE_NUM_OF_TESTED_CELLS_API_ENABLE         STD_ON
#define RAMTST_RUN_FULL_TEST_API_ENABLE                      STD_ON
#define RAMTST_RUN_PARTIAL_TEST_API_ENABLE                   STD_ON
#define RAMTST_TEST_COMPLETE_NOTIFICATION_API_ENABLE         STD_ON
#define RAMTST_TEST_ERROR_NOTIFICATION_API_ENABLE            STD_ON


#define RAMTST_SELF_CHECK_ENABLE                   STD_ON


#define RAMTST_DEM_MAIN_RAM_FAILURE_ENABLE     STD_OFF
#define RAMTST_DEM_PART_RAM_FAILURE_ENABLE     STD_OFF
#define RAMTST_DEM_RUNFL_RAM_FAILURE_ENABLE     STD_OFF

#endif /* RAMTST_CFG_H_ */

