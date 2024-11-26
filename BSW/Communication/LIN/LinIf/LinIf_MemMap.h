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
**  FILENAME    : LinIf_MemMap.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of LINIF             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2/R19_11                **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>       <AUTHOR>   <REVISION LOG>
 *  V2.0.0       2020-08-12   HuRongbo   R19_11 LinIf initial version.
 */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


/*******************************************************************************
**                      MemMap Symbols Define                                 **
*******************************************************************************/
#ifndef LINIF_MEMMAP_NOTUSED
#if defined(LINIF_START_SEC_CODE)
    #undef LINIF_START_SEC_CODE
    #define START_SEC_CODE
#elif defined(LINIF_STOP_SEC_CODE)
    #undef LINIF_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined(LINIF_START_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE)
    #undef LINIF_START_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINIF_STOP_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE)
    #undef LINIF_STOP_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINIF_START_SEC_LINIFHEADERINDICATION_CALLBACK_CODE)
    #undef LINIF_START_SEC_LINIFHEADERINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINIF_STOP_SEC_LINIFHEADERINDICATION_CALLBACK_CODE)
    #undef LINIF_STOP_SEC_LINIFHEADERINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINIF_START_SEC_LINIFRXINDICATION_CALLBACK_CODE)
    #undef LINIF_START_SEC_LINIFRXINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINIF_STOP_SEC_LINIFRXINDICATION_CALLBACK_CODE)
    #undef LINIF_STOP_SEC_LINIFRXINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINIF_START_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE)
    #undef LINIF_START_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINIF_STOP_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE)
    #undef LINIF_STOP_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE

#elif defined(LINIF_START_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE)
    #undef LINIF_START_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE
    #define START_SEC_CALLBACK_CODE
#elif defined(LINIF_STOP_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE)
    #undef LINIF_STOP_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE
    #define STOP_SEC_CALLBACK_CODE


#elif defined(LINIF_START_SEC_VAR_INIT_UNSPECIFIED)
    #undef LINIF_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined(LINIF_STOP_SEC_VAR_INIT_UNSPECIFIED)
    #undef LINIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined(LINIF_START_SEC_VAR_INIT_PTR)
    #undef LINIF_START_SEC_VAR_INIT_PTR
    #define START_SEC_VAR_INIT_PTR
#elif defined(LINIF_STOP_SEC_VAR_INIT_PTR)
    #undef LINIF_STOP_SEC_VAR_INIT_PTR
    #define STOP_SEC_VAR_INIT_PTR
    
#elif defined(LINIF_START_SEC_CONFIG_DATA_UNSPECIFIED)
    #undef LINIF_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined(LINIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
    #undef LINIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined(LINIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
    #undef LINIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined(LINIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
    #undef LINIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED


#elif defined(LINTP_START_SEC_CODE)
    #undef LINTP_START_SEC_CODE
    #define START_SEC_CODE
#elif defined(LINTP_STOP_SEC_CODE)
    #undef LINTP_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined(LINTP_START_SEC_VAR_INIT_UNSPECIFIED)
    #undef LINTP_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined(LINTP_STOP_SEC_VAR_INIT_UNSPECIFIED)
    #undef LINTP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined(LINTP_START_SEC_VAR_INIT_PTR)
    #undef LINTP_START_SEC_VAR_INIT_PTR
    #define START_SEC_VAR_INIT_PTR
#elif defined(LINTP_STOP_SEC_VAR_INIT_PTR)
    #undef LINTP_STOP_SEC_VAR_INIT_PTR
    #define STOP_SEC_VAR_INIT_PTR

#elif defined(LINTP_START_SEC_CONFIG_DATA_UNSPECIFIED)
    #undef LINTP_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined(LINTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
    #undef LINTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined(LINTP_START_SEC_VAR_CLEARED_UNSPECIFIED)
    #undef LINTP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined(LINTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
    #undef LINTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined(LINIF_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    #undef LINIF_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined(LINIF_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    #undef LINIF_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

#elif defined(LINIF_START_SEC_CONST_UNSPECIFIED)
    #undef LINIF_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined(LINIF_STOP_SEC_CONST_UNSPECIFIED)
    #undef LINIF_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED

#else
    #error "Undefined section in LINIF"
#endif
#endif /* #ifndef LINIF_MEMMAP_NOTUSED */

#include "MemMap.h"
