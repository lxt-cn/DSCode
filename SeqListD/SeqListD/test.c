#include "SeqListD.h"

void Test()
{
	SeqList Seq;
	InitSeqList(&Seq);
	PushBack(&Seq, 1);
	PushBack(&Seq, 2);
	PushBack(&Seq, 3);
	PushBack(&Seq, 2);
	PushBack(&Seq, 4);
	PushBack(&Seq, 2);
	PrintSeqList(&Seq);

	PopBack(&Seq);
	PrintSeqList(&Seq);
	PopBack(&Seq);
	PrintSeqList(&Seq);

	Insert(&Seq, 2, 5);
	PrintSeqList(&Seq);

	Erase(&Seq, 3);
	PrintSeqList(&Seq);

	DeatroySeqList(&Seq);
}

int main()
{
	Test();

	system("pause");
	return 0;
}