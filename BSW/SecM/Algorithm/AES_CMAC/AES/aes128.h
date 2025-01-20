/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <aes.h>
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

#ifndef AES_H
#define AES_H
#define AES_ENCRYPT     1 /**< AES encryption. */
#define AES_DECRYPT     0 /**< AES decryption. */

/*=======[I N C L U D E S]====================================================*/
#include "Std_Types.h"

/**=======[T Y P E   D E F I N I T I O N S]===================================*/
typedef struct
{
    int nr;                     /*!< The number of rounds. */
    uint32 *rk;               /*!< AES round keys. */
    uint32 buf[68];           /*!< Unaligned data buffer. This buffer can
                                     hold 32 extra Bytes,which can be used for
                                     one of the following purposes:
                                     <ul><li>Alignment if VIA padlock is
                                             used.</li>
                                     <li>Simplifying key expansion in the 256-bit
                                         case by generating an extra round key.
                                         </li></ul> */
}Crypto_AESData;



/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
Std_ReturnType Crypto_aes_setkey_enc( Crypto_AESData *ctx,uint8* key,
                    uint16 keybits);
Std_ReturnType Crypto_aes_setkey_dec( Crypto_AESData *ctx,uint8* key,
                    uint16 keybits);
Std_ReturnType Crypto_aes_crypt_ecb( Crypto_AESData *ctx,
                    uint8 mode,
                    const uint8 input[16],
                    uint8 output[16]);
Std_ReturnType Crypto_aes_crypt_cbc( Crypto_AESData *ctx,
        uint8 mode,uint8 length,uint8 iv[16],
		uint8* input,
		uint8* output);
Std_ReturnType Crypto_AESEncryptECB(uint8* key,uint8 buf[64]);
Std_ReturnType Crypto_AESDecryptECB(uint8* key,uint8 buf[64]);
Std_ReturnType Crypto_AESEncryptCBC(uint8* key,uint8 buf[64],
        uint8 iv[16],uint8 inputlength);
Std_ReturnType Crypto_AESDecryptCBC(uint8* key,uint8 buf[16],
        uint8 iv[16],uint8 inputlength);
Std_ReturnType Crypto_AESEncryptCTR(uint8* key,uint8 buf[64],
        uint8 iv[16]);
Std_ReturnType Crypto_AESDecryptCTR(uint8* key,uint8 buf[64],
        uint8 iv[16]);

#endif /* aes.h */
