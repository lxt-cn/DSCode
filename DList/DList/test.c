#include "DList.h"

void PushBackTest()
{
	pList plist;
	plist = InitList();
	PushBack(plist, 1);
	PushBack(plist, 2);
	PushBack(plist, 3);
	PushBack(plist, 4);
	PrintList(plist);      // 1  2  3  4 
	DestoryList(plist);
}

void PushFrontTest()
{
	pList plist = InitList();
	PushFront(plist, 1);
	PushFront(plist, 2);
	PushFront(plist, 3);
	PushFront(plist, 4);
	PrintList(plist);      // 4  3  2  1
	DestoryList(plist);
}

void FindListTest()
{
	pNode pos = NULL;
	pList plist = InitList();

	PushFront(plist, 1);
	PushFront(plist, 2);
	PushFront(plist, 3);
	PushFront(plist, 4);
	PrintList(plist);      // 4  3  2  1
	pos = FindList(plist, 3);
	if (pos == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了:%d\n", pos->data);
	}
	DestoryList(plist);
}

void InsertListTest()
{
	pNode pos = NULL;
	pList plist = InitList();

	PushFront(plist, 1);
	PushFront(plist, 2);
	PushFront(plist, 3);
	PushFront(plist, 4);
	PrintList(plist);      // 4  3  2  1
	pos = FindList(plist, 3);
	if (pos == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		InsertList(pos, 5);
		PrintList(plist);      // 4  5  3  2  1
	}
	DestoryList(plist);
}

void PopBackTest()
{
	pList plist = InitList();
	PushFront(plist, 1);
	PushFront(plist, 2);
	PushFront(plist, 3);
	PushFront(plist, 4);
	PrintList(plist);      // 4  3  2  1
	PopBack(plist);
	PrintList(plist);      // 4  3  2 
	PopBack(plist);
	PrintList(plist);      // 4  3  
	PopBack(plist);
	PrintList(plist);      // 4  
	PopBack(plist);
	PrintList(plist);      //
	DestoryList(plist);
}

void PopFrontTest()
{
	pList plist = InitList();
	PushFront(plist, 1);
	PushFront(plist, 2);
	PushFront(plist, 3);
	PushFront(plist, 4);
	PrintList(plist);      // 4  3  2  1
	PopFront(plist);
	PrintList(plist);      // 3  2  1
	PopFront(plist);
	PrintList(plist);      // 2  1
	PopFront(plist);
	PrintList(plist);      // 1
	PopFront(plist);
	PrintList(plist);      //
	DestoryList(plist);
}

void EraseListTest()
{
	pNode pos = NULL;
	pList plist = InitList();

	PushFront(plist, 1);
	PushFront(plist, 2);
	PushFront(plist, 3);
	PushFront(plist, 4);
	PrintList(plist);      // 4  3  2  1
	pos = FindList(plist, 3);
	if (pos == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		EraseList(pos);
		PrintList(plist);      // 4  5  3  2  1
	}
	DestoryList(plist);
}

int main()
{
	PushBackTest();
	PushFrontTest();
	FindListTest();
	InsertListTest();
	PopBackTest();
	PopFrontTest();
	EraseListTest();

	return 0;
}