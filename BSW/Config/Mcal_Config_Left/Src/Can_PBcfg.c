/**************************************************************************************************/
/**
 * @file      : Can_PBcfg.c
 * @brief     : Can AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Configuration
 *  @brief Can AUTOSAR level configuration
 *  @{
 */

#include "Can.h"
#include "Can_Drv.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */

#define CAN_PBCFG_C_VENDOR_ID                   0x00B3U
#define CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_PBCFG_C_SW_MAJOR_VERSION            1U
#define CAN_PBCFG_C_SW_MINOR_VERSION            2U
#define CAN_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Can.h are of the same vendor */
#if (CAN_PBCFG_C_VENDOR_ID != CAN_VENDOR_ID)
    #error "Vendor ID of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION   != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Software version */
#if ((CAN_PBCFG_C_SW_MAJOR_VERSION  != CAN_SW_MAJOR_VERSION) || \
     (CAN_PBCFG_C_SW_MINOR_VERSION  != CAN_SW_MINOR_VERSION) || \
     (CAN_PBCFG_C_SW_PATCH_VERSION  != CAN_SW_PATCH_VERSION))
    #error "Software Version of Can_PBcfg.c and Can.h are different"
#endif

/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_PBCFG_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor ID of Can_PBcfg.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION   != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_PBcfg.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_PBCFG_C_SW_MAJOR_VERSION  != CAN_DRV_H_SW_MAJOR_VERSION) || \
     (CAN_PBCFG_C_SW_MINOR_VERSION  != CAN_DRV_H_SW_MINOR_VERSION) || \
     (CAN_PBCFG_C_SW_PATCH_VERSION  != CAN_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Can_PBcfg.c and Can_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* CAN_START_SEC_VAR_CLEARED_UNSPECIFIED */
    #define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Can_MemMap.h"


    #define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Can_MemMap.h"
    /* CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED */
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"



/**
* @brief   Export CAN configurations.
*/

static const Can_HwChannelConfigType Can_HwChannelConfig0 =
{
    /* Here should be included the structure from CAN*/
    &Can_Drv_CtrlConfig[0U]
};

/* Can_HardwareFilterType */
static const Can_HardwareFilterType Can_HwFilterObject0=
{
                                
    (uint32)0x00000183U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject1=
{
                                
    (uint32)0x00000185U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject2=
{
                                
    (uint32)0x0000018eU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject3=
{
                                
    (uint32)0x0000018cU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject4=
{
                                
    (uint32)0x00000180U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject5=
{
                                
    (uint32)0x00000040U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject6=
{
                                
    (uint32)0x0000018fU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject7=
{
                                
    (uint32)0x0000017dU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject8=
{
                                
    (uint32)0x0000013bU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject9=
{
                                
    (uint32)0x0000013fU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject10=
{
                                
    (uint32)0x0000018aU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject11=
{
                                
    (uint32)0x00000300U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject12=
{
                                
    (uint32)0x00000189U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject13=
{
                                
    (uint32)0x0000018dU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject14=
{
                                
    (uint32)0x00000220U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject15=
{
                                
    (uint32)0x00000080U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject16=
{
                                
    (uint32)0x00000200U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject17=
{
                                
    (uint32)0x0000013dU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject18=
{
                                
    (uint32)0x00000078U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject19=
{
                                
    (uint32)0x00000188U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject20=
{
                                
    (uint32)0x0000018bU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject21=
{
                                
    (uint32)0x00000139U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject22=
{
                                
    (uint32)0x00000138U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject23=
{
                                
    (uint32)0x00000052U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject24=
{
                                
    (uint32)0x00000137U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject25=
{
                                
    (uint32)0x00000141U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject26=
{
                                
    (uint32)0x00000050U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject27=
{
                                
    (uint32)0x0000021aU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject28=
{
                                
    (uint32)0x00000186U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject29=
{
                                
    (uint32)0x00000187U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject30=
{
                                
    (uint32)0x00000264U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject31=
{
                                
    (uint32)0x0000020aU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject32=
{
                                
    (uint32)0x0000001cU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject33=
{
                                
    (uint32)0x00000190U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject34=
{
                                
    (uint32)0x00000018U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject35=
{
                                
    (uint32)0x0000014dU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject36=
{
                                
    (uint32)0x00000150U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject37=
{
                                
    (uint32)0x00000321U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject38=
{
                                
    (uint32)0x00000322U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject39=
{
                                
    (uint32)0x00000323U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject40=
{
                                
    (uint32)0x00000324U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject41=
{
                                
    (uint32)0x00000325U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject42=
{
                                
    (uint32)0x00000326U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject43=
{
                                
    (uint32)0x00000327U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject44=
{
                                
    (uint32)0x00000328U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject45=
{
                                
    (uint32)0x00000329U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject46=
{
                                
    (uint32)0x0000032aU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject47=
{
                                
    (uint32)0x0000032bU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject48=
{
                                
    (uint32)0x0000032cU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject49=
{
                                
    (uint32)0x0000032dU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject50=
{
                                
    (uint32)0x0000032fU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject51=
{
                                
    (uint32)0x0000032eU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject52=
{
                                
    (uint32)0x00000330U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject53=
{
                                
    (uint32)0x00000331U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject54=
{
                                
    (uint32)0x00000332U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject55=
{
                                
    (uint32)0x00000333U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject56=
{
                                
    (uint32)0x00000334U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject57=
{
                                
    (uint32)0x00000335U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject58=
{
                                
    (uint32)0x00000336U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject59=
{
                                
    (uint32)0x00000337U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject60=
{
                                
    (uint32)0x00000338U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject61=
{
                                
    (uint32)0x00000310U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject62=
{
                                
    (uint32)0x00000480U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject63=
{
                                
    (uint32)0x00000532U,
    (uint32)0xdf000000U

};
static const Can_HardwareFilterType Can_HwFilterObject64=
{
                                
    (uint32)0x00000315U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject65=
{
                                
    (uint32)0x00000596U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject66=
{
                                
    (uint32)0x000007b3U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject67=
{
                                
    (uint32)0x000007ffU,
    (uint32)0xdffc0000U

};



/**
*   @brief  Can Hardware Object Config
*/
static const Can_HwObjConfigType Can_HwObjectConfig[CAN_HWOBJECT_CONFIG_COUNT]=
{
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)0,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject0,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)0U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)1,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject1,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)1U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)2,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject2,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)2U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)3,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject3,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)3U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)4,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject4,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)4U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)5,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject5,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)5U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)6,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject6,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)6U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)7,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject7,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)7U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)8,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject8,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)8U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)9,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject9,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)9U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)10,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject10,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)10U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)11,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject11,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)11U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)12,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject12,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)12U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)13,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject13,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)13U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)14,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject14,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)14U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)15,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject15,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)15U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)16,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject16,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)16U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)17,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject17,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)17U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)18,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject18,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)18U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)19,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject19,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)19U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)20,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject20,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)20U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)21,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject21,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)21U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)22,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject22,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)22U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)23,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject23,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)23U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)24,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject24,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)24U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)25,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject25,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)25U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)26,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject26,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)26U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)27,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject27,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)27U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)28,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject28,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)28U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)29,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject29,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)29U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)30,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject30,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)30U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)31,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject31,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)31U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)32,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject32,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)32U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)33,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject33,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)33U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)34,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject34,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)34U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)35,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject35,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)35U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)36,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject36,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)36U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)37,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject37,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)37U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)38,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject38,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)38U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)39,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject39,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)39U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)40,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject40,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)40U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)41,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject41,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)41U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)42,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject42,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)42U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)43,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject43,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)43U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)44,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject44,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)44U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)45,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject45,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)45U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)46,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject46,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)46U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)47,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject47,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)47U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)48,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject48,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)48U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)49,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject49,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)49U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)50,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject50,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)50U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)51,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject51,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)51U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)52,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject52,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)52U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)53,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject53,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)53U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)54,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject54,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)54U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)55,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject55,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)55U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)56,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject56,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)56U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)57,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject57,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)57U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)58,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject58,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)58U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)59,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject59,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)59U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)60,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject60,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)60U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)61,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject61,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)61U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)62,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject62,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)62U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)63,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject63,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)63U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)64,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject64,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)64U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)65,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject65,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)65U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)66,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject66,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)66U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)67,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject67,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)67U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)68,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)68U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)69,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)69U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)70,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)70U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)71,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)71U,
    },
    
    
    {
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)72,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)72U,
    }
    
};
/**
*   @brief  Can Baudrate Config of 0
*/
static const Can_ControllerBaudrateConfigType Can_BaudrateConfigCtrl0[1U]=
{
    
    {
        
        (uint8)0U,                
        /* arbitration phase  */
        {
            
            (uint8)6U,
            (uint8)3U,
            (uint8)2U,
            (uint16)4U,
            (uint8)2U
        },
        /* FD enable */
        (boolean)FALSE,
        
        /* Can Fd Data Bit Rate */
        {
        (uint8)1U,
        (uint8)1U,
        (uint8)2U,
        (uint16)1U,
        (uint8)1U
        },
        /* Tx Bit Rate Switch */
        (boolean)FALSE,
        
        
        (boolean)FALSE,
        (uint8)0U
    }
    
};


