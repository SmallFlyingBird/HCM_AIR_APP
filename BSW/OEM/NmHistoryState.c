#include "ComStack_Types.h"
#include "NmHistoryState.h"
#include "Com.h"

/*extern uint8 NvMBlockRamBuffer5[64];*/

#ifdef GEELY20_SPECIFICATION_USED

#if defined(NM_CUSTOM_SUPPORT_NVM)
/* nvm store data shall align 16 */
#define NM_HIS_NVM_BUF_LEN      ((NHS_BUFFER_SIZE * 5 + 15 + 2) / 16 * 16)
#include "NvM.h"
/* #define NVM_NMHISTORY_BLOCKID   5 */
#define NVM_NMHISTORY_BLOCKID   NvM_Block_NmHistory
static uint8 Nhs_NvmBuffer[NM_HIS_NVM_BUF_LEN];
#define Nvm_BlockRamAdr (\
    NvM_BlockDescriptor[NVM_NMHISTORY_BLOCKID - 1u].NvmRamBlockDataAddress)
#endif/* defined(NM_CUSTOM_SUPPORT_NVM) */

/* response did data support dynamic length */
#if 0
#define NM_CUSTOM_DID_SUPORT_DYN
#endif
/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/




#if defined(NM_CUSTOM_TIMERSTAMP)

#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)
static uint32 nHs_gTimer = 0ul;
#endif

#if(STD_ON == CAR_GLOBAL_TIMESTAMP_SUPPORT)
uint32 CarGlobalTimeStamp = 0ul;
#endif

#define TIMER_ASSEMBER(buf)     (\
                        ((uint32)(buf)[0]) << 24u|\
                        ((uint32)(buf)[1]) << 16u|\
                        ((uint32)(buf)[2]) << 8u|\
                        ((uint32)(buf)[3]))

#define  TIMER_REASSEMBER(buf,timervlu)     \
                    do\
                      {\
                          (buf)[0] = (uint8)(timervlu >> 24u);\
                          (buf)[1] = (uint8)(timervlu >> 16u);\
                          (buf)[2] = (uint8)(timervlu >> 8u);\
                          (buf)[3] = (uint8)(timervlu);\
                      }while(0);


#endif/* defind(NM_CUSTOM_TIMERSTAMP) */

typedef struct
{
#if defined(NM_CUSTOM_TIMERSTAMP)
    uint32 tmStampU32;
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
    uint8 nmState;

} Nhs_BufferType;


static uint8 writePoint;
#if defined(NM_CUSTOM_DID_SUPORT_DYN)
static uint32 localBufStoreCnt = 0u;
#endif/* defined(NM_CUSTOM_DID_SUPORT_DYN) */
static boolean localBusOffState = FALSE;
static uint8 previousState;

#if defined(NM_CUSTOM_TIMERSTAMP)

typedef struct
{
    /* data */
    Std_ReturnType (*readTimerStampFuncPtr)(uint8*);
    Std_ReturnType (*writeTimerStampFuncPtr)(uint8*);

} Nhs_ConfigType;

static const Nhs_ConfigType Nhs_Config =
{
    /* readTimerStampFuncPtr */
    NULL_PTR,
    /* writeTimerStampFuncPtr */
    NULL_PTR,
};
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */

static Nhs_BufferType Nhs_Buffer[NHS_BUFFER_SIZE];


void NmHistoryState_PreInit(void)
{
#if defined(NM_CUSTOM_TIMERSTAMP)
    /* step 1:
    read global timer stamp form trcv TJA1169 */
#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)
    uint8 localTmSt[4];

    if(NULL_PTR != Nhs_Config.readTimerStampFuncPtr)
    {
        Std_ReturnType ret =
            Nhs_Config.readTimerStampFuncPtr(localTmSt);

        if(E_OK == ret)
        {
            nHs_gTimer = TIMER_ASSEMBER(localTmSt);
        }
    }
#endif

#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
    uint32 index = 0u;

    for(index = 0u; index < NHS_BUFFER_SIZE; index++)
    {
        Nhs_Buffer[index].nmState = NHS_STATE_OFF;
    }

    previousState = NHS_STATE_OFF;
    writePoint = 0u;
#if defined(NM_CUSTOM_DID_SUPORT_DYN)
    localBufStoreCnt = 0u;
#endif/* defined(NM_CUSTOM_DID_SUPORT_DYN) */
    localBusOffState = FALSE;
}
#if defined(NM_CUSTOM_TIMERSTAMP)
#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)

uint32 GetNmHistoryTimeStamps(void)
{
    return nHs_gTimer;
}

