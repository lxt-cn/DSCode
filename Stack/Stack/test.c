#include "Stack.h"

void test()
{
	Stack s;
	int ret = 0;

	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	Print(&s);

	StackPop(&s);
	StackPop(&s);
	Print(&s);

	printf("top = %d\n", StackTop(&s));

	ret = StackEmpty(&s);
	if (ret == 0)
	{
		printf("Õ»Îª¿Õ\n");
	}
	else
	{
		printf("Õ»·Ç¿Õ\n");
	}

	printf("size = %d\n", StackSize(&s));

	StackDestory(&s);
}

int main()
{
	test();
	return 0;
}