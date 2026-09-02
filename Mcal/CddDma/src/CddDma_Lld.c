/**
* @file    CddDma_Lld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations List
 * PRQA S 1891 Rule 10.7: If a composite expression is used as one operand of an operator in which the usual arithmetic conversions are performed then
 *                        the other operand shall not have wider essential type.
 * PRQA S 4524 Rule 10.1: Operands shall not be of an inappropriate essential type.
 * PRQA S 4559 Rule 10.1: Operands shall not be of an inappropriate essential type.
 * PRQA S 0404 Rule 1.3:  More than one read access to volatile objects between sequence points.
 * PRQA S 2985 Rule 2.2:  The operation here is redundant as the result's Value is always that of the left-hand operand.
 */

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "CddDma.h"
#include "CddDma_Lld_Reg.h"
#include "CddDma_Lld.h"
#include "SchM_CddDma.h"
#include "OsIf.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_LLD_VENDOR_ID_C                      (180)
#define CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CDDDMA_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define CDDDMA_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define CDDDMA_LLD_SW_MAJOR_VERSION_C               (2)
#define CDDDMA_LLD_SW_MINOR_VERSION_C               (3)
#define CDDDMA_LLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if Source file and CDDDMA_LLD header file are of the same vendor */
#if (CDDDMA_LLD_VENDOR_ID_C != CDDDMA_LLD_VENDOR_ID)
#error "CddDma_Lld.c and CddDma_Lld.h have different vendor ids"
#endif

/* Check if Source file and CDDDMA_LLD header file are of the same Autosar version */
#if (( CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_MINOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_REVISION_VERSION_C != CDDDMA_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Lld.c and CddDma_Lld.h are different"
#endif

/* Check if Source file and CDDDMA_LLD header file are of the same Software version */
#if (( CDDDMA_LLD_SW_MAJOR_VERSION_C != CDDDMA_LLD_SW_MAJOR_VERSION) || \
      ( CDDDMA_LLD_SW_MINOR_VERSION_C != CDDDMA_LLD_SW_MINOR_VERSION) || \
      ( CDDDMA_LLD_SW_PATCH_VERSION_C != CDDDMA_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma_Lld.c and CddDma_Lld.h are different"
#endif

/* Check if Source file and CddDma_Lld_Reg header file are of the same vendor */
#if (CDDDMA_LLD_VENDOR_ID_C != CDDDMA_LLD_REG_VENDOR_ID)
#error "CddDma_Lld.c and CddDma_Lld_Reg.h have different vendor ids"
#endif

/* Check if Source file and CddDma_Lld_Reg header file are of the same Autosar version */
#if (( CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_MINOR_VERSION_C != CDDDMA_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_REVISION_VERSION_C != CDDDMA_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Lld.c and CddDma_Lld_Reg.h are different"
#endif

/* Check if Source file and CddDma_Lld_Reg header file are of the same Software version */
#if (( CDDDMA_LLD_SW_MAJOR_VERSION_C != CDDDMA_LLD_REG_SW_MAJOR_VERSION) || \
      ( CDDDMA_LLD_SW_MINOR_VERSION_C != CDDDMA_LLD_REG_SW_MINOR_VERSION) || \
      ( CDDDMA_LLD_SW_PATCH_VERSION_C != CDDDMA_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma_Lld.c and CddDma_Lld_Reg.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
#define CDDDMA_START_SEC_CONST_UNSPECIFIED
#include "CddDma_MemMap.h"

/*! @brief Array of Base addresses for DMA instances. */
CDDDMA_CONST static volatile DMA_Type *const Dma_Base[DMA_INSTANCE_COUNT] = DMA_BASE_PTRS;

#define CDDDMA_STOP_SEC_CONST_UNSPECIFIED
#include "CddDma_MemMap.h"

/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
/*function previous declaration*/
static void Dma_Lld_IrqHandler(CddDma_ChannelType Channel);
static void Dma_Lld_Error_IrqHandler(uint8 Instance);
ISR(DMA0_IRQHandler);
ISR(DMA1_IRQHandler);
ISR(DMA2_IRQHandler);
ISR(DMA3_IRQHandler);
#if (DMA_CHMUX_COUNT > 4U)
ISR(DMA4_IRQHandler);
ISR(DMA5_IRQHandler);
ISR(DMA6_IRQHandler);
ISR(DMA7_IRQHandler);
#endif
#if (DMA_CHMUX_COUNT > 8U)
ISR(DMA8_IRQHandler);
ISR(DMA9_IRQHandler);
ISR(DMA10_IRQHandler);
ISR(DMA11_IRQHandler);
ISR(DMA12_IRQHandler);
ISR(DMA13_IRQHandler);
ISR(DMA14_IRQHandler);
ISR(DMA15_IRQHandler);
#endif
#if (DMA_CHMUX_COUNT > 16U)
ISR(DMA16_IRQHandler);
ISR(DMA17_IRQHandler);
ISR(DMA18_IRQHandler);
ISR(DMA19_IRQHandler);
ISR(DMA20_IRQHandler);
ISR(DMA21_IRQHandler);
ISR(DMA22_IRQHandler);
ISR(DMA23_IRQHandler);
ISR(DMA24_IRQHandler);
ISR(DMA25_IRQHandler);
ISR(DMA26_IRQHandler);
ISR(DMA27_IRQHandler);
ISR(DMA28_IRQHandler);
ISR(DMA29_IRQHandler);
ISR(DMA30_IRQHandler);
ISR(DMA31_IRQHandler);
#endif


#define CDDDMA_START_SEC_CODE
#include "CddDma_MemMap.h"

/*!
 * @brief Configures the DMA request for the DMAMUX Channel.
 *
 * @details Set the DMA Source routed to a DMA Channel.
 *
 * @param[in] Base    Register Base Address for DMAMUX module.
 * @param[in] Channel DMAMUX Channel number.
 * @param[in] Source  DMA request Source.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMAMUX_SetChannelSource(volatile DMA_Type *Base, uint8 Channel, uint8 Source)
{
    Base->CHMUX[Channel] = Source;
}

/*!
 * @brief Clear the DMA request for the DMAMUX Channel.
 *
 * @details Set the DMA Source routed to a Default Channel.
 *
 * @param[in] Base    Register Base Address for DMAMUX module.
 * @param[in] Channel DMAMUX Channel number.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMAMUX_ClearChannelSource(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CHMUX[Channel] = (uint8)DMA_REQ_DISABLED;
}

/*!
 * @brief Halts or does not halt the DMA module when an error occurs.
 *
 * @details Error causes the HALT bit to be set. Subsequently, all service requests are ignored until the
 *          HALT bit is cleared.
 *
 * @param[in] Base        Register Base Address for DMA module.
 * @param[in] HaltOnError Halts (true) or not halt (false) DMA module when an error occurs.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_SetHaltOnErrorCmd(volatile DMA_Type *Base, boolean HaltOnError)
{
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_POE_MASK;
    RegValTemp |= DMA_CTRL_POE(HaltOnError);
    Base->CTRL = RegValTemp;
}

/*!
 * @brief Enables/Disables the DMA Debug mode.
 *
 * @details
 *
 * @param[in] Base  Register Base Address for DMA module.
 * @param[in] Debug Enable (true) or disable (false) DMA module.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_SetDebugMode(volatile DMA_Type *Base, boolean Debug)
{
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_DBGDIS_MASK;
    RegValTemp |= DMA_CTRL_DBGDIS(Debug);
    Base->CTRL = RegValTemp;
}

/*!
 * @brief Enables/Disables the transfer loop mapping.
 *
 * @details This function enables/disables the transfer loop mapping feature.
 *          If enabled, the BCNT is redefined to include the individual Enable fields and the BCNT field. The
 *          individual Enable fields allow the transfer loop Offset to be applied to the Source Address, the
 *          destination Address, or both. The BCNT field is reduced when either Offset is enabled.
 *
 * @param[in] Base   Register Base Address for DMA module.
 * @param[in] Enable Enables (true) or Disable (false) transfer loop mapping.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_SetTransferLoopMappingCmd(volatile DMA_Type *Base, boolean Enable)
{
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_LOEN_MASK;
    RegValTemp |= DMA_CTRL_LOEN(Enable);
    Base->CTRL = RegValTemp;
}

/*!
 * @brief Configure error interrupt for channels.
 *
 * @param[in] Base    Register Base Address for DMAMUX module.
 * @param[in] Channel DMAMUX Channel number.
 * @param[in] Enable  Interrupt Enable or Disable
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_SetErrorIntCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    if (TRUE == Enable)
    {
        Base->CHEIE |= (uint32) 0x01U << Channel;
    }
    else
    {
        /* MR12 RULE 10.7 VIOLATION:  If a composite expression is used as one operand of an operator in which the usual arithmetic
         * conversions are performed then the other operand shall not have wider essential type. Couldn't adhere to M3CM Rule-10.7 in this case
         */
        Base->CHEIE &= ~(0x01U << Channel); /* PRQA S 1891 */
    }
}

