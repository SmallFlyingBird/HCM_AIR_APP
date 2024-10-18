/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file mpu_driver.h
 */

#ifndef MPU_DRIVER_H
#define MPU_DRIVER_H

#include "status.h"
#include "Platform_Types.h"

#include "Std_Types.h"

#ifndef false
#define false (0U)
#endif

#ifndef true
#define true (1U)
#endif
/*!
 * @defgroup mpu_drv MPU Driver
 * @ingroup mpu
 * @brief Memory Protection Unit Peripheral Driver.
 * @addtogroup mpu_drv
 * @{
 */
#define MPU_RGD_COUNT                                 16u
#define Cortex_M7_Core0                               0u
#define Cortex_M7_Core1                               1u
#define FEATURE_MPU_M7_MIN_REGION_SIZE                (32)
#define FEATURE_MPU_M7_MIN_REGION_SIZE_WITH_SUBREGION (256)
#define FEATURE_MPU_M7_EXECUTE_RIGHT_MASK             (16)
#define S32_SCB_CFSR_MMFSR_MASK_WITHOUT_VALID         (127)

/**
 * @brief             Enumeration listing the memory and cache attributes when RASR[TEX] == 0x0XX
 */
/* @implements     Mpu_M7_Ip_MemoryType_enum */
typedef enum
{
    MPU_M7_MEM_STRONG_ORDER = 0U,         /*!< Strongly ordered */
    MPU_M7_MEM_DEVICE_SHARED = 1U,        /*!< Shared device */
    MPU_M7_MEM_NORMAL_IO_WR_THROUGH = 2U, /*!< Outer and inner write-through, no write allocate */
    MPU_M7_MEM_NORMAL_IO_WR_BACK1 = 3U,   /*!< Outer and inner write-back, no write allocate */
    MPU_M7_MEM_NORMAL_IO_NO_CACHE = 4U,   /*!< Outer and inner Non-cacheable */
    MPU_M7_MEM_NORMAL_IO_WR_BACK2 = 5U,   /*!< Outer and inner write-back; write and read allocate */
    MPU_M7_MEM_DEVICE_NOSHARE = 6U,       /*!< Non-shared device */
    MPU_M7_MEM_NORMAL_CACHEABLE = 7U,     /*!< Normal Memory Cache policy enabled */
    MPU_M7_MEM_NO
} Mpu_M7_Ip_MemoryType;
static const uint8 u8Mpu_M7_MemoryTypeValues[MPU_M7_MEM_NO] = {
    /* 7-6, 5-3, 2, 1, 0 bit S always clear to not influence previous setting
     *        Res, TEX, S, C, B */
    0x00U, /*0b00000000,  MPU_M7_MEMORY_TYPE_STRONG_ORDER  */
    0x01U, /*0b00000001,  MPU_M7_MEMORY_TYPE_DEVICE_SHARED */
    0x02U, /*0b00000010,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_THROUGH */
    0x03U, /*0b00000011,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_BACK1 */
    0x08U, /*0b00001000,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_NO_CACHE */
    0x0BU, /*0b00001011,  MPU_M7_MEMORY_TYPE_NORMAL_IN_OUT_WRITE_BACK2 */
    0x10U, /*0b00010000,  MPU_M7_MEMORY_TYPE_DEVICE_NOSHARE */
    0x20U  /*0b00100000    MPU_M7_MEMORY_TYPE_NORMAL_CACHEABLE */
};
/*******************************************************************************
 * Definitions
 *******************************************************************************/
/*!
 * @brief MPU access error
 * Implements : mpu_err_access_type_t_Class
 */
typedef enum
{
    MPU_ERR_TYPE_READ = 0U, /*!< MPU error type: read  */
    MPU_ERR_TYPE_WRITE = 1U /*!< MPU error type: write */
} mpu_err_access_type_t;

/*!
 * @brief MPU access error attributes
 * Implements : mpu_err_attributes_t_Class
 */
typedef enum
{
    MPU_INSTRUCTION_ACCESS_IN_USER_MODE = 0U,       /*!< Access instruction error in user mode         */
    MPU_DATA_ACCESS_IN_USER_MODE = 1U,              /*!< Access data error in user mode                  */
    MPU_INSTRUCTION_ACCESS_IN_SUPERVISOR_MODE = 2U, /*!< Access instruction error in supervisor mode */
    MPU_DATA_ACCESS_IN_SUPERVISOR_MODE = 3U         /*!< Access data error in supervisor mode          */
} mpu_err_attributes_t;

