#include <stdlib.h>
#include <string.h>

#include "ListImpl.h"

List_t* ListInit(size_t itemSize)
{
	List_t* pLs = (List_t*)malloc(sizeof(List_t));
	pLs->head = NULL;
	pLs->itemSize = itemSize;
	pLs->listSize = 0;
	return pLs;
}

void ListDeInit(List_t* pLs)
{
	free(pLs);
}

ListItem_t* ListItemInit(List_t * pLs, const void* itemSrc)
{
	ListItem_t* pItem = (ListItem_t*)malloc(sizeof(ListItem_t));
	pItem->pItemData = malloc(pLs->itemSize);
	memcpy(pItem->pItemData, itemSrc, pLs->itemSize);
	pItem->nextItem = NULL;
	return pItem;
}

void InsertListItem(List_t* pLs, ListItem_t* pItemForInsert)
{
	if (FindListItemByListItemData(pLs, pItemForInsert->pItemData) != NULL) return;
	ListItem_t* item = GetLast(pLs);

	if (item == NULL) pLs->head = pItemForInsert;
	else item->nextItem = pItemForInsert;
	pLs->listSize++;
}

bool IsHeadItem(List_t* pLs, ListItem_t* pCandidate)
{
	return (pCandidate == pLs->head);
}

bool ListEmpty(List_t* pLs)
{
	return (pLs->listSize == 0);
}

ListItem_t* FindListItemByListItemData(List_t* pLs, void* pListItemData)
{
	ListItem_t* pListItem;
	for (pListItem = pLs->head;  pListItem != NULL;  pListItem = pListItem->nextItem)
		if (memcmp(pListItem->pItemData, pListItemData, pLs->itemSize) == 0) return pListItem;
	return NULL;
}

ListItem_t* GetPrevious(List_t* pLs, ListItem_t* pItem)
{
	ListItem_t* prevItem = NULL;

	if (ListEmpty(pLs) || IsHeadItem(pLs, pItem)) goto exit;
	for (prevItem = pLs->head; prevItem->nextItem != pItem; prevItem = prevItem->nextItem);
	exit:
	return prevItem;
}

ListItem_t* GetLastButOne(List_t* pLs)
{
	ListItem_t* pItem = NULL;
	if (ListEmpty(pLs) || (pLs->head->nextItem == NULL)) goto exit;
	for (pItem = pLs->head; pItem->nextItem->nextItem != NULL; pItem = pItem->nextItem);
	exit:
	return pItem;
}

ListItem_t* GetLast(List_t* pLs)
{
	ListItem_t* pItem = NULL;
	if (ListEmpty(pLs) == true) goto exit;
	for (pItem = pLs->head; pItem->nextItem != NULL; pItem = pItem->nextItem);
	exit:
	return pItem;
}

void DeleteListItem(List_t* pLs, ListItem_t* pItemForDelete)
{
	ListItem_t* pPrevItem = GetPrevious(pLs, pItemForDelete);

	if (pPrevItem == NULL) pLs->head = pLs->head->nextItem;
	else pPrevItem->nextItem = pItemForDelete->nextItem;
	free(pItemForDelete);
	pLs->listSize--;
}
