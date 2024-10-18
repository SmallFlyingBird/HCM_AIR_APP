/*
 * List.c
 *
 *  Created on: 2024.04.02
 *      Author: mihuiliang
 *  此模块代码主要参考FreeRtos中的List模块
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "List_Interface.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType ListItemInit(ListItem_t *pxItem)
{
    if (pxItem == NULL)
        return E_NOT_OK;
    pxItem->pvContainer = NULL;
    pxItem->pxPrevious = NULL;
    pxItem->pxNext = NULL;
    return E_OK;
}
Std_ReturnType ListInit(List_t *pxList)
{
    if (pxList == NULL)
        return E_NOT_OK;

    pxList->uxNumberOfItems = 0;
    pxList->xListEnd.xItemValue = MAX_ITEM_VALUE;
    pxList->xListEnd.pxNext = (ListItem_t *)&(pxList->xListEnd);
    pxList->xListEnd.pxPrevious = (ListItem_t *)&(pxList->xListEnd);
    return E_OK;
}

/*
 *  列表项插入函数
 *  此函数把列表项插入到列表的末尾
 */
Std_ReturnType ListItemInsertEnd(List_t *pxList, ListItem_t *pxNewListItem)
{
    ListItem_t *pxIterator;

    if (pxList == NULL || pxNewListItem == NULL)
        return E_NOT_OK;

    pxIterator = pxList->xListEnd.pxPrevious;

    pxNewListItem->pxPrevious = pxIterator;
    pxNewListItem->pxNext = &(pxList->xListEnd);
    pxIterator->pxNext = pxNewListItem;
    pxList->xListEnd.pxPrevious = pxNewListItem;

    pxNewListItem->pvContainer = pxList;

    (pxList->uxNumberOfItems)++;

    return E_OK;
}
/*
 *  列表项插入函数
 *  此函数会根据 pxNewListItem->xItemValue的大小进行顺序插入
 */
Std_ReturnType ListItemInsert(List_t *pxList, ListItem_t *pxNewListItem)
{
    ListItem_t *pxIterator;

    if (pxList == NULL || pxNewListItem == NULL)
        return E_NOT_OK;

    if (pxNewListItem->xItemValue == MAX_ITEM_VALUE)
    {
        /*插入列表的末尾*/
        pxNewListItem->pxNext = &(pxList->xListEnd);
        pxNewListItem->pxPrevious = pxList->xListEnd.pxPrevious;

        (pxList->xListEnd.pxPrevious)->pxNext = pxNewListItem;
        pxList->xListEnd.pxPrevious = pxNewListItem;
    }
    else
    {
        /*遍历列表*/
        for (pxIterator = pxList->xListEnd.pxNext; pxIterator->xItemValue < pxNewListItem->xItemValue; pxIterator = pxIterator->pxNext)
        {
        }

        pxNewListItem->pxNext = pxIterator;
        pxNewListItem->pxPrevious = pxIterator->pxPrevious;
        pxIterator->pxPrevious->pxNext = pxNewListItem;
        pxIterator->pxPrevious = pxNewListItem;
    }

    /* Remember which list the item is in.  This allows fast removal of the
    item later. */
    pxNewListItem->pvContainer = (void *)pxList;
    (pxList->uxNumberOfItems)++;

    return E_OK;
}
/*
 * 把列表项从某个列表中移除
 */
Std_ReturnType ListItemRemove(ListItem_t *pxItemToRemove)
{
    List_t *pxList = (List_t *)pxItemToRemove->pvContainer;

    if (pxItemToRemove == NULL || pxList == NULL)
        return E_NOT_OK;

    pxItemToRemove->pxNext->pxPrevious = pxItemToRemove->pxPrevious;
    pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;

    pxItemToRemove->pvContainer = NULL;
    (pxList->uxNumberOfItems)--;

    return E_OK;
}
/*
 *查看某个列表项是否挂载到某个列表下
 */
uint8_t IsListItemInList(List_t *pxList, ListItem_t *pxListItem)
{
    if (pxList == NULL || pxListItem == NULL)
        return 0;

    if (pxListItem->pvContainer == pxList)
        return 1;

    return 0;
}

ListItem_t *GetNextListItem(ListItem_t *pxListItemIn)
{
    List_t *ListContainer = NULL;

    if (pxListItemIn == NULL)
        return NULL;

    ListContainer = pxListItemIn->pvContainer;
    if (ListContainer == NULL)
        return NULL;
    
    if(pxListItemIn->pxNext == (&(ListContainer->xListEnd)))
        return (ListContainer->xListEnd.pxNext);
    else
        return (pxListItemIn->pxNext);
}

uint16_t GetListNumberOfItems(List_t *pxList)
{
    if (pxList == NULL)
        return 0;

    return (pxList->uxNumberOfItems);
}