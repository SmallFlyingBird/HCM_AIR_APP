
/*************************************************************************************/
/**
 * @file      : Dio_Cfg.h
 * @brief     : AUTOSAR Dio configuration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

/** @addtogroup DIO_CFG
*   @{
*/
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif



/** @defgroup Public_MacroDefinition
*  @{
*/
#define DIO_CFG_H_VENDOR_ID                   0x00B3U
#define DIO_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_CFG_H_SW_MAJOR_VERSION            1U
#define DIO_CFG_H_SW_MINOR_VERSION            2U
#define DIO_CFG_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((DIO_CFG_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||   \
         (DIO_CFG_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Dio_Cfg.h and Std_Types.h are different"
    #endif
#endif

/**
* @brief          Enable or Disable Development Error Detection.
*/
#define DIO_DEV_ERROR_DETECT     (STD_OFF)

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#endif 
/**
* @brief          Enable or Disable Dio module verion acquisition.
*/
#define DIO_VERSION_INFO_API   (STD_OFF)

/**
* @brief          Enable or Disable function for flipping channel.
*
*/
#define DIO_FLIP_CHANNEL_API    (STD_OFF)

/**
* @brief          Enable or Disable function for mask channel.
*
*/
#define DIO_MASKED_WRITE_PORT_API  (STD_OFF)





/**
* @brief          Number of implemented ports.
*
*/
#define DIO_PORT_NUM            ((uint16)0x5U)      

/**
* @brief          The number of partition on the port
*/
#define DIO_PORT_PARTITION_NUM   ((uint16)5U)
 
/**
* @brief          Number of channels available on the implemented ports.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
#define DIO_CHANNEL_NUM           ((uint32)159U)
#endif

/**
* @brief The number of partition on the channel.
*/
#define DIO_CHANNEL_PARTITION_NUM   ((uint16)160U)

/**
* @brief          Mask representing no available channels on a port.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NO_AVAILABLE_CHANNEL_NUM   ((Dio_PortLevelType)0x0U)
#endif


/**
* @brief          Mask representing the maximum valid offset for a channel group.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_VALID_OFFSET_MAX         ((uint8)0x1FU)
#endif


/**
* @brief          Dio driver Pre-Compile configuration switch.
*/
#define DIO_PRECOMPILE_SUPPORT





/* ========== DioConfig ========== */

/* ---------- PTA ---------- */ 

/**
* @brief          Symbolic name for the port PTA.
*
*/
#define DioConf_DioPort_PTA  ((uint8)0x00U)



/**
* @brief          Symbolic name for the channel OUT_CON_5V.
*
*/
#define  DioConf_DioChannel_OUT_CON_5V  ((uint16)0x0010U)


/**
* @brief          Symbolic name for the channel LR_Identify.
*
*/
#define  DioConf_DioChannel_LR_Identify  ((uint16)0x0006U)


/**
* @brief          Symbolic name for the channel Uart0_TX.
*
*/
#define  DioConf_DioChannel_Uart0_TX  ((uint16)0x000bU)

/* ---------- PTB ---------- */ 

/**
* @brief          Symbolic name for the port PTB.
*
*/
#define DioConf_DioPort_PTB  ((uint8)0x01U)



/**
* @brief          Symbolic name for the channel SPI_BD_CS_BOOST.
*
*/
#define  DioConf_DioChannel_SPI_BD_CS_BOOST  ((uint16)0x0025U)


/**
* @brief          Symbolic name for the channel EN_92682.
*
*/
#define  DioConf_DioChannel_EN_92682  ((uint16)0x0024U)


/**
* @brief          Symbolic name for the channel HSD_EN4.
*
*/
#define  DioConf_DioChannel_HSD_EN4  ((uint16)0x0023U)


/**
* @brief          Symbolic name for the channel HSD_EN2.
*
*/
#define  DioConf_DioChannel_HSD_EN2  ((uint16)0x0022U)


/**
* @brief          Symbolic name for the channel AD_5V_2.
*
*/
#define  DioConf_DioChannel_AD_5V_2  ((uint16)0x002aU)


/**
* @brief          Symbolic name for the channel PG_LDO1.
*
*/
#define  DioConf_DioChannel_PG_LDO1  ((uint16)0x0031U)


/**
* @brief          Symbolic name for the channel HSD1_SEL2.
*
*/
#define  DioConf_DioChannel_HSD1_SEL2  ((uint16)0x0020U)

/* ---------- PTC ---------- */ 

/**
* @brief          Symbolic name for the port PTC.
*
*/
#define DioConf_DioPort_PTC  ((uint8)0x02U)



/**
* @brief          Symbolic name for the channel AFS_DIR.
*
*/
#define  DioConf_DioChannel_AFS_DIR  ((uint16)0x004dU)


/**
* @brief          Symbolic name for the channel CS_AFS.
*
*/
#define  DioConf_DioChannel_CS_AFS  ((uint16)0x004cU)


/**
* @brief          Symbolic name for the channel HSD1_SEL1.
*
*/
#define  DioConf_DioChannel_HSD1_SEL1  ((uint16)0x0048U)


/**
* @brief          Symbolic name for the channel HSD2_SEL2.
*
*/
#define  DioConf_DioChannel_HSD2_SEL2  ((uint16)0x004aU)


/**
* @brief          Symbolic name for the channel HSD2_SEL1.
*
*/
#define  DioConf_DioChannel_HSD2_SEL1  ((uint16)0x004bU)

/* ---------- PTD ---------- */ 

/**
* @brief          Symbolic name for the port PTD.
*
*/
#define DioConf_DioPort_PTD  ((uint8)0x03U)



/**
* @brief          Symbolic name for the channel SBC_STB.
*
*/
#define  DioConf_DioChannel_SBC_STB  ((uint16)0x0060U)


/**
* @brief          Symbolic name for the channel SPI_BD_CS3.
*
*/
#define  DioConf_DioChannel_SPI_BD_CS3  ((uint16)0x0071U)


/**
* @brief          Symbolic name for the channel SPI_BD_CS2.
*
*/
#define  DioConf_DioChannel_SPI_BD_CS2  ((uint16)0x006fU)


/**
* @brief          Symbolic name for the channel ALS_DIR.
*
*/
#define  DioConf_DioChannel_ALS_DIR  ((uint16)0x006eU)


/**
* @brief          Symbolic name for the channel MotorOut_Con_ALS.
*
*/
#define  DioConf_DioChannel_MotorOut_Con_ALS  ((uint16)0x0066U)


/**
* @brief          Symbolic name for the channel MotorOut_Con_AFS.
*
*/
#define  DioConf_DioChannel_MotorOut_Con_AFS  ((uint16)0x0065U)


/**
* @brief          Symbolic name for the channel MOTOR_ERR.
*
*/
#define  DioConf_DioChannel_MOTOR_ERR  ((uint16)0x006cU)


/**
* @brief          Symbolic name for the channel WD_Feed.
*
*/
#define  DioConf_DioChannel_WD_Feed  ((uint16)0x0062U)


/**
* @brief          Symbolic name for the channel HSD_EN3.
*
*/
#define  DioConf_DioChannel_HSD_EN3  ((uint16)0x0064U)


/**
* @brief          Symbolic name for the channel CS_ALS.
*
*/
#define  DioConf_DioChannel_CS_ALS  ((uint16)0x0067U)


/**
* @brief          Symbolic name for the channel GPIO_PTD_16.
*
*/
#define  DioConf_DioChannel_GPIO_PTD_16  ((uint16)0x0070U)

/* ---------- PTE ---------- */ 

/**
* @brief          Symbolic name for the port PTE.
*
*/
#define DioConf_DioPort_PTE  ((uint8)0x04U)



/**
* @brief          Symbolic name for the channel SBC_EN.
*
*/
#define  DioConf_DioChannel_SBC_EN  ((uint16)0x0090U)


/**
* @brief          Symbolic name for the channel ERR_N.
*
*/
#define  DioConf_DioChannel_ERR_N  ((uint16)0x008fU)


/**
* @brief          Symbolic name for the channel CAN_TX_BODY.
*
*/
#define  DioConf_DioChannel_CAN_TX_BODY  ((uint16)0x008dU)


/**
* @brief          Symbolic name for the channel LIMP_CON.
*
*/
#define  DioConf_DioChannel_LIMP_CON  ((uint16)0x008eU)


/**
* @brief          Symbolic name for the channel SPI_BD_CS1.
*
*/
#define  DioConf_DioChannel_SPI_BD_CS1  ((uint16)0x0083U)


/**
* @brief          Symbolic name for the channel SPI_BD_CS4.
*
*/
#define  DioConf_DioChannel_SPI_BD_CS4  ((uint16)0x008cU)


/**
* @brief          Symbolic name for the channel Fault_92682.
*
*/
#define  DioConf_DioChannel_Fault_92682  ((uint16)0x0089U)


/**
* @brief          Symbolic name for the channel HSD_EN1.
*
*/
#define  DioConf_DioChannel_HSD_EN1  ((uint16)0x0087U)

/** @} end of group Public_MacroDefinition */



/** @defgroup Global_VariableDefinition
 *  @{
 */

/**
* @brief Array: the available pins in each port.
*/
#define DIO_CONFIG_AVAILABLE_PIN \
extern const Dio_PortLevelType Dio_AvailablePinsForWrite[DIO_PORT_NUM];\
extern const Dio_PortLevelType Dio_AvailablePinsForRead[DIO_PORT_NUM];

#define DIO_CONFIG_GROUP_LIST
#define DIO_CONFIG_GROUP_PARTITION
/** @} end of group Global_VariableDefinition */



#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} end of group DIO_CFG */

