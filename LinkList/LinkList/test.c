#include "LinkList.h"

void TestPushBack()
{
	pList plist = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintList(plist);  //1  2  3  4
	printf("len = %d\n", GetListLength(plist));  //4
	DestroyList(&plist);
	PrintList(plist);  //
}

void TestPopBack()
{
	pList plist = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintList(plist);   //1  2  3  4
	PopBack(&plist);  
	PrintList(plist);   //1  2  3
	PopBack(&plist);  
	PrintList(plist);   //1  2
	PopBack(&plist);  
	PrintList(plist);   //1
	PopBack(&plist);  
	PrintList(plist);   //
	DestroyList(&plist);
	PrintList(plist);   //
}

void TestPushFront()
{
	pList plist = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);   //4  3  2  1
	DestroyList(&plist);
	PrintList(plist);  //
}

void TestPopFront()
{
	pList plist = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);   //4  3  2  1
	PopFront(&plist);
	PrintList(plist);   //3  2  1
	PopFront(&plist);
	PrintList(plist);   //2  1
	PopFront(&plist);
	PrintList(plist);   //1
	PopFront(&plist);
	PrintList(plist);   //
	DestroyList(&plist);
	PrintList(plist);  //
}

void TestFind()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);   //4  3  2  1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
	DestroyList(&plist);
	PrintList(plist);  //
}

void TestInsert()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);   //4  3  2  1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		Insert(&plist, pos, 5);
	}
	PrintList(plist);   //4  5  3  2  1
	pos = Find(plist, 4);
	if (pos != NULL)
	{
		Insert(&plist, pos, 6);
	}
	PrintList(plist);   //6  4  5  3  2  1
	DestroyList(&plist);
	PrintList(plist);  //
}

void TestErase()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);   //4  3  2  1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		Erase(&plist, pos);
	}
	PrintList(plist);   //4  2  1
	pos = Find(plist, 4);
	if (pos != NULL)
	{
		Erase(&plist, pos);
	}
	PrintList(plist);   //2  1
	DestroyList(&plist);
	PrintList(plist);  //
}

void TestRemove()
{
	pList plist = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 1);
	PushFront(&plist, 4);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PrintList(plist);   //3  2  4  1  3  2  1
	Remove_1(&plist, 2);
	PrintList(plist);   //3  4  1  3  2  1
	Remove_2(&plist, 3);
	PrintList(plist);   //4  1  3  2  1

	RemoveAll(&plist, 1);
	PrintList(plist);   //4  3  2 
	DestroyList(&plist);
	PrintList(plist);  //
}

int main()
{
	TestPushBack();
	TestPopBack();
	TestPushFront();
	TestPopFront();
	TestFind();
	TestInsert();
	TestErase();
	TestRemove();

	system("pause");
	return 0;
}