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

	if (*pplist == NULL)   //������
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

	//����Ϊ�գ��޿�ɾ�����ݣ�ֱ�ӷ���
	if (*pplist == NULL)
	{
		return;
	}
	//ֻ��һ�����
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//һ�����ϵĽ��
	else
	{
		pNode cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		//ѭ��������curָ�����ڶ�����㣬�ͷ����һ�����
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

	//��һ��λ�á���>ͷ��
	if (pos == *pplist)
	{
		newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while (cur && cur->next != pos)  //˳�򲻿��Եߵ�
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
	//��һ�����
	if (*pplist == pos)
	{
		//ͷɾ
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	//���ǵ�һ�����
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
			//�ǵ�һ�����
			if (*pplist == cur)
			{
				PopFront(pplist);
			}
			//�ǵ�һ�����
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
			//�ǵ�һ�����
			if (*pplist == cur)
			{
				PopFront(pplist);
				cur = *pplist;
			}
			//�ǵ�һ�����
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

//--------------------------����������-----------------------------------------------

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

	//�滻ɾ����
	del = pos->next;
	//�ƶ�����
	pos->data = pos->next->data;
	//ɾ����һ�����
	pos->next = del->next;
	free(del);
	del = NULL;
}

void InsertNode(pNode pos, DataType d)
{
	pNode newNode = NULL;
	DataType tmp = 0;
	assert(pos != NULL);

#if 1    //����һ
	newNode = BuyNode(d);
	newNode->next = pos->next;
	pos->next = newNode;
	//�������ֵ
	tmp = pos->data;
	pos->data = newNode->data;
	newNode->data = tmp;
#endif

#if 0     //������
	newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;
	//��ֵ
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
		printf("ɾ����%d\n", cur->data);
		//�滻ɾ����
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("�Ҵ��ߣ�%d\n", cur->data);
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
		//ͷ��
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
	//�����������һ�����
	if ((plist == NULL) || (plist->next == NULL))
	{
		return;
	}
	while (plist != tail)   //����
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
	//ͬʱΪ��
	if (pplist1 == pplist2)
	{
		return NULL;
	}
	//pplist1Ϊ�գ�pplist2�ǿ�
	if (pplist1 == NULL)
	{
		return pplist2;
	}
	//pplist2Ϊ��,pplist1�ǿ�
	if (pplist2 == NULL)
	{
		return pplist1;
	}
	//����Ϊ��
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
	//�����������ҽ�С��Ԫ��β��
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
	//׷��ʣ���Ԫ��
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

pList Merge_R(pList pplist1, pList pplist2)
{
	pList pplist = NULL;
	pNode tail = NULL;
	//ͬʱΪ��
	if (pplist1 == pplist2)
	{
		return NULL;
	}
	//pplist1Ϊ�գ�pplist2�ǿ�
	if (pplist1 == NULL)
	{
		return pplist2;
	}
	//pplist2Ϊ��,pplist1�ǿ�
	if (pplist2 == NULL)
	{
		return pplist1;
	}

	if (pplist1->data < pplist2->data)
	{
		pplist = pplist1;
		pplist->next = Merge_R(pplist1->next, pplist2);
	}
	else
	{
		pplist = pplist2;
		pplist->next = Merge_R(pplist2->next, pplist1);
	}
	return pplist;
}

pNode FindMidNode(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;

	if ((plist == NULL) || (plist->next == NULL))
	{
		return plist;
	}

	while (fast && (fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

pNode FindLastKNode(pList plist, int k)
{
	pNode fast = plist;
	pNode slow = plist;

	if (plist == NULL)
	{
		return NULL;
	}

	//��һ��Ԫ������ k ��
	while (k--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}

	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

pNode IsCircle(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
	{
		return plist;
	}

	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}

int GetCircleLength(pNode meet)
{
	pNode cur = NULL;
	int len = 1;
	
	assert(meet != NULL);

	cur = meet->next;
	while (cur != meet)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

pNode GetCirCleEntryNode(pList plist, pNode meet)
{
	pNode cur = plist;

	if (plist == NULL)
	{
		return NULL;
	}
	assert(meet != NULL);

	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
	}
	return cur;
}

int CheckCross(pList plist1, pList plist2)
{
	pNode end1 = plist1;
	pNode end2 = plist2;
	if ((plist1 == NULL) || (plist2 == NULL))
	{
		return 0;
	}

	while (end1->next != NULL)
	{
		end1 = end1->next;
	}
	while (end2->next != NULL)
	{
		end2 = end2->next;
	}
	return end1 == end2;
}

pNode GetCrossMeetNode(pList plist1, pList plist2)
{
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	int len1 = 0;
	int len2 = 0;
	int gap = 0;

	while (cur1)
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		len2++;
		cur2 = cur2->next;
	}

	gap = abs(len1 - len2);
	cur1 = plist1;  //��
	cur2 = plist2;  //��

	if (len1 < len2)
	{
		cur1 = plist2;
		cur2 = plist1;
	}

	while (gap--)
	{
		cur1 = cur1->next;
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

int CheckCrossWithCircle(pList plist1, pList plist2)
{
	pNode pos1 = IsCircle(plist1);
	pNode pos2 = IsCircle(plist2);
	pNode cur = plist1;

	if ((pos1 == NULL) || (pos2 == NULL))
	{
		return 0;
	}
	while (cur)
	{
		if (cur == pos2)
		{
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

void GetCrossMeetNodeWithCircle(pList plist1, pList plist2)
{
	pNode pos1 = IsCircle(plist1);
	pNode pos2 = IsCircle(plist2);
	pNode entry1 = NULL;
	pNode entry2 = NULL;
	int len1 = 0;
	int len2 = 0;
	int gap = 0;
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	if ((pos1 == NULL) || (pos2 == NULL))
	{
		return;
	}
	entry1 = GetCirCleEntryNode(plist1, pos1);
	entry2 = GetCirCleEntryNode(plist2, pos2);
	if (entry1 == entry2)
	{
		while (cur1 != entry1)
		{
			len1++;
			cur1 = cur1->next;
		}
		while (cur2 != entry2)
		{
			len2++;
			cur2 = cur2->next;
		}
		gap = abs(len1 - len2);
		cur1 = plist1;  //��
		cur2 = plist2;  //��

		if (len1 < len2)
		{
			cur1 = plist2;
			cur2 = plist1;
		}

		while (gap--)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		printf("������Ϊ��%d\n", cur1->data);
		return;
	}
	printf("���������������ֱ�Ϊ��%d , %d\n", entry1->data, entry2->data);
}

void UnionSet(pList plist1, pList plist2)
{
	if ((plist1 == NULL) || (plist2 == NULL))
		return;
	while (plist1&&plist2)
	{
		if (plist1->data < plist2->data)
		{
			plist1 = plist1->next;
		}
		else if (plist1->data > plist2->data)
		{
			plist2 = plist2->next;
		}
		else
		{
			printf("%d  ", plist1->data);
			plist1 = plist1->next;
			plist2 = plist2->next;
		}
	}
	printf("\n");
}

ComplexNode* BuyComplexNode(DataType d)
{
	ComplexNode* p = (ComplexNode*)malloc(sizeof(ComplexNode));
	if (p == NULL)
	{
		perror("BuyComplexNode::malooc");
		return NULL;
	}
	p->data = d;
	p->next = NULL;
	p->random = NULL;
	return p;
}

void PrintComplexList(ComplexNode* plist)
{
	ComplexNode* cur = plist;
	while (cur)
	{
		printf("%d:", cur->data);
		if (cur->random != NULL)
		{
			printf("(%d)-->", cur->random->data);
		}
		else
		{
			printf("(NULL)-->");
		}
		cur = cur->next;
	}
	printf("over\n");
}

ComplexNode* CopyComplexList(ComplexNode* plist)
{
	ComplexNode* cur = plist;
	ComplexNode* next = cur->next;
	ComplexNode* cp = NULL;
	ComplexNode* newlist = NULL;
	//1���ڵ�ǰ���ĺ�߲���һ����ǰ��������
	while (cur != NULL)
	{
		ComplexNode* newNode = BuyComplexNode(cur->data);
		newNode->next = next;
		cur->next = newNode;
		cur = next;
		if (cur != NULL)
		{
			next = cur->next;
		}
	}
	//2�������������randomָ��
	cur = plist;
	cp = cur->next;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		{
			cp->random = cur->random->next;
		}
		cur = cp->next;
		if (cur != NULL)
		{
			cp = cur->next;
		}
	}
	//3���������
	cur = plist;
	cp = cur->next;
	newlist = cp;
	
	while (cur != NULL)
	{
		cur->next = cp->next;
		if (cur->next != NULL)
		{
			cp->next = cur->next->next;
		}
		cur = cur->next;
		cp = cp->next;
	}

	return newlist;
}