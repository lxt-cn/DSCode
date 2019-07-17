#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

#define maxSize 6
typedef int DataType;

typedef struct CirQueue{
	DataType* data;
	int front;
	int rear;
}CirQueue;

void CirQueueInit(CirQueue* pcq);
void CirQueueDestory(CirQueue* pcq);
void CirQueuePush(CirQueue* pcq, DataType d);
void CirQueuePop(CirQueue* pcq);
DataType CirQueueFront(CirQueue* pcq);
int CirQueueFull(CirQueue* pcq);
int CirQueueEmpty(CirQueue* pcq);
int CirQueueSize(CirQueue* pcq);
