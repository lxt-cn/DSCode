#ifndef __DLIST_H__
#define __DLIST_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
	struct Node* prev;
}Node, *pNode, *pList;

pList InitList();
void DestoryList(pList plist);
pNode BuyNode(DataType d);
void PushBack(pList plist, DataType d);
void PushFront(pList plist, DataType d);
pNode FindList(pList plist, DataType d);
void InsertList(pNode pos, DataType d);
void PopBack(pList plist);
void PopFront(pList plist);
void EraseList(pNode pos);
void PrintList(pList plist);


#endif //__DLIST_H__