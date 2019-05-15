#pragma once

#include "Queue.h"
#include "Stack.h"

//###########################################
//1������ջʵ��һ������
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts); 
void QueueByTwoStackDestory(QueueByTwoStack* qts);

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType d);
void QueueByTwoStackPop(QueueByTwoStack* qts);

DataType QueueByTwoStackFront(QueueByTwoStack* qts);
int QueueByTwoStackSize(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);

void TestQueueByTwoStack();

//###########################################


//###########################################
//2����������ʵ��һ��ջ

typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType d);
void StackByTwoQueuePop(StackByTwoQueue* stq);

DataType StackByTwoQueueTop(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);

void TestStackByTwoQueue();