/*!
 * @brief Enables/Disables the half complete interrupt for the CTS.
 *
 * @details If set, the Channel generates an interrupt request by setting the appropriate bit in the
 * interrupt register when the current major iteration Count reaches the halfway point. Specifically,
 * the comparison performed by the DMA engine is (TCNT == (TCNTRV >> 1)). This half-way point
 * interrupt request is provided to support the double-buffered schemes or other types of data movement
 * where the processor needs an early indication of the transfer's process.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Enable  Enable (true) /Disable (false) half complete interrupt.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_SetMajorHalfCompleteIntCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_THDINT_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_THDINT(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/*!
 * @brief Enables/Disables the interrupt after the trigger loop completes for the CTS.
 *
 * @details If enabled, the Channel generates an interrupt request by setting the appropriate bit in the
 * interrupt register when the current major iteration Count reaches zero.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Enable  Enable (true) /Disable (false) interrupt after CTS done.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetMajorCompleteIntCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_TDINT_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_TDINT(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/*!
 * @brief Configures DMA engine to stall for a number of Cycles after each R/W.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number..
 * @param[in] Cycles  Number of Cycles the DMA engine is stalled after each R/W.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetEngineStall(volatile DMA_Type *Base, uint8 Channel, CddDma_EngineStallType Cycles)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= ~DMA_CTS_CSR_BWC_MASK;
    RegValTemp |= (uint16)DMA_CTS_CSR_BWC(Cycles);
    Base->CTS[Channel].CSR = RegValTemp;
}

/*!
 * @brief Get CTS active bit Value of DMA Channel
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number..
 * @param[out] PValue  Active bit Value
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_GetCtsActiveStatus(const volatile DMA_Type *Base, uint8 Channel, boolean *PValue)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= DMA_CTS_CSR_ACTIVE_MASK;
    *PValue = (((RegValTemp >> DMA_CTS_CSR_ACTIVE_SHIFT) != 0U) ? TRUE : FALSE);
}

/*!
 * @brief Get CTS Done bit Value of DMA Channel
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number..
 * @param[out] PValue  Done bit Value
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_GetCtsDoneStatus(const volatile DMA_Type *Base, uint8 Channel, boolean *PValue)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= DMA_CTS_CSR_DONE_MASK;
    *PValue = (((RegValTemp >> DMA_CTS_CSR_DONE_SHIFT) != 0U) ? TRUE : FALSE);
}

/*!
 * @brief Gets the DMA error Status.
 *
 * @param[in] Base Register Base Address for DMA module.
 * @param[out] Value  ERS register's Value
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_GetErrorStatus(const volatile DMA_Type *Base, uint32 *Value)
{
    *Value = Base->ERS;
}

/*!
 * @brief Configures the Source Address for the hardware CTS.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Address The pointer to the Source memory Address.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetSrcAddr(volatile DMA_Type *Base, uint8 Channel, uint32 Address)
{
    Base->CTS[Channel].SADDR = Address;
}

/*!
 * @brief Configures the destination Address for the CTS.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Address The pointer to the destination Address.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetDestAddr(volatile DMA_Type *Base, uint8 Channel, uint32 Address)
{
    Base->CTS[Channel].DADDR = Address;
}

/*!
 * @brief Configures the destination Address signed Offset for the CTS.
 *
 * @details Sign-extended Offset applied to the current Source Address to form the next-state Value as each
 *          destination write is complete.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Offset  signed-Offset
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetDestOffset(volatile DMA_Type *Base, uint8 Channel, sint16 Offset)
{
    Base->CTS[Channel].DOFF = (uint16) Offset;
}

/*!
 * @brief Configures the Source Address signed Offset for the hardware CTS.
 *
 * @details Sign-extended Offset applied to the current Source Address to form the next-state Value as each
 *          Source read is complete.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Offset  signed-Offset for Source Address.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetSrcOffset(volatile DMA_Type *Base, uint8 Channel, sint16 Offset)
{
    Base->CTS[Channel].SOFF = (uint16) Offset;
}

/*!
 * @brief Configures the last Source Address adjustment for the CTS.
 *
 * @details Adjustment Value added to the Source Address at the completion of the major iteration Count. This
 *          Value can be applied to restore the Source Address to the initial Value, or Adjust the Address to
 *          reference the next data structure.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Size    adjustment Value
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetSrcLastAdjust(volatile DMA_Type *Base, uint8 Channel, sint32 Size)
{
    Base->CTS[Channel].STO = (uint32) Size;
}

/*!
 * @brief Configures the last dest Address adjustment.
 *
 * @details This function adds an adjustment Value added to the dest Address at the completion of the major
 *          iteration Count. This Value can be applied to restore the Source Address to the initial Value, or
 *          Adjust the Address to reference the next data structure.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Adjust  adjustment Value
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetDestLastAdjust(volatile DMA_Type *Base, uint8 Channel, sint32 Adjust)
{
    Base->CTS[Channel].DTO_RLD.DTO = (uint32) Adjust;
}

/*!
 * @brief Enables/Disables the ram reload feature for the CTS.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Enable  Enables (true) /Disables (false) ram reload feature.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetRamReloadCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_RLDEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_RLDEN(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/*!
 * @brief Configures the memory Address for the next transfer CTS for the CTS.
 *
 *
 * @details This function enables the ram reload feature for the CTS and configures the next
 *          CTS's Address. This Address points to the beginning of a 0-modulo-32 byte region containing
 *          the next transfer CTS to be loaded into this Channel. The Channel reload is performed as the
 *          major iteration Count completes. The ram reload Address must be 0-modulo-32-byte. Otherwise,
 *          a configuration error is reported.
 *
 * @param[in] Base        Register Base Address for DMA module.
 * @param[in] Channel     DMA Channel number.
 * @param[in] NextCTSAddr The Address of the next CTS to be linked to this CTS.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetRamReloadLink(volatile DMA_Type *Base, uint8 Channel, uint32 NextCTSAddr)
{
    Base->CTS[Channel].DTO_RLD.RLD = NextCTSAddr;
}

/*!
 * @brief Enables/disables the Source transfer loop Offset feature for the CTS.
 *
 * @details Configures whether the transfer loop Offset is applied to the Source Address
 *          upon transfer loop completion.
 * NOTE: EMLM bit needs to be enabled prior to calling this function, otherwise
 *       it has no effect.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Enable  Enables (true) or disables (false) Source transfer loop Offset.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetSrcMinorLoopOffsetCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    if (((Base->CTRL >> DMA_CTRL_LOEN_SHIFT) & 1U) != 0U)
    {
        uint32 RegValTemp;
        RegValTemp = Base->CTS[Channel].BCNT.LOEN;
        RegValTemp &= ~DMA_CTS_BCNT_LOEN_SLOE_MASK;
        RegValTemp |= DMA_CTS_BCNT_LOEN_SLOE(Enable); /*PRQA S 2985*/
        Base->CTS[Channel].BCNT.LOEN = RegValTemp;
    }
    else
    {
        /* Do nothing*/
    }
}

