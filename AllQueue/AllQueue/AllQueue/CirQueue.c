#include "CirQueue.h"

void CirQueueInit(CirQueue* pcq)
{
	pcq->data = (DataType*)malloc(sizeof(DataType)*maxSize);
	assert(pcq->data);

	pcq->front = 0;
	pcq->rear = 0;
}

void CirQueueDestory(CirQueue* pcq)
{
	free(pcq->data);
	pcq->data = NULL;
}

void CirQueuePush(CirQueue* pcq, DataType d)
{
	if (CirQueueFull(pcq))
	{
		printf("队列已满，无法入队数据\n");
	}
	else
	{
		pcq->data[pcq->rear + 1] = d;
		pcq->rear = (pcq->rear + 1) % maxSize;
	}
}

void CirQueuePop(CirQueue* pcq)
{
	if (!CirQueueEmpty(pcq))
	{
		printf("队列为空，无可出队数据\n");
	}
	else
	{
		pcq->front = (pcq->front + 1) % maxSize;
	}
}

DataType CirQueueFront(CirQueue* pcq)
{
	assert(pcq);

	return pcq->data[(pcq->front + 1) % maxSize];
}

int CirQueueFull(CirQueue* pcq)
{
	assert(pcq);
	return pcq->front == (pcq->rear + 1) % maxSize ? 1 : 0;	// 满 1  不满 0
}

int CirQueueEmpty(CirQueue* pcq)
{
	assert(pcq);
	return (pcq->front == pcq->rear) ? 0 : 1;	// 空 0  非空 1
}

int CirQueueSize(CirQueue* pcq)
{
	if (CirQueueFull(pcq))
	{
		return maxSize - 1;
	}
	return pcq->rear - pcq->front > 0 ? pcq->rear - pcq->front : pcq->front - pcq->rear;
}
