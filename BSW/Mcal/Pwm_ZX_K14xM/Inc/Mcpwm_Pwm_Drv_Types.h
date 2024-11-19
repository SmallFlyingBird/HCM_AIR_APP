/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv_Types.h
 * @brief     : AUTOSAR Pwm low level driver types definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef MCPWM_PWM_DRV_TYPES_H
#define MCPWM_PWM_DRV_TYPES_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Mcpwm_Pwm_Drv
 *  @brief Pwm low level driver types definition
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "Mcpwm_Pwm_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define MCPWM_PWM_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_TYPES_H_SW_PATCH_VERSION            2U

#if (MCPWM_PWM_DRV_TYPES_H_VENDOR_ID != MCPWM_PWM_DRV_CFG_H_VENDOR_ID) 
    #error "Vendor ID of Mcpwm_Pwm_Drv_types.h and Mcpwm_Pwm_Drv_Cfg.h are different"
#endif

#if ((MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCPWM_PWM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCPWM_PWM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcpwm_Pwm_Drv_Types.h and Mcpwm_Pwm_Drv_Cfg.h are different"
#endif

#if ((MCPWM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION != MCPWM_PWM_DRV_CFG_H_SW_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_TYPES_H_SW_MINOR_VERSION != MCPWM_PWM_DRV_CFG_H_SW_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_TYPES_H_SW_PATCH_VERSION != MCPWM_PWM_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mcpwm_Pwm_Drv_Types.h and Mcpwm_Pwm_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Mcpwm_Pwm_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */


/**
 * @brief Maximum value for Mcpwm duty cycle
 */
#define MCPWM_PWM_DRV_MAX_DUTY_CYCLE      (0x8000U)

/**
 * @brief Mcpwm No Notification Edge.
 */
#define MCPWM_PWM_DRV_NO_EDGE               ((Mcpwm_Pwm_Drv_EdgeInterruptType)0U)

/**
 * @brief Mcpwm has a channel matching interrupt notification edge.
 */
#define MCPWM_PWM_DRV_CHF_IRQ_EDGE          ((Mcpwm_Pwm_Drv_EdgeInterruptType)1U)

/**
 * @brief Mcpwm has overflow interrupt notification edge.
 */
#define MCPWM_PWM_DRV_TOF_IRQ_EDGE          ((Mcpwm_Pwm_Drv_EdgeInterruptType)2U)

/**
 * @brief Mcpwm overflow interrupt notification edge closed.
 */
#define MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF     ((Mcpwm_Pwm_Drv_EdgeInterruptType)4U)

/**
 * @brief Mcpwm has complementary channel matching interrupt notification edges.
 */
#define MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE  ((Mcpwm_Pwm_Drv_EdgeInterruptType)8U)

/** @} end of Public_MacroDefinition */


/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Mcpwm Status Type.
 */
typedef enum
{
   MCPWM_PWM_DRV_STATUS_SUCCESS      = E_OK,     /*!< Generic operation success status */
   MCPWM_PWM_DRV_STATUS_ERROR        = E_NOT_OK, /*!< Generic operation failure status */
   MCPWM_PWM_DRV_STATUS_BUSY         = 0x002U,   /*!< Generic operation busy status */
   MCPWM_PWM_DRV_STATUS_TIMEOUT      = 0x003U,   /*!< Generic operation timeout status */
   MCPWM_PWM_DRV_STATUS_UNSUPPORTED  = 0x004U    /*!< Generic operation unsupported status */
} Mcpwm_Pwm_Drv_StatusType;

/**
 * @brief Mcpwm clock source type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_CLK_DISABLE = 0U,               /*!< Mcpwm Clock Source: None */
   MCPWM_PWM_DRV_CLK_SOURCE_SYSTEM = 1U,         /*!< Mcpwm Clock Source: System Clock */
   MCPWM_PWM_DRV_CLK_SOURCE_FUNCTION = 2U,       /*!< Mcpwm Clock Source: Functional Clock */
   MCPWM_PWM_DRV_CLK_SOURCE_EXTERNAL = 3U        /*!< Mcpwm Clock Source: External Clock */
} Mcpwm_Pwm_Drv_ClkSourceType;

/**
 * @brief Mcpwm clock divide type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_CLK_DIVIDE_1 = 0U,              /*!< Mcpwm Clock Divide is 1 */
   MCPWM_PWM_DRV_CLK_DIVIDE_2,                   /*!< Mcpwm Clock Divide is 2 */
   MCPWM_PWM_DRV_CLK_DIVIDE_4,                   /*!< Mcpwm Clock Divide is 4 */
   MCPWM_PWM_DRV_CLK_DIVIDE_8,                   /*!< Mcpwm Clock Divide is 8 */
   MCPWM_PWM_DRV_CLK_DIVIDE_16,                  /*!< Mcpwm Clock Divide is 16 */
   MCPWM_PWM_DRV_CLK_DIVIDE_32,                  /*!< Mcpwm Clock Divide is 32 */
   MCPWM_PWM_DRV_CLK_DIVIDE_64,                  /*!< Mcpwm Clock Divide is 64 */
   MCPWM_PWM_DRV_CLK_DIVIDE_128                  /*!< Mcpwm Clock Divide is 128*/
} Mcpwm_Pwm_Drv_ClkDivideType;

