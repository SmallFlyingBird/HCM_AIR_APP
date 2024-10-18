/**************************************************************************************************/
/**
 * @file      : Smpu_Drv.c
 * @brief     : System memory protect unit source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Mpu_Module
 *  @{
 */

/** @addtogroup Smpu_Drv
 *  @brief Smpu Driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Smpu_Drv.h"
#include "Device_Regs.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SMPU_DRV_C_VENDOR_ID                   0x00B3U
#define SMPU_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define SMPU_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define SMPU_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define SMPU_DRV_C_SW_MAJOR_VERSION            1U
#define SMPU_DRV_C_SW_MINOR_VERSION            1U
#define SMPU_DRV_C_SW_PATCH_VERSION            0U
/**
 *  @brief Check if current file and Smpu_Drv.h file are of the same vendor
 */
#if (SMPU_DRV_C_VENDOR_ID != SMPU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Smpu_Drv.c and Smpu_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv.h file are of the same Autosar version
 */
#if ((SMPU_DRV_C_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SMPU_DRV_C_AR_RELEASE_MINOR_VERSION != SMPU_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SMPU_DRV_C_AR_RELEASE_REVISION_VERSION != SMPU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Smpu_Drv.c and Smpu_Drv.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv.h file are of the same SW version
 */
#if ((SMPU_DRV_C_SW_MAJOR_VERSION != SMPU_DRV_H_SW_MAJOR_VERSION) ||                               \
     (SMPU_DRV_C_SW_MINOR_VERSION != SMPU_DRV_H_SW_MINOR_VERSION) ||                               \
     (SMPU_DRV_C_SW_PATCH_VERSION != SMPU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Smpu_Drv.c and Smpu_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Device_Regs.h and Smpu_Drv.c are of the same AUTOSAR version */
    #if ((DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_C_AR_RELEASE_MAJOR_VERSION) ||  \
         (DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION != SMPU_DRV_C_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Device_Regs.h and Smpu_Drv.c are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define SMPU_DRV_CS_STATUS_MASK       (0x00000100UL)
/** @} end of group Public_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define MPU_START_SEC_VAR_INIT_PTR
#include "Mpu_MemMap.h"

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.*/
static Reg_Smpu_WType  *Smpu_Drv_SmpuRegWPtr = (Reg_Smpu_WType *)(SMPU_BASE_ADDR);
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
 no side effects forseen by violating this rule.*/
static Reg_Smpu_BfType *Smpu_Drv_SmpuRegBfPtr = (Reg_Smpu_BfType *)(SMPU_BASE_ADDR);

#define MPU_STOP_SEC_VAR_INIT_PTR
#include "Mpu_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define MPU_START_SEC_CODE
#include "Mpu_MemMap.h"
/**
 * @brief      Init Smpu memory region config.
 *
 * @param[in]  SmpuRegionConfigPtr: Pointer to configuration information
 *
 * @return     None
 * 
 */
void Smpu_Drv_InitMemoryRegion(const Smpu_Drv_RegionConfigType *SmpuRegionConfigPtr)
{
    uint32 RetVal = 0x0U;
    uint32 MasterId = 0x0U;
    uint32 Index = 0x0U;
    uint32 Region;
    
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(NULL_PTR != SmpuRegionConfigPtr);
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

    Region = SmpuRegionConfigPtr->RegionId;

    Smpu_Drv_SmpuRegBfPtr->SMPU_MRCn_W[Region].SMPU_MRCn_W0.SADDR =
        SmpuRegionConfigPtr->StartAddress >> 0x05U;
    Smpu_Drv_SmpuRegBfPtr->SMPU_MRCn_W[Region].SMPU_MRCn_W1.EADDR =
        SmpuRegionConfigPtr->EndAddress >> 0x05U;
    Smpu_Drv_SmpuRegBfPtr->SMPU_MRCn_W[Region].SMPU_MRCn_W3.EN = SmpuRegionConfigPtr->RegionState;

    for (; Index < (uint32)SMPU_DRV_BUS_MASTER_ALL; Index++)
    {
        MasterId = (uint32)SmpuRegionConfigPtr->MasterAccess[Index].BusMaster;
        RetVal |= ((uint32)(SmpuRegionConfigPtr->MasterAccess[Index].UserExeAllow)
                   << (MasterId * 0x6U));
        RetVal |= ((uint32)(SmpuRegionConfigPtr->MasterAccess[Index].UserWriteAllow)
                   << ((MasterId * 0x6U) + 0x1U));
        RetVal |= ((uint32)(SmpuRegionConfigPtr->MasterAccess[Index].UserReadAllow)
                   << ((MasterId * 0x6U) + 0x2U));
        RetVal |= ((uint32)(SmpuRegionConfigPtr->MasterAccess[Index].SupervisorModeAccess)
                   << ((MasterId * 0x6U) + 0x3U));
    }

    Smpu_Drv_SmpuRegWPtr->SMPU_MRCn_W[Region].SMPU_MRCn_W2 = RetVal;
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief        This function is used to enable or disable Smpu
 *
 * @param[in]    ControlState: Enable and Disable Smpu
 *
 * @return       none
 * 
 */
void Smpu_Drv_Enable(const boolean ControlState)
{
    Smpu_Drv_SmpuRegWPtr->SMPU_CS = (uint32)ControlState << 8U;
}

/**
 * @brief        This function get memory region id that detected a error.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 *
 * @return       MRC Number by MRCn(n=0~15),
 *               Bit n corresponds to MRCn, bit n set 1 when error occurs in MRCn.
 * 
 */
uint16 Smpu_Drv_GetSingleMrcErrStatus(const Smpu_Drv_SlavePortType SlavePort)
{
    uint16                    MrcStatus = 0U;
    
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(SlavePort < SMPU_DRV_SLV_PORT_ALL);
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

    MrcStatus = Smpu_Drv_SmpuRegBfPtr->SMPU_Sn_ES[SlavePort].EMRC;

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

    return MrcStatus;
}

/**
 * @brief       This function get master number that cause the error.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 * 
 * @return      Error master number:
 * @retval      0: bus master0 cause the access error
 * @retval      1: bus master1 cause the access error
 * @retval      2: bus master2 cause the access error
 * 
 */
Smpu_Drv_BusMasterType Smpu_Drv_GetErrAccessMasterNum(const Smpu_Drv_SlavePortType SlavePort)
{
    Smpu_Drv_BusMasterType RetVal = SMPU_DRV_BUS_MASTER_0;
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(SlavePort < SMPU_DRV_SLV_PORT_ALL);
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

    RetVal = (Smpu_Drv_BusMasterType)Smpu_Drv_SmpuRegBfPtr->SMPU_Sn_ES[SlavePort].EMN;

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */
    
    return RetVal;
}

/**
 * @brief       This function get error cause that occur in slave port.
 *
 * @param[in]   SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 * @param[out]  ErrorTypePtr: Point to the structure that contain error information
 * 
 * @return      none
 * 
 */
void Smpu_Drv_GetAccessErrCause(const Smpu_Drv_SlavePortType SlavePort, 
                                      Smpu_Drv_SalveErrorType *ErrorTypePtr)
{
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(SlavePort < SMPU_DRV_SLV_PORT_ALL);
    MCALLIB_DEV_ASSERT(ErrorTypePtr != NULL_PTR);
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

    ErrorTypePtr->IsWriteError =
        (Smpu_Drv_SmpuRegBfPtr->SMPU_Sn_ES[SlavePort].ERW != 0U) ? TRUE : FALSE;
    ErrorTypePtr->AccessMode = (0U == Smpu_Drv_SmpuRegBfPtr->SMPU_Sn_ES[SlavePort].EUS)
                                   ? SMPU_DRV_ACC_MODE_USER
                                   : SMPU_DRV_ACC_MODE_SVR;
    ErrorTypePtr->AccessError = (0U == Smpu_Drv_SmpuRegBfPtr->SMPU_Sn_ES[SlavePort].EATTR)
                                    ? SMPU_DRV_ACC_TYPE_INS
                                    : SMPU_DRV_ACC_TYPE_DATA;

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */
}

/**
 * @brief        This function get slave port error address.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 *
 * @return       Slave port n error address
 * 
 */
uint32 Smpu_Drv_GetSlavePortErrAddress(const Smpu_Drv_SlavePortType SlavePort)
{
     uint32 RetVal = 0U;
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(SlavePort < SMPU_DRV_SLV_PORT_ALL);
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

     RetVal = Smpu_Drv_SmpuRegWPtr->SMPU_Sn_EA[SlavePort];

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */
    
    return RetVal;
}

/**
 * @brief        This function get error bits mask.
 *
 * @param[in]    None
 *
 * @return       Slave port bits mask that occur an error.
 * 
 */
uint32 Smpu_Drv_GetSlavePortAccErrStatus(void)
{
    uint32 BitStatus;

    BitStatus = ((Smpu_Drv_SmpuRegWPtr->SMPU_CS) & 0x00000007U);

    return BitStatus;
}

/**
 * @brief        This function check Smpu is enabled or disabled.
 *
 * @param[in]    None
 *
 * @return       Smpu status.
 * @retval       TRUE: Smpu is enabled
 * @retval       FALSE: Smpu is disabled
 * 
 */
boolean Smpu_Drv_CheckStatus(void)
{
    return (0x00U == Smpu_Drv_SmpuRegBfPtr->SMPU_CS.GLBEN) ? FALSE : TRUE;
}
/**
 * @brief        This function is used to clear slave port n error status.
 *
 * @param[in]    SlavePort: Select slave port type: SMPU_DRV_SLV_PORT_0,
 *                          SMPU_DRV_SLV_PORT_1, SMPU_DRV_SLV_PORT_2.
 *
 * @return       None
 * 
 */
void Smpu_Drv_ClearSlavePortErrStatus(const Smpu_Drv_SlavePortType SlavePort)
{
    uint32 SmpuCsStatus;
#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT(SlavePort < SMPU_DRV_SLV_PORT_ALL);
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */
    SmpuCsStatus = Smpu_Drv_SmpuRegWPtr->SMPU_CS;
    SmpuCsStatus = SmpuCsStatus & SMPU_DRV_CS_STATUS_MASK;
    Smpu_Drv_SmpuRegWPtr->SMPU_CS = ((uint32)0x01U << (uint32)SlavePort) | SmpuCsStatus;

#if (SMPU_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif /* (SMPU_DRV_DEV_ERROR_DETECT == STD_ON) */
}
#define MPU_STOP_SEC_CODE
#include "Mpu_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu_Drv */

/** @} end of group Mpu_Module */
