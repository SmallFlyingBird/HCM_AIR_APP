/**************************************************************************************************/
/**
 * @file      : SchM_Dma.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Mcal Driver
 *  @{
 */

/** @addtogroup  Dma Driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Dma.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_DMA_C_VENDOR_ID                   0x00B3U
#define SCHM_DMA_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_DMA_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_DMA_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_DMA_C_SW_MAJOR_VERSION            1U
#define SCHM_DMA_C_SW_MINOR_VERSION            2U
#define SCHM_DMA_C_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and SchM_Dma header file are of the same vendor
 */
#if (SCHM_DMA_C_VENDOR_ID != SCHM_DMA_H_VENDOR_ID)
    #error "Vendor ID of SchM_Dma.c and SchM_Dma.h are different"
#endif
/**
 *  @brief Check if current file and SchM_Dma header file are of the same Autosar version
 */
#if ((SCHM_DMA_C_AR_RELEASE_MAJOR_VERSION != SCHM_DMA_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (SCHM_DMA_C_AR_RELEASE_MINOR_VERSION != SCHM_DMA_H_AR_RELEASE_MINOR_VERSION) ||               \
     (SCHM_DMA_C_AR_RELEASE_REVISION_VERSION != SCHM_DMA_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of SchM_Dma.h and SchM_Dma.c are different"
#endif

#if ((SCHM_DMA_C_SW_MAJOR_VERSION != SCHM_DMA_H_SW_MAJOR_VERSION) ||                               \
     (SCHM_DMA_C_SW_MINOR_VERSION != SCHM_DMA_H_SW_MINOR_VERSION) ||                               \
     (SCHM_DMA_C_SW_PATCH_VERSION != SCHM_DMA_H_SW_PATCH_VERSION))
    #error "Software Version of SchM_Dma.c and SchM_Dma.h are different"
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

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

void SchM_Enter_Dma_ChannelRequest(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Dma_ChannelRequest(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Dma_ClearIntStatus(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Dma_ClearIntStatus(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Dma_DmaChConfig(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Dma_DmaChConfig(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Dma_DmamuxChCfg(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Dma_DmamuxChCfg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Dma_DmaEie(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Dma_DmaEie(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Dma_DmaCprio(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Dma_DmaCprio(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Dma_DmaConfig(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Dma_DmaConfig(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group SchM_Dma_Public_Functions */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma Driver */
/** @} end of group Mcal Driver */
