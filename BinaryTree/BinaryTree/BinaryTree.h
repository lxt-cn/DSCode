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

// a 是一个前序遍历的数组
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

// 遍历 
// 递归
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
<<<<<<< HEAD

// 层序
void BinaryTreeLevelOrder(BTNode* root);
=======
>>>>>>> 9fb4243855014088c2a5653ff72f86e2ded87323
