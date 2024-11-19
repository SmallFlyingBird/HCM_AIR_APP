/**************************************************************************************************/
/**
 * @file      : Tmu_Drv.c
 * @brief     : Interrupt Control low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Platform_Module
 *  @{
 */

/** @defgroup Tmu_Drv
 *  @brief It provides the source code of Tmu_Drv APIS.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tmu_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define TMU_DRV_C_VENDOR_ID                   0x00B3U
#define TMU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TMU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TMU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TMU_DRV_C_SW_MAJOR_VERSION            1U
#define TMU_DRV_C_SW_MINOR_VERSION            2U
#define TMU_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Tmu_Drv.h are the same vendor */
#if (TMU_DRV_C_VENDOR_ID != TMU_DRV_H_VENDOR_ID)
    #error "Tmu_Drv.c and Tmu_Drv.h have different vendor ids"
#endif
/* Check if current file and Tmu_Drv.h are the same Autosar version */
#if ((TMU_DRV_C_AR_RELEASE_MAJOR_VERSION != TMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (TMU_DRV_C_AR_RELEASE_MINOR_VERSION != TMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (TMU_DRV_C_AR_RELEASE_REVISION_VERSION != TMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Tmu_Drv.c and Tmu_Drv.h are different"
#endif
/* Check if current file and Tmu_Drv.h are the same Software version */
#if ((TMU_DRV_C_SW_MAJOR_VERSION != TMU_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (TMU_DRV_C_SW_MINOR_VERSION != TMU_DRV_H_SW_MINOR_VERSION) ||                                 \
     (TMU_DRV_C_SW_PATCH_VERSION != TMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Tmu_Drv.c and Tmu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((TMU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (TMU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tmu_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

#define PLATFORM_START_SEC_CONST_PTR
#include "Platform_MemMap.h"
/**
 *  @brief Pointer to TMU Register address
 */
static Reg_Tmu_BfType *const Tmu_Drv_TmuRegBfPtr = (Reg_Tmu_BfType *)TMU_BASE_ADDR;
static Reg_Tmu_WType *const  Tmu_Drv_TmuRegWPtr = (Reg_Tmu_WType *)TMU_BASE_ADDR;

#define PLATFORM_STOP_SEC_CONST_PTR
#include "Platform_MemMap.h"

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

static void Tmu_Drv_SelectInput(const Tmu_Drv_InputChannelType  InputChannel,
                                const Tmu_Drv_OutputChannelType OutputChannel,
                                const boolean                   Enabled);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief      This function selects input source for TMU module.
 *
 * @param[in]  InputChannel: Input channel.
 * @param[in]  OutputChannel: Output channel.
 * @param[out] Enabled: Output enabled or not.
 *
 * @return     None.
 */
static void Tmu_Drv_SelectInput(const Tmu_Drv_InputChannelType  InputChannel,
                                const Tmu_Drv_OutputChannelType OutputChannel,
                                const boolean                   Enabled)
{

#if (STD_ON == TMU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TMU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TMU_DRV_INPUT_CHANNELS_COUNT >= (uint32)InputChannel);
    MCALLIB_DEV_ASSERT(TMU_DRV_OUTPUT_CHANNELS_COUNT >= (uint32)OutputChannel);
#endif /*(STD_ON == TMU_DRV_DEV_ERROR_DETECT) */
    if (0U != Tmu_Drv_TmuRegBfPtr->TMU_CFGn[OutputChannel].LOCK)
    {
        Tmu_Drv_TmuRegWPtr->TMU_CFGn[OutputChannel] = 0x5B000000U;
    }
    Tmu_Drv_TmuRegBfPtr->TMU_CFGn[OutputChannel].SEL = (uint32)InputChannel;
    Tmu_Drv_TmuRegBfPtr->TMU_CFGn[OutputChannel].EN = (uint32)Enabled;
    Tmu_Drv_TmuRegBfPtr->TMU_CFGn[OutputChannel].LOCK = 1U;

#if (STD_ON == TMU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief     This function initializes the configured TMU.
 *
 * @param[in] ConfigPtr: pointer to configuration structure for TMU.
 *
 * @return    None.
 */
void Tmu_Drv_Init(const Tmu_Drv_ConfigType *ConfigPtr)
{
    uint32 Index;

#if (STD_ON == TMU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == TMU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigPtr);
    MCALLIB_DEV_ASSERT(TMU_DRV_OUTPUT_CHANNELS_COUNT >= ConfigPtr->ConfigChannelCount);
#endif /*(STD_ON == TMU_DRV_DEV_ERROR_DETECT) */
    for (Index = 0U; Index < ConfigPtr->ConfigChannelCount; Index++)
    {
        Tmu_Drv_SelectInput(ConfigPtr->ChannelConfigList[Index].InputChannel,
                            ConfigPtr->ChannelConfigList[Index].OutputChannel,
                            ConfigPtr->ChannelConfigList[Index].OutputEnabled);
    }

#if (STD_ON == TMU_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif
}
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Tmu_Drv */

/** @} end of group Platform_Module */
