/**
 * @file    LinIf.c
 * @version
 *
 * @brief   AUTOSAR LinIf module interface
 * @details API implementation for LINIF driver
 *
 * @addtogroup LINIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : LinIf
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Dio_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Dio_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */



/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "LinIf.h"
#include "EcuM.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINIF_VENDOR_ID_C                      (0xB4)
#define LINIF_AR_RELEASE_MAJOR_VERSION_C       (4)
#define LINIF_AR_RELEASE_MINOR_VERSION_C       (4)
#define LINIF_AR_RELEASE_REVISION_VERSION_C    (0)
#define LINIF_SW_MAJOR_VERSION_C               (2)
#define LINIF_SW_MINOR_VERSION_C               (3)
#define LINIF_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and LINIF header file are of the same vendor */
#if (LINIF_VENDOR_ID_C != LINIF_VENDOR_ID)
#error "LinIf.c and LinIf.h have different vendor ids"
#endif

/* Check if source file and LINIF header file are of the same Autosar version */
#if ((LINIF_AR_RELEASE_MAJOR_VERSION_C != LINIF_AR_RELEASE_MAJOR_VERSION) || \
     (LINIF_AR_RELEASE_MINOR_VERSION_C != LINIF_AR_RELEASE_MINOR_VERSION) || \
     (LINIF_AR_RELEASE_REVISION_VERSION_C != LINIF_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of LinIf.c and LinIf.h are different"
#endif

/* Check if source file and LINIF header file are of the same Software version */
#if ((LINIF_SW_MAJOR_VERSION_C != LINIF_SW_MAJOR_VERSION) || \
     (LINIF_SW_MINOR_VERSION_C != LINIF_SW_MINOR_VERSION) || \
     (LINIF_SW_PATCH_VERSION_C != LINIF_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of LinIf.c and LinIf.h are different"
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief            Will be called when the EcuM has been notified about a wakeup on a specific LIN channel.
 * @param[in]        EcuM_WakeupSourceType Source device, which initiated the wakeup event: LIN controller or LIN transceiver
 * @return           Std_ReturnType
 */
__attribute__((weak)) Std_ReturnType LinIf_CheckWakeup (EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
    return E_OK;
}


/**
 * @brief            The LIN Driver or LIN Transceiver Driver will call this function to report the wake up source after the
                     successful wakeup detection during CheckWakeup or after power on by bus.
 * @param[in]        EcuM_WakeupSourceType Source device which initiated the wakeup event: LIN controller or LIN transceiver
 * @return           void
 */
__attribute__((weak)) void LinIf_WakeupConfirmation (EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
}

/**
 * @brief           The LIN Driver will call this function to report a received LIN header. This
 *                  function is only applicable for LIN slave nodes (available only if the ECU has
 *                  any LIN slave channel).
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @param[in]       Lin_PduType LIN Frame information.
 * @return          Std_ReturnType
 */
__attribute__((weak)) Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType* PduPtr)
{
    (void)Channel;
    (void)PduPtr;
    return E_OK;
}

/**
 * @brief           The LIN Driver will call this function to report a successfully received
 *                  response and provides the reception data to the LIN Interface. This function
 *                  is only applicable for LIN slave nodes (available only if the ECU has any LIN
 *                  slave channel).
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @param[in]       uint8* Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *                  receive buffer where the current SDU is stored. This pointer is only valid if
 *                  the response is received.
 * @return          void
 */
__attribute__((weak)) void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr)
{
    (void)Channel;
    (void)Lin_SduPtr;
}

/**
 * @brief           The LIN Driver will call this function to report a successfully transmitted
 *                  response. This function is only applicable for LIN slave nodes (available only
 *                  if the ECU has any LIN slave channel).
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @return          void
 */
__attribute__((weak)) void LinIf_TxConfirmation(NetworkHandleType Channel)
{
    (void)Channel;
}

/**
 * @brief           The LIN Driver will call this function to report a detected error event during
 *                  header or response processing. This function is only applicable for LIN slave
 *                  nodes (available only if the ECU has any LIN slave channel).
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @param[in]       Lin_SlaveErrorType Type of detected error.
 * @return          void
 */
__attribute__((weak)) void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus)
{
    (void)Channel;
    (void)ErrorStatus;
}

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

