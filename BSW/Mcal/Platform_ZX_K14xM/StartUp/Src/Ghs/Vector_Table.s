/*****************************************************************************************/
/* @file      : Vector_Table.s                                                           */
/* @brief     : Vector table Source File.                                                */
/*              - Platform: Z20K14xM                                                     */
/*              - Autosar Version: 4.6.0                                                 */
/* @version   : 1.2.1                                                                    */
/* @author    : Zhixin Semiconductor                                                     */
/* @note                                                                                 */
/*                                                                                       */
/* @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.   */
/*****************************************************************************************/
.section  ".intc_vector","ax"
.align 2
.thumb
.globl undefined_handler
.globl __VECTOR_TABLE
.globl __STACK_TOP               /* Top of Stack for Initial Stack Pointer */
.globl Reset_Handler             /* Reset Handler */
.globl NMI_Handler               /* NMI Handler */
.globl HardFault_Handler         /* Hard Fault Handler */
.globl MemManageFault_Handler    /* Reserved */
.globl BusFault_Handler          /* Bus Fault Handler */
.globl UsageFault_Handler        /* Usage Fault Handler */
.globl SVC_Handler               /* SVCall Handler */
.globl DebugMonitor_Handler      /* Debug Monitor Handler */

.globl SysTick_Handler           /* SysTick Handler */ /* 15*/

__VECTOR_TABLE:

.long __STACK_TOP          /* Top of Stack for Initial Stack Pointer */
.long Reset_Handler+1           /* Reset Handler need plus 1 because Reset_Handler is generated with LSB bit =0*/
.long NMI_Handler               /* NMI Handler */
.long HardFault_Handler         /* Hard Fault Handler */
.long MemManageFault_Handler    /* Reserved */
.long BusFault_Handler          /* Bus Fault Handler */
.long UsageFault_Handler        /* Usage Fault Handler */
.long 0                         /* Reserved */
.long 0                         /* Reserved */
.long 0                         /* Reserved */
.long 0                         /* Reserved */
.long SVC_Handler+1             /* SVCall Handler */
.long 0      /* Debug Monitor Handler */
.long 0                         /* Reserved */
.long 0            /* PendSV Handler */
.long SysTick_Handler           /* SysTick Handler */ /* 15*/

.long undefined_handler /*0*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*10*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*20*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*30*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler /*40*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler /*50*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*60*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*70*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*80*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*90*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*100*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*110*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*120*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*130*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*140*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*150*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*160*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*170*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*180*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*190*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*200*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*204*/

.size __VECTOR_TABLE, . - __VECTOR_TABLE
