#include "ListImpl.h"

typedef struct ListItem1_s {
	int a;
	int b;
	const char* str;
}ListItem1_t;

typedef struct ListItem2_s {
	const char* str;
	int b;
}ListItem2_t;

void DeleteLastItem(List_t* pLs, ListItem_t* pLastItem)
{
	//ListItem_t* pListItem = FindListItemByListItemData(pLs, (void*)pLastItem);
	DeleteListItem(pLs, pLastItem);
}

void DeleteFirstItem(List_t* pLs, ListItem_t* pFirstItem)
{
	//ListItem_t* pListItem = FindListItemByListItemData(pLs, (void*)pFirstItem);
	DeleteListItem(pLs, pFirstItem);
}

List_t* CreateListItem1List(ListItem1_t* pListItem1Arr, const size_t arrSize)
{
	List_t* pLsListItem1 = ListInit(sizeof(ListItem1_t));
	ListItem_t* pListItem1;

	for (size_t i = 0; i < arrSize; i++) {
		pListItem1 = ListItemInit(pLsListItem1, &pListItem1Arr[i]);
		InsertListItem(pLsListItem1, pListItem1);

	}
	return pLsListItem1;
}

void ListItem1Test()
{
	ListItem1_t listItem1_1 = {};
	ListItem1_t listItem1_2 = {};

	listItem1_1.a = 0;
	listItem1_1.b = 10;
	listItem1_1.str = "listItem1_1";

	listItem1_2.a = 1;
	listItem1_2.b = 10;
	listItem1_2.str = "listItem1_2";

	ListItem1_t listItemArr[] = {listItem1_1, listItem1_2};

	List_t* pLs = CreateListItem1List(listItemArr, sizeof(listItemArr) / sizeof(listItemArr[0]));

	ListItem1_t listItem1Test = {};
	listItem1Test.a = ((ListItem1_t*)(pLs->head->pItemData))->a;
	listItem1Test.b = ((ListItem1_t*)(pLs->head->pItemData))->b;
	listItem1Test.str = ((ListItem1_t*)(pLs->head->pItemData))->str;
	DeleteLastItem(pLs, pLs->head->nextItem);
	DeleteFirstItem(pLs, pLs->head);
	ListDeInit(pLs);
}

int main()
{
	List_t* pLsListItem2 = ListInit(sizeof(ListItem2_t));
	ListItem1Test();
	return 0;
}