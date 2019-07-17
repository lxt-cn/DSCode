#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;

typedef struct LinkQueueNode
{
	DataType _data;
	struct LinkQueueNode* _next;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* _front;
	LinkQueueNode* _rear;
}LinkQueue;

void LinkQueueInit(LinkQueue* plq);
void LinkQueueDestory(LinkQueue* plq);
void LinkQueuePush(LinkQueue* plq, DataType d);
void LinkQueuePop(LinkQueue* plq);
DataType LinkQueueFront(LinkQueue* plq);
int LinkQueueEmpty(LinkQueue* plq);
int LinkQueueSize(LinkQueue* plq);
