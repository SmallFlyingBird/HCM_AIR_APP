/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Os_ArchMacro.h>
 *  @brief      <>
 *
 * <Compiler: S32K    MCU:S32K344>
 *
 *  @author     <jiansen.zhao>
 *  @date       <04-01-2022>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>       <AUTHOR>          <REVISION LOG>
 *  V0.1.0      2021070705   jiansen.zhao     Initial version
 */
/*============================================================================*/
#ifndef OS_ARCHMACRO_H
#define OS_ARCHMACRO_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/

/*=======[I N C L U D E S]====================================================*/

/*=======[M A C R O S]========================================================*/
#if defined(OS_SECTION_RESTORE)
#if defined(OS_SECTION_CODE)
#undef OS_SECTION_CODE
#pragma GCC section text
#elif defined(OS_SECTION_DATA)
#undef OS_SECTION_DATA
/* #pragma GCC section data */
#elif defined(OS_SECTION_STACK)
#undef OS_SECTION_STACK
/* #pragma GCC section bss */
#endif
#undef OS_SECTION_RESTORE
#endif

#if defined(OS_SECTION_NAME)
#if defined(OS_SECTION_CODE)
/* #define dddd ".OSCore0_OsApplication_0Code" */
/* #pragma GCC section text dddd */
__attribute__((section(OS_SECTION_NAME)))
#elif defined(OS_SECTION_DATA)
/* #pragma GCC section data OS_SECTION_NAME */
__attribute__((section(OS_SECTION_NAME)))
#elif defined(OS_SECTION_STACK)
/* #pragma GCC section bss OS_SECTION_NAME */
__attribute__((section(OS_SECTION_NAME)))
#endif
#undef OS_SECTION_NAME
#endif

#endif /* #ifndef OS_ARCHMACRO_H */

/*=======[E N D   O F   F I L E]==============================================*/
