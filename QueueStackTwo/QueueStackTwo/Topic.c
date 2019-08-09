#include "Topic.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 一
void MinStackInit(MinStack* pms)
{
	assert(pms);
	StackInit(&pms->_st);
	StackInit(&pms->_minst);
}

void MinStackDestory(MinStack* pms)
{
	assert(pms);
	StackDestory(&pms->_st);
	StackDestory(&pms->_minst);
}

void MinStackPush(MinStack* pms, MSTDataType d)
{
	assert(pms);

	StackPush(&pms->_st, d);
	if (StackEmpty(&pms->_minst) == 0
		|| StackTop(&pms->_minst) >= d)
	{
		StackPush(&pms->_minst, d);
	}
}

void MinStackPop(MinStack* pms)
{
	assert(pms);

	if (StackTop(&pms->_st) == StackTop(&pms->_minst))
	{
		StackPop(&pms->_minst);
	}
	StackPop(&pms->_st);
}

MSTDataType MinStackMin(MinStack* pms)
{
	assert(pms);

	return StackTop(&pms->_minst);
}

void TestMinStack()
{
	MinStack mst;
	MinStackInit(&mst);
	MinStackPush(&mst, 1);
	MinStackPush(&mst, 4);
	MinStackPush(&mst, 0);
	MinStackPush(&mst, 0);
	MinStackPush(&mst, 5);
	MinStackPush(&mst, 0);

	printf("min = %d\n", MinStackMin(&mst));
	MinStackPop(&mst);

	printf("min = %d\n", MinStackMin(&mst));
	MinStackPop(&mst);

	printf("min = %d\n", MinStackMin(&mst));
	MinStackPop(&mst);

	printf("min = %d\n", MinStackMin(&mst));
	MinStackPop(&mst);

	printf("min = %d\n", MinStackMin(&mst));
	MinStackPop(&mst);

	printf("min = %d\n", MinStackMin(&mst));
	MinStackPop(&mst);

	MinStackDestory(&mst);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 二
// 不是合法 0
// 合法 1
int IsLegalStackOrder(int* in, int insize, int* out, int outsize)
{
	assert(in && out && insize == outsize);

	Stack st;
	StackInit(&st);

	int inindex = 0;
	int outindex = 0;
	while (inindex < insize)
	{
		StackPush(&st, in[inindex]);
		++inindex;

		while (StackEmpty(&st)
			&& StackTop(&st) == out[outindex])
		{
			StackPop(&st);
			++outindex;
		}
	}

	if (StackEmpty(&st) == 0)
	{
		StackDestory(&st);
		return 1;
	}
	StackDestory(&st);
	return 0;
}

void TestIsLegalStackOrder()
{
	int in[5] = { 1,2,3,4,5 };
	int out1[5] = { 4,5,3,2,1 };
	int out2[5] = { 4,5,2,3,1 };

	printf("%d\n", IsLegalStackOrder(in, 5, out1, 5));	// 1
	printf("%d\n", IsLegalStackOrder(in, 5, out2, 5));	// 0

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 三
// 奇偶栈
void ShareStackInit(ShareStack* pss)
{
	assert(pss);

	pss->_top1 = 0;
	pss->_top2 = 1;
}

void ShareStackPush(ShareStack* pss, SSDataType d, int which)
{
	assert(pss && which == 1 || which == 2);

	if (which == 1)
	{
		if (pss->_top1 >= N)
		{
			printf("Stack1 Full\n");
			return;
		}
		pss->_a[pss->_top1] = d;
		pss->_top1 += 2;
	}
	else if (which == 2)
	{
		if (pss->_top2 >= N)
		{
			printf("Stack2 Full\n");
			return;
		}
		pss->_a[pss->_top2] = d;
		pss->_top2 += 2;
	}
	else
	{
		printf("StackPush Error\n");
		return;
	}
}

void ShareStackPop(ShareStack* pss, int which)
{
	assert(pss && which == 1 || which == 2);

	if (which == 1)
	{
		if (pss->_top1 == 0)
		{
			printf("Stack1 Empty\n");
			return;
		}
		pss->_top1 -= 2;
	}
	else if (which == 2)
	{
		if (pss->_top2 == 1)
		{
			printf("Stack2 Empty\n");
			return;
		}
		pss->_top2 -= 2;
	}
	else
	{
		printf("StackPop Error\n");
		return;
	}

}

SSDataType ShareStackTop(ShareStack* pss, int which)
{
	assert(pss && which == 1 || which == 2);

	if (which == 1)
	{
		if (pss->_top1 == 0)
		{
			printf("Stack1 Empty\n");
			return -1;
		}
		return pss->_a[pss->_top1 - 2];
	}
	else if (which == 2)
	{
		if (pss->_top2 == 1)
		{
			printf("Stack2 Empty\n");
			return -1;
		}
		return pss->_a[pss->_top2 - 2];
	}
	else
	{
		printf("Get StackTop Error\n");
		return -1;
	}
}
void TestShareStack()
{
	ShareStack ss;
	int i = 0;
	ShareStackInit(&ss);

	ShareStackPush(&ss, 1, 1);
	ShareStackPush(&ss, 2, 1);
	ShareStackPush(&ss, 3, 1);
	ShareStackPush(&ss, 4, 1);
	ShareStackPush(&ss, 5, 1);

	ShareStackPush(&ss, 6, 2);
	ShareStackPush(&ss, 7, 2);
	ShareStackPush(&ss, 8, 2);
	ShareStackPush(&ss, 9, 2);
	ShareStackPush(&ss, 10, 2);

	// 1 6 2 7 3 8 4 9 5 10

	for (i = 0; i < 6; i++)
	{
		printf("Stack1Top: %d\n", ShareStackTop(&ss, 1));
		ShareStackPop(&ss, 1);
		printf("Stack2Top: %d\n", ShareStackTop(&ss, 2));
		ShareStackPop(&ss, 2);
	}

}