/*!
 * @brief Enables/disables the destination transfer loop Offset feature for the CTS.
 *
 * @details Configures whether the transfer loop Offset is applied to the destination Address
 *          upon transfer loop completion.
 * NOTE: EMLM bit needs to be enabled prior to calling this function, otherwise
 *       it has no effect.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Enable  Enables (true) or disables (false) destination transfer loop Offset.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetDstMinorLoopOffsetCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    if (((Base->CTRL >> DMA_CTRL_LOEN_SHIFT) & 1U) != 0U)
    {
        uint32 RegValTemp;
        RegValTemp = Base->CTS[Channel].BCNT.LOEN;
        RegValTemp &= ~DMA_CTS_BCNT_LOEN_DLOE_MASK;
        RegValTemp |= DMA_CTS_BCNT_LOEN_DLOE(Enable);
        Base->CTS[Channel].BCNT.LOEN = RegValTemp;
    }
    else
    {
        /* Do nothing*/
    }
}

/*!
 * @brief Configures the major Channel link of the CTS.
 *
 * @details If the major link is enabled, after the trigger loop counter is exhausted, the DMA engine initiates a
 *          Channel service request at the Channel defined at CTS CSR register.
 *
 * @param[in] Base             Register Base Address for DMA module.
 * @param[in] Channel          DMA Channel number.
 * @param[in] MajorLinkChannel Channel number for major link
 * @param[in] Enable           Enables (true) or Disables (false) Channel major link.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetChannelTriggerLink(volatile DMA_Type *Base, uint8 Channel, uint8 MajorLinkChannel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_TLKCH_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_TLKCH(MajorLinkChannel);
    Base->CTS[Channel].CSR = RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_TLKEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_TLKEN(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/*!
 * @brief Sets the major iteration Count according to transfer loop Channel link setting.
 *
 * NOTE: User need to first set the transfer loop Channel link and then call this function.
 *       The execute flow inside this function is dependent on the transfer loop Channel link setting.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Count   Trigger loop Count
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_CTSSetTriggerCount(volatile DMA_Type *Base, uint8 Channel, uint32 Count)
{
    uint16 RegValTemp;
    if (DMA_CTS_TCNT_LKDIS_LKEN_MASK == (Base->CTS[Channel].TCNTRV & DMA_CTS_TCNT_LKDIS_LKEN_MASK))
    {
        RegValTemp = Base->CTS[Channel].TCNTRV;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNTRV = RegValTemp;

        RegValTemp = Base->CTS[Channel].TCNT.LKEN;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNT.LKEN = RegValTemp;
    }
    else
    {
        RegValTemp = Base->CTS[Channel].TCNTRV;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKDIS_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKDIS_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNTRV = RegValTemp;

        RegValTemp = Base->CTS[Channel].TCNT.LKDIS;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKDIS_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKDIS_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNT.LKDIS = RegValTemp;
    }
}

/*!
 * @brief Gets the major iteration Count according to transfer loop Channel link setting.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 *
 * @return uint32 Trigger loop Count
 */
CDDDMA_FUNC LOCAL_INLINE uint32 DMA_CTSGetCurrentTriggerCount(const volatile DMA_Type *Base, uint8 Channel)
{
    uint16 TriggerCount = 0U;
    if (DMA_CTS_TCNT_LKDIS_LKEN_MASK == (Base->CTS[Channel].TCNTRV & DMA_CTS_TCNT_LKDIS_LKEN_MASK))
    {
        TriggerCount = (Base->CTS[Channel].TCNT.LKEN & DMA_CTS_TCNT_LKEN_TCNT_MASK) >> DMA_CTS_TCNT_LKEN_TCNT_SHIFT;
    }
    else
    {
        TriggerCount = (Base->CTS[Channel].TCNT.LKDIS & DMA_CTS_TCNT_LKDIS_TCNT_MASK) >> DMA_CTS_TCNT_LKDIS_TCNT_SHIFT;
    }
    return (uint32)TriggerCount;
}

