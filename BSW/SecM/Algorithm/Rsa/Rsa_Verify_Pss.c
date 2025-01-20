
/**  RSASSA-PSS/SHA-256 signature verification program
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https:  tls.mbed.org)
 **/



#include "std_types.h"
#include "Rsa2048.h"
#include "Sha_256.h"

uint32  PublicbufDc[64];

#define RSA_ERR_RSA_BAD_INPUT_DATA                    -0x4080  /**< Bad input parameters to function. */
#define RSA_ERR_RSA_INVALID_PADDING                   -0x4100  /**< Input data contains invalid padding and is rejected. */
#define RSA_ERR_RSA_VERIFY_FAILED                     -0x4380  /**< The PKCS#1 verification failed. */
#define RSA_ERR_PK_SIG_LEN_MISMATCH   				  -0x3900  /**< The buffer contains a valid signature followed by more data. */

#define RSA_SALT_LEN_ANY    							-1

#define ciL    (sizeof(uint32))         /* chars in limb  */
#define biL    (ciL << 3u)               /* bits  in limb  */
#define biH    (ciL << 2u)               /* half limb size */


static sint32 rsa_rsassa_pss_verify_V21(uint32 hashlen,
                               		const uint8 *hash,
                               		sint32 expected_salt_len,
                               		const uint8 *sig,
                               		uint32 sig_len);

static void rsa_mgf_mask(uint8 *dst, uint32 dlen, const uint8 *src,uint32 slen);
static void rsa_public_cal(const uint8 *input, uint8 *output);
static uint16 rsa_clz( const uint32 x );

void Rsa_verifyInit(void)
{
    tLongIntDataInit();
}

boolean Rsa_verify(const uint8 *hash, uint32 HashLength, const uint8 *SignBuf, uint32 SignBufLength)
{
    sint32 ret;
    boolean exit_code = FALSE;

    /* if size is small than 128 */
	if( SignBufLength < 256u )
	{
	   ret = RSA_ERR_RSA_VERIFY_FAILED;
	}
	else
	{
	   /* MBEDTLS_RSA_PKCS_V21 */
		ret = 	rsa_rsassa_pss_verify_V21(
									HashLength, hash,
									RSA_SALT_LEN_ANY,
									SignBuf,SignBufLength);
	}

	if(ret == 0)
	{
	   /* The buffer contains a valid signature followed by extra data.
		* We have a special error code for that so that so that callers can
		* use mbedtls_pk_verify() to check "Does the buffer start with a
		* valid signature?" and not just "Does the buffer contain a valid
		* signature?". */
		 if( SignBufLength > 256uL )
		 {
			 ret = RSA_ERR_PK_SIG_LEN_MISMATCH;
		 }
	}

    if(ret == 0)
    {
        exit_code = TRUE;
    }
    return( exit_code );
}

