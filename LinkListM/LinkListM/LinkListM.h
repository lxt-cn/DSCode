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
pList Merge_R(pList pplist1, pList pplist2);
//9、查找单链表的中间节点，要求只能遍历一次链表
pNode FindMidNode(pList plist);
//10、查找单链表的倒数第k个节点，要求只能遍历一次链表
pNode FindLastKNode(pList plist, int k);
//11、判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。
pNode IsCircle(pList plist);
int GetCircleLength(pNode meet);
pNode GetCirCleEntryNode(pList plist, pNode meet);
//12、判断两个链表是否相交，若相交，求交点。（假设链表不带环）
int CheckCross(pList plist1, pList plist2);
pNode GetCrossMeetNode(pList plist1, pList plist2);
//13、判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
int CheckCrossWithCircle(pList plist, pList plist2);
void GetCrossMeetNodeWithCircle(pList plist1, pList plist2);
//14、求两个有序单链表中的交集。
void UnionSet(pList plist1, pList plist2);
//15、复杂链表的复制。一个链表的每个节点，有一个指向next指针指向
//    下一个节点，还有一个random指针指向这个链表中的一个随机节点
//    或者NULL，现在要求实现复制这个链表，返回复制后的新链表。
typedef struct ComplexNode
{  
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;
ComplexNode* BuyComplexNode(DataType d);
void PrintComplexList(ComplexNode* plist);
ComplexNode* CopyComplexList(ComplexNode* plist);

#endif //__LINKLIx bSTM_H__