#pragma once

#include "Queue.h"
#include "Stack.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

一、实现一个栈，要求实现Push(入栈)、Pop(出栈)、Min(返回最小值)的时间复杂度为O(1)。

*/

typedef int MSTDataType;

typedef struct MinStack
{
	Stack _st;
	Stack _minst;

}MinStack;

void MinStackInit(MinStack* pms);
void MinStackDestory(MinStack* pms);

void MinStackPush(MinStack* pms, MSTDataType d);
void MinStackPop(MinStack* pms);
MSTDataType MinStackMin(MinStack* pms);

void TestMinStack();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

二、元素出栈、入栈顺序的合法性。如入栈的序列(1,2,3,4,5)，出栈序列为 (4,5,3,2,1) 。

*/

int IsLegalStackOrder(int* in, int insize, int* out, int outsize);
void TestIsLegalStackOrder();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

三、一个数组实现两个栈(共享栈)

*/

#define N 100

typedef int SSDataType;
typedef struct ShareStack
{
	SSDataType _a[N];
	int _top1;
	int _top2;
}ShareStack;

void StareStackInit(ShareStack* pss);
void ShareStackPush(ShareStack* pss, SSDataType d, int which);
void ShareStackPop(ShareStack* pss, int which);
SSDataType ShareStackTop(ShareStack* pss, int which);

void TestShareStack();

