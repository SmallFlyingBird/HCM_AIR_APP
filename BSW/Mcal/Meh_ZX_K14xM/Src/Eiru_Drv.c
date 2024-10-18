/**************************************************************************************************/
/**
 * @file      : Eiru_Drv.c
 * @brief     : Eiru driver source file
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

/** @defgroup Meh_EiruDrv
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eiru_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define EIRU_DRV_C_VENDOR_ID                   0x00B3U
#define EIRU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define EIRU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define EIRU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define EIRU_DRV_C_SW_MAJOR_VERSION            1U
#define EIRU_DRV_C_SW_MINOR_VERSION            1U
#define EIRU_DRV_C_SW_PATCH_VERSION            0U
/**
 *  @brief Check if current file and Meh Eiru driver header file are of the same vendor
 */
#if (EIRU_DRV_C_VENDOR_ID != EIRU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Eiru_Drv.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Meh Eiru driver header file are of the same Autosar version
 */
#if ((EIRU_DRV_C_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (EIRU_DRV_C_AR_RELEASE_MINOR_VERSION != EIRU_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (EIRU_DRV_C_AR_RELEASE_REVISION_VERSION != EIRU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Eiru_Drv.c and Eiru_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Meh Eiru driver header file are of the same SW version
 */
#if ((EIRU_DRV_C_SW_MAJOR_VERSION != EIRU_DRV_H_SW_MAJOR_VERSION) ||                               \
     (EIRU_DRV_C_SW_MINOR_VERSION != EIRU_DRV_H_SW_MINOR_VERSION) ||                               \
     (EIRU_DRV_C_SW_PATCH_VERSION != EIRU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Eiru_Drv.c and Eiru_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Device_Regs.h and Eiru_Drv.c are of the same AUTOSAR version */
    #if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_C_AR_RELEASE_MAJOR_VERSION) ||        \
         (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != EIRU_DRV_C_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Device_Regs.h and Eiru_Drv.c are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define MEH_START_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.*/
static Reg_Eiru_WType  *Eiru_Drv_EiruRegWPtr = (Reg_Eiru_WType *)(EIRU_BASE_ADDR);
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.*/
static Reg_Eiru_BfType *Eiru_Drv_EiruRegBfPtr = (Reg_Eiru_BfType *)(EIRU_BASE_ADDR);

#define MEH_STOP_SEC_VAR_INIT_PTR
#include "Meh_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define MEH_START_SEC_CODE
#include "Meh_MemMap.h"

/**
 * @brief      Initialize Eiru Module.
 *
 * @param[in]  EiruConfigPtr: points to the struct that stores the parameters.
 *
 * @return     none
 * 
 */
void Eiru_Drv_Init(const Eiru_Drv_SramEccConfigType *EiruConfigPtr)
{
#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(NULL_PTR != EiruConfigPtr);
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

    if (0x0U != Eiru_Drv_EiruRegBfPtr->EIRU_CR.LOCK)
    {
        Eiru_Drv_EiruRegWPtr->EIRU_CR = 0x5C000000U;
    }

    Eiru_Drv_EiruRegBfPtr->EIRU_CR.SRAM0_EEI_EN = (uint32)EiruConfigPtr->SramLEccErrorInjectEnable;
    Eiru_Drv_EiruRegBfPtr->EIRU_CR.SRAM0_ESB_DIS = (uint32)EiruConfigPtr->SramLSingleBitDisable;
    Eiru_Drv_EiruRegBfPtr->EIRU_CR.SRAM0_EMB_DIS = (uint32)EiruConfigPtr->SramLMultiBitDisable;

    Eiru_Drv_EiruRegBfPtr->EIRU_CR.SRAM1_EEI_EN = (uint32)EiruConfigPtr->SramUEccErrorInjectEnable;
    Eiru_Drv_EiruRegBfPtr->EIRU_CR.SRAM1_ESB_DIS = (uint32)EiruConfigPtr->SramUSingleBitDisable;
    Eiru_Drv_EiruRegBfPtr->EIRU_CR.SRAM1_EMB_DIS = (uint32)EiruConfigPtr->SramUMultiBitDisable;

    Eiru_Drv_EiruRegBfPtr->EIRU_CR.LOCK = 1U;
    
#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief      De-Initialize Eiru Module.
 *
 * @param[in]  none.
 *
 * @return     none
 * 
 */
void Eiru_Drv_DeInit(void)
{
    if (0x0U != Eiru_Drv_EiruRegBfPtr->EIRU_CR.LOCK)
    {
        Eiru_Drv_EiruRegWPtr->EIRU_CR = 0x5C000000U;
    }

    Eiru_Drv_EiruRegWPtr->EIRU_CR = 0x0U;

    Eiru_Drv_EiruRegBfPtr->EIRU_CR.LOCK = 1U;    
}
/**
 * @brief      This function get ECC error Cause for choosing Sram.
 *
 * @param[in]  Sram: select which Sram to config:
 *                    - EIRU_DRV_SRAM_L
 *                    - EIRU_DRV_SRAM_U
 * @param[out]  Cause: the Cause of Sram ERR error will be stored in the struct
 *                    that is pointed by this parameter.
 *
 * @return      None
 * 
 */
void Eiru_Drv_GetSramEccErrCause(const Eiru_Drv_SramType Sram, Eiru_Drv_SramEccErrCauseType *Cause)
{
#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(Sram <= EIRU_DRV_SRAM_U);
    MCALLIB_DEV_ASSERT(NULL_PTR != Cause);
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

    Cause->ErrFaultAddr = Eiru_Drv_EiruRegWPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_FADDR;
    Cause->ErrFaultData = Eiru_Drv_EiruRegWPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_FDATA;
    Cause->ErrFaultMaster =
        (Eiru_Drv_MasterType)(Eiru_Drv_EiruRegBfPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_EESR.EFMST);
    Cause->ErrFaultSize = (Eiru_Drv_AccessSizeType)(Eiru_Drv_EiruRegBfPtr->EIRU_SRAMn_SC[Sram]
                                                        .EIRU_SRAMn_EESR.EFSIZE);
    Cause->AccessType =
        (0U == ((Eiru_Drv_EiruRegWPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_EESR) & 0x00000001U))
            ? EIRU_DRV_ACC_TYPE_OPCODE
            : EIRU_DRV_ACC_TYPE_DATA;
    Cause->AccessMode =
        (0U == ((Eiru_Drv_EiruRegWPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_EESR) & 0x00000002U))
            ? EIRU_DRV_ACC_MODE_USER
            : EIRU_DRV_ACC_MODE_PRIVIL;

#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief      This function get error Status for choosing Sram.
 *
 * @param[in]  Sram: select which Sram to config:
 *                    - EIRU_DRV_SRAM_L
 *                    - EIRU_DRV_SRAM_U
 * @param[in]  Status: select the Status to get :
 *               - EIRU_DRV_SRAM_ECC_ERR_SINGLEBIT
 *               - EIRU_DRV_SRAM_ECC_ERR_MULTIBIT
 *               - EIRU_DRV_SRAM_ECC_ERR_OVERRUN
 *
 * @return    boolean
 * @retval    FALSE: the error Status is not set
 * @retval    TRUE: the error Status is set
 * 
 */
boolean Eiru_Drv_GetSramEccErrStatus(const Eiru_Drv_SramType             Sram,
                                     const Eiru_Drv_SramEccErrStatusType Status)
{
    uint32 EiruSramEesr = 0U;
    uint32 SramEccErrValue = 0U;
#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(Sram <= EIRU_DRV_SRAM_U);
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

    EiruSramEesr = Eiru_Drv_EiruRegWPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_EESR;
    SramEccErrValue = (uint32)Status << EIRU_DRV_SRAM_ECC_ERR_OFFSET;
#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

    return ((EiruSramEesr & SramEccErrValue) != 0U)? TRUE : FALSE;
}

/**
 * @brief      This function clear ECC error Status for choosing Sram
 *
 * @param[in]  Sram: select which Sram to config:
                     - EIRU_DRV_SRAM_L
                     - EIRU_DRV_SRAM_U
 * @param[in]  Status: select the Status to clear.
 *
 * @return None
 * 
 */
void Eiru_Drv_ClearSramEccErrStatus(const Eiru_Drv_SramType             Sram,
                                    const Eiru_Drv_SramEccErrStatusType Status)
{
    uint32 SramEccErrValue = 0U;
#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(Sram <= EIRU_DRV_SRAM_U);
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */

    SramEccErrValue = (uint32)Status << EIRU_DRV_SRAM_ECC_ERR_OFFSET;
    Eiru_Drv_EiruRegWPtr->EIRU_SRAMn_SC[Sram].EIRU_SRAMn_EESR = SramEccErrValue;

#if (EIRU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (EIRU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

#define MEH_STOP_SEC_CODE
#include "Meh_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Meh_EiruDrv */

/** @} end of group Meh_Module */
