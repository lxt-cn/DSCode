#ifndef __LINKLISTM_H__
#define __LINKLISTM_H__

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
void PushBack(pList* pplist, DataType d);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pNode Find(pList plist, DataType d);
void Insert(pList* pplist, pNode pos, DataType d);
void Erase(pList* pplist, pNode pos);
void Remove_1(pList* pplist, DataType d);
void Remove_2(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void PrintList(pList plist);
void DestroyList(pList* pplist);
int GetListLength(pList plist);

//------------链表面试题------------------------------------------

//1、比较顺序表和链表的优缺点
//   说说它们分别再什么场景下使用？
// 答：（1）、顺序表支持随机访问，单链表不支持随机访问
//     （2）、顺序表的插入/删除效率低，时间复杂度为O(N),除尾插尾删；
//            单链表的插入/删除效率高，时间复杂度为O(1)；
//     （3）、顺序表的CPU高效缓存效率更高，单链表的CPU高效缓存效率低


//2、从尾到头打印单链表(逆序)
void PrintTailToHead_R(pList plist);   //递归
void PrintTailToHead(pList plist);   //非递归
//3、删除一个无头单链表的非尾节点（不能遍历链表）
void DelNodeNotTail(pNode pos);
//4、在无头单链表的一个节点前插入一个节点（不能遍历链表）
void InsertNode(pNode pos, DataType d);
//5、单链表实现约瑟夫环(JosephCircle)
void JosephusCycle(pList* pplist, int k);
//6、逆置 / 反转单链表
void ReverseList_1(pList* pplist);
void ReverseList_2(pList* pplist);
//7、单链表排序（冒泡排序）
void BubbleSortList(pList plist);
//8、合并两个有序链表, 合并后依然有序
pList Merge(pList pplist1, pList pplist2);


#endif //__LINKLISTM_H__