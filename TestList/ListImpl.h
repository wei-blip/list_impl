#pragma once
typedef struct ListItem_s {
	void* pItemData;
	//size_t itemSize;
	ListItem_s* nextItem;
}ListItem_t;

typedef struct List_s {
	ListItem_t* head;
	size_t itemSize;
	size_t listSize;
}List_t;

List_t* ListInit(size_t itemSize);
void ListDeInit(List_t* pLs);
ListItem_t* ListItemInit(List_t * pLs, const void* itemSrc);
void InsertListItem(List_t* pLs, ListItem_t* pItemForInsert);
bool IsHeadItem(List_t* pLs, ListItem_t* pCandidate);
bool ListEmpty(List_t* pLs);
ListItem_t* FindListItemByListItemData(List_t* pLs, void* pListItemData);
ListItem_t* GetPrevious(List_t* pLs, ListItem_t* pItem);
ListItem_t* GetLastButOne(List_t* pLs);
ListItem_t* GetLast(List_t* pLs);
void DeleteListItem(List_t* pLs, ListItem_t* pItemForDelete);