/*!
 * @brief Disables/Enables the DMA request after the trigger loop completes for the CTS.
 *
 * @details If disabled, the DMA hardware automatically clears the corresponding DMA request when the
 *          current major iteration Count reaches zero.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Disable Disable (true)/Enable (false) DMA request after CTS complete.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_DisDmaReqAfterCTSDoneCmd(volatile DMA_Type *Base, uint8 Channel, boolean Disable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_DREQ_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_DREQ(Disable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/*!
 * @brief Clears the done Status for a Channel or all channels.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_ClearDoneStatusFlag(volatile DMA_Type *Base, uint8 Channel)
{
    Base->DONE = (uint32) 0x01U << Channel;
}

/*!
 * @brief Clears the interrupt Status for the DMA Channel.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_ClearIntStatusFlag(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CHTLDIF = (uint32) 0x01U << Channel;
    Base->CHTLHDIF = (uint32) 0x01U << Channel;
}

/*!
 * @brief Gets the DMA error interrupt Status.
 *
 * @param[in] Base Register Base Address for DMA module.
 *
 * @return 32 bit variable indicating error channels. If error happens on DMA Channel n, the bit n
 *         of this variable is '1'. If not, the bit n of this variable is '0'.
 */
CDDDMA_FUNC LOCAL_INLINE uint32 DMA_GetErrorIntStatusFlag(const volatile DMA_Type *Base)
{
    return Base->CHEIF;
}

/*!
 * @brief Clears the error interrupt Status for the DMA Channel or channels.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 *
 * @return void
 */
CDDDMA_FUNC LOCAL_INLINE void DMA_ClearErrorIntStatusFlag(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CHEIF = (uint32) 0x01U << Channel;
}

#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
/*!
 * @brief Clears the struct to zero state.
 *
 * @param[in] StructPtr The pointer to the struct which needs to be initialized.
 * @param[in] Size      Size for initialized.
 *
 * @return    void
 */
CDDDMA_FUNC static void DMA_ClearStructure(uint8 *StructPtr, uint32 Size)
{
    uint8 *TmpPtr = StructPtr;
    uint32 TmpSize = Size;

    while (TmpSize > 0U)
    {
        *TmpPtr = 0;
        ++TmpPtr;
        --TmpSize;
    }
}
#endif

/*!
 * @brief Sets registers to 0 for hardware CTS of DMA Channel.
 *
 * @param[in] Base   Register Base Address for DMA module.
 * @param[in] ChannelIndex The DMA Channel index.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_CTSClearReg(volatile DMA_Type *Base, uint8 ChannelIndex)
{
    Base->CTS[ChannelIndex].BCNT.BCNT = 0U;
    Base->CTS[ChannelIndex].SADDR = 0U;
    Base->CTS[ChannelIndex].SOFF = 0;
    Base->CTS[ChannelIndex].TCR = 0U;
    Base->CTS[ChannelIndex].STO = 0;
    Base->CTS[ChannelIndex].DADDR = 0U;
    Base->CTS[ChannelIndex].DOFF = 0;
    Base->CTS[ChannelIndex].TCNT.LKDIS = 0U;
    Base->CTS[ChannelIndex].DTO_RLD.DTO = 0;
    Base->CTS[ChannelIndex].CSR = 0U;
    Base->CTS[ChannelIndex].TCNTRV = 0U;
}

/*!
 * @brief Initializes DMA module to a known state
 *
 * @param[in] Base Register Base Address for DMA module.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_InstanceClear(volatile DMA_Type *Base)
{
    /* Clear the bit of CR register */
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_CLM_MASK;
    RegValTemp &= ~DMA_CTRL_CX_MASK;
    RegValTemp &= ~DMA_CTRL_ECX_MASK;
    RegValTemp &= ~DMA_CTRL_DBGDIS_MASK;
    RegValTemp &= ~DMA_CTRL_LOEN_MASK;
    Base->CTRL = RegValTemp;
    Base->CHEIE = 0x0;
    for (uint8 Channel = 0; Channel < CDDDMA_CHANNEL_CONFIG_COUNT; ++Channel)
    {
        /* Disables the DMA Channel request*/
        Dma_Lld_SetDmaRequestCmd(Channel, FALSE);
        /* Clears all registers of DMA->CTS */
        DMA_CTSClearReg(Base, Channel);
        /* Clear all DMA hardware request*/
        DMAMUX_ClearChannelSource(Base, Channel);
    }
}

/*!
 * @brief Set the DMA Source routed to a DMA Channel.
 *
 * @param[in] Channel DMAMUX Channel number.
 * @param[in] Source  DMA request Source.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_SetChannelSourceRequest(uint8 Channel, CddDma_RequestSourceType Source)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    /* Set request and the trigger*/
    DMAMUX_SetChannelSource(DmaRegBase, Channel, (uint8)Source);
}

/*!
 * @brief Disables/Enables the Channel interrupt requests.
 *
 * @param[in] Channel DMAMUX Channel number.
 * @param[in] IntSrc  Interrupt request type.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_ConfigChannelInterrupt(uint8 Channel, Dma_ChanInterruptType IntSrc)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];
    DMA_SetErrorIntCmd(DmaRegBase, Channel, IntSrc.EnErrInt);
    DMA_SetMajorHalfCompleteIntCmd(DmaRegBase, Channel, IntSrc.EnHalfMajorInt);
    DMA_CTSSetMajorCompleteIntCmd(DmaRegBase, Channel, IntSrc.EnMajorInt);
}

/*!
 * @brief Configures the transfer loop Offset to the CTS.
 *
 * @details Configures the Offset Value. If neither Source nor destination Offset is enabled,
 *          Offset is not configured.
 * NOTE: EMLM bit needs to be enabled prior to calling this function, otherwise it has no effect.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Offset  Minor loop Offset
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_CTSSetTransferLoopOffset(volatile DMA_Type *Base, uint8 Channel, sint32 Offset)
{
    uint32 RegValTemp;

    if (((Base->CTRL & DMA_CTRL_LOEN_MASK) >> DMA_CTRL_LOEN_SHIFT) != 0UL)
    {
        boolean MlOffNo = FALSE;

        if ((((Base->CTS[Channel].BCNT.LODIS & DMA_CTS_BCNT_LODIS_SLOE_MASK) >> DMA_CTS_BCNT_LODIS_SLOE_SHIFT) != 0UL) || \
                (((Base->CTS[Channel].BCNT.LODIS & DMA_CTS_BCNT_LODIS_DLOE_MASK) >> DMA_CTS_BCNT_LODIS_DLOE_SHIFT) != 0UL))
        {
            MlOffNo = TRUE;
        }

        if (TRUE == MlOffNo)
        {
            RegValTemp = Base->CTS[Channel].BCNT.LOEN;
            RegValTemp &= ~DMA_CTS_BCNT_LOEN_OFFSET_MASK;
            RegValTemp |= DMA_CTS_BCNT_LOEN_OFFSET(Offset);
            Base->CTS[Channel].BCNT.LOEN = RegValTemp;
        }
        else
        {
            /* Do nothing*/
        }
    }
    else
    {
        /* Do nothing*/
    }
}

