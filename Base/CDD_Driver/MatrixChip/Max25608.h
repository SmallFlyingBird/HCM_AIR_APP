/***
Date: 2024/02/17
Auther: yinjianye
***/

#ifndef MAX25608_H
#define MAX25608_H

/*==================================================================================================
*                                       CONFIGURATION
==================================================================================================*/
/*if used OS_Resource*/
#define MAX25608_CONFIG_OS_RESOURCE_USED 0
#if MAX25608_CONFIG_OS_RESOURCE_USED
    #define OsResource_MAX25608Uart OS_Resource_Uart_MACROS
    #if (OsResource_MAX25608Uart==OS_Resource_Uart_MACROS)
        #error "MAX25608 OS_Resource need be input"
    #endif
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "Std_Types.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MAX25608_H_DRIVER_MAJOR_VERSION 0
#define MAX25608_H_DRIVER_MINOR_VERSION 0
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*Register Map*/
#define MAX25608_NO_OP          0x00
#define MAX25608_SW_GO          0x01
#define MAX25608_CNFG_GEN_1     0x02  
#define MAX25608_CNFG_GEN_2     0x04
#define MAX25608_CNFG_GEN_3     0x05
#define MAX25608_CNFG_GEN_4     0x06
#define MAX25608_CNFG_UART      0x07
#define MAX25608_CNFG_WATCHDOG  0x08
#define MAX25608_CNFG_OPEN_OVRD 0x09
#define MAX25608_CNFG_GROUPA    0x0A
#define MAX25608_CNFG_GROUPB    0x0B
#define MAX25608_CNFG_MSK_GEN   0x0C
#define MAX25608_CNFG_MSK_LED   0x0D
#define MAX25608_STAT_RADC      0x0E
#define MAX25608_STAT_RES_CODE  0x0F
#define MAX25608_STAT_GEN       0x10
#define MAX25608_STAT_UART      0x11
#define MAX25608_STAT_SHORT_LED 0x12
#define MAX25608_STAT_OPEN_LED  0x13
#define MAX25608_RTEMP          0x15
#define MAX25608_LOW_DUTY_TH    0x16
#define MAX25608_PSFT_GRP       0x20
#define MAX25608_PSFT_1         0x21
#define MAX25608_PSFT_2         0x22
#define MAX25608_PSFT_3         0x23
#define MAX25608_PSFT_4         0x24
#define MAX25608_PSFT_5         0x25
#define MAX25608_PSFT_6         0x26
#define MAX25608_PSFT_7         0x27
#define MAX25608_PSFT_8         0x28
#define MAX25608_PSFT_9         0x29
#define MAX25608_PSFT_10        0x2A
#define MAX25608_PSFT_11        0x2B
#define MAX25608_PSFT_12        0x2C
#define MAX25608_TDIM_GRP       0x30
#define MAX25608_TDIM_321       0x31
#define MAX25608_TDIM_654       0x32
#define MAX25608_TDIM_987       0x33
#define MAX25608_TDIM_KQJ       0x34
#define MAX25608_PWM_GRPA_DUTY  0x40
#define MAX25608_PWM_GRPB_DUTY  0x41
#define MAX25608_PWM1           0x42
#define MAX25608_PWM2           0x43
#define MAX25608_PWM3           0x44
#define MAX25608_PWM4           0x45
#define MAX25608_PWM5           0x46
#define MAX25608_PWM6           0x47
#define MAX25608_PWM7           0x48
#define MAX25608_PWM8           0x49
#define MAX25608_PWM9           0x4A
#define MAX25608_PWM10          0x4B
#define MAX25608_PWM11          0x4C
#define MAX25608_PWM12          0x4D

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* register struct*/
typedef struct 
{
    /* data */
    uint8 SW_GO_Data;
    
}Max25608_RegDataType;


typedef struct 
{
    uint8 is25608b;
    uint8 uartNum;
    /* data */
}Max25608_TransType;


/*Device fault*/
typedef union 
{
    struct 
    {
        uint16 TH_WARN:1;
        uint16 TH_SHDN:1;
        uint16 CP_RDY_N:1;
        uint16 SHORT_LED:1;
        uint16 OPEN_LED:1;
        uint16 reserve1:1;
        uint16 UART_ERR:1;
        uint16 EXT_CLK_ERR:1;
        uint16 RADC_ERR:1;
        uint16 CONFIG_NOT_DONE:1;
        uint16 OTP_CRC_ERR:1;
        uint16 reserve2:1;
        uint16 reserve3:1;
        uint16 reserve4:1;
        uint16 reserve5:1;
        uint16 reserve6:1;
        /* data */
    }bit;
    uint16 fltData;
    /* data */
}Max25608_DeviceFltUnionType;

