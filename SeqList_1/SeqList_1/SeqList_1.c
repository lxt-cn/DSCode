#include "SeqList_1.h"

void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	memset(pSeq->data, 0, sizeof(pSeq->data));
	pSeq->size = 0;
}

void PushBack(pSeqList pSeq, DataType d)
{
	//1、assert
	assert(pSeq != NULL);

	//2、判断满
	if (pSeq->size == MAX)
	{
		printf("顺序表已满，无法插入数据\n");
		return;
	}

	//3、存储数据
	pSeq->data[pSeq->size] = d;
	pSeq->size++;
}

void PopBack(pSeqList pSeq)
{
	//1、assert
	assert(pSeq != NULL);

	//2、已经为空的判断
	if (pSeq->size == 0)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}

	//3、删除数据
	pSeq->size--;
}

void PushFront(pSeqList pSeq, DataType d)
{
	int i = 0;

	//1、断言
	assert(pSeq != NULL);

	//2、判断满
	if (pSeq->size == MAX)
	{
		printf("顺序表已满，无法插入数据\n");
		return;
	}

	//3、插入数据
	for (i = pSeq->size; i > 0; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	//
	pSeq->data[0] = d;
	pSeq->size++;

}

void PopFront(pSeqList pSeq)
{
	int i = 0;

	assert(pSeq != NULL);

	if (pSeq->size == 0)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}

	for (i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}

int Find(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

void Insert(pSeqList pSeq, int pos, DataType d)
{
	int i = 0;

	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size);

	if (pSeq->size == MAX)
	{
		printf("顺序表已满，无法插入数据\n");
		return;
	}

	for (i = pSeq->size; i > pos; i--)
	{
		pSeq->data[i] = pSeq->data[i - 1];
	}
	pSeq->data[pos] = d;
	pSeq->size++;
}


void Erase(pSeqList pSeq, int pos)
{
	int i = 0;

	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->size);

	if (pSeq->size == 0)
	{
		printf("顺序表为空，无法删除数据\n");
		return;
	}

	for (i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}

void Remove(pSeqList pSeq, DataType d)
{
	int i = 0;
	int pos = 0;

	assert(pSeq != NULL);

	if (pSeq->size == 0)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}

	if ((pos = Find(pSeq, d)) != -1)
	{
		Erase(pSeq, pos);
	}
	else
	{
		printf("删除的元素不存在\n");
	}
#if 0
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			break;
		}
	}
	if (i == pSeq->size)
	{
		printf("删除的元素不存在\n");
		return;
	}

	for (; i < pSeq->size - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
#endif
}

void RemoveAll(pSeqList pSeq, DataType d)
{
	int pos = 0;
	int i = 0;
	int count = 0;
	DataType* tmp = NULL;

	assert(pSeq != NULL);

	if (pSeq->size == 0)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}

#if 0
	//RemoveAll_1
	while ((pos = Find(pSeq, d)) != -1)
	{
		Erase(pSeq, pos);
	}
#endif

#if 0
	//RemoveAll_2
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			int j = 0;
			for (j = i; j < pSeq->size; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->size--;
			--i;
		}
	}
#endif

#if 0
	//RemoveAll_3
	tmp = (DataType*)malloc(sizeof(DataType)*pSeq->size);

	assert(pSeq != NULL);

	if (pSeq->size == 0)
	{
		printf("顺序表为空，无可删除数据\n");
		return;
	}

	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] != d)
		{
			tmp[count++] = pSeq->data[i];
		}
	}
	memcpy(pSeq->data, tmp, count * sizeof(DataType));
	pSeq->size = count;
	free(tmp);
	tmp = NULL;
#endif

#if 1
	//RemoveAll_4
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->size = count;
#endif
}

int Size(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->size;
}

int Empty(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->size == 0;
}

void Swap(DataType* p1, DataType* p2)
{
	DataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BubbleSort(pSeqList pSeq)
{
	int i = 0;   //控制循环趟数
   	int j = 0;   //控制每趟循环次数
	int flag = 0;

	assert(pSeq != NULL);

	for (i = 0; i < pSeq->size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < pSeq->size - i - 1; j++)
		{
			if (pSeq->data[j] > pSeq->data[j + 1])
			{
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

void SelectSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;

	assert(pSeq != NULL);

	for (i = 0; i < pSeq->size-1; i++)
	{
		int max = 0;
		for (j = 1; j < pSeq->size-i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}
		//max最大元素的下标
		if (max != pSeq->size - 1 - i)
		{
			Swap(pSeq->data + max, pSeq->data + pSeq->size - 1 - i);
		}
	}
}

void SelectSort_OP(pSeqList pSeq)
{
	int start = 0;
	int end = pSeq->size - 1;

	assert(pSeq != NULL);

	while (start < end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[i] > pSeq->data[max])
			{
				max = i;
			}
			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}
		if (min != start)
		{
			Swap(pSeq->data + start, pSeq->data + min);
		}
		if (max == start)
		{
			max = min;
		}
		if (max != end)
		{
			Swap(pSeq->data + end, pSeq->data + max);
		}
		start++;
		end--;
	}
}

int BinarySearch(pSeqList pSeq, DataType d)
{
	int left = 0;
	int right = pSeq->size - 1;

	assert(pSeq != NULL);

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] > d)
		{
			right = mid - 1;
		}
		else if (pSeq->data[mid] < d)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d)
{
	int mid = 0;

	assert(pSeq != NULL);
	
	if (left > right)
	{
		return -1;
	}
	mid = left + (right - left) / 2;

	if (pSeq->data[mid] > d)
	{
		return BinarySearch_R(pSeq, left, mid - 1, d);
	}
	else if (pSeq->data[mid] < d)
	{
		return BinarySearch_R(pSeq, mid + 1, right, d);
	}
	else
	{
		return mid;
	}
	return -1;
}

void PrintSeqList(pSeqList pSeq)
{
	int i = 0;

	assert(pSeq != NULL);

	if (pSeq->size == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}