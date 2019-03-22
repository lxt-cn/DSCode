#include "SeqList.h"

int main()
{
	SeqList Seq;
	int ret = 0;
	InitSeqList(&Seq);

	printf("头插\n");
	FrontPushSeqList(&Seq, 1);
	FrontPushSeqList(&Seq, 2);
	FrontPushSeqList(&Seq, 3);
	FrontPushSeqList(&Seq, 4);
	FrontPushSeqList(&Seq, 5);
	PrintSeqList(&Seq);

	printf("尾插\n");
	BackPushSeqList(&Seq, 6);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 8);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 8);
	PrintSeqList(&Seq);
	
	printf("头删\n");
	FrontPopSeqList(&Seq);
	FrontPopSeqList(&Seq);
	PrintSeqList(&Seq);

	printf("尾删\n");
	BackPopSeqList(&Seq);
	PrintSeqList(&Seq);

	printf("指定位置插入\n");
	InsertSeqList(&Seq, 3, 9);
	PrintSeqList(&Seq);

	printf("判断是否为空\n");
	ret = EmptySeqList(&Seq);
	if (0 == ret)
	{
		printf("顺序表为空\n");
	}
	else
		printf("顺序表非空\n");


	ret = FindData(&Seq, 9);
	if (ret == -1)
	{
		printf("没找到指定元素\n");
	}
	else
	{
		printf("指定元素的位置为:%d\n", ret);
	}

	printf("指定位置删除\n");
	EraseData(&Seq, -1);
	EraseData(&Seq, 3);
	PrintSeqList(&Seq);

	printf("删除指定数据\n");
	RemoveData_1(&Seq, 7);
	PrintSeqList(&Seq);

	RemoveData_2(&Seq, 7);
	PrintSeqList(&Seq);

	printf("删除所有指定数据\n");
	RemoveAllData(&Seq, 7);
	PrintSeqList(&Seq);

	system("pause");
	return 0;
}