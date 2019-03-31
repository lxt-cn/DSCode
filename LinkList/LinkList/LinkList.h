#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

void InitList(pList* pplist);
pNode BuyNode(DataType d);
void PushBack(pList* pplist,DataType d);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pNode Find(pList plist, DataType d);
void Insert(pList* pplist,pNode pos, DataType d);
void Erase(pList* pplist, pNode pos);
void Remove_1(pList* pplist, DataType d);
void Remove_2(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void PrintList(pList plist);
void DestroyList(pList* pplist);
int GetListLength(pList plist);



#endif //__LINKLIST_H__