/*Uart fault*/
typedef union 
{
    /* data */
    struct 
    {
        /* data */
        uint16 reserve1:1;
        uint16 RX_PL_START_ERR:1;
        uint16 RX_PL_STOP_ERR:1;
        uint16 RX_SYNC_STOP_ERR:1;
        uint16 RX_PL_PERR:1;
        uint16 RX_SYNC_PERR:1;
        uint16 RX_CRC_ERR:1;
        uint16 RX_TIMEOUT_ERR:1;
        uint16 UART_WATCHDOG:1;
        uint16 reserve2:1;
        uint16 reserve3:1;
        uint16 reserve4:1;
        uint16 reserve5:1;
        uint16 reserve6:1;
        uint16 reserve7:1;
        uint16 reserve8:1;
    }bit;
    uint16 fltData;
}Max25608_UartFltUnionType;


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * Std_ReturnType Max25608_GetDeviceInfo();
 * @brief this function used to read device info which is REV_ID and constant_test number. 
 * This function used for check uart network function;
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param device_addr specific IC or Cluster device_addr.
 * @param REV_ID a pointer which point to where you want to store REV_ID. type: uint8*.
 * @param Const_test a pointer which point to where you wanna store constant_test, type: uint8*.
 * */
Std_ReturnType Max25608_GetDeviceInfo(
    Max25608_TransType *device, 
    uint8 device_addr,
    uint8 *REV_ID,
    uint8 *Const_test
    );


/**
 * Std_ReturnType Max25608_SetSWGO();
 * @brief this function is used to control channel.
 * usually for start device dimming after init. 
 * @warning should set SW_GO_EN == 0, then change CNFG_GEN_1/2/3/4, otherwise will failed
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param isON 1: SW_GO_EN set1. 
 * */
Std_ReturnType Max25608_SetSWGO(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 isON
    );

/**
 * Std_ReturnType Max25608_SetCNFG1();
 * @brief this function is used to set CNFG_GEN_1(02h).
 * this register should be set when init, 
 * and its usually using boardcast function, except first device. 
 * @warning should set SW_GO_EN == 0, then change CNFG_GEN_1/2/3/4, 
 * otherwise will be failed.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param PWM_CLK_SEL PWM clk source select and fun choice. 
 * @details :
 * bit0: CLKOUT OPEN/CLOSE; 
 * bit1: INTERNAL/CLKIN
 * @param DIV PWM freq select, norminal: 
 * @details norminal:
 * 0x0: 2khz;
 * 0x1: 1khz;
 * 0x2: 500hz;
 * 0x3: 250hz; 
 * @param LED_SLEW PWM freq select, 
 * @details : 
 * 0x0: 0.04V/us;
 * 0x1: 0.062V/us;
 * ...
 * 0x6: 1.0V/us;
 * @param VOTH LED OPEN threshold:
 * @details :
 * 0x0: 14V;
 * 0x1: 9.33V;
 * 0x2: 4.66V;
 * 0x3: reserve;
 * */
Std_ReturnType Max25608_SetCNFG1(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 PWM_CLK_SEL,
    uint8 DIV,
    uint8 LED_SLEW,
    uint8 VOTH
    );

/**
 * Std_ReturnType Max25608_SetShortTh();
 * @brief this function is used to set CNFG_GEN_2(04h)to 4(06h).
 * this register should be set when init, 
 * but you should use Max25608_SetCNFG2to4() to init reg first. 
 * and use this fun to change exis val .
 * @warning should set SW_GO_EN == 0, then change CNFG_GEN_1/2/3/4, 
 * otherwise will be failed.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param channel specific channel. range: 0~11;
 * @param VSTH LED short ground vol threshold.
 * */
Std_ReturnType Max25608_SetShortTh(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 channel,
    uint8 VSTH
);

/**
 * Std_ReturnType Max25608_SetCNFG2to4();
 * @brief this function is used to set CNFG_GEN_2(04h)to 4 (06h).
 * this register should be set when init, 
 * The difference between the two functions is that this function is used for initialization and norminal situation. 
 * @warning should set SW_GO_EN == 0, then changing CNFG_GEN_1/2/3/4, 
 * otherwise will be failed.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param CNFG_X specific CNFG_GEN_X. range: 2~4;
 * @param data data which you want input in this register.
 * */
Std_ReturnType Max25608_SetCNFG2to4(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 CNFG_X,
    uint16 data
);

/**
 * Std_ReturnType Max25608_UartCNFG();
 * @brief this function is used to set CNFG_UART(07h).
 * this register should be set when init, indicate device CID and WDG timeout function.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param CID set Cluster device_addr, it will be used by cluster write;
 * @param WDG_timeout_SEL com watchdog timeout select.
 * */