static const Can_RxFifoConfigType Can_RxFiFOConfigCtr0=
{
    /* --- Default values when Legacy FIFO is not available --- */
    /* ID Acceptance Mode */
    CAN_RX_FIFO_FORMAT_A,
    /* Global mask of Legacy FIFO */
    (uint32)0xFFFFFFFFU,
    /* Legacy FIFO Overflow Notification */
    NULL_PTR,
    /* Legacy FIFO Warning Notification */
    NULL_PTR,
    /* Legacy FIFO avialbe Notification */
     NULL_PTR,
    
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


/**
*   @brief  CAN Hardware Object Type of CanControllerId_0
*/
static const Can_HwObjConfigType * const Can_HwObjectCfgPtr0[73U]=
{
    &Can_HwObjectConfig[0U],
    
    &Can_HwObjectConfig[1U],
    
    &Can_HwObjectConfig[2U],
    
    &Can_HwObjectConfig[3U],
    
    &Can_HwObjectConfig[4U],
    
    &Can_HwObjectConfig[5U],
    
    &Can_HwObjectConfig[6U],
    
    &Can_HwObjectConfig[7U],
    
    &Can_HwObjectConfig[8U],
    
    &Can_HwObjectConfig[9U],
    
    &Can_HwObjectConfig[10U],
    
    &Can_HwObjectConfig[11U],
    
    &Can_HwObjectConfig[12U],
    
    &Can_HwObjectConfig[13U],
    
    &Can_HwObjectConfig[14U],
    
    &Can_HwObjectConfig[15U],
    
    &Can_HwObjectConfig[16U],
    
    &Can_HwObjectConfig[17U],
    
    &Can_HwObjectConfig[18U],
    
    &Can_HwObjectConfig[19U],
    
    &Can_HwObjectConfig[20U],
    
    &Can_HwObjectConfig[21U],
    
    &Can_HwObjectConfig[22U],
    
    &Can_HwObjectConfig[23U],
    
    &Can_HwObjectConfig[24U],
    
    &Can_HwObjectConfig[25U],
    
    &Can_HwObjectConfig[26U],
    
    &Can_HwObjectConfig[27U],
    
    &Can_HwObjectConfig[28U],
    
    &Can_HwObjectConfig[29U],
    
    &Can_HwObjectConfig[30U],
    
    &Can_HwObjectConfig[31U],
    
    &Can_HwObjectConfig[32U],
    
    &Can_HwObjectConfig[33U],
    
    &Can_HwObjectConfig[34U],
    
    &Can_HwObjectConfig[35U],
    
    &Can_HwObjectConfig[36U],
    
    &Can_HwObjectConfig[37U],
    
    &Can_HwObjectConfig[38U],
    
    &Can_HwObjectConfig[39U],
    
    &Can_HwObjectConfig[40U],
    
    &Can_HwObjectConfig[41U],
    
    &Can_HwObjectConfig[42U],
    
    &Can_HwObjectConfig[43U],
    
    &Can_HwObjectConfig[44U],
    
    &Can_HwObjectConfig[45U],
    
    &Can_HwObjectConfig[46U],
    
    &Can_HwObjectConfig[47U],
    
    &Can_HwObjectConfig[48U],
    
    &Can_HwObjectConfig[49U],
    
    &Can_HwObjectConfig[50U],
    
    &Can_HwObjectConfig[51U],
    
    &Can_HwObjectConfig[52U],
    
    &Can_HwObjectConfig[53U],
    
    &Can_HwObjectConfig[54U],
    
    &Can_HwObjectConfig[55U],
    
    &Can_HwObjectConfig[56U],
    
    &Can_HwObjectConfig[57U],
    
    &Can_HwObjectConfig[58U],
    
    &Can_HwObjectConfig[59U],
    
    &Can_HwObjectConfig[60U],
    
    &Can_HwObjectConfig[61U],
    
    &Can_HwObjectConfig[62U],
    
    &Can_HwObjectConfig[63U],
    
    &Can_HwObjectConfig[64U],
    
    &Can_HwObjectConfig[65U],
    
    &Can_HwObjectConfig[66U],
    
    &Can_HwObjectConfig[67U],
    
    &Can_HwObjectConfig[68U],
    
    &Can_HwObjectConfig[69U],
    
    &Can_HwObjectConfig[70U],
    
    &Can_HwObjectConfig[71U],
    
    &Can_HwObjectConfig[72U]
    
};


#define CAN_STOP_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"


static const Can_ControllerConfigType Can_ControllerConfig[CAN_CONTROLLER_CONFIG_COUNT]=
{
        {
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
        (uint32)CAN_NONE_ECUM_WAKEUP_SOURCE_REF, 
        
        /*!< Source Wakeup Enable Status*/
        (boolean)FALSE,
        #endif
        /* Controller ID */
        (uint8)0U,
        /* Current Can interface index  */
        
        (uint8)0U,            
        /* Current Can Controller Offset */
        (uint8)6U,
        /* Can Controller active Status configure bit */
        (boolean)TRUE,
        &Can_RxFiFOConfigCtr0,
        /* Bus Off uses polling */
        (0x00000000U),      
        /* Error interrupt enable */
        (boolean)FALSE,
        
        /* Error Notification */
        NULL_PTR,
        
        /* Error FD Notification */
        NULL_PTR,
        /* Default Baudrate ID */
        (uint16)0U,
        /* Number of Can baudrate*/
        (uint16)1U,
        /* pointer to Can baudrate configure */
        Can_BaudrateConfigCtrl0,
        /* Number of Can hardware referred to current controller */
        (uint8)73U,
        /* Pointer point to Group of Hw Object that refer to Controller */
        Can_HwObjectCfgPtr0,      
        /* Pointer to hardware channel configuration */
        &Can_HwChannelConfig0,
        #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* FIFO Dma Error Notification */
        NULL_PTR,
        /* DMA is not enabled */
        NULL_PTR,
        #endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        #if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
        /* Can ecc interrupt enable */
        0,
        /* Notification */
        NULL_PTR,
        
        /* Notification */
        NULL_PTR,
        
        /* Notification */
        NULL_PTR,
        
        #endif
        FALSE,
    }
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"

static const Can_ControllerConfigType * const Can_ControllerPtr[CAN_CONTROLLER_CONFIG_COUNT]=
{
    &Can_ControllerConfig[0U]
    
};

#define CAN_STOP_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define CAN_START_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"
/*Can_CtrlOffsetToCtrlIDMap and Can_HwObjIDToCtrlIDMap  */


/**
*   @brief  The index corresponds to the actual sequence Value
*/
static const uint8 Can_CtrlOffsetToCtrlIDMap[CAN_HWNUMBER_SUPPORT]=
{        
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)0,
    
    (uint8)CAN_HWOBJ_UNMAPPED
};
/**
*   @brief  Controller ID corresponds to Hardware Object ID
*/
static const uint8 Can_HwObjIDToCtrlIDMap[CAN_HWOBJECT_CONFIG_COUNT]=
{
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U
};

#define CAN_STOP_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"


/**
*   @brief This structure is All dirver Configure  
*/

    

const Can_ConfigType Can_Config =
{
            /* Can Configure core Id */
    (uint32)0U,
    /* Can Tx First Index*/
    (Can_HwHandleType)68U,
    /*Can controller number */
    CAN_CONTROLLER_CONFIG_COUNT,
    /*  The index corresponds to the actual sequence Value*/
    Can_CtrlOffsetToCtrlIDMap,
    /*Hardware object Counter*/
    CAN_HWOBJECT_CONFIG_COUNT,
    /* Controller ID corresponds to Hardware Object ID  */
    Can_HwObjIDToCtrlIDMap,
    /* Pointer point to Can Hw Object Config */
    Can_HwObjectConfig,
    /* Pointer to Can Controller Config pointer */
    Can_ControllerPtr
};

    
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"



#define CAN_STOP_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Can_Configuration */

/** @} end of group Can_Module */
