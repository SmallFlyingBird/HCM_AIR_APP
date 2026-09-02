#include "Dem.h"
#include "Com_Cfg.h"

#define CLEAR_BITS(value, bits) ((value) & ~(bits))
#define SET_BITS(value, bits)   ((value) | (bits))

static uint32 Dem_TestFailed = 0;  // 0→1变化标志（bitN=1表示对应位发生0→1）
static uint32 Dem_Confirmed = 0;  // 1→0变化标志（bitN=1表示对应位发生1→0）
static uint32 Dem_D900_Flag[2] = 0;
static uint8 update_flag = 0;

void modify_bits(uint32* originalptr,uint8 bit,Dem_Dtc_ErrorStatus_Enum_Type value)
{
    static uint32 mask_set_low = 0;
    static uint32 mask_set_high = 0;
    uint32 mask_clear = 0;
    /** clear bit index,index only 2,4,6,8 etc.*/ 
    if(bit < 31)
    {
        mask_clear = ~((1ULL << bit) | (1ULL << (bit+1)));
        *originalptr &= (mask_clear);
    }
    else
    {
        mask_clear = ~((1ULL << bit - 31) | (1ULL << (bit - 30)));
        *(originalptr+1) &= (mask_clear << 31);
    }

    
    
    /* Set bit */ 
    if(value == DEM_DTC_TESTFAIL)
    {
        if(bit < 31)
        {
            mask_set_low = (DEM_DTC_TESTFAIL << bit);
        }
        else
        {
            mask_set_high = (DEM_DTC_TESTFAIL << (bit - 31));
        }
    }
    else if(value == DEM_DTC_CONFIRMED)
    {
        if(bit < 31)
        {
            mask_set_low = (DEM_DTC_CONFIRMED << bit);
        }
        else
        {
            mask_set_high = (DEM_DTC_CONFIRMED << (bit - 31));
        }
    }
    else
    {
        *originalptr = 0;
    }

    *originalptr |= mask_set_high ;
    *(originalptr+1) |= mask_set_low;
}

void Dem_Compare_DTC_Status(void)
{
    static DTC_Group_Type Last_DTC = 0;
    static DTC_Group_Type Current_DTC;


    /* Get lastest data from HcmZcud_Lin2Fr01 */
    Com_Dem_GetDTCData(&Current_DTC.DTCGroup);

    /* Get change bit */
    const uint32 diff = Current_DTC.DTCGroup ^ Last_DTC.DTCGroup;

    if(diff == 0)
    {/* if no change then return */
        return;
    }

    /* find running dtc */
    Dem_TestFailed = Current_DTC.DTCGroup & diff;

    /* find history dtc */
    Dem_Confirmed = Last_DTC.DTCGroup & diff;

    /* Updata Dtc data */
    Last_DTC.DTCGroup = Current_DTC.DTCGroup;

    update_flag = 1;
}

void Dem_Update_Dtcstatus(void)
{
    if(update_flag == 1)
    {
        if(Dem_TestFailed != Dem_Dtc_NO_ERROR)
        {/*  */
            for (uint8 i = 0; i < 32; i++)
            {
                if (Dem_TestFailed & (1U << i))
                {
                    modify_bits(Dem_D900_Flag,i*2,DEM_DTC_TESTFAIL);
                }
            }
        }
        if(Dem_Confirmed != Dem_Dtc_NO_ERROR)
        {
            for (uint8 i = 0; i < 32; i++)
            {
                if (Dem_Confirmed & (1U << i))
                {
                    modify_bits(Dem_D900_Flag,i*2,DEM_DTC_CONFIRMED);
                }
            }
        }
        update_flag = 0;
    }

}


/* Get 2 bits from number bit+1 and bit */
uint8 Dem_GetDTC_Status(uint8 bit)
{
    uint8 ret = Dem_Dtc_NO_ERROR;
    uint32 high32bit = Dem_D900_Flag[0];
    uint32 low32bit = Dem_D900_Flag[1];
    if((bit < 63) && (bit >31))
    {
        ret = (((high32bit >> (bit - 31))) & ((1ULL << 1) | (1ULL << 0)));    
    }
    else
    {
        ret = (((low32bit >> bit)) & ((1ULL << 1) | (1ULL << 0)));    
    }

    return ret;
}

void Dem_Clear_DTCFlag(void)
{
    Dem_D900_Flag[0] = 0;
    Dem_D900_Flag[1] = 0;
}


void Dem_MainFunction(void)
{
    /* find dtc change bit */
    Dem_Compare_DTC_Status();

    /* Update DID-D900 */
    Dem_Update_Dtcstatus();
}