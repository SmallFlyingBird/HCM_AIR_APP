/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <cmac.h>
 *
 *  <Compiler: Don't Care    MCU: Don't Care>
 *
 *  @author     <Xinglin Li>
 *  @date       <2022-07-13>
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/

/*=========[R E V I S I O N   H I S T O R Y]==================================*/
/** <VERSION>   <DATE>   <AUTHOR>        <REVISION LOG>
 *    V1.0.0    20220714   Xinglin Li	 New Version
 *
 */
/*============================================================================*/

#ifndef CMAC_H
#define CMAC_H

/*=======[I N C L U D E S]====================================================*/
#include "Std_Types.h"

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
Std_ReturnType Crypto_GernerateMAC(
		uint8* Key,
        uint8* inputData,
        uint32 inputlength,
		uint8* OutPutData);

#endif /* CMAC_H */
