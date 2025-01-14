/***
Date: 2024/01/08
Auther: yinjianye
***/
#ifndef BD18397_INTERFACE_H
#define BD18397_INTERFACE_H
/*==================================================================================================
*                                       CONFIGURATION
==================================================================================================*/

/**
 * SNSN_R related 18397 specific hardware design, all BUCKs which belong to HCM_CDE is 100mΩ. 
 * this parameter is effect SetCurrent function.
*/

#define BD18397_SNSN_R 100
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "BD18397.h"
#include "Buck_Interface.h"
#include "HcmPlatform.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BD18397_INTERFACE_H_DRIVER_MAJOR_VERSION 0
#define BD18397_INTERFACE_H_DRIVER_MINOR_VERSION 0
#if (BD18397_INTERFACE_H_DRIVER_MAJOR_VERSION != BD18397_H_DRIVER_MAJOR_VERSION)
    #error "BD18397_interface.h and BD18397.h have different version id, please check files compatibility"
#endif
#if ((BUCK_INTERFACE_VERSION_HIGH_BYTE!=BD18397_INTERFACE_H_DRIVER_MAJOR_VERSION)|(BUCK_INTERFACE_VERSION_MIDDLE_BYTE!=BD18397_INTERFACE_H_DRIVER_MINOR_VERSION))
    #error "BD18397_Interface and buck_Interface have different version id, please check files compatibility"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

#define BD18398_MAX_DEV_NUM_GEN2 2

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct{
    uint8 device_id;
    uint8 hw_ch;
}BD18397_ChannelMappingType;
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

Std_ReturnType BD18397ReadFun(void *inputPtr);
Std_ReturnType BD18397WriteFun(void *inputPtr);
Std_ReturnType BD18397InitFun(void *inputPtr);
Std_ReturnType BD18397DeInitFun(void *inputPtr);
Std_ReturnType BD18397task(void *inputPtr);
Std_ReturnType CddDriver_18397Init(void);
#endif
