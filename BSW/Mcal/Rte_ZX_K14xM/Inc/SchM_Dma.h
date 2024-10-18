/**************************************************************************************************/
/**
 * @file      : SchM_Dma.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_DMA_H
#define SCHM_DMA_H

/** @addtogroup  Mcal Driver
 *  @{
 */

/** @addtogroup  Dma Driver
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup SchM_Dma_Public_Defines
 *  @{
 */
#define SCHM_DMA_H_VENDOR_ID                   0x00B3U       
#define SCHM_DMA_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_DMA_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_DMA_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_DMA_H_SW_MAJOR_VERSION            1U
#define SCHM_DMA_H_SW_MINOR_VERSION            2U
#define SCHM_DMA_H_SW_PATCH_VERSION            1U
       
/** @} end of group SchM_Dma_Public_Defines */

/** @defgroup SchM_Dma_Public_FunctionDeclaration
 *  @{
 */     
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

extern void SchM_Enter_Dma_ChannelRequest(void);
extern void SchM_Exit_Dma_ChannelRequest(void);

extern void SchM_Enter_Dma_ClearIntStatus(void);
extern void SchM_Exit_Dma_ClearIntStatus(void);

extern void SchM_Enter_Dma_DmaChConfig(void);
extern void SchM_Exit_Dma_DmaChConfig(void);

extern void SchM_Enter_Dma_DmaConfig(void);
extern void SchM_Exit_Dma_DmaConfig(void);

extern void SchM_Enter_Dma_DmamuxChCfg(void);
extern void SchM_Exit_Dma_DmamuxChCfg(void);

extern void SchM_Enter_Dma_DmaEie(void);
extern void SchM_Exit_Dma_DmaEie(void);

extern void SchM_Enter_Dma_DmaCprio(void);
extern void SchM_Exit_Dma_DmaCprio(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group SchM_Dma_Public_FunctionDeclaration */

#ifdef __cplusplus
    }
#endif
        
/** @} end of group Dma Driver  */
/** @} end of group Mcal Driver */

#endif    /* SCHM_DMA_H */