Std_ReturnType Max25608_SetUartCNFG(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 CID,
    uint8 WDG_timeout_SEL
);

/**
 * Std_ReturnType Max25608_SetWDGFailSafeState();
 * @brief this function is used to set CNFG_WATCHDOG(08h).
 * this register indicate channel state when WDG timeout happened.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param WD_LED_STATE set LED state when wdg timeout happened. 0b0: switch open, 0b1: switch close;
 * */
Std_ReturnType Max25608_SetWDGFailSafeState(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 WD_LED_STATE
);

/**
 * Std_ReturnType Max25608_SetChannelMask();
 * @brief this function is used to set CNFG_OPEN_OVRD(09h).
 * if any bit is high, corresponding channel switch will be closed.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param OPEN_LED_OVRD mask channel 0: Normal; 1:LED switch force closed
 * */
Std_ReturnType Max25608_SetChannelMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 OPEN_LED_OVRD
);

/**
 * Std_ReturnType Max25608_SetGroupMask();
 * @brief this function is used to set CNFG_GROUPA/B(0A/Bh).
 * if any bit is high, corresponding channel will be in this group.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param isAOrB 0: Group A; 1: Group B
 * @param Group_Mask 1:including 0:none
 * */
Std_ReturnType Max25608_SetGroupMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 isAOrB,
    uint16 Group_Mask
);

/**
 * Std_ReturnType Max25608_SetDeviceFaultMask();
 * @brief this function is used to set CNFG_MSK_GEN(0Ch).
 * mask specific fault in this device and it will not trigger FLT pin.
 * and indicate what to do when Thermal_shutdown(close all switch or open it)
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param Flt_Mask Fault mask and TH_SHDN_ACT;
 * @details bit0: MSK_TH_WARN; bit1: MSK_RADC_ERR ;bit2:MSK_CP_RDY_N ;
 * bit3:MSK_SHORT_LED ;bit4:MSK_OPEN_LED ;bit6:MSK_UART_ERR ;bit12:TH_SHDN_ACT
 * */
Std_ReturnType Max25608_SetDeviceFltPinMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 Flt_Mask
);

/**
 * Std_ReturnType Max25608_SetLEDFltPinMask();
 * @brief this function is used to set CNFG_MSK_LED(0Dh).
 * FLT pin will not assert when this register indicate specific channel open or short.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param LED_Mask Fault mask;
 * */
Std_ReturnType Max25608_SetLEDFltPinMask(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 LED_Mask
);

/**
 * Std_ReturnType Max25608_GetRADC();
 * @brief this function is used to get STAT_RDAC(0Dh).
 * status indicate the RGRADE and RADDR decoding
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param measurementState pointer which indicate measurement state, 1: complete, 0: not complete.
 * @param fltState pointer which indicate flt: when any bit is 1: 
 * bit0: RGADE under range or short
 * bit1: RADDR under range or short
 * bit2: RGADE over range or open
 * bit3: RADDR over range or open
 * */
Std_ReturnType Max25608_GetRADC(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 *measurementState,
    uint8 *fltState
);

/**
 * Std_ReturnType Max25608_GetRGRADE();
 * @brief this function is used to get STAT_RES_CODE(0Fh).
 * what is the meaning of this reg?
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param RGRADE pointer which is RGRADE val;
 * */
Std_ReturnType Max25608_GetRGRADE(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 *RGRADE
);

/**
 * Std_ReturnType Max25608_GetDeviceFault();
 * @brief this function is used to get STAT_GEN(10h).
 * this register indicate device fault.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param FltUnion pointer which is store deviceflt;
 * */
Std_ReturnType Max25608_GetDeviceFault(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    Max25608_DeviceFltUnionType *FltUnion
);

/**
 * Std_ReturnType Max25608_GetUartFault();
 * @brief this function is used to get STAT_GEN(11h).
 * this register indicate device fault.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param FltUnion pointer which is store uartflt;
 * */
Std_ReturnType Max25608_GetUartFault(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    Max25608_UartFltUnionType *FltUnion
);

/**
 * Std_ReturnType Max25608_GetLEDShort();
 * @brief this function is used to get STAT_SHORT_LED(12h).
 * this register indicate led short.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param FltChannel pointer which is store flt channel;
 * */
Std_ReturnType Max25608_GetLEDShort(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 *FltChannel
);

/**
 * Std_ReturnType Max25608_GetLEDOpen();
 * @brief this function is used to get STAT_SHORT_OPEN(13h).
 * this register indicate led open.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param FltChannel pointer which is store flt channel;
 * */
