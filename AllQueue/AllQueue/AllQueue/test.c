#pragma once
#include "LinkQueue.h"
#include "CirQueue.h"

void LinkQueueTest()
{
	LinkQueue lq;
	LinkQueueInit(&lq);
	LinkQueuePush(&lq, 1);
	LinkQueuePush(&lq, 2);
	LinkQueuePush(&lq, 3);
	LinkQueuePush(&lq, 4);
	LinkQueuePush(&lq, 5);

	while (LinkQueueEmpty(&lq))
	{
		printf("Front = %d\n", LinkQueueFront(&lq));
		printf("size = %d\n", LinkQueueSize(&lq));
		LinkQueuePop(&lq);
	}

	LinkQueueDestory(&lq);
}

void CirQueueTest()
{
	CirQueue cq;
	CirQueueInit(&cq);
	CirQueuePush(&cq, 1);
	CirQueuePush(&cq, 2);
	CirQueuePush(&cq, 3);
	CirQueuePush(&cq, 4);
	CirQueuePush(&cq, 5);
	CirQueuePush(&cq, 6);

	while (CirQueueEmpty(&cq))
	{
		printf("Front = %d\n", CirQueueFront(&cq));
		printf("size = %d\n", CirQueueSize(&cq));
		CirQueuePop(&cq);
	}

	CirQueueDestory(&cq);
}

int main()
{
	//LinkQueueTest();
	CirQueueTest();
	return 0;
}