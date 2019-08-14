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
void BinaryTreeDestory(BTNode** pptree);

int BinaryTreeHeight(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType d);


// 遍历 
// 递归
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// 层序
void BinaryTreeLevelOrder(BTNode* root);