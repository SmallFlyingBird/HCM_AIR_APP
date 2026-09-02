#ifndef _DEM_H_
#define _DEM_H_



typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef union
{
    uint32 DTCGroup;
    struct
    {
        uint32 DTCGroup0Bit0 : 1;
        uint32 DTCGroup0Bit1 : 1;
        uint32 DTCGroup0Bit2 : 1;
        uint32 DTCGroup0Bit3 : 1;
        uint32 DTCGroup0Bit4 : 1;
        uint32 DTCGroup0Bit5 : 1;
        uint32 DTCGroup0Bit6 : 1;
        uint32 DTCGroup0Bit7 : 1;
        uint32 DTCGroup1Bit0 : 1;
        uint32 DTCGroup1Bit1 : 1;
        uint32 DTCGroup1Bit2 : 1;
        uint32 DTCGroup1Bit3 : 1;
        uint32 DTCGroup1Bit4 : 1;
        uint32 DTCGroup1Bit5 : 1;
        uint32 DTCGroup1Bit6 : 1;
        uint32 DTCGroup1Bit7 : 1;
        uint32 DTCGroup2Bit0 : 1;
        uint32 DTCGroup2Bit1 : 1;
        uint32 DTCGroup2Bit2 : 1;
        uint32 DTCGroup2Bit3 : 1;
        uint32 DTCGroup2Bit4 : 1;
        uint32 DTCGroup2Bit5 : 1;
        uint32 DTCGroup2Bit6 : 1;
        uint32 DTCGroup2Bit7 : 1;
        uint32 DTCGroup3Bit0 : 1;
        uint32 DTCGroup3Bit1 : 1;
        uint32 DTCGroup3Bit2 : 1;
        uint32 DTCGroup3Bit3 : 1;
        uint32 DTCGroup3Bit4 : 1;
        uint32 DTCGroup3Bit5 : 1;
        uint32 DTCGroup3Bit6 : 1;
        uint32 DTCGroup3Bit7 : 1;
    } bits;
} DTC_Group_Type;

typedef enum
{
    Dem_Dtc_NO_ERROR,
    DEM_DTC_TESTFAIL,
    DEM_DTC_CONFIRMED
}Dem_Dtc_ErrorStatus_Enum_Type;

void modify_bits(uint32 *originalptr, uint8 bit, Dem_Dtc_ErrorStatus_Enum_Type value);
void Dem_Compare_DTC_Status(void);
void Dem_Update_Dtcstatus(void);
uint8 Dem_GetDTC_Status(uint8 bit);
void Dem_MainFunction(void);
void Dem_Clear_DTCFlag(void);
#endif