/*!
 * @brief MPU detail error access info
 * Implements : mpu_access_err_info_t_Class
 */

typedef enum
{
    MPU_M7_MEMMAN_ERROR_INSTRUCTION_ACCESS, /*! IACCVIOL  Instruction access violation */
    MPU_M7_MEMMAN_ERROR_DATA_ACCESS,        /*! DACCVIOL  Data access violation */
    MPU_M7_MEMMAN_ERROR_STACK,              /*! MUNSTKERR MemManage fault on unstacking for a return from exception */
    MPU_M7_MEMMAN_ERROR_UNSTACK,            /*! MSTKERR    MemManage fault on stacking for exception entry*/
    MPU_M7_MEMMAN_ERROR_FLOATING_POINT, /*! MLSPERR    MemManage fault during floating point lazy state preservation*/
    MPU_M7_MEMMAN_ERROR_MULTIPLE,       /*! MemManage fault Multiple Errors detected */
    MPU_M7_MEMMAN_ERROR_NONE
} Mpu_M7_Ip_ErrorType;

typedef struct Mpu_M7_Ip_ErrorDetailsType
{
    uint32 u32Address;         /*!< Violation address */
    Mpu_M7_Ip_ErrorType eType; /*!< Type of violation */
} Mpu_M7_Ip_ErrorDetailsType;
/*!
 * @brief MPU access rights.
 * |        Code                            |  Supervisor  |      User     |  Description |
 * |-------------------------------|--------------|-------------|------------------------------------------------------------------------------------|
 * |  MPU_SUPERVISOR_RWX_USER_NONE |     r w x      |     - - -     | Allow Read, write, execute in supervisor mode; no
 * access in user mode                  | |  MPU_SUPERVISOR_RWX_USER_X     |     r w x      |     - - x     | Allow
 * Read, write, execute in supervisor mode; execute in user mode                     | |  MPU_SUPERVISOR_RWX_USER_W | r
 * w x      |     - w -     | Allow Read, write, execute in supervisor mode; write in user mode                        |
 * |  MPU_SUPERVISOR_RWX_USER_WX    |     r w x      |     - w x     | Allow Read, write, execute in supervisor mode;
 * write and execute in user mode        | |  MPU_SUPERVISOR_RWX_USER_R     |     r w x      |     r - -     | Allow
 * Read, write, execute in supervisor mode; read in user mode                         | |  MPU_SUPERVISOR_RWX_USER_RX |
 * r w x      |     r - x     | Allow Read, write, execute in supervisor mode; read and execute in user mode         |
 * |  MPU_SUPERVISOR_RWX_USER_RW    |     r w x      |     r w -     | Allow Read, write, execute in supervisor mode;
 * read and write in user mode            | |  MPU_SUPERVISOR_RWX_USER_RWX  |     r w x      |     r w x     | Allow
 * Read, write, execute in supervisor mode; read, write and execute in user mode| |  MPU_SUPERVISOR_RX_USER_NONE  | r -
 * x      |     - - -     | Allow Read, execute in supervisor mode; no access in user mode                            |
 * |  MPU_SUPERVISOR_RX_USER_X      |     r - x      |     - - x     | Allow Read, execute in supervisor mode; execute
 * in user mode                              | |  MPU_SUPERVISOR_RX_USER_W      |     r - x      |     - w -     | Allow
 * Read, execute in supervisor mode; write in user mode                                 | |  MPU_SUPERVISOR_RX_USER_WX
 * |     r - x      |     - w x     | Allow Read, execute in supervisor mode; write and execute in user mode | |
 * MPU_SUPERVISOR_RX_USER_R      |     r - x      |     r - -     | Allow Read, execute in supervisor mode; read in user
 * mode                                  | |  MPU_SUPERVISOR_RX_USER_RX     |     r - x      |     r - x     | Allow
 * Read, execute in supervisor mode; read and execute in user mode                  | |  MPU_SUPERVISOR_RX_USER_RW     |
 * r - x      |     r w -     | Allow Read, execute in supervisor mode; read and write in user mode | |
 * MPU_SUPERVISOR_RX_USER_RWX    |     r - x      |     r w x     | Allow Read, execute in supervisor mode; read, write
 * and execute in user mode         | |  MPU_SUPERVISOR_RW_USER_NONE  |     r w -      |     - - -     | Allow Read,
 * write in supervisor mode; no access in user mode                              | |  MPU_SUPERVISOR_RW_USER_X      | r
 * w -      |     - - x     | Allow Read, write in supervisor mode; execute in user mode | |  MPU_SUPERVISOR_RW_USER_W
 * |     r w -      |     - w -     | Allow Read, write in supervisor mode; write in user mode | |
 * MPU_SUPERVISOR_RW_USER_WX     |     r w -      |     - w x     | Allow Read, write in supervisor mode; write and
 * execute in user mode                    | |  MPU_SUPERVISOR_RW_USER_R      |     r w -      |     r - -     | Allow
 * Read, write in supervisor mode; read in user mode                                     | |  MPU_SUPERVISOR_RW_USER_RX
 * |     r w -      |     r - x     | Allow Read, write in supervisor mode; read and execute in user mode | |
 * MPU_SUPERVISOR_RW_USER_RW     |     r w -      |     r w -     | Allow Read, write in supervisor mode; read and write
 * in user mode                        | |  MPU_SUPERVISOR_RW_USER_RWX    |     r w -      |     r w x     | Allow Read,
 * write in supervisor mode; read, write and execute in user mode            | |  MPU_SUPERVISOR_USER_NONE      |     -
 * - -      |     - - -     | No access allowed in user and supervisor modes | |  MPU_SUPERVISOR_USER_X          |     -
 * - x      |     - - x     | Execute operation is allowed in user and supervisor modes | |  MPU_SUPERVISOR_USER_W | - w
 * -      |     - w -     | Write operation is allowed in user and supervisor modes | |  MPU_SUPERVISOR_USER_WX |     -
 * w x      |     - w x     | Write and execute operations are allowed in user and supervisor modes                  |
 * |  MPU_SUPERVISOR_USER_R          |     r - -      |     r - -     | Read operation is allowed in user and supervisor
 * modes                                      | |  MPU_SUPERVISOR_USER_RX         |     r - x      |     r - x     |
 * Read and execute operations are allowed in user and supervisor modes                    | |  MPU_SUPERVISOR_USER_RW
 * |     r w -      |     r w -     | Read and write operations are allowed in user and supervisor modes | |
 * MPU_SUPERVISOR_USER_RWX        |     r w x      |     r w x     | Read write and execute operations are allowed in
 * user and supervisor modes            |
 *
 *
 * |        Code                            | Read/Write permission    | Description                              |
 * |-------------------------------|-------------------------|-----------------------------------|
 * |  MPU_NONE                            |             - -                | No Read/Write access permission    |
 * |  MPU_W                                |             - w                | Write access permission              |
 * |  MPU_R                                |             r -                | Read access permission                |
 * |  MPU_RW                              |             r w                | Read/Write access permission        |
 * Implements : mpu_access_rights_t_Class
 */
