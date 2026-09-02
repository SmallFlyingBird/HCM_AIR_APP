/*
* @file    Fls_Mld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Fls_Mld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef FLS_MLD_H
#define FLS_MLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "Fls_Types.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION                                
==================================================================================================*/
#define FLS_MLD_VENDOR_ID             		  (180)
#define FLS_MLD_AR_REL_MAJOR_VER              (4)
#define FLS_MLD_AR_REL_MINOR_VER              (4)
#define FLS_MLD_AR_REL_REVISION_VER           (0)
#define FLS_MLD_SW_MAJOR_VER                  (2)
#define FLS_MLD_SW_MINOR_VER                  (3)
#define FLS_MLD_SW_PATCH_VER                  (0)
/*==================================================================================================
                                                DEFINES AND MACROS                                       
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS                                        
==================================================================================================*/
/*==================================================================================================
                                                ENUMS                                        
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES                                           
==================================================================================================*/
/**
 * @brief   Initializes the Flash module and device.
 * @details This function initializes the internal/extern flash device and the QSPI controller.
 * @param   void
 * @return  void
*/
void Fls_Mld_Init(void);

/**
 * @brief   Aborts the flash module and device.
 * @details This function aborts the internal/extern flash device operation.
 * @param   void
 * @return  void
 */
void Fls_Mld_AbortSuspended(void);

/**
 * @brief   Cancels the flash module operation.
 * @details This function cancels the internal/extern flash device operation.
 * @param   void
 * @return  void
 */
void Fls_Mld_Cancel(void);
/**
 * @brief Process ongoing erase or write hardware job.
 * @details        In case Async Operation is ongoing this function will complete the following job:
 *                 - Erase
 *                 - Erase on Interleaved sectors
 *                 - Write
 *                 - Erase blank Check
 * @param   void
 * @return  void
 */
void Fls_Mld_MainFunction( void );

/**
 * @brief  Route Fls read, blank check, compare job to appropriate lld functions.
 * @param[in]   SectorOffset  Offset of the sector to be read.
 * @param[in]   Length        Length of the data to be read.
 * @param[out]  JobDataDestPtr  Pointer to the target data buffer.
 * @param[in]   JobDataSrcPtr  Pointer to the job source data buffer.
 * @return  Fls_Lld_ReturnType
 */
Fls_Lld_ReturnType Fls_Mld_SectorRead(const Fls_AddressType SectorOffset,
                                     const Fls_AddressType Length,
                                     uint8 * JobDataDestPtr,
                                     const uint8 *JobDataSrcPtr
                                    );

/**
 * @brief   Route the erase job to appropriate Lld function.
 * @param   SectorOffset  Offset of the sector to be erased.
 * @param   PhysicalSectorSize   Physical sector length to be erased.
 * @param   Asynch   Asynchronous or synchronous write.
 * @return  Fls_Lld_ReturnType
 */
Fls_Lld_ReturnType Fls_Mid_SectorErase(const Fls_AddressType SectorOffset,
                                      const Fls_LengthType PhysicalSectorSize,
                                      const boolean Asynch
                                     );

/**
 * @brief   Route the write job to appropriate Lld function.
 * @param   SectorOffset  Offset of the sector to be written.
 * @param   Length   Length of the data to be written.
 * @param   DataPtr  Pointer to the data source to be written.
 * @param   Asynch   Asynchronous or synchronous write.
 * @return  Fls_Lld_ReturnType
 */
Fls_Lld_ReturnType Fls_Mld_SectorWrite(const Fls_AddressType SectorOffset,
                                      const Fls_AddressType Length,
                                      const uint8 *JobDataSrcPtr,
                                      const boolean Asynch
                                     );
#ifdef __cplusplus
}
#endif

#endif /* End of file Fls_Mld.h */
