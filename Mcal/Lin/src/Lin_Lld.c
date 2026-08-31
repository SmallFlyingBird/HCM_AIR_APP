/**
 * @file    Lin_Lld.c
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin Driver Interface
 * @details API implementation for LIN driver
 *
 * @addtogroup LIN_DRIVER
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lin
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
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Lin_Lld.h"
#include "SchM_Lin.h"
#include "Lin_Cfg.h"
#include "EcuM.h"
#include "LinIf.h"
#include "OsIf.h"
#include "pSIP_Linflexd.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_LLD_VENDOR_ID_C                      (180)
#define LIN_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define LIN_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define LIN_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define LIN_LLD_SW_MAJOR_VERSION_C               (2)
#define LIN_LLD_SW_MINOR_VERSION_C               (3)
#define LIN_LLD_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and LIN header file are of the same vendor */
#if (LIN_LLD_VENDOR_ID_C != LIN_LLD_VENDOR_ID)
#error "Lin_Lld.c have different vendor ids"
#endif

/* Check if source file and LIN header file are of the same Autosar version */
#if ((LIN_LLD_AR_RELEASE_MAJOR_VERSION_C != LIN_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_LLD_AR_RELEASE_MINOR_VERSION_C != LIN_LLD_AR_RELEASE_MINOR_VERSION) || \
     (LIN_LLD_AR_RELEASE_REVISION_VERSION_C != LIN_LLD_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lin_Lld.c are different"
#endif

/* Check if source file and LIN header file are of the same Software version */
#if ((LIN_LLD_SW_MAJOR_VERSION_C != LIN_LLD_SW_MAJOR_VERSION) || \
     (LIN_LLD_SW_MINOR_VERSION_C != LIN_LLD_SW_MINOR_VERSION) || \
     (LIN_LLD_SW_PATCH_VERSION_C != LIN_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lin_Lld.c are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL CONSTANTS
==================================================================================================*/
#define LIN_START_SEC_CONST_8
#include "Lin_MemMap.h"

#if (LIN_SLAVE_API_SUPPORT == STD_ON)
LIN_CONST static const uint8 LinPidTable[64] =
{
    0x80U, 0xC1U, 0x42U, 0x03U, 0xC4U, 0x85U, 0x06U, 0x47U,
    0x08U, 0x49U, 0xCAU, 0x8BU, 0x4CU, 0x0DU, 0x8EU, 0xCFU,
    0x50U, 0x11U, 0x92U, 0xD3U, 0x14U, 0x55U, 0xD6U, 0x97U,
    0xD8U, 0x99U, 0x1AU, 0x5BU, 0x9CU, 0xDDU, 0x5EU, 0x1FU,
    0x20U, 0x61U, 0xE2U, 0xA3U, 0x64U, 0x25U, 0xA6U, 0xE7U,
    0xA8U, 0xE9U, 0x6AU, 0x2BU, 0xECU, 0xADU, 0x2EU, 0x6FU,
    0xF0U, 0xB1U, 0x32U, 0x73U, 0xB4U, 0xF5U, 0x76U, 0x37U,
    0x78U, 0x39U, 0xBAU, 0xFBU, 0x3CU, 0x7DU, 0xFEU, 0xBFU
};
#endif

LIN_CONST static const uint32 LinIferTable[17] =
{
    0x0000U,
    0x0001U, 0x0003U, 0x0007U, 0x000FU, 0x001FU, 0x003FU, 0x007FU, 0x00FFU,
    0x01FFU, 0x03FFU, 0x07FFU, 0x0FFFU, 0x1FFFU, 0x3FFFU, 0x7FFFU, 0xFFFFU
};

#define LIN_STOP_SEC_CONST_8
#include "Lin_MemMap.h"

/*==================================================================================================
 *                                       LOCAL VARIABLES
==================================================================================================*/
#if defined(UNIT_TEST)
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"
LIN_VAR static volatile LINFlexD_Type * Lin_LocBasePtrs[LIN_CHANNEL_MAX_NUM] = LINFlexD_BASE_PTRS;
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"/*memory map finish*/
#else
#define LIN_START_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"
/* MAX NUM is necessary because of 6 hardware instances */
LIN_CONST static volatile LINFlexD_Type * const Lin_LocBasePtrs[LIN_CHANNEL_MAX_NUM] = LINFlexD_BASE_PTRS;
#define LIN_STOP_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"/*memory map finish*/
#endif

#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"
/**
 * @brief          LIN global channels configuration pointer
 */
LIN_VAR static const Lin_ChConfigType * Lin_GlobalChConfigPtrs[LIN_CHANNEL_USED_NUM];

LIN_VAR static const uint8 * Lin_LocInstMapPtr;

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"/*memory map finish*/

#define LIN_START_SEC_VAR_CLEARED_32
#include "Lin_MemMap.h"
LIN_VAR static volatile uint32 Lin_LocLatchedStatusRegs[LIN_CHANNEL_USED_NUM];

#define LIN_STOP_SEC_VAR_CLEARED_32
#include "Lin_MemMap.h"/*memory map finish*/

#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"
/**
 * @brief          LIN driver wakeup flag array.
 */
LIN_VAR static boolean Lin_LocWakeupReq[LIN_CHANNEL_USED_NUM];

/**
 * @brief          LIN driver header commands array.
 */
LIN_VAR static Lin_DrvCommandType Lin_LocTxHeaderCommands[LIN_CHANNEL_USED_NUM];

/**
 * @brief          LIN driver frame error states array for all channels.
 */
LIN_VAR static Lin_DrvErrorType Lin_LocChFrameErrorStates[LIN_CHANNEL_USED_NUM];

/**
 * @brief          LIN driver frame states array for all channels.
 */
LIN_VAR static Lin_DrvStateType Lin_LocChFrameStates[LIN_CHANNEL_USED_NUM];

/**
 * @brief          LIN driver channel node mode array for all channels.
 */
LIN_VAR static Lin_LinNodeModeType Lin_LocNodeMode[LIN_CHANNEL_USED_NUM];

/**
 * @brief          Lin driver wakeup byte for all channels.
 */
LIN_VAR static uint8 Lin_LocWakeupByte[LIN_CHANNEL_USED_NUM];

/**
 * @brief          LIN driver states array for all channels.
 */
extern LIN_VAR Lin_DrvStateType Lin_ChStates[LIN_CHANNEL_USED_NUM];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"/*memory map finish*/

/*==================================================================================================
 *                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_MASTER_API_SUPPORT == STD_ON)
LIN_FUNC LOCAL_INLINE uint8 Lin_Lld_LocGetLinDataLength(volatile const LINFlexD_Type * Base);
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */
LIN_FUNC LOCAL_INLINE Std_ReturnType Lin_Lld_LocTransmittionAbort(volatile LINFlexD_Type * Base);
LIN_FUNC LOCAL_INLINE Std_ReturnType Lin_Lld_LocAbortingState(volatile const LINFlexD_Type * Base);

LIN_FUNC void Lin_Lld_LocRxTxIntHandler(const uint8 HwChannel);
LIN_FUNC void Lin_Lld_LocErrorIntHandler(const uint8 HwChannel);
#ifdef LINFLEXD_IP_0_LIN_OCCUPY
#ifdef LINFlexD0_BASE_ADDR32
LIN_FUNC ISR(LINFlexD0_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_1_LIN_OCCUPY
#ifdef LINFlexD1_BASE_ADDR32
LIN_FUNC ISR(LINFlexD1_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_2_LIN_OCCUPY
#ifdef LINFlexD2_BASE_ADDR32
LIN_FUNC ISR(LINFlexD2_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_3_LIN_OCCUPY
#ifdef LINFlexD3_BASE_ADDR32
LIN_FUNC ISR(LINFlexD3_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_4_LIN_OCCUPY
#ifdef LINFlexD4_BASE_ADDR32
LIN_FUNC ISR(LINFlexD4_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_5_LIN_OCCUPY
#ifdef LINFlexD5_BASE_ADDR32
LIN_FUNC ISR(LINFlexD5_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_6_LIN_OCCUPY
#ifdef LINFlexD6_BASE_ADDR32
LIN_FUNC ISR(LINFlexD6_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_7_LIN_OCCUPY
#ifdef LINFlexD7_BASE_ADDR32
LIN_FUNC ISR(LINFlexD7_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_8_LIN_OCCUPY
#ifdef LINFlexD8_BASE_ADDR32
LIN_FUNC ISR(LINFlexD8_IRQHandler);
#endif
#endif
#ifdef LINFLEXD_IP_9_LIN_OCCUPY
#ifdef LINFlexD9_BASE_ADDR32
LIN_FUNC ISR(LINFlexD9_IRQHandler);
#endif
#endif

/*==================================================================================================
 *                                    LOCAL INLINE FUNCTION
==================================================================================================*/

LIN_FUNC LOCAL_INLINE void Lin_Lld_LocDisgardData(volatile LINFlexD_Type * Base)
{
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_06();
    Base->LINCR2 |= LINFlexD_LINCR2_DDRQ_MASK;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_06();
}

#if (LIN_MASTER_API_SUPPORT == STD_ON)

LIN_FUNC LOCAL_INLINE void Lin_Lld_LocHeaderTx(volatile LINFlexD_Type * Base)
{
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_07();
    Base->LINCR2 |= LINFlexD_LINCR2_HTRQ_MASK;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_07();
}

LIN_FUNC LOCAL_INLINE uint8 Lin_Lld_LocGetLinDataLength(volatile const LINFlexD_Type * Base)
{
    return (uint8)(((Base->BIDR & LINFlexD_BIDR_DFL_MASK) >> LINFlexD_BIDR_DFL_SHIFT) + 1U);
}
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

LIN_FUNC void Lin_Lld_LocGoToSleep(const uint8 Channel)
{
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_10();
    /* Release message buffer */
    Base->LINSR = LINFlexD_LINSR_RMB_MASK;
    /* Enter sleep mode */
    Base->LINCR1 |= LINFlexD_LINCR1_SLEEP_MASK;
    Base->LINSR = LINFlexD_LINSR_WUF_MASK;
    /* Enable wakeup interrupt */
    Base->LINIER |= LINFlexD_LINIER_WUIE_MASK;
    /* Reset header command type */
    Lin_LocTxHeaderCommands[Channel] = LIN_DRV_TX_NO_CMD;
    /* Reset error status flag */
    Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NO_ERROR;
    /* Set LIN channel frame state to default not ready */
    Lin_LocChFrameStates[Channel] = LIN_DRV_CH_SLEEP;
    Lin_LocWakeupReq[Channel] = FALSE;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_10();
    Lin_ChStates[Channel] = LIN_DRV_CH_SLEEP;
}

LIN_FUNC LOCAL_INLINE uint8 Lin_Lld_LocGetWakeupByte(const uint32 Baudrate)
{
    uint32 Tmp32;
    uint8 Tmp8;
    uint8 RetVal;
    Tmp32 = LIN_CONST_PARA_BYTE_US_TIME_DIVIDEND / Baudrate; /*us per byte*/
    Tmp32 = LIN_CONST_PARA_400US_DIVIDEND / Tmp32; /* Low Level bits number for wakeup by Baudrate, 400us to 1000us */
    Tmp8 = (uint8)Tmp32;
    if(0U < Tmp8)
    {
        RetVal = (uint8)LIN_CONST_CONST_WHOLE_OF_BYTE_ALL_TRUE << Tmp8;
    }
    else
    {
        RetVal = (uint8)LIN_CONST_CONST_WHOLE_OF_BYTE_ALL_TRUE;
    }
    return RetVal;
}

LIN_FUNC LOCAL_INLINE Std_ReturnType Lin_Lld_LocAbortingState(volatile const LINFlexD_Type * Base)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 Index = 0U;
    /* wait frame transmission aborted */
    while((LINFlexD_LINCR2_ABRQ_MASK == (LINFlexD_LINCR2_ABRQ_MASK & Base->LINCR2)) && (Index < (uint32)LIN_TIMEOUT_DURATION))
    {
        ++Index;
    }
    if(Index < (uint32)LIN_TIMEOUT_DURATION)
    {
        RetVal = E_OK;
    }
    return RetVal;
}

LIN_FUNC LOCAL_INLINE Std_ReturnType Lin_Lld_LocTransmittionAbort(volatile LINFlexD_Type * Base)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_04();
    /* request to abort previous transmission */
    Base->LINCR2 |= LINFlexD_LINCR2_ABRQ_MASK;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_04();
    if (E_OK == Lin_Lld_LocAbortingState(Base))
    {
        RetVal = E_OK;
    }
    return RetVal;
}

LIN_FUNC LOCAL_INLINE void Lin_Lld_LocWakeup(const uint8 Channel)
{
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00();
    /* Clear sleep bit */
    Base->LINCR1 &= ~LINFlexD_LINCR1_SLEEP_MASK;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();
}

LIN_FUNC LOCAL_INLINE void Lin_Lld_LocDisableWUIE(const uint8 Channel)
{
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_01();
    Base->LINSR = LINFlexD_LINSR_WUF_MASK;
    /* Disable wakeup interrupt */
    Base->LINIER &= ~LINFlexD_LINIER_WUIE_MASK;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_01();
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

LIN_FUNC void Lin_Lld_SetDrvReady(const uint8 Channel)
{
    Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
}

LIN_FUNC void Lin_Lld_SetInstMap(const uint8 * LinInstMapPtr)
{
    Lin_LocInstMapPtr = LinInstMapPtr;
}

LIN_FUNC void Lin_Lld_InitChannel(const uint8 Channel, const Lin_ConfigType * LinCfgPtr)
{
    uint8 BreakLength;
    uint8 DetectBreakLength;
    uint32 TmpBaudrate;
    uint32 TmpIbr;
    uint32 TmpFbr;
    Lin_GlobalChConfigPtrs[Channel] = &(LinCfgPtr->LinChConfigPtrs[Channel]);
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    Lin_GlobalChConfigPtrs[Channel] = &(LinCfgPtr->LinChConfigPtrs[Channel]);
    /* Reset latched interrupt status */
    Lin_LocLatchedStatusRegs[Channel] = 0U;
    BreakLength = (uint8)Lin_GlobalChConfigPtrs[Channel]->LinChBreakLength;
    Lin_LocNodeMode[Channel] = Lin_GlobalChConfigPtrs[Channel]->LinNodeMode;
    /*Slave: CR1.BF, HRF interrupt, and Filter init*/
    DetectBreakLength = (uint8)Lin_GlobalChConfigPtrs[Channel]->LinDetectBreakLength;

    /* Switch to init mode */
    Base->LINCR1 = LINFlexD_LINCR1_INIT_MASK;
    Lin_LocWakeupByte[Channel] = Lin_Lld_LocGetWakeupByte((uint32)Lin_GlobalChConfigPtrs[Channel]->LinBaudrateRegValue);
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_05();
    /* Write init value */
    /* Checksum calculation by hardware */
    /* Checksum field is sent automatically */
    /* Disable LIN auto synchronization mode */
    /* Disable LIN loop back mode */
    /* Disable auto wakeup function */

    /* Enable Master or Slave mode */
    Base->LINCR1 |= (LINFlexD_LINCR1_MME((uint8)Lin_LocNodeMode[Channel]) |  /*NOSONAR,no memory overruns here*/
                     LINFlexD_LINCR1_BF(1U) |            /* Bypass ID filter */
                     LINFlexD_LINCR1_SSBL(DetectBreakLength) |  /* Slave mode sync break length */
                     LINFlexD_LINCR1_MBL(BreakLength)); /* Break length */
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_05();
    Base->LINCR2 = LINFlexD_LINCR2_TBDE(1U) |   /* Set 2 bits for the break delimiter */
                   LINFlexD_LINCR2_IOBE(1U) |   /* Bit error reset LIN state machine. */
                   LINFlexD_LINCR2_IOPE(1U) ;   /* Parity error reset LIN state machine. */
    /* Baudrate configuration */
    TmpBaudrate = Lin_GlobalChConfigPtrs[Channel]->LinBaudrateRegValue;
    TmpBaudrate = (Lin_GlobalChConfigPtrs[Channel]->LinClockRef) / TmpBaudrate;
    TmpIbr = TmpBaudrate / (uint32)LIN_CONST_DECIMAL_BITS;
    TmpFbr = TmpBaudrate % (uint32)LIN_CONST_DECIMAL_BITS;
    Base->LINIBRR = TmpIbr;
    Base->LINFBRR = TmpFbr;
#if (LIN_FRAME_TIMEOUT_DISABLE == STD_OFF)
    Base->LINTCSR = LINFlexD_LINTCSR_IOT(1U) |  /* LIN state reset when timeout */
                    LINFlexD_LINTCSR_TOCE(1U) | /* Timer Enable */
                    LINFlexD_LINTCSR_MODE(1U);  /* Timer under LIN mode */
    Base->LINTOCR = LINFlexD_LINOCR_OC2(0xFFU) |
                    LINFlexD_LINOCR_OC1(0xFFU);
    Base->LINTCSR = LINFlexD_LINTCSR_IOT(1U) |  /* LIN state reset when timeout */
                    LINFlexD_LINTCSR_TOCE(1U) | /* Timer Enable */
                    LINFlexD_LINTCSR_MODE(0U);  /* Timer under LIN mode */
#else
    Base->LINTCSR = LINFlexD_LINTCSR_IOT(0U) |  /* LIN state won't reset when timeout */
                    LINFlexD_LINTCSR_TOCE(0U) | /* Timer disable */
                    LINFlexD_LINTCSR_MODE(1U);  /* Timer under output compare mode */
#endif /* LIN_FRAME_TIMEOUT_DISABLE == STD_OFF */
    /* Response and header timeout value */
    Base->LINTOCR = LINFlexD_LINTOCR_RTO(Lin_GlobalChConfigPtrs[Channel]->ResponseTimeoutValue) | \
                    (Lin_GlobalChConfigPtrs[Channel]->HeaderTimeoutValue);/*NOSONAR,no memory overruns here*/
    /*                LINFlexD_LINTOCR_HTO(Lin_GlobalChConfigPtrs[Channel]->HeaderTimeoutValue); */
    /* update Write default,can not change the register */
    /* config Lin filter when the channel is configured as a SLAVE node */
    Base->IFER = 0x00000000U;
    if ((LIN_SLAVE_MODE == Lin_LocNodeMode[Channel]) && \
            (TRUE == Lin_GlobalChConfigPtrs[Channel]->LinFilterEnable))
    {
        Base->IFER = LinIferTable[Lin_GlobalChConfigPtrs[Channel]->LinFilterNum];
        for(uint8 Index = 0U; Index < Lin_GlobalChConfigPtrs[Channel]->LinFilterNum; ++Index)
        {
            Base->IFCR[Index] = Lin_GlobalChConfigPtrs[Channel]->LinFilterIdPtr[Index];
        }
    }
    /* Clear previous status */
    Base->LINSR = Base->LINSR;
    /* Exit initialization mode */
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_02();
    /* Exit init mode */
    Base->LINCR1 &= ~LINFlexD_LINCR1_INIT_MASK;
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_02();
    /* Configure interrupt */
    Base->LINIER =  LINFlexD_LINIER_HEIE_MASK |  /* Header error interrupt enable */
                    LINFlexD_LINIER_BEIE_MASK |  /* Bit error interrupt enable */
                    LINFlexD_LINIER_CEIE_MASK |  /* Checksum error interrupt enable */
                    LINFlexD_LINIER_FEIE_MASK |  /* Frame error interrupt enable */
                    LINFlexD_LINIER_BOIE_MASK |  /* Buffer overrun interrupt enable */
                    LINFlexD_LINIER_DRIE_MASK |  /* Data reception complete interrupt enable */
#if (LIN_FRAME_TIMEOUT_DISABLE == STD_OFF)
                    LINFlexD_LINIER_OCIE_MASK |  /* Timeout interrupt enable */
#endif /* LIN_FRAME_TIMEOUT_DISABLE == STD_OFF */
                    LINFlexD_LINIER_DTIE_MASK ;  /* Data transmitted interrupt enable */
    if(LIN_SLAVE_MODE == Lin_LocNodeMode[Channel])
    {
        Base->LINIER |= LINFlexD_LINIER_HRIE_MASK;  /* Data Header Receive interrupt enable */
    }
    Lin_Lld_LocGoToSleep(Channel);
}

#if (LIN_DEINIT_API_SUPPORT == STD_ON)
LIN_FUNC void Lin_Lld_DeInitChannel(const uint8 Channel)
{
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    Base->LINCR1 = LINFlexD_LINCR1_INIT_MASK;
    Base->LINIER = 0x00000000U;
    Base->LINCR2 = 0x00000000U;
    for(uint8 Index = 0U; Index < Lin_GlobalChConfigPtrs[Channel]->LinFilterNum; ++Index)
    {
        Base->IFCR[Index] = 0;
    }
    Base->IFER = 0x00000000U;
    Base->LINTCSR = 0x00000000U;
    Base->LINTOCR = LIN_CONST_LINTOCR_DEFAULT_VALUE;
    Base->LINIBRR = 0x00000000U;
    Base->LINFBRR = 0x00000000U;
    Base->LINSR = Base->LINSR;
    Base->LINCR1 = LIN_CONST_LINCR1_DEFAULT_VALUE;
    Lin_GlobalChConfigPtrs[Channel] = NULL_PTR;
}
#endif /* LIN_DEINIT_API_SUPPORT == STD_ON */

LIN_FUNC Std_ReturnType Lin_Lld_SendGoToSleep(const uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    if (E_OK == Lin_Lld_LocTransmittionAbort(Base))
    {
        /* Release message buffer */
        Base->LINSR = LINFlexD_LINSR_RMB_MASK;
        /* Setup header */
        Base->BIDR = LINFlexD_BIDR_ID(LIN_DRV_SLEEP_COMMAND_ID) |
                     LINFlexD_BIDR_CCS(1U) |
                     LINFlexD_BIDR_DIR(1U) |
                     LINFlexD_BIDR_DFL(LIN_DRV_SLEEP_COMMAND_DATA_LENGTH - 1U);
        Base->DATA.DATA8[0] = 0x00U;
        for (uint8 Index = 1U; Index < LIN_DRV_SLEEP_COMMAND_DATA_LENGTH; ++Index)
        {
            Base->DATA.DATA8[Index] = LIN_CONST_CONST_WHOLE_OF_BYTE_ALL_TRUE;
        }
        Lin_LocTxHeaderCommands[Channel] = LIN_DRV_TX_SLEEP_CMD;
#if (LIN_MASTER_API_SUPPORT == STD_ON)
        /* Send out data */
        Lin_Lld_LocHeaderTx(Base);
#endif
        RetVal = E_OK;
    }
    else
    {
        Lin_Lld_LocWakeup(Channel);
    }
    return RetVal;
}

LIN_FUNC Std_ReturnType Lin_Lld_GoToSleepInternal(const uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    if (E_OK == Lin_Lld_LocTransmittionAbort(Base))
    {
        Lin_Lld_LocGoToSleep(Channel);
        RetVal = E_OK;
    }
    else
    {
        Lin_Lld_LocWakeup(Channel);
    }
    return RetVal;
}

LIN_FUNC void Lin_Lld_Wakeup(const uint8 Channel)
{
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    Lin_Lld_LocWakeup(Channel);
    if (E_OK == Lin_Lld_LocTransmittionAbort(Base))
    {
        Base->DATA.DATA8[0] = Lin_LocWakeupByte[Channel];
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_09();
        /* Send out wakeup request */
        Base->LINCR2 |= LINFlexD_LINCR2_WURQ_MASK;
        uint32 Timeout = 0U;
        while(Timeout < 0xFFFF)
        {
            Timeout++;
            if (TRUE == Lin_Lld_GetWurqDoneStates(Channel))
            {
                Lin_ChStates[Channel] = LIN_DRV_CH_OPERATIONAL;
                break;
            }
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_09();
    }
    /* Update LIN channel frame operation status */
    Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
    /* Reset frame error status */
    Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NO_ERROR;
    Lin_LocLatchedStatusRegs[Channel] = 0UL;
    Lin_Lld_LocDisableWUIE(Channel);
    Lin_ChStates[Channel] = LIN_DRV_CH_OPERATIONAL;
}

LIN_FUNC void Lin_Lld_WakeupInternal(const uint8 Channel)
{
    Lin_Lld_LocWakeup(Channel);
    Lin_Lld_LocDisableWUIE(Channel);
    /* Update LIN channel frame operation status */
    Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
    /* Reset frame error status */
    Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NO_ERROR;
    /* Reset latched error status */
    Lin_LocLatchedStatusRegs[Channel] = 0UL;
    Lin_ChStates[Channel] = LIN_DRV_CH_OPERATIONAL;
}

LIN_FUNC boolean Lin_Lld_CheckWakeup(const uint8 Channel)
{
    boolean RetVal = FALSE;
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    if(TRUE == Lin_LocWakeupReq[Channel])
    {
        if (0U == (Base->LINCR2 & LINFlexD_LINCR2_WURQ_MASK))
        {
            if(Base->LINSR & LINFlexD_LINSR_RDI_MASK)
            {
                /* Update channel frame state */
                Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
                /* Reset header command type */
                Lin_LocTxHeaderCommands[Channel] = LIN_DRV_TX_NO_CMD;
                /* Reset frame error status */
                Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NO_ERROR;
                /* Reset latched error status */
                Lin_LocLatchedStatusRegs[Channel] = 0UL;
                Lin_LocWakeupReq[Channel] = FALSE;
                EcuM_CheckWakeup(Lin_GlobalChConfigPtrs[Channel]->LinChEcuMWakeupSource);
                Lin_ChStates[Channel] = LIN_DRV_CH_OPERATIONAL;
                Lin_Lld_LocDisableWUIE(Channel);
                RetVal = TRUE;
            }
        }
    }
    return RetVal;
}

#if (LIN_MASTER_API_SUPPORT == STD_ON)
LIN_FUNC Std_ReturnType Lin_Lld_SendHeader(const uint8 Channel, const Lin_PduType* PduInfoPtr)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Lin_FrameCsModelType LinCs = LIN_ENHANCED_CS;
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    /* Release message buffer */
    Base->LINSR = LINFlexD_LINSR_RMB_MASK;
    /* Clear previous noise flag */
    Base->LINESR = LINFlexD_LINESR_NF_MASK;
    uint8 CurrentId = PduInfoPtr->Pid & 0x3FU;
    if((LIN_DRV_MASTER_REQUEST_DIAGNOSTIC_ID <= CurrentId) || (LIN_CLASSIC_CS == PduInfoPtr->Cs))
    {
        LinCs = LIN_CLASSIC_CS;
    }
    if (E_OK == Lin_Lld_LocTransmittionAbort(Base))
    {
        /* Reset error status */
        Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NO_ERROR;
        /* Reset latched error status */
        Lin_LocLatchedStatusRegs[Channel] = 0UL;
        if (LIN_FRAMERESPONSE_TX == PduInfoPtr->Drc)
        {
            /* Master response */
            Lin_LocTxHeaderCommands[Channel] = LIN_DRV_TX_MASTER_RES_CMD;
            /* Update LIN channel frame operation status */
            Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
            /* Setup ID, Data length and direction of the frame */
            /* Setup ID checksum type based on Pid */
            if(LIN_CLASSIC_CS == LinCs)
            {
                /* using classic checksum */
                Base->BIDR = CurrentId |
                             LINFlexD_BIDR_DFL(PduInfoPtr->Dl - (uint32)1U) |
                             LINFlexD_BIDR_DIR(1U)|   /* LINFlexD transmits the data */
                             LINFlexD_BIDR_CCS(1U);   /* Classic checksum covering data field only */
            }
            else
            {
                /* using enhanced checksum */
                Base->BIDR = CurrentId |
                             LINFlexD_BIDR_DFL(PduInfoPtr->Dl - (uint32)1U) |
                             LINFlexD_BIDR_DIR(1U);   /* LINFlexD transmits the data */
                /* LINFlexD_BIDR_CCS(0U);    Classic checksum covering data field only */
            }
        }
        else if (LIN_FRAMERESPONSE_RX == PduInfoPtr->Drc)
        {
            Lin_LocTxHeaderCommands[Channel] = LIN_DRV_TX_SLAVE_RES_CMD;
            Lin_LocChFrameStates[Channel] = LIN_DRV_CH_HEADER_SENT;
            /* Setup ID, Data length and direction of the frame */
            /* Setup ID checksum type based on Pid */
            if(LIN_CLASSIC_CS == LinCs)
            {
                /* using classic checksum */
                Base->BIDR = CurrentId |
                             LINFlexD_BIDR_DFL(PduInfoPtr->Dl - (uint32)1U) |
                             /*LINFlexD_BIDR_DIR(0U)|    LINFlexD receiving the data */
                             LINFlexD_BIDR_CCS(1U);   /* Classic checksum covering data field only */
            }
            else
            {
                /* using enhanced checksum */
                Base->BIDR = CurrentId |
                             LINFlexD_BIDR_DFL(PduInfoPtr->Dl - (uint32)1U);
                /*  LINFlexD_BIDR_DIR(0U)|   LINFlexD receiving the data */
                /*   LINFlexD_BIDR_CCS(0U);    Classic checksum covering data field only */
            }
            /* clear status flags */
            Base->LINSR = LINFlexD_LINSR_DRBNE_MASK;
            /* Send out data */
            Lin_Lld_LocHeaderTx(Base);
        }
        else
        {
            /* Slave send data to slave */
            Lin_LocTxHeaderCommands[Channel] = LIN_DRV_SLAVE_TO_SLAVE_CMD;
            Lin_LocChFrameStates[Channel] = LIN_DRV_CH_STS_HEADER_SENT;
            /* using enhanced checksum */
            Base->BIDR = CurrentId | LINFlexD_BIDR_DFL(PduInfoPtr->Dl - (uint32)1U);   /* LINFlexD receive the data */
            /*  LINFlexD_BIDR_CCS(0U);   /Enhanced checksum covering data and pid field */
            /* Send out data */
            Lin_Lld_LocHeaderTx(Base);
            /* As data from slave to slave, master won't save the response */
            Lin_Lld_LocDisgardData(Base);
        }
        RetVal = E_OK;
    }
    else
    {
        Lin_Lld_LocWakeup(Channel);
    }
    return RetVal;
}

LIN_FUNC void Lin_Lld_SendResponse(const uint8 Channel, const Lin_PduType* PduInfoPtr)
{
    uint8 DataLength;
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    DataLength = Lin_Lld_LocGetLinDataLength(Base);
    /* fill data to LINFlexD data register */
    for (uint8 Index = 0U; Index < DataLength; ++Index)
    {
        Base->DATA.DATA8[Index] = PduInfoPtr->SduPtr[Index];
    }
    /* Send out data */
    Lin_Lld_LocHeaderTx(Base);
}

LIN_FUNC Lin_Drv_HwStatusType Lin_Lld_GetLinState(const uint8 Channel)
{
    uint32 Tmp32;
    /* Get LINFlexD Base address */
    volatile const LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    Tmp32 = (Base->LINSR & LINFlexD_LINSR_LINS_MASK) >> LINFlexD_LINSR_LINS_SHIFT;
    return (Lin_Drv_HwStatusType )Tmp32;
}

LIN_FUNC void Lin_Lld_CopyData(const uint8 Channel, uint8 * LinSduPtr)
{
    uint8 DataLength;
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    DataLength = Lin_Lld_LocGetLinDataLength(Base);
    for(uint8 Index = 0U; Index < DataLength; ++Index)
    {
        LinSduPtr[Index] = Base->DATA.DATA8[Index];
        Base->DATA.DATA8[Index] = 0x00U;
    }
    /* Release message buffer */
    Base->LINSR = LINFlexD_LINSR_RMB_MASK;
}
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

LIN_FUNC Lin_DrvCommandType Lin_Lld_GetTxHeaderComands(const uint8 Channel)
{
    return Lin_LocTxHeaderCommands[Channel];
}

LIN_FUNC Lin_DrvErrorType Lin_Lld_GetFrameErrStates(const uint8 Channel)
{
    return Lin_LocChFrameErrorStates[Channel];
}

LIN_FUNC Lin_DrvStateType Lin_Lld_GetFrameStates(const uint8 Channel)
{
    return Lin_LocChFrameStates[Channel];
}

LIN_FUNC boolean Lin_Lld_GetWurqDoneStates(const uint8 Channel)
{
    boolean RetVal = TRUE;
    /* Get LINFlexD Base address */
    volatile const LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    if(0U != (Base->LINCR2 & LINFlexD_LINCR2_WURQ_MASK))
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/*==================================================================================================
 *                                      INTERRUPT FUNCTIONS
==================================================================================================*/
LIN_FUNC LOCAL_INLINE void Lin_Lld_HandleWkuInt(uint8 Channel, volatile LINFlexD_Type *Base)
{
    if ((TRUE == Lin_GlobalChConfigPtrs[Channel]->LinChWakeSupport)&&
            ((Lin_ChStates[Channel] != LIN_DRV_CH_OPERATIONAL)||(LINFlexD_LINCR1_SLEEP_MASK == (Base->LINCR1 & LINFlexD_LINCR1_SLEEP_MASK))))
    {
        if(0U == (Base->LINCR2 & LINFlexD_LINCR2_WURQ_MASK))
        {
            /* Reset header command type */
            Lin_LocTxHeaderCommands[Channel] = LIN_DRV_TX_NO_CMD;
            /* Update channel frame state */
            Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
            /* Reset frame error status */
            Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NO_ERROR;
            /* Reset latched error status */
            Lin_LocLatchedStatusRegs[Channel] = 0UL;
            /* send valid wakeup event to ECU */
            EcuM_CheckWakeup(Lin_GlobalChConfigPtrs[Channel]->LinChEcuMWakeupSource);
            Lin_ChStates[Channel] = LIN_DRV_CH_OPERATIONAL;
        }
    }
    else
    {
        Lin_LocWakeupReq[Channel] = TRUE;
    }
    Lin_Lld_LocWakeup(Channel);
    Base->LINSR = LINFlexD_LINSR_WUF_MASK;
}

LIN_FUNC LOCAL_INLINE void Lin_Lld_HandleDataRecInt(uint8 Channel, volatile LINFlexD_Type *Base)
{
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
    uint8 TmpData[8];
    Lin_PduType TmpPduInfo;
#endif
    if(LIN_MASTER_MODE == Lin_LocNodeMode[Channel])
    {
        /* Data reception complete */
        /* Check if noise detected */
        if (0UL != (Base->LINESR & LINFlexD_LINESR_NF_MASK))
        {
            Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NOISE_ERROR;
            /* Clear noise error status */
            Base->LINESR = LINFlexD_LINESR_NF_MASK;
        }
        /* Update LIN channel frame state */
        Lin_LocChFrameStates[Channel] = LIN_DRV_CH_RX_COMPLETE;
    }
    else
    {
        /*  After successful reception of a LIN response, the LIN driver shall directly make
            the received data available to the LIN interface module by calling the Rx
            indication callback function LinIf_RxIndication with the Lin_SduPtr parameter set
            to the reception data.
            Trace: SWS_Lin_00274 */
        if (0UL != (Base->LINESR & LINFlexD_LINESR_NF_MASK))
        {
            Lin_LocChFrameErrorStates[Channel] = LIN_DRV_NOISE_ERROR;
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_INC_RESP);
#endif
            /* Clear noise error status */
            Base->LINESR = LINFlexD_LINESR_NF_MASK;
        }
        else
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            TmpPduInfo.SduPtr = TmpData;
#endif
            for(uint8 Index = 0U; Index < LIN_CONST_MAX_FRAME_BYTES_NUM; ++Index)
            {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
                TmpData[Index] = Base->DATA.DATA8[Index];
#endif
                Base->DATA.DATA8[Index] = 0x00U;
            }
            Base->LINSR = LINFlexD_LINSR_RMB_MASK;
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_RxIndication(Channel, TmpPduInfo.SduPtr);
#endif
        }
        Base->LINSR = LINFlexD_LINSR_HRF_MASK;
        Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
    }
    /* Clear data reception interrupt */
    Base->LINSR = LINFlexD_LINSR_DRF_MASK;
}

LIN_FUNC LOCAL_INLINE void Lin_Lld_HandleDataTransInt(uint8 Channel, volatile LINFlexD_Type *Base)
{
    if(LIN_MASTER_MODE == Lin_LocNodeMode[Channel])
    {
        /* Data transmission complete interrupt */
        /* Check if sleep mode transmitted */
        if (LIN_DRV_TX_SLEEP_CMD == Lin_LocTxHeaderCommands[Channel])
        {
            Lin_Lld_LocGoToSleep(Channel);
        }
        else
        {
            /* Update lin channel frame state */
            Lin_LocChFrameStates[Channel] = LIN_DRV_CH_TX_COMPLETE;
        }
    }
    else
    {
        /*  After successful transmission of a LIN response, the transmission shall be
            directly confirmed to the LIN Interface module by calling the Tx confirmation
            callback function LinIf_TxConfirmation.
            Trace: SWS_Lin_00275 */
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
        LinIf_TxConfirmation(Channel);
#endif
        /* SCHM operate update */
        Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
        Base->LINSR = LINFlexD_LINSR_HRF_MASK;
    }
    /* Clear data transmission interrupt */
    Base->LINSR = LINFlexD_LINSR_DTF_MASK;
}

LIN_FUNC LOCAL_INLINE void Lin_Lld_HandleHeaderRecInt(uint8 Channel, volatile LINFlexD_Type *Base)
{
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
    uint8 TmpData[8];
    uint8 Tmp8;
    uint32 Tmp32;
    uint32 TmpBDIR;
    Lin_PduType TmpPduInfo;
#endif
    /*  The LIN driver shall be able to receive a LIN header at any time in LIN_DRV_CH_READY
     state. The header is composed of the break field, synch byte field, and protected
     identifier byte field as detailed in [16].
     Trace: SWS_Lin_00272 */
    /*GCOVR_EXCL_START this case always true because of software, But it is not allowed to be deleted because of autosar*/
    if(LIN_DRV_CH_READY == Lin_LocChFrameStates[Channel])
        /*GCOVR_EXCL_STOP*/
    {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
        TmpBDIR = Base->BIDR & LINFlexD_BIDR_ID_MASK;
        /*  Note: If the LIN hardware unit provides the ID (frame identifier without parity
            bits) instead of the PID, the LIN driver is responsible to calculate the PID from
            the ID to comply with the callback interface. */
        Tmp8 = LinPidTable[(uint8)TmpBDIR];
        TmpPduInfo.Pid = Tmp8;
        TmpPduInfo.SduPtr = TmpData;
        TmpPduInfo.Cs = LIN_ENHANCED_CS;
        TmpPduInfo.Dl = LIN_CONST_MAX_FRAME_BYTES_NUM;
        TmpPduInfo.Drc = LIN_FRAMERESPONSE_IGNORE;
        /*  On LIN header reception, the LIN driver shall call the header indication callback
            function LinIf_HeaderIndication with PduPtr->Pid set to the received PID value and
            PduPtr->SduPtr set to the (hardware or shadow) buffer of the LIN driver, to which
            the slave response shall be written by the upper layer.
            Trace: SWS_Lin_00280 */
        /*  If the LIN hardware unit cannot detect invalid PIDs, the LIN driver shall not
            evaluate the PID value (i.e. it shall not verify parity bits in software). The LIN
            driver shall provide the PID as-received to the LIN interface module
            Trace: SWS_Lin_00271 */
        if(E_OK == LinIf_HeaderIndication(Channel, &TmpPduInfo))
        {
            if((0U == TmpPduInfo.Dl) || (LIN_CONST_PARA_NUM_8 < TmpPduInfo.Dl))
            {
                Lin_Lld_LocDisgardData(Base);
            }
            /*  After the call of LinIf_HeaderIndication when the return value is E_OK, the LIN
                driver shall evaluate the PduPtr->Drc to determine the type of LIN response.
                Trace: SWS_Lin_00282 */
            else if(LIN_FRAMERESPONSE_RX == TmpPduInfo.Drc)
            {
                /*  If the LIN response is going to be received (LIN_FRAMERESPONSE_RX), the LIN
                    driver shall evaluate the Cs and Dl members in parameter PduPtr (after the
                    call of LinIf_HeaderIndication with return value E_OK) to configure the LIN
                    response reception.
                    Trace: SWS_Lin_00284 */
                Tmp32 = (uint32)Tmp8;
                Tmp32 |= LINFlexD_BIDR_DFL(TmpPduInfo.Dl - (uint32)1U);
                if(LIN_ENHANCED_CS != TmpPduInfo.Cs)
                {
                    Tmp32 |= LINFlexD_BIDR_CCS_MASK;
                }
                Base->BIDR = Tmp32;
                if(0U != (Base->LINSR & LINFlexD_LINSR_DRBNE_MASK))
                {
                    Base->LINSR = LINFlexD_LINSR_DRBNE_MASK;
                }
                Base->LINSR = LINFlexD_LINSR_DRF_MASK;
            }
            else if(LIN_FRAMERESPONSE_TX == TmpPduInfo.Drc)
            {
                /*  If the LIN response is going to be transmitted (LIN_FRAMERESPONSE_TX), the
                    LIN driver shall evaluate the Cs, Dl and SduPtr members in parameter PduPtr
                    (after the call of LinIf_HeaderIndication with return value E_OK) to setup
                    and transmit the LIN response
                    Trace: SWS_Lin_00283 */
                for(uint8 Index = 0U; Index < TmpPduInfo.Dl; ++Index)
                {
                    Base->DATA.DATA8[Index] = TmpPduInfo.SduPtr[Index];
                }
                Tmp32 = (uint32)Tmp8 | LINFlexD_BIDR_DIR_MASK;
                Tmp32 |= ((uint32)TmpPduInfo.Dl - 1U) << LINFlexD_BIDR_DFL_SHIFT;
                if(LIN_ENHANCED_CS != TmpPduInfo.Cs)
                {
                    Tmp32 |= LINFlexD_BIDR_CCS_MASK;
                }
                Base->BIDR = Tmp32;
                Base->LINSR = LINFlexD_LINSR_DTF_MASK;
                Base->LINSR = LINFlexD_LINSR_DRF_MASK;
                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_03();
                Base->LINCR2 |= LINFlexD_LINCR2_DTRQ_MASK;
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_03();
            }
            else
            {
                /*  If the return value of LinIf_HeaderIndication is E_NOT_OK or the returned
                    PduPtr->Drc is LIN_FRAMERESPONSE_IGNORE, the LIN driver shall ignore the
                    response.
                Trace: SWS_Lin_00286 */
                Lin_Lld_LocDisgardData(Base);
            }
        }
        else
        {
#endif
            /*  The LIN driver shall not report any events to the LIN interface module if the
                LIN response is ignored until the reception of a new LIN header.
                Trace: SWS_Lin_00276 */
            Lin_Lld_LocDisgardData(Base);
            /*  For a LIN slave, DDRQ can be set only when LINSR.HRF = 1 and the identifier is
                software-filtered.*/
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
        }
#endif
        /*  The LIN driver shall be able to send, receive or ignore a LIN response.
            Trace: SWS_Lin_00273 */
        /*  The LIN driver shall detect communication errors during response transmission
            and response reception. Once an error is detected, the current frame handling
            shall be aborted and the error indication callback function
            LinIf_LinErrorIndication shall be called.
            Trace: SWS_Lin_00277 */
        /*  The handling of each relevant (i.e. not ignored) LIN response must be completed
            by a call to either LinIf_RxIndication, LinIf_TxConfirmation or
            LinIf_LinErrorIndication, latest before a new LIN header reception is indicated
            by a call of Lin_HeaderIndication.
            Trace: SWS_Lin_00285 */
    }
    /* Update channel state  */
    Base->LINSR = LINFlexD_LINSR_HRF_MASK;
}


/**
 * @brief
 * @details          This function will process all LIN RX and TX interrupt
 * @param[in]        HwChannel LIN hardware channel.
 * @return           void.
 */
LIN_FUNC void Lin_Lld_LocRxTxIntHandler(const uint8 HwChannel)
{
    uint32 LinStatus;
    uint32 LinIe;
    /* convert hardware channel to logic channel */
    uint8 Channel = Lin_LocInstMapPtr[HwChannel];
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    /* Get lin status register */
    LinStatus = Base->LINSR;
    LinIe = Base->LINIER;
    if((0UL != (LinStatus & LINFlexD_LINSR_WUF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_WUIE_MASK)))
    {
        Lin_Lld_HandleWkuInt(Channel, Base);
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_DRIE_MASK always true, But it is not allowed to be deleted */
    else if((0UL != (LinStatus & LINFlexD_LINSR_DRF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_DRIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        Lin_Lld_HandleDataRecInt(Channel, Base);
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_DTIE_MASK always true, But it is not allowed to be deleted */
    else if((0UL != (LinStatus & LINFlexD_LINSR_DTF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_DTIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        Lin_Lld_HandleDataTransInt(Channel, Base);
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_HRIE_MASK always true, But it is not allowed to be deleted */
    else if((0UL != (LinStatus & LINFlexD_LINSR_HRF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_HRIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        Lin_Lld_HandleHeaderRecInt(Channel, Base);
    }
    else
    {
        /* Should never reach here */
        /* Clear all status */
        Base->LINSR = Base->LINSR;
    }
}
/**
 * @brief
 * @details          This function will process all LIN error interrupt
 * @param[in]        HwChannel LIN hardware channel.
 * @return           void.
 */
LIN_FUNC void Lin_Lld_LocErrorIntHandler(const uint8 HwChannel)
{
    uint32 LinStatus;
    uint32 LinIe;
    boolean DataDiscardEnable = FALSE;
    boolean ErrHeadInd = FALSE;
    boolean ErrFrameInd = FALSE;
    boolean ErrChecksumInd = FALSE;
    boolean ErrBitInd = FALSE;
    boolean ErrTimeoutInd = FALSE;
    boolean ErrNoRespInd = FALSE;
    boolean ErrSlave = FALSE;
    /* convert hardware channel to logic channel */
    uint8 Channel = Lin_LocInstMapPtr[HwChannel];
    /* Get LINFlexD Base address */
    volatile LINFlexD_Type * Base = Lin_LocBasePtrs[(uint8)Lin_GlobalChConfigPtrs[Channel]->LinHwChannel];
    /* Get lin error status register */
    LinStatus = Base->LINESR;
    LinIe = Base->LINIER;
    /*GCOVR_EXCL_START LINFlexD_LINIER_DRIE_MASK always true, But it is not allowed to be deleted */
    if (0UL != (LinIe & LINFlexD_LINIER_DRIE_MASK))
        /*GCOVR_EXCL_STOP*/
    {
        if (0UL != (LinStatus & LINFlexD_LINESR_SFEF_MASK))
        {
            /* Header field Synch error happens */
            ErrHeadInd = TRUE;
            /* update frame error status */
            Lin_LocChFrameErrorStates[Channel] = LIN_DRV_SYNCH_FIELD_ERROR;
            /* Clear error status */
            Base->LINESR = LINFlexD_LINESR_SFEF_MASK;
        }
        if (0UL != (LinStatus & (uint32)LINFlexD_LINESR_SDEF_MASK))
        {
            /* Header field delimiter error happens */
            ErrHeadInd = TRUE;
            /* update frame error status */
            Lin_LocChFrameErrorStates[Channel] = LIN_DRV_BREAK_FIELD_ERROR;
            /* Clear error status */
            Base->LINESR = LINFlexD_LINESR_SDEF_MASK;
        }
        if (0UL != (LinStatus & (uint32)LINFlexD_LINESR_IDPEF_MASK))
        {
            /* Header field ID error happens */
            ErrHeadInd = TRUE;
            /* update frame error status */
            Lin_LocChFrameErrorStates[Channel] = LIN_DRV_ID_PARITY_ERROR;
            /* Clear error status */
            Base->LINESR = LINFlexD_LINESR_IDPEF_MASK;
        }
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_CEIE_MASK always true, But it is not allowed to be deleted */
    if ((0UL != (LinStatus & LINFlexD_LINESR_CEF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_CEIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        /* Checksum error happens */
        ErrChecksumInd = TRUE;
        /* update frame error status */
        Lin_LocChFrameErrorStates[Channel] = LIN_DRV_CHECKSUM_ERROR;
        /* Clear error status */
        Base->LINESR = LINFlexD_LINESR_CEF_MASK;
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_FEIE_MASK always true, But it is not allowed to be deleted */
    if ((0UL != (LinStatus & LINFlexD_LINESR_FEF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_FEIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        /* Frame error happens */
        ErrFrameInd = TRUE;
        /* update frame error status */
        Lin_LocChFrameErrorStates[Channel] = LIN_DRV_FRAMING_ERROR;
        /* Clear error status */
        Base->LINESR = LINFlexD_LINESR_FEF_MASK;
        DataDiscardEnable = TRUE;
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_BEIE_MASK always true, But it is not allowed to be deleted */
    if ((0UL != (LinStatus & LINFlexD_LINESR_BEF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_BEIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        /* Bit error happens */
        ErrBitInd = TRUE;
        /* Latch up bit error status register */
        Lin_LocLatchedStatusRegs[Channel] = Base->LINSR;
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_08();
        /* Abort ongoing transmission */
        Base->LINCR2 |= LINFlexD_LINCR2_ABRQ_MASK;
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_08();
        /* update frame error status */
        Lin_LocChFrameErrorStates[Channel] = LIN_DRV_BIT_ERROR;
        /* Clear bit error status */
        Base->LINESR = LINFlexD_LINESR_BEF_MASK;
        /* Enable data discard */
        DataDiscardEnable = TRUE;
    }
    /*GCOVR_EXCL_START LINFlexD_LINIER_DRIE_MASK always true, But it is not allowed to be deleted */
    if ((0UL != (LinStatus & LINFlexD_LINESR_OCF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_OCIE_MASK)))
        /*GCOVR_EXCL_STOP*/
    {
        /* Output compare error happens */
        ErrTimeoutInd = TRUE;
        /* update frame error status */
        Lin_LocChFrameErrorStates[Channel] = LIN_DRV_TIMEOUT_ERROR;
        /* Latch status */
        Lin_LocLatchedStatusRegs[Channel] = Base->LINSR;
        /* Clear error status */
        Base->LINESR = LINFlexD_LINESR_OCF_MASK;
        /* Enable data discard */
        DataDiscardEnable = TRUE;
    }
    /*GCOVR_EXCL_START this case never occured because of software, But it is not allowed to be deleted */
    if ((0UL != (LinStatus & LINFlexD_LINESR_BOF_MASK))&&(0UL != (LinIe & LINFlexD_LINIER_BOIE_MASK)))
    {
        /* Buffer overrun error happens */
        ErrNoRespInd = TRUE;
        /* update frame error status */
        Lin_LocChFrameErrorStates[Channel] = LIN_DRV_OVERRUN_ERROR;
        /* Clear error status */
        Base->LINESR = LINFlexD_LINESR_BOF_MASK;
        DataDiscardEnable = TRUE;
    }
    /*GCOVR_EXCL_STOP*/
    if (LIN_DRV_TX_SLEEP_CMD == Lin_LocTxHeaderCommands[Channel])
    {
        Lin_Lld_LocGoToSleep(Channel);
    }
    if (TRUE == DataDiscardEnable)
    {
        Base->LINSR = LINFlexD_LINSR_DRBNE_MASK | LINFlexD_LINSR_RMB_MASK;
        for(uint8 Index = 0U; Index < LIN_CONST_MAX_FRAME_BYTES_NUM; ++Index)
        {
            Base->DATA.DATA8[Index] = 0x00U;
        }
    }
    /* Confirm all error processed */
    Base->LINESR = Base->LINESR;
    if (LIN_SLAVE_MODE == Lin_LocNodeMode[Channel])
    {
        if (TRUE == ErrHeadInd)
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_HEADER);
#endif
            ErrSlave = TRUE;
        }
        if (TRUE == ErrFrameInd)
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_RESP_STOPBIT);
#endif
            ErrSlave = TRUE;
        }
        if (TRUE == ErrChecksumInd)
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_RESP_CHKSUM);
#endif
            ErrSlave = TRUE;
        }
        if (TRUE == ErrBitInd)
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_RESP_DATABIT);
#endif
            ErrSlave = TRUE;
        }
        if (TRUE == ErrTimeoutInd)
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_NO_RESP);
#endif
            ErrSlave = TRUE;
        }
        /*GCOVR_EXCL_START this case never occured because of software, But it is not allowed to be deleted */
        if (TRUE == ErrNoRespInd)
        {
#if (LIN_SLAVE_API_SUPPORT == STD_ON)
            LinIf_LinErrorIndication(Channel, LIN_ERR_NO_RESP);
#endif
            ErrSlave = TRUE;
        }
        /*GCOVR_EXCL_STOP*/
        if(TRUE == ErrSlave)
        {
            Base->LINSR = LINFlexD_LINSR_HRF_MASK |
                          LINFlexD_LINSR_DTF_MASK |
                          LINFlexD_LINSR_HRF_MASK;
            Lin_LocChFrameStates[Channel] = LIN_DRV_CH_READY;
        }
    }
}

#ifdef LINFLEXD_IP_0_LIN_OCCUPY
#ifdef LINFlexD0_BASE_ADDR32
LIN_FUNC ISR(LINFlexD0_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_0);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_0);
}
#endif
#endif
#ifdef LINFLEXD_IP_1_LIN_OCCUPY
#ifdef LINFlexD1_BASE_ADDR32
LIN_FUNC ISR(LINFlexD1_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_1);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_1);
}
#endif
#endif
#ifdef LINFLEXD_IP_2_LIN_OCCUPY
#ifdef LINFlexD2_BASE_ADDR32
LIN_FUNC ISR(LINFlexD2_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_2);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_2);
}
#endif
#endif
#ifdef LINFLEXD_IP_3_LIN_OCCUPY
#ifdef LINFlexD3_BASE_ADDR32
LIN_FUNC ISR(LINFlexD3_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_3);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_3);
}
#endif
#endif
#ifdef LINFLEXD_IP_4_LIN_OCCUPY
#ifdef LINFlexD4_BASE_ADDR32
LIN_FUNC ISR(LINFlexD4_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_4);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_4);
}
#endif
#endif
#ifdef LINFLEXD_IP_5_LIN_OCCUPY
#ifdef LINFlexD5_BASE_ADDR32
LIN_FUNC ISR(LINFlexD5_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_5);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_5);
}
#endif
#endif
#ifdef LINFLEXD_IP_6_LIN_OCCUPY
#ifdef LINFlexD6_BASE_ADDR32
LIN_FUNC ISR(LINFlexD6_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_6);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_6);
}
#endif
#endif
#ifdef LINFLEXD_IP_7_LIN_OCCUPY
#ifdef LINFlexD7_BASE_ADDR32
LIN_FUNC ISR(LINFlexD7_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_7);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_7);
}
#endif
#endif
#ifdef LINFLEXD_IP_8_LIN_OCCUPY
#ifdef LINFlexD8_BASE_ADDR32
LIN_FUNC ISR(LINFlexD8_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_8);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_8);
}
#endif
#endif
#ifdef LINFLEXD_IP_9_LIN_OCCUPY
#ifdef LINFlexD9_BASE_ADDR32
LIN_FUNC ISR(LINFlexD9_IRQHandler)
{
    Lin_Lld_LocRxTxIntHandler(LIN_INSTANCE_ID_9);
    Lin_Lld_LocErrorIntHandler(LIN_INSTANCE_ID_9);
}
#endif
#endif
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

/** @} */