#if 0
typedef enum
{
     /* Format: M_R_W_SS_UUU
      * M  : 1 bit  - Specify that access right is for masters which have separated
      * privilege rights for user and supervisor mode accesses (e.g. master0~3)
      * R  : 1 bit  - Read access permission
      * W  : 1 bit  - Write access permission
      * SS : 2 bits - Supervisor Mode Access Control
      * UUU: 3 bits - User Mode Access Control
      */
     MPU_SUPERVISOR_RWX_USER_NONE     = 0x00U,     /*!< 0b00000000U : rwx|--- */
     MPU_SUPERVISOR_RWX_USER_X         = 0x01U,     /*!< 0b00000001U : rwx|--x */
     MPU_SUPERVISOR_RWX_USER_W         = 0x02U,     /*!< 0b00000010U : rwx|-w- */
     MPU_SUPERVISOR_RWX_USER_WX        = 0x03U,     /*!< 0b00000011U : rwx|-wx */
     MPU_SUPERVISOR_RWX_USER_R         = 0x04U,     /*!< 0b00000100U : rwx|r-- */
     MPU_SUPERVISOR_RWX_USER_RX        = 0x05U,     /*!< 0b00000101U : rwx|r-x */
     MPU_SUPERVISOR_RWX_USER_RW        = 0x06U,     /*!< 0b00000110U : rwx|rw- */
     MPU_SUPERVISOR_RWX_USER_RWX      = 0x07U,     /*!< 0b00000111U : rwx|rwx */
     MPU_SUPERVISOR_RX_USER_NONE      = 0x08U,     /*!< 0b00001000U : r-x|--- */
     MPU_SUPERVISOR_RX_USER_X          = 0x09U,     /*!< 0b00001001U : r-x|--x */
     MPU_SUPERVISOR_RX_USER_W          = 0x0AU,     /*!< 0b00001010U : r-x|-w- */
     MPU_SUPERVISOR_RX_USER_WX         = 0x0BU,     /*!< 0b00001011U : r-x|-wx */
     MPU_SUPERVISOR_RX_USER_R          = 0x0CU,     /*!< 0b00001100U : r-x|r-- */
     MPU_SUPERVISOR_RX_USER_RX         = 0x0DU,     /*!< 0b00001101U : r-x|r-x */
     MPU_SUPERVISOR_RX_USER_RW         = 0x0EU,     /*!< 0b00001110U : r-x|rw- */
     MPU_SUPERVISOR_RX_USER_RWX        = 0x0FU,     /*!< 0b00001111U : r-x|rwx */
     MPU_SUPERVISOR_RW_USER_NONE      = 0x10U,     /*!< 0b00010000U : rw-|--- */
     MPU_SUPERVISOR_RW_USER_X          = 0x11U,     /*!< 0b00010001U : rw-|--x */
     MPU_SUPERVISOR_RW_USER_W          = 0x12U,     /*!< 0b00010010U : rw-|-w- */
     MPU_SUPERVISOR_RW_USER_WX         = 0x13U,     /*!< 0b00010011U : rw-|-wx */
     MPU_SUPERVISOR_RW_USER_R          = 0x14U,     /*!< 0b00010100U : rw-|r-- */
     MPU_SUPERVISOR_RW_USER_RX         = 0x15U,     /*!< 0b00010101U : rw-|r-x */
     MPU_SUPERVISOR_RW_USER_RW         = 0x16U,     /*!< 0b00010110U : rw-|rw- */
     MPU_SUPERVISOR_RW_USER_RWX        = 0x17U,     /*!< 0b00010111U : rw-|rwx */
     MPU_SUPERVISOR_USER_NONE          = 0x18U,     /*!< 0b00011000U : ---|--- */
     MPU_SUPERVISOR_USER_X              = 0x19U,     /*!< 0b00011001U : --x|--x */
     MPU_SUPERVISOR_USER_W              = 0x1AU,     /*!< 0b00011010U : -w-|-w- */
     MPU_SUPERVISOR_USER_WX             = 0x1BU,     /*!< 0b00011011U : -wx|-wx */
     MPU_SUPERVISOR_USER_R              = 0x1CU,     /*!< 0b00011100U : r--|r-- */
     MPU_SUPERVISOR_USER_RX             = 0x1DU,     /*!< 0b00011101U : r-x|r-x */
     MPU_SUPERVISOR_USER_RW             = 0x1EU,     /*!< 0b00011110U : rw-|rw- */
     MPU_SUPERVISOR_USER_RWX            = 0x1FU,     /*!< 0b00011111U : rwx|rwx */
     MPU_NONE                                = 0x80U,     /*!< 0b10000000U : --        */
     MPU_W                                    = 0xA0U,     /*!< 0b10100000U : w-        */
     MPU_R                                    = 0xC0U,     /*!< 0b11000000U : -r        */
     MPU_RW                                  = 0xE0U      /*!< 0b11100000U : wr        */
} mpu_access_rights_t;

