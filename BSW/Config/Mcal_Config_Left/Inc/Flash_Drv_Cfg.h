/**************************************************************************************************/
/**
 * @file      : Flash_Drv_Cfg.h  
 * @brief     : Flash driver configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLASH_DRV_CFG_H
#define FLASH_DRV_CFG_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv_Cfg
 *  @brief Flash driver level configuration 
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLASH_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define FLASH_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define FLASH_DRV_CFG_H_SW_MINOR_VERSION            2U
#define FLASH_DRV_CFG_H_SW_PATCH_VERSION            2U

#define FLASH_DRV_SECTOR_SIZE                   0x2000U

#define FLASH_DRV_PHRASE_SIZE                   0x10U

/* Pflash */
#define FLASH_DRV_PFLASH_BASE_ADDR              (0U)
#define FLASH_DRV_PFLASH_SIZE                   (0x00200000U)
#define FLASH_DRV_PFLASH_END_ADDR               (FLASH_DRV_PFLASH_BASE_ADDR + FLASH_DRV_PFLASH_SIZE - 1U)
/* Pflash IFR */
#define FLASH_DRV_PFLASH_IFR_BASE_ADDR          (0x02000000U)
#define FLASH_DRV_PFLASH_IFR_SIZE               (0x00008000U)
#define FLASH_DRV_PFLASH_IFR_END_ADDR           (FLASH_DRV_PFLASH_IFR_BASE_ADDR + FLASH_DRV_PFLASH_IFR_SIZE - 1U)
/* Dflash */
#define FLASH_DRV_DFLASH_BASE_ADDR              (0x01000000U)
#define FLASH_DRV_DFLASH_SIZE                   (0x00020000U)
#define FLASH_DRV_DFLASH_END_ADDR               (FLASH_DRV_DFLASH_BASE_ADDR + FLASH_DRV_DFLASH_SIZE - 1U)

/* check address is in PFLASH */
#define FLASH_DRV_VALID_PFLASH_ADDR(addr)       ((addr) <= FLASH_DRV_PFLASH_END_ADDR)

/* check address is in PFLASH IFR */
#define FLASH_DRV_VALID_PFLASH_IFR_ADDR(addr)   (((addr) >= FLASH_DRV_PFLASH_IFR_BASE_ADDR) && ((addr) <= FLASH_DRV_PFLASH_IFR_END_ADDR))

/* check address is in DFLASH */
#define FLASH_DRV_VALID_DFLASH_ADDR(addr)       (((addr) >= FLASH_DRV_DFLASH_BASE_ADDR) && ((addr) <= FLASH_DRV_DFLASH_END_ADDR))          

/* check address is in PFLASH or DFLASH */
#define FLASH_DRV_VALID_FLASH_ADDR(addr)        (FLASH_DRV_VALID_PFLASH_ADDR(addr) || FLASH_DRV_VALID_PFLASH_IFR_ADDR(addr) || FLASH_DRV_VALID_DFLASH_ADDR(addr))

/* check address is sector aligned */
#define FLASH_DRV_SECTOR_ALIGNED(addr)          (((addr) & (FLASH_DRV_SECTOR_SIZE - 1U)) == 0U)

/* check address is phrase aligned */
#define FLASH_DRV_PHRASE_ALIGNED(addr)          (((addr) & (FLASH_DRV_PHRASE_SIZE - 1U)) == 0U)  

#define FLASH_DRV_ERASED_VALUE                  (0xFFFFFFFFU)

#define FLASH_DRV_DEV_ERROR_DETECT              (STD_ON)

#define FLASH_DRV_SYNCHRONIZE_CACHE             (STD_OFF)

#define FLASH_DRV_ECC_CHECK_INT                 (STD_ON)

#define FLASH_DRV_TIMEOUT_ABORT_WAIT_CNT        300U

#define FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED   (STD_OFF)

#define FLASH_DRV_TIMEOUT_TYPE                  (MCALLIB_COUNTER_SOFTWARE)

#define FLASH_DRV_TIMEOUT_ERASE                 (2147483647U)
#define FLASH_DRV_TIMEOUT_ERASE_IN_AC           (2147483647U)
#define FLASH_DRV_TIMEOUT_WRITE                 (2147483647U)
#define FLASH_DRV_TIMEOUT_WRITE_IN_AC           (2147483647U)

#define FLASH_DRV_CONFIG_EXT \
        extern const Flash_Drv_ConfigType Flash_DrvConfig;
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *	@{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv_Cfg */

/** @} end of group Fls_Module */

#endif /* FLASH_DRV_CFG_H */
