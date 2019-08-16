#include "BinaryTree.h"
<<<<<<< HEAD
#include "Queue.h"
=======
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323

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

<<<<<<< HEAD
void BinaryTreeDestory(BTNode** pptree)
{
	BTNode* root = *pptree;
	if (root == NULL)
		return;

	BinaryTreeDestory(&root->_left);
	BinaryTreeDestory(&root->_right);
	free(root);
	*pptree = NULL;
}

int BinaryTreeHeight(BTNode* root)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (root == NULL)
		return 0;

	leftHeight = BinaryTreeHeight(root->_left);
	rightHeight = BinaryTreeHeight(root->_right);

	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

=======
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323
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

<<<<<<< HEAD
BTNode* BinaryTreeFind(BTNode* root, BTDataType d)
{
	BTNode* ret = NULL;
	if (root == NULL || root->_data == d)
		return root;

	ret = BinaryTreeFind(root->_left, d);
	if(ret == NULL)
    	ret = BinaryTreeFind(root->_right, d);
	return ret;

}

=======
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323
// ±éÀú 
// µÝ¹é
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
<<<<<<< HEAD

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (QueueEmpty(&q) != 0)
	{
		QUDataType front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);

		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		else
		{
			QueuePush(&q, front->_right);
		}
	}
	printf("\n");
}
=======
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323
