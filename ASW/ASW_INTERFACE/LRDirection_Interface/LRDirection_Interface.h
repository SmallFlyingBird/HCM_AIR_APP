/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define LEFT_SIDE_PIN_LEVEL 1
#define RIGHT_SIDE_PIN_LEVEL 0
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum {
	DIRECTION_UNKOWM=0,
	DIRECTION_LEFT=1,
	DIRECTION_RIGHT=2,
}E_LR_DIRECTION;

typedef enum {
	DIRECTION_SAME=0,
	DIRECTION_DIF=1,
}E_LR_DIRECTIONCMP;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void DirectionInterface_Init(void);
uint8 Interface_GetLRDirection(void);
uint8 Interface_GetLRDirectionCmp(void);