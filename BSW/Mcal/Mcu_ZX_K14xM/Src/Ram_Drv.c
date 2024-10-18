/**************************************************************************************************/
/**
 * @file      : Ram_Drv.c
 * @brief     : RAM low level driver source file
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

/** @addtogroup Ram_Drv
 *  @brief RAM low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ram_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

/* Published information */
#define RAM_DRV_C_VENDOR_ID                   0x00B3U
#define RAM_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define RAM_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define RAM_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define RAM_DRV_C_SW_MAJOR_VERSION            1U
#define RAM_DRV_C_SW_MINOR_VERSION            2U
#define RAM_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Ram_Drv.h file are of the same vendor */
#if (RAM_DRV_C_VENDOR_ID != RAM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Ram_Drv.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Autosar version */
#if ((RAM_DRV_C_AR_RELEASE_MAJOR_VERSION != RAM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (RAM_DRV_C_AR_RELEASE_MINOR_VERSION != RAM_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (RAM_DRV_C_AR_RELEASE_REVISION_VERSION != RAM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ram_Drv.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Software version */
#if ((RAM_DRV_C_SW_MAJOR_VERSION != RAM_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (RAM_DRV_C_SW_MINOR_VERSION != RAM_DRV_H_SW_MINOR_VERSION) ||                                 \
     (RAM_DRV_C_SW_PATCH_VERSION != RAM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Ram_Drv.c and Ram_Drv.h are different"
#endif

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
 * @brief       Writes RAM sector with specify value by each one byte.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be written.
 *
 * @return      None
 *
 */
LOCAL_INLINE void Ram_Drv_WriteSectionWithOneByte(const Ram_Drv_ConfigType *RamConfigPtr,
                                                  Ram_Drv_SectorSizeType    RamWriteCnt)
{
    Ram_Drv_IndexType RamWriteIndex = (Ram_Drv_IndexType)0UL;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamWriteIndex < RamWriteCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            *((uint8 *)(RamConfigPtr->RamBaseAddr + RamWriteIndex)) =
                (uint8)RamConfigPtr->RamDefaultValue;

            ++RamWriteIndex;
        }
    }
}

/**
 * @brief       Writes RAM sector with specify value by each two bytes.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be written.
 *
 * @return      None
 *
 */
LOCAL_INLINE void Ram_Drv_WriteSectionWithTwoBytes(const Ram_Drv_ConfigType *RamConfigPtr,
                                                   Ram_Drv_SectorSizeType    RamWriteCnt)
{
    Ram_Drv_IndexType RamWriteIndex = (Ram_Drv_IndexType)0UL;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamWriteIndex < RamWriteCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            *((uint16 *)(RamConfigPtr->RamBaseAddr + RamWriteIndex)) =
                (uint16)RamConfigPtr->RamDefaultValue;

            RamWriteIndex += 2U;
        }
    }
}

/**
 * @brief       Writes RAM sector with specify value by each four bytes.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be written.
 *
 * @return      None
 *
 */
LOCAL_INLINE void Ram_Drv_WriteSectionWithFourBytes(const Ram_Drv_ConfigType *RamConfigPtr,
                                                    Ram_Drv_SectorSizeType    RamWriteCnt)
{
    Ram_Drv_IndexType RamWriteIndex = (Ram_Drv_IndexType)0UL;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamWriteIndex < RamWriteCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            *((uint32 *)(RamConfigPtr->RamBaseAddr + RamWriteIndex)) =
                (uint32)RamConfigPtr->RamDefaultValue;

            RamWriteIndex += 4U;
        }
    }
}

/**
 * @brief       Writes RAM sector with specify value by each eight bytes.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be written.
 *
 * @return      None
 *
 */
LOCAL_INLINE void Ram_Drv_WriteSectionWithEightBytes(const Ram_Drv_ConfigType *RamConfigPtr,
                                                     Ram_Drv_SectorSizeType    RamWriteCnt)
{
    Ram_Drv_IndexType RamWriteIndex = (Ram_Drv_IndexType)0UL;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamWriteIndex < RamWriteCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            *((uint64 *)(RamConfigPtr->RamBaseAddr + RamWriteIndex)) =
                (uint64)RamConfigPtr->RamDefaultValue;

            RamWriteIndex += 8U;
        }
    }
}