/*!
 * @brief MPU master access rights.
 * Implements : mpu_master_access_right_t_Class
 */
typedef struct
{
     uint8                            masterNum;                        /*!< Master number                                  */
     mpu_access_rights_t            accessRight;                     /*!< Access right                                    */
#if FEATURE_MPU_HAS_PROCESS_IDENTIFIER
     boolean                                processIdentifierEnable;     /*!< Enables or disables process identifier */
#endif
} mpu_master_access_right_t;

/*!
 * @brief MPU user region configuration structure.
 * This structure is used when calling the MPU_DRV_Init function.
 * Implements : mpu_user_config_t_Class
 */
typedef struct
{
     uint32                                     startAddr;                /*!< Memory region start address                         */
     uint32                                     endAddr;                  /*!< Memory region end address                            */
     const mpu_master_access_right_t      *masterAccRight;        /*!< Access permission for masters                      */
#if FEATURE_MPU_HAS_PROCESS_IDENTIFIER
     uint8                                      processIdentifier;     /*!< Process identifier                                     */
     uint8                                      processIdMask;          /*!< Process identifier mask. The setting bit will
                                                                                  ignore the same bit in process identifier             */
#endif /* FEATURE_MPU_HAS_PROCESS_IDENTIFIER */
} mpu_user_config_t;
#endif
/**
 * @brief             Enumeration listing the outer and inner cache policies when RASR[TEX] == 0x1XX
 */
/* @implements      Mpu_M7_Ip_CachePolicyType_enum */
typedef enum
{
    MPU_M7_CACHE_POLICY_NO_CACHE = 0UL,                /*!< Non-cacheable */
    MPU_M7_CACHE_POLICY_W_BACK_WR_ALLOCATE = 1UL,      /*!< Write-back, write and read allocate */
    MPU_M7_CACHE_POLICY_W_THROUGH_NO_W_ALLOCATE = 2UL, /*!< Write-through, no write allocate */
    MPU_M7_CACHE_POLICY_W_BACK_NO_W_ALLOCATE = 3UL     /*!< Write-back, no write allocate */
} Mpu_M7_Ip_CachePolicyType;

/**
 * @brief             Enumeration listing access permisions
 */
/* @implements     Mpu_M7_Ip_AccessRightsType_enum */
typedef enum
{
    /* Format: X_R_APP
     * X  = 1 bit : Execute Allow or not
     * R  = 1 bit : Reserved
     *APP = 3 bit : Define Privileged & Uprivileged Access Right
     */
    MPU_M7_PRIV_UNPRIV_NONE = 0x00U,     /*!< 0b00000000U : ---|--- */
    MPU_M7_PRIV_RW_UNPRIV_NONE = 0x01U,  /*!< 0b00000001U : rw-|--- */
    MPU_M7_PRIV_RWX_UNPRIV_NONE = 0x11U, /*!< 0b00010001U : rwx|--- */
    MPU_M7_PRIV_RW_UNPRIV_R = 0x02U,     /*!< 0b00000010U : rw-|r-- */
    MPU_M7_PRIV_RWX_UNPRIV_RX = 0x12U,   /*!< 0b00010010U : rwx|r-x */
    MPU_M7_PRIV_RW_UNPRIV_RW = 0x03U,    /*!< 0b00000011U : rw-|rw- */
    MPU_M7_PRIV_RWX_UNPRIV_RWX = 0x13U,  /*!< 0b00010011U : rwx|rwx */
    MPU_M7_PRIV_R_UNPRIV_NONE = 0x05U,   /*!< 0b00000101U : r--|--- */
    MPU_M7_PRIV_RX_UNPRIV_NONE = 0x15U,  /*!< 0b00010101U : r-x|--- */
    MPU_M7_PRIV_R_UNPRIV_R = 0x06U,      /*!< 0b00000110U : r--|r-- */
    MPU_M7_PRIV_RX_UNPRIV_RX = 0x16U,    /*!< 0b00010110U : r-x|r-x */
} Mpu_M7_Ip_AccessRightsType;

typedef struct
{
    uint8 u8RegionNum;                           /*!< Region number                          */
    uint32 u32StartAddr;                         /*!< Memory region start address        */
    uint32 u32EndAddr;                           /*!< Memory region end address          */
    Mpu_M7_Ip_MemoryType eMemType;               /*!< Memory Type for region              */
    Mpu_M7_Ip_AccessRightsType eAccessRight;     /*!< Access permission for region      */
    Mpu_M7_Ip_CachePolicyType eOuterCachePolicy; /*!< Outer Cache Policy                    */
    Mpu_M7_Ip_CachePolicyType eInnerCachePolicy; /*!< Inner Cache Policy                    */
    uint8 u8SubRegMask;                          /*!< SubRegion Disable Mask              */
    boolean bShareable;                          /*!< Enables or disables shareability */
} mpu_user_config_t;

/**
 * @brief             IP configuration structure
 */
/* @implements      Mpu_M7_Ip_ConfigType_struct */
typedef struct Mpu_M7_Ip_ConfigType
{
    uint8 ConfigCore;
    boolean bDefaultMapEn;   /*!< Enables the default memory map background region */
    boolean bEnableRunHFNMI; /*!< Enables use of the MPU when in the hard fault, non-maskable interrupt, and FAULTMASK
                                escalated handlers  */
    boolean bEnMemManageInterrupt;             /*!< Enable Memory Manage Fault Exception Handler */
    uint8 u8RegionCnt;                         /*! Region Count */
    const mpu_user_config_t* pRegionConfigArr; /*! Region configuration array */
} Mpu_M7_Ip_ConfigType;

/*******************************************************************************
 * API
 *******************************************************************************/
/*!
 * @name MPU Driver API
 * @{
 */
#if defined(__cplusplus)
extern "C"
{
#endif

    /*!
     * @brief The function sets the MPU regions according to user input and then enables the MPU.
     * Please note that access rights for region 0 will always be configured and
     * regionCnt takes values between 1 and the maximum region count supported by the hardware.
     * e.g. In S32K144 the number of supported regions is 8.
     * The user must make sure that the clock is enabled.
     *
     * @param[in] instance The MPU peripheral instance number.
     * @param[in] regionCnt The number of configured regions.
     * @param[in] userConfigArr The pointer to the array of MPU user configure structure, see #mpu_user_config_t.
     * @return operation status
     *          - STATUS_SUCCESS:     Operation was successful.
     *          - STATUS_ERROR:        Operation failed due to master number is out of range supported by hardware.
     */
    status_t MPU_DRV_Init(Mpu_M7_Ip_ConfigType* pConfig);

    /*!
     * @brief De-initializes the MPU region by resetting and disabling MPU module.
     *
     * @param[in] instance The MPU peripheral instance number.
     */
    void MPU_DRV_Deinit(void);

    /*!
     * @brief Sets the region start and end address.
     *
     * @param[in] instance The MPU peripheral instance number.
     * @param[in] regionNum The region number.
     * @param[in] startAddr The region start address.
     * @param[in] endAddr The region end address.
     */
    void MPU_DRV_SetRegionAddr(uint32 instance, uint8 regionNum, uint32 startAddr, uint32 endAddr);

    /*!
     * @brief Sets the region configuration.
     *
     * @param[in] instance The MPU peripheral instance number.
     * @param[in] regionNum The region number.
     * @param[in] userConfigPtr The region configuration structure pointer.
     * @return operation status
     *          - STATUS_SUCCESS:     Operation was successful.
     *          - STATUS_ERROR:        Operation failed due to master number is out of range supported by hardware.
     */
    status_t MPU_DRV_SetRegionConfig(uint8 u8RegionNum, const mpu_user_config_t* pUserConfigPtr);

    /*!
     * @brief Checks and gets the MPU access error detail information for a slave port.
     *
     * @param[in] instance The MPU peripheral instance number.
     * @param[in] slavePortNum The slave port number to get Error Detail.
     * @param[out] errInfoPtr The pointer to access error info structure.
     * @return operation status
     *          - true  : An error has occurred.
     *          - false : No error has occurred.
     */
    boolean MPU_DRV_GetDetailErrorAccessInfo(Mpu_M7_Ip_ErrorDetailsType* pErrorDetails);

    /*!
     * @brief Gets default region configuration. Grants all access rights for masters
     * and disable PID.
     *
     * @param[in] instance The MPU peripheral instance number.
     * @param[out] masterAccRight The pointer to master configuration structure, see #mpu_master_access_right_t.
     *                                     The length of array should be defined by number of masters supported by
     * hardware.
     * @return The default region configuration, see #mpu_user_config_t.
     */
    mpu_user_config_t MPU_DRV_GetDefaultRegionConfig(mpu_user_config_t* masterAccRight);

    /*!
     * @brief Enables/Disables region descriptor.
     * Please note that region 0 should not be disabled.
     *
     * @param[in] instance The MPU peripheral instance number.
     * @param[in] regionNum The region number.
     * @param[in] enable Valid state
     *                - true  : Enable region.
     *                - false : Disable region.
     */
    void MPU_DRV_EnableRegion(uint32 instance, uint8 regionNum, boolean enable);

    /*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* MPU_DRIVER_H */
/*******************************************************************************
 * EOF
 *******************************************************************************/