/**
 * @brief Count mode type of Mcpwm counter
 */
typedef enum 
{
   MCPWM_PWM_DRV_COUNTING_UP = 0U,               /*!< Mcpwm Counter Up Counting Mode */
   MCPWM_PWM_DRV_COUNTING_UP_AND_DOWN            /*!< Mcpwm Counter Up_Down Counting Mode*/
} Mcpwm_Pwm_Drv_CountingModeType;

/**
 * @brief Mcpwm pulse polarity type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_LOW_PULSE_POL = 0U,             /*!< Mcpwm Channel Pulse Polarity Low */
   MCPWM_PWM_DRV_HIGH_PULSE_POL                  /*!< Mcpwm Channel Pulse Polarity High */
} Mcpwm_Pwm_Drv_PulsePolarityType;

/**
 * @brief Mcpwm output polarity type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_POL_HIGH = 0U,                  /*!< Mcpwm Channel Output Polarity High */
   MCPWM_PWM_DRV_POL_LOW                         /*!< Mcpwm Channel Output Polarity Low */
} Mcpwm_Pwm_Drv_PolarityType;

/**
 * @brief Mcpwm symmetric type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_SYMMETRIC = 0U,                 /*!< Mcpwm Complementary Output Symmetric Mode */
   MCPWM_PWM_DRV_ASYMMETRIC                      /*!< Mcpwm Complementary Output Asymmetric Mode */
} Mcpwm_Pwm_Drv_AsymType;

/**
 * @brief Mcpwm Channel Status Type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_CHANNEL_UNINIT        = 0x00U,    /*!< The channel state is before initialization */
   MCPWM_PWM_DRV_CHANNEL_RUNNING       = 0x01U,    /*!< The channel state is running */
   MCPWM_PWM_DRV_CHANNEL_IDLE          = 0x02U,    /*!< The channel state is idle */
   MCPWM_PWM_DRV_CHANNEL_OUTPUT_FORCED = 0x03U     /*!< The channel state is in force output channel mode*/
} Mcpwm_Pwm_Drv_ChannelStateType;

/**
 * @brief The initial state of the channel output is configured in Mcpwm signal.
 */
typedef enum
{
   MCPWM_PWM_DRV_OUTPUT_STATE_LOW  = 0x00U,  /*!< The channel output is LOW */
   MCPWM_PWM_DRV_OUTPUT_STATE_HIGH = 0x01U   /*!< The channel output is HIGH */
} Mcpwm_Pwm_Drv_OutputStateType;

/**
* @brief   Edge notification type
* @details This enumeration defines the type of edge transition that can generate a notification
*/
typedef enum
{  
   MCPWM_PWM_DRV_RISING_EDGE  = 0U, /*!< A notification will be generated on the rising edge */  
   MCPWM_PWM_DRV_FALLING_EDGE = 1U, /*!< A notification will be generated on the falling edge */   
   MCPWM_PWM_DRV_BOTH_EDGES   = 2U  /*!< A notification will be generated on any state transition */
} Mcpwm_Pwm_Drv_EdgeNotifType;

/**
* @brief   Power state type
* @details Power state currently active or set as target power state.
*/
typedef enum
{  
   MCPWM_PWM_DRV_FULL_POWER     = 0x00U,   /*!< Mcpwm full power mode */  
   MCPWM_PWM_DRV_LOW_POWER      = 0x01U,   /*!< Mcpwm low power mode */ 
   MCPWM_PWM_DRV_NODEFINE_POWER = 0x02U    /*!< Mcpwm no define power mode */
} Mcpwm_Pwm_Drv_PowerStateType;

/**
 * @brief Mcpwm Channel Mode Type.
 */
typedef enum 
{
   MCPWM_PWM_DRV_MODE_EDGE_ALIGNED = 0x01,                    /*!< Mcpwm channel output Edge Aligned */
   MCPWM_PWM_DRV_MODE_CENTER_ALIGNED = 0x02,                  /*!< Mcpwm channel output Center Aligned */
   MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED = 0x03,            /*!< Mcpwm channels output Combine Edge Aligned */
   MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED = 0x04,      /*!< Mcpwm channels output Combine Symmetric Center Aligned */
   MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT = 0x06  /*!< Mcpwm channels output variable edge placement */  
} Mcpwm_Pwm_Drv_ChannelModeType;

/**
 * @brief Mcpwm notification edge interrupt type.
 */
typedef uint8 Mcpwm_Pwm_Drv_EdgeInterruptType;

/**
 * @brief Mcpwm callback function type.
 */
typedef void (*Mcpwm_Pwm_Drv_CallbackType)(void);

/**
 * @brief Mcpwm Channel Pair Configuration Type.
 */
