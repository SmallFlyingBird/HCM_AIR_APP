/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinSM_MemMap.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory map definition for LinSM                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      MemMap Symbols Define                                 **
*******************************************************************************/
#ifndef LINSM_MEMMAP_NOTUSED

#if defined(LINSM_START_SEC_CODE)
    #undef LINSM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined(LINSM_STOP_SEC_CODE)
    #undef LINSM_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined(LINSM_START_SEC_LINSMSCHEDULEREQUESTCONFIRMATION_CALLBACK_CODE)
    #undef LINSM_START_SEC_LINSMSCHEDULEREQUESTCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINSM_STOP_SEC_LINSMSCHEDULEREQUESTCONFIRMATION_CALLBACK_CODE)
    #undef LINSM_STOP_SEC_LINSMSCHEDULEREQUESTCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINSM_START_SEC_LINSMGOTOSLEEPINDICATION_CALLBACK_CODE)
    #undef LINSM_START_SEC_LINSMGOTOSLEEPINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINSM_STOP_SEC_LINSMGOTOSLEEPINDICATION_CALLBACK_CODE)
    #undef LINSM_STOP_SEC_LINSMGOTOSLEEPINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINSM_START_SEC_LINSMGOTOSLEEPCONFIRMATION_CALLBACK_CODE)
    #undef LINSM_START_SEC_LINSMGOTOSLEEPCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINSM_STOP_SEC_LINSMGOTOSLEEPCONFIRMATION_CALLBACK_CODE)
    #undef LINSM_STOP_SEC_LINSMGOTOSLEEPCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINSM_START_SEC_LINSMWAKEUPCONFIRMATION_CALLBACK_CODE)
    #undef LINSM_START_SEC_LINSMWAKEUPCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINSM_STOP_SEC_LINSMWAKEUPCONFIRMATION_CALLBACK_CODE)
    #undef LINSM_STOP_SEC_LINSMWAKEUPCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE


#elif defined(LINSM_START_SEC_VAR_INIT_UNSPECIFIED)
    #undef LINSM_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined(LINSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
    #undef LINSM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined(LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
    #undef LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined(LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
    #undef LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED
    
#elif defined(LINSM_START_SEC_VAR_INIT_PTR)
    #undef LINSM_START_SEC_VAR_INIT_PTR
    #define START_SEC_VAR_INIT_PTR
#elif defined(LINSM_STOP_SEC_VAR_INIT_PTR)
    #undef LINSM_STOP_SEC_VAR_INIT_PTR
    #define STOP_SEC_VAR_INIT_PTR

#elif defined(LINSM_START_SEC_CONFIG_DATA_UNSPECIFIED)
    #undef LINSM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined(LINSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
    #undef LINSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#else
    #error "Undefined section in LINSM"
#endif
#endif /* #ifndef LINSM_MEMMAP_NOTUSED */

#include "MemMap.h"
