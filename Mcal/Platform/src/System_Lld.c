/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @defgroup   System_Lld System LLD
*   @ingroup    Platform
*
*   @addtogroup System_Lld
*   @{
*/

/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 4404  Rule-10.3: The value of an expression shall not be assigned to an object with a narrower
                          essential type or of a different essential type category.
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "System_Lld.h"
#include "OsIf.h"
#include "SchM_Platform.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_SYSTEM_LLD_VENDOR_ID_C                          (180)
#define PLATFORM_SYSTEM_LLD_SW_MAJOR_VERSION_C                   (2)
#define PLATFORM_SYSTEM_LLD_SW_MINOR_VERSION_C                   (3)
#define PLATFORM_SYSTEM_LLD_SW_PATCH_VERSION_C                   (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Lld header file are of the same vendor */
#if (PLATFORM_SYSTEM_LLD_VENDOR_ID_C != PLATFORM_SYSTEM_LLD_VENDOR_ID)
#error "System_Lld.c and System_Lld.h have different vendor ids"
#endif

/* Check if current file and System_Lld header file are of the same Software version */
#if ((PLATFORM_SYSTEM_LLD_SW_MAJOR_VERSION_C != PLATFORM_SYSTEM_LLD_SW_MAJOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_SW_MINOR_VERSION_C != PLATFORM_SYSTEM_LLD_SW_MINOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_SW_PATCH_VERSION_C != PLATFORM_SYSTEM_LLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of System_Lld.c and System_Lld.h are different"
#endif



/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == SYSTEM_LLD_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
#define Call_System_Lld_ConfigIrq(Irq,Enable)  \
                OsIf_Trusted_Call2params(System_Lld_ConfigIrqPrivileged,(Irq),(Enable))
#else /*STD_ON == SYSTEM_LLD_ENABLE_USER_MODE_SUPPORT*/
#define Call_System_Lld_ConfigIrq(Irq,Enable)  \
                System_Lld_ConfigIrqPrivileged((Irq), (Enable))

#endif /*STD_ON == SYSTEM_LLD_ENABLE_USER_MODE_SUPPORT*/


#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if ((SYSTEM_LLD_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
PLATFORM_FUNC static inline void System_Lld_ConfigIrqPrivileged(System_Lld_IrqType Irq, boolean Enable);
#endif


/**
 * @brief         Enables/disables core-related interrupt exceptions.
 *
 * @details       This function is non-reentrant and configures core-related interrupt
 *
 * */
#if ((SYSTEM_LLD_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
PLATFORM_FUNC static inline void System_Lld_ConfigIrqPrivileged(System_Lld_IrqType Irq, boolean Enable)
{
#if (SYSTEM_LLD_DEV_ERROR_DETECT == STD_ON)
    /* Check interrupt to be enabled */
    /*
    *  MR12 RULE 10.3 VIOLATION: It's caused by using DevAssert() with the input paramter
    *                             as "typedef unsigned char boolean" from Platform_Types.h,
    *                            it's no risk for this essentially Boolean type conversion.
    */
    DevAssert((uint8)Irq < 32U); /* PRQA S 4404 */
#endif /*(SYSTEM_LLD_DEV_ERROR_DETECT == STD_ON) */

    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_00();

    uint32 RegTemp = CIM->FPUIE;

    if (TRUE == Enable)
    {
        RegTemp |= (1UL << (uint32)Irq);
    }
    else
    {
        RegTemp &= ~(1UL << (uint32)Irq);
    }
    CIM->FPUIE = RegTemp;

    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_00();
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if ((SYSTEM_LLD_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
PLATFORM_FUNC void System_Lld_ConfigIrq(System_Lld_IrqType Irq, boolean Enable)
{
    Call_System_Lld_ConfigIrq(Irq, Enable);
}
#endif


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */

