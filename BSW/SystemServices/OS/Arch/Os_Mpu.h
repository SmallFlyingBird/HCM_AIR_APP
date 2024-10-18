/*===========================================================================*/
/*  Copyright (C) 2020, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Os_Mpu.h>
 *  @brief      <>
 *
 * <Compiler: S32K    MCU:S32K14X>
 *
 *  @author     <xiaohong.hu>
 *  @date       <05-12-2020>
 */
/*===========================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]===================================*/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V0.1.0       20201205    xiaohong.hu     Initial version
 */
/*===========================================================================*/
#ifndef OS_ARCH_OS_MPU_H_
#define OS_ARCH_OS_MPU_H_


#define Os_RaisePrivilege()     Os_ArchSyscall()
#define Os_LowerPrivilege()     Os_SetCpuMode(OS_CPUMODE_USER0)
#define Os_MPU_CESR             0x4000D000u


#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
extern VAR(uint16, OS_VAR)  HardFault_Flag;

extern FUNC(void, OS_CODE) Os_ArchMemProtEnable(void);

/* Memory Protection Set */
#define OS_ARCH_API_DEFINE()

#define OS_ARCH_API_ENTRY()         \
    uint32 MPU_Group = 0u;  \
    if((1u == (getControlValue() & 0x00000001u)))   \
    {   \
        Os_RaisePrivilege();    \
        MPU_Group = 1u; \
    }   \
    else    \
    {   \
    }

#define OS_ARCH_API_EXIT()  \
    if (MPU_Group > 0u) \
    {   \
        Os_LowerPrivilege();    \
    }

#else
#define OS_ARCH_API_DEFINE()
#define OS_ARCH_API_ENTRY()
#define OS_ARCH_API_EXIT()
#endif


#endif /* 02_SOURCE_OS_ARCH_OS_MPU_H_ */
