#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct BinaryTreeNode;
typedef struct BinaryTreeNode* QUDataType;

typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _back;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QUDataType d);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

