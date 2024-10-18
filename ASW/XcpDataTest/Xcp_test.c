#include "XcpMeasuredata.h"
#include "Xcp_Caldata.h"
#include "Xcp_test.h"

void DaqChangeTest(void)
{   
	Mea_A = Calib_A + Calib_B;
}

void App_DaqDataInit(void)
{
	Mea_A = 0;

}