typedef struct 
{
   boolean DeadTimeEnable;         /*!< enable/disable deadtime insert */
   uint16 PhaseShiftValue;         /*!< the first edge offset of variable edge and double switch edge Mcpwm output */
} Mcpwm_Pwm_Drv_PairChannelCfgType;

/**
 * @brief Mcpwm Channel Configuration Type.
 */
typedef struct
{
    uint8 ChannelId;                                  /*!< channel id of MCPWM module, from 0-8*/
    boolean ChIrqEn;                                  /*!< enable/disable channel interrupt */
    Mcpwm_Pwm_Drv_CallbackType ChannelCb;             /*!< channel interrupt callback function and parameters */
    boolean ChannelOutputEnable;                      /*!< enable/disable channel output */
    Mcpwm_Pwm_Drv_PolarityType Polarity;              /*!< the polarity of channel output 
                                                       - MCPWM_PWM_DRV_POL_HIGH: the output polarity of channel is high 
                                                       - MCPWM_PWM_DRV_POL_LOW: the output polarity of channel is low */
    Mcpwm_Pwm_Drv_ChannelModeType ChannelMode;        /*!< the signal generated mode of channel output */
    uint8 ChannelDither;                              /*!< the inserted channel dither of Mcpwm output, 5 bits width */
    boolean ChannelMatchTrigEnable;                   /*!< enable/disable the trigger when CV match counter value */
    boolean DmaEn;                                    /*!< enable/disable DMA transfer for this channel */
    const Mcpwm_Pwm_Drv_PairChannelCfgType *PairCfg;  /*!< the pair configuration of channel output when in complementary mode */
} Mcpwm_Pwm_Drv_ChannelConfigType;

/**
 * @brief Mcpwm Counter Configuration Type.
 */
typedef struct 
{
    uint8 CntId;                                    /*!< Mcpwm counter id*/
    uint16 PwmPeriod;                               /*!< Period of the counter */          
    uint16 PwmPeriodDither;                         /*!< the Mcpwm period dither value inserted, 5 bits width */
    uint16 DeadTimeVal;                             /*!< the Mcpwm deadtime value inserted, 12 bits width */
    boolean OverflowIrqEn;                          /*!< enable/disable counter overflow interrupt */
    Mcpwm_Pwm_Drv_CallbackType OverflowCb;          /*!< the overflow interrupt callback function and parameters */
} Mcpwm_Pwm_Drv_CounterType;

/**
 * @brief Mcpwm Instance Configuration Type.
 */
typedef struct 
{
    Mcpwm_Pwm_Drv_ClkSourceType ClkSrc;                       /*!< Clock Source for Mcpwm instances 
                                                               -MCPWM_PWM_DRV_CLK_DISABLE: disable clock of Mcpwm 
                                                               -MCPWM_PWM_DRV_CLK_SOURCE_SYSTEM: select system clock as Mcpwm module clock source
                                                               -MCPWM_PWM_DRV_CLK_SOURCE_FUNCTION: select function clock as Mcpwm module clock source
                                                               -MCPWM_PWM_DRV_CLK_SOURCE_EXTERNAL: select the external clock as Mcpwm module clock source */
    Mcpwm_Pwm_Drv_ClkDivideType ClkDiv;                       /*!< Divider for Mcpwm instances 
                                                               -MCPWM_PWM_DRV_DIVIDE_1: the clock divide by 1
                                                               -MCPWM_PWM_DRV_DIVIDE_2: the clock divide by 2
                                                               -MCPWM_PWM_DRV_DIVIDE_4: the clock divide by 4
                                                               -MCPWM_PWM_DRV_DIVIDE_8: the clock divide by 8
                                                               -MCPWM_PWM_DRV_DIVIDE_16: the clock divide by 16
                                                               -MCPWM_PWM_DRV_DIVIDE_32: the clock divide by 32
                                                               -MCPWM_PWM_DRV_DIVIDE_64: the clock divide by 64
                                                               -MCPWM_PWM_DRV_DIVIDE_128: the clock divide by 128 */
    boolean GlobalCntEn;                                      /*!< Selected the global counter/individual counters of Mcpwm module*/
    boolean InitTrigEn;                                       /*!< Enable/disable init trigger */ 
    uint8 CounterNum;                                         /*!< The configured counter number */
    const Mcpwm_Pwm_Drv_CounterType * const *CounterConfig;   /*!< Configurations for Mcpwm counters */
} Mcpwm_Pwm_Drv_ConfigType;

/**
 * @brief Mcpwm Configuration Type.
 */
typedef struct
{
    const Mcpwm_Pwm_Drv_ConfigType *InstanceCfg;                          /*!< Point to the Mcpwm instance configuration */
    const Mcpwm_Pwm_Drv_ChannelConfigType * const *ConfiguredChArray;     /*!< Pointer to the configured channels array for the Mcpwm channel */
    uint8 NoOfConfiguredCh;                                               /*!< Number of the configured channels for the Mcpwm channel */
} Mcpwm_Pwm_Drv_UserCfgType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */


/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif

/** @} end of group Mcpwm_Pwm_Drv */

/** @} end of group Pwm_Module */
