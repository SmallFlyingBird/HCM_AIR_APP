/*
 * DrvTps92682.h
 *
 *  Created on: 2024��2��20��
 *      Author: mihuiliang
 */

#ifndef CDD_DRIVER_BOOSTDRV_DRVTPS92682_H_
#define CDD_DRIVER_BOOSTDRV_DRVTPS92682_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define MAX_BOOST_DRV_NUM 1

#define BOOST_CHANNEL1_RUP         (float)75
#define BOOST_CHANNEL1_RDOWN       (float)3
#define BOOST_CHANNEL2_RUP         (float)75
#define BOOST_CHANNEL2_RDOWN       (float)3


#define REG_CFG1_VAL 0xA3


/********************************************Reg  Map***************************************************************/
#define REG_EN              ((uint8_t) 0x00)
#define REG_CFG1			((uint8_t) 0x01)
#define REG_CFG2			((uint8_t) 0x02)
#define REG_SWDIV			((uint8_t) 0x03)
#define REG_ISLOPE			((uint8_t) 0x04)
#define REG_FM				((uint8_t) 0x05)
#define REG_SOFTSTART		((uint8_t) 0x06)
#define REG_CH1IADJ			((uint8_t) 0x07)
#define REG_CH2IADJ			((uint8_t) 0x08)
#define REG_PWMDIV			((uint8_t) 0x09)
#define REG_CH1PWML			((uint8_t) 0x0A)
#define REG_CH1PWMH			((uint8_t) 0x0B)
#define REG_CH2PWML			((uint8_t) 0x0C)
#define REG_CH2PWMH			((uint8_t) 0x0D)
#define REG_ILIM			((uint8_t) 0x0E)
#define REG_IFT				((uint8_t) 0x0F)
#define REG_MFT				((uint8_t) 0x10)
#define REG_FLT1			((uint8_t) 0x11)
#define REG_FLT2			((uint8_t) 0x12)
#define REG_FEN1			((uint8_t) 0x13)
#define REG_FEN2			((uint8_t) 0x14)
#define REG_FLATEN			((uint8_t) 0x15)
#define REG_OV				((uint8_t) 0x16)
#define REG_LHCFG			((uint8_t) 0x17)
#define REG_LHCH1IADJ		((uint8_t) 0x18)
#define REG_LHCH2IADJ		((uint8_t) 0x19)
#define REG_LHCH1PWML		((uint8_t) 0x1A)
#define REG_LHCH1PWMH		((uint8_t) 0x1B)
#define REG_LHCH2PWML		((uint8_t) 0x1C)
#define REG_LHCH2PWMH		((uint8_t) 0x1D)
#define REG_LHILIM			((uint8_t) 0x1E)
#define REG_LHIFT			((uint8_t) 0x1F)
#define REG_LHMFT			((uint8_t) 0x20)
#define REG_LHFEN1			((uint8_t) 0x21)
#define REG_LHFEN2			((uint8_t) 0x22)
#define REG_LHFLATEN		((uint8_t) 0x23)
#define REG_LHOV			((uint8_t) 0x24)
#define REG_CAL				((uint8_t) 0x25)
#define REG_RESET			((uint8_t) 0x26)

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
Std_ReturnType CddDriver_DrvTps92682Init(void);
#endif /* CDD_DRIVER_BOOSTDRV_DRVTPS92682_H_ */
