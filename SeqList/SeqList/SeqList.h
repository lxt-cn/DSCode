#ifndef __SeqList_H__
#define __SeqList_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int size;
}SeqList, *pSeqList;


void InitSeqList(pSeqList pSaq);
void FrontPushSeqList(pSeqList pSeq, DataType d);
void BackPushSeqList(pSeqList pSeq, DataType d);
void FrontPopSeqList(pSeqList pSeq);
void BackPopSeqList(pSeqList pSeq);
int FindData(pSeqList pSeq, DataType d);
void InsertSeqList(pSeqList pSeq, int pos, DataType d);
void EraseData(pSeqList pSeq, int pos);
void RemoveData_1(pSeqList pSeq, DataType d);
void RemoveData_2(pSeqList pSeq, DataType d);
void RemoveAllData(pSeqList pSeq, DataType d);
int EmptySeqList(pSeqList pSeq);
void PrintSeqList(pSeqList pSeq);


#endif // __SeqList_H__