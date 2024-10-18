/**************************************************************************************************/
/**
 * @file      : Cmu_Drv.c
 * @brief     : AUTOSAR CMU driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu_Drv
 *  @brief Cmu low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Cmu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define CMU_DRV_C_VENDOR_ID                   0x00B3U
#define CMU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define CMU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define CMU_DRV_C_SW_MAJOR_VERSION            1U
#define CMU_DRV_C_SW_MINOR_VERSION            1U
#define CMU_DRV_C_SW_PATCH_VERSION            0U

/* Check if current file and Cmu_Drv.h file are of the same vendor */
#if (CMU_DRV_C_VENDOR_ID != CMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Cmu_Drv.c and Cmu_Drv.h are different"
#endif

/* Check if current file and Cmu_Drv.h file are of the same Autosar version */
#if ((CMU_DRV_C_AR_RELEASE_MAJOR_VERSION != CMU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (CMU_DRV_C_AR_RELEASE_MINOR_VERSION != CMU_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (CMU_DRV_C_AR_RELEASE_REVISION_VERSION != CMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu_Drv.c and Cmu_Drv.h are different"
#endif

/* Check if current file and Cmu_Drv.h file are of the same software version */
#if ((CMU_DRV_C_SW_MAJOR_VERSION != CMU_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (CMU_DRV_C_SW_MINOR_VERSION != CMU_DRV_H_SW_MINOR_VERSION) ||                                 \
     (CMU_DRV_C_SW_PATCH_VERSION != CMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu_Drv.c and Cmu_Drv.h are different"
#endif

#define CMU_DRV_INT_BELOW_LOW_THRE_MASK  (((uint32)1U) << 17U)
#define CMU_DRV_INT_ABOVE_HIGH_THRE_MASK (((uint32)1U) << 16U)
#define CMU_DRV_INT_ALL_MASK             (CMU_DRV_INT_BELOW_LOW_THRE_MASK | CMU_DRV_INT_ABOVE_HIGH_THRE_MASK)

#define CMU_DRV_NUM 3U

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

#define CMU_START_SEC_CONST_32
#include "Cmu_MemMap.h"

static const uint32 Cmu_Drv_InterruptMaskTable[] = {
    CMU_DRV_INT_BELOW_LOW_THRE_MASK, CMU_DRV_INT_ABOVE_HIGH_THRE_MASK, CMU_DRV_INT_ALL_MASK};

#define CMU_STOP_SEC_CONST_32
#include "Cmu_MemMap.h"

#define CMU_START_SEC_VAR_INIT_PTR
#include "Cmu_MemMap.h"

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
 no side effects forseen by violating this rule.
 The following three lines of code also violate this rule with the same reason. */
static Reg_Cmu_BfType *Cmu_Drv_CmuRegBfPtr[CMU_DRV_NUM] = {
    (Reg_Cmu_BfType *)CMU0_BASE_ADDR,
    (Reg_Cmu_BfType *)CMU1_BASE_ADDR,
    (Reg_Cmu_BfType *)CMU2_BASE_ADDR,
};

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
 no side effects forseen by violating this rule.
 The following three lines of code also violate this rule with the same reason. */
static Reg_Cmu_WType *Cmu_Drv_CmuRegWPtr[CMU_DRV_NUM] = {
    (Reg_Cmu_WType *)CMU0_BASE_ADDR,
    (Reg_Cmu_WType *)CMU1_BASE_ADDR,
    (Reg_Cmu_WType *)CMU2_BASE_ADDR,
};

/**
 * @brief Local copy of the pointer to the configuration data
 */
static const Cmu_Drv_ConfigType *Cmu_Drv_ConfigPtr[CMU_DRV_NUM] = {
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
};

#define CMU_STOP_SEC_VAR_INIT_PTR
#include "Cmu_MemMap.h"


/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#define CMU_START_SEC_CODE
#include "Cmu_MemMap.h"

/**
 * @brief      Configures specify clock monitor.
 *
 * @param[in]  CmuConfigPtr: Pointer to the cmu configuration.
 *
 * @return     None
 *
 */
static void Cmu_Drv_Config(const Cmu_Drv_ConfigType *CmuConfigPtr)
{
    Cmu_Drv_IdType CmuMonitorId;
    Reg_Cmu_BfType *CmuBfPtr;
    Reg_Cmu_WType  *CmuWxPtr;
    if (NULL_PTR != CmuConfigPtr )
    {
        CmuMonitorId = CmuConfigPtr->ClockMonitorId;
        CmuBfPtr = Cmu_Drv_CmuRegBfPtr[CmuMonitorId];
        CmuWxPtr = Cmu_Drv_CmuRegWPtr[CmuMonitorId];
        /* Make sure monitor is disabled before configuration */
        Cmu_Drv_Disable(CmuMonitorId);

        CmuBfPtr->CMU_CTRL.FBLTIE = (TRUE == CmuConfigPtr->BelowLowThresholdIntEn) ? 1U : 0U;
        CmuBfPtr->CMU_CTRL.FAHTIE = (TRUE == CmuConfigPtr->AboveHighThresholdIntEn) ? 1U : 0U;
        CmuBfPtr->CMU_CTRL.FBLTRSTE = (TRUE == CmuConfigPtr->BelowLowThresholdResetEn) ? 1U : 0U;
        CmuBfPtr->CMU_CTRL.FAHTRSTE = (TRUE == CmuConfigPtr->AboveHighThresholdResetEn) ? 1U : 0U;

        CmuWxPtr->CMU_CUMHCT4INT = CmuConfigPtr->IntHighThreshold;
        CmuWxPtr->CMU_CUMLCT4INT = CmuConfigPtr->IntLowThreshold;
        CmuWxPtr->CMU_CUMHCT4RST = CmuConfigPtr->ResetHighThreshold;
        CmuWxPtr->CMU_CUMLCT4RST = CmuConfigPtr->ResetLowThreshold;

        CmuWxPtr->CMU_MONWIN = CmuConfigPtr->MonitorWindow;

        /* Set monitor mode */
        if (CMU_DRV_MONITOR_MODE == CmuConfigPtr->Mode)
        {
            CmuBfPtr->CMU_CTRL.CMMD = 0U;
        }
        else if (CMU_DRV_MEASURE_MODE == CmuConfigPtr->Mode)
        {
            CmuBfPtr->CMU_CTRL.CMMD = 1U;
        }
        else
        {
            /* Do nothing */
        }
    }

}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief       Initializes the given clock monitor.
 *
 * @param[in]   CmuConfigPtr: Pointer to the clock monitor configuration.
 *
 * @return      None
 *
 */
void Cmu_Drv_Init(const Cmu_Drv_ConfigType *CmuConfigPtr)
{
    if (NULL_PTR != CmuConfigPtr)
    {
        /* Configure CMUX Config  */
        Cmu_Drv_Config(CmuConfigPtr);
        Cmu_Drv_ConfigPtr[CmuConfigPtr->ClockMonitorId] = CmuConfigPtr;
    }
}

/**
 * @brief       Gets current mode of the given clock monitor.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 *
 * @return      Cmu_Drv_ModeType
 * @retval      - CMU_DRV_MONITOR_MODE: Monitor mode.
 * @retval      - CMU_DRV_MEASURE_MODE: Measure mode.
 *
 */
Cmu_Drv_ModeType Cmu_Drv_GetMode(const Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_BfType *CmuXPtr = Cmu_Drv_CmuRegBfPtr[CmuMonitorId];

    return (Cmu_Drv_ModeType)CmuXPtr->CMU_CTRL.CMMD;
}

/**
 * @brief       Sets specify clock monitor to the given mode.
 *
 * @param[in]   CmuMonitorId: CMU Monitor id.
 * @param[in]   CmuMode: The given mode.
 *
 * @return      None
 *
 */
void Cmu_Drv_SetMode(const Cmu_Drv_IdType CmuMonitorId, const Cmu_Drv_ModeType CmuMode)
{
    Reg_Cmu_BfType *CmuXPtr = Cmu_Drv_CmuRegBfPtr[CmuMonitorId];

    Cmu_Drv_Disable(CmuMonitorId);
    CmuXPtr->CMU_CTRL.CMMD = (uint32)CmuMode;
    Cmu_Drv_Enable(CmuMonitorId);
}

/**
 * @brief       Starts the measure mode.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return      None
 *
 */
void Cmu_Drv_StartMeasure(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_BfType *CmuXPtr = Cmu_Drv_CmuRegBfPtr[CmuMonitorId];

    CmuXPtr->CMU_STAT.STARTMEA = 1U;
}

/**
 * @brief       Gets the measure complete status.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return     boolean.
 * @retval     - TRUE:measure state is completed.
 * @retval     - FALSE:measure state is not completed.
 */
boolean Cmu_Drv_GetMeasureCompleteStatus(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_BfType *CmuXPtr = Cmu_Drv_CmuRegBfPtr[CmuMonitorId];

    return ((0U == CmuXPtr->CMU_STAT.STARTMEA) ? TRUE : FALSE);
}

/**
 * @brief      Gets measure result when CMU is working in measure mode.
 * @note       User  needs to make sure the measure is completed before calling this
 *             function, otherwise, the return value is incorrect.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return    uint32: Measurement result.
 *
 *
 */
uint32 Cmu_Drv_GetMeasureResult(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_WType *CmuWxPtr = (Reg_Cmu_WType *)(Cmu_Drv_CmuRegWPtr[CmuMonitorId]);

    return (CmuWxPtr->CMU_CUMMEARSLT);
}

/**
 * @brief      Enables the given CMU.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return     None
 *
 */
void Cmu_Drv_Enable(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_BfType *CmuXPtr = Cmu_Drv_CmuRegBfPtr[CmuMonitorId];
    Reg_Cmu_WType  *CmuWxPtr = (Reg_Cmu_WType *)(Cmu_Drv_CmuRegWPtr[CmuMonitorId]);
    uint32          Tmp;

    if (0U != CmuXPtr->CMU_CTRL.LOCK)
    {
        /* unlock */
        Tmp = CmuWxPtr->CMU_CTRL;
        Tmp &= 0xFFFFFFU;
        Tmp |= 0x5B000000U;
        CmuWxPtr->CMU_CTRL = Tmp;
    }

    CmuXPtr->CMU_CTRL.CME = 1U;

    /* lock CMU_CTRL register */
    CmuXPtr->CMU_CTRL.LOCK = 1U;
}

/**
 * @brief      Disables the given CMU.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return     None
 *
 */
void Cmu_Drv_Disable(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_BfType *CmuXPtr = (Reg_Cmu_BfType *)(Cmu_Drv_CmuRegBfPtr[CmuMonitorId]);
    Reg_Cmu_WType  *CmuWxPtr = (Reg_Cmu_WType *)(Cmu_Drv_CmuRegWPtr[CmuMonitorId]);
    uint32          Tmp;

    if (0U != CmuXPtr->CMU_CTRL.LOCK)
    {
        /* unlock */
        Tmp = CmuWxPtr->CMU_CTRL;
        Tmp &= 0xFFFFFFU;
        Tmp |= 0x5B000000U;
        CmuWxPtr->CMU_CTRL = Tmp;
    }
    else
    {
        /* Do nothing */
    }

    CmuXPtr->CMU_CTRL.CME = 0U;

    /* lock CMU_CTRL register */
    CmuXPtr->CMU_CTRL.LOCK = 1U;
}

/**
 * @brief      CMU interrupt Handler
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return     None
 *
 */
void Cmu_Drv_IrqHandler(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_WType *CmuRegWPtr = Cmu_Drv_CmuRegWPtr[CmuMonitorId];
    uint32         CmuStatus;

    CmuStatus = CMU_DRV_INT_ALL_MASK & (CmuRegWPtr->CMU_CTRL);

    CmuStatus &= (CmuRegWPtr->CMU_STAT);

    /* Clear interrupt status */
    CmuRegWPtr->CMU_STAT = CmuStatus;

    /* Handle CMU_DRV_INT_BELOW_LOW_THRE */
    if (0U != (CmuStatus & Cmu_Drv_InterruptMaskTable[CMU_DRV_INT_BELOW_LOW_THRE]))
    {
        if (NULL_PTR != Cmu_Drv_ConfigPtr[CmuMonitorId]->BelowLowThresholdNotification)
        {
            Cmu_Drv_ConfigPtr[CmuMonitorId]->BelowLowThresholdNotification();
        }
    }

    /* Handle CMU_DRV_INT_ABOVE_HIGH_THRE */
    if (0U != (CmuStatus & Cmu_Drv_InterruptMaskTable[CMU_DRV_INT_ABOVE_HIGH_THRE]))
    {
        if (NULL_PTR != Cmu_Drv_ConfigPtr[CmuMonitorId]->AboveHighThresholdNotification)
        {
            Cmu_Drv_ConfigPtr[CmuMonitorId]->AboveHighThresholdNotification();
        }
    }
}

/**
 * @brief      Gets the given CMU current state.
 *
 * @param[in]  CmuMonitorId: CMU Monitor id.
 *
 * @return     Cmu_Drv_StateType.
 * @retval     - CMU_DRV_STATE_CFG_UPDATABLE:CMU configuration can be updated.
 * @retval     - CMU_DRV_STATE_CFG_LOCKED:CMU configuration is locked.
 * @retval     - CMU_DRV_STATE_MONITOR_RUNNING:CMU is running.
 */
Cmu_Drv_StateType Cmu_Drv_GetState(Cmu_Drv_IdType CmuMonitorId)
{
    Reg_Cmu_BfType *CmuBfPtr = (Reg_Cmu_BfType *)(Cmu_Drv_CmuRegBfPtr[CmuMonitorId]);

    return (Cmu_Drv_StateType)(CmuBfPtr->CMU_STAT.MONST);
}

#define CMU_STOP_SEC_CODE
#include "Cmu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Cmu_Drv */

/** @} end of group Cmu_Module */
