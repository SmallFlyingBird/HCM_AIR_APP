#ifndef ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_H_
#define ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/

#include "Buck_Interface.h"
#include "HcmPlatform.h"

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

/*�汾�� 0.0.0*/
#define CHANNEL_INTERFACE_VERSION_HIGH_BYTE 0
#define CHANNEL_INTERFACE_VERSION_MIDDLE_BYTE 0
#define CHANNEL_INTERFACE_VERSION_LOW_BYTE 0

#define CHANNEL_SHORT2VCC_VOLTAGE_LIMIT 5.0
#define SHORT2BATTARY_VOLATGE_HYSTERESIS 1

#define INVALIED_CURRENT 0xFFFF

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef union
{
    uint16_t channelinfo;
    struct
    {
        uint16_t IsChannelConfiged : 1;
        uint16_t IsChannelDiagEnable : 1;
        uint16_t rcvd : 5;
    } bits;
} U_ChannelInfo;

typedef struct ChannelControl
{
    E_ChannelState channel_state;//err check
    uint8 channelDiagEn;
    U_ChannelInfo channelinfo;
    uint8 channel_open_errorcnt;
    uint8 channel_short2GND_errorcnt;
    uint8 channel_short2VCC_errorcnt;
    uint8 channel_lowvoltage_errorcnt;
    uint8 channel_overvoltage_errorcnt;
    uint16_t channelon_diag_delaytimer;
    uint16_t channeloff_diag_delaytimer;
    uint16_t channel_DidconfigcurrentRef; /*DID Signal reference*/
    uint16_t channel_current_cur;
    uint8_t channel_current_pwm;
    uint16_t channel_DidConfigcurrent;  /*DID(437C) Config current*/
    uint16_t channel_bincurrent;        /*Bin Current*/
    uint16_t channel_ParaNormalcurrent; /*Para table Normal Current*/
    uint32_t channelontimer;
    uint32_t channelOfftimer;
    double Channel_CurVoltage;
} S_ChannelControl;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*
 *Function: SetChannelMatrixChipDeviceAddress
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			dev_address: Matrix chip dev address
 */
Std_ReturnType Interface_SetChannelMatrixChipDeviceAddress(E_ChannelID id, uint8_t dev_address);
/*
 *Function: Set channel Bin Current. The Rcod layer will call this function to set channel BinCurrent
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			pwm: 0-65535(mA)
 */
Std_ReturnType Interface_SetChannelBinCurrent(E_ChannelID id, uint16_t current);
/*
 *Function: Set channel switch on or off
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			pwm: 0-65535(mA)
 */
Std_ReturnType Interface_SetChannelCurrent(E_ChannelID id, uint16_t current);
/*
 *Function: Set channel switch on or off
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			pwm: 0-100 -> 0%-100%
 */
Std_ReturnType Interface_SetChannelPWM(E_ChannelID id, uint8_t pwm);
/*
 *Function: Set channel switch on or off
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			channelstate: CHANNEL_STATE_OFF(close channel) or CHANNEL_STATE_ON(open channel)
 */
Std_ReturnType Interface_SetChannelSwitchState(E_ChannelID id, E_ChannelState channelstate);

/*
 *Function: Set channel delay timer when channel is off
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			timer: 0-65535(ms)
 */
Std_ReturnType Interface_SetChannelOffDiagDelaytimer(E_ChannelID id, uint16_t timer);
/*
 *Function: Enable or Disable channel diagnose
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			DiagEn: 0(disable) or 1(enable)
 */
Std_ReturnType Interface_SetChannelDiagSwitch(E_ChannelID id, uint8_t DiagEn);

/*
 *Function: Get channel switch Frequency
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			Freq: 0-65535(Hz)
 */
Std_ReturnType Interface_GetChannelFrequency(E_ChannelID id, uint16_t *Freq);

/*
 *Function: Get channel output coltage
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			voltage: (V)
 */
Std_ReturnType Interface_GetChannelVoltage(E_ChannelID id, double *voltage);

/*
 *Function: Get channel switch state
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			id:ChannelID1-ChannelID4
 *			channelstate: CHANNEL_STATE_OFF or CHANNEL_STATE_ON
 */
Std_ReturnType Interface_GetChannelSwitchState(E_ChannelID id, E_ChannelState *channelstate);

/*
 *Function: Get channel DidConfigCurrent whitch is set by DID(437C)
 *Std_ReturnType:  0xFFFFF means DIDConfigCurrent not configed. (mA)
 *Parameter:
 *			id:ChannelID1-ChannelID4
 */
uint16_t Interface_GetChannelDidConfigCurrent(E_ChannelID id);

/*
 *Function: Get channel BinCurrent whitch is set by NtcRcod_Interface module
 *Std_ReturnType:  0xFFFFF means BinCurrent is not configed or not cacultaed completed
 *Parameter:
 *			id:ChannelID1-ChannelID4
 */
uint16_t Interface_GetChannelBinCurrent(E_ChannelID id);

/*
 *Function: Get channel ParamTableNormalCurrent from ParamTable
 *Std_ReturnType:  mA
 * Led forward nominal current of the channel  to be used if diagnostic current is out of range defined by parameters pLedMinCurrent#0 and pLedMaxCurrent#0
 *Parameter:
 *			id:ChannelID1-ChannelID4
 */
uint16_t Interface_GetChannelParamTableNormalCurrent(E_ChannelID id);
/*获得通道当前电流*/
uint16_t Interface_GetChannelCurCurrent(E_ChannelID id);
/*
 *获得通道的当前占空比
 *返回值0-100 表示0%-100%
 */
uint8_t Interface_GetChannelCurPWM(E_ChannelID id);
uint16_t Interface_GetChannelMask(void);

Std_ReturnType Channel_Interface_TimerMainFunction(uint8_t timebase);
/*
 *Function: Mainly deal with channel diagnose.Put this function in 10ms task
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			timebase:task cycle time
 */
Std_ReturnType Channel_Interface_MainFunction(uint8_t timebase);

Std_ReturnType BuckDrvDev_Register(S_BuckDrv_Dev *Drv_Dev);
Std_ReturnType Interface_ChannelInit(void);
void Interface_ChannelClose(E_ChannelID id);
void Interface_ChannelOpen(E_ChannelID id,uint16 cur,uint8 pwm);
void Reset_ChannelAllError(E_ChannelID id);
void ChannelDiagEnable(E_ChannelID id,uint8 data);
#endif /* ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_H_ */
