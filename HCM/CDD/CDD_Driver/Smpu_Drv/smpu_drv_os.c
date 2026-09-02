/***************************************************************************//**
 * @file     smpu_drv.c
 * @brief    SMPU module driver file.
 * @version  V1.0.0
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 ******************************************************************************/

#include "smpu_drv_os.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @defgroup SMPU SMPU
 *  @brief SMPU driver modules
 *  @{
 */

/** @defgroup SMPU_Private_Type
 *  @{
 */

/** @} end of group SMPU_Private_Type*/

/** @defgroup SMPU_Private_Defines
 *  @{
 */


static Reg_Smpu_BfType *const smpuRegPtr = (Reg_Smpu_BfType *) SMPU_BASE_ADDR;
static Reg_Smpu_WType *const smpuRegWPtr = (Reg_Smpu_WType *) SMPU_BASE_ADDR;

/** @} end of group SMPU_Private_Defines */

/** @defgroup SMPU_Private_Variables
 *  @{
 */


/** @} end of group SMPU_Private_Variables */

/** @defgroup SMPU_Global_Variables
 *  @{
 */

/** @} end of group SMPU_Global_Variables */


/** @defgroup SMPU_Private_FunctionDeclaration
 *  @{
 */


/** @} end of group SMPU_Private_FunctionDeclaration */

/** @defgroup SMPU_Public_Functions
 *  @{
 */

/**
 * @brief       Initializes the SMPU
 *
 * @param[in]     region: Select memory region protect unit.
 * @param[in]     smpuConfigStruct: Pointer to a SMPU configuration structure.
 *
 * @return none
 *
 */
void SMPU_Init(SMPU_MemoryRegion_t region,
                                  const SMPU_Config_t* smpuConfigStruct)
{
   uint32 retVal;
   
   smpuRegPtr->SMPU_MRCn_W[region].SMPU_MRCn_W0.SADDR = 
                                       smpuConfigStruct->startAddress >> 0x05UL;
   smpuRegPtr->SMPU_MRCn_W[region].SMPU_MRCn_W1.EADDR = 
                                        smpuConfigStruct->endAddress >> 0x05UL;
   
   retVal = ((uint32)(smpuConfigStruct->exeAllow) 
                          << ((uint32)(smpuConfigStruct->busMaster) * 0x6UL));
   retVal |= ((uint32)(smpuConfigStruct->writeAllow)
                  << ((uint32)(smpuConfigStruct->busMaster) * 0x6UL + 0x1UL));
   retVal |= ((uint32)(smpuConfigStruct->readAllow)
                  << ((uint32)(smpuConfigStruct->busMaster) * 0x6UL + 0x2UL));  
   retVal |= ((uint32)(smpuConfigStruct->supervisorModeAccess) & 0x03UL)
                     << ((uint32)smpuConfigStruct->busMaster * 0x6UL + 0x3UL);
   smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 &= ~(0x1FUL <<
                                 (uint32)smpuConfigStruct->busMaster * 0x6UL);
   smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 |= retVal;
}

/**
 * @brief       The range of address protected by MRCn.
 *
 *  Memory regions address can overlap.If MRC1 is accessible and MRC2 is not in 
 *  the overlapping part, then the overlapping part is accessible.
 *
 * @param[in]     region: Select memory region protect unit.
 * @param[in]     startAddress: Start address protected by MRCn(n=0~15).
 * @param[in]     endAddress: End address protected by MRCn(n=0~15).
 *
 * @return none
 *
 */
void SMPU_MemoryRegionRange(SMPU_MemoryRegion_t region, 
                                  uint32 startAddress, uint32 endAddress)
{  
   smpuRegPtr->SMPU_MRCn_W[region].SMPU_MRCn_W0.SADDR = startAddress >> 0x05UL;
   smpuRegPtr->SMPU_MRCn_W[region].SMPU_MRCn_W1.EADDR = endAddress >> 0x05UL;
}

/**
 * @brief       The execute access control of bus master for each region in user 
 *              mode.
 * @param[in]   region:Select memory region protect unit.
 * @param[in]   busMaster:Select bus master number.
 * @param[in]   exeAllow: Execute access control 
 *                    - Enable: execute is allowed
 *                    - Disable: execute is not allowed
 * @return none
 *
 */
void SMPU_BusMstUserModeExeControl(SMPU_MemoryRegion_t region, 
                            SMPU_BusMaster_t busMaster, SmpuControlState_t exeAllow)
{ 
    uint32 offset;
    offset = (uint32)busMaster * 0x6UL;
    if(SMPU_DISABLE == exeAllow)
    {
        smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 &= 
                                                    ~((uint32)0x01 << offset);
    }
    else
    {
        smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 |= 
                                                     ((uint32)0x01 << offset);
    }
                          
}

/**
 * @brief       The write access control of bus master for each region in user 
 *              mode.
 * @param[in]   region:Select memory region protect unit.
 * @param[in]   busMaster:Select bus master number.
 * @param[in]   writeAllow: Write access control 
 *                    - Enable: write is allowed
 *                    - Disable: write is not allowed
 * @return none
 *
 */
void SMPU_BusMstUserModeWriteControl(SMPU_MemoryRegion_t region, 
                          SMPU_BusMaster_t busMaster, SmpuControlState_t writeAllow)
{
    uint32 offset;
    offset = (uint32)busMaster * 0x6UL + 0x1UL; 
    if(SMPU_DISABLE == writeAllow)
    {
        smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 &= 
                                                    ~((uint32)0x01 << offset);
    }
    else
    {
        smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 |= 
                                                     ((uint32)0x01 << offset);
    }
}

/**
 * @brief       The read access control of bus master for each region in user 
 *              mode.
 * @param[in]   region:Select memory region protect unit.
 * @param[in]   busMaster:Select bus master number.
 * @param[in]   readAllow: Read access control 
 *                    - Enable: read is allowed
 *                    - Disable: read is not allowed
 * @return none
 *
 */
void SMPU_BusMstUserModeReadControl(SMPU_MemoryRegion_t region, 
                           SMPU_BusMaster_t busMaster, SmpuControlState_t readAllow)
{   
    uint32 offset;
    offset = (uint32)busMaster * 0x6UL + 0x2UL; 
    if(SMPU_DISABLE == readAllow)
    {
        smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 &= 
                                                    ~((uint32)0x01 << offset);
    }
    else
    {
        smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 |= 
                                                     ((uint32)0x01 << offset);
    }
}

/**
 * @brief     The write/read/execute access control for bus master in supervisor
 *            mode
 * @param[in]   region:Select memory region protect unit.
 * @param[in]   busMaster:Select bus master number.
 * @param[in]   controlType: Access control types for bus master
 *     - SMPU_ALL_ALLOWED: Read/write/execute are all allowed
 *     - SMPU_READ_EXE_ALLOWED: Read/execute are allowed, write is not allowed
 *     - SMPU_READ_WRITE_ALLOWED: Read/write are allowed, execute is not allowed
 *     - SMPU_SAME_WITH_USERMODE: Access control are same with user mode
 *
 * @return none
 *
 */
void SMPU_BusMstSvrModeAccessControl(SMPU_MemoryRegion_t region, 
                                     SMPU_BusMaster_t busMaster,
                                     SMPU_SupvModeAccess_t controlType)
{   
    uint32 offset;
    offset = (uint32)busMaster * 0x6UL + 0x3UL; 
    
    smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 &= 
                                    ~((uint32)0x3UL << offset);
    smpuRegWPtr->SMPU_MRCn_W[region].SMPU_MRCn_W2 |= 
                                    (((uint32)controlType & 0x3UL) << offset);
}

/**
 * @brief        Global SMPU enable
 *
 * @param[in]    none
 *
 * @return none
 *
 */
void SMPU_Enable(void)
{
    smpuRegPtr->SMPU_CS.GLBEN = 1U;
}

/**
 * @brief        Global SMPU disable
 *
 * @param[in]    none
 *
 * @return none
 *
 */
void SMPU_Disable(void)
{   
    smpuRegPtr->SMPU_CS.GLBEN = 0U;
}

/**
 * @brief        Memory region n configuration enable
 *
 * @param[in]   region:Select memory region protect unit.
 *
 * @return none
 *
 */
void SMPU_MemoryRegionConfigEnable(SMPU_MemoryRegion_t region)
{ 
    smpuRegPtr->SMPU_MRCn_W[region].SMPU_MRCn_W3.EN = 1U;
}

/**
 * @brief       Memory region n configuration disable
 *
 * @param[in]   region:Select memory region protect unit.
 *
 * @return none
 *
 */
void SMPU_MemoryRegionConfigDisable(SMPU_MemoryRegion_t region)
{  
    smpuRegPtr->SMPU_MRCn_W[region].SMPU_MRCn_W3.EN = 0U;
}

/**
 * @brief         Record the error is detected by appointed MRC.
 *
 * This function detected a MRC.
 *
 * @param[in]    slavePort: Select slave port type: SMPU_SLV_PORT_0, 
 *                          SMPU_SLV_PORT_1, SMPU_SLV_PORT_2, SMPU_SLV_PORT_3.
 * @param[in]    region:   Select memory region protect unit.
 *
 * @return       - SET: Error detected by memory region configuration
 *               - RESET: No error detected by memory region configuration
 *
 */
SmpuFlagStatus_t SMPU_GetSingleMrcErrStatus(SMPU_SlvPort_t slavePort, 
                                        SMPU_MemoryRegion_t region)
{   
    uint32 mrcStatus = smpuRegPtr->SMPU_Sn_ES[slavePort].EMRC;
    mrcStatus = ((mrcStatus & (0x01UL << (uint32)region)) >> 
                                                            (uint32)region);
    return (SmpuFlagStatus_t)mrcStatus;
}

/**
 * @brief        Record the error is detected by which MRC in slave port
 *
 * @param[in]   slavePort: Select slave PORT Type: SMPU_SLV_PORT_0, 
 *                          SMPU_SLV_PORT_1, SMPU_SLV_PORT_2, SMPU_SLV_PORT_3.
 *              
 * @return      Error detected by MRCn number.(n = 0~15)
 *       (Bit n corresponds to MRCn, and bit n set 1 when error occurs in MRCn.)
 *
 */
uint32 SMPU_GetErrMrcNum(SMPU_SlvPort_t slavePort)
{   
    return smpuRegPtr->SMPU_Sn_ES[slavePort].EMRC;
}

/**
 * @brief       The bus master that cause the access error.
 * @param[in]   slavePort: Select slave PORT Type: SMPU_SLV_PORT_0, 
 *                          SMPU_SLV_PORT_1, SMPU_SLV_PORT_2, SMPU_SLV_PORT_3.
 * 
 * @return      Error master number:
 *               - 0: bus master0 cause the access error
 *               - 1: bus master1 cause the access error
 *               - 2: bus master2 cause the access error
 */
uint32 SMPU_GetErrAccMstNum(SMPU_SlvPort_t slavePort)
{ 
    return smpuRegPtr->SMPU_Sn_ES[slavePort].EMN;
}

/**
 * @brief       Error type is read or write access
 * @param[in]   slavePort: Select slave PORT Type: SMPU_SLV_PORT_0, 
 *                          SMPU_SLV_PORT_1, SMPU_SLV_PORT_2, SMPU_SLV_PORT_3.
 *
 * @return       none
 *
 */
void SMPU_GetAccErrCause(SMPU_SlvPort_t slavePort, SMPU_ErrorType_t * errorType)
{  
    errorType->write = (smpuRegPtr->SMPU_Sn_ES[slavePort].ERW != 0U) ? 
                                         SET:RESET;
    errorType->accessMode = (smpuRegPtr->SMPU_Sn_ES[slavePort].EUS == 0U) ?
                                         SMPU_ACCESS_MODE_USER : SMPU_ACCESS_MODE_SVR;
    errorType->accessType = (smpuRegPtr->SMPU_Sn_ES[slavePort].EATTR == 0U) ? 
                                         SMPU_ACCESS_TYPE_INS : SMPU_ACCESS_TYPE_DATA;
}

/**
 * @brief        slave port n error address.
 *
 * @param[in]    slavePort: Select slave PORT Type: SMPU_SLV_PORT_0, 
 *                          SMPU_SLV_PORT_1, SMPU_SLV_PORT_2, SMPU_SLV_PORT_3.
 *
 * @return       slave port n error address
 *
 */
uint32 SMPU_GetSlvPortErrAddress(SMPU_SlvPort_t slavePort)
{ 
    return smpuRegWPtr->SMPU_Sn_EA[slavePort];
}

/**
 * @brief        slave port n error status .
 *
 * @param[in]    errorPortStatus: slave port n error type
 *               - SMPU_SLV_PORT_0_ERROR
 *               - SMPU_SLV_PORT_1_ERROR
 *               - SMPU_SLV_PORT_2_ERROR
 *               - SMPU_SLV_PORT_3_ERROR
 *
 * @return       - SET: slave port n access error occurred.
 *               - RESET: slave port n access error didn't occur.
 *
 */
SmpuFlagStatus_t SMPU_GetSlvPortAccErrStatus
(
    SMPU_SlvPortErrorStatus_t portAccessStatus
)
{  
    uint32 bitStatus;
    bitStatus = (((smpuRegWPtr->SMPU_CS) & 
        (0x01UL << (uint32)portAccessStatus)) >> (uint32)portAccessStatus);
    return (SmpuFlagStatus_t)bitStatus;
}

/**
 * @brief        clear slave port n error status .
 *
 * @param[in]    errorPortStatus: slave port n error type
 *               - SMPU_SLV_PORT_0_ERROR
 *               - SMPU_SLV_PORT_1_ERROR
 *               - SMPU_SLV_PORT_2_ERROR
 *               - SMPU_SLV_PORT_3_ERROR
 *               - SMPU_SLV_PORT_ALL_ERROR
 *
 * @return       none
 *
 */
void SMPU_ClearSlvPortErrStatus(SMPU_SlvPortErrorStatus_t portAccessStatus)
{
    smpuRegWPtr->SMPU_CS |= 0x01UL << (uint32)portAccessStatus;
}
/** @} end of group SMPU_Public_Functions */

/** @} end of group SMPU_definitions */

/** @} end of group Z20K14XM_Peripheral_Driver */
