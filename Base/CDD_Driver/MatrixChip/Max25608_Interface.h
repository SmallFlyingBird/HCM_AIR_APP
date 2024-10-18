#ifndef MAX25608_INTERFACE_H
#define MAX25608_INTERFACE_H

/*==================================================================================================
*                                       CONFIGURATION
==================================================================================================*/


#define isMAX25608B 1


#define MAX_NUMBER_OF_MAX25608 12
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "McalLib.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MAX25608_INTERFACE_H_HIGH_VERSION     0
#define MAX25608_INTERFACE_H_MIDDLE_VERSION   0
#define MAX25608_INTERFACE_H_LOW_VERSION      0

#if (MAX25608_INTERFACE_H_HIGH_VERSION != MAX25608_INTERFACE_C_HIGH_VERSION)
    #error "Max25608_Interface.c and Max25608_Interface.h have different version id, please check files compatibility"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    /* data */

    /**
     * PWM Diming freq for all LMMS
     * @details:
     * 0x0: FOSC/8192 (Norminal 2kHZ)
     * 0x1: FOSC/16384 (Norminal 1KHZ)
     * 0x2: FOSC/32768 (Norminal 500HZ)
     * 0x3: FOSC/65535 (Norminal 250HZ)
    */
    uint8 pMaxLMMPWMDimFreq;

        /**
     * communication watchdog timer settings for all LMM
     * @details:
     * 0x0: disabled; 0x1: 200us; 0x2: 500us; 0x3: 1ms
     * 0x4: 2ms; 0x5: 5ms; 0x6: 10ms; 0x7: 20ms; 0x8: 50ms
     * 0x9: 100ms; 0xa: 200ms; 0xb: 500ms; 0xc: 1s; 0xd: 2s
     * 0xe: 5s; 0xf：5s
    */
    uint8 pMaxLMMWdgCfg;

    /**
     * Low Duty threshold, under this duty , will disable short
     * @details:
     * 0x1: internal
     * 0x2: external
     */
    uint8 pMaxLMMLowPWMTh;

    uint8 pMaxLMMMaxPWMTh;
}Max25608_GlobalParaSettingType;

/**
 * @brief 
 * member: isEnable;Addr;SlewRate;ClkSel;Type;OpenTh;ShortTh;
 */
typedef struct
{
    /* data */

    /**
     * enabled flag
     * @details:
     * 0x0: disabled
     * 0x1: enabled
     */
    uint8 isEnable;

        /**
     * device_addr
     */
    uint8 Addr;

        /**
     * SlewRate
     * @details:
     * 0x0: 0.04
     * 0x1: 0.062
     * 0x2: 0.11
     * 0x3: 0.2
     * 0x4: 0.31
     * 0x5: 0.5
     * 0x6: 1.0
     */
    uint8 SlewRate;

        /**
     * SlewRate
     * @details:
     * 0x0: 0.04
     * 0x1: 0.062
     * 0x2: 0.11
     * 0x3: 0.2
     * 0x4: 0.31
     * 0x5: 0.5
     * 0x6: 1.0
     */
    uint8 ClkSel;

    /*LMM Type*/
    uint8 Type;

    /***
     * open led threshold
     * 
     */
    uint8 OpenTh;

    /***
     * short led threshold
     * 
     */
    uint8 ShortTh;
    uint8 PHASE[12];
    uint8 FailSafetyEnState;
    
}Max25608_MaritxSettingType;

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

Std_ReturnType LMM_Max25608_InitFun(void);
Std_ReturnType LMM_Max25608_MainFunction(void);

#endif