void NmHistory_UpdateTimeStamps(uint32 TimeStamp)
{
    /*TimeStamp  0-4294967295  -> 0-429496729.5s */
    /*(TimeStamp * 0.1 *1000)ms = (nHs_gTimer *100)ms*/
    nHs_gTimer = TimeStamp;

}
void NmHistoryState_MainFunction(void)
{
    /* cycle 100ms */
    nHs_gTimer++;
}
#endif
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
#if defined(NM_CUSTOM_SUPPORT_NVM)
void NmHistoryState_NvmReadyInit(void)
{
    uint32 index = 0;
    NvM_RequestResultType nvmStu;
    Std_ReturnType ret =
        NvM_GetErrorStatus(NVM_NMHISTORY_BLOCKID, &nvmStu);
    if((E_OK == ret) && (NVM_REQ_OK == nvmStu))
    {
        for(index = 0; index < sizeof(Nhs_NvmBuffer); index++)
        {
            Nhs_NvmBuffer[index] = Nvm_BlockRamAdr[index];
			/*Nhs_NvmBuffer[index] = NvMBlockRamBuffer5[index];*/
        }

        /* shall merge local queue buffer and nvm buffer */
        uint8 nvmWp = Nhs_NvmBuffer[NHS_BUFFER_SIZE * 5 + 1];
        uint8 localWp = writePoint;
        boolean continueFlg = TRUE;

        /* step0:merge local queue buffer to nvm buffer */
        for(index = 0;
                (index < NHS_BUFFER_SIZE) && (FALSE != continueFlg);
                index++)
        {
            if(0u < localWp)
            {
                localWp--;
            }
            else
            {
                localWp = NHS_BUFFER_SIZE - 1;
            }

            if(NHS_STATE_OFF != Nhs_Buffer[localWp].nmState)
            {
                Nhs_NvmBuffer[nvmWp * 5] = Nhs_Buffer[localWp].nmState;
#if defined(NM_CUSTOM_TIMERSTAMP)
                TIMER_REASSEMBER(&Nhs_NvmBuffer[nvmWp * 5 + 1],
                                 Nhs_Buffer[localWp].tmStampU32);
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
                nvmWp++;

                if(nvmWp >= NHS_BUFFER_SIZE)
                {
                    nvmWp = 0u;
                }
            }
            else
            {
                continueFlg = FALSE;
            }
        }

        /* step 1: copy nvm buffer to lcoal queue buffer */
        for(index = 0; index < NHS_BUFFER_SIZE; index++)
        {
            if((0u < Nhs_NvmBuffer[index * 5])
                    && (10u > Nhs_NvmBuffer[index * 5]))
            {
                Nhs_Buffer[index].nmState = Nhs_NvmBuffer[index * 5];
#if defined(NM_CUSTOM_TIMERSTAMP)
                Nhs_Buffer[index].tmStampU32 =
                    TIMER_ASSEMBER(&Nhs_NvmBuffer[index * 5 + 1]);
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
            }
        }

        /* step 2: recalculate local write point */
        writePoint = nvmWp;
        Nhs_NvmBuffer[NHS_BUFFER_SIZE * 5 + 1] = writePoint;
    }
}
#endif/* defined(NM_CUSTOM_SUPPORT_NVM) */

