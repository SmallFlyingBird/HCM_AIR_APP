
#ifndef ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_
#define ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"

typedef enum
{
    E_CAHNNEL_OPEN = 0,
    E_CAHNNEL_SHORT2GND = 1,
    E_CAHNNEL_SHORT2VCC = 2,
    E_CAHNNEL_UNVOL = 3,
} E_ChannelErrorType;


typedef enum
{
    E_BinType_Bin1 = 0,
    E_BinType_Bin2 = 1,
    E_BinType_Bin3 = 2,
    E_BinType_MatrixBin1 = 3,
    E_BinType_MatrixBin2 = 4,
} E_BinType;

typedef enum
{
    E_NtcSsignalNo_NTC1 = 0,
    E_NtcSsignalNo_NTC2 = 1,
    E_NtcSsignalNo_NTC3 = 2,
    E_NtcSsignalNo_NTC4 = 3,
    E_NtcSsignalNo_NTC5 = 4,
} E_NtcSignalNo;

void Interface_SetDtcChannelError(E_ChannelID index, E_ChannelErrorType errortype, uint8 val);



#endif

