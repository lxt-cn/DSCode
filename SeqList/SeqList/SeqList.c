#include "SeqList.h"

//初始化
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	memset(pSeq->data, 0, sizeof(pSeq->data));
	pSeq->size = 0;
}

//头插
void FrontPushSeqList(pSeqList pSeq, DataType d)
{
	int i = pSeq->size ;

	assert(pSeq != NULL);

	if (MAX == pSeq->size)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}

	for (; i > 0; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[i] = d;
	pSeq->size++;
}

//尾插
void BackPushSeqList(pSeqList pSeq, DataType d)
{
	assert(pSeq != NULL);

	if (MAX == pSeq->size)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}

	pSeq->data[pSeq->size] = d;
	pSeq->size++;
}

//头删
void FrontPopSeqList(pSeqList pSeq)
{

	int i = 0;
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("顺序表为空，无可删除的数据\n");
		return;
	}

	for (i = 0; i < pSeq->size-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}

	pSeq->size--;
}

//尾删
void BackPopSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}

	pSeq->size--;
}

//查找指定元素
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

//指定位置插入
void InsertSeqList(pSeqList pSeq, int pos, DataType d)
{
	int i = pSeq->size;

	assert(pSeq != NULL);

	if (pos < 0 || pos >= pSeq->size)
	{
		printf("位置错误\n");
		return;
	}

	for (; i > pos; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[i] = d;
	pSeq->size++;
}

//删除指定位置元素
void EraseData(pSeqList pSeq, int pos)
{
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}
	if ((pos < 0) || (pos >= pSeq->size))
	{
		printf("指定位置错误\n");
		return;
	}

	for (; pos < pSeq->size; pos++)
	{
		pSeq->data[pos] = pSeq->data[pos + 1];
	}
	pSeq->size--;
}

//删除指定元素
void RemoveData_1(pSeqList pSeq, DataType d)
{
	int i = 0;
	int j = 0;

	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		printf("顺序表为空，无可删除数据\n");
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
		printf("顺序表为空，无可删除数据\n");
		return;
	}

	i = FindData(pSeq, d);
	if (i == -1)
	{
		printf("顺序表无指定元素\n");
		return;
	}
	else
	{
		EraseData(pSeq, i);
	}
}
//删除所有指定元素

//void RemoveAllData(pSeqList pSeq, DataType d)
//{
//	int i = 0;
//
//	assert(pSeq != NULL);
//
//	if (0 == pSeq->size)
//	{
//		printf("顺序表为空，无可删除的数据\n");
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

//判断是否为空
int EmptySeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	if (0 == pSeq->size)
	{
		return 0;
	}
	return 1;
}

//打印
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