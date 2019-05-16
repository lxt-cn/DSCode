#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _next;
}Node;

typedef struct LinkStack
{
	Node* _top;   //Õ»¶¥Ö¸Õë
	int _nCount; //¸öÊý
}LinkStack;

void LinkStackInit(LinkStack* pls);
void LinkStackDestory(LinkStack* pls);
void LinkStackPush(LinkStack* pls, DataType d);
void LinkStackPop(LinkStack* pls);
DataType LinkStackTop(LinkStack* pls);
int LinkStackEmpty(LinkStack* pls);
int LinkStackSize(LinkStack* pls);

#endif //__LINKSTACK_H__