/*!
 * @brief Configures the Nbytes to the DMA Channel.
 *
 * @details Note here that user needs firstly configure the transfer loop mapping feature and then call this
 *          function.
 *
 * @param[in] Base    Register Base Address for DMA module.
 * @param[in] Channel DMA Channel number.
 * @param[in] Nbytes  Number of bytes to be transferred in each service request of the Channel.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_CTSSetNbytes(volatile DMA_Type *Base, uint8 Channel, uint32 Nbytes)
{
    uint32 RegValTemp;

    if (((Base->CTRL & DMA_CTRL_LOEN_MASK) >> DMA_CTRL_LOEN_SHIFT) != 0UL)
    {
        boolean MlOffNo = FALSE;

        if (0UL == ((Base->CTS[Channel].BCNT.LODIS & DMA_CTS_BCNT_LODIS_SLOE_MASK) >> DMA_CTS_BCNT_LODIS_SLOE_SHIFT))
        {
            if (0UL == ((Base->CTS[Channel].BCNT.LODIS & DMA_CTS_BCNT_LODIS_DLOE_MASK) >> DMA_CTS_BCNT_LODIS_DLOE_SHIFT))
            {
                Base->CTS[Channel].BCNT.LODIS = (Nbytes & DMA_CTS_BCNT_LODIS_BCNT_MASK);
                MlOffNo = TRUE;
            }
            else
            {
                MlOffNo = FALSE;
            }
        }
        if (FALSE == MlOffNo)
        {
            RegValTemp = Base->CTS[Channel].BCNT.LOEN;
            RegValTemp &= ~DMA_CTS_BCNT_LOEN_BCNT_MASK;
            RegValTemp |= DMA_CTS_BCNT_LOEN_BCNT(Nbytes); /*PRQA S 2985*/
            Base->CTS[Channel].BCNT.LOEN = RegValTemp;
        }
    }
    else
    {
#if 0
        Base->CTS[Channel].BCNT.BCNT = Nbytes;
#endif
    }
}

/*!
 * @brief Sets the Channel minor link to the CTS.
 *
 * @param[in] Base        Register Base Address for DMA module.
 * @param[in] Channel     DMA Channel number.
 * @param[in] LinkChannel Channel to be linked on transfer loop complete.
 * @param[in] Enable      Enable (true)/Disable (false) Channel minor link.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_CTSSetChannelLoopLink(volatile DMA_Type *Base, uint8 Channel, uint8 LinkChannel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].TCNTRV;
    RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKEN(Enable);
    Base->CTS[Channel].TCNTRV = RegValTemp;
    RegValTemp = Base->CTS[Channel].TCNT.LKEN;
    RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKEN(Enable);
    Base->CTS[Channel].TCNT.LKEN = RegValTemp;

    if (TRUE == Enable)
    {
        RegValTemp = Base->CTS[Channel].TCNTRV;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKCH_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKCH(LinkChannel);
        Base->CTS[Channel].TCNTRV = RegValTemp;

        RegValTemp = Base->CTS[Channel].TCNT.LKEN;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKCH_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKCH(LinkChannel);
        Base->CTS[Channel].TCNT.LKEN = RegValTemp;
    }
}

/*!
 * @brief Configures the transfer attribute for the DMA Channel.
 *
 * @param[in] Base             Register Base Address for DMA module.
 * @param[in] Channel          DMA Channel number.
 * @param[in] SrcModulo        Enumeration type for an allowed Source modulo. The Value defines a specific Address range
 *                             specified as the Value after the SADDR + SOFF calculation is performed on the original register
 *                             Value. Setting this field provides the ability to implement a circular data. For data queues
 *                             requiring power-of-2 Size bytes, the queue should start at a 0-modulo-Size Address and the SMOD
 *                             field should be set to the appropriate Value for the queue, freezing the desired number of upper
 *                             Address bits. The Value programmed into this field specifies the number of the lower Address bits
 *                             allowed to change. For a circular queue application, the SOFF is typically set to the transfer
 *                             Size to implement post-increment addressing with SMOD function restricting the addresses to a
 *                             0-modulo-Size range.
 * @param[in] DestModulo       Enum type for an allowed destination modulo.
 * @param[in] SrcTransferSize  Enum type for Source transfer Size.
 * @param[in] DestTransferSize Enum type for destination transfer Size.
 *
 * @return void
 */
CDDDMA_FUNC static void DMA_CTSSetAttribute(volatile DMA_Type *Base, uint8 Channel, \
        CddDma_ModuloType SrcModulo, CddDma_ModuloType DestModulo, \
        CddDma_TransferSizeType SrcTransferSize, CddDma_TransferSizeType DestTransferSize)
{
    uint16 RegValTemp;
    RegValTemp = (uint16)(DMA_CTS_TCR_SMOD(SrcModulo) | DMA_CTS_TCR_SSIZE(SrcTransferSize));
    RegValTemp |= (uint16)(DMA_CTS_TCR_DMOD(DestModulo) | DMA_CTS_TCR_DSIZE(DestTransferSize)); /*PRQA S 2985*/
    Base->CTS[Channel].TCR = RegValTemp;
}

CDDDMA_FUNC void Dma_Lld_TransferCancel(void)
{
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    DmaRegBase = Dma_Base[0];
    DmaRegBase->CTRL |= DMA_CTRL_ECX_MASK;
}

/*!
 * @brief Copies the Channel configuration to the CTS registers.
 *
 * @param[in] Base      Register Base Address for DMA module.
 * @param[in] Channel   DMA Channel number.
 * @param[in] CtsConfig Pointer to the Channel transfer configuration structure.
 *
 * @return void
 */
