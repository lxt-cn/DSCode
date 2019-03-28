#include "SeqListD.h"

void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	pSeq->data = (DataType*)malloc(DEFAULT_SZ * sizeof(DataType));
	if (pSeq->data == NULL)
	{
		perror("use malloc");
		exit(EXIT_FAILURE);
	}
	pSeq->size = 0;
	pSeq->capacity = DEFAULT_SZ;
}

void DeatroySeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);

	free(pSeq->data);
	pSeq->data = NULL;
	pSeq->size = 0;
	pSeq->capacity = 0;
}

void CheckCapacity(pSeqList pSeq)
{
	assert(pSeq != NULL);

	if (pSeq->size == pSeq->capacity)
	{
		DataType* tmp = (DataType*)realloc(pSeq->data, (pSeq->capacity + 2) * sizeof(DataType));
		if (tmp != NULL)
		{
			pSeq->data = tmp;
		}
		pSeq->capacity += 2;
	}

}

void PushBack(pSeqList pSeq, DataType d)
{
	assert(pSeq != NULL);

	CheckCapacity(pSeq);

	pSeq->data[pSeq->size] = d;
	pSeq->size++;
}

int Empty(pSeqList pSeq)
{
	return pSeq->size == 0;
}

void PopBack(pSeqList pSeq)
{
	assert(pSeq != NULL);

	if (Empty(pSeq))
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	pSeq->size--;
}

void Insert(pSeqList pSeq, int pos, DataType d)
{
	int i = 0;

	assert(pSeq != NULL);

	CheckCapacity(pSeq);

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

	if (Empty(pSeq))
	{
		printf("顺序表为空，无法删除\n");
		return;
	}

	for (i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}

int Capacity(pSeqList pSeq)
{
	assert(pSeq != NULL);

	return pSeq->capacity;
}

int Size(pSeqList pSeq)
{
	assert(pSeq != NULL);

	return pSeq->size;
}

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
