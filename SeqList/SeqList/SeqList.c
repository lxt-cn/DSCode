#include "SeqList.h"

//��ʼ��
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	memset(pSeq->data, 0, sizeof(pSeq->data));
	pSeq->size = 0;
}

//ͷ��
void FrontPushSeqList(pSeqList pSeq, DataType d)
{
	int i = pSeq->size ;

	assert(pSeq != NULL);

	if (MAX == pSeq->size)
	{
		printf("˳����������޷�����\n");
		return;
	}

	for (; i > 0; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[i] = d;
	pSeq->size++;
}

//β��
void BackPushSeqList(pSeqList pSeq, DataType d)
{
	assert(pSeq != NULL);

	if (MAX == pSeq->size)
	{
		printf("˳����������޷�����\n");
		return;
	}

	pSeq->data[pSeq->size] = d;
	pSeq->size++;
}

//ͷɾ
void FrontPopSeqList(pSeqList pSeq)
{

	int i = 0;
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("˳���Ϊ�գ��޿�ɾ��������\n");
		return;
	}

	for (i = 0; i < pSeq->size-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}

	pSeq->size--;
}

//βɾ
void BackPopSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("˳���Ϊ�գ��޿�ɾ������\n");
		return;
	}

	pSeq->size--;
}

//����ָ��Ԫ��
int FindData(pSeqList pSeq, DataType d)
{
	int i = 0;

	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		return -1;
	}

	for (i = 0; i < pSeq->size; i++)
	{
		if (d == pSeq->data[i])
		{
			return i;
		}
	}
	return -1;
}

//ָ��λ�ò���
void InsertSeqList(pSeqList pSeq, int pos, DataType d)
{
	int i = pSeq->size;

	assert(pSeq != NULL);

	if (pos < 0 || pos >= pSeq->size)
	{
		printf("λ�ô���\n");
		return;
	}

	for (; i > pos; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[i] = d;
	pSeq->size++;
}

//ɾ��ָ��λ��Ԫ��
void EraseData(pSeqList pSeq, int pos)
{
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("˳���Ϊ�գ��޿�ɾ������\n");
		return;
	}
	if ((pos < 0) || (pos >= pSeq->size))
	{
		printf("ָ��λ�ô���\n");
		return;
	}

	for (; pos < pSeq->size; pos++)
	{
		pSeq->data[pos] = pSeq->data[pos + 1];
	}
	pSeq->size--;
}

//ɾ��ָ��Ԫ��
void RemoveData_1(pSeqList pSeq, DataType d)
{
	int i = 0;
	int j = 0;

	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("˳���Ϊ�գ��޿�ɾ������\n");
		return;
	}

	for (i = 0; i < pSeq->size; i++)
	{
		if (d == pSeq->data[i])
		{
			for (j = i; j < pSeq->size; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->size--;
			return;
		}
	}
}

void RemoveData_2(pSeqList pSeq, DataType d)
{
	int i = 0;

	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("˳���Ϊ�գ��޿�ɾ������\n");
		return;
	}

	i = FindData(pSeq, d);
	if (i == -1)
	{
		printf("˳�����ָ��Ԫ��\n");
		return;
	}
	else
	{
		EraseData(pSeq, i);
	}
}
//ɾ������ָ��Ԫ��

//void RemoveAllData(pSeqList pSeq, DataType d)
//{
//	int i = 0;
//
//	assert(pSeq != NULL);
//
//	if (0 == pSeq->size)
//	{
//		printf("˳���Ϊ�գ��޿�ɾ��������\n");
//		return;
//	}
//
//	while (1)
//	{
//		i = FindData(pSeq, d);
//		if (i = -1)
//		{
//			return;
//		}
//		EraseData(pSeq, i);
//	}
//}

void RemoveAllData(pSeqList pSeq, DataType d)
{
	int count = 0;
	int i = 0;

	assert(pSeq != NULL);

	for (; i < pSeq->size; ++i)
	{
		if (pSeq->data[i] == d)
		{
			count++;
		}
		else
		{
			pSeq->data[i - count] = pSeq->data[i];
		}
	}
	pSeq->size -= count;
}

//�ж��Ƿ�Ϊ��
int EmptySeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		return 0;
	}
	return 1;
}

//��ӡ
void PrintSeqList(pSeqList pSeq)
{
	int i = 0;

	assert(pSeq != NULL);

	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}