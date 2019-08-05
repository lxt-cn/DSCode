#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>


typedef struct Pos
{
	int _row;
	int _col;
}Pos;

typedef Pos STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType d);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void Print(Stack* ps);