CDDDMA_FUNC static void Dma_Lld_PushConfigToReg(volatile DMA_Type *Base, uint8 Channel, const CddDma_TransferConfigType *CtsConfig)
{
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_01();
    /* Configure the DMA Engine to stall for a number of Cycles after each R/W */
    DMA_CTSSetEngineStall(Base, Channel, CtsConfig->EngineStall);

    /* Set Source and destination addresses */
    DMA_CTSSetSrcAddr(Base, Channel, CtsConfig->SrcAddr);
    DMA_CTSSetDestAddr(Base, Channel, CtsConfig->DestAddr);
    /* Set Source/destination modulo feature and transfer Size */
    DMA_CTSSetAttribute(Base, Channel, CtsConfig->SrcModulo, CtsConfig->DestModulo,
                        CtsConfig->SrcTransferSize, CtsConfig->DestTransferSize);
    /* Set Source/destination Offset and last adjustment; for ram reload operation, destination
     * last adjustment is the Address of the next CTS structure to be loaded by the DMA engine */
    DMA_CTSSetSrcOffset(Base, Channel, CtsConfig->SrcOffset);
    DMA_CTSSetDestOffset(Base, Channel, CtsConfig->DestOffset);
    DMA_CTSSetSrcLastAdjust(Base, Channel, CtsConfig->SrcLastAddrAdjust);

    if (TRUE == CtsConfig->ChannelPollingMode)
    {
        DMA_SetErrorIntCmd(Base, Channel, FALSE);
        DMA_SetMajorHalfCompleteIntCmd(Base, Channel, FALSE);
        DMA_CTSSetMajorCompleteIntCmd(Base, Channel, FALSE);
    }
    else
    {
        DMA_SetErrorIntCmd(Base, Channel, TRUE);
        DMA_CTSSetMajorCompleteIntCmd(Base, Channel, TRUE);
    }

    if (TRUE == CtsConfig->RamReloadEnable)
    {
        DMA_CTSSetRamReloadCmd(Base, Channel, TRUE);
        DMA_CTSSetRamReloadLink(Base, Channel, CtsConfig->RamReloadNextDescAddr);
        DMA_CTSSetMajorCompleteIntCmd(Base, Channel, CtsConfig->RamReloadIntEnable);
    }
    else
    {
        DMA_CTSSetRamReloadCmd(Base, Channel, FALSE);
        DMA_CTSSetDestLastAdjust(Base, Channel, CtsConfig->DestLastAddrAdjust);
    }

    /* If loop configuration is available, copy transfer/trigger loop setup to registers */
    if (NULL_PTR != CtsConfig->LoopTransferConfig)
    {
        DMA_CTSSetSrcMinorLoopOffsetCmd(Base, Channel, CtsConfig->LoopTransferConfig->SrcOffsetEnable);
        DMA_CTSSetDstMinorLoopOffsetCmd(Base, Channel, CtsConfig->LoopTransferConfig->DestOffsetEnable);
        DMA_CTSSetTransferLoopOffset(Base, Channel, CtsConfig->LoopTransferConfig->TriggerLoopOffset);
        DMA_CTSSetNbytes(Base, Channel, CtsConfig->TransferLoopByteCount);

        DMA_CTSSetChannelLoopLink(Base, Channel, CtsConfig->LoopTransferConfig->TransferLoopChnLinkNumber,
                                  CtsConfig->LoopTransferConfig->TransferLoopChnLinkEnable);
        DMA_CTSSetChannelTriggerLink(Base, Channel, CtsConfig->LoopTransferConfig->TriggerLoopChnLinkNumber,
                                     CtsConfig->LoopTransferConfig->TriggerLoopChnLinkEnable);

        DMA_CTSSetTriggerCount(Base, Channel, CtsConfig->LoopTransferConfig->TriggerLoopIterationCount);
    }
    else
    {
        /* Set the number of trigger Count */
        DMA_CTSSetTriggerCount(Base, Channel, CtsConfig->TriggerCount);
        /* Set the number of data counts to be transferred in each trigger loop */
        DMA_CTSSetNbytes(Base, Channel, CtsConfig->TransferLoopByteCount);
    }

    DMA_DisDmaReqAfterCTSDoneCmd(Base, Channel, CtsConfig->DisableReqOnCompletion);

    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_01();
}

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
CDDDMA_FUNC CddDma_ReturnType Dma_Lld_Init(const CddDma_ConfigType *ConfigPtr)
{
    CddDma_ReturnType DmaIpStatus = DMA_IP_STATUS_SUCCESS;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 Channel;
    uint8 DmaInstance = 0;

    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_02();

    DmaRegBase = Dma_Base[DmaInstance];

    DMA_InstanceClear(DmaRegBase);
    /* Set configuration of 'Halt on error'*/
    DMA_SetHaltOnErrorCmd(DmaRegBase, ConfigPtr->HaltOnError);
    DMA_SetDebugMode(DmaRegBase, ConfigPtr->EnDebug);

    for (uint8 ChnCount = 0; ChnCount < ConfigPtr->ChannelCount; ++ChnCount)
    {
        Channel = (uint8)ConfigPtr->ChannelConfigPtr[ChnCount].VirtualChannel;
        if (TRUE != CddDma_State[Channel].ChannelEnable)
        {
            DMA_SetChannelSourceRequest(Channel, ConfigPtr->ChannelConfigPtr[ChnCount].RequestSource);
            DMA_ConfigChannelInterrupt(Channel, ConfigPtr->ChannelConfigPtr[ChnCount].ChanIntRequest);

            /* Copy and set configuration to global state */
            CddDma_State[Channel].ChannelEnable = TRUE;
            CddDma_State[Channel].Callback = ConfigPtr->ChannelConfigPtr[ChnCount].Callback;
            CddDma_State[Channel].CallbackParam = ConfigPtr->ChannelConfigPtr[ChnCount].CallbackParam;
            CddDma_State[Channel].Status = DMA_CHN_NORMAL;

            DmaIpStatus = DMA_IP_STATUS_SUCCESS;

        }
        else
        {
            DmaIpStatus = DMA_IP_STATUS_WRONG_STATE;
        }

    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_02();
    return DmaIpStatus;
}

CDDDMA_FUNC static void Dma_Software_DeInit(void)
{
    /*Asserted a software reset*/
    DMA_REST_VIA_IPC->CTRL |= (uint32)DMA_CTRL_SWRESET_MASK;
    /*De-assert the software reset*/
    DMA_REST_VIA_IPC->CTRL &= (uint32)(~DMA_CTRL_SWRESET_MASK);

}

CDDDMA_FUNC void Dma_Lld_Deinit(void)
{
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_03();
    Dma_Software_DeInit();
    /* Reset the channels state*/
    for (uint8 Channel = 0; Channel < CDDDMA_CHANNEL_CONFIG_COUNT; ++Channel)
    {
        CddDma_State[Channel].ChannelEnable = FALSE;
        CddDma_State[Channel].Callback = NULL_PTR;
        CddDma_State[Channel].CallbackParam = NULL_PTR;
        CddDma_State[Channel].Status = DMA_CHN_UNINIT;
    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_03();
}

CDDDMA_FUNC void Dma_Lld_SetDmaRequestCmd(uint8 Channel, boolean Enable)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 DmaActiveTimeout = 50U;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_10();
    /* Hardware clear of ReqEn causes inconsistent data writeback. It is necessary to add a DMA HALT,
     * then wait for several clock cycles before performing read and write operations.*/
    /* Halt DMA before changing the REQEN register*/
    DmaRegBase->CTRL |= 1UL << DMA_CTRL_PAUSE_SHIFT;
    /* Wait DMA active done*/
    while ((DmaRegBase->CTRL & DMA_CTRL_ACTIVE_MASK) != 0U)
    {
        --DmaActiveTimeout;
        if (0U == DmaActiveTimeout)
        {
            break;
        }
    }

    if (TRUE == Enable)
    {
        DmaRegBase->REQEN |= (0x01UL << Channel);
    }
    else
    {
        DmaRegBase->REQEN &= ~(0x01UL << Channel);
    }
    /* Resume DMA*/
    DmaRegBase->CTRL &= ~(1UL << DMA_CTRL_PAUSE_SHIFT);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_10();
}

CDDDMA_FUNC void Dma_Lld_TriggerChannelStart(uint8 Channel)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    DmaRegBase->CTS[Channel].CSR |= DMA_CTS_CSR_START_MASK;
}

