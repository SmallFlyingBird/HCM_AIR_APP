/*============================================================================*/
/*  Copyright (C) 2009-2019, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       < Rsa2048.h >
 *  brief      < Compute SHA256 hash value  head file >
 *
 *  < Compiler: Tasking     MCU:TC23X >
 *
 *  author     < houcheng.ge >
 *  date       < 2019-05-07 >
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>       <REVISION LOG>
 *  V1.0.0       20190507  long.zhu    Initial version
 *  V1.0.1       20220409  long.zhu    add external variable
 */
/*============================================================================*/

#ifndef _RSA2048_H
#define _RSA2048_H

#include "Platform_Types.h"
#include "Rsa_Cfg.h"
/*need to open long long int support for compiler option*/

#define GET_BITLEN(bytelen) ((bytelen) * 8u)
#define GET_BYTLEN(bitlen)  ((bitlen) / 8u)

/*3072bit key need about 400byte space,which is 100 in dword size*/
#define KEY_BITSIZE  2048u
#define KEY_BYTSIZE GET_BYTLEN(KEY_BITSIZE)

#define MAXINT_TYPE    		uint64
#define BASEINT_TYPE   		uint32
#define SIZE_TYPE         	uint16
#define BSINTBYT_LEN  		sizeof(BASEINT_TYPE)
#define SIZEBYT_LEN  		sizeof(SIZE_TYPE)
/*max base int data*/
#define BSINT_MAX       	0xFFFFFFu
#define R_UINT             (0x01uLL << GET_BITLEN(BSINTBYT_LEN))


#define ND_BSINTSIZE (KEY_BYTSIZE / BSINTBYT_LEN)  /*n and e(private key) use this base
int size*/
#define PQ_BSINTSIZE (ND_BSINTSIZE / 2u) /*prime p&q use this size*/

#define E_BSINTSIZE (PQ_BSINTSIZE / 2u) /*public key(e) size*/

#define MAX_SIZE  (ND_BSINTSIZE + 1u)

#define MAX_MULSIZE (MAX_SIZE * 2u)


#define GetLoWord(maxintdata)  (BASEINT_TYPE)(maxintdata)       
#define GetHiWord(maxintdata)  (BASEINT_TYPE)((maxintdata) >> GET_BITLEN(BSINTBYT_LEN))

#define GetBaseintSize(x)       (SIZE_TYPE)(sizeof(x)/sizeof((x)[0]))
#define ConfgData(x,realsize)         GetBaseintSize(x),realsize,&(x)[0]

#define DefLintBuff(buffname,size)  BASEINT_TYPE buffname[size]
#define DecLintBuff(buffname,size) extern DefLintBuff(buffname,size)

#define InitIntStruct(sname,buffname)   (sname).baseintmaxsize = GetBaseintSize(buffname);\
                                                            (sname).pbignum = &(buffname)[0]

typedef struct
{
    SIZE_TYPE baseintmaxsize;
    SIZE_TYPE  baseintrealsize;
    
    BASEINT_TYPE  *pbignum;
}tLongIntData;
extern uint32  PublicbufDc[64];
extern void lint_pwrmd(tLongIntData y,tLongIntData a,tLongIntData b,tLongIntData *pc);

extern tLongIntData M;

extern tLongIntData N;

extern tLongIntData E ;

extern tLongIntData C ;

extern DefLintBuff(m,64);

extern DefLintBuff(z,64);

extern DefLintBuff(n,64);/*n = p * q*/

extern DefLintBuff(e,1);/*public key*/

extern void Rsa_verifyInit(void);

extern boolean Rsa_verify(const uint8 *hash,uint32 HashLength, const uint8 *SignBuf,uint32 SignBufLength);

extern void tLongIntDataInit(void);

extern void Rsa_MemcpyPublicKey(const uint8 *source, uint32 length);

#endif