/**
 * @brief       Checks RAM sector content with specify value by each one byte.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be checked.
 *
 * @return      boolean
 * @retval      TRUE:  RAM sector value equals to specify value.
 * @retval      FALSE: RAM sector value differs to specify value.
 *
 */
LOCAL_INLINE boolean Ram_Drv_CheckSectorByOneByte(const Ram_Drv_ConfigType *RamConfigPtr,
                                                  Ram_Drv_SectorSizeType    RamCheckCnt)
{
    boolean                RetState = TRUE;
    Ram_Drv_SectorSizeType RamCheckIndex = 0U;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamCheckIndex < RamCheckCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            if ((uint8)RamConfigPtr->RamDefaultValue !=
                *((uint8 *)(RamConfigPtr->RamBaseAddr + RamCheckIndex)))
            {
                RetState = FALSE;
                break;
            }
            ++RamCheckIndex;
        }
    }
    else
    {
        RetState = FALSE;
    }

    return RetState;
}

/**
 * @brief       Checks RAM sector content with specify value by each two bytes.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be checked.
 *
 * @return      boolean
 * @retval      TRUE:  RAM sector value equals to specify value.
 * @retval      FALSE: RAM sector value differs to specify value.
 *
 */
LOCAL_INLINE boolean Ram_Drv_CheckSectorByTwoBytes(const Ram_Drv_ConfigType *RamConfigPtr,
                                                   Ram_Drv_SectorSizeType    RamCheckCnt)
{
    boolean                RetState = TRUE;
    Ram_Drv_SectorSizeType RamCheckIndex = 0U;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamCheckIndex < RamCheckCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            if ((uint16)RamConfigPtr->RamDefaultValue !=
                *((uint16 *)(RamConfigPtr->RamBaseAddr + RamCheckIndex)))
            {
                RetState = FALSE;
                break;
            }

            RamCheckIndex += 2U;
        }
    }
    else
    {
        RetState = FALSE;
    }

    return RetState;
}

/**
 * @brief       Checks RAM sector content with specify value by each four bytes.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be checked.
 *
 * @return      boolean
 * @retval      TRUE:  RAM sector value equals to specify value.
 * @retval      FALSE: RAM sector value differs to specify value.
 *
 */
LOCAL_INLINE boolean Ram_Drv_CheckSectorByFourBytes(const Ram_Drv_ConfigType *RamConfigPtr,
                                                    Ram_Drv_SectorSizeType    RamCheckCnt)
{
    boolean                RetState = TRUE;
    Ram_Drv_SectorSizeType RamCheckIndex = 0U;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamCheckIndex < RamCheckCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            if ((uint32)RamConfigPtr->RamDefaultValue !=
                *((uint32 *)(RamConfigPtr->RamBaseAddr + RamCheckIndex)))
            {
                RetState = FALSE;
                break;
            }

            RamCheckIndex += 4U;
        }
    }
    else
    {
        RetState = FALSE;
    }

    return RetState;
}

/**
 * @brief       Checks RAM sector content with specify value by each eight bytes.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 * @param[in]   RamCheckCnt: Number of area to be checked.
 *
 * @return      boolean
 * @retval      TRUE:  RAM sector value equals to specify value.
 * @retval      FALSE: RAM sector value differs to specify value.
 *
 */
LOCAL_INLINE boolean Ram_Drv_CheckSectorByEightBytes(const Ram_Drv_ConfigType *RamConfigPtr,
                                                     Ram_Drv_SectorSizeType    RamCheckCnt)
{
    boolean                RetState = TRUE;
    Ram_Drv_SectorSizeType RamCheckIndex = 0U;

    if (NULL_PTR != RamConfigPtr)
    {
        while (RamCheckIndex < RamCheckCnt)
        {
            /* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
             * implementation needed to initialize RAM. No side effects forseen by violating this
             * rule. */
            if ((uint64)RamConfigPtr->RamDefaultValue !=
                *((uint64 *)(RamConfigPtr->RamBaseAddr + RamCheckIndex)))
            {
                RetState = FALSE;
                break;
            }

            RamCheckIndex += 8U;
        }
    }
    else
    {
        RetState = FALSE;
    }

    return RetState;
}
/**
 * @brief       Initializes RAM section with configured default value.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 *
 * @return      boolean
 * @retval      TRUE:  RAM section has been initialized successfully.
 * @retval      FALSE: RAM section has been initialized failed, e.g. RAM write size is invalid.
 *
 */