CDDDMA_FUNC StatusType Dma_Lld_SetChannelTransfer(uint8 Channel, const CddDma_TransferConfigType *TransferConfig)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_04();
    DMA_SetTransferLoopMappingCmd(DmaRegBase, TRUE);
    /* Write the configuration in the transfer control descriptor registers */
    Dma_Lld_PushConfigToReg(DmaRegBase, Channel, TransferConfig);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_04();

    return E_OK;
}

CDDDMA_FUNC void Dma_Lld_GetChannelStatus(uint8 Channel, CddDma_ChannelStatusReturnType *ChannelStatus)
{
    const volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 DmaInstance;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_05();
    ChannelStatus->ChannelStateValue = CddDma_State[Channel].Status;

    DMA_GetCtsActiveStatus(DmaRegBase, Channel, &ChannelStatus->Active);
    DMA_GetCtsDoneStatus(DmaRegBase, Channel, &ChannelStatus->Done);
    DMA_GetErrorStatus(DmaRegBase, &ChannelStatus->Errors);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_05();
}

CDDDMA_FUNC void Dma_Lld_ClearChannelDoneStatus(uint8 Channel)
{
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 DmaInstance;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    DMA_ClearDoneStatusFlag(DmaRegBase, Channel);
}

CDDDMA_FUNC uint32 Dma_Lld_GetRemainingTriggerCount(uint8 Channel)
{
    uint32 TriggerCount = 0U;
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    TriggerCount = DMA_CTSGetCurrentTriggerCount(DmaRegBase, Channel);

    return TriggerCount;
}

#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1MC0)
#if 0
#ifdef __ARM_C6_C_YTM32B1MXX  /*For Keil compiler to avoid optimize*/
__attribute__((optnone))
#endif
#endif
CDDDMA_FUNC void Dma_Lld_PushConfigToScts(const CddDma_TransferConfigType *TransferConfig, CddDma_SoftwareCtsType *Scts)
{
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_06();
    DMA_ClearStructure((uint8 *) Scts, sizeof(CddDma_SoftwareCtsType));
    /* Set the software CTS fields */
    Scts->ATTR = (uint16)(DMA_CTS_TCR_SMOD(TransferConfig->SrcModulo) | DMA_CTS_TCR_SSIZE(TransferConfig->SrcTransferSize) |
                          DMA_CTS_TCR_DMOD(TransferConfig->DestModulo) | DMA_CTS_TCR_DSIZE(TransferConfig->DestTransferSize)); /*PRQA S 2985*/
    Scts->SADDR = TransferConfig->SrcAddr;
    Scts->SOFF = TransferConfig->SrcOffset;
    Scts->BCNT = TransferConfig->TransferLoopByteCount;
    Scts->STO = TransferConfig->SrcLastAddrAdjust;
    Scts->DADDR = TransferConfig->DestAddr;
    Scts->DOFF = TransferConfig->DestOffset;
    if (TRUE == TransferConfig->RamReloadEnable)
    {
        Scts->RamLoadAddr = (sint32) TransferConfig->RamReloadNextDescAddr;
    }
    else
    {
        Scts->RamLoadAddr = TransferConfig->DestLastAddrAdjust;
    }
    /* MR12 RULE 10.1 VIOLATION: Here a cast is made between an object pointer and an integer type.
     * In this specific case, it uses a bitwise operation to set a single bit in the register, thus, couldn't adhere to M3CM Rule-10.1
     */
    /* PRQA S 4559 EOF*/
    Scts->CSR = (uint16)(((uint32)(TransferConfig->RamReloadIntEnable) << DMA_CTS_CSR_TDINT_SHIFT) |
                         ((uint32)(TransferConfig->RamReloadEnable) << DMA_CTS_CSR_RLDEN_SHIFT) |
                         ((uint32)(TransferConfig->DisableReqOnCompletion) << DMA_CTS_CSR_DREQ_SHIFT));

    if (NULL_PTR != (TransferConfig->LoopTransferConfig))
    {
        Scts->TCNTRV = (uint16)TransferConfig->LoopTransferConfig->TriggerLoopIterationCount;
    }
    else
    {
        Scts->TCNT = (uint16)TransferConfig->TriggerCount;
    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_06();
}
#endif

CDDDMA_FUNC void Dma_Lld_InstallCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, void *Parameter)
{
    volatile CddDma_ChannelStateType *ChannelState;

    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_07();
    ChannelState = &CddDma_State[Channel];
    ChannelState->Callback = Callback;
    ChannelState->CallbackParam = Parameter;
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_07();
}

CDDDMA_FUNC void Dma_Lld_InstallErrorCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, void *Parameter)
{
    volatile CddDma_ChannelStateType *ChannelState;

    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_08();
    ChannelState = &CddDma_State[Channel];
    ChannelState->ErrorCallback = Callback;
    ChannelState->ErrorCallbackParam = Parameter;
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_08();
}

/*!
* @brief This function is IRQ handler for DMA driver.
* @details
*
* @param[in] Channel  DMA virtual Channel number.
*
* @return void
*/
CDDDMA_FUNC static void Dma_Lld_IrqHandler(CddDma_ChannelType Channel)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = Dma_Base[DmaInstance];

    /* Clear Done */
    DMA_ClearDoneStatusFlag(DmaRegBase, Channel);
    /* Clear the interrupt Status */
    DMA_ClearIntStatusFlag(DmaRegBase, Channel);

    if (NULL_PTR != CddDma_State[Channel].Callback)
    {
        /* Callback for interrupt */
        /* MR12 RULE 1.3 VIOLATION: More than one read access to volatile objects between sequence points.
         * couldn't adhere to M3CM Rule-1.3 in this case
         */
        CddDma_State[Channel].Callback(CddDma_State[Channel].CallbackParam); /* PRQA S 0404 */
    }
}

