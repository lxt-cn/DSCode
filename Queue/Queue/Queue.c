#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_front = NULL;
	pq->_back = NULL;
}

void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->_front;

	assert(pq);

	while (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = NULL;
	pq->_back = NULL;
}

static QueueNode* BuyQueueNode(DataType d)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	
	newNode->_data = d;
	newNode->_next = NULL;
	return newNode;
}

void QueuePush(Queue* pq, DataType d)
{
	assert(pq);

	if (pq->_back == NULL)
	{
		pq->_front = pq->_back = BuyQueueNode(d);
	}
	else
	{
		QueueNode* back = BuyQueueNode(d);
		pq->_back->_next = back;
		pq->_back = back;
	}
}

void QueuePop(Queue* pq)
{
	QueueNode* next = NULL;
	
	assert(pq);

	next = pq->_front->_next;

	free(pq->_front);
	pq->_front = next;
}

DataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->_front->_data;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->_front == NULL ? 0 : 1;  //¿Õ 0   ·Ç¿Õ 1
}

int QueueSize(Queue* pq)
{
	int size = 0;
	QueueNode* cur = NULL;

	assert(pq);

	cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
