
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : PduR_Callout.c                                                  **
**                                                                            **
**  Created on  : 2023/09/15 16:21:42                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20230818   long.zhu          Initial Version
 */

/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "PduR_Callout.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define DID437C_DATA_BASE_ADDRESS 0x0101A1A4U
#define DID437C_LR_OFFSET 12U
#define PDUR_
#define PDUR_
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
uint8 PduR_GetLightSide(void)
{
    uint8 Did437c_Side_Of_Vehicle = *(volatile uint8*)(DID437C_DATA_BASE_ADDRESS+DID437C_LR_OFFSET);

    return Did437c_Side_Of_Vehicle;
}



/*******************************************************************************
*Function:PduR_SetLightSide
* Description: Set Lin buffer LinIf_FrameData[0] FrameId
* Input : side 0x01 -- left
               0x02 -- right
*******************************************************************************/
void PduR_SetLightSide(uint8 side)
{
    uint8 *ptr = LinIf_FrameData[0].LinIfFrameId;
    
    if(PduR_Side_Right == side)
    {/* Right side */
        *ptr = 0x42;
    }
    else
    {
        /*do nothing*/
    }
}