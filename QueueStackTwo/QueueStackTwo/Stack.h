#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	int _top;        
	int _capacity;     
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, DataType d);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void Print(Stack* ps);

void TestStack();

#endif // __STACK_H__