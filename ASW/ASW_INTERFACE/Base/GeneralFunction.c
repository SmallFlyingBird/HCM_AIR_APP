/*
 * GeneralFunction.c
 *
 *  Created on: 2024��1��23��
 *      Author: mihuiliang
 */


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "GeneralFunction.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/


/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint32_t CNT_INC(uint32_t cntbase,uint32_t cntstep,uint32_t cntlimit)
{
	if(cntbase+cntstep>cntlimit)
		return cntlimit;
	else
		return (cntbase+cntstep);
}

uint32_t CNT_DEC(uint32_t cntbase,uint32_t cntstep,uint32_t cntlimit)
{
	if(cntlimit+cntstep>cntbase)
		return cntlimit;
	else
		return (cntbase-cntstep);
}

sint16 CalArrayAverageValue_Sint16(sint16 *datasrc,uint8_t arrayNum)
{
	sint16 admax=0;
	sint16 admin=0xFFFF;
	sint32 sum=0;
	sint16 adval_tmp;
	uint8_t i=0;

	admin=datasrc[0];
	admax=datasrc[0];
	for(i=0;i<arrayNum;i++)
	{
		adval_tmp=datasrc[i];

		sum+=adval_tmp;
		admax=(adval_tmp>admax)?(adval_tmp):admax;
		admin=(adval_tmp<admin)?(adval_tmp):admin;
	}
	sum=(sum-admax-admin)/(arrayNum-2);
	return ((sint16)sum);
}

uint32_t CalArrayAverageValue_Uint32(uint32_t *datasrc,uint8_t arrayNum)
{
	uint32_t admax=0;
	uint32_t admin=0xFFFFFFFF;
	uint32_t sum=0;
	uint32_t adval_tmp;
	uint8_t i=0;

	for(i=0;i<arrayNum;i++)
	{
		adval_tmp=datasrc[i];

		sum+=adval_tmp;
		admax=(adval_tmp>admax)?(adval_tmp):admax;
		admin=(adval_tmp<admin)?(adval_tmp):admin;
	}
	sum=(sum-admax-admin)/(arrayNum-2);
	return ((uint16)sum);
}

/**
 * @brief bytes-array set
 */
int C_Memset_B(unsigned char *s, unsigned char v, unsigned int n)
{
    int i;
    if ((s==0)||(n==0)) { return -1; }
    for (i=0; i<n; i++) { s[i] = v; }
    return 0;
}

/**
 * @brief bytes-array copy
 */
int C_Memcpy_B(unsigned char *d, unsigned char *s, unsigned int n)
{
    int i;
    if ((d==0)||(s==0)||(n==0)) { return -1; }
    for (i=0; i<n; i++) { d[i] = s[i]; }
    return 0;
}

/**
 * @brief Adder for uint16_t, max 0xFFFF
 */
uint16_t C_AddToMax_U16(uint16_t v1, uint16_t v2)
{
	if ((0xFFFF - v1) > v2) { return (v1 + v2); }
	else                    { return 0xFFFF; }
}

/**
 * @brief Subtractor for uint8_t, min 0
 */
uint8_t C_SubToMin_U8(uint8_t v1, uint8_t v2)
{
	if (v1 > v2) { return (v1 - v2); }
	else         { return 0; }
}

/**
 * @brief Subtractor for uint16_t, min 0
 */
uint16_t C_SubToMin_U16(uint16_t v1, uint16_t v2)
{
	if (v1 > v2) { return (v1 - v2); }
	else         { return 0; }
}

/**
 * @brief VehSpd Value Unit Convert
 */
uint32_t C_VehSpd_00m1s_m1h(uint16_t v_00m1s)
{
	uint32_t u32v = (uint32_t)v_00m1s;
	u32v *= 36;
	return u32v;
}