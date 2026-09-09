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
#include "EcuM.h"
#include "LinIf.h"
#include "LinIf_Cbk.h"
#include "LinIf_Internal.h"
#include "LinIf_Slave.h"
#include "LinTp_Slave.h"
#include "LinTp_Internal.h"
#include "PduR_Callout.h"
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
    Std_ReturnType ret = E_NOT_OK;
    ret = LinIf_SlaveHeaderIndication(Channel, PduPtr);
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
    LinIf_SlaveRxIndication(Channel, Lin_SduPtr);
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
    LinIf_SlaveTxConfirmation(Channel);
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
    LinIf_SlaveLinErrorIndication(Channel, ErrorStatus);
}

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(
     NetworkHandleType channel
);

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(
     NetworkHandleType channel
);

static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle( void );

LinIf_StatusType LinIf_Status = LINIF_UNINIT;
LinIf_ConfigType* LinIf_ConfigPtr = NULL_PTR;
FUNC(void, LINIF_CODE) LinIf_Init
(
    LinIf_ConfigType* ConfigPtr
)
{
       /*@req <SWS_LinIf_00381>*/
	LinIf_ConfigPtr = ConfigPtr;

    LinIf_SlaveInit();

    /* Set the status of LINIF */
    LinIf_Status = LINIF_INIT;
}

FUNC(void, LINIF_CODE) LinIf_Side_Init(void)
{
    /*@req <SWS_LinIf_00371>,<SWS_LinIf_00373>*/

    PduR_SetLightSide(PduR_GetLightSide());

    LinIf_Init(&LinIf_PCConfig);
}


FUNC(Std_ReturnType, LINIF_CODE) LinIf_GotoSleep
(
    NetworkHandleType Channel
)
{
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

    LinIf_SlaveGotoSleep(ch);

    return E_OK;
}

FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup
(
    NetworkHandleType Channel
)
{
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    Std_ReturnType ret = E_NOT_OK;

    ret = LinIf_SlaveWakeUp(ch);

    return ret;
}

FUNC(void, LINIF_CODE) LinIf_MainFunction(void)
{
    LinIf_SlaveMainHandle();
}

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(
     NetworkHandleType channel
)
{
     NetworkHandleType idx = LINIF_NUMBER_OF_CHANNELS;

    if (LINIF_INIT == LinIf_Status)
    {
        for (idx = 0; idx < LINIF_NUMBER_OF_CHANNELS; idx++)
        {
        	if (LINIF_GET_COMM_NETWORK(idx) == channel)
            {
                return idx;
            }
        }
    }

    return idx;
}

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(
     NetworkHandleType channel
)
{
     NetworkHandleType idx = LINIF_NUMBER_OF_CHANNELS;

    if (LINIF_INIT == LinIf_Status)
    {
        for (idx = 0; idx < LINIF_NUMBER_OF_CHANNELS; idx++)
        {
        	if (LINIF_GET_LIN_CHANNEL_ID(idx) == channel)
            {
                return idx;
            }
        }
    }

    return idx;
}


static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle( void )
{
    uint8 ch;

    for (ch = 0u; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
    {
        LinIf_SlaveMainFunction(ch);
        LinTp_SlaveMainFunction(ch);
    }
}
/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

