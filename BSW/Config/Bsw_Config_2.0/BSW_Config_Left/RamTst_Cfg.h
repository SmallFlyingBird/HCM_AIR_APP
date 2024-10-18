
/*******************************************************************************
**                                                                            **
** Copyright(C)iSOFT (2022)                                                   **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document,and communication                  **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : RamTst_Cfg.h                                                **
**                                                                            **
**  Created on  : <2024-04-11>                      **
**  Author      : peng.wu                                                     **
**  Vendor      : iSOFT                                                       **
**  DESCRIPTION : Post-build configuration parameter of RamTst                **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
#ifndef RAMTST_CFG_H_
#define RAMTST_CFG_H_

/*===========================[I N C L U D E S]====================================================*/
#include "Std_Types.h"

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define RAMTST_CFG_H_SW_MAJOR_VERSION       (4U)
#define RAMTST_CFG_H_SW_MINOR_VERSION       (5U)
#define RAMTST_CFG_H_SW_PATCH_VERSION       (0U)
#define RAMTST_CFG_H_AR_MAJOR_VERSION       (2U)
#define RAMTST_CFG_H_AR_MINOR_VERSION       (0U)
#define RAMTST_CFG_H_AR_PATCH_VERSION       (0U)

#define RAMTST_DEV_ERROR_DETECT             STD_ON

#define RAM_SAFERESERVEAREA_START  (uint32)0x20010000u
#define RAM_SAFERESERVEAREA_END    (uint32)0x20011c00u

#define RAM_LOCAL_VAR_AREA_START  (uint32)0x1fff0000u
#define RAM_LOCAL_VAR_AREA_END    (uint32)0x1fff0400u

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
#define RAMTST_TEST_COMPLETE_NOTIFICATION_API_ENABLE         STD_OFF
#define RAMTST_TEST_ERROR_NOTIFICATION_API_ENABLE            STD_OFF

#define RAMTST_SELF_CHECK_ENABLE                   STD_ON

#define RAMTST_DEM_MAIN_RAM_FAILURE_ENABLE     STD_OFF
#define RAMTST_DEM_PART_RAM_FAILURE_ENABLE     STD_OFF
#define RAMTST_DEM_RUNFL_RAM_FAILURE_ENABLE     STD_OFF

#endif /* #ifndef  RAMTST_CFG_H_ */
/*===========================[E N D   O F   F I L E]==============================================*/

