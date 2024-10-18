
/**
 *
 * Copyright (C) iSOFT   (2022)
 *
 * All rights reserved.
 *
 * This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and
 * communication of its contents is not permitted without prior written authorization.
 *
 *
 *  @file               : ComM_Gent.c
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/03/26 15:24:41
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 */

/*=================================================[inclusions]=======================================================*/
#include "Std_Types.h"
#include "ComM_Types.h"
#include "ComM_Gent.h"
/*============================================[external date declarations]============================================*/

BEGIN_C_DECLS
/*==========================================[external function definitions]===========================================*/
FUNC(void, COMM_CODE) ComM_PncMainFunction(void);

FUNC(void, COMM_CODE) ComM_PncProcessTimer(void);

FUNC(void, COMM_CODE) ComM_ChProcessTimer(uint8 chIdx);

END_C_DECLS
/*==========================================[external function definitions]===========================================*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"
FUNC(void, COMM_CODE) ComM_MainFunction_BodyExposedCAN_HCML(void){  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_PncMainFunction();
    ComM_PncProcessTimer();
    ComM_ChProcessTimer(0);
}
#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

