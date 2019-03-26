#ifndef __SEQLIST_1_H__
#define __SEQLIST_1_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100

typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int size;
}SeqList, *pSeqList;


void InitSeqList(pSeqList pSeq);
void PushBack(pSeqList pSeq, DataType d);
void PopBack(pSeqList pSeq);
void PushFront(pSeqList pSeq, DataType d);
void PopFront(pSeqList pSeq);
int Find(pSeqList pSeq, DataType d);
void Insert(pSeqList pSeq, int pos, DataType d);
void Erase(pSeqList pSeq, int pos);
void Remove(pSeqList pSeq, DataType d);
void RemoveAll(pSeqList pSeq, DataType d);
int Size(pSeqList pSeq);
int Empty(pSeqList pSeq);
void BubbleSort(pSeqList pSeq);
void SelectSort(pSeqList pSeq);
void SelectSort_OP(pSeqList pSeq);
int BinarySearch(pSeqList pSeq, DataType d);
int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);
void PrintSeqList(pSeqList pSeq);


#endif //__SEQLIST_1_H__