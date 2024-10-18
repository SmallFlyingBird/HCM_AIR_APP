#include "SafetyDrv.h"
#include "HTMSS.h"

typedef struct
{
    uint8_t ret;
    boolean htmssRet;
    HTMSS_TestResultType SelfTestRet[10U];
} Sfety_Htmss;

Sfety_Htmss g_htmssInfo = {0, false, {0}};

static void Safety_HtmssInit(void)
{
    HTMSS_Init(HTMSS_PreDefinedConfigPtr);
}

/*Checks whether all self tests execution results are success.*/
static boolean Ex_SafetyLib_CheckSelfTestResult(HTMSS_TestResultType *SelfTestRet, uint8 ModuleCnt)
{
    boolean Ret = TRUE;
    uint8 Index;

    for (Index = 0U; Index < ModuleCnt; ++Index)
    {
        if (SelfTestRet[Index].TestResult != 0U)
        {
            Ret = FALSE;
            break;
        }
    }

    return Ret;
}

static void Safety_HtmssSelftest(void)
{
    g_htmssInfo.htmssRet = FALSE;

    /* As WDOG configured in Startup test group, MCU will perform reset during executing self test
     */
    if (MSTP_SELFTEST_STATE_IDLE == Mstp_GetSelfTestFlag())
    {
        if (HTMSS_StartTest(HTMSS_STARTUP) != E_OK)
        {
            Safety_SetTestRes(SAFETY_HTMSS, SAFETY_ERROR);
            return;
        }
    }

    if (HTMSS_STATUS_OK == HTMSS_GetTestStatus(HTMSS_STARTUP, g_htmssInfo.SelfTestRet))
    {
        if (TRUE == Ex_SafetyLib_CheckSelfTestResult(g_htmssInfo.SelfTestRet, HTMSS_NUMBER_OF_START_UP_TESTS))
        {
            Safety_SetTestRes(SAFETY_HTMSS, SAFETY_NORMAL);
            g_htmssInfo.htmssRet = TRUE;
            return;
        }
    }
    Safety_SetTestRes(SAFETY_HTMSS, SAFETY_ERROR);
}

void Safety_Htmsstest(void)
{
#if SAFETEY_MECHANISMS_ON
    Safety_HtmssInit();
    Safety_HtmssSelftest();
#endif
}

void HTMSSStartUpTestErrorCallbackFunc(void)
{
}