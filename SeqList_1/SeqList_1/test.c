#include "SeqList_1.h"

void TestBack()
{
	SeqList Seq;
	InitSeqList(&Seq);
	PushBack(&Seq, 1);
	PushBack(&Seq, 2);
	PushBack(&Seq, 3);
	PushBack(&Seq, 4);
	PrintSeqList(&Seq);

	PopBack(&Seq);
	PrintSeqList(&Seq);
	PopBack(&Seq);
	PrintSeqList(&Seq);
	PopBack(&Seq);
	PrintSeqList(&Seq);
	PopBack(&Seq);
	PrintSeqList(&Seq);
	PopBack(&Seq);
	PrintSeqList(&Seq);
}

void TestFront()
{
	SeqList Seq;
	InitSeqList(&Seq);
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PrintSeqList(&Seq);

	PopFront(&Seq);
	PrintSeqList(&Seq);
	PopFront(&Seq);
	PrintSeqList(&Seq);
	PopFront(&Seq);
	PrintSeqList(&Seq);
	PopFront(&Seq);
	PrintSeqList(&Seq);
	PopFront(&Seq);
	PrintSeqList(&Seq);
}

void TestFind()
{
	int pos = 0;
	SeqList Seq;
	InitSeqList(&Seq);
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PrintSeqList(&Seq);

	pos = Find(&Seq, 3);
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标为 %d\n", pos);
	}
}

void TestInsert()
{
	int pos = 0;
	SeqList Seq;
	InitSeqList(&Seq);
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PrintSeqList(&Seq);

	pos = Find(&Seq, 3);
	if (pos != -1)
	{
		//在制定位置的前面插入
		Insert(&Seq, pos, 7);
	}
	PrintSeqList(&Seq);
}

void TestErase()
{
	int pos = 0;
	SeqList Seq;
	InitSeqList(&Seq);
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PrintSeqList(&Seq);

	pos = Find(&Seq, 3);
	if (pos != -1)
	{
		Erase(&Seq, pos);
	}
	PrintSeqList(&Seq);

}

void TestRemove()
{
	SeqList Seq;
	InitSeqList(&Seq);
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PushFront(&Seq, 5);
	PushFront(&Seq, 6);
	PushFront(&Seq, 3);
	PrintSeqList(&Seq);

	Remove(&Seq, 2);
	PrintSeqList(&Seq);
	Remove(&Seq, 7);
	PrintSeqList(&Seq);

}

void TestRemoveAll()
{
	SeqList Seq;
	InitSeqList(&Seq);
	PushFront(&Seq, 1);
	PushFront(&Seq, 2);
	PushFront(&Seq, 3);
	PushFront(&Seq, 3);
	PushFront(&Seq, 4);
	PushFront(&Seq, 5);
	PushFront(&Seq, 6);
	PushFront(&Seq, 3);
	PushFront(&Seq, 3);
	PushFront(&Seq, 3);
	PrintSeqList(&Seq);
	if(!Empty(&Seq))
		printf("大小：%d\n", Size(&Seq));
	PrintSeqList(&Seq);

	RemoveAll(&Seq, 3);
	PrintSeqList(&Seq);

}

void TestBubbleSort()
{
	SeqList Seq;
	int i = 0;
	InitSeqList(&Seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&Seq, i);
	}
	PrintSeqList(&Seq);

	//升序
	BubbleSort(&Seq);
	PrintSeqList(&Seq);

}

void TestSelectSort()
{
	SeqList Seq;
	int i = 0;
	InitSeqList(&Seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&Seq, i);
	}
	PrintSeqList(&Seq);

	SelectSort(&Seq);
	PrintSeqList(&Seq);

	SelectSort_OP(&Seq);
	PrintSeqList(&Seq);

}

void TestBinarySearch()
{
	SeqList Seq;
	int i = 0;
	int pos = 0;
	InitSeqList(&Seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&Seq, i);
	}
	PrintSeqList(&Seq);

	SelectSort(&Seq);
	PrintSeqList(&Seq);

	//pos = BinarySearch(&Seq, 7);
	pos = BinarySearch_R(&Seq, 0, Seq.size - 1, 7);
	if (pos != -1)
	{
		printf("下标是：%d\n", pos);
	}
	else
	{
		printf("找不到\n");
	}
}

int main()
{
	//TestBack();
	//TestFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestRemoveAll();
	TestBubbleSort();
	//TestSelectSort();
	//TestBinarySearch();

	system("pause");
	return 0;
}