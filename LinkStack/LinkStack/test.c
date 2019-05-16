#include "LinkStack.h"

void test()
{
	LinkStack ls;
	LinkStackInit(&ls);

	LinkStackPush(&ls, 1);
	LinkStackPush(&ls, 2);
	LinkStackPush(&ls, 3);
	LinkStackPush(&ls, 4);
	LinkStackPush(&ls, 5);

	printf("size = %d\n", LinkStackSize(&ls));

	while (LinkStackEmpty(&ls))
	{
		printf("%d ", LinkStackTop(&ls));
		LinkStackPop(&ls);
	}
	printf("\n");

	LinkStackDestory(&ls);
}

int main()
{
	test();
	return 0;
}