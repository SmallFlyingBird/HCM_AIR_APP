#include "Rte_E2E_Callout.h"
#include "Com.h"
#include "DTC_Interface.h"
#include "Rte_E2EXf.h"

S_E2EStateForFailSafe gs_E2EStateForFailSafe;
static uint8 E2ESwitchStatus = 0;
uint8 RTE_COM_E2E_GetE2EStatus(void)
{
    return E2ESwitchStatus;
}

void RTE_COM_E2E_SetE2EStatus(uint8 status)
{
    E2ESwitchStatus = status;
}

void RTE_COM_E2E_ZcudZcud_Lin2Fr01_Handle(uint8* Lin_SduPtr)
{
    Rte_COMCbk_igActnOfLedLoBeam(Lin_SduPtr);
    Rte_COMCbk_igActvnOfIndcr(Lin_SduPtr);
}

void RTE_COM_E2E_ZcudZcud_Lin2Fr02_Handle(uint8* Lin_SduPtr)
{
    Rte_COMCbk_igLvlgSwtSetReq(Lin_SduPtr);
}

void Rte_COMCbk_igActnOfLedLoBeam(uint8* Lin_SduPtr)
{
    Std_ReturnType ret = E_NOT_OK;
	uint8 inputData[3] = {0};
	uint32 inputLength = 3;
	uint32 outputLength;
	uint8 outputData[3] = {0};
    Std_ReturnType Ret = E2E_E_OK;


    /* ActnOfLedLoBeamChks */
    inputData[0] = Lin_SduPtr[3];

    /* ActnOfLedLoBeamCntr */
    inputData[1] = Lin_SduPtr[4] & 0x0F;

    /* ActnOfLedLoBeamActnOfLedLoBeam */
    inputData[2] = (Lin_SduPtr[2] >> 7) & 0x01;

    ret = E2EXf_Inv_igActnOfLedLoBeam(outputData, &outputLength, inputData, inputLength);

    /* clear timeout */
    Com_Signal_TimeCounter_Reset(Com_Signal_ActnOfLedLoBeam);		
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamTimeout=0;

    
    if (E2E_P_OK == (ret & 0x0F))
	{
		/*E2E_P_OK*/

        Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CounterError, 0);
        Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 0);

        if(gs_E2EStateForFailSafe.ActnOfLedLoBeamCounterErrResumeCnt >0)
            gs_E2EStateForFailSafe.ActnOfLedLoBeamCounterErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCntErr=0;

        if(gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=0;
	}
    else
    {

    }
	if (E2E_P_REPEATED == (ret & 0x0F))
	{
		/*E2E_P_REPEATED*/
        gs_E2EStateForFailSafe.ActnOfLedLoBeamCounterErrResumeCnt =2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCntErr=1;

        Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CounterError, 1);

        /*clear CRC error*/
        if(gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=0;

        Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 0);

	}
	if (E2E_P_WRONGSEQUENCE == (ret & 0x0F))
	{
		/*E2E_P_WRONGSEQUENCE*/
	}
	if (E2E_P_ERROR == (ret & 0x0F))
	{
		/*E2E_P_CRCERROR*/
        gs_E2EStateForFailSafe.ActnOfLedLoBeamCrcErrResumeCnt=2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr=1;
        Interface_SetDtcE2EError(E_E2EErrorType_ActnOfLedLoBeam_CrcError, 1);
	}

}

void Rte_COMCbk_igActvnOfIndcr(uint8* Lin_SduPtr)
{
    Std_ReturnType ret = E_NOT_OK;
	uint8 inputData[3] = {0};
	uint32 inputLength = 3;
	uint32 outputLength;
	uint8 outputData[3] = {0};
    Std_ReturnType Ret = E2E_E_OK;


    /* ActvnOfIndcrChks */
    inputData[0] = Lin_SduPtr[6];

    /* ActvnOfIndcrCntr */
    inputData[1] = (Lin_SduPtr[5] & 0x3C) >> 2;

    /* ActvnOfIndcr */
    inputData[2] = (Lin_SduPtr[5] & 0xC0) >> 6;

    ret = E2EXf_Inv_igActvnOfIndcr(outputData, &outputLength, inputData, inputLength);

    /* clear timeout */
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrTimeout=0;
    Com_Signal_TimeCounter_Reset(Com_Signal_ActvnOfIndcr);

    if (E2E_P_OK == (ret & 0x0F))
	{
		/*E2E_P_OK*/

        Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CounterError, 0);
        Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CrcError, 0);

        if(gs_E2EStateForFailSafe.ActvnOfIndcrCounterErrResumeCnt >0)
            gs_E2EStateForFailSafe.ActvnOfIndcrCounterErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCntErr=0;

        if(gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCrcErr=0;
	}
	if (E2E_P_REPEATED == (ret & 0x0F))
	{
		/*E2E_P_REPEATED*/
        gs_E2EStateForFailSafe.ActvnOfIndcrCounterErrResumeCnt =2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCntErr=1;

        Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CounterError, 1);

        /*clear CRC error*/
        if(gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt>0)
            gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt--;
        else
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCrcErr=0;

        Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CrcError, 0);

	}
	if (E2E_P_WRONGSEQUENCE == (ret & 0x0F))
	{
		/*E2E_P_WRONGSEQUENCE*/
	}
	if (E2E_P_ERROR == (ret & 0x0F))
	{
		/*E2E_P_CRCERROR*/
        gs_E2EStateForFailSafe.ActvnOfIndcrCrcErrResumeCnt=2;
        gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCrcErr=1;
        Interface_SetDtcE2EError(E_E2EErrorType_ActvnOfIndcr_CrcError, 1);
	}
}

void Rte_COMCbk_igLvlgSwtSetReq(uint8* Lin_SduPtr)
{
	Std_ReturnType ret = 0;
	uint32 SignalValue;
    uint8_t DataSrc[2];
    uint8_t crc;
    uint8_t crc_tmp;
    
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqTimeout=0;
	if (ret == E_OK)
	{  
        DataSrc[0] = Lin_SduPtr[1] & 0x0F;
        DataSrc[1] = (Lin_SduPtr[1] & 0x70 ) >> 4;
        crc = Lin_SduPtr[0];

        crc_tmp = Crc_CalculateCRC8((uint8 *)DataSrc, 2, 0x00, TRUE);
        if(crc == crc_tmp)
        {
            Interface_SetDtcE2EError(E_E2EErrorType_LvlgSwtSetReq_ChksError, 0);
            if(gs_E2EStateForFailSafe.LvlgSwtSetReqCrcErrResumeCnt>0)
                gs_E2EStateForFailSafe.LvlgSwtSetReqCrcErrResumeCnt--;
            else
                gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqCrcErr=0;
        }           
        else
        {
            Interface_SetDtcE2EError(E_E2EErrorType_LvlgSwtSetReq_ChksError, 1);
            gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.bits.LvlgSwtSetReqCrcErr=1;
            gs_E2EStateForFailSafe.LvlgSwtSetReqCrcErrResumeCnt=2;
        }
	}
}

void Rbk_U_E2EErrorFlag(U_E2EErrorFlag* status)
{
    *status = gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe;
}

void RTE_E2E_ClearE2EErrorFlag(void)
{
    gs_E2EStateForFailSafe.E2EErrorFlagForFailSafe.E2EErrFlag = 0;
}


/* PRQA S 0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */
