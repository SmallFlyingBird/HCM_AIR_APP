/**************************************************************************************************/
/**
 * @file      : Flash_Drv_Ac.c
 * @brief     : Internal flash access code source file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv_Ac
 *  @brief Internal Flash access code
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Flash_Drv_Ac.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *	@{
 */
/* Published information */
#define FLASH_DRV_AC_C_VENDOR_ID                   0x00B3U
#define FLASH_DRV_AC_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_AC_C_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_AC_C_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_AC_C_SW_MAJOR_VERSION            1U
#define FLASH_DRV_AC_C_SW_MINOR_VERSION            2U
#define FLASH_DRV_AC_C_SW_PATCH_VERSION            1U

/* Check if current file and Flash_Drv_Ac.h are the same vendor */
#if (FLASH_DRV_AC_C_VENDOR_ID != FLASH_DRV_AC_H_VENDOR_ID)
    #error "Vendor ID of Flash_Drv_Ac.c and Flash_Drv_Ac.h are different"
#endif
/* Check if current file and Flash_Drv_Ac.h are the same Autosar version */
#if ((FLASH_DRV_AC_C_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_AC_H_AR_RELEASE_MAJOR_VERSION) || \
     (FLASH_DRV_AC_C_AR_RELEASE_MINOR_VERSION != FLASH_DRV_AC_H_AR_RELEASE_MINOR_VERSION) || \
     (FLASH_DRV_AC_C_AR_RELEASE_REVISION_VERSION != FLASH_DRV_AC_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Flash_Drv_Ac.c and Flash_Drv_Ac.h are different"
#endif
/* Check if current file and Flash_Drv_Ac.h are the same Software version */
#if ((FLASH_DRV_AC_C_SW_MAJOR_VERSION != FLASH_DRV_AC_H_SW_MAJOR_VERSION) || \
     (FLASH_DRV_AC_C_SW_MINOR_VERSION != FLASH_DRV_AC_H_SW_MINOR_VERSION) || \
     (FLASH_DRV_AC_C_SW_PATCH_VERSION != FLASH_DRV_AC_H_SW_PATCH_VERSION))
    #error "Software Version of Flash_Drv_Ac.c and Flash_Drv_Ac.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((FLASH_DRV_AC_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||    \
         (FLASH_DRV_AC_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Flash_Drv_Ac.c and Device_Regs.h are different"
    #endif
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
#define FLS_START_SEC_CODE_AC
#include "Fls_MemMap.h"
/* SWS_Fls_00137 */
#if (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
/**
 * @brief     Flash Access code
 *
 * @param[in] CallBack: It points to the callback function that will be called while waiting for
 *                      completing the command.  If no callback function is needed, please set
 *                      this parameter to NULL.
 *
 * @return none
 */
void Flash_Drv_AccessCode(void (*CallBack)(void))
{
    /* MISRA2012 Rule-11.4 violation: Convert an integral type of register address to a pointer object, 
    no side effects forseen by violating this rule */
    Reg_Flash_BfType const *FlashRegPtr = (Reg_Flash_BfType *) FLASHC_BASE_ADDR;

    /* clear CCIF to start cmd */
    ASM_KEYWORD volatile(
        "PUSH  {R0, R1, R2}\n"
		"LDR   R0, =0x40020000\n"
		"LDR   R1, =0x80\n"
		"STR   R1, [R0]\n"
		"LDR   R2, [R0]\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
        "POP  {R0, R1, R2}\n"
        );

    while ((FlashRegPtr->FLASH_FSTAT.CCIF == 0U) && (Flash_Drv_ElapsedTicks < Flash_Drv_TimeoutTicks))
    {
        if (CallBack != NULL_PTR)
        {
            CallBack();
        }
        Flash_Drv_ElapsedTicks++;
    }
}
#else
/**
 * @brief     Flash Access code
 *
 * @param[in] CallBack: It points to the callback function that will be called while waiting for
 *                      completing the command.  If no callback function is needed, please set
 *                      this parameter to NULL.
 *
 * @return none
 */
void Flash_Drv_AccessCode(void (*CallBack)(void))
{
    /* MISRA2012 Rule-11.4 violation: Convert an integral type of register address to a pointer object, 
    no side effects forseen by violating this rule */
    Reg_Flash_BfType *FlashRegPtr = (Reg_Flash_BfType *) FLASHC_BASE_ADDR;

    /* clear CCIF to start cmd */
    ASM_KEYWORD volatile(
        "PUSH  {R0, R1, R2}\n"
		"LDR   R0, =0x40020000\n"
		"LDR   R1, =0x80\n"
		"STR   R1, [R0]\n"
		"LDR   R2, [R0]\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
		"NOP\n"
        "POP  {R0, R1, R2}\n"
        );

    while (FlashRegPtr->FLASH_FSTAT.CCIF == 0U)
    {
        if (CallBack != NULL_PTR)
        {
            CallBack();
        }
    }
}
#endif /* FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

#define FLS_STOP_SEC_CODE_AC
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv_Ac */

/** @} end of group Fls_Module */
