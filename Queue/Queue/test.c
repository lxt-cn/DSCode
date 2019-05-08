#include "Queue.h"

void test()
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

int main()
{
	test();
	return 0;
}