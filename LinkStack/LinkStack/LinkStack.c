#include "LinkStack.h"

void LinkStackInit(LinkStack* pls)
{
	assert(pls);

	pls->_nCount = 0;
	pls->_top = NULL;
}

void LinkStackDestory(LinkStack* pls)
{
	assert(pls);
	
	Node* del = NULL;
	
	while (pls->_top)
	{
		del = pls->_top;
		pls->_top = del->_next;
		free(del);
		del = NULL;
		pls->_nCount--;
	}
}

static Node* BuyNode(DataType d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	assert(node);

	node->_data = d;
	node->_next = NULL;
	return node;
}

void LinkStackPush(LinkStack* pls, DataType d)
{
	Node* node = NULL;

	assert(pls);

	node = BuyNode(d);

	node->_next = pls->_top;
	pls->_top = node;
	pls->_nCount++;
}

void LinkStackPop(LinkStack* pls)
{
	Node* tmp = NULL;

	assert(pls);

	if (LinkStackEmpty(pls) == 0)
	{
		return;
	}

	tmp = pls->_top;
	pls->_top = tmp->_next;
	free(tmp);
	tmp = NULL;
}

DataType LinkStackTop(LinkStack* pls)
{
	assert(pls);

	return pls->_top->_data;
}

int LinkStackEmpty(LinkStack* pls)
{
	assert(pls);

	return pls->_nCount == 0 ? 0 : 1;     //¿Õ 0   ·Ç¿Õ  1
}

int LinkStackSize(LinkStack* pls)
{
	assert(pls);

	return pls->_nCount;
}