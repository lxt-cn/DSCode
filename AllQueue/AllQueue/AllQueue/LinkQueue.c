#include "LinkQueue.h"

void LinkQueueInit(LinkQueue* plq)
{
	assert(plq);

	plq->_front = NULL;
	plq->_rear = NULL;
}

void LinkQueueDestory(LinkQueue* plq)
{
	LinkQueueNode* cur = plq->_front;

	assert(plq);

	while (cur != NULL)
	{
		LinkQueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plq->_front = NULL;
	plq->_rear = NULL;
}

static LinkQueueNode* BuyQueueNode(DataType d)
{
	LinkQueueNode* newNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(newNode);

	newNode->_data = d;
	newNode->_next = NULL;
	return newNode;
}

void LinkQueuePush(LinkQueue* plq, DataType d)
{
	assert(plq);

	if (plq->_front == NULL)
	{
		plq->_front = plq->_rear = BuyQueueNode(d);
	}
	else
	{
		LinkQueueNode* back = BuyQueueNode(d);
		plq->_rear->_next = back;
		plq->_rear = back;
	}
}

void LinkQueuePop(LinkQueue* plq)
{
	LinkQueueNode* next = NULL;

	assert(plq);

	next = plq->_front->_next;

	free(plq->_front);
	plq->_front = next;
}

DataType LinkQueueFront(LinkQueue* plq)
{
	assert(plq);

	return plq->_front->_data;
}

int LinkQueueEmpty(LinkQueue* plq)
{
	assert(plq);

	return plq->_front == NULL ? 0 : 1;  //¿Õ 0   ·Ç¿Õ 1
}

int LinkQueueSize(LinkQueue* plq)
{
	int size = 0;
	LinkQueueNode* cur = NULL;

	assert(plq);

	cur = plq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}