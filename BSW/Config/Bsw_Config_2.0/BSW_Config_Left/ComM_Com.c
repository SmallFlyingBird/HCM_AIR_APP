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
 *  @file               : ComM_Com.c
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/03/26 15:24:41 
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 *
 */
/*=================================================[inclusions]=======================================================*/
#include "Std_Types.h"
#include "ComM_Types.h"
#include "ComM_Cfg.h"
#include "ComM_Com.h"
/*========================================[external function declarations]============================================*/
FUNC(void, COMM_CODE) ComM_ComEiraRxIndication(uint8 sigIdx);

/*==========================================[external function definitions]===========================================*/
void ComM_COMCbk_isCanNmEira(void) {  /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    ComM_ComEiraRxIndication(0u);
}

