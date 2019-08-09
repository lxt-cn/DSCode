#pragma once

#include "Queue.h"
#include "Stack.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

һ��ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�临�Ӷ�ΪO(1)��

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

����Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ������(1,2,3,4,5)����ջ����Ϊ (4,5,3,2,1) ��

*/

int IsLegalStackOrder(int* in, int insize, int* out, int outsize);
void TestIsLegalStackOrder();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

����һ������ʵ������ջ(����ջ)

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

