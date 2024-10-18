/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Std_Types.h                                                   **
**                                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    :                                                               **
**                                                                            **
**  VENDOR    :                                                               **
**                                                                            **
**  DESCRIPTION: Provision of Standard Types                                  **
**                                                                            **
**                                                                            **
**   SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                            **
**                                                                            **
*******************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Compiler.h"
#include "Platform_Types.h"

typedef uint8 Std_ReturnType;

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u
#define E_BUSY   0x02u
#define GEELY20_SPECIFICATION_USED
#define GEELY_SPECIFICATION_USED
typedef struct
{
    uint16 vendorID;
    uint16 moduleID;

    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;

#define STD_HIGH   0x01u /* Physical state 5V or 3.3V */

#define STD_LOW    0x00u /* Physical state 0V */

#define STD_ACTIVE 0x01u /* Logical state active */

#define STD_IDLE   0x00u /* Logical state idle */

#define STD_ON     0x01u

#define STD_OFF    0x00u

#endif /* STD_TYPES_H */