Std_ReturnType Max25608_GetLEDOpen(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 *FltChannel
);

/**
 * Std_ReturnType Max25608_GetRTEMP();
 * @brief this function is used to get RTEMP(15h).
 * this register indicate ADC.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param FltChannel pointer which is store flt channel;
 * */
Std_ReturnType Max25608_GetRTEMP(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 *rtempData
);

/**
 * Std_ReturnType Max25608_SetLowDutyTh();
 * @brief this function is used to set LOW_DUTY_TH(16h).
 * this register set LED fault filter.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param Threshold low duty threshold;
 * */
Std_ReturnType Max25608_SetLowDutyTh(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint16 Threshold
);

/**
 * Std_ReturnType Max25608_SetPSFTGPR();
 * @brief this function is used to set PSFT_GRP(20h).
 * this register written group PSFT.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param PSFT_GROUP group select: bit0:group A, bit1: group B,it can select both group;
 * @param PSFT phase shift,uint8;
 * */
Std_ReturnType Max25608_SetPSFTGPR(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 PSFT_GROUP,
    uint8 PSFT
);

/**
 * Std_ReturnType Max25608_SetPSFT();
 * @brief this function is used to set PSFT_x(21h-2Ch).
 * this register written channel PSFT.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param channel channel select: 0to11
 * @param PSFT phase shift, uint8;
 */
Std_ReturnType Max25608_SetPSFT(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 channel,
    uint8 PSFT
);

/**
 * Std_ReturnType MAX25608_SetTDIMGRP();
 * @brief this function is used to set TDIM_GRP(30h).
 * this register written group dimming period.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param channel channel select: 0~12;
 * @param PSFT dimming period select;
 * @details:
 * 0x0:Update PWM duty cycle every 1 PWM period;
 * 0x1:2 PWM period;
 * 0x2:4 PWM period;
 * 0x3:8 PWM period;
 * 0x4:16 PWM period;
 * 0x5~0x7:32 PWM period;
 * (1 PWM period = 8192 clock cycles by default. it can set by 02h register)
 * */
Std_ReturnType Max25608_SetTDIMGRP(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 TDIM_GROUP,
    uint8 TDIM
);

/**
 * Std_ReturnType MAX25608_SetTDIMxPaller();
 * @brief this function is used to set TDIM_xxx(31h-34h).
 * this register written series dimming period.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param Series Series select: 0~3;
 * @param PSFT dimming period select;
 * @details:
 * 0x0:Update PWM duty cycle every 1 PWM period;
 * 0x1:2 PWM period;
 * 0x2:4 PWM period;
 * 0x3:8 PWM period;
 * 0x4:16 PWM period;
 * 0x5~0x7:32 PWM period;
 * (1 PWM period = 8192 clock cycles by default. it can set by 02h register)
 * */
Std_ReturnType Max25608_SetTDIMxPaller(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 Series,
    uint8 TDIM
);

/**
 * Std_ReturnType MAX25608_SetGRPDutyCycle();
 * @brief this function is used to set PWM_GRPX_DUTY(40h-41h).
 * this register written group duty cycles.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param Group Group select: 0x0:A, 0x1:B, it can NOT set at the same time;
 * @param isfade enable specific group fade function. 0x0:disbale, 0x1:enable;
 * @param Duty uint16 12bit duty cycle val;
 * */
Std_ReturnType Max25608_SetGRPDutyCycle(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 Group,
    uint8 isfade,
    uint16 Duty
);

/**
 * Std_ReturnType Max25608_SetPWMx();
 * @brief this function is used to set PWMx(x==1 to 12)(42h-4dh).
 * this register written group duty cycles.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * @param channel Group select: 0x0:A, 0x1:B, it can NOT set at the same time;
 * @param isFADE enable specific group fade function. 0x0:disbale, 0x1:enable;
 * @param DUTY uint16 12bit duty cycle val;
 * */
Std_ReturnType Max25608_SetPWMx(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr,
    uint8 channel,
    uint8 isFADE,
    uint16 DUTY
);

/**
 * Std_ReturnType Max25608_PreInit();
 * @brief this function is used to Init the chip. but have no config of DUTYCYCLE and PHASE .
 *  it only PreInit CNFG register and not set SW_GO.
 * @param device a pointer specific IC type, including uart channel number and assert 25608b.
 * @param isBCOrCs 0: specific IC;
 *                 1: boardcast/cluster;
 * @param device_addr specific IC or Cluster device_addr.
 * */
Std_ReturnType Max25608_PreInit(
    Max25608_TransType *device,
    uint8 isBCOrCs,
    uint8 device_addr
);

#endif
