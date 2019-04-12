#include "LinkListM.h"

void InitList(pList* pplist)
{
	assert(pplist != NULL);

	*pplist = NULL;
}

pNode BuyNode(DataType d)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		perror("BuyNode::malooc");
		return NULL;
	}
	tmp->data = d;
	tmp->next = NULL;
	return tmp;
}

void PushBack(pList* pplist, DataType d)
{
	pNode newNode = BuyNode(d);

	assert(pplist != NULL);

	if (newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (*pplist == NULL)   //空链表
	{
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void PopBack(pList* pplist)
{
	assert(pplist != NULL);

	//链表为空，无可删除数据，直接返回
	if (*pplist == NULL)
	{
		return;
	}
	//只有一个结点
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//一个以上的结点
	else
	{
		pNode cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		//循环结束，cur指向倒数第二个结点，释放最后一个结点
		free(cur->next);
		cur->next = NULL;
	}
}

void PushFront(pList* pplist, DataType d)
{
	pNode newNode = BuyNode(d);

	assert(pplist != NULL);

	if (newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}

	newNode->next = *pplist;
	*pplist = newNode;
}

void PopFront(pList* pplist)
{
	assert(pplist != NULL);

	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		pNode del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
	}
}

pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode newNode = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);

	//第一个位置——>头插
	if (pos == *pplist)
	{
		newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while (cur && cur->next != pos)  //顺序不可以颠倒
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			newNode = BuyNode(d);
			newNode->next = pos;
			cur->next = newNode;
		}
	}
}

void Erase(pList* pplist, pNode pos)
{
	assert(pplist != NULL);
	assert(pos != NULL);

	if (*pplist == NULL)
	{
		return;
	}
	//第一个结点
	if (*pplist == pos)
	{
		//头删
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	//不是第一个结点
	else
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			cur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}

void Remove_1(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;

	assert(pplist != NULL);

	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			//是第一个结点
			if (*pplist == cur)
			{
				PopFront(pplist);
			}
			//非第一个结点
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void Remove_2(pList* pplist, DataType d)
{
	pNode pos = NULL;

	assert(pplist != NULL);

	pos = Find(*pplist, d);
	if (pos != NULL)
	{
		Erase(pplist, pos);
	}
}

void RemoveAll(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;

	assert(pplist != NULL);

	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			//是第一个结点
			if (*pplist == cur)
			{
				PopFront(pplist);
				cur = *pplist;
			}
			//非第一个结点
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void PrintList(pList plist)
{
	pNode cur = plist;

	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}

void DestroyList(pList* pplist)
{
	pNode cur = *pplist;
	assert(pplist != NULL);

	while (cur != NULL)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}

int GetListLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//--------------------------链表面试题-----------------------------------------------

void PrintTailToHead_R(pList plist)
{
	if (plist == NULL)
	{
		return;
	}
	PrintTailToHead(plist->next);
	printf("%d-->", plist->data);
}

void PrintTailToHead(pList plist)
{
	pNode cur = plist;
	pNode tail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if (plist->next == NULL)
	{
		printf("%d\n", plist->data);
		return;
	}
	while (plist != tail)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d-->", cur->data);
		tail = cur;
	}
}

void DelNodeNotTail(pNode pos)
{
	pNode del = NULL;
	assert(pos != NULL);
	assert(pos->next != NULL);

	//替换删除法
	del = pos->next;
	//移动数据
	pos->data = pos->next->data;
	//删除下一个结点
	pos->next = del->next;
	free(del);
	del = NULL;
}

void InsertNode(pNode pos, DataType d)
{
	pNode newNode = NULL;
	DataType tmp = 0;
	assert(pos != NULL);

#if 1    //方法一
	newNode = BuyNode(d);
	newNode->next = pos->next;
	pos->next = newNode;
	//交换结点值
	tmp = pos->data;
	pos->data = newNode->data;
	newNode->data = tmp;
#endif

#if 0     //方法二
	newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;
	//赋值
	pos->data = d;
#endif
}

void JosephusCycle(pList* pplist, int k)
{
	pNode cur = *pplist;

	assert(pplist != NULL);

	while (cur != cur->next)
	{
		int count = k;
		pNode del = NULL;
		while (--count)
		{
			cur = cur->next;
		}
		printf("删除：%d\n", cur->data);
		//替换删除法
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("幸存者：%d\n", cur->data);
}

void ReverseList_1(pList* pplist)
{
	pNode n1 = NULL;
	pNode n2 = NULL; 
	pNode n3 = NULL;

	assert(pplist != NULL);

	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		return;
	}
	n1 = *pplist;
	n2 = n1->next;
	n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	(*pplist)->next = NULL;
	*pplist = n1;
}

void ReverseList_2(pList* pplist)
{
	pNode head = NULL;
	pNode cur = NULL;
	pNode tmp = NULL;
	assert(pplist != NULL);

	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next == NULL)
	{
		return;
	}

	cur = *pplist;
	tmp = cur->next;
	while(cur)
	{
		//头插
		cur->next = head;
		head = cur;
		cur = tmp;

		if (tmp != NULL)
		{
			tmp = tmp->next;
		}
	}
	*pplist = head;
}

void BubbleSortList(pList plist)
{
	pNode tail = NULL;
	//空链表或者有一个结点
	if ((plist == NULL) || (plist->next == NULL))
	{
		return;
	}
	while (plist != tail)   //趟数
	{
		pNode cur = plist;
		pNode next = cur->next;
		while (next != tail)
		{
			if (cur->data > next->data)
			{
				DataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
			}
			cur = next;
			next = cur->next;
		}
		tail = cur;
	}
}

pList Merge(pList pplist1, pList pplist2)
{
	pList pplist = NULL;
	pNode tail = NULL;
	//同时为空
	if (pplist1 == pplist2)
	{
		return NULL;
	}
	//pplist1为空，pplist2非空
	if (pplist1 == NULL)
	{
		return pplist2;
	}
	//pplist2为空,pplist1非空
	if (pplist2 == NULL)
	{
		return pplist1;
	}
	//都不为空
	if (pplist1->data < pplist2->data)
	{
		pplist = pplist1;
		pplist1 = pplist1->next;
	}
	else
	{
		pplist = pplist2;
		pplist2 = pplist2->next;
	}
	//两条链表中找较小的元素尾插
	tail = pplist;
	while ((pplist1 != NULL) && (pplist2) != NULL)
	{
		if (pplist1->data < pplist2->data)
		{
			tail->next = pplist1;
			pplist1 = pplist1->next;
		}
		else
		{
			tail->next = pplist2;
			pplist2 = pplist2->next;
		}
		tail = tail->next;
	}
	//追加剩余的元素
	if (pplist1 == NULL)
	{
		tail->next = pplist2;
	}
	else if (pplist2 == NULL)
	{
		tail->next = NULL;
	}
	return pplist;
}