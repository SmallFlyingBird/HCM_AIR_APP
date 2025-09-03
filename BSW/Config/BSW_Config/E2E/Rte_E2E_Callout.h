#ifndef E2E_CBK_H_
#define E2E_CBK_H_
#include "TransformerTypes.h"

#define APP_E2E_FUN_ON (0x01u)


typedef union{
    struct{
        uint32 ActnOfLedLoBeamTimeout :1;
        uint32 ActnOfLedLoBeamCntErr  :1;
        uint32 ActnOfLedLoBeamCrcErr  :1;
        uint32 ActvnOfIndcrTimeout    :1;
        uint32 ActvnOfIndcrCntErr     :1;
        uint32 ActvnOfIndcrCrcErr     :1;
        uint32 LvlgSwtSetReqTimeout    :1;
        uint32 LvlgSwtSetReqCntErr     :1;
        uint32 LvlgSwtSetReqCrcErr     :1;
    }bits;
    uint32 E2EErrFlag;
}U_E2EErrorFlag;

typedef struct{
    U_E2EErrorFlag E2EErrorFlagForFailSafe;
    uint8 ActnOfLedLoBeamCrcErrResumeCnt;
    uint8 ActnOfLedLoBeamCounterErrResumeCnt;
    uint8 ActvnOfIndcrCrcErrResumeCnt;
    uint8 ActvnOfIndcrCounterErrResumeCnt;
    uint8 LvlgSwtSetReqCrcErrResumeCnt;
    uint8 LvlgSwtSetReqCounterErrResumeCnt;
}S_E2EStateForFailSafe;

extern S_E2EStateForFailSafe gs_E2EStateForFailSafe;
uint8 RTE_COM_E2E_GetE2EStatus(void);

extern void RTE_COM_E2E_SetE2EStatus(uint8 status);
void RTE_COM_E2E_ZcudZcud_Lin2Fr01_Handle(uint8 *Lin_SduPtr);
void RTE_COM_E2E_ZcudZcud_Lin2Fr02_Handle(uint8 *Lin_SduPtr);
void Rte_COMCbk_igActnOfLedLoBeam(uint8 *Lin_SduPtr);
void Rte_COMCbk_igActvnOfIndcr(uint8* Lin_SduPtr);
void Rte_COMCbk_igLvlgSwtSetReq(uint8 *Lin_SduPtr);
void Rbk_U_E2EErrorFlag(U_E2EErrorFlag* status);

#endif