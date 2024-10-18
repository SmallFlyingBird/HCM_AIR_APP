/*
 * MatrixChipManager.c
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */


#include "Tps92662A.h"
#include "Max25608_Interface.h"
#include "MatrixChipManager.h"



Std_ReturnType MatrixChipDevInit(void)
{
	Std_ReturnType rtval=E_OK;
	rtval|=Tps92662ADevRegister();
	return rtval;
}

