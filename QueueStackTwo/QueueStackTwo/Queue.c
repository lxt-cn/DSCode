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

	if (next == NULL)
	{
		pq->_back = NULL;
	}
}

DataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->_front->_data;
}

DataType QueueBack(Queue* pq)
{
	return pq->_back->_data;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->_front == NULL ? 0 : 1; 
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

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (QueueEmpty(&q))
	{
		printf("Front = %d\n", QueueFront(&q));
		printf("size = %d\n", QueueSize(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}