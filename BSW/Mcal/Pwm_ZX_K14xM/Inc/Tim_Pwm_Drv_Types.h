/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv_Types.h
 * @brief     : AUTOSAR Pwm low level driver types definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef TIM_PWM_DRV_TYPES_H
#define TIM_PWM_DRV_TYPES_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Tim_Pwm_Drv
 *  @brief Pwm low level driver types definition
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "Tim_Pwm_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define TIM_PWM_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TIM_PWM_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TIM_PWM_DRV_TYPES_H_SW_PATCH_VERSION            2U

#if (TIM_PWM_DRV_TYPES_H_VENDOR_ID != TIM_PWM_DRV_CFG_H_VENDOR_ID) 
    #error "Vendor ID of Tim_Pwm_Drv_types.h and Tim_Pwm_Drv_Cfg.h are different"
#endif

#if ((TIM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_PWM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_PWM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Pwm_Drv_Types.h and Tim_Pwm_Drv_Cfg.h are different"
#endif

#if ((TIM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION != TIM_PWM_DRV_CFG_H_SW_MAJOR_VERSION) || \
     (TIM_PWM_DRV_TYPES_H_SW_MINOR_VERSION != TIM_PWM_DRV_CFG_H_SW_MINOR_VERSION) || \
     (TIM_PWM_DRV_TYPES_H_SW_PATCH_VERSION != TIM_PWM_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Pwm_Drv_Types.h and Tim_Pwm_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((TIM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (TIM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Pwm_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */


/**
 * @brief Maximum value for Tim duty cycle
 */
#define TIM_PWM_DRV_MAX_DUTY_CYCLE      (0x8000U)

/**
 * @brief Tim No Notification Edge.
 */
#define TIM_PWM_DRV_NO_EDGE               ((Tim_Pwm_Drv_EdgeInterruptType)0U)

/**
 * @brief Tim has a channel matching interrupt notification edge.
 */
#define TIM_PWM_DRV_CHF_IRQ_EDGE          ((Tim_Pwm_Drv_EdgeInterruptType)1U)

/**
 * @brief Tim has overflow interrupt notification edge.
 */
#define TIM_PWM_DRV_TOF_IRQ_EDGE          ((Tim_Pwm_Drv_EdgeInterruptType)2U)

/**
 * @brief Tim overflow interrupt notification edge closed.
 */
#define TIM_PWM_DRV_IRQ_NO_EDGE_NOTIF     ((Tim_Pwm_Drv_EdgeInterruptType)4U)

/**
 * @brief Tim has complementary channel matching interrupt notification edges.
 */
#define TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE  ((Tim_Pwm_Drv_EdgeInterruptType)8U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Tim Status Type.
 */
typedef enum
{
   TIM_PWM_DRV_STATUS_SUCCESS      = E_OK,     /*!< Generic operation success status */
   TIM_PWM_DRV_STATUS_ERROR        = E_NOT_OK, /*!< Generic operation failure status */
   TIM_PWM_DRV_STATUS_BUSY         = 0x002U,   /*!< Generic operation busy status */
   TIM_PWM_DRV_STATUS_TIMEOUT      = 0x003U,   /*!< Generic operation timeout status */
   TIM_PWM_DRV_STATUS_UNSUPPORTED  = 0x004U    /*!< Generic operation unsupported status */
} Tim_Pwm_Drv_StatusType;

/**
 * @brief Tim clock source type.
 */
typedef enum 
{
   TIM_PWM_DRV_CLK_DISABLE = 0U,               /*!< Tim Clock Source: None */
   TIM_PWM_DRV_CLK_SOURCE_SYSTEM = 1U,         /*!< Tim Clock Source: System Clock */
   TIM_PWM_DRV_CLK_SOURCE_FUNCTION = 2U,       /*!< Tim Clock Source: Functional Clock */
   TIM_PWM_DRV_CLK_SOURCE_EXTERNAL = 3U        /*!< Tim Clock Source: External Clock */
} Tim_Pwm_Drv_ClkSourceType;

/**
 * @brief Tim clock divide type.
 */
typedef enum 
{
   TIM_PWM_DRV_CLK_DIVIDE_1 = 0U,              /*!< Tim Clock Divide is 1 */
   TIM_PWM_DRV_CLK_DIVIDE_2,                   /*!< Tim Clock Divide is 2 */
   TIM_PWM_DRV_CLK_DIVIDE_4,                   /*!< Tim Clock Divide is 4 */
   TIM_PWM_DRV_CLK_DIVIDE_8,                   /*!< Tim Clock Divide is 8 */
   TIM_PWM_DRV_CLK_DIVIDE_16,                  /*!< Tim Clock Divide is 16 */
   TIM_PWM_DRV_CLK_DIVIDE_32,                  /*!< Tim Clock Divide is 32 */
   TIM_PWM_DRV_CLK_DIVIDE_64,                  /*!< Tim Clock Divide is 64 */
   TIM_PWM_DRV_CLK_DIVIDE_128                  /*!< Tim Clock Divide is 128*/
} Tim_Pwm_Drv_ClkDivideType;

/**
 * @brief Count mode type of Tim counter
 */
typedef enum 
{
   TIM_PWM_DRV_COUNTING_UP = 0U,               /*!< Tim Counter Up Counting Mode */
   TIM_PWM_DRV_COUNTING_UP_AND_DOWN            /*!< Tim Counter Up_Down Counting Mode*/
} Tim_Pwm_Drv_CountingModeType;

/**
 * @brief Tim pulse polarity type.
 */
typedef enum 
{
   TIM_PWM_DRV_LOW_PULSE_POL = 1U,             /*!< Tim Channel Pulse Polarity Low */
   TIM_PWM_DRV_HIGH_PULSE_POL                  /*!< Tim Channel Pulse Polarity High */
} Tim_Pwm_Drv_PulsePolarityType;

/**
 * @brief Tim output polarity type.
 */
typedef enum 
{
   TIM_PWM_DRV_POL_HIGH = 0U,                  /*!< Tim Channel Output Polarity High */
   TIM_PWM_DRV_POL_LOW                         /*!< Tim Channel Output Polarity Low */
} Tim_Pwm_Drv_PolarityType;

/**
 * @brief Tim Channel Status Type.
 */
typedef enum 
{
   TIM_PWM_DRV_CHANNEL_UNINIT        = 0x00U,    /*!< The channel state is before initialization */
   TIM_PWM_DRV_CHANNEL_RUNNING       = 0x01U,    /*!< The channel state is running */
   TIM_PWM_DRV_CHANNEL_IDLE          = 0x02U,    /*!< The channel state is idle */
   TIM_PWM_DRV_CHANNEL_OUTPUT_FORCED = 0x03U     /*!< The channel state is in force output channel mode*/
} Tim_Pwm_Drv_ChannelStateType;

/**
 * @brief The initial state of the channel output is configured in Tim signal
 */
typedef enum
{
   TIM_PWM_DRV_OUTPUT_STATE_LOW  = 0x00U,  /*!< The channel output is LOW */
   TIM_PWM_DRV_OUTPUT_STATE_HIGH = 0x01U   /*!< The channel output is HIGH */
} Tim_Pwm_Drv_OutputStateType;

/**
* @brief   Edge notification type
* @details This enumeration defines the type of edge transition that can generate a notification
*/
typedef enum
{
   TIM_PWM_DRV_RISING_EDGE  = 0U,   /*!< A notification will be generated on the rising edge */
   TIM_PWM_DRV_FALLING_EDGE = 1U,   /*!< A notification will be generated on the falling edge */
   TIM_PWM_DRV_BOTH_EDGES   = 2U    /*!< A notification will be generated on any state transition */
} Tim_Pwm_Drv_EdgeNotifType;

/**
* @brief   Power state type
* @details Power state currently active or set as target power state.
*/
typedef enum
{
   TIM_PWM_DRV_FULL_POWER     = 0x00U,    /*!< Tim full power mode */
   TIM_PWM_DRV_LOW_POWER      = 0x01U,    /*!< Tim low power mode */
   TIM_PWM_DRV_NODEFINE_POWER = 0x02U     /*!< Tim no define power mode */
} Tim_Pwm_Drv_PowerStateType;

/**
 * @brief Tim Channel Mode Type.
 */
typedef enum 
{
   TIM_PWM_DRV_MODE_EDGE_ALIGNED = 0x01U,                    /*!< Tim channel output Edge Aligned */
   TIM_PWM_DRV_MODE_CENTER_ALIGNED = 0x02U,                  /*!< Tim channel output Center Aligned */
   TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT = 0x03U  /*!< Tim channels output variable edge placement */
} Tim_Pwm_Drv_ChannelModeType;

/**
 * @brief Tim Dead band Time Divider
 */
typedef enum 
{
   TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_1 = 0x01U,    /*!< Divided the system clock by 1, this divided clock is used for deadtime counter*/
   TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_4 = 0x02U,    /*!< Divided the system clock by 4 */
   TIM_PWM_DRV_CLK_DEADTIME_DIVIDE_16 = 0x03U    /*!< Divided the system clock by 16 */
} Tim_Pwm_Drv_DeadTimeDivider;


/**
 * @brief Tim notification edge interrupt type.
 */
typedef uint8 Tim_Pwm_Drv_EdgeInterruptType;

/**
 * @brief Tim callback function type.
 */
typedef void (*Tim_Pwm_Drv_CallbackType)(void);

/**
 * @brief Tim Channel Pair Configuration Type.
 */
typedef struct 
{
    boolean DeadTimeEnable;         /*!< enable/disable deadtime insert */
    uint16 PhaseShiftValue;         /*!< the first edge offset of variable edge and double switch edge Tim output */
} Tim_Pwm_Drv_PairChannelCfgType;

/**
 * @brief Tim Channel Configuration Type.
 */
typedef struct
{
    uint8 ChannelId;                                 /*!< channel id of Tim module, from 0-8*/
    boolean ChIrqEn;                                 /*!< enable/disable channel interrupt */
    Tim_Pwm_Drv_CallbackType ChannelCb;              /*!< channel interrupt callback function and parameters */
    boolean ChannelOutputEnable;                     /*!< enable/disable channel output */
    Tim_Pwm_Drv_PolarityType Polarity;               /*!< the polarity of channel output 
                                                      - TIM_PWM_DRV_POL_HIGH: the output polarity of channel is high 
                                                      - TIM_PWM_DRV_POL_LOW: the output polarity of channel is low */
    Tim_Pwm_Drv_ChannelModeType ChannelMode;         /*!< the signal generated mode of channel output */
    boolean ChannelMatchTrigEnable;                  /*!< enable/disable the trigger when CV match counter value */
    boolean DmaEn;                                   /*!< enable/disable DMA transfer for this channel */
    const Tim_Pwm_Drv_PairChannelCfgType *PairCfg;   /*!< the pair configuration of channel output when in complementary mode */
} Tim_Pwm_Drv_ChannelConfigType;

/**
 * @brief Tim Instance Configuration Type.
 */
typedef struct 
{
    Tim_Pwm_Drv_ClkSourceType   ClkSrc;                  /*!< Clock Source for Tim instances 
                                                          -TIM_PWM_DRV_CLK_DISABLE: disable clock of Tim 
                                                          -TIM_PWM_DRV_CLK_SOURCE_SYSTEM: select system clock as Tim module clock source
                                                          -TIM_PWM_DRV_CLK_SOURCE_FUNCTION: select function clock as Tim module clock source
                                                          -TIM_PWM_DRV_CLK_SOURCE_EXTERNAL: select the external clock as Tim module clock source
                                                          */
    Tim_Pwm_Drv_ClkDivideType   ClkDiv;                  /*!< Divider for Tim instances 
                                                          -TIM_PWM_DRV_DIVIDE_1: the clock divide by 1
                                                          -TIM_PWM_DRV_DIVIDE_2: the clock divide by 2
                                                          -TIM_PWM_DRV_DIVIDE_4: the clock divide by 4
                                                          -TIM_PWM_DRV_DIVIDE_8: the clock divide by 8
                                                          -TIM_PWM_DRV_DIVIDE_16: the clock divide by 16
                                                          -TIM_PWM_DRV_DIVIDE_32: the clock divide by 32
                                                          -TIM_PWM_DRV_DIVIDE_64: the clock divide by 64
                                                          -TIM_PWM_DRV_DIVIDE_128: the clock divide by 128
                                                          */   
    uint16 PwmPeriod;                                    /*!< Period of the counter */          
    Tim_Pwm_Drv_CountingModeType PwmCounterMode;         /*!< Counter counting mode */
    Tim_Pwm_Drv_DeadTimeDivider DeadTimeDiv;             /*!< Select the divide value of system clock, this divided clock is used for deadtime counter */
    uint16 DeadTimeVal;                                  /*!< The number of deadtime counts used to create a offset between the output of two consecutive Tim channels used complementary modes */
    boolean InitTrigEn;                                  /*!< Enable/disable init trigger */ 
    boolean OverflowIrqEn;                               /*!< enable/dsiable counter overflow interrupt */
    Tim_Pwm_Drv_CallbackType OverflowCb;                 /*!< the overflow interrupt callback function and parameters */
} Tim_Pwm_Drv_ConfigType;

/**
 * @brief Tim Configuration Type.
 */
typedef struct
{
    const Tim_Pwm_Drv_ConfigType *InstanceCfg;                          /*!< Point to the Tim instance configuration */
    const Tim_Pwm_Drv_ChannelConfigType * const *ConfiguredChArray;     /*!< Pointer to the configured channels array for the Tim channel */
    uint8 NoOfConfiguredCh;                                             /*!< Number of the configured channels for the Tim channel */
} Tim_Pwm_Drv_UserCfgType;

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

/** @} end of group Tim_Pwm_Drv */

/** @} end of group Pwm_Module */
