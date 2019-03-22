#include "SeqList.h"

int main()
{
	SeqList Seq;
	int ret = 0;
	InitSeqList(&Seq);

	printf("ͷ��\n");
	FrontPushSeqList(&Seq, 1);
	FrontPushSeqList(&Seq, 2);
	FrontPushSeqList(&Seq, 3);
	FrontPushSeqList(&Seq, 4);
	FrontPushSeqList(&Seq, 5);
	PrintSeqList(&Seq);

	printf("β��\n");
	BackPushSeqList(&Seq, 6);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 8);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 7);
	BackPushSeqList(&Seq, 8);
	PrintSeqList(&Seq);
	
	printf("ͷɾ\n");
	FrontPopSeqList(&Seq);
	FrontPopSeqList(&Seq);
	PrintSeqList(&Seq);

	printf("βɾ\n");
	BackPopSeqList(&Seq);
	PrintSeqList(&Seq);

	printf("ָ��λ�ò���\n");
	InsertSeqList(&Seq, 3, 9);
	PrintSeqList(&Seq);

	printf("�ж��Ƿ�Ϊ��\n");
	ret = EmptySeqList(&Seq);
	if (0 == ret)
	{
		printf("˳���Ϊ��\n");
	}
	else
		printf("˳���ǿ�\n");


	ret = FindData(&Seq, 9);
	if (ret == -1)
	{
		printf("û�ҵ�ָ��Ԫ��\n");
	}
	else
	{
		printf("ָ��Ԫ�ص�λ��Ϊ:%d\n", ret);
	}

	printf("ָ��λ��ɾ��\n");
	EraseData(&Seq, -1);
	EraseData(&Seq, 3);
	PrintSeqList(&Seq);

	printf("ɾ��ָ������\n");
	RemoveData_1(&Seq, 7);
	PrintSeqList(&Seq);

	RemoveData_2(&Seq, 7);
	PrintSeqList(&Seq);

	printf("ɾ������ָ������\n");
	RemoveAllData(&Seq, 7);
	PrintSeqList(&Seq);

	system("pause");
	return 0;
}