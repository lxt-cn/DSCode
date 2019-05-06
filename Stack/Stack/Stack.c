#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType) * 3);
	assert(ps->_a);   //ÅÐ¶ÏÉêÇë¿Õ¼äÊÇ·ñ³É¹¦

	ps->_top = 0;
	ps->_capacity = 3;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}
}

void StackPush(Stack* ps, DataType d)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		ps->_a = (DataType*)realloc(ps->_a, sizeof(DataType)*(ps->_capacity) * 2);
		assert(ps->_a);
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = d;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);

	ps->_top--;
}

DataType StackTop(Stack* ps)
{
	assert(ps->_a&&ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;  //¿Õ 0  ·Ç¿Õ 1
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

void Print(Stack* ps)
{
	int i = 0;
	for (i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}