#include "LinkListM.h"

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

void TestPrintTailToHead()
{
	pList plist = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);         //4  3  2  1
	PrintTailToHead_R(plist); //1  2  3  4
	printf("\n");
	PrintTailToHead(plist);   //1  2  3  4
	DestroyList(&plist);
}

void TestDelNodeNotTail()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);         //4  3  2  1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		DelNodeNotTail(pos);
	}
	PrintList(plist);         //4  2  1
	DestroyList(&plist);
}

void TestInsertNode()
{
	pList plist = NULL;
	pNode pos = NULL;
	InitList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);         //4  3  2  1
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		InsertNode(pos, 5);
	}
	PrintList(plist);         //4  5  3  2  1
	DestroyList(&plist);
}

void TestJosephusCycle()
{
	pNode plist = NULL;
	for (int i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);  //1  2  3  4  5  6  7  8  9  10
	//构成环
	Find(plist, 41)->next = plist;
	//
	JosephusCycle(&plist, 3);
	DestroyList(&plist);
}

void TestReverseList()
{
	pNode plist = NULL;
	for (int i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);  // 1  2  3  4  5  6  7  8  9  10
	ReverseList_1(&plist);
	PrintList(plist);  //10  9  8  7  6  5  4  3  2  1
	ReverseList_2(&plist);
	PrintList(plist);  // 1  2  3  4  5  6  7  8  9  10
	DestroyList(&plist);
}

void TestBubbleSortList()
{
	int i = 0;
	pNode plist = NULL;
	for (i = 1; i <= 5; i++)
	{
		PushBack(&plist, 6 - i);
	}
	PrintList(plist);  // 5  4  3  2  1
	BubbleSortList(plist);
	PrintList(plist);  // 1  2  3  4  5  
}

void TestMerge()
{
	pList plist1 = NULL;
	pList plist2 = NULL;
	pList plist = NULL;
	int i = 0;
	for (i = 0; i < 10; i+=2)
	{
		PushBack(&plist1, i);
	}
	for (i = 1; i < 10; i += 2)
	{
		PushBack(&plist2, i);
	}
	PrintList(plist1);    //0  2  4  6  8 
	PrintList(plist2);    //1  3  5  7  9
	//plist = Merge(plist1, plist2);
	plist = Merge_R(plist1, plist2);
	PrintList(plist);     //0  1  2  3  4  5  6  7  8  9 
	DestroyList(&plist);
}

void TestFindMidNode()
{
	pList plist = NULL;
	pNode Mid = NULL;
	for (int i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);  // 1  2  3  4  5  6  7  8  9  10
	Mid = FindMidNode(plist);
	if (Mid != NULL)
	{
		printf("%d\n", Mid->data);    // 6
	}
	DestroyList(&plist);
}

void TestFindLastKNode()
{
	pList plist = NULL;
	pNode pos = NULL;
	for (int i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);
	}
	PrintList(plist);  // 1  2  3  4  5  6  7  8  9  10
	pos = FindLastKNode(plist, 3);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);  // 8
	}
	DestroyList(&plist);
}

void TestCircle()
{
	pList plist = NULL;
	pNode pos = NULL;
	for (int i = 1; i <= 5; i++)
	{
		PushBack(&plist, i);
	}
	Find(plist, 5)->next = Find(plist, 3);
	pos = IsCircle(plist);
	if (pos != NULL)
	{
		printf("带环，相遇点是：%d\n", pos->data);
		printf("环的长度：%d\n", GetCircleLength(pos));
		printf("入口点是：%d\n", GetCirCleEntryNode(plist, pos)->data);
	}
	else
	{
		printf("不带环\n");
	}
}

void TestCheckCross()
{
	pList plist1 = NULL;
	pList plist2 = NULL;
	pNode pos = NULL;
	int i = 0;
	for (i = 0; i < 10; i += 2)
	{
		PushBack(&plist1, i);
	}
	PrintList(plist1);    //0  2  4  6  8 
	for (i = 1; i < 10; i += 2)
	{
		PushBack(&plist2, i);
	}
	PrintList(plist2);    //1  3  5  7  9
	Find(plist2, 9)->next = Find(plist1, 4);
	PrintList(plist1);    //0  2  4  6  8
	PrintList(plist2);    //1  3  5  7  9  4  6  8
	if (CheckCross(plist1, plist2) == 1)
	{
		printf("相交\n");
		//求交点
		pos = GetCrossMeetNode(plist1, plist2);
		printf("交点是：%d\n", pos->data);
	}
	else
	{
		printf("不相交\n");
	}
}

void TestCheckCrossWithCircle()
{
	pList plist1 = NULL;
	pList plist2 = NULL;
	pNode pos = NULL;
	int i = 0;
	for (i = 1; i < 10; i++)
	{
		PushBack(&plist1, i);
	}
	PrintList(plist1);    // 1  2  3  4  5  6  7  8  9(5) 
	Find(plist1, 9)->next = Find(plist1, 5);

	for (i = 1; i < 6; i += 2)
	{
		PushBack(&plist2, i);
	}
	PrintList(plist2);    //1  3  5
	//Find(plist2, 5)->next = Find(plist1, 3); //1  3  5(p1:3)(3  4  5  6  7  8  9)
	Find(plist2, 5)->next = Find(plist1, 8);  //1  3  5(p1:8)(8  9  5  6  7)
	if ((IsCircle(plist1) == NULL) || (IsCircle(plist2) == NULL))
	{
		if (CheckCross(plist1, plist2) == 1)
		{
			printf("不带环相交\n");
			//求交点
			pos = GetCrossMeetNode(plist1, plist2);
			printf("交点是：%d\n", pos->data);
		}
		else
		{
			printf("不相交\n");
		}
	}
	if (CheckCrossWithCircle(plist1, plist2) == 1)
	{
		printf("带环相交\n");
		GetCrossMeetNodeWithCircle(plist1, plist2);
	}
	else
	{
		printf("都带环不相交\n");
	}

}

void TestUnionSet()
{
	pList plist1 = NULL;
	pList plist2 = NULL;
	int i = 0;
	for (i = 1; i <= 9; i += 2)
	{
		PushBack(&plist1, i);
	}
	PrintList(plist1);    // 1  3  5  7  9
	for (i = 2; i <= 6; i++)
	{
		PushBack(&plist2, i); 
	}
	PrintList(plist2);   // 2  3  4  5  6
	UnionSet(plist1, plist2);
}

void TestComplexCopyList()
{
	ComplexNode* plist = NULL;
	ComplexNode* newlist = NULL;

	ComplexNode* p1 = BuyComplexNode(5);
	ComplexNode* p2 = BuyComplexNode(4);
	ComplexNode* p3 = BuyComplexNode(3);
	ComplexNode* p4 = BuyComplexNode(2);
	ComplexNode* p5 = BuyComplexNode(1);
	plist = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	
	p1->random = p3;
	p2->random = p1;
	p3->random = NULL;
	p4->random = p2;
	p5->random = p4;

	PrintComplexList(plist);
	newlist = CopyComplexList(plist);
	PrintComplexList(newlist);

}

int main()
{
	//TestPushBack();
	//TestPopBack();
	//TestPushFront();
	//TestPopFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestPrintTailToHead();
	//TestDelNodeNotTail();
	//TestInsertNode();
	//TestJosephusCycle();
	//TestReverseList();
	//TestBubbleSortList();
	//TestMerge();
	//TestFindMidNode();
	//TestFindLastKNode();
	//TestCircle();
	//TestCheckCross();
	//TestCheckCrossWithCircle();
	//TestUnionSet();
	TestComplexCopyList();

	system("pause");
	return 0;
}