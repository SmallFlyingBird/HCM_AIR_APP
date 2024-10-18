/***
@date: 2024/02/18
@auther: yinjianye
***/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Max25608.h"
#include "HcmPlatform.h"
#include "Uart.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/ 

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * Std_ReturnType MAX25608_ReadFun();
 * @brief this function used to read data into register;
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param device_id specific IC or Cluster device_id.
 * @param Reg read or write register. 
 * @param data a pointer which point to where you wanna store, type: uint16.
 * @todo CRC CHECK
 * */
static Std_ReturnType MAX25608_ReadFun(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 Reg,
    uint16 *data
    );
/**
 * Std_ReturnType MAX25608_WriteFun();
 * @brief this function used to write data into register;
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCS 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_id specific IC or Cluster device_id.
 * @param Reg read or write register. 
 * @param data write data, type: uint16.
*/
static Std_ReturnType MAX25608_WriteFun(
    Max25608_TransType *device,
    uint8 isBCOrCs, 
    uint8 device_id, 
    uint8 Reg, 
    uint16 data);

/**
 * static uint8 Reflect8()
 * @brief this function is used for WriteFun and ReadFun, to create CRC3
 * @param val inputdata
*/
static uint8 Reflect8(uint8 val );
/**
 * static uint8 Calculate3BitCRC()
 * @brief this function is used for WriteFun and ReadFun, to create CRC3
 * @param data inputdata
*/
static uint8 Calculate3BitCRC( uint32 data );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

static Std_ReturnType MAX25608_ReadFun(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 Reg,
    uint16 *data
    ){
    Std_ReturnType res=E_OK;
    uint32 cmdRead;
    uint32 T_timeout;
    uint8 i=0;
    __attribute__(( aligned(32) )) static uint8 receiveData[7]={0x10,};
    __attribute__(( aligned(32) )) static uint8 readCmd[4]={0x79,};
    for(i=0;i<4;i++){
        readCmd[i]=0;
        receiveData[i]=0;
    }
    for(i=4;i<7;i++){
        receiveData[i]=0;
    }
    readCmd[0] = 0x79;
    readCmd[1] = ((device_id &0x3f) << 1)|0x01;
    readCmd[2] = Reg;
    readCmd[3] = 0;
    /*caculate CRC. CRC covers 8bit payload of device_id frame, ADDR frame and [4:0]CRC frame*/
    cmdRead =( Reflect8( readCmd[1] ) << 16) | ( Reflect8( readCmd[2] ) << 8);
    readCmd[3] = (Calculate3BitCRC( cmdRead )<<5);
    if(1 == device->is25608b){
        res |=Uart_AsyncReceive(device->uartNum,receiveData,7);
    }
    res |= Uart_AsyncSend(device->uartNum,readCmd,4);
    T_timeout=0x1FFF;
	do{
		/*Uart_ReceiveStatus = Uart_GetStatus(0,&T_bytesRemaining,UART_RECEIVE);*/
		T_timeout--;
	}while(0!=T_timeout);
    /*if receiveData[4] is not ACK, there is a ERR*/
    if(0xc3 != receiveData[4]){
        res=E_NOT_OK;
    }
    /**
     * @todo CRC CHECK
    */
   if(1 == device->is25608b){
        *data=((uint16)(receiveData[5]) | ((uint16)((receiveData[6]&0x1f)<<8)));
   }else{
        *data=((uint16)(receiveData[0]) | ((uint16)((receiveData[1]&0x1f)<<8)));
   }
    
    return res;
}

