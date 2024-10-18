/*
 * List.h
 *
 *  Created on: 2024.04.02
 *      Author: mihuiliang
 */

#ifndef _LIST_H_
#define _LIST_H_
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
#define MAX_ITEM_VALUE 0xFFFF
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
struct xLIST_ITEM
{
	uint16_t xItemValue;			                    /*根据此值的大小插入到列表中*/
	struct xLIST_ITEM *  pxNext;		                /*< Pointer to the next ListItem_t in the list. */
	struct xLIST_ITEM *  pxPrevious;	                /*< Pointer to the previous ListItem_t in the list. */
	void * pvContainer;				                    /*表示这个列表项所属哪个列表 */
    void * pvDataPtr;                                   /*指针，APP可用此指针指向所需要的数据*/
};
typedef struct xLIST_ITEM ListItem_t;					/* For some reason lint wants this as two separate definitions. */

typedef struct xLIST
{
	uint16_t uxNumberOfItems;                           /*列表中列表项的个数*/
    ListItem_t  xListEnd;                                                    
} List_t;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType ListItemInit( ListItem_t * pxItem );
Std_ReturnType ListInit( List_t * pxList );
Std_ReturnType ListItemInsertEnd(List_t *pxList, ListItem_t *pxNewListItem);
Std_ReturnType ListItemInsert(List_t *  pxList, ListItem_t *  pxNewListItem);
Std_ReturnType ListItemRemove(ListItem_t * pxItemToRemove);
uint8_t IsListItemInList(List_t *pxList, ListItem_t *pxListItem);
ListItem_t *GetNextListItem(ListItem_t *pxListItemIn);
uint16_t GetListNumberOfItems(List_t *  pxList);
#endif
