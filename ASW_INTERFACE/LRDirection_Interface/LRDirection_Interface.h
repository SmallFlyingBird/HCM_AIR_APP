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

typedef enum{
	LR_PIN_STATE_UNKOWN=0,
	LR_PIN_STATE_SHORT2GND=1,
	LR_PIN_STATE_OPENORSHORT2VCC=2,
}E_LR_PIN_STATE;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
E_LR_DIRECTION Interface_GetBootLRDection(void);
E_LR_DIRECTION Interface_GetAppLRDection(void);
uint8_t DirectionInterface_Init(void);