static Std_ReturnType MAX25608_WriteFun(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 Reg,
    uint16 data
    ){
        Std_ReturnType res=E_OK;
        uint32 cmdwrite;
        __attribute__(( aligned(32) )) static uint8 receiveData[6]={0x0,};
        uint8 crc3;
        uint32 T_timeout;
        uint8 i=0;
        /*define writeCmd, using aligned32 to compatible DMA*/
        __attribute__(( aligned(32) )) static uint8 writeCmd[5]={0x79,0x00,0x00,0x00,0x00};
        for(i=0;i<5;i++){
            writeCmd[i]=0;
            receiveData[i]=0;
         }
        for(i=5;i<6;i++){
            receiveData[i]=0;
        }
        /*prepare writeCmd SYNC and address frame*/
        writeCmd[0] = 0x79;
        writeCmd[1] = (((device_id&0x3f)<<1) | ((isBCOrCs&0x01)<<7));
        writeCmd[2] = Reg;
        writeCmd[3] = data & 0x00ff;
        writeCmd[4] = ((data>>8) & 0x001f);
        /*now caculate CRC*/
        cmdwrite= (Reflect8(writeCmd[1])<<24) | (Reflect8(writeCmd[2])<<16) | (Reflect8(writeCmd[3]) << 8) | Reflect8(writeCmd[4]);
        crc3=Calculate3BitCRC(cmdwrite);
        writeCmd[4] |= ( crc3 << 5 );
        /*if there is 25608b device, it should receive ACK Frame */
        if(1 == device->is25608b){
            res |=Uart_AsyncReceive(device->uartNum,receiveData,6);
        }
        res |= Uart_AsyncSend(device->uartNum,writeCmd,5);
            T_timeout=0x1FFF;
	do{
		/*Uart_ReceiveStatus = Uart_GetStatus(0,&T_bytesRemaining,UART_RECEIVE);*/
		T_timeout--;
	}while(0!=T_timeout);
        if(0xc3 != receiveData[5]){
            res=E_NOT_OK;
        }
        return res;
}

static uint8 Reflect8(uint8 val )
{
	uint8 i;
	uint8 resByte = 0;

    for( i = 0; i < 8; i++)
    {
    	if ((val & (1 << i)) != 0)
        {
    		resByte |= (uint8)(1 << (7 - i));
        }
    }
    return resByte;
}

static uint8 Calculate3BitCRC( uint32 data )
{
	uint32 crcVal = 0;
	uint32 polynomial = 0xB0000000;
	uint32 msb = 0x80000000;
	uint32 crcMask = 0xFFFFFFF8;

	crcVal = data & crcMask;

	while ((crcVal & crcMask) != 0)
	{
		if ((crcVal & msb) != 0)
		{
			/*if msb is 1'b1, divide by polynomial and shift polynomial to the right */
			crcVal = crcVal ^ polynomial;
			polynomial = polynomial >> 1;
		}
		else
		{
			/* if msb is zero, shift polynomial */
			polynomial = polynomial >> 1;
		}
		msb = msb >> 1;
	}
	return (uint8)crcVal;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

Std_ReturnType Max25608_GetDeviceInfo(
    Max25608_TransType *device,
    uint8 device_id,
    uint8 *REV_ID,
    uint8 *Const_test
    ){
    Std_ReturnType res=E_OK;
    uint16 receiveData=0;
    res |= MAX25608_ReadFun(device,0,device_id,MAX25608_NO_OP,&receiveData);
    if(E_NOT_OK == res){
        *REV_ID=0xff;
        *Const_test=0xff;
        return res;
    }else{
        if(REV_ID!=NULL_PTR){
            *REV_ID=(uint8)((receiveData>>8)&0x1f);
        }
        if(Const_test!=NULL_PTR){
            *Const_test=(uint8)(receiveData&0x1f);
        }
        return res;
    }

}

Std_ReturnType Max25608_SetSWGO(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 isON
    ){
    Std_ReturnType res=E_OK;
    uint16 data=isON;
    /*set SW_GO_EN bit*/
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_SW_GO,data);
    return res;
}

Std_ReturnType Max25608_SetCNFG1(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 PWM_CLK_SEL,
    uint8 DIV,
    uint8 LED_SLEW,
    uint8 VOTH
    ){
        Std_ReturnType res=E_OK;
        uint16 data;
        /*assembling data */
        data=(((uint16)(PWM_CLK_SEL&0x3))|(((uint16)(DIV&0x3))<<2)|(((uint16)(LED_SLEW&0x7))<<4)|(((uint16)(VOTH&0x3))<<7));
        res |=  MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_GEN_1,data);
        return res;
}

