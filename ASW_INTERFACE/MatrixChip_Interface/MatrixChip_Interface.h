/*
 * MatrixChip_Interface.h
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_MATRIXCHIP_INTERFACE_MATRIXCHIP_INTERFACE_H_
#define ASW_INTERFACE_MATRIXCHIP_INTERFACE_MATRIXCHIP_INTERFACE_H_
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
/**************************************************
 *                                                *
 *                Macro Define                    *
 *                                                *
 **************************************************/
/*�汾�� 0.0.0*/
#define MATRIXCHIP_INTERFACE_VERSION_HIGH_BYTE 0
#define MATRIXCHIP_INTERFACE_VERSION_MIDDLE_BYTE 0
#define MATRIXCHIP_INTERFACE_VERSION_LOW_BYTE 0

#if USE_TPS92662
	#define MAX_MATRIXCHIP_CHANNEL_NUM 12
#else if USE_TLD7002
	#define MAX_MATRIXCHIP_CHANNEL_NUM 16
#endif

#define MAX_MATRIXCHIP_NUM MAX_CHANNLE_NUM

#define TPS92662A_MAX_CHANNEL_NUM MAX_MATRIXCHIP_CHANNEL_NUM

#define LOWHIGH_MAX_MATRIXCHIP_NUM 7
#define TI_MAX_MATRIXCHIP_NUM 4
#define DRLPOS_MAX_MATRIXCHIP_NUM 4
#define GRILLE_MAX_MATRIXCHIP_NUM 4
#define LOGO_MAX_MATRIXCHIP_NUM 2
#define ASSISTANT_MAX_MATRIXCHIP_NUM 2
#define FRONTCROSS_MAX_MATRIXCHIP_NUM 3

#define LMM_AVL_INDEX 0
#define LMM_ADDRESS_INDEX 1
#define LMM_CH_INDEX 2
#define LMM_SLEWRATE_INDEX 3
#define LMM_OVLIMIT_INDEX 4
#define LMM_TYPE_INDEX 7
#define LMM_PIXNUMBERID_INDEX 8
#define LMM_PWM_INDEX 20

#define UNUSED_PWM_VALUE 0xFF

/*
*矩阵芯片通行丢失自动回复使能
*1：某颗矩阵芯片通信丢失后，继续读取
*0：某颗矩阵芯片通信丢失后，剔除该矩阵芯片的通信队列
*/
#define LMM_LOSCOM_AUTORESUM_ENABLE 1

#if LMM_LOSCOM_AUTORESUM_ENABLE
#else
#define MatrixIndex xItemValue
#endif

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum
{
    E_None = 0,
    E_TPS92662 = 146,
    E_TPS92663 = 147,
    E_TPS92662A = 148,
    E_TPS92663A = 149,
    E_MAX25608 = 150,
    E_TLD7002 = 151,
} E_MatrixChipType;
/***************************************************************************Start 92662A typedef***************************************************************************/
typedef struct Tps92662A_InitDataSrc
{
    uint8_t AdcID;
    uint8_t PwmTick;
    uint8_t CMWEN;
    uint8_t CMWTAP;
    uint8_t SlewRate;
    uint8_t OvLimit;
    uint8_t DefaultPwm[TPS92662A_MAX_CHANNEL_NUM];
    uint16_t PhaseShift[TPS92662A_MAX_CHANNEL_NUM];
} S_Tps92662A_InitDataSrc;

typedef struct Tps92662A_MainFunctionDataSrc
{
    uint8_t ComError;
} S_Tps92662A_MainFunctionDataSrc;
/***************************************************************************End 92662A typedef***************************************************************************/
typedef enum
{
    E_MatrixTripDataType_DevInit = 0,
    E_MatrixTripDataType_DevDeInit,
    E_MatrixTripDataType_PwmValue,
    E_MatrixTripDataType_AdcValue,
    E_MatrixTripDataType_MainFunction,
    E_MatrixTripDataType_MatrixComReset,
} E_MatrixTripDataType;

typedef struct ChannelPWMDataSrc
{
    uint8_t PwmValue[MAX_MATRIXCHIP_CHANNEL_NUM]; /*PwmValue :0-100(%)*/
} S_ChannelPWMDataSrc;

typedef struct AdcValueDataSrc
{
    uint8_t AdcNO;
    uint8_t AdcValue;
    uint8_t LostComErr;
} S_AdcValueDataSrc;

typedef struct MainFunctionDataSrc
{
    uint8_t ComTimeout : 1;
    uint8_t ComError : 1;
    uint8_t LostCfg : 1;
    uint8_t Led1Error : 1;
    uint8_t Led2Error : 1;
    uint8_t Led3Error : 1;
    uint8_t Led4Error : 1;
    uint8_t Led5Error : 1;
    uint8_t Led6Error : 1;
    uint8_t Led7Error : 1;
    uint8_t Led8Error : 1;
    uint8_t Led9Error : 1;
    uint8_t Led10Error : 1;
    uint8_t Led11Error : 1;
    uint8_t Led12Error : 1;
} S_MainFunctionDataSrc;