/******************************************************************************/
/**
 * @brief               <memory compare>
 *
 * <compare the dest and source is equal or not .> .
 * @param[in]           <source (IN),dest(IN) length (IN)>
 * @param[out]          <dest (OUT)>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
boolean rsa_Memcompare(const uint8 * dest, const uint8 *source, uint32 length)
{
	boolean retVal = (boolean)TRUE;
    const uint8 * destBuffer = dest;
    const uint8 *srcBuffer = source;
    uint32 inputLength = length;

    /* compare length should not be zero */
    if ((uint32)0U == length)
    {
        retVal = (boolean)FALSE;
    }
    else
    {
        while (inputLength > (uint32)0U)
        {
            if ((NULL_PTR != destBuffer) && (NULL_PTR != srcBuffer) && (*destBuffer == *srcBuffer))
            {
                destBuffer++;
                srcBuffer++;
            }
            else
            {
                retVal = (boolean)FALSE;
                break;
            }
            inputLength--;
        }
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <memory set>
 *
 * <MISRA C 2004 forbid to use memset() lib, only used  to set data buffer of
 *  indirect address.> .
 * @param[in]           <source (IN), length (IN)>
 * @param[out]          <dest (OUT)>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void rsa_Memset(uint8 * dest, const uint8 source, uint32 length)
{
    uint8 * destBuffer = dest;
    uint32 inputLength = length;
    while (inputLength > 0U)
    {
        if (destBuffer != NULL_PTR)
        {
            *destBuffer = source;
            destBuffer++;
        }
        else
        {
            break;
        }

        inputLength--;
    }
}


static sint32 rsa_rsassa_pss_verify_V21(uint32 hashlen,
        							const uint8 *hash,
        							sint32 expected_salt_len,
        							const uint8 *sig,
        							uint32 sig_len)
{
    sint32 ret = 0;
    uint8 *p;
    uint8 *hash_start = NULL_PTR;
    uint8 zeros[8];
    uint32 hlen;
    uint32 observed_salt_len, msb;
    uint8 i;
    uint16 j;
    uint8 buf[256];
    boolean processContinue = TRUE;

    Sha256Calc Sha256forRsa;

	/* Gather length of hash to sign */
    hlen = hashlen;
    p    = buf;

    msb  = 0;

    if( (sig_len < 16u) || (sig_len > sizeof(buf)) )
    {
    	ret = RSA_ERR_RSA_BAD_INPUT_DATA;
    	processContinue = FALSE;
    }
    else
    {
	    rsa_public_cal(sig, buf);

	    if( buf[sig_len - 1u] != 0xBCu )
	    {
	    	ret = RSA_ERR_RSA_INVALID_PADDING;
	    	processContinue = FALSE;
	    }
	}

    if(processContinue == TRUE)
    {
    	rsa_Memset(zeros, 0u, 8u);
        /*
         * Note: EMSA-PSS verification is over the length of N - 1 bits
         */
        /* msb = mbedtls_mpi_bitlen( &ctx->N ) - 1 */
        for( i = 0; i < 64u; i++)
        {
        	if(PublicbufDc[i] != 0u )
        	{
        		break;
        	}
        }
        /* (uint16)4 is the size of (uint32) */
        j = ((uint16)4u << 3u) - rsa_clz(PublicbufDc[i]);

        /* (uint16)4 is the size of (uint32) */
        msb =  ( (uint32)(63uL - i) * ((uint16)4u << 3u) ) + j - 1u;

        if( (buf[0u] >> (8u - (sig_len * 8u) + msb)) != 0u )
        {
        	ret = RSA_ERR_RSA_BAD_INPUT_DATA;
        	processContinue = FALSE;
        }
        else
        {
            /* Compensate for boundary condition when applying mask */
            if( (msb % 8u) == 0u )
            {
                p++;
                sig_len -= 1u;
            }

            if( sig_len < (hlen + 2u))
            {
            	ret = RSA_ERR_RSA_BAD_INPUT_DATA;
            	processContinue = FALSE;
            }
        }
    }

    if(processContinue == TRUE)
    {
        hash_start = p + sig_len - hlen - 1u;
        rsa_mgf_mask( p, sig_len - hlen - 1u, hash_start, hlen);
        buf[0] &= 0xFFu >> ((sig_len * 8u) - msb );

        while( (p < hash_start - 1u) && ((*p) == 0U) )
        {
        	p++;
        }

        if( *p++ != 0x01u )
        {
            ret = RSA_ERR_RSA_INVALID_PADDING;
        }
        else
        {
        	observed_salt_len = (uint32)(hash_start - p);

			if( (expected_salt_len != RSA_SALT_LEN_ANY)
			  &&(observed_salt_len != (uint32) expected_salt_len ))
			{
				ret = RSA_ERR_RSA_INVALID_PADDING;
			}
			else
			{
				/*
				 * Generate H = Hash( M' )
				 */
				(void)Sha256Calc_init(&Sha256forRsa);
				(void)Sha256Calc_calculate(&Sha256forRsa, zeros, 8u);
				(void)Sha256Calc_calculate(&Sha256forRsa, hash,  hashlen);
				(void)Sha256Calc_calculate(&Sha256forRsa, p,     observed_salt_len);

				if(rsa_Memcompare( hash_start,Sha256forRsa.Value, hlen ) != TRUE )
				{
					ret = RSA_ERR_RSA_VERIFY_FAILED;
				}
			}
        }
    }

    return ret;
}

/**
 * Generate and apply the MGF1 operation (from PKCS#1 v2.1) to a buffer.
 *
 * \param dst       buffer to mask
 * \param dlen      length of destination buffer
 * \param src       source of the mask generation
 * \param slen      length of the source buffer
 * \param md_ctx    message digest context to use
 */
static void rsa_mgf_mask(uint8 *dst, uint32 dlen, const uint8 *src,uint32 slen)
{
	uint8 counter[4];
	uint8 *p;
	uint16 hlen;
	uint32 i, use_len;
    Sha256Calc Sha256forMask;
   
    rsa_Memset(counter, 0u, 4u);

    hlen = 0x20u;

    /* Generate and apply dbMask */
    p = dst;

    while( dlen > 0u )
    {
        use_len = hlen;
        if( dlen < hlen )
        {
        	use_len = dlen;
        }

        (void)Sha256Calc_init(&Sha256forMask);
        (void)Sha256Calc_calculate(&Sha256forMask, src, slen);
        (void)Sha256Calc_calculate(&Sha256forMask, counter,  4u);

        for( i = 0; i < use_len; ++i )
        {
        	*p++ ^= Sha256forMask.Value[i];
        }

        counter[3]++;

        dlen -= use_len;
    }
}




static void rsa_public_cal(const uint8 *input, uint8 *output)
{
    uint8 i;
    uint16 j;
    /* fixme judge input and output null */

	for (i = 0; i < 64u; i++)
	{
		m[63u-i] = ((uint32)*(input+(i*4u)) << 24u)
				  +((uint32)*((input+(i*4u)) + 1u) << 16u)
				  +((uint32)*((input+(i*4u)) + 2u) << 8u)
				  +((uint32)*((input+(i*4u)) + 3u));
	}

	/* fixme */
	e[0] = 65537u;

	for (i = 0;i < 64u;i++)
	{
		n[i] = PublicbufDc[63u - i];
	}

    lint_pwrmd(M,E,N,&C);


	for (i = 0; i < 64u; i++)
	{
		j = (uint16)i*4u;
		*(output+255u-j-3u) = (uint8)(z[i] >> 24u);
		*(output+255u-j-2u) = (uint8)(z[i] >> 16u);
		*(output+255u-j-1u) = (uint8)(z[i] >> 8u);
		*(output+255u-j) = (uint8)(z[i]);
	}
}


/*
 * Count leading zero bits in a given integer
 */
static uint16 rsa_clz( const uint32 x )
{
	uint16 j;
	uint32 mask = (uint32) 1 << (biL - 1u);

    for( j = 0; j < biL; j++ )
    {
        if( (x & mask) != 0u )
        {
        	break;
        }

        mask >>= 1u;
    }

    return j;
}

/******************************************************************************/
/**
 * @brief               <memory copy Public Key>
 *
 * <MISRA C 2004 forbid to use memcpy() lib, only used  to copy data buffer of
 *  indirect address.> .
 * @param[in]           <source (IN), length (IN)>
 * @param[out]          <dest (OUT)>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Rsa_MemcpyPublicKey(const uint8 *source, uint32 length)
{
	uint32 DestData = 0;
	uint32 * dest = PublicbufDc;
    while (length > 0UL)
    {
        if ((dest != NULL_PTR) && (source != NULL_PTR))
        {
        	DestData = (((uint32)*source) << 24u)& 0xFF000000u;
            source++;
            DestData += (((uint32)*source) << 16u)& 0xFF0000u;
            source++;
            DestData += (((uint32)*source) << 8u) & 0xFF00u;
            source++;
            DestData += ((uint32)*source) ;
            *dest = DestData;
            source++;
            dest++;
        }
        else
        {
            break;
        }

        length = length - 4u;
    }

    return;
}
