#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// a ��һ��ǰ�����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
<<<<<<< HEAD
void BinaryTreeDestory(BTNode** pptree);

int BinaryTreeHeight(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType d);

=======

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323

// ���� 
// �ݹ�
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
<<<<<<< HEAD

// ����
void BinaryTreeLevelOrder(BTNode* root);
=======
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323
