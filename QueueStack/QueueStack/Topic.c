#include "Topic.h"

//###############################################
//1、两个栈实现一个队列
void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	StackInit(&(qts->s1));
	StackInit(&(qts->s2));
}

void QueueByTwoStackDestory(QueueByTwoStack* qts)
{
	StackDestory(&(qts->s1));
	StackDestory(&(qts->s2));
}

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType d)
{
	assert(qts);

	StackPush(&(qts->s1), d);
}

void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);

	//1、如果s2有数据，则直接出
	//2、如果s2没有数据，则将s1的数据倒过来，再出
	if (StackEmpty(&(qts->s2)) == 0)
	{
		while (StackEmpty(&(qts->s1)))
		{
			StackPush(&(qts->s2), StackTop(&(qts->s1)));
			StackPop(&(qts->s1));
		}
	}
	StackPop(&(qts->s2));
}

DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	if (StackEmpty(&(qts->s2)) == 0)
	{
		while (StackEmpty(&(qts->s1)))
		{
			StackPush(&(qts->s2), StackTop(&(qts->s1)));
			StackPop(&(qts->s1));
		}
	}
	return StackTop(&(qts->s2));
}

int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	return StackSize(&(qts->s1)) + StackSize(&(qts->s2));
}

int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	return StackEmpty(&(qts->s1)) | StackEmpty(&(qts->s2));
}

void TestQueueByTwoStack()
{
	QueueByTwoStack qts;
	QueueByTwoStackInit(&qts);

	QueueByTwoStackPush(&qts, 1);
	QueueByTwoStackPush(&qts, 2);
	QueueByTwoStackPush(&qts, 3);
	QueueByTwoStackPush(&qts, 4);
	QueueByTwoStackPush(&qts, 5);

	while (QueueByTwoStackEmpty(&qts))
	{
		printf("%d ", QueueByTwoStackFront(&qts));
		QueueByTwoStackPop(&qts);
	}
	printf("\n");

	QueueByTwoStackDestory(&qts);
}

//########################################################


//########################################################
//2、两个队列实现一个栈
void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	QueueInit(&(stq->q1));
	QueueInit(&(stq->q2));
}

void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	QueueDestory(&(stq->q1));
	QueueDestory(&(stq->q2));
}

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType d)
{
	assert(stq);

	if (QueueEmpty(&(stq->q1)) != 0)
	{
		QueuePush(&(stq->q1), d);
	}
	else
	{
		QueuePush(&(stq->q2), d); 
	}
}

void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue* empty = NULL; 
	Queue* nonempty = NULL;

	assert(stq);

	empty = &(stq->q1);
	nonempty = &(stq->q2);
	if (QueueEmpty(&(stq->q1)) != 0)
	{
		empty = &(stq->q2);
		nonempty = &(stq->q1);
	}

	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}

	QueuePop(nonempty);
}

DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	if (QueueEmpty(&(stq->q1)))
	{
		return QueueBack(&(stq->q1));
	}
	else
	{
		return QueueBack(&(stq->q2));
	}
}

int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	return QueueSize(&(stq->q1)) + QueueSize(&(stq->q2));
}

int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	return QueueEmpty(&(stq->q1)) | QueueEmpty(&(stq->q2));
}

void TestStackByTwoQueue()
{
	StackByTwoQueue stq;
	StackByTwoQueueInit(&stq);

	StackByTwoQueuePush(&stq, 1);
	StackByTwoQueuePush(&stq, 2);
	StackByTwoQueuePush(&stq, 3);
	StackByTwoQueuePush(&stq, 4);
	StackByTwoQueuePush(&stq, 5);

	while (StackByTwoQueueEmpty(&stq))
	{
		printf("%d ", StackByTwoQueueTop(&stq));
		StackByTwoQueuePop(&stq);
	}
	printf("\n");

	StackByTwoQueueDestory(&stq);
}