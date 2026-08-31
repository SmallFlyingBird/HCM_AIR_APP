/*
* @file    Adc_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Adc_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef ADC_LLD_H
#define ADC_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_LLD_VENDOR_ID                      (180)
#define ADC_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define ADC_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define ADC_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define ADC_LLD_SW_MAJOR_VERSION               (2)
#define ADC_LLD_SW_MINOR_VERSION               (3)
#define ADC_LLD_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief   adc get running group index
 * @details This function is used to get the running group index for a hwunit.
 * @param[in]  AdcHwIndex      Adc hw unit index
 * @return    uint16     The running group index
*/
extern uint16 Adc_Lld_GetRunningGroupIndex(uint8 AdcHwIndex);
/**
 * @brief Internal temperature sensor configured
 * @details This function is used to enable or disable the internal temperature sensor.
 * @param[in]   TempSensorEnable      TRUE: Enable the internal temperature sensor.
 *                                    FALSE: Disable the internal temperature sensor.
 * @return      void
 */
extern void Adc_Lld_InitTempSensor(boolean TempSensorEnable);

/**
 * @brief   Adc hw unit enable
 * @details This function is used to enable the adc hw unit.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return    void
*/
extern void Adc_Lld_HwUnitEnable(uint8 AdcHwUnit);

/**
 * @brief   Adc hw unit clock init
 * @details This function is used to init the adc hw unit clock prescaler and startup time.
 * @param[in]   HwUnitCfgPtr      Adc hw unit
 * @return      void
*/
extern void Adc_Lld_HwClockInit(const Adc_HwUnitType *HwUnitCfgPtr);

/**
 * @brief   Stop the adc conversion
 * @details This function is used to stop the ungoing adc conversion.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      void
*/
extern void Adc_Lld_StopConversion(uint8 AdcHwUnit);

/**
 * @brief Start the adc conversion
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      void
 *
*/
extern void Adc_Lld_StartConversion(uint8 AdcHwUnit);

/**
 * @brief   Disable all interrupt and set to sw trigger
 * @details This function configure the adc to sw trigger and diasble all interrupt.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      void
*/
extern void Adc_Lld_DisableIntcandHwTrigger(uint8 AdcHwUnit);

/**
 * @brief   Adc hw unit deinit
 * @details Call this function to return the adc hw unit to its uninitialized state.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      void
*/
extern void Adc_Lld_DeinitHwUnit(uint8 AdcHwUnit);

/**
 * @brief   Get the adc EOSEQ flag
 * @details This function is used to read the adc EOSEQ flag.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      boolean
*/
extern boolean Adc_Lld_ReadSeqConvEndIntFlag(uint8 AdcHwUnit);

/**
 * @brief   Clear the adc EOSEQ flag
 * @details This function is used to clear the adc EOSEQ flag.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @return      void
*/
extern void Adc_Lld_ClearSeqConvEndIntFlag(uint8 AdcHwUnit);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief  Read the adc conversion result
 * @details This function is used to read the adc conversion result from FIFO, and check the result.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @param[in]   GroupIndex      Adc group index
 * @param[out]   ResultBufPtr      Pointer to the result buffer
 * @param[in]   ChannelCount      The length of the result buffer
 * @param[in]   Resolution      The resolution of the result buffer
 * @return      boolean     TRUE: The result is in the limit range,
 *                          FALSE: The result is out of the limit range
 *
*/
extern boolean Adc_Lld_ReadConversionResults(uint8 AdcHwUnit, uint16 GroupIndex, Adc_ValueGroupType *ResultBufPtr,
        uint16 ChannelCount, Adc_ResolutionType Resolution);
#else
/**
 * @brief  Read the adc conversion result
 * @details This function is used to read the adc conversion result from FIFO.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @param[out]   ResultBufPtr      Pointer to the result buffer
 * @param[in]   ChannelCount      The length of the result buffer
 * @param[in]   Resolution      The resolution of the result buffer
 * @return      void
 *
*/
extern void Adc_Lld_ReadConversionResults(uint8 AdcHwUnit, Adc_ValueGroupType *ResultBufPtr,
        uint16 ChannelCount, Adc_ResolutionType Resolution);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

/**
 * @brief  Load the adc group configuration to hw unit
 * @details This function is used to load a adc group configuration to hw unit.
 * @param[in]   AdcHwUnit      Adc hw unit
 * @param[in]   GroupIndex      The index of the group
 * @return      void
*/
extern void Adc_Lld_LoadGroupToHwUnit(uint8 AdcHwUnit, uint16 GroupIndex);

/**
 * @brief            The interrupt ISR for ADC HW.
 * @details          This function will be called by the ADC HW ISR.
 * @param[in]        AdcHwIndex HW uinit ID of requested ADC unit.
 * @return           void
 */
extern void Adc_Lld_IrqProcess(uint8 AdcHwIndex);

/**
 * @brief            The dma transfer end notification foe ADC HW.
 * @details          This function will be called by the DMA ISR when the conversion result transfered end.
 * @param[in]        Parameter The hw uinit ID if requested ADC unit.
 * @return           void
 */
extern void Adc_Lld_DmaTransEndNotification(void *Parameter);

/**
 * @brief            The Group Index Check.
 * @details          This function used to check the group index based on the Group ID.
 * @param[in]        Group The group ID.
 * @return           uint16 The group index.
*/
extern uint16 Adc_Lld_GroupIndexCheck(Adc_GroupType Group);

/**
 * @brief            Update the queue data.
 * @details          This function used to update the queue when the group in queue[0] is convert completed.
 * @param[in]        AdcHwIndex The hw unit index.
 * @param[in]        GroupIndex The group index in queue[0].
 * @return           Std_ReturnType E_OK: The queue data is updated. E_NOT_OK: The queue data is not updated.
*/
extern Std_ReturnType Adc_Lld_QueueDataUpdata(uint8 AdcHwIndex, uint16 GroupIndex);

/**
 * @brief   Update the group status in IRQ
 * @param[in]   GroupIndex ADC group index
 * @return  void
*/
extern void Adc_Lld_GroupStatusUpdata(uint16 GroupIndex);


#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief   Set the ADC hardware unit power state
 * @param[in]   PowerState Target powerState of ADC
 * @return  Std_ReturnType
        E_OK: The power state is set successfully.
        E_NOT_OK: The power state is not set.
*/
extern Std_ReturnType Adc_Lld_SetPowerState(Adc_PowerStateType PowerState);
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif /* End of file Adc_Lld.h */