Std_ReturnType Max25608_SetShortTh(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 channel,
    uint8 VSTH
){
    Std_ReturnType res=E_OK;
    uint16 data;
    /*vsth_x: specific channel in current register*/
    uint8 VSTH_X;
    /*reg_offset: specific which channel*/
    uint8 reg_offset;
    if(channel <=3){
        reg_offset=0;
    }else if(channel <=7){
        reg_offset=1;
    }else if(channel <=11){
        reg_offset=2;
    }else{
        return E_NOT_OK;
    }
    VSTH_X=(channel % 4);
    /*first read back register val*/
    res |=MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_CNFG_GEN_2+reg_offset,&data);
    /*clean specific VSTH bit*/
    data = data &(~(0x7<<(3*VSTH)));
    /*load new val*/
    data|= (VSTH<<(3*VSTH_X));
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_GEN_2+reg_offset,data);
    return res;
}

Std_ReturnType Max25608_SetCNFG2to4(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 CNFG_X,
    uint16 data
){
    Std_ReturnType res=E_OK;
    if(CNFG_X <2 || CNFG_X >4){
        return E_NOT_OK;
    }
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_GEN_2+CNFG_X-2,data);
    return res;
}

Std_ReturnType Max25608_SetUartCNFG(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 CID,
    uint8 WDG_timeout_SEL
){
    Std_ReturnType res=E_OK;
    uint16 data;
    /*assmbling data*/
    data=(((uint16)(CID&0x7F))|(((uint16)(WDG_timeout_SEL&0x7))<<7));
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_UART,data);
    return res;
}

Std_ReturnType Max25608_SetWDGFailSafeState(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 WD_LED_STATE
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_WATCHDOG,WD_LED_STATE);
    return res;
}

Std_ReturnType Max25608_SetChannelMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 OPEN_LED_OVRD
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_OPEN_OVRD,OPEN_LED_OVRD);
    return res;
}

Std_ReturnType Max25608_SetGroupMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 isAOrB,
    uint16 Group_Mask
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_GROUPA+isAOrB,Group_Mask);
    return res;
}

Std_ReturnType Max25608_SetDeviceFltPinMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 Flt_Mask
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_MSK_GEN,Flt_Mask);
    return res;
}

Std_ReturnType Max25608_SetLEDFltPinMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 LED_Mask
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_CNFG_MSK_LED,LED_Mask);
    return res;
}

Std_ReturnType Max25608_GetRADC(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 *measurementState,
    uint8 *fltState
){
    Std_ReturnType res=E_OK;
    uint16 data=0;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_STAT_RADC,&data);
    *measurementState=(uint8)(data>>4);
    if(0!=(data&0x0f)){
        *fltState=1;
    }else{
        *fltState=0;
    }
    return res;
}

Std_ReturnType Max25608_GetRGRADE(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 *RGRADE
){
    Std_ReturnType res=E_OK;
    uint16 data=0;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_STAT_RES_CODE,&data);
    *RGRADE=(uint8)(data&0xf);
    return res;
}

Std_ReturnType Max25608_GetDeviceFault(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    Max25608_DeviceFltUnionType *FltUnion
){
    Std_ReturnType res=E_OK;
    uint16 data=0;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_STAT_GEN,&data);
    FltUnion->fltData=data;
    data=0;
    /*clean flt*/
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_STAT_GEN,data);
    return res;
}

Std_ReturnType Max25608_GetUartFault(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    Max25608_UartFltUnionType *FltUnion
){
    Std_ReturnType res=E_OK;
    uint16 data=0;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_STAT_UART,&data);
    FltUnion->fltData=data;
    /*clean flt*/
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_STAT_UART,0x0003);
    return res;
}