typedef struct MatrixTripDataPackets
{
    E_MatrixTripDataType DataType;
    uint8_t dev_address;
    void *datasrc;
} S_MatrixTripDataPackets;

typedef struct MatrixDrvInfo
{
    uint8_t dev_address;
    uint8_t LostComFlag;
    uint8_t LostComErrCnt;
    E_ChannelID ChannlMap;
    uint8_t CurPwm[MAX_MATRIXCHIP_CHANNEL_NUM]; /*CurPwm :0-100(%)*/
} S_MatrixDrvInfo;

typedef struct MatrixChipDrv_Dev
{
    E_MatrixChipType MatrixChipType;
    uint8_t dev_address;
    Std_ReturnType (*DeviceInit)(void *ptr);
    Std_ReturnType (*DeviceDeInit)(void *ptr);
    Std_ReturnType (*Read)(void *ptr);
    Std_ReturnType (*Write)(void *ptr);
    Std_ReturnType (*MainFunction)(void *ptr);
    struct MatrixChipDrv_Dev *ptNext;
} S_MatrixChipDrv_Dev;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/*判断矩阵芯片使用的通道是都都是0%占空比*/
uint8_t Interface_IsMatrixChipIsEmtpyPwm(uint8_t dev_address);
/*
 *Function: For channel whith Matrix chip to judge if PWM is full.
 *return :  0(not full pwm) or 1(full pwm)
 *Parameter:
 *				   dev_address : dev_address(0-255)
 */
uint8_t Interface_IsMatrixChipIsFullPwm(uint8_t dev_address);
Std_ReturnType Interface_SetMatrixChipChannelMap(E_ChannelID channelid, uint8_t dev_address);
/*
 *Function: Get MatrixChip Adc Value.
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *				   dev_address : dev_address(0-255)
 *				   pwmdata: the piont to pwm array
 *example:
 *         uint8  PWM_DATA[MAX_MATRIXCHIP_CHANNEL_NUM]={0};     //PWM_DATA    0-100 -> 0%->100%
 * 		   Interface_SetMatrixChipChannelPwm(0,PWM_DATA);
 *
 */
Std_ReturnType Interface_SetMatrixChipChannelPwm(uint8_t dev_address, uint8 *pwmdata);

Std_ReturnType Interface_GetMatrixChipChannelPwm(uint8_t dev_address, uint8 *pwmdata);

/*
 *Function: Set MatrixChip channel PWM.
 *			If PWM is not changed,this funntion will not call S_MatrixChipDrv_Dev->SetMatrixChip
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *				   dev_address : dev_address(0-255)
 *				   AdcValueDataSrc:  poit
 * example:
 *	S_AdcValueDataSrc gs_AdcValueDataSrc;
 *	gs_AdcValueDataSrc.AdcNO =1; //0 : None, 1: ADC1, 2: ADC2
 *	if(Interface_GetMatrixChipAdcValue(0,&gs_AdcValueDataSrc)==E_OK)
 *
 */
Std_ReturnType Interface_GetMatrixChipAdcValue(uint8_t dev_address, S_AdcValueDataSrc *AdcValueDataSrc);

/*
 *Function: Get MatrixChip channel PWM.
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *				   dev_address : dev_address(0-255)
 *				   pwmdata:  poit      (unit 0->100   : 0%->100%)
 *
 */
Std_ReturnType Interface_GetMatrixChipPwmWidth(uint8_t dev_address, uint8 *pwmdata);

uint8_t Interface_GetMatrixChipRegisterNumer(void);
uint8_t Interface_GetMatrixChipAddress(uint8_t registerid);

Std_ReturnType Interface_ResetMatrixChipComList(void);
/*
 *Function: Mainly keep communication with matrix chip.
 *Std_ReturnType:  E_OK or E_NOT_OK
 *Parameter:
 *			timebase:task cycle time
 */
Std_ReturnType MatrixChip_Interface_Mainfunction(uint8_t timebase);

/*
 *Function: Register  MatrixChipDrvDev. The device layer should consider the parameter table to register device.
 *Std_ReturnType:  E_OK(Register successful) or E_NOT_OK(Register failed)
 *Parameter:
 *				   Drv_Dev : point to S_MatrixChipDrv_Dev
 */
Std_ReturnType MatrixChipDrvDev_Register(S_MatrixChipDrv_Dev *Drv_Dev);
uint8_t Interface_GetMatrixChioLostComErrorFlag(uint8_t dev_address);
Std_ReturnType MatrixChipInterfaceModuleInit(void);
#endif /* ASW_INTERFACE_MATRIXCHIP_INTERFACE_MATRIXCHIP_INTERFACE_H_ */
