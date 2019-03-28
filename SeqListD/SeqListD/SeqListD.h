#ifndef __SEQLISTD_H__
#define __SEQLISTD_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

#define DEFAULT_SZ 3
typedef int DataType;

typedef struct SeqList
{
	DataType* data;
	int size;
	int capacity;
}SeqList, *pSeqList;


void InitSeqList(pSeqList pSeq);
void DeatroySeqList(pSeqList pSeq);
void PushBack(pSeqList pSeq, DataType d);
void PopBack(pSeqList pSeq);
void PopBack(pSeqList pSeq);
void Insert(pSeqList pSeq, int pos, DataType d);
void Erase(pSeqList pSeq, int pos);
int Capacity(pSeqList pSeq);
int Size(pSeqList pSeq);
void CheckCapacity(pSeqList pSeq);
void PrintSeqList(pSeqList pSeq);
 


#endif //__SEQLISTD_H__