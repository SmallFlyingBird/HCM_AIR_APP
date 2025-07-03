/*
 * GeneralFunction.h
 *
 *  
 *      Author: mihuiliang
 */

#ifndef BASE_GENERALFUNCTION_H_
#define BASE_GENERALFUNCTION_H_
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AdcDev_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define STEP_1	1
#define STEP_10	10
#define STEP_20	20
#define CNT_LIMIT_5  5
#define CNT_LIMIT_10 10
#define CNT_LIMIT_20 20
#define DEC_LIMIT_0 0
#define ADCWIDTH   4095
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
uint32_t CNT_INC(uint32_t cntbase,uint32_t cntstep,uint32_t cntlimit);
uint32_t CNT_DEC(uint32_t cntbase,uint32_t cntstep,uint32_t cntlimit);
sint16 CalArrayAverageValue_Sint16(sint16 *datasrc,uint8_t arrayNum);
uint32_t CalArrayAverageValue_Uint32(uint32_t *datasrc,uint8_t arrayNum);


/**
 * @brief bytes-array set
 * 
 * @param s point to bytes head
 * @param v value of every byte
 * @param n number of bytes
 * @return 0: ok; not 0: error
 */
extern
int C_Memset_B(unsigned char *s, unsigned char v, unsigned int n);

/**
 * @brief bytes-array copy
 * 
 * @param d point to destine bytes head
 * @param s point to source bytes head
 * @param n number of copy bytes
 * @return 0: ok; not 0: error
 */
extern
int C_Memcpy_B(unsigned char *d, unsigned char *s, unsigned int n);

/**
 * @brief Adder for uint16_t, max 0xFFFF
 * 
 * @param v1 addend1
 * @param v2 addend2
 * @return (addend1 + addend2) or 0xFFFF
 */
extern 
uint16_t C_AddToMax_U16(uint16_t v1, uint16_t v2);

/**
 * @brief Subtractor for uint8_t, min 0
 * 
 * @param v1 minend
 * @param v2 subtrahend
 * @return (minend - subtrahend) or 0
 */
extern 
uint8_t C_SubToMin_U8(uint8_t v1, uint8_t v2);

/**
 * @brief Subtractor for uint16_t, min 0
 * 
 * @param v1 minend
 * @param v2 subtrahend
 * @return (minend - subtrahend) or 0
 */
extern 
uint16_t C_SubToMin_U16(uint16_t v1, uint16_t v2);

/**
 * @brief VehSpd Value Unit Convert
 * 
 * @param v_00m1s  Vehicle Speed Value (0.01 m/s)
 * @return         Vehicle Speed Value (   1 m/h)
 */
extern
uint32_t C_VehSpd_00m1s_m1h(uint16_t v_00m1s);

#endif /* BASE_GENERALFUNCTION_H_ */
