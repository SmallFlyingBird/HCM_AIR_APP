/**************************************************************************************************/
/**
 * @file      : Pmu_Drv.c
 * @brief     : PMU low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Pmu_Drv
 *  @brief PMU low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pmu_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define PMU_DRV_C_VENDOR_ID                   0x00B3U
#define PMU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define PMU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define PMU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define PMU_DRV_C_SW_MAJOR_VERSION            1U
#define PMU_DRV_C_SW_MINOR_VERSION            2U
#define PMU_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Pmu_Drv.h file are of the same vendor */
#if (PMU_DRV_C_VENDOR_ID != PMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Pmu_Drv.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Autosar version */
#if ((PMU_DRV_C_AR_RELEASE_MAJOR_VERSION != PMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (PMU_DRV_C_AR_RELEASE_MINOR_VERSION != PMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (PMU_DRV_C_AR_RELEASE_REVISION_VERSION != PMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pmu_Drv.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Software version */
#if ((PMU_DRV_C_SW_MAJOR_VERSION != PMU_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (PMU_DRV_C_SW_MINOR_VERSION != PMU_DRV_H_SW_MINOR_VERSION) ||                                 \
     (PMU_DRV_C_SW_PATCH_VERSION != PMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Pmu_Drv.c and Pmu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((PMU_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (PMU_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Pmu_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/*PMU unlock define*/
#define PMU_DRV_UNLOCK_KEY (0x94730000U) /*!< PMU Unlock Key */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

static const uint32 Pmu_Drv_IntStatusMaskTable[] = {
    0x00000040U, /* PMU_DRV_VDD_LVW_INT status mask */
    0x00000080U  /* PMU_DRV_VDD_LVD_INT status mask */
};

static const uint32 Pmu_Drv_IntEnableMaskTable[] = {
    0x00000020U, /* PMU_DRV_VDD_LVW_INT enable mask */
    0x00000004U  /* PMU_DRV_VDD_LVD_INT enable mask */
};

#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_PTR
#include "Mcu_MemMap.h"

/**
 *  @brief Pointer to PMU Registers
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Pmu_BfType *const Pmu_Drv_PmuRegBfPtr = (Reg_Pmu_BfType *)PMU_BASE_ADDR;
static Reg_Pmu_WType *const  Pmu_Drv_PmuRegWPtr = (Reg_Pmu_WType *)PMU_BASE_ADDR;

#define MCU_STOP_SEC_CONST_PTR
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_PTR
#include "Mcu_MemMap.h"

/**
 * @brief     Configured LVD callback function.
 */
static Pmu_Drv_CallbackFunc Pmu_Drv_LvdCallBackFunc = NULL_PTR;

/**
 * @brief     Configured LVW callback function.
 */
static Pmu_Drv_CallbackFunc Pmu_Drv_LvwCallBackFunc = NULL_PTR;

#define MCU_STOP_SEC_VAR_INIT_PTR
#include "Mcu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/**
 * @brief      Configs PMU control and status register.
 *
 * @param[in]  PmuCtrlType: Type of VDD5v detection.
 * @param[in]  PmuInterruptEnable: Enable/Disable given VDD5v detection.
 *
 * @return     None
 *
 */
static void Pmu_Drv_ConfigControlAndStatusReg(Pmu_Drv_CtrlType PmuCtrlType,
                                              boolean          PmuInterruptEnable)
{
    if (Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK != 0U)
    {
        Pmu_Drv_PmuRegWPtr->PMU_LOCK = PMU_DRV_UNLOCK_KEY;
    }

    switch (PmuCtrlType)
    {
        case PMU_DRV_VDD_LVD_LP:
            Pmu_Drv_PmuRegBfPtr->PMU_CSR.VDD_LVD_LP_EN = (uint32)PmuInterruptEnable;
            break;
        case PMU_DRV_VDD_LVD_ACT:
            Pmu_Drv_PmuRegBfPtr->PMU_CSR.VDD_LVD_ACT_EN = (uint32)PmuInterruptEnable;
            break;
        case PMU_DRV_VDD_LVD_RE:
            Pmu_Drv_PmuRegBfPtr->PMU_CSR.VDD_LVD_RE = (uint32)PmuInterruptEnable;
            break;
        case PMU_DRV_VDD_LVW:
            Pmu_Drv_PmuRegBfPtr->PMU_CSR.VDD_LVW_EN = (uint32)PmuInterruptEnable;
            break;
        case PMU_DRV_REF_BUF_1V:
            Pmu_Drv_PmuRegBfPtr->PMU_CSR.REF_BUF_1V_EN = (uint32)PmuInterruptEnable;
            break;
        default:
            /* Do nothing */
            break;
    }

    Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK = 1U;

    return;
}

/**
 * @brief      Configs enable or disable interrupt to given VDD5v detection interrupt.
 *
 * @param[in]  PmuIntType: Given VDD5v detection interrupt.
 * @param[in]  PmuInterruptEnable: Enable/Disable given VDD5v detection interrupt.
 *
 * @return     None
 *
 */
static void Pmu_Drv_ConfigInterrupt(Pmu_Drv_IntType PmuIntType, boolean PmuInterruptEnable)
{
    if (Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK != 0U)
    {
        Pmu_Drv_PmuRegWPtr->PMU_LOCK = PMU_DRV_UNLOCK_KEY;
    }

    if (0U != PmuInterruptEnable)
    {
        Pmu_Drv_PmuRegWPtr->PMU_CSR =
            Pmu_Drv_PmuRegWPtr->PMU_CSR | Pmu_Drv_IntEnableMaskTable[PmuIntType];
    }
    else
    {
        Pmu_Drv_PmuRegWPtr->PMU_CSR =
            Pmu_Drv_PmuRegWPtr->PMU_CSR & (~Pmu_Drv_IntEnableMaskTable[PmuIntType]);
    }

    Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK = 1U;
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief       Initializes PMU configuration.
 *
 * @param[in]   ConfigPtr: Pointer to the PMU configuration.
 *
 * @return      None
 *
 */
void Pmu_Drv_Init(const Pmu_Drv_ConfigType *ConfigPtr)
{
    if (NULL_PTR != ConfigPtr)
    {
        /* Configure PMU Control  */
        Pmu_Drv_ConfigControlAndStatusReg(PMU_DRV_VDD_LVD_LP, ConfigPtr->PmuCtrlLVDLowPowerEnable);
        Pmu_Drv_ConfigControlAndStatusReg(PMU_DRV_VDD_LVD_ACT, ConfigPtr->PmuCtrlLVDActiveEnable);
        Pmu_Drv_ConfigControlAndStatusReg(PMU_DRV_VDD_LVD_RE, ConfigPtr->PmuCtrlLVDResetEnable);
        Pmu_Drv_ConfigControlAndStatusReg(PMU_DRV_VDD_LVW, ConfigPtr->PmuCtrlLVWEnable);
        Pmu_Drv_ConfigControlAndStatusReg(PMU_DRV_REF_BUF_1V, ConfigPtr->PmuCtrlRef1VEnable);
        /* Configure PMU Interrupt Enable  */
        Pmu_Drv_ConfigInterrupt(PMU_DRV_VDD_LVW_INT, ConfigPtr->PmuLVWInterruptEnable);
        Pmu_Drv_LvwCallBackFunc = ConfigPtr->PmuLVWInterruptCallbackFunc;

        Pmu_Drv_ConfigInterrupt(PMU_DRV_VDD_LVD_INT, ConfigPtr->PmuLVDInterruptEnable);
        Pmu_Drv_LvdCallBackFunc = ConfigPtr->PmuLVDInterruptCallbackFunc;
    }
}

/**
 * @brief       Clears isolation clear register.
 *
 * @param[in]   None
 *
 * @return      None
 *
 */
void Pmu_Drv_ClearIsolationClear(void)
{
    if (Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK != 0U)
    {
        Pmu_Drv_PmuRegWPtr->PMU_LOCK = PMU_DRV_UNLOCK_KEY;
    }

    Pmu_Drv_PmuRegBfPtr->PMU_ISO_CLR.ISO_CLR = 1U;
    Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK = 1U;
}

/**
 * @brief      PMU interrupt handler
 *
 * @param[in]  None
 *
 * @return     None
 *
 */
void Pmu_Drv_IntHandler(void)
{
    uint32 IntStatus = Pmu_Drv_PmuRegWPtr->PMU_CSR;

    /* Clear interrupt status */
    if (Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK != 0U)
    {
        Pmu_Drv_PmuRegWPtr->PMU_LOCK = PMU_DRV_UNLOCK_KEY;
    }

    Pmu_Drv_PmuRegWPtr->PMU_CSR = IntStatus;

    Pmu_Drv_PmuRegBfPtr->PMU_LOCK.LOCK = 1U;

    /* VDD LVW(Low Voltage Warning) detect interrupt */
    if ((1U == Pmu_Drv_PmuRegBfPtr->PMU_CSR.VDD_LVW_IE) &&
        ((IntStatus & Pmu_Drv_IntStatusMaskTable[PMU_DRV_VDD_LVW_INT]) != 0U))
    {
        if (Pmu_Drv_LvwCallBackFunc != NULL_PTR)
        {
            Pmu_Drv_LvwCallBackFunc();
        }
    }

    /* VDD LVD(Low Voltage Detect) Interrupt */
    if ((1U == Pmu_Drv_PmuRegBfPtr->PMU_CSR.VDD_LVD_IE) &&
        ((IntStatus & Pmu_Drv_IntStatusMaskTable[PMU_DRV_VDD_LVD_INT]) != 0U))
    {
        if (Pmu_Drv_LvdCallBackFunc != NULL_PTR)
        {
            Pmu_Drv_LvdCallBackFunc();
        }
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Pmu_Drv */

/** @} end of group Mcu_Module */
