/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "LinSM.h"
#include "RTE_ASW.h"
#include "Rte_E2E_Callout.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* sleep confirmation */
void LinSM_GotoSleepConfirmation(NetworkHandleType network,boolean success)
{

}
/* sleep Indication */
void LinSM_GotoSleepIndication(NetworkHandleType network)
{
    /* stop e2e check */ 
    RTE_COM_E2E_SetE2EStatus(0x00u);

    /*clear e2e error*/
    RTE_E2E_ClearE2EErrorFlag();

    /* turn off all light */
    RTE_ASW_AllLightOff();
}

/* wakeup confirmation */
void LinSM_WakeupConfirmation(NetworkHandleType network,boolean success)
{

}

