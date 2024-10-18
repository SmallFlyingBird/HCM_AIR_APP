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
**  FILENAME    : RamTst_MemMap                                               **
**                                                                            **
**  Created on  : 2021-09-28                                                  **
**  Author      : xin.liu                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>   	 <AUTHOR>   	 <REVISION LOG>
 *  V1.0.0       2021-09-28  xin.liu        initial version.
 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#if defined RAMTST_START_SEC_CODE
	#undef RAMTST_START_SEC_CODE
	#define ISOFT_RAMTST_START_SEC_CODE
#elif defined RAMTST_STOP_SEC_CODE
	#undef RAMTST_STOP_SEC_CODE
	#define ISOFT_RAMTST_STOP_SEC_CODE

#elif defined RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
	#undef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
	#define ISOFT_RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
#elif defined RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define ISOFT_RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define ISOFT_RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define ISOFT_RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined RAMTST_START_SEC_VAR_CLEARED_32
	#undef RAMTST_START_SEC_VAR_CLEARED_32
	#define ISOFT_RAMTST_START_SEC_VAR_CLEARED_32
#elif defined RAMTST_STOP_SEC_VAR_CLEARED_32
	#undef RAMTST_STOP_SEC_VAR_CLEARED_32
	#define ISOFT_RAMTST_STOP_SEC_VAR_CLEARED_32

#elif defined RAMTST_START_SEC_VAR_CLEARED_16
	#undef RAMTST_START_SEC_VAR_CLEARED_16
	#define ISOFT_RAMTST_START_SEC_VAR_CLEARED_16
#elif defined RAMTST_STOP_SEC_VAR_CLEARED_16
	#undef RAMTST_STOP_SEC_VAR_CLEARED_16
	#define ISOFT_RAMTST_STOP_SEC_VAR_CLEARED_16

#elif defined RAMTST_START_SEC_VAR_CLEARED_8
	#undef RAMTST_START_SEC_VAR_CLEARED_8
	#define ISOFT_RAMTST_START_SEC_VAR_CLEARED_8
#elif defined RAMTST_STOP_SEC_VAR_CLEARED_8
	#undef RAMTST_STOP_SEC_VAR_CLEARED_8
	#define ISOFT_RAMTST_STOP_SEC_VAR_CLEARED_8

#elif defined RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ISOFT_RAMTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define ISOFT_RAMTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined RAMTST_START_SEC_CONST_PTR
    #undef RAMTST_START_SEC_CONST_PTR
    #define ISOFT_RAMTST_START_SEC_CONST_PTR
#elif defined RAMTST_STOP_SEC_CONST_PTR
    #undef RAMTST_STOP_SEC_CONST_PTR
    #define ISOFT_RAMTST_STOP_SEC_CONST_PTR

#elif defined RAMTST_START_SEC_CONST_8
    #undef RAMTST_START_SEC_CONST_8
    #define ISOFT_RAMTST_START_SEC_CONST_8
#elif defined RAMTST_STOP_SEC_CONST_8
    #undef RAMTST_STOP_SEC_CONST_8
    #define ISOFT_RAMTST_STOP_SEC_CONST_8

#elif defined RAMTST_START_SEC_CONST_16
    #undef RAMTST_START_SEC_CONST_16
    #define ISOFT_RAMTST_START_SEC_CONST_16
#elif defined RAMTST_STOP_SEC_CONST_16
    #undef RAMTST_STOP_SEC_CONST_16
    #define ISOFT_RAMTST_STOP_SEC_CONST_16

#elif defined RAMTST_START_SEC_CONST_32
    #undef RAMTST_START_SEC_CONST_32
    #define ISOFT_RAMTST_START_SEC_CONST_32
#elif defined RAMTST_STOP_SEC_CONST_32
    #undef RAMTST_STOP_SEC_CONST_32
    #define ISOFT_RAMTST_STOP_SEC_CONST_32

#elif defined RAMTST_START_SEC_CONST_UNSPECIFIED
    #undef RAMTST_START_SEC_CONST_UNSPECIFIED
    #define ISOFT_RAMTST_START_SEC_CONST_UNSPECIFIED
#elif defined RAMTST_STOP_SEC_CONST_UNSPECIFIED
    #undef RAMTST_STOP_SEC_CONST_UNSPECIFIED
    #define ISOFT_RAMTST_STOP_SEC_CONST_UNSPECIFIED
#else
#error "RAMTST not include this section"
#endif
#include "MemMap.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/








