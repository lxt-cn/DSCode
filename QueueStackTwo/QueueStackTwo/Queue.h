#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;
typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;

}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _back;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, DataType d);
void QueuePop(Queue* pq);
DataType QueueFront(Queue* pq);
DataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void TestQueue();

#endif //__QUEUE_H__