/*!
* @brief This function is the DMA Error IRQ handler for DMA driver.
* @details
*
* @param[in] Instance  DMA instance ID.
*
* @return void
*/
CDDDMA_FUNC static void Dma_Lld_Error_IrqHandler(uint8 Instance)
{
    volatile DMA_Type *DmaRegBase = NULL_PTR;

    uint32 ErrorStatus;

    DmaRegBase = Dma_Base[Instance];
    ErrorStatus = DMA_GetErrorIntStatusFlag(DmaRegBase);
    for (uint8 Channel = 0; Channel < CDDDMA_CHANNEL_CONFIG_COUNT; ++Channel)
    {
        /* MR12 RULE 10.7 VIOLATION:  If a composite expression is used as one operand of an operator in which the usual arithmetic conversions are
         * performed then the other operand shall not have wider essential type. Couldn't adhere to M3CM Rule-10.7 in this case.
         */
        if ((ErrorStatus & (1U << Channel)) != 0U)  /* PRQA S 1891 */
        {
            Dma_Lld_SetDmaRequestCmd(Channel, FALSE);

            SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_09();
            CddDma_State[Channel].Status = DMA_CHN_ERROR;
            SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_09();

            if (NULL_PTR != CddDma_State[Channel].ErrorCallback)
            {
                /* Callback for interrupt */
                /* MR12 RULE 1.3 VIOLATION: More than one read access to volatile objects between sequence points.
                 * Couldn't adhere to M3CM Rule-1.3 in this case.
                 */
                CddDma_State[Channel].ErrorCallback(CddDma_State[Channel].ErrorCallbackParam);  /* PRQA S 0404 */
            }
            DMA_ClearDoneStatusFlag(DmaRegBase, Channel);
            DMA_ClearIntStatusFlag(DmaRegBase, Channel);
            DMA_ClearErrorIntStatusFlag(DmaRegBase, Channel);
            break;
        }
    }
}

/*! @brief DMA Error IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA_Error_IRQHandler)
{
    Dma_Lld_Error_IrqHandler(0U);
}

/*! @brief DMA Channel 0 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA0_IRQHandler)
{
    Dma_Lld_IrqHandler(0U);
}

/*! @brief DMA Channel 1 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA1_IRQHandler)
{
    Dma_Lld_IrqHandler(1U);
}

/*! @brief DMA Channel 2 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA2_IRQHandler)
{
    Dma_Lld_IrqHandler(2U);
}

/*! @brief DMA Channel 3 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA3_IRQHandler)
{
    Dma_Lld_IrqHandler(3U);
}

#if (DMA_CHMUX_COUNT > 4U)

/*! @brief DMA Channel 4 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA4_IRQHandler)
{
    Dma_Lld_IrqHandler(4U);
}

/*! @brief DMA Channel 5 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA5_IRQHandler)
{
    Dma_Lld_IrqHandler(5U);
}

/*! @brief DMA Channel 6 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA6_IRQHandler)
{
    Dma_Lld_IrqHandler(6U);
}

/*! @brief DMA Channel 7 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA7_IRQHandler)
{
    Dma_Lld_IrqHandler(7U);
}

#endif /* (DMA_CHMUX_COUNT > 4U) */
#if (DMA_CHMUX_COUNT > 8U)

/*! @brief DMA Channel 8 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA8_IRQHandler)
{
    Dma_Lld_IrqHandler(8U);
}

/*! @brief DMA Channel 9 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA9_IRQHandler)
{
    Dma_Lld_IrqHandler(9U);
}

/*! @brief DMA Channel 10 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA10_IRQHandler)
{
    Dma_Lld_IrqHandler(10U);
}

/*! @brief DMA Channel 11 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA11_IRQHandler)
{
    Dma_Lld_IrqHandler(11U);
}

/*! @brief DMA Channel 12 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA12_IRQHandler)
{
    Dma_Lld_IrqHandler(12U);
}

/*! @brief DMA Channel 13 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA13_IRQHandler)
{
    Dma_Lld_IrqHandler(13U);
}

/*! @brief DMA Channel 14 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA14_IRQHandler)
{
    Dma_Lld_IrqHandler(14U);
}

/*! @brief DMA Channel 15 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA15_IRQHandler)
{
    Dma_Lld_IrqHandler(15U);
}

#endif /* (DMA_CHMUX_COUNT > 8U) */
#if (DMA_CHMUX_COUNT > 16U)
/*! @brief DMA Channel 16 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA16_IRQHandler)
{
    Dma_Lld_IrqHandler(16U);
}

/*! @brief DMA Channel 17 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA17_IRQHandler)
{
    Dma_Lld_IrqHandler(17U);
}

/*! @brief DMA Channel 18 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA18_IRQHandler)
{
    Dma_Lld_IrqHandler(18U);
}

/*! @brief DMA Channel 19 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA19_IRQHandler)
{
    Dma_Lld_IrqHandler(19U);
}

/*! @brief DMA Channel 20 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA20_IRQHandler)
{
    Dma_Lld_IrqHandler(20U);
}

/*! @brief DMA Channel 21 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA21_IRQHandler)
{
    Dma_Lld_IrqHandler(21U);
}

/*! @brief DMA Channel 22 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA22_IRQHandler)
{
    Dma_Lld_IrqHandler(22U);
}

/*! @brief DMA Channel 23 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA23_IRQHandler)
{
    Dma_Lld_IrqHandler(23U);
}

/*! @brief DMA Channel 24 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA24_IRQHandler)
{
    Dma_Lld_IrqHandler(24U);
}

/*! @brief DMA Channel 25 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA25_IRQHandler)
{
    Dma_Lld_IrqHandler(25U);
}

/*! @brief DMA Channel 26 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA26_IRQHandler)
{
    Dma_Lld_IrqHandler(26U);
}

/*! @brief DMA Channel 27 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA27_IRQHandler)
{
    Dma_Lld_IrqHandler(27U);
}

/*! @brief DMA Channel 28 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA28_IRQHandler)
{
    Dma_Lld_IrqHandler(28U);
}

/*! @brief DMA Channel 29 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA29_IRQHandler)
{
    Dma_Lld_IrqHandler(29U);
}

/*! @brief DMA Channel 30 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA30_IRQHandler)
{
    Dma_Lld_IrqHandler(30U);
}

/*! @brief DMA Channel 31 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA31_IRQHandler)
{
    Dma_Lld_IrqHandler(31U);
}
#endif /* (DMA_CHMUX_COUNT > 16U) */

#define CDDDMA_STOP_SEC_CODE
#include "CddDma_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file CddDma_Lld.c */

