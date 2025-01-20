/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <cmac.c>
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

/*=======[I N C L U D E S]====================================================*/
#include "cmac.h"
#include "aes128.h"
#include "DP.h"
/**=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]=======*/
extern Std_ReturnType Crypto_memset(void *buf, uint32 len);

/**=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]=======*/
static void internal_GenerateMAC(
        uint32 length,
		uint8* input,
		uint8* macvalue,
		uint8* Key,
		uint8* k1,
		uint8* k2);

static Std_ReturnType LoadMacKey(
        uint8* key,
		uint8* k1,
		uint8* k2);

static void leftshift(long len,uint8* add,uint8*des);

static void ArrayXor(long len,uint8*a1,uint8*a2,uint8*des);

/**=======[F U N C T I O N   I M P L E M E N T A T I O N S]===================*/

/*=======[Move Array Left]====================================================*/
static void leftshift(long len,uint8* add,uint8* des)
{
    long i;
    for (i = 0; i < len - 1; i++)
    {
        des[i] = (add[i] << 1)+ (add[i + 1] >= 0x80?1:0);
    }
    des[len - 1] = add[len - 1] << 1;
}

/*=======[Array XOR Operation]================================================*/
static void ArrayXor(long len,uint8*a1,uint8*a2,uint8*des)
{
    long i;
    for (i = 0; i < len; i++)
    {
        des[i] = a1[i] ^ a2[i];
    }
}

/*=======[Load MAC Key]=======================================================*/
static Std_ReturnType LoadMacKey(
        uint8* key,
        uint8* k1,
        uint8* k2)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 c0[16];
    uint8 plain[16];
    uint8 Rb[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87};


    uint8 IVkey[16u];

    Crypto_AESData aes;

	DP_Memset(plain, 0u, 16u);

	DP_Memset(IVkey, 0u, 16u);
	DP_Memset((uint8 *)&aes, 0u, sizeof(Crypto_AESData));

    ret = Crypto_aes_setkey_enc(&aes,key,128);
    ret = Crypto_aes_crypt_cbc(&aes,AES_ENCRYPT,16,IVkey,plain,c0);


    if (c0[0] < 0x80)   /* generate k1 */
    {
        leftshift(16,c0,k1);
    }
    else
    {
        leftshift(16,c0,k1);
        ArrayXor(16,k1,Rb,k1);
    }

    if (k1[0] < 0x80)  /* generate k2 */
    {
        leftshift(16,k1,k2);
    }
    else
    {
        leftshift(16,k1,k2);
        ArrayXor(16,k2,Rb,k2);
    }
    return ret;
}

static void MAC_padding(uint8 *lastb, uint8 *pad, uint32 length)
{
    uint8 j;

    /* original last block */
    for ( j = 0u; j < 16u; j++)
    {
        if (j < length)
        {
            pad[j] = lastb[j];
        }
        else if (j == length)
        {
            pad[j] = 0x80u;
        }
        else
        {
            pad[j] = 0x00u;
        }
    }
}
/*=======[Generate MAC Key]====================================================*/
static void internal_GenerateMAC(
		uint32 length,
		uint8* input,
		uint8* macvalue,
		uint8* Key,
		uint8* k1,
		uint8* k2
)
{
	uint8 i;

    uint32 n,flag;
    uint8 X[16u], Y[16u], M_last[16u], padded[16u];

	uint8 IVkey[16u];
    Crypto_AESData aes;

    DP_Memset(padded, 0u, 16);

	n = (length + 15u) / 16u;
	/* n is number of rounds */
	if (n == 0)
	{
		n = 1u;
		flag = 0u;
	}
	else
	{
		if ((length % 16u) == 0u)
		{
			/* last block is a complete block */
			flag = 1u;
		}
		else
		{
			/* last block is not complete block */
			flag = 0u;
		}
	}

	if (flag)
	{
		/* last block is complete block */
		ArrayXor(16, &input[16u * (n - 1u)], k1, M_last);
	}
	else
	{
		MAC_padding(&input[16u * (n - 1u)], padded, length % 16u);
		ArrayXor(16, padded, k2, M_last);
	}

	for (i = 0u; i < 16u; i++)
	{
		X[i] = 0u;
	}

	for (i = 0u; i < (n - 1u); i++)
	{
		ArrayXor(16, X, &input[16u * i], Y);
		/* Y := Mi (+) X */

		/* AES Crypto */
		DP_Memset(IVkey, 0u, 16u);
		DP_Memset((uint8 *)&aes, 0u, sizeof(Crypto_AESData));
		Crypto_aes_setkey_enc(&aes,Key,128);/* load mac key */
		Crypto_aes_crypt_cbc(&aes,AES_ENCRYPT,16,IVkey,Y,X);
	}

	ArrayXor(16, X, M_last, Y);
	/* AES Crypto */
	DP_Memset(IVkey, 0u, 16u);
	DP_Memset((uint8 *)&aes, 0u, sizeof(Crypto_AESData));
	Crypto_aes_setkey_enc(&aes,Key,128); /* load mac key */
	Crypto_aes_crypt_cbc(&aes,AES_ENCRYPT,16,IVkey,Y,X);

	for (i = 0u; i < 16u; i++)
	{
		macvalue[i] = X[i];
	}

}

/*=======[Load And Generate MAC Key]===========================================*/
/********************************************************************************/
/****
 * brief			:Crypto_GernerateMAC
 *
 * Sync/Async		: <Synchronous>
 * Reentrancy		: <Non reentrant>
 * param[in]		: <MAC : Pointer to message authentication code>
 *                    <Key : Pointer to encryption key>
 *                    <IVKey : Pointer to the initial vector>
 *                    <add : Pointer for plain text input>
 *                    <inputlength : Enter plain text length>
 * param[out]	    : <NONE>
 * param[in/out]	: <NONE>
 * return		    : <NONE>
 */
/********************************************************************************/
 Std_ReturnType Crypto_GernerateMAC(
		uint8* Key,
        uint8* inputData,
        uint32 inputlength,
		uint8* OutPutData)
{
    Std_ReturnType ret = E_OK;
    uint8 k1[16] = {0X00};
    uint8 k2[16] = {0X00};

    /* Load MAC Key */
    LoadMacKey(Key,k1,k2);
    /* Generate MAC Key */
    internal_GenerateMAC(inputlength,inputData,OutPutData,Key,k1,k2);

    return ret;
}

/* =======================[END OF FILE]===========================================*/