Std_ReturnType Max25608_GetLEDShort(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 *FltChannel
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_STAT_SHORT_LED,FltChannel);
    /*write 1 to clean*/
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_STAT_SHORT_LED,0x0fff);
    return res;
}

Std_ReturnType Max25608_GetLEDOpen(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 *FltChannel
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_STAT_OPEN_LED,FltChannel);
    /*write 1 to clean*/
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_STAT_OPEN_LED,0x0fff);
    return res;
}

Std_ReturnType Max25608_GetRTEMP(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 *rtempData
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_ReadFun(device,isBCOrCs,device_id,MAX25608_RTEMP,rtempData);
    return res;
}

Std_ReturnType Max25608_SetLowDutyTh(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint16 Threshold
){
    Std_ReturnType res=E_OK;
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_RTEMP,Threshold);
    return res;
}

Std_ReturnType Max25608_SetPSFTGPR(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 PSFT_GROUP,
    uint8 PSFT
){
    Std_ReturnType res=E_OK;
    uint16 data=0;
    data=((uint16)(PSFT&0xff))|(((uint16)(PSFT_GROUP))<<8);
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_PSFT_GRP,data);
    return res;
}

Std_ReturnType Max25608_SetPSFT(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 channel,
    uint8 PSFT
){
    Std_ReturnType res=E_OK;
    uint16 data=PSFT;
    if(channel >12){
        /*invaild channel*/
        return E_NOT_OK;
    }
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_PSFT_1+channel,data);
    return res;
}

Std_ReturnType Max25608_SetTDIMGRP(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 TDIM_GROUP,
    uint8 TDIM
){
    Std_ReturnType res=E_OK;
    uint16 data=(((uint16)(TDIM_GROUP&0x3))<<4) | ((uint16)(TDIM&0x7));
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_TDIM_GRP,data);
    return res;
}

Std_ReturnType Max25608_SetTDIMxPaller(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 Series,
    uint8 TDIM
){
    Std_ReturnType res=E_OK;
    uint16 data=TDIM;
    if(Series>3){
        return E_NOT_OK;
    }
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_TDIM_321+Series,data);
    return res;
}

Std_ReturnType Max25608_SetGRPDutyCycle(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 Group,
    uint8 isFade,
    uint16 Duty
){
    Std_ReturnType res=E_OK;
    uint16 data=Duty | (isFade<<12);
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_PWM_GRPA_DUTY+Group,data);
    return res;
}

Std_ReturnType Max25608_SetPWMx(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id,
    uint8 channel,
    uint8 isFADE,
    uint16 DUTY
){
    Std_ReturnType res=E_OK;
    uint16 data=0;
    data=(DUTY&0xfff)|(((uint16)isFADE)<<12);
    res |= MAX25608_WriteFun(device,isBCOrCs,device_id,MAX25608_PWM1+channel,data);
    return res;
}

Std_ReturnType Max25608_PreInit(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_id
){
    /*return val*/
    Std_ReturnType res=E_OK;
    /*first, set all IC PWM CLK Source internal, disable CLKOUT*/
    /*PWM Dimming Freq is 0x2:default 500HZ*/
    /*LED_SLEW: 0x6: 1V/us*/
    /*VOTH: 0x1: 9.33V*/
    res |=Max25608_SetCNFG1(device,isBCOrCs,device_id,0,0x2,6,1);
    /*set all channel short LED threshold 0: 1.4V*/
    res |=Max25608_SetCNFG2to4(device,isBCOrCs,device_id,2,0);
    /*set UARR watchdog disable*/
    res |=Max25608_SetUartCNFG(device,isBCOrCs,device_id,0,0);
    /*set LED OFF when watchdog triggerd*/
    res |=Max25608_SetWDGFailSafeState(device,isBCOrCs,device_id,0x0fff);
    /*set Low duty cycle threshold 0x000f*/
    res |=Max25608_SetLowDutyTh(device,isBCOrCs,device_id,0x000f);
    /**/
    return res;
}

