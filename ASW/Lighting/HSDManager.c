

#include "HcmPlatform.h"
#include "GeneralFunction.h"

#include "HighSide_Interface.h"

typedef struct _HsdM_
{
    /* 是否可自由控制? */
    uint8_t     pr_bCtlHS0  :1;
    uint8_t     pr_bCtlHS1  :1;
    /* 自由控制开关 */
    uint8_t     st_bHS0_Fan     :1; /* control HS out */
    uint8_t     st_bHS1_        :1; /* control HS out */
}S_HsdM_t;

static S_HsdM_t hsdm, *_ctl = 0;


void HsdM_Init(void)
{
    uint16_t HSFuncFlag[2] = 0; /* 高边选配功能 */

    hsdm.pr_bCtlHS0 = 0;
    hsdm.pr_bCtlHS1 = 0;

    if (((HSFuncFlag[0] & 0x1000) == 0) &&
        ((HSFuncFlag[1] & 0x1000) == 0) )
    { hsdm.pr_bCtlHS1 = 1; }

    hsdm.st_bHS0_Fan = 0;
    hsdm.st_bHS1_ = 0;

    _ctl = &hsdm;
}

void HsdM_Exit(void)
{

    
    _ctl = 0;
}




