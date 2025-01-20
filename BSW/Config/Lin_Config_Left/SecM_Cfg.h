
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : SecM_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2023/09/15 16:21:42                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Config File for Security Module.                            **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818     long.zhu         Initial Version
 */

#ifndef SECM_CFG_H
#define SECM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "std_types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/** value k for security access */
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define SecM_NEW_27_ECY              STD_OFF

#if(SecM_NEW_27_ECY == STD_OFF)
#define SECM_ECU_BOOT_FAC               0x00C541A9U
#define SECM_SECCONST_DID    		    0xF102U
#define SECM_SECCONST_LENGTH    		0x05U
#else
#define SECM_SECCONST_DID    		    0xF109U
#define SECM_SECCONST_LENGTH    		16U

#endif

/* CAL check length once for SecM_ProcessCal. */
#define SECM_CAL_BUFFER_LEN             0x1000u

/* Hardware Algorithm implementation Enabled */
#define SECM_HSM_ENABLED                STD_OFF

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern const uint8 SecM_DefaultFixedSeedBytes[SECM_SECCONST_LENGTH];

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif/* endif of SECM_CFG_H */

