#include "BinaryTree.h"

static BTNode* BuyBTNode(BTDataType d)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = d;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		
		++(*pi);
		root->_left = BinaryTreeCreate(a, n, pi);
		
		++(*pi);
		root->_right = BinaryTreeCreate(a, n, pi);
		
		return root;
	}
	else
	{
		return NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->_left == NULL
		&& root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ±éÀú 
// µİ¹é
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
