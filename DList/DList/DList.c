#include "DList.h"

pNode BuyNode(DataType d)
{
	pNode ptr = (pNode)malloc(sizeof(Node));
	if (ptr == NULL)
	{
		perror("BuyNode::malloc");
		return NULL;
	}
	ptr->data = d;
	ptr->next = NULL;
	ptr->prev = NULL;

	return ptr;
}

pList InitList()
{
	DataType d = 0;
	pNode head = BuyNode(d);
	head->next = head;
	head->prev = head;
	return head;
}

void DestoryList(pList plist)
{
	pNode cur = plist->next;
	pNode next = NULL;
	while (cur != plist)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
}
void PushBack(pList plist, DataType d)
{
	pNode head = plist;
	pNode tail = head->prev;
	//tail newnode head
	pNode newnode = BuyNode(d);;
	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = head;
	head->prev = newnode;
}

void PushFront(pList plist, DataType d)
{
	pNode first = plist->next;
	pNode newnode = BuyNode(d);
	//plist newnode first;
	plist->next = newnode;
	newnode->prev = plist;

	newnode->next = first;
	first->prev = newnode;
}

pNode FindList(pList plist, DataType d)
{
	pNode cur = NULL;

	assert(plist);

	cur = plist->next;
	while (cur != plist)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void InsertList(pNode pos, DataType d)
{
	pNode newnode = NULL;
	pNode prev = NULL;

	assert(pos);

	prev = pos->prev;
	newnode = BuyNode(d);
	//prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

void PopBack(pList plist)
{
	pNode tail = NULL;
	pNode prev = NULL;

	assert(plist&&plist->next != NULL);

#if 0     //方法一
	tail = plist->prev;
	prev = tail->prev;
	//plist ... prev tail
	plist->prev = prev;
	prev->next = plist;
	free(tail);
	tail = NULL;
#endif 

#if 1  //方法二
	EraseList(plist->prev);
#endif 

}

void PopFront(pList plist)
{
	pNode first = NULL;
	pNode next = NULL;

	assert(plist&&plist->next != NULL);
	
#if 1    //方法一
	first = plist->next;
	next = first->next;
	//plist first next
	plist->next = next;
	next->prev = plist;
	free(first);
	first = NULL;
#endif

#if 0   //方法二
	EraseList(plist->next);
#endif
}

void EraseList(pNode pos)
{
	pNode prev = NULL;
	pNode next = NULL;

	assert(pos);

	prev = pos->prev;
	next = pos->next;
	//prev pos next
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

void PrintList(pList plist)
{
	pNode cur = plist->next;
	while (cur != plist)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("head\n");
}
