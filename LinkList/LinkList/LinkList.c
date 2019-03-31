#include "LinkList.h"

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

void PushBack(pList* pplist,DataType d)
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
		while(cur->next->next != NULL)
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