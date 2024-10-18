/**************************************************************************************************/
/**
 * @file      : Seru_Drv.c
 * @brief     : Seru driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Seru_Drv
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Seru_Drv.h"
#include "Meh_Externals.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SERU_DRV_C_VENDOR_ID                   0x00B3U
#define SERU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_C_SW_MAJOR_VERSION            1U
#define SERU_DRV_C_SW_MINOR_VERSION            1U
#define SERU_DRV_C_SW_PATCH_VERSION            0U
/**
 *  @brief Check if current file and Seru_Drv header file are of the same vendor
 */
#if (SERU_DRV_C_VENDOR_ID != SERU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv header file are of the same Autosar version
 */
#if ((SERU_DRV_C_AR_RELEASE_MAJOR_VERSION != SERU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SERU_DRV_C_AR_RELEASE_MINOR_VERSION != SERU_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SERU_DRV_C_AR_RELEASE_REVISION_VERSION != SERU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Seru_Drv.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv header file are of the same SW version
 */
#if ((SERU_DRV_C_SW_MAJOR_VERSION != SERU_DRV_H_SW_MAJOR_VERSION) ||                               \
     (SERU_DRV_C_SW_MINOR_VERSION != SERU_DRV_H_SW_MINOR_VERSION) ||                               \
     (SERU_DRV_C_SW_PATCH_VERSION != SERU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv.c and Seru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Externals.h are of the same vendor
 */
#if (SERU_DRV_C_VENDOR_ID != MEH_EXTERNALS_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv.c and Meh_Externals.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Externals.h are of the same Autosar version
 */
#if ((SERU_DRV_C_AR_RELEASE_MAJOR_VERSION != MEH_EXTERNALS_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SERU_DRV_C_AR_RELEASE_MINOR_VERSION != MEH_EXTERNALS_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SERU_DRV_C_AR_RELEASE_REVISION_VERSION != MEH_EXTERNALS_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Seru_Drv.c and Meh_Externals.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Externals.h are of the same SW version
 */
#if ((SERU_DRV_C_SW_MAJOR_VERSION != MEH_EXTERNALS_H_SW_MAJOR_VERSION) ||                               \
     (SERU_DRV_C_SW_MINOR_VERSION != MEH_EXTERNALS_H_SW_MINOR_VERSION) ||                               \
     (SERU_DRV_C_SW_PATCH_VERSION != MEH_EXTERNALS_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv.c and Meh_Externals.hare different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Device_Regs.h and Seru_Drv.c are of the same AUTOSAR version */
    #if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != SERU_DRV_C_AR_RELEASE_MAJOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != SERU_DRV_C_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Device_Regs.h and Seru_Drv.c are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define SERU_DRV_CHANNEL_ERROR_FLAG_MASK     (0x103U)

#define SERU_DRV_MAX_CHANNEL     (17U)
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define MEH_START_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.*/
static Reg_Seru_WType  *Seru_Drv_SeruRegWPtr = (Reg_Seru_WType *)(SERU_BASE_ADDR);
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.*/
static Reg_Seru_BfType *Seru_Drv_SeruRegBfPtr = (Reg_Seru_BfType *)(SERU_BASE_ADDR);

#define MEH_STOP_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

#define MEH_START_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"
#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
static Seru_Drv_ChannelErrorCallBackFunType *Seru_Drv_ChannelCallBackPtr =
    MEH_SERU_CHANNEL_ERRORNOTIFICATIONPTR;
#endif
#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
static Seru_Drv_ParityErrCallBackFunType *Seru_Drv_ParityErrorCallbackPtr =
    MEH_SERU_PARITY_ERRORNOTIFICATIONPTR;
#endif
#define MEH_STOP_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

static void Seru_Drv_InitChannel(const Seru_Drv_ChannelConfigType *ChannelConfig);
static void Seru_Drv_EnterMode(const Seru_Drv_ModeType SeruMode);
#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
static void Seru_Drv_ClearParityErrorFlag(void);
#endif
#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
static uint32 Seru_Drv_GetChannelErrFlag(const uint32 ChNo);
static void Seru_Drv_ClearChannelErrFlag(const uint32 ChNo);
#endif

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

/**
 * @brief        This function can set SERU to config mode or normal mode
 *
 * @param[in]    SeruMode: Select SERU mode
 *                       - SERU_DRV_CONFIG_MODE : SERU is in config mode.
 *                       - SERU_DRV_NORMAL_MODE : SERU is in normal mode.
 *
 * @return       None.
 * 
 */
static void Seru_Drv_EnterMode(const Seru_Drv_ModeType SeruMode)
{
    if (SERU_DRV_CONFIG_MODE == SeruMode)
    {
        Seru_Drv_SeruRegWPtr->SERU_CFG_KEY = SERU_DRV_CONFIG_KEY;
    }
    else if (SERU_DRV_NORMAL_MODE == SeruMode)
    {
        Seru_Drv_SeruRegWPtr->SERU_CFG_KEY = SERU_DRV_NORMAL_KEY;
    }
    else
    {
        /*No action*/
    }
}

/**
 * @brief        Init channel configuration through this function.
 *
 * @param[in]    ChannelConfig: points to the struct that stores the parameters.
 *
 * @return       none
 * 
 */
static void Seru_Drv_InitChannel(const Seru_Drv_ChannelConfigType *ChannelConfig)
{
#if (SERU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SERU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SERU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(ChannelConfig != NULL_PTR);
    MCALLIB_DEV_ASSERT(ChannelConfig->ChannelNo <= SERU_DRV_CPU_DEBUG_HALT);
#endif /* (SERU_DRV_DEV_ERROR_DETECT == STD_ON) */

    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_EOUT_CFG =
        (uint32)(ChannelConfig->EoutEnable);
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_INT_TYP =
        (uint32)(ChannelConfig->IntType);
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_INT_CFG =
        (uint32)(ChannelConfig->IntEnable);
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_RESET_TYP =
        (uint32)(ChannelConfig->ResetType);
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_RESET_DLY =
        (uint32)(ChannelConfig->ResetDelay);
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_RESET_CFG =
        (uint32)(ChannelConfig->ResetEnable);
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChannelConfig->ChannelNo].CH_EN =
        (uint32)(ChannelConfig->ChannelEnable);

#if (SERU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SERU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief        This function can clear register parity error flag.
 *
 * @param[in]    None.
 *
 * @return       None.
 * 
 */
static void Seru_Drv_ClearParityErrorFlag(void)
{
    Seru_Drv_SeruRegBfPtr->SERU_INTF.S_CRPAR_ERR = 0x1U;
}
#endif

#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      Read channel error flag.
 *
 * @param[in]  ChNo. Channel number
 *
 * @return     Channel error flag.
 * 
 */
static uint32 Seru_Drv_GetChannelErrFlag(const uint32 ChNo)
{
    return Seru_Drv_SeruRegWPtr->SERU_CFG_CHn[ChNo] & SERU_DRV_CHANNEL_ERROR_FLAG_MASK;
}

/**
 * @brief      This function can clear channel error flag
 *
 * @param[in]  ChNo. Channel number
 *
 * @return     None.
 * 
 */
static void Seru_Drv_ClearChannelErrFlag(const uint32 ChNo)
{
    Seru_Drv_SeruRegBfPtr->SERU_CFG_CHn[ChNo].CH_FLAG = 1U;
}
#endif

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

/**
 * @brief      Init SERU CSR and channel register.
 *
 * @param[in]  SeruConfig: points to the struct that stores the parameters.
 *
 * @return     none
 * 
 */
void Seru_Drv_Init(const Seru_Drv_ConfigType *SeruConfig)
{
    uint32 Index = 0U;

#if (SERU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SERU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SERU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(SeruConfig != NULL_PTR);
#endif /* (SERU_DRV_DEV_ERROR_DETECT == STD_ON) */
    Seru_Drv_EnterMode(SERU_DRV_CONFIG_MODE);

    Seru_Drv_SeruRegBfPtr->SERU_CSR.EOUT_PS = (uint32)(SeruConfig->PolaritySel);
    Seru_Drv_SeruRegBfPtr->SERU_CSR.FFI_EN = (uint32)(SeruConfig->FaultInjectEnable);
    Seru_Drv_SeruRegBfPtr->SERU_CSR.CRPAR_INT_EN = (uint32)(SeruConfig->ParityErrorInterruptEnable);
    Seru_Drv_SeruRegBfPtr->SERU_CSR.EOUT0_IO_EN = (uint32)(SeruConfig->Eout0Mode);
    Seru_Drv_SeruRegBfPtr->SERU_CSR.EOUT1_IO_EN = (uint32)(SeruConfig->Eout1Mode);

    for (Index = 0; Index < SeruConfig->SeruChannelUserUsedNum; Index++)
    {
        Seru_Drv_InitChannel(&(SeruConfig->SeruChannelConfigPtr[Index]));
    }
    Seru_Drv_EnterMode(SERU_DRV_NORMAL_MODE);

#if (SERU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SERU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief        This function will De-Initialize SERU Module.
 *
 * @param[in]    None.
 *
 * @return       None.
 * 
 */
void Seru_Drv_DeInit(void)
{
    uint32 Index;
    
    Seru_Drv_EnterMode(SERU_DRV_CONFIG_MODE);

    Seru_Drv_SeruRegWPtr->SERU_CSR = 0U;

    for (Index = 0; Index < SERU_DRV_MAX_CHANNEL; Index++)
    {
        Seru_Drv_SeruRegWPtr->SERU_CFG_CHn[Index] = 0U;
    }
    Seru_Drv_EnterMode(SERU_DRV_NORMAL_MODE);
}

#if (SERU_DRV_PARITY_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU Parity Error interrupt handler.
 *
 * @param[in]  none
 *
 * @return none
 * 
 */
void Seru_Drv_ParityIrqHandler(void)
{
    /* clear parity error interrupt status */
    Seru_Drv_ClearParityErrorFlag();

    if (Seru_Drv_ParityErrorCallbackPtr != NULL_PTR)
    {
        Seru_Drv_ParityErrorCallbackPtr();
    }
}
#endif

#if (SERU_DRV_CHANNEL_ERROR_ISR_ENABLED == STD_ON)
/**
 * @brief      SERU channel Error interrupt handler
 *
 * @param[in]  none
 *
 * @return none
 * 
 */
void Seru_Drv_IrqHandler(void)
{
    uint32 ChannelStatus = 0U;
    uint32 ChNo = 0U;

    if (FALSE == Mstp_SeruSelfTestCallbackFunction())
    {
        /*Implement for normal Seru interrupt*/
        for (ChNo = 0U; ChNo <= (uint32)SERU_DRV_CPU_DEBUG_HALT; ChNo++)
        {
            if(((uint32)SERU_DRV_RESERVED == ChNo) || ((uint32)SERU_DRV_RESERVED1 == ChNo))
            {
                continue;
            }
            ChannelStatus = Seru_Drv_GetChannelErrFlag(ChNo);

            if (SERU_DRV_CHANNEL_ERROR_FLAG_MASK == ChannelStatus)
            {
                if (Seru_Drv_ChannelCallBackPtr != NULL_PTR)
                {
                    Seru_Drv_ChannelCallBackPtr(ChNo);
                }
                /* Clear channel interrupt status */
                Seru_Drv_ClearChannelErrFlag(ChNo);
            }
        }
    }
}
#endif
/** @} end of group Public_FunctionDefinition */
#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} end of group Seru_Drv */

/** @} end of group Meh_Module */