static boolean Ram_Drv_InitSectionWithDefaultValue(const Ram_Drv_ConfigType *RamConfigPtr)
{
    boolean                RamInitStatus = TRUE;

    if (NULL_PTR != RamConfigPtr)
    {
        switch (RamConfigPtr->RamWriteSize)
        {
            case 1U:
                Ram_Drv_WriteSectionWithOneByte(RamConfigPtr, (Ram_Drv_SectorSizeType)RamConfigPtr->RamSize);
                break;

            case 2U:
                Ram_Drv_WriteSectionWithTwoBytes(RamConfigPtr, (Ram_Drv_SectorSizeType)RamConfigPtr->RamSize);
                break;

            case 4U:
                Ram_Drv_WriteSectionWithFourBytes(RamConfigPtr, (Ram_Drv_SectorSizeType)RamConfigPtr->RamSize);
                break;

            case 8U:
                Ram_Drv_WriteSectionWithEightBytes(RamConfigPtr, (Ram_Drv_SectorSizeType)RamConfigPtr->RamSize);
                break;
            default:
                RamInitStatus = FALSE;
                break;
        }
    }
    else
    {
        RamInitStatus = FALSE;
    }

    return RamInitStatus;
}

/**
 * @brief       Checks whether RAM section is initialized with configured default value.
 *
 * @param[in]   RamConfigPtr: RAM section configuration.
 *
 * @return      boolean
 * @retval      TRUE:  RAM section is initialized with configured default value.
 * @retval      FALSE: RAM section is not initialized with configured default value.
 *
 */
static boolean Ram_Drv_CheckSectionWithDefaultValue(const Ram_Drv_ConfigType *RamConfigPtr)
{
    boolean                RamCheckStatus = TRUE;
    Ram_Drv_SectorSizeType RamCheckCnt;

    if (NULL_PTR != RamConfigPtr)
    {
        RamCheckCnt = (Ram_Drv_SectorSizeType)(((Ram_Drv_SectorSizeType)(RamConfigPtr->RamSize)) /
                                               (RamConfigPtr->RamWriteSize));

        switch (RamConfigPtr->RamWriteSize)
        {
            case 1U:
                RamCheckStatus = Ram_Drv_CheckSectorByOneByte(RamConfigPtr, RamCheckCnt);
                break;
            case 2U:
                RamCheckStatus = Ram_Drv_CheckSectorByTwoBytes(RamConfigPtr, RamCheckCnt);
                break;
            case 4U:
                RamCheckStatus = Ram_Drv_CheckSectorByFourBytes(RamConfigPtr, RamCheckCnt);
                break;
            case 8U:
                RamCheckStatus = Ram_Drv_CheckSectorByEightBytes(RamConfigPtr, RamCheckCnt);
                break;
            default:
                RamCheckStatus = FALSE;
                break;
        }
    }
    else
    {
        RamCheckStatus = FALSE;
    }

    return RamCheckStatus;
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief       Initializes RAM section.
 *
 * @param[in]   RamConfigPtr: Pointer to RAM section configuration.
 *
 * @return      Ram_Drv_StatusType: RAM status.
 *
 */
Ram_Drv_StatusType Ram_Drv_Init(const Ram_Drv_ConfigType *RamConfigPtr)
{
    Ram_Drv_StatusType RamStatus = RAM_DRV_STATUS_NOT_OK;

    if (NULL_PTR != RamConfigPtr)
    {
        if ((1U == RamConfigPtr->RamWriteSize) || (2U == RamConfigPtr->RamWriteSize) ||
            (4U == RamConfigPtr->RamWriteSize) || (8U == RamConfigPtr->RamWriteSize))
        {
            if (TRUE == Ram_Drv_InitSectionWithDefaultValue(RamConfigPtr))
            {
                if (TRUE == Ram_Drv_CheckSectionWithDefaultValue(RamConfigPtr))
                {
                    RamStatus = RAM_DRV_STATUS_OK;
                }
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }

    return RamStatus;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Ram_Drv */

/** @} end of group Mcu_Module */
