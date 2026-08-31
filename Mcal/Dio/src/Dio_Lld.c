/**
* @file    Dio_Lld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Dio_Lld
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
 * @page misra_violations MISRA-C:2012 violations
 *   PRQA S 2985 Rule-2.2: There shall be no dead code
 */




/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/

#include "Compiler.h"
#include "Dio.h"
#include "Dio_Lld.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DIO_LLD_VENDOR_ID_C                      (180)
#define DIO_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define DIO_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define DIO_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define DIO_LLD_SW_MAJOR_VERSION_C               (2)
#define DIO_LLD_SW_MINOR_VERSION_C               (3)
#define DIO_LLD_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DIO_LLD header file are of the same vendor */
#if (DIO_LLD_VENDOR_ID_C != DIO_LLD_VENDOR_ID)
#error "Dio_Lld.c and Dio_Lld.h have different vendor ids"
#endif

/* Check if source file and DIO_LLD header file are of the same Autosar version */
#if (( DIO_LLD_AR_RELEASE_MAJOR_VERSION_C != DIO_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( DIO_LLD_AR_RELEASE_MINOR_VERSION_C != DIO_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( DIO_LLD_AR_RELEASE_REVISION_VERSION_C != DIO_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dio_Lld.c and Dio_Lld.h are different"
#endif

/* Check if source file and DIO_LLD header file are of the same Software version */
#if (( DIO_LLD_SW_MAJOR_VERSION_C != DIO_LLD_SW_MAJOR_VERSION) || \
      ( DIO_LLD_SW_MINOR_VERSION_C != DIO_LLD_SW_MINOR_VERSION) || \
      ( DIO_LLD_SW_PATCH_VERSION_C != DIO_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Dio_Lld.c and Dio_Lld.h are different"
#endif
/*=================================================================================*/
/* Check if source file and DIO_LLD_REG header file are of the same vendor */
#if (DIO_LLD_VENDOR_ID_C != DIO_LLD_REG_VENDOR_ID)
#error "Dio_Lld.c and Dio_Lld_Reg.h have different vendor ids"
#endif

/* Check if source file and DIO_LLD_REG header file are of the same Autosar version */
#if (( DIO_LLD_AR_RELEASE_MAJOR_VERSION_C != DIO_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
      ( DIO_LLD_AR_RELEASE_MINOR_VERSION_C != DIO_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
      ( DIO_LLD_AR_RELEASE_REVISION_VERSION_C != DIO_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dio_Lld.c and Dio_Lld_Reg.h are different"
#endif

/* Check if source file and DIO_LLD_REG header file are of the same Software version */
#if (( DIO_LLD_SW_MAJOR_VERSION_C != DIO_LLD_REG_SW_MAJOR_VERSION) || \
      ( DIO_LLD_SW_MINOR_VERSION_C != DIO_LLD_REG_SW_MINOR_VERSION) || \
      ( DIO_LLD_SW_PATCH_VERSION_C != DIO_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Dio_Lld.c and Dio_Lld_Reg.h are different"
#endif
/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/

#define DIO_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))
#define DIO_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))

#define DIO_REG_ADDR32_INDEX_SET_BIT(address, bitindex) ((*(volatile uint32 *)(address)) |= ((uint32)1 << (bitindex)))

#define DIO_REG_ADDR32_INDEX_GET_BIT(address, bitindex) (((*(volatile uint32 *)(address)) >> (bitindex)) & ((uint32)1U))

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
DIO_FUNC void Dio_Lld_WriteSetOutGPIOPort(Dio_PortType PortHwId, Dio_PortLevelType Level)
{
    DIO_REG_ADDR32_WRITE(GPIO_PSOR_ADDR32(PortHwId), Level);
}

DIO_FUNC void Dio_Lld_WriteClrOutGPIOPort(Dio_PortType PortHwId, Dio_PortLevelType Level)
{
    DIO_REG_ADDR32_WRITE(GPIO_PCOR_ADDR32(PortHwId), Level);
}

DIO_FUNC void Dio_Lld_WriteGPIOPin(Dio_PortType PortHwId, Dio_PinType PinHwId, Dio_LevelType Level)
{
    if ((Dio_LevelType)STD_LOW == Level)
    {
        DIO_REG_ADDR32_INDEX_SET_BIT(GPIO_PCOR_ADDR32(PortHwId), PinHwId);
    }
    else
    {
        DIO_REG_ADDR32_INDEX_SET_BIT(GPIO_PSOR_ADDR32(PortHwId), PinHwId);
    }
}

DIO_FUNC Dio_LevelType Dio_Lld_ReadGPIOPin(Dio_PortType PortHwId, Dio_PinType PinHwId)
{
    return (Dio_LevelType)DIO_REG_ADDR32_INDEX_GET_BIT(GPIO_PDIR_ADDR32(PortHwId), PinHwId);
}

DIO_FUNC void Dio_Lld_WriteGPIOPort(Dio_PortType PortHwId, Dio_PortLevelType Level)
{
    /*
     *  MR12 RULE 2.2 VIOLATION: The PDOR address has offset 0, and use the GPIO_PDOR_ADDR32() macro to
     *  keep GPIO LLD register access as the same code style
     */
    DIO_REG_ADDR32_WRITE(GPIO_PDOR_ADDR32(PortHwId), Level);/* PRQA S 2985 */
}

DIO_FUNC Dio_PortLevelType Dio_Lld_ReadGPIOPort(Dio_PortType PortHwId)
{
    return DIO_REG_ADDR32_READ(GPIO_PDIR_ADDR32(PortHwId));
}


DIO_FUNC Dio_LevelType Dio_Lld_ToggleGPIOPin(Dio_PortType PortHwId, Dio_PinType PinHwId)
{
    Dio_LevelType DioLevel = STD_LOW;
    /* toggle the PIN state */
    DIO_REG_ADDR32_INDEX_SET_BIT(GPIO_PTOR_ADDR32(PortHwId), PinHwId);
    /* read back the PIN state */

    /*
     *  MR12 RULE 2.2 VIOLATION: The PDOR address has offset 0, and use the GPIO_PDOR_ADDR32() macro to
     *  keep GPIO LLD register access as the same code style
     */
    DioLevel = (Dio_LevelType)DIO_REG_ADDR32_INDEX_GET_BIT(GPIO_PDOR_ADDR32(PortHwId), PinHwId);/* PRQA S 2985 */

    return DioLevel;
}

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/* End of file Dio_Lld.c */

