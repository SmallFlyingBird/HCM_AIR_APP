/***
Date: 2024/01/08
Auther: yinjianye
***/
#ifndef BD18397_H
#define BD18397_H

/*==================================================================================================
*                                       CONFIGURATION
==================================================================================================*/
/**
 * config for BD18397 driver ADC function MAX read note. 
 * @details if you only read a few ADC note, you can adjust this, 
 * */
#define MAX_ADC_Node 4

/**
 * config for BD18397 driver main function behavior. 
 * @details if ASSERT 1, mainfunction will get channel err in mainfunction, and BD18397GetHwChErrStatus will only return buffer value , 
 * if ASSERT 0, mainfunction will not read channel err, and BD18397GetHwChErrStatus will send SPI read err command, and retrive register value.
 * */
#define BD18397CONFIG_GetChannel_ERR_In_MainFunction 1

/**
 * config for BD18397 driver main function behavior. 
 * @details if ASSERT 1, mainfunction will get ADC val in accroding to the number of MAX_ADC_Node, and ADNode_mapping. 
 * 
 * if ASSERT 0, mainfunction will not read channel err, and GetChannelErr will send SPI read err command, and retrive register value.
 * */
#define BD18397CONFIG_GetADC_In_MainFunctin 1


/*if used OS_Resource*/
#define BD18397CONFIG_OS_RESOURCE_USED 1
#if BD18397CONFIG_OS_RESOURCE_USED
#include "Os_Cfg.h"
#include "Os.h"
    #define OsResource_BD18397Spi OsResource_BoostBuckSpi
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "HcmPlatform.h"
#include "Buck_Interface.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BD18397_H_DRIVER_MAJOR_VERSION 0
#define BD18397_H_DRIVER_MINOR_VERSION 0
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*BD18397 Vfsradc voltage*/
#define BD18397_VFSRADC     25      /*2.5V*/

/**
 * BD18397 register map
*/
#define BD18397_SYSSET      (0x00u)
#define BD18397_ERRSET1     (0x02u)
#define BD18397_DIMSET      (0x03u)
#define BD18397_ISET1H      (0x04u)
#define BD18397_ISET1L      (0x05u)
#define BD18397_ISET2H      (0x06u)
#define BD18397_ISET2L      (0x07u)
#define BD18397_ISET3H      (0x08u)
#define BD18397_ISET3L      (0x09u)
#define BD18397_DPWM1H      (0x0au)
#define BD18397_DPWM1L      (0x0bu)
#define BD18397_DPWM2H      (0x0cu)
#define BD18397_DPWM2L      (0x0du)
#define BD18397_DPWM3H      (0x0eu)
#define BD18397_DPWM3L      (0x0fu)
#define BD18397_DCDCSET1    (0x10u)
#define BD18397_DCDCSET2    (0x11u)
#define BD18397_DCDCSET3    (0x12u)
#define BD18397_DCDCSET4    (0x13u)
#define BD18397_CHEN        (0x14u)
#define BD18397_ADSEL       (0x15u)
#define BD18397_VMONH       (0x16u)
#define BD18397_VMONL       (0x17u)
#define BD18397_ERRSTALL    (0x18u)
#define BD18397_ERRST1      (0x19u)
#define BD18397_ERRST2      (0x1au)
#define BD18397_ERRST3      (0x1bu)


/*crc formula x8+x5+x4+1*/
#define	CRC_MUL		        (0x31u)  


#define BD18397_MODIFY_MHL 1

 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/*A/D Node */
typedef enum{
    A_D_Thermal     =0x00,
    A_D_ISET1       =0x01,
    A_D_ISET2       =0x02,
    A_D_ISET3       =0x03,
    A_D_VIN         =0x04,
    A_D_V5VEXT      =0x05,
    A_D_VPIN        =0x06,
    A_D_VSNSN1      =0x07,
    A_D_VSNSN2      =0x08,
    A_D_VSNSN3      =0x09,
}BD18397_A_D_NodeType;
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*
 *  BD18397_TransType is the IC data which is used for transfer data;
*/
typedef struct {
    uint8 ID;
    uint8 SpiChNo;
    uint8 RWAddr;
    uint8 data;
    uint8 CRC;
}BD18397_TransType;

/*
 *  BD18397_ReceiveType is the IC data which is used for receive data;
*/
typedef struct {
    uint8 ID;
    uint8 data1;
    uint8 data2;
    uint8 CRC;
}BD18397_ReceiveType;
/*
 *  BD18397_RegDataType is the IC Regeister data buffer;
*/
typedef struct{
    uint8 BD18397_SYSSET_Data;
    uint8 BD18397_ERRSET1_Data;
    uint8 BD18397_DIMSET_Data;      
    uint8 BD18397_ISET1H_Data;      
    uint8 BD18397_ISET1L_Data;      
    uint8 BD18397_ISET2H_Data;      
    uint8 BD18397_ISET2L_Data;      
    uint8 BD18397_ISET3H_Data;      
    uint8 BD18397_ISET3L_Data;      
    uint8 BD18397_DPWM1H_Data;      
    uint8 BD18397_DPWM1L_Data;      
    uint8 BD18397_DPWM2H_Data;      
    uint8 BD18397_DPWM2L_Data;      
    uint8 BD18397_DPWM3H_Data;      
    uint8 BD18397_DPWM3L_Data;      
    uint8 BD18397_DCDCSET1_Data;    
    uint8 BD18397_DCDCSET2_Data;    
    uint8 BD18397_DCDCSET3_Data;    
    uint8 BD18397_DCDCSET4_Data;    
    uint8 BD18397_CHEN_Data;        
    uint8 BD18397_ADSEL_Data;       
    uint8 BD18397_VMONH_Data;       
    uint8 BD18397_VMONL_Data;       
    uint8 BD18397_ERRSTALL_Data;    
    uint8 BD18397_ERRST1_Data;      
    uint8 BD18397_ERRST2_Data;      
    uint8 BD18397_ERRST3_Data;         
}BD18397_RegDataType;


/*
*   BD18397 ADC retrive val
*/
typedef union 
{
    struct 
    {
        /* data */
        uint16 Thermal;
        uint16 ISET1;
        uint16 ISET2;
        uint16 ISET3;
        uint16 VIN;
        uint16 V5VEXT;
        uint16 VPIN;
        uint16 VSNSN1;
        uint16 VSNSN2;
        uint16 VSNSN3;
        uint16 ADSEL;
        uint16 TMEPDELAY;
    }AdcStruct;
    uint16 data[12];
    /* data */

}BD18397_ADCStoreType;



/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * BD18397SetRDMODE is used for change RDMODE, be caution you need know what you want to do
 * this function can not return E_NOT_OK, expecte SPI err. 
 * if present RDMODE is equal to is10bit, function do nothing, and return E_OK;
 * */
Std_ReturnType BD18397SetRDMODE(uint8 id, uint8 is10bit);

/**
 * BD18397SetICH used to set ch current. 
 * Rsnsx is the resistance between SNSPx and SNSNx, unit: mΩ;
 * current is the target current, unit: mA;
 * hw_ch start as 0;
*/
Std_ReturnType BD18397SetICH(uint8 id, uint8 hw_ch, uint16 Rsnsx, uint16 Current);

/**
 * BD18397SetPWM used to set ch PWM dutycycle. 
 * this function can only change internal PWM dimming setting.
 * hw_ch start as 0;
*/
Std_ReturnType BD18397SetPWM(uint8 id, uint8 hw_ch, uint8 PWM);

/**
 * BD18397SetHwCHCtrl used to set channel open and close.
*/
Std_ReturnType BD18397SetHwCHCtrl(uint8 id, uint8 hw_ch, uint8 isON); //测试 记得改回  20241202

/**
 * BD18397Init used to init IC, you need fill RegDataBuffer before call this function.
*/
Std_ReturnType BD18397Init(uint8 id);

/**
 * BD18397DeInit used to RESET IC, after that, you need reconfig IC next.
 * WARNING: this function will not reset regDataBuffer, data is still remain. 
*/
Std_ReturnType BD18397DeInit(uint8 id);

/**
 * BD18397GetHwCHCtrl used to retrive present hardware channel ON/OFF status. It will also reflesh RegDataBuffer;
*/
Std_ReturnType BD18397GetHwCHCtrl(uint8 id, uint8 hw_ch, E_ChannelState *isON);

/**
 * BD18397MainFun used to retrive DiagDataAutoMaticly,and cycling A/D temp. it can adjust the function, 
 * WARNING: this function just reflash RegDataBuffer, 
 * if you want retrive err data or a/d data, you need use read regbuffer function. 
*/
Std_ReturnType BD18397MainFun(uint8 id);

/**
 * BD18397SetDCDCSetting used to write channel DCDC.
 * 
*/
Std_ReturnType BD18397SetDCDCSetting(uint8 id, uint8 hw_ch, uint8 GM, uint8 TON);

/**
 * BD18397GetPWM used to retrive present PWM. It will also reflesh RegDataBuffer;
*/
Std_ReturnType BD18397GetPWM(uint8 id, uint8 hw_ch, uint8 *PWMBuffer);

/**
 * BD18397SetADCNoteMode used to write ADCSEL. It will also reflesh RegDataBuffer;
*/
Std_ReturnType BD18397SetADCNoteMode(uint8 id, uint8 mode, uint8 trg, uint8 ADMODE);

/**
 * BD18397GetPWM used to retrive VMON. It will also reflesh RegDataBuffer;
*/
Std_ReturnType BD18397GetADC(uint8 id, uint16 *VMON);

/**
 * BD18397GetThremalBuffer used to retrive thremal ADC BUFFER, it need caculate.
 * @warning: you should use BD18397MainFun to retrive ADC data first, and then use this to Get ADC BUFFER.
*/
Std_ReturnType BD18397GetThremalBuffer(uint8 id, uint16 *buffer);

/**
 * BD18397GetHwChVoltage used to retrive channel voltage. it need caculate.
 * @warning: you should use BD18397MainFun to retrive ADC data first, and then use this to Get ADC BUFFER.
*/
Std_ReturnType BD18397GetHwChVoltage(uint8 id,uint8 hw_ch, uint16 *buffer);

/**
 * BD18397GetHwChErrStatus used to retrive ERRST1 to ERRST3.
 * @warning: you should use BD18397MainFun to reflash store buffer.
*/
Std_ReturnType BD18397GetHwChErrStatus(uint8 id,uint8 hw_ch, uint8 *buffer);
Std_ReturnType BD18397GetOutputFrequency(uint8 id, uint8 hw_ch, uint16 *OutputFrequency);

Std_ReturnType BD18397GetLostComFlag(uint8 id, uint8 *val);
Std_ReturnType BD18397GetLostConfig(uint8 id, uint8 *val);

Std_ReturnType BD18397SetLHEnable(uint8 id);
Std_ReturnType BD18397SetLHDisable(uint8 id);

#endif
