/*
 * DID_Interface.h
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_DID_DTC_INTERFACE_DID_INTERFACE_H_
#define ASW_INTERFACE_DID_DTC_INTERFACE_DID_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/

#include "HcmPlatform.h"
#include "DIDConfig.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
/*�汾�� 0.0.0*/
#define DID_INTERFACE_VERSION_HIGH_BYTE 	1
#define DID_INTERFACE_VERSION_MIDDLE_BYTE 	0
#define DID_INTERFACE_VERSION_LOW_BYTE 		1

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum{
	E_DataType_0x22_0x2E=0,
	E_DataType_0x2F,
}E_DataType;



/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_DID434B_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4358_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4359_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID435B_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID435C_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID435D_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID435E_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID435F_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4360_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4361_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4362_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4363_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4364_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4367_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4365_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID4366_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID43A9_IoCtrCallback(E_IOCtrType IOCtrTypeState);
Std_ReturnType Interface_DID7022_IoCtrCallback(E_IOCtrType IOCtrTypeState);

Std_ReturnType Interface_GetDidIoctrMask(uint8_t DidNameId,uint8_t *Mask);
Std_ReturnType Interface_GetDidIoctrState(uint8_t DidNameId,E_IOCtrType *IoctrState);
Std_ReturnType Interface_GetDidSignalIoctrData(uint16_t DidSignalID,uint32_t *val);
Std_ReturnType Interface_GetDidSignalData(uint16_t DidSignalID,uint32_t *val);
Std_ReturnType Interface_SetDidSignalData(uint16_t DidSignalID,uint32_t val);

Std_ReturnType DID_Interface_Mainfunction(uint8_t timebase);
Std_ReturnType Interface_DIDInit(void);

#endif /* ASW_INTERFACE_DID_DTC_INTERFACE_DID_INTERFACE_H_ */
