


/*Base inlude*/
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "ComSignal_Interface.h"

// #include "DMoni.h"

#include "PaSi.h"


/**
 * @brief Get the si ActnLB object
 * 
 * @param sig_val 
 * @return Std_ReturnType 
 */

Std_ReturnType get_si_ActnLB(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][1] & 0x01);
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnHB(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedHiBeam(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][1] & 0x10) >> 4;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnDRL(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedDaytiRunngLamp(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = dmoni_rx[D_LIGHTING][2] & 0x01;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnPOS(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedPosnLamp(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][2] & 0x10) >> 4;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnTIsts(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_IndcrSts(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][3] & 0x03);
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnTIact(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActvnOfIndcrIndcrOut(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][3] & 0x0c) >> 2;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnTIseq(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_IndcrNoSeq(&v1);
    if (r1 == E_OK) { *sig_val = v1 ? 0 : 1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][3] & 0x10) >> 4;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnGIRL(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedGrilleLamp(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][4] & 0x01);
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnLOGO(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

#if (HCM_LEFT_SIDE)
    r1 = Interface_GetSignal_ActnOfLedLeLogoLamp(&v1);
#else
    r1 = Interface_GetSignal_ActnOfLedRiLogoLamp(&v1);
#endif
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][4] & 0x04) >> 2;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnASSI(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

#if (HCM_LEFT_SIDE)
    r1 = Interface_GetSignal_ActnOfLedLeLogoLamp(&v1);
#else   /* HCM_LEFT_SIDE */
    r1 = Interface_GetSignal_ActnOfLedRiLogoLamp(&v1);
#endif  /* HCM_LEFT_SIDE */
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][4] & 0x10) >> 4;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnCROS(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedFrntCrossLamp(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][4] & 0x40) >> 6;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnCOR(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

#if (HCM_LEFT_SIDE)
    r1 = Interface_GetSignal_ActnOfLedCornrgLampLe(&v1);
#else
    r1 = Interface_GetSignal_ActnOfLedCornrgLampRi(&v1);
#endif
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][5] & 0x01);
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnFOG(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedFrntFogLamp(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if ((DMONI_FUN(D_LIGHTING)) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][5] & 0x04) >> 2;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}






Std_ReturnType get_si_ActnWELC(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActvnOfWelcomeLi(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnAHBC(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActvnOfAhbc(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if (DMONI_FUN(D_LIGHTING) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][1] & 0x20) >> 5;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnTOUR(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActvnOfTouristMod(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if (DMONI_FUN(D_LIGHTING) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][1] & 0x04) ? 1 : 0;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnAFS(uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActvnOfAfs(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if (DMONI_FUN(D_LIGHTING) && (DMONI_SUB(D_LIGHTING) == 0))
    {
        r2 = E_OK;
        *sig_val = (dmoni_rx[D_LIGHTING][1] & 0x02) ? 1 : 0;
    }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}


/************************************************************** Dync Lighting */

Std_ReturnType get_si_ActnPOS_Dyn  (uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedPosnLampDyn(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnGIRL_Dyn (uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedGrilleLampDyn(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnLOGO_Dyn (uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

#if (HCM_LEFT_SIDE)
    r1 = Interface_GetSignal_ActnOfLedLeLogoLampDyn(&v1);
#else
    r1 = Interface_GetSignal_ActnOfLedRiLogoLampDyn(&v1);
#endif
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

Std_ReturnType get_si_ActnCROS_Dyn (uint32_t * sig_val)
{
    Std_ReturnType r1 = E_NOT_OK;
    Std_ReturnType r2 = E_NOT_OK;
    uint32_t v1;

    r1 = Interface_GetSignal_ActnOfLedFrntCrossLampDyn(&v1);
    if (r1 == E_OK) { *sig_val = v1; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

    if ((r1 == E_OK) || (r2 == E_OK)) { return E_OK;     }
    else                              { return E_NOT_OK; }
}