void NmNmHistoryState_NodifyBusOff(boolean busOffState)
{
    localBusOffState = busOffState;
}
void NmHistoryState_NodifyState(uint8 state)
{

	if(state != previousState)
    {
        previousState = state;
        Nhs_Buffer[writePoint].nmState = state;
#if defined(NM_CUSTOM_TIMERSTAMP)
#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)
        Nhs_Buffer[writePoint].tmStampU32 = nHs_gTimer;
#endif
#if(STD_ON == CAR_GLOBAL_TIMESTAMP_SUPPORT)
        /*this signal is from global time stamp, should use this way to save*/
        /*Com_ReceiveSignal(CarTiGlb_IPDU_COM_CEMBodySignalIPdu30,&CarGlobalTimeStamp);*/
        Nhs_Buffer[writePoint].tmStampU32 = CarGlobalTimeStamp;
#endif
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
#if defined(NM_CUSTOM_SUPPORT_NVM)
        Nhs_NvmBuffer[writePoint * 5 ] = state;
#if defined(NM_CUSTOM_TIMERSTAMP)
#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)
        TIMER_REASSEMBER(&Nhs_NvmBuffer[writePoint * 5 + 1], nHs_gTimer);
#endif
#if(STD_ON == CAR_GLOBAL_TIMESTAMP_SUPPORT)
        TIMER_REASSEMBER(&Nhs_NvmBuffer[writePoint * 5 + 1], CarGlobalTimeStamp);
#endif
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
#endif/* defined(NM_CUSTOM_SUPPORT_NVM) */
        writePoint++;

        if(writePoint >= NHS_BUFFER_SIZE)
        {
            writePoint = 0u;
        }

#if defined(NM_CUSTOM_SUPPORT_NVM)
        Nhs_NvmBuffer[NHS_BUFFER_SIZE * 5] = previousState;
        Nhs_NvmBuffer[NHS_BUFFER_SIZE * 5 + 1] = writePoint;
#endif/* defined(NM_CUSTOM_SUPPORT_NVM) */
#if defined(NM_CUSTOM_DID_SUPORT_DYN)
        localBufStoreCnt++;

        if(localBufStoreCnt > NHS_BUFFER_SIZE)
        {
            localBufStoreCnt = NHS_BUFFER_SIZE;
        }

#endif/* defined(NM_CUSTOM_DID_SUPORT_DYN) */
    }
}
Std_ReturnType NmHistoryState_BaseDidReadLen(uint16* lenPtr)
{
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR != lenPtr)
    {
#if defined(NM_CUSTOM_DID_SUPORT_DYN)
#if defined(NM_CUSTOM_TIMERSTAMP)
        *lenPtr = (uint16)(5u * localBufStoreCnt);
#else
        *lenPtr = (uint16)(1u * localBufStoreCnt);
#endif/* defined(NM_CUSTOM_TIMERSTAMP) */
#else
#if defined(NM_CUSTOM_TIMERSTAMP)
        *lenPtr = (uint16)(5u * NHS_BUFFER_SIZE);
#else
        *lenPtr = (uint16)(1u * NHS_BUFFER_SIZE);
#endif/* defined(NM_CUSTOM_TIMERSTAMP) */
#endif/* defined(NM_CUSTOM_DID_SUPORT_DYN) */
        ret = E_OK;
    }

    return ret;
}
Std_ReturnType NmHistoryState_BaseDidReadBuf(uint8* bufPtr)
{
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR != bufPtr)
    {
        ret = E_OK;
#if defined(NM_CUSTOM_DID_SUPORT_DYN)
        uint32 totCnt = localBufStoreCnt;
#else
        uint32 totCnt = NHS_BUFFER_SIZE;
#endif/* defined(NM_CUSTOM_DID_SUPORT_DYN) */
        uint32 index = writePoint, u8index = 0u;

        if(totCnt > 0u)
        {
            while(totCnt--)
            {
                if(0u == index)
                {
                    index = NHS_BUFFER_SIZE - 1u;
                }
                else
                {
                    index--;
                }

                bufPtr[u8index++] = Nhs_Buffer[index].nmState;
#if defined(NM_CUSTOM_TIMERSTAMP)
                bufPtr[u8index++] =
                    (uint8)(Nhs_Buffer[index].tmStampU32 >> 24u);
                bufPtr[u8index++] =
                    (uint8)(Nhs_Buffer[index].tmStampU32 >> 16u);
                bufPtr[u8index++] =
                    (uint8)(Nhs_Buffer[index].tmStampU32 >> 8u);
                bufPtr[u8index++] =
                    (uint8)(Nhs_Buffer[index].tmStampU32);
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
            }
        }
    }

    return ret;
}
void NmHistoryState_DeInit(void)
{
	uint16 index;
#if defined(NM_CUSTOM_TIMERSTAMP)
#if(STD_ON == LOCAL_NODE_REALTIMESTAMP_SUPPORT)
    uint8 localTmSt[4];
    TIMER_REASSEMBER(localTmSt, nHs_gTimer);

    if(NULL_PTR != Nhs_Config.writeTimerStampFuncPtr)
    {
        (void)Nhs_Config.writeTimerStampFuncPtr(localTmSt);
    }
#endif
#endif/* defind(NM_CUSTOM_TIMERSTAMP) */
    for(index = 0; index < sizeof(Nhs_NvmBuffer); index++)
    {
    	Nvm_BlockRamAdr[index]= Nhs_NvmBuffer[index];
		/*NvMBlockRamBuffer5[index] = Nhs_NvmBuffer[index];*/
    }
#if defined(NM_CUSTOM_SUPPORT_NVM)
    /*(void)NvM_WriteBlock(NVM_NMHISTORY_BLOCKID, Nvm_BlockRamAdr);*/
    /*(void)NvM_WriteBlock(NVM_NMHISTORY_BLOCKID, Nhs_NvmBuffer);*/
#endif/* defined(NM_CUSTOM_SUPPORT_NVM) */
}
#endif/* defined(SAS_009_19_JL_NM_CUSTOM) */
